/*
 * imu_gait_detection_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "imu_gait_detection".
 *
 * Model version              : 1.766
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Sun Nov 17 23:50:07 2019
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_imu_gait_detection_types_h_
#define RTW_HEADER_imu_gait_detection_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

/* Custom Type definition for MATLAB Function: '<Root>/MATLAB Function' */
#ifndef struct_emxArray_real_T_1x10
#define struct_emxArray_real_T_1x10

struct emxArray_real_T_1x10
{
  real_T data[10];
  int32_T size[2];
};

#endif                                 /*struct_emxArray_real_T_1x10*/

#ifndef typedef_emxArray_real_T_1x10_imu_gait_detection_T
#define typedef_emxArray_real_T_1x10_imu_gait_detection_T

typedef struct emxArray_real_T_1x10 emxArray_real_T_1x10_imu_gait_detection_T;

#endif                     /*typedef_emxArray_real_T_1x10_imu_gait_detection_T*/

/* Parameters (default storage) */
typedef struct P_imu_gait_detection_T_ P_imu_gait_detection_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_imu_gait_detection_T RT_MODEL_imu_gait_detection_T;

#endif                              /* RTW_HEADER_imu_gait_detection_types_h_ */
