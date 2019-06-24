object DMInterfMainMenuPar: TDMInterfMainMenuPar
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 341
  Width = 435
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE INTERF_MAINMENU_PAR'
      'SET '
      '    IDBASE_INTERF_MAINMENU_PAR = :IDBASE_INTERF_MAINMENU_PAR,'
      '    GID_INTERF_MAINMENU_PAR = :GID_INTERF_MAINMENU_PAR,'
      
        '    IDMAINMENU_INTERF_MAINMENU_PAR = :IDMAINMENU_INTERF_MAINMENU' +
        '_PAR,'
      '    NAME_INTERF_MAINMENU_PAR = :NAME_INTERF_MAINMENU_PAR,'
      '    VALUE_INTERF_MAINMENU_PAR = :VALUE_INTERF_MAINMENU_PAR,'
      
        '    VALUE_TIMESTAMP_MAINMENU_PAR = :VALUE_TIMESTAMP_MAINMENU_PAR' +
        ','
      '    TYPE_VALUE_MAINMENU_PAR = :TYPE_VALUE_MAINMENU_PAR,'
      '    TYPE_PAR_INTERF_MAINMENU_PAR = :TYPE_PAR_INTERF_MAINMENU_PAR'
      'WHERE'
      '    ID_INTERF_MAINMENU_PAR = :OLD_ID_INTERF_MAINMENU_PAR'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    INTERF_MAINMENU_PAR'
      'WHERE'
      '        ID_INTERF_MAINMENU_PAR = :OLD_ID_INTERF_MAINMENU_PAR'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO INTERF_MAINMENU_PAR('
      '    ID_INTERF_MAINMENU_PAR,'
      '    IDBASE_INTERF_MAINMENU_PAR,'
      '    GID_INTERF_MAINMENU_PAR,'
      '    IDMAINMENU_INTERF_MAINMENU_PAR,'
      '    NAME_INTERF_MAINMENU_PAR,'
      '    VALUE_INTERF_MAINMENU_PAR,'
      '    VALUE_TIMESTAMP_MAINMENU_PAR,'
      '    TYPE_VALUE_MAINMENU_PAR,'
      '    TYPE_PAR_INTERF_MAINMENU_PAR'
      ')'
      'VALUES('
      '    :ID_INTERF_MAINMENU_PAR,'
      '    :IDBASE_INTERF_MAINMENU_PAR,'
      '    :GID_INTERF_MAINMENU_PAR,'
      '    :IDMAINMENU_INTERF_MAINMENU_PAR,'
      '    :NAME_INTERF_MAINMENU_PAR,'
      '    :VALUE_INTERF_MAINMENU_PAR,'
      '    :VALUE_TIMESTAMP_MAINMENU_PAR,'
      '    :TYPE_VALUE_MAINMENU_PAR,'
      '    :TYPE_PAR_INTERF_MAINMENU_PAR'
      ')')
    RefreshSQL.Strings = (
      'select interf_mainmenu_par.*'
      'from interf_mainmenu_par'
      
        'where(  interf_mainmenu_par.idmainmenu_interf_mainmenu_par=:PARA' +
        'M_IDOWNER'
      
        '     ) and (     INTERF_MAINMENU_PAR.ID_INTERF_MAINMENU_PAR = :O' +
        'LD_ID_INTERF_MAINMENU_PAR'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select interf_mainmenu_par.*'
      'from interf_mainmenu_par'
      
        'where interf_mainmenu_par.idmainmenu_interf_mainmenu_par=:PARAM_' +
        'IDOWNER')
    AutoUpdateOptions.UpdateTableName = 'INTERF_MAINMENU_PAR'
    AutoUpdateOptions.KeyFields = 'ID_INTERF_MAINMENU_PAR'
    AutoUpdateOptions.GeneratorName = 'GEN_INTERF_MAINMENU_PAR_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 24
    poUseLargeIntField = True
    object TableID_INTERF_MAINMENU_PAR: TFIBLargeIntField
      FieldName = 'ID_INTERF_MAINMENU_PAR'
    end
    object TableIDBASE_INTERF_MAINMENU_PAR: TFIBLargeIntField
      FieldName = 'IDBASE_INTERF_MAINMENU_PAR'
    end
    object TableGID_INTERF_MAINMENU_PAR: TFIBWideStringField
      FieldName = 'GID_INTERF_MAINMENU_PAR'
      Size = 10
    end
    object TableIDMAINMENU_INTERF_MAINMENU_PAR: TFIBLargeIntField
      FieldName = 'IDMAINMENU_INTERF_MAINMENU_PAR'
    end
    object TableNAME_INTERF_MAINMENU_PAR: TFIBWideStringField
      FieldName = 'NAME_INTERF_MAINMENU_PAR'
      Size = 30
    end
    object TableVALUE_INTERF_MAINMENU_PAR: TFIBWideStringField
      FieldName = 'VALUE_INTERF_MAINMENU_PAR'
      Size = 200
    end
    object TableVALUE_TIMESTAMP_MAINMENU_PAR: TFIBDateTimeField
      FieldName = 'VALUE_TIMESTAMP_MAINMENU_PAR'
    end
    object TableTYPE_VALUE_MAINMENU_PAR: TFIBSmallIntField
      FieldName = 'TYPE_VALUE_MAINMENU_PAR'
    end
    object TableTYPE_PAR_INTERF_MAINMENU_PAR: TFIBIntegerField
      FieldName = 'TYPE_PAR_INTERF_MAINMENU_PAR'
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
    Left = 240
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
    Left = 240
    Top = 80
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 48
    Top = 80
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE INTERF_MAINMENU_PAR'
      'SET '
      '    IDBASE_INTERF_MAINMENU_PAR = :IDBASE_INTERF_MAINMENU_PAR,'
      '    GID_INTERF_MAINMENU_PAR = :GID_INTERF_MAINMENU_PAR,'
      
        '    IDMAINMENU_INTERF_MAINMENU_PAR = :IDMAINMENU_INTERF_MAINMENU' +
        '_PAR,'
      '    NAME_INTERF_MAINMENU_PAR = :NAME_INTERF_MAINMENU_PAR,'
      '    VALUE_INTERF_MAINMENU_PAR = :VALUE_INTERF_MAINMENU_PAR,'
      
        '    VALUE_TIMESTAMP_MAINMENU_PAR = :VALUE_TIMESTAMP_MAINMENU_PAR' +
        ','
      '    TYPE_VALUE_MAINMENU_PAR = :TYPE_VALUE_MAINMENU_PAR,'
      '    TYPE_PAR_INTERF_MAINMENU_PAR = :TYPE_PAR_INTERF_MAINMENU_PAR'
      'WHERE'
      '    ID_INTERF_MAINMENU_PAR = :OLD_ID_INTERF_MAINMENU_PAR'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    INTERF_MAINMENU_PAR'
      'WHERE'
      '        ID_INTERF_MAINMENU_PAR = :OLD_ID_INTERF_MAINMENU_PAR'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO INTERF_MAINMENU_PAR('
      '    ID_INTERF_MAINMENU_PAR,'
      '    IDBASE_INTERF_MAINMENU_PAR,'
      '    GID_INTERF_MAINMENU_PAR,'
      '    IDMAINMENU_INTERF_MAINMENU_PAR,'
      '    NAME_INTERF_MAINMENU_PAR,'
      '    VALUE_INTERF_MAINMENU_PAR,'
      '    VALUE_TIMESTAMP_MAINMENU_PAR,'
      '    TYPE_VALUE_MAINMENU_PAR,'
      '    TYPE_PAR_INTERF_MAINMENU_PAR'
      ')'
      'VALUES('
      '    :ID_INTERF_MAINMENU_PAR,'
      '    :IDBASE_INTERF_MAINMENU_PAR,'
      '    :GID_INTERF_MAINMENU_PAR,'
      '    :IDMAINMENU_INTERF_MAINMENU_PAR,'
      '    :NAME_INTERF_MAINMENU_PAR,'
      '    :VALUE_INTERF_MAINMENU_PAR,'
      '    :VALUE_TIMESTAMP_MAINMENU_PAR,'
      '    :TYPE_VALUE_MAINMENU_PAR,'
      '    :TYPE_PAR_INTERF_MAINMENU_PAR'
      ')')
    RefreshSQL.Strings = (
      'select interf_mainmenu_par.*'
      'from interf_mainmenu_par'
      'where(  interf_mainmenu_par.id_interf_mainmenu_par=:PARAM_ID'
      
        '     ) and (     INTERF_MAINMENU_PAR.ID_INTERF_MAINMENU_PAR = :O' +
        'LD_ID_INTERF_MAINMENU_PAR'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select interf_mainmenu_par.*'
      'from interf_mainmenu_par'
      'where interf_mainmenu_par.id_interf_mainmenu_par=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'INTERF_MAINMENU_PAR'
    AutoUpdateOptions.KeyFields = 'ID_INTERF_MAINMENU_PAR'
    AutoUpdateOptions.GeneratorName = 'GEN_INTERF_MAINMENU_PAR_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 80
    poUseLargeIntField = True
    object ElementID_INTERF_MAINMENU_PAR: TFIBLargeIntField
      FieldName = 'ID_INTERF_MAINMENU_PAR'
    end
    object ElementIDBASE_INTERF_MAINMENU_PAR: TFIBLargeIntField
      FieldName = 'IDBASE_INTERF_MAINMENU_PAR'
    end
    object ElementGID_INTERF_MAINMENU_PAR: TFIBWideStringField
      FieldName = 'GID_INTERF_MAINMENU_PAR'
      Size = 10
    end
    object ElementIDMAINMENU_INTERF_MAINMENU_PAR: TFIBLargeIntField
      FieldName = 'IDMAINMENU_INTERF_MAINMENU_PAR'
    end
    object ElementNAME_INTERF_MAINMENU_PAR: TFIBWideStringField
      FieldName = 'NAME_INTERF_MAINMENU_PAR'
      Size = 30
    end
    object ElementVALUE_INTERF_MAINMENU_PAR: TFIBWideStringField
      FieldName = 'VALUE_INTERF_MAINMENU_PAR'
      Size = 200
    end
    object ElementVALUE_TIMESTAMP_MAINMENU_PAR: TFIBDateTimeField
      FieldName = 'VALUE_TIMESTAMP_MAINMENU_PAR'
    end
    object ElementTYPE_VALUE_MAINMENU_PAR: TFIBSmallIntField
      FieldName = 'TYPE_VALUE_MAINMENU_PAR'
    end
    object ElementTYPE_PAR_INTERF_MAINMENU_PAR: TFIBIntegerField
      FieldName = 'TYPE_PAR_INTERF_MAINMENU_PAR'
    end
  end
end
