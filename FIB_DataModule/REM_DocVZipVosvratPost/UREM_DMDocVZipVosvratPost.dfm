object REM_DMDocVZipVosvratPost: TREM_DMDocVZipVosvratPost
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 420
  Width = 743
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
      '    PREFIKS_NUM_REM_GALLDOC = :PREFIKS_NUM_REM_GALLDOC,'
      '    IDOBJECT_REM_GALLDOC = :IDOBJECT_REM_GALLDOC'
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
      '    PREFIKS_NUM_REM_GALLDOC,'
      '    IDOBJECT_REM_GALLDOC'
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
      '    :PREFIKS_NUM_REM_GALLDOC,'
      '    :IDOBJECT_REM_GALLDOC'
      ')')
    RefreshSQL.Strings = (
      'select rem_galldoc.*,'
      ' suser.fname_user ,'
      ' sinfbase_obmen.name_sinfbase_obmen,'
      ' sfirm.namefirm,'
      ' ssklad.namesklad,'
      ' sklient.nameklient,'
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper,'
      ' sobject.name_sobject'
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
      
        'left outer join sobject on rem_galldoc.idobject_rem_galldoc=sobj' +
        'ect.id_sobject'
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
      ' sbusiness_oper.name_sbusiness_oper,'
      ' sobject.name_sobject'
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
      
        'left outer join sobject on rem_galldoc.idobject_rem_galldoc=sobj' +
        'ect.id_sobject'
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
    object DocAllIDOBJECT_REM_GALLDOC: TFIBLargeIntField
      FieldName = 'IDOBJECT_REM_GALLDOC'
    end
    object DocAllNAME_SOBJECT: TFIBWideStringField
      FieldName = 'NAME_SOBJECT'
      Size = 200
    end
  end
  object Doc: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_DVZVPO'
      'SET '
      '    IDBASE_REM_DVZVPO = :IDBASE_REM_DVZVPO,'
      '    IDDOC_REM_DVZVPO = :IDDOC_REM_DVZVPO,'
      '    DESCR_REM_DVZVPO = :DESCR_REM_DVZVPO,'
      '    OPER_REM_DVZVPO = :OPER_REM_DVZVPO'
      'WHERE'
      '    ID_REM_DVZVPO = :OLD_ID_REM_DVZVPO'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DVZVPO'
      'WHERE'
      '        ID_REM_DVZVPO = :OLD_ID_REM_DVZVPO'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DVZVPO('
      '    ID_REM_DVZVPO,'
      '    IDBASE_REM_DVZVPO,'
      '    IDDOC_REM_DVZVPO,'
      '    DESCR_REM_DVZVPO,'
      '    OPER_REM_DVZVPO'
      ')'
      'VALUES('
      '    :ID_REM_DVZVPO,'
      '    :IDBASE_REM_DVZVPO,'
      '    :IDDOC_REM_DVZVPO,'
      '    :DESCR_REM_DVZVPO,'
      '    :OPER_REM_DVZVPO'
      ')')
    RefreshSQL.Strings = (
      'select rem_dvzvpo.*'
      'from  rem_dvzvpo'
      'where(  rem_dvzvpo.iddoc_rem_dvzvpo=:PARAM_IDDOC'
      '     ) and (     REM_DVZVPO.ID_REM_DVZVPO = :OLD_ID_REM_DVZVPO'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_dvzvpo.*'
      'from  rem_dvzvpo'
      'where rem_dvzvpo.iddoc_rem_dvzvpo=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_DVZVPO'
    AutoUpdateOptions.KeyFields = 'ID_REM_DVZVPO'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DVZVPO_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object DocID_REM_DVZVPO: TFIBLargeIntField
      FieldName = 'ID_REM_DVZVPO'
    end
    object DocIDBASE_REM_DVZVPO: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DVZVPO'
    end
    object DocIDDOC_REM_DVZVPO: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DVZVPO'
    end
    object DocDESCR_REM_DVZVPO: TFIBWideStringField
      FieldName = 'DESCR_REM_DVZVPO'
      Size = 100
    end
    object DocOPER_REM_DVZVPO: TFIBIntegerField
      FieldName = 'OPER_REM_DVZVPO'
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_DVZVPOT'
      'SET '
      '    IDBASE_REM_DVZVPOT = :IDBASE_REM_DVZVPOT,'
      '    IDDOC_REM_DVZVPOT = :IDDOC_REM_DVZVPOT,'
      '    IDTNOM_REM_DVZVPOT = :IDTNOM_REM_DVZVPOT,'
      '    IDNOM_REM_DVZVPOT = :IDNOM_REM_DVZVPOT,'
      '    IDZ_REM_DVZVPOT = :IDZ_REM_DVZVPOT,'
      '    IDHW_REM_DVZVPOT = :IDHW_REM_DVZVPOT,'
      '    IDTVZIP_REM_DVZVPOT = :IDTVZIP_REM_DVZVPOT,'
      '    KOL_REM_DVZVPOT = :KOL_REM_DVZVPOT,'
      '    IDMHRAN_REM_DVZVPOT = :IDMHRAN_REM_DVZVPOT'
      'WHERE'
      '    ID_REM_DVZVPOT = :OLD_ID_REM_DVZVPOT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DVZVPOT'
      'WHERE'
      '        ID_REM_DVZVPOT = :OLD_ID_REM_DVZVPOT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DVZVPOT('
      '    ID_REM_DVZVPOT,'
      '    IDBASE_REM_DVZVPOT,'
      '    IDDOC_REM_DVZVPOT,'
      '    IDTNOM_REM_DVZVPOT,'
      '    IDNOM_REM_DVZVPOT,'
      '    IDZ_REM_DVZVPOT,'
      '    IDHW_REM_DVZVPOT,'
      '    IDTVZIP_REM_DVZVPOT,'
      '    KOL_REM_DVZVPOT,'
      '    IDMHRAN_REM_DVZVPOT'
      ')'
      'VALUES('
      '    :ID_REM_DVZVPOT,'
      '    :IDBASE_REM_DVZVPOT,'
      '    :IDDOC_REM_DVZVPOT,'
      '    :IDTNOM_REM_DVZVPOT,'
      '    :IDNOM_REM_DVZVPOT,'
      '    :IDZ_REM_DVZVPOT,'
      '    :IDHW_REM_DVZVPOT,'
      '    :IDTVZIP_REM_DVZVPOT,'
      '    :KOL_REM_DVZVPOT,'
      '    :IDMHRAN_REM_DVZVPOT'
      ')')
    RefreshSQL.Strings = (
      'select rem_dvzvpot.*,'
      '        rem_z.name_rem_z,'
      '        rem_z.num_rem_z,'
      '        rem_z.pos_rem_z,'
      '        rem_z.sernum_rem_z,'
      '        rem_z.sernum2_rem_z,'
      '        rem_z.klient_name_rem_z,'
      '        rem_z.model_rem_z,'
      '        stnom.name_stnom,'
      '        snom.namenom,'
      '        snom.codenom,'
      '        snom.artnom,'
      '        rem_stvzip.name_rem_stvzip,'
      '        rem_shardware.name_rem_shardware,'
      '        rem_shardware.sernum_rem_shardware,'
      '        rem_shardware.sernum2_rem_shardware,'
      '        rem_sprmodel.name_rem_sprmodel,'
      '        smhran.name_smhran'
      'from  rem_dvzvpot'
      
        'left outer join stnom on rem_dvzvpot.idtnom_rem_dvzvpot=stnom.id' +
        '_stnom'
      'left outer join snom on rem_dvzvpot.idnom_rem_dvzvpot=snom.idnom'
      
        'left outer join rem_z on rem_dvzvpot.idz_rem_dvzvpot=rem_z.id_re' +
        'm_z'
      
        'left outer join rem_shardware on rem_dvzvpot.idhw_rem_dvzvpot=re' +
        'm_shardware.id_rem_shardware'
      
        'left outer join rem_sprmodel on rem_shardware.idprmodel_rem_shar' +
        'dware=rem_sprmodel.id_rem_sprmodel'
      
        'left outer join rem_stvzip on rem_dvzvpot.idtvzip_rem_dvzvpot=re' +
        'm_stvzip.id_rem_stvzip'
      
        'left outer join smhran on rem_dvzvpot.idmhran_rem_dvzvpot=smhran' +
        '.id_smhran'
      'where(  rem_dvzvpot.iddoc_rem_dvzvpot=:PARAM_IDDOC'
      
        '     ) and (     REM_DVZVPOT.ID_REM_DVZVPOT = :OLD_ID_REM_DVZVPO' +
        'T'
      '     )'
      '    '
      '')
    SelectSQL.Strings = (
      'select rem_dvzvpot.*,'
      '        rem_z.name_rem_z,'
      '        rem_z.num_rem_z,'
      '        rem_z.pos_rem_z,'
      '        rem_z.sernum_rem_z,'
      '        rem_z.sernum2_rem_z,'
      '        rem_z.klient_name_rem_z,'
      '        rem_z.model_rem_z,'
      '        stnom.name_stnom,'
      '        snom.namenom,'
      '        snom.codenom,'
      '        snom.artnom,'
      '        rem_stvzip.name_rem_stvzip,'
      '        rem_shardware.name_rem_shardware,'
      '        rem_shardware.sernum_rem_shardware,'
      '        rem_shardware.sernum2_rem_shardware,'
      '        rem_sprmodel.name_rem_sprmodel,'
      '        smhran.name_smhran'
      'from  rem_dvzvpot'
      
        'left outer join stnom on rem_dvzvpot.idtnom_rem_dvzvpot=stnom.id' +
        '_stnom'
      'left outer join snom on rem_dvzvpot.idnom_rem_dvzvpot=snom.idnom'
      
        'left outer join rem_z on rem_dvzvpot.idz_rem_dvzvpot=rem_z.id_re' +
        'm_z'
      
        'left outer join rem_shardware on rem_dvzvpot.idhw_rem_dvzvpot=re' +
        'm_shardware.id_rem_shardware'
      
        'left outer join rem_sprmodel on rem_shardware.idprmodel_rem_shar' +
        'dware=rem_sprmodel.id_rem_sprmodel'
      
        'left outer join rem_stvzip on rem_dvzvpot.idtvzip_rem_dvzvpot=re' +
        'm_stvzip.id_rem_stvzip'
      
        'left outer join smhran on rem_dvzvpot.idmhran_rem_dvzvpot=smhran' +
        '.id_smhran'
      'where rem_dvzvpot.iddoc_rem_dvzvpot=:PARAM_IDDOC'
      '')
    AutoUpdateOptions.UpdateTableName = 'REM_DVZVPOT'
    AutoUpdateOptions.KeyFields = 'ID_REM_DVZVPOT'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DVZVPOT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnCalcFields = DocTCalcFields
    OnNewRecord = DocTNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 112
    poUseLargeIntField = True
    object DocTID_REM_DVZVPOT: TFIBLargeIntField
      FieldName = 'ID_REM_DVZVPOT'
    end
    object DocTIDBASE_REM_DVZVPOT: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DVZVPOT'
    end
    object DocTIDDOC_REM_DVZVPOT: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DVZVPOT'
    end
    object DocTIDTNOM_REM_DVZVPOT: TFIBLargeIntField
      FieldName = 'IDTNOM_REM_DVZVPOT'
    end
    object DocTIDNOM_REM_DVZVPOT: TFIBLargeIntField
      FieldName = 'IDNOM_REM_DVZVPOT'
    end
    object DocTIDZ_REM_DVZVPOT: TFIBLargeIntField
      FieldName = 'IDZ_REM_DVZVPOT'
    end
    object DocTIDHW_REM_DVZVPOT: TFIBLargeIntField
      FieldName = 'IDHW_REM_DVZVPOT'
    end
    object DocTIDTVZIP_REM_DVZVPOT: TFIBLargeIntField
      FieldName = 'IDTVZIP_REM_DVZVPOT'
    end
    object DocTKOL_REM_DVZVPOT: TFIBBCDField
      FieldName = 'KOL_REM_DVZVPOT'
      Size = 3
      RoundByScale = True
    end
    object DocTNAME_REM_Z: TFIBWideStringField
      FieldName = 'NAME_REM_Z'
      Size = 200
    end
    object DocTNUM_REM_Z: TFIBIntegerField
      FieldName = 'NUM_REM_Z'
    end
    object DocTPOS_REM_Z: TFIBDateTimeField
      FieldName = 'POS_REM_Z'
    end
    object DocTSERNUM_REM_Z: TFIBWideStringField
      FieldName = 'SERNUM_REM_Z'
      Size = 50
    end
    object DocTSERNUM2_REM_Z: TFIBWideStringField
      FieldName = 'SERNUM2_REM_Z'
      Size = 50
    end
    object DocTKLIENT_NAME_REM_Z: TFIBWideStringField
      FieldName = 'KLIENT_NAME_REM_Z'
      Size = 200
    end
    object DocTMODEL_REM_Z: TFIBWideStringField
      FieldName = 'MODEL_REM_Z'
      Size = 40
    end
    object DocTNAME_STNOM: TFIBWideStringField
      FieldName = 'NAME_STNOM'
      Size = 200
    end
    object DocTNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object DocTNAME_REM_STVZIP: TFIBWideStringField
      FieldName = 'NAME_REM_STVZIP'
      Size = 200
    end
    object DocTNAME_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'NAME_REM_SHARDWARE'
      Size = 200
    end
    object DocTSERNUM_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'SERNUM_REM_SHARDWARE'
      Size = 50
    end
    object DocTSERNUM2_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'SERNUM2_REM_SHARDWARE'
      Size = 50
    end
    object DocTNAME_REM_SPRMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SPRMODEL'
      Size = 200
    end
    object DocTRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object DocTCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object DocTARTNOM: TFIBWideStringField
      FieldName = 'ARTNOM'
      Size = 40
    end
    object DocTIDMHRAN_REM_DVZVPOT: TFIBLargeIntField
      FieldName = 'IDMHRAN_REM_DVZVPOT'
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
      'select *'
      
        'from rem_doc_vzvpo_get_num_new_doc (:PARAM_IDBASE,:PARAM_IDFIRM,' +
        ':PARAM_IDSKLAD)')
    Transaction = IBTr
    Left = 296
    Top = 16
  end
  object pFIBQ: TpFIBQuery
    Left = 336
    Top = 176
    qoStartTransaction = True
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE rem_doc_vzvpo_cancel_dvreg(:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 304
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE rem_doc_vzvpo_dvreg (:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 240
    qoStartTransaction = True
  end
end
