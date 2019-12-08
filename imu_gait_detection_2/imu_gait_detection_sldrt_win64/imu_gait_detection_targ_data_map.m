  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (imu_gait_detection_P)
    ;%
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% imu_gait_detection_P.PacketInput2_MaxMissedTicks
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% imu_gait_detection_P.PacketInput1_MaxMissedTicks
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
	  ;% imu_gait_detection_P.PacketInput3_MaxMissedTicks
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 2;
	
	  ;% imu_gait_detection_P.PacketOutput_MaxMissedTicks
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 3;
	
	  ;% imu_gait_detection_P.RealTimeSynchronization1_MaxMissedTicks
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 4;
	
	  ;% imu_gait_detection_P.PacketInput2_YieldWhenWaiting
	  section.data(6).logicalSrcIdx = 7;
	  section.data(6).dtTransOffset = 5;
	
	  ;% imu_gait_detection_P.PacketInput1_YieldWhenWaiting
	  section.data(7).logicalSrcIdx = 8;
	  section.data(7).dtTransOffset = 6;
	
	  ;% imu_gait_detection_P.PacketInput3_YieldWhenWaiting
	  section.data(8).logicalSrcIdx = 9;
	  section.data(8).dtTransOffset = 7;
	
	  ;% imu_gait_detection_P.PacketOutput_YieldWhenWaiting
	  section.data(9).logicalSrcIdx = 10;
	  section.data(9).dtTransOffset = 8;
	
	  ;% imu_gait_detection_P.RealTimeSynchronization1_YieldWhenWaiting
	  section.data(10).logicalSrcIdx = 11;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% imu_gait_detection_P.PacketInput2_PacketID
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% imu_gait_detection_P.PacketInput1_PacketID
	  section.data(2).logicalSrcIdx = 13;
	  section.data(2).dtTransOffset = 1;
	
	  ;% imu_gait_detection_P.PacketInput3_PacketID
	  section.data(3).logicalSrcIdx = 14;
	  section.data(3).dtTransOffset = 2;
	
	  ;% imu_gait_detection_P.PacketOutput_PacketID
	  section.data(4).logicalSrcIdx = 15;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% imu_gait_detection_P.Constant4_Value
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
	  ;% imu_gait_detection_P.Constant5_Value
	  section.data(2).logicalSrcIdx = 17;
	  section.data(2).dtTransOffset = 1;
	
	  ;% imu_gait_detection_P.Constant6_Value
	  section.data(3).logicalSrcIdx = 18;
	  section.data(3).dtTransOffset = 2;
	
	  ;% imu_gait_detection_P.Constant7_Value
	  section.data(4).logicalSrcIdx = 19;
	  section.data(4).dtTransOffset = 3;
	
	  ;% imu_gait_detection_P.Constant8_Value
	  section.data(5).logicalSrcIdx = 20;
	  section.data(5).dtTransOffset = 4;
	
	  ;% imu_gait_detection_P.Constant9_Value
	  section.data(6).logicalSrcIdx = 21;
	  section.data(6).dtTransOffset = 5;
	
	  ;% imu_gait_detection_P.Constant10_Value
	  section.data(7).logicalSrcIdx = 22;
	  section.data(7).dtTransOffset = 6;
	
	  ;% imu_gait_detection_P.Constant11_Value
	  section.data(8).logicalSrcIdx = 23;
	  section.data(8).dtTransOffset = 7;
	
	  ;% imu_gait_detection_P.Constant12_Value
	  section.data(9).logicalSrcIdx = 24;
	  section.data(9).dtTransOffset = 8;
	
	  ;% imu_gait_detection_P.Constant13_Value
	  section.data(10).logicalSrcIdx = 25;
	  section.data(10).dtTransOffset = 9;
	
	  ;% imu_gait_detection_P.Constant14_Value
	  section.data(11).logicalSrcIdx = 26;
	  section.data(11).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% imu_gait_detection_P.Constant3_Value
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% imu_gait_detection_P.Constant1_Value
	  section.data(1).logicalSrcIdx = 28;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% imu_gait_detection_P.Constant_Value
	  section.data(1).logicalSrcIdx = 29;
	  section.data(1).dtTransOffset = 0;
	
	  ;% imu_gait_detection_P.Constant2_Value
	  section.data(2).logicalSrcIdx = 30;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (imu_gait_detection_B)
    ;%
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% imu_gait_detection_B.PacketInput2
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% imu_gait_detection_B.PacketInput1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% imu_gait_detection_B.PacketInput3
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% imu_gait_detection_B.CANPack1
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 23;
      section.data(23)  = dumData; %prealloc
      
	  ;% imu_gait_detection_B.Clock
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% imu_gait_detection_B.CANUnpack2_o1
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% imu_gait_detection_B.CANUnpack2_o2
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 2;
	
	  ;% imu_gait_detection_B.Divide
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 3;
	
	  ;% imu_gait_detection_B.Divide1
	  section.data(5).logicalSrcIdx = 8;
	  section.data(5).dtTransOffset = 4;
	
	  ;% imu_gait_detection_B.CANUnpack1_o1
	  section.data(6).logicalSrcIdx = 9;
	  section.data(6).dtTransOffset = 5;
	
	  ;% imu_gait_detection_B.CANUnpack1_o2
	  section.data(7).logicalSrcIdx = 10;
	  section.data(7).dtTransOffset = 6;
	
	  ;% imu_gait_detection_B.Divide2
	  section.data(8).logicalSrcIdx = 11;
	  section.data(8).dtTransOffset = 7;
	
	  ;% imu_gait_detection_B.TmpSignalConversionAtTAQSigLogging_InsertedFor_Mux1_at_outport_0Inport1
	  section.data(9).logicalSrcIdx = 12;
	  section.data(9).dtTransOffset = 8;
	
	  ;% imu_gait_detection_B.Divide3
	  section.data(10).logicalSrcIdx = 13;
	  section.data(10).dtTransOffset = 12;
	
	  ;% imu_gait_detection_B.CANUnpack3_o1
	  section.data(11).logicalSrcIdx = 14;
	  section.data(11).dtTransOffset = 13;
	
	  ;% imu_gait_detection_B.CANUnpack3_o2
	  section.data(12).logicalSrcIdx = 15;
	  section.data(12).dtTransOffset = 14;
	
	  ;% imu_gait_detection_B.Divide4
	  section.data(13).logicalSrcIdx = 16;
	  section.data(13).dtTransOffset = 15;
	
	  ;% imu_gait_detection_B.Divide5
	  section.data(14).logicalSrcIdx = 17;
	  section.data(14).dtTransOffset = 16;
	
	  ;% imu_gait_detection_B.Multiply
	  section.data(15).logicalSrcIdx = 18;
	  section.data(15).dtTransOffset = 17;
	
	  ;% imu_gait_detection_B.Derivative
	  section.data(16).logicalSrcIdx = 19;
	  section.data(16).dtTransOffset = 18;
	
	  ;% imu_gait_detection_B.Derivative1
	  section.data(17).logicalSrcIdx = 20;
	  section.data(17).dtTransOffset = 19;
	
	  ;% imu_gait_detection_B.Derivative2
	  section.data(18).logicalSrcIdx = 21;
	  section.data(18).dtTransOffset = 20;
	
	  ;% imu_gait_detection_B.TmpSignalConversionAtsfunxyInport1
	  section.data(19).logicalSrcIdx = 22;
	  section.data(19).dtTransOffset = 21;
	
	  ;% imu_gait_detection_B.TmpSignalConversionAtsfunxyInport1_p
	  section.data(20).logicalSrcIdx = 23;
	  section.data(20).dtTransOffset = 23;
	
	  ;% imu_gait_detection_B.TmpSignalConversionAtsfunxyInport1_pe
	  section.data(21).logicalSrcIdx = 24;
	  section.data(21).dtTransOffset = 25;
	
	  ;% imu_gait_detection_B.newInputTrainingFilteredValue
	  section.data(22).logicalSrcIdx = 25;
	  section.data(22).dtTransOffset = 27;
	
	  ;% imu_gait_detection_B.PercentGait
	  section.data(23).logicalSrcIdx = 26;
	  section.data(23).dtTransOffset = 28;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% imu_gait_detection_B.RealTimeSynchronization1
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 5;
    sectIdxOffset = 3;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (imu_gait_detection_DW)
    ;%
      section.nData     = 17;
      section.data(17)  = dumData; %prealloc
      
	  ;% imu_gait_detection_DW.windowLengthBuffer
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% imu_gait_detection_DW.windowLengthFilteredBuffer
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% imu_gait_detection_DW.peakPositions
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% imu_gait_detection_DW.peakValues
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% imu_gait_detection_DW.peakGradients
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% imu_gait_detection_DW.TOHSPositions
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% imu_gait_detection_DW.TOHSValues
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% imu_gait_detection_DW.TOHSGradients
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% imu_gait_detection_DW.HSPositions
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% imu_gait_detection_DW.HSValues
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% imu_gait_detection_DW.HSGradients
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% imu_gait_detection_DW.TOPositions
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% imu_gait_detection_DW.TOValues
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% imu_gait_detection_DW.TOGradients
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% imu_gait_detection_DW.stepLengths
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% imu_gait_detection_DW.stepPositions
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% imu_gait_detection_DW.stepValues
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 23;
      section.data(23)  = dumData; %prealloc
      
	  ;% imu_gait_detection_DW.TimeStampA
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% imu_gait_detection_DW.LastUAtTimeA
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 1;
	
	  ;% imu_gait_detection_DW.TimeStampB
	  section.data(3).logicalSrcIdx = 19;
	  section.data(3).dtTransOffset = 2;
	
	  ;% imu_gait_detection_DW.LastUAtTimeB
	  section.data(4).logicalSrcIdx = 20;
	  section.data(4).dtTransOffset = 3;
	
	  ;% imu_gait_detection_DW.TimeStampA_l
	  section.data(5).logicalSrcIdx = 21;
	  section.data(5).dtTransOffset = 4;
	
	  ;% imu_gait_detection_DW.LastUAtTimeA_h
	  section.data(6).logicalSrcIdx = 22;
	  section.data(6).dtTransOffset = 5;
	
	  ;% imu_gait_detection_DW.TimeStampB_l
	  section.data(7).logicalSrcIdx = 23;
	  section.data(7).dtTransOffset = 6;
	
	  ;% imu_gait_detection_DW.LastUAtTimeB_d
	  section.data(8).logicalSrcIdx = 24;
	  section.data(8).dtTransOffset = 7;
	
	  ;% imu_gait_detection_DW.TimeStampA_i
	  section.data(9).logicalSrcIdx = 25;
	  section.data(9).dtTransOffset = 8;
	
	  ;% imu_gait_detection_DW.LastUAtTimeA_g
	  section.data(10).logicalSrcIdx = 26;
	  section.data(10).dtTransOffset = 9;
	
	  ;% imu_gait_detection_DW.TimeStampB_e
	  section.data(11).logicalSrcIdx = 27;
	  section.data(11).dtTransOffset = 10;
	
	  ;% imu_gait_detection_DW.LastUAtTimeB_m
	  section.data(12).logicalSrcIdx = 28;
	  section.data(12).dtTransOffset = 11;
	
	  ;% imu_gait_detection_DW.TimeStartHS
	  section.data(13).logicalSrcIdx = 29;
	  section.data(13).dtTransOffset = 12;
	
	  ;% imu_gait_detection_DW.timeTickCount
	  section.data(14).logicalSrcIdx = 30;
	  section.data(14).dtTransOffset = 13;
	
	  ;% imu_gait_detection_DW.stepLength
	  section.data(15).logicalSrcIdx = 31;
	  section.data(15).dtTransOffset = 14;
	
	  ;% imu_gait_detection_DW.TOHSThreshold
	  section.data(16).logicalSrcIdx = 32;
	  section.data(16).dtTransOffset = 15;
	
	  ;% imu_gait_detection_DW.TOHSDetectFlag
	  section.data(17).logicalSrcIdx = 33;
	  section.data(17).dtTransOffset = 16;
	
	  ;% imu_gait_detection_DW.detectResult
	  section.data(18).logicalSrcIdx = 34;
	  section.data(18).dtTransOffset = 17;
	
	  ;% imu_gait_detection_DW.lastHS
	  section.data(19).logicalSrcIdx = 35;
	  section.data(19).dtTransOffset = 18;
	
	  ;% imu_gait_detection_DW.lastTO
	  section.data(20).logicalSrcIdx = 36;
	  section.data(20).dtTransOffset = 19;
	
	  ;% imu_gait_detection_DW.Timeswing
	  section.data(21).logicalSrcIdx = 37;
	  section.data(21).dtTransOffset = 20;
	
	  ;% imu_gait_detection_DW.Timestance
	  section.data(22).logicalSrcIdx = 38;
	  section.data(22).dtTransOffset = 21;
	
	  ;% imu_gait_detection_DW.stepCount
	  section.data(23).logicalSrcIdx = 39;
	  section.data(23).dtTransOffset = 22;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% imu_gait_detection_DW.PacketInput2_PWORK
	  section.data(1).logicalSrcIdx = 40;
	  section.data(1).dtTransOffset = 0;
	
	  ;% imu_gait_detection_DW.PacketInput1_PWORK
	  section.data(2).logicalSrcIdx = 41;
	  section.data(2).dtTransOffset = 1;
	
	  ;% imu_gait_detection_DW.PacketInput3_PWORK
	  section.data(3).logicalSrcIdx = 42;
	  section.data(3).dtTransOffset = 2;
	
	  ;% imu_gait_detection_DW.Scope_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 43;
	  section.data(4).dtTransOffset = 3;
	
	  ;% imu_gait_detection_DW.Scope1_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 44;
	  section.data(5).dtTransOffset = 4;
	
	  ;% imu_gait_detection_DW.Scope3_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 45;
	  section.data(6).dtTransOffset = 5;
	
	  ;% imu_gait_detection_DW.Scope4_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 46;
	  section.data(7).dtTransOffset = 6;
	
	  ;% imu_gait_detection_DW.Scope6_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 47;
	  section.data(8).dtTransOffset = 7;
	
	  ;% imu_gait_detection_DW.TAQSigLogging_InsertedFor_Mux1_at_outport_0_PWORK.AQHandles
	  section.data(9).logicalSrcIdx = 48;
	  section.data(9).dtTransOffset = 8;
	
	  ;% imu_gait_detection_DW.PacketOutput_PWORK
	  section.data(10).logicalSrcIdx = 49;
	  section.data(10).dtTransOffset = 9;
	
	  ;% imu_gait_detection_DW.RealTimeSynchronization1_PWORK
	  section.data(11).logicalSrcIdx = 50;
	  section.data(11).dtTransOffset = 11;
	
	  ;% imu_gait_detection_DW.Scope2_PWORK.LoggedData
	  section.data(12).logicalSrcIdx = 51;
	  section.data(12).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% imu_gait_detection_DW.CANUnpack2_ModeSignalID
	  section.data(1).logicalSrcIdx = 52;
	  section.data(1).dtTransOffset = 0;
	
	  ;% imu_gait_detection_DW.CANUnpack2_StatusPortID
	  section.data(2).logicalSrcIdx = 53;
	  section.data(2).dtTransOffset = 1;
	
	  ;% imu_gait_detection_DW.CANUnpack1_ModeSignalID
	  section.data(3).logicalSrcIdx = 54;
	  section.data(3).dtTransOffset = 2;
	
	  ;% imu_gait_detection_DW.CANUnpack1_StatusPortID
	  section.data(4).logicalSrcIdx = 55;
	  section.data(4).dtTransOffset = 3;
	
	  ;% imu_gait_detection_DW.CANUnpack3_ModeSignalID
	  section.data(5).logicalSrcIdx = 56;
	  section.data(5).dtTransOffset = 4;
	
	  ;% imu_gait_detection_DW.CANUnpack3_StatusPortID
	  section.data(6).logicalSrcIdx = 57;
	  section.data(6).dtTransOffset = 5;
	
	  ;% imu_gait_detection_DW.CANPack1_ModeSignalID
	  section.data(7).logicalSrcIdx = 58;
	  section.data(7).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 18;
      section.data(18)  = dumData; %prealloc
      
	  ;% imu_gait_detection_DW.windowLengthBuffer_not_empty
	  section.data(1).logicalSrcIdx = 59;
	  section.data(1).dtTransOffset = 0;
	
	  ;% imu_gait_detection_DW.windowLengthFilteredBuffer_not_empty
	  section.data(2).logicalSrcIdx = 60;
	  section.data(2).dtTransOffset = 1;
	
	  ;% imu_gait_detection_DW.peakPositions_not_empty
	  section.data(3).logicalSrcIdx = 61;
	  section.data(3).dtTransOffset = 2;
	
	  ;% imu_gait_detection_DW.peakValues_not_empty
	  section.data(4).logicalSrcIdx = 62;
	  section.data(4).dtTransOffset = 3;
	
	  ;% imu_gait_detection_DW.peakGradients_not_empty
	  section.data(5).logicalSrcIdx = 63;
	  section.data(5).dtTransOffset = 4;
	
	  ;% imu_gait_detection_DW.TOHSThreshold_not_empty
	  section.data(6).logicalSrcIdx = 64;
	  section.data(6).dtTransOffset = 5;
	
	  ;% imu_gait_detection_DW.TOHSPositions_not_empty
	  section.data(7).logicalSrcIdx = 65;
	  section.data(7).dtTransOffset = 6;
	
	  ;% imu_gait_detection_DW.TOHSValues_not_empty
	  section.data(8).logicalSrcIdx = 66;
	  section.data(8).dtTransOffset = 7;
	
	  ;% imu_gait_detection_DW.TOHSGradients_not_empty
	  section.data(9).logicalSrcIdx = 67;
	  section.data(9).dtTransOffset = 8;
	
	  ;% imu_gait_detection_DW.HSPositions_not_empty
	  section.data(10).logicalSrcIdx = 68;
	  section.data(10).dtTransOffset = 9;
	
	  ;% imu_gait_detection_DW.HSValues_not_empty
	  section.data(11).logicalSrcIdx = 69;
	  section.data(11).dtTransOffset = 10;
	
	  ;% imu_gait_detection_DW.HSGradients_not_empty
	  section.data(12).logicalSrcIdx = 70;
	  section.data(12).dtTransOffset = 11;
	
	  ;% imu_gait_detection_DW.TOPositions_not_empty
	  section.data(13).logicalSrcIdx = 71;
	  section.data(13).dtTransOffset = 12;
	
	  ;% imu_gait_detection_DW.TOValues_not_empty
	  section.data(14).logicalSrcIdx = 72;
	  section.data(14).dtTransOffset = 13;
	
	  ;% imu_gait_detection_DW.TOGradients_not_empty
	  section.data(15).logicalSrcIdx = 73;
	  section.data(15).dtTransOffset = 14;
	
	  ;% imu_gait_detection_DW.stepLengths_not_empty
	  section.data(16).logicalSrcIdx = 74;
	  section.data(16).dtTransOffset = 15;
	
	  ;% imu_gait_detection_DW.stepPositions_not_empty
	  section.data(17).logicalSrcIdx = 75;
	  section.data(17).dtTransOffset = 16;
	
	  ;% imu_gait_detection_DW.stepValues_not_empty
	  section.data(18).logicalSrcIdx = 76;
	  section.data(18).dtTransOffset = 17;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 4285159410;
  targMap.checksum1 = 3344894375;
  targMap.checksum2 = 791044387;
  targMap.checksum3 = 177274129;

