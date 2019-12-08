/*
 * imu_gait_detection_data.c
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

#include "imu_gait_detection.h"
#include "imu_gait_detection_private.h"

/* Block parameters (default storage) */
P_imu_gait_detection_T imu_gait_detection_P = {
  /* Mask Parameter: PacketInput2_MaxMissedTicks
   * Referenced by: '<Root>/Packet Input2'
   */
  1000.0,

  /* Mask Parameter: PacketInput1_MaxMissedTicks
   * Referenced by: '<Root>/Packet Input1'
   */
  1000.0,

  /* Mask Parameter: PacketInput3_MaxMissedTicks
   * Referenced by: '<Root>/Packet Input3'
   */
  1000.0,

  /* Mask Parameter: PacketOutput_MaxMissedTicks
   * Referenced by: '<Root>/Packet Output'
   */
  1000.0,

  /* Mask Parameter: RealTimeSynchronization1_MaxMissedTicks
   * Referenced by: '<Root>/Real-Time Synchronization1'
   */
  1000.0,

  /* Mask Parameter: PacketInput2_YieldWhenWaiting
   * Referenced by: '<Root>/Packet Input2'
   */
  0.0,

  /* Mask Parameter: PacketInput1_YieldWhenWaiting
   * Referenced by: '<Root>/Packet Input1'
   */
  0.0,

  /* Mask Parameter: PacketInput3_YieldWhenWaiting
   * Referenced by: '<Root>/Packet Input3'
   */
  0.0,

  /* Mask Parameter: PacketOutput_YieldWhenWaiting
   * Referenced by: '<Root>/Packet Output'
   */
  0.0,

  /* Mask Parameter: RealTimeSynchronization1_YieldWhenWaiting
   * Referenced by: '<Root>/Real-Time Synchronization1'
   */
  0.0,

  /* Mask Parameter: PacketInput2_PacketID
   * Referenced by: '<Root>/Packet Input2'
   */
  2433,

  /* Mask Parameter: PacketInput1_PacketID
   * Referenced by: '<Root>/Packet Input1'
   */
  2689,

  /* Mask Parameter: PacketInput3_PacketID
   * Referenced by: '<Root>/Packet Input3'
   */
  2945,

  /* Mask Parameter: PacketOutput_PacketID
   * Referenced by: '<Root>/Packet Output'
   */
  2176,

  /* Expression: 100
   * Referenced by: '<Root>/Constant4'
   */
  100.0,

  /* Expression: 100
   * Referenced by: '<Root>/Constant5'
   */
  100.0,

  /* Expression: 10
   * Referenced by: '<Root>/Constant6'
   */
  10.0,

  /* Expression: 10
   * Referenced by: '<Root>/Constant7'
   */
  10.0,

  /* Expression: 10
   * Referenced by: '<Root>/Constant8'
   */
  10.0,

  /* Expression: 10
   * Referenced by: '<Root>/Constant9'
   */
  10.0,

  /* Expression: 10
   * Referenced by: '<Root>/Constant10'
   */
  10.0,

  /* Expression: 0.9
   * Referenced by: '<Root>/Constant11'
   */
  0.9,

  /* Expression: 1.1
   * Referenced by: '<Root>/Constant12'
   */
  1.1,

  /* Expression: 0.01
   * Referenced by: '<Root>/Constant13'
   */
  0.01,

  /* Expression: 100
   * Referenced by: '<Root>/Constant14'
   */
  100.0,

  /* Computed Parameter: Constant3_Value
   * Referenced by: '<Root>/Constant3'
   */
  0U,

  /* Expression: 0x0000
   * Referenced by: '<Root>/Constant1'
   */
  0U,

  /* Expression: 0x00
   * Referenced by: '<Root>/Constant'
   */
  0U,

  /* Expression: 0x00
   * Referenced by: '<Root>/Constant2'
   */
  0U
};
