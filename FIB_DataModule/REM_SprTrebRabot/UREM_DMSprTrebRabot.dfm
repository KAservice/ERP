object REM_DMSprTrebRabot: TREM_DMSprTrebRabot
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
      '        rem_strebrabot.*,'
      '        rem_styprabot.name_rem_styprabot'
      'from rem_strebrabot'
      
        'left outer join rem_styprabot on rem_strebrabot.idtyprabot_rem_s' +
        'trebrabot=rem_styprabot.id_rem_styprabot'
      'where rem_strebrabot.iddmn_rem_strebrabot=:PARAM_IDDMN'
      'order by rem_strebrabot.name_rem_strebrabot')
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
    object TableID_REM_STREBRABOT: TFIBLargeIntField
      FieldName = 'ID_REM_STREBRABOT'
    end
    object TableGID_REM_STREBRABOT: TFIBWideStringField
      FieldName = 'GID_REM_STREBRABOT'
      Size = 10
    end
    object TableIDBASE_REM_STREBRABOT: TFIBLargeIntField
      FieldName = 'IDBASE_REM_STREBRABOT'
    end
    object TableIDDMN_REM_STREBRABOT: TFIBLargeIntField
      FieldName = 'IDDMN_REM_STREBRABOT'
    end
    object TableIDTYPRABOT_REM_STREBRABOT: TFIBLargeIntField
      FieldName = 'IDTYPRABOT_REM_STREBRABOT'
    end
    object TableNAME_REM_STREBRABOT: TFIBWideStringField
      FieldName = 'NAME_REM_STREBRABOT'
      Size = 200
    end
    object TableNAME_REM_STYPRABOT: TFIBWideStringField
      FieldName = 'NAME_REM_STYPRABOT'
      Size = 200
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_STREBRABOT'
      'SET '
      '    GID_REM_STREBRABOT = :GID_REM_STREBRABOT,'
      '    IDBASE_REM_STREBRABOT = :IDBASE_REM_STREBRABOT,'
      '    IDDMN_REM_STREBRABOT = :IDDMN_REM_STREBRABOT,'
      '    IDTYPRABOT_REM_STREBRABOT = :IDTYPRABOT_REM_STREBRABOT,'
      '    NAME_REM_STREBRABOT = :NAME_REM_STREBRABOT'
      'WHERE'
      '    ID_REM_STREBRABOT = :OLD_ID_REM_STREBRABOT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_STREBRABOT'
      'WHERE'
      '        ID_REM_STREBRABOT = :OLD_ID_REM_STREBRABOT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_STREBRABOT('
      '    ID_REM_STREBRABOT,'
      '    GID_REM_STREBRABOT,'
      '    IDBASE_REM_STREBRABOT,'
      '    IDDMN_REM_STREBRABOT,'
      '    IDTYPRABOT_REM_STREBRABOT,'
      '    NAME_REM_STREBRABOT'
      ')'
      'VALUES('
      '    :ID_REM_STREBRABOT,'
      '    :GID_REM_STREBRABOT,'
      '    :IDBASE_REM_STREBRABOT,'
      '    :IDDMN_REM_STREBRABOT,'
      '    :IDTYPRABOT_REM_STREBRABOT,'
      '    :NAME_REM_STREBRABOT'
      ')')
    RefreshSQL.Strings = (
      'select'
      '        rem_strebrabot.*,'
      '        rem_styprabot.name_rem_styprabot'
      'from rem_strebrabot'
      
        'left outer join rem_styprabot on rem_strebrabot.idtyprabot_rem_s' +
        'trebrabot=rem_styprabot.id_rem_styprabot'
      'where(  rem_strebrabot.id_rem_strebrabot=:PARAM_ID'
      
        '     ) and (     REM_STREBRABOT.ID_REM_STREBRABOT = :OLD_ID_REM_' +
        'STREBRABOT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select'
      '        rem_strebrabot.*,'
      '        rem_styprabot.name_rem_styprabot'
      'from rem_strebrabot'
      
        'left outer join rem_styprabot on rem_strebrabot.idtyprabot_rem_s' +
        'trebrabot=rem_styprabot.id_rem_styprabot'
      'where rem_strebrabot.id_rem_strebrabot=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_STREBRABOT'
    AutoUpdateOptions.KeyFields = 'ID_REM_STREBRABOT'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_STREBRABOT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 80
    poUseLargeIntField = True
    object ElementID_REM_STREBRABOT: TFIBLargeIntField
      FieldName = 'ID_REM_STREBRABOT'
    end
    object ElementGID_REM_STREBRABOT: TFIBWideStringField
      FieldName = 'GID_REM_STREBRABOT'
      Size = 10
    end
    object ElementIDBASE_REM_STREBRABOT: TFIBLargeIntField
      FieldName = 'IDBASE_REM_STREBRABOT'
    end
    object ElementIDDMN_REM_STREBRABOT: TFIBLargeIntField
      FieldName = 'IDDMN_REM_STREBRABOT'
    end
    object ElementIDTYPRABOT_REM_STREBRABOT: TFIBLargeIntField
      FieldName = 'IDTYPRABOT_REM_STREBRABOT'
    end
    object ElementNAME_REM_STREBRABOT: TFIBWideStringField
      FieldName = 'NAME_REM_STREBRABOT'
      Size = 200
    end
    object ElementNAME_REM_STYPRABOT: TFIBWideStringField
      FieldName = 'NAME_REM_STYPRABOT'
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
    Left = 344
    Top = 80
    qoStartTransaction = True
  end
end
