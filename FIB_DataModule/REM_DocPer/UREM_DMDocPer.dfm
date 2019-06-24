object REM_DMDocPer: TREM_DMDocPer
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
      'UPDATE REM_DPER'
      'SET '
      '    IDBASE_REM_DPER = :IDBASE_REM_DPER,'
      '    IDDOC_REM_DPER = :IDDOC_REM_DPER,'
      '    GID_REM_DPER = :GID_REM_DPER,'
      '    IDRTPRICE_REM_DPER = :IDRTPRICE_REM_DPER,'
      '    IDSKLPOL_REM_DPER = :IDSKLPOL_REM_DPER,'
      '    PRIM_REM_DPER = :PRIM_REM_DPER'
      'WHERE'
      '    ID_REM_DPER = :OLD_ID_REM_DPER'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DPER'
      'WHERE'
      '        ID_REM_DPER = :OLD_ID_REM_DPER'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DPER('
      '    ID_REM_DPER,'
      '    IDBASE_REM_DPER,'
      '    IDDOC_REM_DPER,'
      '    GID_REM_DPER,'
      '    IDRTPRICE_REM_DPER,'
      '    IDSKLPOL_REM_DPER,'
      '    PRIM_REM_DPER'
      ')'
      'VALUES('
      '    :ID_REM_DPER,'
      '    :IDBASE_REM_DPER,'
      '    :IDDOC_REM_DPER,'
      '    :GID_REM_DPER,'
      '    :IDRTPRICE_REM_DPER,'
      '    :IDSKLPOL_REM_DPER,'
      '    :PRIM_REM_DPER'
      ')')
    RefreshSQL.Strings = (
      'select rem_dper.*,'
      '        ssklad.namesklad'
      'from  rem_dper'
      
        'left outer join ssklad on rem_dper.idsklpol_rem_dper=ssklad.idsk' +
        'lad'
      'where(  rem_dper.iddoc_rem_dper=:PARAM_IDDOC'
      '     ) and (     REM_DPER.ID_REM_DPER = :OLD_ID_REM_DPER'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_dper.*,'
      '        ssklad.namesklad'
      'from  rem_dper'
      
        'left outer join ssklad on rem_dper.idsklpol_rem_dper=ssklad.idsk' +
        'lad'
      'where rem_dper.iddoc_rem_dper=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_DPER'
    AutoUpdateOptions.KeyFields = 'ID_REM_DPER'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DPER_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 72
    poUseLargeIntField = True
    object DocID_REM_DPER: TFIBLargeIntField
      FieldName = 'ID_REM_DPER'
    end
    object DocIDBASE_REM_DPER: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DPER'
    end
    object DocIDDOC_REM_DPER: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DPER'
    end
    object DocGID_REM_DPER: TFIBWideStringField
      FieldName = 'GID_REM_DPER'
      Size = 10
    end
    object DocIDRTPRICE_REM_DPER: TFIBLargeIntField
      FieldName = 'IDRTPRICE_REM_DPER'
    end
    object DocIDSKLPOL_REM_DPER: TFIBLargeIntField
      FieldName = 'IDSKLPOL_REM_DPER'
    end
    object DocPRIM_REM_DPER: TFIBWideStringField
      FieldName = 'PRIM_REM_DPER'
      Size = 100
    end
    object DocNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 200
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_DPERT'
      'SET '
      '    IDBASE_REM_DPERT = :IDBASE_REM_DPERT,'
      '    IDDOC_REM_DPERT = :IDDOC_REM_DPERT,'
      '    GID_REM_DPERT = :GID_REM_DPERT,'
      '    IDNOM_REM_DPERT = :IDNOM_REM_DPERT,'
      '    IDED_REM_DPERT = :IDED_REM_DPERT,'
      '    IDHW_REM_DPERT = :IDHW_REM_DPERT,'
      '    KOL_REM_DPERT = :KOL_REM_DPERT,'
      '    KF_REM_DPERT = :KF_REM_DPERT,'
      '    RPRICE_REM_DPERT = :RPRICE_REM_DPERT,'
      '    RSUM_REM_DPERT = :RSUM_REM_DPERT,'
      '    NAC_REM_DPERT = :NAC_REM_DPERT,'
      '    DVREG_REM_DPERT = :DVREG_REM_DPERT,'
      '    DVREG_POL_REM_DPERT = :DVREG_POL_REM_DPERT,'
      '    IDTNOM_REM_DPERT = :IDTNOM_REM_DPERT,'
      '    IDMHRAN_OTPR_REM_DPERT = :IDMHRAN_OTPR_REM_DPERT,'
      '    IDMHRAN_POL_REM_DPERT = :IDMHRAN_POL_REM_DPERT'
      'WHERE'
      '    ID_REM_DPERT = :OLD_ID_REM_DPERT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DPERT'
      'WHERE'
      '        ID_REM_DPERT = :OLD_ID_REM_DPERT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DPERT('
      '    ID_REM_DPERT,'
      '    IDBASE_REM_DPERT,'
      '    IDDOC_REM_DPERT,'
      '    GID_REM_DPERT,'
      '    IDNOM_REM_DPERT,'
      '    IDED_REM_DPERT,'
      '    IDHW_REM_DPERT,'
      '    KOL_REM_DPERT,'
      '    KF_REM_DPERT,'
      '    RPRICE_REM_DPERT,'
      '    RSUM_REM_DPERT,'
      '    NAC_REM_DPERT,'
      '    DVREG_REM_DPERT,'
      '    DVREG_POL_REM_DPERT,'
      '    IDTNOM_REM_DPERT,'
      '    IDMHRAN_OTPR_REM_DPERT,'
      '    IDMHRAN_POL_REM_DPERT'
      ')'
      'VALUES('
      '    :ID_REM_DPERT,'
      '    :IDBASE_REM_DPERT,'
      '    :IDDOC_REM_DPERT,'
      '    :GID_REM_DPERT,'
      '    :IDNOM_REM_DPERT,'
      '    :IDED_REM_DPERT,'
      '    :IDHW_REM_DPERT,'
      '    :KOL_REM_DPERT,'
      '    :KF_REM_DPERT,'
      '    :RPRICE_REM_DPERT,'
      '    :RSUM_REM_DPERT,'
      '    :NAC_REM_DPERT,'
      '    :DVREG_REM_DPERT,'
      '    :DVREG_POL_REM_DPERT,'
      '    :IDTNOM_REM_DPERT,'
      '    :IDMHRAN_OTPR_REM_DPERT,'
      '    :IDMHRAN_POL_REM_DPERT'
      ')')
    RefreshSQL.Strings = (
      'select rem_dpert.*,'
      
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
      '  mhran_otpr.name_smhran as name_smhran_otpr,'
      '  mhran_pol.name_smhran as name_smhran_pol,'
      '  stnom.name_stnom'
      'from rem_dpert'
      'left outer join SNOM  ON rem_dpert.idnom_rem_dpert=snom.idnom'
      'left outer join SED  on  rem_dpert.ided_rem_dpert=sed.ided'
      'left outer join sgrpnom on snom.idgrpnom=sgrpnom.idgn'
      'left outer join svidnom on snom.idvid_snom=svidnom.id_svidnom'
      
        'left outer join rem_shardware on rem_dpert.idhw_rem_dpert=rem_sh' +
        'ardware.id_rem_shardware'
      
        'left outer join smhran as mhran_otpr on rem_dpert.idmhran_otpr_r' +
        'em_dpert=mhran_otpr.id_smhran'
      
        'left outer join smhran as mhran_pol on rem_dpert.idmhran_pol_rem' +
        '_dpert=mhran_pol.id_smhran'
      
        'left outer join stnom  ON rem_dpert.idtnom_rem_dpert=stnom.id_st' +
        'nom'
      'where(  rem_dpert.iddoc_rem_dpert=:PARAM_IDDOC'
      '     ) and (     REM_DPERT.ID_REM_DPERT = :OLD_ID_REM_DPERT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_dpert.*,'
      
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
      '  mhran_otpr.name_smhran as name_smhran_otpr,'
      '  mhran_pol.name_smhran as name_smhran_pol,'
      '  stnom.name_stnom'
      'from rem_dpert'
      'left outer join SNOM  ON rem_dpert.idnom_rem_dpert=snom.idnom'
      'left outer join SED  on  rem_dpert.ided_rem_dpert=sed.ided'
      'left outer join sgrpnom on snom.idgrpnom=sgrpnom.idgn'
      'left outer join svidnom on snom.idvid_snom=svidnom.id_svidnom'
      
        'left outer join rem_shardware on rem_dpert.idhw_rem_dpert=rem_sh' +
        'ardware.id_rem_shardware'
      
        'left outer join smhran as mhran_otpr on rem_dpert.idmhran_otpr_r' +
        'em_dpert=mhran_otpr.id_smhran'
      
        'left outer join smhran as mhran_pol on rem_dpert.idmhran_pol_rem' +
        '_dpert=mhran_pol.id_smhran'
      
        'left outer join stnom  ON rem_dpert.idtnom_rem_dpert=stnom.id_st' +
        'nom'
      'where rem_dpert.iddoc_rem_dpert=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_DPERT'
    AutoUpdateOptions.KeyFields = 'ID_REM_DPERT'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DPERT_ID'
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
    object DocTID_REM_DPERT: TFIBLargeIntField
      FieldName = 'ID_REM_DPERT'
    end
    object DocTIDBASE_REM_DPERT: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DPERT'
    end
    object DocTIDDOC_REM_DPERT: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DPERT'
    end
    object DocTGID_REM_DPERT: TFIBWideStringField
      FieldName = 'GID_REM_DPERT'
      Size = 10
    end
    object DocTIDNOM_REM_DPERT: TFIBLargeIntField
      FieldName = 'IDNOM_REM_DPERT'
    end
    object DocTIDED_REM_DPERT: TFIBLargeIntField
      FieldName = 'IDED_REM_DPERT'
    end
    object DocTIDHW_REM_DPERT: TFIBLargeIntField
      FieldName = 'IDHW_REM_DPERT'
    end
    object DocTKOL_REM_DPERT: TFIBBCDField
      FieldName = 'KOL_REM_DPERT'
      OnChange = DocTKOL_REM_DPERTChange
      Size = 3
      RoundByScale = True
    end
    object DocTKF_REM_DPERT: TFIBBCDField
      FieldName = 'KF_REM_DPERT'
      Size = 3
      RoundByScale = True
    end
    object DocTRPRICE_REM_DPERT: TFIBBCDField
      FieldName = 'RPRICE_REM_DPERT'
      OnChange = DocTRPRICE_REM_DPERTChange
      Size = 2
      RoundByScale = True
    end
    object DocTRSUM_REM_DPERT: TFIBBCDField
      FieldName = 'RSUM_REM_DPERT'
      Size = 2
      RoundByScale = True
    end
    object DocTNAC_REM_DPERT: TFIBBCDField
      FieldName = 'NAC_REM_DPERT'
      Size = 2
      RoundByScale = True
    end
    object DocTDVREG_REM_DPERT: TFIBSmallIntField
      FieldName = 'DVREG_REM_DPERT'
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
    object DocTDVREG_POL_REM_DPERT: TFIBSmallIntField
      FieldName = 'DVREG_POL_REM_DPERT'
    end
    object DocTIDTNOM_REM_DPERT: TFIBLargeIntField
      FieldName = 'IDTNOM_REM_DPERT'
    end
    object DocTIDMHRAN_OTPR_REM_DPERT: TFIBLargeIntField
      FieldName = 'IDMHRAN_OTPR_REM_DPERT'
    end
    object DocTIDMHRAN_POL_REM_DPERT: TFIBLargeIntField
      FieldName = 'IDMHRAN_POL_REM_DPERT'
    end
    object DocTNAME_SMHRAN_POL: TFIBWideStringField
      FieldName = 'NAME_SMHRAN_POL'
      Size = 200
    end
    object DocTNAME_STNOM: TFIBWideStringField
      FieldName = 'NAME_STNOM'
      Size = 200
    end
    object DocTNAME_SMHRAN_OTPR: TFIBWideStringField
      FieldName = 'NAME_SMHRAN_OTPR'
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
      'where rem_galldoc.tdoc_rem_galldoc='#39'REMPER'#39
      '            and rem_galldoc.pos_rem_galldoc > :PARAM_POS')
    Left = 368
    Top = 16
    object NumDocMAXNUMBER: TFIBIntegerField
      FieldName = 'MAXNUMBER'
    end
  end
  object SpisokTypePrice: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from STPRICE')
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
      'EXECUTE PROCEDURE REM_DOC_PER_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 360
    Top = 224
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE REM_DOC_PER_DVREG (:PARAM_IDDOC,0,0,0)')
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
