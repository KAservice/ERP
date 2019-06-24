object REM_DMGurZPredv: TREM_DMGurZPredv
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 281
  Width = 591
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 16
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select rem_z2.*,'
      '    sinfbase_obmen.name_sinfbase_obmen,'
      '    sfirm.namefirm,'
      '    rem_smodel.name_rem_smodel,'
      '    sklad_pr.namesklad as name_sklad_pr,'
      '    sklient.nameklient,'
      '    diler.nameklient as namediler,'
      '    suser.name_user,'
      '    sbrand.name_sbrand'
      'from rem_z2'
      
        'left outer join sinfbase_obmen on sinfbase_obmen.id_sinfbase_obm' +
        'en=rem_z2.idbase_rem_z2'
      'left outer join sfirm on sfirm.idfirm=rem_z2.idfirm_rem_z2'
      
        'left outer join rem_smodel on rem_smodel.id_rem_smodel=rem_z2.id' +
        'model_rem_z2'
      
        'left outer join ssklad as sklad_pr on sklad_pr.idsklad=rem_z2.id' +
        'sklpr_rem_z2'
      
        'left outer join sklient on sklient.idklient=rem_z2.idklient_rem_' +
        'z2'
      
        'left outer join sklient as diler on diler.idklient=rem_z2.iddile' +
        'r_rem_z2'
      'left outer join suser on suser.id_user=rem_z2.iduser_rem_z2'
      'left outer join sbrand on rem_z2.idbrand_rem_z2=sbrand.id_sbrand'
      
        'where rem_z2.pos_rem_z2 between  :PARAM_DATE_NACH and :PARAM_DAT' +
        'E_CON'
      'order by   rem_z2.pos_rem_z2')
    Transaction = IBTr
    Left = 144
    Top = 16
    poUseLargeIntField = True
    object TableID_REM_Z2: TFIBLargeIntField
      FieldName = 'ID_REM_Z2'
    end
    object TableIDBASE_REM_Z2: TFIBLargeIntField
      FieldName = 'IDBASE_REM_Z2'
    end
    object TablePREFIKS_REM_Z2: TFIBWideStringField
      FieldName = 'PREFIKS_REM_Z2'
      Size = 12
    end
    object TableNUM_REM_Z2: TFIBIntegerField
      FieldName = 'NUM_REM_Z2'
    end
    object TableGUID_REM_Z2: TFIBWideStringField
      FieldName = 'GUID_REM_Z2'
      Size = 38
    end
    object TablePOS_REM_Z2: TFIBDateTimeField
      FieldName = 'POS_REM_Z2'
    end
    object TableIDMODEL_REM_Z2: TFIBLargeIntField
      FieldName = 'IDMODEL_REM_Z2'
    end
    object TableIDPRMODEL_REM_Z2: TFIBLargeIntField
      FieldName = 'IDPRMODEL_REM_Z2'
    end
    object TableIDFIRM_REM_Z2: TFIBLargeIntField
      FieldName = 'IDFIRM_REM_Z2'
    end
    object TableIDSKLPR_REM_Z2: TFIBLargeIntField
      FieldName = 'IDSKLPR_REM_Z2'
    end
    object TableIDKLIENT_REM_Z2: TFIBLargeIntField
      FieldName = 'IDKLIENT_REM_Z2'
    end
    object TableIDDILER_REM_Z2: TFIBLargeIntField
      FieldName = 'IDDILER_REM_Z2'
    end
    object TableNAME_REM_Z2: TFIBWideStringField
      FieldName = 'NAME_REM_Z2'
      Size = 200
    end
    object TableDESCR_REM_Z2: TFIBWideStringField
      FieldName = 'DESCR_REM_Z2'
      Size = 150
    end
    object TableKLIENT_NAME_REM_Z2: TFIBWideStringField
      FieldName = 'KLIENT_NAME_REM_Z2'
      Size = 200
    end
    object TableKLIENT_ADR_REM_Z2: TFIBWideStringField
      FieldName = 'KLIENT_ADR_REM_Z2'
      Size = 200
    end
    object TableKLIENT_PHONE_REM_Z2: TFIBWideStringField
      FieldName = 'KLIENT_PHONE_REM_Z2'
      Size = 40
    end
    object TableKLIENT_EMAIL_REM_Z2: TFIBWideStringField
      FieldName = 'KLIENT_EMAIL_REM_Z2'
      Size = 40
    end
    object TableIDBRAND_REM_Z2: TFIBLargeIntField
      FieldName = 'IDBRAND_REM_Z2'
    end
    object TableIDPRODUCER_REM_Z2: TFIBLargeIntField
      FieldName = 'IDPRODUCER_REM_Z2'
    end
    object TableNEISPR_REM_Z2: TFIBWideStringField
      FieldName = 'NEISPR_REM_Z2'
      Size = 250
    end
    object TableSOST_REM_Z2: TFIBWideStringField
      FieldName = 'SOST_REM_Z2'
      Size = 250
    end
    object TableMODEL_STR_REM_Z2: TFIBWideStringField
      FieldName = 'MODEL_STR_REM_Z2'
      Size = 40
    end
    object TableSERNUM1_REM_Z2: TFIBWideStringField
      FieldName = 'SERNUM1_REM_Z2'
      Size = 50
    end
    object TableSERNUM2_REM_Z2: TFIBWideStringField
      FieldName = 'SERNUM2_REM_Z2'
      Size = 50
    end
    object TableIDKKT_REM_Z2: TFIBLargeIntField
      FieldName = 'IDKKT_REM_Z2'
    end
    object TableIDHW_REM_Z2: TFIBLargeIntField
      FieldName = 'IDHW_REM_Z2'
    end
    object TableIDSELLER_REM_Z2: TFIBLargeIntField
      FieldName = 'IDSELLER_REM_Z2'
    end
    object TableDOPOPISANIE_REM_Z2: TFIBWideStringField
      FieldName = 'DOPOPISANIE_REM_Z2'
      Size = 250
    end
    object TableSUMKLIENTA_REM_Z2: TFIBBCDField
      FieldName = 'SUMKLIENTA_REM_Z2'
      Size = 2
      RoundByScale = True
    end
    object TableSUMNACHA_REM_Z2: TFIBBCDField
      FieldName = 'SUMNACHA_REM_Z2'
      Size = 2
      RoundByScale = True
    end
    object TableRESULT_REM_Z2: TFIBIntegerField
      FieldName = 'RESULT_REM_Z2'
    end
    object TablePRICHINA_REM_Z2: TFIBWideStringField
      FieldName = 'PRICHINA_REM_Z2'
      Size = 250
    end
    object TablePRICHINA_LIST_REM_Z2: TFIBIntegerField
      FieldName = 'PRICHINA_LIST_REM_Z2'
    end
    object TableSROK_REM_Z2: TFIBIntegerField
      FieldName = 'SROK_REM_Z2'
    end
    object TableIDUSER_REM_Z2: TFIBLargeIntField
      FieldName = 'IDUSER_REM_Z2'
    end
    object TableNAME_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 200
    end
    object TableNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 200
    end
    object TableNAME_REM_SMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SMODEL'
      Size = 200
    end
    object TableNAME_SKLAD_PR: TFIBWideStringField
      FieldName = 'NAME_SKLAD_PR'
      Size = 200
    end
    object TableNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 200
    end
    object TableNAMEDILER: TFIBWideStringField
      FieldName = 'NAMEDILER'
      Size = 200
    end
    object TableNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
      Size = 200
    end
    object TableNAME_SBRAND: TFIBWideStringField
      FieldName = 'NAME_SBRAND'
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
    Left = 232
    Top = 16
  end
  object pFIBQ: TpFIBQuery
    Left = 232
    Top = 80
    qoStartTransaction = True
  end
end
