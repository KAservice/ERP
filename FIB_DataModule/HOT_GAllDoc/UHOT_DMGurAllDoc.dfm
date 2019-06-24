object HOT_DMGurAllDoc: THOT_DMGurAllDoc
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 218
  Width = 292
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 16
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select '
      'HOT_GALLDOC.*, NAMEFIRM, NAMEKLIENT, NAME_USER'
      'from '
      'HOT_GALLDOC '
      'LEFT OUTER JOIN SFIRM ON IDFIRM_HOT_GALLDOC=IDFIRM'
      'left outer join SKLIENT on IDKL_HOT_GALLDOC=IDKLIENT'
      'left outer join SUSER on  IDUSER_HOT_GALLDOC= ID_USER'
      
        'where POS_HOT_GALLDOC between  :PARAM_DATE_NACH and :PARAM_DATE_' +
        'CON'
      'order by POS_HOT_GALLDOC')
    Transaction = IBTr
    Left = 144
    Top = 16
    object TablePOS_HOT_GALLDOC: TFIBDateTimeField
      FieldName = 'POS_HOT_GALLDOC'
      DisplayFormat = 'c'
    end
    object TablePR_HOT_GALLDOC: TFIBSmallIntField
      FieldName = 'PR_HOT_GALLDOC'
    end
    object TableSUM_HOT_GALLDOC: TFIBBCDField
      FieldName = 'SUM_HOT_GALLDOC'
      Size = 2
      RoundByScale = True
    end
    object TableID_HOT_GALLDOC: TFIBBCDField
      FieldName = 'ID_HOT_GALLDOC'
      Size = 0
      RoundByScale = True
    end
    object TableIDFIRM_HOT_GALLDOC: TFIBBCDField
      FieldName = 'IDFIRM_HOT_GALLDOC'
      Size = 0
      RoundByScale = True
    end
    object TableIDKL_HOT_GALLDOC: TFIBBCDField
      FieldName = 'IDKL_HOT_GALLDOC'
      Size = 0
      RoundByScale = True
    end
    object TableIDUSER_HOT_GALLDOC: TFIBBCDField
      FieldName = 'IDUSER_HOT_GALLDOC'
      Size = 0
      RoundByScale = True
    end
    object TableIDDOCOSN_HOT_GALLDOC: TFIBBCDField
      FieldName = 'IDDOCOSN_HOT_GALLDOC'
      Size = 0
      RoundByScale = True
    end
    object TableIDBASE_HOT_GALLDOC: TFIBBCDField
      FieldName = 'IDBASE_HOT_GALLDOC'
      Size = 0
      RoundByScale = True
    end
    object TableTDOC_HOT_GALLDOC: TFIBWideStringField
      FieldName = 'TDOC_HOT_GALLDOC'
      OnGetText = TableTDOC_HOT_GALLDOCGetText
      Size = 10
    end
    object TableNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 100
    end
    object TableNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 100
    end
    object TableNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
      Size = 100
    end
    object TableNUMBER_HOT_GALLDOC: TFIBIntegerField
      FieldName = 'NUMBER_HOT_GALLDOC'
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
  object IBQ: TpFIBDataSet
    Transaction = IBTr
    Left = 144
    Top = 128
  end
end
