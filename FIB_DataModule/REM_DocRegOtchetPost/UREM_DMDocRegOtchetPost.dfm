object REM_DMDocRegOtchetPost: TREM_DMDocRegOtchetPost
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 369
  Width = 398
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
      '            FNAME_USER ,'
      '            NAME_SINFBASE_OBMEN,'
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from '
      '  rem_galldoc'
      'left outer join SUSER on rem_galldoc.iduser_rem_galldoc=ID_USER'
      
        'left outer join SINFBASE_OBMEN on rem_galldoc.idbase_rem_galldoc' +
        '=SINFBASE_OBMEN.id_sinfbase_obmen'
      
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
      '            FNAME_USER ,'
      '            NAME_SINFBASE_OBMEN,'
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from '
      '  rem_galldoc'
      'left outer join SUSER on rem_galldoc.iduser_rem_galldoc=ID_USER'
      
        'left outer join SINFBASE_OBMEN on rem_galldoc.idbase_rem_galldoc' +
        '=SINFBASE_OBMEN.id_sinfbase_obmen'
      
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
      Size = 15
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
    object DocAllFNAME_USER: TFIBWideStringField
      FieldName = 'FNAME_USER'
      Size = 200
    end
    object DocAllNAME_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 200
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
      'UPDATE REM_DRG_OTCHPOST'
      'SET '
      '    IDBASE_REM_DRG_OTCHPOST = :IDBASE_REM_DRG_OTCHPOST,'
      '    IDDOC_REM_DRG_OTCHPOST = :IDDOC_REM_DRG_OTCHPOST,'
      '    DESCR_REM_DRG_OTCHPOST = :DESCR_REM_DRG_OTCHPOST'
      'WHERE'
      '    ID_REM_DRG_OTCHPOST = :OLD_ID_REM_DRG_OTCHPOST'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DRG_OTCHPOST'
      'WHERE'
      '        ID_REM_DRG_OTCHPOST = :OLD_ID_REM_DRG_OTCHPOST'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DRG_OTCHPOST('
      '    ID_REM_DRG_OTCHPOST,'
      '    IDBASE_REM_DRG_OTCHPOST,'
      '    IDDOC_REM_DRG_OTCHPOST,'
      '    DESCR_REM_DRG_OTCHPOST'
      ')'
      'VALUES('
      '    :ID_REM_DRG_OTCHPOST,'
      '    :IDBASE_REM_DRG_OTCHPOST,'
      '    :IDDOC_REM_DRG_OTCHPOST,'
      '    :DESCR_REM_DRG_OTCHPOST'
      ')')
    RefreshSQL.Strings = (
      'select rem_drg_otchpost.*'
      'from  rem_drg_otchpost'
      'where(  rem_drg_otchpost.iddoc_rem_drg_otchpost=:PARAM_IDDOC'
      
        '     ) and (     REM_DRG_OTCHPOST.ID_REM_DRG_OTCHPOST = :OLD_ID_' +
        'REM_DRG_OTCHPOST'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_drg_otchpost.*'
      'from  rem_drg_otchpost'
      'where rem_drg_otchpost.iddoc_rem_drg_otchpost=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_DRG_OTCHPOST'
    AutoUpdateOptions.KeyFields = 'ID_REM_DRG_OTCHPOST'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DRG_OTCHPOST_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object DocID_REM_DRG_OTCHPOST: TFIBLargeIntField
      FieldName = 'ID_REM_DRG_OTCHPOST'
    end
    object DocIDBASE_REM_DRG_OTCHPOST: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DRG_OTCHPOST'
    end
    object DocIDDOC_REM_DRG_OTCHPOST: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DRG_OTCHPOST'
    end
    object DocDESCR_REM_DRG_OTCHPOST: TFIBWideStringField
      FieldName = 'DESCR_REM_DRG_OTCHPOST'
      Size = 150
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_DRG_OTCHPOSTT'
      'SET '
      '    IDBASE_REM_DRG_OTCHPOSTT = :IDBASE_REM_DRG_OTCHPOSTT,'
      '    IDDOC_REM_DRG_OTCHPOSTT = :IDDOC_REM_DRG_OTCHPOSTT,'
      '    TDV_REM_DRG_OTCHPOSTT = :TDV_REM_DRG_OTCHPOSTT,'
      '    IDFIRM_REM_DRG_OTCHPOSTT = :IDFIRM_REM_DRG_OTCHPOSTT,'
      '    IDSKLAD_REM_DRG_OTCHPOSTT = :IDSKLAD_REM_DRG_OTCHPOSTT,'
      '    IDPOST_REM_DRG_OTCHPOSTT = :IDPOST_REM_DRG_OTCHPOSTT,'
      '    IDDOCPOST_REM_DRG_OTCHPOSTT = :IDDOCPOST_REM_DRG_OTCHPOSTT,'
      '    IDNOM_REM_DRG_OTCHPOSTT = :IDNOM_REM_DRG_OTCHPOSTT,'
      '    KOL_REM_DRG_OTCHPOSTT = :KOL_REM_DRG_OTCHPOSTT,'
      '    SUM_REM_DRG_OTCHPOSTT = :SUM_REM_DRG_OTCHPOSTT'
      'WHERE'
      '    ID_REM_DRG_OTCHPOSTT = :OLD_ID_REM_DRG_OTCHPOSTT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DRG_OTCHPOSTT'
      'WHERE'
      '        ID_REM_DRG_OTCHPOSTT = :OLD_ID_REM_DRG_OTCHPOSTT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DRG_OTCHPOSTT('
      '    ID_REM_DRG_OTCHPOSTT,'
      '    IDBASE_REM_DRG_OTCHPOSTT,'
      '    IDDOC_REM_DRG_OTCHPOSTT,'
      '    TDV_REM_DRG_OTCHPOSTT,'
      '    IDFIRM_REM_DRG_OTCHPOSTT,'
      '    IDSKLAD_REM_DRG_OTCHPOSTT,'
      '    IDPOST_REM_DRG_OTCHPOSTT,'
      '    IDDOCPOST_REM_DRG_OTCHPOSTT,'
      '    IDNOM_REM_DRG_OTCHPOSTT,'
      '    KOL_REM_DRG_OTCHPOSTT,'
      '    SUM_REM_DRG_OTCHPOSTT'
      ')'
      'VALUES('
      '    :ID_REM_DRG_OTCHPOSTT,'
      '    :IDBASE_REM_DRG_OTCHPOSTT,'
      '    :IDDOC_REM_DRG_OTCHPOSTT,'
      '    :TDV_REM_DRG_OTCHPOSTT,'
      '    :IDFIRM_REM_DRG_OTCHPOSTT,'
      '    :IDSKLAD_REM_DRG_OTCHPOSTT,'
      '    :IDPOST_REM_DRG_OTCHPOSTT,'
      '    :IDDOCPOST_REM_DRG_OTCHPOSTT,'
      '    :IDNOM_REM_DRG_OTCHPOSTT,'
      '    :KOL_REM_DRG_OTCHPOSTT,'
      '    :SUM_REM_DRG_OTCHPOSTT'
      ')')
    RefreshSQL.Strings = (
      'select rem_drg_otchpostt.*,'
      '    sfirm.namefirm,'
      '    ssklad.namesklad,'
      '    sklient.nameklient,'
      '    snom.namenom,'
      '    snom.codenom,'
      '    snom.artnom,'
      '    rem_galldoc.prefiks_num_rem_galldoc,'
      '    rem_galldoc.num_rem_galldoc,'
      '    rem_galldoc.pos_rem_galldoc'
      'from rem_drg_otchpostt'
      
        'left outer join sfirm on rem_drg_otchpostt.idfirm_rem_drg_otchpo' +
        'stt=sfirm.idfirm'
      
        'left outer join ssklad on rem_drg_otchpostt.idsklad_rem_drg_otch' +
        'postt=ssklad.idsklad'
      
        'left outer join sklient on rem_drg_otchpostt.idpost_rem_drg_otch' +
        'postt=sklient.idklient'
      
        'left outer join rem_galldoc on rem_drg_otchpostt.iddocpost_rem_d' +
        'rg_otchpostt=rem_galldoc.id_rem_galldoc'
      
        'left outer join snom on rem_drg_otchpostt.idnom_rem_drg_otchpost' +
        't=snom.idnom'
      ''
      'where(  rem_drg_otchpostt.iddoc_rem_drg_otchpostt=:PARAM_IDDOC'
      
        '     ) and (     REM_DRG_OTCHPOSTT.ID_REM_DRG_OTCHPOSTT = :OLD_I' +
        'D_REM_DRG_OTCHPOSTT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_drg_otchpostt.*,'
      '    sfirm.namefirm,'
      '    ssklad.namesklad,'
      '    sklient.nameklient,'
      '    snom.namenom,'
      '    snom.codenom,'
      '    snom.artnom,'
      '    rem_galldoc.prefiks_num_rem_galldoc,'
      '    rem_galldoc.num_rem_galldoc,'
      '    rem_galldoc.pos_rem_galldoc'
      'from rem_drg_otchpostt'
      
        'left outer join sfirm on rem_drg_otchpostt.idfirm_rem_drg_otchpo' +
        'stt=sfirm.idfirm'
      
        'left outer join ssklad on rem_drg_otchpostt.idsklad_rem_drg_otch' +
        'postt=ssklad.idsklad'
      
        'left outer join sklient on rem_drg_otchpostt.idpost_rem_drg_otch' +
        'postt=sklient.idklient'
      
        'left outer join rem_galldoc on rem_drg_otchpostt.iddocpost_rem_d' +
        'rg_otchpostt=rem_galldoc.id_rem_galldoc'
      
        'left outer join snom on rem_drg_otchpostt.idnom_rem_drg_otchpost' +
        't=snom.idnom'
      ''
      'where rem_drg_otchpostt.iddoc_rem_drg_otchpostt=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_DRG_OTCHPOSTT'
    AutoUpdateOptions.KeyFields = 'ID_REM_DRG_OTCHPOSTT'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DRG_OTCHPOSTT_ID'
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
    object DocTID_REM_DRG_OTCHPOSTT: TFIBLargeIntField
      FieldName = 'ID_REM_DRG_OTCHPOSTT'
    end
    object DocTIDBASE_REM_DRG_OTCHPOSTT: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DRG_OTCHPOSTT'
    end
    object DocTIDDOC_REM_DRG_OTCHPOSTT: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DRG_OTCHPOSTT'
    end
    object DocTTDV_REM_DRG_OTCHPOSTT: TFIBSmallIntField
      FieldName = 'TDV_REM_DRG_OTCHPOSTT'
    end
    object DocTIDFIRM_REM_DRG_OTCHPOSTT: TFIBLargeIntField
      FieldName = 'IDFIRM_REM_DRG_OTCHPOSTT'
    end
    object DocTIDSKLAD_REM_DRG_OTCHPOSTT: TFIBLargeIntField
      FieldName = 'IDSKLAD_REM_DRG_OTCHPOSTT'
    end
    object DocTIDPOST_REM_DRG_OTCHPOSTT: TFIBLargeIntField
      FieldName = 'IDPOST_REM_DRG_OTCHPOSTT'
    end
    object DocTIDDOCPOST_REM_DRG_OTCHPOSTT: TFIBLargeIntField
      FieldName = 'IDDOCPOST_REM_DRG_OTCHPOSTT'
    end
    object DocTIDNOM_REM_DRG_OTCHPOSTT: TFIBLargeIntField
      FieldName = 'IDNOM_REM_DRG_OTCHPOSTT'
    end
    object DocTKOL_REM_DRG_OTCHPOSTT: TFIBBCDField
      FieldName = 'KOL_REM_DRG_OTCHPOSTT'
      Size = 3
      RoundByScale = True
    end
    object DocTSUM_REM_DRG_OTCHPOSTT: TFIBBCDField
      FieldName = 'SUM_REM_DRG_OTCHPOSTT'
      Size = 2
      RoundByScale = True
    end
    object DocTNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 200
    end
    object DocTNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 200
    end
    object DocTNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object DocTCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object DocTARTNOM: TFIBWideStringField
      FieldName = 'ARTNOM'
      Size = 40
    end
    object DocTPREFIKS_NUM_REM_GALLDOC: TFIBWideStringField
      FieldName = 'PREFIKS_NUM_REM_GALLDOC'
      Size = 12
    end
    object DocTNUM_REM_GALLDOC: TFIBIntegerField
      FieldName = 'NUM_REM_GALLDOC'
    end
    object DocTPOS_REM_GALLDOC: TFIBDateTimeField
      FieldName = 'POS_REM_GALLDOC'
    end
    object DocTNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
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
      'select *'
      'from REM_DOC_RGOTCHPOST_GET_NUM_DOC (:PARAM_IDBASE)')
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
      
        'EXECUTE PROCEDURE REM_DOC_RGOTCHPOST_CANCEL_DVREG(:PARAM_IDDOC,0' +
        ',0,0)')
    Left = 96
    Top = 304
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE REM_DOC_RGOTCHPOST_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 240
    qoStartTransaction = True
  end
end
