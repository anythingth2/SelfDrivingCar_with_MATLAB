  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 15;
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
    ;% Auto data (vipldws2_P)
    ;%
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% vipldws2_P.uDFIRFilter_filterMtrx
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_P.FindLocalMaxima1_threshold
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% vipldws2_P.FindLocalMaxima_threshold
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% vipldws2_P.FindLocalMaxima1_threshold_b
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 5;
	
	  ;% vipldws2_P.UnitDelayResettable1_vinit
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% vipldws2_P.CompareToConstant2_const
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_P.CompareToConstant_const
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vipldws2_P.CompareToConstant_const_m
	  section.data(3).logicalSrcIdx = 7;
	  section.data(3).dtTransOffset = 2;
	
	  ;% vipldws2_P.CompareToConstant1_const
	  section.data(4).logicalSrcIdx = 8;
	  section.data(4).dtTransOffset = 3;
	
	  ;% vipldws2_P.CompareToConstant10_const
	  section.data(5).logicalSrcIdx = 9;
	  section.data(5).dtTransOffset = 4;
	
	  ;% vipldws2_P.CompareToConstant1_const_o
	  section.data(6).logicalSrcIdx = 10;
	  section.data(6).dtTransOffset = 5;
	
	  ;% vipldws2_P.OnlyupdatethelineswhichKalmanfi
	  section.data(7).logicalSrcIdx = 11;
	  section.data(7).dtTransOffset = 6;
	
	  ;% vipldws2_P.DrawShapes_lineWidth
	  section.data(8).logicalSrcIdx = 12;
	  section.data(8).dtTransOffset = 7;
	
	  ;% vipldws2_P.DrawShapes_lineWidth_i
	  section.data(9).logicalSrcIdx = 13;
	  section.data(9).dtTransOffset = 8;
	
	  ;% vipldws2_P.InsertText_textLoc
	  section.data(10).logicalSrcIdx = 14;
	  section.data(10).dtTransOffset = 9;
	
	  ;% vipldws2_P.UnitDelayResettable_vinit
	  section.data(11).logicalSrcIdx = 15;
	  section.data(11).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% vipldws2_P.NSampleEnable_ActiveLevel
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_P.NSampleEnable_N
	  section.data(2).logicalSrcIdx = 17;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% vipldws2_P.Counter_InitialCount
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% vipldws2_P.CompareToConstant_const_h
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_P.CompareToConstant1_const_h
	  section.data(2).logicalSrcIdx = 20;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vipldws2_P.CompareToConstant2_const_i
	  section.data(3).logicalSrcIdx = 21;
	  section.data(3).dtTransOffset = 2;
	
	  ;% vipldws2_P.CompareToConstant1_const_j
	  section.data(4).logicalSrcIdx = 22;
	  section.data(4).dtTransOffset = 3;
	
	  ;% vipldws2_P.CompareToConstant1_const_l
	  section.data(5).logicalSrcIdx = 23;
	  section.data(5).dtTransOffset = 4;
	
	  ;% vipldws2_P.CompareToConstant2_const_h
	  section.data(6).logicalSrcIdx = 24;
	  section.data(6).dtTransOffset = 5;
	
	  ;% vipldws2_P.CompareToConstant_const_n
	  section.data(7).logicalSrcIdx = 25;
	  section.data(7).dtTransOffset = 6;
	
	  ;% vipldws2_P.CompareToConstant3_const
	  section.data(8).logicalSrcIdx = 26;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% vipldws2_P.Rotate_fillVal
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% vipldws2_P.Constant1_Value
	  section.data(1).logicalSrcIdx = 28;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_P.Constant_Value
	  section.data(2).logicalSrcIdx = 29;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vipldws2_P.Constant1_Value_d
	  section.data(3).logicalSrcIdx = 30;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 24;
      section.data(24)  = dumData; %prealloc
      
	  ;% vipldws2_P.Constant3_Value
	  section.data(1).logicalSrcIdx = 31;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_P.Hcst_Value
	  section.data(2).logicalSrcIdx = 32;
	  section.data(2).dtTransOffset = 16;
	
	  ;% vipldws2_P.Hcst_t_Value
	  section.data(3).logicalSrcIdx = 33;
	  section.data(3).dtTransOffset = 24;
	
	  ;% vipldws2_P.Constant2_Value
	  section.data(4).logicalSrcIdx = 34;
	  section.data(4).dtTransOffset = 32;
	
	  ;% vipldws2_P.Constant4_Value
	  section.data(5).logicalSrcIdx = 35;
	  section.data(5).dtTransOffset = 36;
	
	  ;% vipldws2_P.Constant5_Value
	  section.data(6).logicalSrcIdx = 36;
	  section.data(6).dtTransOffset = 52;
	
	  ;% vipldws2_P.Reset_Value_Value
	  section.data(7).logicalSrcIdx = 37;
	  section.data(7).dtTransOffset = 68;
	
	  ;% vipldws2_P.Reset_Value_Value_j
	  section.data(8).logicalSrcIdx = 38;
	  section.data(8).dtTransOffset = 84;
	
	  ;% vipldws2_P.Reset_Value_Value_b
	  section.data(9).logicalSrcIdx = 39;
	  section.data(9).dtTransOffset = 88;
	
	  ;% vipldws2_P.Reset_Value_Value_p
	  section.data(10).logicalSrcIdx = 40;
	  section.data(10).dtTransOffset = 90;
	
	  ;% vipldws2_P.Gain_Gain
	  section.data(11).logicalSrcIdx = 41;
	  section.data(11).dtTransOffset = 92;
	
	  ;% vipldws2_P.DrawShapes_RTP_FILLCOLOR
	  section.data(12).logicalSrcIdx = 42;
	  section.data(12).dtTransOffset = 93;
	
	  ;% vipldws2_P.DrawShapes_RTP_FILLCOLOR_o
	  section.data(13).logicalSrcIdx = 43;
	  section.data(13).dtTransOffset = 96;
	
	  ;% vipldws2_P.DrawShapes_RTP_OPACITY
	  section.data(14).logicalSrcIdx = 44;
	  section.data(14).dtTransOffset = 99;
	
	  ;% vipldws2_P.DrawShapes_RTP_FILLCOLOR_f
	  section.data(15).logicalSrcIdx = 45;
	  section.data(15).dtTransOffset = 100;
	
	  ;% vipldws2_P.InsertText_TxtOpacity
	  section.data(16).logicalSrcIdx = 46;
	  section.data(16).dtTransOffset = 106;
	
	  ;% vipldws2_P.Yellow1_Value
	  section.data(17).logicalSrcIdx = 47;
	  section.data(17).dtTransOffset = 107;
	
	  ;% vipldws2_P.InsertTextLeftLane_TxtOpacity
	  section.data(18).logicalSrcIdx = 48;
	  section.data(18).dtTransOffset = 122;
	
	  ;% vipldws2_P.InsertTextRightLane_TxtOpacity
	  section.data(19).logicalSrcIdx = 49;
	  section.data(19).dtTransOffset = 123;
	
	  ;% vipldws2_P.Saturation_UpperSat
	  section.data(20).logicalSrcIdx = 50;
	  section.data(20).dtTransOffset = 124;
	
	  ;% vipldws2_P.Saturation_LowerSat
	  section.data(21).logicalSrcIdx = 51;
	  section.data(21).dtTransOffset = 125;
	
	  ;% vipldws2_P.UnitDelay2_InitialCondition
	  section.data(22).logicalSrcIdx = 52;
	  section.data(22).dtTransOffset = 126;
	
	  ;% vipldws2_P.UnitDelay3_InitialCondition
	  section.data(23).logicalSrcIdx = 53;
	  section.data(23).dtTransOffset = 206;
	
	  ;% vipldws2_P.min_safety_Value
	  section.data(24).logicalSrcIdx = 54;
	  section.data(24).dtTransOffset = 526;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 39;
      section.data(39)  = dumData; %prealloc
      
	  ;% vipldws2_P.ForIterator_IterationLimit
	  section.data(1).logicalSrcIdx = 55;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_P.Constant_Value_i
	  section.data(2).logicalSrcIdx = 56;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vipldws2_P.Min_left_dis_InitialCondition
	  section.data(3).logicalSrcIdx = 57;
	  section.data(3).dtTransOffset = 2;
	
	  ;% vipldws2_P.Min_left_pts_InitialCondition
	  section.data(4).logicalSrcIdx = 58;
	  section.data(4).dtTransOffset = 3;
	
	  ;% vipldws2_P.Min_right_dis_InitialCondition
	  section.data(5).logicalSrcIdx = 59;
	  section.data(5).dtTransOffset = 7;
	
	  ;% vipldws2_P.Min_right_pts_InitialCondition
	  section.data(6).logicalSrcIdx = 60;
	  section.data(6).dtTransOffset = 8;
	
	  ;% vipldws2_P.Iterator_IterationLimit
	  section.data(7).logicalSrcIdx = 61;
	  section.data(7).dtTransOffset = 12;
	
	  ;% vipldws2_P.Constant_Value_l
	  section.data(8).logicalSrcIdx = 62;
	  section.data(8).dtTransOffset = 13;
	
	  ;% vipldws2_P.ForIterator_IterationLimit_g
	  section.data(9).logicalSrcIdx = 63;
	  section.data(9).dtTransOffset = 14;
	
	  ;% vipldws2_P.Constant2_Value_o
	  section.data(10).logicalSrcIdx = 64;
	  section.data(10).dtTransOffset = 15;
	
	  ;% vipldws2_P.ForIterator_IterationLimit_j
	  section.data(11).logicalSrcIdx = 65;
	  section.data(11).dtTransOffset = 415;
	
	  ;% vipldws2_P.Constant_Value_iw
	  section.data(12).logicalSrcIdx = 66;
	  section.data(12).dtTransOffset = 416;
	
	  ;% vipldws2_P.ForIterator_IterationLimit_n
	  section.data(13).logicalSrcIdx = 67;
	  section.data(13).dtTransOffset = 417;
	
	  ;% vipldws2_P.Delay1_InitialCondition
	  section.data(14).logicalSrcIdx = 68;
	  section.data(14).dtTransOffset = 418;
	
	  ;% vipldws2_P.Minimum_prodDims
	  section.data(15).logicalSrcIdx = 69;
	  section.data(15).dtTransOffset = 419;
	
	  ;% vipldws2_P.Constant2_Value_d
	  section.data(16).logicalSrcIdx = 70;
	  section.data(16).dtTransOffset = 421;
	
	  ;% vipldws2_P.Constant1_Value_c
	  section.data(17).logicalSrcIdx = 71;
	  section.data(17).dtTransOffset = 461;
	
	  ;% vipldws2_P.Constant2_Value_b
	  section.data(18).logicalSrcIdx = 72;
	  section.data(18).dtTransOffset = 481;
	
	  ;% vipldws2_P.Constant_Value_i0
	  section.data(19).logicalSrcIdx = 73;
	  section.data(19).dtTransOffset = 501;
	
	  ;% vipldws2_P.Constant_Value_m
	  section.data(20).logicalSrcIdx = 74;
	  section.data(20).dtTransOffset = 502;
	
	  ;% vipldws2_P.ForIterator_IterationLimit_a
	  section.data(21).logicalSrcIdx = 75;
	  section.data(21).dtTransOffset = 503;
	
	  ;% vipldws2_P.Bias_Bias
	  section.data(22).logicalSrcIdx = 76;
	  section.data(22).dtTransOffset = 504;
	
	  ;% vipldws2_P.Saturation_UpperSat_m
	  section.data(23).logicalSrcIdx = 77;
	  section.data(23).dtTransOffset = 505;
	
	  ;% vipldws2_P.Saturation_LowerSat_o
	  section.data(24).logicalSrcIdx = 78;
	  section.data(24).dtTransOffset = 506;
	
	  ;% vipldws2_P.ForIterator_IterationLimit_gd
	  section.data(25).logicalSrcIdx = 79;
	  section.data(25).dtTransOffset = 507;
	
	  ;% vipldws2_P.DSPConstant_Value
	  section.data(26).logicalSrcIdx = 80;
	  section.data(26).dtTransOffset = 508;
	
	  ;% vipldws2_P.Switch_Threshold
	  section.data(27).logicalSrcIdx = 81;
	  section.data(27).dtTransOffset = 510;
	
	  ;% vipldws2_P.DSPConstant2_Value
	  section.data(28).logicalSrcIdx = 82;
	  section.data(28).dtTransOffset = 511;
	
	  ;% vipldws2_P.Switch1_Threshold
	  section.data(29).logicalSrcIdx = 83;
	  section.data(29).dtTransOffset = 513;
	
	  ;% vipldws2_P.Bias1_Bias
	  section.data(30).logicalSrcIdx = 84;
	  section.data(30).dtTransOffset = 514;
	
	  ;% vipldws2_P.Bias2_Bias
	  section.data(31).logicalSrcIdx = 85;
	  section.data(31).dtTransOffset = 516;
	
	  ;% vipldws2_P.En_Delay_InitialCondition
	  section.data(32).logicalSrcIdx = 86;
	  section.data(32).dtTransOffset = 518;
	
	  ;% vipldws2_P.Bias1_Bias_l
	  section.data(33).logicalSrcIdx = 87;
	  section.data(33).dtTransOffset = 519;
	
	  ;% vipldws2_P.DrawLines4_Value
	  section.data(34).logicalSrcIdx = 88;
	  section.data(34).dtTransOffset = 520;
	
	  ;% vipldws2_P.Constant_Value_j
	  section.data(35).logicalSrcIdx = 89;
	  section.data(35).dtTransOffset = 524;
	
	  ;% vipldws2_P.Bias3_Bias
	  section.data(36).logicalSrcIdx = 90;
	  section.data(36).dtTransOffset = 527;
	
	  ;% vipldws2_P.Bias_Bias_i
	  section.data(37).logicalSrcIdx = 91;
	  section.data(37).dtTransOffset = 531;
	
	  ;% vipldws2_P.Saturation_UpperSat_h
	  section.data(38).logicalSrcIdx = 92;
	  section.data(38).dtTransOffset = 539;
	
	  ;% vipldws2_P.Saturation_LowerSat_a
	  section.data(39).logicalSrcIdx = 93;
	  section.data(39).dtTransOffset = 540;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% vipldws2_P.Delay1_DelayLength
	  section.data(1).logicalSrcIdx = 94;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_P.Delay1_DelayLength_n
	  section.data(2).logicalSrcIdx = 95;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vipldws2_P.Delay_DelayLength
	  section.data(3).logicalSrcIdx = 96;
	  section.data(3).dtTransOffset = 2;
	
	  ;% vipldws2_P.Delay1_DelayLength_j
	  section.data(4).logicalSrcIdx = 97;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(10) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% vipldws2_P.Distancethresholdfordeparturewa
	  section.data(1).logicalSrcIdx = 98;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_P.rho_1_Gain
	  section.data(2).logicalSrcIdx = 99;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(11) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% vipldws2_P.Bias2_Bias_k
	  section.data(1).logicalSrcIdx = 100;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_P.Bias3_Bias_c
	  section.data(2).logicalSrcIdx = 101;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vipldws2_P.Bias2_Bias_h
	  section.data(3).logicalSrcIdx = 102;
	  section.data(3).dtTransOffset = 2;
	
	  ;% vipldws2_P.Bias3_Bias_d
	  section.data(4).logicalSrcIdx = 103;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(12) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% vipldws2_P.Constant1_Value_b
	  section.data(1).logicalSrcIdx = 104;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_P.Constant_Value_f
	  section.data(2).logicalSrcIdx = 105;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vipldws2_P.DrawLines3_Value
	  section.data(3).logicalSrcIdx = 106;
	  section.data(3).dtTransOffset = 2;
	
	  ;% vipldws2_P.DrawLines2_Value
	  section.data(4).logicalSrcIdx = 107;
	  section.data(4).dtTransOffset = 3;
	
	  ;% vipldws2_P.DrawLines1_Value
	  section.data(5).logicalSrcIdx = 108;
	  section.data(5).dtTransOffset = 4;
	
	  ;% vipldws2_P.DrawLines_Value
	  section.data(6).logicalSrcIdx = 109;
	  section.data(6).dtTransOffset = 5;
	
	  ;% vipldws2_P.Bias_Bias_d
	  section.data(7).logicalSrcIdx = 110;
	  section.data(7).dtTransOffset = 6;
	
	  ;% vipldws2_P.Bias1_Bias_e
	  section.data(8).logicalSrcIdx = 111;
	  section.data(8).dtTransOffset = 7;
	
	  ;% vipldws2_P.Delay_InitialCondition
	  section.data(9).logicalSrcIdx = 112;
	  section.data(9).dtTransOffset = 8;
	
	  ;% vipldws2_P.Delay1_InitialCondition_p
	  section.data(10).logicalSrcIdx = 113;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(13) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% vipldws2_P.FixPtUnitDelay2_InitialConditio
	  section.data(1).logicalSrcIdx = 114;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_P.FixPtUnitDelay2_InitialCondit_p
	  section.data(2).logicalSrcIdx = 115;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vipldws2_P.Switch_CurrentSetting
	  section.data(3).logicalSrcIdx = 116;
	  section.data(3).dtTransOffset = 2;
	
	  ;% vipldws2_P.FixPtConstant_Value
	  section.data(4).logicalSrcIdx = 117;
	  section.data(4).dtTransOffset = 3;
	
	  ;% vipldws2_P.FixPtConstant_Value_e
	  section.data(5).logicalSrcIdx = 118;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(14) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% vipldws2_P.DrawPolygon_Value
	  section.data(1).logicalSrcIdx = 119;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_P.DrawLines_Value_j
	  section.data(2).logicalSrcIdx = 120;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vipldws2_P._Y0
	  section.data(3).logicalSrcIdx = 121;
	  section.data(3).dtTransOffset = 2;
	
	  ;% vipldws2_P.Constant_Value_b
	  section.data(4).logicalSrcIdx = 122;
	  section.data(4).dtTransOffset = 3;
	
	  ;% vipldws2_P.Constant1_Value_d0
	  section.data(5).logicalSrcIdx = 123;
	  section.data(5).dtTransOffset = 5;
	
	  ;% vipldws2_P.Delay1_InitialCondition_n
	  section.data(6).logicalSrcIdx = 124;
	  section.data(6).dtTransOffset = 6;
	
	  ;% vipldws2_P.Constant_Value_g
	  section.data(7).logicalSrcIdx = 125;
	  section.data(7).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(15) = section;
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
    nTotSects     = 16;
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
    ;% Auto data (vipldws2_B)
    ;%
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% vipldws2_B.ImageDataTypeConversion
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_B.ColorSpaceConversion
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 230400;
	
	  ;% vipldws2_B.Clipimage
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 307200;
	
	  ;% vipldws2_B.HoughTransform_o1
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 345600;
	
	  ;% vipldws2_B.HoughTransform_o2
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 468540;
	
	  ;% vipldws2_B.HoughTransform_o3
	  section.data(6).logicalSrcIdx = 7;
	  section.data(6).dtTransOffset = 468720;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% vipldws2_B.Init
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% vipldws2_B.Probe
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_B.Selector
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 14;
      section.data(14)  = dumData; %prealloc
      
	  ;% vipldws2_B.MatrixConcatenation3
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_B.UnitDelay2
	  section.data(2).logicalSrcIdx = 10;
	  section.data(2).dtTransOffset = 4;
	
	  ;% vipldws2_B.UnitDelay3
	  section.data(3).logicalSrcIdx = 11;
	  section.data(3).dtTransOffset = 84;
	
	  ;% vipldws2_B.ColorSpaceConversion1
	  section.data(4).logicalSrcIdx = 12;
	  section.data(4).dtTransOffset = 404;
	
	  ;% vipldws2_B.Switch
	  section.data(5).logicalSrcIdx = 13;
	  section.data(5).dtTransOffset = 115604;
	
	  ;% vipldws2_B.Xnew
	  section.data(6).logicalSrcIdx = 15;
	  section.data(6).dtTransOffset = 346004;
	
	  ;% vipldws2_B.InsertTextRightLane
	  section.data(7).logicalSrcIdx = 16;
	  section.data(7).dtTransOffset = 346044;
	
	  ;% vipldws2_B.DrawShapes
	  section.data(8).logicalSrcIdx = 17;
	  section.data(8).dtTransOffset = 576444;
	
	  ;% vipldws2_B.DrawShapes_l
	  section.data(9).logicalSrcIdx = 18;
	  section.data(9).dtTransOffset = 806844;
	
	  ;% vipldws2_B.Assignment
	  section.data(10).logicalSrcIdx = 19;
	  section.data(10).dtTransOffset = 1037244;
	
	  ;% vipldws2_B.Switch_l
	  section.data(11).logicalSrcIdx = 60;
	  section.data(11).dtTransOffset = 1037284;
	
	  ;% vipldws2_B.HP_prdt
	  section.data(12).logicalSrcIdx = 61;
	  section.data(12).dtTransOffset = 1037288;
	
	  ;% vipldws2_B.LDLFactorization
	  section.data(13).logicalSrcIdx = 62;
	  section.data(13).dtTransOffset = 1037296;
	
	  ;% vipldws2_B.y
	  section.data(14).logicalSrcIdx = 63;
	  section.data(14).dtTransOffset = 1037300;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 33;
      section.data(33)  = dumData; %prealloc
      
	  ;% vipldws2_B.MatrixConcatenation2
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_B.Selector1
	  section.data(2).logicalSrcIdx = 20;
	  section.data(2).dtTransOffset = 2;
	
	  ;% vipldws2_B.Selector2
	  section.data(3).logicalSrcIdx = 21;
	  section.data(3).dtTransOffset = 4;
	
	  ;% vipldws2_B.Assignment_i
	  section.data(4).logicalSrcIdx = 22;
	  section.data(4).dtTransOffset = 6;
	
	  ;% vipldws2_B.Selector2_f
	  section.data(5).logicalSrcIdx = 23;
	  section.data(5).dtTransOffset = 46;
	
	  ;% vipldws2_B.Selector1_k
	  section.data(6).logicalSrcIdx = 24;
	  section.data(6).dtTransOffset = 48;
	
	  ;% vipldws2_B.Selector_i
	  section.data(7).logicalSrcIdx = 25;
	  section.data(7).dtTransOffset = 50;
	
	  ;% vipldws2_B.Selector1_c
	  section.data(8).logicalSrcIdx = 26;
	  section.data(8).dtTransOffset = 52;
	
	  ;% vipldws2_B.Selector2_n
	  section.data(9).logicalSrcIdx = 27;
	  section.data(9).dtTransOffset = 56;
	
	  ;% vipldws2_B.Assignment_io
	  section.data(10).logicalSrcIdx = 28;
	  section.data(10).dtTransOffset = 72;
	
	  ;% vipldws2_B.Assignment_o
	  section.data(11).logicalSrcIdx = 29;
	  section.data(11).dtTransOffset = 392;
	
	  ;% vipldws2_B.Assignment_p
	  section.data(12).logicalSrcIdx = 30;
	  section.data(12).dtTransOffset = 472;
	
	  ;% vipldws2_B.Assignment_a
	  section.data(13).logicalSrcIdx = 31;
	  section.data(13).dtTransOffset = 512;
	
	  ;% vipldws2_B.AX
	  section.data(14).logicalSrcIdx = 32;
	  section.data(14).dtTransOffset = 552;
	
	  ;% vipldws2_B.P_prd_Reshape
	  section.data(15).logicalSrcIdx = 33;
	  section.data(15).dtTransOffset = 556;
	
	  ;% vipldws2_B.Z_est_Multiply
	  section.data(16).logicalSrcIdx = 34;
	  section.data(16).dtTransOffset = 572;
	
	  ;% vipldws2_B.Z_prd_Multiply
	  section.data(17).logicalSrcIdx = 35;
	  section.data(17).dtTransOffset = 574;
	
	  ;% vipldws2_B.uDFIRFilter
	  section.data(18).logicalSrcIdx = 36;
	  section.data(18).dtTransOffset = 576;
	
	  ;% vipldws2_B.Saturation
	  section.data(19).logicalSrcIdx = 37;
	  section.data(19).dtTransOffset = 38976;
	
	  ;% vipldws2_B.selectrho5
	  section.data(20).logicalSrcIdx = 38;
	  section.data(20).dtTransOffset = 77376;
	
	  ;% vipldws2_B.Xold
	  section.data(21).logicalSrcIdx = 39;
	  section.data(21).dtTransOffset = 77607;
	
	  ;% vipldws2_B.OverwriteValues
	  section.data(22).logicalSrcIdx = 40;
	  section.data(22).dtTransOffset = 77647;
	
	  ;% vipldws2_B.OverwriteValues1
	  section.data(23).logicalSrcIdx = 41;
	  section.data(23).dtTransOffset = 200587;
	
	  ;% vipldws2_B.Selectorrho
	  section.data(24).logicalSrcIdx = 42;
	  section.data(24).dtTransOffset = 323527;
	
	  ;% vipldws2_B.Selectortheta
	  section.data(25).logicalSrcIdx = 43;
	  section.data(25).dtTransOffset = 323529;
	
	  ;% vipldws2_B.selectrho5_f
	  section.data(26).logicalSrcIdx = 44;
	  section.data(26).dtTransOffset = 323531;
	
	  ;% vipldws2_B.selectrho2
	  section.data(27).logicalSrcIdx = 45;
	  section.data(27).dtTransOffset = 323551;
	
	  ;% vipldws2_B.selectrho5_m
	  section.data(28).logicalSrcIdx = 46;
	  section.data(28).dtTransOffset = 323571;
	
	  ;% vipldws2_B.Selector_a
	  section.data(29).logicalSrcIdx = 47;
	  section.data(29).dtTransOffset = 324327;
	
	  ;% vipldws2_B.d
	  section.data(30).logicalSrcIdx = 64;
	  section.data(30).dtTransOffset = 439527;
	
	  ;% vipldws2_B.MatrixScaling
	  section.data(31).logicalSrcIdx = 65;
	  section.data(31).dtTransOffset = 439529;
	
	  ;% vipldws2_B.BackwardSubstitution
	  section.data(32).logicalSrcIdx = 66;
	  section.data(32).dtTransOffset = 439537;
	
	  ;% vipldws2_B.KTrans
	  section.data(33).logicalSrcIdx = 67;
	  section.data(33).dtTransOffset = 439545;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% vipldws2_B.DataTypeConversion1
	  section.data(1).logicalSrcIdx = 48;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_B.DrawShapes_m
	  section.data(2).logicalSrcIdx = 49;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vipldws2_B.InsertText
	  section.data(3).logicalSrcIdx = 50;
	  section.data(3).dtTransOffset = 230401;
	
	  ;% vipldws2_B.InsertTextLeftLane
	  section.data(4).logicalSrcIdx = 51;
	  section.data(4).dtTransOffset = 460801;
	
	  ;% vipldws2_B.Selectorrho_c
	  section.data(5).logicalSrcIdx = 52;
	  section.data(5).dtTransOffset = 691201;
	
	  ;% vipldws2_B.Selectortheta_i
	  section.data(6).logicalSrcIdx = 53;
	  section.data(6).dtTransOffset = 691202;
	
	  ;% vipldws2_B.Selectorrho_o
	  section.data(7).logicalSrcIdx = 54;
	  section.data(7).dtTransOffset = 691203;
	
	  ;% vipldws2_B.Selectortheta_g
	  section.data(8).logicalSrcIdx = 55;
	  section.data(8).dtTransOffset = 691204;
	
	  ;% vipldws2_B.Switch1
	  section.data(9).logicalSrcIdx = 56;
	  section.data(9).dtTransOffset = 691205;
	
	  ;% vipldws2_B.Selector2_b
	  section.data(10).logicalSrcIdx = 57;
	  section.data(10).dtTransOffset = 691207;
	
	  ;% vipldws2_B.Rho_2
	  section.data(11).logicalSrcIdx = 58;
	  section.data(11).dtTransOffset = 691209;
	
	  ;% vipldws2_B.Switch_m
	  section.data(12).logicalSrcIdx = 59;
	  section.data(12).dtTransOffset = 691210;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% vipldws2_B.Init_p
	  section.data(1).logicalSrcIdx = 78;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_B.En_Delay
	  section.data(2).logicalSrcIdx = 79;
	  section.data(2).dtTransOffset = 20;
	
	  ;% vipldws2_B.ConvertlinesfromPolartoCartesia
	  section.data(3).logicalSrcIdx = 80;
	  section.data(3).dtTransOffset = 40;
	
	  ;% vipldws2_B.Transpose
	  section.data(4).logicalSrcIdx = 81;
	  section.data(4).dtTransOffset = 120;
	
	  ;% vipldws2_B.Widthoftheimage
	  section.data(5).logicalSrcIdx = 82;
	  section.data(5).dtTransOffset = 200;
	
	  ;% vipldws2_B.Switch1_b
	  section.data(6).logicalSrcIdx = 86;
	  section.data(6).dtTransOffset = 202;
	
	  ;% vipldws2_B.MatrixConcatenation5
	  section.data(7).logicalSrcIdx = 87;
	  section.data(7).dtTransOffset = 206;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 54;
      section.data(54)  = dumData; %prealloc
      
	  ;% vipldws2_B.rho_1
	  section.data(1).logicalSrcIdx = 83;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_B.Distancethresholdfordeparturewa
	  section.data(2).logicalSrcIdx = 84;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vipldws2_B.Counter
	  section.data(3).logicalSrcIdx = 85;
	  section.data(3).dtTransOffset = 2;
	
	  ;% vipldws2_B.Selector_h
	  section.data(4).logicalSrcIdx = 88;
	  section.data(4).dtTransOffset = 3;
	
	  ;% vipldws2_B.Bias3
	  section.data(5).logicalSrcIdx = 89;
	  section.data(5).dtTransOffset = 4;
	
	  ;% vipldws2_B.Bias
	  section.data(6).logicalSrcIdx = 90;
	  section.data(6).dtTransOffset = 8;
	
	  ;% vipldws2_B.Xnew_m
	  section.data(7).logicalSrcIdx = 91;
	  section.data(7).dtTransOffset = 16;
	
	  ;% vipldws2_B.out3rdLane
	  section.data(8).logicalSrcIdx = 92;
	  section.data(8).dtTransOffset = 36;
	
	  ;% vipldws2_B.HoughLines
	  section.data(9).logicalSrcIdx = 93;
	  section.data(9).dtTransOffset = 40;
	
	  ;% vipldws2_B.Transpose_g
	  section.data(10).logicalSrcIdx = 94;
	  section.data(10).dtTransOffset = 44;
	
	  ;% vipldws2_B.HoughLines1
	  section.data(11).logicalSrcIdx = 95;
	  section.data(11).dtTransOffset = 48;
	
	  ;% vipldws2_B.Transpose1
	  section.data(12).logicalSrcIdx = 96;
	  section.data(12).dtTransOffset = 52;
	
	  ;% vipldws2_B.ForIterator
	  section.data(13).logicalSrcIdx = 97;
	  section.data(13).dtTransOffset = 56;
	
	  ;% vipldws2_B.ForIterator_a
	  section.data(14).logicalSrcIdx = 98;
	  section.data(14).dtTransOffset = 57;
	
	  ;% vipldws2_B.Assignment1
	  section.data(15).logicalSrcIdx = 99;
	  section.data(15).dtTransOffset = 58;
	
	  ;% vipldws2_B.Saturation_h
	  section.data(16).logicalSrcIdx = 100;
	  section.data(16).dtTransOffset = 78;
	
	  ;% vipldws2_B.Selector1_b
	  section.data(17).logicalSrcIdx = 101;
	  section.data(17).dtTransOffset = 98;
	
	  ;% vipldws2_B.ForIterator_l
	  section.data(18).logicalSrcIdx = 102;
	  section.data(18).dtTransOffset = 99;
	
	  ;% vipldws2_B.Assignment1_m
	  section.data(19).logicalSrcIdx = 103;
	  section.data(19).dtTransOffset = 100;
	
	  ;% vipldws2_B.Assignment2
	  section.data(20).logicalSrcIdx = 104;
	  section.data(20).dtTransOffset = 500;
	
	  ;% vipldws2_B.Add_e
	  section.data(21).logicalSrcIdx = 105;
	  section.data(21).dtTransOffset = 900;
	
	  ;% vipldws2_B.Assignment_k
	  section.data(22).logicalSrcIdx = 106;
	  section.data(22).dtTransOffset = 1300;
	
	  ;% vipldws2_B.Assignment3
	  section.data(23).logicalSrcIdx = 107;
	  section.data(23).dtTransOffset = 1340;
	
	  ;% vipldws2_B.ForIterator_j
	  section.data(24).logicalSrcIdx = 108;
	  section.data(24).dtTransOffset = 1360;
	
	  ;% vipldws2_B.Selector1_n
	  section.data(25).logicalSrcIdx = 109;
	  section.data(25).dtTransOffset = 1361;
	
	  ;% vipldws2_B.Selector1_i
	  section.data(26).logicalSrcIdx = 110;
	  section.data(26).dtTransOffset = 1362;
	
	  ;% vipldws2_B.Assignment_p2
	  section.data(27).logicalSrcIdx = 111;
	  section.data(27).dtTransOffset = 1382;
	
	  ;% vipldws2_B.ForIterator_f
	  section.data(28).logicalSrcIdx = 112;
	  section.data(28).dtTransOffset = 1782;
	
	  ;% vipldws2_B.Assignment_j
	  section.data(29).logicalSrcIdx = 113;
	  section.data(29).dtTransOffset = 1783;
	
	  ;% vipldws2_B.Add7
	  section.data(30).logicalSrcIdx = 114;
	  section.data(30).dtTransOffset = 1803;
	
	  ;% vipldws2_B.Iterator
	  section.data(31).logicalSrcIdx = 115;
	  section.data(31).dtTransOffset = 1804;
	
	  ;% vipldws2_B.En_Selector
	  section.data(32).logicalSrcIdx = 116;
	  section.data(32).dtTransOffset = 1805;
	
	  ;% vipldws2_B.ForIterator_e
	  section.data(33).logicalSrcIdx = 117;
	  section.data(33).dtTransOffset = 1806;
	
	  ;% vipldws2_B.ForIterator_fi
	  section.data(34).logicalSrcIdx = 118;
	  section.data(34).dtTransOffset = 1807;
	
	  ;% vipldws2_B.Intersectionwithbottomimageboun
	  section.data(35).logicalSrcIdx = 119;
	  section.data(35).dtTransOffset = 1808;
	
	  ;% vipldws2_B.Intersectionwithbottomimagebo_o
	  section.data(36).logicalSrcIdx = 120;
	  section.data(36).dtTransOffset = 1809;
	
	  ;% vipldws2_B.Intersectionwithbottomimagebo_g
	  section.data(37).logicalSrcIdx = 121;
	  section.data(37).dtTransOffset = 1813;
	
	  ;% vipldws2_B.Intersectionwithbottomimagebo_c
	  section.data(38).logicalSrcIdx = 122;
	  section.data(38).dtTransOffset = 1814;
	
	  ;% vipldws2_B.Xold_g
	  section.data(39).logicalSrcIdx = 123;
	  section.data(39).dtTransOffset = 1818;
	
	  ;% vipldws2_B.Bias1
	  section.data(40).logicalSrcIdx = 124;
	  section.data(40).dtTransOffset = 1838;
	
	  ;% vipldws2_B.Selector1_il
	  section.data(41).logicalSrcIdx = 125;
	  section.data(41).dtTransOffset = 1918;
	
	  ;% vipldws2_B.MultiportSelector_o1
	  section.data(42).logicalSrcIdx = 126;
	  section.data(42).dtTransOffset = 1998;
	
	  ;% vipldws2_B.MultiportSelector_o2
	  section.data(43).logicalSrcIdx = 127;
	  section.data(43).dtTransOffset = 2000;
	
	  ;% vipldws2_B.MultiportSelector_o3
	  section.data(44).logicalSrcIdx = 128;
	  section.data(44).dtTransOffset = 2002;
	
	  ;% vipldws2_B.MultiportSelector_o4
	  section.data(45).logicalSrcIdx = 129;
	  section.data(45).dtTransOffset = 2004;
	
	  ;% vipldws2_B.Selector2_m
	  section.data(46).logicalSrcIdx = 130;
	  section.data(46).dtTransOffset = 2006;
	
	  ;% vipldws2_B.Transpose1_p
	  section.data(47).logicalSrcIdx = 131;
	  section.data(47).dtTransOffset = 2014;
	
	  ;% vipldws2_B.MatrixConcatenation6
	  section.data(48).logicalSrcIdx = 132;
	  section.data(48).dtTransOffset = 2022;
	
	  ;% vipldws2_B.Selector2_h
	  section.data(49).logicalSrcIdx = 133;
	  section.data(49).dtTransOffset = 2034;
	
	  ;% vipldws2_B.Transpose1_b
	  section.data(50).logicalSrcIdx = 134;
	  section.data(50).dtTransOffset = 2046;
	
	  ;% vipldws2_B.TmpSignalConversionAtDrawShapes
	  section.data(51).logicalSrcIdx = 135;
	  section.data(51).dtTransOffset = 2058;
	
	  ;% vipldws2_B.Selector1_ce
	  section.data(52).logicalSrcIdx = 136;
	  section.data(52).dtTransOffset = 2062;
	
	  ;% vipldws2_B.Selector2_l
	  section.data(53).logicalSrcIdx = 137;
	  section.data(53).dtTransOffset = 2066;
	
	  ;% vipldws2_B.DataTypeConversion3
	  section.data(54).logicalSrcIdx = 139;
	  section.data(54).dtTransOffset = 2070;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% vipldws2_B.Minimum_o1
	  section.data(1).logicalSrcIdx = 138;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_B.Switch1_l
	  section.data(2).logicalSrcIdx = 140;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vipldws2_B.Rst_Selector
	  section.data(3).logicalSrcIdx = 141;
	  section.data(3).dtTransOffset = 2;
	
	  ;% vipldws2_B.selectrho5_b
	  section.data(4).logicalSrcIdx = 142;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% vipldws2_B.Minimum_o2
	  section.data(1).logicalSrcIdx = 157;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(10) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% vipldws2_B.FindLocalMaxima
	  section.data(1).logicalSrcIdx = 162;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_B.Selector1_m
	  section.data(2).logicalSrcIdx = 163;
	  section.data(2).dtTransOffset = 4;
	
	  ;% vipldws2_B.Transpose_m
	  section.data(3).logicalSrcIdx = 164;
	  section.data(3).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(11) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% vipldws2_B.Minimum
	  section.data(1).logicalSrcIdx = 155;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_B.Switch3
	  section.data(2).logicalSrcIdx = 156;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(12) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% vipldws2_B.FindLocalMaxima1_o1
	  section.data(1).logicalSrcIdx = 158;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_B.FindLocalMaxima1_o2
	  section.data(2).logicalSrcIdx = 159;
	  section.data(2).dtTransOffset = 2;
	
	  ;% vipldws2_B.FindLocalMaxima1_o1_f
	  section.data(3).logicalSrcIdx = 160;
	  section.data(3).dtTransOffset = 3;
	
	  ;% vipldws2_B.FindLocalMaxima1_o2_c
	  section.data(4).logicalSrcIdx = 161;
	  section.data(4).dtTransOffset = 5;
	
	  ;% vipldws2_B.Selector2_mw
	  section.data(5).logicalSrcIdx = 165;
	  section.data(5).dtTransOffset = 6;
	
	  ;% vipldws2_B.Transpose_b
	  section.data(6).logicalSrcIdx = 166;
	  section.data(6).dtTransOffset = 8;
	
	  ;% vipldws2_B.Selector1_e
	  section.data(7).logicalSrcIdx = 167;
	  section.data(7).dtTransOffset = 10;
	
	  ;% vipldws2_B.Transpose_gb
	  section.data(8).logicalSrcIdx = 168;
	  section.data(8).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(13) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% vipldws2_B.RawMessage
	  section.data(1).logicalSrcIdx = 172;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_B.Delay
	  section.data(2).logicalSrcIdx = 173;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vipldws2_B.outMsg
	  section.data(3).logicalSrcIdx = 174;
	  section.data(3).dtTransOffset = 2;
	
	  ;% vipldws2_B.colorAndTypeIdx
	  section.data(4).logicalSrcIdx = 175;
	  section.data(4).dtTransOffset = 3;
	
	  ;% vipldws2_B.Switch_a
	  section.data(5).logicalSrcIdx = 176;
	  section.data(5).dtTransOffset = 5;
	
	  ;% vipldws2_B.Switch1_j
	  section.data(6).logicalSrcIdx = 177;
	  section.data(6).dtTransOffset = 6;
	
	  ;% vipldws2_B.Bias1_j
	  section.data(7).logicalSrcIdx = 178;
	  section.data(7).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(14) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% vipldws2_B.MatrixConcatenate
	  section.data(1).logicalSrcIdx = 180;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_B.Rotate
	  section.data(2).logicalSrcIdx = 181;
	  section.data(2).dtTransOffset = 230400;
	
	  ;% vipldws2_B.ImageDataTypeConversion_p
	  section.data(3).logicalSrcIdx = 182;
	  section.data(3).dtTransOffset = 460800;
	
	  ;% vipldws2_B.y_g
	  section.data(4).logicalSrcIdx = 183;
	  section.data(4).dtTransOffset = 691200;
	
	  ;% vipldws2_B.y_b
	  section.data(5).logicalSrcIdx = 184;
	  section.data(5).dtTransOffset = 921600;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(15) = section;
      clear section
      
      section.nData     = 23;
      section.data(23)  = dumData; %prealloc
      
	  ;% vipldws2_B.Compare
	  section.data(1).logicalSrcIdx = 187;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_B.LogicalOperator4
	  section.data(2).logicalSrcIdx = 188;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vipldws2_B.LogicalOperator2
	  section.data(3).logicalSrcIdx = 189;
	  section.data(3).dtTransOffset = 2;
	
	  ;% vipldws2_B.LogicalOperator1
	  section.data(4).logicalSrcIdx = 190;
	  section.data(4).dtTransOffset = 3;
	
	  ;% vipldws2_B.LogicalOperator
	  section.data(5).logicalSrcIdx = 191;
	  section.data(5).dtTransOffset = 4;
	
	  ;% vipldws2_B.NSampleEnable
	  section.data(6).logicalSrcIdx = 192;
	  section.data(6).dtTransOffset = 5;
	
	  ;% vipldws2_B.Compare_m
	  section.data(7).logicalSrcIdx = 193;
	  section.data(7).dtTransOffset = 6;
	
	  ;% vipldws2_B.Assignment2_m
	  section.data(8).logicalSrcIdx = 194;
	  section.data(8).dtTransOffset = 26;
	
	  ;% vipldws2_B.Selector2_fh
	  section.data(9).logicalSrcIdx = 195;
	  section.data(9).dtTransOffset = 46;
	
	  ;% vipldws2_B.Rst_And
	  section.data(10).logicalSrcIdx = 196;
	  section.data(10).dtTransOffset = 47;
	
	  ;% vipldws2_B.En_Or
	  section.data(11).logicalSrcIdx = 197;
	  section.data(11).dtTransOffset = 48;
	
	  ;% vipldws2_B.Assignment_d
	  section.data(12).logicalSrcIdx = 198;
	  section.data(12).dtTransOffset = 49;
	
	  ;% vipldws2_B.In
	  section.data(13).logicalSrcIdx = 199;
	  section.data(13).dtTransOffset = 51;
	
	  ;% vipldws2_B.Imagethresholding
	  section.data(14).logicalSrcIdx = 200;
	  section.data(14).dtTransOffset = 52;
	
	  ;% vipldws2_B.RelationalOperator1
	  section.data(15).logicalSrcIdx = 201;
	  section.data(15).dtTransOffset = 38452;
	
	  ;% vipldws2_B.MultiportSelector1_o1
	  section.data(16).logicalSrcIdx = 202;
	  section.data(16).dtTransOffset = 38453;
	
	  ;% vipldws2_B.MultiportSelector1_o2
	  section.data(17).logicalSrcIdx = 203;
	  section.data(17).dtTransOffset = 38454;
	
	  ;% vipldws2_B.Selector_b
	  section.data(18).logicalSrcIdx = 204;
	  section.data(18).dtTransOffset = 38455;
	
	  ;% vipldws2_B.Compare_p
	  section.data(19).logicalSrcIdx = 205;
	  section.data(19).dtTransOffset = 38456;
	
	  ;% vipldws2_B.Compare_mb
	  section.data(20).logicalSrcIdx = 206;
	  section.data(20).dtTransOffset = 38476;
	
	  ;% vipldws2_B.En_Not
	  section.data(21).logicalSrcIdx = 207;
	  section.data(21).dtTransOffset = 38477;
	
	  ;% vipldws2_B.RelationalOperator2
	  section.data(22).logicalSrcIdx = 208;
	  section.data(22).dtTransOffset = 38478;
	
	  ;% vipldws2_B.RelationalOperator3
	  section.data(23).logicalSrcIdx = 209;
	  section.data(23).dtTransOffset = 38479;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(16) = section;
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
    nTotSects     = 15;
    sectIdxOffset = 16;
    
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
    ;% Auto data (vipldws2_DW)
    ;%
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% vipldws2_DW.FrameRateDisplay_PrevTime
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_DW.FrameRateDisplay_TotalTime
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vipldws2_DW.FrameRateDisplay_Count
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% vipldws2_DW.MatrixConcatenation3_PWORK
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_DW.SafetyMarginSignals_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vipldws2_DW.FromWorkspace_PWORK.TimePtr
	  section.data(3).logicalSrcIdx = 5;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% vipldws2_DW.FixPtUnitDelay1_DSTATE
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_DW.UnitDelay2_DSTATE
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 40;
	
	  ;% vipldws2_DW.UnitDelay3_DSTATE
	  section.data(3).logicalSrcIdx = 8;
	  section.data(3).dtTransOffset = 120;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% vipldws2_DW.FixPtUnitDelay1_DSTATE_d
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_DW.En_Delay_DSTATE
	  section.data(2).logicalSrcIdx = 10;
	  section.data(2).dtTransOffset = 20;
	
	  ;% vipldws2_DW.Delay1_DSTATE
	  section.data(3).logicalSrcIdx = 11;
	  section.data(3).dtTransOffset = 40;
	
	  ;% vipldws2_DW.Min_left_dis_DSTATE
	  section.data(4).logicalSrcIdx = 12;
	  section.data(4).dtTransOffset = 440;
	
	  ;% vipldws2_DW.Min_left_pts_DSTATE
	  section.data(5).logicalSrcIdx = 13;
	  section.data(5).dtTransOffset = 441;
	
	  ;% vipldws2_DW.Min_right_dis_DSTATE
	  section.data(6).logicalSrcIdx = 14;
	  section.data(6).dtTransOffset = 445;
	
	  ;% vipldws2_DW.Min_right_pts_DSTATE
	  section.data(7).logicalSrcIdx = 15;
	  section.data(7).dtTransOffset = 446;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 14;
      section.data(14)  = dumData; %prealloc
      
	  ;% vipldws2_DW.ColorSpaceConversion_DWORK1
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_DW.Imagethresholding_P_DW
	  section.data(2).logicalSrcIdx = 17;
	  section.data(2).dtTransOffset = 230400;
	
	  ;% vipldws2_DW.Imagethresholding_MU_DW
	  section.data(3).logicalSrcIdx = 18;
	  section.data(3).dtTransOffset = 230656;
	
	  ;% vipldws2_DW.FindLocalMaxima1_TEMP_IN_DWORKS
	  section.data(4).logicalSrcIdx = 19;
	  section.data(4).dtTransOffset = 230912;
	
	  ;% vipldws2_DW.FindLocalMaxima_TEMP_IN_DWORKS
	  section.data(5).logicalSrcIdx = 20;
	  section.data(5).dtTransOffset = 231143;
	
	  ;% vipldws2_DW.FindLocalMaxima1_TEMP_IN_DWOR_e
	  section.data(6).logicalSrcIdx = 21;
	  section.data(6).dtTransOffset = 354083;
	
	  ;% vipldws2_DW.ColorSpaceConversion1_DWORK1
	  section.data(7).logicalSrcIdx = 22;
	  section.data(7).dtTransOffset = 354839;
	
	  ;% vipldws2_DW.InsertText_colorVectorDW
	  section.data(8).logicalSrcIdx = 23;
	  section.data(8).dtTransOffset = 470039;
	
	  ;% vipldws2_DW.InsertTextLeftLane_colorVectorD
	  section.data(9).logicalSrcIdx = 24;
	  section.data(9).dtTransOffset = 470042;
	
	  ;% vipldws2_DW.InsertTextRightLane_colorVector
	  section.data(10).logicalSrcIdx = 25;
	  section.data(10).dtTransOffset = 470045;
	
	  ;% vipldws2_DW.DrawShapes_DW_FillColorAdd
	  section.data(11).logicalSrcIdx = 26;
	  section.data(11).dtTransOffset = 470048;
	
	  ;% vipldws2_DW.DrawShapes_DW_OneMOpacity
	  section.data(12).logicalSrcIdx = 27;
	  section.data(12).dtTransOffset = 470051;
	
	  ;% vipldws2_DW.Add1_DWORK1
	  section.data(13).logicalSrcIdx = 28;
	  section.data(13).dtTransOffset = 470052;
	
	  ;% vipldws2_DW.LDLFactorization_VMX
	  section.data(14).logicalSrcIdx = 29;
	  section.data(14).dtTransOffset = 470053;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 28;
      section.data(28)  = dumData; %prealloc
      
	  ;% vipldws2_DW.uDFIRFilter_bSEnd
	  section.data(1).logicalSrcIdx = 30;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_DW.uDFIRFilter_bSPreEdg
	  section.data(2).logicalSrcIdx = 31;
	  section.data(2).dtTransOffset = 2;
	
	  ;% vipldws2_DW.uDFIRFilter_bSPstEdg
	  section.data(3).logicalSrcIdx = 32;
	  section.data(3).dtTransOffset = 4;
	
	  ;% vipldws2_DW.uDFIRFilter_bSStart
	  section.data(4).logicalSrcIdx = 33;
	  section.data(4).dtTransOffset = 6;
	
	  ;% vipldws2_DW.uDFIRFilter_inSEnd
	  section.data(5).logicalSrcIdx = 34;
	  section.data(5).dtTransOffset = 8;
	
	  ;% vipldws2_DW.uDFIRFilter_inSStart
	  section.data(6).logicalSrcIdx = 35;
	  section.data(6).dtTransOffset = 10;
	
	  ;% vipldws2_DW.uDFIRFilter_mLoc
	  section.data(7).logicalSrcIdx = 36;
	  section.data(7).dtTransOffset = 12;
	
	  ;% vipldws2_DW.uDFIRFilter_mWidth
	  section.data(8).logicalSrcIdx = 37;
	  section.data(8).dtTransOffset = 22;
	
	  ;% vipldws2_DW.uDFIRFilter_oSPreEdg
	  section.data(9).logicalSrcIdx = 38;
	  section.data(9).dtTransOffset = 32;
	
	  ;% vipldws2_DW.uDFIRFilter_oSPstEdg
	  section.data(10).logicalSrcIdx = 39;
	  section.data(10).dtTransOffset = 34;
	
	  ;% vipldws2_DW.uDFIRFilter_oSStart
	  section.data(11).logicalSrcIdx = 40;
	  section.data(11).dtTransOffset = 36;
	
	  ;% vipldws2_DW.uDFIRFilter_oSecEnd
	  section.data(12).logicalSrcIdx = 41;
	  section.data(12).dtTransOffset = 38;
	
	  ;% vipldws2_DW.uDFIRFilter_sCnt
	  section.data(13).logicalSrcIdx = 42;
	  section.data(13).dtTransOffset = 40;
	
	  ;% vipldws2_DW.FindLocalMaxima_DIMS1
	  section.data(14).logicalSrcIdx = 43;
	  section.data(14).dtTransOffset = 42;
	
	  ;% vipldws2_DW.Selector1_DIMS1
	  section.data(15).logicalSrcIdx = 44;
	  section.data(15).dtTransOffset = 44;
	
	  ;% vipldws2_DW.Transpose_DIMS1
	  section.data(16).logicalSrcIdx = 45;
	  section.data(16).dtTransOffset = 46;
	
	  ;% vipldws2_DW.selectrho_DIMS1
	  section.data(17).logicalSrcIdx = 46;
	  section.data(17).dtTransOffset = 48;
	
	  ;% vipldws2_DW.Selectorrho_DIMS1
	  section.data(18).logicalSrcIdx = 47;
	  section.data(18).dtTransOffset = 50;
	
	  ;% vipldws2_DW.selectrho3_DIMS1
	  section.data(19).logicalSrcIdx = 48;
	  section.data(19).dtTransOffset = 52;
	
	  ;% vipldws2_DW.Selectortheta_DIMS1
	  section.data(20).logicalSrcIdx = 49;
	  section.data(20).dtTransOffset = 54;
	
	  ;% vipldws2_DW.MatrixConcatenation3_DIMS1
	  section.data(21).logicalSrcIdx = 50;
	  section.data(21).dtTransOffset = 56;
	
	  ;% vipldws2_DW.DrawShapes_DW_Polygon
	  section.data(22).logicalSrcIdx = 51;
	  section.data(22).dtTransOffset = 58;
	
	  ;% vipldws2_DW.DrawShapes_DW_Points
	  section.data(23).logicalSrcIdx = 52;
	  section.data(23).dtTransOffset = 130;
	
	  ;% vipldws2_DW.InsertText_TxtLoc
	  section.data(24).logicalSrcIdx = 53;
	  section.data(24).dtTransOffset = 146;
	
	  ;% vipldws2_DW.InsertTextLeftLane_TxtLoc
	  section.data(25).logicalSrcIdx = 54;
	  section.data(25).dtTransOffset = 148;
	
	  ;% vipldws2_DW.InsertTextRightLane_TxtLoc
	  section.data(26).logicalSrcIdx = 55;
	  section.data(26).dtTransOffset = 150;
	
	  ;% vipldws2_DW.Selector2_DIMS1
	  section.data(27).logicalSrcIdx = 56;
	  section.data(27).dtTransOffset = 152;
	
	  ;% vipldws2_DW.Selector1_DIMS1_l
	  section.data(28).logicalSrcIdx = 57;
	  section.data(28).dtTransOffset = 154;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% vipldws2_DW.FindLocalMaxima_NUMPEAKS_DWORK
	  section.data(1).logicalSrcIdx = 58;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_DW.NSampleEnable_Counter
	  section.data(2).logicalSrcIdx = 59;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vipldws2_DW.InsertText_TxtSelctn
	  section.data(3).logicalSrcIdx = 60;
	  section.data(3).dtTransOffset = 2;
	
	  ;% vipldws2_DW.InsertTextLeftLane_TxtSelctn
	  section.data(4).logicalSrcIdx = 61;
	  section.data(4).dtTransOffset = 3;
	
	  ;% vipldws2_DW.InsertTextRightLane_TxtSelctn
	  section.data(5).logicalSrcIdx = 62;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% vipldws2_DW.FromWorkspace_IWORK.PrevIndex
	  section.data(1).logicalSrcIdx = 63;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% vipldws2_DW.Counter_Count
	  section.data(1).logicalSrcIdx = 64;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% vipldws2_DW.Delay_DSTATE
	  section.data(1).logicalSrcIdx = 65;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_DW.Delay1_DSTATE_e
	  section.data(2).logicalSrcIdx = 66;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% vipldws2_DW.FixPtUnitDelay2_DSTATE
	  section.data(1).logicalSrcIdx = 67;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_DW.FixPtUnitDelay2_DSTATE_b
	  section.data(2).logicalSrcIdx = 68;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% vipldws2_DW.Delay1_DSTATE_g
	  section.data(1).logicalSrcIdx = 69;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_DW.Minimum_Valdata
	  section.data(2).logicalSrcIdx = 70;
	  section.data(2).dtTransOffset = 20;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% vipldws2_DW.Enablesignalgenerator_SubsysRan
	  section.data(1).logicalSrcIdx = 71;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_DW.SampleandHold_SubsysRanBC
	  section.data(2).logicalSrcIdx = 72;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vipldws2_DW.Subsystem_SubsysRanBC
	  section.data(3).logicalSrcIdx = 73;
	  section.data(3).dtTransOffset = 2;
	
	  ;% vipldws2_DW.Draw3rdLine_SubsysRanBC
	  section.data(4).logicalSrcIdx = 74;
	  section.data(4).dtTransOffset = 3;
	
	  ;% vipldws2_DW.DrawPolygon_SubsysRanBC
	  section.data(5).logicalSrcIdx = 75;
	  section.data(5).dtTransOffset = 4;
	
	  ;% vipldws2_DW.Selectalinefromtherepositoryifi
	  section.data(6).logicalSrcIdx = 76;
	  section.data(6).dtTransOffset = 5;
	
	  ;% vipldws2_DW.Differencebetweentwolines_Subsy
	  section.data(7).logicalSrcIdx = 77;
	  section.data(7).dtTransOffset = 6;
	
	  ;% vipldws2_DW.Options_SubsysRanBC
	  section.data(8).logicalSrcIdx = 78;
	  section.data(8).dtTransOffset = 7;
	
	  ;% vipldws2_DW.Core_SubsysRanBC
	  section.data(9).logicalSrcIdx = 79;
	  section.data(9).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 13;
      section.data(13)  = dumData; %prealloc
      
	  ;% vipldws2_DW.DrawShapes_DW_PixCount
	  section.data(1).logicalSrcIdx = 80;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_DW.InsertText_RepBuf
	  section.data(2).logicalSrcIdx = 81;
	  section.data(2).dtTransOffset = 320;
	
	  ;% vipldws2_DW.InsertText_VarHolder
	  section.data(3).logicalSrcIdx = 82;
	  section.data(3).dtTransOffset = 321;
	
	  ;% vipldws2_DW.InsertText_StringDataDW
	  section.data(4).logicalSrcIdx = 83;
	  section.data(4).dtTransOffset = 322;
	
	  ;% vipldws2_DW.InsertTextLeftLane_RepBuf
	  section.data(5).logicalSrcIdx = 84;
	  section.data(5).dtTransOffset = 396;
	
	  ;% vipldws2_DW.InsertTextLeftLane_VarHolder
	  section.data(6).logicalSrcIdx = 85;
	  section.data(6).dtTransOffset = 397;
	
	  ;% vipldws2_DW.InsertTextLeftLane_StringDataDW
	  section.data(7).logicalSrcIdx = 86;
	  section.data(7).dtTransOffset = 398;
	
	  ;% vipldws2_DW.InsertTextRightLane_RepBuf
	  section.data(8).logicalSrcIdx = 87;
	  section.data(8).dtTransOffset = 451;
	
	  ;% vipldws2_DW.InsertTextRightLane_VarHolder
	  section.data(9).logicalSrcIdx = 88;
	  section.data(9).dtTransOffset = 452;
	
	  ;% vipldws2_DW.InsertTextRightLane_StringDataD
	  section.data(10).logicalSrcIdx = 89;
	  section.data(10).dtTransOffset = 453;
	
	  ;% vipldws2_DW.ForIterator_IterationMarker
	  section.data(11).logicalSrcIdx = 90;
	  section.data(11).dtTransOffset = 506;
	
	  ;% vipldws2_DW.ForIterator_IterationMarker_c
	  section.data(12).logicalSrcIdx = 91;
	  section.data(12).dtTransOffset = 507;
	
	  ;% vipldws2_DW.Iterator_IterationMarker
	  section.data(13).logicalSrcIdx = 92;
	  section.data(13).dtTransOffset = 508;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% vipldws2_DW.uDFIRFilter_isHgtUpd
	  section.data(1).logicalSrcIdx = 93;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws2_DW.LDLFactorization_STATE
	  section.data(2).logicalSrcIdx = 94;
	  section.data(2).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
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


  targMap.checksum0 = 3383633471;
  targMap.checksum1 = 3478459520;
  targMap.checksum2 = 220928665;
  targMap.checksum3 = 2149239437;

