/*
 * imu_gait_detection.c
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
#include "imu_gait_detection_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  0.0,
  0.0,
  0.0,
  0.0,
  1000.0,
};

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.002, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 1;
SLDRTBOARD SLDRTBoards[1] = {
  { "PEAK-System/CAN_Device", 81U, 5, SLDRTBoardOptions0 },
};

/* Block signals (default storage) */
B_imu_gait_detection_T imu_gait_detection_B;

/* Block states (default storage) */
DW_imu_gait_detection_T imu_gait_detection_DW;

/* Real-time model */
RT_MODEL_imu_gait_detection_T imu_gait_detection_M_;
RT_MODEL_imu_gait_detection_T *const imu_gait_detection_M =
  &imu_gait_detection_M_;

/* Model output function */
void imu_gait_detection_output(void)
{
  real_T *lastU;
  int32_T findPeakResult;
  int32_T findGradientResult;
  real_T peakGradient;
  real_T y;
  real_T tmp_data[10];
  real_T Clock_tmp;

  /* Clock: '<Root>/Clock' incorporates:
   *  Derivative: '<Root>/Derivative'
   *  Derivative: '<Root>/Derivative1'
   *  Derivative: '<Root>/Derivative2'
   */
  Clock_tmp = imu_gait_detection_M->Timing.t[0];
  imu_gait_detection_B.Clock = Clock_tmp;

  /* S-Function (sldrtpi): '<Root>/Packet Input2' */
  /* S-Function Block: <Root>/Packet Input2 */
  {
    uint8_T indata[8U];
    CANMSGPARM canmp;
    int status = RTBIO_DriverIO(0, STREAMINPUT, IOREAD, 8U,
      &imu_gait_detection_P.PacketInput2_PacketID, (double*) indata, &canmp);
    if (status & 0x1) {
      /* fill in the CAN_MESSAGE structure */
      CAN_MESSAGE* msg = (CAN_MESSAGE*) &imu_gait_detection_B.PacketInput2;
      int32_T pktid = imu_gait_detection_P.PacketInput2_PacketID;
      msg->Extended = pktid<=0;        /* extended ID coded as negative */
      msg->Length = canmp.msglen;
      msg->Remote = 0;
      msg->Error = (status>>1) & 0x1;
      msg->ID = pktid>0 ? (pktid & 0x7FF) : ((-pktid) & 0x1FFFFFFF);/* extended ID coded as negative */
      msg->Timestamp = canmp.timestamp;
      memcpy(&(msg->Data), indata, msg->Length);
    }
  }

  /* S-Function (sldrtpi): '<Root>/Packet Input1' */
  /* S-Function Block: <Root>/Packet Input1 */
  {
    uint8_T indata[8U];
    CANMSGPARM canmp;
    int status = RTBIO_DriverIO(0, STREAMINPUT, IOREAD, 8U,
      &imu_gait_detection_P.PacketInput1_PacketID, (double*) indata, &canmp);
    if (status & 0x1) {
      /* fill in the CAN_MESSAGE structure */
      CAN_MESSAGE* msg = (CAN_MESSAGE*) &imu_gait_detection_B.PacketInput1;
      int32_T pktid = imu_gait_detection_P.PacketInput1_PacketID;
      msg->Extended = pktid<=0;        /* extended ID coded as negative */
      msg->Length = canmp.msglen;
      msg->Remote = 0;
      msg->Error = (status>>1) & 0x1;
      msg->ID = pktid>0 ? (pktid & 0x7FF) : ((-pktid) & 0x1FFFFFFF);/* extended ID coded as negative */
      msg->Timestamp = canmp.timestamp;
      memcpy(&(msg->Data), indata, msg->Length);
    }
  }

  /* S-Function (sldrtpi): '<Root>/Packet Input3' */
  /* S-Function Block: <Root>/Packet Input3 */
  {
    uint8_T indata[8U];
    CANMSGPARM canmp;
    int status = RTBIO_DriverIO(0, STREAMINPUT, IOREAD, 8U,
      &imu_gait_detection_P.PacketInput3_PacketID, (double*) indata, &canmp);
    if (status & 0x1) {
      /* fill in the CAN_MESSAGE structure */
      CAN_MESSAGE* msg = (CAN_MESSAGE*) &imu_gait_detection_B.PacketInput3;
      int32_T pktid = imu_gait_detection_P.PacketInput3_PacketID;
      msg->Extended = pktid<=0;        /* extended ID coded as negative */
      msg->Length = canmp.msglen;
      msg->Remote = 0;
      msg->Error = (status>>1) & 0x1;
      msg->ID = pktid>0 ? (pktid & 0x7FF) : ((-pktid) & 0x1FFFFFFF);/* extended ID coded as negative */
      msg->Timestamp = canmp.timestamp;
      memcpy(&(msg->Data), indata, msg->Length);
    }
  }

  /* S-Function (scanunpack): '<Root>/CAN Unpack2' */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack2' */
    if ((8 == imu_gait_detection_B.PacketInput2.Length) &&
        (imu_gait_detection_B.PacketInput2.ID != INVALID_CAN_ID) ) {
      if ((385 == imu_gait_detection_B.PacketInput2.ID) && (0U ==
           imu_gait_detection_B.PacketInput2.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              int32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);
                int32_T* tempValuePtr = (int32_T*)&tempValue;

                {
                  tempValue = tempValue | (uint32_T)
                    (imu_gait_detection_B.PacketInput2.Data[0]);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (imu_gait_detection_B.PacketInput2.Data[1]) << 8);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (imu_gait_detection_B.PacketInput2.Data[2]) << 16);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (imu_gait_detection_B.PacketInput2.Data[3]) << 24);
                }

                unpackedValue = *tempValuePtr;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              imu_gait_detection_B.CANUnpack2_o1 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 32
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              int32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);
                int32_T* tempValuePtr = (int32_T*)&tempValue;

                {
                  tempValue = tempValue | (uint32_T)
                    (imu_gait_detection_B.PacketInput2.Data[4]);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (imu_gait_detection_B.PacketInput2.Data[5]) << 8);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (imu_gait_detection_B.PacketInput2.Data[6]) << 16);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (imu_gait_detection_B.PacketInput2.Data[7]) << 24);
                }

                unpackedValue = *tempValuePtr;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              imu_gait_detection_B.CANUnpack2_o2 = result;
            }
          }
        }
      }
    }
  }

  /* Product: '<Root>/Divide' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  imu_gait_detection_B.Divide = imu_gait_detection_B.CANUnpack2_o1 /
    imu_gait_detection_P.Constant4_Value;

  /* Product: '<Root>/Divide1' incorporates:
   *  Constant: '<Root>/Constant5'
   */
  imu_gait_detection_B.Divide1 = imu_gait_detection_B.CANUnpack2_o2 /
    imu_gait_detection_P.Constant5_Value;

  /* S-Function (scanunpack): '<Root>/CAN Unpack1' */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack1' */
    if ((8 == imu_gait_detection_B.PacketInput1.Length) &&
        (imu_gait_detection_B.PacketInput1.ID != INVALID_CAN_ID) ) {
      if ((641 == imu_gait_detection_B.PacketInput1.ID) && (0U ==
           imu_gait_detection_B.PacketInput1.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              int32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);
                int32_T* tempValuePtr = (int32_T*)&tempValue;

                {
                  tempValue = tempValue | (uint32_T)
                    (imu_gait_detection_B.PacketInput1.Data[0]);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (imu_gait_detection_B.PacketInput1.Data[1]) << 8);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (imu_gait_detection_B.PacketInput1.Data[2]) << 16);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (imu_gait_detection_B.PacketInput1.Data[3]) << 24);
                }

                unpackedValue = *tempValuePtr;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              imu_gait_detection_B.CANUnpack1_o1 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 32
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              int32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);
                int32_T* tempValuePtr = (int32_T*)&tempValue;

                {
                  tempValue = tempValue | (uint32_T)
                    (imu_gait_detection_B.PacketInput1.Data[4]);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (imu_gait_detection_B.PacketInput1.Data[5]) << 8);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (imu_gait_detection_B.PacketInput1.Data[6]) << 16);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (imu_gait_detection_B.PacketInput1.Data[7]) << 24);
                }

                unpackedValue = *tempValuePtr;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              imu_gait_detection_B.CANUnpack1_o2 = result;
            }
          }
        }
      }
    }
  }

  /* Product: '<Root>/Divide2' incorporates:
   *  Constant: '<Root>/Constant6'
   */
  imu_gait_detection_B.Divide2 = imu_gait_detection_B.CANUnpack1_o1 /
    imu_gait_detection_P.Constant6_Value;

  /* SignalConversion generated from: '<Root>/Mux1' */
  imu_gait_detection_B.TmpSignalConversionAtTAQSigLogging_InsertedFor_Mux1_at_outport_0Inport1
    [0] = imu_gait_detection_B.Clock;
  imu_gait_detection_B.TmpSignalConversionAtTAQSigLogging_InsertedFor_Mux1_at_outport_0Inport1
    [1] = imu_gait_detection_B.Divide;
  imu_gait_detection_B.TmpSignalConversionAtTAQSigLogging_InsertedFor_Mux1_at_outport_0Inport1
    [2] = imu_gait_detection_B.Divide1;
  imu_gait_detection_B.TmpSignalConversionAtTAQSigLogging_InsertedFor_Mux1_at_outport_0Inport1
    [3] = imu_gait_detection_B.Divide2;

  /* Product: '<Root>/Divide3' incorporates:
   *  Constant: '<Root>/Constant7'
   */
  imu_gait_detection_B.Divide3 = imu_gait_detection_B.CANUnpack1_o2 /
    imu_gait_detection_P.Constant7_Value;

  /* S-Function (scanunpack): '<Root>/CAN Unpack3' */
  {
    /* S-Function (scanunpack): '<Root>/CAN Unpack3' */
    if ((8 == imu_gait_detection_B.PacketInput3.Length) &&
        (imu_gait_detection_B.PacketInput3.ID != INVALID_CAN_ID) ) {
      if ((897 == imu_gait_detection_B.PacketInput3.ID) && (0U ==
           imu_gait_detection_B.PacketInput3.Extended) ) {
        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              int32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);
                int32_T* tempValuePtr = (int32_T*)&tempValue;

                {
                  tempValue = tempValue | (uint32_T)
                    (imu_gait_detection_B.PacketInput3.Data[0]);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (imu_gait_detection_B.PacketInput3.Data[1]) << 8);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (imu_gait_detection_B.PacketInput3.Data[2]) << 16);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (imu_gait_detection_B.PacketInput3.Data[3]) << 24);
                }

                unpackedValue = *tempValuePtr;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              imu_gait_detection_B.CANUnpack3_o1 = result;
            }
          }

          /* --------------- START Unpacking signal 1 ------------------
           *  startBit                = 32
           *  length                  = 32
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = SIGNED
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              int32_T unpackedValue = 0;

              {
                uint32_T tempValue = (uint32_T) (0);
                int32_T* tempValuePtr = (int32_T*)&tempValue;

                {
                  tempValue = tempValue | (uint32_T)
                    (imu_gait_detection_B.PacketInput3.Data[4]);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (imu_gait_detection_B.PacketInput3.Data[5]) << 8);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (imu_gait_detection_B.PacketInput3.Data[6]) << 16);
                  tempValue = tempValue | (uint32_T)((uint32_T)
                    (imu_gait_detection_B.PacketInput3.Data[7]) << 24);
                }

                unpackedValue = *tempValuePtr;
              }

              outValue = (real64_T) (unpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              imu_gait_detection_B.CANUnpack3_o2 = result;
            }
          }
        }
      }
    }
  }

  /* Product: '<Root>/Divide4' incorporates:
   *  Constant: '<Root>/Constant8'
   */
  imu_gait_detection_B.Divide4 = imu_gait_detection_B.CANUnpack3_o1 /
    imu_gait_detection_P.Constant8_Value;

  /* Product: '<Root>/Divide5' incorporates:
   *  Constant: '<Root>/Constant9'
   */
  imu_gait_detection_B.Divide5 = imu_gait_detection_B.CANUnpack3_o2 /
    imu_gait_detection_P.Constant9_Value;

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  Constant: '<Root>/Constant10'
   *  Constant: '<Root>/Constant11'
   *  Constant: '<Root>/Constant12'
   *  Constant: '<Root>/Constant13'
   */
  /* MATLAB Function 'MATLAB Function': '<S1>:1' */
  if (!imu_gait_detection_DW.windowLengthBuffer_not_empty) {
    /* '<S1>:1:7' */
    /* '<S1>:1:8' */
    for (findPeakResult = 0; findPeakResult < 10; findPeakResult++) {
      imu_gait_detection_DW.windowLengthBuffer.data[findPeakResult] = 0.0;
    }
  }

  if (!imu_gait_detection_DW.windowLengthFilteredBuffer_not_empty) {
    /* '<S1>:1:11' */
    /* '<S1>:1:12' */
    for (findPeakResult = 0; findPeakResult < 10; findPeakResult++) {
      imu_gait_detection_DW.windowLengthFilteredBuffer.data[findPeakResult] =
        0.0;
    }
  }

  if (!imu_gait_detection_DW.peakPositions_not_empty) {
    /* '<S1>:1:27' */
    /* '<S1>:1:28' */
    imu_gait_detection_DW.peakPositions.size[0] = 1;
    imu_gait_detection_DW.peakPositions.size[1] = 10;
    for (findPeakResult = 0; findPeakResult < 10; findPeakResult++) {
      imu_gait_detection_DW.peakPositions.data[findPeakResult] = 0.0;
    }

    imu_gait_detection_DW.peakPositions_not_empty = true;
  }

  if (!imu_gait_detection_DW.peakValues_not_empty) {
    /* '<S1>:1:31' */
    /* '<S1>:1:32' */
    imu_gait_detection_DW.peakValues.size[0] = 1;
    imu_gait_detection_DW.peakValues.size[1] = 10;
    for (findPeakResult = 0; findPeakResult < 10; findPeakResult++) {
      imu_gait_detection_DW.peakValues.data[findPeakResult] = 0.0;
    }

    imu_gait_detection_DW.peakValues_not_empty = true;
  }

  if (!imu_gait_detection_DW.peakGradients_not_empty) {
    /* '<S1>:1:35' */
    /* '<S1>:1:36' */
    imu_gait_detection_DW.peakGradients.size[0] = 1;
    imu_gait_detection_DW.peakGradients.size[1] = 10;
    for (findPeakResult = 0; findPeakResult < 10; findPeakResult++) {
      imu_gait_detection_DW.peakGradients.data[findPeakResult] = 0.0;
    }

    imu_gait_detection_DW.peakGradients_not_empty = true;
  }

  if (!imu_gait_detection_DW.TOHSThreshold_not_empty) {
    /* '<S1>:1:39' */
    if (imu_gait_detection_P.Constant10_Value > 0.0) {
      /* '<S1>:1:40' */
      /* '<S1>:1:41' */
      imu_gait_detection_DW.TOHSThreshold =
        imu_gait_detection_P.Constant10_Value;
      imu_gait_detection_DW.TOHSThreshold_not_empty = true;
    } else {
      /* '<S1>:1:43' */
      imu_gait_detection_DW.TOHSThreshold = 10.0;
      imu_gait_detection_DW.TOHSThreshold_not_empty = true;
    }
  }

  if (!imu_gait_detection_DW.TOHSPositions_not_empty) {
    /* '<S1>:1:47' */
    /* '<S1>:1:48' */
    imu_gait_detection_DW.TOHSPositions.size[0] = 1;
    imu_gait_detection_DW.TOHSPositions.size[1] = 10;
    for (findPeakResult = 0; findPeakResult < 10; findPeakResult++) {
      imu_gait_detection_DW.TOHSPositions.data[findPeakResult] = 0.0;
    }

    imu_gait_detection_DW.TOHSPositions_not_empty = true;
  }

  if (!imu_gait_detection_DW.TOHSValues_not_empty) {
    /* '<S1>:1:51' */
    /* '<S1>:1:52' */
    imu_gait_detection_DW.TOHSValues.size[0] = 1;
    imu_gait_detection_DW.TOHSValues.size[1] = 10;
    for (findPeakResult = 0; findPeakResult < 10; findPeakResult++) {
      imu_gait_detection_DW.TOHSValues.data[findPeakResult] = 0.0;
    }

    imu_gait_detection_DW.TOHSValues_not_empty = true;
  }

  if (!imu_gait_detection_DW.TOHSGradients_not_empty) {
    /* '<S1>:1:55' */
    /* '<S1>:1:56' */
    imu_gait_detection_DW.TOHSGradients.size[0] = 1;
    imu_gait_detection_DW.TOHSGradients.size[1] = 10;
    for (findPeakResult = 0; findPeakResult < 10; findPeakResult++) {
      imu_gait_detection_DW.TOHSGradients.data[findPeakResult] = 0.0;
    }

    imu_gait_detection_DW.TOHSGradients_not_empty = true;
  }

  if (!imu_gait_detection_DW.HSPositions_not_empty) {
    /* '<S1>:1:79' */
    /* '<S1>:1:80' */
    imu_gait_detection_DW.HSPositions.size[0] = 1;
    imu_gait_detection_DW.HSPositions.size[1] = 10;
    for (findPeakResult = 0; findPeakResult < 10; findPeakResult++) {
      imu_gait_detection_DW.HSPositions.data[findPeakResult] = 0.0;
    }

    imu_gait_detection_DW.HSPositions_not_empty = true;
  }

  if (!imu_gait_detection_DW.HSValues_not_empty) {
    /* '<S1>:1:83' */
    /* '<S1>:1:84' */
    imu_gait_detection_DW.HSValues.size[0] = 1;
    imu_gait_detection_DW.HSValues.size[1] = 10;
    for (findPeakResult = 0; findPeakResult < 10; findPeakResult++) {
      imu_gait_detection_DW.HSValues.data[findPeakResult] = 0.0;
    }

    imu_gait_detection_DW.HSValues_not_empty = true;
  }

  if (!imu_gait_detection_DW.HSGradients_not_empty) {
    /* '<S1>:1:87' */
    /* '<S1>:1:88' */
    imu_gait_detection_DW.HSGradients.size[0] = 1;
    imu_gait_detection_DW.HSGradients.size[1] = 10;
    for (findPeakResult = 0; findPeakResult < 10; findPeakResult++) {
      imu_gait_detection_DW.HSGradients.data[findPeakResult] = 0.0;
    }

    imu_gait_detection_DW.HSGradients_not_empty = true;
  }

  if (!imu_gait_detection_DW.TOPositions_not_empty) {
    /* '<S1>:1:95' */
    /* '<S1>:1:96' */
    imu_gait_detection_DW.TOPositions.size[0] = 1;
    imu_gait_detection_DW.TOPositions.size[1] = 10;
    for (findPeakResult = 0; findPeakResult < 10; findPeakResult++) {
      imu_gait_detection_DW.TOPositions.data[findPeakResult] = 0.0;
    }

    imu_gait_detection_DW.TOPositions_not_empty = true;
  }

  if (!imu_gait_detection_DW.TOValues_not_empty) {
    /* '<S1>:1:99' */
    /* '<S1>:1:100' */
    imu_gait_detection_DW.TOValues.size[0] = 1;
    imu_gait_detection_DW.TOValues.size[1] = 10;
    for (findPeakResult = 0; findPeakResult < 10; findPeakResult++) {
      imu_gait_detection_DW.TOValues.data[findPeakResult] = 0.0;
    }

    imu_gait_detection_DW.TOValues_not_empty = true;
  }

  if (!imu_gait_detection_DW.TOGradients_not_empty) {
    /* '<S1>:1:103' */
    /* '<S1>:1:104' */
    imu_gait_detection_DW.TOGradients.size[0] = 1;
    imu_gait_detection_DW.TOGradients.size[1] = 10;
    for (findPeakResult = 0; findPeakResult < 10; findPeakResult++) {
      imu_gait_detection_DW.TOGradients.data[findPeakResult] = 0.0;
    }

    imu_gait_detection_DW.TOGradients_not_empty = true;
  }

  if (!imu_gait_detection_DW.stepLengths_not_empty) {
    /* '<S1>:1:107' */
    /* '<S1>:1:108' */
    imu_gait_detection_DW.stepLengths.size[0] = 1;
    imu_gait_detection_DW.stepLengths.size[1] = 10;
    for (findPeakResult = 0; findPeakResult < 10; findPeakResult++) {
      imu_gait_detection_DW.stepLengths.data[findPeakResult] = 0.0;
    }

    imu_gait_detection_DW.stepLengths_not_empty = true;
  }

  if (!imu_gait_detection_DW.stepPositions_not_empty) {
    /* '<S1>:1:115' */
    /* '<S1>:1:116' */
    imu_gait_detection_DW.stepPositions.size[0] = 1;
    imu_gait_detection_DW.stepPositions.size[1] = 10;
    for (findPeakResult = 0; findPeakResult < 10; findPeakResult++) {
      imu_gait_detection_DW.stepPositions.data[findPeakResult] = 0.0;
    }

    imu_gait_detection_DW.stepPositions_not_empty = true;
  }

  if (!imu_gait_detection_DW.stepValues_not_empty) {
    /* '<S1>:1:119' */
    /* '<S1>:1:120' */
    imu_gait_detection_DW.stepValues.size[0] = 1;
    imu_gait_detection_DW.stepValues.size[1] = 10;
    for (findPeakResult = 0; findPeakResult < 10; findPeakResult++) {
      imu_gait_detection_DW.stepValues.data[findPeakResult] = 0.0;
    }

    imu_gait_detection_DW.stepValues_not_empty = true;
  }

  /* '<S1>:1:127' */
  imu_gait_detection_DW.TimeStartHS++;

  /* '<S1>:1:128' */
  imu_gait_detection_DW.timeTickCount++;

  /* '<S1>:1:130' */
  for (findPeakResult = 0; findPeakResult < 9; findPeakResult++) {
    tmp_data[findPeakResult] =
      imu_gait_detection_DW.windowLengthBuffer.data[findPeakResult + 1];
  }

  tmp_data[9] = imu_gait_detection_B.Divide5;
  imu_gait_detection_DW.windowLengthBuffer.size[0] = 1;
  imu_gait_detection_DW.windowLengthBuffer.size[1] = 10;
  for (findPeakResult = 0; findPeakResult < 10; findPeakResult++) {
    imu_gait_detection_DW.windowLengthBuffer.data[findPeakResult] =
      tmp_data[findPeakResult];
  }

  imu_gait_detection_DW.windowLengthBuffer_not_empty = true;

  /* '<S1>:1:132' */
  y = imu_gait_detection_DW.windowLengthBuffer.data[0];
  for (findPeakResult = 0; findPeakResult < 9; findPeakResult++) {
    y += imu_gait_detection_DW.windowLengthBuffer.data[findPeakResult + 1];
  }

  y /= 10.0;

  /* '<S1>:1:133' */
  imu_gait_detection_DW.stepLength++;

  /* '<S1>:1:135' */
  for (findPeakResult = 0; findPeakResult < 9; findPeakResult++) {
    tmp_data[findPeakResult] =
      imu_gait_detection_DW.windowLengthFilteredBuffer.data[findPeakResult + 1];
  }

  tmp_data[9] = y;
  imu_gait_detection_DW.windowLengthFilteredBuffer.size[0] = 1;
  imu_gait_detection_DW.windowLengthFilteredBuffer.size[1] = 10;
  for (findPeakResult = 0; findPeakResult < 10; findPeakResult++) {
    imu_gait_detection_DW.windowLengthFilteredBuffer.data[findPeakResult] =
      tmp_data[findPeakResult];
  }

  imu_gait_detection_DW.windowLengthFilteredBuffer_not_empty = true;

  /* '<S1>:1:138' */
  /* '<S1>:1:139' */
  findPeakResult = 1;

  /* '<S1>:1:140' */
  for (findGradientResult = 0; findGradientResult < 10; findGradientResult++) {
    /* '<S1>:1:140' */
    if (!(imu_gait_detection_DW.windowLengthFilteredBuffer.data[findGradientResult]
          <= imu_gait_detection_DW.windowLengthFilteredBuffer.data[4])) {
      /* '<S1>:1:143' */
      findPeakResult = 0;
    } else {
      /* '<S1>:1:141' */
    }
  }

  /* '<S1>:1:147' */
  if (findPeakResult == 1) {
    /* '<S1>:1:148' */
    /* '<S1>:1:150' */
    for (findPeakResult = 0; findPeakResult < 9; findPeakResult++) {
      tmp_data[findPeakResult] =
        imu_gait_detection_DW.peakPositions.data[findPeakResult + 1];
    }

    tmp_data[9] = imu_gait_detection_DW.timeTickCount - 4.0;
    imu_gait_detection_DW.peakPositions.size[0] = 1;
    imu_gait_detection_DW.peakPositions.size[1] = 10;
    for (findPeakResult = 0; findPeakResult < 10; findPeakResult++) {
      imu_gait_detection_DW.peakPositions.data[findPeakResult] =
        tmp_data[findPeakResult];
    }

    imu_gait_detection_DW.peakPositions_not_empty = true;

    /* '<S1>:1:151' */
    for (findPeakResult = 0; findPeakResult < 9; findPeakResult++) {
      tmp_data[findPeakResult] =
        imu_gait_detection_DW.peakValues.data[findPeakResult + 1];
    }

    tmp_data[9] = imu_gait_detection_DW.windowLengthFilteredBuffer.data[4];
    imu_gait_detection_DW.peakValues.size[0] = 1;
    imu_gait_detection_DW.peakValues.size[1] = 10;
    for (findPeakResult = 0; findPeakResult < 10; findPeakResult++) {
      imu_gait_detection_DW.peakValues.data[findPeakResult] =
        tmp_data[findPeakResult];
    }

    imu_gait_detection_DW.peakValues_not_empty = true;

    /* '<S1>:1:156' */
    /* '<S1>:1:157' */
    /* '<S1>:1:158' */
    peakGradient = ((imu_gait_detection_DW.windowLengthFilteredBuffer.data[4] -
                     imu_gait_detection_DW.windowLengthFilteredBuffer.data[0]) /
                    4.0 +
                    (imu_gait_detection_DW.windowLengthFilteredBuffer.data[4] -
                     imu_gait_detection_DW.windowLengthFilteredBuffer.data[8]) /
                    4.0) / 2.0;

    /* '<S1>:1:159' */
    for (findPeakResult = 0; findPeakResult < 9; findPeakResult++) {
      tmp_data[findPeakResult] =
        imu_gait_detection_DW.peakGradients.data[findPeakResult + 1];
    }

    tmp_data[9] = peakGradient;
    imu_gait_detection_DW.peakGradients.size[0] = 1;
    imu_gait_detection_DW.peakGradients.size[1] = 10;
    for (findPeakResult = 0; findPeakResult < 10; findPeakResult++) {
      imu_gait_detection_DW.peakGradients.data[findPeakResult] =
        tmp_data[findPeakResult];
    }

    imu_gait_detection_DW.peakGradients_not_empty = true;
    if (peakGradient > imu_gait_detection_DW.TOHSThreshold) {
      /* '<S1>:1:160' */
      /* '<S1>:1:161' */
      /* '<S1>:1:166' */
      /* '<S1>:1:167' */
      for (findPeakResult = 0; findPeakResult < 9; findPeakResult++) {
        tmp_data[findPeakResult] =
          imu_gait_detection_DW.TOHSPositions.data[findPeakResult + 1];
      }

      tmp_data[9] = imu_gait_detection_DW.peakPositions.data[9];
      imu_gait_detection_DW.TOHSPositions.size[0] = 1;
      imu_gait_detection_DW.TOHSPositions.size[1] = 10;
      for (findPeakResult = 0; findPeakResult < 10; findPeakResult++) {
        imu_gait_detection_DW.TOHSPositions.data[findPeakResult] =
          tmp_data[findPeakResult];
      }

      imu_gait_detection_DW.TOHSPositions_not_empty = true;

      /* '<S1>:1:168' */
      for (findPeakResult = 0; findPeakResult < 9; findPeakResult++) {
        tmp_data[findPeakResult] =
          imu_gait_detection_DW.TOHSValues.data[findPeakResult + 1];
      }

      tmp_data[9] = imu_gait_detection_DW.peakValues.data[9];
      imu_gait_detection_DW.TOHSValues.size[0] = 1;
      imu_gait_detection_DW.TOHSValues.size[1] = 10;
      for (findPeakResult = 0; findPeakResult < 10; findPeakResult++) {
        imu_gait_detection_DW.TOHSValues.data[findPeakResult] =
          tmp_data[findPeakResult];
      }

      imu_gait_detection_DW.TOHSValues_not_empty = true;

      /* '<S1>:1:169' */
      for (findPeakResult = 0; findPeakResult < 9; findPeakResult++) {
        tmp_data[findPeakResult] =
          imu_gait_detection_DW.TOHSGradients.data[findPeakResult + 1];
      }

      tmp_data[9] = imu_gait_detection_DW.peakGradients.data[9];
      imu_gait_detection_DW.TOHSGradients.size[0] = 1;
      imu_gait_detection_DW.TOHSGradients.size[1] = 10;
      for (findPeakResult = 0; findPeakResult < 10; findPeakResult++) {
        imu_gait_detection_DW.TOHSGradients.data[findPeakResult] =
          tmp_data[findPeakResult];
      }

      imu_gait_detection_DW.TOHSGradients_not_empty = true;

      /* '<S1>:1:170' */
      imu_gait_detection_DW.TOHSDetectFlag++;

      /* '<S1>:1:182' */
      if (imu_gait_detection_DW.TOHSDetectFlag <= 1.0) {
        /* '<S1>:1:183' */
        /* '<S1>:1:184' */
        imu_gait_detection_DW.detectResult = -1.0;

        /* '<S1>:1:185' */
        imu_gait_detection_DW.TimeStartHS = 0.0;

        /* '<S1>:1:186' */
        imu_gait_detection_DW.lastHS = imu_gait_detection_DW.timeTickCount;

        /* '<S1>:1:187' */
        imu_gait_detection_DW.Timeswing = imu_gait_detection_DW.lastHS -
          imu_gait_detection_DW.lastTO;

        /* '<S1>:1:188' */
        for (findPeakResult = 0; findPeakResult < 9; findPeakResult++) {
          tmp_data[findPeakResult] =
            imu_gait_detection_DW.HSPositions.data[findPeakResult + 1];
        }

        tmp_data[9] = imu_gait_detection_DW.TOHSPositions.data[9];
        imu_gait_detection_DW.HSPositions.size[0] = 1;
        imu_gait_detection_DW.HSPositions.size[1] = 10;
        for (findPeakResult = 0; findPeakResult < 10; findPeakResult++) {
          imu_gait_detection_DW.HSPositions.data[findPeakResult] =
            tmp_data[findPeakResult];
        }

        imu_gait_detection_DW.HSPositions_not_empty = true;

        /* '<S1>:1:189' */
        for (findPeakResult = 0; findPeakResult < 9; findPeakResult++) {
          tmp_data[findPeakResult] =
            imu_gait_detection_DW.HSValues.data[findPeakResult + 1];
        }

        tmp_data[9] = imu_gait_detection_DW.TOHSValues.data[9];
        imu_gait_detection_DW.HSValues.size[0] = 1;
        imu_gait_detection_DW.HSValues.size[1] = 10;
        for (findPeakResult = 0; findPeakResult < 10; findPeakResult++) {
          imu_gait_detection_DW.HSValues.data[findPeakResult] =
            tmp_data[findPeakResult];
        }

        imu_gait_detection_DW.HSValues_not_empty = true;

        /* '<S1>:1:190' */
        for (findPeakResult = 0; findPeakResult < 9; findPeakResult++) {
          tmp_data[findPeakResult] =
            imu_gait_detection_DW.HSGradients.data[findPeakResult + 1];
        }

        tmp_data[9] = imu_gait_detection_DW.TOHSGradients.data[9];
        imu_gait_detection_DW.HSGradients.size[0] = 1;
        imu_gait_detection_DW.HSGradients.size[1] = 10;
        for (findPeakResult = 0; findPeakResult < 10; findPeakResult++) {
          imu_gait_detection_DW.HSGradients.data[findPeakResult] =
            tmp_data[findPeakResult];
        }

        imu_gait_detection_DW.HSGradients_not_empty = true;
      } else {
        /* '<S1>:1:192' */
        imu_gait_detection_DW.detectResult = 1.0;

        /* '<S1>:1:193' */
        imu_gait_detection_DW.lastTO = imu_gait_detection_DW.timeTickCount;

        /* '<S1>:1:194' */
        imu_gait_detection_DW.Timestance = imu_gait_detection_DW.lastTO -
          imu_gait_detection_DW.lastHS;

        /* '<S1>:1:195' */
        imu_gait_detection_DW.TimeStartHS = imu_gait_detection_DW.Timestance;

        /* '<S1>:1:196' */
        for (findPeakResult = 0; findPeakResult < 9; findPeakResult++) {
          tmp_data[findPeakResult] =
            imu_gait_detection_DW.TOPositions.data[findPeakResult + 1];
        }

        tmp_data[9] = imu_gait_detection_DW.TOHSPositions.data[9];
        imu_gait_detection_DW.TOPositions.size[0] = 1;
        imu_gait_detection_DW.TOPositions.size[1] = 10;
        for (findPeakResult = 0; findPeakResult < 10; findPeakResult++) {
          imu_gait_detection_DW.TOPositions.data[findPeakResult] =
            tmp_data[findPeakResult];
        }

        imu_gait_detection_DW.TOPositions_not_empty = true;

        /* '<S1>:1:197' */
        for (findPeakResult = 0; findPeakResult < 9; findPeakResult++) {
          tmp_data[findPeakResult] =
            imu_gait_detection_DW.TOValues.data[findPeakResult + 1];
        }

        tmp_data[9] = imu_gait_detection_DW.TOHSValues.data[9];
        imu_gait_detection_DW.TOValues.size[0] = 1;
        imu_gait_detection_DW.TOValues.size[1] = 10;
        for (findPeakResult = 0; findPeakResult < 10; findPeakResult++) {
          imu_gait_detection_DW.TOValues.data[findPeakResult] =
            tmp_data[findPeakResult];
        }

        imu_gait_detection_DW.TOValues_not_empty = true;

        /* '<S1>:1:198' */
        for (findPeakResult = 0; findPeakResult < 9; findPeakResult++) {
          tmp_data[findPeakResult] =
            imu_gait_detection_DW.TOGradients.data[findPeakResult + 1];
        }

        tmp_data[9] = imu_gait_detection_DW.TOHSGradients.data[9];
        imu_gait_detection_DW.TOGradients.size[0] = 1;
        imu_gait_detection_DW.TOGradients.size[1] = 10;
        for (findPeakResult = 0; findPeakResult < 10; findPeakResult++) {
          imu_gait_detection_DW.TOGradients.data[findPeakResult] =
            tmp_data[findPeakResult];
        }

        imu_gait_detection_DW.TOGradients_not_empty = true;
      }
    } else {
      /* '<S1>:1:163' */
    }
  }

  /* '<S1>:1:203' */
  /* '<S1>:1:204' */
  /* '<S1>:1:205' */
  /* '<S1>:1:207' */
  /* '<S1>:1:208' */
  if (((imu_gait_detection_DW.windowLengthFilteredBuffer.data[8] -
        imu_gait_detection_DW.windowLengthFilteredBuffer.data[7]) /
       imu_gait_detection_P.Constant13_Value < 0.0) &&
      ((imu_gait_detection_DW.windowLengthFilteredBuffer.data[9] -
        imu_gait_detection_DW.windowLengthFilteredBuffer.data[8]) /
       imu_gait_detection_P.Constant13_Value > 0.0) &&
      (imu_gait_detection_DW.windowLengthFilteredBuffer.data[9] <= -50.0)) {
    /* '<S1>:1:210' */
    if (imu_gait_detection_DW.TOHSDetectFlag > 2.0) {
      /* '<S1>:1:222' */
      /* '<S1>:1:223' */
      imu_gait_detection_DW.TOHSThreshold *=
        imu_gait_detection_P.Constant11_Value;
    } else {
      if (imu_gait_detection_DW.TOHSDetectFlag < 2.0) {
        /* '<S1>:1:224' */
        /* '<S1>:1:225' */
        imu_gait_detection_DW.TOHSThreshold *=
          imu_gait_detection_P.Constant12_Value;
      }
    }

    /* '<S1>:1:229' */
    for (findPeakResult = 0; findPeakResult < 9; findPeakResult++) {
      tmp_data[findPeakResult] =
        imu_gait_detection_DW.stepLengths.data[findPeakResult + 1];
    }

    tmp_data[9] = imu_gait_detection_DW.stepLength;
    imu_gait_detection_DW.stepLengths.size[0] = 1;
    imu_gait_detection_DW.stepLengths.size[1] = 10;
    for (findPeakResult = 0; findPeakResult < 10; findPeakResult++) {
      imu_gait_detection_DW.stepLengths.data[findPeakResult] =
        tmp_data[findPeakResult];
    }

    imu_gait_detection_DW.stepLengths_not_empty = true;

    /* '<S1>:1:230' */
    imu_gait_detection_DW.stepLength = 0.0;

    /* '<S1>:1:240' */
    imu_gait_detection_DW.stepCount++;

    /* '<S1>:1:241' */
    for (findPeakResult = 0; findPeakResult < 9; findPeakResult++) {
      tmp_data[findPeakResult] =
        imu_gait_detection_DW.stepPositions.data[findPeakResult + 1];
    }

    tmp_data[9] = imu_gait_detection_DW.timeTickCount;
    imu_gait_detection_DW.stepPositions.size[0] = 1;
    imu_gait_detection_DW.stepPositions.size[1] = 10;
    for (findPeakResult = 0; findPeakResult < 10; findPeakResult++) {
      imu_gait_detection_DW.stepPositions.data[findPeakResult] =
        tmp_data[findPeakResult];
    }

    imu_gait_detection_DW.stepPositions_not_empty = true;

    /* '<S1>:1:242' */
    for (findPeakResult = 0; findPeakResult < 9; findPeakResult++) {
      tmp_data[findPeakResult] =
        imu_gait_detection_DW.stepValues.data[findPeakResult + 1];
    }

    tmp_data[9] = y;
    imu_gait_detection_DW.stepValues.size[0] = 1;
    imu_gait_detection_DW.stepValues.size[1] = 10;
    for (findPeakResult = 0; findPeakResult < 10; findPeakResult++) {
      imu_gait_detection_DW.stepValues.data[findPeakResult] =
        tmp_data[findPeakResult];
    }

    imu_gait_detection_DW.stepValues_not_empty = true;

    /* '<S1>:1:245' */
    imu_gait_detection_DW.TOHSDetectFlag = 0.0;

    /* '<S1>:1:246' */
    imu_gait_detection_DW.detectResult = 0.0;
  }

  /* '<S1>:1:248' */
  imu_gait_detection_B.PercentGait = imu_gait_detection_DW.TimeStartHS /
    (imu_gait_detection_DW.Timeswing + imu_gait_detection_DW.Timestance) * 100.0;

  /* '<S1>:1:249' */
  imu_gait_detection_B.newInputTrainingFilteredValue = y;

  /* Product: '<Root>/Multiply' incorporates:
   *  Constant: '<Root>/Constant14'
   *  MATLAB Function: '<Root>/MATLAB Function'
   */
  imu_gait_detection_B.Multiply = imu_gait_detection_DW.detectResult *
    imu_gait_detection_P.Constant14_Value;

  /* ToAsyncQueueBlock generated from: '<Root>/Mux1' */
  {
    {
      double time = imu_gait_detection_M->Timing.t[1];
      void *pData = (void *)
        &imu_gait_detection_B.TmpSignalConversionAtTAQSigLogging_InsertedFor_Mux1_at_outport_0Inport1
        [0];
      int32_T size = 4*sizeof(real_T);
      sendToAsyncQueueTgtAppSvc(739203683U, time, pData, size);
    }
  }

  /* Derivative: '<Root>/Derivative' */
  if ((imu_gait_detection_DW.TimeStampA >= Clock_tmp) &&
      (imu_gait_detection_DW.TimeStampB >= Clock_tmp)) {
    imu_gait_detection_B.Derivative = 0.0;
  } else {
    y = imu_gait_detection_DW.TimeStampA;
    lastU = &imu_gait_detection_DW.LastUAtTimeA;
    if (imu_gait_detection_DW.TimeStampA < imu_gait_detection_DW.TimeStampB) {
      if (imu_gait_detection_DW.TimeStampB < Clock_tmp) {
        y = imu_gait_detection_DW.TimeStampB;
        lastU = &imu_gait_detection_DW.LastUAtTimeB;
      }
    } else {
      if (imu_gait_detection_DW.TimeStampA >= Clock_tmp) {
        y = imu_gait_detection_DW.TimeStampB;
        lastU = &imu_gait_detection_DW.LastUAtTimeB;
      }
    }

    imu_gait_detection_B.Derivative = (imu_gait_detection_B.Divide - *lastU) /
      (Clock_tmp - y);
  }

  /* Derivative: '<Root>/Derivative1' */
  if ((imu_gait_detection_DW.TimeStampA_l >= Clock_tmp) &&
      (imu_gait_detection_DW.TimeStampB_l >= Clock_tmp)) {
    imu_gait_detection_B.Derivative1 = 0.0;
  } else {
    y = imu_gait_detection_DW.TimeStampA_l;
    lastU = &imu_gait_detection_DW.LastUAtTimeA_h;
    if (imu_gait_detection_DW.TimeStampA_l < imu_gait_detection_DW.TimeStampB_l)
    {
      if (imu_gait_detection_DW.TimeStampB_l < Clock_tmp) {
        y = imu_gait_detection_DW.TimeStampB_l;
        lastU = &imu_gait_detection_DW.LastUAtTimeB_d;
      }
    } else {
      if (imu_gait_detection_DW.TimeStampA_l >= Clock_tmp) {
        y = imu_gait_detection_DW.TimeStampB_l;
        lastU = &imu_gait_detection_DW.LastUAtTimeB_d;
      }
    }

    imu_gait_detection_B.Derivative1 = (imu_gait_detection_B.Divide1 - *lastU) /
      (Clock_tmp - y);
  }

  /* Derivative: '<Root>/Derivative2' */
  if ((imu_gait_detection_DW.TimeStampA_i >= Clock_tmp) &&
      (imu_gait_detection_DW.TimeStampB_e >= Clock_tmp)) {
    imu_gait_detection_B.Derivative2 = 0.0;
  } else {
    y = imu_gait_detection_DW.TimeStampA_i;
    lastU = &imu_gait_detection_DW.LastUAtTimeA_g;
    if (imu_gait_detection_DW.TimeStampA_i < imu_gait_detection_DW.TimeStampB_e)
    {
      if (imu_gait_detection_DW.TimeStampB_e < Clock_tmp) {
        y = imu_gait_detection_DW.TimeStampB_e;
        lastU = &imu_gait_detection_DW.LastUAtTimeB_m;
      }
    } else {
      if (imu_gait_detection_DW.TimeStampA_i >= Clock_tmp) {
        y = imu_gait_detection_DW.TimeStampB_e;
        lastU = &imu_gait_detection_DW.LastUAtTimeB_m;
      }
    }

    imu_gait_detection_B.Derivative2 = (imu_gait_detection_B.Divide2 - *lastU) /
      (Clock_tmp - y);
  }

  /* S-Function (sldrtpo): '<Root>/Packet Output' */
  /* S-Function Block: <Root>/Packet Output */

  /* no code required */

  /* S-Function (scanpack): '<Root>/CAN Pack1' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   */
  /* S-Function (scanpack): '<Root>/CAN Pack1' */
  imu_gait_detection_B.CANPack1.ID = 128U;
  imu_gait_detection_B.CANPack1.Length = 8U;
  imu_gait_detection_B.CANPack1.Extended = 0U;
  imu_gait_detection_B.CANPack1.Remote = 0;
  imu_gait_detection_B.CANPack1.Data[0] = 0;
  imu_gait_detection_B.CANPack1.Data[1] = 0;
  imu_gait_detection_B.CANPack1.Data[2] = 0;
  imu_gait_detection_B.CANPack1.Data[3] = 0;
  imu_gait_detection_B.CANPack1.Data[4] = 0;
  imu_gait_detection_B.CANPack1.Data[5] = 0;
  imu_gait_detection_B.CANPack1.Data[6] = 0;
  imu_gait_detection_B.CANPack1.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 0
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (imu_gait_detection_P.Constant_Value);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        packedValue = (uint8_T) (packingValue);

        {
          {
            imu_gait_detection_B.CANPack1.Data[0] =
              imu_gait_detection_B.CANPack1.Data[0] | (uint8_T)(packedValue);
          }
        }
      }
    }

    /* --------------- START Packing signal 1 ------------------
     *  startBit                = 8
     *  length                  = 16
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (imu_gait_detection_P.Constant1_Value);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint16_T packedValue;
        packedValue = (uint16_T) (packingValue);

        {
          {
            imu_gait_detection_B.CANPack1.Data[1] =
              imu_gait_detection_B.CANPack1.Data[1] | (uint8_T)((uint16_T)
              (packedValue & (uint16_T)0xFFU));
            imu_gait_detection_B.CANPack1.Data[2] =
              imu_gait_detection_B.CANPack1.Data[2] | (uint8_T)((uint16_T)
              ((uint16_T)(packedValue & (uint16_T)0xFF00U) >> 8));
          }
        }
      }
    }

    /* --------------- START Packing signal 2 ------------------
     *  startBit                = 24
     *  length                  = 8
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (imu_gait_detection_P.Constant2_Value);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint8_T packedValue;
        packedValue = (uint8_T) (packingValue);

        {
          {
            imu_gait_detection_B.CANPack1.Data[3] =
              imu_gait_detection_B.CANPack1.Data[3] | (uint8_T)(packedValue);
          }
        }
      }
    }

    /* --------------- START Packing signal 3 ------------------
     *  startBit                = 32
     *  length                  = 32
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = UNSIGNED
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      uint32_T packingValue = 0;

      {
        uint32_T result = (uint32_T) (imu_gait_detection_P.Constant3_Value);

        /* no scaling required */
        packingValue = result;
      }

      {
        uint32_T packedValue;
        packedValue = (uint32_T) (packingValue);

        {
          {
            imu_gait_detection_B.CANPack1.Data[4] =
              imu_gait_detection_B.CANPack1.Data[4] | (uint8_T)((uint32_T)
              (packedValue & (uint32_T)0xFFU));
            imu_gait_detection_B.CANPack1.Data[5] =
              imu_gait_detection_B.CANPack1.Data[5] | (uint8_T)((uint32_T)
              ((uint32_T)(packedValue & (uint32_T)0xFF00U) >> 8));
            imu_gait_detection_B.CANPack1.Data[6] =
              imu_gait_detection_B.CANPack1.Data[6] | (uint8_T)((uint32_T)
              ((uint32_T)(packedValue & (uint32_T)0xFF0000U) >> 16));
            imu_gait_detection_B.CANPack1.Data[7] =
              imu_gait_detection_B.CANPack1.Data[7] | (uint8_T)((uint32_T)
              ((uint32_T)(packedValue & (uint32_T)0xFF000000U) >> 24));
          }
        }
      }
    }
  }

  /* S-Function (sldrtsync): '<Root>/Real-Time Synchronization1' */
  /* S-Function Block: <Root>/Real-Time Synchronization1 */
  {
    imu_gait_detection_B.RealTimeSynchronization1 = 0;/* Missed Ticks value is always zero */
  }
}

/* Model update function */
void imu_gait_detection_update(void)
{
  real_T *lastU;

  /* Update for Derivative: '<Root>/Derivative' */
  if (imu_gait_detection_DW.TimeStampA == (rtInf)) {
    imu_gait_detection_DW.TimeStampA = imu_gait_detection_M->Timing.t[0];
    lastU = &imu_gait_detection_DW.LastUAtTimeA;
  } else if (imu_gait_detection_DW.TimeStampB == (rtInf)) {
    imu_gait_detection_DW.TimeStampB = imu_gait_detection_M->Timing.t[0];
    lastU = &imu_gait_detection_DW.LastUAtTimeB;
  } else if (imu_gait_detection_DW.TimeStampA < imu_gait_detection_DW.TimeStampB)
  {
    imu_gait_detection_DW.TimeStampA = imu_gait_detection_M->Timing.t[0];
    lastU = &imu_gait_detection_DW.LastUAtTimeA;
  } else {
    imu_gait_detection_DW.TimeStampB = imu_gait_detection_M->Timing.t[0];
    lastU = &imu_gait_detection_DW.LastUAtTimeB;
  }

  *lastU = imu_gait_detection_B.Divide;

  /* End of Update for Derivative: '<Root>/Derivative' */

  /* Update for Derivative: '<Root>/Derivative1' */
  if (imu_gait_detection_DW.TimeStampA_l == (rtInf)) {
    imu_gait_detection_DW.TimeStampA_l = imu_gait_detection_M->Timing.t[0];
    lastU = &imu_gait_detection_DW.LastUAtTimeA_h;
  } else if (imu_gait_detection_DW.TimeStampB_l == (rtInf)) {
    imu_gait_detection_DW.TimeStampB_l = imu_gait_detection_M->Timing.t[0];
    lastU = &imu_gait_detection_DW.LastUAtTimeB_d;
  } else if (imu_gait_detection_DW.TimeStampA_l <
             imu_gait_detection_DW.TimeStampB_l) {
    imu_gait_detection_DW.TimeStampA_l = imu_gait_detection_M->Timing.t[0];
    lastU = &imu_gait_detection_DW.LastUAtTimeA_h;
  } else {
    imu_gait_detection_DW.TimeStampB_l = imu_gait_detection_M->Timing.t[0];
    lastU = &imu_gait_detection_DW.LastUAtTimeB_d;
  }

  *lastU = imu_gait_detection_B.Divide1;

  /* End of Update for Derivative: '<Root>/Derivative1' */

  /* Update for Derivative: '<Root>/Derivative2' */
  if (imu_gait_detection_DW.TimeStampA_i == (rtInf)) {
    imu_gait_detection_DW.TimeStampA_i = imu_gait_detection_M->Timing.t[0];
    lastU = &imu_gait_detection_DW.LastUAtTimeA_g;
  } else if (imu_gait_detection_DW.TimeStampB_e == (rtInf)) {
    imu_gait_detection_DW.TimeStampB_e = imu_gait_detection_M->Timing.t[0];
    lastU = &imu_gait_detection_DW.LastUAtTimeB_m;
  } else if (imu_gait_detection_DW.TimeStampA_i <
             imu_gait_detection_DW.TimeStampB_e) {
    imu_gait_detection_DW.TimeStampA_i = imu_gait_detection_M->Timing.t[0];
    lastU = &imu_gait_detection_DW.LastUAtTimeA_g;
  } else {
    imu_gait_detection_DW.TimeStampB_e = imu_gait_detection_M->Timing.t[0];
    lastU = &imu_gait_detection_DW.LastUAtTimeB_m;
  }

  *lastU = imu_gait_detection_B.Divide2;

  /* End of Update for Derivative: '<Root>/Derivative2' */

  /* Update for S-Function (sldrtpo): '<Root>/Packet Output' */

  /* S-Function Block: <Root>/Packet Output */
  {
    const CAN_MESSAGE* msg = (const CAN_MESSAGE*) &imu_gait_detection_B.CANPack1;
    int32_T pktid = msg->Extended ? -msg->ID : (msg->ID | 0x800);
    RTBIO_DriverIO(0, STREAMOUTPUT, IOWRITE, msg->Length, &pktid, (double*)
                   (&msg->Data), NULL);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++imu_gait_detection_M->Timing.clockTick0)) {
    ++imu_gait_detection_M->Timing.clockTickH0;
  }

  imu_gait_detection_M->Timing.t[0] = imu_gait_detection_M->Timing.clockTick0 *
    imu_gait_detection_M->Timing.stepSize0 +
    imu_gait_detection_M->Timing.clockTickH0 *
    imu_gait_detection_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.002s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++imu_gait_detection_M->Timing.clockTick1)) {
      ++imu_gait_detection_M->Timing.clockTickH1;
    }

    imu_gait_detection_M->Timing.t[1] = imu_gait_detection_M->Timing.clockTick1 *
      imu_gait_detection_M->Timing.stepSize1 +
      imu_gait_detection_M->Timing.clockTickH1 *
      imu_gait_detection_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void imu_gait_detection_initialize(void)
{
  /* Start for S-Function (scanunpack): '<Root>/CAN Unpack2' */

  /*-----------S-Function Block: <Root>/CAN Unpack2 -----------------*/

  /* Start for S-Function (scanunpack): '<Root>/CAN Unpack1' */

  /*-----------S-Function Block: <Root>/CAN Unpack1 -----------------*/

  /* Start for S-Function (scanunpack): '<Root>/CAN Unpack3' */

  /*-----------S-Function Block: <Root>/CAN Unpack3 -----------------*/

  /* Start for S-Function (sldrtpo): '<Root>/Packet Output' */

  /* S-Function Block: <Root>/Packet Output */
  /* no initial value should be set */

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  imu_gait_detection_DW.TimeStampA = (rtInf);
  imu_gait_detection_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative1' */
  imu_gait_detection_DW.TimeStampA_l = (rtInf);
  imu_gait_detection_DW.TimeStampB_l = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative2' */
  imu_gait_detection_DW.TimeStampA_i = (rtInf);
  imu_gait_detection_DW.TimeStampB_e = (rtInf);

  /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function' */
  imu_gait_detection_DW.windowLengthBuffer_not_empty = false;
  imu_gait_detection_DW.windowLengthFilteredBuffer_not_empty = false;
  imu_gait_detection_DW.peakPositions_not_empty = false;
  imu_gait_detection_DW.peakValues_not_empty = false;
  imu_gait_detection_DW.peakGradients_not_empty = false;
  imu_gait_detection_DW.TOHSThreshold_not_empty = false;
  imu_gait_detection_DW.TOHSPositions_not_empty = false;
  imu_gait_detection_DW.TOHSValues_not_empty = false;
  imu_gait_detection_DW.TOHSGradients_not_empty = false;
  imu_gait_detection_DW.HSPositions_not_empty = false;
  imu_gait_detection_DW.HSValues_not_empty = false;
  imu_gait_detection_DW.HSGradients_not_empty = false;
  imu_gait_detection_DW.TOPositions_not_empty = false;
  imu_gait_detection_DW.TOValues_not_empty = false;
  imu_gait_detection_DW.TOGradients_not_empty = false;
  imu_gait_detection_DW.stepLengths_not_empty = false;
  imu_gait_detection_DW.stepPositions_not_empty = false;
  imu_gait_detection_DW.stepValues_not_empty = false;
  imu_gait_detection_DW.windowLengthBuffer.size[1] = 0;
  imu_gait_detection_DW.windowLengthFilteredBuffer.size[1] = 0;
  imu_gait_detection_DW.peakPositions.size[1] = 0;
  imu_gait_detection_DW.peakValues.size[1] = 0;
  imu_gait_detection_DW.peakGradients.size[1] = 0;
  imu_gait_detection_DW.TOHSPositions.size[1] = 0;
  imu_gait_detection_DW.TOHSValues.size[1] = 0;
  imu_gait_detection_DW.TOHSGradients.size[1] = 0;
  imu_gait_detection_DW.HSPositions.size[1] = 0;
  imu_gait_detection_DW.HSValues.size[1] = 0;
  imu_gait_detection_DW.HSGradients.size[1] = 0;
  imu_gait_detection_DW.TOPositions.size[1] = 0;
  imu_gait_detection_DW.TOValues.size[1] = 0;
  imu_gait_detection_DW.TOGradients.size[1] = 0;
  imu_gait_detection_DW.stepLengths.size[1] = 0;
  imu_gait_detection_DW.stepPositions.size[1] = 0;
  imu_gait_detection_DW.stepValues.size[1] = 0;

  /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function' */
  imu_gait_detection_DW.TimeStartHS = 0.0;
  imu_gait_detection_DW.timeTickCount = 0.0;
  imu_gait_detection_DW.stepLength = 0.0;
  imu_gait_detection_DW.TOHSDetectFlag = 0.0;
  imu_gait_detection_DW.detectResult = 0.0;
  imu_gait_detection_DW.lastHS = 0.0;
  imu_gait_detection_DW.lastTO = 0.0;
  imu_gait_detection_DW.Timeswing = 40.0;
  imu_gait_detection_DW.Timestance = 60.0;
  imu_gait_detection_DW.stepCount = 0.0;
}

/* Model terminate function */
void imu_gait_detection_terminate(void)
{
  /* Terminate for S-Function (sldrtpo): '<Root>/Packet Output' */

  /* S-Function Block: <Root>/Packet Output */
  /* no initial value should be set */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  imu_gait_detection_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  imu_gait_detection_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  imu_gait_detection_initialize();
}

void MdlTerminate(void)
{
  imu_gait_detection_terminate();
}

/* Registration function */
RT_MODEL_imu_gait_detection_T *imu_gait_detection(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)imu_gait_detection_M, 0,
                sizeof(RT_MODEL_imu_gait_detection_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&imu_gait_detection_M->solverInfo,
                          &imu_gait_detection_M->Timing.simTimeStep);
    rtsiSetTPtr(&imu_gait_detection_M->solverInfo, &rtmGetTPtr
                (imu_gait_detection_M));
    rtsiSetStepSizePtr(&imu_gait_detection_M->solverInfo,
                       &imu_gait_detection_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&imu_gait_detection_M->solverInfo, (&rtmGetErrorStatus
      (imu_gait_detection_M)));
    rtsiSetRTModelPtr(&imu_gait_detection_M->solverInfo, imu_gait_detection_M);
  }

  rtsiSetSimTimeStep(&imu_gait_detection_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&imu_gait_detection_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = imu_gait_detection_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    imu_gait_detection_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    imu_gait_detection_M->Timing.sampleTimes =
      (&imu_gait_detection_M->Timing.sampleTimesArray[0]);
    imu_gait_detection_M->Timing.offsetTimes =
      (&imu_gait_detection_M->Timing.offsetTimesArray[0]);

    /* task periods */
    imu_gait_detection_M->Timing.sampleTimes[0] = (0.0);
    imu_gait_detection_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    imu_gait_detection_M->Timing.offsetTimes[0] = (0.0);
    imu_gait_detection_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(imu_gait_detection_M, &imu_gait_detection_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = imu_gait_detection_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    imu_gait_detection_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(imu_gait_detection_M, 10.0);
  imu_gait_detection_M->Timing.stepSize0 = 0.002;
  imu_gait_detection_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  imu_gait_detection_M->Sizes.checksums[0] = (4285159410U);
  imu_gait_detection_M->Sizes.checksums[1] = (3344894375U);
  imu_gait_detection_M->Sizes.checksums[2] = (791044387U);
  imu_gait_detection_M->Sizes.checksums[3] = (177274129U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    imu_gait_detection_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(imu_gait_detection_M->extModeInfo,
      &imu_gait_detection_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(imu_gait_detection_M->extModeInfo,
                        imu_gait_detection_M->Sizes.checksums);
    rteiSetTPtr(imu_gait_detection_M->extModeInfo, rtmGetTPtr
                (imu_gait_detection_M));
  }

  imu_gait_detection_M->solverInfoPtr = (&imu_gait_detection_M->solverInfo);
  imu_gait_detection_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&imu_gait_detection_M->solverInfo, 0.002);
  rtsiSetSolverMode(&imu_gait_detection_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  imu_gait_detection_M->blockIO = ((void *) &imu_gait_detection_B);
  (void) memset(((void *) &imu_gait_detection_B), 0,
                sizeof(B_imu_gait_detection_T));

  {
    imu_gait_detection_B.PacketInput2 = CAN_DATATYPE_GROUND;
    imu_gait_detection_B.PacketInput1 = CAN_DATATYPE_GROUND;
    imu_gait_detection_B.PacketInput3 = CAN_DATATYPE_GROUND;
    imu_gait_detection_B.CANPack1 = CAN_DATATYPE_GROUND;
    imu_gait_detection_B.Clock = 0.0;
    imu_gait_detection_B.CANUnpack2_o1 = 0.0;
    imu_gait_detection_B.CANUnpack2_o2 = 0.0;
    imu_gait_detection_B.Divide = 0.0;
    imu_gait_detection_B.Divide1 = 0.0;
    imu_gait_detection_B.CANUnpack1_o1 = 0.0;
    imu_gait_detection_B.CANUnpack1_o2 = 0.0;
    imu_gait_detection_B.Divide2 = 0.0;
    imu_gait_detection_B.TmpSignalConversionAtTAQSigLogging_InsertedFor_Mux1_at_outport_0Inport1
      [0] = 0.0;
    imu_gait_detection_B.TmpSignalConversionAtTAQSigLogging_InsertedFor_Mux1_at_outport_0Inport1
      [1] = 0.0;
    imu_gait_detection_B.TmpSignalConversionAtTAQSigLogging_InsertedFor_Mux1_at_outport_0Inport1
      [2] = 0.0;
    imu_gait_detection_B.TmpSignalConversionAtTAQSigLogging_InsertedFor_Mux1_at_outport_0Inport1
      [3] = 0.0;
    imu_gait_detection_B.Divide3 = 0.0;
    imu_gait_detection_B.CANUnpack3_o1 = 0.0;
    imu_gait_detection_B.CANUnpack3_o2 = 0.0;
    imu_gait_detection_B.Divide4 = 0.0;
    imu_gait_detection_B.Divide5 = 0.0;
    imu_gait_detection_B.Multiply = 0.0;
    imu_gait_detection_B.Derivative = 0.0;
    imu_gait_detection_B.Derivative1 = 0.0;
    imu_gait_detection_B.Derivative2 = 0.0;
    imu_gait_detection_B.TmpSignalConversionAtsfunxyInport1[0] = 0.0;
    imu_gait_detection_B.TmpSignalConversionAtsfunxyInport1[1] = 0.0;
    imu_gait_detection_B.TmpSignalConversionAtsfunxyInport1_p[0] = 0.0;
    imu_gait_detection_B.TmpSignalConversionAtsfunxyInport1_p[1] = 0.0;
    imu_gait_detection_B.TmpSignalConversionAtsfunxyInport1_pe[0] = 0.0;
    imu_gait_detection_B.TmpSignalConversionAtsfunxyInport1_pe[1] = 0.0;
    imu_gait_detection_B.newInputTrainingFilteredValue = 0.0;
    imu_gait_detection_B.PercentGait = 0.0;
  }

  /* parameters */
  imu_gait_detection_M->defaultParam = ((real_T *)&imu_gait_detection_P);

  /* states (dwork) */
  imu_gait_detection_M->dwork = ((void *) &imu_gait_detection_DW);
  (void) memset((void *)&imu_gait_detection_DW, 0,
                sizeof(DW_imu_gait_detection_T));
  imu_gait_detection_DW.TimeStampA = 0.0;
  imu_gait_detection_DW.LastUAtTimeA = 0.0;
  imu_gait_detection_DW.TimeStampB = 0.0;
  imu_gait_detection_DW.LastUAtTimeB = 0.0;
  imu_gait_detection_DW.TimeStampA_l = 0.0;
  imu_gait_detection_DW.LastUAtTimeA_h = 0.0;
  imu_gait_detection_DW.TimeStampB_l = 0.0;
  imu_gait_detection_DW.LastUAtTimeB_d = 0.0;
  imu_gait_detection_DW.TimeStampA_i = 0.0;
  imu_gait_detection_DW.LastUAtTimeA_g = 0.0;
  imu_gait_detection_DW.TimeStampB_e = 0.0;
  imu_gait_detection_DW.LastUAtTimeB_m = 0.0;
  imu_gait_detection_DW.TimeStartHS = 0.0;
  imu_gait_detection_DW.timeTickCount = 0.0;
  imu_gait_detection_DW.stepLength = 0.0;
  imu_gait_detection_DW.TOHSThreshold = 0.0;
  imu_gait_detection_DW.TOHSDetectFlag = 0.0;
  imu_gait_detection_DW.detectResult = 0.0;
  imu_gait_detection_DW.lastHS = 0.0;
  imu_gait_detection_DW.lastTO = 0.0;
  imu_gait_detection_DW.Timeswing = 0.0;
  imu_gait_detection_DW.Timestance = 0.0;
  imu_gait_detection_DW.stepCount = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    imu_gait_detection_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  imu_gait_detection_M->Sizes.numContStates = (0);/* Number of continuous states */
  imu_gait_detection_M->Sizes.numY = (0);/* Number of model outputs */
  imu_gait_detection_M->Sizes.numU = (0);/* Number of model inputs */
  imu_gait_detection_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  imu_gait_detection_M->Sizes.numSampTimes = (2);/* Number of sample times */
  imu_gait_detection_M->Sizes.numBlocks = (62);/* Number of blocks */
  imu_gait_detection_M->Sizes.numBlockIO = (28);/* Number of block outputs */
  imu_gait_detection_M->Sizes.numBlockPrms = (29);/* Sum of parameter "widths" */
  return imu_gait_detection_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
