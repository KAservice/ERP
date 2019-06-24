object DMGurLog: TDMGurLog
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
    UpdateSQL.Strings = (
      ''
      '    ')
    RefreshSQL.Strings = (
      'select '
      'LOG.*, NAME_USER'
      'from LOG'
      'left outer join SUSER on  IDUSER_LOG= ID_USER'
      'where(  POS_LOG between  :PARAM_DATE_NACH and :PARAM_DATE_CON'
      '     ) and (     LOG.ID_LOG = :OLD_ID_LOG'
      '     )'
      '     '
      '')
    SelectSQL.Strings = (
      'select '
      'LOG.*, NAME_USER'
      'from LOG'
      'left outer join SUSER on  IDUSER_LOG= ID_USER'
      'where POS_LOG between  :PARAM_DATE_NACH and :PARAM_DATE_CON '
      ''
      'order by POS_LOG')
    Transaction = IBTr
    Left = 144
    Top = 16
    object TablePOS_LOG: TFIBDateTimeField
      FieldName = 'POS_LOG'
    end
    object TableTYPE_LOG: TFIBIntegerField
      FieldName = 'TYPE_LOG'
    end
    object TableOPER_LOG: TFIBIntegerField
      FieldName = 'OPER_LOG'
    end
    object TableID_LOG: TFIBBCDField
      FieldName = 'ID_LOG'
      Size = 0
      RoundByScale = True
    end
    object TableIDUSER_LOG: TFIBBCDField
      FieldName = 'IDUSER_LOG'
      Size = 0
      RoundByScale = True
    end
    object TableMESSAGE_LOG: TFIBWideStringField
      FieldName = 'MESSAGE_LOG'
      Size = 100
    end
    object TableOBJECT_LOG: TFIBIntegerField
      FieldName = 'OBJECT_LOG'
    end
    object TableNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
      Size = 100
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
    Left = 144
    Top = 88
    qoStartTransaction = True
  end
  object IBTrUpdate: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 224
    Top = 88
  end
end
