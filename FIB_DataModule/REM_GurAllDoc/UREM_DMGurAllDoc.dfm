object REM_DMGurAllDoc: TREM_DMGurAllDoc
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 280
  Width = 292
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 16
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select '
      'REM_GALLDOC.*, NAMEFIRM, NAMESKLAD, NAMEKLIENT, NAME_USER,'
      '    sinfbase_obmen.name_sinfbase_obmen,'
      '    rem_gur_prov.id_rem_gur_prov,'
      '    rem_gur_prov.res_rem_gur_prov,'
      '    rem_gur_vigrt.iddoc_rem_gur_vigrt'
      'from '
      'REM_GALLDOC '
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_REM_G' +
        'ALLDOC'
      'LEFT OUTER JOIN SFIRM ON IDFIRM_REM_GALLDOC = IDFIRM'
      'left outer join SSKLAD on IDSKLAD_REM_GALLDOC = IDSKLAD'
      'left outer join SKLIENT on IDKLIENT_REM_GALLDOC =IDKLIENT'
      'left outer join SUSER on  IDUSER_REM_GALLDOC = ID_USER'
      
        'left outer join rem_gur_prov on REM_GALLDOC.id_rem_galldoc= rem_' +
        'gur_prov.iddoc_rem_gur_prov'
      
        'left outer join rem_gur_vigrt on REM_GALLDOC.id_rem_galldoc= rem' +
        '_gur_vigrt.iddocvigr_rem_gur_vigrt'
      'where POS_REM_GALLDOC between  :PARAM_POSNACH and :PARAM_POSCON'
      'order by POS_REM_GALLDOC')
    Transaction = IBTr
    Left = 144
    Top = 16
    poUseLargeIntField = True
    object TableID_REM_GALLDOC: TFIBLargeIntField
      FieldName = 'ID_REM_GALLDOC'
    end
    object TableIDBASE_REM_GALLDOC: TFIBLargeIntField
      FieldName = 'IDBASE_REM_GALLDOC'
    end
    object TableIDFIRM_REM_GALLDOC: TFIBLargeIntField
      FieldName = 'IDFIRM_REM_GALLDOC'
    end
    object TableIDSKLAD_REM_GALLDOC: TFIBLargeIntField
      FieldName = 'IDSKLAD_REM_GALLDOC'
    end
    object TableIDKLIENT_REM_GALLDOC: TFIBLargeIntField
      FieldName = 'IDKLIENT_REM_GALLDOC'
    end
    object TableIDUSER_REM_GALLDOC: TFIBLargeIntField
      FieldName = 'IDUSER_REM_GALLDOC'
    end
    object TablePOS_REM_GALLDOC: TFIBDateTimeField
      FieldName = 'POS_REM_GALLDOC'
      DisplayFormat = 'c'
    end
    object TableNUM_REM_GALLDOC: TFIBIntegerField
      FieldName = 'NUM_REM_GALLDOC'
    end
    object TablePR_REM_GALLDOC: TFIBSmallIntField
      FieldName = 'PR_REM_GALLDOC'
    end
    object TableTDOC_REM_GALLDOC: TFIBWideStringField
      FieldName = 'TDOC_REM_GALLDOC'
      OnGetText = TableTDOC_REM_GALLDOCGetText
      Size = 15
    end
    object TableIDDOCOSN_REM_GALLDOC: TFIBLargeIntField
      FieldName = 'IDDOCOSN_REM_GALLDOC'
    end
    object TableTYPEEXTDOC_REM_GALLDOC: TFIBIntegerField
      FieldName = 'TYPEEXTDOC_REM_GALLDOC'
    end
    object TableIDEXTDOC_REM_GALLDOC: TFIBLargeIntField
      FieldName = 'IDEXTDOC_REM_GALLDOC'
    end
    object TableSUM_REM_GALLDOC: TFIBBCDField
      FieldName = 'SUM_REM_GALLDOC'
      Size = 2
      RoundByScale = True
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
    object TablePREFIKS_NUM_REM_GALLDOC: TFIBWideStringField
      FieldName = 'PREFIKS_NUM_REM_GALLDOC'
      Size = 12
    end
    object TableNAME_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 200
    end
    object TableIDPROJECT_REM_GALLDOC: TFIBLargeIntField
      FieldName = 'IDPROJECT_REM_GALLDOC'
    end
    object TableIDBUSINOP_REM_GALLDOC: TFIBLargeIntField
      FieldName = 'IDBUSINOP_REM_GALLDOC'
    end
    object TableID_REM_GUR_PROV: TFIBLargeIntField
      FieldName = 'ID_REM_GUR_PROV'
    end
    object TableRES_REM_GUR_PROV: TFIBIntegerField
      FieldName = 'RES_REM_GUR_PROV'
    end
    object TableIDDOC_REM_GUR_VIGRT: TFIBLargeIntField
      FieldName = 'IDDOC_REM_GUR_VIGRT'
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
  object IBQ: TpFIBDataSet
    Transaction = IBTr
    Left = 144
    Top = 128
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 224
    Top = 104
    qoStartTransaction = True
  end
end
