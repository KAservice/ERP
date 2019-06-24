object REM_DMSprTypRabot: TREM_DMSprTypRabot
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 393
  Width = 458
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 8
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 56
    Top = 64
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select'
      '    rem_styprabot.*,'
      '    snom.namenom,'
      '    snom.artnom,'
      '    snom.codenom'
      'from rem_styprabot'
      
        'left outer join snom on rem_styprabot.idnom_rem_styprabot=snom.i' +
        'dnom'
      'ORDER BY rem_styprabot.name_rem_styprabot')
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
    object TableID_REM_STYPRABOT: TFIBLargeIntField
      FieldName = 'ID_REM_STYPRABOT'
    end
    object TableGID_REM_STYPRABOT: TFIBWideStringField
      FieldName = 'GID_REM_STYPRABOT'
      Size = 10
    end
    object TableIDBASE_REM_STYPRABOT: TFIBLargeIntField
      FieldName = 'IDBASE_REM_STYPRABOT'
    end
    object TableIDGRP_REM_STYPRABOT: TFIBLargeIntField
      FieldName = 'IDGRP_REM_STYPRABOT'
    end
    object TableIDNOM_REM_STYPRABOT: TFIBLargeIntField
      FieldName = 'IDNOM_REM_STYPRABOT'
    end
    object TableNAME_REM_STYPRABOT: TFIBWideStringField
      FieldName = 'NAME_REM_STYPRABOT'
      Size = 200
    end
    object TableDESCR_REM_STYPRABOT: TFIBWideStringField
      FieldName = 'DESCR_REM_STYPRABOT'
      Size = 150
    end
    object TableNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object TableARTNOM: TFIBWideStringField
      FieldName = 'ARTNOM'
      Size = 40
    end
    object TableCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object TableNAME_ENG_REM_STYPRABOT: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_STYPRABOT'
      Size = 200
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_STYPRABOT'
      'SET '
      '    GID_REM_STYPRABOT = :GID_REM_STYPRABOT,'
      '    IDBASE_REM_STYPRABOT = :IDBASE_REM_STYPRABOT,'
      '    IDGRP_REM_STYPRABOT = :IDGRP_REM_STYPRABOT,'
      '    IDNOM_REM_STYPRABOT = :IDNOM_REM_STYPRABOT,'
      '    NAME_REM_STYPRABOT = :NAME_REM_STYPRABOT,'
      '    DESCR_REM_STYPRABOT = :DESCR_REM_STYPRABOT,'
      '    NAME_ENG_REM_STYPRABOT = :NAME_ENG_REM_STYPRABOT'
      'WHERE'
      '    ID_REM_STYPRABOT = :OLD_ID_REM_STYPRABOT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_STYPRABOT'
      'WHERE'
      '        ID_REM_STYPRABOT = :OLD_ID_REM_STYPRABOT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_STYPRABOT('
      '    ID_REM_STYPRABOT,'
      '    GID_REM_STYPRABOT,'
      '    IDBASE_REM_STYPRABOT,'
      '    IDGRP_REM_STYPRABOT,'
      '    IDNOM_REM_STYPRABOT,'
      '    NAME_REM_STYPRABOT,'
      '    DESCR_REM_STYPRABOT,'
      '    NAME_ENG_REM_STYPRABOT'
      ')'
      'VALUES('
      '    :ID_REM_STYPRABOT,'
      '    :GID_REM_STYPRABOT,'
      '    :IDBASE_REM_STYPRABOT,'
      '    :IDGRP_REM_STYPRABOT,'
      '    :IDNOM_REM_STYPRABOT,'
      '    :NAME_REM_STYPRABOT,'
      '    :DESCR_REM_STYPRABOT,'
      '    :NAME_ENG_REM_STYPRABOT'
      ')')
    RefreshSQL.Strings = (
      'select rem_styprabot.*,'
      '        snom.namenom,'
      '        snom.artnom,'
      '        snom.codenom'
      'from rem_styprabot'
      
        'left outer join snom on rem_styprabot.idnom_rem_styprabot=snom.i' +
        'dnom'
      'where(  rem_styprabot.id_rem_styprabot=:PARAM_ID'
      
        '     ) and (     REM_STYPRABOT.ID_REM_STYPRABOT = :OLD_ID_REM_ST' +
        'YPRABOT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_styprabot.*,'
      '        snom.namenom,'
      '        snom.artnom,'
      '        snom.codenom'
      'from rem_styprabot'
      
        'left outer join snom on rem_styprabot.idnom_rem_styprabot=snom.i' +
        'dnom'
      'where rem_styprabot.id_rem_styprabot=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_STYPRABOT'
    AutoUpdateOptions.KeyFields = 'ID_REM_STYPRABOT'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_STYPRABOT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object ElementID_REM_STYPRABOT: TFIBLargeIntField
      FieldName = 'ID_REM_STYPRABOT'
    end
    object ElementGID_REM_STYPRABOT: TFIBWideStringField
      FieldName = 'GID_REM_STYPRABOT'
      Size = 10
    end
    object ElementIDBASE_REM_STYPRABOT: TFIBLargeIntField
      FieldName = 'IDBASE_REM_STYPRABOT'
    end
    object ElementIDGRP_REM_STYPRABOT: TFIBLargeIntField
      FieldName = 'IDGRP_REM_STYPRABOT'
    end
    object ElementIDNOM_REM_STYPRABOT: TFIBLargeIntField
      FieldName = 'IDNOM_REM_STYPRABOT'
    end
    object ElementNAME_REM_STYPRABOT: TFIBWideStringField
      FieldName = 'NAME_REM_STYPRABOT'
      Size = 200
    end
    object ElementDESCR_REM_STYPRABOT: TFIBWideStringField
      FieldName = 'DESCR_REM_STYPRABOT'
      Size = 150
    end
    object ElementNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object ElementARTNOM: TFIBWideStringField
      FieldName = 'ARTNOM'
      Size = 40
    end
    object ElementCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object ElementNAME_ENG_REM_STYPRABOT: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_STYPRABOT'
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
    Left = 256
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
    Left = 256
    Top = 64
  end
  object pFIBQuery: TpFIBQuery
    Left = 256
    Top = 128
    qoStartTransaction = True
  end
end
