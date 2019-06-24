object REM_DMDocSetServKKT: TREM_DMDocSetServKKT
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 369
  Width = 651
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
      'UPDATE REM_DSETSERVKKT'
      'SET '
      '    IDBASE_REM_DSETSERVKKT = :IDBASE_REM_DSETSERVKKT,'
      '    IDDOC_REM_DSETSERVKKT = :IDDOC_REM_DSETSERVKKT,'
      '    TDOC_REM_DSETSERVKKT = :TDOC_REM_DSETSERVKKT,'
      '    PRIM_REM_DSETSERVKKT = :PRIM_REM_DSETSERVKKT'
      'WHERE'
      '    ID_REM_DSETSERVKKT = :OLD_ID_REM_DSETSERVKKT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DSETSERVKKT'
      'WHERE'
      '        ID_REM_DSETSERVKKT = :OLD_ID_REM_DSETSERVKKT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DSETSERVKKT('
      '    ID_REM_DSETSERVKKT,'
      '    IDBASE_REM_DSETSERVKKT,'
      '    IDDOC_REM_DSETSERVKKT,'
      '    TDOC_REM_DSETSERVKKT,'
      '    PRIM_REM_DSETSERVKKT'
      ')'
      'VALUES('
      '    :ID_REM_DSETSERVKKT,'
      '    :IDBASE_REM_DSETSERVKKT,'
      '    :IDDOC_REM_DSETSERVKKT,'
      '    :TDOC_REM_DSETSERVKKT,'
      '    :PRIM_REM_DSETSERVKKT'
      ')')
    RefreshSQL.Strings = (
      'select rem_dsetservkkt.*'
      'from  rem_dsetservkkt'
      'where(  rem_dsetservkkt.iddoc_rem_dsetservkkt=:PARAM_IDDOC'
      
        '     ) and (     REM_DSETSERVKKT.ID_REM_DSETSERVKKT = :OLD_ID_RE' +
        'M_DSETSERVKKT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_dsetservkkt.*'
      'from  rem_dsetservkkt'
      'where rem_dsetservkkt.iddoc_rem_dsetservkkt=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_DSETSERVKKT'
    AutoUpdateOptions.KeyFields = 'ID_REM_DSETSERVKKT'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DSETSERVKKT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object DocID_REM_DSETSERVKKT: TFIBLargeIntField
      FieldName = 'ID_REM_DSETSERVKKT'
    end
    object DocIDBASE_REM_DSETSERVKKT: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DSETSERVKKT'
    end
    object DocIDDOC_REM_DSETSERVKKT: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DSETSERVKKT'
    end
    object DocTDOC_REM_DSETSERVKKT: TFIBIntegerField
      FieldName = 'TDOC_REM_DSETSERVKKT'
    end
    object DocPRIM_REM_DSETSERVKKT: TFIBWideStringField
      FieldName = 'PRIM_REM_DSETSERVKKT'
      Size = 100
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_DSETSERVKKTT'
      'SET '
      '    IDBASE_REM_DSETSERVKKTT = :IDBASE_REM_DSETSERVKKTT,'
      '    IDDOC_REM_DSETSERVKKTT = :IDDOC_REM_DSETSERVKKTT,'
      '    IDKKT_REM_DSETSERVKKTT = :IDKKT_REM_DSETSERVKKTT,'
      '    SUM_REM_DSETSERVKKTT = :SUM_REM_DSETSERVKKTT'
      'WHERE'
      '    ID_REM_DSETSERVKKTT = :OLD_ID_REM_DSETSERVKKTT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DSETSERVKKTT'
      'WHERE'
      '        ID_REM_DSETSERVKKTT = :OLD_ID_REM_DSETSERVKKTT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DSETSERVKKTT('
      '    ID_REM_DSETSERVKKTT,'
      '    IDBASE_REM_DSETSERVKKTT,'
      '    IDDOC_REM_DSETSERVKKTT,'
      '    IDKKT_REM_DSETSERVKKTT,'
      '    SUM_REM_DSETSERVKKTT'
      ')'
      'VALUES('
      '    :ID_REM_DSETSERVKKTT,'
      '    :IDBASE_REM_DSETSERVKKTT,'
      '    :IDDOC_REM_DSETSERVKKTT,'
      '    :IDKKT_REM_DSETSERVKKTT,'
      '    :SUM_REM_DSETSERVKKTT'
      ')')
    RefreshSQL.Strings = (
      'select rem_dsetservkktt.*,'
      '    rem_skkt.name_rem_skkt'
      'from  rem_dsetservkktt'
      
        'left outer join rem_skkt on rem_dsetservkktt.idkkt_rem_dsetservk' +
        'ktt=rem_skkt.id_rem_skkt'
      'where(  rem_dsetservkktt.iddoc_rem_dsetservkktt=:PARAM_IDDOC'
      
        '     ) and (     REM_DSETSERVKKTT.ID_REM_DSETSERVKKTT = :OLD_ID_' +
        'REM_DSETSERVKKTT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_dsetservkktt.*,'
      '    rem_skkt.name_rem_skkt'
      'from  rem_dsetservkktt'
      
        'left outer join rem_skkt on rem_dsetservkktt.idkkt_rem_dsetservk' +
        'ktt=rem_skkt.id_rem_skkt'
      'where rem_dsetservkktt.iddoc_rem_dsetservkktt=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_DSETSERVKKTT'
    AutoUpdateOptions.KeyFields = 'ID_REM_DSETSERVKKTT'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DSETSERVKKTT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
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
    object DocTID_REM_DSETSERVKKTT: TFIBLargeIntField
      FieldName = 'ID_REM_DSETSERVKKTT'
    end
    object DocTIDBASE_REM_DSETSERVKKTT: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DSETSERVKKTT'
    end
    object DocTIDDOC_REM_DSETSERVKKTT: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DSETSERVKKTT'
    end
    object DocTIDKKT_REM_DSETSERVKKTT: TFIBLargeIntField
      FieldName = 'IDKKT_REM_DSETSERVKKTT'
    end
    object DocTSUM_REM_DSETSERVKKTT: TFIBBCDField
      FieldName = 'SUM_REM_DSETSERVKKTT'
      Size = 3
      RoundByScale = True
    end
    object DocTNAME_REM_SKKT: TFIBWideStringField
      FieldName = 'NAME_REM_SKKT'
      Size = 100
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
      
        'where TDOC_REM_GALLDOC='#39'SETSERVKKT'#39' and POS_REM_GALLDOC > :PARAM' +
        '_POS')
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
      
        'EXECUTE PROCEDURE REM_DOC_SETSERVKKT_CANCEL_DVREG(:PARAM_IDDOC,0' +
        ',0,0)')
    Left = 96
    Top = 304
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE REM_DOC_SETSERVKKT_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 240
    qoStartTransaction = True
  end
end
