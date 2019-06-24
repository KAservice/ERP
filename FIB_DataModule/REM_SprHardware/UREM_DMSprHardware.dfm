object REM_DMSprHardware: TREM_DMSprHardware
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 426
  Width = 540
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
      'select *'
      'from REM_SHARDWARE_GET_TABLE_FULL ('
      '    :PARAM_IDGRP,'
      '    :PARAM_FL_ALL,'
      '    :PARAM_FL_POISK,'
      '    :PARAM_FL_OST,'
      '    :PARAM_STR_PARAM,'
      '    :PARAM_IDFIRM,'
      '    :PARAM_IDSKLAD,'
      '    :PARAM_IDTNOM)'
      'ORDER BY REM_SHARDWARE_GET_TABLE_FULL.NAME_REM_SHARDWARE')
    Transaction = IBTr
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object TableID_REM_SHARDWARE: TFIBLargeIntField
      FieldName = 'ID_REM_SHARDWARE'
    end
    object TableNAME_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'NAME_REM_SHARDWARE'
      Size = 200
    end
    object TableSERNUM_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'SERNUM_REM_SHARDWARE'
      Size = 50
    end
    object TableCODE_REM_SHARDWARE: TFIBIntegerField
      FieldName = 'CODE_REM_SHARDWARE'
    end
    object TableSROKWARRANTY_REM_SHARDWARE: TFIBIntegerField
      FieldName = 'SROKWARRANTY_REM_SHARDWARE'
    end
    object TableSERNUM2_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'SERNUM2_REM_SHARDWARE'
      Size = 50
    end
    object TableSERNUM_STR_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'SERNUM_STR_REM_SHARDWARE'
      Size = 200
    end
    object TableFL_NECOND_REM_SHARDWARE: TFIBSmallIntField
      FieldName = 'FL_NECOND_REM_SHARDWARE'
    end
    object TablePRICE_REM_SHARDWARE: TFIBBCDField
      FieldName = 'PRICE_REM_SHARDWARE'
      Size = 2
      RoundByScale = True
    end
    object TableFL_FICT_REMONT_REM_SHARDWARE: TFIBSmallIntField
      FieldName = 'FL_FICT_REMONT_REM_SHARDWARE'
    end
    object TableFL_REMONT_REM_SHARDWARE: TFIBSmallIntField
      FieldName = 'FL_REMONT_REM_SHARDWARE'
    end
    object TableFL_ACT_REM_SHARDWARE: TFIBSmallIntField
      FieldName = 'FL_ACT_REM_SHARDWARE'
    end
    object TableNAME_ENG_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SHARDWARE'
      Size = 200
    end
    object TableARTIKUL_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'ARTIKUL_REM_SHARDWARE'
      Size = 40
    end
    object TablePARTNUM_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'PARTNUM_REM_SHARDWARE'
      Size = 50
    end
    object TableOUT_IDFIRM: TFIBLargeIntField
      FieldName = 'OUT_IDFIRM'
    end
    object TableOUT_NAME_FIRM: TFIBWideStringField
      FieldName = 'OUT_NAME_FIRM'
      Size = 200
    end
    object TableOUT_IDSKLAD: TFIBLargeIntField
      FieldName = 'OUT_IDSKLAD'
    end
    object TableOUT_NAME_SKLAD: TFIBWideStringField
      FieldName = 'OUT_NAME_SKLAD'
      Size = 200
    end
    object TableOUT_IDTNOM: TFIBLargeIntField
      FieldName = 'OUT_IDTNOM'
    end
    object TableOUT_NAME_TYPE_NOM: TFIBWideStringField
      FieldName = 'OUT_NAME_TYPE_NOM'
      Size = 200
    end
    object TableOUT_OST: TFIBBCDField
      FieldName = 'OUT_OST'
      Size = 3
      RoundByScale = True
    end
    object TableIDGRP_REM_SHARDWARE: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SHARDWARE'
    end
    object TableOUT_IDMHRAN: TFIBLargeIntField
      FieldName = 'OUT_IDMHRAN'
    end
    object TableOUT_NAME_MHRAN: TFIBWideStringField
      FieldName = 'OUT_NAME_MHRAN'
      Size = 200
    end
    object TableOUT_FL_OTCH_PROIZV: TFIBSmallIntField
      FieldName = 'OUT_FL_OTCH_PROIZV'
    end
    object TableOUT_FL_NO_RAZBOR: TFIBSmallIntField
      FieldName = 'OUT_FL_NO_RAZBOR'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_SHARDWARE'
      'SET '
      '    IDBASE_REM_SHARDWARE = :IDBASE_REM_SHARDWARE,'
      '    NAME_REM_SHARDWARE = :NAME_REM_SHARDWARE,'
      '    IDGRP_REM_SHARDWARE = :IDGRP_REM_SHARDWARE,'
      '    IDMODEL_REM_SHARDWARE = :IDMODEL_REM_SHARDWARE,'
      '    IDPOST_REM_SHARDWARE = :IDPOST_REM_SHARDWARE,'
      '    TYPESYSPOST_REM_SHARDWARE = :TYPESYSPOST_REM_SHARDWARE,'
      '    IDDOCPOST_REM_SHARDWARE = :IDDOCPOST_REM_SHARDWARE,'
      '    SERNUM_REM_SHARDWARE = :SERNUM_REM_SHARDWARE,'
      '    WARRANTY_REM_SHARDWARE = :WARRANTY_REM_SHARDWARE,'
      '    SALE_REM_SHARDWARE = :SALE_REM_SHARDWARE,'
      '    IDVLAD_REM_SHARDWARE = :IDVLAD_REM_SHARDWARE,'
      '    NAMEVLAD_REM_SHARDWARE = :NAMEVLAD_REM_SHARDWARE,'
      '    TYPESYSSALE_REM_SHARDWARE = :TYPESYSSALE_REM_SHARDWARE,'
      '    IDDOCSALE_REM_SHARDWARE = :IDDOCSALE_REM_SHARDWARE,'
      '    CODE_REM_SHARDWARE = :CODE_REM_SHARDWARE,'
      '    SROKWARRANTY_REM_SHARDWARE = :SROKWARRANTY_REM_SHARDWARE,'
      '    IDDOCREM_SALE_REM_SHARDWARE = :IDDOCREM_SALE_REM_SHARDWARE,'
      '    SERNUM2_REM_SHARDWARE = :SERNUM2_REM_SHARDWARE,'
      '    SERNUM_STR_REM_SHARDWARE = :SERNUM_STR_REM_SHARDWARE,'
      '    FL_NECOND_REM_SHARDWARE = :FL_NECOND_REM_SHARDWARE,'
      '    PRICE_REM_SHARDWARE = :PRICE_REM_SHARDWARE,'
      '    PRICHINA_REM_SHARDWARE = :PRICHINA_REM_SHARDWARE,'
      '    PRIM_REM_SHARDWARE = :PRIM_REM_SHARDWARE,'
      
        '    FL_FICT_REMONT_REM_SHARDWARE = :FL_FICT_REMONT_REM_SHARDWARE' +
        ','
      '    FL_REMONT_REM_SHARDWARE = :FL_REMONT_REM_SHARDWARE,'
      '    IDPRODUCER_REM_SHARDWARE = :IDPRODUCER_REM_SHARDWARE,'
      '    IDBRAND_REM_SHARDWARE = :IDBRAND_REM_SHARDWARE,'
      '    IDZ_REM_SHARDWARE = :IDZ_REM_SHARDWARE,'
      '    TYPE_ELEMENTA_REM_SHARDWARE = :TYPE_ELEMENTA_REM_SHARDWARE,'
      '    FL_ACT_REM_SHARDWARE = :FL_ACT_REM_SHARDWARE,'
      '    FL_UTILIZ_REM_SHARDWARE = :FL_UTILIZ_REM_SHARDWARE,'
      '    POS_POST_REM_SHARDWARE = :POS_POST_REM_SHARDWARE,'
      '    POS_UTILIZ_REM_SHARDWARE = :POS_UTILIZ_REM_SHARDWARE,'
      '    POS_HRAN_DO_REM_SHARDWARE = :POS_HRAN_DO_REM_SHARDWARE,'
      '    IDPRMODEL_REM_SHARDWARE = :IDPRMODEL_REM_SHARDWARE,'
      '    SERNUM3_REM_SHARDWARE = :SERNUM3_REM_SHARDWARE,'
      '    SERNUM4_REM_SHARDWARE = :SERNUM4_REM_SHARDWARE,'
      '    NUMBAT_REM_SHARDWARE = :NUMBAT_REM_SHARDWARE,'
      '    NUMGARTALON_REM_SHARDWARE = :NUMGARTALON_REM_SHARDWARE,'
      '    SWCODE_REM_SHARDWARE = :SWCODE_REM_SHARDWARE,'
      '    HWCODE_REM_SHARDWARE = :HWCODE_REM_SHARDWARE,'
      '    VERPO_REM_SHARDWARE = :VERPO_REM_SHARDWARE,'
      '    PARTNUM_REM_SHARDWARE = :PARTNUM_REM_SHARDWARE,'
      '    MTM_REM_SHARDWARE = :MTM_REM_SHARDWARE,'
      '    FRU_REM_SHARDWARE = :FRU_REM_SHARDWARE,'
      '    NAME_ENG_REM_SHARDWARE = :NAME_ENG_REM_SHARDWARE,'
      '    CRU_REM_SHARDWARE = :CRU_REM_SHARDWARE,'
      '    ARTIKUL_REM_SHARDWARE = :ARTIKUL_REM_SHARDWARE,'
      
        '    FL_OTCH_PROIZV_REM_SHARDWARE = :FL_OTCH_PROIZV_REM_SHARDWARE' +
        ','
      '    FL_NO_RAZBOR_REM_SHARDWARE = :FL_NO_RAZBOR_REM_SHARDWARE'
      'WHERE'
      '    ID_REM_SHARDWARE = :OLD_ID_REM_SHARDWARE'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_SHARDWARE'
      'WHERE'
      '        ID_REM_SHARDWARE = :OLD_ID_REM_SHARDWARE'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_SHARDWARE('
      '    ID_REM_SHARDWARE,'
      '    IDBASE_REM_SHARDWARE,'
      '    NAME_REM_SHARDWARE,'
      '    IDGRP_REM_SHARDWARE,'
      '    IDMODEL_REM_SHARDWARE,'
      '    IDPOST_REM_SHARDWARE,'
      '    TYPESYSPOST_REM_SHARDWARE,'
      '    IDDOCPOST_REM_SHARDWARE,'
      '    SERNUM_REM_SHARDWARE,'
      '    WARRANTY_REM_SHARDWARE,'
      '    SALE_REM_SHARDWARE,'
      '    IDVLAD_REM_SHARDWARE,'
      '    NAMEVLAD_REM_SHARDWARE,'
      '    TYPESYSSALE_REM_SHARDWARE,'
      '    IDDOCSALE_REM_SHARDWARE,'
      '    CODE_REM_SHARDWARE,'
      '    SROKWARRANTY_REM_SHARDWARE,'
      '    IDDOCREM_SALE_REM_SHARDWARE,'
      '    SERNUM2_REM_SHARDWARE,'
      '    SERNUM_STR_REM_SHARDWARE,'
      '    FL_NECOND_REM_SHARDWARE,'
      '    PRICE_REM_SHARDWARE,'
      '    PRICHINA_REM_SHARDWARE,'
      '    PRIM_REM_SHARDWARE,'
      '    FL_FICT_REMONT_REM_SHARDWARE,'
      '    FL_REMONT_REM_SHARDWARE,'
      '    IDPRODUCER_REM_SHARDWARE,'
      '    IDBRAND_REM_SHARDWARE,'
      '    IDZ_REM_SHARDWARE,'
      '    TYPE_ELEMENTA_REM_SHARDWARE,'
      '    FL_ACT_REM_SHARDWARE,'
      '    FL_UTILIZ_REM_SHARDWARE,'
      '    POS_POST_REM_SHARDWARE,'
      '    POS_UTILIZ_REM_SHARDWARE,'
      '    POS_HRAN_DO_REM_SHARDWARE,'
      '    IDPRMODEL_REM_SHARDWARE,'
      '    SERNUM3_REM_SHARDWARE,'
      '    SERNUM4_REM_SHARDWARE,'
      '    NUMBAT_REM_SHARDWARE,'
      '    NUMGARTALON_REM_SHARDWARE,'
      '    SWCODE_REM_SHARDWARE,'
      '    HWCODE_REM_SHARDWARE,'
      '    VERPO_REM_SHARDWARE,'
      '    PARTNUM_REM_SHARDWARE,'
      '    MTM_REM_SHARDWARE,'
      '    FRU_REM_SHARDWARE,'
      '    NAME_ENG_REM_SHARDWARE,'
      '    CRU_REM_SHARDWARE,'
      '    ARTIKUL_REM_SHARDWARE,'
      '    FL_OTCH_PROIZV_REM_SHARDWARE,'
      '    FL_NO_RAZBOR_REM_SHARDWARE'
      ')'
      'VALUES('
      '    :ID_REM_SHARDWARE,'
      '    :IDBASE_REM_SHARDWARE,'
      '    :NAME_REM_SHARDWARE,'
      '    :IDGRP_REM_SHARDWARE,'
      '    :IDMODEL_REM_SHARDWARE,'
      '    :IDPOST_REM_SHARDWARE,'
      '    :TYPESYSPOST_REM_SHARDWARE,'
      '    :IDDOCPOST_REM_SHARDWARE,'
      '    :SERNUM_REM_SHARDWARE,'
      '    :WARRANTY_REM_SHARDWARE,'
      '    :SALE_REM_SHARDWARE,'
      '    :IDVLAD_REM_SHARDWARE,'
      '    :NAMEVLAD_REM_SHARDWARE,'
      '    :TYPESYSSALE_REM_SHARDWARE,'
      '    :IDDOCSALE_REM_SHARDWARE,'
      '    :CODE_REM_SHARDWARE,'
      '    :SROKWARRANTY_REM_SHARDWARE,'
      '    :IDDOCREM_SALE_REM_SHARDWARE,'
      '    :SERNUM2_REM_SHARDWARE,'
      '    :SERNUM_STR_REM_SHARDWARE,'
      '    :FL_NECOND_REM_SHARDWARE,'
      '    :PRICE_REM_SHARDWARE,'
      '    :PRICHINA_REM_SHARDWARE,'
      '    :PRIM_REM_SHARDWARE,'
      '    :FL_FICT_REMONT_REM_SHARDWARE,'
      '    :FL_REMONT_REM_SHARDWARE,'
      '    :IDPRODUCER_REM_SHARDWARE,'
      '    :IDBRAND_REM_SHARDWARE,'
      '    :IDZ_REM_SHARDWARE,'
      '    :TYPE_ELEMENTA_REM_SHARDWARE,'
      '    :FL_ACT_REM_SHARDWARE,'
      '    :FL_UTILIZ_REM_SHARDWARE,'
      '    :POS_POST_REM_SHARDWARE,'
      '    :POS_UTILIZ_REM_SHARDWARE,'
      '    :POS_HRAN_DO_REM_SHARDWARE,'
      '    :IDPRMODEL_REM_SHARDWARE,'
      '    :SERNUM3_REM_SHARDWARE,'
      '    :SERNUM4_REM_SHARDWARE,'
      '    :NUMBAT_REM_SHARDWARE,'
      '    :NUMGARTALON_REM_SHARDWARE,'
      '    :SWCODE_REM_SHARDWARE,'
      '    :HWCODE_REM_SHARDWARE,'
      '    :VERPO_REM_SHARDWARE,'
      '    :PARTNUM_REM_SHARDWARE,'
      '    :MTM_REM_SHARDWARE,'
      '    :FRU_REM_SHARDWARE,'
      '    :NAME_ENG_REM_SHARDWARE,'
      '    :CRU_REM_SHARDWARE,'
      '    :ARTIKUL_REM_SHARDWARE,'
      '    :FL_OTCH_PROIZV_REM_SHARDWARE,'
      '    :FL_NO_RAZBOR_REM_SHARDWARE'
      ')')
    RefreshSQL.Strings = (
      'select REM_SHARDWARE.*,'
      '    rem_smodel.name_rem_smodel,'
      '    SUPPLIER.NAMEKLIENT as SUPPLIER_NAME,'
      '    OWNER.NAMEKLIENT as OWNER_NAME,'
      '    DOCPOST.tdoc as TDOC_DOCPOST,'
      '    DOCPOST.posdoc as POSDOC_DOCPOST,'
      '    DOCPOST.numdoc as NUMDOC_DOCPOST,'
      '    DOCSALE.tdoc as TDOC_DOCSALE,'
      '    DOCSALE.posdoc as POSDOC_DOCSALE,'
      '    DOCSALE.numdoc as NUMDOC_DOCSALE,'
      ''
      '    sbrand.name_sbrand,'
      '    sproducer.name_sproducer,'
      '    rem_z.name_rem_z,'
      '    rem_z.prefiks_num_rem_z,'
      '    rem_z.pos_rem_z,'
      '    rem_z.num_rem_z,'
      '    rem_z.model_rem_z,'
      '    rem_z.sernum_rem_z,'
      '    rem_sprmodel.name_rem_sprmodel'
      'from rem_shardware'
      
        'left outer join rem_smodel on rem_shardware.idmodel_rem_shardwar' +
        'e=rem_smodel.id_rem_smodel'
      
        'left outer join sklient as SUPPLIER on rem_shardware.idpost_rem_' +
        'shardware=SUPPLIER.IDKLIENT'
      
        'left outer join sklient as OWNER on rem_shardware.idvlad_rem_sha' +
        'rdware=OWNER.IDKLIENT'
      
        'left outer join galldoc as DOCPOST on rem_shardware.iddocpost_re' +
        'm_shardware=DOCPOST.iddoc'
      
        'left outer join galldoc as DOCSALE on rem_shardware.iddocsale_re' +
        'm_shardware=DOCSALE.iddoc'
      ''
      ''
      
        'left outer join sbrand on sbrand.id_sbrand=REM_SHARDWARE.idbrand' +
        '_rem_shardware'
      
        'left outer join sproducer on  REM_SHARDWARE.idproducer_rem_shard' +
        'ware=sproducer.id_sproducer'
      
        'left outer join rem_z on  REM_SHARDWARE.idz_rem_shardware=rem_z.' +
        'id_rem_z'
      
        'left outer join rem_sprmodel on REM_SHARDWARE.idprmodel_rem_shar' +
        'dware=rem_sprmodel.id_rem_sprmodel'
      'where(  rem_shardware.id_rem_shardware=:PARAM_ID'
      
        '     ) and (     REM_SHARDWARE.ID_REM_SHARDWARE = :OLD_ID_REM_SH' +
        'ARDWARE'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select REM_SHARDWARE.*,'
      '    rem_smodel.name_rem_smodel,'
      '    SUPPLIER.NAMEKLIENT as SUPPLIER_NAME,'
      '    OWNER.NAMEKLIENT as OWNER_NAME,'
      '    DOCPOST.tdoc as TDOC_DOCPOST,'
      '    DOCPOST.posdoc as POSDOC_DOCPOST,'
      '    DOCPOST.numdoc as NUMDOC_DOCPOST,'
      '    DOCSALE.tdoc as TDOC_DOCSALE,'
      '    DOCSALE.posdoc as POSDOC_DOCSALE,'
      '    DOCSALE.numdoc as NUMDOC_DOCSALE,'
      ''
      '    sbrand.name_sbrand,'
      '    sproducer.name_sproducer,'
      '    rem_z.name_rem_z,'
      '    rem_z.prefiks_num_rem_z,'
      '    rem_z.pos_rem_z,'
      '    rem_z.num_rem_z,'
      '    rem_z.model_rem_z,'
      '    rem_z.sernum_rem_z,'
      '    rem_sprmodel.name_rem_sprmodel'
      'from rem_shardware'
      
        'left outer join rem_smodel on rem_shardware.idmodel_rem_shardwar' +
        'e=rem_smodel.id_rem_smodel'
      
        'left outer join sklient as SUPPLIER on rem_shardware.idpost_rem_' +
        'shardware=SUPPLIER.IDKLIENT'
      
        'left outer join sklient as OWNER on rem_shardware.idvlad_rem_sha' +
        'rdware=OWNER.IDKLIENT'
      
        'left outer join galldoc as DOCPOST on rem_shardware.iddocpost_re' +
        'm_shardware=DOCPOST.iddoc'
      
        'left outer join galldoc as DOCSALE on rem_shardware.iddocsale_re' +
        'm_shardware=DOCSALE.iddoc'
      ''
      ''
      
        'left outer join sbrand on sbrand.id_sbrand=REM_SHARDWARE.idbrand' +
        '_rem_shardware'
      
        'left outer join sproducer on  REM_SHARDWARE.idproducer_rem_shard' +
        'ware=sproducer.id_sproducer'
      
        'left outer join rem_z on  REM_SHARDWARE.idz_rem_shardware=rem_z.' +
        'id_rem_z'
      
        'left outer join rem_sprmodel on REM_SHARDWARE.idprmodel_rem_shar' +
        'dware=rem_sprmodel.id_rem_sprmodel'
      'where rem_shardware.id_rem_shardware=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_SHARDWARE'
    AutoUpdateOptions.KeyFields = 'ID_REM_SHARDWARE'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SHARDWARE_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object ElementID_REM_SHARDWARE: TFIBLargeIntField
      FieldName = 'ID_REM_SHARDWARE'
    end
    object ElementIDBASE_REM_SHARDWARE: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SHARDWARE'
    end
    object ElementNAME_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'NAME_REM_SHARDWARE'
      Size = 200
    end
    object ElementIDGRP_REM_SHARDWARE: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SHARDWARE'
    end
    object ElementIDMODEL_REM_SHARDWARE: TFIBLargeIntField
      FieldName = 'IDMODEL_REM_SHARDWARE'
    end
    object ElementIDPOST_REM_SHARDWARE: TFIBLargeIntField
      FieldName = 'IDPOST_REM_SHARDWARE'
    end
    object ElementTYPESYSPOST_REM_SHARDWARE: TFIBSmallIntField
      FieldName = 'TYPESYSPOST_REM_SHARDWARE'
    end
    object ElementIDDOCPOST_REM_SHARDWARE: TFIBLargeIntField
      FieldName = 'IDDOCPOST_REM_SHARDWARE'
    end
    object ElementSERNUM_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'SERNUM_REM_SHARDWARE'
      Size = 50
    end
    object ElementWARRANTY_REM_SHARDWARE: TFIBDateField
      FieldName = 'WARRANTY_REM_SHARDWARE'
    end
    object ElementSALE_REM_SHARDWARE: TFIBDateField
      FieldName = 'SALE_REM_SHARDWARE'
    end
    object ElementIDVLAD_REM_SHARDWARE: TFIBLargeIntField
      FieldName = 'IDVLAD_REM_SHARDWARE'
    end
    object ElementNAMEVLAD_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'NAMEVLAD_REM_SHARDWARE'
      Size = 200
    end
    object ElementTYPESYSSALE_REM_SHARDWARE: TFIBSmallIntField
      FieldName = 'TYPESYSSALE_REM_SHARDWARE'
    end
    object ElementIDDOCSALE_REM_SHARDWARE: TFIBLargeIntField
      FieldName = 'IDDOCSALE_REM_SHARDWARE'
    end
    object ElementCODE_REM_SHARDWARE: TFIBIntegerField
      FieldName = 'CODE_REM_SHARDWARE'
    end
    object ElementSROKWARRANTY_REM_SHARDWARE: TFIBIntegerField
      FieldName = 'SROKWARRANTY_REM_SHARDWARE'
    end
    object ElementIDDOCREM_SALE_REM_SHARDWARE: TFIBLargeIntField
      FieldName = 'IDDOCREM_SALE_REM_SHARDWARE'
    end
    object ElementSERNUM2_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'SERNUM2_REM_SHARDWARE'
      Size = 50
    end
    object ElementSERNUM_STR_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'SERNUM_STR_REM_SHARDWARE'
      Size = 200
    end
    object ElementFL_NECOND_REM_SHARDWARE: TFIBSmallIntField
      FieldName = 'FL_NECOND_REM_SHARDWARE'
    end
    object ElementPRICE_REM_SHARDWARE: TFIBBCDField
      FieldName = 'PRICE_REM_SHARDWARE'
      Size = 2
      RoundByScale = True
    end
    object ElementPRICHINA_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'PRICHINA_REM_SHARDWARE'
      Size = 150
    end
    object ElementPRIM_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'PRIM_REM_SHARDWARE'
      Size = 150
    end
    object ElementFL_FICT_REMONT_REM_SHARDWARE: TFIBSmallIntField
      FieldName = 'FL_FICT_REMONT_REM_SHARDWARE'
    end
    object ElementFL_REMONT_REM_SHARDWARE: TFIBSmallIntField
      FieldName = 'FL_REMONT_REM_SHARDWARE'
    end
    object ElementIDPRODUCER_REM_SHARDWARE: TFIBLargeIntField
      FieldName = 'IDPRODUCER_REM_SHARDWARE'
    end
    object ElementIDBRAND_REM_SHARDWARE: TFIBLargeIntField
      FieldName = 'IDBRAND_REM_SHARDWARE'
    end
    object ElementIDZ_REM_SHARDWARE: TFIBLargeIntField
      FieldName = 'IDZ_REM_SHARDWARE'
    end
    object ElementTYPE_ELEMENTA_REM_SHARDWARE: TFIBIntegerField
      FieldName = 'TYPE_ELEMENTA_REM_SHARDWARE'
    end
    object ElementFL_ACT_REM_SHARDWARE: TFIBSmallIntField
      FieldName = 'FL_ACT_REM_SHARDWARE'
    end
    object ElementFL_UTILIZ_REM_SHARDWARE: TFIBSmallIntField
      FieldName = 'FL_UTILIZ_REM_SHARDWARE'
    end
    object ElementPOS_POST_REM_SHARDWARE: TFIBDateTimeField
      FieldName = 'POS_POST_REM_SHARDWARE'
    end
    object ElementPOS_UTILIZ_REM_SHARDWARE: TFIBDateTimeField
      FieldName = 'POS_UTILIZ_REM_SHARDWARE'
    end
    object ElementPOS_HRAN_DO_REM_SHARDWARE: TFIBDateTimeField
      FieldName = 'POS_HRAN_DO_REM_SHARDWARE'
    end
    object ElementIDPRMODEL_REM_SHARDWARE: TFIBLargeIntField
      FieldName = 'IDPRMODEL_REM_SHARDWARE'
    end
    object ElementNAME_REM_SMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SMODEL'
      Size = 200
    end
    object ElementSUPPLIER_NAME: TFIBWideStringField
      FieldName = 'SUPPLIER_NAME'
      Size = 200
    end
    object ElementOWNER_NAME: TFIBWideStringField
      FieldName = 'OWNER_NAME'
      Size = 200
    end
    object ElementTDOC_DOCPOST: TFIBWideStringField
      FieldName = 'TDOC_DOCPOST'
      Size = 15
    end
    object ElementPOSDOC_DOCPOST: TFIBDateTimeField
      FieldName = 'POSDOC_DOCPOST'
    end
    object ElementNUMDOC_DOCPOST: TFIBIntegerField
      FieldName = 'NUMDOC_DOCPOST'
    end
    object ElementTDOC_DOCSALE: TFIBWideStringField
      FieldName = 'TDOC_DOCSALE'
      Size = 15
    end
    object ElementPOSDOC_DOCSALE: TFIBDateTimeField
      FieldName = 'POSDOC_DOCSALE'
    end
    object ElementNUMDOC_DOCSALE: TFIBIntegerField
      FieldName = 'NUMDOC_DOCSALE'
    end
    object ElementNAME_SBRAND: TFIBWideStringField
      FieldName = 'NAME_SBRAND'
      Size = 200
    end
    object ElementNAME_SPRODUCER: TFIBWideStringField
      FieldName = 'NAME_SPRODUCER'
      Size = 200
    end
    object ElementNAME_REM_Z: TFIBWideStringField
      FieldName = 'NAME_REM_Z'
      Size = 200
    end
    object ElementPREFIKS_NUM_REM_Z: TFIBWideStringField
      FieldName = 'PREFIKS_NUM_REM_Z'
      Size = 12
    end
    object ElementPOS_REM_Z: TFIBDateTimeField
      FieldName = 'POS_REM_Z'
    end
    object ElementNUM_REM_Z: TFIBIntegerField
      FieldName = 'NUM_REM_Z'
    end
    object ElementMODEL_REM_Z: TFIBWideStringField
      FieldName = 'MODEL_REM_Z'
      Size = 40
    end
    object ElementSERNUM_REM_Z: TFIBWideStringField
      FieldName = 'SERNUM_REM_Z'
      Size = 50
    end
    object ElementNAME_REM_SPRMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SPRMODEL'
      Size = 200
    end
    object ElementSERNUM3_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'SERNUM3_REM_SHARDWARE'
      Size = 50
    end
    object ElementSERNUM4_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'SERNUM4_REM_SHARDWARE'
      Size = 50
    end
    object ElementNUMBAT_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'NUMBAT_REM_SHARDWARE'
      Size = 50
    end
    object ElementNUMGARTALON_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'NUMGARTALON_REM_SHARDWARE'
      Size = 50
    end
    object ElementSWCODE_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'SWCODE_REM_SHARDWARE'
      Size = 50
    end
    object ElementHWCODE_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'HWCODE_REM_SHARDWARE'
      Size = 50
    end
    object ElementVERPO_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'VERPO_REM_SHARDWARE'
      Size = 50
    end
    object ElementPARTNUM_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'PARTNUM_REM_SHARDWARE'
      Size = 50
    end
    object ElementMTM_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'MTM_REM_SHARDWARE'
      Size = 50
    end
    object ElementFRU_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'FRU_REM_SHARDWARE'
      Size = 50
    end
    object ElementNAME_ENG_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SHARDWARE'
      Size = 200
    end
    object ElementCRU_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'CRU_REM_SHARDWARE'
      Size = 50
    end
    object ElementARTIKUL_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'ARTIKUL_REM_SHARDWARE'
      Size = 40
    end
    object ElementFL_OTCH_PROIZV_REM_SHARDWARE: TFIBSmallIntField
      FieldName = 'FL_OTCH_PROIZV_REM_SHARDWARE'
    end
    object ElementFL_NO_RAZBOR_REM_SHARDWARE: TFIBSmallIntField
      FieldName = 'FL_NO_RAZBOR_REM_SHARDWARE'
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
    Left = 160
    Top = 144
    qoStartTransaction = True
  end
end
