/*
 * DLibShapePredictorJNI.cpp
 *
 *  Created on: Jul 4, 2016
 *      Author: benross
 */

#include "DLibShapePredictorJNI.h"
#include "DLibShapePredictorBridge.h"

/*
 * Class:     com_dlib_shapepredictor_bridge_DLibShapePredictorBridge
 * Method:    createDLibShapePredictor
 * Signature: (Ljava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_com_dlib_shapepredictor_jni_DLibShapePredictorJNI_createDLibShapePredictor
  (JNIEnv* env, jclass clazz, jstring trainingDataObject)
{
    const char* trainingData = env->GetStringUTFChars(trainingDataObject,NULL);
    std::string trainingDataString = trainingData;

    if (trainingDataString.length() == 0) {
    	throw std::runtime_error("Training data string JNI conversion error");
    }

    DLibShapePredictor* dlibShapePredictor = createDLibShapePredictor(trainingData);

    long dlibShapePredictorAddress = (long) dlibShapePredictor;

    if (dlibShapePredictorAddress == 0) {
    	throw std::runtime_error("NPE Dlib JNI error");
    }

    env->ReleaseStringUTFChars(trainingDataObject, trainingData);

    return dlibShapePredictorAddress;
}

/*
 * Class:     com_dlib_shapepredictor_bridge_DLibShapePredictorBridge
 * Method:    destroyDLibShapePredictor
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_dlib_shapepredictor_jni_DLibShapePredictorJNI_destroyDLibShapePredictor
  (JNIEnv* env, jclass clazz, jlong dlibShapePredictorAddress)
{
	DLibShapePredictor* dlibShapePredictor = (DLibShapePredictor*) ((long) dlibShapePredictorAddress);

    if (dlibShapePredictor == 0) {
    	throw std::runtime_error("NPE Dlib JNI error");
    }

    destroyDLibShapePredictor(dlibShapePredictor);
}

/*
 * Class:     com_dlib_shapepredictor_bridge_DLibShapePredictorBridge
 * Method:    findShape
 * Signature: (JLorg/opencv/core/Mat;Lorg/opencv/core/Rect;)[I
 */
JNIEXPORT jobjectArray JNICALL Java_com_dlib_shapepredictor_jni_DLibShapePredictorJNI_findShape
  (JNIEnv *env, jclass clazz, jlong dlibShapePredictorAddress, jobject imgObject, jobject roiObject)
{
	jclass matClass = env->FindClass("org/opencv/core/Mat");
	jmethodID matId = env->GetMethodID(matClass, "getNativeObjAddr", "()J");
	cv::Mat& img = *(cv::Mat*) env->CallLongMethod(imgObject, matId);

	jclass pointClass = env->FindClass("org/opencv/core/Point");
	jmethodID pointInit = env->GetMethodID(pointClass, "<init>","(DD)V");

	jclass rectClass = env->FindClass("org/opencv/core/Rect");
	jfieldID rectClassX = env->GetFieldID(rectClass, "x", "I");
	jfieldID rectClassY = env->GetFieldID(rectClass, "y", "I");
	jfieldID rectClassWidth = env->GetFieldID(rectClass, "width", "I");
	jfieldID rectClassHeight = env->GetFieldID(rectClass, "height", "I");

	cv::Rect roi(env->GetIntField(roiObject, rectClassX), env->GetIntField(roiObject, rectClassY), env->GetIntField(roiObject, rectClassWidth), env->GetIntField(roiObject, rectClassHeight));

	DLibShapePredictor* dlibShapePredictor = (DLibShapePredictor*) ((long) dlibShapePredictorAddress);

    if (dlibShapePredictor == 0) {
    	throw std::runtime_error("NPE Dlib JNI error");
    }

    std::vector<cv::Point> shape = findShape(dlibShapePredictor, img, roi);

    jobjectArray result = env->NewObjectArray(shape.size(), pointClass, NULL);

    for (int i = 0; i < shape.size(); i++) {

    	jobject obj = env->NewObject(pointClass, pointInit, (double) shape[i].x, (double) shape[i].y);
    	env->SetObjectArrayElement(result, i, obj);
    }

    return result;
}
