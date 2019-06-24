object REM_DMSprDefectModelNeispr: TREM_DMSprDefectModelNeispr
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
      '        rem_sdefect_modne.*,'
      '        rem_stypdefect.name_rem_stypdefect,'
      '        rem_stypdefect.code_rem_stypdefect'
      'from rem_sdefect_modne'
      
        'left outer join rem_stypdefect on rem_sdefect_modne.idtdef_rem_s' +
        'defect_modne=rem_stypdefect.id_rem_stypdefect'
      
        'where rem_sdefect_modne.idneismod_rem_sdefect_modne=:PARAM_IDMOD' +
        'ELNEISPR'
      'order by rem_sdefect_modne.name_rem_sdefect_modne')
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
    object TableID_REM_SDEFECT_MODNE: TFIBLargeIntField
      FieldName = 'ID_REM_SDEFECT_MODNE'
    end
    object TableGID_REM_SDEFECT_MODNE: TFIBWideStringField
      FieldName = 'GID_REM_SDEFECT_MODNE'
      Size = 10
    end
    object TableIDBASE_REM_SDEFECT_MODNE: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SDEFECT_MODNE'
    end
    object TableIDNEISMOD_REM_SDEFECT_MODNE: TFIBLargeIntField
      FieldName = 'IDNEISMOD_REM_SDEFECT_MODNE'
    end
    object TableNAME_REM_SDEFECT_MODNE: TFIBWideStringField
      FieldName = 'NAME_REM_SDEFECT_MODNE'
      Size = 200
    end
    object TableDESCR_REM_SDEFECT_MODNE: TFIBWideStringField
      FieldName = 'DESCR_REM_SDEFECT_MODNE'
      Size = 150
    end
    object TableIDTDEF_REM_SDEFECT_MODNE: TFIBLargeIntField
      FieldName = 'IDTDEF_REM_SDEFECT_MODNE'
    end
    object TableNAME_REM_STYPDEFECT: TFIBWideStringField
      FieldName = 'NAME_REM_STYPDEFECT'
      Size = 200
    end
    object TableCODE_REM_STYPDEFECT: TFIBWideStringField
      FieldName = 'CODE_REM_STYPDEFECT'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_SDEFECT_MODNE'
      'SET '
      '    GID_REM_SDEFECT_MODNE = :GID_REM_SDEFECT_MODNE,'
      '    IDBASE_REM_SDEFECT_MODNE = :IDBASE_REM_SDEFECT_MODNE,'
      '    IDNEISMOD_REM_SDEFECT_MODNE = :IDNEISMOD_REM_SDEFECT_MODNE,'
      '    NAME_REM_SDEFECT_MODNE = :NAME_REM_SDEFECT_MODNE,'
      '    DESCR_REM_SDEFECT_MODNE = :DESCR_REM_SDEFECT_MODNE,'
      '    IDTDEF_REM_SDEFECT_MODNE = :IDTDEF_REM_SDEFECT_MODNE'
      'WHERE'
      '    ID_REM_SDEFECT_MODNE = :OLD_ID_REM_SDEFECT_MODNE'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_SDEFECT_MODNE'
      'WHERE'
      '        ID_REM_SDEFECT_MODNE = :OLD_ID_REM_SDEFECT_MODNE'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_SDEFECT_MODNE('
      '    ID_REM_SDEFECT_MODNE,'
      '    GID_REM_SDEFECT_MODNE,'
      '    IDBASE_REM_SDEFECT_MODNE,'
      '    IDNEISMOD_REM_SDEFECT_MODNE,'
      '    NAME_REM_SDEFECT_MODNE,'
      '    DESCR_REM_SDEFECT_MODNE,'
      '    IDTDEF_REM_SDEFECT_MODNE'
      ')'
      'VALUES('
      '    :ID_REM_SDEFECT_MODNE,'
      '    :GID_REM_SDEFECT_MODNE,'
      '    :IDBASE_REM_SDEFECT_MODNE,'
      '    :IDNEISMOD_REM_SDEFECT_MODNE,'
      '    :NAME_REM_SDEFECT_MODNE,'
      '    :DESCR_REM_SDEFECT_MODNE,'
      '    :IDTDEF_REM_SDEFECT_MODNE'
      ')')
    RefreshSQL.Strings = (
      'select'
      '        rem_sdefect_modne.*,'
      '        rem_stypdefect.name_rem_stypdefect,'
      '        rem_stypdefect.code_rem_stypdefect'
      'from rem_sdefect_modne'
      
        'left outer join rem_stypdefect on rem_sdefect_modne.idtdef_rem_s' +
        'defect_modne=rem_stypdefect.id_rem_stypdefect'
      'where(  rem_sdefect_modne.id_rem_sdefect_modne=:PARAM_ID'
      
        '     ) and (     REM_SDEFECT_MODNE.ID_REM_SDEFECT_MODNE = :OLD_I' +
        'D_REM_SDEFECT_MODNE'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select'
      '        rem_sdefect_modne.*,'
      '        rem_stypdefect.name_rem_stypdefect,'
      '        rem_stypdefect.code_rem_stypdefect'
      'from rem_sdefect_modne'
      
        'left outer join rem_stypdefect on rem_sdefect_modne.idtdef_rem_s' +
        'defect_modne=rem_stypdefect.id_rem_stypdefect'
      'where rem_sdefect_modne.id_rem_sdefect_modne=:PARAM_ID'
      'order by rem_sdefect_modne.name_rem_sdefect_modne')
    AutoUpdateOptions.UpdateTableName = 'REM_SDEFECT_MODNE'
    AutoUpdateOptions.KeyFields = 'ID_REM_SDEFECT_MODNE'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SDEFECT_MODNE_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 80
    poUseLargeIntField = True
    object ElementID_REM_SDEFECT_MODNE: TFIBLargeIntField
      FieldName = 'ID_REM_SDEFECT_MODNE'
    end
    object ElementGID_REM_SDEFECT_MODNE: TFIBWideStringField
      FieldName = 'GID_REM_SDEFECT_MODNE'
      Size = 10
    end
    object ElementIDBASE_REM_SDEFECT_MODNE: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SDEFECT_MODNE'
    end
    object ElementIDNEISMOD_REM_SDEFECT_MODNE: TFIBLargeIntField
      FieldName = 'IDNEISMOD_REM_SDEFECT_MODNE'
    end
    object ElementNAME_REM_SDEFECT_MODNE: TFIBWideStringField
      FieldName = 'NAME_REM_SDEFECT_MODNE'
      Size = 200
    end
    object ElementDESCR_REM_SDEFECT_MODNE: TFIBWideStringField
      FieldName = 'DESCR_REM_SDEFECT_MODNE'
      Size = 150
    end
    object ElementIDTDEF_REM_SDEFECT_MODNE: TFIBLargeIntField
      FieldName = 'IDTDEF_REM_SDEFECT_MODNE'
    end
    object ElementNAME_REM_STYPDEFECT: TFIBWideStringField
      FieldName = 'NAME_REM_STYPDEFECT'
      Size = 200
    end
    object ElementCODE_REM_STYPDEFECT: TFIBWideStringField
      FieldName = 'CODE_REM_STYPDEFECT'
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
    Left = 344
    Top = 80
    qoStartTransaction = True
  end
end
