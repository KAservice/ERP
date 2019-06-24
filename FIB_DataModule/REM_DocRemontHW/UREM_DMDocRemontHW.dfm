object REM_DMDocRemontHW: TREM_DMDocRemontHW
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 369
  Width = 615
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
      DisplayFormat = 'c'
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
      'UPDATE REM_DREMONTHW'
      'SET '
      '    IDDOC_REM_DREMONTHW = :IDDOC_REM_DREMONTHW,'
      '    PRIM_REM_DREMONTHW = :PRIM_REM_DREMONTHW,'
      '    IDHW_REM_DREMONTHW = :IDHW_REM_DREMONTHW,'
      '    IDBASE_REM_DREMONTHW = :IDBASE_REM_DREMONTHW,'
      '    IDTPRICE_REM_DREMONTHW = :IDTPRICE_REM_DREMONTHW,'
      '    NEISPR_REM_DREMONTHW = :NEISPR_REM_DREMONTHW'
      'WHERE'
      '    ID_REM_DREMONTHW = :OLD_ID_REM_DREMONTHW'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DREMONTHW'
      'WHERE'
      '        ID_REM_DREMONTHW = :OLD_ID_REM_DREMONTHW'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DREMONTHW('
      '    ID_REM_DREMONTHW,'
      '    IDDOC_REM_DREMONTHW,'
      '    PRIM_REM_DREMONTHW,'
      '    IDHW_REM_DREMONTHW,'
      '    IDBASE_REM_DREMONTHW,'
      '    IDTPRICE_REM_DREMONTHW,'
      '    NEISPR_REM_DREMONTHW'
      ')'
      'VALUES('
      '    :ID_REM_DREMONTHW,'
      '    :IDDOC_REM_DREMONTHW,'
      '    :PRIM_REM_DREMONTHW,'
      '    :IDHW_REM_DREMONTHW,'
      '    :IDBASE_REM_DREMONTHW,'
      '    :IDTPRICE_REM_DREMONTHW,'
      '    :NEISPR_REM_DREMONTHW'
      ')')
    RefreshSQL.Strings = (
      'select rem_dremonthw.*, rem_shardware.name_rem_shardware'
      'from  rem_dremonthw'
      
        'left outer join rem_shardware on rem_dremonthw.idhw_rem_dremonth' +
        'w=rem_shardware.id_rem_shardware'
      'where(  rem_dremonthw.iddoc_rem_dremonthw=:PARAM_IDDOC'
      
        '     ) and (     REM_DREMONTHW.ID_REM_DREMONTHW = :OLD_ID_REM_DR' +
        'EMONTHW'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_dremonthw.*, rem_shardware.name_rem_shardware'
      'from  rem_dremonthw'
      
        'left outer join rem_shardware on rem_dremonthw.idhw_rem_dremonth' +
        'w=rem_shardware.id_rem_shardware'
      'where rem_dremonthw.iddoc_rem_dremonthw=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_DREMONTHW'
    AutoUpdateOptions.KeyFields = 'ID_REM_DREMONTHW'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DREMONTHW_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object DocID_REM_DREMONTHW: TFIBLargeIntField
      FieldName = 'ID_REM_DREMONTHW'
    end
    object DocIDDOC_REM_DREMONTHW: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DREMONTHW'
    end
    object DocPRIM_REM_DREMONTHW: TFIBWideStringField
      FieldName = 'PRIM_REM_DREMONTHW'
      Size = 100
    end
    object DocIDHW_REM_DREMONTHW: TFIBLargeIntField
      FieldName = 'IDHW_REM_DREMONTHW'
    end
    object DocIDBASE_REM_DREMONTHW: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DREMONTHW'
    end
    object DocIDTPRICE_REM_DREMONTHW: TFIBLargeIntField
      FieldName = 'IDTPRICE_REM_DREMONTHW'
    end
    object DocNAME_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'NAME_REM_SHARDWARE'
      Size = 200
    end
    object DocNEISPR_REM_DREMONTHW: TFIBWideStringField
      FieldName = 'NEISPR_REM_DREMONTHW'
      Size = 150
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_DREMONTHWT'
      'SET '
      '    IDDOC_REM_DREMONTHWT = :IDDOC_REM_DREMONTHWT,'
      '    IDBASE_REM_DREMONTHWT = :IDBASE_REM_DREMONTHWT,'
      '    IDNOM_REM_DREMONTHWT = :IDNOM_REM_DREMONTHWT,'
      '    IDED_REM_DREMONTHWT = :IDED_REM_DREMONTHWT,'
      '    KOL_REM_DREMONTHWT = :KOL_REM_DREMONTHWT,'
      '    KF_REM_DREMONTHWT = :KF_REM_DREMONTHWT,'
      '    PRICE_REM_DREMONTHWT = :PRICE_REM_DREMONTHWT,'
      '    SUM_REM_DREMONTHWT = :SUM_REM_DREMONTHWT,'
      '    PRICEMEX_REM_DREMONTHWT = :PRICEMEX_REM_DREMONTHWT,'
      '    SUMMEX_REM_DREMONTHWT = :SUMMEX_REM_DREMONTHWT,'
      '    IDHW_REM_DREMONTHWT = :IDHW_REM_DREMONTHWT,'
      '    DVREG_REM_DREMONTHWT = :DVREG_REM_DREMONTHWT'
      'WHERE'
      '    ID_REM_DREMONTHWT = :OLD_ID_REM_DREMONTHWT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DREMONTHWT'
      'WHERE'
      '        ID_REM_DREMONTHWT = :OLD_ID_REM_DREMONTHWT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DREMONTHWT('
      '    ID_REM_DREMONTHWT,'
      '    IDDOC_REM_DREMONTHWT,'
      '    IDBASE_REM_DREMONTHWT,'
      '    IDNOM_REM_DREMONTHWT,'
      '    IDED_REM_DREMONTHWT,'
      '    KOL_REM_DREMONTHWT,'
      '    KF_REM_DREMONTHWT,'
      '    PRICE_REM_DREMONTHWT,'
      '    SUM_REM_DREMONTHWT,'
      '    PRICEMEX_REM_DREMONTHWT,'
      '    SUMMEX_REM_DREMONTHWT,'
      '    IDHW_REM_DREMONTHWT,'
      '    DVREG_REM_DREMONTHWT'
      ')'
      'VALUES('
      '    :ID_REM_DREMONTHWT,'
      '    :IDDOC_REM_DREMONTHWT,'
      '    :IDBASE_REM_DREMONTHWT,'
      '    :IDNOM_REM_DREMONTHWT,'
      '    :IDED_REM_DREMONTHWT,'
      '    :KOL_REM_DREMONTHWT,'
      '    :KF_REM_DREMONTHWT,'
      '    :PRICE_REM_DREMONTHWT,'
      '    :SUM_REM_DREMONTHWT,'
      '    :PRICEMEX_REM_DREMONTHWT,'
      '    :SUMMEX_REM_DREMONTHWT,'
      '    :IDHW_REM_DREMONTHWT,'
      '    :DVREG_REM_DREMONTHWT'
      ')')
    RefreshSQL.Strings = (
      'select rem_dremonthwt.*,'
      ' snom.namenom,'
      ' snom.codenom,'
      ' snom.artnom,'
      ' sed.nameed,'
      ' sed.shed,'
      ' rem_shardware.name_rem_shardware,'
      ' rem_shardware.code_rem_shardware,'
      ' rem_shardware.sernum_rem_shardware '
      'from  rem_dremonthwt'
      
        'left outer join snom on rem_dremonthwt.idnom_rem_dremonthwt=snom' +
        '.idnom'
      
        'left outer join sed on rem_dremonthwt.ided_rem_dremonthwt=sed.id' +
        'ed'
      
        'left outer join rem_shardware on rem_dremonthwt.idhw_rem_dremont' +
        'hwt=rem_shardware.id_rem_shardware'
      'where(  rem_dremonthwt.iddoc_rem_dremonthwt=:PARAM_IDDOC'
      
        '     ) and (     REM_DREMONTHWT.ID_REM_DREMONTHWT = :OLD_ID_REM_' +
        'DREMONTHWT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_dremonthwt.*,'
      ' snom.namenom,'
      ' snom.codenom,'
      ' snom.artnom,'
      ' sed.nameed,'
      ' sed.shed,'
      ' rem_shardware.name_rem_shardware,'
      ' rem_shardware.code_rem_shardware,'
      ' rem_shardware.sernum_rem_shardware '
      'from  rem_dremonthwt'
      
        'left outer join snom on rem_dremonthwt.idnom_rem_dremonthwt=snom' +
        '.idnom'
      
        'left outer join sed on rem_dremonthwt.ided_rem_dremonthwt=sed.id' +
        'ed'
      
        'left outer join rem_shardware on rem_dremonthwt.idhw_rem_dremont' +
        'hwt=rem_shardware.id_rem_shardware'
      'where rem_dremonthwt.iddoc_rem_dremonthwt=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_DREMONTHWT'
    AutoUpdateOptions.KeyFields = 'ID_REM_DREMONTHWT'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DREMONTHWT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    AfterDelete = DocTAfterDelete
    BeforeDelete = DocTBeforeDelete
    OnCalcFields = DocTCalcFields
    OnNewRecord = DocTNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 112
    poUseLargeIntField = True
    object DocTKOL_REM_DREMONTHWT: TFIBBCDField
      FieldName = 'KOL_REM_DREMONTHWT'
      OnChange = DocTKOL_REM_DREMONTHWTChange
      Size = 3
      RoundByScale = True
    end
    object DocTKF_REM_DREMONTHWT: TFIBBCDField
      FieldName = 'KF_REM_DREMONTHWT'
      Size = 3
      RoundByScale = True
    end
    object DocTPRICE_REM_DREMONTHWT: TFIBBCDField
      FieldName = 'PRICE_REM_DREMONTHWT'
      OnChange = DocTPRICE_REM_DREMONTHWTChange
      Size = 2
      RoundByScale = True
    end
    object DocTSUM_REM_DREMONTHWT: TFIBBCDField
      FieldName = 'SUM_REM_DREMONTHWT'
      Size = 2
      RoundByScale = True
    end
    object DocTPRICEMEX_REM_DREMONTHWT: TFIBBCDField
      FieldName = 'PRICEMEX_REM_DREMONTHWT'
      Size = 2
      RoundByScale = True
    end
    object DocTSUMMEX_REM_DREMONTHWT: TFIBBCDField
      FieldName = 'SUMMEX_REM_DREMONTHWT'
      Size = 2
      RoundByScale = True
    end
    object DocTRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object DocTID_REM_DREMONTHWT: TFIBLargeIntField
      FieldName = 'ID_REM_DREMONTHWT'
    end
    object DocTIDDOC_REM_DREMONTHWT: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DREMONTHWT'
    end
    object DocTIDBASE_REM_DREMONTHWT: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DREMONTHWT'
    end
    object DocTIDNOM_REM_DREMONTHWT: TFIBLargeIntField
      FieldName = 'IDNOM_REM_DREMONTHWT'
    end
    object DocTIDED_REM_DREMONTHWT: TFIBLargeIntField
      FieldName = 'IDED_REM_DREMONTHWT'
    end
    object DocTNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object DocTNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 200
    end
    object DocTIDHW_REM_DREMONTHWT: TFIBLargeIntField
      FieldName = 'IDHW_REM_DREMONTHWT'
    end
    object DocTDVREG_REM_DREMONTHWT: TFIBSmallIntField
      FieldName = 'DVREG_REM_DREMONTHWT'
    end
    object DocTCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object DocTARTNOM: TFIBWideStringField
      FieldName = 'ARTNOM'
    end
    object DocTSHED: TFIBWideStringField
      FieldName = 'SHED'
      Size = 13
    end
    object DocTNAME_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'NAME_REM_SHARDWARE'
      Size = 200
    end
    object DocTCODE_REM_SHARDWARE: TFIBIntegerField
      FieldName = 'CODE_REM_SHARDWARE'
    end
    object DocTSERNUM_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'SERNUM_REM_SHARDWARE'
      Size = 50
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
      
        'where TDOC_REM_GALLDOC='#39'REMONTHW'#39' and POS_REM_GALLDOC > :PARAM_P' +
        'OS')
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
      
        'EXECUTE PROCEDURE REM_DOC_REMONTHW_CANCEL_DVREG(:PARAM_IDDOC,0,0' +
        ',0)')
    Left = 96
    Top = 304
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE REM_DOC_REMONTHW_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 240
    qoStartTransaction = True
  end
end
