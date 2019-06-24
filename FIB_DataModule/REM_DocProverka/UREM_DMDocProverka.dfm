object REM_DMDocProverka: TREM_DMDocProverka
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 439
  Width = 667
  object DataSourceDocAll: TDataSource
    DataSet = DocAll
    Left = 72
    Top = 16
  end
  object DocAll: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_GUR_PROV'
      'SET '
      '    IDBASE_REM_GUR_PROV = :IDBASE_REM_GUR_PROV,'
      '    POS_REM_GUR_PROV = :POS_REM_GUR_PROV,'
      '    NUM_REM_GUR_PROV = :NUM_REM_GUR_PROV,'
      '    DESCR_REM_GUR_PROV = :DESCR_REM_GUR_PROV,'
      '    IDDOC_REM_GUR_PROV = :IDDOC_REM_GUR_PROV,'
      '    IDUSER_REM_GUR_PROV = :IDUSER_REM_GUR_PROV,'
      '    RES_REM_GUR_PROV = :RES_REM_GUR_PROV'
      'WHERE'
      '    ID_REM_GUR_PROV = :OLD_ID_REM_GUR_PROV'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_GUR_PROV'
      'WHERE'
      '        ID_REM_GUR_PROV = :OLD_ID_REM_GUR_PROV'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_GUR_PROV('
      '    ID_REM_GUR_PROV,'
      '    IDBASE_REM_GUR_PROV,'
      '    POS_REM_GUR_PROV,'
      '    NUM_REM_GUR_PROV,'
      '    DESCR_REM_GUR_PROV,'
      '    IDDOC_REM_GUR_PROV,'
      '    IDUSER_REM_GUR_PROV,'
      '    RES_REM_GUR_PROV'
      ')'
      'VALUES('
      '    :ID_REM_GUR_PROV,'
      '    :IDBASE_REM_GUR_PROV,'
      '    :POS_REM_GUR_PROV,'
      '    :NUM_REM_GUR_PROV,'
      '    :DESCR_REM_GUR_PROV,'
      '    :IDDOC_REM_GUR_PROV,'
      '    :IDUSER_REM_GUR_PROV,'
      '    :RES_REM_GUR_PROV'
      ')')
    RefreshSQL.Strings = (
      'select '
      '    rem_gur_prov.*,'
      '    sfirm.namefirm,'
      '    ssklad.namesklad,'
      '    sklient.NAMEKLIENT,'
      '    USER_DOC.NAME_USER as NAME_USER_DOC,'
      '    USER_PROV.NAME_USER as NAME_USER_PROV,'
      '    sinfbase_obmen.name_sinfbase_obmen,'
      '    rem_galldoc.prefiks_num_rem_galldoc,'
      '    rem_galldoc.pr_rem_galldoc,'
      '    rem_galldoc.num_rem_galldoc,'
      '    rem_galldoc.pos_rem_galldoc,'
      '    rem_galldoc.tdoc_rem_galldoc'
      ''
      'from   rem_gur_prov'
      
        'left outer join rem_galldoc on rem_gur_prov.iddoc_rem_gur_prov=r' +
        'em_galldoc.id_rem_galldoc'
      
        'left outer join SINFBASE_OBMEN on rem_galldoc.idbase_rem_galldoc' +
        '=sinfbase_obmen.id_sinfbase_obmen'
      
        'LEFT OUTER JOIN SFIRM ON rem_galldoc.idfirm_rem_galldoc = sfirm.' +
        'IDFIRM'
      
        'left outer join SSKLAD on rem_galldoc.idsklad_rem_galldoc = sskl' +
        'ad.idsklad'
      
        'left outer join SKLIENT on rem_galldoc.idklient_rem_galldoc =skl' +
        'ient.IDKLIENT'
      
        'left outer join SUSER as USER_DOC on  rem_galldoc.iduser_rem_gal' +
        'ldoc = USER_DOC.ID_USER'
      
        'left outer join SUSER as USER_PROV on  rem_gur_prov.iduser_rem_g' +
        'ur_prov = USER_PROV.ID_USER'
      'where(  rem_gur_prov.id_rem_gur_prov=:PARAM_IDDOC'
      
        '     ) and (     REM_GUR_PROV.ID_REM_GUR_PROV = :OLD_ID_REM_GUR_' +
        'PROV'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select '
      '    rem_gur_prov.*,'
      '    sfirm.namefirm,'
      '    ssklad.namesklad,'
      '    sklient.NAMEKLIENT,'
      '    USER_DOC.NAME_USER as NAME_USER_DOC,'
      '    USER_PROV.NAME_USER as NAME_USER_PROV,'
      '    sinfbase_obmen.name_sinfbase_obmen,'
      '    rem_galldoc.prefiks_num_rem_galldoc,'
      '    rem_galldoc.pr_rem_galldoc,'
      '    rem_galldoc.num_rem_galldoc,'
      '    rem_galldoc.pos_rem_galldoc,'
      '    rem_galldoc.tdoc_rem_galldoc'
      ''
      'from   rem_gur_prov'
      
        'left outer join rem_galldoc on rem_gur_prov.iddoc_rem_gur_prov=r' +
        'em_galldoc.id_rem_galldoc'
      
        'left outer join SINFBASE_OBMEN on rem_galldoc.idbase_rem_galldoc' +
        '=sinfbase_obmen.id_sinfbase_obmen'
      
        'LEFT OUTER JOIN SFIRM ON rem_galldoc.idfirm_rem_galldoc = sfirm.' +
        'IDFIRM'
      
        'left outer join SSKLAD on rem_galldoc.idsklad_rem_galldoc = sskl' +
        'ad.idsklad'
      
        'left outer join SKLIENT on rem_galldoc.idklient_rem_galldoc =skl' +
        'ient.IDKLIENT'
      
        'left outer join SUSER as USER_DOC on  rem_galldoc.iduser_rem_gal' +
        'ldoc = USER_DOC.ID_USER'
      
        'left outer join SUSER as USER_PROV on  rem_gur_prov.iduser_rem_g' +
        'ur_prov = USER_PROV.ID_USER'
      'where rem_gur_prov.id_rem_gur_prov=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_GUR_PROV'
    AutoUpdateOptions.KeyFields = 'ID_REM_GUR_PROV'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_GUR_PROV_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object DocAllID_REM_GUR_PROV: TFIBLargeIntField
      FieldName = 'ID_REM_GUR_PROV'
    end
    object DocAllIDBASE_REM_GUR_PROV: TFIBLargeIntField
      FieldName = 'IDBASE_REM_GUR_PROV'
    end
    object DocAllPOS_REM_GUR_PROV: TFIBDateTimeField
      FieldName = 'POS_REM_GUR_PROV'
    end
    object DocAllNUM_REM_GUR_PROV: TFIBIntegerField
      FieldName = 'NUM_REM_GUR_PROV'
    end
    object DocAllDESCR_REM_GUR_PROV: TFIBWideStringField
      FieldName = 'DESCR_REM_GUR_PROV'
      Size = 150
    end
    object DocAllIDDOC_REM_GUR_PROV: TFIBLargeIntField
      FieldName = 'IDDOC_REM_GUR_PROV'
    end
    object DocAllIDUSER_REM_GUR_PROV: TFIBLargeIntField
      FieldName = 'IDUSER_REM_GUR_PROV'
    end
    object DocAllRES_REM_GUR_PROV: TFIBIntegerField
      FieldName = 'RES_REM_GUR_PROV'
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
    object DocAllNAME_USER_DOC: TFIBWideStringField
      FieldName = 'NAME_USER_DOC'
      Size = 200
    end
    object DocAllNAME_USER_PROV: TFIBWideStringField
      FieldName = 'NAME_USER_PROV'
      Size = 200
    end
    object DocAllNAME_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 200
    end
    object DocAllPREFIKS_NUM_REM_GALLDOC: TFIBWideStringField
      FieldName = 'PREFIKS_NUM_REM_GALLDOC'
      Size = 12
    end
    object DocAllPR_REM_GALLDOC: TFIBSmallIntField
      FieldName = 'PR_REM_GALLDOC'
    end
    object DocAllNUM_REM_GALLDOC: TFIBIntegerField
      FieldName = 'NUM_REM_GALLDOC'
    end
    object DocAllPOS_REM_GALLDOC: TFIBDateTimeField
      FieldName = 'POS_REM_GALLDOC'
    end
    object DocAllTDOC_REM_GALLDOC: TFIBWideStringField
      FieldName = 'TDOC_REM_GALLDOC'
      OnGetText = DocAllTDOC_REM_GALLDOCGetText
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
    Left = 240
    Top = 16
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
      '    select max(rem_gur_prov.num_rem_gur_prov) as MAXNUMBER'
      '    from rem_gur_prov')
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
  object IBTrUpdate: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 240
    Top = 88
  end
end
