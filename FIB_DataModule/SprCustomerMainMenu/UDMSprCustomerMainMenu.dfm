object DMSprCustomerMainMenu: TDMSprCustomerMainMenu
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 293
  Width = 483
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE CUST_MAINMENU'
      'SET '
      '    IDBASE_CUST_MAINMENU = :IDBASE_CUST_MAINMENU,'
      '    GID_CUST_MAINMENU = :GID_CUST_MAINMENU,'
      '    IDACCOUNT_CUST_MAINMENU = :IDACCOUNT_CUST_MAINMENU,'
      '    IDGRPUSER_CUST_MAINMENU = :IDGRPUSER_CUST_MAINMENU,'
      '    IDGRP_CUST_MAINMENU = :IDGRP_CUST_MAINMENU,'
      '    NAME_CUST_MAINMENU = :NAME_CUST_MAINMENU,'
      '    INDEX_CUST_MAINMENU = :INDEX_CUST_MAINMENU,'
      '    GUID_CUST_MAINMENU = :GUID_CUST_MAINMENU,'
      '    GUIDMOD_CUST_MAINMENU = :GUIDMOD_CUST_MAINMENU,'
      '    IDMOD_CUST_MAINMENU = :IDMOD_CUST_MAINMENU,'
      '    FL_OPEN_EL_CUST_MAINMENU = :FL_OPEN_EL_CUST_MAINMENU,'
      '    IDEL_CUST_MAINMENU = :IDEL_CUST_MAINMENU'
      'WHERE'
      '    ID_CUST_MAINMENU = :OLD_ID_CUST_MAINMENU'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    CUST_MAINMENU'
      'WHERE'
      '        ID_CUST_MAINMENU = :OLD_ID_CUST_MAINMENU'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO CUST_MAINMENU('
      '    ID_CUST_MAINMENU,'
      '    IDBASE_CUST_MAINMENU,'
      '    GID_CUST_MAINMENU,'
      '    IDACCOUNT_CUST_MAINMENU,'
      '    IDGRPUSER_CUST_MAINMENU,'
      '    IDGRP_CUST_MAINMENU,'
      '    NAME_CUST_MAINMENU,'
      '    INDEX_CUST_MAINMENU,'
      '    GUID_CUST_MAINMENU,'
      '    GUIDMOD_CUST_MAINMENU,'
      '    IDMOD_CUST_MAINMENU,'
      '    FL_OPEN_EL_CUST_MAINMENU,'
      '    IDEL_CUST_MAINMENU'
      ')'
      'VALUES('
      '    :ID_CUST_MAINMENU,'
      '    :IDBASE_CUST_MAINMENU,'
      '    :GID_CUST_MAINMENU,'
      '    :IDACCOUNT_CUST_MAINMENU,'
      '    :IDGRPUSER_CUST_MAINMENU,'
      '    :IDGRP_CUST_MAINMENU,'
      '    :NAME_CUST_MAINMENU,'
      '    :INDEX_CUST_MAINMENU,'
      '    :GUID_CUST_MAINMENU,'
      '    :GUIDMOD_CUST_MAINMENU,'
      '    :IDMOD_CUST_MAINMENU,'
      '    :FL_OPEN_EL_CUST_MAINMENU,'
      '    :IDEL_CUST_MAINMENU'
      ')')
    RefreshSQL.Strings = (
      'select cust_mainmenu.*,'
      '    program_module.name_program_module,'
      '    program_module.progid_program_module,'
      '    program_module.patch_program_module,'
      '         program_module.typemod_program_module'
      'from cust_mainmenu'
      
        'left outer join program_module on cust_mainmenu.idmod_cust_mainm' +
        'enu=program_module.id_program_module'
      'where( '
      ' cust_mainmenu.idgrpuser_cust_mainmenu=:PARAM_IDGRP_USER'
      ' and cust_mainmenu.idaccount_cust_mainmenu=:PARAM_IDACCOUNT'
      
        '     ) and (     CUST_MAINMENU.ID_CUST_MAINMENU = :OLD_ID_CUST_M' +
        'AINMENU'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select cust_mainmenu.*,'
      '    program_module.name_program_module,'
      '    program_module.progid_program_module,'
      '    program_module.patch_program_module,'
      '         program_module.typemod_program_module'
      'from cust_mainmenu'
      
        'left outer join program_module on cust_mainmenu.idmod_cust_mainm' +
        'enu=program_module.id_program_module'
      'where'
      ' cust_mainmenu.idgrpuser_cust_mainmenu=:PARAM_IDGRP_USER'
      ' and cust_mainmenu.idaccount_cust_mainmenu=:PARAM_IDACCOUNT'
      'order by cust_mainmenu.index_cust_mainmenu desc'
      '')
    AutoUpdateOptions.UpdateTableName = 'CUST_MAINMENU'
    AutoUpdateOptions.KeyFields = 'ID_CUST_MAINMENU'
    AutoUpdateOptions.GeneratorName = 'GEN_CUST_MAINMENU_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 136
    Top = 16
    poUseGuidField = True
    poUseLargeIntField = True
    object TableID_CUST_MAINMENU: TFIBLargeIntField
      FieldName = 'ID_CUST_MAINMENU'
    end
    object TableIDBASE_CUST_MAINMENU: TFIBLargeIntField
      FieldName = 'IDBASE_CUST_MAINMENU'
    end
    object TableGID_CUST_MAINMENU: TFIBWideStringField
      FieldName = 'GID_CUST_MAINMENU'
      Size = 10
    end
    object TableIDACCOUNT_CUST_MAINMENU: TFIBLargeIntField
      FieldName = 'IDACCOUNT_CUST_MAINMENU'
    end
    object TableIDGRPUSER_CUST_MAINMENU: TFIBLargeIntField
      FieldName = 'IDGRPUSER_CUST_MAINMENU'
    end
    object TableIDGRP_CUST_MAINMENU: TFIBLargeIntField
      FieldName = 'IDGRP_CUST_MAINMENU'
    end
    object TableNAME_CUST_MAINMENU: TFIBWideStringField
      FieldName = 'NAME_CUST_MAINMENU'
      Size = 200
    end
    object TableINDEX_CUST_MAINMENU: TFIBIntegerField
      FieldName = 'INDEX_CUST_MAINMENU'
    end
    object TableGUID_CUST_MAINMENU: TFIBWideStringField
      FieldName = 'GUID_CUST_MAINMENU'
      Size = 38
    end
    object TableGUIDMOD_CUST_MAINMENU: TFIBWideStringField
      FieldName = 'GUIDMOD_CUST_MAINMENU'
      Size = 38
    end
    object TableIDMOD_CUST_MAINMENU: TFIBLargeIntField
      FieldName = 'IDMOD_CUST_MAINMENU'
    end
    object TableFL_OPEN_EL_CUST_MAINMENU: TFIBSmallIntField
      FieldName = 'FL_OPEN_EL_CUST_MAINMENU'
    end
    object TableIDEL_CUST_MAINMENU: TFIBLargeIntField
      FieldName = 'IDEL_CUST_MAINMENU'
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
      'UPDATE CUST_MAINMENU'
      'SET '
      '    IDBASE_CUST_MAINMENU = :IDBASE_CUST_MAINMENU,'
      '    GID_CUST_MAINMENU = :GID_CUST_MAINMENU,'
      '    IDACCOUNT_CUST_MAINMENU = :IDACCOUNT_CUST_MAINMENU,'
      '    IDGRPUSER_CUST_MAINMENU = :IDGRPUSER_CUST_MAINMENU,'
      '    IDGRP_CUST_MAINMENU = :IDGRP_CUST_MAINMENU,'
      '    NAME_CUST_MAINMENU = :NAME_CUST_MAINMENU,'
      '    INDEX_CUST_MAINMENU = :INDEX_CUST_MAINMENU,'
      '    GUID_CUST_MAINMENU = :GUID_CUST_MAINMENU,'
      '    GUIDMOD_CUST_MAINMENU = :GUIDMOD_CUST_MAINMENU,'
      '    IDMOD_CUST_MAINMENU = :IDMOD_CUST_MAINMENU,'
      '    FL_OPEN_EL_CUST_MAINMENU = :FL_OPEN_EL_CUST_MAINMENU,'
      '    IDEL_CUST_MAINMENU = :IDEL_CUST_MAINMENU'
      'WHERE'
      '    ID_CUST_MAINMENU = :OLD_ID_CUST_MAINMENU'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    CUST_MAINMENU'
      'WHERE'
      '        ID_CUST_MAINMENU = :OLD_ID_CUST_MAINMENU'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO CUST_MAINMENU('
      '    ID_CUST_MAINMENU,'
      '    IDBASE_CUST_MAINMENU,'
      '    GID_CUST_MAINMENU,'
      '    IDACCOUNT_CUST_MAINMENU,'
      '    IDGRPUSER_CUST_MAINMENU,'
      '    IDGRP_CUST_MAINMENU,'
      '    NAME_CUST_MAINMENU,'
      '    INDEX_CUST_MAINMENU,'
      '    GUID_CUST_MAINMENU,'
      '    GUIDMOD_CUST_MAINMENU,'
      '    IDMOD_CUST_MAINMENU,'
      '    FL_OPEN_EL_CUST_MAINMENU,'
      '    IDEL_CUST_MAINMENU'
      ')'
      'VALUES('
      '    :ID_CUST_MAINMENU,'
      '    :IDBASE_CUST_MAINMENU,'
      '    :GID_CUST_MAINMENU,'
      '    :IDACCOUNT_CUST_MAINMENU,'
      '    :IDGRPUSER_CUST_MAINMENU,'
      '    :IDGRP_CUST_MAINMENU,'
      '    :NAME_CUST_MAINMENU,'
      '    :INDEX_CUST_MAINMENU,'
      '    :GUID_CUST_MAINMENU,'
      '    :GUIDMOD_CUST_MAINMENU,'
      '    :IDMOD_CUST_MAINMENU,'
      '    :FL_OPEN_EL_CUST_MAINMENU,'
      '    :IDEL_CUST_MAINMENU'
      ')')
    RefreshSQL.Strings = (
      'select cust_mainmenu.*,'
      '        program_module.name_program_module,'
      '        program_module.progid_program_module,'
      '        program_module.patch_program_module'
      'from cust_mainmenu'
      
        'left outer join program_module on cust_mainmenu.idmod_cust_mainm' +
        'enu=program_module.id_program_module'
      'where(  cust_mainmenu.id_cust_mainmenu=:PARAM_ID'
      
        '     ) and (     CUST_MAINMENU.ID_CUST_MAINMENU = :OLD_ID_CUST_M' +
        'AINMENU'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select cust_mainmenu.*,'
      '        program_module.name_program_module,'
      '        program_module.progid_program_module,'
      '        program_module.patch_program_module'
      'from cust_mainmenu'
      
        'left outer join program_module on cust_mainmenu.idmod_cust_mainm' +
        'enu=program_module.id_program_module'
      'where cust_mainmenu.id_cust_mainmenu=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'CUST_MAINMENU'
    AutoUpdateOptions.KeyFields = 'ID_CUST_MAINMENU'
    AutoUpdateOptions.GeneratorName = 'GEN_CUST_MAINMENU_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 136
    Top = 80
    poUseGuidField = True
    poUseLargeIntField = True
    object ElementID_CUST_MAINMENU: TFIBLargeIntField
      FieldName = 'ID_CUST_MAINMENU'
    end
    object ElementIDBASE_CUST_MAINMENU: TFIBLargeIntField
      FieldName = 'IDBASE_CUST_MAINMENU'
    end
    object ElementGID_CUST_MAINMENU: TFIBWideStringField
      FieldName = 'GID_CUST_MAINMENU'
      Size = 10
    end
    object ElementIDACCOUNT_CUST_MAINMENU: TFIBLargeIntField
      FieldName = 'IDACCOUNT_CUST_MAINMENU'
    end
    object ElementIDGRPUSER_CUST_MAINMENU: TFIBLargeIntField
      FieldName = 'IDGRPUSER_CUST_MAINMENU'
    end
    object ElementIDGRP_CUST_MAINMENU: TFIBLargeIntField
      FieldName = 'IDGRP_CUST_MAINMENU'
    end
    object ElementNAME_CUST_MAINMENU: TFIBWideStringField
      FieldName = 'NAME_CUST_MAINMENU'
      Size = 200
    end
    object ElementINDEX_CUST_MAINMENU: TFIBIntegerField
      FieldName = 'INDEX_CUST_MAINMENU'
    end
    object ElementGUID_CUST_MAINMENU: TFIBWideStringField
      FieldName = 'GUID_CUST_MAINMENU'
      Size = 38
    end
    object ElementGUIDMOD_CUST_MAINMENU: TFIBWideStringField
      FieldName = 'GUIDMOD_CUST_MAINMENU'
      Size = 38
    end
    object ElementIDMOD_CUST_MAINMENU: TFIBLargeIntField
      FieldName = 'IDMOD_CUST_MAINMENU'
    end
    object ElementFL_OPEN_EL_CUST_MAINMENU: TFIBSmallIntField
      FieldName = 'FL_OPEN_EL_CUST_MAINMENU'
    end
    object ElementIDEL_CUST_MAINMENU: TFIBLargeIntField
      FieldName = 'IDEL_CUST_MAINMENU'
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
  end
end
