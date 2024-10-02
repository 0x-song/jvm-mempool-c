//
// Created by song on 24-10-2.
//
#include <stdlib.h>
#include <stdio.h>

#ifndef COMMON_H
#define COMMON_H

typedef union {
    long        l_dummy;
    double      d_dummy;
    void *      p_dummy;
}Align;

#define ALIGN_SIZE          (sizeof(Align))

typedef enum {
    GC_MARK_CLEAN,
    GC_MARK_COLLECT,
    GC_MARK_COPY,
    GC_G1,
}GC_Type;

#define UseParallelGC false
#define UseG1GC false
#define UseSerialGC false
#define UseConcMarkSweepGC false
#define UseAdaptiveSizePolicy false

#define DEFAULT_GC_TYPE GC_MARK_COLLECT

/*=================================
 *  自定义打印输出
 ==================================*/
#define INFO_OUTPUT         3
#define WARNING_OUTPUT      2
#define DEBUG_OUTPUT        1
#define ERROR_OUTPUT        0

#define DEBUG
#define DEBUG_LEVEL         INFO_OUTPUT

#endif //COMMON_H
