object REM_DMGurCustQuery: TREM_DMGurCustQuery
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
      'select rem_cquery.*,'
      '    sfirm.namefirm,'
      '    rem_smodel.name_rem_smodel,'
      '    ssklad.namesklad,'
      '    sklient.nameklient,'
      '    suser.name_user,'
      '    sbrand.name_sbrand,'
      '    sproducer.name_sproducer'
      'from rem_cquery'
      
        'left outer join sfirm on sfirm.idfirm=rem_cquery.idfirm_rem_cque' +
        'ry'
      
        'left outer join rem_smodel on rem_smodel.id_rem_smodel=rem_cquer' +
        'y.idmodel_rem_cquery'
      
        'left outer join ssklad on ssklad.idsklad=rem_cquery.idsklad_rem_' +
        'cquery'
      
        'left outer join sklient on sklient.idklient=rem_cquery.idklient_' +
        'rem_cquery'
      
        'left outer join suser on suser.id_user=rem_cquery.iduser_rem_cqu' +
        'ery'
      
        'left outer join sbrand on rem_cquery.idbrand_rem_cquery=sbrand.i' +
        'd_sbrand'
      
        'left outer join sproducer on rem_cquery.idproducer_rem_cquery=sp' +
        'roducer.id_sproducer'
      
        'where rem_cquery.pos_rem_cquery between  :PARAM_DATE_NACH and :P' +
        'ARAM_DATE_CON'
      'order by   rem_cquery.pos_rem_cquery')
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
      Size = 200
    end
    object TableNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 200
    end
    object TableNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
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
