object DMInterfMainMenu: TDMInterfMainMenu
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 251
  Width = 382
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE INTERF_MAINMENU'
      'SET '
      '    IDBASE_INTERF_MAINMENU = :IDBASE_INTERF_MAINMENU,'
      '    IDGRP_INTERF_MAINMENU = :IDGRP_INTERF_MAINMENU,'
      '    NAME_INTERF_MAINMENU = :NAME_INTERF_MAINMENU,'
      '    MODUL_INTERF_MAINMENU = :MODUL_INTERF_MAINMENU,'
      '    IDGRPUSER_INTERF_MAINMENU = :IDGRPUSER_INTERF_MAINMENU,'
      '    APPLICATION_INTERF_MAINMENU = :APPLICATION_INTERF_MAINMENU,'
      '    SHORTCUT_INTERF_MAINMENU = :SHORTCUT_INTERF_MAINMENU,'
      '    INDEX_INTERF_MAINMENU = :INDEX_INTERF_MAINMENU,'
      '    GUID_INTERF_MAINMENU = :GUID_INTERF_MAINMENU,'
      '    FL_UPD_FORM_INTERF_MAINMENU = :FL_UPD_FORM_INTERF_MAINMENU,'
      '    FL_NEW_DOC_INTERF_MAINMENU = :FL_NEW_DOC_INTERF_MAINMENU,'
      '    IDEL_INTERF_MAINMENU = :IDEL_INTERF_MAINMENU,'
      '    FL_OPEN_EL_INTERF_MAINMENU = :FL_OPEN_EL_INTERF_MAINMENU,'
      '    GUIDMOD_INTERF_MAINMENU = :GUIDMOD_INTERF_MAINMENU,'
      '    TYPE_IDEL_INTERF_MAINMENU = :TYPE_IDEL_INTERF_MAINMENU,'
      '    IDMOD_INTERF_MAINMENU = :IDMOD_INTERF_MAINMENU'
      'WHERE'
      '    ID_INTERF_MAINMENU = :OLD_ID_INTERF_MAINMENU'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    INTERF_MAINMENU'
      'WHERE'
      '        ID_INTERF_MAINMENU = :OLD_ID_INTERF_MAINMENU'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO INTERF_MAINMENU('
      '    ID_INTERF_MAINMENU,'
      '    IDBASE_INTERF_MAINMENU,'
      '    IDGRP_INTERF_MAINMENU,'
      '    NAME_INTERF_MAINMENU,'
      '    MODUL_INTERF_MAINMENU,'
      '    IDGRPUSER_INTERF_MAINMENU,'
      '    APPLICATION_INTERF_MAINMENU,'
      '    SHORTCUT_INTERF_MAINMENU,'
      '    INDEX_INTERF_MAINMENU,'
      '    GUID_INTERF_MAINMENU,'
      '    FL_UPD_FORM_INTERF_MAINMENU,'
      '    FL_NEW_DOC_INTERF_MAINMENU,'
      '    IDEL_INTERF_MAINMENU,'
      '    FL_OPEN_EL_INTERF_MAINMENU,'
      '    GUIDMOD_INTERF_MAINMENU,'
      '    TYPE_IDEL_INTERF_MAINMENU,'
      '    IDMOD_INTERF_MAINMENU'
      ')'
      'VALUES('
      '    :ID_INTERF_MAINMENU,'
      '    :IDBASE_INTERF_MAINMENU,'
      '    :IDGRP_INTERF_MAINMENU,'
      '    :NAME_INTERF_MAINMENU,'
      '    :MODUL_INTERF_MAINMENU,'
      '    :IDGRPUSER_INTERF_MAINMENU,'
      '    :APPLICATION_INTERF_MAINMENU,'
      '    :SHORTCUT_INTERF_MAINMENU,'
      '    :INDEX_INTERF_MAINMENU,'
      '    :GUID_INTERF_MAINMENU,'
      '    :FL_UPD_FORM_INTERF_MAINMENU,'
      '    :FL_NEW_DOC_INTERF_MAINMENU,'
      '    :IDEL_INTERF_MAINMENU,'
      '    :FL_OPEN_EL_INTERF_MAINMENU,'
      '    :GUIDMOD_INTERF_MAINMENU,'
      '    :TYPE_IDEL_INTERF_MAINMENU,'
      '    :IDMOD_INTERF_MAINMENU'
      ')')
    RefreshSQL.Strings = (
      'select INTERF_MAINMENU.*,'
      '         NAME_SGRPUSER,'
      '         program_module.name_program_module,'
      '         program_module.progid_program_module,'
      '         program_module.patch_program_module,'
      '         program_module.typemod_program_module'
      'from INTERF_MAINMENU'
      
        'left outer join sgrpuser on ID_SGRPUSER=IDGRPUSER_INTERF_MAINMEN' +
        'U'
      
        'left outer join program_module on interf_mainmenu.idmod_interf_m' +
        'ainmenu=program_module.id_program_module'
      'where(  '
      'IDGRP_INTERF_MAINMENU=:PARAM_IDGRP'
      
        '     ) and (     INTERF_MAINMENU.ID_INTERF_MAINMENU = :OLD_ID_IN' +
        'TERF_MAINMENU'
      '     )'
      '    '
      '')
    SelectSQL.Strings = (
      'select interf_toolbar.*,'
      '    program_module.name_program_module,'
      '    program_module.progid_program_module,'
      '    program_module.patch_program_module,'
      '         program_module.typemod_program_module'
      'from interf_toolbar'
      
        'left outer join program_module on interf_toolbar.guid_interf_too' +
        'lbar=program_module.guid_program_module'
      'where'
      ' interf_toolbar.idgrpuser_interf_toolbar=:PARAM_IDGRP_USER'
      
        ' and interf_toolbar.application_interf_toolbar=:PARAM_APPLICATIO' +
        'N'
      'order by interf_toolbar.index_interf_toolbar desc'
      '')
    AutoUpdateOptions.UpdateTableName = 'INTERF_MAINMENU'
    AutoUpdateOptions.KeyFields = 'ID_INTERF_MAINMENU'
    AutoUpdateOptions.GeneratorName = 'GEN_INTERF_MAINMENU_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnCalcFields = TableCalcFields
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 136
    Top = 16
    poUseGuidField = True
    poUseLargeIntField = True
    object TableID_INTERF_MAINMENU: TFIBLargeIntField
      FieldName = 'ID_INTERF_MAINMENU'
    end
    object TableIDBASE_INTERF_MAINMENU: TFIBLargeIntField
      FieldName = 'IDBASE_INTERF_MAINMENU'
    end
    object TableIDGRP_INTERF_MAINMENU: TFIBLargeIntField
      FieldName = 'IDGRP_INTERF_MAINMENU'
    end
    object TableNAME_INTERF_MAINMENU: TFIBWideStringField
      FieldName = 'NAME_INTERF_MAINMENU'
      Size = 40
    end
    object TableMODUL_INTERF_MAINMENU: TFIBIntegerField
      FieldName = 'MODUL_INTERF_MAINMENU'
    end
    object TableIDGRPUSER_INTERF_MAINMENU: TFIBLargeIntField
      FieldName = 'IDGRPUSER_INTERF_MAINMENU'
    end
    object TableAPPLICATION_INTERF_MAINMENU: TFIBIntegerField
      FieldName = 'APPLICATION_INTERF_MAINMENU'
    end
    object TableSHORTCUT_INTERF_MAINMENU: TFIBWideStringField
      FieldName = 'SHORTCUT_INTERF_MAINMENU'
      Size = 10
    end
    object TableINDEX_INTERF_MAINMENU: TFIBIntegerField
      FieldName = 'INDEX_INTERF_MAINMENU'
    end
    object TableNAME_SGRPUSER: TFIBWideStringField
      FieldName = 'NAME_SGRPUSER'
      Size = 200
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
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableFL_UPD_FORM_INTERF_MAINMENU: TFIBSmallIntField
      FieldName = 'FL_UPD_FORM_INTERF_MAINMENU'
    end
    object TableFL_NEW_DOC_INTERF_MAINMENU: TFIBSmallIntField
      FieldName = 'FL_NEW_DOC_INTERF_MAINMENU'
    end
    object TableIDEL_INTERF_MAINMENU: TFIBLargeIntField
      FieldName = 'IDEL_INTERF_MAINMENU'
    end
    object TableFL_OPEN_EL_INTERF_MAINMENU: TFIBSmallIntField
      FieldName = 'FL_OPEN_EL_INTERF_MAINMENU'
    end
    object TableGUIDMOD_INTERF_MAINMENU: TFIBWideStringField
      FieldName = 'GUIDMOD_INTERF_MAINMENU'
      Size = 38
    end
    object TableTYPE_IDEL_INTERF_MAINMENU: TFIBIntegerField
      FieldName = 'TYPE_IDEL_INTERF_MAINMENU'
    end
    object TableIDMOD_INTERF_MAINMENU: TFIBLargeIntField
      FieldName = 'IDMOD_INTERF_MAINMENU'
    end
    object TableTYPEMOD_PROGRAM_MODULE: TFIBIntegerField
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
      'UPDATE INTERF_MAINMENU'
      'SET '
      '    IDBASE_INTERF_MAINMENU = :IDBASE_INTERF_MAINMENU,'
      '    IDGRP_INTERF_MAINMENU = :IDGRP_INTERF_MAINMENU,'
      '    NAME_INTERF_MAINMENU = :NAME_INTERF_MAINMENU,'
      '    MODUL_INTERF_MAINMENU = :MODUL_INTERF_MAINMENU,'
      '    IDGRPUSER_INTERF_MAINMENU = :IDGRPUSER_INTERF_MAINMENU,'
      '    APPLICATION_INTERF_MAINMENU = :APPLICATION_INTERF_MAINMENU,'
      '    SHORTCUT_INTERF_MAINMENU = :SHORTCUT_INTERF_MAINMENU,'
      '    INDEX_INTERF_MAINMENU = :INDEX_INTERF_MAINMENU,'
      '    GUID_INTERF_MAINMENU = :GUID_INTERF_MAINMENU,'
      '    FL_UPD_FORM_INTERF_MAINMENU = :FL_UPD_FORM_INTERF_MAINMENU,'
      '    FL_NEW_DOC_INTERF_MAINMENU = :FL_NEW_DOC_INTERF_MAINMENU,'
      '    IDEL_INTERF_MAINMENU = :IDEL_INTERF_MAINMENU,'
      '    FL_OPEN_EL_INTERF_MAINMENU = :FL_OPEN_EL_INTERF_MAINMENU,'
      '    GUIDMOD_INTERF_MAINMENU = :GUIDMOD_INTERF_MAINMENU,'
      '    TYPE_IDEL_INTERF_MAINMENU = :TYPE_IDEL_INTERF_MAINMENU,'
      '    IDMOD_INTERF_MAINMENU = :IDMOD_INTERF_MAINMENU'
      'WHERE'
      '    ID_INTERF_MAINMENU = :OLD_ID_INTERF_MAINMENU'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    INTERF_MAINMENU'
      'WHERE'
      '        ID_INTERF_MAINMENU = :OLD_ID_INTERF_MAINMENU'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO INTERF_MAINMENU('
      '    ID_INTERF_MAINMENU,'
      '    IDBASE_INTERF_MAINMENU,'
      '    IDGRP_INTERF_MAINMENU,'
      '    NAME_INTERF_MAINMENU,'
      '    MODUL_INTERF_MAINMENU,'
      '    IDGRPUSER_INTERF_MAINMENU,'
      '    APPLICATION_INTERF_MAINMENU,'
      '    SHORTCUT_INTERF_MAINMENU,'
      '    INDEX_INTERF_MAINMENU,'
      '    GUID_INTERF_MAINMENU,'
      '    FL_UPD_FORM_INTERF_MAINMENU,'
      '    FL_NEW_DOC_INTERF_MAINMENU,'
      '    IDEL_INTERF_MAINMENU,'
      '    FL_OPEN_EL_INTERF_MAINMENU,'
      '    GUIDMOD_INTERF_MAINMENU,'
      '    TYPE_IDEL_INTERF_MAINMENU,'
      '    IDMOD_INTERF_MAINMENU'
      ')'
      'VALUES('
      '    :ID_INTERF_MAINMENU,'
      '    :IDBASE_INTERF_MAINMENU,'
      '    :IDGRP_INTERF_MAINMENU,'
      '    :NAME_INTERF_MAINMENU,'
      '    :MODUL_INTERF_MAINMENU,'
      '    :IDGRPUSER_INTERF_MAINMENU,'
      '    :APPLICATION_INTERF_MAINMENU,'
      '    :SHORTCUT_INTERF_MAINMENU,'
      '    :INDEX_INTERF_MAINMENU,'
      '    :GUID_INTERF_MAINMENU,'
      '    :FL_UPD_FORM_INTERF_MAINMENU,'
      '    :FL_NEW_DOC_INTERF_MAINMENU,'
      '    :IDEL_INTERF_MAINMENU,'
      '    :FL_OPEN_EL_INTERF_MAINMENU,'
      '    :GUIDMOD_INTERF_MAINMENU,'
      '    :TYPE_IDEL_INTERF_MAINMENU,'
      '    :IDMOD_INTERF_MAINMENU'
      ')')
    RefreshSQL.Strings = (
      'select interf_mainmenu.*,'
      '        program_module.name_program_module,'
      '        program_module.progid_program_module,'
      '        program_module.patch_program_module'
      'from INTERF_MAINMENU'
      
        'left outer join program_module on interf_mainmenu.idmod_interf_m' +
        'ainmenu=program_module.id_program_module'
      'where(  ID_INTERF_MAINMENU=:PARAM_ID'
      
        '     ) and (     INTERF_MAINMENU.ID_INTERF_MAINMENU = :OLD_ID_IN' +
        'TERF_MAINMENU'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select interf_mainmenu.*,'
      '        program_module.name_program_module,'
      '        program_module.progid_program_module,'
      '        program_module.patch_program_module'
      'from INTERF_MAINMENU'
      
        'left outer join program_module on interf_mainmenu.idmod_interf_m' +
        'ainmenu=program_module.id_program_module'
      'where ID_INTERF_MAINMENU=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'INTERF_MAINMENU'
    AutoUpdateOptions.KeyFields = 'ID_INTERF_MAINMENU'
    AutoUpdateOptions.GeneratorName = 'GEN_INTERF_MAINMENU_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 136
    Top = 80
    poUseGuidField = True
    poUseLargeIntField = True
    object ElementID_INTERF_MAINMENU: TFIBLargeIntField
      FieldName = 'ID_INTERF_MAINMENU'
    end
    object ElementIDBASE_INTERF_MAINMENU: TFIBLargeIntField
      FieldName = 'IDBASE_INTERF_MAINMENU'
    end
    object ElementIDGRP_INTERF_MAINMENU: TFIBLargeIntField
      FieldName = 'IDGRP_INTERF_MAINMENU'
    end
    object ElementNAME_INTERF_MAINMENU: TFIBWideStringField
      FieldName = 'NAME_INTERF_MAINMENU'
      Size = 40
    end
    object ElementMODUL_INTERF_MAINMENU: TFIBIntegerField
      FieldName = 'MODUL_INTERF_MAINMENU'
    end
    object ElementIDGRPUSER_INTERF_MAINMENU: TFIBLargeIntField
      FieldName = 'IDGRPUSER_INTERF_MAINMENU'
    end
    object ElementAPPLICATION_INTERF_MAINMENU: TFIBIntegerField
      FieldName = 'APPLICATION_INTERF_MAINMENU'
    end
    object ElementSHORTCUT_INTERF_MAINMENU: TFIBWideStringField
      FieldName = 'SHORTCUT_INTERF_MAINMENU'
      Size = 10
    end
    object ElementINDEX_INTERF_MAINMENU: TFIBIntegerField
      FieldName = 'INDEX_INTERF_MAINMENU'
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
    object ElementFL_UPD_FORM_INTERF_MAINMENU: TFIBSmallIntField
      FieldName = 'FL_UPD_FORM_INTERF_MAINMENU'
    end
    object ElementFL_NEW_DOC_INTERF_MAINMENU: TFIBSmallIntField
      FieldName = 'FL_NEW_DOC_INTERF_MAINMENU'
    end
    object ElementIDEL_INTERF_MAINMENU: TFIBLargeIntField
      FieldName = 'IDEL_INTERF_MAINMENU'
    end
    object ElementFL_OPEN_EL_INTERF_MAINMENU: TFIBSmallIntField
      FieldName = 'FL_OPEN_EL_INTERF_MAINMENU'
    end
    object ElementGUIDMOD_INTERF_MAINMENU: TFIBWideStringField
      FieldName = 'GUIDMOD_INTERF_MAINMENU'
      Size = 38
    end
    object ElementTYPE_IDEL_INTERF_MAINMENU: TFIBIntegerField
      FieldName = 'TYPE_IDEL_INTERF_MAINMENU'
    end
    object ElementIDMOD_INTERF_MAINMENU: TFIBLargeIntField
      FieldName = 'IDMOD_INTERF_MAINMENU'
    end
  end
end
