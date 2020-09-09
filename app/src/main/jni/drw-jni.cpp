//
// Created by ycx on 2020/09/08.
//
#include <jni.h>
#include "libdxfrw.h"
#include "drw_imp.h"
void jniDoubleToPoint(JNIEnv *env, jdoubleArray p, DRW_Coord *drwPoint) {
    jdouble *point = env->GetDoubleArrayElements(p, 0);
    drwPoint->x = point[0];
    drwPoint->y = point[1];
    drwPoint->z = point[2];
    env->ReleaseDoubleArrayElements(p, point, 0);
}


extern "C"
JNIEXPORT jlong JNICALL
Java_cn_shiftcmd_libcad_DxfWriter_createNativeObject(JNIEnv *env, jobject thiz) {
    jlong result;
    auto *dxData = new dx_data();
    DRW_Textstyle *textstyle = new DRW_Textstyle();
    textstyle->height = 3;
    textstyle->font = "黑体";
    textstyle->name = "CHARSET";
    dxData->textStyles.push_back(*textstyle);
    return (jlong) dxData;
}


extern "C"
JNIEXPORT void JNICALL
Java_cn_shiftcmd_libcad_DxfWriter_writePoint(JNIEnv *env, jobject thiz, jlong addr,
                                             jdoubleArray p) {
    auto *dxData = (dx_data *) addr;
    DRW_Point *drwPoint = new DRW_Point();
    jniDoubleToPoint(env, p, &drwPoint->basePoint);
    dxData->mBlock->ent.push_back(drwPoint);
}
extern "C"
JNIEXPORT void JNICALL
Java_cn_shiftcmd_libcad_DxfWriter_writeToFile(JNIEnv *env, jobject thiz, jlong addr, jstring file,
                                              jint version) {
    auto *dxData = (dx_data *) addr;
    const char *filePath = env->GetStringUTFChars(file, 0);
    auto *drwImp = new drw_imp();
    drwImp->fileExport(filePath, DRW::Version(version), false, dxData);
    delete drwImp;
}


extern "C"
JNIEXPORT void JNICALL
Java_cn_shiftcmd_libcad_DxfWriter_writeText(JNIEnv *env, jobject thiz, jlong addr, jdoubleArray p1,
                                            jdoubleArray p2, jstring text) {
    auto *dxData = (dx_data *) addr;
    const char *content = env->GetStringUTFChars(text, 0);
    DRW_Text *drwText = new DRW_Text();
    drwText->text = content;
    drwText->style = "CHARSET";
    drwText->height=0;
    jniDoubleToPoint(env, p1, &drwText->basePoint);
    jniDoubleToPoint(env, p2, &drwText->secPoint);
    dxData->mBlock->ent.push_back(drwText);
}
extern "C"
JNIEXPORT void JNICALL
Java_cn_shiftcmd_libcad_DxfWriter_writeLine(JNIEnv *env, jobject thiz, jlong addr, jdoubleArray p1,
                                            jdoubleArray p2, jdouble line_w) {
    auto *dxData = (dx_data *) addr;
    DRW_Line *drwText = new DRW_Line();
    drwText->thickness = line_w;
    jniDoubleToPoint(env, p1, &drwText->basePoint);
    jniDoubleToPoint(env, p2, &drwText->secPoint);
    dxData->mBlock->ent.push_back(drwText);
}
extern "C"
JNIEXPORT void JNICALL
Java_cn_shiftcmd_libcad_DxfWriter_writeCircle(JNIEnv *env, jobject thiz, jlong addr, jdoubleArray p,
                                              jdouble radius) {
    auto *dxData = (dx_data *) addr;
    auto *drwCirle = new DRW_Circle();
    jniDoubleToPoint(env, p, &drwCirle->basePoint);
    drwCirle->radious = radius;
    dxData->mBlock->ent.push_back(drwCirle);
}


extern "C"
JNIEXPORT jlong JNICALL
Java_cn_shiftcmd_libcad_DxfWriter_clear(JNIEnv *env, jobject thiz, jlong addr) {
    auto *dxData = (dx_data *) addr;
    delete dxData;
    auto *newData = new dx_data();
    return (jlong) newData;
}