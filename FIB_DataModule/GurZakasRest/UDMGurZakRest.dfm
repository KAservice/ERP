object DMGurZakRest: TDMGurZakRest
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Left = 744
  Top = 156
  Height = 173
  Width = 261
  object Table: TIBQuery
    Database = DM.IBData
    Transaction = IBTr
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      'select '
      '  RGZAK.*,'
      '  NAMEKLIENT, '
      '  NAME_USER,'
      '  NAME_STROB,'
      '  ID_STROB'
      'from '
      '  RGZAK'
      'left outer join SKLIENT on IDKLIENT_ZAK=IDKLIENT'
      'left outer join SUSER on  IDUSER_ZAK= ID_USER'
      'left outer join SSTROB on IDOB_ZAK=ID_STROB'
      ''
      'where IDUSER_ZAK=:PARAM_IDUSER')
    Left = 136
    Top = 16
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'PARAM_IDUSER'
        ParamType = ptUnknown
      end>
    object TableID_ZAK: TIntegerField
      FieldName = 'ID_ZAK'
      Origin = 'RGZAK.ID_ZAK'
      Required = True
    end
    object TableIDOB_ZAK: TIntegerField
      FieldName = 'IDOB_ZAK'
      Origin = 'RGZAK.IDOB_ZAK'
    end
    object TableSUM_ZAK: TIBBCDField
      FieldName = 'SUM_ZAK'
      Origin = 'RGZAK.SUM_ZAK'
      Precision = 18
      Size = 2
    end
    object TableSOST_ZAK: TSmallintField
      FieldName = 'SOST_ZAK'
      Origin = 'RGZAK.SOST_ZAK'
    end
    object TableIDKLIENT_ZAK: TIntegerField
      FieldName = 'IDKLIENT_ZAK'
      Origin = 'RGZAK.IDKLIENT_ZAK'
    end
    object TableIDUSER_ZAK: TIntegerField
      FieldName = 'IDUSER_ZAK'
      Origin = 'RGZAK.IDUSER_ZAK'
    end
    object TableNAMEKLIENT: TIBStringField
      FieldName = 'NAMEKLIENT'
      Origin = 'SKLIENT.NAMEKLIENT'
      Size = 50
    end
    object TableNAME_USER: TIBStringField
      FieldName = 'NAME_USER'
      Origin = 'SUSER.NAME_USER'
    end
    object TableNAME_STROB: TIBStringField
      FieldName = 'NAME_STROB'
      Origin = 'SSTROB.NAME_STROB'
      Size = 50
    end
    object TableID_STROB: TIntegerField
      FieldName = 'ID_STROB'
      Origin = 'SSTROB.ID_STROB'
    end
  end
  object IBTr: TIBTransaction
    Active = False
    DefaultDatabase = DM.IBData
    DefaultAction = TARollback
    Params.Strings = (
      'read_committed'
      'rec_version'
      'nowait')
    AutoStopAction = saNone
    Left = 200
    Top = 16
  end
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 16
  end
end
