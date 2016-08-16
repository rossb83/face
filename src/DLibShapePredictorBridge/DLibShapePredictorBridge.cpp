/*
 * DLibShapePredictorBridge.cpp
 *
 *  Created on: Jul 4, 2016
 *      Author: benross
 */

#include "DLibShapePredictorBridge.h"

DLibShapePredictor* createDLibShapePredictor(std::string trainingData) {
	return new DLibShapePredictor(trainingData);
}

void destroyDLibShapePredictor(DLibShapePredictor* dlibShapePredictor) {
	delete dlibShapePredictor;
}

std::vector<cv::Point> findShape(DLibShapePredictor* dlibShapePredictor, cv::Mat img, cv::Rect roi) {

	if (dlibShapePredictor == NULL) {
		throw std::runtime_error("Shape predictor must be initialized");
	}

	return dlibShapePredictor->findShape(img, roi);
}
