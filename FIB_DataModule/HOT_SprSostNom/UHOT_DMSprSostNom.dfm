object HOT_DMSprSostNom: THOT_DMSprSostNom
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 231
  Width = 363
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 40
    Top = 16
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 40
    Top = 96
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select  *'
      'from HOT_SSOSTNOM'
      '')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 160
    Top = 16
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableFLBRON_HOT_SSOSTNOM: TFIBSmallIntField
      FieldName = 'FLBRON_HOT_SSOSTNOM'
    end
    object TableFLRASM_HOT_SSOSTNOM: TFIBSmallIntField
      FieldName = 'FLRASM_HOT_SSOSTNOM'
    end
    object TableID_HOT_SSOSTNOM: TFIBBCDField
      FieldName = 'ID_HOT_SSOSTNOM'
      Size = 0
      RoundByScale = True
    end
    object TableNAME_HOT_SSOSTNOM: TFIBWideStringField
      FieldName = 'NAME_HOT_SSOSTNOM'
      Size = 100
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE HOT_SSOSTNOM'
      'SET '
      '    GID_HOT_SSOSTNOM = :GID_HOT_SSOSTNOM,'
      '    NAME_HOT_SSOSTNOM = :NAME_HOT_SSOSTNOM,'
      '    FLBRON_HOT_SSOSTNOM = :FLBRON_HOT_SSOSTNOM,'
      '    FLRASM_HOT_SSOSTNOM = :FLRASM_HOT_SSOSTNOM,'
      '    COLOR_HOT_SSOSTNOM = :COLOR_HOT_SSOSTNOM'
      'WHERE'
      '    ID_HOT_SSOSTNOM = :OLD_ID_HOT_SSOSTNOM'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    HOT_SSOSTNOM'
      'WHERE'
      '        ID_HOT_SSOSTNOM = :OLD_ID_HOT_SSOSTNOM'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO HOT_SSOSTNOM('
      '    ID_HOT_SSOSTNOM,'
      '    GID_HOT_SSOSTNOM,'
      '    NAME_HOT_SSOSTNOM,'
      '    FLBRON_HOT_SSOSTNOM,'
      '    FLRASM_HOT_SSOSTNOM,'
      '    COLOR_HOT_SSOSTNOM'
      ')'
      'VALUES('
      '    :ID_HOT_SSOSTNOM,'
      '    :GID_HOT_SSOSTNOM,'
      '    :NAME_HOT_SSOSTNOM,'
      '    :FLBRON_HOT_SSOSTNOM,'
      '    :FLRASM_HOT_SSOSTNOM,'
      '    :COLOR_HOT_SSOSTNOM'
      ')')
    RefreshSQL.Strings = (
      'select *'
      'from HOT_SSOSTNOM '
      'where(  ID_HOT_SSOSTNOM=:PARAM_ID'
      
        '     ) and (     HOT_SSOSTNOM.ID_HOT_SSOSTNOM = :OLD_ID_HOT_SSOS' +
        'TNOM'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select *'
      'from HOT_SSOSTNOM '
      'where ID_HOT_SSOSTNOM=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'HOT_SSOSTNOM'
    AutoUpdateOptions.KeyFields = 'ID_HOT_SSOSTNOM'
    AutoUpdateOptions.GeneratorName = 'GEN_HOT_SSOSTNOM_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 96
    object ElementFLBRON_HOT_SSOSTNOM: TFIBSmallIntField
      FieldName = 'FLBRON_HOT_SSOSTNOM'
    end
    object ElementFLRASM_HOT_SSOSTNOM: TFIBSmallIntField
      FieldName = 'FLRASM_HOT_SSOSTNOM'
    end
    object ElementID_HOT_SSOSTNOM: TFIBBCDField
      FieldName = 'ID_HOT_SSOSTNOM'
      Size = 0
      RoundByScale = True
    end
    object ElementCOLOR_HOT_SSOSTNOM: TFIBIntegerField
      FieldName = 'COLOR_HOT_SSOSTNOM'
    end
    object ElementNAME_HOT_SSOSTNOM: TFIBWideStringField
      FieldName = 'NAME_HOT_SSOSTNOM'
      Size = 100
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
    Left = 264
    Top = 16
  end
  object IBTrUpdate: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 264
    Top = 96
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 152
    Top = 160
    qoStartTransaction = True
  end
end
