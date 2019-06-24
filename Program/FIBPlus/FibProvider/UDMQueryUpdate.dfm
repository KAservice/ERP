object DMQueryUpdate: TDMQueryUpdate
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 150
  Width = 215
  object Query: TpFIBQuery
    Transaction = Transaction
    Database = DMConnection.Database
    Left = 32
    Top = 56
  end
  object Transaction: TpFIBTransaction
    DefaultDatabase = DMConnection.Database
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 120
    Top = 56
  end
end
