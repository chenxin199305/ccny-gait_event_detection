/*
 * imu_gait_detection_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "imu_gait_detection".
 *
 * Model version              : 1.758
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Sun Nov 17 20:31:40 2019
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(CAN_DATATYPE)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "CAN_DATATYPE"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&imu_gait_detection_B.PacketInput2), 14, 0, 4 },

  { (char_T *)(&imu_gait_detection_B.Clock), 0, 0, 17 }
  ,

  { (char_T *)(&imu_gait_detection_DW.PacketInput2_PWORK), 11, 0, 9 },

  { (char_T *)(&imu_gait_detection_DW.CANUnpack2_ModeSignalID), 10, 0, 7 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  4U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&imu_gait_detection_P.PacketInput2_MaxMissedTicks), 0, 0, 8 },

  { (char_T *)(&imu_gait_detection_P.PacketInput2_PacketID), 6, 0, 4 },

  { (char_T *)(&imu_gait_detection_P.Constant4_Value), 0, 0, 6 },

  { (char_T *)(&imu_gait_detection_P.Constant3_Value), 7, 0, 1 },

  { (char_T *)(&imu_gait_detection_P.Constant1_Value), 5, 0, 1 },

  { (char_T *)(&imu_gait_detection_P.Constant_Value), 3, 0, 2 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  6U,
  rtPTransitions
};

/* [EOF] imu_gait_detection_dt.h */
