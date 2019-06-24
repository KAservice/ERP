object REM_DMGurZAktPr: TREM_DMGurZAktPr
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 396
  Width = 696
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 16
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select'
      '    rem_dzaktpr.iddoc_rem_dzaktpr,'
      '    rem_galldoc.pr_rem_galldoc,'
      '    REM_GALLDOC.pos_rem_galldoc,'
      '    rem_galldoc.prefiks_num_rem_galldoc,'
      '    rem_galldoc.num_rem_galldoc,'
      '    rem_galldoc.sum_rem_galldoc,'
      '    rem_z.pos_rem_z,'
      '    rem_z.prefiks_num_rem_z,'
      '    rem_z.num_rem_z,'
      '    rem_sprmodel.name_rem_sprmodel,'
      '    rem_z.num_gardoc_rem_z,'
      '    rem_dzaktpr.numgartalon_rem_dzaktpr,'
      '    rem_z.sernum_rem_z,'
      '    rem_z.sernum2_rem_z,'
      '    NAMEFIRM,'
      '    NAMESKLAD,'
      '    NAMEKLIENT,'
      '    NAME_USER,'
      '    sinfbase_obmen.name_sinfbase_obmen,'
      '    rem_dzaktpr.klient_name_rem_dzaktpr,'
      '    rem_dzaktpr.klient_adr_rem_dzaktpr,'
      '    rem_dzaktpr.klient_phone_rem_dzaktpr,'
      '    rem_dzaktpr.fl_fictiv_rem_dzaktpr,'
      '    rem_z.fl_povtor_rem_z,'
      '    rem_z.fl_addreport_rem_z,'
      '    rem_z.fl_fictiv_rem_z,'
      '    rem_z.fl_ne_otch_rem_z,'
      '    rem_z.fl_nado_otch_rem_z,'
      '    rem_dzaktpr.fl_ne_otch_rem_dzaktpr,'
      '    rem_dzaktpr.fl_nado_otch_rem_dzaktpr,'
      '    rem_dzaktpr.pospriema_rem_dzaktpr'
      'from rem_dzaktpr'
      
        'left outer join rem_galldoc on rem_dzaktpr.iddoc_rem_dzaktpr=rem' +
        '_galldoc.id_rem_galldoc'
      
        'left outer join rem_z on rem_dzaktpr.idz_rem_dzaktpr=rem_z.id_re' +
        'm_z'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_REM_G' +
        'ALLDOC'
      'LEFT OUTER JOIN SFIRM ON IDFIRM_REM_GALLDOC = IDFIRM'
      'left outer join SSKLAD on IDSKLAD_REM_GALLDOC = IDSKLAD'
      'left outer join SKLIENT on IDKLIENT_REM_GALLDOC =IDKLIENT'
      'left outer join SUSER on  IDUSER_REM_GALLDOC = ID_USER'
      
        'left outer join rem_sprmodel on rem_dzaktpr.idprmodel_rem_dzaktp' +
        'r=rem_sprmodel.id_rem_sprmodel'
      
        'where rem_galldoc.pos_rem_galldoc between  :PARAM_POSNACH and :P' +
        'ARAM_POSCON'
      'order by rem_galldoc.pos_rem_galldoc'
      '')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 144
    Top = 16
    poUseLargeIntField = True
    object TablePOS_REM_GALLDOC: TFIBDateTimeField
      FieldName = 'POS_REM_GALLDOC'
      DisplayFormat = 'c'
    end
    object TableNUM_REM_GALLDOC: TFIBIntegerField
      FieldName = 'NUM_REM_GALLDOC'
    end
    object TablePOS_REM_Z: TFIBDateTimeField
      FieldName = 'POS_REM_Z'
      DisplayFormat = 'c'
    end
    object TablePREFIKS_NUM_REM_Z: TFIBWideStringField
      FieldName = 'PREFIKS_NUM_REM_Z'
      Size = 12
    end
    object TableNUM_REM_Z: TFIBIntegerField
      FieldName = 'NUM_REM_Z'
    end
    object TableNUM_GARDOC_REM_Z: TFIBWideStringField
      FieldName = 'NUM_GARDOC_REM_Z'
      Size = 50
    end
    object TableSERNUM_REM_Z: TFIBWideStringField
      FieldName = 'SERNUM_REM_Z'
      Size = 50
    end
    object TableSERNUM2_REM_Z: TFIBWideStringField
      FieldName = 'SERNUM2_REM_Z'
      Size = 50
    end
    object TableNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 200
    end
    object TableNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 200
    end
    object TableNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 200
    end
    object TableNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
      Size = 200
    end
    object TableNAME_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 200
    end
    object TableKLIENT_NAME_REM_DZAKTPR: TFIBWideStringField
      FieldName = 'KLIENT_NAME_REM_DZAKTPR'
      Size = 200
    end
    object TableKLIENT_ADR_REM_DZAKTPR: TFIBWideStringField
      FieldName = 'KLIENT_ADR_REM_DZAKTPR'
      Size = 200
    end
    object TableKLIENT_PHONE_REM_DZAKTPR: TFIBWideStringField
      FieldName = 'KLIENT_PHONE_REM_DZAKTPR'
      Size = 200
    end
    object TableIDDOC_REM_DZAKTPR: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DZAKTPR'
    end
    object TableFL_FICTIV_REM_DZAKTPR: TFIBIntegerField
      FieldName = 'FL_FICTIV_REM_DZAKTPR'
    end
    object TablePR_REM_GALLDOC: TFIBSmallIntField
      FieldName = 'PR_REM_GALLDOC'
    end
    object TablePREFIKS_NUM_REM_GALLDOC: TFIBWideStringField
      FieldName = 'PREFIKS_NUM_REM_GALLDOC'
      Size = 12
    end
    object TableSUM_REM_GALLDOC: TFIBBCDField
      FieldName = 'SUM_REM_GALLDOC'
      Size = 2
      RoundByScale = True
    end
    object TableNAME_REM_SPRMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SPRMODEL'
      Size = 200
    end
    object TableNUMGARTALON_REM_DZAKTPR: TFIBWideStringField
      FieldName = 'NUMGARTALON_REM_DZAKTPR'
      Size = 50
    end
    object TableFL_POVTOR_REM_Z: TFIBSmallIntField
      FieldName = 'FL_POVTOR_REM_Z'
    end
    object TableFL_ADDREPORT_REM_Z: TFIBSmallIntField
      FieldName = 'FL_ADDREPORT_REM_Z'
    end
    object TableFL_FICTIV_REM_Z: TFIBIntegerField
      FieldName = 'FL_FICTIV_REM_Z'
    end
    object TableFL_NE_OTCH_REM_Z: TFIBSmallIntField
      FieldName = 'FL_NE_OTCH_REM_Z'
    end
    object TableFL_NADO_OTCH_REM_Z: TFIBSmallIntField
      FieldName = 'FL_NADO_OTCH_REM_Z'
    end
    object TableFL_NE_OTCH_REM_DZAKTPR: TFIBSmallIntField
      FieldName = 'FL_NE_OTCH_REM_DZAKTPR'
    end
    object TableFL_NADO_OTCH_REM_DZAKTPR: TFIBSmallIntField
      FieldName = 'FL_NADO_OTCH_REM_DZAKTPR'
    end
    object TableSROK_REMONTA: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'SROK_REMONTA'
      Calculated = True
    end
    object TableSROK_REMONTA_NOW: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'SROK_REMONTA_NOW'
      Calculated = True
    end
    object TableSROK_REMONTA_IS_DOC: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'SROK_REMONTA_IS_DOC'
      Calculated = True
    end
    object TablePOSPRIEMA_REM_DZAKTPR: TFIBDateTimeField
      FieldName = 'POSPRIEMA_REM_DZAKTPR'
      DisplayFormat = 'c'
    end
  end
  object IBTr: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 232
    Top = 16
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 224
    Top = 104
    qoStartTransaction = True
  end
end
