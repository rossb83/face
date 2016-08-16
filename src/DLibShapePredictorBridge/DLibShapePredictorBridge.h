/*
 * DLibShapePredictorBridge.h
 *
 *  Created on: Jul 4, 2016
 *      Author: benross
 */

#ifndef DLIBSHAPEPREDICTORBRIDGE_DLIBSHAPEPREDICTORBRIDGE_H_
#define DLIBSHAPEPREDICTORBRIDGE_DLIBSHAPEPREDICTORBRIDGE_H_

#include "DLibShapePredictor.h"

DLibShapePredictor* createDLibShapePredictor(std::string trainingData);

void destroyDLibShapePredictor(DLibShapePredictor* dlibShapePredictor);

std::vector<cv::Point> findShape(DLibShapePredictor* dlibShapePredictor, cv::Mat img, cv::Rect roi);

#endif /* DLIBSHAPEPREDICTORBRIDGE_DLIBSHAPEPREDICTORBRIDGE_H_ */
