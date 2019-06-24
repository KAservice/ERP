object DMQueryRead: TDMQueryRead
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 150
  Width = 215
  object Query: TpFIBQuery
    Transaction = Transaction
    Database = DMConnection.Database
    Left = 32
    Top = 48
    qoStartTransaction = True
  end
  object Transaction: TpFIBTransaction
    DefaultDatabase = DMConnection.Database
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 112
    Top = 48
  end
end
