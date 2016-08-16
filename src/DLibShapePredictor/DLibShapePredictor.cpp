/*
 * DLibShapePredictor.cpp
 *
 *  Created on: Jul 4, 2016
 *      Author: benross
 */


#include "DLibShapePredictor.h"

DLibShapePredictor::DLibShapePredictor(std::string trainingData) {
	dlib::deserialize(trainingData) >> sp;
}

std::vector<cv::Point> DLibShapePredictor::findShape(cv::Mat img, cv::Rect roi) {

	std::vector<cv::Point> points;

	cv::Mat gray;

	cv::cvtColor(img, gray, CV_BGR2GRAY);

	dlib::rectangle r = openCVRectToDlib(roi);

	dlib::full_object_detection shape = sp(dlib::cv_image<uchar>(gray), r);

	for (int i = 0; i < shape.num_parts(); i++) {

		points.push_back(cv::Point(shape.part(i).x(), shape.part(i).y()));
	}

	return points;
}

dlib::rectangle DLibShapePredictor::openCVRectToDlib(cv::Rect r)
{
  return dlib::rectangle((long)r.tl().x, (long)r.tl().y, (long)r.br().x - 1, (long)r.br().y - 1);
}

cv::Rect DLibShapePredictor::dlibRectangleToOpenCV(dlib::rectangle r)
{
  return cv::Rect(cv::Point2i(r.left(), r.top()), cv::Point2i(r.right() + 1, r.bottom() + 1));
}
