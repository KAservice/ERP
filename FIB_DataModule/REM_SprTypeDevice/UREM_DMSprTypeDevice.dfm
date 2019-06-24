object REM_DMSprTypeDevice: TREM_DMSprTypeDevice
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 305
  Width = 596
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 48
    Top = 88
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select '
      '  rem_stypedevice.*'
      'from '
      '  rem_stypedevice')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 144
    Top = 16
    poUseLargeIntField = True
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_REM_STYPEDEVICE: TFIBLargeIntField
      FieldName = 'ID_REM_STYPEDEVICE'
    end
    object TableGID_REM_STYPEDEVICE: TFIBWideStringField
      FieldName = 'GID_REM_STYPEDEVICE'
      Size = 10
    end
    object TableIDBASE_REM_STYPEDEVICE: TFIBLargeIntField
      FieldName = 'IDBASE_REM_STYPEDEVICE'
    end
    object TableNAME_REM_STYPEDEVICE: TFIBWideStringField
      FieldName = 'NAME_REM_STYPEDEVICE'
      Size = 200
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_STYPEDEVICE'
      'SET '
      '    GID_REM_STYPEDEVICE = :GID_REM_STYPEDEVICE,'
      '    IDBASE_REM_STYPEDEVICE = :IDBASE_REM_STYPEDEVICE,'
      '    NAME_REM_STYPEDEVICE = :NAME_REM_STYPEDEVICE'
      'WHERE'
      '    ID_REM_STYPEDEVICE = :OLD_ID_REM_STYPEDEVICE'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_STYPEDEVICE'
      'WHERE'
      '        ID_REM_STYPEDEVICE = :OLD_ID_REM_STYPEDEVICE'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_STYPEDEVICE('
      '    ID_REM_STYPEDEVICE,'
      '    GID_REM_STYPEDEVICE,'
      '    IDBASE_REM_STYPEDEVICE,'
      '    NAME_REM_STYPEDEVICE'
      ')'
      'VALUES('
      '    :ID_REM_STYPEDEVICE,'
      '    :GID_REM_STYPEDEVICE,'
      '    :IDBASE_REM_STYPEDEVICE,'
      '    :NAME_REM_STYPEDEVICE'
      ')')
    RefreshSQL.Strings = (
      'select '
      '  rem_stypedevice.*'
      'from '
      '  rem_stypedevice'
      'where(  '
      '  rem_stypedevice.id_rem_stypedevice=:PARAM_ID'
      
        '     ) and (     REM_STYPEDEVICE.ID_REM_STYPEDEVICE = :OLD_ID_RE' +
        'M_STYPEDEVICE'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select '
      '  rem_stypedevice.*'
      'from '
      '  rem_stypedevice'
      'where '
      '  rem_stypedevice.id_rem_stypedevice=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_STYPEDEVICE'
    AutoUpdateOptions.KeyFields = 'ID_REM_STYPEDEVICE'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_STYPEDEVICE_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 88
    poUseLargeIntField = True
    object ElementID_REM_STYPEDEVICE: TFIBLargeIntField
      FieldName = 'ID_REM_STYPEDEVICE'
    end
    object ElementGID_REM_STYPEDEVICE: TFIBWideStringField
      FieldName = 'GID_REM_STYPEDEVICE'
      Size = 10
    end
    object ElementIDBASE_REM_STYPEDEVICE: TFIBLargeIntField
      FieldName = 'IDBASE_REM_STYPEDEVICE'
    end
    object ElementNAME_REM_STYPEDEVICE: TFIBWideStringField
      FieldName = 'NAME_REM_STYPEDEVICE'
      Size = 200
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
    Left = 232
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
    Left = 232
    Top = 88
  end
end
