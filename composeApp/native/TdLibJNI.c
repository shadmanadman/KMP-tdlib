#include <jni.h>
#include <stdint.h>
#include "include/td/telegram/td_json_client.h"


// ✅ Create a new TDLib client instance
JNIEXPORT jint JNICALL Java_org_adman_kmp_tdlib_TDLib_tdCreateClientId(JNIEnv* env, jclass clazz) {
    return td_create_client_id();
}

// ✅ Send request to TDLib
JNIEXPORT void JNICALL Java_org_adman_kmp_tdlib_TDLib_tdSend(JNIEnv* env, jclass clazz, jint client_id, jstring request) {
const char* requestStr = (*env)->GetStringUTFChars(env, request, NULL);
td_send(client_id, requestStr);
(*env)->ReleaseStringUTFChars(env, request, requestStr);
}

// ✅ Receive updates from TDLib
JNIEXPORT jstring JNICALL Java_org_adman_kmp_tdlib_TDLib_tdReceive(JNIEnv* env, jclass clazz, jdouble timeout) {
const char* response = td_receive(timeout);
return response ? (*env)->NewStringUTF(env, response) : NULL;
}

// ✅ Execute TDLib request synchronously
JNIEXPORT jstring JNICALL Java_org_adman_kmp_tdlib_TDLib_tdExecute(JNIEnv* env, jclass clazz, jstring request) {
const char* requestStr = (*env)->GetStringUTFChars(env, request, NULL);
const char* response = td_execute(requestStr);
(*env)->ReleaseStringUTFChars(env, request, requestStr);
return response ? (*env)->NewStringUTF(env, response) : NULL;
}