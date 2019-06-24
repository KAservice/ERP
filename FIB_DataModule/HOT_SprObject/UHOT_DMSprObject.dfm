object HOT_DMSprObject: THOT_DMSprObject
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
      'select  HOT_SOBJECT.*, NAMESKLAD '
      'from HOT_SOBJECT'
      'left outer join SSKLAD on IDSKL_HOT_SOBJECT=IDSKLAD')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 160
    Top = 16
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_HOT_SOBJECT: TFIBBCDField
      FieldName = 'ID_HOT_SOBJECT'
      Size = 0
      RoundByScale = True
    end
    object TableIDSKL_HOT_SOBJECT: TFIBBCDField
      FieldName = 'IDSKL_HOT_SOBJECT'
      Size = 0
      RoundByScale = True
    end
    object TableNAME_HOT_SOBJECT: TFIBWideStringField
      FieldName = 'NAME_HOT_SOBJECT'
      Size = 100
    end
    object TableNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 100
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE HOT_SOBJECT'
      'SET '
      '    GID_HOT_SOBJECT = :GID_HOT_SOBJECT,'
      '    NAME_HOT_SOBJECT = :NAME_HOT_SOBJECT,'
      '    IDSKL_HOT_SOBJECT = :IDSKL_HOT_SOBJECT'
      'WHERE'
      '    ID_HOT_SOBJECT = :OLD_ID_HOT_SOBJECT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    HOT_SOBJECT'
      'WHERE'
      '        ID_HOT_SOBJECT = :OLD_ID_HOT_SOBJECT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO HOT_SOBJECT('
      '    ID_HOT_SOBJECT,'
      '    GID_HOT_SOBJECT,'
      '    NAME_HOT_SOBJECT,'
      '    IDSKL_HOT_SOBJECT'
      ')'
      'VALUES('
      '    :ID_HOT_SOBJECT,'
      '    :GID_HOT_SOBJECT,'
      '    :NAME_HOT_SOBJECT,'
      '    :IDSKL_HOT_SOBJECT'
      ')')
    RefreshSQL.Strings = (
      'select HOT_SOBJECT.*, NAMESKLAD'
      'from HOT_SOBJECT '
      'left outer join SSKLAD on IDSKL_HOT_SOBJECT=IDSKLAD'
      'where(  ID_HOT_SOBJECT=:PARAM_ID'
      
        '     ) and (     HOT_SOBJECT.ID_HOT_SOBJECT = :OLD_ID_HOT_SOBJEC' +
        'T'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select HOT_SOBJECT.*, NAMESKLAD'
      'from HOT_SOBJECT '
      'left outer join SSKLAD on IDSKL_HOT_SOBJECT=IDSKLAD'
      'where ID_HOT_SOBJECT=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'HOT_SOBJECT'
    AutoUpdateOptions.KeyFields = 'ID_HOT_SOBJECT'
    AutoUpdateOptions.GeneratorName = 'GEN_HOT_SOBJECT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 96
    object ElementID_HOT_SOBJECT: TFIBBCDField
      FieldName = 'ID_HOT_SOBJECT'
      Size = 0
      RoundByScale = True
    end
    object ElementIDSKL_HOT_SOBJECT: TFIBBCDField
      FieldName = 'IDSKL_HOT_SOBJECT'
      Size = 0
      RoundByScale = True
    end
    object ElementNAME_HOT_SOBJECT: TFIBWideStringField
      FieldName = 'NAME_HOT_SOBJECT'
      Size = 100
    end
    object ElementNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
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
