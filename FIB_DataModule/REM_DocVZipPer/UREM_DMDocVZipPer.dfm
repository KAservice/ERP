object REM_DMDocVZipPer: TREM_DMDocVZipPer
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
      'UPDATE REM_DVZPER'
      'SET '
      '    IDBASE_REM_DVZPER = :IDBASE_REM_DVZPER,'
      '    IDDOC_REM_DVZPER = :IDDOC_REM_DVZPER,'
      '    IDSKLADPOL_REM_DVZPER = :IDSKLADPOL_REM_DVZPER,'
      '    PRIM_REM_DVZPER = :PRIM_REM_DVZPER,'
      '    OPER_REM_DVZPER = :OPER_REM_DVZPER'
      'WHERE'
      '    ID_REM_DVZPER = :OLD_ID_REM_DVZPER'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DVZPER'
      'WHERE'
      '        ID_REM_DVZPER = :OLD_ID_REM_DVZPER'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DVZPER('
      '    ID_REM_DVZPER,'
      '    IDBASE_REM_DVZPER,'
      '    IDDOC_REM_DVZPER,'
      '    IDSKLADPOL_REM_DVZPER,'
      '    PRIM_REM_DVZPER,'
      '    OPER_REM_DVZPER'
      ')'
      'VALUES('
      '    :ID_REM_DVZPER,'
      '    :IDBASE_REM_DVZPER,'
      '    :IDDOC_REM_DVZPER,'
      '    :IDSKLADPOL_REM_DVZPER,'
      '    :PRIM_REM_DVZPER,'
      '    :OPER_REM_DVZPER'
      ')')
    RefreshSQL.Strings = (
      'select rem_dvzper.*,'
      '        ssklad.namesklad'
      'from  rem_dvzper'
      
        'left outer join ssklad on rem_dvzper.idskladpol_rem_dvzper=sskla' +
        'd.idsklad'
      'where(  rem_dvzper.iddoc_rem_dvzper=:PARAM_IDDOC'
      '     ) and (     REM_DVZPER.ID_REM_DVZPER = :OLD_ID_REM_DVZPER'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_dvzper.*,'
      '        ssklad.namesklad'
      'from  rem_dvzper'
      
        'left outer join ssklad on rem_dvzper.idskladpol_rem_dvzper=sskla' +
        'd.idsklad'
      'where rem_dvzper.iddoc_rem_dvzper=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_DVZPER'
    AutoUpdateOptions.KeyFields = 'ID_REM_DVZPER'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DVZPER_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object DocID_REM_DVZPER: TFIBLargeIntField
      FieldName = 'ID_REM_DVZPER'
    end
    object DocIDBASE_REM_DVZPER: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DVZPER'
    end
    object DocIDDOC_REM_DVZPER: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DVZPER'
    end
    object DocIDSKLADPOL_REM_DVZPER: TFIBLargeIntField
      FieldName = 'IDSKLADPOL_REM_DVZPER'
    end
    object DocPRIM_REM_DVZPER: TFIBWideStringField
      FieldName = 'PRIM_REM_DVZPER'
      Size = 100
    end
    object DocOPER_REM_DVZPER: TFIBIntegerField
      FieldName = 'OPER_REM_DVZPER'
    end
    object DocNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 200
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_DVZPERT'
      'SET '
      '    IDBASE_REM_DVZPERT = :IDBASE_REM_DVZPERT,'
      '    IDDOC_REM_DVZPERT = :IDDOC_REM_DVZPERT,'
      '    IDKLIENT_REM_DVZPERT = :IDKLIENT_REM_DVZPERT,'
      '    IDTNOM_REM_DVZPERT = :IDTNOM_REM_DVZPERT,'
      '    IDNOM_REM_DVZPERT = :IDNOM_REM_DVZPERT,'
      '    IDZ_REM_DVZPERT = :IDZ_REM_DVZPERT,'
      '    IDHW_REM_DVZPERT = :IDHW_REM_DVZPERT,'
      '    KOL_REM_DVZPERT = :KOL_REM_DVZPERT,'
      '    IDTVZIP_REM_DVZPERT = :IDTVZIP_REM_DVZPERT,'
      '    IDMHRAN_OTPR_REM_DVZPERT = :IDMHRAN_OTPR_REM_DVZPERT,'
      '    IDMHRAN_POL_REM_DVZPERT = :IDMHRAN_POL_REM_DVZPERT'
      'WHERE'
      '    ID_REM_DVZPERT = :OLD_ID_REM_DVZPERT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DVZPERT'
      'WHERE'
      '        ID_REM_DVZPERT = :OLD_ID_REM_DVZPERT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DVZPERT('
      '    ID_REM_DVZPERT,'
      '    IDBASE_REM_DVZPERT,'
      '    IDDOC_REM_DVZPERT,'
      '    IDKLIENT_REM_DVZPERT,'
      '    IDTNOM_REM_DVZPERT,'
      '    IDNOM_REM_DVZPERT,'
      '    IDZ_REM_DVZPERT,'
      '    IDHW_REM_DVZPERT,'
      '    KOL_REM_DVZPERT,'
      '    IDTVZIP_REM_DVZPERT,'
      '    IDMHRAN_OTPR_REM_DVZPERT,'
      '    IDMHRAN_POL_REM_DVZPERT'
      ')'
      'VALUES('
      '    :ID_REM_DVZPERT,'
      '    :IDBASE_REM_DVZPERT,'
      '    :IDDOC_REM_DVZPERT,'
      '    :IDKLIENT_REM_DVZPERT,'
      '    :IDTNOM_REM_DVZPERT,'
      '    :IDNOM_REM_DVZPERT,'
      '    :IDZ_REM_DVZPERT,'
      '    :IDHW_REM_DVZPERT,'
      '    :KOL_REM_DVZPERT,'
      '    :IDTVZIP_REM_DVZPERT,'
      '    :IDMHRAN_OTPR_REM_DVZPERT,'
      '    :IDMHRAN_POL_REM_DVZPERT'
      ')')
    RefreshSQL.Strings = (
      'select rem_dvzpert.*,'
      '        rem_z.name_rem_z,'
      '        rem_z.num_rem_z,'
      '        rem_z.pos_rem_z,'
      '        rem_z.sernum_rem_z,'
      '        rem_z.sernum2_rem_z,'
      '        rem_z.klient_name_rem_z,'
      '        rem_z.model_rem_z,'
      '        sklient.nameklient,'
      '        stnom.name_stnom,'
      '        snom.namenom,'
      '        rem_stvzip.name_rem_stvzip,'
      '        rem_shardware.name_rem_shardware,'
      '        rem_shardware.sernum_rem_shardware,'
      '        rem_shardware.sernum2_rem_shardware,'
      '        rem_sprmodel.name_rem_sprmodel,'
      '        smhran_otpr.name_smhran  as  name_smhran_otpr,'
      '        smhran_pol.name_smhran  as  name_smhran_pol'
      'from  rem_dvzpert'
      
        'left outer join sklient on rem_dvzpert.idklient_rem_dvzpert=skli' +
        'ent.idklient'
      
        'left outer join stnom on rem_dvzpert.idtnom_rem_dvzpert=stnom.id' +
        '_stnom'
      'left outer join snom on rem_dvzpert.idnom_rem_dvzpert=snom.idnom'
      
        'left outer join rem_z on rem_dvzpert.idz_rem_dvzpert=rem_z.id_re' +
        'm_z'
      
        'left outer join rem_shardware on rem_dvzpert.idhw_rem_dvzpert=re' +
        'm_shardware.id_rem_shardware'
      
        'left outer join rem_sprmodel on rem_shardware.idprmodel_rem_shar' +
        'dware=rem_sprmodel.id_rem_sprmodel'
      
        'left outer join rem_stvzip on rem_dvzpert.idtvzip_rem_dvzpert=re' +
        'm_stvzip.id_rem_stvzip'
      
        'left outer join smhran as smhran_otpr on rem_dvzpert.idmhran_otp' +
        'r_rem_dvzpert=smhran_otpr.id_smhran'
      
        'left outer join smhran as smhran_pol on rem_dvzpert.idmhran_pol_' +
        'rem_dvzpert=smhran_pol.id_smhran'
      'where(  rem_dvzpert.iddoc_rem_dvzpert=:PARAM_IDDOC'
      
        '     ) and (     REM_DVZPERT.ID_REM_DVZPERT = :OLD_ID_REM_DVZPER' +
        'T'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_dvzpert.*,'
      '        rem_z.name_rem_z,'
      '        rem_z.num_rem_z,'
      '        rem_z.pos_rem_z,'
      '        rem_z.sernum_rem_z,'
      '        rem_z.sernum2_rem_z,'
      '        rem_z.klient_name_rem_z,'
      '        rem_z.model_rem_z,'
      '        sklient.nameklient,'
      '        stnom.name_stnom,'
      '        snom.namenom,'
      '        rem_stvzip.name_rem_stvzip,'
      '        rem_shardware.name_rem_shardware,'
      '        rem_shardware.sernum_rem_shardware,'
      '        rem_shardware.sernum2_rem_shardware,'
      '        rem_sprmodel.name_rem_sprmodel,'
      '        smhran_otpr.name_smhran  as  name_smhran_otpr,'
      '        smhran_pol.name_smhran  as  name_smhran_pol'
      'from  rem_dvzpert'
      
        'left outer join sklient on rem_dvzpert.idklient_rem_dvzpert=skli' +
        'ent.idklient'
      
        'left outer join stnom on rem_dvzpert.idtnom_rem_dvzpert=stnom.id' +
        '_stnom'
      'left outer join snom on rem_dvzpert.idnom_rem_dvzpert=snom.idnom'
      
        'left outer join rem_z on rem_dvzpert.idz_rem_dvzpert=rem_z.id_re' +
        'm_z'
      
        'left outer join rem_shardware on rem_dvzpert.idhw_rem_dvzpert=re' +
        'm_shardware.id_rem_shardware'
      
        'left outer join rem_sprmodel on rem_shardware.idprmodel_rem_shar' +
        'dware=rem_sprmodel.id_rem_sprmodel'
      
        'left outer join rem_stvzip on rem_dvzpert.idtvzip_rem_dvzpert=re' +
        'm_stvzip.id_rem_stvzip'
      
        'left outer join smhran as smhran_otpr on rem_dvzpert.idmhran_otp' +
        'r_rem_dvzpert=smhran_otpr.id_smhran'
      
        'left outer join smhran as smhran_pol on rem_dvzpert.idmhran_pol_' +
        'rem_dvzpert=smhran_pol.id_smhran'
      'where rem_dvzpert.iddoc_rem_dvzpert=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_DVZPERT'
    AutoUpdateOptions.KeyFields = 'ID_REM_DVZPERT'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DVZPERT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnCalcFields = DocTCalcFields
    OnNewRecord = DocTNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 112
    poUseLargeIntField = True
    object DocTID_REM_DVZPERT: TFIBLargeIntField
      FieldName = 'ID_REM_DVZPERT'
    end
    object DocTIDBASE_REM_DVZPERT: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DVZPERT'
    end
    object DocTIDDOC_REM_DVZPERT: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DVZPERT'
    end
    object DocTIDKLIENT_REM_DVZPERT: TFIBLargeIntField
      FieldName = 'IDKLIENT_REM_DVZPERT'
    end
    object DocTIDTNOM_REM_DVZPERT: TFIBLargeIntField
      FieldName = 'IDTNOM_REM_DVZPERT'
    end
    object DocTIDNOM_REM_DVZPERT: TFIBLargeIntField
      FieldName = 'IDNOM_REM_DVZPERT'
    end
    object DocTIDZ_REM_DVZPERT: TFIBLargeIntField
      FieldName = 'IDZ_REM_DVZPERT'
    end
    object DocTIDHW_REM_DVZPERT: TFIBLargeIntField
      FieldName = 'IDHW_REM_DVZPERT'
    end
    object DocTKOL_REM_DVZPERT: TFIBBCDField
      FieldName = 'KOL_REM_DVZPERT'
      Size = 3
      RoundByScale = True
    end
    object DocTIDTVZIP_REM_DVZPERT: TFIBLargeIntField
      FieldName = 'IDTVZIP_REM_DVZPERT'
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
    object DocTNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 200
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
    object DocTIDMHRAN_OTPR_REM_DVZPERT: TFIBLargeIntField
      FieldName = 'IDMHRAN_OTPR_REM_DVZPERT'
    end
    object DocTIDMHRAN_POL_REM_DVZPERT: TFIBLargeIntField
      FieldName = 'IDMHRAN_POL_REM_DVZPERT'
    end
    object DocTNAME_SMHRAN_OTPR: TFIBWideStringField
      FieldName = 'NAME_SMHRAN_OTPR'
      Size = 200
    end
    object DocTNAME_SMHRAN_POL: TFIBWideStringField
      FieldName = 'NAME_SMHRAN_POL'
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
      
        'from rem_doc_vzper_get_num_new_doc (:PARAM_IDBASE,:PARAM_IDFIRM,' +
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
      'EXECUTE PROCEDURE rem_doc_vzper_cancel_dvreg(:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 304
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE rem_doc_vzper_dvreg (:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 240
    qoStartTransaction = True
  end
end
