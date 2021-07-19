#include <iostream>
#include <string>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <stdlib.h>
#include <jni_md.h>
#include <jvmti.h>

using namespace std;


JNIEXPORT jint JNICALL
Agent_OnLoad(JavaVM *vm, char *options, void *reserved){
    jvmtiEnv *jvmti;
    jint result = vm->GetEnv((void**)&jvmti,JVMTI_VERSION_1_1);
    if (result != JNI_OK){
        printf("ERROR: Unable to access JVMTI!\n");
    }

    jvmtiError err = (jvmtiError)0;
    jclass *classes;
    jint count;
    err = jvmti->GetLoadedClasses(&count,&classes);
    if (err){
        printf("ERROR: JVMIT GetLoadedClasses failed!\n");
    }

    jint thread_state;
    err = jvmti->GetThreadState(NULL,&thread_state);


    for (int i = 0; i < 100 ; i++){
        char *sig;
        jvmti->GetClassSignature(classes[i],&sig,NULL);
        printf("i=%d ,class sig=%s\n",i,sig);
    }


    printf("error:%d\n",err);
    return err;

}


//JNIEXPORT jint JNICALL
//Agent_OnAttach(JavaVM* vm, char* options, void* reserved){
//    jvmtiEnv *jvmti;
//    jint result = vm->GetEnv((void**)&jvmti,JVMTI_VERSION_1_1);
//    if (result != JNI_OK){
//        printf("ERROR: Unable to access JVMTI!\n");
//    }
//
//    jvmtiError err = (jvmtiError)0;
//    jclass *classes;
//    jint count;
//    err = jvmti->GetLoadedClasses(&count,&classes);
//    if (err){
//        printf("ERROR: JVMIT GetLoadedClasses failed!\n");
//    }
//
//    jint thread_state;
//    err = jvmti->GetThreadState(NULL,&thread_state);
//
//
////    for (int i = 0; i < 100 ; i++){
////        char *sig;
////        jvmti->GetClassSignature(classes[i],&sig,NULL);
////        printf("i=%d ,class sig=%s\n",i,sig);
////    }
////
////    printf("error:%d\n",err);
//
//
//
//    return err;
//
//}

