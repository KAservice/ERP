object HOT_DMSprTypePosel: THOT_DMSprTypePosel
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
      'from HOT_STYPEPOS'
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
    object TableKOLM_HOT_STYPEPOS: TFIBSmallIntField
      FieldName = 'KOLM_HOT_STYPEPOS'
    end
    object TableALL_HOT_STYPEPOS: TFIBSmallIntField
      FieldName = 'ALL_HOT_STYPEPOS'
    end
    object TableID_HOT_STYPEPOS: TFIBBCDField
      FieldName = 'ID_HOT_STYPEPOS'
      Size = 0
      RoundByScale = True
    end
    object TableNAME_HOT_STYPEPOS: TFIBWideStringField
      FieldName = 'NAME_HOT_STYPEPOS'
      Size = 100
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE HOT_STYPEPOS'
      'SET '
      '    GID_HOT_STYPEPOS = :GID_HOT_STYPEPOS,'
      '    NAME_HOT_STYPEPOS = :NAME_HOT_STYPEPOS,'
      '    KOLM_HOT_STYPEPOS = :KOLM_HOT_STYPEPOS,'
      '    ALL_HOT_STYPEPOS = :ALL_HOT_STYPEPOS'
      'WHERE'
      '    ID_HOT_STYPEPOS = :OLD_ID_HOT_STYPEPOS'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    HOT_STYPEPOS'
      'WHERE'
      '        ID_HOT_STYPEPOS = :OLD_ID_HOT_STYPEPOS'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO HOT_STYPEPOS('
      '    ID_HOT_STYPEPOS,'
      '    GID_HOT_STYPEPOS,'
      '    NAME_HOT_STYPEPOS,'
      '    KOLM_HOT_STYPEPOS,'
      '    ALL_HOT_STYPEPOS'
      ')'
      'VALUES('
      '    :ID_HOT_STYPEPOS,'
      '    :GID_HOT_STYPEPOS,'
      '    :NAME_HOT_STYPEPOS,'
      '    :KOLM_HOT_STYPEPOS,'
      '    :ALL_HOT_STYPEPOS'
      ')')
    RefreshSQL.Strings = (
      'select *'
      'from HOT_STYPEPOS'
      'where(  ID_HOT_STYPEPOS=:PARAM_ID'
      
        '     ) and (     HOT_STYPEPOS.ID_HOT_STYPEPOS = :OLD_ID_HOT_STYP' +
        'EPOS'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select *'
      'from HOT_STYPEPOS'
      'where ID_HOT_STYPEPOS=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'HOT_STYPEPOS'
    AutoUpdateOptions.KeyFields = 'ID_HOT_STYPEPOS'
    AutoUpdateOptions.GeneratorName = 'GEN_HOT_STYPEPOS_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 96
    object ElementKOLM_HOT_STYPEPOS: TFIBSmallIntField
      FieldName = 'KOLM_HOT_STYPEPOS'
    end
    object ElementALL_HOT_STYPEPOS: TFIBSmallIntField
      FieldName = 'ALL_HOT_STYPEPOS'
    end
    object ElementID_HOT_STYPEPOS: TFIBBCDField
      FieldName = 'ID_HOT_STYPEPOS'
      Size = 0
      RoundByScale = True
    end
    object ElementNAME_HOT_STYPEPOS: TFIBWideStringField
      FieldName = 'NAME_HOT_STYPEPOS'
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
