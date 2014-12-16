#include <stdlib.h>
#include "JLiberation.h"
#include "javautility.h"
#include "liberation.h"

/*
 * Class:     cn_ctyun_ec_jni_Liberation
 * Method:    liberation_coding_bitmatrix
 * Signature: (II)[I
 */
JNIEXPORT jintArray JNICALL Java_cn_ctyun_ec_jni_Liberation_liberation_1coding_1bitmatrix
	(JNIEnv *env, jclass clazz, jint k, jint w)
{
	bool outOfMemory = false;
	jintArray result = NULL;

	if(k <= w) {
		int* matrix = liberation_coding_bitmatrix(k,w);
		if(matrix != NULL) {
			result = env->NewIntArray(2*k*w*w);

			if(result != NULL) {
				env->SetIntArrayRegion(result, 0, 2*k*w*w, (jint*)matrix);
			} else {
				outOfMemory = true;
			}
		} else {
			outOfMemory = true;
		}

		free(matrix);
	} else {
		throwIllegalArgumentException(env, "k > w");
	}

	if(outOfMemory) {
		throwOutOfMemoryError(env, "Could not allocate enough memory.");
	}

	return result;
}

/*
 * Class:     cn_ctyun_ec_jni_Liberation
 * Method:    liber8tion_coding_bitmatrix
 * Signature: (I)[I
 */
JNIEXPORT jintArray JNICALL Java_cn_ctyun_ec_jni_Liberation_liber8tion_1coding_1bitmatrix
	(JNIEnv *env, jclass clazz, jint k)
{
	bool outOfMemory = false;
	jintArray result = NULL;

	if(k <= 8) {
		int* matrix = liber8tion_coding_bitmatrix(k);

		if(matrix != NULL) {
			result = env->NewIntArray(2*k*8*8);
			if(result != NULL) {
				env->SetIntArrayRegion(result, 0, 2*k*8*8, (jint*)matrix);
			} else {
				outOfMemory = true;
			}
		} else {
			outOfMemory = true;
		}

		free(matrix);
	} else {
		throwIllegalArgumentException(env, "k > 8");
	}

	if(outOfMemory) {
		throwOutOfMemoryError(env, "");
	}

	return result;
}

/*
 * Class:     cn_ctyun_ec_jni_Liberation
 * Method:    blaum_roth_coding_bitmatrix
 * Signature: (II)[I
 */
JNIEXPORT jintArray JNICALL Java_cn_ctyun_ec_jni_Liberation_blaum_1roth_1coding_1bitmatrix
	(JNIEnv *env, jclass clazz, jint k, jint w)
{
	bool outOfMemory = false;
	jintArray result = NULL;

	if(k <= w) {
		int* matrix = blaum_roth_coding_bitmatrix(k, w);

		if(matrix != NULL) {
			result = env->NewIntArray(2*k*w*w);
			if(result != NULL) {
				env->SetIntArrayRegion(result, 0, 2*k*w*w, (jint*)matrix);
			} else {
				outOfMemory = true;
			}
		} else {
			outOfMemory = true;
		}

		free(matrix);
	} else {
		throwIllegalArgumentException(env, "k > w");
	}

	if(outOfMemory){
		throwOutOfMemoryError(env, "");
	}

	return result;
}

/*
 * Class:     cn_ctyun_ec_jni_Liberation
 * Method:    my_liberation_coding_bitmatrix
 * Signature: (II)J
 */
JNIEXPORT jlong JNICALL Java_cn_ctyun_ec_jni_Liberation_my_1liberation_1coding_1bitmatrix
	(JNIEnv *env, jclass clazz, jint k, jint w)
{
	if(k <= w) {
		int* matrix = liberation_coding_bitmatrix(k,w);
		if(matrix != NULL) {
			return (long)matrix;
		} else {
			throwOutOfMemoryError(env, "Could not allocate enough memory.");
		}
	} else {
		throwIllegalArgumentException(env, "k > w");
	}

	return 0L;
}

/*
 * Class:     cn_ctyun_ec_jni_Liberation
 * Method:    my_liber8tion_coding_bitmatrix
 * Signature: (I)J
 */
JNIEXPORT jlong JNICALL Java_cn_ctyun_ec_jni_Liberation_my_1liber8tion_1coding_1bitmatrix
	(JNIEnv *env, jclass clazz, jint k)
{
	if(k <= 8) {
		int* matrix = liber8tion_coding_bitmatrix(k);

		if(matrix != NULL) {
			return (long)matrix;
		} else {
			throwOutOfMemoryError(env, "Could not allocate enough memory.");
		}
	} else {
		throwIllegalArgumentException(env, "k > 8");
	}
	return 0L;
}

/*
 * Class:     cn_ctyun_ec_jni_Liberation
 * Method:    my_blaum_roth_coding_bitmatrix
 * Signature: (II)J
 */
JNIEXPORT jlong JNICALL Java_cn_ctyun_ec_jni_Liberation_my_1blaum_1roth_1coding_1bitmatrix
	(JNIEnv *env, jclass clazz, jint k, jint w)
{
	if(k <= w) {
		int* matrix = blaum_roth_coding_bitmatrix(k, w);

		if(matrix != NULL) {
			return (long)matrix;
		} else {
			throwOutOfMemoryError(env, "Could not allocate enough memory.");
		}
	} else {
		throwIllegalArgumentException(env, "k > w");
	}
	return 0L;
}