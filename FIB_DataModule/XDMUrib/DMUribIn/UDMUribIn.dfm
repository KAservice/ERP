object DMUribIn: TDMUribIn
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 231
  Width = 378
  object xml: TXMLDocument
    Left = 8
    Top = 8
    DOMVendorDesc = 'Open XML'
  end
  object IBQ122: TIBQuery
    Transaction = IBTr22
    Left = 8
    Top = 56
  end
  object IBTr22: TIBTransaction
    Params.Strings = (
      'read_committed'
      'rec_version'
      'nowait')
    Left = 56
    Top = 56
  end
  object IBTr122: TIBTransaction
    Params.Strings = (
      'read_committed'
      'rec_version'
      'nowait'
      'read')
    Left = 8
    Top = 112
  end
  object IBQ222: TIBQuery
    Transaction = IBTr122
    Left = 48
    Top = 112
  end
  object IBQ322: TIBQuery
    Transaction = IBTr122
    Left = 96
    Top = 112
  end
  object IBQ422: TIBQuery
    Transaction = IBTr122
    Left = 136
    Top = 112
  end
  object IBQ1: TpFIBQuery
    Transaction = IBTr
    Database = DM.pFIBData
    Left = 144
    Top = 56
    qoStartTransaction = True
  end
  object IBTr: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 192
    Top = 56
  end
  object IBTr1: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 8
    Top = 168
  end
  object IBQ2: TpFIBQuery
    Transaction = IBTr1
    Database = DM.pFIBData
    Left = 56
    Top = 168
    qoAutoCommit = True
    qoStartTransaction = True
  end
  object IBQ3: TpFIBQuery
    Transaction = IBTr1
    Database = DM.pFIBData
    Left = 96
    Top = 168
    qoAutoCommit = True
    qoStartTransaction = True
  end
  object IBQ4: TpFIBQuery
    Transaction = IBTr1
    Database = DM.pFIBData
    Left = 136
    Top = 168
    qoAutoCommit = True
    qoStartTransaction = True
  end
  object TableDoc: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from SUSER where ID_USER=123456')
    Transaction = IBTr
    Database = DM.pFIBData
    Left = 288
    Top = 120
    object TableDocPOSDOC: TDateTimeField
      FieldKind = fkCalculated
      FieldName = 'POSDOC'
      Calculated = True
    end
    object TableDocIDDOC: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'IDDOC'
      Calculated = True
    end
    object TableDocTDOC: TStringField
      FieldKind = fkCalculated
      FieldName = 'TDOC'
      Size = 10
      Calculated = True
    end
  end
end
