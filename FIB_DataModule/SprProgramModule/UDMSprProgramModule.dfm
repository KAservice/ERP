object DMSprProgramModule: TDMSprProgramModule
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 265
  Width = 484
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 64
    Top = 24
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 64
    Top = 80
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select * '
      'from '
      '  PROGRAM_MODULE')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 168
    Top = 24
    poUseGuidField = True
    poUseLargeIntField = True
    object TableID_PROGRAM_MODULE: TFIBLargeIntField
      FieldName = 'ID_PROGRAM_MODULE'
    end
    object TableNAME_PROGRAM_MODULE: TFIBWideStringField
      FieldName = 'NAME_PROGRAM_MODULE'
      Size = 200
    end
    object TablePROGID_PROGRAM_MODULE: TFIBWideStringField
      FieldName = 'PROGID_PROGRAM_MODULE'
      Size = 38
    end
    object TableMODULE_PROGRAM_MODULE: TFIBWideStringField
      FieldName = 'MODULE_PROGRAM_MODULE'
      Size = 40
    end
    object TableDESCR_PROGRAM_MODULE: TFIBWideStringField
      FieldName = 'DESCR_PROGRAM_MODULE'
      Size = 150
    end
    object TablePATCH_PROGRAM_MODULE: TFIBWideStringField
      FieldName = 'PATCH_PROGRAM_MODULE'
      Size = 200
    end
    object TableIDBASE_PROGRAM_MODULE: TFIBLargeIntField
      FieldName = 'IDBASE_PROGRAM_MODULE'
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableGUID_PROGRAM_MODULE: TFIBWideStringField
      FieldName = 'GUID_PROGRAM_MODULE'
      Size = 38
    end
    object TableTYPEMOD_PROGRAM_MODULE: TFIBIntegerField
      FieldName = 'TYPEMOD_PROGRAM_MODULE'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE PROGRAM_MODULE'
      'SET '
      '    GUID_PROGRAM_MODULE = :GUID_PROGRAM_MODULE,'
      '    NAME_PROGRAM_MODULE = :NAME_PROGRAM_MODULE,'
      '    PROGID_PROGRAM_MODULE = :PROGID_PROGRAM_MODULE,'
      '    MODULE_PROGRAM_MODULE = :MODULE_PROGRAM_MODULE,'
      '    DESCR_PROGRAM_MODULE = :DESCR_PROGRAM_MODULE,'
      '    PATCH_PROGRAM_MODULE = :PATCH_PROGRAM_MODULE,'
      '    IDBASE_PROGRAM_MODULE = :IDBASE_PROGRAM_MODULE,'
      '    TYPEMOD_PROGRAM_MODULE = :TYPEMOD_PROGRAM_MODULE'
      'WHERE'
      '    ID_PROGRAM_MODULE = :OLD_ID_PROGRAM_MODULE'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    PROGRAM_MODULE'
      'WHERE'
      '        ID_PROGRAM_MODULE = :OLD_ID_PROGRAM_MODULE'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO PROGRAM_MODULE('
      '    ID_PROGRAM_MODULE,'
      '    GUID_PROGRAM_MODULE,'
      '    NAME_PROGRAM_MODULE,'
      '    PROGID_PROGRAM_MODULE,'
      '    MODULE_PROGRAM_MODULE,'
      '    DESCR_PROGRAM_MODULE,'
      '    PATCH_PROGRAM_MODULE,'
      '    IDBASE_PROGRAM_MODULE,'
      '    TYPEMOD_PROGRAM_MODULE'
      ')'
      'VALUES('
      '    :ID_PROGRAM_MODULE,'
      '    :GUID_PROGRAM_MODULE,'
      '    :NAME_PROGRAM_MODULE,'
      '    :PROGID_PROGRAM_MODULE,'
      '    :MODULE_PROGRAM_MODULE,'
      '    :DESCR_PROGRAM_MODULE,'
      '    :PATCH_PROGRAM_MODULE,'
      '    :IDBASE_PROGRAM_MODULE,'
      '    :TYPEMOD_PROGRAM_MODULE'
      ')')
    RefreshSQL.Strings = (
      'select program_module.*'
      'from program_module'
      'where(  program_module.id_program_module=:PARAM_ID'
      
        '     ) and (     PROGRAM_MODULE.ID_PROGRAM_MODULE = :OLD_ID_PROG' +
        'RAM_MODULE'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select program_module.*'
      'from program_module'
      'where program_module.id_program_module=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SSCALE'
    AutoUpdateOptions.KeyFields = 'ID_SSCALE'
    AutoUpdateOptions.GeneratorName = 'GEN_SSCALE_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 80
    poUseGuidField = True
    poUseLargeIntField = True
    object ElementID_PROGRAM_MODULE: TFIBLargeIntField
      FieldName = 'ID_PROGRAM_MODULE'
    end
    object ElementNAME_PROGRAM_MODULE: TFIBWideStringField
      FieldName = 'NAME_PROGRAM_MODULE'
      Size = 200
    end
    object ElementPROGID_PROGRAM_MODULE: TFIBWideStringField
      FieldName = 'PROGID_PROGRAM_MODULE'
      Size = 38
    end
    object ElementMODULE_PROGRAM_MODULE: TFIBWideStringField
      FieldName = 'MODULE_PROGRAM_MODULE'
      Size = 40
    end
    object ElementDESCR_PROGRAM_MODULE: TFIBWideStringField
      FieldName = 'DESCR_PROGRAM_MODULE'
      Size = 150
    end
    object ElementPATCH_PROGRAM_MODULE: TFIBWideStringField
      FieldName = 'PATCH_PROGRAM_MODULE'
      Size = 200
    end
    object ElementIDBASE_PROGRAM_MODULE: TFIBLargeIntField
      FieldName = 'IDBASE_PROGRAM_MODULE'
    end
    object ElementGUID_PROGRAM_MODULE: TFIBWideStringField
      FieldName = 'GUID_PROGRAM_MODULE'
      Size = 38
    end
    object ElementTYPEMOD_PROGRAM_MODULE: TFIBIntegerField
      FieldName = 'TYPEMOD_PROGRAM_MODULE'
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
    Left = 256
    Top = 80
  end
  object Query: TpFIBQuery
    Transaction = IBTr
    Left = 168
    Top = 144
    qoStartTransaction = True
  end
end
