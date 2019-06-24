object REM_DMGurVigrusok: TREM_DMGurVigrusok
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 280
  Width = 292
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 16
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select '
      '    rem_gur_vigr.*,'
      '    sproducer.name_sproducer,'
      '    sklient.NAMEKLIENT,'
      '    suser.NAME_USER,'
      '    sinfbase_obmen.name_sinfbase_obmen'
      ''
      'from   rem_gur_vigr'
      
        'left outer join SINFBASE_OBMEN on rem_gur_vigr.idbase_rem_gur_vi' +
        'gr=sinfbase_obmen.id_sinfbase_obmen'
      
        'left outer join SKLIENT on rem_gur_vigr.idklient_rem_gur_vigr =s' +
        'klient.IDKLIENT'
      
        'left outer join sproducer on rem_gur_vigr.idproducer_rem_gur_vig' +
        'r =sproducer.id_sproducer'
      
        'left outer join SUSER on  rem_gur_vigr.iduser_rem_gur_vigr = sus' +
        'er.ID_USER'
      ''
      
        'where rem_gur_vigr.pos_rem_gur_vigr between  :PARAM_POSNACH and ' +
        ':PARAM_POSCON'
      'order by rem_gur_vigr.pos_rem_gur_vigr')
    Transaction = IBTr
    Left = 144
    Top = 16
    poUseLargeIntField = True
    object TableID_REM_GUR_VIGR: TFIBLargeIntField
      FieldName = 'ID_REM_GUR_VIGR'
    end
    object TableIDBASE_REM_GUR_VIGR: TFIBLargeIntField
      FieldName = 'IDBASE_REM_GUR_VIGR'
    end
    object TableIDUSER_REM_GUR_VIGR: TFIBLargeIntField
      FieldName = 'IDUSER_REM_GUR_VIGR'
    end
    object TablePOS_REM_GUR_VIGR: TFIBDateTimeField
      FieldName = 'POS_REM_GUR_VIGR'
      DisplayFormat = 'c'
    end
    object TableNUM_REM_GUR_VIGR: TFIBIntegerField
      FieldName = 'NUM_REM_GUR_VIGR'
    end
    object TableGUID_TRANSACTION_REM_GUR_VIGR: TFIBWideStringField
      FieldName = 'GUID_TRANSACTION_REM_GUR_VIGR'
      Size = 38
    end
    object TableCODE_STR_VIGR_REM_GUR_VIGR: TFIBWideStringField
      FieldName = 'CODE_STR_VIGR_REM_GUR_VIGR'
      Size = 40
    end
    object TableGUID_VIGR_REM_GUR_VIGR: TFIBWideStringField
      FieldName = 'GUID_VIGR_REM_GUR_VIGR'
      Size = 38
    end
    object TableIDKLIENT_REM_GUR_VIGR: TFIBLargeIntField
      FieldName = 'IDKLIENT_REM_GUR_VIGR'
    end
    object TableIDPRODUCER_REM_GUR_VIGR: TFIBLargeIntField
      FieldName = 'IDPRODUCER_REM_GUR_VIGR'
    end
    object TableNAME_SPRODUCER: TFIBWideStringField
      FieldName = 'NAME_SPRODUCER'
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
    object TableNAME_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
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
  object IBQ: TpFIBDataSet
    Transaction = IBTr
    Left = 144
    Top = 128
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 224
    Top = 104
    qoStartTransaction = True
  end
end
