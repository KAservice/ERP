object REM_DMDocZAktPr: TREM_DMDocZAktPr
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 439
  Width = 667
  object DataSourceDoc: TDataSource
    DataSet = Doc
    Left = 72
    Top = 64
  end
  object DataSourceDocT: TDataSource
    DataSet = DocT
    Left = 72
    Top = 112
  end
  object DataSourceDocAll: TDataSource
    DataSet = DocAll
    Left = 72
    Top = 16
  end
  object DocAll: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_GALLDOC'
      'SET '
      '    IDBASE_REM_GALLDOC = :IDBASE_REM_GALLDOC,'
      '    IDFIRM_REM_GALLDOC = :IDFIRM_REM_GALLDOC,'
      '    IDSKLAD_REM_GALLDOC = :IDSKLAD_REM_GALLDOC,'
      '    IDKLIENT_REM_GALLDOC = :IDKLIENT_REM_GALLDOC,'
      '    IDUSER_REM_GALLDOC = :IDUSER_REM_GALLDOC,'
      '    POS_REM_GALLDOC = :POS_REM_GALLDOC,'
      '    NUM_REM_GALLDOC = :NUM_REM_GALLDOC,'
      '    PR_REM_GALLDOC = :PR_REM_GALLDOC,'
      '    TDOC_REM_GALLDOC = :TDOC_REM_GALLDOC,'
      '    IDDOCOSN_REM_GALLDOC = :IDDOCOSN_REM_GALLDOC,'
      '    TYPEEXTDOC_REM_GALLDOC = :TYPEEXTDOC_REM_GALLDOC,'
      '    IDEXTDOC_REM_GALLDOC = :IDEXTDOC_REM_GALLDOC,'
      '    SUM_REM_GALLDOC = :SUM_REM_GALLDOC,'
      '    IDPROJECT_REM_GALLDOC = :IDPROJECT_REM_GALLDOC,'
      '    IDBUSINOP_REM_GALLDOC = :IDBUSINOP_REM_GALLDOC,'
      '    PREFIKS_NUM_REM_GALLDOC = :PREFIKS_NUM_REM_GALLDOC,'
      '    IDOBJECT_REM_GALLDOC = :IDOBJECT_REM_GALLDOC'
      'WHERE'
      '    ID_REM_GALLDOC = :OLD_ID_REM_GALLDOC'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_GALLDOC'
      'WHERE'
      '        ID_REM_GALLDOC = :OLD_ID_REM_GALLDOC'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_GALLDOC('
      '    ID_REM_GALLDOC,'
      '    IDBASE_REM_GALLDOC,'
      '    IDFIRM_REM_GALLDOC,'
      '    IDSKLAD_REM_GALLDOC,'
      '    IDKLIENT_REM_GALLDOC,'
      '    IDUSER_REM_GALLDOC,'
      '    POS_REM_GALLDOC,'
      '    NUM_REM_GALLDOC,'
      '    PR_REM_GALLDOC,'
      '    TDOC_REM_GALLDOC,'
      '    IDDOCOSN_REM_GALLDOC,'
      '    TYPEEXTDOC_REM_GALLDOC,'
      '    IDEXTDOC_REM_GALLDOC,'
      '    SUM_REM_GALLDOC,'
      '    IDPROJECT_REM_GALLDOC,'
      '    IDBUSINOP_REM_GALLDOC,'
      '    PREFIKS_NUM_REM_GALLDOC,'
      '    IDOBJECT_REM_GALLDOC'
      ')'
      'VALUES('
      '    :ID_REM_GALLDOC,'
      '    :IDBASE_REM_GALLDOC,'
      '    :IDFIRM_REM_GALLDOC,'
      '    :IDSKLAD_REM_GALLDOC,'
      '    :IDKLIENT_REM_GALLDOC,'
      '    :IDUSER_REM_GALLDOC,'
      '    :POS_REM_GALLDOC,'
      '    :NUM_REM_GALLDOC,'
      '    :PR_REM_GALLDOC,'
      '    :TDOC_REM_GALLDOC,'
      '    :IDDOCOSN_REM_GALLDOC,'
      '    :TYPEEXTDOC_REM_GALLDOC,'
      '    :IDEXTDOC_REM_GALLDOC,'
      '    :SUM_REM_GALLDOC,'
      '    :IDPROJECT_REM_GALLDOC,'
      '    :IDBUSINOP_REM_GALLDOC,'
      '    :PREFIKS_NUM_REM_GALLDOC,'
      '    :IDOBJECT_REM_GALLDOC'
      ')')
    RefreshSQL.Strings = (
      'select rem_galldoc.*,'
      ' suser.fname_user ,'
      ' sinfbase_obmen.name_sinfbase_obmen,'
      ' sfirm.namefirm,'
      ' ssklad.namesklad,'
      ' sklient.nameklient,'
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper,'
      ' sobject.name_sobject'
      'from '
      '  rem_galldoc'
      
        'left outer join SUSER on rem_galldoc.iduser_rem_galldoc=suser.id' +
        '_user'
      
        'left outer join SINFBASE_OBMEN on sinfbase_obmen.id_sinfbase_obm' +
        'en=rem_galldoc.idbase_rem_galldoc'
      
        'left outer join SFIRM on rem_galldoc.idfirm_rem_galldoc=sfirm.id' +
        'firm'
      
        'left outer join SSKLAD on rem_galldoc.idsklad_rem_galldoc=ssklad' +
        '.idsklad'
      
        'left outer join SKLIENT on rem_galldoc.idklient_rem_galldoc=skli' +
        'ent.idklient'
      
        'left outer join SPROJECT on rem_galldoc.idproject_rem_galldoc=sp' +
        'roject.id_sproject'
      
        'left outer join sbusiness_oper on rem_galldoc.idbusinop_rem_gall' +
        'doc=sbusiness_oper.id_sbusiness_oper'
      
        'left outer join sobject on rem_galldoc.idobject_rem_galldoc=sobj' +
        'ect.id_sobject'
      'where(  '
      '  rem_galldoc.id_rem_galldoc=:PARAM_IDDOC'
      
        '     ) and (     REM_GALLDOC.ID_REM_GALLDOC = :OLD_ID_REM_GALLDO' +
        'C'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_galldoc.*,'
      ' suser.fname_user ,'
      ' sinfbase_obmen.name_sinfbase_obmen,'
      ' sfirm.namefirm,'
      ' ssklad.namesklad,'
      ' sklient.nameklient,'
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper,'
      ' sobject.name_sobject'
      'from '
      '  rem_galldoc'
      
        'left outer join SUSER on rem_galldoc.iduser_rem_galldoc=suser.id' +
        '_user'
      
        'left outer join SINFBASE_OBMEN on sinfbase_obmen.id_sinfbase_obm' +
        'en=rem_galldoc.idbase_rem_galldoc'
      
        'left outer join SFIRM on rem_galldoc.idfirm_rem_galldoc=sfirm.id' +
        'firm'
      
        'left outer join SSKLAD on rem_galldoc.idsklad_rem_galldoc=ssklad' +
        '.idsklad'
      
        'left outer join SKLIENT on rem_galldoc.idklient_rem_galldoc=skli' +
        'ent.idklient'
      
        'left outer join SPROJECT on rem_galldoc.idproject_rem_galldoc=sp' +
        'roject.id_sproject'
      
        'left outer join sbusiness_oper on rem_galldoc.idbusinop_rem_gall' +
        'doc=sbusiness_oper.id_sbusiness_oper'
      
        'left outer join sobject on rem_galldoc.idobject_rem_galldoc=sobj' +
        'ect.id_sobject'
      'where '
      '  rem_galldoc.id_rem_galldoc=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_GALLDOC'
    AutoUpdateOptions.KeyFields = 'ID_REM_GALLDOC'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_GALLDOC_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object DocAllID_REM_GALLDOC: TFIBLargeIntField
      FieldName = 'ID_REM_GALLDOC'
    end
    object DocAllIDBASE_REM_GALLDOC: TFIBLargeIntField
      FieldName = 'IDBASE_REM_GALLDOC'
      OnChange = DocAllIDBASE_REM_GALLDOCChange
    end
    object DocAllIDFIRM_REM_GALLDOC: TFIBLargeIntField
      FieldName = 'IDFIRM_REM_GALLDOC'
    end
    object DocAllIDSKLAD_REM_GALLDOC: TFIBLargeIntField
      FieldName = 'IDSKLAD_REM_GALLDOC'
    end
    object DocAllIDKLIENT_REM_GALLDOC: TFIBLargeIntField
      FieldName = 'IDKLIENT_REM_GALLDOC'
    end
    object DocAllIDUSER_REM_GALLDOC: TFIBLargeIntField
      FieldName = 'IDUSER_REM_GALLDOC'
    end
    object DocAllPOS_REM_GALLDOC: TFIBDateTimeField
      FieldName = 'POS_REM_GALLDOC'
      OnChange = DocAllPOS_REM_GALLDOCChange
      DisplayFormat = 'c'
    end
    object DocAllNUM_REM_GALLDOC: TFIBIntegerField
      FieldName = 'NUM_REM_GALLDOC'
    end
    object DocAllPR_REM_GALLDOC: TFIBSmallIntField
      FieldName = 'PR_REM_GALLDOC'
    end
    object DocAllTDOC_REM_GALLDOC: TFIBWideStringField
      FieldName = 'TDOC_REM_GALLDOC'
      Size = 15
    end
    object DocAllIDDOCOSN_REM_GALLDOC: TFIBLargeIntField
      FieldName = 'IDDOCOSN_REM_GALLDOC'
    end
    object DocAllTYPEEXTDOC_REM_GALLDOC: TFIBIntegerField
      FieldName = 'TYPEEXTDOC_REM_GALLDOC'
    end
    object DocAllIDEXTDOC_REM_GALLDOC: TFIBLargeIntField
      FieldName = 'IDEXTDOC_REM_GALLDOC'
    end
    object DocAllSUM_REM_GALLDOC: TFIBBCDField
      FieldName = 'SUM_REM_GALLDOC'
      Size = 2
      RoundByScale = True
    end
    object DocAllFNAME_USER: TFIBWideStringField
      FieldName = 'FNAME_USER'
      Size = 200
    end
    object DocAllNAME_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 200
    end
    object DocAllNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 200
    end
    object DocAllNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 200
    end
    object DocAllNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 200
    end
    object DocAllIDPROJECT_REM_GALLDOC: TFIBLargeIntField
      FieldName = 'IDPROJECT_REM_GALLDOC'
    end
    object DocAllIDBUSINOP_REM_GALLDOC: TFIBLargeIntField
      FieldName = 'IDBUSINOP_REM_GALLDOC'
    end
    object DocAllPREFIKS_NUM_REM_GALLDOC: TFIBWideStringField
      FieldName = 'PREFIKS_NUM_REM_GALLDOC'
      Size = 12
    end
    object DocAllNAME_SPROJECT: TFIBWideStringField
      FieldName = 'NAME_SPROJECT'
      Size = 200
    end
    object DocAllNAME_SBUSINESS_OPER: TFIBWideStringField
      FieldName = 'NAME_SBUSINESS_OPER'
      Size = 200
    end
    object DocAllIDOBJECT_REM_GALLDOC: TFIBLargeIntField
      FieldName = 'IDOBJECT_REM_GALLDOC'
    end
    object DocAllNAME_SOBJECT: TFIBWideStringField
      FieldName = 'NAME_SOBJECT'
      Size = 200
    end
  end
  object Doc: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_DZAKTPR'
      'SET '
      '    IDBASE_REM_DZAKTPR = :IDBASE_REM_DZAKTPR,'
      '    GID_REM_DZAKTPR = :GID_REM_DZAKTPR,'
      '    IDDOC_REM_DZAKTPR = :IDDOC_REM_DZAKTPR,'
      '    IDZ_REM_DZAKTPR = :IDZ_REM_DZAKTPR,'
      '    IDTPRICE_REM_DZAKTPR = :IDTPRICE_REM_DZAKTPR,'
      '    PRIM_REM_DZAKTPR = :PRIM_REM_DZAKTPR,'
      '    IDPR_REM_DZAKTPR = :IDPR_REM_DZAKTPR,'
      '    IDCFC_REM_DZAKTPR = :IDCFC_REM_DZAKTPR,'
      '    IDDFC_REM_DZAKTPR = :IDDFC_REM_DZAKTPR,'
      '    IDPRMODEL_REM_DZAKTPR = :IDPRMODEL_REM_DZAKTPR,'
      '    PODO_REM_DZAKTPR = :PODO_REM_DZAKTPR,'
      '    POPOSLE_REM_DZAKTPR = :POPOSLE_REM_DZAKTPR,'
      '    DESCR_REM_DZAKTPR = :DESCR_REM_DZAKTPR,'
      '    PRODAVEC_REM_DZAKTPR = :PRODAVEC_REM_DZAKTPR,'
      '    NUMGARTALON_REM_DZAKTPR = :NUMGARTALON_REM_DZAKTPR,'
      '    SERNUM3_REM_DZAKTPR = :SERNUM3_REM_DZAKTPR,'
      '    SERNUM4_REM_DZAKTPR = :SERNUM4_REM_DZAKTPR,'
      '    NUMBAT_REM_DZAKTPR = :NUMBAT_REM_DZAKTPR,'
      '    SOST_REM_DZAKTPR = :SOST_REM_DZAKTPR,'
      '    DATEVIPUSK_REM_DZAKTPR = :DATEVIPUSK_REM_DZAKTPR,'
      '    DATE_PRODAGI_REM_DZAKTPR = :DATE_PRODAGI_REM_DZAKTPR,'
      '    TYPE_REMONT_REM_DZAKTPR = :TYPE_REMONT_REM_DZAKTPR,'
      '    KEM_SDANO_REM_DZAKTPR = :KEM_SDANO_REM_DZAKTPR,'
      '    NEISPR_REM_DZAKTPR = :NEISPR_REM_DZAKTPR,'
      '    FL_FICTIV_REM_DZAKTPR = :FL_FICTIV_REM_DZAKTPR,'
      '    KLIENT_NAME_REM_DZAKTPR = :KLIENT_NAME_REM_DZAKTPR,'
      '    KLIENT_ADR_REM_DZAKTPR = :KLIENT_ADR_REM_DZAKTPR,'
      '    KLIENT_PHONE_REM_DZAKTPR = :KLIENT_PHONE_REM_DZAKTPR,'
      '    IDDILER_REM_DZAKTPR = :IDDILER_REM_DZAKTPR,'
      '    FL_OTCHET_POST_REM_DZAKTPR = :FL_OTCHET_POST_REM_DZAKTPR,'
      '    IDPOST_ZIP_REM_DZAKTPR = :IDPOST_ZIP_REM_DZAKTPR,'
      '    FL_NE_OTCH_REM_DZAKTPR = :FL_NE_OTCH_REM_DZAKTPR,'
      '    FL_NADO_OTCH_REM_DZAKTPR = :FL_NADO_OTCH_REM_DZAKTPR,'
      '    FL_PRIG_KREM_REM_DZAKTPR = :FL_PRIG_KREM_REM_DZAKTPR,'
      '    POSPRIEMA_REM_DZAKTPR = :POSPRIEMA_REM_DZAKTPR,'
      '    IDSELLER_REM_DZAKTPR = :IDSELLER_REM_DZAKTPR,'
      '    KLIENT_EMAIL_REM_DZAKTPR = :KLIENT_EMAIL_REM_DZAKTPR,'
      '    FAMILIYA_REM_DZAKTPR = :FAMILIYA_REM_DZAKTPR,'
      '    IMYA_REM_DZAKTPR = :IMYA_REM_DZAKTPR,'
      '    OTCHESTVO_REM_DZAKTPR = :OTCHESTVO_REM_DZAKTPR,'
      
        '    FL_OST_NA_OTV_XRAN_REM_DZAKTPR = :FL_OST_NA_OTV_XRAN_REM_DZA' +
        'KTPR'
      'WHERE'
      '    ID_REM_DZAKTPR = :OLD_ID_REM_DZAKTPR'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DZAKTPR'
      'WHERE'
      '        ID_REM_DZAKTPR = :OLD_ID_REM_DZAKTPR'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DZAKTPR('
      '    ID_REM_DZAKTPR,'
      '    IDBASE_REM_DZAKTPR,'
      '    GID_REM_DZAKTPR,'
      '    IDDOC_REM_DZAKTPR,'
      '    IDZ_REM_DZAKTPR,'
      '    IDTPRICE_REM_DZAKTPR,'
      '    PRIM_REM_DZAKTPR,'
      '    IDPR_REM_DZAKTPR,'
      '    IDCFC_REM_DZAKTPR,'
      '    IDDFC_REM_DZAKTPR,'
      '    IDPRMODEL_REM_DZAKTPR,'
      '    PODO_REM_DZAKTPR,'
      '    POPOSLE_REM_DZAKTPR,'
      '    DESCR_REM_DZAKTPR,'
      '    PRODAVEC_REM_DZAKTPR,'
      '    NUMGARTALON_REM_DZAKTPR,'
      '    SERNUM3_REM_DZAKTPR,'
      '    SERNUM4_REM_DZAKTPR,'
      '    NUMBAT_REM_DZAKTPR,'
      '    SOST_REM_DZAKTPR,'
      '    DATEVIPUSK_REM_DZAKTPR,'
      '    DATE_PRODAGI_REM_DZAKTPR,'
      '    TYPE_REMONT_REM_DZAKTPR,'
      '    KEM_SDANO_REM_DZAKTPR,'
      '    NEISPR_REM_DZAKTPR,'
      '    FL_FICTIV_REM_DZAKTPR,'
      '    KLIENT_NAME_REM_DZAKTPR,'
      '    KLIENT_ADR_REM_DZAKTPR,'
      '    KLIENT_PHONE_REM_DZAKTPR,'
      '    IDDILER_REM_DZAKTPR,'
      '    FL_OTCHET_POST_REM_DZAKTPR,'
      '    IDPOST_ZIP_REM_DZAKTPR,'
      '    FL_NE_OTCH_REM_DZAKTPR,'
      '    FL_NADO_OTCH_REM_DZAKTPR,'
      '    FL_PRIG_KREM_REM_DZAKTPR,'
      '    POSPRIEMA_REM_DZAKTPR,'
      '    IDSELLER_REM_DZAKTPR,'
      '    KLIENT_EMAIL_REM_DZAKTPR,'
      '    FAMILIYA_REM_DZAKTPR,'
      '    IMYA_REM_DZAKTPR,'
      '    OTCHESTVO_REM_DZAKTPR,'
      '    FL_OST_NA_OTV_XRAN_REM_DZAKTPR'
      ')'
      'VALUES('
      '    :ID_REM_DZAKTPR,'
      '    :IDBASE_REM_DZAKTPR,'
      '    :GID_REM_DZAKTPR,'
      '    :IDDOC_REM_DZAKTPR,'
      '    :IDZ_REM_DZAKTPR,'
      '    :IDTPRICE_REM_DZAKTPR,'
      '    :PRIM_REM_DZAKTPR,'
      '    :IDPR_REM_DZAKTPR,'
      '    :IDCFC_REM_DZAKTPR,'
      '    :IDDFC_REM_DZAKTPR,'
      '    :IDPRMODEL_REM_DZAKTPR,'
      '    :PODO_REM_DZAKTPR,'
      '    :POPOSLE_REM_DZAKTPR,'
      '    :DESCR_REM_DZAKTPR,'
      '    :PRODAVEC_REM_DZAKTPR,'
      '    :NUMGARTALON_REM_DZAKTPR,'
      '    :SERNUM3_REM_DZAKTPR,'
      '    :SERNUM4_REM_DZAKTPR,'
      '    :NUMBAT_REM_DZAKTPR,'
      '    :SOST_REM_DZAKTPR,'
      '    :DATEVIPUSK_REM_DZAKTPR,'
      '    :DATE_PRODAGI_REM_DZAKTPR,'
      '    :TYPE_REMONT_REM_DZAKTPR,'
      '    :KEM_SDANO_REM_DZAKTPR,'
      '    :NEISPR_REM_DZAKTPR,'
      '    :FL_FICTIV_REM_DZAKTPR,'
      '    :KLIENT_NAME_REM_DZAKTPR,'
      '    :KLIENT_ADR_REM_DZAKTPR,'
      '    :KLIENT_PHONE_REM_DZAKTPR,'
      '    :IDDILER_REM_DZAKTPR,'
      '    :FL_OTCHET_POST_REM_DZAKTPR,'
      '    :IDPOST_ZIP_REM_DZAKTPR,'
      '    :FL_NE_OTCH_REM_DZAKTPR,'
      '    :FL_NADO_OTCH_REM_DZAKTPR,'
      '    :FL_PRIG_KREM_REM_DZAKTPR,'
      '    :POSPRIEMA_REM_DZAKTPR,'
      '    :IDSELLER_REM_DZAKTPR,'
      '    :KLIENT_EMAIL_REM_DZAKTPR,'
      '    :FAMILIYA_REM_DZAKTPR,'
      '    :IMYA_REM_DZAKTPR,'
      '    :OTCHESTVO_REM_DZAKTPR,'
      '    :FL_OST_NA_OTV_XRAN_REM_DZAKTPR'
      ')')
    RefreshSQL.Strings = (
      'select rem_dzaktpr.*,'
      '        rem_z.name_rem_z,'
      '        rem_z.num_rem_z,'
      '        rem_z.pos_rem_z,'
      '        rem_z.sernum_rem_z,'
      '        rem_z.sernum2_rem_z,'
      '        rem_z.klient_name_rem_z,'
      '        rem_z.model_rem_z,'
      '        rem_z.neispr_rem_z,'
      '        rem_smodel.name_rem_smodel,'
      '        rem_smodel.code_rem_smodel,'
      ''
      '        cfc.name_rem_sprneispr as cfc_name,'
      '        cfc.code_rem_sprneispr as cfc_code,'
      '        cfc.name_eng_rem_sprneispr as cfc_name_eng,'
      ''
      '        rem_sprneispr_grp.name_rem_sprneispr_grp,'
      '        rem_sprneispr_grp.name_eng_rem_sprneispr_grp,'
      ''
      '        dfc.name_rem_sprneispr as dfc_name,'
      '        dfc.code_rem_sprneispr as dfc_code,'
      '        sproducer.name_sproducer,'
      '        rem_sprmodel.name_rem_sprmodel,'
      '        rem_sprmodel.code_rem_sprmodel,'
      '        sklient.nameklient,'
      '        post_zip.nameklient as post_zip_name,'
      '        sseller.name_sseller'
      ''
      'from  rem_dzaktpr'
      
        'left outer join rem_z on rem_dzaktpr.idz_rem_dzaktpr=rem_z.id_re' +
        'm_z'
      
        'left outer join rem_smodel on rem_z.idmodel_rem_z=rem_smodel.id_' +
        'rem_smodel'
      
        'left outer join rem_sprneispr as cfc on  cfc.id_rem_sprneispr=re' +
        'm_dzaktpr.idcfc_rem_dzaktpr'
      
        'left outer join rem_sprneispr_grp on cfc.idgrp_rem_sprneispr=rem' +
        '_sprneispr_grp.id_rem_sprneispr_grp'
      
        'left outer join rem_sprneispr as dfc on  dfc.id_rem_sprneispr=re' +
        'm_dzaktpr.iddfc_rem_dzaktpr'
      
        'left outer join sproducer on sproducer.id_sproducer=rem_dzaktpr.' +
        'idpr_rem_dzaktpr'
      
        'left outer join rem_sprmodel on rem_sprmodel.id_rem_sprmodel= re' +
        'm_dzaktpr.idprmodel_rem_dzaktpr'
      
        'left outer join sklient on rem_dzaktpr.iddiler_rem_dzaktpr=sklie' +
        'nt.idklient'
      
        'left outer join sklient as post_zip on rem_dzaktpr.idpost_zip_re' +
        'm_dzaktpr=post_zip.idklient'
      
        'left outer join sseller on  rem_dzaktpr.idseller_rem_dzaktpr=sse' +
        'ller.id_sseller'
      'where(  rem_dzaktpr.iddoc_rem_dzaktpr=:PARAM_IDDOC'
      
        '     ) and (     REM_DZAKTPR.ID_REM_DZAKTPR = :OLD_ID_REM_DZAKTP' +
        'R'
      '     )'
      '    '
      '')
    SelectSQL.Strings = (
      'select rem_dzaktpr.*,'
      '        rem_z.name_rem_z,'
      '        rem_z.num_rem_z,'
      '        rem_z.pos_rem_z,'
      '        rem_z.sernum_rem_z,'
      '        rem_z.sernum2_rem_z,'
      '        rem_z.klient_name_rem_z,'
      '        rem_z.model_rem_z,'
      '        rem_z.neispr_rem_z,'
      '        rem_smodel.name_rem_smodel,'
      '        rem_smodel.code_rem_smodel,'
      ''
      '        cfc.name_rem_sprneispr as cfc_name,'
      '        cfc.code_rem_sprneispr as cfc_code,'
      '        cfc.name_eng_rem_sprneispr as cfc_name_eng,'
      ''
      '        rem_sprneispr_grp.name_rem_sprneispr_grp,'
      '        rem_sprneispr_grp.name_eng_rem_sprneispr_grp,'
      ''
      '        dfc.name_rem_sprneispr as dfc_name,'
      '        dfc.code_rem_sprneispr as dfc_code,'
      '        sproducer.name_sproducer,'
      '        rem_sprmodel.name_rem_sprmodel,'
      '        rem_sprmodel.code_rem_sprmodel,'
      '        sklient.nameklient,'
      '        post_zip.nameklient as post_zip_name,'
      '        sseller.name_sseller'
      ''
      'from  rem_dzaktpr'
      
        'left outer join rem_z on rem_dzaktpr.idz_rem_dzaktpr=rem_z.id_re' +
        'm_z'
      
        'left outer join rem_smodel on rem_z.idmodel_rem_z=rem_smodel.id_' +
        'rem_smodel'
      
        'left outer join rem_sprneispr as cfc on  cfc.id_rem_sprneispr=re' +
        'm_dzaktpr.idcfc_rem_dzaktpr'
      
        'left outer join rem_sprneispr_grp on cfc.idgrp_rem_sprneispr=rem' +
        '_sprneispr_grp.id_rem_sprneispr_grp'
      
        'left outer join rem_sprneispr as dfc on  dfc.id_rem_sprneispr=re' +
        'm_dzaktpr.iddfc_rem_dzaktpr'
      
        'left outer join sproducer on sproducer.id_sproducer=rem_dzaktpr.' +
        'idpr_rem_dzaktpr'
      
        'left outer join rem_sprmodel on rem_sprmodel.id_rem_sprmodel= re' +
        'm_dzaktpr.idprmodel_rem_dzaktpr'
      
        'left outer join sklient on rem_dzaktpr.iddiler_rem_dzaktpr=sklie' +
        'nt.idklient'
      
        'left outer join sklient as post_zip on rem_dzaktpr.idpost_zip_re' +
        'm_dzaktpr=post_zip.idklient'
      
        'left outer join sseller on  rem_dzaktpr.idseller_rem_dzaktpr=sse' +
        'ller.id_sseller'
      'where rem_dzaktpr.iddoc_rem_dzaktpr=:PARAM_IDDOC'
      '')
    AutoUpdateOptions.UpdateTableName = 'REM_DZAKTPR'
    AutoUpdateOptions.KeyFields = 'ID_REM_DZAKTPR'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DZAKTPR_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object DocID_REM_DZAKTPR: TFIBLargeIntField
      FieldName = 'ID_REM_DZAKTPR'
    end
    object DocIDBASE_REM_DZAKTPR: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DZAKTPR'
    end
    object DocGID_REM_DZAKTPR: TFIBWideStringField
      FieldName = 'GID_REM_DZAKTPR'
      Size = 10
    end
    object DocIDDOC_REM_DZAKTPR: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DZAKTPR'
    end
    object DocIDZ_REM_DZAKTPR: TFIBLargeIntField
      FieldName = 'IDZ_REM_DZAKTPR'
    end
    object DocIDTPRICE_REM_DZAKTPR: TFIBLargeIntField
      FieldName = 'IDTPRICE_REM_DZAKTPR'
    end
    object DocPRIM_REM_DZAKTPR: TFIBWideStringField
      FieldName = 'PRIM_REM_DZAKTPR'
      Size = 100
    end
    object DocNAME_REM_Z: TFIBWideStringField
      FieldName = 'NAME_REM_Z'
      Size = 200
    end
    object DocNUM_REM_Z: TFIBIntegerField
      FieldName = 'NUM_REM_Z'
    end
    object DocPOS_REM_Z: TFIBDateTimeField
      FieldName = 'POS_REM_Z'
    end
    object DocSERNUM_REM_Z: TFIBWideStringField
      FieldName = 'SERNUM_REM_Z'
      Size = 50
    end
    object DocSERNUM2_REM_Z: TFIBWideStringField
      FieldName = 'SERNUM2_REM_Z'
      Size = 50
    end
    object DocKLIENT_NAME_REM_Z: TFIBWideStringField
      FieldName = 'KLIENT_NAME_REM_Z'
      Size = 200
    end
    object DocMODEL_REM_Z: TFIBWideStringField
      FieldName = 'MODEL_REM_Z'
      Size = 40
    end
    object DocNAME_REM_SMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SMODEL'
      Size = 200
    end
    object DocIDPR_REM_DZAKTPR: TFIBLargeIntField
      FieldName = 'IDPR_REM_DZAKTPR'
    end
    object DocIDCFC_REM_DZAKTPR: TFIBLargeIntField
      FieldName = 'IDCFC_REM_DZAKTPR'
    end
    object DocIDDFC_REM_DZAKTPR: TFIBLargeIntField
      FieldName = 'IDDFC_REM_DZAKTPR'
    end
    object DocIDPRMODEL_REM_DZAKTPR: TFIBLargeIntField
      FieldName = 'IDPRMODEL_REM_DZAKTPR'
    end
    object DocPODO_REM_DZAKTPR: TFIBWideStringField
      FieldName = 'PODO_REM_DZAKTPR'
      Size = 40
    end
    object DocPOPOSLE_REM_DZAKTPR: TFIBWideStringField
      FieldName = 'POPOSLE_REM_DZAKTPR'
      Size = 40
    end
    object DocDESCR_REM_DZAKTPR: TFIBWideStringField
      FieldName = 'DESCR_REM_DZAKTPR'
      Size = 150
    end
    object DocPRODAVEC_REM_DZAKTPR: TFIBWideStringField
      FieldName = 'PRODAVEC_REM_DZAKTPR'
      Size = 40
    end
    object DocNUMGARTALON_REM_DZAKTPR: TFIBWideStringField
      FieldName = 'NUMGARTALON_REM_DZAKTPR'
      Size = 50
    end
    object DocSERNUM3_REM_DZAKTPR: TFIBWideStringField
      FieldName = 'SERNUM3_REM_DZAKTPR'
      Size = 50
    end
    object DocSERNUM4_REM_DZAKTPR: TFIBWideStringField
      FieldName = 'SERNUM4_REM_DZAKTPR'
      Size = 50
    end
    object DocNUMBAT_REM_DZAKTPR: TFIBWideStringField
      FieldName = 'NUMBAT_REM_DZAKTPR'
      Size = 50
    end
    object DocSOST_REM_DZAKTPR: TFIBWideStringField
      FieldName = 'SOST_REM_DZAKTPR'
      Size = 150
    end
    object DocDATEVIPUSK_REM_DZAKTPR: TFIBDateField
      FieldName = 'DATEVIPUSK_REM_DZAKTPR'
    end
    object DocDATE_PRODAGI_REM_DZAKTPR: TFIBDateField
      FieldName = 'DATE_PRODAGI_REM_DZAKTPR'
    end
    object DocTYPE_REMONT_REM_DZAKTPR: TFIBIntegerField
      FieldName = 'TYPE_REMONT_REM_DZAKTPR'
    end
    object DocKEM_SDANO_REM_DZAKTPR: TFIBIntegerField
      FieldName = 'KEM_SDANO_REM_DZAKTPR'
    end
    object DocCFC_NAME: TFIBWideStringField
      FieldName = 'CFC_NAME'
      Size = 200
    end
    object DocCFC_CODE: TFIBWideStringField
      FieldName = 'CFC_CODE'
    end
    object DocDFC_NAME: TFIBWideStringField
      FieldName = 'DFC_NAME'
      Size = 200
    end
    object DocDFC_CODE: TFIBWideStringField
      FieldName = 'DFC_CODE'
    end
    object DocNAME_SPRODUCER: TFIBWideStringField
      FieldName = 'NAME_SPRODUCER'
      Size = 200
    end
    object DocNAME_REM_SPRMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SPRMODEL'
      Size = 200
    end
    object DocCODE_REM_SPRMODEL: TFIBWideStringField
      FieldName = 'CODE_REM_SPRMODEL'
    end
    object DocNEISPR_REM_DZAKTPR: TFIBWideStringField
      FieldName = 'NEISPR_REM_DZAKTPR'
      Size = 250
    end
    object DocNEISPR_REM_Z: TFIBWideStringField
      FieldName = 'NEISPR_REM_Z'
      Size = 250
    end
    object DocFL_FICTIV_REM_DZAKTPR: TFIBIntegerField
      FieldName = 'FL_FICTIV_REM_DZAKTPR'
    end
    object DocKLIENT_NAME_REM_DZAKTPR: TFIBWideStringField
      FieldName = 'KLIENT_NAME_REM_DZAKTPR'
      Size = 200
    end
    object DocKLIENT_ADR_REM_DZAKTPR: TFIBWideStringField
      FieldName = 'KLIENT_ADR_REM_DZAKTPR'
      Size = 200
    end
    object DocKLIENT_PHONE_REM_DZAKTPR: TFIBWideStringField
      FieldName = 'KLIENT_PHONE_REM_DZAKTPR'
      Size = 200
    end
    object DocIDDILER_REM_DZAKTPR: TFIBLargeIntField
      FieldName = 'IDDILER_REM_DZAKTPR'
    end
    object DocNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 200
    end
    object DocPOST_ZIP_NAME: TFIBWideStringField
      FieldName = 'POST_ZIP_NAME'
      Size = 200
    end
    object DocFL_OTCHET_POST_REM_DZAKTPR: TFIBSmallIntField
      FieldName = 'FL_OTCHET_POST_REM_DZAKTPR'
    end
    object DocIDPOST_ZIP_REM_DZAKTPR: TFIBLargeIntField
      FieldName = 'IDPOST_ZIP_REM_DZAKTPR'
    end
    object DocFL_NE_OTCH_REM_DZAKTPR: TFIBSmallIntField
      FieldName = 'FL_NE_OTCH_REM_DZAKTPR'
    end
    object DocFL_NADO_OTCH_REM_DZAKTPR: TFIBSmallIntField
      FieldName = 'FL_NADO_OTCH_REM_DZAKTPR'
    end
    object DocFL_PRIG_KREM_REM_DZAKTPR: TFIBSmallIntField
      FieldName = 'FL_PRIG_KREM_REM_DZAKTPR'
    end
    object DocCODE_REM_SMODEL: TFIBWideStringField
      FieldName = 'CODE_REM_SMODEL'
    end
    object DocNAME_REM_SPRNEISPR_GRP: TFIBWideStringField
      FieldName = 'NAME_REM_SPRNEISPR_GRP'
      Size = 200
    end
    object DocPOSPRIEMA_REM_DZAKTPR: TFIBDateTimeField
      FieldName = 'POSPRIEMA_REM_DZAKTPR'
      DisplayFormat = 'c'
    end
    object DocIDSELLER_REM_DZAKTPR: TFIBLargeIntField
      FieldName = 'IDSELLER_REM_DZAKTPR'
    end
    object DocNAME_SSELLER: TFIBWideStringField
      FieldName = 'NAME_SSELLER'
      Size = 200
    end
    object DocCFC_NAME_ENG: TFIBWideStringField
      FieldName = 'CFC_NAME_ENG'
      Size = 200
    end
    object DocNAME_ENG_REM_SPRNEISPR_GRP: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SPRNEISPR_GRP'
      Size = 200
    end
    object DocKLIENT_EMAIL_REM_DZAKTPR: TFIBWideStringField
      FieldName = 'KLIENT_EMAIL_REM_DZAKTPR'
      Size = 30
    end
    object DocFAMILIYA_REM_DZAKTPR: TFIBWideStringField
      FieldName = 'FAMILIYA_REM_DZAKTPR'
      Size = 30
    end
    object DocIMYA_REM_DZAKTPR: TFIBWideStringField
      FieldName = 'IMYA_REM_DZAKTPR'
      Size = 30
    end
    object DocOTCHESTVO_REM_DZAKTPR: TFIBWideStringField
      FieldName = 'OTCHESTVO_REM_DZAKTPR'
      Size = 30
    end
    object DocFL_OST_NA_OTV_XRAN_REM_DZAKTPR: TFIBSmallIntField
      FieldName = 'FL_OST_NA_OTV_XRAN_REM_DZAKTPR'
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_DZAKTPRT'
      'SET '
      '    IDBASE_REM_DZAKTPRT = :IDBASE_REM_DZAKTPRT,'
      '    GID_REM_DZAKTPRT = :GID_REM_DZAKTPRT,'
      '    IDDOC_REM_DZAKTPRT = :IDDOC_REM_DZAKTPRT,'
      '    IDNOM_REM_DZAKTPRT = :IDNOM_REM_DZAKTPRT,'
      '    IDED_REM_DZAKTPRT = :IDED_REM_DZAKTPRT,'
      '    IDHW_REM_DZAKTPRT = :IDHW_REM_DZAKTPRT,'
      '    KOL_REM_DZAKTPRT = :KOL_REM_DZAKTPRT,'
      '    KF_REM_DZAKTPRT = :KF_REM_DZAKTPRT,'
      '    PRICE_REM_DZAKTPRT = :PRICE_REM_DZAKTPRT,'
      '    SUM_REM_DZAKTPRT = :SUM_REM_DZAKTPRT,'
      '    DVREG_REM_DZAKTPRT = :DVREG_REM_DZAKTPRT,'
      '    IDPRDEFECT_REM_DZAKTPR = :IDPRDEFECT_REM_DZAKTPR,'
      '    IDPRNEISPR_REM_DZAKTPRT = :IDPRNEISPR_REM_DZAKTPRT,'
      '    IDPRRABOTA_REM_DZAKTPRT = :IDPRRABOTA_REM_DZAKTPRT,'
      '    IDHWOLD_REM_DZAKTPRT = :IDHWOLD_REM_DZAKTPRT,'
      '    FL_VOSVRAT_ZIP_REM_DZAKTPRT = :FL_VOSVRAT_ZIP_REM_DZAKTPRT,'
      '    FL_ISP_REM_DZAKTPRT = :FL_ISP_REM_DZAKTPRT,'
      '    IDPRCOND_REM_DZAKTPRT = :IDPRCOND_REM_DZAKTPRT,'
      '    IDPRSECTION_REM_DZAKTPRT = :IDPRSECTION_REM_DZAKTPRT,'
      '    IDTNOM_REM_DZAKTPRT = :IDTNOM_REM_DZAKTPRT,'
      '    IDHW_DONOR_REM_DZAKTPRT = :IDHW_DONOR_REM_DZAKTPRT,'
      '    IDTYP_USEL_REM_DZAKTPRT = :IDTYP_USEL_REM_DZAKTPRT,'
      '    DESCR_REM_DZAKTPRT = :DESCR_REM_DZAKTPRT,'
      '    IDTVZIP_REM_DZAKTPRT = :IDTVZIP_REM_DZAKTPRT,'
      '    IDMHRAN_REM_DZAKTPRT = :IDMHRAN_REM_DZAKTPRT'
      'WHERE'
      '    ID_REM_DZAKTPRT = :OLD_ID_REM_DZAKTPRT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DZAKTPRT'
      'WHERE'
      '        ID_REM_DZAKTPRT = :OLD_ID_REM_DZAKTPRT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DZAKTPRT('
      '    ID_REM_DZAKTPRT,'
      '    IDBASE_REM_DZAKTPRT,'
      '    GID_REM_DZAKTPRT,'
      '    IDDOC_REM_DZAKTPRT,'
      '    IDNOM_REM_DZAKTPRT,'
      '    IDED_REM_DZAKTPRT,'
      '    IDHW_REM_DZAKTPRT,'
      '    KOL_REM_DZAKTPRT,'
      '    KF_REM_DZAKTPRT,'
      '    PRICE_REM_DZAKTPRT,'
      '    SUM_REM_DZAKTPRT,'
      '    DVREG_REM_DZAKTPRT,'
      '    IDPRDEFECT_REM_DZAKTPR,'
      '    IDPRNEISPR_REM_DZAKTPRT,'
      '    IDPRRABOTA_REM_DZAKTPRT,'
      '    IDHWOLD_REM_DZAKTPRT,'
      '    FL_VOSVRAT_ZIP_REM_DZAKTPRT,'
      '    FL_ISP_REM_DZAKTPRT,'
      '    IDPRCOND_REM_DZAKTPRT,'
      '    IDPRSECTION_REM_DZAKTPRT,'
      '    IDTNOM_REM_DZAKTPRT,'
      '    IDHW_DONOR_REM_DZAKTPRT,'
      '    IDTYP_USEL_REM_DZAKTPRT,'
      '    DESCR_REM_DZAKTPRT,'
      '    IDTVZIP_REM_DZAKTPRT,'
      '    IDMHRAN_REM_DZAKTPRT'
      ')'
      'VALUES('
      '    :ID_REM_DZAKTPRT,'
      '    :IDBASE_REM_DZAKTPRT,'
      '    :GID_REM_DZAKTPRT,'
      '    :IDDOC_REM_DZAKTPRT,'
      '    :IDNOM_REM_DZAKTPRT,'
      '    :IDED_REM_DZAKTPRT,'
      '    :IDHW_REM_DZAKTPRT,'
      '    :KOL_REM_DZAKTPRT,'
      '    :KF_REM_DZAKTPRT,'
      '    :PRICE_REM_DZAKTPRT,'
      '    :SUM_REM_DZAKTPRT,'
      '    :DVREG_REM_DZAKTPRT,'
      '    :IDPRDEFECT_REM_DZAKTPR,'
      '    :IDPRNEISPR_REM_DZAKTPRT,'
      '    :IDPRRABOTA_REM_DZAKTPRT,'
      '    :IDHWOLD_REM_DZAKTPRT,'
      '    :FL_VOSVRAT_ZIP_REM_DZAKTPRT,'
      '    :FL_ISP_REM_DZAKTPRT,'
      '    :IDPRCOND_REM_DZAKTPRT,'
      '    :IDPRSECTION_REM_DZAKTPRT,'
      '    :IDTNOM_REM_DZAKTPRT,'
      '    :IDHW_DONOR_REM_DZAKTPRT,'
      '    :IDTYP_USEL_REM_DZAKTPRT,'
      '    :DESCR_REM_DZAKTPRT,'
      '    :IDTVZIP_REM_DZAKTPRT,'
      '    :IDMHRAN_REM_DZAKTPRT'
      ')')
    RefreshSQL.Strings = (
      ''
      'select rem_dzaktprt.*,'
      ''
      ' rem_sprneispr.name_rem_sprneispr,'
      ' rem_sprneispr.name_eng_rem_sprneispr,'
      ' rem_sprneispr.code_rem_sprneispr,'
      ' rem_sprneispr_grp.name_rem_sprneispr_grp,'
      ' rem_sprneispr_grp.name_eng_rem_sprneispr_grp,'
      ''
      ' rem_sprdefect.code_rem_sprdefect,'
      ' rem_sprdefect.name_rem_sprdefect,'
      ' rem_sprdefect_grp.name_rem_sprdefect_grp,'
      ' rem_sprdefect_grp.name_eng_rem_sprdefect_grp,'
      ''
      ' rem_sprrabota.code_rem_sprrabota,'
      ' rem_sprrabota.name_rem_sprrabota,'
      ' rem_sprrabota.name_eng_rem_sprrabota,'
      ' rem_sprrabota_grp.name_rem_sprrabota_grp,'
      ' rem_sprrabota_grp.name_eng_rem_sprrabota_grp,'
      ''
      '    snom.namenom,'
      ' snom.codenom,'
      ' snom.artnom,'
      ' sed.nameed,'
      ' sed.shed,'
      ''
      '  rem_shardware.name_rem_shardware,'
      ' rem_shardware.code_rem_shardware,'
      ' rem_shardware.sernum_rem_shardware,'
      ''
      
        '  old_rem_shardware.name_rem_shardware as old_name_rem_shardware' +
        ','
      ' old_rem_shardware.code_rem_shardware as old_code_rem_shardware,'
      
        ' old_rem_shardware.sernum_rem_shardware as old_sernum_rem_shardw' +
        'are,'
      ''
      ' rem_sprcondition.code_rem_sprcondition,'
      ' rem_sprcondition.name_rem_sprcondition,'
      ' rem_sprcondition.name_eng_rem_sprcondition,'
      ' rem_sprcond_grp.code_rem_sprcond_grp,'
      ' rem_sprcond_grp.name_rem_sprcond_grp,'
      ' rem_sprcond_grp.name_eng_rem_sprcond_grp,'
      ''
      ' rem_sprsection.code_rem_sprsection,'
      ' rem_sprsection.name_rem_sprsection,'
      ' rem_sprsection.name_eng_rem_sprsection,'
      ''
      ' rem_sprsection_grp.code_rem_sprsection_grp,'
      ' rem_sprsection_grp.name_rem_sprsection_grp,'
      ' rem_sprsection_grp.name_eng_rem_sprsection_grp,'
      ''
      ' donor.name_rem_shardware as donor_name_rem_shardware,'
      ' donor.code_rem_shardware as donor_code_rem_shardware,'
      ' donor.sernum_rem_shardware as donor_sernum_rem_shardware,'
      ' rem_stypuslov.name_rem_stypuslov,'
      ' stnom.name_stnom,'
      ' smhran.name_smhran,'
      ' rem_stvzip.name_rem_stvzip'
      ''
      'from  rem_dzaktprt'
      
        'left outer join snom on rem_dzaktprt.idnom_rem_dzaktprt=snom.idn' +
        'om'
      'left outer join sed on rem_dzaktprt.ided_rem_dzaktprt=sed.ided'
      
        'left outer join rem_shardware on rem_dzaktprt.idhw_rem_dzaktprt=' +
        'rem_shardware.id_rem_shardware'
      
        'left outer join rem_shardware as old_rem_shardware  on rem_dzakt' +
        'prt.idhwold_rem_dzaktprt=old_rem_shardware.id_rem_shardware'
      
        'left outer join rem_sprneispr on rem_dzaktprt.idprneispr_rem_dza' +
        'ktprt=rem_sprneispr.id_rem_sprneispr'
      
        'left outer join rem_sprneispr_grp on rem_sprneispr.idgrp_rem_spr' +
        'neispr=rem_sprneispr_grp.id_rem_sprneispr_grp'
      
        'left outer join rem_sprdefect on rem_dzaktprt.idprdefect_rem_dza' +
        'ktpr=rem_sprdefect.id_rem_sprdefect'
      
        'left outer join rem_sprdefect_grp on rem_sprdefect.idgrp_rem_spr' +
        'defect=rem_sprdefect_grp.id_rem_sprdefect_grp'
      
        'left outer join rem_sprrabota on rem_dzaktprt.idprrabota_rem_dza' +
        'ktprt=rem_sprrabota.id_rem_sprrabota'
      
        'left outer join rem_sprrabota_grp on rem_sprrabota.idpr_rem_sprr' +
        'abota=rem_sprrabota_grp.id_rem_sprrabota_grp'
      
        'left outer join rem_sprcondition on rem_sprcondition.id_rem_sprc' +
        'ondition=rem_dzaktprt.idprcond_rem_dzaktprt'
      
        'left outer join rem_sprcond_grp on rem_sprcond_grp.id_rem_sprcon' +
        'd_grp=rem_sprcondition.idgrp_rem_sprcondition'
      ''
      
        'left outer join rem_sprsection on rem_sprsection.id_rem_sprsecti' +
        'on=rem_dzaktprt.idprsection_rem_dzaktprt'
      
        'left outer join rem_sprsection_grp on rem_sprsection.idgrp_rem_s' +
        'prsection=rem_sprsection_grp.id_rem_sprsection_grp'
      
        'left outer join rem_shardware as donor  on rem_dzaktprt.idhw_don' +
        'or_rem_dzaktprt=donor.id_rem_shardware'
      
        'left outer join rem_stypuslov on rem_dzaktprt.idtyp_usel_rem_dza' +
        'ktprt=rem_stypuslov.id_rem_stypuslov'
      
        'left outer join stnom on rem_dzaktprt.idtnom_rem_dzaktprt=stnom.' +
        'id_stnom'
      
        'left outer join smhran on rem_dzaktprt.idmhran_rem_dzaktprt=smhr' +
        'an.id_smhran'
      
        'left outer join rem_stvzip on rem_dzaktprt.idtvzip_rem_dzaktprt=' +
        'rem_stvzip.id_rem_stvzip'
      'where(  rem_dzaktprt.iddoc_rem_dzaktprt=:PARAM_IDDOC'
      
        '     ) and (     REM_DZAKTPRT.ID_REM_DZAKTPRT = :OLD_ID_REM_DZAK' +
        'TPRT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      ''
      'select rem_dzaktprt.*,'
      ''
      ' rem_sprneispr.name_rem_sprneispr,'
      ' rem_sprneispr.name_eng_rem_sprneispr,'
      ' rem_sprneispr.code_rem_sprneispr,'
      ' rem_sprneispr_grp.name_rem_sprneispr_grp,'
      ' rem_sprneispr_grp.name_eng_rem_sprneispr_grp,'
      ''
      ' rem_sprdefect.code_rem_sprdefect,'
      ' rem_sprdefect.name_rem_sprdefect,'
      ' rem_sprdefect_grp.name_rem_sprdefect_grp,'
      ' rem_sprdefect_grp.name_eng_rem_sprdefect_grp,'
      ''
      ' rem_sprrabota.code_rem_sprrabota,'
      ' rem_sprrabota.name_rem_sprrabota,'
      ' rem_sprrabota.name_eng_rem_sprrabota,'
      ' rem_sprrabota_grp.name_rem_sprrabota_grp,'
      ' rem_sprrabota_grp.name_eng_rem_sprrabota_grp,'
      ''
      '    snom.namenom,'
      ' snom.codenom,'
      ' snom.artnom,'
      ' sed.nameed,'
      ' sed.shed,'
      ''
      '  rem_shardware.name_rem_shardware,'
      ' rem_shardware.code_rem_shardware,'
      ' rem_shardware.sernum_rem_shardware,'
      ''
      
        '  old_rem_shardware.name_rem_shardware as old_name_rem_shardware' +
        ','
      ' old_rem_shardware.code_rem_shardware as old_code_rem_shardware,'
      
        ' old_rem_shardware.sernum_rem_shardware as old_sernum_rem_shardw' +
        'are,'
      ''
      ' rem_sprcondition.code_rem_sprcondition,'
      ' rem_sprcondition.name_rem_sprcondition,'
      ' rem_sprcondition.name_eng_rem_sprcondition,'
      ' rem_sprcond_grp.code_rem_sprcond_grp,'
      ' rem_sprcond_grp.name_rem_sprcond_grp,'
      ' rem_sprcond_grp.name_eng_rem_sprcond_grp,'
      ''
      ' rem_sprsection.code_rem_sprsection,'
      ' rem_sprsection.name_rem_sprsection,'
      ' rem_sprsection.name_eng_rem_sprsection,'
      ''
      ' rem_sprsection_grp.code_rem_sprsection_grp,'
      ' rem_sprsection_grp.name_rem_sprsection_grp,'
      ' rem_sprsection_grp.name_eng_rem_sprsection_grp,'
      ''
      ' donor.name_rem_shardware as donor_name_rem_shardware,'
      ' donor.code_rem_shardware as donor_code_rem_shardware,'
      ' donor.sernum_rem_shardware as donor_sernum_rem_shardware,'
      ' rem_stypuslov.name_rem_stypuslov,'
      ' stnom.name_stnom,'
      ' smhran.name_smhran,'
      ' rem_stvzip.name_rem_stvzip'
      ''
      'from  rem_dzaktprt'
      
        'left outer join snom on rem_dzaktprt.idnom_rem_dzaktprt=snom.idn' +
        'om'
      'left outer join sed on rem_dzaktprt.ided_rem_dzaktprt=sed.ided'
      
        'left outer join rem_shardware on rem_dzaktprt.idhw_rem_dzaktprt=' +
        'rem_shardware.id_rem_shardware'
      
        'left outer join rem_shardware as old_rem_shardware  on rem_dzakt' +
        'prt.idhwold_rem_dzaktprt=old_rem_shardware.id_rem_shardware'
      
        'left outer join rem_sprneispr on rem_dzaktprt.idprneispr_rem_dza' +
        'ktprt=rem_sprneispr.id_rem_sprneispr'
      
        'left outer join rem_sprneispr_grp on rem_sprneispr.idgrp_rem_spr' +
        'neispr=rem_sprneispr_grp.id_rem_sprneispr_grp'
      
        'left outer join rem_sprdefect on rem_dzaktprt.idprdefect_rem_dza' +
        'ktpr=rem_sprdefect.id_rem_sprdefect'
      
        'left outer join rem_sprdefect_grp on rem_sprdefect.idgrp_rem_spr' +
        'defect=rem_sprdefect_grp.id_rem_sprdefect_grp'
      
        'left outer join rem_sprrabota on rem_dzaktprt.idprrabota_rem_dza' +
        'ktprt=rem_sprrabota.id_rem_sprrabota'
      
        'left outer join rem_sprrabota_grp on rem_sprrabota.idpr_rem_sprr' +
        'abota=rem_sprrabota_grp.id_rem_sprrabota_grp'
      
        'left outer join rem_sprcondition on rem_sprcondition.id_rem_sprc' +
        'ondition=rem_dzaktprt.idprcond_rem_dzaktprt'
      
        'left outer join rem_sprcond_grp on rem_sprcond_grp.id_rem_sprcon' +
        'd_grp=rem_sprcondition.idgrp_rem_sprcondition'
      ''
      
        'left outer join rem_sprsection on rem_sprsection.id_rem_sprsecti' +
        'on=rem_dzaktprt.idprsection_rem_dzaktprt'
      
        'left outer join rem_sprsection_grp on rem_sprsection.idgrp_rem_s' +
        'prsection=rem_sprsection_grp.id_rem_sprsection_grp'
      
        'left outer join rem_shardware as donor  on rem_dzaktprt.idhw_don' +
        'or_rem_dzaktprt=donor.id_rem_shardware'
      
        'left outer join rem_stypuslov on rem_dzaktprt.idtyp_usel_rem_dza' +
        'ktprt=rem_stypuslov.id_rem_stypuslov'
      
        'left outer join stnom on rem_dzaktprt.idtnom_rem_dzaktprt=stnom.' +
        'id_stnom'
      
        'left outer join smhran on rem_dzaktprt.idmhran_rem_dzaktprt=smhr' +
        'an.id_smhran'
      
        'left outer join rem_stvzip on rem_dzaktprt.idtvzip_rem_dzaktprt=' +
        'rem_stvzip.id_rem_stvzip'
      'where rem_dzaktprt.iddoc_rem_dzaktprt=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_DZAKTPRT'
    AutoUpdateOptions.KeyFields = 'ID_REM_DZAKTPRT'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DZAKTPRT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    AfterDelete = DocTAfterDelete
    BeforeDelete = DocTBeforeDelete
    OnCalcFields = DocTCalcFields
    OnNewRecord = DocTNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 112
    poUseLargeIntField = True
    object DocTRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object DocTID_REM_DZAKTPRT: TFIBLargeIntField
      FieldName = 'ID_REM_DZAKTPRT'
    end
    object DocTIDBASE_REM_DZAKTPRT: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DZAKTPRT'
    end
    object DocTGID_REM_DZAKTPRT: TFIBWideStringField
      FieldName = 'GID_REM_DZAKTPRT'
      Size = 10
    end
    object DocTIDDOC_REM_DZAKTPRT: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DZAKTPRT'
    end
    object DocTIDNOM_REM_DZAKTPRT: TFIBLargeIntField
      FieldName = 'IDNOM_REM_DZAKTPRT'
    end
    object DocTIDED_REM_DZAKTPRT: TFIBLargeIntField
      FieldName = 'IDED_REM_DZAKTPRT'
    end
    object DocTIDHW_REM_DZAKTPRT: TFIBLargeIntField
      FieldName = 'IDHW_REM_DZAKTPRT'
    end
    object DocTKOL_REM_DZAKTPRT: TFIBBCDField
      FieldName = 'KOL_REM_DZAKTPRT'
      OnChange = DocTKOL_REM_DZAKTPRTChange
      Size = 3
      RoundByScale = True
    end
    object DocTKF_REM_DZAKTPRT: TFIBBCDField
      FieldName = 'KF_REM_DZAKTPRT'
      Size = 3
      RoundByScale = True
    end
    object DocTPRICE_REM_DZAKTPRT: TFIBBCDField
      FieldName = 'PRICE_REM_DZAKTPRT'
      OnChange = DocTPRICE_REM_DZAKTPRTChange
      Size = 2
      RoundByScale = True
    end
    object DocTSUM_REM_DZAKTPRT: TFIBBCDField
      FieldName = 'SUM_REM_DZAKTPRT'
      Size = 2
      RoundByScale = True
    end
    object DocTDVREG_REM_DZAKTPRT: TFIBSmallIntField
      FieldName = 'DVREG_REM_DZAKTPRT'
    end
    object DocTNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      OnGetText = DocTNAMENOMGetText
      Size = 200
    end
    object DocTCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object DocTARTNOM: TFIBWideStringField
      FieldName = 'ARTNOM'
      Size = 40
    end
    object DocTNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 200
    end
    object DocTSHED: TFIBWideStringField
      FieldName = 'SHED'
      Size = 13
    end
    object DocTNAME_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'NAME_REM_SHARDWARE'
      Size = 200
    end
    object DocTCODE_REM_SHARDWARE: TFIBIntegerField
      FieldName = 'CODE_REM_SHARDWARE'
    end
    object DocTSERNUM_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'SERNUM_REM_SHARDWARE'
      Size = 50
    end
    object DocTIDPRDEFECT_REM_DZAKTPR: TFIBLargeIntField
      FieldName = 'IDPRDEFECT_REM_DZAKTPR'
    end
    object DocTCODE_REM_SPRDEFECT: TFIBWideStringField
      FieldName = 'CODE_REM_SPRDEFECT'
    end
    object DocTNAME_REM_SPRDEFECT: TFIBWideStringField
      FieldName = 'NAME_REM_SPRDEFECT'
      OnGetText = DocTNAME_REM_SPRDEFECTGetText
      Size = 200
    end
    object DocTIDPRNEISPR_REM_DZAKTPRT: TFIBLargeIntField
      FieldName = 'IDPRNEISPR_REM_DZAKTPRT'
    end
    object DocTIDPRRABOTA_REM_DZAKTPRT: TFIBLargeIntField
      FieldName = 'IDPRRABOTA_REM_DZAKTPRT'
    end
    object DocTIDHWOLD_REM_DZAKTPRT: TFIBLargeIntField
      FieldName = 'IDHWOLD_REM_DZAKTPRT'
    end
    object DocTFL_VOSVRAT_ZIP_REM_DZAKTPRT: TFIBSmallIntField
      FieldName = 'FL_VOSVRAT_ZIP_REM_DZAKTPRT'
    end
    object DocTNAME_REM_SPRNEISPR: TFIBWideStringField
      FieldName = 'NAME_REM_SPRNEISPR'
      OnGetText = DocTNAME_REM_SPRNEISPRGetText
      Size = 200
    end
    object DocTNAME_ENG_REM_SPRNEISPR: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SPRNEISPR'
      Size = 200
    end
    object DocTCODE_REM_SPRNEISPR: TFIBWideStringField
      FieldName = 'CODE_REM_SPRNEISPR'
    end
    object DocTNAME_REM_SPRNEISPR_GRP: TFIBWideStringField
      FieldName = 'NAME_REM_SPRNEISPR_GRP'
      Size = 200
    end
    object DocTNAME_ENG_REM_SPRNEISPR_GRP: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SPRNEISPR_GRP'
      Size = 200
    end
    object DocTNAME_REM_SPRDEFECT_GRP: TFIBWideStringField
      FieldName = 'NAME_REM_SPRDEFECT_GRP'
      Size = 200
    end
    object DocTNAME_ENG_REM_SPRDEFECT_GRP: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SPRDEFECT_GRP'
      Size = 200
    end
    object DocTCODE_REM_SPRRABOTA: TFIBWideStringField
      FieldName = 'CODE_REM_SPRRABOTA'
    end
    object DocTNAME_REM_SPRRABOTA: TFIBWideStringField
      FieldName = 'NAME_REM_SPRRABOTA'
      OnGetText = DocTNAME_REM_SPRRABOTAGetText
      Size = 200
    end
    object DocTNAME_ENG_REM_SPRRABOTA: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SPRRABOTA'
      Size = 200
    end
    object DocTNAME_REM_SPRRABOTA_GRP: TFIBWideStringField
      FieldName = 'NAME_REM_SPRRABOTA_GRP'
      Size = 200
    end
    object DocTNAME_ENG_REM_SPRRABOTA_GRP: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SPRRABOTA_GRP'
      Size = 200
    end
    object DocTOLD_NAME_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'OLD_NAME_REM_SHARDWARE'
      Size = 200
    end
    object DocTOLD_CODE_REM_SHARDWARE: TFIBIntegerField
      FieldName = 'OLD_CODE_REM_SHARDWARE'
    end
    object DocTOLD_SERNUM_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'OLD_SERNUM_REM_SHARDWARE'
      Size = 50
    end
    object DocTFL_ISP_REM_DZAKTPRT: TFIBIntegerField
      FieldName = 'FL_ISP_REM_DZAKTPRT'
    end
    object DocTIDPRCOND_REM_DZAKTPRT: TFIBLargeIntField
      FieldName = 'IDPRCOND_REM_DZAKTPRT'
    end
    object DocTIDPRSECTION_REM_DZAKTPRT: TFIBLargeIntField
      FieldName = 'IDPRSECTION_REM_DZAKTPRT'
    end
    object DocTCODE_REM_SPRCONDITION: TFIBWideStringField
      FieldName = 'CODE_REM_SPRCONDITION'
      Size = 10
    end
    object DocTNAME_REM_SPRCONDITION: TFIBWideStringField
      FieldName = 'NAME_REM_SPRCONDITION'
      OnGetText = DocTNAME_REM_SPRCONDITIONGetText
      Size = 200
    end
    object DocTNAME_ENG_REM_SPRCONDITION: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SPRCONDITION'
      Size = 200
    end
    object DocTCODE_REM_SPRCOND_GRP: TFIBWideStringField
      FieldName = 'CODE_REM_SPRCOND_GRP'
      Size = 10
    end
    object DocTNAME_REM_SPRCOND_GRP: TFIBWideStringField
      FieldName = 'NAME_REM_SPRCOND_GRP'
      Size = 200
    end
    object DocTNAME_ENG_REM_SPRCOND_GRP: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SPRCOND_GRP'
      Size = 200
    end
    object DocTCODE_REM_SPRSECTION: TFIBWideStringField
      FieldName = 'CODE_REM_SPRSECTION'
      Size = 10
    end
    object DocTNAME_REM_SPRSECTION: TFIBWideStringField
      FieldName = 'NAME_REM_SPRSECTION'
      OnGetText = DocTNAME_REM_SPRSECTIONGetText
      Size = 200
    end
    object DocTNAME_ENG_REM_SPRSECTION: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SPRSECTION'
      Size = 200
    end
    object DocTCODE_REM_SPRSECTION_GRP: TFIBWideStringField
      FieldName = 'CODE_REM_SPRSECTION_GRP'
      Size = 10
    end
    object DocTNAME_REM_SPRSECTION_GRP: TFIBWideStringField
      FieldName = 'NAME_REM_SPRSECTION_GRP'
      Size = 200
    end
    object DocTNAME_ENG_REM_SPRSECTION_GRP: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SPRSECTION_GRP'
      Size = 200
    end
    object DocTIDTNOM_REM_DZAKTPRT: TFIBLargeIntField
      FieldName = 'IDTNOM_REM_DZAKTPRT'
    end
    object DocTIDHW_DONOR_REM_DZAKTPRT: TFIBLargeIntField
      FieldName = 'IDHW_DONOR_REM_DZAKTPRT'
    end
    object DocTIDTYP_USEL_REM_DZAKTPRT: TFIBLargeIntField
      FieldName = 'IDTYP_USEL_REM_DZAKTPRT'
    end
    object DocTDESCR_REM_DZAKTPRT: TFIBWideStringField
      FieldName = 'DESCR_REM_DZAKTPRT'
      Size = 150
    end
    object DocTDONOR_NAME_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'DONOR_NAME_REM_SHARDWARE'
      Size = 200
    end
    object DocTDONOR_CODE_REM_SHARDWARE: TFIBIntegerField
      FieldName = 'DONOR_CODE_REM_SHARDWARE'
    end
    object DocTDONOR_SERNUM_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'DONOR_SERNUM_REM_SHARDWARE'
      Size = 50
    end
    object DocTNAME_REM_STYPUSLOV: TFIBWideStringField
      FieldName = 'NAME_REM_STYPUSLOV'
      Size = 200
    end
    object DocTNAME_STNOM: TFIBWideStringField
      FieldName = 'NAME_STNOM'
      Size = 200
    end
    object DocTNAME_TYPE_NOM_LOOCUP: TStringField
      FieldKind = fkLookup
      FieldName = 'NAME_TYPE_NOM_LOOCUP'
      LookupDataSet = TypeNom
      LookupKeyFields = 'ID_STNOM'
      LookupResultField = 'NAME_STNOM'
      KeyFields = 'IDTNOM_REM_DZAKTPRT'
      Size = 50
      Lookup = True
    end
    object DocTIDTVZIP_REM_DZAKTPRT: TFIBLargeIntField
      FieldName = 'IDTVZIP_REM_DZAKTPRT'
    end
    object DocTIDMHRAN_REM_DZAKTPRT: TFIBLargeIntField
      FieldName = 'IDMHRAN_REM_DZAKTPRT'
    end
    object DocTNAME_SMHRAN: TFIBWideStringField
      FieldName = 'NAME_SMHRAN'
      Size = 200
    end
    object DocTNAME_REM_STVZIP: TFIBWideStringField
      FieldName = 'NAME_REM_STVZIP'
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
    Left = 240
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
    Left = 240
    Top = 64
  end
  object IBTrDvReg: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 24
    Top = 272
  end
  object NumDoc: TpFIBDataSet
    SelectSQL.Strings = (
      'select max(NUM_REM_GALLDOC) AS MAXNUMBER from  REM_GALLDOC'
      
        'where TDOC_REM_GALLDOC='#39'REMZAKTPR'#39' and POS_REM_GALLDOC > :PARAM_' +
        'POS')
    Left = 296
    Top = 16
    object NumDocMAXNUMBER: TFIBIntegerField
      FieldName = 'MAXNUMBER'
    end
  end
  object pFIBQ: TpFIBQuery
    Left = 336
    Top = 176
    qoStartTransaction = True
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      
        'EXECUTE PROCEDURE REM_DOC_ZAKTPR_CANCEL_DVREG(:PARAM_IDDOC,0,0,0' +
        ')')
    Left = 96
    Top = 304
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE REM_DOC_ZAKTPR_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 240
    qoStartTransaction = True
  end
  object TypeNom: TpFIBDataSet
    SelectSQL.Strings = (
      'select stnom.id_stnom,'
      '       stnom.name_stnom'
      'from stnom'
      'order by stnom.name_stnom')
    Transaction = IBTr
    Left = 512
    Top = 232
    poUseLargeIntField = True
    object TypeNomID_STNOM: TFIBLargeIntField
      FieldName = 'ID_STNOM'
    end
    object TypeNomNAME_STNOM: TFIBWideStringField
      FieldName = 'NAME_STNOM'
      Size = 200
    end
  end
end
