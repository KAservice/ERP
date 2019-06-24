object REM_DMSprSost: TREM_DMSprSost
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
      'select  * from REM_SSOST'
      'order by rem_ssost.name_remssost')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_REMSSOST: TFIBLargeIntField
      FieldName = 'ID_REMSSOST'
    end
    object TableGID_REMSSOST: TFIBWideStringField
      FieldName = 'GID_REMSSOST'
      Size = 10
    end
    object TableNAME_REMSSOST: TFIBWideStringField
      FieldName = 'NAME_REMSSOST'
      Size = 100
    end
    object TableIDBASE_REM_SSOST: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SSOST'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_SSOST'
      'SET '
      '    GID_REMSSOST = :GID_REMSSOST,'
      '    NAME_REMSSOST = :NAME_REMSSOST'
      'WHERE'
      '    ID_REMSSOST = :OLD_ID_REMSSOST'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_SSOST'
      'WHERE'
      '        ID_REMSSOST = :OLD_ID_REMSSOST'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_SSOST('
      '    ID_REMSSOST,'
      '    GID_REMSSOST,'
      '    NAME_REMSSOST'
      ')'
      'VALUES('
      '    :ID_REMSSOST,'
      '    :GID_REMSSOST,'
      '    :NAME_REMSSOST'
      ')')
    RefreshSQL.Strings = (
      'select * from REM_SSOST'
      'where(  ID_REMSSOST=:PARAM_ID'
      '     ) and (     REM_SSOST.ID_REMSSOST = :OLD_ID_REMSSOST'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from REM_SSOST'
      'where ID_REMSSOST=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_SSOST'
    AutoUpdateOptions.KeyFields = 'ID_REMSSOST'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SSOST_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 96
    poUseLargeIntField = True
    object ElementID_REMSSOST: TFIBLargeIntField
      FieldName = 'ID_REMSSOST'
    end
    object ElementGID_REMSSOST: TFIBWideStringField
      FieldName = 'GID_REMSSOST'
      Size = 10
    end
    object ElementNAME_REMSSOST: TFIBWideStringField
      FieldName = 'NAME_REMSSOST'
      Size = 100
    end
    object ElementIDBASE_REM_SSOST: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SSOST'
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
