  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 0;
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
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtP)
    ;%
    
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
    nTotSects     = 5;
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
    ;% Auto data (rtB)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.HoughTransform_o1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtB.MatrixConcatenate
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.DrawShapes
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 57600;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtB.HoughTransform_o2
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.HoughTransform_o3
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 180;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.EdgeDetection
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.HoughLines
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
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
    nTotSects     = 3;
    sectIdxOffset = 5;
    
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
    ;% Auto data (rtDW)
    ;%
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% rtDW.FrameRateDisplay_PrevTime
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.FrameRateDisplay_TotalTime
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.FrameRateDisplay_Count
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.FindLocalMaxima_TEMP_IN_DWORKS
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 28;
      section.data(28)  = dumData; %prealloc
      
	  ;% rtDW.Erosion_NUMNONZ_DW
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.Erosion_STREL_DW
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 2;
	
	  ;% rtDW.Erosion_ERODE_OFF_DW
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 4;
	
	  ;% rtDW.EdgeDetection_VO_DW
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 12;
	
	  ;% rtDW.EdgeDetection_HO_DW
	  section.data(5).logicalSrcIdx = 8;
	  section.data(5).dtTransOffset = 18;
	
	  ;% rtDW.EdgeDetection_VOU_DW
	  section.data(6).logicalSrcIdx = 9;
	  section.data(6).dtTransOffset = 24;
	
	  ;% rtDW.EdgeDetection_VOD_DW
	  section.data(7).logicalSrcIdx = 10;
	  section.data(7).dtTransOffset = 30;
	
	  ;% rtDW.EdgeDetection_VOL_DW
	  section.data(8).logicalSrcIdx = 11;
	  section.data(8).dtTransOffset = 36;
	
	  ;% rtDW.EdgeDetection_VOR_DW
	  section.data(9).logicalSrcIdx = 12;
	  section.data(9).dtTransOffset = 42;
	
	  ;% rtDW.EdgeDetection_HOU_DW
	  section.data(10).logicalSrcIdx = 13;
	  section.data(10).dtTransOffset = 48;
	
	  ;% rtDW.EdgeDetection_HOD_DW
	  section.data(11).logicalSrcIdx = 14;
	  section.data(11).dtTransOffset = 54;
	
	  ;% rtDW.EdgeDetection_HOL_DW
	  section.data(12).logicalSrcIdx = 15;
	  section.data(12).dtTransOffset = 60;
	
	  ;% rtDW.EdgeDetection_HOR_DW
	  section.data(13).logicalSrcIdx = 16;
	  section.data(13).dtTransOffset = 66;
	
	  ;% rtDW.EdgeDetection_VOUL_DW
	  section.data(14).logicalSrcIdx = 17;
	  section.data(14).dtTransOffset = 72;
	
	  ;% rtDW.EdgeDetection_VOLL_DW
	  section.data(15).logicalSrcIdx = 18;
	  section.data(15).dtTransOffset = 78;
	
	  ;% rtDW.EdgeDetection_VOUR_DW
	  section.data(16).logicalSrcIdx = 19;
	  section.data(16).dtTransOffset = 84;
	
	  ;% rtDW.EdgeDetection_VOLR_DW
	  section.data(17).logicalSrcIdx = 20;
	  section.data(17).dtTransOffset = 90;
	
	  ;% rtDW.EdgeDetection_HOUL_DW
	  section.data(18).logicalSrcIdx = 21;
	  section.data(18).dtTransOffset = 96;
	
	  ;% rtDW.EdgeDetection_HOLL_DW
	  section.data(19).logicalSrcIdx = 22;
	  section.data(19).dtTransOffset = 102;
	
	  ;% rtDW.EdgeDetection_HOUR_DW
	  section.data(20).logicalSrcIdx = 23;
	  section.data(20).dtTransOffset = 108;
	
	  ;% rtDW.EdgeDetection_HOLR_DW
	  section.data(21).logicalSrcIdx = 24;
	  section.data(21).dtTransOffset = 114;
	
	  ;% rtDW.FindLocalMaxima_DIMS1
	  section.data(22).logicalSrcIdx = 25;
	  section.data(22).dtTransOffset = 120;
	
	  ;% rtDW.Selector_DIMS1
	  section.data(23).logicalSrcIdx = 26;
	  section.data(23).dtTransOffset = 122;
	
	  ;% rtDW.Selector1_DIMS1
	  section.data(24).logicalSrcIdx = 27;
	  section.data(24).dtTransOffset = 124;
	
	  ;% rtDW.Selector2_DIMS1
	  section.data(25).logicalSrcIdx = 28;
	  section.data(25).dtTransOffset = 126;
	
	  ;% rtDW.Selector5_DIMS1
	  section.data(26).logicalSrcIdx = 29;
	  section.data(26).dtTransOffset = 128;
	
	  ;% rtDW.HoughLines_DIMS1
	  section.data(27).logicalSrcIdx = 30;
	  section.data(27).dtTransOffset = 130;
	
	  ;% rtDW.EdgeDetection_MEAN_FACTOR_DW
	  section.data(28).logicalSrcIdx = 32;
	  section.data(28).dtTransOffset = 132;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.ColorSpaceConversion_DWORK1
	  section.data(1).logicalSrcIdx = 33;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
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


  targMap.checksum0 = 1917102677;
  targMap.checksum1 = 1693815341;
  targMap.checksum2 = 2059061006;
  targMap.checksum3 = 728033140;

