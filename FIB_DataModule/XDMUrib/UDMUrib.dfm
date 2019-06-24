object DMUrib: TDMUrib
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Left = 598
  Top = 106
  Height = 191
  Width = 286
  object Doc: TIBQuery
    Database = DM.IBData
    Transaction = IBTr1
    BufferChunks = 1000
    CachedUpdates = False
    Left = 72
    Top = 80
  end
  object IBQ: TIBQuery
    Database = DM.IBData
    Transaction = IBTr1
    BufferChunks = 1000
    CachedUpdates = False
    Left = 32
    Top = 16
  end
  object IBTr1: TIBTransaction
    Active = False
    DefaultDatabase = DM.IBData
    Params.Strings = (
      'read_committed'
      'rec_version'
      'nowait'
      'read')
    AutoStopAction = saNone
    Left = 64
    Top = 16
  end
  object DocAll: TIBQuery
    Database = DM.IBData
    Transaction = IBTr1
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      'select TDOC, IDSKLDOC from GALLDOC'
      'where IDDOC=:PARAM_IDDOC')
    Left = 24
    Top = 80
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'PARAM_IDDOC'
        ParamType = ptUnknown
      end>
    object DocAllTDOC: TIBStringField
      FieldName = 'TDOC'
      Origin = 'GALLDOC.TDOC'
      Size = 10
    end
    object DocAllIDSKLDOC: TIntegerField
      FieldName = 'IDSKLDOC'
      Origin = 'GALLDOC.IDSKLDOC'
    end
  end
  object DocT: TIBQuery
    Database = DM.IBData
    Transaction = IBTr1
    BufferChunks = 1000
    CachedUpdates = False
    Left = 112
    Top = 80
  end
end
