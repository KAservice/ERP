object REM_DMDocVosvratHW: TREM_DMDocVosvratHW
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 379
  Width = 709
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
  end
  object Doc: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_DVOSVRAT_HW'
      'SET '
      '    IDBASE_REM_DVOSVRAT_HW = :IDBASE_REM_DVOSVRAT_HW,'
      '    GID_REM_DVOSVRAT_HW = :GID_REM_DVOSVRAT_HW,'
      '    IDDOC_REM_DVOSVRAT_HW = :IDDOC_REM_DVOSVRAT_HW,'
      '    PRIM_REM_DVOSVRAT_HW = :PRIM_REM_DVOSVRAT_HW,'
      '    IDZ_REM_DVOSVRAT_HW = :IDZ_REM_DVOSVRAT_HW,'
      '    IDHW_REM_DVOSVRAT_HW = :IDHW_REM_DVOSVRAT_HW,'
      '    IDKKT_REM_DVOSVRAT_HW = :IDKKT_REM_DVOSVRAT_HW'
      'WHERE'
      '    ID_REM_DVOSVRAT_HW = :OLD_ID_REM_DVOSVRAT_HW'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DVOSVRAT_HW'
      'WHERE'
      '        ID_REM_DVOSVRAT_HW = :OLD_ID_REM_DVOSVRAT_HW'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DVOSVRAT_HW('
      '    ID_REM_DVOSVRAT_HW,'
      '    IDBASE_REM_DVOSVRAT_HW,'
      '    GID_REM_DVOSVRAT_HW,'
      '    IDDOC_REM_DVOSVRAT_HW,'
      '    PRIM_REM_DVOSVRAT_HW,'
      '    IDZ_REM_DVOSVRAT_HW,'
      '    IDHW_REM_DVOSVRAT_HW,'
      '    IDKKT_REM_DVOSVRAT_HW'
      ')'
      'VALUES('
      '    :ID_REM_DVOSVRAT_HW,'
      '    :IDBASE_REM_DVOSVRAT_HW,'
      '    :GID_REM_DVOSVRAT_HW,'
      '    :IDDOC_REM_DVOSVRAT_HW,'
      '    :PRIM_REM_DVOSVRAT_HW,'
      '    :IDZ_REM_DVOSVRAT_HW,'
      '    :IDHW_REM_DVOSVRAT_HW,'
      '    :IDKKT_REM_DVOSVRAT_HW'
      ')')
    RefreshSQL.Strings = (
      'select rem_dvosvrat_hw.*,'
      '        rem_shardware.name_rem_shardware,'
      '        rem_shardware.code_rem_shardware,'
      '        rem_shardware.sernum_rem_shardware,'
      '        rem_shardware.sernum2_rem_shardware,'
      '        rem_smodel.name_rem_smodel,'
      '        rem_smodel.code_rem_smodel,'
      '        rem_sprmodel.code_rem_sprmodel,'
      '        rem_sprmodel.name_rem_sprmodel,'
      '        rem_z.name_rem_z,'
      '        rem_z.prefiks_num_rem_z,'
      '        rem_z.num_rem_z,'
      '        rem_z.pos_rem_z,'
      '        rem_z.model_rem_z,'
      '        rem_z.sernum_rem_z,'
      '        rem_z.sernum2_rem_z'
      'from  rem_dvosvrat_hw'
      
        'left outer join rem_shardware on rem_shardware.id_rem_shardware=' +
        'rem_dvosvrat_hw.idhw_rem_dvosvrat_hw'
      
        'left outer join rem_smodel on rem_smodel.id_rem_smodel=rem_shard' +
        'ware.idmodel_rem_shardware'
      
        'left outer join rem_sprmodel on rem_sprmodel.id_rem_sprmodel=rem' +
        '_shardware.idprmodel_rem_shardware'
      
        'left outer join rem_z on rem_z.id_rem_z=rem_dvosvrat_hw.idz_rem_' +
        'dvosvrat_hw'
      'where(  rem_dvosvrat_hw.iddoc_rem_dvosvrat_hw=:PARAM_IDDOC'
      
        '     ) and (     REM_DVOSVRAT_HW.ID_REM_DVOSVRAT_HW = :OLD_ID_RE' +
        'M_DVOSVRAT_HW'
      '     )'
      '    '
      '')
    SelectSQL.Strings = (
      'select rem_dvosvrat_hw.*,'
      '        rem_shardware.name_rem_shardware,'
      '        rem_shardware.code_rem_shardware,'
      '        rem_shardware.sernum_rem_shardware,'
      '        rem_shardware.sernum2_rem_shardware,'
      '        rem_smodel.name_rem_smodel,'
      '        rem_smodel.code_rem_smodel,'
      '        rem_sprmodel.code_rem_sprmodel,'
      '        rem_sprmodel.name_rem_sprmodel,'
      '        rem_z.name_rem_z,'
      '        rem_z.prefiks_num_rem_z,'
      '        rem_z.num_rem_z,'
      '        rem_z.pos_rem_z,'
      '        rem_z.model_rem_z,'
      '        rem_z.sernum_rem_z,'
      '        rem_z.sernum2_rem_z'
      'from  rem_dvosvrat_hw'
      
        'left outer join rem_shardware on rem_shardware.id_rem_shardware=' +
        'rem_dvosvrat_hw.idhw_rem_dvosvrat_hw'
      
        'left outer join rem_smodel on rem_smodel.id_rem_smodel=rem_shard' +
        'ware.idmodel_rem_shardware'
      
        'left outer join rem_sprmodel on rem_sprmodel.id_rem_sprmodel=rem' +
        '_shardware.idprmodel_rem_shardware'
      
        'left outer join rem_z on rem_z.id_rem_z=rem_dvosvrat_hw.idz_rem_' +
        'dvosvrat_hw'
      'where rem_dvosvrat_hw.iddoc_rem_dvosvrat_hw=:PARAM_IDDOC'
      '')
    AutoUpdateOptions.UpdateTableName = 'REM_DVOSVRAT_HW'
    AutoUpdateOptions.KeyFields = 'ID_REM_DVOSVRAT_HW'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DVOSVRAT_HW_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object DocID_REM_DVOSVRAT_HW: TFIBLargeIntField
      FieldName = 'ID_REM_DVOSVRAT_HW'
    end
    object DocIDBASE_REM_DVOSVRAT_HW: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DVOSVRAT_HW'
    end
    object DocGID_REM_DVOSVRAT_HW: TFIBWideStringField
      FieldName = 'GID_REM_DVOSVRAT_HW'
      Size = 10
    end
    object DocIDDOC_REM_DVOSVRAT_HW: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DVOSVRAT_HW'
    end
    object DocPRIM_REM_DVOSVRAT_HW: TFIBWideStringField
      FieldName = 'PRIM_REM_DVOSVRAT_HW'
      Size = 100
    end
    object DocIDZ_REM_DVOSVRAT_HW: TFIBLargeIntField
      FieldName = 'IDZ_REM_DVOSVRAT_HW'
    end
    object DocIDHW_REM_DVOSVRAT_HW: TFIBLargeIntField
      FieldName = 'IDHW_REM_DVOSVRAT_HW'
    end
    object DocIDKKT_REM_DVOSVRAT_HW: TFIBLargeIntField
      FieldName = 'IDKKT_REM_DVOSVRAT_HW'
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
      Size = 50
    end
    object DocSERNUM2_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'SERNUM2_REM_SHARDWARE'
      Size = 50
    end
    object DocNAME_REM_SMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SMODEL'
      Size = 200
    end
    object DocCODE_REM_SMODEL: TFIBWideStringField
      FieldName = 'CODE_REM_SMODEL'
    end
    object DocCODE_REM_SPRMODEL: TFIBWideStringField
      FieldName = 'CODE_REM_SPRMODEL'
    end
    object DocNAME_REM_SPRMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SPRMODEL'
      Size = 200
    end
    object DocNAME_REM_Z: TFIBWideStringField
      FieldName = 'NAME_REM_Z'
      Size = 200
    end
    object DocPREFIKS_NUM_REM_Z: TFIBWideStringField
      FieldName = 'PREFIKS_NUM_REM_Z'
      Size = 12
    end
    object DocNUM_REM_Z: TFIBIntegerField
      FieldName = 'NUM_REM_Z'
    end
    object DocPOS_REM_Z: TFIBDateTimeField
      FieldName = 'POS_REM_Z'
    end
    object DocMODEL_REM_Z: TFIBWideStringField
      FieldName = 'MODEL_REM_Z'
      Size = 40
    end
    object DocSERNUM_REM_Z: TFIBWideStringField
      FieldName = 'SERNUM_REM_Z'
      Size = 50
    end
    object DocSERNUM2_REM_Z: TFIBWideStringField
      FieldName = 'SERNUM2_REM_Z'
      Size = 50
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_DVOSVRAT_HWT'
      'SET '
      '    IDBASE_REM_DVOSVRAT_HWT = :IDBASE_REM_DVOSVRAT_HWT,'
      '    GID_REM_DVOSVRAT_HWT = :GID_REM_DVOSVRAT_HWT,'
      '    IDDOC_REM_DVOSVRAT_HWT = :IDDOC_REM_DVOSVRAT_HWT,'
      '    IDHW_REM_DVOSVRAT_HWT = :IDHW_REM_DVOSVRAT_HWT,'
      '    KF_REM_DVOSVRAT_HWT = :KF_REM_DVOSVRAT_HWT,'
      '    KOL_REM_DVOSVRAT_HWT = :KOL_REM_DVOSVRAT_HWT'
      'WHERE'
      '    ID_REM_DVOSVRAT_HWT = :OLD_ID_REM_DVOSVRAT_HWT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DVOSVRAT_HWT'
      'WHERE'
      '        ID_REM_DVOSVRAT_HWT = :OLD_ID_REM_DVOSVRAT_HWT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DVOSVRAT_HWT('
      '    ID_REM_DVOSVRAT_HWT,'
      '    IDBASE_REM_DVOSVRAT_HWT,'
      '    GID_REM_DVOSVRAT_HWT,'
      '    IDDOC_REM_DVOSVRAT_HWT,'
      '    IDHW_REM_DVOSVRAT_HWT,'
      '    KF_REM_DVOSVRAT_HWT,'
      '    KOL_REM_DVOSVRAT_HWT'
      ')'
      'VALUES('
      '    :ID_REM_DVOSVRAT_HWT,'
      '    :IDBASE_REM_DVOSVRAT_HWT,'
      '    :GID_REM_DVOSVRAT_HWT,'
      '    :IDDOC_REM_DVOSVRAT_HWT,'
      '    :IDHW_REM_DVOSVRAT_HWT,'
      '    :KF_REM_DVOSVRAT_HWT,'
      '    :KOL_REM_DVOSVRAT_HWT'
      ')')
    RefreshSQL.Strings = (
      'select rem_dvosvrat_hwt.*,'
      '        rem_shardware.name_rem_shardware,'
      '        rem_shardware.code_rem_shardware,'
      '        rem_shardware.sernum_rem_shardware,'
      '        rem_shardware.sernum2_rem_shardware,'
      '        rem_smodel.name_rem_smodel,'
      '        rem_smodel.code_rem_smodel,'
      '        rem_sprmodel.code_rem_sprmodel,'
      '        rem_sprmodel.name_rem_sprmodel'
      'from  rem_dvosvrat_hwt'
      
        'left outer join rem_shardware on rem_shardware.id_rem_shardware=' +
        'rem_dvosvrat_hwt.idhw_rem_dvosvrat_hwt'
      
        'left outer join rem_smodel on rem_smodel.id_rem_smodel=rem_shard' +
        'ware.idmodel_rem_shardware'
      
        'left outer join rem_sprmodel on rem_sprmodel.id_rem_sprmodel=rem' +
        '_shardware.idprmodel_rem_shardware'
      ''
      'where(  rem_dvosvrat_hwt.iddoc_rem_dvosvrat_hwt=:PARAM_IDDOC'
      
        '     ) and (     REM_DVOSVRAT_HWT.ID_REM_DVOSVRAT_HWT = :OLD_ID_' +
        'REM_DVOSVRAT_HWT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_dvosvrat_hwt.*,'
      '        rem_shardware.name_rem_shardware,'
      '        rem_shardware.code_rem_shardware,'
      '        rem_shardware.sernum_rem_shardware,'
      '        rem_shardware.sernum2_rem_shardware,'
      '        rem_smodel.name_rem_smodel,'
      '        rem_smodel.code_rem_smodel,'
      '        rem_sprmodel.code_rem_sprmodel,'
      '        rem_sprmodel.name_rem_sprmodel'
      'from  rem_dvosvrat_hwt'
      
        'left outer join rem_shardware on rem_shardware.id_rem_shardware=' +
        'rem_dvosvrat_hwt.idhw_rem_dvosvrat_hwt'
      
        'left outer join rem_smodel on rem_smodel.id_rem_smodel=rem_shard' +
        'ware.idmodel_rem_shardware'
      
        'left outer join rem_sprmodel on rem_sprmodel.id_rem_sprmodel=rem' +
        '_shardware.idprmodel_rem_shardware'
      ''
      'where rem_dvosvrat_hwt.iddoc_rem_dvosvrat_hwt=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_DVOSVRAT_HWT'
    AutoUpdateOptions.KeyFields = 'ID_REM_DVOSVRAT_HWT'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DVOSVRAT_HWT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnCalcFields = DocTCalcFields
    OnNewRecord = DocTNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 112
    poUseLargeIntField = True
    object DocTID_REM_DVOSVRAT_HWT: TFIBLargeIntField
      FieldName = 'ID_REM_DVOSVRAT_HWT'
    end
    object DocTIDBASE_REM_DVOSVRAT_HWT: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DVOSVRAT_HWT'
    end
    object DocTGID_REM_DVOSVRAT_HWT: TFIBWideStringField
      FieldName = 'GID_REM_DVOSVRAT_HWT'
      Size = 10
    end
    object DocTIDDOC_REM_DVOSVRAT_HWT: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DVOSVRAT_HWT'
    end
    object DocTIDHW_REM_DVOSVRAT_HWT: TFIBLargeIntField
      FieldName = 'IDHW_REM_DVOSVRAT_HWT'
    end
    object DocTKF_REM_DVOSVRAT_HWT: TFIBBCDField
      FieldName = 'KF_REM_DVOSVRAT_HWT'
      Size = 3
      RoundByScale = True
    end
    object DocTKOL_REM_DVOSVRAT_HWT: TFIBBCDField
      FieldName = 'KOL_REM_DVOSVRAT_HWT'
      Size = 3
      RoundByScale = True
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
    object DocTSERNUM2_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'SERNUM2_REM_SHARDWARE'
      Size = 50
    end
    object DocTNAME_REM_SMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SMODEL'
      Size = 200
    end
    object DocTCODE_REM_SMODEL: TFIBWideStringField
      FieldName = 'CODE_REM_SMODEL'
    end
    object DocTCODE_REM_SPRMODEL: TFIBWideStringField
      FieldName = 'CODE_REM_SPRMODEL'
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
      
        'where TDOC_REM_GALLDOC='#39'REM_VOSVRAT_HW'#39' and POS_REM_GALLDOC > :P' +
        'ARAM_POS')
    Left = 296
    Top = 16
    object NumDocMAXNUMBER: TFIBIntegerField
      FieldName = 'MAXNUMBER'
    end
  end
  object pFIBQ: TpFIBQuery
    Left = 336
    Top = 176
    qoStartTransaction = True
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      
        'EXECUTE PROCEDURE REM_DOC_VOSVRAT_HW_CANCEL_DVREG(:PARAM_IDDOC,0' +
        ',0,0)')
    Left = 96
    Top = 304
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE REM_DOC_VOSVRAT_HW_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 240
    qoStartTransaction = True
  end
end
