object REM_DMGurCustQueryDetal: TREM_DMGurCustQueryDetal
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 276
  Width = 414
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 16
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select rem_cquery_get_table_detal.*,'
      '       sklient.nameklient  as prodavec_name,'
      '       rem_cquery.num_str_zak_post_rem_cquery,'
      '       rem_cquery.num_str_zak_sprov_rem_cquery,'
      '       rem_cquery.numdoctk_rem_cquery'
      
        'from rem_cquery_get_table_detal(:PARAM_IDUSER,:PARAM_DATE_NACH,:' +
        'PARAM_DATE_CON,:PARAM_POISK,:PARAM_STR,:PARAM_INT64)'
      
        'left outer join rem_cquery on rem_cquery.id_rem_cquery =  rem_cq' +
        'uery_get_table_detal.id_rem_cquery'
      
        'left outer join sklient on sklient.idklient = rem_cquery.idproda' +
        'vec_rem_cquery')
    Transaction = IBTr
    Left = 144
    Top = 16
    poUseLargeIntField = True
    object TableID_REM_CQUERY: TFIBLargeIntField
      FieldName = 'ID_REM_CQUERY'
    end
    object TableGID_REM_CQUERY: TFIBWideStringField
      FieldName = 'GID_REM_CQUERY'
      Size = 10
    end
    object TableIDBASE_REM_CQUERY: TFIBLargeIntField
      FieldName = 'IDBASE_REM_CQUERY'
    end
    object TablePOS_REM_CQUERY: TFIBDateTimeField
      FieldName = 'POS_REM_CQUERY'
      DisplayFormat = 'c'
    end
    object TableNUM_REM_CQUERY: TFIBIntegerField
      FieldName = 'NUM_REM_CQUERY'
    end
    object TableIDFIRM_REM_CQUERY: TFIBLargeIntField
      FieldName = 'IDFIRM_REM_CQUERY'
    end
    object TableIDSKLAD_REM_CQUERY: TFIBLargeIntField
      FieldName = 'IDSKLAD_REM_CQUERY'
    end
    object TableIDUSER_REM_CQUERY: TFIBLargeIntField
      FieldName = 'IDUSER_REM_CQUERY'
    end
    object TableIDKLIENT_REM_CQUERY: TFIBLargeIntField
      FieldName = 'IDKLIENT_REM_CQUERY'
    end
    object TableKLIENT_NAME_REM_CQUERY: TFIBWideStringField
      FieldName = 'KLIENT_NAME_REM_CQUERY'
      Size = 200
    end
    object TableKLIENT_ADR_REM_CQUERY: TFIBWideStringField
      FieldName = 'KLIENT_ADR_REM_CQUERY'
      Size = 200
    end
    object TableKLIENT_PHONE_REM_CQUERY: TFIBWideStringField
      FieldName = 'KLIENT_PHONE_REM_CQUERY'
      Size = 40
    end
    object TableCOMMENTS_REM_CQUERY: TFIBWideStringField
      FieldName = 'COMMENTS_REM_CQUERY'
      Size = 250
    end
    object TableRUN_REM_CQUERY: TFIBSmallIntField
      FieldName = 'RUN_REM_CQUERY'
    end
    object TableDO_SUM_REM_CQUERY: TFIBBCDField
      FieldName = 'DO_SUM_REM_CQUERY'
      Size = 2
      RoundByScale = True
    end
    object TableTEC_SUM_REM_CQUERY: TFIBBCDField
      FieldName = 'TEC_SUM_REM_CQUERY'
      Size = 2
      RoundByScale = True
    end
    object TableSOGL_SUM_REM_CQUERY: TFIBBCDField
      FieldName = 'SOGL_SUM_REM_CQUERY'
      Size = 2
      RoundByScale = True
    end
    object TableIDZ_REM_CQUERY: TFIBLargeIntField
      FieldName = 'IDZ_REM_CQUERY'
    end
    object TableIDMODEL_REM_CQUERY: TFIBLargeIntField
      FieldName = 'IDMODEL_REM_CQUERY'
    end
    object TableNAME_MODEL_REM_CQUERY: TFIBWideStringField
      FieldName = 'NAME_MODEL_REM_CQUERY'
      Size = 40
    end
    object TableNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 200
    end
    object TableNAME_REM_SMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SMODEL'
      OnGetText = TableNAME_REM_SMODELGetText
      Size = 200
    end
    object TableNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 200
    end
    object TableNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      OnGetText = TableNAMEKLIENTGetText
      Size = 200
    end
    object TableNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
      Size = 200
    end
    object TableIDBRAND_REM_CQUERY: TFIBLargeIntField
      FieldName = 'IDBRAND_REM_CQUERY'
    end
    object TableIDPRODUCER_REM_CQUERY: TFIBLargeIntField
      FieldName = 'IDPRODUCER_REM_CQUERY'
    end
    object TableFL_KLIENT_UVEDOML_REM_CQUERY: TFIBSmallIntField
      FieldName = 'FL_KLIENT_UVEDOML_REM_CQUERY'
    end
    object TableNAME_SBRAND: TFIBWideStringField
      FieldName = 'NAME_SBRAND'
      Size = 200
    end
    object TableNAME_SPRODUCER: TFIBWideStringField
      FieldName = 'NAME_SPRODUCER'
      Size = 200
    end
    object TableNUM_ZAKAZA_REM_CQUERY: TFIBIntegerField
      FieldName = 'NUM_ZAKAZA_REM_CQUERY'
    end
    object TableDATE_ZAKAZA_REM_CQUERY: TFIBDateField
      FieldName = 'DATE_ZAKAZA_REM_CQUERY'
    end
    object TableTYPE_REM_CQUERY: TFIBIntegerField
      FieldName = 'TYPE_REM_CQUERY'
    end
    object TableNAMENOM_REM_CQUERYT: TFIBWideStringField
      FieldName = 'NAMENOM_REM_CQUERYT'
      Size = 200
    end
    object TableCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object TableARTNOM: TFIBWideStringField
      FieldName = 'ARTNOM'
      Size = 40
    end
    object TableNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      OnGetText = TableNAMENOMGetText
      Size = 200
    end
    object TableKOL_REM_CQUERYT: TFIBBCDField
      FieldName = 'KOL_REM_CQUERYT'
      Size = 3
      RoundByScale = True
    end
    object TableKF_REM_CQUERYT: TFIBBCDField
      FieldName = 'KF_REM_CQUERYT'
      Size = 3
      RoundByScale = True
    end
    object TablePRICE_REM_CQUERYT: TFIBBCDField
      FieldName = 'PRICE_REM_CQUERYT'
      Size = 2
      RoundByScale = True
    end
    object TableNOM_SUM_STR: TFIBBCDField
      FieldName = 'NOM_SUM_STR'
      Size = 2
      RoundByScale = True
    end
    object TableCODE_SPRNOM: TFIBIntegerField
      FieldName = 'CODE_SPRNOM'
    end
    object TableART_SPRNOM: TFIBWideStringField
      FieldName = 'ART_SPRNOM'
      Size = 40
    end
    object TableNAME_SPRNOM: TFIBWideStringField
      FieldName = 'NAME_SPRNOM'
      Size = 200
    end
    object TableFL_DOSTUPNO_SPRNOM: TFIBSmallIntField
      FieldName = 'FL_DOSTUPNO_SPRNOM'
    end
    object TablePRICE_ZAKUP_SPRNOM: TFIBBCDField
      FieldName = 'PRICE_ZAKUP_SPRNOM'
      Size = 2
      RoundByScale = True
    end
    object TablePRNOM_SUM_STR: TFIBBCDField
      FieldName = 'PRNOM_SUM_STR'
      Size = 2
      RoundByScale = True
    end
    object TableID_REM_CQUERYT: TFIBLargeIntField
      FieldName = 'ID_REM_CQUERYT'
    end
    object TablePRODAVEC_NAME: TFIBWideStringField
      FieldName = 'PRODAVEC_NAME'
      Size = 200
    end
    object TableNUM_STR_ZAK_POST_REM_CQUERY: TFIBWideStringField
      FieldName = 'NUM_STR_ZAK_POST_REM_CQUERY'
    end
    object TableNUM_STR_ZAK_SPROV_REM_CQUERY: TFIBWideStringField
      FieldName = 'NUM_STR_ZAK_SPROV_REM_CQUERY'
    end
    object TableNUMDOCTK_REM_CQUERY: TFIBWideStringField
      FieldName = 'NUMDOCTK_REM_CQUERY'
      Size = 40
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
    Transaction = IBTr
    Left = 232
    Top = 80
    qoStartTransaction = True
  end
end
