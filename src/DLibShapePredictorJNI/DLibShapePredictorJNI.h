/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_dlib_shapepredictor_jni_DLibShapePredictorJNI */

#ifndef _Included_com_dlib_shapepredictor_jni_DLibShapePredictorJNI
#define _Included_com_dlib_shapepredictor_jni_DLibShapePredictorJNI
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_dlib_shapepredictor_jni_DLibShapePredictorJNI
 * Method:    createDLibShapePredictor
 * Signature: (Ljava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_com_dlib_shapepredictor_jni_DLibShapePredictorJNI_createDLibShapePredictor
  (JNIEnv *, jclass, jstring);

/*
 * Class:     com_dlib_shapepredictor_jni_DLibShapePredictorJNI
 * Method:    destroyDLibShapePredictor
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_dlib_shapepredictor_jni_DLibShapePredictorJNI_destroyDLibShapePredictor
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_dlib_shapepredictor_jni_DLibShapePredictorJNI
 * Method:    findShape
 * Signature: (JLorg/opencv/core/Mat;Lorg/opencv/core/Rect;)[Lorg/opencv/core/Point;
 */
JNIEXPORT jobjectArray JNICALL Java_com_dlib_shapepredictor_jni_DLibShapePredictorJNI_findShape
  (JNIEnv *, jclass, jlong, jobject, jobject);

#ifdef __cplusplus
}
#endif
#endif