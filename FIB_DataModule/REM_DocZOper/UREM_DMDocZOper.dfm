object REM_DMDocZOper: TREM_DMDocZOper
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 439
  Width = 667
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
      'UPDATE REM_DZOPER'
      'SET '
      '    IDBASE_REM_DZOPER = :IDBASE_REM_DZOPER,'
      '    GID_REM_DZOPER = :GID_REM_DZOPER,'
      '    IDDOC_REM_DZOPER = :IDDOC_REM_DZOPER,'
      '    IDZ_REM_DZOPER = :IDZ_REM_DZOPER,'
      '    IDTPRICE_REM_DZOPER = :IDTPRICE_REM_DZOPER,'
      '    PRIM_REM_DZOPER = :PRIM_REM_DZOPER'
      'WHERE'
      '    ID_REM_DZOPER = :OLD_ID_REM_DZOPER'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DZOPER'
      'WHERE'
      '        ID_REM_DZOPER = :OLD_ID_REM_DZOPER'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DZOPER('
      '    ID_REM_DZOPER,'
      '    IDBASE_REM_DZOPER,'
      '    GID_REM_DZOPER,'
      '    IDDOC_REM_DZOPER,'
      '    IDZ_REM_DZOPER,'
      '    IDTPRICE_REM_DZOPER,'
      '    PRIM_REM_DZOPER'
      ')'
      'VALUES('
      '    :ID_REM_DZOPER,'
      '    :IDBASE_REM_DZOPER,'
      '    :GID_REM_DZOPER,'
      '    :IDDOC_REM_DZOPER,'
      '    :IDZ_REM_DZOPER,'
      '    :IDTPRICE_REM_DZOPER,'
      '    :PRIM_REM_DZOPER'
      ')')
    RefreshSQL.Strings = (
      'select rem_dzoper.*,'
      '        rem_z.name_rem_z,'
      '        rem_z.num_rem_z,'
      '        rem_z.pos_rem_z,'
      '        rem_z.sernum_rem_z,'
      '        rem_z.sernum2_rem_z,'
      '        rem_z.klient_name_rem_z,'
      '        rem_z.model_rem_z,'
      '        rem_smodel.name_rem_smodel'
      'from  rem_dzoper'
      
        'left outer join rem_z on rem_dzoper.idz_rem_dzoper=rem_z.id_rem_' +
        'z'
      
        'left outer join rem_smodel on rem_z.idmodel_rem_z=rem_smodel.id_' +
        'rem_smodel'
      'where(  rem_dzoper.iddoc_rem_dzoper=:PARAM_IDDOC'
      '     ) and (     REM_DZOPER.ID_REM_DZOPER = :OLD_ID_REM_DZOPER'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_dzoper.*,'
      '        rem_z.name_rem_z,'
      '        rem_z.num_rem_z,'
      '        rem_z.pos_rem_z,'
      '        rem_z.sernum_rem_z,'
      '        rem_z.sernum2_rem_z,'
      '        rem_z.klient_name_rem_z,'
      '        rem_z.model_rem_z,'
      '        rem_smodel.name_rem_smodel'
      'from  rem_dzoper'
      
        'left outer join rem_z on rem_dzoper.idz_rem_dzoper=rem_z.id_rem_' +
        'z'
      
        'left outer join rem_smodel on rem_z.idmodel_rem_z=rem_smodel.id_' +
        'rem_smodel'
      'where rem_dzoper.iddoc_rem_dzoper=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_DZOPER'
    AutoUpdateOptions.KeyFields = 'ID_REM_DZOPER'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DZOPER_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object DocID_REM_DZOPER: TFIBLargeIntField
      FieldName = 'ID_REM_DZOPER'
    end
    object DocIDBASE_REM_DZOPER: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DZOPER'
    end
    object DocGID_REM_DZOPER: TFIBWideStringField
      FieldName = 'GID_REM_DZOPER'
      Size = 10
    end
    object DocIDDOC_REM_DZOPER: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DZOPER'
    end
    object DocIDZ_REM_DZOPER: TFIBLargeIntField
      FieldName = 'IDZ_REM_DZOPER'
    end
    object DocIDTPRICE_REM_DZOPER: TFIBLargeIntField
      FieldName = 'IDTPRICE_REM_DZOPER'
    end
    object DocPRIM_REM_DZOPER: TFIBWideStringField
      FieldName = 'PRIM_REM_DZOPER'
      Size = 100
    end
    object DocNAME_REM_Z: TFIBWideStringField
      FieldName = 'NAME_REM_Z'
      Size = 200
    end
    object DocNUM_REM_Z: TFIBIntegerField
      FieldName = 'NUM_REM_Z'
    end
    object DocPOS_REM_Z: TFIBDateTimeField
      FieldName = 'POS_REM_Z'
    end
    object DocSERNUM_REM_Z: TFIBWideStringField
      FieldName = 'SERNUM_REM_Z'
      Size = 50
    end
    object DocSERNUM2_REM_Z: TFIBWideStringField
      FieldName = 'SERNUM2_REM_Z'
      Size = 50
    end
    object DocKLIENT_NAME_REM_Z: TFIBWideStringField
      FieldName = 'KLIENT_NAME_REM_Z'
      Size = 200
    end
    object DocMODEL_REM_Z: TFIBWideStringField
      FieldName = 'MODEL_REM_Z'
      Size = 40
    end
    object DocNAME_REM_SMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SMODEL'
      Size = 200
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_DZOPERT'
      'SET '
      '    IDBASE_REM_DZOPERT = :IDBASE_REM_DZOPERT,'
      '    GID_REM_DZOPERT = :GID_REM_DZOPERT,'
      '    IDDOC_REM_DZOPERT = :IDDOC_REM_DZOPERT,'
      '    IDNOM_REM_DZOPERT = :IDNOM_REM_DZOPERT,'
      '    IDED_REM_DZOPERT = :IDED_REM_DZOPERT,'
      '    IDHW_REM_DZOPERT = :IDHW_REM_DZOPERT,'
      '    KOL_REM_DZOPERT = :KOL_REM_DZOPERT,'
      '    KF_REM_DZOPERT = :KF_REM_DZOPERT,'
      '    PRICE_REM_DZOPERT = :PRICE_REM_DZOPERT,'
      '    SUM_REM_DZOPERT = :SUM_REM_DZOPERT,'
      '    DVREG_REM_DZOPERT = :DVREG_REM_DZOPERT,'
      '    STR_NAMENOM_REM_DZOPERT = :STR_NAMENOM_REM_DZOPERT,'
      '    IDHWOLD_REM_DZOPERT = :IDHWOLD_REM_DZOPERT,'
      '    IDTNOM_REM_DZOPERT = :IDTNOM_REM_DZOPERT,'
      '    IDHW_DONOR_REM_DZOPERT = :IDHW_DONOR_REM_DZOPERT,'
      '    IDTYP_USEL_REM_DZOPERT = :IDTYP_USEL_REM_DZOPERT,'
      '    IDMHRAN_REM_DZOPERT = :IDMHRAN_REM_DZOPERT'
      'WHERE'
      '    ID_REM_DZOPERT = :OLD_ID_REM_DZOPERT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DZOPERT'
      'WHERE'
      '        ID_REM_DZOPERT = :OLD_ID_REM_DZOPERT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DZOPERT('
      '    ID_REM_DZOPERT,'
      '    IDBASE_REM_DZOPERT,'
      '    GID_REM_DZOPERT,'
      '    IDDOC_REM_DZOPERT,'
      '    IDNOM_REM_DZOPERT,'
      '    IDED_REM_DZOPERT,'
      '    IDHW_REM_DZOPERT,'
      '    KOL_REM_DZOPERT,'
      '    KF_REM_DZOPERT,'
      '    PRICE_REM_DZOPERT,'
      '    SUM_REM_DZOPERT,'
      '    DVREG_REM_DZOPERT,'
      '    STR_NAMENOM_REM_DZOPERT,'
      '    IDHWOLD_REM_DZOPERT,'
      '    IDTNOM_REM_DZOPERT,'
      '    IDHW_DONOR_REM_DZOPERT,'
      '    IDTYP_USEL_REM_DZOPERT,'
      '    IDMHRAN_REM_DZOPERT'
      ')'
      'VALUES('
      '    :ID_REM_DZOPERT,'
      '    :IDBASE_REM_DZOPERT,'
      '    :GID_REM_DZOPERT,'
      '    :IDDOC_REM_DZOPERT,'
      '    :IDNOM_REM_DZOPERT,'
      '    :IDED_REM_DZOPERT,'
      '    :IDHW_REM_DZOPERT,'
      '    :KOL_REM_DZOPERT,'
      '    :KF_REM_DZOPERT,'
      '    :PRICE_REM_DZOPERT,'
      '    :SUM_REM_DZOPERT,'
      '    :DVREG_REM_DZOPERT,'
      '    :STR_NAMENOM_REM_DZOPERT,'
      '    :IDHWOLD_REM_DZOPERT,'
      '    :IDTNOM_REM_DZOPERT,'
      '    :IDHW_DONOR_REM_DZOPERT,'
      '    :IDTYP_USEL_REM_DZOPERT,'
      '    :IDMHRAN_REM_DZOPERT'
      ')')
    RefreshSQL.Strings = (
      'select rem_dzopert.*,'
      ' snom.namenom,'
      ' snom.codenom,'
      ' snom.artnom,'
      ' sed.nameed,'
      ' sed.shed,'
      ' rem_shardware.name_rem_shardware,'
      ' rem_shardware.code_rem_shardware,'
      ' rem_shardware.sernum_rem_shardware,'
      ' old_shw.name_rem_shardware as old_name_rem_shardware,'
      ' old_shw.code_rem_shardware as old_code_rem_shardware,'
      ' old_shw.sernum_rem_shardware as old_sernum_rem_shardware,'
      ' donor_shw.name_rem_shardware as donor_name_rem_shardware,'
      ' donor_shw.code_rem_shardware as donor_code_rem_shardware,'
      ' donor_shw.sernum_rem_shardware as donor_sernum_rem_shardware,'
      ' stnom.name_stnom,'
      ' smhran.name_smhran,'
      ' rem_stypuslov.name_rem_stypuslov'
      'from  rem_dzopert'
      'left outer join snom on rem_dzopert.idnom_rem_dzopert=snom.idnom'
      'left outer join sed on rem_dzopert.ided_rem_dzopert=sed.ided'
      
        'left outer join rem_shardware on rem_dzopert.idhw_rem_dzopert=re' +
        'm_shardware.id_rem_shardware'
      
        'left outer join rem_shardware as old_shw on rem_dzopert.idhwold_' +
        'rem_dzopert=old_shw.id_rem_shardware'
      
        'left outer join rem_shardware as donor_shw on rem_dzopert.idhw_d' +
        'onor_rem_dzopert=donor_shw.id_rem_shardware'
      
        'left outer join stnom on rem_dzopert.idtnom_rem_dzopert=stnom.id' +
        '_stnom'
      
        'left outer join smhran on rem_dzopert.idmhran_rem_dzopert=smhran' +
        '.id_smhran'
      
        'left outer join rem_stypuslov on rem_dzopert.idtyp_usel_rem_dzop' +
        'ert=rem_stypuslov.id_rem_stypuslov'
      'where(  rem_dzopert.iddoc_rem_dzopert=:PARAM_IDDOC'
      
        '     ) and (     REM_DZOPERT.ID_REM_DZOPERT = :OLD_ID_REM_DZOPER' +
        'T'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_dzopert.*,'
      ' snom.namenom,'
      ' snom.codenom,'
      ' snom.artnom,'
      ' sed.nameed,'
      ' sed.shed,'
      ' rem_shardware.name_rem_shardware,'
      ' rem_shardware.code_rem_shardware,'
      ' rem_shardware.sernum_rem_shardware,'
      ' old_shw.name_rem_shardware as old_name_rem_shardware,'
      ' old_shw.code_rem_shardware as old_code_rem_shardware,'
      ' old_shw.sernum_rem_shardware as old_sernum_rem_shardware,'
      ' donor_shw.name_rem_shardware as donor_name_rem_shardware,'
      ' donor_shw.code_rem_shardware as donor_code_rem_shardware,'
      ' donor_shw.sernum_rem_shardware as donor_sernum_rem_shardware,'
      ' stnom.name_stnom,'
      ' smhran.name_smhran,'
      ' rem_stypuslov.name_rem_stypuslov'
      'from  rem_dzopert'
      'left outer join snom on rem_dzopert.idnom_rem_dzopert=snom.idnom'
      'left outer join sed on rem_dzopert.ided_rem_dzopert=sed.ided'
      
        'left outer join rem_shardware on rem_dzopert.idhw_rem_dzopert=re' +
        'm_shardware.id_rem_shardware'
      
        'left outer join rem_shardware as old_shw on rem_dzopert.idhwold_' +
        'rem_dzopert=old_shw.id_rem_shardware'
      
        'left outer join rem_shardware as donor_shw on rem_dzopert.idhw_d' +
        'onor_rem_dzopert=donor_shw.id_rem_shardware'
      
        'left outer join stnom on rem_dzopert.idtnom_rem_dzopert=stnom.id' +
        '_stnom'
      
        'left outer join smhran on rem_dzopert.idmhran_rem_dzopert=smhran' +
        '.id_smhran'
      
        'left outer join rem_stypuslov on rem_dzopert.idtyp_usel_rem_dzop' +
        'ert=rem_stypuslov.id_rem_stypuslov'
      'where rem_dzopert.iddoc_rem_dzopert=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_DZOPERT'
    AutoUpdateOptions.KeyFields = 'ID_REM_DZOPERT'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DZOPERT_ID'
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
    object DocTRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object DocTID_REM_DZOPERT: TFIBLargeIntField
      FieldName = 'ID_REM_DZOPERT'
    end
    object DocTIDBASE_REM_DZOPERT: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DZOPERT'
    end
    object DocTGID_REM_DZOPERT: TFIBWideStringField
      FieldName = 'GID_REM_DZOPERT'
      Size = 10
    end
    object DocTIDDOC_REM_DZOPERT: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DZOPERT'
    end
    object DocTIDNOM_REM_DZOPERT: TFIBLargeIntField
      FieldName = 'IDNOM_REM_DZOPERT'
    end
    object DocTIDED_REM_DZOPERT: TFIBLargeIntField
      FieldName = 'IDED_REM_DZOPERT'
    end
    object DocTIDHW_REM_DZOPERT: TFIBLargeIntField
      FieldName = 'IDHW_REM_DZOPERT'
    end
    object DocTKOL_REM_DZOPERT: TFIBBCDField
      FieldName = 'KOL_REM_DZOPERT'
      OnChange = DocTKOL_REM_DZOPERTChange
      Size = 3
      RoundByScale = True
    end
    object DocTKF_REM_DZOPERT: TFIBBCDField
      FieldName = 'KF_REM_DZOPERT'
      Size = 3
      RoundByScale = True
    end
    object DocTPRICE_REM_DZOPERT: TFIBBCDField
      FieldName = 'PRICE_REM_DZOPERT'
      OnChange = DocTPRICE_REM_DZOPERTChange
      Size = 2
      RoundByScale = True
    end
    object DocTSUM_REM_DZOPERT: TFIBBCDField
      FieldName = 'SUM_REM_DZOPERT'
      Size = 2
      RoundByScale = True
    end
    object DocTDVREG_REM_DZOPERT: TFIBSmallIntField
      FieldName = 'DVREG_REM_DZOPERT'
    end
    object DocTSTR_NAMENOM_REM_DZOPERT: TFIBWideStringField
      FieldName = 'STR_NAMENOM_REM_DZOPERT'
      Size = 100
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
    object DocTNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 200
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
    object DocTIDHWOLD_REM_DZOPERT: TFIBLargeIntField
      FieldName = 'IDHWOLD_REM_DZOPERT'
    end
    object DocTIDTNOM_REM_DZOPERT: TFIBLargeIntField
      FieldName = 'IDTNOM_REM_DZOPERT'
    end
    object DocTIDHW_DONOR_REM_DZOPERT: TFIBLargeIntField
      FieldName = 'IDHW_DONOR_REM_DZOPERT'
    end
    object DocTIDTYP_USEL_REM_DZOPERT: TFIBLargeIntField
      FieldName = 'IDTYP_USEL_REM_DZOPERT'
    end
    object DocTIDMHRAN_REM_DZOPERT: TFIBLargeIntField
      FieldName = 'IDMHRAN_REM_DZOPERT'
    end
    object DocTSERNUM_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'SERNUM_REM_SHARDWARE'
      Size = 50
    end
    object DocTOLD_NAME_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'OLD_NAME_REM_SHARDWARE'
      Size = 200
    end
    object DocTOLD_CODE_REM_SHARDWARE: TFIBIntegerField
      FieldName = 'OLD_CODE_REM_SHARDWARE'
    end
    object DocTOLD_SERNUM_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'OLD_SERNUM_REM_SHARDWARE'
      Size = 50
    end
    object DocTDONOR_NAME_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'DONOR_NAME_REM_SHARDWARE'
      Size = 200
    end
    object DocTDONOR_CODE_REM_SHARDWARE: TFIBIntegerField
      FieldName = 'DONOR_CODE_REM_SHARDWARE'
    end
    object DocTDONOR_SERNUM_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'DONOR_SERNUM_REM_SHARDWARE'
      Size = 50
    end
    object DocTNAME_STNOM: TFIBWideStringField
      FieldName = 'NAME_STNOM'
      Size = 200
    end
    object DocTNAME_SMHRAN: TFIBWideStringField
      FieldName = 'NAME_SMHRAN'
      Size = 200
    end
    object DocTNAME_REM_STYPUSLOV: TFIBWideStringField
      FieldName = 'NAME_REM_STYPUSLOV'
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
      'select max(NUM_REM_GALLDOC) AS MAXNUMBER from  REM_GALLDOC'
      
        'where TDOC_REM_GALLDOC='#39'REMZOPER'#39' and POS_REM_GALLDOC > :PARAM_P' +
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
      'EXECUTE PROCEDURE REM_DOC_ZOPER_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 304
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE REM_DOC_ZOPER_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 240
    qoStartTransaction = True
  end
end
