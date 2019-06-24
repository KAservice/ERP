object REM_DMZayavka: TREM_DMZayavka
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 511
  Width = 514
  object DataSourceGurZKompl: TDataSource
    DataSet = GurZKompl
    Left = 72
    Top = 136
  end
  object DataSourceGurZNeispr: TDataSource
    DataSet = GurZNeispr
    Left = 72
    Top = 192
  end
  object DataSourceGurZ: TDataSource
    DataSet = GurZ
    Left = 72
    Top = 16
  end
  object GurZ: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_Z'
      'SET '
      '    GID_REM_Z = :GID_REM_Z,'
      '    PREFIKS_REM_Z = :PREFIKS_REM_Z,'
      '    NUM_REM_Z = :NUM_REM_Z,'
      '    POS_REM_Z = :POS_REM_Z,'
      '    IDBASE_REM_Z = :IDBASE_REM_Z,'
      '    IDMODEL_REM_Z = :IDMODEL_REM_Z,'
      '    IDSKLPR_REM_Z = :IDSKLPR_REM_Z,'
      '    IDKLIENT_REM_Z = :IDKLIENT_REM_Z,'
      '    IDDILER_REM_Z = :IDDILER_REM_Z,'
      '    SERNUM_REM_Z = :SERNUM_REM_Z,'
      '    NAME_REM_Z = :NAME_REM_Z,'
      '    DESCR_REM_Z = :DESCR_REM_Z,'
      '    IDTYPEREM_REM_Z = :IDTYPEREM_REM_Z,'
      '    IDSOST_REM_Z = :IDSOST_REM_Z,'
      '    IDTECSKL_REM_Z = :IDTECSKL_REM_Z,'
      '    IDUSER_REM_Z = :IDUSER_REM_Z,'
      '    OPER_REM_Z = :OPER_REM_Z,'
      '    SUM_REM_Z = :SUM_REM_Z,'
      '    SROK_REM_Z = :SROK_REM_Z,'
      '    OUT_REM_Z = :OUT_REM_Z,'
      '    IDFIRM_REM_Z = :IDFIRM_REM_Z,'
      '    NEISPR_REM_Z = :NEISPR_REM_Z,'
      '    KLIENT_NAME_REM_Z = :KLIENT_NAME_REM_Z,'
      '    KLIENT_ADR_REM_Z = :KLIENT_ADR_REM_Z,'
      '    KLIENT_PHONE_REM_Z = :KLIENT_PHONE_REM_Z,'
      '    KOMPLECT_REM_Z = :KOMPLECT_REM_Z,'
      '    MODEL_REM_Z = :MODEL_REM_Z,'
      '    SOST_REM_Z = :SOST_REM_Z,'
      '    SERNUM2_REM_Z = :SERNUM2_REM_Z,'
      '    COMENTS_REM_Z = :COMENTS_REM_Z,'
      '    POSOUT_REM_Z = :POSOUT_REM_Z,'
      '    POSREMONT_REM_Z = :POSREMONT_REM_Z,'
      '    WARRANTY_REM_Z = :WARRANTY_REM_Z,'
      '    IDMEXANIK_REM_Z = :IDMEXANIK_REM_Z,'
      '    IDBRAND_REM_Z = :IDBRAND_REM_Z,'
      '    IDACTCAT_REM_Z = :IDACTCAT_REM_Z,'
      '    GUID_REM_Z = :GUID_REM_Z,'
      '    IDZOSN_REM_Z = :IDZOSN_REM_Z,'
      '    FL_POVTOR_REM_Z = :FL_POVTOR_REM_Z,'
      '    DILER_NUMZ_REM_Z = :DILER_NUMZ_REM_Z,'
      '    DILER_POSZ_REM_Z = :DILER_POSZ_REM_Z,'
      '    DILER_GUIDZ_REM_Z = :DILER_GUIDZ_REM_Z,'
      '    SC_NUMZ_REM_Z = :SC_NUMZ_REM_Z,'
      '    SC_POSZ_REM_Z = :SC_POSZ_REM_Z,'
      '    SC_GUIDZ_REM_Z = :SC_GUIDZ_REM_Z,'
      '    FL_ADDREPORT_REM_Z = :FL_ADDREPORT_REM_Z,'
      '    SERNUM_STR_REM_Z = :SERNUM_STR_REM_Z,'
      '    IDHW_REM_Z = :IDHW_REM_Z,'
      '    IDKKT_REM_Z = :IDKKT_REM_Z,'
      '    FL_KLIENT_UVEDOML_REM_Z = :FL_KLIENT_UVEDOML_REM_Z,'
      '    FL_TREB_KONS_KL_REM_Z = :FL_TREB_KONS_KL_REM_Z,'
      '    FL_KL_OTV_NA_ZAPROS_REM_Z = :FL_KL_OTV_NA_ZAPROS_REM_Z,'
      '    PREFIKS_NUM_REM_Z = :PREFIKS_NUM_REM_Z,'
      '    NUM_GARDOC_REM_Z = :NUM_GARDOC_REM_Z,'
      '    FL_FICTIV_REM_Z = :FL_FICTIV_REM_Z,'
      '    FL_NE_OTCH_REM_Z = :FL_NE_OTCH_REM_Z,'
      '    FL_NADO_OTCH_REM_Z = :FL_NADO_OTCH_REM_Z,'
      '    FL_ISM_GARDOC_REM_Z = :FL_ISM_GARDOC_REM_Z,'
      '    NUM_GARDOC_NEW_REM_Z = :NUM_GARDOC_NEW_REM_Z,'
      '    FL_ISM_SERNUM_REM_Z = :FL_ISM_SERNUM_REM_Z,'
      '    SERNUM_NEW_REM_Z = :SERNUM_NEW_REM_Z,'
      '    FL_ISM_SERNUM2_REM_Z = :FL_ISM_SERNUM2_REM_Z,'
      '    SERNUM2_NEW_REM_Z = :SERNUM2_NEW_REM_Z,'
      '    GOTOVO_K_VIDACHE_REM_Z = :GOTOVO_K_VIDACHE_REM_Z'
      'WHERE'
      '    ID_REM_Z = :OLD_ID_REM_Z'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_Z'
      'WHERE'
      '        ID_REM_Z = :OLD_ID_REM_Z'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_Z('
      '    ID_REM_Z,'
      '    GID_REM_Z,'
      '    PREFIKS_REM_Z,'
      '    NUM_REM_Z,'
      '    POS_REM_Z,'
      '    IDBASE_REM_Z,'
      '    IDMODEL_REM_Z,'
      '    IDSKLPR_REM_Z,'
      '    IDKLIENT_REM_Z,'
      '    IDDILER_REM_Z,'
      '    SERNUM_REM_Z,'
      '    NAME_REM_Z,'
      '    DESCR_REM_Z,'
      '    IDTYPEREM_REM_Z,'
      '    IDSOST_REM_Z,'
      '    IDTECSKL_REM_Z,'
      '    IDUSER_REM_Z,'
      '    OPER_REM_Z,'
      '    SUM_REM_Z,'
      '    SROK_REM_Z,'
      '    OUT_REM_Z,'
      '    IDFIRM_REM_Z,'
      '    NEISPR_REM_Z,'
      '    KLIENT_NAME_REM_Z,'
      '    KLIENT_ADR_REM_Z,'
      '    KLIENT_PHONE_REM_Z,'
      '    KOMPLECT_REM_Z,'
      '    MODEL_REM_Z,'
      '    SOST_REM_Z,'
      '    SERNUM2_REM_Z,'
      '    COMENTS_REM_Z,'
      '    POSOUT_REM_Z,'
      '    POSREMONT_REM_Z,'
      '    WARRANTY_REM_Z,'
      '    IDMEXANIK_REM_Z,'
      '    IDBRAND_REM_Z,'
      '    IDACTCAT_REM_Z,'
      '    GUID_REM_Z,'
      '    IDZOSN_REM_Z,'
      '    FL_POVTOR_REM_Z,'
      '    DILER_NUMZ_REM_Z,'
      '    DILER_POSZ_REM_Z,'
      '    DILER_GUIDZ_REM_Z,'
      '    SC_NUMZ_REM_Z,'
      '    SC_POSZ_REM_Z,'
      '    SC_GUIDZ_REM_Z,'
      '    FL_ADDREPORT_REM_Z,'
      '    SERNUM_STR_REM_Z,'
      '    IDHW_REM_Z,'
      '    IDKKT_REM_Z,'
      '    FL_KLIENT_UVEDOML_REM_Z,'
      '    FL_TREB_KONS_KL_REM_Z,'
      '    FL_KL_OTV_NA_ZAPROS_REM_Z,'
      '    PREFIKS_NUM_REM_Z,'
      '    NUM_GARDOC_REM_Z,'
      '    FL_FICTIV_REM_Z,'
      '    FL_NE_OTCH_REM_Z,'
      '    FL_NADO_OTCH_REM_Z,'
      '    FL_ISM_GARDOC_REM_Z,'
      '    NUM_GARDOC_NEW_REM_Z,'
      '    FL_ISM_SERNUM_REM_Z,'
      '    SERNUM_NEW_REM_Z,'
      '    FL_ISM_SERNUM2_REM_Z,'
      '    SERNUM2_NEW_REM_Z,'
      '    GOTOVO_K_VIDACHE_REM_Z'
      ')'
      'VALUES('
      '    :ID_REM_Z,'
      '    :GID_REM_Z,'
      '    :PREFIKS_REM_Z,'
      '    :NUM_REM_Z,'
      '    :POS_REM_Z,'
      '    :IDBASE_REM_Z,'
      '    :IDMODEL_REM_Z,'
      '    :IDSKLPR_REM_Z,'
      '    :IDKLIENT_REM_Z,'
      '    :IDDILER_REM_Z,'
      '    :SERNUM_REM_Z,'
      '    :NAME_REM_Z,'
      '    :DESCR_REM_Z,'
      '    :IDTYPEREM_REM_Z,'
      '    :IDSOST_REM_Z,'
      '    :IDTECSKL_REM_Z,'
      '    :IDUSER_REM_Z,'
      '    :OPER_REM_Z,'
      '    :SUM_REM_Z,'
      '    :SROK_REM_Z,'
      '    :OUT_REM_Z,'
      '    :IDFIRM_REM_Z,'
      '    :NEISPR_REM_Z,'
      '    :KLIENT_NAME_REM_Z,'
      '    :KLIENT_ADR_REM_Z,'
      '    :KLIENT_PHONE_REM_Z,'
      '    :KOMPLECT_REM_Z,'
      '    :MODEL_REM_Z,'
      '    :SOST_REM_Z,'
      '    :SERNUM2_REM_Z,'
      '    :COMENTS_REM_Z,'
      '    :POSOUT_REM_Z,'
      '    :POSREMONT_REM_Z,'
      '    :WARRANTY_REM_Z,'
      '    :IDMEXANIK_REM_Z,'
      '    :IDBRAND_REM_Z,'
      '    :IDACTCAT_REM_Z,'
      '    :GUID_REM_Z,'
      '    :IDZOSN_REM_Z,'
      '    :FL_POVTOR_REM_Z,'
      '    :DILER_NUMZ_REM_Z,'
      '    :DILER_POSZ_REM_Z,'
      '    :DILER_GUIDZ_REM_Z,'
      '    :SC_NUMZ_REM_Z,'
      '    :SC_POSZ_REM_Z,'
      '    :SC_GUIDZ_REM_Z,'
      '    :FL_ADDREPORT_REM_Z,'
      '    :SERNUM_STR_REM_Z,'
      '    :IDHW_REM_Z,'
      '    :IDKKT_REM_Z,'
      '    :FL_KLIENT_UVEDOML_REM_Z,'
      '    :FL_TREB_KONS_KL_REM_Z,'
      '    :FL_KL_OTV_NA_ZAPROS_REM_Z,'
      '    :PREFIKS_NUM_REM_Z,'
      '    :NUM_GARDOC_REM_Z,'
      '    :FL_FICTIV_REM_Z,'
      '    :FL_NE_OTCH_REM_Z,'
      '    :FL_NADO_OTCH_REM_Z,'
      '    :FL_ISM_GARDOC_REM_Z,'
      '    :NUM_GARDOC_NEW_REM_Z,'
      '    :FL_ISM_SERNUM_REM_Z,'
      '    :SERNUM_NEW_REM_Z,'
      '    :FL_ISM_SERNUM2_REM_Z,'
      '    :SERNUM2_NEW_REM_Z,'
      '    :GOTOVO_K_VIDACHE_REM_Z'
      ')')
    RefreshSQL.Strings = (
      'select rem_z.*,'
      '    sfirm.namefirm,'
      '    NAME_SINFBASE_OBMEN,'
      '    rem_smodel.name_rem_smodel,'
      '    sklad_pr.namesklad as name_sklad_pr,'
      '    sklient.nameklient,'
      '    diler.nameklient as namediler,'
      '    rem_stremont.name_stremont,'
      '    rem_ssost.name_remssost,'
      '    sklad_tec.namesklad as name_sklad_tec,'
      '    suser.name_user,'
      '    mexanik.name_user as name_mexanik,'
      '    sbrand.name_sbrand,'
      '    rem_sactcategory.name_rem_sactcategory,'
      '    rem_shardware.name_rem_shardware,'
      '    rem_shardware.sernum_rem_shardware,'
      '    rem_shardware.sernum2_rem_shardware,'
      '    rem_skkt.name_rem_skkt,'
      '    rem_skkt.sernum_rem_skkt'
      'from rem_z'
      'left outer join sfirm on sfirm.idfirm=rem_z.idfirm_rem_z'
      'left outer join SINFBASE_OBMEN on IDBASE_REM_Z=ID_SINFBASE_OBMEN'
      
        'left outer join rem_smodel on rem_smodel.id_rem_smodel=rem_z.idm' +
        'odel_rem_z'
      
        'left outer join ssklad as sklad_pr on sklad_pr.idsklad=rem_z.ids' +
        'klpr_rem_z'
      'left outer join sklient on sklient.idklient=rem_z.idklient_rem_z'
      
        'left outer join sklient as diler on diler.idklient=rem_z.iddiler' +
        '_rem_z'
      
        'left outer join rem_stremont on rem_stremont.id_stremont=rem_z.i' +
        'dtyperem_rem_z'
      
        'left outer join rem_ssost on rem_ssost.id_remssost=rem_z.idsost_' +
        'rem_z'
      
        'left outer join ssklad as sklad_tec on sklad_tec.idsklad=rem_z.i' +
        'dtecskl_rem_z'
      'left outer join suser  on suser.id_user=rem_z.iduser_rem_z'
      
        'left outer join suser as mexanik on mexanik.id_user=rem_z.idmexa' +
        'nik_rem_z'
      'left outer join sbrand on sbrand.id_sbrand=rem_z.idbrand_rem_z'
      
        'left outer join rem_sactcategory on rem_sactcategory.id_rem_sact' +
        'category=rem_z.idactcat_rem_z'
      
        'left outer join rem_shardware on rem_z.idhw_rem_z=rem_shardware.' +
        'id_rem_shardware'
      
        'left outer join rem_skkt on rem_z.idkkt_rem_z=rem_skkt.idklient_' +
        'rem_skkt'
      'where(  ID_REM_Z=:PARAM_ID'
      '     ) and (     REM_Z.ID_REM_Z = :OLD_ID_REM_Z'
      '     )'
      '    '
      '')
    SelectSQL.Strings = (
      'select rem_z.*,'
      '    sfirm.namefirm,'
      '    NAME_SINFBASE_OBMEN,'
      '    rem_smodel.name_rem_smodel,'
      '    sklad_pr.namesklad as name_sklad_pr,'
      '    sklient.nameklient,'
      '    diler.nameklient as namediler,'
      '    rem_stremont.name_stremont,'
      '    rem_ssost.name_remssost,'
      '    sklad_tec.namesklad as name_sklad_tec,'
      '    suser.name_user,'
      '    mexanik.name_user as name_mexanik,'
      '    sbrand.name_sbrand,'
      '    rem_sactcategory.name_rem_sactcategory,'
      '    rem_shardware.name_rem_shardware,'
      '    rem_shardware.sernum_rem_shardware,'
      '    rem_shardware.sernum2_rem_shardware,'
      '    rem_skkt.name_rem_skkt,'
      '    rem_skkt.sernum_rem_skkt'
      'from rem_z'
      'left outer join sfirm on sfirm.idfirm=rem_z.idfirm_rem_z'
      'left outer join SINFBASE_OBMEN on IDBASE_REM_Z=ID_SINFBASE_OBMEN'
      
        'left outer join rem_smodel on rem_smodel.id_rem_smodel=rem_z.idm' +
        'odel_rem_z'
      
        'left outer join ssklad as sklad_pr on sklad_pr.idsklad=rem_z.ids' +
        'klpr_rem_z'
      'left outer join sklient on sklient.idklient=rem_z.idklient_rem_z'
      
        'left outer join sklient as diler on diler.idklient=rem_z.iddiler' +
        '_rem_z'
      
        'left outer join rem_stremont on rem_stremont.id_stremont=rem_z.i' +
        'dtyperem_rem_z'
      
        'left outer join rem_ssost on rem_ssost.id_remssost=rem_z.idsost_' +
        'rem_z'
      
        'left outer join ssklad as sklad_tec on sklad_tec.idsklad=rem_z.i' +
        'dtecskl_rem_z'
      'left outer join suser  on suser.id_user=rem_z.iduser_rem_z'
      
        'left outer join suser as mexanik on mexanik.id_user=rem_z.idmexa' +
        'nik_rem_z'
      'left outer join sbrand on sbrand.id_sbrand=rem_z.idbrand_rem_z'
      
        'left outer join rem_sactcategory on rem_sactcategory.id_rem_sact' +
        'category=rem_z.idactcat_rem_z'
      
        'left outer join rem_shardware on rem_z.idhw_rem_z=rem_shardware.' +
        'id_rem_shardware'
      
        'left outer join rem_skkt on rem_z.idkkt_rem_z=rem_skkt.idklient_' +
        'rem_skkt'
      'where ID_REM_Z=:PARAM_ID'
      '')
    AutoUpdateOptions.UpdateTableName = 'REM_Z'
    AutoUpdateOptions.KeyFields = 'ID_REM_Z'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_Z_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object GurZID_REM_Z: TFIBLargeIntField
      FieldName = 'ID_REM_Z'
    end
    object GurZGID_REM_Z: TFIBWideStringField
      FieldName = 'GID_REM_Z'
      Size = 10
    end
    object GurZPREFIKS_REM_Z: TFIBWideStringField
      FieldName = 'PREFIKS_REM_Z'
      Size = 2
    end
    object GurZNUM_REM_Z: TFIBIntegerField
      FieldName = 'NUM_REM_Z'
    end
    object GurZPOS_REM_Z: TFIBDateTimeField
      FieldName = 'POS_REM_Z'
      DisplayFormat = 'c'
    end
    object GurZIDBASE_REM_Z: TFIBLargeIntField
      FieldName = 'IDBASE_REM_Z'
      OnChange = GurZIDBASE_REM_ZChange
    end
    object GurZIDMODEL_REM_Z: TFIBLargeIntField
      FieldName = 'IDMODEL_REM_Z'
    end
    object GurZIDSKLPR_REM_Z: TFIBLargeIntField
      FieldName = 'IDSKLPR_REM_Z'
      OnChange = GurZIDSKLPR_REM_ZChange
    end
    object GurZIDKLIENT_REM_Z: TFIBLargeIntField
      FieldName = 'IDKLIENT_REM_Z'
    end
    object GurZIDDILER_REM_Z: TFIBLargeIntField
      FieldName = 'IDDILER_REM_Z'
    end
    object GurZNAME_REM_Z: TFIBWideStringField
      FieldName = 'NAME_REM_Z'
      Size = 200
    end
    object GurZDESCR_REM_Z: TFIBWideStringField
      FieldName = 'DESCR_REM_Z'
      Size = 150
    end
    object GurZIDTYPEREM_REM_Z: TFIBLargeIntField
      FieldName = 'IDTYPEREM_REM_Z'
      OnChange = GurZIDTYPEREM_REM_ZChange
    end
    object GurZIDSOST_REM_Z: TFIBLargeIntField
      FieldName = 'IDSOST_REM_Z'
      OnChange = GurZIDSOST_REM_ZChange
    end
    object GurZIDTECSKL_REM_Z: TFIBLargeIntField
      FieldName = 'IDTECSKL_REM_Z'
      OnChange = GurZIDTECSKL_REM_ZChange
    end
    object GurZIDUSER_REM_Z: TFIBLargeIntField
      FieldName = 'IDUSER_REM_Z'
    end
    object GurZOPER_REM_Z: TFIBIntegerField
      FieldName = 'OPER_REM_Z'
    end
    object GurZSUM_REM_Z: TFIBBCDField
      FieldName = 'SUM_REM_Z'
      OnChange = GurZSUM_REM_ZChange
      Size = 2
      RoundByScale = True
    end
    object GurZSROK_REM_Z: TFIBDateField
      FieldName = 'SROK_REM_Z'
      OnChange = GurZSROK_REM_ZChange
    end
    object GurZOUT_REM_Z: TFIBSmallIntField
      FieldName = 'OUT_REM_Z'
      OnChange = GurZOUT_REM_ZChange
    end
    object GurZIDFIRM_REM_Z: TFIBLargeIntField
      FieldName = 'IDFIRM_REM_Z'
      OnChange = GurZIDFIRM_REM_ZChange
    end
    object GurZNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 200
    end
    object GurZNAME_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 200
    end
    object GurZNAME_REM_SMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SMODEL'
      Size = 200
    end
    object GurZNAME_SKLAD_PR: TFIBWideStringField
      FieldName = 'NAME_SKLAD_PR'
      Size = 200
    end
    object GurZNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 200
    end
    object GurZNAMEDILER: TFIBWideStringField
      FieldName = 'NAMEDILER'
      Size = 200
    end
    object GurZNAME_STREMONT: TFIBWideStringField
      FieldName = 'NAME_STREMONT'
      Size = 200
    end
    object GurZNAME_REMSSOST: TFIBWideStringField
      FieldName = 'NAME_REMSSOST'
      Size = 200
    end
    object GurZNAME_SKLAD_TEC: TFIBWideStringField
      FieldName = 'NAME_SKLAD_TEC'
      Size = 200
    end
    object GurZNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
      Size = 200
    end
    object GurZNEISPR_REM_Z: TFIBWideStringField
      FieldName = 'NEISPR_REM_Z'
      Size = 250
    end
    object GurZKLIENT_NAME_REM_Z: TFIBWideStringField
      FieldName = 'KLIENT_NAME_REM_Z'
      Size = 200
    end
    object GurZKLIENT_ADR_REM_Z: TFIBWideStringField
      FieldName = 'KLIENT_ADR_REM_Z'
      Size = 200
    end
    object GurZKLIENT_PHONE_REM_Z: TFIBWideStringField
      FieldName = 'KLIENT_PHONE_REM_Z'
      Size = 40
    end
    object GurZKOMPLECT_REM_Z: TFIBWideStringField
      FieldName = 'KOMPLECT_REM_Z'
      Size = 200
    end
    object GurZMODEL_REM_Z: TFIBWideStringField
      FieldName = 'MODEL_REM_Z'
      Size = 40
    end
    object GurZSOST_REM_Z: TFIBWideStringField
      FieldName = 'SOST_REM_Z'
      Size = 200
    end
    object GurZSERNUM2_REM_Z: TFIBWideStringField
      FieldName = 'SERNUM2_REM_Z'
      Size = 50
    end
    object GurZSERNUM_REM_Z: TFIBWideStringField
      FieldName = 'SERNUM_REM_Z'
      Size = 50
    end
    object GurZCOMENTS_REM_Z: TFIBWideStringField
      FieldName = 'COMENTS_REM_Z'
      Size = 250
    end
    object GurZPOSOUT_REM_Z: TFIBDateTimeField
      FieldName = 'POSOUT_REM_Z'
      DisplayFormat = 'c'
    end
    object GurZPOSREMONT_REM_Z: TFIBDateTimeField
      FieldName = 'POSREMONT_REM_Z'
      DisplayFormat = 'c'
    end
    object GurZWARRANTY_REM_Z: TFIBIntegerField
      FieldName = 'WARRANTY_REM_Z'
    end
    object GurZIDMEXANIK_REM_Z: TFIBLargeIntField
      FieldName = 'IDMEXANIK_REM_Z'
    end
    object GurZIDBRAND_REM_Z: TFIBLargeIntField
      FieldName = 'IDBRAND_REM_Z'
    end
    object GurZIDACTCAT_REM_Z: TFIBLargeIntField
      FieldName = 'IDACTCAT_REM_Z'
    end
    object GurZGUID_REM_Z: TFIBWideStringField
      FieldName = 'GUID_REM_Z'
      Size = 38
    end
    object GurZIDZOSN_REM_Z: TFIBLargeIntField
      FieldName = 'IDZOSN_REM_Z'
    end
    object GurZFL_POVTOR_REM_Z: TFIBSmallIntField
      FieldName = 'FL_POVTOR_REM_Z'
    end
    object GurZDILER_NUMZ_REM_Z: TFIBWideStringField
      FieldName = 'DILER_NUMZ_REM_Z'
      Size = 10
    end
    object GurZDILER_POSZ_REM_Z: TFIBDateTimeField
      FieldName = 'DILER_POSZ_REM_Z'
    end
    object GurZDILER_GUIDZ_REM_Z: TFIBWideStringField
      FieldName = 'DILER_GUIDZ_REM_Z'
      Size = 38
    end
    object GurZSC_NUMZ_REM_Z: TFIBWideStringField
      FieldName = 'SC_NUMZ_REM_Z'
      Size = 10
    end
    object GurZSC_POSZ_REM_Z: TFIBDateTimeField
      FieldName = 'SC_POSZ_REM_Z'
    end
    object GurZSC_GUIDZ_REM_Z: TFIBWideStringField
      FieldName = 'SC_GUIDZ_REM_Z'
      Size = 38
    end
    object GurZFL_ADDREPORT_REM_Z: TFIBSmallIntField
      FieldName = 'FL_ADDREPORT_REM_Z'
    end
    object GurZSERNUM_STR_REM_Z: TFIBWideStringField
      FieldName = 'SERNUM_STR_REM_Z'
      Size = 200
    end
    object GurZNAME_MEXANIK: TFIBWideStringField
      FieldName = 'NAME_MEXANIK'
      Size = 200
    end
    object GurZNAME_SBRAND: TFIBWideStringField
      FieldName = 'NAME_SBRAND'
      Size = 200
    end
    object GurZNAME_REM_SACTCATEGORY: TFIBWideStringField
      FieldName = 'NAME_REM_SACTCATEGORY'
      Size = 200
    end
    object GurZIDHW_REM_Z: TFIBLargeIntField
      FieldName = 'IDHW_REM_Z'
    end
    object GurZIDKKT_REM_Z: TFIBLargeIntField
      FieldName = 'IDKKT_REM_Z'
    end
    object GurZNAME_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'NAME_REM_SHARDWARE'
      Size = 200
    end
    object GurZSERNUM_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'SERNUM_REM_SHARDWARE'
      Size = 50
    end
    object GurZSERNUM2_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'SERNUM2_REM_SHARDWARE'
      Size = 50
    end
    object GurZNAME_REM_SKKT: TFIBWideStringField
      FieldName = 'NAME_REM_SKKT'
      Size = 200
    end
    object GurZSERNUM_REM_SKKT: TFIBWideStringField
      FieldName = 'SERNUM_REM_SKKT'
      Size = 15
    end
    object GurZFL_KLIENT_UVEDOML_REM_Z: TFIBIntegerField
      FieldName = 'FL_KLIENT_UVEDOML_REM_Z'
    end
    object GurZFL_TREB_KONS_KL_REM_Z: TFIBIntegerField
      FieldName = 'FL_TREB_KONS_KL_REM_Z'
    end
    object GurZFL_KL_OTV_NA_ZAPROS_REM_Z: TFIBIntegerField
      FieldName = 'FL_KL_OTV_NA_ZAPROS_REM_Z'
    end
    object GurZPREFIKS_NUM_REM_Z: TFIBWideStringField
      FieldName = 'PREFIKS_NUM_REM_Z'
      Size = 12
    end
    object GurZNUM_GARDOC_REM_Z: TFIBWideStringField
      FieldName = 'NUM_GARDOC_REM_Z'
      Size = 50
    end
    object GurZFL_FICTIV_REM_Z: TFIBIntegerField
      FieldName = 'FL_FICTIV_REM_Z'
    end
    object GurZFL_NE_OTCH_REM_Z: TFIBSmallIntField
      FieldName = 'FL_NE_OTCH_REM_Z'
    end
    object GurZFL_NADO_OTCH_REM_Z: TFIBSmallIntField
      FieldName = 'FL_NADO_OTCH_REM_Z'
    end
    object GurZFL_ISM_GARDOC_REM_Z: TFIBSmallIntField
      FieldName = 'FL_ISM_GARDOC_REM_Z'
    end
    object GurZFL_ISM_SERNUM_REM_Z: TFIBSmallIntField
      FieldName = 'FL_ISM_SERNUM_REM_Z'
    end
    object GurZFL_ISM_SERNUM2_REM_Z: TFIBSmallIntField
      FieldName = 'FL_ISM_SERNUM2_REM_Z'
    end
    object GurZNUM_GARDOC_NEW_REM_Z: TFIBWideStringField
      FieldName = 'NUM_GARDOC_NEW_REM_Z'
      Size = 50
    end
    object GurZSERNUM_NEW_REM_Z: TFIBWideStringField
      FieldName = 'SERNUM_NEW_REM_Z'
      Size = 50
    end
    object GurZSERNUM2_NEW_REM_Z: TFIBWideStringField
      FieldName = 'SERNUM2_NEW_REM_Z'
      Size = 50
    end
    object GurZGOTOVO_K_VIDACHE_REM_Z: TFIBSmallIntField
      FieldName = 'GOTOVO_K_VIDACHE_REM_Z'
    end
  end
  object GurZKompl: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_ZKOMPL'
      'SET '
      '    GID_REM_ZKOMPL = :GID_REM_ZKOMPL,'
      '    PREFIKS_REM_ZKOMPL = :PREFIKS_REM_ZKOMPL,'
      '    IDZ_REM_ZKOMPL = :IDZ_REM_ZKOMPL,'
      '    IDKOMPL_REM_ZKOMPL = :IDKOMPL_REM_ZKOMPL,'
      '    KOL_REM_ZKOMPL = :KOL_REM_ZKOMPL'
      'WHERE'
      '    ID_REM_ZKOMPL = :OLD_ID_REM_ZKOMPL'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_ZKOMPL'
      'WHERE'
      '        ID_REM_ZKOMPL = :OLD_ID_REM_ZKOMPL'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_ZKOMPL('
      '    ID_REM_ZKOMPL,'
      '    GID_REM_ZKOMPL,'
      '    PREFIKS_REM_ZKOMPL,'
      '    IDZ_REM_ZKOMPL,'
      '    IDKOMPL_REM_ZKOMPL,'
      '    KOL_REM_ZKOMPL'
      ')'
      'VALUES('
      '    :ID_REM_ZKOMPL,'
      '    :GID_REM_ZKOMPL,'
      '    :PREFIKS_REM_ZKOMPL,'
      '    :IDZ_REM_ZKOMPL,'
      '    :IDKOMPL_REM_ZKOMPL,'
      '    :KOL_REM_ZKOMPL'
      ')')
    RefreshSQL.Strings = (
      'select REM_ZKOMPL.*, NAME_REM_SKOMPLMODEL '
      'from  REM_ZKOMPL'
      
        'left outer join REM_SKOMPLMODEL on ID_REM_SKOMPLMODEL=IDKOMPL_RE' +
        'M_ZKOMPL'
      'where(  IDZ_REM_ZKOMPL=:PARAM_IDZ'
      '     ) and (     REM_ZKOMPL.ID_REM_ZKOMPL = :OLD_ID_REM_ZKOMPL'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select REM_ZKOMPL.*, NAME_REM_SKOMPLMODEL '
      'from  REM_ZKOMPL'
      
        'left outer join REM_SKOMPLMODEL on ID_REM_SKOMPLMODEL=IDKOMPL_RE' +
        'M_ZKOMPL'
      'where IDZ_REM_ZKOMPL=:PARAM_IDZ')
    AutoUpdateOptions.UpdateTableName = 'REM_ZKOMPL'
    AutoUpdateOptions.KeyFields = 'ID_REM_ZKOMPL'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_ZKOMPL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnCalcFields = GurZKomplCalcFields
    OnNewRecord = GurZKomplNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 136
    poUseLargeIntField = True
    object GurZKomplRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object GurZKomplID_REM_ZKOMPL: TFIBLargeIntField
      FieldName = 'ID_REM_ZKOMPL'
    end
    object GurZKomplGID_REM_ZKOMPL: TFIBWideStringField
      FieldName = 'GID_REM_ZKOMPL'
      Size = 10
    end
    object GurZKomplPREFIKS_REM_ZKOMPL: TFIBWideStringField
      FieldName = 'PREFIKS_REM_ZKOMPL'
      Size = 2
    end
    object GurZKomplIDZ_REM_ZKOMPL: TFIBLargeIntField
      FieldName = 'IDZ_REM_ZKOMPL'
    end
    object GurZKomplIDKOMPL_REM_ZKOMPL: TFIBLargeIntField
      FieldName = 'IDKOMPL_REM_ZKOMPL'
    end
    object GurZKomplKOL_REM_ZKOMPL: TFIBBCDField
      FieldName = 'KOL_REM_ZKOMPL'
      Size = 3
      RoundByScale = True
    end
    object GurZKomplIDBASE_REM_ZKOMPL: TFIBLargeIntField
      FieldName = 'IDBASE_REM_ZKOMPL'
    end
    object GurZKomplNAME_REM_SKOMPLMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SKOMPLMODEL'
      Size = 100
    end
  end
  object GurZNeispr: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_ZNEISPR'
      'SET '
      '    GID_REM_ZNEISPR = :GID_REM_ZNEISPR,'
      '    PREFIKS_REM_ZNEISPR = :PREFIKS_REM_ZNEISPR,'
      '    IDZ_REM_ZNEISPR = :IDZ_REM_ZNEISPR,'
      '    IDNEISPR_REM_ZNEISPR = :IDNEISPR_REM_ZNEISPR,'
      '    IDBASE_REM_ZNEISPR = :IDBASE_REM_ZNEISPR'
      'WHERE'
      '    ID_REM_ZNEISPR = :OLD_ID_REM_ZNEISPR'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_ZNEISPR'
      'WHERE'
      '        ID_REM_ZNEISPR = :OLD_ID_REM_ZNEISPR'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_ZNEISPR('
      '    ID_REM_ZNEISPR,'
      '    GID_REM_ZNEISPR,'
      '    PREFIKS_REM_ZNEISPR,'
      '    IDZ_REM_ZNEISPR,'
      '    IDNEISPR_REM_ZNEISPR,'
      '    IDBASE_REM_ZNEISPR'
      ')'
      'VALUES('
      '    :ID_REM_ZNEISPR,'
      '    :GID_REM_ZNEISPR,'
      '    :PREFIKS_REM_ZNEISPR,'
      '    :IDZ_REM_ZNEISPR,'
      '    :IDNEISPR_REM_ZNEISPR,'
      '    :IDBASE_REM_ZNEISPR'
      ')')
    RefreshSQL.Strings = (
      'select REM_ZNEISPR.*,'
      '    REM_SNEISPR.NAME_REM_SNEISPR,'
      '    REM_SNEISPR.name_eng_rem_sneispr,'
      '    rem_sgrpneispr.name_rem_sgrpneispr,'
      '    rem_sgrpneispr.name_eng_rem_sgrpneispr'
      'from REM_ZNEISPR '
      
        'left outer join REM_SNEISPR  on  REM_SNEISPR.id_rem_sneispr=REM_' +
        'ZNEISPR.idneispr_rem_zneispr'
      
        'left outer join rem_sgrpneispr  on  REM_SNEISPR.idgrp_rem_sneisp' +
        'r=rem_sgrpneispr.id_rem_sgrpneispr'
      'where(  IDZ_REM_ZNEISPR=:PARAM_IDZ'
      
        '     ) and (     REM_ZNEISPR.ID_REM_ZNEISPR = :OLD_ID_REM_ZNEISP' +
        'R'
      '     )'
      '    '
      ''
      '')
    SelectSQL.Strings = (
      'select REM_ZNEISPR.*,'
      '    REM_SNEISPR.NAME_REM_SNEISPR,'
      '    REM_SNEISPR.name_eng_rem_sneispr,'
      '    rem_sgrpneispr.name_rem_sgrpneispr,'
      '    rem_sgrpneispr.name_eng_rem_sgrpneispr'
      'from REM_ZNEISPR '
      
        'left outer join REM_SNEISPR  on  REM_SNEISPR.id_rem_sneispr=REM_' +
        'ZNEISPR.idneispr_rem_zneispr'
      
        'left outer join rem_sgrpneispr  on  REM_SNEISPR.idgrp_rem_sneisp' +
        'r=rem_sgrpneispr.id_rem_sgrpneispr'
      'where IDZ_REM_ZNEISPR=:PARAM_IDZ'
      ''
      '')
    AutoUpdateOptions.UpdateTableName = 'REM_ZNEISPR'
    AutoUpdateOptions.KeyFields = 'ID_REM_ZNEISPR'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_ZNEISPR_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnCalcFields = GurZNeisprCalcFields
    OnNewRecord = GurZNeisprNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 192
    poUseLargeIntField = True
    object GurZNeisprRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object GurZNeisprID_REM_ZNEISPR: TFIBLargeIntField
      FieldName = 'ID_REM_ZNEISPR'
    end
    object GurZNeisprGID_REM_ZNEISPR: TFIBWideStringField
      FieldName = 'GID_REM_ZNEISPR'
      Size = 10
    end
    object GurZNeisprPREFIKS_REM_ZNEISPR: TFIBWideStringField
      FieldName = 'PREFIKS_REM_ZNEISPR'
      Size = 2
    end
    object GurZNeisprIDZ_REM_ZNEISPR: TFIBLargeIntField
      FieldName = 'IDZ_REM_ZNEISPR'
    end
    object GurZNeisprIDNEISPR_REM_ZNEISPR: TFIBLargeIntField
      FieldName = 'IDNEISPR_REM_ZNEISPR'
    end
    object GurZNeisprIDBASE_REM_ZNEISPR: TFIBLargeIntField
      FieldName = 'IDBASE_REM_ZNEISPR'
    end
    object GurZNeisprNAME_REM_SNEISPR: TFIBWideStringField
      FieldName = 'NAME_REM_SNEISPR'
      Size = 200
    end
    object GurZNeisprNAME_ENG_REM_SNEISPR: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SNEISPR'
      Size = 200
    end
    object GurZNeisprNAME_REM_SGRPNEISPR: TFIBWideStringField
      FieldName = 'NAME_REM_SGRPNEISPR'
      Size = 200
    end
    object GurZNeisprNAME_ENG_REM_SGRPNEISPR: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SGRPNEISPR'
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
    Left = 248
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
    Left = 248
    Top = 136
  end
  object NumDoc: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      
        'from REM_ZAYAVKA_GET_NUM (:PARAM_IDBASE,:PARAM_IDFIRM,:PARAM_IDS' +
        'KLAD)'
      ''
      '')
    Transaction = IBTr
    Left = 368
    Top = 16
  end
  object DopUsl: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_ZDOPUSL'
      'SET '
      '    GID_REM_ZDOPUSL = :GID_REM_ZDOPUSL,'
      '    IDBASE_REM_ZDOPUSL = :IDBASE_REM_ZDOPUSL,'
      '    IDZ_REM_ZDOPUSL = :IDZ_REM_ZDOPUSL,'
      '    IDNOM_REM_ZDOPUSL = :IDNOM_REM_ZDOPUSL,'
      '    IDED_REM_ZDOPUSL = :IDED_REM_ZDOPUSL,'
      '    KOL_REM_ZDOPUSL = :KOL_REM_ZDOPUSL,'
      '    KF_REM_ZDOPUSL = :KF_REM_ZDOPUSL,'
      '    PRICE_REM_ZDOPUSL = :PRICE_REM_ZDOPUSL,'
      '    SUM_REM_ZDOPUSL = :SUM_REM_ZDOPUSL,'
      '    TEXTNOM_REM_ZDOPUSL = :TEXTNOM_REM_ZDOPUSL'
      'WHERE'
      '    ID_REM_ZDOPUSL = :OLD_ID_REM_ZDOPUSL'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_ZDOPUSL'
      'WHERE'
      '        ID_REM_ZDOPUSL = :OLD_ID_REM_ZDOPUSL'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_ZDOPUSL('
      '    ID_REM_ZDOPUSL,'
      '    GID_REM_ZDOPUSL,'
      '    IDBASE_REM_ZDOPUSL,'
      '    IDZ_REM_ZDOPUSL,'
      '    IDNOM_REM_ZDOPUSL,'
      '    IDED_REM_ZDOPUSL,'
      '    KOL_REM_ZDOPUSL,'
      '    KF_REM_ZDOPUSL,'
      '    PRICE_REM_ZDOPUSL,'
      '    SUM_REM_ZDOPUSL,'
      '    TEXTNOM_REM_ZDOPUSL'
      ')'
      'VALUES('
      '    :ID_REM_ZDOPUSL,'
      '    :GID_REM_ZDOPUSL,'
      '    :IDBASE_REM_ZDOPUSL,'
      '    :IDZ_REM_ZDOPUSL,'
      '    :IDNOM_REM_ZDOPUSL,'
      '    :IDED_REM_ZDOPUSL,'
      '    :KOL_REM_ZDOPUSL,'
      '    :KF_REM_ZDOPUSL,'
      '    :PRICE_REM_ZDOPUSL,'
      '    :SUM_REM_ZDOPUSL,'
      '    :TEXTNOM_REM_ZDOPUSL'
      ')')
    RefreshSQL.Strings = (
      'select rem_zdopusl.*,'
      '    snom.namenom,'
      '    sed.nameed'
      'from rem_zdopusl'
      'left outer join snom on snom.idnom=rem_zdopusl.idnom_rem_zdopusl'
      'left outer join sed on sed.ided=rem_zdopusl.ided_rem_zdopusl'
      'where(  rem_zdopusl.idz_rem_zdopusl=:PARAM_IDZ'
      
        '     ) and (     REM_ZDOPUSL.ID_REM_ZDOPUSL = :OLD_ID_REM_ZDOPUS' +
        'L'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_zdopusl.*,'
      '    snom.namenom,'
      '    sed.nameed'
      'from rem_zdopusl'
      'left outer join snom on snom.idnom=rem_zdopusl.idnom_rem_zdopusl'
      'left outer join sed on sed.ided=rem_zdopusl.ided_rem_zdopusl'
      'where rem_zdopusl.idz_rem_zdopusl=:PARAM_IDZ')
    AutoUpdateOptions.UpdateTableName = 'REM_ZDOPUSL'
    AutoUpdateOptions.KeyFields = 'ID_REM_ZDOPUSL'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_ZDOPUSL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DopUslNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 264
    poUseLargeIntField = True
    object DopUslID_REM_ZDOPUSL: TFIBLargeIntField
      FieldName = 'ID_REM_ZDOPUSL'
    end
    object DopUslGID_REM_ZDOPUSL: TFIBWideStringField
      FieldName = 'GID_REM_ZDOPUSL'
      Size = 10
    end
    object DopUslIDBASE_REM_ZDOPUSL: TFIBLargeIntField
      FieldName = 'IDBASE_REM_ZDOPUSL'
    end
    object DopUslIDZ_REM_ZDOPUSL: TFIBLargeIntField
      FieldName = 'IDZ_REM_ZDOPUSL'
    end
    object DopUslIDNOM_REM_ZDOPUSL: TFIBLargeIntField
      FieldName = 'IDNOM_REM_ZDOPUSL'
    end
    object DopUslIDED_REM_ZDOPUSL: TFIBLargeIntField
      FieldName = 'IDED_REM_ZDOPUSL'
    end
    object DopUslKOL_REM_ZDOPUSL: TFIBBCDField
      FieldName = 'KOL_REM_ZDOPUSL'
      OnChange = DopUslKOL_REM_ZDOPUSLChange
      Size = 3
      RoundByScale = True
    end
    object DopUslKF_REM_ZDOPUSL: TFIBBCDField
      FieldName = 'KF_REM_ZDOPUSL'
      Size = 3
      RoundByScale = True
    end
    object DopUslPRICE_REM_ZDOPUSL: TFIBBCDField
      FieldName = 'PRICE_REM_ZDOPUSL'
      OnChange = DopUslPRICE_REM_ZDOPUSLChange
      Size = 2
      RoundByScale = True
    end
    object DopUslSUM_REM_ZDOPUSL: TFIBBCDField
      FieldName = 'SUM_REM_ZDOPUSL'
      Size = 2
      RoundByScale = True
    end
    object DopUslTEXTNOM_REM_ZDOPUSL: TFIBWideStringField
      FieldName = 'TEXTNOM_REM_ZDOPUSL'
      Size = 150
    end
    object DopUslNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object DopUslNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 200
    end
  end
  object DataSourceDopUsl: TDataSource
    DataSet = DopUsl
    Left = 64
    Top = 264
  end
  object PerformedWork: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_ZPERFWORK'
      'SET '
      '    GID_REM_ZPERFWORK = :GID_REM_ZPERFWORK,'
      '    IDBASE_REM_ZPERFWORK = :IDBASE_REM_ZPERFWORK,'
      '    IDZ_REM_ZPERFWORK = :IDZ_REM_ZPERFWORK,'
      '    IDNOM_REM_ZPERFWORK = :IDNOM_REM_ZPERFWORK,'
      '    IDED_REM_ZPERFWORK = :IDED_REM_ZPERFWORK,'
      '    KOL_REM_ZPERFWORK = :KOL_REM_ZPERFWORK,'
      '    KF_REM_ZPERFWORK = :KF_REM_ZPERFWORK,'
      '    PRICE_REM_ZPERFWORK = :PRICE_REM_ZPERFWORK,'
      '    SUM_REM_ZPERFWORK = :SUM_REM_ZPERFWORK,'
      '    TEXTNOM_REM_ZPERFWORK = :TEXTNOM_REM_ZPERFWORK,'
      '    POS_REM_ZPERFWORK = :POS_REM_ZPERFWORK,'
      '    RESULT_REM_ZPERFWORK = :RESULT_REM_ZPERFWORK,'
      '    ADDACT_REM_ZPERFWORK = :ADDACT_REM_ZPERFWORK,'
      '    SHOWFORUSER_REM_ZPERFWORK = :SHOWFORUSER_REM_ZPERFWORK,'
      '    IDUSER_REM_ZPERFWORK = :IDUSER_REM_ZPERFWORK'
      'WHERE'
      '    ID_REM_ZPERFWORK = :OLD_ID_REM_ZPERFWORK'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_ZPERFWORK'
      'WHERE'
      '        ID_REM_ZPERFWORK = :OLD_ID_REM_ZPERFWORK'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_ZPERFWORK('
      '    ID_REM_ZPERFWORK,'
      '    GID_REM_ZPERFWORK,'
      '    IDBASE_REM_ZPERFWORK,'
      '    IDZ_REM_ZPERFWORK,'
      '    IDNOM_REM_ZPERFWORK,'
      '    IDED_REM_ZPERFWORK,'
      '    KOL_REM_ZPERFWORK,'
      '    KF_REM_ZPERFWORK,'
      '    PRICE_REM_ZPERFWORK,'
      '    SUM_REM_ZPERFWORK,'
      '    TEXTNOM_REM_ZPERFWORK,'
      '    POS_REM_ZPERFWORK,'
      '    RESULT_REM_ZPERFWORK,'
      '    ADDACT_REM_ZPERFWORK,'
      '    SHOWFORUSER_REM_ZPERFWORK,'
      '    IDUSER_REM_ZPERFWORK'
      ')'
      'VALUES('
      '    :ID_REM_ZPERFWORK,'
      '    :GID_REM_ZPERFWORK,'
      '    :IDBASE_REM_ZPERFWORK,'
      '    :IDZ_REM_ZPERFWORK,'
      '    :IDNOM_REM_ZPERFWORK,'
      '    :IDED_REM_ZPERFWORK,'
      '    :KOL_REM_ZPERFWORK,'
      '    :KF_REM_ZPERFWORK,'
      '    :PRICE_REM_ZPERFWORK,'
      '    :SUM_REM_ZPERFWORK,'
      '    :TEXTNOM_REM_ZPERFWORK,'
      '    :POS_REM_ZPERFWORK,'
      '    :RESULT_REM_ZPERFWORK,'
      '    :ADDACT_REM_ZPERFWORK,'
      '    :SHOWFORUSER_REM_ZPERFWORK,'
      '    :IDUSER_REM_ZPERFWORK'
      ')')
    RefreshSQL.Strings = (
      'select rem_zperfwork.*,'
      '    snom.namenom,'
      '    sed.nameed,'
      '    suser.name_user'
      'from rem_zperfwork'
      
        'left outer join snom on snom.idnom=rem_zperfwork.idnom_rem_zperf' +
        'work'
      'left outer join sed on sed.ided=rem_zperfwork.ided_rem_zperfwork'
      
        'left outer join suser on suser.id_user=rem_zperfwork.iduser_rem_' +
        'zperfwork'
      'where(  rem_zperfwork.idz_rem_zperfwork=:PARAM_IDZ'
      
        '     ) and (     REM_ZPERFWORK.ID_REM_ZPERFWORK = :OLD_ID_REM_ZP' +
        'ERFWORK'
      '     )'
      'order by rem_zperfwork.pos_rem_zperfwork'
      '    ')
    SelectSQL.Strings = (
      'select rem_zperfwork.*,'
      '    snom.namenom,'
      '    sed.nameed,'
      '    suser.name_user'
      'from rem_zperfwork'
      
        'left outer join snom on snom.idnom=rem_zperfwork.idnom_rem_zperf' +
        'work'
      'left outer join sed on sed.ided=rem_zperfwork.ided_rem_zperfwork'
      
        'left outer join suser on suser.id_user=rem_zperfwork.iduser_rem_' +
        'zperfwork'
      'where rem_zperfwork.idz_rem_zperfwork=:PARAM_IDZ'
      'order by rem_zperfwork.pos_rem_zperfwork')
    AutoUpdateOptions.UpdateTableName = 'REM_ZPERFWORK'
    AutoUpdateOptions.KeyFields = 'ID_REM_ZPERFWORK'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_ZPERFWORK_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = PerformedWorkNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 344
    poUseLargeIntField = True
    object PerformedWorkID_REM_ZPERFWORK: TFIBLargeIntField
      FieldName = 'ID_REM_ZPERFWORK'
    end
    object PerformedWorkGID_REM_ZPERFWORK: TFIBWideStringField
      FieldName = 'GID_REM_ZPERFWORK'
      Size = 10
    end
    object PerformedWorkIDBASE_REM_ZPERFWORK: TFIBLargeIntField
      FieldName = 'IDBASE_REM_ZPERFWORK'
    end
    object PerformedWorkIDZ_REM_ZPERFWORK: TFIBLargeIntField
      FieldName = 'IDZ_REM_ZPERFWORK'
    end
    object PerformedWorkIDNOM_REM_ZPERFWORK: TFIBLargeIntField
      FieldName = 'IDNOM_REM_ZPERFWORK'
    end
    object PerformedWorkIDED_REM_ZPERFWORK: TFIBLargeIntField
      FieldName = 'IDED_REM_ZPERFWORK'
    end
    object PerformedWorkKOL_REM_ZPERFWORK: TFIBBCDField
      FieldName = 'KOL_REM_ZPERFWORK'
      OnChange = PerformedWorkKOL_REM_ZPERFWORKChange
      Size = 3
      RoundByScale = True
    end
    object PerformedWorkKF_REM_ZPERFWORK: TFIBBCDField
      FieldName = 'KF_REM_ZPERFWORK'
      Size = 3
      RoundByScale = True
    end
    object PerformedWorkPRICE_REM_ZPERFWORK: TFIBBCDField
      FieldName = 'PRICE_REM_ZPERFWORK'
      OnChange = PerformedWorkPRICE_REM_ZPERFWORKChange
      Size = 2
      RoundByScale = True
    end
    object PerformedWorkSUM_REM_ZPERFWORK: TFIBBCDField
      FieldName = 'SUM_REM_ZPERFWORK'
      Size = 2
      RoundByScale = True
    end
    object PerformedWorkTEXTNOM_REM_ZPERFWORK: TFIBWideStringField
      FieldName = 'TEXTNOM_REM_ZPERFWORK'
      Size = 150
    end
    object PerformedWorkPOS_REM_ZPERFWORK: TFIBDateTimeField
      FieldName = 'POS_REM_ZPERFWORK'
      DisplayFormat = 'c'
    end
    object PerformedWorkRESULT_REM_ZPERFWORK: TFIBSmallIntField
      FieldName = 'RESULT_REM_ZPERFWORK'
    end
    object PerformedWorkADDACT_REM_ZPERFWORK: TFIBSmallIntField
      FieldName = 'ADDACT_REM_ZPERFWORK'
    end
    object PerformedWorkSHOWFORUSER_REM_ZPERFWORK: TFIBSmallIntField
      FieldName = 'SHOWFORUSER_REM_ZPERFWORK'
    end
    object PerformedWorkNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object PerformedWorkNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 200
    end
    object PerformedWorkIDUSER_REM_ZPERFWORK: TFIBLargeIntField
      FieldName = 'IDUSER_REM_ZPERFWORK'
    end
    object PerformedWorkNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
      Size = 200
    end
  end
  object DataSourcePerformedWork: TDataSource
    DataSet = PerformedWork
    Left = 56
    Top = 344
  end
  object DataSourceGurZ_1: TDataSource
    DataSet = GurZ_1
    Left = 64
    Top = 80
  end
  object GurZ_1: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_Z_1'
      'SET '
      '    IDBASE_REM_Z_1 = :IDBASE_REM_Z_1,'
      '    IDZ_REM_Z_1 = :IDZ_REM_Z_1,'
      '    IDPRMODEL_REM_Z_1 = :IDPRMODEL_REM_Z_1,'
      '    IDPRODUCER_REM_Z_1 = :IDPRODUCER_REM_Z_1,'
      '    FL_VKL_REM_Z_1 = :FL_VKL_REM_Z_1,'
      '    FL_ZIP_REM_Z_1 = :FL_ZIP_REM_Z_1,'
      '    FL_DEFECT_DEMO_REM_Z_1 = :FL_DEFECT_DEMO_REM_Z_1,'
      
        '    FL_KL_PREDUPR_NO_GARANT_REM_Z_1 = :FL_KL_PREDUPR_NO_GARANT_R' +
        'EM_Z_1,'
      '    IDSELLER_REM_Z_1 = :IDSELLER_REM_Z_1,'
      '    KLIENT_EMAIL_REM_Z_1 = :KLIENT_EMAIL_REM_Z_1,'
      '    KLIENT_DOP_INFO_REM_Z_1 = :KLIENT_DOP_INFO_REM_Z_1,'
      '    IDADRKV_REM_Z_1 = :IDADRKV_REM_Z_1,'
      '    FL_PLOMBA_SET_REM_Z_1 = :FL_PLOMBA_SET_REM_Z_1,'
      '    TEXT_PLOMBA_REM_Z_1 = :TEXT_PLOMBA_REM_Z_1,'
      '    FL_PROBLEM_DEVICE_REM_Z_1 = :FL_PROBLEM_DEVICE_REM_Z_1,'
      '    FL_PROBLEM_KLIENT_REM_Z_1 = :FL_PROBLEM_KLIENT_REM_Z_1,'
      '    NEISPR_ENG_REM_Z_1 = :NEISPR_ENG_REM_Z_1,'
      '    DEFECT_ENG_REM_Z_1 = :DEFECT_ENG_REM_Z_1,'
      '    SOLUTION_ENG_REM_Z_1 = :SOLUTION_ENG_REM_Z_1,'
      '    STR_CODE_VIGR_REM_Z_1 = :STR_CODE_VIGR_REM_Z_1,'
      '    FL_ONLY_DAGNOSTIC_REM_Z_1 = :FL_ONLY_DAGNOSTIC_REM_Z_1,'
      '    FAMILIYA_REM_Z_1 = :FAMILIYA_REM_Z_1,'
      '    IMYA_REM_Z_1 = :IMYA_REM_Z_1,'
      '    OTCHESTVO_REM_Z_1 = :OTCHESTVO_REM_Z_1,'
      '    DATE_VIPUSK_REM_Z_1 = :DATE_VIPUSK_REM_Z_1,'
      '    DATE_PRODAGI_REM_Z_1 = :DATE_PRODAGI_REM_Z_1,'
      '    PODO_REM_Z_1 = :PODO_REM_Z_1,'
      '    POPOSLE_REM_Z_1 = :POPOSLE_REM_Z_1,'
      '    IDPRNEISPR_REM_Z_1 = :IDPRNEISPR_REM_Z_1,'
      '    PARTNUM_REM_Z_1 = :PARTNUM_REM_Z_1,'
      '    REFERENCE_REM_Z_1 = :REFERENCE_REM_Z_1,'
      '    SWCODE_REM_Z_1 = :SWCODE_REM_Z_1,'
      '    HWCODE_REM_Z_1 = :HWCODE_REM_Z_1,'
      '    KEMSDANO_REM_Z_1 = :KEMSDANO_REM_Z_1,'
      '    POS_ZAPROSA_NA_AKT_REM_Z_1 = :POS_ZAPROSA_NA_AKT_REM_Z_1,'
      '    SERNUM3_REM_Z_1 = :SERNUM3_REM_Z_1,'
      '    SERNUM4_REM_Z_1 = :SERNUM4_REM_Z_1,'
      '    NUMBAT_REM_Z_1 = :NUMBAT_REM_Z_1,'
      '    FL_ISM_SERNUM3_REM_Z_1 = :FL_ISM_SERNUM3_REM_Z_1,'
      '    SERNUM3_NEW_REM_Z_1 = :SERNUM3_NEW_REM_Z_1,'
      '    FL_ISM_SERNUM4_REM_Z_1 = :FL_ISM_SERNUM4_REM_Z_1,'
      '    SERNUM4_NEW_REM_Z_1 = :SERNUM4_NEW_REM_Z_1,'
      '    FL_ISM_REFERENCE_REM_Z_1 = :FL_ISM_REFERENCE_REM_Z_1,'
      '    REFERENCE_NEW_REM_Z_1 = :REFERENCE_NEW_REM_Z_1,'
      '    FL_ISM_HWCODE_REM_Z_1 = :FL_ISM_HWCODE_REM_Z_1,'
      '    HWCODE_NEW_REM_Z_1 = :HWCODE_NEW_REM_Z_1,'
      '    FL_ISM_SWCODE_REM_Z_1 = :FL_ISM_SWCODE_REM_Z_1,'
      '    SWCODE_NEW_REM_Z_1 = :SWCODE_NEW_REM_Z_1,'
      '    FL_ISM_PARTNUM_REM_Z_1 = :FL_ISM_PARTNUM_REM_Z_1,'
      '    PARTNUM_NEW_REM_Z_1 = :PARTNUM_NEW_REM_Z_1,'
      '    PREDOPLATA_REM_Z_1 = :PREDOPLATA_REM_Z_1'
      'WHERE'
      '    ID_REM_Z_1 = :OLD_ID_REM_Z_1'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_Z_1'
      'WHERE'
      '        ID_REM_Z_1 = :OLD_ID_REM_Z_1'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_Z_1('
      '    ID_REM_Z_1,'
      '    IDBASE_REM_Z_1,'
      '    IDZ_REM_Z_1,'
      '    IDPRMODEL_REM_Z_1,'
      '    IDPRODUCER_REM_Z_1,'
      '    FL_VKL_REM_Z_1,'
      '    FL_ZIP_REM_Z_1,'
      '    FL_DEFECT_DEMO_REM_Z_1,'
      '    FL_KL_PREDUPR_NO_GARANT_REM_Z_1,'
      '    IDSELLER_REM_Z_1,'
      '    KLIENT_EMAIL_REM_Z_1,'
      '    KLIENT_DOP_INFO_REM_Z_1,'
      '    IDADRKV_REM_Z_1,'
      '    FL_PLOMBA_SET_REM_Z_1,'
      '    TEXT_PLOMBA_REM_Z_1,'
      '    FL_PROBLEM_DEVICE_REM_Z_1,'
      '    FL_PROBLEM_KLIENT_REM_Z_1,'
      '    NEISPR_ENG_REM_Z_1,'
      '    DEFECT_ENG_REM_Z_1,'
      '    SOLUTION_ENG_REM_Z_1,'
      '    STR_CODE_VIGR_REM_Z_1,'
      '    FL_ONLY_DAGNOSTIC_REM_Z_1,'
      '    FAMILIYA_REM_Z_1,'
      '    IMYA_REM_Z_1,'
      '    OTCHESTVO_REM_Z_1,'
      '    DATE_VIPUSK_REM_Z_1,'
      '    DATE_PRODAGI_REM_Z_1,'
      '    PODO_REM_Z_1,'
      '    POPOSLE_REM_Z_1,'
      '    IDPRNEISPR_REM_Z_1,'
      '    PARTNUM_REM_Z_1,'
      '    REFERENCE_REM_Z_1,'
      '    SWCODE_REM_Z_1,'
      '    HWCODE_REM_Z_1,'
      '    KEMSDANO_REM_Z_1,'
      '    POS_ZAPROSA_NA_AKT_REM_Z_1,'
      '    SERNUM3_REM_Z_1,'
      '    SERNUM4_REM_Z_1,'
      '    NUMBAT_REM_Z_1,'
      '    FL_ISM_SERNUM3_REM_Z_1,'
      '    SERNUM3_NEW_REM_Z_1,'
      '    FL_ISM_SERNUM4_REM_Z_1,'
      '    SERNUM4_NEW_REM_Z_1,'
      '    FL_ISM_REFERENCE_REM_Z_1,'
      '    REFERENCE_NEW_REM_Z_1,'
      '    FL_ISM_HWCODE_REM_Z_1,'
      '    HWCODE_NEW_REM_Z_1,'
      '    FL_ISM_SWCODE_REM_Z_1,'
      '    SWCODE_NEW_REM_Z_1,'
      '    FL_ISM_PARTNUM_REM_Z_1,'
      '    PARTNUM_NEW_REM_Z_1,'
      '    PREDOPLATA_REM_Z_1'
      ')'
      'VALUES('
      '    :ID_REM_Z_1,'
      '    :IDBASE_REM_Z_1,'
      '    :IDZ_REM_Z_1,'
      '    :IDPRMODEL_REM_Z_1,'
      '    :IDPRODUCER_REM_Z_1,'
      '    :FL_VKL_REM_Z_1,'
      '    :FL_ZIP_REM_Z_1,'
      '    :FL_DEFECT_DEMO_REM_Z_1,'
      '    :FL_KL_PREDUPR_NO_GARANT_REM_Z_1,'
      '    :IDSELLER_REM_Z_1,'
      '    :KLIENT_EMAIL_REM_Z_1,'
      '    :KLIENT_DOP_INFO_REM_Z_1,'
      '    :IDADRKV_REM_Z_1,'
      '    :FL_PLOMBA_SET_REM_Z_1,'
      '    :TEXT_PLOMBA_REM_Z_1,'
      '    :FL_PROBLEM_DEVICE_REM_Z_1,'
      '    :FL_PROBLEM_KLIENT_REM_Z_1,'
      '    :NEISPR_ENG_REM_Z_1,'
      '    :DEFECT_ENG_REM_Z_1,'
      '    :SOLUTION_ENG_REM_Z_1,'
      '    :STR_CODE_VIGR_REM_Z_1,'
      '    :FL_ONLY_DAGNOSTIC_REM_Z_1,'
      '    :FAMILIYA_REM_Z_1,'
      '    :IMYA_REM_Z_1,'
      '    :OTCHESTVO_REM_Z_1,'
      '    :DATE_VIPUSK_REM_Z_1,'
      '    :DATE_PRODAGI_REM_Z_1,'
      '    :PODO_REM_Z_1,'
      '    :POPOSLE_REM_Z_1,'
      '    :IDPRNEISPR_REM_Z_1,'
      '    :PARTNUM_REM_Z_1,'
      '    :REFERENCE_REM_Z_1,'
      '    :SWCODE_REM_Z_1,'
      '    :HWCODE_REM_Z_1,'
      '    :KEMSDANO_REM_Z_1,'
      '    :POS_ZAPROSA_NA_AKT_REM_Z_1,'
      '    :SERNUM3_REM_Z_1,'
      '    :SERNUM4_REM_Z_1,'
      '    :NUMBAT_REM_Z_1,'
      '    :FL_ISM_SERNUM3_REM_Z_1,'
      '    :SERNUM3_NEW_REM_Z_1,'
      '    :FL_ISM_SERNUM4_REM_Z_1,'
      '    :SERNUM4_NEW_REM_Z_1,'
      '    :FL_ISM_REFERENCE_REM_Z_1,'
      '    :REFERENCE_NEW_REM_Z_1,'
      '    :FL_ISM_HWCODE_REM_Z_1,'
      '    :HWCODE_NEW_REM_Z_1,'
      '    :FL_ISM_SWCODE_REM_Z_1,'
      '    :SWCODE_NEW_REM_Z_1,'
      '    :FL_ISM_PARTNUM_REM_Z_1,'
      '    :PARTNUM_NEW_REM_Z_1,'
      '    :PREDOPLATA_REM_Z_1'
      ')')
    RefreshSQL.Strings = (
      'select rem_z_1.*, '
      '       sproducer.name_sproducer,'
      '       rem_sprmodel.name_rem_sprmodel,'
      '       sseller.name_sseller,'
      '       sadr_kv.name_sadr_kv,'
      '       sadr_stroen.name_sadr_stroen,'
      '       sadr_dom.name_sadr_dom,'
      '       sadr_street.name_sadr_street,'
      '       sadr_street.postcode_sadr_street,'
      '       sadr_naspunkt.name_sadr_naspunkt,'
      '       sadr_rayon.name_sadr_rayon,'
      '       sadr_region.name_sadr_region,'
      '       sadr_region.code_sadr_region,'
      '       rem_sprneispr.name_rem_sprneispr,'
      '       rem_sprneispr.name_eng_rem_sprneispr,'
      '       rem_sprneispr.code_rem_sprneispr,'
      '       rem_sprneispr_grp.name_rem_sprneispr_grp,'
      '       rem_sprneispr_grp.name_eng_rem_sprneispr_grp'
      'from rem_z_1'
      
        'left outer join sproducer on rem_z_1.idproducer_rem_z_1=sproduce' +
        'r.id_sproducer'
      
        'left outer join rem_sprmodel  on rem_z_1.idprmodel_rem_z_1=rem_s' +
        'prmodel.id_rem_sprmodel'
      
        'left outer join sseller on rem_z_1.idseller_rem_z_1=sseller.id_s' +
        'seller'
      
        'left outer join sadr_kv on rem_z_1.idadrkv_rem_z_1=sadr_kv.id_sa' +
        'dr_kv'
      
        'left outer join sadr_stroen on sadr_stroen.id_sadr_stroen=sadr_k' +
        'v.idstroen_sadr_kv'
      
        'left outer join sadr_dom on sadr_dom.id_sadr_dom=sadr_stroen.idd' +
        'om_sadr_stroen'
      
        'left outer join sadr_street on sadr_street.id_sadr_street=sadr_d' +
        'om.idstreet_sadr_dom'
      
        'left outer join sadr_naspunkt on sadr_naspunkt.id_sadr_naspunkt=' +
        'sadr_street.idnaspunkt_sadr_street'
      
        'left outer join sadr_rayon on sadr_rayon.id_sadr_rayon=sadr_nasp' +
        'unkt.idrayon_sadr_naspunkt'
      
        'left outer join sadr_region on sadr_region.id_sadr_region=sadr_r' +
        'ayon.idregion_sadr_rayon'
      
        'left outer join rem_sprneispr on  rem_sprneispr.id_rem_sprneispr' +
        '=rem_z_1.idprneispr_rem_z_1'
      
        'left outer join rem_sprneispr_grp on rem_sprneispr_grp.id_rem_sp' +
        'rneispr_grp=rem_sprneispr.idgrp_rem_sprneispr'
      'where(  rem_z_1.idz_rem_z_1=:PARAM_IDZ'
      '     ) and (     REM_Z_1.ID_REM_Z_1 = :OLD_ID_REM_Z_1'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_z_1.*, '
      '       sproducer.name_sproducer,'
      '       rem_sprmodel.name_rem_sprmodel,'
      '       sseller.name_sseller,'
      '       sadr_kv.name_sadr_kv,'
      '       sadr_stroen.name_sadr_stroen,'
      '       sadr_dom.name_sadr_dom,'
      '       sadr_street.name_sadr_street,'
      '       sadr_street.postcode_sadr_street,'
      '       sadr_naspunkt.name_sadr_naspunkt,'
      '       sadr_rayon.name_sadr_rayon,'
      '       sadr_region.name_sadr_region,'
      '       sadr_region.code_sadr_region,'
      '       rem_sprneispr.name_rem_sprneispr,'
      '       rem_sprneispr.name_eng_rem_sprneispr,'
      '       rem_sprneispr.code_rem_sprneispr,'
      '       rem_sprneispr_grp.name_rem_sprneispr_grp,'
      '       rem_sprneispr_grp.name_eng_rem_sprneispr_grp'
      'from rem_z_1'
      
        'left outer join sproducer on rem_z_1.idproducer_rem_z_1=sproduce' +
        'r.id_sproducer'
      
        'left outer join rem_sprmodel  on rem_z_1.idprmodel_rem_z_1=rem_s' +
        'prmodel.id_rem_sprmodel'
      
        'left outer join sseller on rem_z_1.idseller_rem_z_1=sseller.id_s' +
        'seller'
      
        'left outer join sadr_kv on rem_z_1.idadrkv_rem_z_1=sadr_kv.id_sa' +
        'dr_kv'
      
        'left outer join sadr_stroen on sadr_stroen.id_sadr_stroen=sadr_k' +
        'v.idstroen_sadr_kv'
      
        'left outer join sadr_dom on sadr_dom.id_sadr_dom=sadr_stroen.idd' +
        'om_sadr_stroen'
      
        'left outer join sadr_street on sadr_street.id_sadr_street=sadr_d' +
        'om.idstreet_sadr_dom'
      
        'left outer join sadr_naspunkt on sadr_naspunkt.id_sadr_naspunkt=' +
        'sadr_street.idnaspunkt_sadr_street'
      
        'left outer join sadr_rayon on sadr_rayon.id_sadr_rayon=sadr_nasp' +
        'unkt.idrayon_sadr_naspunkt'
      
        'left outer join sadr_region on sadr_region.id_sadr_region=sadr_r' +
        'ayon.idregion_sadr_rayon'
      
        'left outer join rem_sprneispr on  rem_sprneispr.id_rem_sprneispr' +
        '=rem_z_1.idprneispr_rem_z_1'
      
        'left outer join rem_sprneispr_grp on rem_sprneispr_grp.id_rem_sp' +
        'rneispr_grp=rem_sprneispr.idgrp_rem_sprneispr'
      'where rem_z_1.idz_rem_z_1=:PARAM_IDZ')
    AutoUpdateOptions.UpdateTableName = 'REM_Z_1'
    AutoUpdateOptions.KeyFields = 'ID_REM_Z_1'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_Z_1_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = GurZ_1NewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 80
    poUseLargeIntField = True
    object GurZ_1ID_REM_Z_1: TFIBLargeIntField
      FieldName = 'ID_REM_Z_1'
    end
    object GurZ_1IDBASE_REM_Z_1: TFIBLargeIntField
      FieldName = 'IDBASE_REM_Z_1'
    end
    object GurZ_1IDZ_REM_Z_1: TFIBLargeIntField
      FieldName = 'IDZ_REM_Z_1'
    end
    object GurZ_1IDPRMODEL_REM_Z_1: TFIBLargeIntField
      FieldName = 'IDPRMODEL_REM_Z_1'
    end
    object GurZ_1IDPRODUCER_REM_Z_1: TFIBLargeIntField
      FieldName = 'IDPRODUCER_REM_Z_1'
    end
    object GurZ_1FL_VKL_REM_Z_1: TFIBIntegerField
      FieldName = 'FL_VKL_REM_Z_1'
    end
    object GurZ_1FL_ZIP_REM_Z_1: TFIBIntegerField
      FieldName = 'FL_ZIP_REM_Z_1'
    end
    object GurZ_1FL_DEFECT_DEMO_REM_Z_1: TFIBIntegerField
      FieldName = 'FL_DEFECT_DEMO_REM_Z_1'
    end
    object GurZ_1FL_KL_PREDUPR_NO_GARANT_REM_Z_1: TFIBIntegerField
      FieldName = 'FL_KL_PREDUPR_NO_GARANT_REM_Z_1'
    end
    object GurZ_1IDSELLER_REM_Z_1: TFIBLargeIntField
      FieldName = 'IDSELLER_REM_Z_1'
    end
    object GurZ_1KLIENT_EMAIL_REM_Z_1: TFIBWideStringField
      FieldName = 'KLIENT_EMAIL_REM_Z_1'
      Size = 40
    end
    object GurZ_1KLIENT_DOP_INFO_REM_Z_1: TFIBWideStringField
      FieldName = 'KLIENT_DOP_INFO_REM_Z_1'
      Size = 250
    end
    object GurZ_1IDADRKV_REM_Z_1: TFIBLargeIntField
      FieldName = 'IDADRKV_REM_Z_1'
    end
    object GurZ_1NAME_SPRODUCER: TFIBWideStringField
      FieldName = 'NAME_SPRODUCER'
      Size = 200
    end
    object GurZ_1NAME_REM_SPRMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SPRMODEL'
      Size = 200
    end
    object GurZ_1NAME_SSELLER: TFIBWideStringField
      FieldName = 'NAME_SSELLER'
      Size = 200
    end
    object GurZ_1NAME_SADR_DOM: TFIBWideStringField
      FieldName = 'NAME_SADR_DOM'
    end
    object GurZ_1NAME_SADR_STREET: TFIBWideStringField
      FieldName = 'NAME_SADR_STREET'
      Size = 200
    end
    object GurZ_1POSTCODE_SADR_STREET: TFIBWideStringField
      FieldName = 'POSTCODE_SADR_STREET'
      Size = 7
    end
    object GurZ_1NAME_SADR_NASPUNKT: TFIBWideStringField
      FieldName = 'NAME_SADR_NASPUNKT'
      Size = 200
    end
    object GurZ_1NAME_SADR_REGION: TFIBWideStringField
      FieldName = 'NAME_SADR_REGION'
      Size = 200
    end
    object GurZ_1CODE_SADR_REGION: TFIBWideStringField
      FieldName = 'CODE_SADR_REGION'
      Size = 5
    end
    object GurZ_1NAME_SADR_KV: TFIBWideStringField
      FieldName = 'NAME_SADR_KV'
    end
    object GurZ_1FL_PLOMBA_SET_REM_Z_1: TFIBIntegerField
      FieldName = 'FL_PLOMBA_SET_REM_Z_1'
    end
    object GurZ_1TEXT_PLOMBA_REM_Z_1: TFIBWideStringField
      FieldName = 'TEXT_PLOMBA_REM_Z_1'
      Size = 10
    end
    object GurZ_1FL_PROBLEM_DEVICE_REM_Z_1: TFIBIntegerField
      FieldName = 'FL_PROBLEM_DEVICE_REM_Z_1'
    end
    object GurZ_1FL_PROBLEM_KLIENT_REM_Z_1: TFIBIntegerField
      FieldName = 'FL_PROBLEM_KLIENT_REM_Z_1'
    end
    object GurZ_1NEISPR_ENG_REM_Z_1: TFIBWideStringField
      FieldName = 'NEISPR_ENG_REM_Z_1'
      Size = 250
    end
    object GurZ_1DEFECT_ENG_REM_Z_1: TFIBWideStringField
      FieldName = 'DEFECT_ENG_REM_Z_1'
      Size = 250
    end
    object GurZ_1SOLUTION_ENG_REM_Z_1: TFIBWideStringField
      FieldName = 'SOLUTION_ENG_REM_Z_1'
      Size = 250
    end
    object GurZ_1STR_CODE_VIGR_REM_Z_1: TFIBWideStringField
      FieldName = 'STR_CODE_VIGR_REM_Z_1'
      Size = 40
    end
    object GurZ_1NAME_SADR_STROEN: TFIBWideStringField
      FieldName = 'NAME_SADR_STROEN'
      Size = 40
    end
    object GurZ_1NAME_SADR_RAYON: TFIBWideStringField
      FieldName = 'NAME_SADR_RAYON'
      Size = 200
    end
    object GurZ_1FL_ONLY_DAGNOSTIC_REM_Z_1: TFIBIntegerField
      FieldName = 'FL_ONLY_DAGNOSTIC_REM_Z_1'
    end
    object GurZ_1FAMILIYA_REM_Z_1: TFIBWideStringField
      FieldName = 'FAMILIYA_REM_Z_1'
      Size = 30
    end
    object GurZ_1IMYA_REM_Z_1: TFIBWideStringField
      FieldName = 'IMYA_REM_Z_1'
      Size = 30
    end
    object GurZ_1OTCHESTVO_REM_Z_1: TFIBWideStringField
      FieldName = 'OTCHESTVO_REM_Z_1'
      Size = 30
    end
    object GurZ_1DATE_VIPUSK_REM_Z_1: TFIBDateField
      FieldName = 'DATE_VIPUSK_REM_Z_1'
    end
    object GurZ_1DATE_PRODAGI_REM_Z_1: TFIBDateField
      FieldName = 'DATE_PRODAGI_REM_Z_1'
    end
    object GurZ_1PODO_REM_Z_1: TFIBWideStringField
      FieldName = 'PODO_REM_Z_1'
      Size = 40
    end
    object GurZ_1POPOSLE_REM_Z_1: TFIBWideStringField
      FieldName = 'POPOSLE_REM_Z_1'
      Size = 40
    end
    object GurZ_1IDPRNEISPR_REM_Z_1: TFIBLargeIntField
      FieldName = 'IDPRNEISPR_REM_Z_1'
    end
    object GurZ_1PARTNUM_REM_Z_1: TFIBWideStringField
      FieldName = 'PARTNUM_REM_Z_1'
      Size = 40
    end
    object GurZ_1REFERENCE_REM_Z_1: TFIBWideStringField
      FieldName = 'REFERENCE_REM_Z_1'
      Size = 40
    end
    object GurZ_1SWCODE_REM_Z_1: TFIBWideStringField
      FieldName = 'SWCODE_REM_Z_1'
      Size = 10
    end
    object GurZ_1HWCODE_REM_Z_1: TFIBWideStringField
      FieldName = 'HWCODE_REM_Z_1'
      Size = 10
    end
    object GurZ_1KEMSDANO_REM_Z_1: TFIBIntegerField
      FieldName = 'KEMSDANO_REM_Z_1'
    end
    object GurZ_1POS_ZAPROSA_NA_AKT_REM_Z_1: TFIBDateTimeField
      FieldName = 'POS_ZAPROSA_NA_AKT_REM_Z_1'
    end
    object GurZ_1SERNUM3_REM_Z_1: TFIBWideStringField
      FieldName = 'SERNUM3_REM_Z_1'
      Size = 50
    end
    object GurZ_1SERNUM4_REM_Z_1: TFIBWideStringField
      FieldName = 'SERNUM4_REM_Z_1'
      Size = 50
    end
    object GurZ_1NUMBAT_REM_Z_1: TFIBWideStringField
      FieldName = 'NUMBAT_REM_Z_1'
      Size = 50
    end
    object GurZ_1NAME_REM_SPRNEISPR: TFIBWideStringField
      FieldName = 'NAME_REM_SPRNEISPR'
      Size = 200
    end
    object GurZ_1NAME_ENG_REM_SPRNEISPR: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SPRNEISPR'
      Size = 200
    end
    object GurZ_1CODE_REM_SPRNEISPR: TFIBWideStringField
      FieldName = 'CODE_REM_SPRNEISPR'
    end
    object GurZ_1NAME_REM_SPRNEISPR_GRP: TFIBWideStringField
      FieldName = 'NAME_REM_SPRNEISPR_GRP'
      Size = 200
    end
    object GurZ_1NAME_ENG_REM_SPRNEISPR_GRP: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SPRNEISPR_GRP'
      Size = 200
    end
    object GurZ_1FL_ISM_SERNUM3_REM_Z_1: TFIBSmallIntField
      FieldName = 'FL_ISM_SERNUM3_REM_Z_1'
    end
    object GurZ_1SERNUM3_NEW_REM_Z_1: TFIBWideStringField
      FieldName = 'SERNUM3_NEW_REM_Z_1'
      Size = 50
    end
    object GurZ_1FL_ISM_SERNUM4_REM_Z_1: TFIBSmallIntField
      FieldName = 'FL_ISM_SERNUM4_REM_Z_1'
    end
    object GurZ_1SERNUM4_NEW_REM_Z_1: TFIBWideStringField
      FieldName = 'SERNUM4_NEW_REM_Z_1'
      Size = 50
    end
    object GurZ_1FL_ISM_REFERENCE_REM_Z_1: TFIBWideStringField
      FieldName = 'FL_ISM_REFERENCE_REM_Z_1'
      Size = 40
    end
    object GurZ_1REFERENCE_NEW_REM_Z_1: TFIBWideStringField
      FieldName = 'REFERENCE_NEW_REM_Z_1'
      Size = 40
    end
    object GurZ_1FL_ISM_HWCODE_REM_Z_1: TFIBSmallIntField
      FieldName = 'FL_ISM_HWCODE_REM_Z_1'
    end
    object GurZ_1HWCODE_NEW_REM_Z_1: TFIBWideStringField
      FieldName = 'HWCODE_NEW_REM_Z_1'
      Size = 10
    end
    object GurZ_1FL_ISM_SWCODE_REM_Z_1: TFIBSmallIntField
      FieldName = 'FL_ISM_SWCODE_REM_Z_1'
    end
    object GurZ_1SWCODE_NEW_REM_Z_1: TFIBWideStringField
      FieldName = 'SWCODE_NEW_REM_Z_1'
      Size = 10
    end
    object GurZ_1FL_ISM_PARTNUM_REM_Z_1: TFIBSmallIntField
      FieldName = 'FL_ISM_PARTNUM_REM_Z_1'
    end
    object GurZ_1PARTNUM_NEW_REM_Z_1: TFIBWideStringField
      FieldName = 'PARTNUM_NEW_REM_Z_1'
      Size = 40
    end
    object GurZ_1PREDOPLATA_REM_Z_1: TFIBBCDField
      FieldName = 'PREDOPLATA_REM_Z_1'
      Size = 2
      RoundByScale = True
    end
  end
  object DataSourcePrNeispr: TDataSource
    DataSet = GurZPrNeispr
    Left = 56
    Top = 416
  end
  object GurZPrNeispr: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_ZPRNEISPR'
      'SET '
      '    IDBASE_REM_ZPRNEISPR = :IDBASE_REM_ZPRNEISPR,'
      '    GID_REM_ZPRNEISPR = :GID_REM_ZPRNEISPR,'
      '    IDPRCOND_REM_ZPRNEISPR = :IDPRCOND_REM_ZPRNEISPR,'
      '    IDPRNEISP_REM_ZPRNEISPR = :IDPRNEISP_REM_ZPRNEISPR,'
      '    IDZ_REM_ZPRNEISPR = :IDZ_REM_ZPRNEISPR'
      'WHERE'
      '    ID_REM_ZPRNEISPR = :OLD_ID_REM_ZPRNEISPR'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_ZPRNEISPR'
      'WHERE'
      '        ID_REM_ZPRNEISPR = :OLD_ID_REM_ZPRNEISPR'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_ZPRNEISPR('
      '    ID_REM_ZPRNEISPR,'
      '    IDBASE_REM_ZPRNEISPR,'
      '    GID_REM_ZPRNEISPR,'
      '    IDPRCOND_REM_ZPRNEISPR,'
      '    IDPRNEISP_REM_ZPRNEISPR,'
      '    IDZ_REM_ZPRNEISPR'
      ')'
      'VALUES('
      '    :ID_REM_ZPRNEISPR,'
      '    :IDBASE_REM_ZPRNEISPR,'
      '    :GID_REM_ZPRNEISPR,'
      '    :IDPRCOND_REM_ZPRNEISPR,'
      '    :IDPRNEISP_REM_ZPRNEISPR,'
      '    :IDZ_REM_ZPRNEISPR'
      ')')
    RefreshSQL.Strings = (
      'select rem_zprneispr.*,'
      '    rem_sprneispr.name_rem_sprneispr,'
      '    rem_sprneispr.code_rem_sprneispr,'
      '    rem_sprneispr.name_eng_rem_sprneispr,'
      '    rem_sprneispr_grp.name_rem_sprneispr_grp,'
      '    rem_sprneispr_grp.name_eng_rem_sprneispr_grp,'
      '    rem_sprcondition.code_rem_sprcondition,'
      '    rem_sprcondition.name_rem_sprcondition,'
      '    rem_sprcondition.name_eng_rem_sprcondition,'
      '    rem_sprcond_grp.code_rem_sprcond_grp,'
      '    rem_sprcond_grp.name_rem_sprcond_grp,'
      '    rem_sprcond_grp.name_eng_rem_sprcond_grp'
      ''
      'from rem_zprneispr'
      
        'left outer join rem_sprneispr  on  rem_sprneispr.id_rem_sprneisp' +
        'r=rem_zprneispr.idprneisp_rem_zprneispr'
      
        'left outer join rem_sprneispr_grp  on  rem_sprneispr.idgrp_rem_s' +
        'prneispr=rem_sprneispr_grp.id_rem_sprneispr_grp'
      
        'left outer join rem_sprcondition  on  rem_sprcondition.id_rem_sp' +
        'rcondition=rem_zprneispr.idprcond_rem_zprneispr'
      
        'left outer join rem_sprcond_grp  on  rem_sprcond_grp.id_rem_sprc' +
        'ond_grp=rem_sprcondition.idgrp_rem_sprcondition'
      'where(  rem_zprneispr.idz_rem_zprneispr=:PARAM_IDZ'
      
        '     ) and (     REM_ZPRNEISPR.ID_REM_ZPRNEISPR = :OLD_ID_REM_ZP' +
        'RNEISPR'
      '     )'
      '    '
      ''
      '')
    SelectSQL.Strings = (
      'select rem_zprneispr.*,'
      '    rem_sprneispr.name_rem_sprneispr,'
      '    rem_sprneispr.code_rem_sprneispr,'
      '    rem_sprneispr.name_eng_rem_sprneispr,'
      '    rem_sprneispr_grp.name_rem_sprneispr_grp,'
      '    rem_sprneispr_grp.name_eng_rem_sprneispr_grp,'
      '    rem_sprcondition.code_rem_sprcondition,'
      '    rem_sprcondition.name_rem_sprcondition,'
      '    rem_sprcondition.name_eng_rem_sprcondition,'
      '    rem_sprcond_grp.code_rem_sprcond_grp,'
      '    rem_sprcond_grp.name_rem_sprcond_grp,'
      '    rem_sprcond_grp.name_eng_rem_sprcond_grp'
      ''
      'from rem_zprneispr'
      
        'left outer join rem_sprneispr  on  rem_sprneispr.id_rem_sprneisp' +
        'r=rem_zprneispr.idprneisp_rem_zprneispr'
      
        'left outer join rem_sprneispr_grp  on  rem_sprneispr.idgrp_rem_s' +
        'prneispr=rem_sprneispr_grp.id_rem_sprneispr_grp'
      
        'left outer join rem_sprcondition  on  rem_sprcondition.id_rem_sp' +
        'rcondition=rem_zprneispr.idprcond_rem_zprneispr'
      
        'left outer join rem_sprcond_grp  on  rem_sprcond_grp.id_rem_sprc' +
        'ond_grp=rem_sprcondition.idgrp_rem_sprcondition'
      'where rem_zprneispr.idz_rem_zprneispr=:PARAM_IDZ'
      ''
      '')
    AutoUpdateOptions.UpdateTableName = 'REM_ZPRNEISPR'
    AutoUpdateOptions.KeyFields = 'ID_REM_ZPRNEISPR'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_ZPRNEISPR_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnCalcFields = GurZPrNeisprCalcFields
    OnNewRecord = GurZPrNeisprNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 416
    poUseLargeIntField = True
    object GurZPrNeisprID_REM_ZPRNEISPR: TFIBLargeIntField
      FieldName = 'ID_REM_ZPRNEISPR'
    end
    object GurZPrNeisprIDBASE_REM_ZPRNEISPR: TFIBLargeIntField
      FieldName = 'IDBASE_REM_ZPRNEISPR'
    end
    object GurZPrNeisprGID_REM_ZPRNEISPR: TFIBWideStringField
      FieldName = 'GID_REM_ZPRNEISPR'
      Size = 10
    end
    object GurZPrNeisprIDPRCOND_REM_ZPRNEISPR: TFIBLargeIntField
      FieldName = 'IDPRCOND_REM_ZPRNEISPR'
    end
    object GurZPrNeisprIDPRNEISP_REM_ZPRNEISPR: TFIBLargeIntField
      FieldName = 'IDPRNEISP_REM_ZPRNEISPR'
    end
    object GurZPrNeisprIDZ_REM_ZPRNEISPR: TFIBLargeIntField
      FieldName = 'IDZ_REM_ZPRNEISPR'
    end
    object GurZPrNeisprNAME_REM_SPRNEISPR: TFIBWideStringField
      FieldName = 'NAME_REM_SPRNEISPR'
      Size = 200
    end
    object GurZPrNeisprCODE_REM_SPRNEISPR: TFIBWideStringField
      FieldName = 'CODE_REM_SPRNEISPR'
    end
    object GurZPrNeisprNAME_ENG_REM_SPRNEISPR: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SPRNEISPR'
      Size = 200
    end
    object GurZPrNeisprNAME_REM_SPRNEISPR_GRP: TFIBWideStringField
      FieldName = 'NAME_REM_SPRNEISPR_GRP'
      Size = 200
    end
    object GurZPrNeisprNAME_ENG_REM_SPRNEISPR_GRP: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SPRNEISPR_GRP'
      Size = 200
    end
    object GurZPrNeisprCODE_REM_SPRCONDITION: TFIBWideStringField
      FieldName = 'CODE_REM_SPRCONDITION'
      Size = 10
    end
    object GurZPrNeisprNAME_REM_SPRCONDITION: TFIBWideStringField
      FieldName = 'NAME_REM_SPRCONDITION'
      Size = 200
    end
    object GurZPrNeisprNAME_ENG_REM_SPRCONDITION: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SPRCONDITION'
      Size = 200
    end
    object GurZPrNeisprCODE_REM_SPRCOND_GRP: TFIBWideStringField
      FieldName = 'CODE_REM_SPRCOND_GRP'
      Size = 10
    end
    object GurZPrNeisprNAME_REM_SPRCOND_GRP: TFIBWideStringField
      FieldName = 'NAME_REM_SPRCOND_GRP'
      Size = 200
    end
    object GurZPrNeisprNAME_ENG_REM_SPRCOND_GRP: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SPRCOND_GRP'
      Size = 200
    end
    object GurZPrNeisprRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
  end
end
