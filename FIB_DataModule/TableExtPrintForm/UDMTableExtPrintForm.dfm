object DMTableExtPrintForm: TDMTableExtPrintForm
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 165
  Width = 355
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 40
    Top = 16
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 40
    Top = 96
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select  EXTPRINT_FORM.*,'
      '        program_module.name_program_module,'
      '        program_module.progid_program_module,'
      '        program_module.patch_program_module '
      'from  EXTPRINT_FORM'
      
        'left outer join program_module on extprint_form.guid_ob_extprint' +
        '_form=program_module.guid_program_module'
      
        'order by program_module.name_program_module,EXTPRINT_FORM.name_e' +
        'xtprint_form'
      '')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 144
    Top = 16
    poUseLargeIntField = True
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_EXTPRINT_FORM: TFIBLargeIntField
      FieldName = 'ID_EXTPRINT_FORM'
    end
    object TableNAME_EXTPRINT_FORM: TFIBWideStringField
      FieldName = 'NAME_EXTPRINT_FORM'
      Size = 200
    end
    object TableOBJECT_EXTPRINT_FORM: TFIBWideStringField
      FieldName = 'OBJECT_EXTPRINT_FORM'
      Size = 40
    end
    object TableFILE_NAME_EXTPRINT_FORM: TFIBWideStringField
      FieldName = 'FILE_NAME_EXTPRINT_FORM'
      Size = 200
    end
    object TableISPCONST_EXTPRINT_FORM: TFIBIntegerField
      FieldName = 'ISPCONST_EXTPRINT_FORM'
    end
    object TableGID_EXTPRINT_FORM: TFIBWideStringField
      FieldName = 'GID_EXTPRINT_FORM'
      Size = 10
    end
    object TableIDBASE_EXTPRINT_FORM: TFIBLargeIntField
      FieldName = 'IDBASE_EXTPRINT_FORM'
    end
    object TableTYPEMODULE_EXTPRINT_FORM: TFIBIntegerField
      FieldName = 'TYPEMODULE_EXTPRINT_FORM'
    end
    object TableRESIDENCE_EXTPRINT_FORM: TFIBIntegerField
      FieldName = 'RESIDENCE_EXTPRINT_FORM'
    end
    object TableBODY_EXTPRINT_FORM: TFIBBlobField
      FieldName = 'BODY_EXTPRINT_FORM'
      Size = 8
    end
    object TableGUID_OB_EXTPRINT_FORM: TFIBWideStringField
      FieldName = 'GUID_OB_EXTPRINT_FORM'
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
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE EXTPRINT_FORM'
      'SET '
      '    NAME_EXTPRINT_FORM = :NAME_EXTPRINT_FORM,'
      '    OBJECT_EXTPRINT_FORM = :OBJECT_EXTPRINT_FORM,'
      '    FILE_NAME_EXTPRINT_FORM = :FILE_NAME_EXTPRINT_FORM,'
      '    ISPCONST_EXTPRINT_FORM = :ISPCONST_EXTPRINT_FORM,'
      '    GID_EXTPRINT_FORM = :GID_EXTPRINT_FORM,'
      '    IDBASE_EXTPRINT_FORM = :IDBASE_EXTPRINT_FORM,'
      '    TYPEMODULE_EXTPRINT_FORM = :TYPEMODULE_EXTPRINT_FORM,'
      '    RESIDENCE_EXTPRINT_FORM = :RESIDENCE_EXTPRINT_FORM,'
      '    BODY_EXTPRINT_FORM = :BODY_EXTPRINT_FORM,'
      '    GUID_OB_EXTPRINT_FORM = :GUID_OB_EXTPRINT_FORM'
      'WHERE'
      '    ID_EXTPRINT_FORM = :OLD_ID_EXTPRINT_FORM'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    EXTPRINT_FORM'
      'WHERE'
      '        ID_EXTPRINT_FORM = :OLD_ID_EXTPRINT_FORM'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO EXTPRINT_FORM('
      '    ID_EXTPRINT_FORM,'
      '    NAME_EXTPRINT_FORM,'
      '    OBJECT_EXTPRINT_FORM,'
      '    FILE_NAME_EXTPRINT_FORM,'
      '    ISPCONST_EXTPRINT_FORM,'
      '    GID_EXTPRINT_FORM,'
      '    IDBASE_EXTPRINT_FORM,'
      '    TYPEMODULE_EXTPRINT_FORM,'
      '    RESIDENCE_EXTPRINT_FORM,'
      '    BODY_EXTPRINT_FORM,'
      '    GUID_OB_EXTPRINT_FORM'
      ')'
      'VALUES('
      '    :ID_EXTPRINT_FORM,'
      '    :NAME_EXTPRINT_FORM,'
      '    :OBJECT_EXTPRINT_FORM,'
      '    :FILE_NAME_EXTPRINT_FORM,'
      '    :ISPCONST_EXTPRINT_FORM,'
      '    :GID_EXTPRINT_FORM,'
      '    :IDBASE_EXTPRINT_FORM,'
      '    :TYPEMODULE_EXTPRINT_FORM,'
      '    :RESIDENCE_EXTPRINT_FORM,'
      '    :BODY_EXTPRINT_FORM,'
      '    :GUID_OB_EXTPRINT_FORM'
      ')')
    RefreshSQL.Strings = (
      'select  EXTPRINT_FORM.*,'
      '        program_module.name_program_module,'
      '        program_module.progid_program_module,'
      '        program_module.patch_program_module '
      'from EXTPRINT_FORM '
      
        'left outer join program_module on extprint_form.guid_ob_extprint' +
        '_form=program_module.guid_program_module'
      'where(  ID_EXTPRINT_FORM=:PARAM_ID'
      
        '     ) and (     EXTPRINT_FORM.ID_EXTPRINT_FORM = :OLD_ID_EXTPRI' +
        'NT_FORM'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select  EXTPRINT_FORM.*,'
      '        program_module.name_program_module,'
      '        program_module.progid_program_module,'
      '        program_module.patch_program_module '
      'from EXTPRINT_FORM '
      
        'left outer join program_module on extprint_form.guid_ob_extprint' +
        '_form=program_module.guid_program_module'
      'where ID_EXTPRINT_FORM=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'EXTPRINT_FORM'
    AutoUpdateOptions.KeyFields = 'ID_EXTPRINT_FORM'
    AutoUpdateOptions.GeneratorName = 'GEN_EXTPRINT_FORM_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 96
    poUseLargeIntField = True
    object ElementID_EXTPRINT_FORM: TFIBLargeIntField
      FieldName = 'ID_EXTPRINT_FORM'
    end
    object ElementNAME_EXTPRINT_FORM: TFIBWideStringField
      FieldName = 'NAME_EXTPRINT_FORM'
      Size = 200
    end
    object ElementOBJECT_EXTPRINT_FORM: TFIBWideStringField
      FieldName = 'OBJECT_EXTPRINT_FORM'
      Size = 40
    end
    object ElementFILE_NAME_EXTPRINT_FORM: TFIBWideStringField
      FieldName = 'FILE_NAME_EXTPRINT_FORM'
      Size = 200
    end
    object ElementISPCONST_EXTPRINT_FORM: TFIBIntegerField
      FieldName = 'ISPCONST_EXTPRINT_FORM'
    end
    object ElementGID_EXTPRINT_FORM: TFIBWideStringField
      FieldName = 'GID_EXTPRINT_FORM'
      Size = 10
    end
    object ElementIDBASE_EXTPRINT_FORM: TFIBLargeIntField
      FieldName = 'IDBASE_EXTPRINT_FORM'
    end
    object ElementTYPEMODULE_EXTPRINT_FORM: TFIBIntegerField
      FieldName = 'TYPEMODULE_EXTPRINT_FORM'
    end
    object ElementRESIDENCE_EXTPRINT_FORM: TFIBIntegerField
      FieldName = 'RESIDENCE_EXTPRINT_FORM'
    end
    object ElementBODY_EXTPRINT_FORM: TFIBBlobField
      FieldName = 'BODY_EXTPRINT_FORM'
      Size = 8
    end
    object ElementGUID_OB_EXTPRINT_FORM: TFIBWideStringField
      FieldName = 'GUID_OB_EXTPRINT_FORM'
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
    Top = 96
  end
end
