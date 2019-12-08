/*
 * imu_gait_detection.c
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
  /* Clock: '<Root>/Clock' */
  imu_gait_detection_B.Clock = imu_gait_detection_M->Timing.t[0];

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

  /* ToAsyncQueueBlock generated from: '<Root>/Mux1' */
  {
    {
      double time = imu_gait_detection_M->Timing.t[1];
      void *pData = (void *)
        &imu_gait_detection_B.TmpSignalConversionAtTAQSigLogging_InsertedFor_Mux1_at_outport_0Inport1
        [0];
      int32_T size = 4*sizeof(real_T);
      sendToAsyncQueueTgtAppSvc(2910123399U, time, pData, size);
    }
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
}

/* Model update function */
void imu_gait_detection_update(void)
{
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
  imu_gait_detection_M->Sizes.checksums[0] = (1576250156U);
  imu_gait_detection_M->Sizes.checksums[1] = (3541011811U);
  imu_gait_detection_M->Sizes.checksums[2] = (1714327959U);
  imu_gait_detection_M->Sizes.checksums[3] = (3231637761U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    imu_gait_detection_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
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
  }

  /* parameters */
  imu_gait_detection_M->defaultParam = ((real_T *)&imu_gait_detection_P);

  /* states (dwork) */
  imu_gait_detection_M->dwork = ((void *) &imu_gait_detection_DW);
  (void) memset((void *)&imu_gait_detection_DW, 0,
                sizeof(DW_imu_gait_detection_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    imu_gait_detection_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
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
  imu_gait_detection_M->Sizes.numBlocks = (31);/* Number of blocks */
  imu_gait_detection_M->Sizes.numBlockIO = (18);/* Number of block outputs */
  imu_gait_detection_M->Sizes.numBlockPrms = (22);/* Sum of parameter "widths" */
  return imu_gait_detection_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
