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
    ;% Auto data (vipldws_P)
    ;%
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% vipldws_P.DrawShapes_color
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_P.uDFIRFilter_filterMtrx
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% vipldws_P.DrawShapes_opacity
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 6;
	
	  ;% vipldws_P.FindLocalMaxima1_threshold
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 7;
	
	  ;% vipldws_P.FindLocalMaxima_threshold
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
	  ;% vipldws_P.FindLocalMaxima1_threshold_b
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 9;
	
	  ;% vipldws_P.UnitDelayResettable1_vinit
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% vipldws_P.CompareToConstant2_const
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_P.CompareToConstant_const
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vipldws_P.CompareToConstant_const_m
	  section.data(3).logicalSrcIdx = 9;
	  section.data(3).dtTransOffset = 2;
	
	  ;% vipldws_P.CompareToConstant1_const
	  section.data(4).logicalSrcIdx = 10;
	  section.data(4).dtTransOffset = 3;
	
	  ;% vipldws_P.CompareToConstant10_const
	  section.data(5).logicalSrcIdx = 11;
	  section.data(5).dtTransOffset = 4;
	
	  ;% vipldws_P.CompareToConstant1_const_o
	  section.data(6).logicalSrcIdx = 12;
	  section.data(6).dtTransOffset = 5;
	
	  ;% vipldws_P.OnlyupdatethelineswhichKalmanfi
	  section.data(7).logicalSrcIdx = 13;
	  section.data(7).dtTransOffset = 6;
	
	  ;% vipldws_P.DrawShapes_lineWidth
	  section.data(8).logicalSrcIdx = 14;
	  section.data(8).dtTransOffset = 7;
	
	  ;% vipldws_P.DrawShapes_lineWidth_i
	  section.data(9).logicalSrcIdx = 15;
	  section.data(9).dtTransOffset = 8;
	
	  ;% vipldws_P.InsertText_textLoc
	  section.data(10).logicalSrcIdx = 16;
	  section.data(10).dtTransOffset = 9;
	
	  ;% vipldws_P.UnitDelayResettable_vinit
	  section.data(11).logicalSrcIdx = 17;
	  section.data(11).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% vipldws_P.NSampleEnable_ActiveLevel
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_P.NSampleEnable_N
	  section.data(2).logicalSrcIdx = 19;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% vipldws_P.Counter_InitialCount
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% vipldws_P.CompareToConstant_const_h
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_P.CompareToConstant1_const_h
	  section.data(2).logicalSrcIdx = 22;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vipldws_P.CompareToConstant2_const_i
	  section.data(3).logicalSrcIdx = 23;
	  section.data(3).dtTransOffset = 2;
	
	  ;% vipldws_P.CompareToConstant1_const_j
	  section.data(4).logicalSrcIdx = 24;
	  section.data(4).dtTransOffset = 3;
	
	  ;% vipldws_P.CompareToConstant1_const_l
	  section.data(5).logicalSrcIdx = 25;
	  section.data(5).dtTransOffset = 4;
	
	  ;% vipldws_P.CompareToConstant2_const_h
	  section.data(6).logicalSrcIdx = 26;
	  section.data(6).dtTransOffset = 5;
	
	  ;% vipldws_P.CompareToConstant_const_n
	  section.data(7).logicalSrcIdx = 27;
	  section.data(7).dtTransOffset = 6;
	
	  ;% vipldws_P.CompareToConstant3_const
	  section.data(8).logicalSrcIdx = 28;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% vipldws_P.DrawShapes_color_e
	  section.data(1).logicalSrcIdx = 29;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% vipldws_P.Constant1_Value
	  section.data(1).logicalSrcIdx = 30;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_P.Constant_Value
	  section.data(2).logicalSrcIdx = 31;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 21;
      section.data(21)  = dumData; %prealloc
      
	  ;% vipldws_P.Constant3_Value
	  section.data(1).logicalSrcIdx = 32;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_P.Hcst_Value
	  section.data(2).logicalSrcIdx = 33;
	  section.data(2).dtTransOffset = 16;
	
	  ;% vipldws_P.Hcst_t_Value
	  section.data(3).logicalSrcIdx = 34;
	  section.data(3).dtTransOffset = 24;
	
	  ;% vipldws_P.Constant2_Value
	  section.data(4).logicalSrcIdx = 35;
	  section.data(4).dtTransOffset = 32;
	
	  ;% vipldws_P.Constant4_Value
	  section.data(5).logicalSrcIdx = 36;
	  section.data(5).dtTransOffset = 36;
	
	  ;% vipldws_P.Constant5_Value
	  section.data(6).logicalSrcIdx = 37;
	  section.data(6).dtTransOffset = 52;
	
	  ;% vipldws_P.Reset_Value_Value
	  section.data(7).logicalSrcIdx = 38;
	  section.data(7).dtTransOffset = 68;
	
	  ;% vipldws_P.Reset_Value_Value_j
	  section.data(8).logicalSrcIdx = 39;
	  section.data(8).dtTransOffset = 84;
	
	  ;% vipldws_P.Reset_Value_Value_b
	  section.data(9).logicalSrcIdx = 40;
	  section.data(9).dtTransOffset = 88;
	
	  ;% vipldws_P.Reset_Value_Value_p
	  section.data(10).logicalSrcIdx = 41;
	  section.data(10).dtTransOffset = 90;
	
	  ;% vipldws_P.Gain_Gain
	  section.data(11).logicalSrcIdx = 42;
	  section.data(11).dtTransOffset = 92;
	
	  ;% vipldws_P.DrawShapes_RTP_FILLCOLOR
	  section.data(12).logicalSrcIdx = 43;
	  section.data(12).dtTransOffset = 93;
	
	  ;% vipldws_P.InsertText_TxtOpacity
	  section.data(13).logicalSrcIdx = 44;
	  section.data(13).dtTransOffset = 99;
	
	  ;% vipldws_P.Yellow1_Value
	  section.data(14).logicalSrcIdx = 45;
	  section.data(14).dtTransOffset = 100;
	
	  ;% vipldws_P.InsertTextLeftLane_TxtOpacity
	  section.data(15).logicalSrcIdx = 46;
	  section.data(15).dtTransOffset = 115;
	
	  ;% vipldws_P.InsertTextRightLane_TxtOpacity
	  section.data(16).logicalSrcIdx = 47;
	  section.data(16).dtTransOffset = 116;
	
	  ;% vipldws_P.Saturation_UpperSat
	  section.data(17).logicalSrcIdx = 48;
	  section.data(17).dtTransOffset = 117;
	
	  ;% vipldws_P.Saturation_LowerSat
	  section.data(18).logicalSrcIdx = 49;
	  section.data(18).dtTransOffset = 118;
	
	  ;% vipldws_P.UnitDelay2_InitialCondition
	  section.data(19).logicalSrcIdx = 50;
	  section.data(19).dtTransOffset = 119;
	
	  ;% vipldws_P.UnitDelay3_InitialCondition
	  section.data(20).logicalSrcIdx = 51;
	  section.data(20).dtTransOffset = 199;
	
	  ;% vipldws_P.min_safety_Value
	  section.data(21).logicalSrcIdx = 52;
	  section.data(21).dtTransOffset = 519;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 39;
      section.data(39)  = dumData; %prealloc
      
	  ;% vipldws_P.ForIterator_IterationLimit
	  section.data(1).logicalSrcIdx = 53;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_P.Constant_Value_i
	  section.data(2).logicalSrcIdx = 54;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vipldws_P.Min_left_dis_InitialCondition
	  section.data(3).logicalSrcIdx = 55;
	  section.data(3).dtTransOffset = 2;
	
	  ;% vipldws_P.Min_left_pts_InitialCondition
	  section.data(4).logicalSrcIdx = 56;
	  section.data(4).dtTransOffset = 3;
	
	  ;% vipldws_P.Min_right_dis_InitialCondition
	  section.data(5).logicalSrcIdx = 57;
	  section.data(5).dtTransOffset = 7;
	
	  ;% vipldws_P.Min_right_pts_InitialCondition
	  section.data(6).logicalSrcIdx = 58;
	  section.data(6).dtTransOffset = 8;
	
	  ;% vipldws_P.Iterator_IterationLimit
	  section.data(7).logicalSrcIdx = 59;
	  section.data(7).dtTransOffset = 12;
	
	  ;% vipldws_P.Constant_Value_l
	  section.data(8).logicalSrcIdx = 60;
	  section.data(8).dtTransOffset = 13;
	
	  ;% vipldws_P.ForIterator_IterationLimit_g
	  section.data(9).logicalSrcIdx = 61;
	  section.data(9).dtTransOffset = 14;
	
	  ;% vipldws_P.Constant2_Value_o
	  section.data(10).logicalSrcIdx = 62;
	  section.data(10).dtTransOffset = 15;
	
	  ;% vipldws_P.ForIterator_IterationLimit_j
	  section.data(11).logicalSrcIdx = 63;
	  section.data(11).dtTransOffset = 415;
	
	  ;% vipldws_P.Constant_Value_iw
	  section.data(12).logicalSrcIdx = 64;
	  section.data(12).dtTransOffset = 416;
	
	  ;% vipldws_P.ForIterator_IterationLimit_n
	  section.data(13).logicalSrcIdx = 65;
	  section.data(13).dtTransOffset = 417;
	
	  ;% vipldws_P.Delay1_InitialCondition
	  section.data(14).logicalSrcIdx = 66;
	  section.data(14).dtTransOffset = 418;
	
	  ;% vipldws_P.Minimum_prodDims
	  section.data(15).logicalSrcIdx = 67;
	  section.data(15).dtTransOffset = 419;
	
	  ;% vipldws_P.Constant2_Value_d
	  section.data(16).logicalSrcIdx = 68;
	  section.data(16).dtTransOffset = 421;
	
	  ;% vipldws_P.Constant1_Value_c
	  section.data(17).logicalSrcIdx = 69;
	  section.data(17).dtTransOffset = 461;
	
	  ;% vipldws_P.Constant2_Value_b
	  section.data(18).logicalSrcIdx = 70;
	  section.data(18).dtTransOffset = 481;
	
	  ;% vipldws_P.Constant_Value_i0
	  section.data(19).logicalSrcIdx = 71;
	  section.data(19).dtTransOffset = 501;
	
	  ;% vipldws_P.Constant_Value_m
	  section.data(20).logicalSrcIdx = 72;
	  section.data(20).dtTransOffset = 502;
	
	  ;% vipldws_P.ForIterator_IterationLimit_a
	  section.data(21).logicalSrcIdx = 73;
	  section.data(21).dtTransOffset = 503;
	
	  ;% vipldws_P.Bias_Bias
	  section.data(22).logicalSrcIdx = 74;
	  section.data(22).dtTransOffset = 504;
	
	  ;% vipldws_P.Saturation_UpperSat_m
	  section.data(23).logicalSrcIdx = 75;
	  section.data(23).dtTransOffset = 505;
	
	  ;% vipldws_P.Saturation_LowerSat_o
	  section.data(24).logicalSrcIdx = 76;
	  section.data(24).dtTransOffset = 506;
	
	  ;% vipldws_P.ForIterator_IterationLimit_gd
	  section.data(25).logicalSrcIdx = 77;
	  section.data(25).dtTransOffset = 507;
	
	  ;% vipldws_P.DSPConstant_Value
	  section.data(26).logicalSrcIdx = 78;
	  section.data(26).dtTransOffset = 508;
	
	  ;% vipldws_P.Switch_Threshold
	  section.data(27).logicalSrcIdx = 79;
	  section.data(27).dtTransOffset = 510;
	
	  ;% vipldws_P.DSPConstant2_Value
	  section.data(28).logicalSrcIdx = 80;
	  section.data(28).dtTransOffset = 511;
	
	  ;% vipldws_P.Switch1_Threshold
	  section.data(29).logicalSrcIdx = 81;
	  section.data(29).dtTransOffset = 513;
	
	  ;% vipldws_P.Bias1_Bias
	  section.data(30).logicalSrcIdx = 82;
	  section.data(30).dtTransOffset = 514;
	
	  ;% vipldws_P.Bias2_Bias
	  section.data(31).logicalSrcIdx = 83;
	  section.data(31).dtTransOffset = 516;
	
	  ;% vipldws_P.En_Delay_InitialCondition
	  section.data(32).logicalSrcIdx = 84;
	  section.data(32).dtTransOffset = 518;
	
	  ;% vipldws_P.Bias1_Bias_l
	  section.data(33).logicalSrcIdx = 85;
	  section.data(33).dtTransOffset = 519;
	
	  ;% vipldws_P.DrawLines4_Value
	  section.data(34).logicalSrcIdx = 86;
	  section.data(34).dtTransOffset = 520;
	
	  ;% vipldws_P.Constant_Value_j
	  section.data(35).logicalSrcIdx = 87;
	  section.data(35).dtTransOffset = 524;
	
	  ;% vipldws_P.Bias3_Bias
	  section.data(36).logicalSrcIdx = 88;
	  section.data(36).dtTransOffset = 527;
	
	  ;% vipldws_P.Bias_Bias_i
	  section.data(37).logicalSrcIdx = 89;
	  section.data(37).dtTransOffset = 531;
	
	  ;% vipldws_P.Saturation_UpperSat_h
	  section.data(38).logicalSrcIdx = 90;
	  section.data(38).dtTransOffset = 539;
	
	  ;% vipldws_P.Saturation_LowerSat_a
	  section.data(39).logicalSrcIdx = 91;
	  section.data(39).dtTransOffset = 540;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% vipldws_P.Delay1_DelayLength
	  section.data(1).logicalSrcIdx = 92;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_P.Delay1_DelayLength_n
	  section.data(2).logicalSrcIdx = 93;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vipldws_P.Delay_DelayLength
	  section.data(3).logicalSrcIdx = 94;
	  section.data(3).dtTransOffset = 2;
	
	  ;% vipldws_P.Delay1_DelayLength_j
	  section.data(4).logicalSrcIdx = 95;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(10) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% vipldws_P.Distancethresholdfordeparturewa
	  section.data(1).logicalSrcIdx = 96;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_P.rho_1_Gain
	  section.data(2).logicalSrcIdx = 97;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(11) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% vipldws_P.Bias2_Bias_k
	  section.data(1).logicalSrcIdx = 98;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_P.Bias3_Bias_c
	  section.data(2).logicalSrcIdx = 99;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vipldws_P.Bias2_Bias_h
	  section.data(3).logicalSrcIdx = 100;
	  section.data(3).dtTransOffset = 2;
	
	  ;% vipldws_P.Bias3_Bias_d
	  section.data(4).logicalSrcIdx = 101;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(12) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% vipldws_P.Constant1_Value_b
	  section.data(1).logicalSrcIdx = 102;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_P.Constant_Value_f
	  section.data(2).logicalSrcIdx = 103;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vipldws_P.DrawLines3_Value
	  section.data(3).logicalSrcIdx = 104;
	  section.data(3).dtTransOffset = 2;
	
	  ;% vipldws_P.DrawLines2_Value
	  section.data(4).logicalSrcIdx = 105;
	  section.data(4).dtTransOffset = 3;
	
	  ;% vipldws_P.DrawLines1_Value
	  section.data(5).logicalSrcIdx = 106;
	  section.data(5).dtTransOffset = 4;
	
	  ;% vipldws_P.DrawLines_Value
	  section.data(6).logicalSrcIdx = 107;
	  section.data(6).dtTransOffset = 5;
	
	  ;% vipldws_P.Bias_Bias_d
	  section.data(7).logicalSrcIdx = 108;
	  section.data(7).dtTransOffset = 6;
	
	  ;% vipldws_P.Bias1_Bias_e
	  section.data(8).logicalSrcIdx = 109;
	  section.data(8).dtTransOffset = 7;
	
	  ;% vipldws_P.Delay_InitialCondition
	  section.data(9).logicalSrcIdx = 110;
	  section.data(9).dtTransOffset = 8;
	
	  ;% vipldws_P.Delay1_InitialCondition_p
	  section.data(10).logicalSrcIdx = 111;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(13) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% vipldws_P.FixPtUnitDelay2_InitialConditio
	  section.data(1).logicalSrcIdx = 112;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_P.FixPtUnitDelay2_InitialCondit_p
	  section.data(2).logicalSrcIdx = 113;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vipldws_P.Switch_CurrentSetting
	  section.data(3).logicalSrcIdx = 114;
	  section.data(3).dtTransOffset = 2;
	
	  ;% vipldws_P.FixPtConstant_Value
	  section.data(4).logicalSrcIdx = 115;
	  section.data(4).dtTransOffset = 3;
	
	  ;% vipldws_P.FixPtConstant_Value_e
	  section.data(5).logicalSrcIdx = 116;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(14) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% vipldws_P.DrawPolygon_Value
	  section.data(1).logicalSrcIdx = 117;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_P.DrawLines_Value_j
	  section.data(2).logicalSrcIdx = 118;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vipldws_P._Y0
	  section.data(3).logicalSrcIdx = 119;
	  section.data(3).dtTransOffset = 2;
	
	  ;% vipldws_P.Constant_Value_b
	  section.data(4).logicalSrcIdx = 120;
	  section.data(4).dtTransOffset = 3;
	
	  ;% vipldws_P.Constant1_Value_d
	  section.data(5).logicalSrcIdx = 121;
	  section.data(5).dtTransOffset = 5;
	
	  ;% vipldws_P.Delay1_InitialCondition_n
	  section.data(6).logicalSrcIdx = 122;
	  section.data(6).dtTransOffset = 6;
	
	  ;% vipldws_P.Constant_Value_n
	  section.data(7).logicalSrcIdx = 123;
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
    nTotSects     = 17;
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
    ;% Auto data (vipldws_B)
    ;%
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% vipldws_B.ColorSpaceConversion
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_B.Clipimage
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 76800;
	
	  ;% vipldws_B.HoughTransform_o1
	  section.data(3).logicalSrcIdx = 5;
	  section.data(3).dtTransOffset = 124800;
	
	  ;% vipldws_B.DrawShapes
	  section.data(4).logicalSrcIdx = 47;
	  section.data(4).dtTransOffset = 237300;
	
	  ;% vipldws_B.InsertText
	  section.data(5).logicalSrcIdx = 48;
	  section.data(5).dtTransOffset = 467700;
	
	  ;% vipldws_B.InsertTextLeftLane
	  section.data(6).logicalSrcIdx = 49;
	  section.data(6).dtTransOffset = 698100;
	
	  ;% vipldws_B.ImageDataTypeConversion_n
	  section.data(7).logicalSrcIdx = 50;
	  section.data(7).dtTransOffset = 928500;
	
	  ;% vipldws_B.DrawShapes_f
	  section.data(8).logicalSrcIdx = 51;
	  section.data(8).dtTransOffset = 1158900;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% vipldws_B.HoughTransform_o2
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_B.HoughTransform_o3
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 180;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% vipldws_B.Init
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% vipldws_B.KTrans
	  section.data(1).logicalSrcIdx = 67;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% vipldws_B.Transpose_g
	  section.data(1).logicalSrcIdx = 93;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_B.HoughLines1
	  section.data(2).logicalSrcIdx = 94;
	  section.data(2).dtTransOffset = 4;
	
	  ;% vipldws_B.Transpose1
	  section.data(3).logicalSrcIdx = 95;
	  section.data(3).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% vipldws_B.Probe
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_B.Selector
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% vipldws_B.ImageDataTypeConversion
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_B.MatrixConcatenation3
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 230400;
	
	  ;% vipldws_B.UnitDelay2
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 230404;
	
	  ;% vipldws_B.UnitDelay3
	  section.data(4).logicalSrcIdx = 11;
	  section.data(4).dtTransOffset = 230484;
	
	  ;% vipldws_B.ColorSpaceConversion1
	  section.data(5).logicalSrcIdx = 12;
	  section.data(5).dtTransOffset = 230804;
	
	  ;% vipldws_B.Xnew
	  section.data(6).logicalSrcIdx = 14;
	  section.data(6).dtTransOffset = 317204;
	
	  ;% vipldws_B.InsertTextRightLane
	  section.data(7).logicalSrcIdx = 15;
	  section.data(7).dtTransOffset = 317244;
	
	  ;% vipldws_B.Assignment
	  section.data(8).logicalSrcIdx = 16;
	  section.data(8).dtTransOffset = 547644;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 29;
      section.data(29)  = dumData; %prealloc
      
	  ;% vipldws_B.MatrixConcatenation2
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_B.Selector1
	  section.data(2).logicalSrcIdx = 17;
	  section.data(2).dtTransOffset = 2;
	
	  ;% vipldws_B.Selector2
	  section.data(3).logicalSrcIdx = 18;
	  section.data(3).dtTransOffset = 4;
	
	  ;% vipldws_B.Assignment_i
	  section.data(4).logicalSrcIdx = 19;
	  section.data(4).dtTransOffset = 6;
	
	  ;% vipldws_B.Selector2_f
	  section.data(5).logicalSrcIdx = 20;
	  section.data(5).dtTransOffset = 46;
	
	  ;% vipldws_B.Selector1_k
	  section.data(6).logicalSrcIdx = 21;
	  section.data(6).dtTransOffset = 48;
	
	  ;% vipldws_B.Selector_i
	  section.data(7).logicalSrcIdx = 22;
	  section.data(7).dtTransOffset = 50;
	
	  ;% vipldws_B.Selector1_c
	  section.data(8).logicalSrcIdx = 23;
	  section.data(8).dtTransOffset = 52;
	
	  ;% vipldws_B.Selector2_n
	  section.data(9).logicalSrcIdx = 24;
	  section.data(9).dtTransOffset = 56;
	
	  ;% vipldws_B.Assignment_io
	  section.data(10).logicalSrcIdx = 25;
	  section.data(10).dtTransOffset = 72;
	
	  ;% vipldws_B.Assignment_o
	  section.data(11).logicalSrcIdx = 26;
	  section.data(11).dtTransOffset = 392;
	
	  ;% vipldws_B.Assignment_p
	  section.data(12).logicalSrcIdx = 27;
	  section.data(12).dtTransOffset = 472;
	
	  ;% vipldws_B.Assignment_a
	  section.data(13).logicalSrcIdx = 28;
	  section.data(13).dtTransOffset = 512;
	
	  ;% vipldws_B.AX
	  section.data(14).logicalSrcIdx = 29;
	  section.data(14).dtTransOffset = 552;
	
	  ;% vipldws_B.P_prd_Reshape
	  section.data(15).logicalSrcIdx = 30;
	  section.data(15).dtTransOffset = 556;
	
	  ;% vipldws_B.Z_est_Multiply
	  section.data(16).logicalSrcIdx = 31;
	  section.data(16).dtTransOffset = 572;
	
	  ;% vipldws_B.Z_prd_Multiply
	  section.data(17).logicalSrcIdx = 32;
	  section.data(17).dtTransOffset = 574;
	
	  ;% vipldws_B.uDFIRFilter
	  section.data(18).logicalSrcIdx = 33;
	  section.data(18).dtTransOffset = 576;
	
	  ;% vipldws_B.Saturation
	  section.data(19).logicalSrcIdx = 34;
	  section.data(19).dtTransOffset = 48576;
	
	  ;% vipldws_B.selectrho5
	  section.data(20).logicalSrcIdx = 35;
	  section.data(20).dtTransOffset = 96576;
	
	  ;% vipldws_B.Xold
	  section.data(21).logicalSrcIdx = 36;
	  section.data(21).dtTransOffset = 96807;
	
	  ;% vipldws_B.OverwriteValues
	  section.data(22).logicalSrcIdx = 37;
	  section.data(22).dtTransOffset = 96847;
	
	  ;% vipldws_B.OverwriteValues1
	  section.data(23).logicalSrcIdx = 38;
	  section.data(23).dtTransOffset = 209347;
	
	  ;% vipldws_B.Selectorrho
	  section.data(24).logicalSrcIdx = 39;
	  section.data(24).dtTransOffset = 321847;
	
	  ;% vipldws_B.Selectortheta
	  section.data(25).logicalSrcIdx = 40;
	  section.data(25).dtTransOffset = 321849;
	
	  ;% vipldws_B.selectrho5_f
	  section.data(26).logicalSrcIdx = 41;
	  section.data(26).dtTransOffset = 321851;
	
	  ;% vipldws_B.selectrho2
	  section.data(27).logicalSrcIdx = 42;
	  section.data(27).dtTransOffset = 321871;
	
	  ;% vipldws_B.selectrho5_m
	  section.data(28).logicalSrcIdx = 43;
	  section.data(28).dtTransOffset = 321891;
	
	  ;% vipldws_B.Selector_a
	  section.data(29).logicalSrcIdx = 44;
	  section.data(29).dtTransOffset = 322647;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
      section.nData     = 17;
      section.data(17)  = dumData; %prealloc
      
	  ;% vipldws_B.DataTypeConversion1
	  section.data(1).logicalSrcIdx = 45;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_B.Switch
	  section.data(2).logicalSrcIdx = 46;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vipldws_B.Selectorrho_c
	  section.data(3).logicalSrcIdx = 52;
	  section.data(3).dtTransOffset = 230401;
	
	  ;% vipldws_B.Selectortheta_i
	  section.data(4).logicalSrcIdx = 53;
	  section.data(4).dtTransOffset = 230402;
	
	  ;% vipldws_B.Selectorrho_o
	  section.data(5).logicalSrcIdx = 54;
	  section.data(5).dtTransOffset = 230403;
	
	  ;% vipldws_B.Selectortheta_g
	  section.data(6).logicalSrcIdx = 55;
	  section.data(6).dtTransOffset = 230404;
	
	  ;% vipldws_B.Switch1
	  section.data(7).logicalSrcIdx = 56;
	  section.data(7).dtTransOffset = 230405;
	
	  ;% vipldws_B.Selector2_b
	  section.data(8).logicalSrcIdx = 57;
	  section.data(8).dtTransOffset = 230407;
	
	  ;% vipldws_B.Rho_2
	  section.data(9).logicalSrcIdx = 58;
	  section.data(9).dtTransOffset = 230409;
	
	  ;% vipldws_B.Switch_m
	  section.data(10).logicalSrcIdx = 59;
	  section.data(10).dtTransOffset = 230410;
	
	  ;% vipldws_B.Switch_l
	  section.data(11).logicalSrcIdx = 60;
	  section.data(11).dtTransOffset = 230426;
	
	  ;% vipldws_B.HP_prdt
	  section.data(12).logicalSrcIdx = 61;
	  section.data(12).dtTransOffset = 230430;
	
	  ;% vipldws_B.LDLFactorization
	  section.data(13).logicalSrcIdx = 62;
	  section.data(13).dtTransOffset = 230438;
	
	  ;% vipldws_B.y
	  section.data(14).logicalSrcIdx = 63;
	  section.data(14).dtTransOffset = 230442;
	
	  ;% vipldws_B.d
	  section.data(15).logicalSrcIdx = 64;
	  section.data(15).dtTransOffset = 230450;
	
	  ;% vipldws_B.MatrixScaling
	  section.data(16).logicalSrcIdx = 65;
	  section.data(16).dtTransOffset = 230452;
	
	  ;% vipldws_B.BackwardSubstitution
	  section.data(17).logicalSrcIdx = 66;
	  section.data(17).dtTransOffset = 230460;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(9) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% vipldws_B.Init_p
	  section.data(1).logicalSrcIdx = 77;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_B.En_Delay
	  section.data(2).logicalSrcIdx = 78;
	  section.data(2).dtTransOffset = 20;
	
	  ;% vipldws_B.ConvertlinesfromPolartoCartesia
	  section.data(3).logicalSrcIdx = 79;
	  section.data(3).dtTransOffset = 40;
	
	  ;% vipldws_B.Transpose
	  section.data(4).logicalSrcIdx = 80;
	  section.data(4).dtTransOffset = 120;
	
	  ;% vipldws_B.Widthoftheimage
	  section.data(5).logicalSrcIdx = 81;
	  section.data(5).dtTransOffset = 200;
	
	  ;% vipldws_B.Switch1_b
	  section.data(6).logicalSrcIdx = 85;
	  section.data(6).dtTransOffset = 202;
	
	  ;% vipldws_B.MatrixConcatenation5
	  section.data(7).logicalSrcIdx = 86;
	  section.data(7).dtTransOffset = 206;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(10) = section;
      clear section
      
      section.nData     = 51;
      section.data(51)  = dumData; %prealloc
      
	  ;% vipldws_B.rho_1
	  section.data(1).logicalSrcIdx = 82;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_B.Distancethresholdfordeparturewa
	  section.data(2).logicalSrcIdx = 83;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vipldws_B.Counter
	  section.data(3).logicalSrcIdx = 84;
	  section.data(3).dtTransOffset = 2;
	
	  ;% vipldws_B.Selector_h
	  section.data(4).logicalSrcIdx = 87;
	  section.data(4).dtTransOffset = 3;
	
	  ;% vipldws_B.Bias3
	  section.data(5).logicalSrcIdx = 88;
	  section.data(5).dtTransOffset = 4;
	
	  ;% vipldws_B.Bias
	  section.data(6).logicalSrcIdx = 89;
	  section.data(6).dtTransOffset = 8;
	
	  ;% vipldws_B.Xnew_m
	  section.data(7).logicalSrcIdx = 90;
	  section.data(7).dtTransOffset = 16;
	
	  ;% vipldws_B.out3rdLane
	  section.data(8).logicalSrcIdx = 91;
	  section.data(8).dtTransOffset = 36;
	
	  ;% vipldws_B.HoughLines
	  section.data(9).logicalSrcIdx = 92;
	  section.data(9).dtTransOffset = 40;
	
	  ;% vipldws_B.ForIterator
	  section.data(10).logicalSrcIdx = 96;
	  section.data(10).dtTransOffset = 44;
	
	  ;% vipldws_B.ForIterator_a
	  section.data(11).logicalSrcIdx = 97;
	  section.data(11).dtTransOffset = 45;
	
	  ;% vipldws_B.Assignment1
	  section.data(12).logicalSrcIdx = 98;
	  section.data(12).dtTransOffset = 46;
	
	  ;% vipldws_B.Saturation_h
	  section.data(13).logicalSrcIdx = 99;
	  section.data(13).dtTransOffset = 66;
	
	  ;% vipldws_B.Selector1_b
	  section.data(14).logicalSrcIdx = 100;
	  section.data(14).dtTransOffset = 86;
	
	  ;% vipldws_B.ForIterator_l
	  section.data(15).logicalSrcIdx = 101;
	  section.data(15).dtTransOffset = 87;
	
	  ;% vipldws_B.Assignment1_m
	  section.data(16).logicalSrcIdx = 102;
	  section.data(16).dtTransOffset = 88;
	
	  ;% vipldws_B.Assignment2
	  section.data(17).logicalSrcIdx = 103;
	  section.data(17).dtTransOffset = 488;
	
	  ;% vipldws_B.Add_e
	  section.data(18).logicalSrcIdx = 104;
	  section.data(18).dtTransOffset = 888;
	
	  ;% vipldws_B.Assignment_k
	  section.data(19).logicalSrcIdx = 105;
	  section.data(19).dtTransOffset = 1288;
	
	  ;% vipldws_B.Assignment3
	  section.data(20).logicalSrcIdx = 106;
	  section.data(20).dtTransOffset = 1328;
	
	  ;% vipldws_B.ForIterator_j
	  section.data(21).logicalSrcIdx = 107;
	  section.data(21).dtTransOffset = 1348;
	
	  ;% vipldws_B.Selector1_n
	  section.data(22).logicalSrcIdx = 108;
	  section.data(22).dtTransOffset = 1349;
	
	  ;% vipldws_B.Selector1_i
	  section.data(23).logicalSrcIdx = 109;
	  section.data(23).dtTransOffset = 1350;
	
	  ;% vipldws_B.Assignment_p2
	  section.data(24).logicalSrcIdx = 110;
	  section.data(24).dtTransOffset = 1370;
	
	  ;% vipldws_B.ForIterator_f
	  section.data(25).logicalSrcIdx = 111;
	  section.data(25).dtTransOffset = 1770;
	
	  ;% vipldws_B.Assignment_j
	  section.data(26).logicalSrcIdx = 112;
	  section.data(26).dtTransOffset = 1771;
	
	  ;% vipldws_B.Add7
	  section.data(27).logicalSrcIdx = 113;
	  section.data(27).dtTransOffset = 1791;
	
	  ;% vipldws_B.Iterator
	  section.data(28).logicalSrcIdx = 114;
	  section.data(28).dtTransOffset = 1792;
	
	  ;% vipldws_B.En_Selector
	  section.data(29).logicalSrcIdx = 115;
	  section.data(29).dtTransOffset = 1793;
	
	  ;% vipldws_B.ForIterator_e
	  section.data(30).logicalSrcIdx = 116;
	  section.data(30).dtTransOffset = 1794;
	
	  ;% vipldws_B.ForIterator_fi
	  section.data(31).logicalSrcIdx = 117;
	  section.data(31).dtTransOffset = 1795;
	
	  ;% vipldws_B.Intersectionwithbottomimageboun
	  section.data(32).logicalSrcIdx = 118;
	  section.data(32).dtTransOffset = 1796;
	
	  ;% vipldws_B.Intersectionwithbottomimagebo_o
	  section.data(33).logicalSrcIdx = 119;
	  section.data(33).dtTransOffset = 1797;
	
	  ;% vipldws_B.Intersectionwithbottomimagebo_g
	  section.data(34).logicalSrcIdx = 120;
	  section.data(34).dtTransOffset = 1801;
	
	  ;% vipldws_B.Intersectionwithbottomimagebo_c
	  section.data(35).logicalSrcIdx = 121;
	  section.data(35).dtTransOffset = 1802;
	
	  ;% vipldws_B.Xold_g
	  section.data(36).logicalSrcIdx = 122;
	  section.data(36).dtTransOffset = 1806;
	
	  ;% vipldws_B.Bias1
	  section.data(37).logicalSrcIdx = 123;
	  section.data(37).dtTransOffset = 1826;
	
	  ;% vipldws_B.Selector1_il
	  section.data(38).logicalSrcIdx = 124;
	  section.data(38).dtTransOffset = 1906;
	
	  ;% vipldws_B.MultiportSelector_o1
	  section.data(39).logicalSrcIdx = 125;
	  section.data(39).dtTransOffset = 1986;
	
	  ;% vipldws_B.MultiportSelector_o2
	  section.data(40).logicalSrcIdx = 126;
	  section.data(40).dtTransOffset = 1988;
	
	  ;% vipldws_B.MultiportSelector_o3
	  section.data(41).logicalSrcIdx = 127;
	  section.data(41).dtTransOffset = 1990;
	
	  ;% vipldws_B.MultiportSelector_o4
	  section.data(42).logicalSrcIdx = 128;
	  section.data(42).dtTransOffset = 1992;
	
	  ;% vipldws_B.Selector2_m
	  section.data(43).logicalSrcIdx = 129;
	  section.data(43).dtTransOffset = 1994;
	
	  ;% vipldws_B.Transpose1_p
	  section.data(44).logicalSrcIdx = 130;
	  section.data(44).dtTransOffset = 2002;
	
	  ;% vipldws_B.MatrixConcatenation6
	  section.data(45).logicalSrcIdx = 131;
	  section.data(45).dtTransOffset = 2010;
	
	  ;% vipldws_B.Selector2_h
	  section.data(46).logicalSrcIdx = 132;
	  section.data(46).dtTransOffset = 2022;
	
	  ;% vipldws_B.Transpose1_b
	  section.data(47).logicalSrcIdx = 133;
	  section.data(47).dtTransOffset = 2034;
	
	  ;% vipldws_B.TmpSignalConversionAtDrawShapes
	  section.data(48).logicalSrcIdx = 134;
	  section.data(48).dtTransOffset = 2046;
	
	  ;% vipldws_B.Selector1_ce
	  section.data(49).logicalSrcIdx = 135;
	  section.data(49).dtTransOffset = 2050;
	
	  ;% vipldws_B.Selector2_l
	  section.data(50).logicalSrcIdx = 136;
	  section.data(50).dtTransOffset = 2054;
	
	  ;% vipldws_B.DataTypeConversion3
	  section.data(51).logicalSrcIdx = 138;
	  section.data(51).dtTransOffset = 2058;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(11) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% vipldws_B.Minimum_o1
	  section.data(1).logicalSrcIdx = 137;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_B.Switch1_l
	  section.data(2).logicalSrcIdx = 139;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vipldws_B.Rst_Selector
	  section.data(3).logicalSrcIdx = 140;
	  section.data(3).dtTransOffset = 2;
	
	  ;% vipldws_B.selectrho5_b
	  section.data(4).logicalSrcIdx = 141;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(12) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% vipldws_B.Minimum
	  section.data(1).logicalSrcIdx = 154;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_B.Switch3
	  section.data(2).logicalSrcIdx = 155;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vipldws_B.Minimum_o2
	  section.data(3).logicalSrcIdx = 156;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(13) = section;
      clear section
      
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% vipldws_B.FindLocalMaxima1_o1
	  section.data(1).logicalSrcIdx = 157;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_B.FindLocalMaxima1_o2
	  section.data(2).logicalSrcIdx = 158;
	  section.data(2).dtTransOffset = 2;
	
	  ;% vipldws_B.FindLocalMaxima1_o1_f
	  section.data(3).logicalSrcIdx = 159;
	  section.data(3).dtTransOffset = 3;
	
	  ;% vipldws_B.FindLocalMaxima1_o2_c
	  section.data(4).logicalSrcIdx = 160;
	  section.data(4).dtTransOffset = 5;
	
	  ;% vipldws_B.FindLocalMaxima
	  section.data(5).logicalSrcIdx = 161;
	  section.data(5).dtTransOffset = 6;
	
	  ;% vipldws_B.Selector1_m
	  section.data(6).logicalSrcIdx = 162;
	  section.data(6).dtTransOffset = 10;
	
	  ;% vipldws_B.Transpose_m
	  section.data(7).logicalSrcIdx = 163;
	  section.data(7).dtTransOffset = 14;
	
	  ;% vipldws_B.Selector2_mw
	  section.data(8).logicalSrcIdx = 164;
	  section.data(8).dtTransOffset = 18;
	
	  ;% vipldws_B.Transpose_b
	  section.data(9).logicalSrcIdx = 165;
	  section.data(9).dtTransOffset = 20;
	
	  ;% vipldws_B.Selector1_e
	  section.data(10).logicalSrcIdx = 166;
	  section.data(10).dtTransOffset = 22;
	
	  ;% vipldws_B.Transpose_gb
	  section.data(11).logicalSrcIdx = 167;
	  section.data(11).dtTransOffset = 24;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(14) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% vipldws_B.RawMessage
	  section.data(1).logicalSrcIdx = 171;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_B.Delay
	  section.data(2).logicalSrcIdx = 172;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vipldws_B.outMsg
	  section.data(3).logicalSrcIdx = 173;
	  section.data(3).dtTransOffset = 2;
	
	  ;% vipldws_B.colorAndTypeIdx
	  section.data(4).logicalSrcIdx = 174;
	  section.data(4).dtTransOffset = 3;
	
	  ;% vipldws_B.Switch_a
	  section.data(5).logicalSrcIdx = 175;
	  section.data(5).dtTransOffset = 5;
	
	  ;% vipldws_B.Switch1_j
	  section.data(6).logicalSrcIdx = 176;
	  section.data(6).dtTransOffset = 6;
	
	  ;% vipldws_B.Bias1_j
	  section.data(7).logicalSrcIdx = 177;
	  section.data(7).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(15) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% vipldws_B.MatrixConcatenate
	  section.data(1).logicalSrcIdx = 179;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_B.Switch_mz
	  section.data(2).logicalSrcIdx = 180;
	  section.data(2).dtTransOffset = 230400;
	
	  ;% vipldws_B.Selector_hy
	  section.data(3).logicalSrcIdx = 181;
	  section.data(3).dtTransOffset = 460800;
	
	  ;% vipldws_B.Selector1_p
	  section.data(4).logicalSrcIdx = 182;
	  section.data(4).dtTransOffset = 537600;
	
	  ;% vipldws_B.Selector2_c
	  section.data(5).logicalSrcIdx = 183;
	  section.data(5).dtTransOffset = 614400;
	
	  ;% vipldws_B.ImageDataTypeConversion1
	  section.data(6).logicalSrcIdx = 184;
	  section.data(6).dtTransOffset = 691200;
	
	  ;% vipldws_B.DrawShapes_l
	  section.data(7).logicalSrcIdx = 185;
	  section.data(7).dtTransOffset = 921600;
	
	  ;% vipldws_B.Switch2
	  section.data(8).logicalSrcIdx = 186;
	  section.data(8).dtTransOffset = 1152000;
	
	  ;% vipldws_B.ImageDataTypeConversion_f
	  section.data(9).logicalSrcIdx = 187;
	  section.data(9).dtTransOffset = 1382400;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(16) = section;
      clear section
      
      section.nData     = 23;
      section.data(23)  = dumData; %prealloc
      
	  ;% vipldws_B.Compare
	  section.data(1).logicalSrcIdx = 190;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_B.LogicalOperator4
	  section.data(2).logicalSrcIdx = 191;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vipldws_B.LogicalOperator2
	  section.data(3).logicalSrcIdx = 192;
	  section.data(3).dtTransOffset = 2;
	
	  ;% vipldws_B.LogicalOperator1
	  section.data(4).logicalSrcIdx = 193;
	  section.data(4).dtTransOffset = 3;
	
	  ;% vipldws_B.LogicalOperator
	  section.data(5).logicalSrcIdx = 194;
	  section.data(5).dtTransOffset = 4;
	
	  ;% vipldws_B.NSampleEnable
	  section.data(6).logicalSrcIdx = 195;
	  section.data(6).dtTransOffset = 5;
	
	  ;% vipldws_B.Compare_m
	  section.data(7).logicalSrcIdx = 196;
	  section.data(7).dtTransOffset = 6;
	
	  ;% vipldws_B.Assignment2_m
	  section.data(8).logicalSrcIdx = 197;
	  section.data(8).dtTransOffset = 26;
	
	  ;% vipldws_B.Selector2_fh
	  section.data(9).logicalSrcIdx = 198;
	  section.data(9).dtTransOffset = 46;
	
	  ;% vipldws_B.Rst_And
	  section.data(10).logicalSrcIdx = 199;
	  section.data(10).dtTransOffset = 47;
	
	  ;% vipldws_B.En_Or
	  section.data(11).logicalSrcIdx = 200;
	  section.data(11).dtTransOffset = 48;
	
	  ;% vipldws_B.Assignment_d
	  section.data(12).logicalSrcIdx = 201;
	  section.data(12).dtTransOffset = 49;
	
	  ;% vipldws_B.In
	  section.data(13).logicalSrcIdx = 202;
	  section.data(13).dtTransOffset = 51;
	
	  ;% vipldws_B.Imagethresholding
	  section.data(14).logicalSrcIdx = 203;
	  section.data(14).dtTransOffset = 52;
	
	  ;% vipldws_B.RelationalOperator1
	  section.data(15).logicalSrcIdx = 204;
	  section.data(15).dtTransOffset = 48052;
	
	  ;% vipldws_B.MultiportSelector1_o1
	  section.data(16).logicalSrcIdx = 205;
	  section.data(16).dtTransOffset = 48053;
	
	  ;% vipldws_B.MultiportSelector1_o2
	  section.data(17).logicalSrcIdx = 206;
	  section.data(17).dtTransOffset = 48054;
	
	  ;% vipldws_B.Selector_b
	  section.data(18).logicalSrcIdx = 207;
	  section.data(18).dtTransOffset = 48055;
	
	  ;% vipldws_B.Compare_p
	  section.data(19).logicalSrcIdx = 208;
	  section.data(19).dtTransOffset = 48056;
	
	  ;% vipldws_B.Compare_mb
	  section.data(20).logicalSrcIdx = 209;
	  section.data(20).dtTransOffset = 48076;
	
	  ;% vipldws_B.En_Not
	  section.data(21).logicalSrcIdx = 210;
	  section.data(21).dtTransOffset = 48077;
	
	  ;% vipldws_B.RelationalOperator2
	  section.data(22).logicalSrcIdx = 211;
	  section.data(22).dtTransOffset = 48078;
	
	  ;% vipldws_B.RelationalOperator3
	  section.data(23).logicalSrcIdx = 212;
	  section.data(23).dtTransOffset = 48079;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(17) = section;
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
    sectIdxOffset = 17;
    
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
    ;% Auto data (vipldws_DW)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% vipldws_DW.obj
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% vipldws_DW.MatrixConcatenation3_PWORK
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_DW.SafetyMarginSignals_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vipldws_DW.FromWorkspace_PWORK.TimePtr
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 2;
	
	  ;% vipldws_DW.MATLABSystem_PWORK
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% vipldws_DW.FixPtUnitDelay1_DSTATE
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_DW.UnitDelay2_DSTATE
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 40;
	
	  ;% vipldws_DW.UnitDelay3_DSTATE
	  section.data(3).logicalSrcIdx = 7;
	  section.data(3).dtTransOffset = 120;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% vipldws_DW.FixPtUnitDelay1_DSTATE_d
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_DW.En_Delay_DSTATE
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 20;
	
	  ;% vipldws_DW.Delay1_DSTATE
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 40;
	
	  ;% vipldws_DW.Min_left_dis_DSTATE
	  section.data(4).logicalSrcIdx = 11;
	  section.data(4).dtTransOffset = 440;
	
	  ;% vipldws_DW.Min_left_pts_DSTATE
	  section.data(5).logicalSrcIdx = 12;
	  section.data(5).dtTransOffset = 441;
	
	  ;% vipldws_DW.Min_right_dis_DSTATE
	  section.data(6).logicalSrcIdx = 13;
	  section.data(6).dtTransOffset = 445;
	
	  ;% vipldws_DW.Min_right_pts_DSTATE
	  section.data(7).logicalSrcIdx = 14;
	  section.data(7).dtTransOffset = 446;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 14;
      section.data(14)  = dumData; %prealloc
      
	  ;% vipldws_DW.ColorSpaceConversion_DWORK1
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_DW.Imagethresholding_P_DW
	  section.data(2).logicalSrcIdx = 16;
	  section.data(2).dtTransOffset = 230400;
	
	  ;% vipldws_DW.Imagethresholding_MU_DW
	  section.data(3).logicalSrcIdx = 17;
	  section.data(3).dtTransOffset = 230656;
	
	  ;% vipldws_DW.FindLocalMaxima1_TEMP_IN_DWORKS
	  section.data(4).logicalSrcIdx = 18;
	  section.data(4).dtTransOffset = 230912;
	
	  ;% vipldws_DW.FindLocalMaxima_TEMP_IN_DWORKS
	  section.data(5).logicalSrcIdx = 19;
	  section.data(5).dtTransOffset = 231143;
	
	  ;% vipldws_DW.FindLocalMaxima1_TEMP_IN_DWOR_e
	  section.data(6).logicalSrcIdx = 20;
	  section.data(6).dtTransOffset = 343643;
	
	  ;% vipldws_DW.ColorSpaceConversion1_DWORK1
	  section.data(7).logicalSrcIdx = 21;
	  section.data(7).dtTransOffset = 344399;
	
	  ;% vipldws_DW.InsertText_colorVectorDW
	  section.data(8).logicalSrcIdx = 22;
	  section.data(8).dtTransOffset = 430799;
	
	  ;% vipldws_DW.InsertTextLeftLane_colorVectorD
	  section.data(9).logicalSrcIdx = 23;
	  section.data(9).dtTransOffset = 430802;
	
	  ;% vipldws_DW.InsertTextRightLane_colorVector
	  section.data(10).logicalSrcIdx = 24;
	  section.data(10).dtTransOffset = 430805;
	
	  ;% vipldws_DW.DrawShapes_DW_FillColorAdd
	  section.data(11).logicalSrcIdx = 25;
	  section.data(11).dtTransOffset = 430808;
	
	  ;% vipldws_DW.DrawShapes_DW_OneMOpacity
	  section.data(12).logicalSrcIdx = 26;
	  section.data(12).dtTransOffset = 430811;
	
	  ;% vipldws_DW.Add1_DWORK1
	  section.data(13).logicalSrcIdx = 27;
	  section.data(13).dtTransOffset = 430812;
	
	  ;% vipldws_DW.LDLFactorization_VMX
	  section.data(14).logicalSrcIdx = 28;
	  section.data(14).dtTransOffset = 430813;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 28;
      section.data(28)  = dumData; %prealloc
      
	  ;% vipldws_DW.uDFIRFilter_bSEnd
	  section.data(1).logicalSrcIdx = 29;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_DW.uDFIRFilter_bSPreEdg
	  section.data(2).logicalSrcIdx = 30;
	  section.data(2).dtTransOffset = 2;
	
	  ;% vipldws_DW.uDFIRFilter_bSPstEdg
	  section.data(3).logicalSrcIdx = 31;
	  section.data(3).dtTransOffset = 4;
	
	  ;% vipldws_DW.uDFIRFilter_bSStart
	  section.data(4).logicalSrcIdx = 32;
	  section.data(4).dtTransOffset = 6;
	
	  ;% vipldws_DW.uDFIRFilter_inSEnd
	  section.data(5).logicalSrcIdx = 33;
	  section.data(5).dtTransOffset = 8;
	
	  ;% vipldws_DW.uDFIRFilter_inSStart
	  section.data(6).logicalSrcIdx = 34;
	  section.data(6).dtTransOffset = 10;
	
	  ;% vipldws_DW.uDFIRFilter_mLoc
	  section.data(7).logicalSrcIdx = 35;
	  section.data(7).dtTransOffset = 12;
	
	  ;% vipldws_DW.uDFIRFilter_mWidth
	  section.data(8).logicalSrcIdx = 36;
	  section.data(8).dtTransOffset = 22;
	
	  ;% vipldws_DW.uDFIRFilter_oSPreEdg
	  section.data(9).logicalSrcIdx = 37;
	  section.data(9).dtTransOffset = 32;
	
	  ;% vipldws_DW.uDFIRFilter_oSPstEdg
	  section.data(10).logicalSrcIdx = 38;
	  section.data(10).dtTransOffset = 34;
	
	  ;% vipldws_DW.uDFIRFilter_oSStart
	  section.data(11).logicalSrcIdx = 39;
	  section.data(11).dtTransOffset = 36;
	
	  ;% vipldws_DW.uDFIRFilter_oSecEnd
	  section.data(12).logicalSrcIdx = 40;
	  section.data(12).dtTransOffset = 38;
	
	  ;% vipldws_DW.uDFIRFilter_sCnt
	  section.data(13).logicalSrcIdx = 41;
	  section.data(13).dtTransOffset = 40;
	
	  ;% vipldws_DW.FindLocalMaxima_DIMS1
	  section.data(14).logicalSrcIdx = 42;
	  section.data(14).dtTransOffset = 42;
	
	  ;% vipldws_DW.Selector1_DIMS1
	  section.data(15).logicalSrcIdx = 43;
	  section.data(15).dtTransOffset = 44;
	
	  ;% vipldws_DW.Transpose_DIMS1
	  section.data(16).logicalSrcIdx = 44;
	  section.data(16).dtTransOffset = 46;
	
	  ;% vipldws_DW.selectrho_DIMS1
	  section.data(17).logicalSrcIdx = 45;
	  section.data(17).dtTransOffset = 48;
	
	  ;% vipldws_DW.Selectorrho_DIMS1
	  section.data(18).logicalSrcIdx = 46;
	  section.data(18).dtTransOffset = 50;
	
	  ;% vipldws_DW.selectrho3_DIMS1
	  section.data(19).logicalSrcIdx = 47;
	  section.data(19).dtTransOffset = 52;
	
	  ;% vipldws_DW.Selectortheta_DIMS1
	  section.data(20).logicalSrcIdx = 48;
	  section.data(20).dtTransOffset = 54;
	
	  ;% vipldws_DW.MatrixConcatenation3_DIMS1
	  section.data(21).logicalSrcIdx = 49;
	  section.data(21).dtTransOffset = 56;
	
	  ;% vipldws_DW.DrawShapes_DW_Polygon
	  section.data(22).logicalSrcIdx = 50;
	  section.data(22).dtTransOffset = 58;
	
	  ;% vipldws_DW.DrawShapes_DW_Points
	  section.data(23).logicalSrcIdx = 51;
	  section.data(23).dtTransOffset = 130;
	
	  ;% vipldws_DW.InsertText_TxtLoc
	  section.data(24).logicalSrcIdx = 52;
	  section.data(24).dtTransOffset = 146;
	
	  ;% vipldws_DW.InsertTextLeftLane_TxtLoc
	  section.data(25).logicalSrcIdx = 53;
	  section.data(25).dtTransOffset = 148;
	
	  ;% vipldws_DW.InsertTextRightLane_TxtLoc
	  section.data(26).logicalSrcIdx = 54;
	  section.data(26).dtTransOffset = 150;
	
	  ;% vipldws_DW.Selector2_DIMS1
	  section.data(27).logicalSrcIdx = 55;
	  section.data(27).dtTransOffset = 152;
	
	  ;% vipldws_DW.Selector1_DIMS1_l
	  section.data(28).logicalSrcIdx = 56;
	  section.data(28).dtTransOffset = 154;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% vipldws_DW.FindLocalMaxima_NUMPEAKS_DWORK
	  section.data(1).logicalSrcIdx = 57;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_DW.NSampleEnable_Counter
	  section.data(2).logicalSrcIdx = 58;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vipldws_DW.InsertText_TxtSelctn
	  section.data(3).logicalSrcIdx = 59;
	  section.data(3).dtTransOffset = 2;
	
	  ;% vipldws_DW.InsertTextLeftLane_TxtSelctn
	  section.data(4).logicalSrcIdx = 60;
	  section.data(4).dtTransOffset = 3;
	
	  ;% vipldws_DW.InsertTextRightLane_TxtSelctn
	  section.data(5).logicalSrcIdx = 61;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% vipldws_DW.FromWorkspace_IWORK.PrevIndex
	  section.data(1).logicalSrcIdx = 62;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% vipldws_DW.Counter_Count
	  section.data(1).logicalSrcIdx = 63;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% vipldws_DW.Delay_DSTATE
	  section.data(1).logicalSrcIdx = 64;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_DW.Delay1_DSTATE_e
	  section.data(2).logicalSrcIdx = 65;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% vipldws_DW.FixPtUnitDelay2_DSTATE
	  section.data(1).logicalSrcIdx = 66;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_DW.FixPtUnitDelay2_DSTATE_b
	  section.data(2).logicalSrcIdx = 67;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% vipldws_DW.Delay1_DSTATE_g
	  section.data(1).logicalSrcIdx = 68;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_DW.Minimum_Valdata
	  section.data(2).logicalSrcIdx = 69;
	  section.data(2).dtTransOffset = 20;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% vipldws_DW.Enablesignalgenerator_SubsysRan
	  section.data(1).logicalSrcIdx = 70;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_DW.SampleandHold_SubsysRanBC
	  section.data(2).logicalSrcIdx = 71;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vipldws_DW.Subsystem_SubsysRanBC
	  section.data(3).logicalSrcIdx = 72;
	  section.data(3).dtTransOffset = 2;
	
	  ;% vipldws_DW.Draw3rdLine_SubsysRanBC
	  section.data(4).logicalSrcIdx = 73;
	  section.data(4).dtTransOffset = 3;
	
	  ;% vipldws_DW.DrawPolygon_SubsysRanBC
	  section.data(5).logicalSrcIdx = 74;
	  section.data(5).dtTransOffset = 4;
	
	  ;% vipldws_DW.Selectalinefromtherepositoryifi
	  section.data(6).logicalSrcIdx = 75;
	  section.data(6).dtTransOffset = 5;
	
	  ;% vipldws_DW.Differencebetweentwolines_Subsy
	  section.data(7).logicalSrcIdx = 76;
	  section.data(7).dtTransOffset = 6;
	
	  ;% vipldws_DW.Options_SubsysRanBC
	  section.data(8).logicalSrcIdx = 77;
	  section.data(8).dtTransOffset = 7;
	
	  ;% vipldws_DW.Core_SubsysRanBC
	  section.data(9).logicalSrcIdx = 78;
	  section.data(9).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 13;
      section.data(13)  = dumData; %prealloc
      
	  ;% vipldws_DW.DrawShapes_DW_PixCount
	  section.data(1).logicalSrcIdx = 79;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_DW.InsertText_RepBuf
	  section.data(2).logicalSrcIdx = 80;
	  section.data(2).dtTransOffset = 320;
	
	  ;% vipldws_DW.InsertText_VarHolder
	  section.data(3).logicalSrcIdx = 81;
	  section.data(3).dtTransOffset = 321;
	
	  ;% vipldws_DW.InsertText_StringDataDW
	  section.data(4).logicalSrcIdx = 82;
	  section.data(4).dtTransOffset = 322;
	
	  ;% vipldws_DW.InsertTextLeftLane_RepBuf
	  section.data(5).logicalSrcIdx = 83;
	  section.data(5).dtTransOffset = 396;
	
	  ;% vipldws_DW.InsertTextLeftLane_VarHolder
	  section.data(6).logicalSrcIdx = 84;
	  section.data(6).dtTransOffset = 397;
	
	  ;% vipldws_DW.InsertTextLeftLane_StringDataDW
	  section.data(7).logicalSrcIdx = 85;
	  section.data(7).dtTransOffset = 398;
	
	  ;% vipldws_DW.InsertTextRightLane_RepBuf
	  section.data(8).logicalSrcIdx = 86;
	  section.data(8).dtTransOffset = 451;
	
	  ;% vipldws_DW.InsertTextRightLane_VarHolder
	  section.data(9).logicalSrcIdx = 87;
	  section.data(9).dtTransOffset = 452;
	
	  ;% vipldws_DW.InsertTextRightLane_StringDataD
	  section.data(10).logicalSrcIdx = 88;
	  section.data(10).dtTransOffset = 453;
	
	  ;% vipldws_DW.ForIterator_IterationMarker
	  section.data(11).logicalSrcIdx = 89;
	  section.data(11).dtTransOffset = 506;
	
	  ;% vipldws_DW.ForIterator_IterationMarker_c
	  section.data(12).logicalSrcIdx = 90;
	  section.data(12).dtTransOffset = 507;
	
	  ;% vipldws_DW.Iterator_IterationMarker
	  section.data(13).logicalSrcIdx = 91;
	  section.data(13).dtTransOffset = 508;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% vipldws_DW.uDFIRFilter_isHgtUpd
	  section.data(1).logicalSrcIdx = 92;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vipldws_DW.objisempty
	  section.data(2).logicalSrcIdx = 93;
	  section.data(2).dtTransOffset = 2;
	
	  ;% vipldws_DW.LDLFactorization_STATE
	  section.data(3).logicalSrcIdx = 94;
	  section.data(3).dtTransOffset = 3;
	
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


  targMap.checksum0 = 3292013895;
  targMap.checksum1 = 1028096924;
  targMap.checksum2 = 2331457176;
  targMap.checksum3 = 2336779331;

