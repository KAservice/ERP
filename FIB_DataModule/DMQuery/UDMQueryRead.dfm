object DMQueryRead: TDMQueryRead
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 208
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
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 120
    Top = 40
  end
  object Query: TpFIBQuery
    Left = 48
    Top = 128
    qoStartTransaction = True
  end
  object Transaction: TpFIBTransaction
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
