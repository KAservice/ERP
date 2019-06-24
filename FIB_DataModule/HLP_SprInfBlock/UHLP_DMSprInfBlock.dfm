object HLP_DMSprInfBlock: THLP_DMSprInfBlock
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 403
  Width = 371
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
      'select hlp_ib.*,'
      '        program_module.name_program_module,'
      '        program_module.module_program_module,'
      '        program_module.descr_program_module,'
      '        program_module.patch_program_module'
      'from hlp_ib'
      
        'left outer join program_module on program_module.guid_program_mo' +
        'dule=hlp_ib.guid_prog_module_hlp_ib'
      'where hlp_ib.idgrp_hlp_ib=:PARAM_IDGRP'
      'ORDER BY hlp_ib.idgrp_hlp_ib, hlp_ib.index_hlp_ib')
    Transaction = IBTr
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object TableID_HLP_IB: TFIBLargeIntField
      FieldName = 'ID_HLP_IB'
    end
    object TableIDBASE_HLP_IB: TFIBLargeIntField
      FieldName = 'IDBASE_HLP_IB'
    end
    object TablePOS_ISM_HLP_IB: TFIBDateTimeField
      FieldName = 'POS_ISM_HLP_IB'
    end
    object TableGUID_HLP_IB: TFIBWideStringField
      FieldName = 'GUID_HLP_IB'
      Size = 38
    end
    object TableIDGRP_HLP_IB: TFIBLargeIntField
      FieldName = 'IDGRP_HLP_IB'
    end
    object TableGUIDGRP_HLP_IB: TFIBWideStringField
      FieldName = 'GUIDGRP_HLP_IB'
      Size = 38
    end
    object TableNAME_HLP_IB: TFIBWideStringField
      FieldName = 'NAME_HLP_IB'
      Size = 200
    end
    object TableKEYWORDS_HLP_IB: TFIBWideStringField
      FieldName = 'KEYWORDS_HLP_IB'
      Size = 200
    end
    object TableTITLE_HLP_IB: TFIBWideStringField
      FieldName = 'TITLE_HLP_IB'
      Size = 200
    end
    object TableDESCR_HLP_IB: TFIBWideStringField
      FieldName = 'DESCR_HLP_IB'
      Size = 200
    end
    object TableINDEX_HLP_IB: TFIBIntegerField
      FieldName = 'INDEX_HLP_IB'
    end
    object TableWEB_KEYWORDS_HLP_IB: TFIBWideStringField
      FieldName = 'WEB_KEYWORDS_HLP_IB'
      Size = 200
    end
    object TableWEB_TITLE_HLP_IB: TFIBWideStringField
      FieldName = 'WEB_TITLE_HLP_IB'
      Size = 200
    end
    object TableWEB_DESCR_HLP_IB: TFIBWideStringField
      FieldName = 'WEB_DESCR_HLP_IB'
      Size = 200
    end
    object TableGUID_PROG_MODULE_HLP_IB: TFIBWideStringField
      FieldName = 'GUID_PROG_MODULE_HLP_IB'
      Size = 38
    end
    object TableNAME_PROGRAM_MODULE: TFIBWideStringField
      FieldName = 'NAME_PROGRAM_MODULE'
      Size = 200
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
    object TableFL_ADD_SITEMAP_HLP_IB: TFIBSmallIntField
      FieldName = 'FL_ADD_SITEMAP_HLP_IB'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE HLP_IB'
      'SET '
      '    IDBASE_HLP_IB = :IDBASE_HLP_IB,'
      '    POS_ISM_HLP_IB = :POS_ISM_HLP_IB,'
      '    GUID_HLP_IB = :GUID_HLP_IB,'
      '    IDGRP_HLP_IB = :IDGRP_HLP_IB,'
      '    GUIDGRP_HLP_IB = :GUIDGRP_HLP_IB,'
      '    NAME_HLP_IB = :NAME_HLP_IB,'
      '    KEYWORDS_HLP_IB = :KEYWORDS_HLP_IB,'
      '    TITLE_HLP_IB = :TITLE_HLP_IB,'
      '    DESCR_HLP_IB = :DESCR_HLP_IB,'
      '    INDEX_HLP_IB = :INDEX_HLP_IB,'
      '    WEB_KEYWORDS_HLP_IB = :WEB_KEYWORDS_HLP_IB,'
      '    WEB_TITLE_HLP_IB = :WEB_TITLE_HLP_IB,'
      '    WEB_DESCR_HLP_IB = :WEB_DESCR_HLP_IB,'
      '    GUID_PROG_MODULE_HLP_IB = :GUID_PROG_MODULE_HLP_IB,'
      '    FL_ADD_SITEMAP_HLP_IB = :FL_ADD_SITEMAP_HLP_IB'
      'WHERE'
      '    ID_HLP_IB = :OLD_ID_HLP_IB'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    HLP_IB'
      'WHERE'
      '        ID_HLP_IB = :OLD_ID_HLP_IB'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO HLP_IB('
      '    ID_HLP_IB,'
      '    IDBASE_HLP_IB,'
      '    POS_ISM_HLP_IB,'
      '    GUID_HLP_IB,'
      '    IDGRP_HLP_IB,'
      '    GUIDGRP_HLP_IB,'
      '    NAME_HLP_IB,'
      '    KEYWORDS_HLP_IB,'
      '    TITLE_HLP_IB,'
      '    DESCR_HLP_IB,'
      '    INDEX_HLP_IB,'
      '    WEB_KEYWORDS_HLP_IB,'
      '    WEB_TITLE_HLP_IB,'
      '    WEB_DESCR_HLP_IB,'
      '    GUID_PROG_MODULE_HLP_IB,'
      '    FL_ADD_SITEMAP_HLP_IB'
      ')'
      'VALUES('
      '    :ID_HLP_IB,'
      '    :IDBASE_HLP_IB,'
      '    :POS_ISM_HLP_IB,'
      '    :GUID_HLP_IB,'
      '    :IDGRP_HLP_IB,'
      '    :GUIDGRP_HLP_IB,'
      '    :NAME_HLP_IB,'
      '    :KEYWORDS_HLP_IB,'
      '    :TITLE_HLP_IB,'
      '    :DESCR_HLP_IB,'
      '    :INDEX_HLP_IB,'
      '    :WEB_KEYWORDS_HLP_IB,'
      '    :WEB_TITLE_HLP_IB,'
      '    :WEB_DESCR_HLP_IB,'
      '    :GUID_PROG_MODULE_HLP_IB,'
      '    :FL_ADD_SITEMAP_HLP_IB'
      ')')
    RefreshSQL.Strings = (
      'select hlp_ib.* ,'
      '        program_module.name_program_module,'
      '        program_module.module_program_module,'
      '        program_module.descr_program_module,'
      '        program_module.patch_program_module'
      'from hlp_ib'
      
        'left outer join program_module on program_module.guid_program_mo' +
        'dule=hlp_ib.guid_prog_module_hlp_ib'
      'where(  hlp_ib.id_hlp_ib=:PARAM_ID'
      '     ) and (     HLP_IB.ID_HLP_IB = :OLD_ID_HLP_IB'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select hlp_ib.* ,'
      '        program_module.name_program_module,'
      '        program_module.module_program_module,'
      '        program_module.descr_program_module,'
      '        program_module.patch_program_module'
      'from hlp_ib'
      
        'left outer join program_module on program_module.guid_program_mo' +
        'dule=hlp_ib.guid_prog_module_hlp_ib'
      'where hlp_ib.id_hlp_ib=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'HLP_IB'
    AutoUpdateOptions.KeyFields = 'ID_HLP_IB'
    AutoUpdateOptions.GeneratorName = 'GEN_HLP_IB_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object ElementID_HLP_IB: TFIBLargeIntField
      FieldName = 'ID_HLP_IB'
    end
    object ElementIDBASE_HLP_IB: TFIBLargeIntField
      FieldName = 'IDBASE_HLP_IB'
    end
    object ElementPOS_ISM_HLP_IB: TFIBDateTimeField
      FieldName = 'POS_ISM_HLP_IB'
    end
    object ElementGUID_HLP_IB: TFIBWideStringField
      FieldName = 'GUID_HLP_IB'
      Size = 38
    end
    object ElementIDGRP_HLP_IB: TFIBLargeIntField
      FieldName = 'IDGRP_HLP_IB'
    end
    object ElementGUIDGRP_HLP_IB: TFIBWideStringField
      FieldName = 'GUIDGRP_HLP_IB'
      Size = 38
    end
    object ElementNAME_HLP_IB: TFIBWideStringField
      FieldName = 'NAME_HLP_IB'
      Size = 200
    end
    object ElementKEYWORDS_HLP_IB: TFIBWideStringField
      FieldName = 'KEYWORDS_HLP_IB'
      Size = 200
    end
    object ElementTITLE_HLP_IB: TFIBWideStringField
      FieldName = 'TITLE_HLP_IB'
      Size = 200
    end
    object ElementDESCR_HLP_IB: TFIBWideStringField
      FieldName = 'DESCR_HLP_IB'
      Size = 200
    end
    object ElementINDEX_HLP_IB: TFIBIntegerField
      FieldName = 'INDEX_HLP_IB'
    end
    object ElementWEB_KEYWORDS_HLP_IB: TFIBWideStringField
      FieldName = 'WEB_KEYWORDS_HLP_IB'
      Size = 200
    end
    object ElementWEB_TITLE_HLP_IB: TFIBWideStringField
      FieldName = 'WEB_TITLE_HLP_IB'
      Size = 200
    end
    object ElementWEB_DESCR_HLP_IB: TFIBWideStringField
      FieldName = 'WEB_DESCR_HLP_IB'
      Size = 200
    end
    object ElementGUID_PROG_MODULE_HLP_IB: TFIBWideStringField
      FieldName = 'GUID_PROG_MODULE_HLP_IB'
      Size = 38
    end
    object ElementNAME_PROGRAM_MODULE: TFIBWideStringField
      FieldName = 'NAME_PROGRAM_MODULE'
      Size = 200
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
    object ElementFL_ADD_SITEMAP_HLP_IB: TFIBSmallIntField
      FieldName = 'FL_ADD_SITEMAP_HLP_IB'
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
  object Query: TpFIBQuery
    Transaction = IBTr
    Left = 152
    Top = 144
    qoStartTransaction = True
  end
end
