object DMQueryRead: TDMQueryRead
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 208
  Width = 215
  object pFIBQ: TpFIBQuery
    Transaction = pFIBTr
    Database = DM.pFIBData
    Left = 40
    Top = 40
    qoStartTransaction = True
  end
  object pFIBTr: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 120
    Top = 40
  end
  object Query: TpFIBQuery
    Transaction = DM.pFIBTr
    Database = DM.pFIBData
    Left = 48
    Top = 128
    qoStartTransaction = True
  end
  object Transaction: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 120
    Top = 128
  end
end
