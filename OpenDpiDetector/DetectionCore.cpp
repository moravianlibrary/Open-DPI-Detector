#include "DetectionCore.h"

//length of the calibration object (distance between centers of circles in inches)
const double calibrationLength = 4;
//values for cvHoughCircles (10 means 1/10 of whole image, 30 is 1/30 of whole image)
//smaller number means higher value
const int minimalDistance = 10;
const int minimalRadius = 30;
const int maximalRadius = 10;

using namespace std;

	DetectionCore::DetectionCore(Orientation_t ori)
	{
		orientation = ori;
	}

	DetectionCore::~DetectionCore(void)
	{
	}

	int DetectionCore::detectDPI(char* fileName)
	{
		//pointers to images created during processing
		IplImage *source=0,
				  *croppedImage=0,
				  *filteredImage=0;
		//pointer to array with found circles
		CvSeq* foundCircles=0;
		//pointer to pair with two centers of circles
		CvPoint* expectedCircles=0;
		//computed dpi
		int dpi;
		try
		{
			source=cvLoadImage(fileName,1); //load image with build-in openCV function
			croppedImage = cropImage(source,orientation);//crop away unnecessary area
			cvReleaseImage(&source );//release original image
			filteredImage = filterImage(croppedImage);//filter away unwanted colors
			cvReleaseImage(&croppedImage );//release cropped image
			foundCircles = findCircles(filteredImage,orientation);//find all circles in filtered and cropped img
			expectedCircles = getExpectedCircles(foundCircles,orientation);//take only 2 expected circles
			dpi = countDPI(expectedCircles);//count DPI
			cvReleaseImage(&filteredImage );//release last image
			cvClearSeq(foundCircles);
			delete [] expectedCircles;
			expectedCircles=0;
		}
		catch(DetectionFailureException ex)
		{
			//deallocate all used memory and throw exception
			if (source !=0)
			{
				cvReleaseImage(&source );
				source=0;
			}
			if (croppedImage != 0)
			{
				cvReleaseImage(&croppedImage );
				croppedImage=0;
			}
			if (filteredImage != 0) 
			{
				cvReleaseImage(&filteredImage );
				filteredImage=0;
			}
			if (foundCircles != 0)
			{
				cvClearSeq(foundCircles);
				foundCircles=0;
			}
			if (expectedCircles != 0)
			{
				delete [] expectedCircles;
				expectedCircles=0;
			}
			string errMs =ex.getMessage()+" in file " +fileName;
			throw DetectionFailureException(errMs, ex.getfunction());
		}
		catch(...)//catch all exceptions thrown by OpenCV
		{
			throw DetectionFailureException("Couldn't load, file not exist or insufficient memory","cvLoadImage");
		}
	return dpi;
	}

	IplImage* DetectionCore::filterImage(IplImage* src)
	{
		if (src == 0)
		{
			throw DetectionFailureException("Image is not supported or was not loaded properly",__FUNCTION__);
		}
		IplImage* result= cvCreateImage( cvGetSize(src), 8,1 );//create memory space for filtered image
		int height = src->height;
		int width = src->width;

		//data of original image
		int stepSource = src->widthStep;
		int channelsSource = src->nChannels;
		uchar* dataSource = (uchar *)src->imageData;
		//data of destination image
		int stepResult = result->widthStep;
		int channelsResult = result->nChannels;
		uchar* dataResult = (uchar*) result->imageData;

		//filter only red elements from image (60% of red value of pixel must be more than all blue and green)
		for(int i=0;i<height;i++) 
		{
			for(int j=0;j<width;j++)
			{		//red value must be at least 50, less is considered too dark
				if((dataSource[i*stepSource+j*channelsSource+2] > 50)
					//compare with blue channel
				&&	((dataSource[i*stepSource+j*channelsSource+2]) * 0.60 > (dataSource[i*stepSource+j*channelsSource]))
					//compare with green channel
				&& ((dataSource[i*stepSource+j*channelsSource+2]) * 0.60 > (dataSource[i*stepSource+j*channelsSource+1])))
					dataResult[i*stepResult+j*channelsResult]=0;//set color black
				else
					dataResult[i*stepResult+j*channelsResult]=255;//set color white
			}
		}
		return result;
	}

	IplImage* DetectionCore::cropImage(IplImage* source, Orientation_t orientation)
	{
		if (source == 0)
		{
			throw DetectionFailureException("Image source is not supported or was not loaded properly",__FUNCTION__);
		}
		CvRect rect;
		IplImage* subimg;
		switch(orientation)
		{
		case UPPER_SIDE://crop away bottom half
			rect = cvRect(0, 0, source->width,(int)(source->height/2));//create Region of Interest
			//create destination (cropped) img
			subimg = cvCreateImage(
					(cvSize(source->width , (int)(source->height/2))),
                     source->depth,
					 source->nChannels
					 );
			break;
		case RIGHT_SIDE://crop  away left half
			rect = cvRect((int)(source->width/2), 0, source->width,source->height);//create Region of Interest
			//create destination (cropped) img
			subimg = cvCreateImage(
				(cvSize((int)((source->width+1)/2) , source->height)),
                     source->depth,
					 source->nChannels
					 );
			break;
		case BOTTOM_SIDE://crop away upper half
			rect = cvRect(0, (int)(source->height/2), source->width, source->height);//create Region of Interest
			//create destination (cropped) img
			subimg = cvCreateImage(
					(cvSize(source->width , (int)((source->height+1)/2))),
                     source->depth,
					 source->nChannels
					 );
			break;
		case LEFT_SIDE://crop away right half
			rect = cvRect(0, 0, (int)(source->width/2), source->height);//create Region of Interest
			//create destination (cropped) img
			subimg = cvCreateImage(
					(cvSize((int)(source->width/2) , source->height)),
                     source->depth,
					 source->nChannels
					 );
			break;
		}
		cvSetImageROI(source, rect);
		cvCopy(source, subimg,NULL);//copy ROI to destination img
		cvResetImageROI(source);//free ROI
		return subimg;
	}

	CvSeq* DetectionCore::findCircles(IplImage* src, Orientation_t orientation)
	{
		if (src == 0)
		{
			throw DetectionFailureException("Image source is not supported or was not loaded properly",__FUNCTION__);
		}
		CvSeq* results;
		CvMemStorage* storage = cvCreateMemStorage(0);
		if (orientation == UPPER_SIDE || orientation == BOTTOM_SIDE)//vertical half was cut
		{
			results = cvHoughCircles(
				src,						//source img
				storage,					//memory storage
				CV_HOUGH_GRADIENT,			//method for finding
				1.8,						//size of accumulator
				src->width/minimalDistance,	//minimal distance between 2 circles
				100,100,					//params for cvCanny()
				src->height/minimalRadius,	//minimal radius of circle
				src->height/maximalRadius	//maximal radius of circle
				);
		}
		else if (orientation == LEFT_SIDE || orientation == RIGHT_SIDE)//horizontal half was cut
		{
			results = cvHoughCircles(
				src,							//source img
				storage,						//memory storage
				CV_HOUGH_GRADIENT,				//method for finding
				1.8,							//size of accumulator
				src->height/(minimalDistance*2),//minimal distance between 2 circles
				100,100,						//params for cvCanny()
				(src->width*2)/minimalRadius,	//minimal radius of circle
				(src->width*2)/maximalRadius	//maximal radius of circle
				);
		}
		return results;
	}

	CvPoint* DetectionCore::getExpectedCircles(CvSeq* results, Orientation_t orientation){
		if(results->total < 2)
		{
			throw DetectionFailureException("There were detected less than 2 circles",__FUNCTION__);
		}
		CvPoint *pair = new CvPoint[2];//create array on the Heap
		CvPoint pt;
		CvPoint pt2;
		float* p;
		float maximumFit;
		float maximumFit2;
		switch(orientation)
			{
			//in this case looks for 2 centers with smallest y (vertical) coordinate
			case UPPER_SIDE:
				p = (float*) cvGetSeqElem(results,0);
				maximumFit = p[1];//assign first possible y value as best fitting
				pt = cvPoint((int) p[0],(int)p[1]);//remember this point as best fitting
				p = (float*) cvGetSeqElem(results,1);
				maximumFit2 = p[1]; //assign second possible y value as second best fitting
				pt2 = cvPoint((int) p[0], (int) p[1]);//remember this point as second best
				if (maximumFit > maximumFit2)
				{
					std::swap(maximumFit,maximumFit2);//swap first and second value if needed
					std::swap(pt,pt2);
				}
				//iterates through centers of all circles and finds 2 expected centers (pt & pt2) 
				for (int i=2; i < results->total; i++)
				{
					p = (float*) cvGetSeqElem(results,i);
					if (p[1] < maximumFit)
					{
						maximumFit2 = maximumFit;
						maximumFit = p[1];
						pt2 = cvPoint((int) pt.x, (int) pt.y);
						pt = cvPoint((int) p[0], (int) p[1]);
					}
					else if(p[1] < maximumFit2)
					{
						maximumFit2 = p[1];
						pt2 = cvPoint((int)p[0], (int)p[1]);
					}
				}
				break;
			//in this case looks for 2 centers with largest x (horizontal) cordinate
			case RIGHT_SIDE:
				p = (float*) cvGetSeqElem(results,0);
				maximumFit = p[0];//assign first possible x value as best fitting
				pt = cvPoint((int) p[0],(int)p[1]);//remember this point as best fitting
				p = (float*) cvGetSeqElem(results,1);
				maximumFit2 = p[0]; //assign second possible x value as second best fitting
				pt2 = cvPoint((int) p[0], (int) p[1]);//remember this point as second best
				if (maximumFit < maximumFit2)
				{
					std::swap(maximumFit,maximumFit2);//swap first and second value if needed
					std::swap(pt,pt2);
				}
				//iterates through centers of all circles and finds 2 expected centers (pt & pt2) 
				for (int i=2; i < results->total; i++)
				{
					p = (float*) cvGetSeqElem(results,i);
					if (p[0] > maximumFit)
					{
						maximumFit2 = maximumFit;
						maximumFit = p[0];
						pt2 = cvPoint((int) pt.x, (int) pt.y);
						pt = cvPoint((int) p[0], (int) p[1]);
					}
					else if(p[0] > maximumFit2)
					{
						maximumFit2 = p[0];
						pt2 = cvPoint((int)p[0], (int)p[1]);
					}
				}
				break;
			//int this case looks for 2 centers with largest y (vertical) coordinate
			case BOTTOM_SIDE:
				p = (float*) cvGetSeqElem(results,0);
				maximumFit = p[1];//assign first possible y value as best fitting
				pt = cvPoint((int) p[0],(int)p[1]);//remember this point as best fitting
				p = (float*) cvGetSeqElem(results,1);
				maximumFit2 = p[1]; //assign second possible y value as second best fitting
				pt2 = cvPoint((int) p[0], (int) p[1]);//remember this point as second best
				if (maximumFit < maximumFit2)
				{
					std::swap(maximumFit,maximumFit2);//swap first and second value if needed
					std::swap(pt,pt2);
				}
				//iterates through centers of all circles and finds 2 expected centers (pt & pt2) 
				for (int i=2; i < results->total; i++)
				{
					p = (float*) cvGetSeqElem(results,i);
					if (p[1] > maximumFit)
					{
						maximumFit2 = maximumFit;
						maximumFit = p[1];
						pt2 = cvPoint((int) pt.x, (int) pt.y);
						pt = cvPoint((int) p[0], (int) p[1]);
					}
					else if(p[1] > maximumFit2)
					{
						maximumFit2 = p[1];
						pt2 = cvPoint((int)p[0], (int)p[1]);
					}
				}
				break;
			//in this case looks for 2 centers with lowest x (horizontal) coordinate
			case LEFT_SIDE:
				p = (float*) cvGetSeqElem(results,0);
				maximumFit = p[0];//assign first possible x value as best fitting
				pt = cvPoint((int) p[0],(int)p[1]);//remember this point as best fitting
				p = (float*) cvGetSeqElem(results,1);
				maximumFit2 = p[0]; //assign second possible x value as second best fitting
				pt2 = cvPoint((int) p[0], (int) p[1]);//remember this point as second best
				if (maximumFit > maximumFit2)
				{
					std::swap(maximumFit,maximumFit2);//swap first and second value if needed
					std::swap(pt,pt2);
				}
				//iterates through centers of all circles and finds 2 expected centers (pt & pt2) 
				for (int i=2; i < results->total; i++)
				{
					p = (float*) cvGetSeqElem(results,i);
					if (p[0] < maximumFit)
					{
						maximumFit2 = maximumFit;
						maximumFit = p[0];
						pt2 = cvPoint((int) pt.x, (int) pt.y);
						pt = cvPoint((int) p[0], (int) p[1]);
					}
					else if(p[0] < maximumFit2)
					{
						maximumFit2 = p[0];
						pt2 = cvPoint((int)p[0], (int)p[1]);
					}
				}
				break;
		}
			pair[0]=pt;
			pair[1]=pt2;
			return pair;
	}

	int DetectionCore::countDPI(CvPoint* pair)
	{
		double a = abs(pair[0].x - pair[1].x);//horizontal distance between 2 points
		double b = abs(pair[0].y - pair[1].y);//vertical distance between 2 points
		//count distance between 2 points through Pythagorean theorem (c^2 = a^2 + b^2)
		double c = sqrt(a*a+b*b);
		c = c/calibrationLength; //divide by length of calibration object (in inches)
		return (int) c;
	}

