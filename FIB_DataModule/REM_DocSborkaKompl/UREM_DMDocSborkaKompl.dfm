object REM_DMDocSborkaKompl: TREM_DMDocSborkaKompl
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
      'UPDATE REM_DSBKOMPL'
      'SET '
      '    IDBASE_REM_DSBKOMPL = :IDBASE_REM_DSBKOMPL,'
      '    IDDOC_REM_DSBKOMPL = :IDDOC_REM_DSBKOMPL,'
      '    GID_REM_DSBKOMPL = :GID_REM_DSBKOMPL,'
      '    IDNOM_REM_DSBKOMPL = :IDNOM_REM_DSBKOMPL,'
      '    IDED_REM_DSBKOMPL = :IDED_REM_DSBKOMPL,'
      '    IDHW_REM_DSBKOMPL = :IDHW_REM_DSBKOMPL,'
      '    KOL_REM_DSBKOMPL = :KOL_REM_DSBKOMPL,'
      '    KF_REM_DSBKOMPL = :KF_REM_DSBKOMPL,'
      '    RPRICE_REM_DSBKOMPL = :RPRICE_REM_DSBKOMPL,'
      '    IDRTPRICE_REM_DSBKOMPL = :IDRTPRICE_REM_DSBKOMPL,'
      '    PRIM_REM_DSBKOMPL = :PRIM_REM_DSBKOMPL'
      'WHERE'
      '    ID_REM_DSBKOMPL = :OLD_ID_REM_DSBKOMPL'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DSBKOMPL'
      'WHERE'
      '        ID_REM_DSBKOMPL = :OLD_ID_REM_DSBKOMPL'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DSBKOMPL('
      '    ID_REM_DSBKOMPL,'
      '    IDBASE_REM_DSBKOMPL,'
      '    IDDOC_REM_DSBKOMPL,'
      '    GID_REM_DSBKOMPL,'
      '    IDNOM_REM_DSBKOMPL,'
      '    IDED_REM_DSBKOMPL,'
      '    IDHW_REM_DSBKOMPL,'
      '    KOL_REM_DSBKOMPL,'
      '    KF_REM_DSBKOMPL,'
      '    RPRICE_REM_DSBKOMPL,'
      '    IDRTPRICE_REM_DSBKOMPL,'
      '    PRIM_REM_DSBKOMPL'
      ')'
      'VALUES('
      '    :ID_REM_DSBKOMPL,'
      '    :IDBASE_REM_DSBKOMPL,'
      '    :IDDOC_REM_DSBKOMPL,'
      '    :GID_REM_DSBKOMPL,'
      '    :IDNOM_REM_DSBKOMPL,'
      '    :IDED_REM_DSBKOMPL,'
      '    :IDHW_REM_DSBKOMPL,'
      '    :KOL_REM_DSBKOMPL,'
      '    :KF_REM_DSBKOMPL,'
      '    :RPRICE_REM_DSBKOMPL,'
      '    :IDRTPRICE_REM_DSBKOMPL,'
      '    :PRIM_REM_DSBKOMPL'
      ')')
    RefreshSQL.Strings = (
      'select rem_dsbkompl.*,'
      '  snom.namenom,'
      '  snom.codenom,'
      '  snom.artnom,'
      '  sed.nameed,'
      '  rem_shardware.name_rem_shardware,'
      '  rem_shardware.code_rem_shardware,'
      '  rem_shardware.sernum_rem_shardware'
      'from  rem_dsbkompl'
      
        'left outer join snom on snom.idnom=rem_dsbkompl.idnom_rem_dsbkom' +
        'pl'
      
        'left outer join rem_shardware on rem_shardware.id_rem_shardware=' +
        'rem_dsbkompl.idhw_rem_dsbkompl'
      'left outer join sed on sed.ided=rem_dsbkompl.ided_rem_dsbkompl'
      'where(  rem_dsbkompl.iddoc_rem_dsbkompl=:PARAM_IDDOC'
      
        '     ) and (     REM_DSBKOMPL.ID_REM_DSBKOMPL = :OLD_ID_REM_DSBK' +
        'OMPL'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_dsbkompl.*,'
      '  snom.namenom,'
      '  snom.codenom,'
      '  snom.artnom,'
      '  sed.nameed,'
      '  rem_shardware.name_rem_shardware,'
      '  rem_shardware.code_rem_shardware,'
      '  rem_shardware.sernum_rem_shardware'
      'from  rem_dsbkompl'
      
        'left outer join snom on snom.idnom=rem_dsbkompl.idnom_rem_dsbkom' +
        'pl'
      
        'left outer join rem_shardware on rem_shardware.id_rem_shardware=' +
        'rem_dsbkompl.idhw_rem_dsbkompl'
      'left outer join sed on sed.ided=rem_dsbkompl.ided_rem_dsbkompl'
      'where rem_dsbkompl.iddoc_rem_dsbkompl=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_DSBKOMPL'
    AutoUpdateOptions.KeyFields = 'ID_REM_DSBKOMPL'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DSBKOMPL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 72
    poUseLargeIntField = True
    object DocID_REM_DSBKOMPL: TFIBLargeIntField
      FieldName = 'ID_REM_DSBKOMPL'
    end
    object DocIDBASE_REM_DSBKOMPL: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DSBKOMPL'
    end
    object DocIDDOC_REM_DSBKOMPL: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DSBKOMPL'
    end
    object DocGID_REM_DSBKOMPL: TFIBWideStringField
      FieldName = 'GID_REM_DSBKOMPL'
      Size = 10
    end
    object DocIDNOM_REM_DSBKOMPL: TFIBLargeIntField
      FieldName = 'IDNOM_REM_DSBKOMPL'
    end
    object DocIDED_REM_DSBKOMPL: TFIBLargeIntField
      FieldName = 'IDED_REM_DSBKOMPL'
    end
    object DocIDHW_REM_DSBKOMPL: TFIBLargeIntField
      FieldName = 'IDHW_REM_DSBKOMPL'
    end
    object DocKOL_REM_DSBKOMPL: TFIBBCDField
      FieldName = 'KOL_REM_DSBKOMPL'
      Size = 3
      RoundByScale = True
    end
    object DocKF_REM_DSBKOMPL: TFIBBCDField
      FieldName = 'KF_REM_DSBKOMPL'
      Size = 3
      RoundByScale = True
    end
    object DocRPRICE_REM_DSBKOMPL: TFIBBCDField
      FieldName = 'RPRICE_REM_DSBKOMPL'
      Size = 2
      RoundByScale = True
    end
    object DocIDRTPRICE_REM_DSBKOMPL: TFIBLargeIntField
      FieldName = 'IDRTPRICE_REM_DSBKOMPL'
    end
    object DocPRIM_REM_DSBKOMPL: TFIBWideStringField
      FieldName = 'PRIM_REM_DSBKOMPL'
      Size = 100
    end
    object DocNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object DocCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object DocARTNOM: TFIBWideStringField
      FieldName = 'ARTNOM'
    end
    object DocNAME_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'NAME_REM_SHARDWARE'
      Size = 200
    end
    object DocCODE_REM_SHARDWARE: TFIBIntegerField
      FieldName = 'CODE_REM_SHARDWARE'
    end
    object DocSERNUM_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'SERNUM_REM_SHARDWARE'
    end
    object DocNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 200
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_DSBKOMPLT'
      'SET '
      '    IDBASE_REM_DSBKOMPLT = :IDBASE_REM_DSBKOMPLT,'
      '    IDDOC_REM_DSBKOMPLT = :IDDOC_REM_DSBKOMPLT,'
      '    GID_REM_DSBKOMPLT = :GID_REM_DSBKOMPLT,'
      '    IDNOM_REM_DSBKOMPLT = :IDNOM_REM_DSBKOMPLT,'
      '    IDED_REM_DSBKOMPLT = :IDED_REM_DSBKOMPLT,'
      '    IDHW_REM_DSBKOMPLT = :IDHW_REM_DSBKOMPLT,'
      '    KOL_REM_DSBKOMPLT = :KOL_REM_DSBKOMPLT,'
      '    KF_REM_DSBKOMPLT = :KF_REM_DSBKOMPLT,'
      '    RPRICE_REM_DSBKOMPLT = :RPRICE_REM_DSBKOMPLT,'
      '    RSUM_REM_DSBKOMPLT = :RSUM_REM_DSBKOMPLT,'
      '    DVREG_REM_DSBKOMPLT = :DVREG_REM_DSBKOMPLT'
      'WHERE'
      '    ID_REM_DSBKOMPLT = :OLD_ID_REM_DSBKOMPLT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DSBKOMPLT'
      'WHERE'
      '        ID_REM_DSBKOMPLT = :OLD_ID_REM_DSBKOMPLT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DSBKOMPLT('
      '    ID_REM_DSBKOMPLT,'
      '    IDBASE_REM_DSBKOMPLT,'
      '    IDDOC_REM_DSBKOMPLT,'
      '    GID_REM_DSBKOMPLT,'
      '    IDNOM_REM_DSBKOMPLT,'
      '    IDED_REM_DSBKOMPLT,'
      '    IDHW_REM_DSBKOMPLT,'
      '    KOL_REM_DSBKOMPLT,'
      '    KF_REM_DSBKOMPLT,'
      '    RPRICE_REM_DSBKOMPLT,'
      '    RSUM_REM_DSBKOMPLT,'
      '    DVREG_REM_DSBKOMPLT'
      ')'
      'VALUES('
      '    :ID_REM_DSBKOMPLT,'
      '    :IDBASE_REM_DSBKOMPLT,'
      '    :IDDOC_REM_DSBKOMPLT,'
      '    :GID_REM_DSBKOMPLT,'
      '    :IDNOM_REM_DSBKOMPLT,'
      '    :IDED_REM_DSBKOMPLT,'
      '    :IDHW_REM_DSBKOMPLT,'
      '    :KOL_REM_DSBKOMPLT,'
      '    :KF_REM_DSBKOMPLT,'
      '    :RPRICE_REM_DSBKOMPLT,'
      '    :RSUM_REM_DSBKOMPLT,'
      '    :DVREG_REM_DSBKOMPLT'
      ')')
    RefreshSQL.Strings = (
      'select rem_dsbkomplt.*,'
      
        '  snom.krnamenom, snom.namenom,snom.tnom,snom.codenom,snom.artno' +
        'm,'
      '  sed.NAMEED,sed.shed,'
      '  snom.idgrpnom,'
      '  snom.idvid_snom,'
      '  sgrpnom.namegn,'
      '  svidnom.name_svidnom,'
      '  rem_shardware.name_rem_shardware,'
      '  rem_shardware.code_rem_shardware,'
      '  rem_shardware.sernum_rem_shardware'
      'from rem_dsbkomplt'
      
        'left outer join SNOM  ON rem_dsbkomplt.idnom_rem_dsbkomplt=snom.' +
        'idnom'
      
        'left outer join SED  on  rem_dsbkomplt.ided_rem_dsbkomplt=sed.id' +
        'ed'
      'left outer join sgrpnom on snom.idgrpnom=sgrpnom.idgn'
      'left outer join svidnom on snom.idvid_snom=svidnom.id_svidnom'
      
        'left outer join rem_shardware on rem_dsbkomplt.idhw_rem_dsbkompl' +
        't=rem_shardware.id_rem_shardware'
      'where(  rem_dsbkomplt.iddoc_rem_dsbkomplt=:PARAM_IDDOC'
      
        '     ) and (     REM_DSBKOMPLT.ID_REM_DSBKOMPLT = :OLD_ID_REM_DS' +
        'BKOMPLT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_dsbkomplt.*,'
      
        '  snom.krnamenom, snom.namenom,snom.tnom,snom.codenom,snom.artno' +
        'm,'
      '  sed.NAMEED,sed.shed,'
      '  snom.idgrpnom,'
      '  snom.idvid_snom,'
      '  sgrpnom.namegn,'
      '  svidnom.name_svidnom,'
      '  rem_shardware.name_rem_shardware,'
      '  rem_shardware.code_rem_shardware,'
      '  rem_shardware.sernum_rem_shardware'
      'from rem_dsbkomplt'
      
        'left outer join SNOM  ON rem_dsbkomplt.idnom_rem_dsbkomplt=snom.' +
        'idnom'
      
        'left outer join SED  on  rem_dsbkomplt.ided_rem_dsbkomplt=sed.id' +
        'ed'
      'left outer join sgrpnom on snom.idgrpnom=sgrpnom.idgn'
      'left outer join svidnom on snom.idvid_snom=svidnom.id_svidnom'
      
        'left outer join rem_shardware on rem_dsbkomplt.idhw_rem_dsbkompl' +
        't=rem_shardware.id_rem_shardware'
      'where rem_dsbkomplt.iddoc_rem_dsbkomplt=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_DSBKOMPLT'
    AutoUpdateOptions.KeyFields = 'ID_REM_DSBKOMPLT'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DSBKOMPLT_ID'
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
    object DocTID_REM_DSBKOMPLT: TFIBLargeIntField
      FieldName = 'ID_REM_DSBKOMPLT'
    end
    object DocTIDBASE_REM_DSBKOMPLT: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DSBKOMPLT'
    end
    object DocTIDDOC_REM_DSBKOMPLT: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DSBKOMPLT'
    end
    object DocTGID_REM_DSBKOMPLT: TFIBWideStringField
      FieldName = 'GID_REM_DSBKOMPLT'
      Size = 10
    end
    object DocTIDNOM_REM_DSBKOMPLT: TFIBLargeIntField
      FieldName = 'IDNOM_REM_DSBKOMPLT'
    end
    object DocTIDED_REM_DSBKOMPLT: TFIBLargeIntField
      FieldName = 'IDED_REM_DSBKOMPLT'
    end
    object DocTIDHW_REM_DSBKOMPLT: TFIBLargeIntField
      FieldName = 'IDHW_REM_DSBKOMPLT'
    end
    object DocTKOL_REM_DSBKOMPLT: TFIBBCDField
      FieldName = 'KOL_REM_DSBKOMPLT'
      OnChange = DocTKOL_REM_DSBKOMPLTChange
      Size = 3
      RoundByScale = True
    end
    object DocTKF_REM_DSBKOMPLT: TFIBBCDField
      FieldName = 'KF_REM_DSBKOMPLT'
      Size = 3
      RoundByScale = True
    end
    object DocTRPRICE_REM_DSBKOMPLT: TFIBBCDField
      FieldName = 'RPRICE_REM_DSBKOMPLT'
      OnChange = DocTRPRICE_REM_DSBKOMPLTChange
      Size = 2
      RoundByScale = True
    end
    object DocTRSUM_REM_DSBKOMPLT: TFIBBCDField
      FieldName = 'RSUM_REM_DSBKOMPLT'
      Size = 2
      RoundByScale = True
    end
    object DocTDVREG_REM_DSBKOMPLT: TFIBSmallIntField
      FieldName = 'DVREG_REM_DSBKOMPLT'
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
      'where rem_galldoc.tdoc_rem_galldoc='#39'REMSBKOMPL'#39
      '            and rem_galldoc.pos_rem_galldoc > :PARAM_POS')
    Transaction = IBTr
    Left = 368
    Top = 16
    object NumDocMAXNUMBER: TFIBIntegerField
      FieldName = 'MAXNUMBER'
    end
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      
        'EXECUTE PROCEDURE REM_DOC_SBKOMPL_CANCEL_DVREG(:PARAM_IDDOC,0,0,' +
        '0)')
    Left = 360
    Top = 224
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE REM_DOC_SBKOMPL_DVREG (:PARAM_IDDOC,0,0,0)')
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
