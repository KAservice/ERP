object REM_DMDocReal: TREM_DMDocReal
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 433
  Width = 741
  object DataSourceDoc: TDataSource
    DataSet = Doc
    Left = 72
    Top = 72
  end
  object DataSourceDocT: TDataSource
    DataSet = DocT
    Left = 72
    Top = 128
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
      'UPDATE REM_DREAL'
      'SET '
      '    IDBASE_REM_DREAL = :IDBASE_REM_DREAL,'
      '    IDDOC_REM_DREAL = :IDDOC_REM_DREAL,'
      '    GID_REM_DREAL = :GID_REM_DREAL,'
      '    IDTPRICE_REM_DREAL = :IDTPRICE_REM_DREAL,'
      '    PRIM_REM_DREAL = :PRIM_REM_DREAL,'
      '    IDCARD_REM_DREAL = :IDCARD_REM_DREAL'
      'WHERE'
      '    ID_REM_DREAL = :OLD_ID_REM_DREAL'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DREAL'
      'WHERE'
      '        ID_REM_DREAL = :OLD_ID_REM_DREAL'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DREAL('
      '    ID_REM_DREAL,'
      '    IDBASE_REM_DREAL,'
      '    IDDOC_REM_DREAL,'
      '    GID_REM_DREAL,'
      '    IDTPRICE_REM_DREAL,'
      '    PRIM_REM_DREAL,'
      '    IDCARD_REM_DREAL'
      ')'
      'VALUES('
      '    :ID_REM_DREAL,'
      '    :IDBASE_REM_DREAL,'
      '    :IDDOC_REM_DREAL,'
      '    :GID_REM_DREAL,'
      '    :IDTPRICE_REM_DREAL,'
      '    :PRIM_REM_DREAL,'
      '    :IDCARD_REM_DREAL'
      ')')
    RefreshSQL.Strings = (
      'select rem_dreal.*,'
      '  sdiscount_card.name_sdiscount_card'
      'from  rem_dreal'
      
        'left outer join SDISCOUNT_CARD on sdiscount_card.id_sdiscount_ca' +
        'rd=rem_dreal.idcard_rem_dreal'
      'where(  rem_dreal.iddoc_rem_dreal=:PARAM_IDDOC'
      '     ) and (     REM_DREAL.ID_REM_DREAL = :OLD_ID_REM_DREAL'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_dreal.*,'
      '  sdiscount_card.name_sdiscount_card'
      'from  rem_dreal'
      
        'left outer join SDISCOUNT_CARD on sdiscount_card.id_sdiscount_ca' +
        'rd=rem_dreal.idcard_rem_dreal'
      'where rem_dreal.iddoc_rem_dreal=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_DREAL'
    AutoUpdateOptions.KeyFields = 'ID_REM_DREAL'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DREAL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 72
    poUseLargeIntField = True
    object DocID_REM_DREAL: TFIBLargeIntField
      FieldName = 'ID_REM_DREAL'
    end
    object DocIDBASE_REM_DREAL: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DREAL'
    end
    object DocIDDOC_REM_DREAL: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DREAL'
    end
    object DocGID_REM_DREAL: TFIBWideStringField
      FieldName = 'GID_REM_DREAL'
      Size = 10
    end
    object DocIDTPRICE_REM_DREAL: TFIBLargeIntField
      FieldName = 'IDTPRICE_REM_DREAL'
    end
    object DocPRIM_REM_DREAL: TFIBWideStringField
      FieldName = 'PRIM_REM_DREAL'
      Size = 100
    end
    object DocIDCARD_REM_DREAL: TFIBLargeIntField
      FieldName = 'IDCARD_REM_DREAL'
    end
    object DocNAME_SDISCOUNT_CARD: TFIBWideStringField
      FieldName = 'NAME_SDISCOUNT_CARD'
      Size = 200
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_DREALT'
      'SET '
      '    IDBASE_REM_DREALT = :IDBASE_REM_DREALT,'
      '    IDDOC_REM_DREALT = :IDDOC_REM_DREALT,'
      '    GID_REM_DREALT = :GID_REM_DREALT,'
      '    IDNOM_REM_DREALT = :IDNOM_REM_DREALT,'
      '    IDED_REM_DREALT = :IDED_REM_DREALT,'
      '    IDHW_REM_DREALT = :IDHW_REM_DREALT,'
      '    KOL_REM_DREALT = :KOL_REM_DREALT,'
      '    KF_REM_DREALT = :KF_REM_DREALT,'
      '    PRICE_REM_DREALT = :PRICE_REM_DREALT,'
      '    SUM_REM_DREALT = :SUM_REM_DREALT,'
      '    NDS_REM_DREALT = :NDS_REM_DREALT,'
      '    SUMNDS_REM_DREALT = :SUMNDS_REM_DREALT,'
      '    PRSK_REM_DREALT = :PRSK_REM_DREALT,'
      '    SUMSK_REM_DREALT = :SUMSK_REM_DREALT,'
      '    PRSK_CARD_REM_DREALT = :PRSK_CARD_REM_DREALT,'
      '    PRSK_AUTO_REM_DREALT = :PRSK_AUTO_REM_DREALT,'
      '    PRSK_HAND_REM_DREALT = :PRSK_HAND_REM_DREALT,'
      '    NO_SK_REM_DREALT = :NO_SK_REM_DREALT,'
      '    DVREG_REM_DREALT = :DVREG_REM_DREALT,'
      '    WARRANTY_REM_DREALT = :WARRANTY_REM_DREALT,'
      '    IDTNOM_REM_DREALT = :IDTNOM_REM_DREALT,'
      '    IDMHRAN_DREALT = :IDMHRAN_DREALT'
      'WHERE'
      '    ID_REM_DREALT = :OLD_ID_REM_DREALT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DREALT'
      'WHERE'
      '        ID_REM_DREALT = :OLD_ID_REM_DREALT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DREALT('
      '    ID_REM_DREALT,'
      '    IDBASE_REM_DREALT,'
      '    IDDOC_REM_DREALT,'
      '    GID_REM_DREALT,'
      '    IDNOM_REM_DREALT,'
      '    IDED_REM_DREALT,'
      '    IDHW_REM_DREALT,'
      '    KOL_REM_DREALT,'
      '    KF_REM_DREALT,'
      '    PRICE_REM_DREALT,'
      '    SUM_REM_DREALT,'
      '    NDS_REM_DREALT,'
      '    SUMNDS_REM_DREALT,'
      '    PRSK_REM_DREALT,'
      '    SUMSK_REM_DREALT,'
      '    PRSK_CARD_REM_DREALT,'
      '    PRSK_AUTO_REM_DREALT,'
      '    PRSK_HAND_REM_DREALT,'
      '    NO_SK_REM_DREALT,'
      '    DVREG_REM_DREALT,'
      '    WARRANTY_REM_DREALT,'
      '    IDTNOM_REM_DREALT,'
      '    IDMHRAN_DREALT'
      ')'
      'VALUES('
      '    :ID_REM_DREALT,'
      '    :IDBASE_REM_DREALT,'
      '    :IDDOC_REM_DREALT,'
      '    :GID_REM_DREALT,'
      '    :IDNOM_REM_DREALT,'
      '    :IDED_REM_DREALT,'
      '    :IDHW_REM_DREALT,'
      '    :KOL_REM_DREALT,'
      '    :KF_REM_DREALT,'
      '    :PRICE_REM_DREALT,'
      '    :SUM_REM_DREALT,'
      '    :NDS_REM_DREALT,'
      '    :SUMNDS_REM_DREALT,'
      '    :PRSK_REM_DREALT,'
      '    :SUMSK_REM_DREALT,'
      '    :PRSK_CARD_REM_DREALT,'
      '    :PRSK_AUTO_REM_DREALT,'
      '    :PRSK_HAND_REM_DREALT,'
      '    :NO_SK_REM_DREALT,'
      '    :DVREG_REM_DREALT,'
      '    :WARRANTY_REM_DREALT,'
      '    :IDTNOM_REM_DREALT,'
      '    :IDMHRAN_DREALT'
      ')')
    RefreshSQL.Strings = (
      'select rem_drealt.*,'
      
        '  snom.krnamenom, snom.namenom,snom.tnom,snom.codenom,snom.artno' +
        'm,'
      '  sed.NAMEED,sed.shed,'
      '  snom.idgrpnom,'
      '  snom.idvid_snom,'
      '  sgrpnom.namegn,'
      '  svidnom.name_svidnom,'
      '  rem_shardware.name_rem_shardware,'
      '  rem_shardware.code_rem_shardware,'
      '  rem_shardware.sernum_rem_shardware,'
      '  rem_shardware.fl_necond_rem_shardware,'
      '  rem_shardware.prichina_rem_shardware,'
      '  stnom.name_stnom,'
      '  smhran.name_smhran'
      'from rem_drealt'
      'left outer join SNOM  ON rem_drealt.idnom_rem_drealt=snom.idnom'
      'left outer join SED  on  rem_drealt.ided_rem_drealt=sed.ided'
      'left outer join sgrpnom on snom.idgrpnom=sgrpnom.idgn'
      'left outer join svidnom on snom.idvid_snom=svidnom.id_svidnom'
      
        'left outer join rem_shardware on rem_drealt.idhw_rem_drealt=rem_' +
        'shardware.id_rem_shardware'
      
        'left outer join stnom  ON rem_drealt.idtnom_rem_drealt=stnom.id_' +
        'stnom'
      
        'left outer join smhran  ON rem_drealt.idmhran_drealt=smhran.id_s' +
        'mhran'
      ''
      'where(  rem_drealt.iddoc_rem_drealt=:PARAM_IDDOC'
      '     ) and (     REM_DREALT.ID_REM_DREALT = :OLD_ID_REM_DREALT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_drealt.*,'
      
        '  snom.krnamenom, snom.namenom,snom.tnom,snom.codenom,snom.artno' +
        'm,'
      '  sed.NAMEED,sed.shed,'
      '  snom.idgrpnom,'
      '  snom.idvid_snom,'
      '  sgrpnom.namegn,'
      '  svidnom.name_svidnom,'
      '  rem_shardware.name_rem_shardware,'
      '  rem_shardware.code_rem_shardware,'
      '  rem_shardware.sernum_rem_shardware,'
      '  rem_shardware.fl_necond_rem_shardware,'
      '  rem_shardware.prichina_rem_shardware,'
      '  stnom.name_stnom,'
      '  smhran.name_smhran'
      'from rem_drealt'
      'left outer join SNOM  ON rem_drealt.idnom_rem_drealt=snom.idnom'
      'left outer join SED  on  rem_drealt.ided_rem_drealt=sed.ided'
      'left outer join sgrpnom on snom.idgrpnom=sgrpnom.idgn'
      'left outer join svidnom on snom.idvid_snom=svidnom.id_svidnom'
      
        'left outer join rem_shardware on rem_drealt.idhw_rem_drealt=rem_' +
        'shardware.id_rem_shardware'
      
        'left outer join stnom  ON rem_drealt.idtnom_rem_drealt=stnom.id_' +
        'stnom'
      
        'left outer join smhran  ON rem_drealt.idmhran_drealt=smhran.id_s' +
        'mhran'
      ''
      'where rem_drealt.iddoc_rem_drealt=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_DREALT'
    AutoUpdateOptions.KeyFields = 'ID_REM_DREALT'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DREALT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    AfterDelete = DocTAfterDelete
    BeforeDelete = DocTBeforeDelete
    OnCalcFields = DocTCalcFields
    OnNewRecord = DocTNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 128
    poUseLargeIntField = True
    object DocTID_REM_DREALT: TFIBLargeIntField
      FieldName = 'ID_REM_DREALT'
    end
    object DocTIDBASE_REM_DREALT: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DREALT'
    end
    object DocTIDDOC_REM_DREALT: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DREALT'
    end
    object DocTGID_REM_DREALT: TFIBWideStringField
      FieldName = 'GID_REM_DREALT'
      Size = 10
    end
    object DocTIDNOM_REM_DREALT: TFIBLargeIntField
      FieldName = 'IDNOM_REM_DREALT'
    end
    object DocTIDED_REM_DREALT: TFIBLargeIntField
      FieldName = 'IDED_REM_DREALT'
    end
    object DocTIDHW_REM_DREALT: TFIBLargeIntField
      FieldName = 'IDHW_REM_DREALT'
    end
    object DocTKOL_REM_DREALT: TFIBBCDField
      FieldName = 'KOL_REM_DREALT'
      OnChange = DocTKOL_REM_DREALTChange
      Size = 3
      RoundByScale = True
    end
    object DocTKF_REM_DREALT: TFIBBCDField
      FieldName = 'KF_REM_DREALT'
      Size = 3
      RoundByScale = True
    end
    object DocTPRICE_REM_DREALT: TFIBBCDField
      FieldName = 'PRICE_REM_DREALT'
      OnChange = DocTPRICE_REM_DREALTChange
      Size = 2
      RoundByScale = True
    end
    object DocTSUM_REM_DREALT: TFIBBCDField
      FieldName = 'SUM_REM_DREALT'
      Size = 2
      RoundByScale = True
    end
    object DocTNDS_REM_DREALT: TFIBIntegerField
      FieldName = 'NDS_REM_DREALT'
    end
    object DocTSUMNDS_REM_DREALT: TFIBBCDField
      FieldName = 'SUMNDS_REM_DREALT'
      Size = 2
      RoundByScale = True
    end
    object DocTPRSK_REM_DREALT: TFIBBCDField
      FieldName = 'PRSK_REM_DREALT'
      OnChange = DocTPRSK_REM_DREALTChange
      Size = 2
      RoundByScale = True
    end
    object DocTSUMSK_REM_DREALT: TFIBBCDField
      FieldName = 'SUMSK_REM_DREALT'
      Size = 2
      RoundByScale = True
    end
    object DocTPRSK_CARD_REM_DREALT: TFIBBCDField
      FieldName = 'PRSK_CARD_REM_DREALT'
      Size = 2
      RoundByScale = True
    end
    object DocTPRSK_AUTO_REM_DREALT: TFIBBCDField
      FieldName = 'PRSK_AUTO_REM_DREALT'
      Size = 2
      RoundByScale = True
    end
    object DocTPRSK_HAND_REM_DREALT: TFIBBCDField
      FieldName = 'PRSK_HAND_REM_DREALT'
      Size = 2
      RoundByScale = True
    end
    object DocTNO_SK_REM_DREALT: TFIBSmallIntField
      FieldName = 'NO_SK_REM_DREALT'
    end
    object DocTKRNAMENOM: TFIBWideStringField
      FieldName = 'KRNAMENOM'
      Size = 40
    end
    object DocTNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object DocTTNOM: TFIBSmallIntField
      FieldName = 'TNOM'
    end
    object DocTCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object DocTARTNOM: TFIBWideStringField
      FieldName = 'ARTNOM'
      Size = 40
    end
    object DocTNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 200
    end
    object DocTSHED: TFIBWideStringField
      FieldName = 'SHED'
      Size = 13
    end
    object DocTIDGRPNOM: TFIBLargeIntField
      FieldName = 'IDGRPNOM'
    end
    object DocTIDVID_SNOM: TFIBLargeIntField
      FieldName = 'IDVID_SNOM'
    end
    object DocTNAMEGN: TFIBWideStringField
      FieldName = 'NAMEGN'
      Size = 200
    end
    object DocTNAME_SVIDNOM: TFIBWideStringField
      FieldName = 'NAME_SVIDNOM'
      Size = 200
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
    object DocTDVREG_REM_DREALT: TFIBSmallIntField
      FieldName = 'DVREG_REM_DREALT'
    end
    object DocTWARRANTY_REM_DREALT: TFIBIntegerField
      FieldName = 'WARRANTY_REM_DREALT'
    end
    object DocTFL_NECOND_REM_SHARDWARE: TFIBSmallIntField
      FieldName = 'FL_NECOND_REM_SHARDWARE'
    end
    object DocTPRICHINA_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'PRICHINA_REM_SHARDWARE'
      Size = 150
    end
    object DocTIDTNOM_REM_DREALT: TFIBLargeIntField
      FieldName = 'IDTNOM_REM_DREALT'
    end
    object DocTIDMHRAN_DREALT: TFIBLargeIntField
      FieldName = 'IDMHRAN_DREALT'
    end
    object DocTNAME_STNOM: TFIBWideStringField
      FieldName = 'NAME_STNOM'
      Size = 200
    end
    object DocTNAME_SMHRAN: TFIBWideStringField
      FieldName = 'NAME_SMHRAN'
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
    Left = 248
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
    Left = 248
    Top = 72
  end
  object IBTrDvReg: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 432
    Top = 192
  end
  object NumDoc: TpFIBDataSet
    SelectSQL.Strings = (
      
        'select max(rem_galldoc.num_rem_galldoc) AS MAXNUMBER from  rem_g' +
        'alldoc'
      'where rem_galldoc.tdoc_rem_galldoc='#39'REMREAL'#39
      '            and rem_galldoc.pos_rem_galldoc > :PARAM_POS')
    Transaction = IBTr
    Left = 368
    Top = 16
    object NumDocMAXNUMBER: TFIBIntegerField
      FieldName = 'MAXNUMBER'
    end
  end
  object SpisokTypePrice: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from STPRICE')
    Transaction = IBTr
    Left = 368
    Top = 72
    object SpisokTypePriceID_TPRICE: TFIBIntegerField
      FieldName = 'ID_TPRICE'
    end
    object SpisokTypePriceNAME_TPRICE: TFIBWideStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
    end
    object SpisokTypePriceGID_STPRICE: TFIBWideStringField
      FieldName = 'GID_STPRICE'
      Size = 10
    end
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE REM_DOC_REAL_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 360
    Top = 224
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE REM_DOC_REAL_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 360
    Top = 168
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
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 192
    poUseLargeIntField = True
    object DocOsnTDOC_REM_GALLDOC: TFIBWideStringField
      FieldName = 'TDOC_REM_GALLDOC'
      OnGetText = DocOsnTDOC_REM_GALLDOCGetText
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
    Top = 192
  end
end
