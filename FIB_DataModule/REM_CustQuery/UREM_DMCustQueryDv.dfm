object REM_DMCustQueryDv: TREM_DMCustQueryDv
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 307
  Width = 547
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
      'select rem_cqueryt_dv.*,'
      '    rem_ssost_cquery.name_rem_ssost_cquery,'
      '    suser.name_user'
      'from rem_cqueryt_dv'
      
        'left outer join rem_ssost_cquery on rem_ssost_cquery.id_rem_ssos' +
        't_cquery=rem_cqueryt_dv.idsost_rem_cqueryt_dv'
      
        'left outer join suser on suser.id_user=rem_cqueryt_dv.iduser_rem' +
        '_cqueryt_dv'
      'where rem_cqueryt_dv.idcqt_rem_cqueryt_dv=:PARAM_IDCQT'
      'order by rem_cqueryt_dv.pos_rem_cqueryt_dv')
    Transaction = IBTr
    Left = 168
    Top = 8
    poUseLargeIntField = True
    object TableID_REM_CQUERYT_DV: TFIBLargeIntField
      FieldName = 'ID_REM_CQUERYT_DV'
    end
    object TableGID_REM_CQUERYT_DV: TFIBWideStringField
      FieldName = 'GID_REM_CQUERYT_DV'
      Size = 10
    end
    object TableIDBASE_REM_CQUERYT_DV: TFIBLargeIntField
      FieldName = 'IDBASE_REM_CQUERYT_DV'
    end
    object TableIDCQT_REM_CQUERYT_DV: TFIBLargeIntField
      FieldName = 'IDCQT_REM_CQUERYT_DV'
    end
    object TableIDUSER_REM_CQUERYT_DV: TFIBLargeIntField
      FieldName = 'IDUSER_REM_CQUERYT_DV'
    end
    object TableIDSOST_REM_CQUERYT_DV: TFIBLargeIntField
      FieldName = 'IDSOST_REM_CQUERYT_DV'
    end
    object TablePOS_REM_CQUERYT_DV: TFIBDateTimeField
      FieldName = 'POS_REM_CQUERYT_DV'
      DisplayFormat = 'c'
    end
    object TableNAME_REM_SSOST_CQUERY: TFIBWideStringField
      FieldName = 'NAME_REM_SSOST_CQUERY'
      Size = 200
    end
    object TableNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
      Size = 200
    end
    object TableRUN_REM_CQUERY_DV: TFIBSmallIntField
      FieldName = 'RUN_REM_CQUERY_DV'
    end
    object TableACT_REM_CQUERY_DV: TFIBSmallIntField
      FieldName = 'ACT_REM_CQUERY_DV'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_CQUERYT_DV'
      'SET '
      '    GID_REM_CQUERYT_DV = :GID_REM_CQUERYT_DV,'
      '    IDBASE_REM_CQUERYT_DV = :IDBASE_REM_CQUERYT_DV,'
      '    IDCQT_REM_CQUERYT_DV = :IDCQT_REM_CQUERYT_DV,'
      '    IDUSER_REM_CQUERYT_DV = :IDUSER_REM_CQUERYT_DV,'
      '    IDSOST_REM_CQUERYT_DV = :IDSOST_REM_CQUERYT_DV,'
      '    POS_REM_CQUERYT_DV = :POS_REM_CQUERYT_DV,'
      '    RUN_REM_CQUERY_DV = :RUN_REM_CQUERY_DV,'
      '    ACT_REM_CQUERY_DV = :ACT_REM_CQUERY_DV'
      'WHERE'
      '    ID_REM_CQUERYT_DV = :OLD_ID_REM_CQUERYT_DV'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_CQUERYT_DV'
      'WHERE'
      '        ID_REM_CQUERYT_DV = :OLD_ID_REM_CQUERYT_DV'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_CQUERYT_DV('
      '    ID_REM_CQUERYT_DV,'
      '    GID_REM_CQUERYT_DV,'
      '    IDBASE_REM_CQUERYT_DV,'
      '    IDCQT_REM_CQUERYT_DV,'
      '    IDUSER_REM_CQUERYT_DV,'
      '    IDSOST_REM_CQUERYT_DV,'
      '    POS_REM_CQUERYT_DV,'
      '    RUN_REM_CQUERY_DV,'
      '    ACT_REM_CQUERY_DV'
      ')'
      'VALUES('
      '    :ID_REM_CQUERYT_DV,'
      '    :GID_REM_CQUERYT_DV,'
      '    :IDBASE_REM_CQUERYT_DV,'
      '    :IDCQT_REM_CQUERYT_DV,'
      '    :IDUSER_REM_CQUERYT_DV,'
      '    :IDSOST_REM_CQUERYT_DV,'
      '    :POS_REM_CQUERYT_DV,'
      '    :RUN_REM_CQUERY_DV,'
      '    :ACT_REM_CQUERY_DV'
      ')')
    RefreshSQL.Strings = (
      'select rem_cqueryt_dv.*,'
      '    rem_ssost_cquery.name_rem_ssost_cquery,'
      '    suser.name_user'
      'from rem_cqueryt_dv'
      
        'left outer join rem_ssost_cquery on rem_ssost_cquery.id_rem_ssos' +
        't_cquery=rem_cqueryt_dv.idsost_rem_cqueryt_dv'
      
        'left outer join suser on suser.id_user=rem_cqueryt_dv.iduser_rem' +
        '_cqueryt_dv'
      'where(  rem_cqueryt_dv.id_rem_cqueryt_dv=:PARAM_ID'
      
        '     ) and (     REM_CQUERYT_DV.ID_REM_CQUERYT_DV = :OLD_ID_REM_' +
        'CQUERYT_DV'
      '     )'
      '    '
      '')
    SelectSQL.Strings = (
      'select rem_cqueryt_dv.*,'
      '    rem_ssost_cquery.name_rem_ssost_cquery,'
      '    suser.name_user'
      'from rem_cqueryt_dv'
      
        'left outer join rem_ssost_cquery on rem_ssost_cquery.id_rem_ssos' +
        't_cquery=rem_cqueryt_dv.idsost_rem_cqueryt_dv'
      
        'left outer join suser on suser.id_user=rem_cqueryt_dv.iduser_rem' +
        '_cqueryt_dv'
      'where rem_cqueryt_dv.id_rem_cqueryt_dv=:PARAM_ID'
      '')
    AutoUpdateOptions.UpdateTableName = 'REM_CQUERYT_DV'
    AutoUpdateOptions.KeyFields = 'ID_REM_CQUERYT_DV'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_CQUERYT_DV_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 80
    poUseLargeIntField = True
    object ElementID_REM_CQUERYT_DV: TFIBLargeIntField
      FieldName = 'ID_REM_CQUERYT_DV'
    end
    object ElementGID_REM_CQUERYT_DV: TFIBWideStringField
      FieldName = 'GID_REM_CQUERYT_DV'
      Size = 10
    end
    object ElementIDBASE_REM_CQUERYT_DV: TFIBLargeIntField
      FieldName = 'IDBASE_REM_CQUERYT_DV'
    end
    object ElementIDCQT_REM_CQUERYT_DV: TFIBLargeIntField
      FieldName = 'IDCQT_REM_CQUERYT_DV'
    end
    object ElementIDUSER_REM_CQUERYT_DV: TFIBLargeIntField
      FieldName = 'IDUSER_REM_CQUERYT_DV'
    end
    object ElementIDSOST_REM_CQUERYT_DV: TFIBLargeIntField
      FieldName = 'IDSOST_REM_CQUERYT_DV'
    end
    object ElementPOS_REM_CQUERYT_DV: TFIBDateTimeField
      FieldName = 'POS_REM_CQUERYT_DV'
      DisplayFormat = 'c'
    end
    object ElementNAME_REM_SSOST_CQUERY: TFIBWideStringField
      FieldName = 'NAME_REM_SSOST_CQUERY'
      Size = 200
    end
    object ElementNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
      Size = 200
    end
    object ElementRUN_REM_CQUERY_DV: TFIBSmallIntField
      FieldName = 'RUN_REM_CQUERY_DV'
    end
    object ElementACT_REM_CQUERY_DV: TFIBSmallIntField
      FieldName = 'ACT_REM_CQUERY_DV'
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
    Top = 80
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 352
    Top = 80
    qoStartTransaction = True
  end
end
