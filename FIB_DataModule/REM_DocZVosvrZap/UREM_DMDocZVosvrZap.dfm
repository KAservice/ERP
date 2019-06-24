object REM_DMDocZVosvrZap: TREM_DMDocZVosvrZap
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
      'UPDATE REM_DZVZAP'
      'SET '
      '    IDBASE_REM_DZVZAP = :IDBASE_REM_DZVZAP,'
      '    GID_REM_DZVZAP = :GID_REM_DZVZAP,'
      '    IDDOC_REM_DZVZAP = :IDDOC_REM_DZVZAP,'
      '    IDZ_REM_DZVZAP = :IDZ_REM_DZVZAP,'
      '    IDTPRICE_REM_DZVZAP = :IDTPRICE_REM_DZVZAP,'
      '    PRIM_REM_DZVZAP = :PRIM_REM_DZVZAP'
      'WHERE'
      '    ID_REM_DZVZAP = :OLD_ID_REM_DZVZAP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DZVZAP'
      'WHERE'
      '        ID_REM_DZVZAP = :OLD_ID_REM_DZVZAP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DZVZAP('
      '    ID_REM_DZVZAP,'
      '    IDBASE_REM_DZVZAP,'
      '    GID_REM_DZVZAP,'
      '    IDDOC_REM_DZVZAP,'
      '    IDZ_REM_DZVZAP,'
      '    IDTPRICE_REM_DZVZAP,'
      '    PRIM_REM_DZVZAP'
      ')'
      'VALUES('
      '    :ID_REM_DZVZAP,'
      '    :IDBASE_REM_DZVZAP,'
      '    :GID_REM_DZVZAP,'
      '    :IDDOC_REM_DZVZAP,'
      '    :IDZ_REM_DZVZAP,'
      '    :IDTPRICE_REM_DZVZAP,'
      '    :PRIM_REM_DZVZAP'
      ')')
    RefreshSQL.Strings = (
      'select rem_dzvzap.*,'
      '        rem_z.name_rem_z,'
      '        rem_z.num_rem_z,'
      '        rem_z.pos_rem_z,'
      '        rem_z.sernum_rem_z,'
      '        rem_z.sernum2_rem_z,'
      '        rem_z.klient_name_rem_z,'
      '        rem_z.model_rem_z,'
      '        rem_smodel.name_rem_smodel'
      'from  rem_dzvzap'
      
        'left outer join rem_z on rem_dzvzap.idz_rem_dzvzap=rem_z.id_rem_' +
        'z'
      
        'left outer join rem_smodel on rem_z.idmodel_rem_z=rem_smodel.id_' +
        'rem_smodel'
      'where(  rem_dzvzap.iddoc_rem_dzvzap=:PARAM_IDDOC'
      '     ) and (     REM_DZVZAP.ID_REM_DZVZAP = :OLD_ID_REM_DZVZAP'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_dzvzap.*,'
      '        rem_z.name_rem_z,'
      '        rem_z.num_rem_z,'
      '        rem_z.pos_rem_z,'
      '        rem_z.sernum_rem_z,'
      '        rem_z.sernum2_rem_z,'
      '        rem_z.klient_name_rem_z,'
      '        rem_z.model_rem_z,'
      '        rem_smodel.name_rem_smodel'
      'from  rem_dzvzap'
      
        'left outer join rem_z on rem_dzvzap.idz_rem_dzvzap=rem_z.id_rem_' +
        'z'
      
        'left outer join rem_smodel on rem_z.idmodel_rem_z=rem_smodel.id_' +
        'rem_smodel'
      'where rem_dzvzap.iddoc_rem_dzvzap=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_DZVZAP'
    AutoUpdateOptions.KeyFields = 'ID_REM_DZVZAP'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DZVZAP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object DocID_REM_DZVZAP: TFIBLargeIntField
      FieldName = 'ID_REM_DZVZAP'
    end
    object DocIDBASE_REM_DZVZAP: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DZVZAP'
    end
    object DocGID_REM_DZVZAP: TFIBWideStringField
      FieldName = 'GID_REM_DZVZAP'
      Size = 10
    end
    object DocIDDOC_REM_DZVZAP: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DZVZAP'
    end
    object DocIDZ_REM_DZVZAP: TFIBLargeIntField
      FieldName = 'IDZ_REM_DZVZAP'
    end
    object DocIDTPRICE_REM_DZVZAP: TFIBLargeIntField
      FieldName = 'IDTPRICE_REM_DZVZAP'
    end
    object DocPRIM_REM_DZVZAP: TFIBWideStringField
      FieldName = 'PRIM_REM_DZVZAP'
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
      'UPDATE REM_DZVZAPT'
      'SET '
      '    IDBASE_REM_DZVZAPT = :IDBASE_REM_DZVZAPT,'
      '    GID_REM_DZVZAPT = :GID_REM_DZVZAPT,'
      '    IDDOC_REM_DZVZAPT = :IDDOC_REM_DZVZAPT,'
      '    IDNOM_REM_DZVZAPT = :IDNOM_REM_DZVZAPT,'
      '    IDED_REM_DZVZAPT = :IDED_REM_DZVZAPT,'
      '    IDHW_REM_DZVZAPT = :IDHW_REM_DZVZAPT,'
      '    KOL_REM_DZVZAPT = :KOL_REM_DZVZAPT,'
      '    KF_REM_DZVZAPT = :KF_REM_DZVZAPT,'
      '    PRICE_REM_DZVZAPT = :PRICE_REM_DZVZAPT,'
      '    SUM_REM_DZVZAPT = :SUM_REM_DZVZAPT,'
      '    DVREG_REM_DZVZAPT = :DVREG_REM_DZVZAPT,'
      '    IDTNOM_REM_DZVZAPT = :IDTNOM_REM_DZVZAPT,'
      '    IDTVZIP_REM_DZVZAPT = :IDTVZIP_REM_DZVZAPT,'
      '    IDMHRAN_REM_DVZAPT = :IDMHRAN_REM_DVZAPT'
      'WHERE'
      '    ID_REM_DZVZAPT = :OLD_ID_REM_DZVZAPT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DZVZAPT'
      'WHERE'
      '        ID_REM_DZVZAPT = :OLD_ID_REM_DZVZAPT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DZVZAPT('
      '    ID_REM_DZVZAPT,'
      '    IDBASE_REM_DZVZAPT,'
      '    GID_REM_DZVZAPT,'
      '    IDDOC_REM_DZVZAPT,'
      '    IDNOM_REM_DZVZAPT,'
      '    IDED_REM_DZVZAPT,'
      '    IDHW_REM_DZVZAPT,'
      '    KOL_REM_DZVZAPT,'
      '    KF_REM_DZVZAPT,'
      '    PRICE_REM_DZVZAPT,'
      '    SUM_REM_DZVZAPT,'
      '    DVREG_REM_DZVZAPT,'
      '    IDTNOM_REM_DZVZAPT,'
      '    IDTVZIP_REM_DZVZAPT,'
      '    IDMHRAN_REM_DVZAPT'
      ')'
      'VALUES('
      '    :ID_REM_DZVZAPT,'
      '    :IDBASE_REM_DZVZAPT,'
      '    :GID_REM_DZVZAPT,'
      '    :IDDOC_REM_DZVZAPT,'
      '    :IDNOM_REM_DZVZAPT,'
      '    :IDED_REM_DZVZAPT,'
      '    :IDHW_REM_DZVZAPT,'
      '    :KOL_REM_DZVZAPT,'
      '    :KF_REM_DZVZAPT,'
      '    :PRICE_REM_DZVZAPT,'
      '    :SUM_REM_DZVZAPT,'
      '    :DVREG_REM_DZVZAPT,'
      '    :IDTNOM_REM_DZVZAPT,'
      '    :IDTVZIP_REM_DZVZAPT,'
      '    :IDMHRAN_REM_DVZAPT'
      ')')
    RefreshSQL.Strings = (
      'select rem_dzvzapt.*,'
      ' snom.namenom,'
      ' snom.codenom,'
      ' snom.artnom,'
      ' sed.nameed,'
      ' sed.shed,'
      ' rem_shardware.name_rem_shardware,'
      ' rem_shardware.code_rem_shardware,'
      ' rem_shardware.sernum_rem_shardware,'
      ' stnom.name_stnom,'
      ' rem_stvzip.name_rem_stvzip,'
      ' smhran.name_smhran'
      'from  rem_dzvzapt'
      'left outer join snom on rem_dzvzapt.idnom_rem_dzvzapt=snom.idnom'
      'left outer join sed on rem_dzvzapt.ided_rem_dzvzapt=sed.ided'
      
        'left outer join rem_shardware on rem_dzvzapt.idhw_rem_dzvzapt=re' +
        'm_shardware.id_rem_shardware'
      
        'left outer join stnom on rem_dzvzapt.idtnom_rem_dzvzapt=stnom.id' +
        '_stnom'
      
        'left outer join rem_stvzip on rem_dzvzapt.idtvzip_rem_dzvzapt=re' +
        'm_stvzip.id_rem_stvzip'
      
        'left outer join smhran on rem_dzvzapt.idmhran_rem_dvzapt=smhran.' +
        'id_smhran'
      'where(  rem_dzvzapt.iddoc_rem_dzvzapt=:PARAM_IDDOC'
      
        '     ) and (     REM_DZVZAPT.ID_REM_DZVZAPT = :OLD_ID_REM_DZVZAP' +
        'T'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_dzvzapt.*,'
      ' snom.namenom,'
      ' snom.codenom,'
      ' snom.artnom,'
      ' sed.nameed,'
      ' sed.shed,'
      ' rem_shardware.name_rem_shardware,'
      ' rem_shardware.code_rem_shardware,'
      ' rem_shardware.sernum_rem_shardware,'
      ' stnom.name_stnom,'
      ' rem_stvzip.name_rem_stvzip,'
      ' smhran.name_smhran'
      'from  rem_dzvzapt'
      'left outer join snom on rem_dzvzapt.idnom_rem_dzvzapt=snom.idnom'
      'left outer join sed on rem_dzvzapt.ided_rem_dzvzapt=sed.ided'
      
        'left outer join rem_shardware on rem_dzvzapt.idhw_rem_dzvzapt=re' +
        'm_shardware.id_rem_shardware'
      
        'left outer join stnom on rem_dzvzapt.idtnom_rem_dzvzapt=stnom.id' +
        '_stnom'
      
        'left outer join rem_stvzip on rem_dzvzapt.idtvzip_rem_dzvzapt=re' +
        'm_stvzip.id_rem_stvzip'
      
        'left outer join smhran on rem_dzvzapt.idmhran_rem_dvzapt=smhran.' +
        'id_smhran'
      'where rem_dzvzapt.iddoc_rem_dzvzapt=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_DZVZAPT'
    AutoUpdateOptions.KeyFields = 'ID_REM_DZVZAPT'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DZVZAPT_ID'
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
    object DocTID_REM_DZVZAPT: TFIBLargeIntField
      FieldName = 'ID_REM_DZVZAPT'
    end
    object DocTIDBASE_REM_DZVZAPT: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DZVZAPT'
    end
    object DocTGID_REM_DZVZAPT: TFIBWideStringField
      FieldName = 'GID_REM_DZVZAPT'
      Size = 10
    end
    object DocTIDDOC_REM_DZVZAPT: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DZVZAPT'
    end
    object DocTIDNOM_REM_DZVZAPT: TFIBLargeIntField
      FieldName = 'IDNOM_REM_DZVZAPT'
    end
    object DocTIDED_REM_DZVZAPT: TFIBLargeIntField
      FieldName = 'IDED_REM_DZVZAPT'
    end
    object DocTIDHW_REM_DZVZAPT: TFIBLargeIntField
      FieldName = 'IDHW_REM_DZVZAPT'
    end
    object DocTKOL_REM_DZVZAPT: TFIBBCDField
      FieldName = 'KOL_REM_DZVZAPT'
      OnChange = DocTKOL_REM_DZVZAPTChange
      Size = 3
      RoundByScale = True
    end
    object DocTKF_REM_DZVZAPT: TFIBBCDField
      FieldName = 'KF_REM_DZVZAPT'
      OnChange = DocTKF_REM_DZVZAPTChange
      Size = 3
      RoundByScale = True
    end
    object DocTPRICE_REM_DZVZAPT: TFIBBCDField
      FieldName = 'PRICE_REM_DZVZAPT'
      Size = 2
      RoundByScale = True
    end
    object DocTSUM_REM_DZVZAPT: TFIBBCDField
      FieldName = 'SUM_REM_DZVZAPT'
      Size = 2
      RoundByScale = True
    end
    object DocTDVREG_REM_DZVZAPT: TFIBSmallIntField
      FieldName = 'DVREG_REM_DZVZAPT'
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
    object DocTSERNUM_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'SERNUM_REM_SHARDWARE'
      Size = 50
    end
    object DocTIDTNOM_REM_DZVZAPT: TFIBLargeIntField
      FieldName = 'IDTNOM_REM_DZVZAPT'
    end
    object DocTNAME_TYPE_NOM_LOOKUP: TStringField
      FieldKind = fkLookup
      FieldName = 'NAME_TYPE_NOM_LOOKUP'
      LookupDataSet = TypeNom
      LookupKeyFields = 'ID_STNOM'
      LookupResultField = 'NAME_STNOM'
      KeyFields = 'IDTNOM_REM_DZVZAPT'
      Size = 50
      Lookup = True
    end
    object DocTIDTVZIP_REM_DZVZAPT: TFIBLargeIntField
      FieldName = 'IDTVZIP_REM_DZVZAPT'
    end
    object DocTIDMHRAN_REM_DVZAPT: TFIBLargeIntField
      FieldName = 'IDMHRAN_REM_DVZAPT'
    end
    object DocTNAME_STNOM: TFIBWideStringField
      FieldName = 'NAME_STNOM'
      Size = 200
    end
    object DocTNAME_REM_STVZIP: TFIBWideStringField
      FieldName = 'NAME_REM_STVZIP'
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
      
        'where TDOC_REM_GALLDOC='#39'REMZVZAP'#39' and POS_REM_GALLDOC > :PARAM_P' +
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
      'EXECUTE PROCEDURE REM_DOC_ZVZAP_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 304
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE REM_DOC_ZVZAP_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 240
    qoStartTransaction = True
  end
  object TypeNom: TpFIBDataSet
    SelectSQL.Strings = (
      'select stnom.id_stnom,'
      '       stnom.name_stnom'
      'from stnom'
      'order by stnom.name_stnom')
    Transaction = IBTr
    Left = 224
    Top = 176
    poUseLargeIntField = True
    object TypeNomID_STNOM: TFIBLargeIntField
      FieldName = 'ID_STNOM'
    end
    object TypeNomNAME_STNOM: TFIBWideStringField
      FieldName = 'NAME_STNOM'
      Size = 200
    end
  end
end
