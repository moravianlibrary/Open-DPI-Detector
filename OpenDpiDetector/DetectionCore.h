#ifndef _DETECTIONCORE_H

#define _DETECTIONCORE_H

#include "DetectionFailureException.h"
#include"highgui.h"
#include <cmath>
#include "cv.h"
#include "EnumTypes.h"

/**
 * Class for detecting DPI from source image, if there is suitable calibration object
 * (2 red circles with distance of their centres 4" and diameter approximately 1")
 */
class DetectionCore
{
public:
	/**
	 * Constructor
	 * @param ori location of calibration mark relative to document
	 */
	DetectionCore(Orientation_t ori);
	/**
	 * Destructor
	 */
	~DetectionCore(void);
	/**
	 * public function for detection of DPI
	 * @param fileName name of image file containing calibration mark
	 * @return detected integer DPI
	 * @throw DetectionFailureException if error occured during process
	 */
	int detectDPI(char* fileName);
private:
	Orientation_t orientation;/**< location of calibration mark relative to document */
	/**
	 * filters only red color from image
	 * @param src image from which red elements will be filtered
	 * @return bicolor image containing only elements that was red in original image
	 * @throw DetectionFailureException if src is null
	 */
	IplImage* filterImage(IplImage* src);
	/**
	 * crops unneeded half of image (one opposite of orientation)
	 * @param source image that will be cropped
	 * @param orientation position of calibration mark relative to document
	 * @return cropped image
	 * @throw DetectionFailureException if source is null
	 */
	IplImage* cropImage(IplImage* source, Orientation_t orientation);
	/**
	 * finds all appropriate circles in source image
	 * @param src source image
	 * @param orientation position of calibration mark relative to document
	 * @return sequence of tripples containing position of center and radius of each circle
	 * @throw DetectionFailureException if src is null;
	 */
	CvSeq* findCircles(IplImage* src, Orientation_t orientation);
	/**
	 * take appropriate 2 circles from all detected circles
	 * @param results circles detected by findCircles function
	 * @param orientation position of calibration mark relative to document
	 * @return pair containing x and y coordinates for centers of both circles
	 * @throw DetectionFailureException if results contain less than 2 elements
	 */
	CvPoint* getExpectedCircles(CvSeq* results, Orientation_t orientation);
	/**
	 * counts DPI from distance of centers in pair
	 * @param pair coordinates of centers of 2 circles
	 * @return DPI of processed image
	 */
	int countDPI(CvPoint* pair);

};

#endif
