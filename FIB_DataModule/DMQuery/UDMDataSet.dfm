object DMDataSet: TDMDataSet
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 250
  Width = 395
  object Transaction: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 256
    Top = 136
  end
  object DataSet: TpFIBDataSet
    CachedUpdates = True
    Left = 176
    Top = 136
    poUseLargeIntField = True
  end
  object DataSource: TDataSource
    DataSet = DataSet
    Left = 88
    Top = 136
  end
end
