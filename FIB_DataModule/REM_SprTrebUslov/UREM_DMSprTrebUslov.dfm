object REM_DMSprTrebUslov: TREM_DMSprTrebUslov
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 301
  Width = 491
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 8
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 56
    Top = 80
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select'
      '        rem_strebuslov.*,'
      '        rem_stypuslov.name_rem_stypuslov'
      'from rem_strebuslov'
      
        'left outer join rem_stypuslov on rem_strebuslov.idtypusla_rem_st' +
        'rebuslov=rem_stypuslov.id_rem_stypuslov'
      'where rem_strebuslov.iddmn_rem_strebuslov=:PARAM_IDDMN'
      'order by rem_strebuslov.name_rem_strebuslov')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 160
    Top = 8
    poUseLargeIntField = True
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_REM_STREBUSLOV: TFIBLargeIntField
      FieldName = 'ID_REM_STREBUSLOV'
    end
    object TableGID_REM_STREBUSLOV: TFIBWideStringField
      FieldName = 'GID_REM_STREBUSLOV'
      Size = 10
    end
    object TableIDBASE_REM_STREBUSLOV: TFIBLargeIntField
      FieldName = 'IDBASE_REM_STREBUSLOV'
    end
    object TableIDDMN_REM_STREBUSLOV: TFIBLargeIntField
      FieldName = 'IDDMN_REM_STREBUSLOV'
    end
    object TableIDTYPUSLA_REM_STREBUSLOV: TFIBLargeIntField
      FieldName = 'IDTYPUSLA_REM_STREBUSLOV'
    end
    object TableNAME_REM_STREBUSLOV: TFIBWideStringField
      FieldName = 'NAME_REM_STREBUSLOV'
      Size = 200
    end
    object TableNAME_REM_STYPUSLOV: TFIBWideStringField
      FieldName = 'NAME_REM_STYPUSLOV'
      Size = 200
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_STREBUSLOV'
      'SET '
      '    GID_REM_STREBUSLOV = :GID_REM_STREBUSLOV,'
      '    IDBASE_REM_STREBUSLOV = :IDBASE_REM_STREBUSLOV,'
      '    IDDMN_REM_STREBUSLOV = :IDDMN_REM_STREBUSLOV,'
      '    IDTYPUSLA_REM_STREBUSLOV = :IDTYPUSLA_REM_STREBUSLOV,'
      '    NAME_REM_STREBUSLOV = :NAME_REM_STREBUSLOV'
      'WHERE'
      '    ID_REM_STREBUSLOV = :OLD_ID_REM_STREBUSLOV'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_STREBUSLOV'
      'WHERE'
      '        ID_REM_STREBUSLOV = :OLD_ID_REM_STREBUSLOV'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_STREBUSLOV('
      '    ID_REM_STREBUSLOV,'
      '    GID_REM_STREBUSLOV,'
      '    IDBASE_REM_STREBUSLOV,'
      '    IDDMN_REM_STREBUSLOV,'
      '    IDTYPUSLA_REM_STREBUSLOV,'
      '    NAME_REM_STREBUSLOV'
      ')'
      'VALUES('
      '    :ID_REM_STREBUSLOV,'
      '    :GID_REM_STREBUSLOV,'
      '    :IDBASE_REM_STREBUSLOV,'
      '    :IDDMN_REM_STREBUSLOV,'
      '    :IDTYPUSLA_REM_STREBUSLOV,'
      '    :NAME_REM_STREBUSLOV'
      ')')
    RefreshSQL.Strings = (
      'select'
      '        rem_strebuslov.*,'
      '        rem_stypuslov.name_rem_stypuslov'
      'from rem_strebuslov'
      
        'left outer join rem_stypuslov on rem_strebuslov.idtypusla_rem_st' +
        'rebuslov=rem_stypuslov.id_rem_stypuslov'
      'where(  rem_strebuslov.id_rem_strebuslov=:PARAM_ID'
      
        '     ) and (     REM_STREBUSLOV.ID_REM_STREBUSLOV = :OLD_ID_REM_' +
        'STREBUSLOV'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select'
      '        rem_strebuslov.*,'
      '        rem_stypuslov.name_rem_stypuslov'
      'from rem_strebuslov'
      
        'left outer join rem_stypuslov on rem_strebuslov.idtypusla_rem_st' +
        'rebuslov=rem_stypuslov.id_rem_stypuslov'
      'where rem_strebuslov.id_rem_strebuslov=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_STREBUSLOV'
    AutoUpdateOptions.KeyFields = 'ID_REM_STREBUSLOV'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_STREBUSLOV_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 80
    poUseLargeIntField = True
    object ElementID_REM_STREBUSLOV: TFIBLargeIntField
      FieldName = 'ID_REM_STREBUSLOV'
    end
    object ElementGID_REM_STREBUSLOV: TFIBWideStringField
      FieldName = 'GID_REM_STREBUSLOV'
      Size = 10
    end
    object ElementIDBASE_REM_STREBUSLOV: TFIBLargeIntField
      FieldName = 'IDBASE_REM_STREBUSLOV'
    end
    object ElementIDDMN_REM_STREBUSLOV: TFIBLargeIntField
      FieldName = 'IDDMN_REM_STREBUSLOV'
    end
    object ElementIDTYPUSLA_REM_STREBUSLOV: TFIBLargeIntField
      FieldName = 'IDTYPUSLA_REM_STREBUSLOV'
    end
    object ElementNAME_REM_STREBUSLOV: TFIBWideStringField
      FieldName = 'NAME_REM_STREBUSLOV'
      Size = 200
    end
    object ElementNAME_REM_STYPUSLOV: TFIBWideStringField
      FieldName = 'NAME_REM_STYPUSLOV'
      Size = 200
    end
  end
  object IBTr: TpFIBTransaction
    DefaultDatabase = pFIBDatabase1
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
    DefaultDatabase = pFIBDatabase1
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 264
    Top = 80
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 344
    Top = 80
    qoStartTransaction = True
  end
  object pFIBDatabase1: TpFIBDatabase
    Connected = True
    DBName = 'K:\NewData\BASE_33.FDB'
    DBParams.Strings = (
      'user_name=SYSDBA'
      'password=masterkey'
      'lc_ctype=UTF8')
    DefaultTransaction = IBTr
    DefaultUpdateTransaction = IBTrUpdate
    SQLDialect = 3
    Timeout = 0
    WaitForRestoreConnect = 0
    Left = 304
    Top = 192
  end
end
