object REM_DMDocVosvratPok: TREM_DMDocVosvratPok
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 453
  Width = 686
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
      '  rem_galldoc.id_rem_galldoc=:PARAM_ID'
      
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
      '  rem_galldoc.id_rem_galldoc=:PARAM_ID')
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
      OnChange = DocAllIDSKLAD_REM_GALLDOCChange
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
    object DocAllIDPROJECT_REM_GALLDOC: TFIBLargeIntField
      FieldName = 'IDPROJECT_REM_GALLDOC'
    end
    object DocAllIDBUSINOP_REM_GALLDOC: TFIBLargeIntField
      FieldName = 'IDBUSINOP_REM_GALLDOC'
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
    object DocAllNAME_SPROJECT: TFIBWideStringField
      FieldName = 'NAME_SPROJECT'
      Size = 200
    end
    object DocAllNAME_SBUSINESS_OPER: TFIBWideStringField
      FieldName = 'NAME_SBUSINESS_OPER'
      Size = 200
    end
    object DocAllPREFIKS_NUM_REM_GALLDOC: TFIBWideStringField
      FieldName = 'PREFIKS_NUM_REM_GALLDOC'
      Size = 12
    end
  end
  object Doc: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_DVPOK'
      'SET '
      '    IDBASE_REM_DVPOK = :IDBASE_REM_DVPOK,'
      '    GID_REM_DVPOK = :GID_REM_DVPOK,'
      '    IDDOC_REM_DVPOK = :IDDOC_REM_DVPOK,'
      '    IDTYPEPRICE_REM_DVPOK = :IDTYPEPRICE_REM_DVPOK,'
      '    IDRTYPEPRICE_REM_DVPOK = :IDRTYPEPRICE_REM_DVPOK,'
      '    IDCARD_REM_DVPOK = :IDCARD_REM_DVPOK,'
      '    KLIENT_NAME_REM_DVPOK = :KLIENT_NAME_REM_DVPOK,'
      '    KLIENT_ADR_REM_DVPOK = :KLIENT_ADR_REM_DVPOK,'
      '    KLIENT_PHONE_REM_DVPOK = :KLIENT_PHONE_REM_DVPOK,'
      '    KLIENT_PASSPORT_REM_DVPOK = :KLIENT_PASSPORT_REM_DVPOK,'
      '    PRICHINA_REM_DVPOK = :PRICHINA_REM_DVPOK,'
      '    DESCR_REM_DVPOK = :DESCR_REM_DVPOK,'
      '    NUMDOCSALE_REM_DVPOK = :NUMDOCSALE_REM_DVPOK,'
      '    POSDOCSALE_REM_DVPOK = :POSDOCSALE_REM_DVPOK,'
      '    NUMDOCKL_REM_DVPOK = :NUMDOCKL_REM_DVPOK,'
      '    POSDOCKL_REM_DVPOK = :POSDOCKL_REM_DVPOK'
      'WHERE'
      '    ID_REM_DVPOK = :OLD_ID_REM_DVPOK'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DVPOK'
      'WHERE'
      '        ID_REM_DVPOK = :OLD_ID_REM_DVPOK'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DVPOK('
      '    ID_REM_DVPOK,'
      '    IDBASE_REM_DVPOK,'
      '    GID_REM_DVPOK,'
      '    IDDOC_REM_DVPOK,'
      '    IDTYPEPRICE_REM_DVPOK,'
      '    IDRTYPEPRICE_REM_DVPOK,'
      '    IDCARD_REM_DVPOK,'
      '    KLIENT_NAME_REM_DVPOK,'
      '    KLIENT_ADR_REM_DVPOK,'
      '    KLIENT_PHONE_REM_DVPOK,'
      '    KLIENT_PASSPORT_REM_DVPOK,'
      '    PRICHINA_REM_DVPOK,'
      '    DESCR_REM_DVPOK,'
      '    NUMDOCSALE_REM_DVPOK,'
      '    POSDOCSALE_REM_DVPOK,'
      '    NUMDOCKL_REM_DVPOK,'
      '    POSDOCKL_REM_DVPOK'
      ')'
      'VALUES('
      '    :ID_REM_DVPOK,'
      '    :IDBASE_REM_DVPOK,'
      '    :GID_REM_DVPOK,'
      '    :IDDOC_REM_DVPOK,'
      '    :IDTYPEPRICE_REM_DVPOK,'
      '    :IDRTYPEPRICE_REM_DVPOK,'
      '    :IDCARD_REM_DVPOK,'
      '    :KLIENT_NAME_REM_DVPOK,'
      '    :KLIENT_ADR_REM_DVPOK,'
      '    :KLIENT_PHONE_REM_DVPOK,'
      '    :KLIENT_PASSPORT_REM_DVPOK,'
      '    :PRICHINA_REM_DVPOK,'
      '    :DESCR_REM_DVPOK,'
      '    :NUMDOCSALE_REM_DVPOK,'
      '    :POSDOCSALE_REM_DVPOK,'
      '    :NUMDOCKL_REM_DVPOK,'
      '    :POSDOCKL_REM_DVPOK'
      ')')
    RefreshSQL.Strings = (
      'select rem_dvpok.*,'
      '        sdiscount_card.name_sdiscount_card'
      'from  rem_dvpok'
      
        'left outer join sdiscount_card on rem_dvpok.idcard_rem_dvpok=sdi' +
        'scount_card.id_sdiscount_card'
      'where(  rem_dvpok.iddoc_rem_dvpok=:PARAM_IDDOC'
      '     ) and (     REM_DVPOK.ID_REM_DVPOK = :OLD_ID_REM_DVPOK'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_dvpok.*,'
      '        sdiscount_card.name_sdiscount_card'
      'from  rem_dvpok'
      
        'left outer join sdiscount_card on rem_dvpok.idcard_rem_dvpok=sdi' +
        'scount_card.id_sdiscount_card'
      'where rem_dvpok.iddoc_rem_dvpok=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_DVPOK'
    AutoUpdateOptions.KeyFields = 'ID_REM_DVPOK'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DVPOK_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object DocID_REM_DVPOK: TFIBLargeIntField
      FieldName = 'ID_REM_DVPOK'
    end
    object DocIDBASE_REM_DVPOK: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DVPOK'
    end
    object DocGID_REM_DVPOK: TFIBWideStringField
      FieldName = 'GID_REM_DVPOK'
      Size = 10
    end
    object DocIDDOC_REM_DVPOK: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DVPOK'
    end
    object DocIDTYPEPRICE_REM_DVPOK: TFIBLargeIntField
      FieldName = 'IDTYPEPRICE_REM_DVPOK'
    end
    object DocIDRTYPEPRICE_REM_DVPOK: TFIBLargeIntField
      FieldName = 'IDRTYPEPRICE_REM_DVPOK'
    end
    object DocIDCARD_REM_DVPOK: TFIBLargeIntField
      FieldName = 'IDCARD_REM_DVPOK'
    end
    object DocKLIENT_NAME_REM_DVPOK: TFIBWideStringField
      FieldName = 'KLIENT_NAME_REM_DVPOK'
      Size = 200
    end
    object DocKLIENT_ADR_REM_DVPOK: TFIBWideStringField
      FieldName = 'KLIENT_ADR_REM_DVPOK'
      Size = 200
    end
    object DocKLIENT_PHONE_REM_DVPOK: TFIBWideStringField
      FieldName = 'KLIENT_PHONE_REM_DVPOK'
      Size = 200
    end
    object DocKLIENT_PASSPORT_REM_DVPOK: TFIBWideStringField
      FieldName = 'KLIENT_PASSPORT_REM_DVPOK'
      Size = 200
    end
    object DocPRICHINA_REM_DVPOK: TFIBWideStringField
      FieldName = 'PRICHINA_REM_DVPOK'
      Size = 200
    end
    object DocDESCR_REM_DVPOK: TFIBWideStringField
      FieldName = 'DESCR_REM_DVPOK'
      Size = 150
    end
    object DocNUMDOCSALE_REM_DVPOK: TFIBWideStringField
      FieldName = 'NUMDOCSALE_REM_DVPOK'
    end
    object DocPOSDOCSALE_REM_DVPOK: TFIBDateTimeField
      FieldName = 'POSDOCSALE_REM_DVPOK'
    end
    object DocNUMDOCKL_REM_DVPOK: TFIBWideStringField
      FieldName = 'NUMDOCKL_REM_DVPOK'
    end
    object DocPOSDOCKL_REM_DVPOK: TFIBDateTimeField
      FieldName = 'POSDOCKL_REM_DVPOK'
    end
    object DocNAME_SDISCOUNT_CARD: TFIBWideStringField
      FieldName = 'NAME_SDISCOUNT_CARD'
      Size = 200
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_DVPOKT'
      'SET '
      '    IDBASE_REM_DVPOKT = :IDBASE_REM_DVPOKT,'
      '    GID_REM_DVPOKT = :GID_REM_DVPOKT,'
      '    IDDOC_REM_DVPOKT = :IDDOC_REM_DVPOKT,'
      '    IDNOM_REM_DVPOKT = :IDNOM_REM_DVPOKT,'
      '    IDED_REM_DVPOKT = :IDED_REM_DVPOKT,'
      '    IDHW_REM_DVPOKT = :IDHW_REM_DVPOKT,'
      '    DVREG_REM_DVPOKT = :DVREG_REM_DVPOKT,'
      '    KOL_REM_DVPOKT = :KOL_REM_DVPOKT,'
      '    KF_REM_DVPOKT = :KF_REM_DVPOKT,'
      '    PRICE_REM_DVPOKT = :PRICE_REM_DVPOKT,'
      '    SUM_REM_DVPOKT = :SUM_REM_DVPOKT,'
      '    NDS_REM_DVPOKT = :NDS_REM_DVPOKT,'
      '    SUMNDS_REM_DVPOKT = :SUMNDS_REM_DVPOKT,'
      '    PRSK_REM_DVPOKT = :PRSK_REM_DVPOKT,'
      '    SUMSK_REM_DVPOKT = :SUMSK_REM_DVPOKT,'
      '    PRSK_CARD_REM_DVPOKT = :PRSK_CARD_REM_DVPOKT,'
      '    PRSK_AUTO_REM_DVPOKT = :PRSK_AUTO_REM_DVPOKT,'
      '    PRSK_HAND_REM_DVPOKT = :PRSK_HAND_REM_DVPOKT,'
      '    NO_SK_REM_DVPOKT = :NO_SK_REM_DVPOKT'
      'WHERE'
      '    ID_REM_DVPOKT = :OLD_ID_REM_DVPOKT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DVPOKT'
      'WHERE'
      '        ID_REM_DVPOKT = :OLD_ID_REM_DVPOKT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DVPOKT('
      '    ID_REM_DVPOKT,'
      '    IDBASE_REM_DVPOKT,'
      '    GID_REM_DVPOKT,'
      '    IDDOC_REM_DVPOKT,'
      '    IDNOM_REM_DVPOKT,'
      '    IDED_REM_DVPOKT,'
      '    IDHW_REM_DVPOKT,'
      '    DVREG_REM_DVPOKT,'
      '    KOL_REM_DVPOKT,'
      '    KF_REM_DVPOKT,'
      '    PRICE_REM_DVPOKT,'
      '    SUM_REM_DVPOKT,'
      '    NDS_REM_DVPOKT,'
      '    SUMNDS_REM_DVPOKT,'
      '    PRSK_REM_DVPOKT,'
      '    SUMSK_REM_DVPOKT,'
      '    PRSK_CARD_REM_DVPOKT,'
      '    PRSK_AUTO_REM_DVPOKT,'
      '    PRSK_HAND_REM_DVPOKT,'
      '    NO_SK_REM_DVPOKT'
      ')'
      'VALUES('
      '    :ID_REM_DVPOKT,'
      '    :IDBASE_REM_DVPOKT,'
      '    :GID_REM_DVPOKT,'
      '    :IDDOC_REM_DVPOKT,'
      '    :IDNOM_REM_DVPOKT,'
      '    :IDED_REM_DVPOKT,'
      '    :IDHW_REM_DVPOKT,'
      '    :DVREG_REM_DVPOKT,'
      '    :KOL_REM_DVPOKT,'
      '    :KF_REM_DVPOKT,'
      '    :PRICE_REM_DVPOKT,'
      '    :SUM_REM_DVPOKT,'
      '    :NDS_REM_DVPOKT,'
      '    :SUMNDS_REM_DVPOKT,'
      '    :PRSK_REM_DVPOKT,'
      '    :SUMSK_REM_DVPOKT,'
      '    :PRSK_CARD_REM_DVPOKT,'
      '    :PRSK_AUTO_REM_DVPOKT,'
      '    :PRSK_HAND_REM_DVPOKT,'
      '    :NO_SK_REM_DVPOKT'
      ')')
    RefreshSQL.Strings = (
      'select rem_dvpokt.*,'
      '    snom.namenom,'
      '    sed.nameed ,'
      '    snom.codenom,'
      '    snom.artnom,'
      '    sed.shed,'
      '    rem_shardware.name_rem_shardware,'
      '    rem_shardware.code_rem_shardware,'
      '    rem_shardware.sernum_rem_shardware'
      'from rem_dvpokt'
      'left outer join SNOM  on rem_dvpokt.idnom_rem_dvpokt=snom.idnom'
      'left outer join SED  on  rem_dvpokt.ided_rem_dvpokt=sed.ided'
      
        'left outer join rem_shardware on rem_dvpokt.idhw_rem_dvpokt=rem_' +
        'shardware.id_rem_shardware'
      'where(  rem_dvpokt.iddoc_rem_dvpokt=:PARAM_IDDOC'
      '     ) and (     REM_DVPOKT.ID_REM_DVPOKT = :OLD_ID_REM_DVPOKT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_dvpokt.*,'
      '    snom.namenom,'
      '    sed.nameed ,'
      '    snom.codenom,'
      '    snom.artnom,'
      '    sed.shed,'
      '    rem_shardware.name_rem_shardware,'
      '    rem_shardware.code_rem_shardware,'
      '    rem_shardware.sernum_rem_shardware'
      'from rem_dvpokt'
      'left outer join SNOM  on rem_dvpokt.idnom_rem_dvpokt=snom.idnom'
      'left outer join SED  on  rem_dvpokt.ided_rem_dvpokt=sed.ided'
      
        'left outer join rem_shardware on rem_dvpokt.idhw_rem_dvpokt=rem_' +
        'shardware.id_rem_shardware'
      'where rem_dvpokt.iddoc_rem_dvpokt=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_DVPOKT'
    AutoUpdateOptions.KeyFields = 'ID_REM_DVPOKT'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DVPOKT_ID'
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
    object DocTID_REM_DVPOKT: TFIBLargeIntField
      FieldName = 'ID_REM_DVPOKT'
    end
    object DocTIDBASE_REM_DVPOKT: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DVPOKT'
    end
    object DocTGID_REM_DVPOKT: TFIBWideStringField
      FieldName = 'GID_REM_DVPOKT'
      Size = 10
    end
    object DocTIDDOC_REM_DVPOKT: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DVPOKT'
    end
    object DocTIDNOM_REM_DVPOKT: TFIBLargeIntField
      FieldName = 'IDNOM_REM_DVPOKT'
    end
    object DocTIDED_REM_DVPOKT: TFIBLargeIntField
      FieldName = 'IDED_REM_DVPOKT'
    end
    object DocTIDHW_REM_DVPOKT: TFIBLargeIntField
      FieldName = 'IDHW_REM_DVPOKT'
    end
    object DocTDVREG_REM_DVPOKT: TFIBSmallIntField
      FieldName = 'DVREG_REM_DVPOKT'
    end
    object DocTKOL_REM_DVPOKT: TFIBBCDField
      FieldName = 'KOL_REM_DVPOKT'
      OnChange = DocTKOL_REM_DVPOKTChange
      Size = 3
      RoundByScale = True
    end
    object DocTKF_REM_DVPOKT: TFIBBCDField
      FieldName = 'KF_REM_DVPOKT'
      Size = 3
      RoundByScale = True
    end
    object DocTPRICE_REM_DVPOKT: TFIBBCDField
      FieldName = 'PRICE_REM_DVPOKT'
      OnChange = DocTPRICE_REM_DVPOKTChange
      Size = 2
      RoundByScale = True
    end
    object DocTSUM_REM_DVPOKT: TFIBBCDField
      FieldName = 'SUM_REM_DVPOKT'
      Size = 2
      RoundByScale = True
    end
    object DocTNDS_REM_DVPOKT: TFIBIntegerField
      FieldName = 'NDS_REM_DVPOKT'
    end
    object DocTSUMNDS_REM_DVPOKT: TFIBBCDField
      FieldName = 'SUMNDS_REM_DVPOKT'
      Size = 2
      RoundByScale = True
    end
    object DocTPRSK_REM_DVPOKT: TFIBBCDField
      FieldName = 'PRSK_REM_DVPOKT'
      Size = 2
      RoundByScale = True
    end
    object DocTSUMSK_REM_DVPOKT: TFIBBCDField
      FieldName = 'SUMSK_REM_DVPOKT'
      Size = 2
      RoundByScale = True
    end
    object DocTPRSK_CARD_REM_DVPOKT: TFIBBCDField
      FieldName = 'PRSK_CARD_REM_DVPOKT'
      Size = 2
      RoundByScale = True
    end
    object DocTPRSK_AUTO_REM_DVPOKT: TFIBBCDField
      FieldName = 'PRSK_AUTO_REM_DVPOKT'
      Size = 2
      RoundByScale = True
    end
    object DocTPRSK_HAND_REM_DVPOKT: TFIBBCDField
      FieldName = 'PRSK_HAND_REM_DVPOKT'
      Size = 2
      RoundByScale = True
    end
    object DocTNO_SK_REM_DVPOKT: TFIBSmallIntField
      FieldName = 'NO_SK_REM_DVPOKT'
    end
    object DocTNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object DocTNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 200
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
    object DocTRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
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
    Left = 304
    Top = 296
  end
  object NumDoc: TpFIBDataSet
    SelectSQL.Strings = (
      
        'select max(rem_galldoc.num_rem_galldoc) AS MAXNUMBER from  rem_g' +
        'alldoc'
      'where rem_galldoc.tdoc_rem_galldoc='#39'REMVPOK'#39
      '            and rem_galldoc.pos_rem_galldoc > :PARAM_POS')
    Transaction = IBTr
    Left = 296
    Top = 16
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 272
    Top = 192
    qoStartTransaction = True
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE REM_DOC_VPOK_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 192
    Top = 320
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE REM_DOC_VPOK_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 192
    Top = 272
    qoStartTransaction = True
  end
  object DocOsn: TpFIBDataSet
    SelectSQL.Strings = (
      'select'
      '  rem_galldoc.tdoc_rem_galldoc,'
      '  rem_galldoc.pos_rem_galldoc,'
      '  rem_galldoc.num_rem_galldoc'
      'from rem_galldoc'
      'where '
      '  rem_galldoc.id_rem_galldoc=:PARAM_IDDOC')
    Transaction = IBTr
    Left = 160
    Top = 176
    poUseLargeIntField = True
    object DocOsnTDOC_REM_GALLDOC: TFIBWideStringField
      FieldName = 'TDOC_REM_GALLDOC'
      Size = 10
    end
    object DocOsnPOS_REM_GALLDOC: TFIBDateTimeField
      FieldName = 'POS_REM_GALLDOC'
    end
    object DocOsnNUM_REM_GALLDOC: TFIBIntegerField
      FieldName = 'NUM_REM_GALLDOC'
    end
  end
  object DataSourceDocOsn: TDataSource
    DataSet = DocOsn
    Left = 72
    Top = 176
  end
end
