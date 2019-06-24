object DMQueryUpdate: TDMQueryUpdate
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 150
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
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 120
    Top = 40
  end
end
