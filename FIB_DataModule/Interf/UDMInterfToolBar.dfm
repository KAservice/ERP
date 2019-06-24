object DMInterfToolBar: TDMInterfToolBar
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 270
  Width = 452
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE INTERF_TOOLBAR'
      'SET '
      '    IDBASE_INTERF_TOOLBAR = :IDBASE_INTERF_TOOLBAR,'
      '    NAME_INTERF_TOOLBAR = :NAME_INTERF_TOOLBAR,'
      '    IDGRPUSER_INTERF_TOOLBAR = :IDGRPUSER_INTERF_TOOLBAR,'
      '    APPLICATION_INTERF_TOOLBAR = :APPLICATION_INTERF_TOOLBAR,'
      '    MODUL_INTERF_TOOLBAR = :MODUL_INTERF_TOOLBAR,'
      '    HINT_INTERF_TOOLBAR = :HINT_INTERF_TOOLBAR,'
      '    IMAGEINDEX_INTERF_TOOLBAR = :IMAGEINDEX_INTERF_TOOLBAR,'
      '    INDEX_INTERF_TOOLBAR = :INDEX_INTERF_TOOLBAR,'
      '    GUID_INTERF_TOOLBAR = :GUID_INTERF_TOOLBAR,'
      '    GUIDMOD_INTERF_TOOLBAR = :GUIDMOD_INTERF_TOOLBAR,'
      '    IDMOD_INTERF_TOOLBAR = :IDMOD_INTERF_TOOLBAR,'
      '    FL_UPD_FORM_INTERF_TOOLBAR = :FL_UPD_FORM_INTERF_TOOLBAR,'
      '    IDEL_INTERF_TOOLBAR = :IDEL_INTERF_TOOLBAR,'
      '    FL_OPEN_EL_INTERF_TOOLBAR = :FL_OPEN_EL_INTERF_TOOLBAR,'
      '    TYPE_IDEL_INTERF_TOOLBAR = :TYPE_IDEL_INTERF_TOOLBAR'
      'WHERE'
      '    ID_INTERF_TOOLBAR = :OLD_ID_INTERF_TOOLBAR'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    INTERF_TOOLBAR'
      'WHERE'
      '        ID_INTERF_TOOLBAR = :OLD_ID_INTERF_TOOLBAR'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO INTERF_TOOLBAR('
      '    ID_INTERF_TOOLBAR,'
      '    IDBASE_INTERF_TOOLBAR,'
      '    NAME_INTERF_TOOLBAR,'
      '    IDGRPUSER_INTERF_TOOLBAR,'
      '    APPLICATION_INTERF_TOOLBAR,'
      '    MODUL_INTERF_TOOLBAR,'
      '    HINT_INTERF_TOOLBAR,'
      '    IMAGEINDEX_INTERF_TOOLBAR,'
      '    INDEX_INTERF_TOOLBAR,'
      '    GUID_INTERF_TOOLBAR,'
      '    GUIDMOD_INTERF_TOOLBAR,'
      '    IDMOD_INTERF_TOOLBAR,'
      '    FL_UPD_FORM_INTERF_TOOLBAR,'
      '    IDEL_INTERF_TOOLBAR,'
      '    FL_OPEN_EL_INTERF_TOOLBAR,'
      '    TYPE_IDEL_INTERF_TOOLBAR'
      ')'
      'VALUES('
      '    :ID_INTERF_TOOLBAR,'
      '    :IDBASE_INTERF_TOOLBAR,'
      '    :NAME_INTERF_TOOLBAR,'
      '    :IDGRPUSER_INTERF_TOOLBAR,'
      '    :APPLICATION_INTERF_TOOLBAR,'
      '    :MODUL_INTERF_TOOLBAR,'
      '    :HINT_INTERF_TOOLBAR,'
      '    :IMAGEINDEX_INTERF_TOOLBAR,'
      '    :INDEX_INTERF_TOOLBAR,'
      '    :GUID_INTERF_TOOLBAR,'
      '    :GUIDMOD_INTERF_TOOLBAR,'
      '    :IDMOD_INTERF_TOOLBAR,'
      '    :FL_UPD_FORM_INTERF_TOOLBAR,'
      '    :IDEL_INTERF_TOOLBAR,'
      '    :FL_OPEN_EL_INTERF_TOOLBAR,'
      '    :TYPE_IDEL_INTERF_TOOLBAR'
      ')')
    RefreshSQL.Strings = (
      'select interf_toolbar.*,'
      '    program_module.name_program_module,'
      '    program_module.progid_program_module,'
      '    program_module.patch_program_module'
      'from interf_toolbar'
      
        'left outer join program_module on interf_toolbar.guid_interf_too' +
        'lbar=program_module.guid_program_module'
      'where( '
      ' interf_toolbar.idgrpuser_interf_toolbar=:PARAM_IDGRP_USER'
      
        ' and interf_toolbar.application_interf_toolbar=:PARAM_APPLICATIO' +
        'N'
      
        '     ) and (     INTERF_TOOLBAR.ID_INTERF_TOOLBAR = :OLD_ID_INTE' +
        'RF_TOOLBAR'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select interf_toolbar.*,'
      '    program_module.name_program_module,'
      '    program_module.progid_program_module,'
      '    program_module.patch_program_module,'
      '         program_module.typemod_program_module'
      'from interf_toolbar'
      
        'left outer join program_module on interf_toolbar.idmod_interf_to' +
        'olbar=program_module.id_program_module'
      'where'
      ' interf_toolbar.idgrpuser_interf_toolbar=:PARAM_IDGRP_USER'
      
        ' and interf_toolbar.application_interf_toolbar=:PARAM_APPLICATIO' +
        'N'
      'order by interf_toolbar.index_interf_toolbar desc')
    AutoUpdateOptions.UpdateTableName = 'INTERF_TOOLBAR'
    AutoUpdateOptions.KeyFields = 'ID_INTERF_TOOLBAR'
    AutoUpdateOptions.GeneratorName = 'GEN_INTERF_TOOLBAR_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnCalcFields = TableCalcFields
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 136
    Top = 16
    poUseGuidField = True
    poUseLargeIntField = True
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_INTERF_TOOLBAR: TFIBLargeIntField
      FieldName = 'ID_INTERF_TOOLBAR'
    end
    object TableIDBASE_INTERF_TOOLBAR: TFIBLargeIntField
      FieldName = 'IDBASE_INTERF_TOOLBAR'
    end
    object TableNAME_INTERF_TOOLBAR: TFIBWideStringField
      FieldName = 'NAME_INTERF_TOOLBAR'
      Size = 40
    end
    object TableIDGRPUSER_INTERF_TOOLBAR: TFIBLargeIntField
      FieldName = 'IDGRPUSER_INTERF_TOOLBAR'
    end
    object TableAPPLICATION_INTERF_TOOLBAR: TFIBIntegerField
      FieldName = 'APPLICATION_INTERF_TOOLBAR'
    end
    object TableMODUL_INTERF_TOOLBAR: TFIBIntegerField
      FieldName = 'MODUL_INTERF_TOOLBAR'
    end
    object TableHINT_INTERF_TOOLBAR: TFIBWideStringField
      FieldName = 'HINT_INTERF_TOOLBAR'
      Size = 150
    end
    object TableIMAGEINDEX_INTERF_TOOLBAR: TFIBIntegerField
      FieldName = 'IMAGEINDEX_INTERF_TOOLBAR'
    end
    object TableINDEX_INTERF_TOOLBAR: TFIBIntegerField
      FieldName = 'INDEX_INTERF_TOOLBAR'
    end
    object TableNAME_PROGRAM_MODULE: TFIBWideStringField
      FieldName = 'NAME_PROGRAM_MODULE'
      Size = 200
    end
    object TablePROGID_PROGRAM_MODULE: TFIBWideStringField
      FieldName = 'PROGID_PROGRAM_MODULE'
      Size = 38
    end
    object TablePATCH_PROGRAM_MODULE: TFIBWideStringField
      FieldName = 'PATCH_PROGRAM_MODULE'
      Size = 200
    end
    object TableGUIDMOD_INTERF_TOOLBAR: TFIBWideStringField
      FieldName = 'GUIDMOD_INTERF_TOOLBAR'
      Size = 38
    end
    object TableIDMOD_INTERF_TOOLBAR: TFIBLargeIntField
      FieldName = 'IDMOD_INTERF_TOOLBAR'
    end
    object TableFL_UPD_FORM_INTERF_TOOLBAR: TFIBSmallIntField
      FieldName = 'FL_UPD_FORM_INTERF_TOOLBAR'
    end
    object TableIDEL_INTERF_TOOLBAR: TFIBLargeIntField
      FieldName = 'IDEL_INTERF_TOOLBAR'
    end
    object TableFL_OPEN_EL_INTERF_TOOLBAR: TFIBSmallIntField
      FieldName = 'FL_OPEN_EL_INTERF_TOOLBAR'
    end
    object TableTYPE_IDEL_INTERF_TOOLBAR: TFIBIntegerField
      FieldName = 'TYPE_IDEL_INTERF_TOOLBAR'
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
    Left = 224
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
    Left = 224
    Top = 80
  end
  object Element: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE INTERF_TOOLBAR'
      'SET '
      '    IDBASE_INTERF_TOOLBAR = :IDBASE_INTERF_TOOLBAR,'
      '    NAME_INTERF_TOOLBAR = :NAME_INTERF_TOOLBAR,'
      '    IDGRPUSER_INTERF_TOOLBAR = :IDGRPUSER_INTERF_TOOLBAR,'
      '    APPLICATION_INTERF_TOOLBAR = :APPLICATION_INTERF_TOOLBAR,'
      '    MODUL_INTERF_TOOLBAR = :MODUL_INTERF_TOOLBAR,'
      '    HINT_INTERF_TOOLBAR = :HINT_INTERF_TOOLBAR,'
      '    IMAGEINDEX_INTERF_TOOLBAR = :IMAGEINDEX_INTERF_TOOLBAR,'
      '    INDEX_INTERF_TOOLBAR = :INDEX_INTERF_TOOLBAR,'
      '    GUID_INTERF_TOOLBAR = :GUID_INTERF_TOOLBAR,'
      '    GUIDMOD_INTERF_TOOLBAR = :GUIDMOD_INTERF_TOOLBAR,'
      '    IDMOD_INTERF_TOOLBAR = :IDMOD_INTERF_TOOLBAR,'
      '    FL_UPD_FORM_INTERF_TOOLBAR = :FL_UPD_FORM_INTERF_TOOLBAR,'
      '    IDEL_INTERF_TOOLBAR = :IDEL_INTERF_TOOLBAR,'
      '    FL_OPEN_EL_INTERF_TOOLBAR = :FL_OPEN_EL_INTERF_TOOLBAR,'
      '    TYPE_IDEL_INTERF_TOOLBAR = :TYPE_IDEL_INTERF_TOOLBAR'
      'WHERE'
      '    ID_INTERF_TOOLBAR = :OLD_ID_INTERF_TOOLBAR'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    INTERF_TOOLBAR'
      'WHERE'
      '        ID_INTERF_TOOLBAR = :OLD_ID_INTERF_TOOLBAR'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO INTERF_TOOLBAR('
      '    ID_INTERF_TOOLBAR,'
      '    IDBASE_INTERF_TOOLBAR,'
      '    NAME_INTERF_TOOLBAR,'
      '    IDGRPUSER_INTERF_TOOLBAR,'
      '    APPLICATION_INTERF_TOOLBAR,'
      '    MODUL_INTERF_TOOLBAR,'
      '    HINT_INTERF_TOOLBAR,'
      '    IMAGEINDEX_INTERF_TOOLBAR,'
      '    INDEX_INTERF_TOOLBAR,'
      '    GUID_INTERF_TOOLBAR,'
      '    GUIDMOD_INTERF_TOOLBAR,'
      '    IDMOD_INTERF_TOOLBAR,'
      '    FL_UPD_FORM_INTERF_TOOLBAR,'
      '    IDEL_INTERF_TOOLBAR,'
      '    FL_OPEN_EL_INTERF_TOOLBAR,'
      '    TYPE_IDEL_INTERF_TOOLBAR'
      ')'
      'VALUES('
      '    :ID_INTERF_TOOLBAR,'
      '    :IDBASE_INTERF_TOOLBAR,'
      '    :NAME_INTERF_TOOLBAR,'
      '    :IDGRPUSER_INTERF_TOOLBAR,'
      '    :APPLICATION_INTERF_TOOLBAR,'
      '    :MODUL_INTERF_TOOLBAR,'
      '    :HINT_INTERF_TOOLBAR,'
      '    :IMAGEINDEX_INTERF_TOOLBAR,'
      '    :INDEX_INTERF_TOOLBAR,'
      '    :GUID_INTERF_TOOLBAR,'
      '    :GUIDMOD_INTERF_TOOLBAR,'
      '    :IDMOD_INTERF_TOOLBAR,'
      '    :FL_UPD_FORM_INTERF_TOOLBAR,'
      '    :IDEL_INTERF_TOOLBAR,'
      '    :FL_OPEN_EL_INTERF_TOOLBAR,'
      '    :TYPE_IDEL_INTERF_TOOLBAR'
      ')')
    RefreshSQL.Strings = (
      'select interf_toolbar.*,'
      '    program_module.name_program_module,'
      '    program_module.progid_program_module,'
      '    program_module.patch_program_module,'
      '    program_module.typemod_program_module'
      'from interf_toolbar'
      
        'left outer join program_module on interf_toolbar.idmod_interf_to' +
        'olbar=program_module.id_program_module'
      'where( '
      ' interf_toolbar.id_interf_toolbar=:PARAM_ID'
      
        '     ) and (     INTERF_TOOLBAR.ID_INTERF_TOOLBAR = :OLD_ID_INTE' +
        'RF_TOOLBAR'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select interf_toolbar.*,'
      '    program_module.name_program_module,'
      '    program_module.progid_program_module,'
      '    program_module.patch_program_module,'
      '    program_module.typemod_program_module'
      'from interf_toolbar'
      
        'left outer join program_module on interf_toolbar.idmod_interf_to' +
        'olbar=program_module.id_program_module'
      'where'
      ' interf_toolbar.id_interf_toolbar=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'INTERF_TOOLBAR'
    AutoUpdateOptions.KeyFields = 'ID_INTERF_TOOLBAR'
    AutoUpdateOptions.GeneratorName = 'GEN_INTERF_TOOLBAR_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 136
    Top = 80
    poUseGuidField = True
    poUseLargeIntField = True
    object ElementID_INTERF_TOOLBAR: TFIBLargeIntField
      FieldName = 'ID_INTERF_TOOLBAR'
    end
    object ElementIDBASE_INTERF_TOOLBAR: TFIBLargeIntField
      FieldName = 'IDBASE_INTERF_TOOLBAR'
    end
    object ElementNAME_INTERF_TOOLBAR: TFIBWideStringField
      FieldName = 'NAME_INTERF_TOOLBAR'
      Size = 40
    end
    object ElementIDGRPUSER_INTERF_TOOLBAR: TFIBLargeIntField
      FieldName = 'IDGRPUSER_INTERF_TOOLBAR'
    end
    object ElementAPPLICATION_INTERF_TOOLBAR: TFIBIntegerField
      FieldName = 'APPLICATION_INTERF_TOOLBAR'
    end
    object ElementMODUL_INTERF_TOOLBAR: TFIBIntegerField
      FieldName = 'MODUL_INTERF_TOOLBAR'
    end
    object ElementHINT_INTERF_TOOLBAR: TFIBWideStringField
      FieldName = 'HINT_INTERF_TOOLBAR'
      Size = 150
    end
    object ElementIMAGEINDEX_INTERF_TOOLBAR: TFIBIntegerField
      FieldName = 'IMAGEINDEX_INTERF_TOOLBAR'
    end
    object ElementINDEX_INTERF_TOOLBAR: TFIBIntegerField
      FieldName = 'INDEX_INTERF_TOOLBAR'
    end
    object ElementNAME_PROGRAM_MODULE: TFIBWideStringField
      FieldName = 'NAME_PROGRAM_MODULE'
      Size = 200
    end
    object ElementPROGID_PROGRAM_MODULE: TFIBWideStringField
      FieldName = 'PROGID_PROGRAM_MODULE'
      Size = 38
    end
    object ElementPATCH_PROGRAM_MODULE: TFIBWideStringField
      FieldName = 'PATCH_PROGRAM_MODULE'
      Size = 200
    end
    object ElementGUIDMOD_INTERF_TOOLBAR: TFIBWideStringField
      FieldName = 'GUIDMOD_INTERF_TOOLBAR'
      Size = 38
    end
    object ElementIDMOD_INTERF_TOOLBAR: TFIBLargeIntField
      FieldName = 'IDMOD_INTERF_TOOLBAR'
    end
    object ElementFL_UPD_FORM_INTERF_TOOLBAR: TFIBSmallIntField
      FieldName = 'FL_UPD_FORM_INTERF_TOOLBAR'
    end
    object ElementIDEL_INTERF_TOOLBAR: TFIBLargeIntField
      FieldName = 'IDEL_INTERF_TOOLBAR'
    end
    object ElementFL_OPEN_EL_INTERF_TOOLBAR: TFIBSmallIntField
      FieldName = 'FL_OPEN_EL_INTERF_TOOLBAR'
    end
    object ElementTYPE_IDEL_INTERF_TOOLBAR: TFIBIntegerField
      FieldName = 'TYPE_IDEL_INTERF_TOOLBAR'
    end
    object ElementTYPEMOD_PROGRAM_MODULE: TFIBIntegerField
      FieldName = 'TYPEMOD_PROGRAM_MODULE'
    end
  end
end
