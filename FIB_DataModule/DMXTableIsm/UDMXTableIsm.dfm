object DMXTableIsm: TDMXTableIsm
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 161
  Width = 374
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 24
  end
  object DataSourceElement: TDataSource
    Left = 48
    Top = 80
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from  XTISM where  ID_XTISM > :PARAM_IDMAX')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 160
    Top = 24
    object TablePOS_XTISM: TFIBDateTimeField
      FieldName = 'POS_XTISM'
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_XTISM: TFIBBCDField
      FieldName = 'ID_XTISM'
      Size = 0
      RoundByScale = True
    end
    object TableIDREC_XTISM: TFIBIntegerField
      FieldName = 'IDREC_XTISM'
    end
    object TableOPERATION_XTISM: TFIBSmallIntField
      FieldName = 'OPERATION_XTISM'
    end
    object TableTYPE_OBJECT_XTISM: TFIBSmallIntField
      FieldName = 'TYPE_OBJECT_XTISM'
    end
    object TableUSER_XTISM: TFIBWideStringField
      FieldName = 'USER_XTISM'
    end
    object TableNAME_TABLE_XTISM: TFIBWideStringField
      FieldName = 'NAME_TABLE_XTISM'
    end
    object TableNAME_FIELD_ID_XTISM: TFIBWideStringField
      FieldName = 'NAME_FIELD_ID_XTISM'
      Size = 40
    end
    object TableVALUE_FIELD_ID_XTISM: TFIBBCDField
      FieldName = 'VALUE_FIELD_ID_XTISM'
      Size = 0
      RoundByScale = True
    end
    object TableIDBASE_XTISM: TFIBBCDField
      FieldName = 'IDBASE_XTISM'
      Size = 0
      RoundByScale = True
    end
    object TableIDEXT_BASE_XTISM: TFIBBCDField
      FieldName = 'IDEXT_BASE_XTISM'
      Size = 0
      RoundByScale = True
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE XTISM'
      'SET '
      '    POS_XTISM = :POS_XTISM,'
      '    OPERATION_XTISM = :OPERATION_XTISM,'
      '    TYPE_OBJECT_XTISM = :TYPE_OBJECT_XTISM,'
      '    USER_XTISM = :USER_XTISM,'
      '    NAME_TABLE_XTISM = :NAME_TABLE_XTISM,'
      '    NAME_FIELD_ID_XTISM = :NAME_FIELD_ID_XTISM,'
      '    VALUE_FIELD_ID_XTISM = :VALUE_FIELD_ID_XTISM,'
      '    IDBASE_XTISM = :IDBASE_XTISM,'
      '    IDEXT_BASE_XTISM = :IDEXT_BASE_XTISM,'
      '    IDEXT_DATAOUT_XTISM = :IDEXT_DATAOUT_XTISM,'
      '    IDEXT_DOUT_XTISM = :IDEXT_DOUT_XTISM'
      'WHERE'
      '    ID_XTISM = :OLD_ID_XTISM'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    XTISM'
      'WHERE'
      '        ID_XTISM = :OLD_ID_XTISM'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO XTISM('
      '    ID_XTISM,'
      '    POS_XTISM,'
      '    OPERATION_XTISM,'
      '    TYPE_OBJECT_XTISM,'
      '    USER_XTISM,'
      '    NAME_TABLE_XTISM,'
      '    NAME_FIELD_ID_XTISM,'
      '    VALUE_FIELD_ID_XTISM,'
      '    IDBASE_XTISM,'
      '    IDEXT_BASE_XTISM,'
      '    IDEXT_DATAOUT_XTISM,'
      '    IDEXT_DOUT_XTISM'
      ')'
      'VALUES('
      '    :ID_XTISM,'
      '    :POS_XTISM,'
      '    :OPERATION_XTISM,'
      '    :TYPE_OBJECT_XTISM,'
      '    :USER_XTISM,'
      '    :NAME_TABLE_XTISM,'
      '    :NAME_FIELD_ID_XTISM,'
      '    :VALUE_FIELD_ID_XTISM,'
      '    :IDBASE_XTISM,'
      '    :IDEXT_BASE_XTISM,'
      '    :IDEXT_DATAOUT_XTISM,'
      '    :IDEXT_DOUT_XTISM'
      ')')
    RefreshSQL.Strings = (
      'select * from  XTISM where(  ID_XTISM=:PARAM_ID'
      '     ) and (     XTISM.ID_XTISM = :OLD_ID_XTISM'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from  XTISM where ID_XTISM=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'XTISM'
    AutoUpdateOptions.KeyFields = 'ID_XTISM'
    AutoUpdateOptions.GeneratorName = 'GEN_XTISM_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 80
    object ElementID_XTISM: TFIBBCDField
      FieldName = 'ID_XTISM'
      Size = 0
      RoundByScale = True
    end
    object ElementPOS_XTISM: TFIBDateTimeField
      FieldName = 'POS_XTISM'
    end
    object ElementOPERATION_XTISM: TFIBSmallIntField
      FieldName = 'OPERATION_XTISM'
    end
    object ElementTYPE_OBJECT_XTISM: TFIBSmallIntField
      FieldName = 'TYPE_OBJECT_XTISM'
    end
    object ElementUSER_XTISM: TFIBWideStringField
      FieldName = 'USER_XTISM'
    end
    object ElementNAME_TABLE_XTISM: TFIBWideStringField
      FieldName = 'NAME_TABLE_XTISM'
    end
    object ElementNAME_FIELD_ID_XTISM: TFIBWideStringField
      FieldName = 'NAME_FIELD_ID_XTISM'
      Size = 40
    end
    object ElementVALUE_FIELD_ID_XTISM: TFIBBCDField
      FieldName = 'VALUE_FIELD_ID_XTISM'
      Size = 0
      RoundByScale = True
    end
    object ElementIDBASE_XTISM: TFIBBCDField
      FieldName = 'IDBASE_XTISM'
      Size = 0
      RoundByScale = True
    end
    object ElementIDEXT_BASE_XTISM: TFIBBCDField
      FieldName = 'IDEXT_BASE_XTISM'
      Size = 0
      RoundByScale = True
    end
  end
  object IBTr: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 256
    Top = 24
  end
  object IBTrUpdate: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 256
    Top = 80
  end
end
