object DMUribIn: TDMUribIn
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 304
  Width = 686
  object QueryRecord: TpFIBQuery
    Transaction = TrRecord
    Database = DM.Database
    Left = 432
    Top = 24
    qoStartTransaction = True
  end
  object TrRecord: TpFIBTransaction
    DefaultDatabase = DM.Database
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 536
    Top = 24
  end
  object QueryUpdateRecord: TpFIBQuery
    Transaction = TrUpdateRecord
    Database = DM.Database
    Left = 432
    Top = 96
    qoStartTransaction = True
  end
  object TrUpdateRecord: TpFIBTransaction
    DefaultDatabase = DM.Database
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 536
    Top = 96
  end
  object AddDelRecordInXTism: TpFIBQuery
    Transaction = TrXTism
    Database = DM.Database
    SQL.Strings = (
      'insert into xtism  ('
      ' xtism.operation_xtism,'
      ' xtism.name_table_xtism,'
      ' xtism.name_field_id_xtism,'
      ' xtism.value_field_id_xtism,'
      ' xtism.idext_base_xtism,'
      ' xtism.idext_dataout_xtism  ) values ('
      ' 3,'
      ' :PARAM_NAME_TABLE,'
      ' :PARAM_NAME_FIELD_ID,'
      ' :PARAM_VALUE_FIELD_ID,'
      ' :PARAM_IDEXT_BASE,'
      ' :PARAM_IDEXT_DATAOUT)')
    Left = 424
    Top = 176
    qoStartTransaction = True
  end
  object TrXTism: TpFIBTransaction
    DefaultDatabase = DM.Database
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 544
    Top = 176
  end
  object AddRecordInXTism: TpFIBQuery
    Transaction = TrXTism
    Database = DM.Database
    SQL.Strings = (
      'insert into xtism  ('
      ' xtism.operation_xtism,'
      ' xtism.name_table_xtism,'
      ' xtism.name_field_id_xtism,'
      ' xtism.value_field_id_xtism,'
      ' xtism.idext_base_xtism,'
      ' xtism.idext_dataout_xtism  ) values ('
      ' :PARAM_OPERATION,'
      ' :PARAM_NAME_TABLE,'
      ' :PARAM_NAME_FIELD_ID,'
      ' :PARAM_VALUE_FIELD_ID,'
      ' :PARAM_IDEXT_BASE,'
      ' :PARAM_IDEXT_DATAOUT)')
    Left = 424
    Top = 240
    qoStartTransaction = True
  end
  object xml: TXMLDocument
    Left = 40
    Top = 80
    DOMVendorDesc = 'MSXML'
  end
end
