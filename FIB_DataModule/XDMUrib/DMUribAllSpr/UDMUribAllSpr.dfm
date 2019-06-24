object DMUribAllSpr: TDMUribAllSpr
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 174
  Width = 197
  object IBQ33: TIBQuery
    Transaction = IBTr1
    Left = 16
    Top = 8
  end
  object IBTr1: TIBTransaction
    Params.Strings = (
      'read_committed'
      'rec_version'
      'nowait'
      'read')
    Left = 56
    Top = 8
  end
  object IBQ233: TIBQuery
    Transaction = IBTr2
    Left = 16
    Top = 64
  end
  object IBTr2: TIBTransaction
    Params.Strings = (
      'read_committed'
      'rec_version'
      'nowait'
      'read')
    Left = 48
    Top = 64
  end
  object IBTr: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    CSMonitorSupport.Enabled = csmeDatabaseDriven
    TPBMode = tpbDefault
    Left = 128
    Top = 8
  end
  object IBQ: TpFIBQuery
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 128
    Top = 64
    qoStartTransaction = True
  end
  object IBQ2: TpFIBQuery
    Transaction = DM.pFIBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 128
    Top = 120
    qoStartTransaction = True
  end
end
