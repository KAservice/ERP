object DMQueryUpdate: TDMQueryUpdate
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 150
  Width = 215
  object pFIBQ: TpFIBQuery
    Transaction = pFIBTr
    Left = 40
    Top = 40
    qoStartTransaction = True
  end
  object pFIBTr: TpFIBTransaction
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
