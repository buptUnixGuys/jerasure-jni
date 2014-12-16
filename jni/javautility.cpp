#include "javautility.h"

jint throwNoClassDefError(JNIEnv *env, char *message) {
	jclass exClass;
	char *className = "java/lang/NoClassDefFoundError";

	exClass = env->FindClass(className );
	if ( exClass == NULL )
	{
		return throwNoClassDefError(env, className );
	}

	return env->ThrowNew(exClass, message );
}

jint throwOutOfMemoryError(JNIEnv *env, char *message) {
	jclass exClass;
	char *className = "java/lang/OutOfMemoryError";

	exClass = env->FindClass(className);
	if(exClass == NULL)
	{
		return throwNoClassDefError(env, className);
	}

	return env->ThrowNew(exClass, message);
}

jint throwIllegalArgumentException(JNIEnv *env, char* message) {
	jclass exClass;
	char* className = "java/lang/IllegalArgumentException";

	exClass = env->FindClass(className);
	if(exClass == NULL)
	{
		return throwNoClassDefError(env, className);
	}

	return env->ThrowNew(exClass, message);
}

char** convertFromBufferArray(JNIEnv *env, jobjectArray joa)
{
	jsize len = env->GetArrayLength(joa);
	char **data = new char*[len];
	for(int i=0; i<len; i++){
		jobject ob = env->GetObjectArrayElement(joa, i);
		char *obc = (char *)env->GetDirectBufferAddress(ob);
		data[i] = obc;
	}
	return data;
}
