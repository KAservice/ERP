object DMObjectBasePriv: TDMObjectBasePriv
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 251
  Width = 356
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE OBJECT_BASE_PRIV'
      'SET '
      '    IDBASE_OBJECT_BASE_PRIV = :IDBASE_OBJECT_BASE_PRIV,'
      '    IDGRPUSER_OBJECT_BASE_PRIV = :IDGRPUSER_OBJECT_BASE_PRIV,'
      '    INS_OBJECT_BASE_PRIV = :INS_OBJECT_BASE_PRIV,'
      '    EDIT_OBJECT_BASE_PRIV = :EDIT_OBJECT_BASE_PRIV,'
      '    DEL_OBJECT_BASE_PRIV = :DEL_OBJECT_BASE_PRIV,'
      '    EXEC_OBJECT_BASE_PRIV = :EXEC_OBJECT_BASE_PRIV,'
      '    NUMBER_OBJECT_BASE_PRIV = :NUMBER_OBJECT_BASE_PRIV,'
      '    IDGRP_OBJECT_BASE_PRIV = :IDGRP_OBJECT_BASE_PRIV,'
      
        '    APPLICATION_OBJECT_BASE_PRIV = :APPLICATION_OBJECT_BASE_PRIV' +
        ','
      '    GUID_OBJECT_BASE_PRIV = :GUID_OBJECT_BASE_PRIV'
      'WHERE'
      '    ID_OBJECT_BASE_PRIV = :OLD_ID_OBJECT_BASE_PRIV'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    OBJECT_BASE_PRIV'
      'WHERE'
      '        ID_OBJECT_BASE_PRIV = :OLD_ID_OBJECT_BASE_PRIV'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO OBJECT_BASE_PRIV('
      '    ID_OBJECT_BASE_PRIV,'
      '    IDBASE_OBJECT_BASE_PRIV,'
      '    IDGRPUSER_OBJECT_BASE_PRIV,'
      '    INS_OBJECT_BASE_PRIV,'
      '    EDIT_OBJECT_BASE_PRIV,'
      '    DEL_OBJECT_BASE_PRIV,'
      '    EXEC_OBJECT_BASE_PRIV,'
      '    NUMBER_OBJECT_BASE_PRIV,'
      '    IDGRP_OBJECT_BASE_PRIV,'
      '    APPLICATION_OBJECT_BASE_PRIV,'
      '    GUID_OBJECT_BASE_PRIV'
      ')'
      'VALUES('
      '    :ID_OBJECT_BASE_PRIV,'
      '    :IDBASE_OBJECT_BASE_PRIV,'
      '    :IDGRPUSER_OBJECT_BASE_PRIV,'
      '    :INS_OBJECT_BASE_PRIV,'
      '    :EDIT_OBJECT_BASE_PRIV,'
      '    :DEL_OBJECT_BASE_PRIV,'
      '    :EXEC_OBJECT_BASE_PRIV,'
      '    :NUMBER_OBJECT_BASE_PRIV,'
      '    :IDGRP_OBJECT_BASE_PRIV,'
      '    :APPLICATION_OBJECT_BASE_PRIV,'
      '    :GUID_OBJECT_BASE_PRIV'
      ')')
    RefreshSQL.Strings = (
      'select object_base_priv.*,'
      '        program_module.name_program_module,'
      '        program_module.progid_program_module,'
      '        program_module.patch_program_module'
      'from object_base_priv'
      
        'left outer join program_module on object_base_priv.guid_object_b' +
        'ase_priv=program_module.guid_program_module'
      'where(  '
      
        'object_base_priv.idgrpuser_object_base_priv=:PARAM_IDGRP_USER an' +
        'd'
      '            object_base_priv.idgrp_object_base_priv=:PARAM_IDGRP'
      
        '            and object_base_priv.application_object_base_priv=:P' +
        'ARAM_APL'
      
        '     ) and (     OBJECT_BASE_PRIV.ID_OBJECT_BASE_PRIV = :OLD_ID_' +
        'OBJECT_BASE_PRIV'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select object_base_priv.*,'
      '        program_module.name_program_module,'
      '        program_module.progid_program_module,'
      '        program_module.patch_program_module'
      'from object_base_priv'
      
        'left outer join program_module on object_base_priv.guid_object_b' +
        'ase_priv=program_module.guid_program_module'
      'where '
      
        'object_base_priv.idgrpuser_object_base_priv=:PARAM_IDGRP_USER an' +
        'd'
      '            object_base_priv.idgrp_object_base_priv=:PARAM_IDGRP'
      
        '            and object_base_priv.application_object_base_priv=:P' +
        'ARAM_APL')
    AutoUpdateOptions.UpdateTableName = 'OBJECT_BASE_PRIV'
    AutoUpdateOptions.KeyFields = 'ID_OBJECT_BASE_PRIV'
    AutoUpdateOptions.GeneratorName = 'GEN_OBJECT_BASE_PRIV_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnCalcFields = TableCalcFields
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 136
    Top = 16
    poUseLargeIntField = True
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_OBJECT_BASE_PRIV: TFIBLargeIntField
      FieldName = 'ID_OBJECT_BASE_PRIV'
    end
    object TableIDBASE_OBJECT_BASE_PRIV: TFIBLargeIntField
      FieldName = 'IDBASE_OBJECT_BASE_PRIV'
    end
    object TableIDGRPUSER_OBJECT_BASE_PRIV: TFIBLargeIntField
      FieldName = 'IDGRPUSER_OBJECT_BASE_PRIV'
    end
    object TableINS_OBJECT_BASE_PRIV: TFIBSmallIntField
      FieldName = 'INS_OBJECT_BASE_PRIV'
    end
    object TableEDIT_OBJECT_BASE_PRIV: TFIBSmallIntField
      FieldName = 'EDIT_OBJECT_BASE_PRIV'
    end
    object TableDEL_OBJECT_BASE_PRIV: TFIBSmallIntField
      FieldName = 'DEL_OBJECT_BASE_PRIV'
    end
    object TableEXEC_OBJECT_BASE_PRIV: TFIBSmallIntField
      FieldName = 'EXEC_OBJECT_BASE_PRIV'
    end
    object TableNUMBER_OBJECT_BASE_PRIV: TFIBIntegerField
      FieldName = 'NUMBER_OBJECT_BASE_PRIV'
    end
    object TableIDGRP_OBJECT_BASE_PRIV: TFIBLargeIntField
      FieldName = 'IDGRP_OBJECT_BASE_PRIV'
    end
    object TableAPPLICATION_OBJECT_BASE_PRIV: TFIBIntegerField
      FieldName = 'APPLICATION_OBJECT_BASE_PRIV'
    end
    object TableGUID_OBJECT_BASE_PRIV: TFIBWideStringField
      FieldName = 'GUID_OBJECT_BASE_PRIV'
      Size = 38
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
      'UPDATE OBJECT_BASE_PRIV'
      'SET '
      '    IDBASE_OBJECT_BASE_PRIV = :IDBASE_OBJECT_BASE_PRIV,'
      '    IDGRPUSER_OBJECT_BASE_PRIV = :IDGRPUSER_OBJECT_BASE_PRIV,'
      '    INS_OBJECT_BASE_PRIV = :INS_OBJECT_BASE_PRIV,'
      '    EDIT_OBJECT_BASE_PRIV = :EDIT_OBJECT_BASE_PRIV,'
      '    DEL_OBJECT_BASE_PRIV = :DEL_OBJECT_BASE_PRIV,'
      '    EXEC_OBJECT_BASE_PRIV = :EXEC_OBJECT_BASE_PRIV,'
      '    NUMBER_OBJECT_BASE_PRIV = :NUMBER_OBJECT_BASE_PRIV,'
      '    IDGRP_OBJECT_BASE_PRIV = :IDGRP_OBJECT_BASE_PRIV,'
      
        '    APPLICATION_OBJECT_BASE_PRIV = :APPLICATION_OBJECT_BASE_PRIV' +
        ','
      '    GUID_OBJECT_BASE_PRIV = :GUID_OBJECT_BASE_PRIV'
      'WHERE'
      '    ID_OBJECT_BASE_PRIV = :OLD_ID_OBJECT_BASE_PRIV'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    OBJECT_BASE_PRIV'
      'WHERE'
      '        ID_OBJECT_BASE_PRIV = :OLD_ID_OBJECT_BASE_PRIV'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO OBJECT_BASE_PRIV('
      '    ID_OBJECT_BASE_PRIV,'
      '    IDBASE_OBJECT_BASE_PRIV,'
      '    IDGRPUSER_OBJECT_BASE_PRIV,'
      '    INS_OBJECT_BASE_PRIV,'
      '    EDIT_OBJECT_BASE_PRIV,'
      '    DEL_OBJECT_BASE_PRIV,'
      '    EXEC_OBJECT_BASE_PRIV,'
      '    NUMBER_OBJECT_BASE_PRIV,'
      '    IDGRP_OBJECT_BASE_PRIV,'
      '    APPLICATION_OBJECT_BASE_PRIV,'
      '    GUID_OBJECT_BASE_PRIV'
      ')'
      'VALUES('
      '    :ID_OBJECT_BASE_PRIV,'
      '    :IDBASE_OBJECT_BASE_PRIV,'
      '    :IDGRPUSER_OBJECT_BASE_PRIV,'
      '    :INS_OBJECT_BASE_PRIV,'
      '    :EDIT_OBJECT_BASE_PRIV,'
      '    :DEL_OBJECT_BASE_PRIV,'
      '    :EXEC_OBJECT_BASE_PRIV,'
      '    :NUMBER_OBJECT_BASE_PRIV,'
      '    :IDGRP_OBJECT_BASE_PRIV,'
      '    :APPLICATION_OBJECT_BASE_PRIV,'
      '    :GUID_OBJECT_BASE_PRIV'
      ')')
    RefreshSQL.Strings = (
      'select object_base_priv.*,'
      '        program_module.name_program_module,'
      '        program_module.progid_program_module,'
      '        program_module.patch_program_module'
      'from object_base_priv'
      
        'left outer join program_module on object_base_priv.guid_object_b' +
        'ase_priv=program_module.guid_program_module'
      'where(  object_base_priv.id_object_base_priv=:PARAM_ID'
      
        '     ) and (     OBJECT_BASE_PRIV.ID_OBJECT_BASE_PRIV = :OLD_ID_' +
        'OBJECT_BASE_PRIV'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select object_base_priv.*,'
      '        program_module.name_program_module,'
      '        program_module.progid_program_module,'
      '        program_module.patch_program_module'
      'from object_base_priv'
      
        'left outer join program_module on object_base_priv.guid_object_b' +
        'ase_priv=program_module.guid_program_module'
      'where object_base_priv.id_object_base_priv=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'OBJECT_BASE_PRIV'
    AutoUpdateOptions.KeyFields = 'ID_OBJECT_BASE_PRIV'
    AutoUpdateOptions.GeneratorName = 'GEN_OBJECT_BASE_PRIV_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 136
    Top = 80
    poUseLargeIntField = True
    object ElementID_OBJECT_BASE_PRIV: TFIBLargeIntField
      FieldName = 'ID_OBJECT_BASE_PRIV'
    end
    object ElementIDBASE_OBJECT_BASE_PRIV: TFIBLargeIntField
      FieldName = 'IDBASE_OBJECT_BASE_PRIV'
    end
    object ElementIDEXT_DOUT_OBJECT_BASE_PRIV: TFIBLargeIntField
      FieldName = 'IDEXT_DOUT_OBJECT_BASE_PRIV'
    end
    object ElementIDEXT_BASE_OBJECT_BASE_PRIV: TFIBLargeIntField
      FieldName = 'IDEXT_BASE_OBJECT_BASE_PRIV'
    end
    object ElementIDGRPUSER_OBJECT_BASE_PRIV: TFIBLargeIntField
      FieldName = 'IDGRPUSER_OBJECT_BASE_PRIV'
    end
    object ElementINS_OBJECT_BASE_PRIV: TFIBSmallIntField
      FieldName = 'INS_OBJECT_BASE_PRIV'
    end
    object ElementEDIT_OBJECT_BASE_PRIV: TFIBSmallIntField
      FieldName = 'EDIT_OBJECT_BASE_PRIV'
    end
    object ElementDEL_OBJECT_BASE_PRIV: TFIBSmallIntField
      FieldName = 'DEL_OBJECT_BASE_PRIV'
    end
    object ElementEXEC_OBJECT_BASE_PRIV: TFIBSmallIntField
      FieldName = 'EXEC_OBJECT_BASE_PRIV'
    end
    object ElementNUMBER_OBJECT_BASE_PRIV: TFIBIntegerField
      FieldName = 'NUMBER_OBJECT_BASE_PRIV'
    end
    object ElementIDGRP_OBJECT_BASE_PRIV: TFIBLargeIntField
      FieldName = 'IDGRP_OBJECT_BASE_PRIV'
    end
    object ElementAPPLICATION_OBJECT_BASE_PRIV: TFIBIntegerField
      FieldName = 'APPLICATION_OBJECT_BASE_PRIV'
    end
    object ElementGUID_OBJECT_BASE_PRIV: TFIBWideStringField
      FieldName = 'GUID_OBJECT_BASE_PRIV'
      Size = 38
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
  object Query: TpFIBQuery
    Transaction = IBTr
    Left = 136
    Top = 152
    qoStartTransaction = True
  end
end
