/*
 * DLibShapePredictor.h
 *
 *  Created on: Jul 3, 2016
 *      Author: benross
 */

#ifndef DLIBSHAPEPREDICTOR_H_
#define DLIBSHAPEPREDICTOR_H_

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/core/core.hpp>

#include <iostream>
#include <String>
#include <Vector>
#include <stdexcept>
#include <sys/stat.h>
#include <unistd.h>

#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_io.h>
#include <dlib/image_processing.h>
#include <dlib/opencv/cv_image.h>

class DLibShapePredictor {
public:
	DLibShapePredictor(std::string trainingData);
	std::vector<cv::Point> findShape(cv::Mat img, cv::Rect roi);

protected:
    static dlib::rectangle openCVRectToDlib(cv::Rect r);
    static cv::Rect dlibRectangleToOpenCV(dlib::rectangle r);

private:
	dlib::shape_predictor sp;
};

#endif /* DLIBSHAPEPREDICTOR_H_ */
