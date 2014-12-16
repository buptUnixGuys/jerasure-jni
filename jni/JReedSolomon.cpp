#include <stdlib.h>

#include "JReedSolomon.h"
#include "javautility.h"
#include "reed_sol.h"

#define talloc(type, num) (type *) malloc(sizeof(type)*(num))

/*
 * Class:     cn_ctyun_ec_jni_ReedSolomon
 * Method:    reed_sol_vandermonde_coding_matrix
 * Signature: (III)[I
 */
JNIEXPORT jintArray JNICALL Java_cn_ctyun_ec_jni_ReedSolomon_reed_1sol_1vandermonde_1coding_1matrix
	(JNIEnv *env, jclass clazz, jint k, jint m, jint w)
{
	bool outOfMemory = false;
	jintArray result = NULL;

	int* matrix = reed_sol_vandermonde_coding_matrix(k, m, w);
	if(matrix != NULL) {
		result = env->NewIntArray(m*k);
		if(result != NULL) {
			env->SetIntArrayRegion(result, 0, m*k, (jint*)matrix);
		} else {
			outOfMemory = true;
		}
	} else {
		outOfMemory = true;
	}

	free(matrix);

	if(outOfMemory) {
		throwOutOfMemoryError(env, "Error allocating memory for matrix");
	}

	return result;
}

/*
 * Class:     cn_ctyun_ec_jni_ReedSolomon
 * Method:    reed_sol_extended_vandermonde_matrix
 * Signature: (III)[I
 */
JNIEXPORT jintArray JNICALL Java_cn_ctyun_ec_jni_ReedSolomon_reed_1sol_1extended_1vandermonde_1matrix
	(JNIEnv *env, jclass clazz, jint rows, jint cols, jint w)
{
	bool outOfMemory = false;
	jintArray result = NULL;

	if(rows <= cols) {
		int* matrix = reed_sol_extended_vandermonde_matrix(rows, cols, w);

		if(matrix != NULL) {
			result = env->NewIntArray(rows*cols);

			if(result != NULL) {
				env->SetIntArrayRegion(result, 0, rows*cols, (jint*)matrix);
			} else {
				outOfMemory = true;
			}
		} else {
			outOfMemory = true;
		}
		free(matrix);
	} else {
		throwIllegalArgumentException(env, "rows > cols");
	}

	if(outOfMemory) {
		throwOutOfMemoryError(env, "");
	}

	return result;
}

/*
 * Class:     cn_ctyun_ec_jni_ReedSolomon
 * Method:    reed_sol_big_vandermonde_distribution_matrix
 * Signature: (III)[I
 */
JNIEXPORT jintArray JNICALL Java_cn_ctyun_ec_jni_ReedSolomon_reed_1sol_1big_1vandermonde_1distribution_1matrix
	(JNIEnv *env, jclass clazz, jint rows, jint cols, jint w)
{
	bool outOfMemory = false;
	jintArray result = NULL;

	if(rows <= cols) {
		int* matrix = reed_sol_big_vandermonde_distribution_matrix(rows, cols, w);

		if(matrix != NULL) {
			result = env->NewIntArray(rows*cols);

			if(result != NULL) {
				env->SetIntArrayRegion(result, 0, rows*cols, (jint*)matrix);
			} else {
				outOfMemory = true;
			}
		} else {
			outOfMemory = true;
		}

		free(matrix);
	} else {
		throwIllegalArgumentException(env, "rows > cols");
	}

	if(outOfMemory) {
		throwOutOfMemoryError(env, "");
	}

	return result;
}

 /*
 * Class:     cn_ctyun_ec_jni_ReedSolomon
 * Method:    reed_sol_r6_encode
 * Signature: (II[Ljava/nio/ByteBuffer;[Ljava/nio/ByteBuffer;I)Z
 */
JNIEXPORT jboolean JNICALL Java_cn_ctyun_ec_jni_ReedSolomon_reed_1sol_1r6_1encode
  (JNIEnv *env, jclass clazz, jint k, jint w, jobjectArray jdata_ptrs, jobjectArray jcoding_ptrs, jint size)
{
	char **data = convertFromBufferArray(env, jdata_ptrs);
	char **coding = convertFromBufferArray(env, jcoding_ptrs);
	
	int ret = reed_sol_r6_encode(k, w, data, coding, size);

	delete[] data;
	delete[] coding;

	if(ret == 1){
		return JNI_TRUE; 
	}else{
		return JNI_FALSE;
	}
}

/*
 * Class:     cn_ctyun_ec_jni_ReedSolomon
 * Method:    reed_sol_r6_coding_matrix
 * Signature: (II)[I
 */
JNIEXPORT jintArray JNICALL Java_cn_ctyun_ec_jni_ReedSolomon_reed_1sol_1r6_1coding_1matrix
  (JNIEnv *env, jclass clazz, jint k, jint w)
{
	bool outOfMemory = false;
	jintArray result = NULL;

	if (w == 8 || w == 16 || w == 32) {
		int* matrix = reed_sol_r6_coding_matrix(k, w);

		if(matrix != NULL) {
			result = env->NewIntArray(2*k);

			if(result != NULL) {
				env->SetIntArrayRegion(result, 0, 2*k, (jint*)matrix);
			} else {
				outOfMemory = true;
			}
		} else {
			outOfMemory = true;
		}

		free(matrix);
	} else {
		throwIllegalArgumentException(env, "w should be 8, 16 or 32");
	}

	if(outOfMemory) {
		throwOutOfMemoryError(env, "");
	}

	return result;
}

/*
 * Class:     cn_ctyun_ec_jni_ReedSolomon
 * Method:    reed_sol_galois_w08_region_multby_2
 * Signature: (Ljava/nio/ByteBuffer;I)V
 */
JNIEXPORT void JNICALL Java_cn_ctyun_ec_jni_ReedSolomon_reed_1sol_1galois_1w08_1region_1multby_12
  (JNIEnv *env, jclass clazz, jobject jregion, jint nbytes)
{
	char *region = (char*)env->GetDirectBufferAddress(jregion);
	if(region == NULL) {
		throwOutOfMemoryError(env, "Error retrieving region from Java");
		return;
	}

	reed_sol_galois_w08_region_multby_2((char*)region, nbytes);
}

/*
 * Class:     cn_ctyun_ec_jni_ReedSolomon
 * Method:    reed_sol_galois_w16_region_multby_2
 * Signature: (Ljava/nio/ByteBuffer;I)V
 */
JNIEXPORT void JNICALL Java_cn_ctyun_ec_jni_ReedSolomon_reed_1sol_1galois_1w16_1region_1multby_12
  (JNIEnv *env, jclass clazz, jobject jregion, jint nbytes)
{
	char *region = (char*)env->GetDirectBufferAddress(jregion);
	if(region == NULL) {
		throwOutOfMemoryError(env, "Error retrieving region from Java");
		return;
	}

	reed_sol_galois_w16_region_multby_2((char*)region, nbytes);
}
/*
 * Class:     cn_ctyun_ec_jni_ReedSolomon
 * Method:    reed_sol_galois_w32_region_multby_2
 * Signature: (Ljava/nio/ByteBuffer;I)V
 */
JNIEXPORT void JNICALL Java_cn_ctyun_ec_jni_ReedSolomon_reed_1sol_1galois_1w32_1region_1multby_12
  (JNIEnv *env, jclass clazz, jobject jregion, jint nbytes)
{
	char *region = (char *)env->GetDirectBufferAddress(jregion);
	if(region == NULL) {
		throwOutOfMemoryError(env, "Error retrieving region from Java");
		return;
	}

	reed_sol_galois_w32_region_multby_2((char*)region, nbytes);
}

/*
 * Class:     cn_ctyun_ec_jni_ReedSolomon
 * Method:    my_reed_sol_vandermonde_coding_matrix
 * Signature: (III)J
 */
JNIEXPORT jlong JNICALL Java_cn_ctyun_ec_jni_ReedSolomon_my_1reed_1sol_1vandermonde_1coding_1matrix
  (JNIEnv *env, jclass clazz, jint k, jint m, jint w)
{
	int* matrix = reed_sol_vandermonde_coding_matrix(k, m, w);
	if(matrix != NULL) {
		return (long)matrix;
	} else {
		throwOutOfMemoryError(env, "Error allocating memory for matrix");
	}
	return 0L;
}

/*
 * Class:     cn_ctyun_ec_jni_ReedSolomon
 * Method:    my_reed_sol_extended_vandermonde_matrix
 * Signature: (III)J
 */
JNIEXPORT jlong JNICALL Java_cn_ctyun_ec_jni_ReedSolomon_my_1reed_1sol_1extended_1vandermonde_1matrix
	(JNIEnv *env, jclass clazz, jint rows, jint cols, jint w)
{
	int* matrix = reed_sol_extended_vandermonde_matrix(rows, cols, w);
	if(matrix != NULL) {
		return (long)matrix;
	} else {
		throwOutOfMemoryError(env, "Error allocating memory for matrix");
	}
	return 0L;
}

/*
 * Class:     cn_ctyun_ec_jni_ReedSolomon
 * Method:    my_reed_sol_big_vandermonde_distribution_matrix
 * Signature: (III)J
 */
JNIEXPORT jlong JNICALL Java_cn_ctyun_ec_jni_ReedSolomon_my_1reed_1sol_1big_1vandermonde_1distribution_1matrix
  (JNIEnv *env, jclass clazz, jint rows, jint cols, jint w)
{
	int* matrix = reed_sol_big_vandermonde_distribution_matrix(rows, cols, w);
	if(matrix != NULL) {
		return (long)matrix;
	} else {
		throwOutOfMemoryError(env, "Error allocating memory for matrix");
	}
	return 0L;
}

/*
 * Class:     cn_ctyun_ec_jni_ReedSolomon
 * Method:    my_reed_sol_r6_coding_matrix
 * Signature: (II)J
 */
JNIEXPORT jlong JNICALL Java_cn_ctyun_ec_jni_ReedSolomon_my_1reed_1sol_1r6_1coding_1matrix
  (JNIEnv *env, jclass clazz, jint k, jint w)
{
	if (w == 8 || w == 16 || w == 32) {
		int* matrix = reed_sol_r6_coding_matrix(k, w);

		if(matrix != NULL) {
			return (long)matrix;
		} else {
			throwOutOfMemoryError(env, "Error allocating memory for matrix");
		}
	} else {
		throwIllegalArgumentException(env, "w should be 8, 16 or 32");
	}
	return 0L;
}