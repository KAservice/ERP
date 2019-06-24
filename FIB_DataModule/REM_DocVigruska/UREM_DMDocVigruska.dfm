object REM_DMDocVigruska: TREM_DMDocVigruska
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 369
  Width = 398
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
      'UPDATE REM_GUR_VIGR'
      'SET '
      '    IDBASE_REM_GUR_VIGR = :IDBASE_REM_GUR_VIGR,'
      '    IDUSER_REM_GUR_VIGR = :IDUSER_REM_GUR_VIGR,'
      '    POS_REM_GUR_VIGR = :POS_REM_GUR_VIGR,'
      '    NUM_REM_GUR_VIGR = :NUM_REM_GUR_VIGR,'
      
        '    GUID_TRANSACTION_REM_GUR_VIGR = :GUID_TRANSACTION_REM_GUR_VI' +
        'GR,'
      '    CODE_STR_VIGR_REM_GUR_VIGR = :CODE_STR_VIGR_REM_GUR_VIGR,'
      '    GUID_VIGR_REM_GUR_VIGR = :GUID_VIGR_REM_GUR_VIGR,'
      '    IDKLIENT_REM_GUR_VIGR = :IDKLIENT_REM_GUR_VIGR,'
      '    IDPRODUCER_REM_GUR_VIGR = :IDPRODUCER_REM_GUR_VIGR'
      'WHERE'
      '    ID_REM_GUR_VIGR = :OLD_ID_REM_GUR_VIGR'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_GUR_VIGR'
      'WHERE'
      '        ID_REM_GUR_VIGR = :OLD_ID_REM_GUR_VIGR'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_GUR_VIGR('
      '    ID_REM_GUR_VIGR,'
      '    IDBASE_REM_GUR_VIGR,'
      '    IDUSER_REM_GUR_VIGR,'
      '    POS_REM_GUR_VIGR,'
      '    NUM_REM_GUR_VIGR,'
      '    GUID_TRANSACTION_REM_GUR_VIGR,'
      '    CODE_STR_VIGR_REM_GUR_VIGR,'
      '    GUID_VIGR_REM_GUR_VIGR,'
      '    IDKLIENT_REM_GUR_VIGR,'
      '    IDPRODUCER_REM_GUR_VIGR'
      ')'
      'VALUES('
      '    :ID_REM_GUR_VIGR,'
      '    :IDBASE_REM_GUR_VIGR,'
      '    :IDUSER_REM_GUR_VIGR,'
      '    :POS_REM_GUR_VIGR,'
      '    :NUM_REM_GUR_VIGR,'
      '    :GUID_TRANSACTION_REM_GUR_VIGR,'
      '    :CODE_STR_VIGR_REM_GUR_VIGR,'
      '    :GUID_VIGR_REM_GUR_VIGR,'
      '    :IDKLIENT_REM_GUR_VIGR,'
      '    :IDPRODUCER_REM_GUR_VIGR'
      ')')
    RefreshSQL.Strings = (
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
      'where(  rem_gur_vigr.id_rem_gur_vigr=:PARAM_IDDOC'
      
        '     ) and (     REM_GUR_VIGR.ID_REM_GUR_VIGR = :OLD_ID_REM_GUR_' +
        'VIGR'
      '     )'
      '    '
      '')
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
      'where rem_gur_vigr.id_rem_gur_vigr=:PARAM_IDDOC'
      '')
    AutoUpdateOptions.UpdateTableName = 'REM_GUR_VIGR'
    AutoUpdateOptions.KeyFields = 'ID_REM_GUR_VIGR'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_GUR_VIGR_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object DocAllID_REM_GUR_VIGR: TFIBLargeIntField
      FieldName = 'ID_REM_GUR_VIGR'
    end
    object DocAllIDBASE_REM_GUR_VIGR: TFIBLargeIntField
      FieldName = 'IDBASE_REM_GUR_VIGR'
      OnChange = DocAllIDBASE_REM_GUR_VIGRChange
    end
    object DocAllIDUSER_REM_GUR_VIGR: TFIBLargeIntField
      FieldName = 'IDUSER_REM_GUR_VIGR'
    end
    object DocAllPOS_REM_GUR_VIGR: TFIBDateTimeField
      FieldName = 'POS_REM_GUR_VIGR'
      OnChange = DocAllPOS_REM_GUR_VIGRChange
      DisplayFormat = 'c'
    end
    object DocAllNUM_REM_GUR_VIGR: TFIBIntegerField
      FieldName = 'NUM_REM_GUR_VIGR'
    end
    object DocAllGUID_TRANSACTION_REM_GUR_VIGR: TFIBWideStringField
      FieldName = 'GUID_TRANSACTION_REM_GUR_VIGR'
      Size = 38
    end
    object DocAllCODE_STR_VIGR_REM_GUR_VIGR: TFIBWideStringField
      FieldName = 'CODE_STR_VIGR_REM_GUR_VIGR'
      Size = 40
    end
    object DocAllGUID_VIGR_REM_GUR_VIGR: TFIBWideStringField
      FieldName = 'GUID_VIGR_REM_GUR_VIGR'
      Size = 38
    end
    object DocAllIDKLIENT_REM_GUR_VIGR: TFIBLargeIntField
      FieldName = 'IDKLIENT_REM_GUR_VIGR'
    end
    object DocAllIDPRODUCER_REM_GUR_VIGR: TFIBLargeIntField
      FieldName = 'IDPRODUCER_REM_GUR_VIGR'
    end
    object DocAllNAME_SPRODUCER: TFIBWideStringField
      FieldName = 'NAME_SPRODUCER'
      Size = 200
    end
    object DocAllNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 200
    end
    object DocAllNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
      Size = 200
    end
    object DocAllNAME_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 200
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_GUR_VIGRT'
      'SET '
      '    IDBASE_REM_GUR_VIGRT = :IDBASE_REM_GUR_VIGRT,'
      '    IDDOC_REM_GUR_VIGRT = :IDDOC_REM_GUR_VIGRT,'
      '    IDDOCVIGR_REM_GUR_VIGRT = :IDDOCVIGR_REM_GUR_VIGRT'
      'WHERE'
      '    ID_REM_GUR_VIGRT = :OLD_ID_REM_GUR_VIGRT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_GUR_VIGRT'
      'WHERE'
      '        ID_REM_GUR_VIGRT = :OLD_ID_REM_GUR_VIGRT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_GUR_VIGRT('
      '    ID_REM_GUR_VIGRT,'
      '    IDBASE_REM_GUR_VIGRT,'
      '    IDDOC_REM_GUR_VIGRT,'
      '    IDDOCVIGR_REM_GUR_VIGRT'
      ')'
      'VALUES('
      '    :ID_REM_GUR_VIGRT,'
      '    :IDBASE_REM_GUR_VIGRT,'
      '    :IDDOC_REM_GUR_VIGRT,'
      '    :IDDOCVIGR_REM_GUR_VIGRT'
      ')')
    RefreshSQL.Strings = (
      'select rem_gur_vigrt.*,'
      '    sfirm.namefirm,'
      '    ssklad.namesklad,'
      '    sklient.NAMEKLIENT,'
      '    sinfbase_obmen.name_sinfbase_obmen,'
      '    rem_galldoc.prefiks_num_rem_galldoc,'
      '    rem_galldoc.pr_rem_galldoc,'
      '    rem_galldoc.num_rem_galldoc,'
      '    rem_galldoc.pos_rem_galldoc,'
      '    rem_galldoc.tdoc_rem_galldoc'
      'from rem_gur_vigrt'
      
        'left outer join rem_galldoc on rem_gur_vigrt.iddocvigr_rem_gur_v' +
        'igrt=rem_galldoc.id_rem_galldoc'
      
        'left outer join SINFBASE_OBMEN on rem_galldoc.idbase_rem_galldoc' +
        '=sinfbase_obmen.id_sinfbase_obmen'
      
        'LEFT OUTER JOIN SFIRM ON rem_galldoc.idfirm_rem_galldoc = sfirm.' +
        'IDFIRM'
      
        'left outer join SSKLAD on rem_galldoc.idsklad_rem_galldoc = sskl' +
        'ad.idsklad'
      
        'left outer join SKLIENT on rem_galldoc.idklient_rem_galldoc =skl' +
        'ient.IDKLIENT'
      ''
      'where(  rem_gur_vigrt.iddoc_rem_gur_vigrt=:PARAM_IDDOC'
      
        '     ) and (     REM_GUR_VIGRT.ID_REM_GUR_VIGRT = :OLD_ID_REM_GU' +
        'R_VIGRT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_gur_vigrt.*,'
      '    sfirm.namefirm,'
      '    ssklad.namesklad,'
      '    sklient.NAMEKLIENT,'
      '    sinfbase_obmen.name_sinfbase_obmen,'
      '    rem_galldoc.prefiks_num_rem_galldoc,'
      '    rem_galldoc.pr_rem_galldoc,'
      '    rem_galldoc.num_rem_galldoc,'
      '    rem_galldoc.pos_rem_galldoc,'
      '    rem_galldoc.tdoc_rem_galldoc,'
      '    rem_doc_get_info.out_info,'
      '    rem_doc_get_info.out_idz'
      'from rem_gur_vigrt'
      
        'left outer join rem_galldoc on rem_gur_vigrt.iddocvigr_rem_gur_v' +
        'igrt=rem_galldoc.id_rem_galldoc'
      
        'left outer join SINFBASE_OBMEN on rem_galldoc.idbase_rem_galldoc' +
        '=sinfbase_obmen.id_sinfbase_obmen'
      
        'LEFT OUTER JOIN SFIRM ON rem_galldoc.idfirm_rem_galldoc = sfirm.' +
        'IDFIRM'
      
        'left outer join SSKLAD on rem_galldoc.idsklad_rem_galldoc = sskl' +
        'ad.idsklad'
      
        'left outer join SKLIENT on rem_galldoc.idklient_rem_galldoc =skl' +
        'ient.IDKLIENT'
      
        'left outer join rem_doc_get_info(rem_galldoc.id_rem_galldoc) on ' +
        'rem_doc_get_info.out_iddoc=rem_galldoc.id_rem_galldoc'
      'where rem_gur_vigrt.iddoc_rem_gur_vigrt=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_GUR_VIGRT'
    AutoUpdateOptions.KeyFields = 'ID_REM_GUR_VIGRT'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_GUR_VIGRT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnCalcFields = DocTCalcFields
    OnNewRecord = DocTNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 112
    poUseLargeIntField = True
    object DocTID_REM_GUR_VIGRT: TFIBLargeIntField
      FieldName = 'ID_REM_GUR_VIGRT'
    end
    object DocTIDBASE_REM_GUR_VIGRT: TFIBLargeIntField
      FieldName = 'IDBASE_REM_GUR_VIGRT'
    end
    object DocTIDDOC_REM_GUR_VIGRT: TFIBLargeIntField
      FieldName = 'IDDOC_REM_GUR_VIGRT'
    end
    object DocTIDDOCVIGR_REM_GUR_VIGRT: TFIBLargeIntField
      FieldName = 'IDDOCVIGR_REM_GUR_VIGRT'
    end
    object DocTNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 200
    end
    object DocTNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 200
    end
    object DocTNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 200
    end
    object DocTNAME_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 200
    end
    object DocTPREFIKS_NUM_REM_GALLDOC: TFIBWideStringField
      FieldName = 'PREFIKS_NUM_REM_GALLDOC'
      Size = 12
    end
    object DocTPR_REM_GALLDOC: TFIBSmallIntField
      FieldName = 'PR_REM_GALLDOC'
    end
    object DocTNUM_REM_GALLDOC: TFIBIntegerField
      FieldName = 'NUM_REM_GALLDOC'
    end
    object DocTPOS_REM_GALLDOC: TFIBDateTimeField
      FieldName = 'POS_REM_GALLDOC'
      DisplayFormat = 'c'
    end
    object DocTTDOC_REM_GALLDOC: TFIBWideStringField
      FieldName = 'TDOC_REM_GALLDOC'
      OnGetText = DocTTDOC_REM_GALLDOCGetText
      Size = 15
    end
    object DocTRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object DocTOUT_INFO: TFIBWideStringField
      FieldName = 'OUT_INFO'
      Size = 250
    end
    object DocTOUT_IDZ: TFIBLargeIntField
      FieldName = 'OUT_IDZ'
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
      '    select max(rem_gur_vigr.num_rem_gur_vigr) as MAXNUMBER'
      '    from rem_gur_vigr')
    Transaction = IBTr
    Left = 296
    Top = 16
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
      '')
    Left = 96
    Top = 304
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      '')
    Left = 96
    Top = 240
    qoStartTransaction = True
  end
end
