object REM_DMZayavkaPredv: TREM_DMZayavkaPredv
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 441
  Width = 512
  object DataSourceGurZ: TDataSource
    DataSet = GurZ
    Left = 72
    Top = 16
  end
  object GurZ: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_Z2'
      'SET '
      '    IDBASE_REM_Z2 = :IDBASE_REM_Z2,'
      '    PREFIKS_REM_Z2 = :PREFIKS_REM_Z2,'
      '    NUM_REM_Z2 = :NUM_REM_Z2,'
      '    GUID_REM_Z2 = :GUID_REM_Z2,'
      '    POS_REM_Z2 = :POS_REM_Z2,'
      '    IDMODEL_REM_Z2 = :IDMODEL_REM_Z2,'
      '    IDPRMODEL_REM_Z2 = :IDPRMODEL_REM_Z2,'
      '    IDFIRM_REM_Z2 = :IDFIRM_REM_Z2,'
      '    IDSKLPR_REM_Z2 = :IDSKLPR_REM_Z2,'
      '    IDKLIENT_REM_Z2 = :IDKLIENT_REM_Z2,'
      '    IDDILER_REM_Z2 = :IDDILER_REM_Z2,'
      '    NAME_REM_Z2 = :NAME_REM_Z2,'
      '    DESCR_REM_Z2 = :DESCR_REM_Z2,'
      '    KLIENT_NAME_REM_Z2 = :KLIENT_NAME_REM_Z2,'
      '    KLIENT_ADR_REM_Z2 = :KLIENT_ADR_REM_Z2,'
      '    KLIENT_PHONE_REM_Z2 = :KLIENT_PHONE_REM_Z2,'
      '    KLIENT_EMAIL_REM_Z2 = :KLIENT_EMAIL_REM_Z2,'
      '    IDBRAND_REM_Z2 = :IDBRAND_REM_Z2,'
      '    IDPRODUCER_REM_Z2 = :IDPRODUCER_REM_Z2,'
      '    NEISPR_REM_Z2 = :NEISPR_REM_Z2,'
      '    SOST_REM_Z2 = :SOST_REM_Z2,'
      '    MODEL_STR_REM_Z2 = :MODEL_STR_REM_Z2,'
      '    SERNUM1_REM_Z2 = :SERNUM1_REM_Z2,'
      '    SERNUM2_REM_Z2 = :SERNUM2_REM_Z2,'
      '    IDKKT_REM_Z2 = :IDKKT_REM_Z2,'
      '    IDHW_REM_Z2 = :IDHW_REM_Z2,'
      '    IDSELLER_REM_Z2 = :IDSELLER_REM_Z2,'
      '    DOPOPISANIE_REM_Z2 = :DOPOPISANIE_REM_Z2,'
      '    SUMKLIENTA_REM_Z2 = :SUMKLIENTA_REM_Z2,'
      '    SUMNACHA_REM_Z2 = :SUMNACHA_REM_Z2,'
      '    RESULT_REM_Z2 = :RESULT_REM_Z2,'
      '    PRICHINA_REM_Z2 = :PRICHINA_REM_Z2,'
      '    PRICHINA_LIST_REM_Z2 = :PRICHINA_LIST_REM_Z2,'
      '    SROK_REM_Z2 = :SROK_REM_Z2,'
      '    IDUSER_REM_Z2 = :IDUSER_REM_Z2'
      'WHERE'
      '    ID_REM_Z2 = :OLD_ID_REM_Z2'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_Z2'
      'WHERE'
      '        ID_REM_Z2 = :OLD_ID_REM_Z2'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_Z2('
      '    ID_REM_Z2,'
      '    IDBASE_REM_Z2,'
      '    PREFIKS_REM_Z2,'
      '    NUM_REM_Z2,'
      '    GUID_REM_Z2,'
      '    POS_REM_Z2,'
      '    IDMODEL_REM_Z2,'
      '    IDPRMODEL_REM_Z2,'
      '    IDFIRM_REM_Z2,'
      '    IDSKLPR_REM_Z2,'
      '    IDKLIENT_REM_Z2,'
      '    IDDILER_REM_Z2,'
      '    NAME_REM_Z2,'
      '    DESCR_REM_Z2,'
      '    KLIENT_NAME_REM_Z2,'
      '    KLIENT_ADR_REM_Z2,'
      '    KLIENT_PHONE_REM_Z2,'
      '    KLIENT_EMAIL_REM_Z2,'
      '    IDBRAND_REM_Z2,'
      '    IDPRODUCER_REM_Z2,'
      '    NEISPR_REM_Z2,'
      '    SOST_REM_Z2,'
      '    MODEL_STR_REM_Z2,'
      '    SERNUM1_REM_Z2,'
      '    SERNUM2_REM_Z2,'
      '    IDKKT_REM_Z2,'
      '    IDHW_REM_Z2,'
      '    IDSELLER_REM_Z2,'
      '    DOPOPISANIE_REM_Z2,'
      '    SUMKLIENTA_REM_Z2,'
      '    SUMNACHA_REM_Z2,'
      '    RESULT_REM_Z2,'
      '    PRICHINA_REM_Z2,'
      '    PRICHINA_LIST_REM_Z2,'
      '    SROK_REM_Z2,'
      '    IDUSER_REM_Z2'
      ')'
      'VALUES('
      '    :ID_REM_Z2,'
      '    :IDBASE_REM_Z2,'
      '    :PREFIKS_REM_Z2,'
      '    :NUM_REM_Z2,'
      '    :GUID_REM_Z2,'
      '    :POS_REM_Z2,'
      '    :IDMODEL_REM_Z2,'
      '    :IDPRMODEL_REM_Z2,'
      '    :IDFIRM_REM_Z2,'
      '    :IDSKLPR_REM_Z2,'
      '    :IDKLIENT_REM_Z2,'
      '    :IDDILER_REM_Z2,'
      '    :NAME_REM_Z2,'
      '    :DESCR_REM_Z2,'
      '    :KLIENT_NAME_REM_Z2,'
      '    :KLIENT_ADR_REM_Z2,'
      '    :KLIENT_PHONE_REM_Z2,'
      '    :KLIENT_EMAIL_REM_Z2,'
      '    :IDBRAND_REM_Z2,'
      '    :IDPRODUCER_REM_Z2,'
      '    :NEISPR_REM_Z2,'
      '    :SOST_REM_Z2,'
      '    :MODEL_STR_REM_Z2,'
      '    :SERNUM1_REM_Z2,'
      '    :SERNUM2_REM_Z2,'
      '    :IDKKT_REM_Z2,'
      '    :IDHW_REM_Z2,'
      '    :IDSELLER_REM_Z2,'
      '    :DOPOPISANIE_REM_Z2,'
      '    :SUMKLIENTA_REM_Z2,'
      '    :SUMNACHA_REM_Z2,'
      '    :RESULT_REM_Z2,'
      '    :PRICHINA_REM_Z2,'
      '    :PRICHINA_LIST_REM_Z2,'
      '    :SROK_REM_Z2,'
      '    :IDUSER_REM_Z2'
      ')')
    RefreshSQL.Strings = (
      'select rem_z2.*,'
      '    sfirm.namefirm,'
      '    sinfbase_obmen.name_sinfbase_obmen,'
      '    rem_smodel.name_rem_smodel,'
      '    sklad_pr.namesklad as name_sklad_pr,'
      '    sklient.nameklient,'
      '    diler.nameklient as namediler,'
      '    suser.name_user,'
      '    sbrand.name_sbrand,'
      '    rem_shardware.name_rem_shardware,'
      '    rem_shardware.sernum_rem_shardware,'
      '    rem_shardware.sernum2_rem_shardware,'
      '    rem_skkt.name_rem_skkt,'
      '    rem_skkt.sernum_rem_skkt'
      'from rem_z2'
      'left outer join sfirm on sfirm.idfirm=rem_z2.idfirm_rem_z2'
      
        'left outer join sinfbase_obmen on rem_z2.idbase_rem_z2=sinfbase_' +
        'obmen.id_sinfbase_obmen'
      
        'left outer join rem_smodel on rem_smodel.id_rem_smodel=rem_z2.id' +
        'model_rem_z2'
      
        'left outer join ssklad as sklad_pr on sklad_pr.idsklad=rem_z2.id' +
        'sklpr_rem_z2'
      
        'left outer join sklient on sklient.idklient=rem_z2.idklient_rem_' +
        'z2'
      
        'left outer join sklient as diler on diler.idklient=rem_z2.iddile' +
        'r_rem_z2'
      'left outer join suser  on suser.id_user=rem_z2.iduser_rem_z2'
      'left outer join sbrand on sbrand.id_sbrand=rem_z2.idbrand_rem_z2'
      
        'left outer join rem_shardware on rem_z2.idhw_rem_z2=rem_shardwar' +
        'e.id_rem_shardware'
      
        'left outer join rem_skkt on rem_z2.idkkt_rem_z2=rem_skkt.idklien' +
        't_rem_skkt'
      'where(  rem_z2.id_rem_z2=:PARAM_ID'
      '     ) and (     REM_Z2.ID_REM_Z2 = :OLD_ID_REM_Z2'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_z2.*,'
      '    sfirm.namefirm,'
      '    sinfbase_obmen.name_sinfbase_obmen,'
      '    rem_smodel.name_rem_smodel,'
      '    sklad_pr.namesklad as name_sklad_pr,'
      '    sklient.nameklient,'
      '    diler.nameklient as namediler,'
      '    suser.name_user,'
      '    sbrand.name_sbrand,'
      '    rem_shardware.name_rem_shardware,'
      '    rem_shardware.sernum_rem_shardware,'
      '    rem_shardware.sernum2_rem_shardware,'
      '    rem_skkt.name_rem_skkt,'
      '    rem_skkt.sernum_rem_skkt'
      'from rem_z2'
      'left outer join sfirm on sfirm.idfirm=rem_z2.idfirm_rem_z2'
      
        'left outer join sinfbase_obmen on rem_z2.idbase_rem_z2=sinfbase_' +
        'obmen.id_sinfbase_obmen'
      
        'left outer join rem_smodel on rem_smodel.id_rem_smodel=rem_z2.id' +
        'model_rem_z2'
      
        'left outer join ssklad as sklad_pr on sklad_pr.idsklad=rem_z2.id' +
        'sklpr_rem_z2'
      
        'left outer join sklient on sklient.idklient=rem_z2.idklient_rem_' +
        'z2'
      
        'left outer join sklient as diler on diler.idklient=rem_z2.iddile' +
        'r_rem_z2'
      'left outer join suser  on suser.id_user=rem_z2.iduser_rem_z2'
      'left outer join sbrand on sbrand.id_sbrand=rem_z2.idbrand_rem_z2'
      
        'left outer join rem_shardware on rem_z2.idhw_rem_z2=rem_shardwar' +
        'e.id_rem_shardware'
      
        'left outer join rem_skkt on rem_z2.idkkt_rem_z2=rem_skkt.idklien' +
        't_rem_skkt'
      'where rem_z2.id_rem_z2=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_Z'
    AutoUpdateOptions.KeyFields = 'ID_REM_Z'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_Z_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object GurZID_REM_Z2: TFIBLargeIntField
      FieldName = 'ID_REM_Z2'
    end
    object GurZIDBASE_REM_Z2: TFIBLargeIntField
      FieldName = 'IDBASE_REM_Z2'
    end
    object GurZPREFIKS_REM_Z2: TFIBWideStringField
      FieldName = 'PREFIKS_REM_Z2'
      Size = 12
    end
    object GurZNUM_REM_Z2: TFIBIntegerField
      FieldName = 'NUM_REM_Z2'
    end
    object GurZGUID_REM_Z2: TFIBWideStringField
      FieldName = 'GUID_REM_Z2'
      Size = 38
    end
    object GurZPOS_REM_Z2: TFIBDateTimeField
      FieldName = 'POS_REM_Z2'
    end
    object GurZIDMODEL_REM_Z2: TFIBLargeIntField
      FieldName = 'IDMODEL_REM_Z2'
    end
    object GurZIDPRMODEL_REM_Z2: TFIBLargeIntField
      FieldName = 'IDPRMODEL_REM_Z2'
    end
    object GurZIDFIRM_REM_Z2: TFIBLargeIntField
      FieldName = 'IDFIRM_REM_Z2'
    end
    object GurZIDSKLPR_REM_Z2: TFIBLargeIntField
      FieldName = 'IDSKLPR_REM_Z2'
    end
    object GurZIDKLIENT_REM_Z2: TFIBLargeIntField
      FieldName = 'IDKLIENT_REM_Z2'
    end
    object GurZIDDILER_REM_Z2: TFIBLargeIntField
      FieldName = 'IDDILER_REM_Z2'
    end
    object GurZNAME_REM_Z2: TFIBWideStringField
      FieldName = 'NAME_REM_Z2'
      Size = 200
    end
    object GurZDESCR_REM_Z2: TFIBWideStringField
      FieldName = 'DESCR_REM_Z2'
      Size = 150
    end
    object GurZKLIENT_NAME_REM_Z2: TFIBWideStringField
      FieldName = 'KLIENT_NAME_REM_Z2'
      Size = 200
    end
    object GurZKLIENT_ADR_REM_Z2: TFIBWideStringField
      FieldName = 'KLIENT_ADR_REM_Z2'
      Size = 200
    end
    object GurZKLIENT_PHONE_REM_Z2: TFIBWideStringField
      FieldName = 'KLIENT_PHONE_REM_Z2'
      Size = 40
    end
    object GurZKLIENT_EMAIL_REM_Z2: TFIBWideStringField
      FieldName = 'KLIENT_EMAIL_REM_Z2'
      Size = 40
    end
    object GurZIDBRAND_REM_Z2: TFIBLargeIntField
      FieldName = 'IDBRAND_REM_Z2'
    end
    object GurZIDPRODUCER_REM_Z2: TFIBLargeIntField
      FieldName = 'IDPRODUCER_REM_Z2'
    end
    object GurZNEISPR_REM_Z2: TFIBWideStringField
      FieldName = 'NEISPR_REM_Z2'
      Size = 250
    end
    object GurZSOST_REM_Z2: TFIBWideStringField
      FieldName = 'SOST_REM_Z2'
      Size = 250
    end
    object GurZMODEL_STR_REM_Z2: TFIBWideStringField
      FieldName = 'MODEL_STR_REM_Z2'
      Size = 40
    end
    object GurZSERNUM1_REM_Z2: TFIBWideStringField
      FieldName = 'SERNUM1_REM_Z2'
      Size = 50
    end
    object GurZSERNUM2_REM_Z2: TFIBWideStringField
      FieldName = 'SERNUM2_REM_Z2'
      Size = 50
    end
    object GurZIDKKT_REM_Z2: TFIBLargeIntField
      FieldName = 'IDKKT_REM_Z2'
    end
    object GurZIDHW_REM_Z2: TFIBLargeIntField
      FieldName = 'IDHW_REM_Z2'
    end
    object GurZIDSELLER_REM_Z2: TFIBLargeIntField
      FieldName = 'IDSELLER_REM_Z2'
    end
    object GurZDOPOPISANIE_REM_Z2: TFIBWideStringField
      FieldName = 'DOPOPISANIE_REM_Z2'
      Size = 250
    end
    object GurZSUMKLIENTA_REM_Z2: TFIBBCDField
      FieldName = 'SUMKLIENTA_REM_Z2'
      Size = 2
      RoundByScale = True
    end
    object GurZSUMNACHA_REM_Z2: TFIBBCDField
      FieldName = 'SUMNACHA_REM_Z2'
      Size = 2
      RoundByScale = True
    end
    object GurZRESULT_REM_Z2: TFIBIntegerField
      FieldName = 'RESULT_REM_Z2'
    end
    object GurZPRICHINA_REM_Z2: TFIBWideStringField
      FieldName = 'PRICHINA_REM_Z2'
      Size = 250
    end
    object GurZPRICHINA_LIST_REM_Z2: TFIBIntegerField
      FieldName = 'PRICHINA_LIST_REM_Z2'
    end
    object GurZSROK_REM_Z2: TFIBIntegerField
      FieldName = 'SROK_REM_Z2'
    end
    object GurZIDUSER_REM_Z2: TFIBLargeIntField
      FieldName = 'IDUSER_REM_Z2'
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
    object GurZNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
      Size = 200
    end
    object GurZNAME_SBRAND: TFIBWideStringField
      FieldName = 'NAME_SBRAND'
      Size = 200
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
      
        'from REM_ZAYAVKA_PREDV_GET_NUM (:PARAM_IDBASE,:PARAM_IDFIRM,:PAR' +
        'AM_IDSKLAD)'
      ''
      '')
    Transaction = IBTr
    Left = 368
    Top = 16
  end
end
