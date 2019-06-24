object REM_DMDocZStart: TREM_DMDocZStart
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 439
  Width = 667
  object DataSourceDoc: TDataSource
    DataSet = Doc
    Left = 72
    Top = 64
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
      '    PREFIKS_NUM_REM_GALLDOC = :PREFIKS_NUM_REM_GALLDOC'
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
      '    PREFIKS_NUM_REM_GALLDOC'
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
      '    :PREFIKS_NUM_REM_GALLDOC'
      ')')
    RefreshSQL.Strings = (
      'select rem_galldoc.*,'
      ' suser.fname_user ,'
      ' sinfbase_obmen.name_sinfbase_obmen,'
      ' sfirm.namefirm,'
      ' ssklad.namesklad,'
      ' sklient.nameklient,'
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
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
      ' sbusiness_oper.name_sbusiness_oper'
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
      Size = 10
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
  end
  object Doc: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_DZSTART'
      'SET '
      '    IDBASE_REM_DZSTART = :IDBASE_REM_DZSTART,'
      '    GID_REM_DZSTART = :GID_REM_DZSTART,'
      '    IDDOC_REM_DZSTART = :IDDOC_REM_DZSTART,'
      '    IDZ_REM_DZSTART = :IDZ_REM_DZSTART,'
      '    PRIM_REM_DZSTART = :PRIM_REM_DZSTART,'
      '    IDPR_REM_DZSTART = :IDPR_REM_DZSTART,'
      '    IDCFCPR_REM_DZSTART = :IDCFCPR_REM_DZSTART,'
      '    IDNEISPR_REM_DZSTART = :IDNEISPR_REM_DZSTART,'
      '    IDPRMODEL_REM_DZSTART = :IDPRMODEL_REM_DZSTART,'
      '    PODO_REM_DZSTART = :PODO_REM_DZSTART,'
      '    PRODAVEC_REM_DZSTART = :PRODAVEC_REM_DZSTART,'
      '    SERNUM3_REM_DZSTART = :SERNUM3_REM_DZSTART,'
      '    SERNUM4_REM_DZSTART = :SERNUM4_REM_DZSTART,'
      '    NUMBAT_REM_DZSTART = :NUMBAT_REM_DZSTART,'
      '    SOST_REM_DZSTART = :SOST_REM_DZSTART,'
      '    DATEVIPUSK_REM_DZSTART = :DATEVIPUSK_REM_DZSTART,'
      '    DATE_PRODAGI_REM_DZSTART = :DATE_PRODAGI_REM_DZSTART,'
      '    KEM_SDANO_REM_DZSTART = :KEM_SDANO_REM_DZSTART,'
      '    TYPE_REMONT_REM_DZSTART = :TYPE_REMONT_REM_DZSTART,'
      '    IDSELLER_REM_DZSTART = :IDSELLER_REM_DZSTART'
      'WHERE'
      '    ID_REM_DZSTART = :OLD_ID_REM_DZSTART'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DZSTART'
      'WHERE'
      '        ID_REM_DZSTART = :OLD_ID_REM_DZSTART'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DZSTART('
      '    ID_REM_DZSTART,'
      '    IDBASE_REM_DZSTART,'
      '    GID_REM_DZSTART,'
      '    IDDOC_REM_DZSTART,'
      '    IDZ_REM_DZSTART,'
      '    PRIM_REM_DZSTART,'
      '    IDPR_REM_DZSTART,'
      '    IDCFCPR_REM_DZSTART,'
      '    IDNEISPR_REM_DZSTART,'
      '    IDPRMODEL_REM_DZSTART,'
      '    PODO_REM_DZSTART,'
      '    PRODAVEC_REM_DZSTART,'
      '    SERNUM3_REM_DZSTART,'
      '    SERNUM4_REM_DZSTART,'
      '    NUMBAT_REM_DZSTART,'
      '    SOST_REM_DZSTART,'
      '    DATEVIPUSK_REM_DZSTART,'
      '    DATE_PRODAGI_REM_DZSTART,'
      '    KEM_SDANO_REM_DZSTART,'
      '    TYPE_REMONT_REM_DZSTART,'
      '    IDSELLER_REM_DZSTART'
      ')'
      'VALUES('
      '    :ID_REM_DZSTART,'
      '    :IDBASE_REM_DZSTART,'
      '    :GID_REM_DZSTART,'
      '    :IDDOC_REM_DZSTART,'
      '    :IDZ_REM_DZSTART,'
      '    :PRIM_REM_DZSTART,'
      '    :IDPR_REM_DZSTART,'
      '    :IDCFCPR_REM_DZSTART,'
      '    :IDNEISPR_REM_DZSTART,'
      '    :IDPRMODEL_REM_DZSTART,'
      '    :PODO_REM_DZSTART,'
      '    :PRODAVEC_REM_DZSTART,'
      '    :SERNUM3_REM_DZSTART,'
      '    :SERNUM4_REM_DZSTART,'
      '    :NUMBAT_REM_DZSTART,'
      '    :SOST_REM_DZSTART,'
      '    :DATEVIPUSK_REM_DZSTART,'
      '    :DATE_PRODAGI_REM_DZSTART,'
      '    :KEM_SDANO_REM_DZSTART,'
      '    :TYPE_REMONT_REM_DZSTART,'
      '    :IDSELLER_REM_DZSTART'
      ')')
    RefreshSQL.Strings = (
      ''
      'select rem_dzstart.*,'
      '        rem_z.name_rem_z,'
      '        rem_z.num_rem_z,'
      '        rem_z.pos_rem_z,'
      '        rem_z.num_gardoc_rem_z,'
      '        rem_z.sernum_rem_z,'
      '        rem_z.sernum2_rem_z,'
      '        rem_z.klient_name_rem_z,'
      '        rem_z.model_rem_z,'
      '        rem_smodel.name_rem_smodel,'
      '        sproducer.name_sproducer,'
      ''
      '        rem_sprneispr.name_rem_sprneispr,'
      '        rem_sprneispr.code_rem_sprneispr,'
      '        rem_sprneispr_grp.name_rem_sprneispr_grp,'
      '        rem_sprneispr_grp.name_eng_rem_sprneispr_grp,'
      ''
      '        rem_sneispr.name_rem_sneispr,'
      '        rem_sneispr.name_eng_rem_sneispr,'
      '        rem_sgrpneispr.name_rem_sgrpneispr,'
      '        rem_sgrpneispr.name_eng_rem_sgrpneispr,'
      ''
      '        rem_sprmodel.name_rem_sprmodel,'
      '        rem_sprmodel.code_rem_sprmodel,'
      '        sseller.name_sseller'
      ''
      ''
      ''
      'from  rem_dzstart'
      
        'left outer join rem_z on rem_dzstart.idz_rem_dzstart=rem_z.id_re' +
        'm_z'
      
        'left outer join rem_smodel on rem_z.idmodel_rem_z=rem_smodel.id_' +
        'rem_smodel'
      
        'left outer join sproducer on rem_dzstart.idpr_rem_dzstart=sprodu' +
        'cer.id_sproducer'
      ''
      
        'left outer join rem_sprneispr on rem_dzstart.idcfcpr_rem_dzstart' +
        '=rem_sprneispr.id_rem_sprneispr'
      
        'left outer join rem_sprneispr_grp on rem_sprneispr.idgrp_rem_spr' +
        'neispr=rem_sprneispr_grp.id_rem_sprneispr_grp'
      ''
      
        'left outer join rem_sneispr on rem_dzstart.idneispr_rem_dzstart=' +
        'rem_sneispr.id_rem_sneispr'
      
        'left outer join rem_sgrpneispr on rem_sneispr.idgrp_rem_sneispr=' +
        'rem_sgrpneispr.id_rem_sgrpneispr'
      ''
      
        'left outer join rem_sprmodel on rem_dzstart.idprmodel_rem_dzstar' +
        't=rem_sprmodel.id_rem_sprmodel'
      
        'left outer join sseller on rem_dzstart.idseller_rem_dzstart=ssel' +
        'ler.id_sseller'
      'where(  rem_dzstart.iddoc_rem_dzstart=:PARAM_IDDOC'
      
        '     ) and (     REM_DZSTART.ID_REM_DZSTART = :OLD_ID_REM_DZSTAR' +
        'T'
      '     )'
      '    ')
    SelectSQL.Strings = (
      ''
      'select rem_dzstart.*,'
      '        rem_z.name_rem_z,'
      '        rem_z.num_rem_z,'
      '        rem_z.pos_rem_z,'
      '        rem_z.num_gardoc_rem_z,'
      '        rem_z.sernum_rem_z,'
      '        rem_z.sernum2_rem_z,'
      '        rem_z.klient_name_rem_z,'
      '        rem_z.model_rem_z,'
      '        rem_smodel.name_rem_smodel,'
      '        sproducer.name_sproducer,'
      ''
      '        rem_sprneispr.name_rem_sprneispr,'
      '        rem_sprneispr.code_rem_sprneispr,'
      '        rem_sprneispr_grp.name_rem_sprneispr_grp,'
      '        rem_sprneispr_grp.name_eng_rem_sprneispr_grp,'
      ''
      '        rem_sneispr.name_rem_sneispr,'
      '        rem_sneispr.name_eng_rem_sneispr,'
      '        rem_sgrpneispr.name_rem_sgrpneispr,'
      '        rem_sgrpneispr.name_eng_rem_sgrpneispr,'
      ''
      '        rem_sprmodel.name_rem_sprmodel,'
      '        rem_sprmodel.code_rem_sprmodel,'
      '        sseller.name_sseller'
      ''
      ''
      ''
      'from  rem_dzstart'
      
        'left outer join rem_z on rem_dzstart.idz_rem_dzstart=rem_z.id_re' +
        'm_z'
      
        'left outer join rem_smodel on rem_z.idmodel_rem_z=rem_smodel.id_' +
        'rem_smodel'
      
        'left outer join sproducer on rem_dzstart.idpr_rem_dzstart=sprodu' +
        'cer.id_sproducer'
      ''
      
        'left outer join rem_sprneispr on rem_dzstart.idcfcpr_rem_dzstart' +
        '=rem_sprneispr.id_rem_sprneispr'
      
        'left outer join rem_sprneispr_grp on rem_sprneispr.idgrp_rem_spr' +
        'neispr=rem_sprneispr_grp.id_rem_sprneispr_grp'
      ''
      
        'left outer join rem_sneispr on rem_dzstart.idneispr_rem_dzstart=' +
        'rem_sneispr.id_rem_sneispr'
      
        'left outer join rem_sgrpneispr on rem_sneispr.idgrp_rem_sneispr=' +
        'rem_sgrpneispr.id_rem_sgrpneispr'
      ''
      
        'left outer join rem_sprmodel on rem_dzstart.idprmodel_rem_dzstar' +
        't=rem_sprmodel.id_rem_sprmodel'
      
        'left outer join sseller on rem_dzstart.idseller_rem_dzstart=ssel' +
        'ler.id_sseller'
      'where rem_dzstart.iddoc_rem_dzstart=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_DZSTART'
    AutoUpdateOptions.KeyFields = 'ID_REM_DZSTART'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DZSTART_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object DocID_REM_DZSTART: TFIBLargeIntField
      FieldName = 'ID_REM_DZSTART'
    end
    object DocIDBASE_REM_DZSTART: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DZSTART'
    end
    object DocGID_REM_DZSTART: TFIBWideStringField
      FieldName = 'GID_REM_DZSTART'
      Size = 10
    end
    object DocIDDOC_REM_DZSTART: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DZSTART'
    end
    object DocIDZ_REM_DZSTART: TFIBLargeIntField
      FieldName = 'IDZ_REM_DZSTART'
    end
    object DocPRIM_REM_DZSTART: TFIBWideStringField
      FieldName = 'PRIM_REM_DZSTART'
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
    object DocIDPR_REM_DZSTART: TFIBLargeIntField
      FieldName = 'IDPR_REM_DZSTART'
    end
    object DocIDCFCPR_REM_DZSTART: TFIBLargeIntField
      FieldName = 'IDCFCPR_REM_DZSTART'
    end
    object DocIDNEISPR_REM_DZSTART: TFIBLargeIntField
      FieldName = 'IDNEISPR_REM_DZSTART'
    end
    object DocIDPRMODEL_REM_DZSTART: TFIBLargeIntField
      FieldName = 'IDPRMODEL_REM_DZSTART'
    end
    object DocPODO_REM_DZSTART: TFIBWideStringField
      FieldName = 'PODO_REM_DZSTART'
      Size = 40
    end
    object DocPRODAVEC_REM_DZSTART: TFIBWideStringField
      FieldName = 'PRODAVEC_REM_DZSTART'
      Size = 40
    end
    object DocSERNUM3_REM_DZSTART: TFIBWideStringField
      FieldName = 'SERNUM3_REM_DZSTART'
      Size = 50
    end
    object DocSERNUM4_REM_DZSTART: TFIBWideStringField
      FieldName = 'SERNUM4_REM_DZSTART'
      Size = 50
    end
    object DocNUMBAT_REM_DZSTART: TFIBWideStringField
      FieldName = 'NUMBAT_REM_DZSTART'
      Size = 50
    end
    object DocSOST_REM_DZSTART: TFIBWideStringField
      FieldName = 'SOST_REM_DZSTART'
      Size = 150
    end
    object DocDATEVIPUSK_REM_DZSTART: TFIBDateField
      FieldName = 'DATEVIPUSK_REM_DZSTART'
    end
    object DocDATE_PRODAGI_REM_DZSTART: TFIBDateField
      FieldName = 'DATE_PRODAGI_REM_DZSTART'
    end
    object DocKEM_SDANO_REM_DZSTART: TFIBIntegerField
      FieldName = 'KEM_SDANO_REM_DZSTART'
    end
    object DocTYPE_REMONT_REM_DZSTART: TFIBIntegerField
      FieldName = 'TYPE_REMONT_REM_DZSTART'
    end
    object DocNAME_SPRODUCER: TFIBWideStringField
      FieldName = 'NAME_SPRODUCER'
      Size = 200
    end
    object DocNAME_REM_SPRNEISPR: TFIBWideStringField
      FieldName = 'NAME_REM_SPRNEISPR'
      Size = 200
    end
    object DocCODE_REM_SPRNEISPR: TFIBWideStringField
      FieldName = 'CODE_REM_SPRNEISPR'
    end
    object DocNAME_REM_SNEISPR: TFIBWideStringField
      FieldName = 'NAME_REM_SNEISPR'
      Size = 200
    end
    object DocNAME_REM_SPRMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SPRMODEL'
      Size = 200
    end
    object DocCODE_REM_SPRMODEL: TFIBWideStringField
      FieldName = 'CODE_REM_SPRMODEL'
    end
    object DocNUM_GARDOC_REM_Z: TFIBWideStringField
      FieldName = 'NUM_GARDOC_REM_Z'
      Size = 50
    end
    object DocIDSELLER_REM_DZSTART: TFIBLargeIntField
      FieldName = 'IDSELLER_REM_DZSTART'
    end
    object DocNAME_REM_SPRNEISPR_GRP: TFIBWideStringField
      FieldName = 'NAME_REM_SPRNEISPR_GRP'
      Size = 200
    end
    object DocNAME_ENG_REM_SPRNEISPR_GRP: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SPRNEISPR_GRP'
      Size = 200
    end
    object DocNAME_ENG_REM_SNEISPR: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SNEISPR'
      Size = 200
    end
    object DocNAME_REM_SGRPNEISPR: TFIBWideStringField
      FieldName = 'NAME_REM_SGRPNEISPR'
      Size = 200
    end
    object DocNAME_ENG_REM_SGRPNEISPR: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SGRPNEISPR'
      Size = 200
    end
    object DocNAME_SSELLER: TFIBWideStringField
      FieldName = 'NAME_SSELLER'
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
      
        'where TDOC_REM_GALLDOC='#39'REMZSTART'#39' and POS_REM_GALLDOC > :PARAM_' +
        'POS')
    Transaction = IBTr
    Left = 296
    Top = 16
    object NumDocMAXNUMBER: TFIBIntegerField
      FieldName = 'MAXNUMBER'
    end
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 336
    Top = 176
    qoStartTransaction = True
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      
        'EXECUTE PROCEDURE REM_DOC_ZSTART_CANCEL_DVREG(:PARAM_IDDOC,0,0,0' +
        ')')
    Left = 96
    Top = 304
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE REM_DOC_ZSTART_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 240
    qoStartTransaction = True
  end
end
