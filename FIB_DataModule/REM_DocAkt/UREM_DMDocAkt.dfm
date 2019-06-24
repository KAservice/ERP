object REM_DMDocAkt: TREM_DMDocAkt
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 390
  Width = 695
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
      'UPDATE REM_DAKT'
      'SET '
      '    IDBASE_REM_DAKT = :IDBASE_REM_DAKT,'
      '    IDEXT_BASE_REM_DAKT = :IDEXT_BASE_REM_DAKT,'
      '    IDEXT_DOUT_REM_DAKT = :IDEXT_DOUT_REM_DAKT,'
      '    TYPE_TBL_REM_DAKT = :TYPE_TBL_REM_DAKT,'
      '    GID_REM_DAKT = :GID_REM_DAKT,'
      '    IDDOC_REM_DAKT = :IDDOC_REM_DAKT,'
      '    IDZ_REM_DAKT = :IDZ_REM_DAKT,'
      '    IDHW_REM_DAKT = :IDHW_REM_DAKT,'
      '    IDKKT_REM_DAKT = :IDKKT_REM_DAKT,'
      '    PRIM_REM_DAKT = :PRIM_REM_DAKT,'
      '    KL_SOGLASEN_REM_DAKT = :KL_SOGLASEN_REM_DAKT,'
      '    PODPISAN_REM_DAKT = :PODPISAN_REM_DAKT,'
      '    TYPE_REM_DAKT = :TYPE_REM_DAKT,'
      '    NUM_U_PROISV_REM_DAKT = :NUM_U_PROISV_REM_DAKT,'
      '    NEISPR_KLIENTA_REM_DAKT = :NEISPR_KLIENTA_REM_DAKT,'
      '    NEISPR_SC_REM_DAKT = :NEISPR_SC_REM_DAKT,'
      '    FL_FULL_KOMPL_REM_DAKT = :FL_FULL_KOMPL_REM_DAKT,'
      '    NEKOMPL_STR_REM_DAKT = :NEKOMPL_STR_REM_DAKT,'
      '    KOMPL_STR_REM_DAKT = :KOMPL_STR_REM_DAKT,'
      '    FL_MEXPOVR_REM_DAKT = :FL_MEXPOVR_REM_DAKT,'
      '    MEXPOVR_STR_REM_DAKT = :MEXPOVR_STR_REM_DAKT,'
      '    NEISPR_BLOK_REM_DAKT = :NEISPR_BLOK_REM_DAKT,'
      '    FL_PRICHINA_ACTA_REM_DAKT = :FL_PRICHINA_ACTA_REM_DAKT,'
      
        '    PRICHINA_ACTA_DR_STR_REM_DAKT = :PRICHINA_ACTA_DR_STR_REM_DA' +
        'KT,'
      '    FL_PRICHINA_SOST_REM_DAKT = :FL_PRICHINA_SOST_REM_DAKT,'
      '    PRICHINA_SOST_DR_REM_DAKT = :PRICHINA_SOST_DR_REM_DAKT,'
      '    FL_MESTONAX_REM_DAKT = :FL_MESTONAX_REM_DAKT,'
      '    ISD_NAME_REM_DAKT = :ISD_NAME_REM_DAKT,'
      '    ISD_DATE_PRODAGI_REM_DAKT = :ISD_DATE_PRODAGI_REM_DAKT,'
      '    ISD_MODEL_REM_DAKT = :ISD_MODEL_REM_DAKT,'
      '    ISD_SERNUM1_REM_DAKT = :ISD_SERNUM1_REM_DAKT,'
      '    ISD_SERNUM2_REM_DAKT = :ISD_SERNUM2_REM_DAKT,'
      '    ISD_SERNUM3_REM_DAKT = :ISD_SERNUM3_REM_DAKT,'
      '    ISD_NUMUP_REM_DAKT = :ISD_NUMUP_REM_DAKT,'
      '    ISD_NUMTEXLIST_REM_DAKT = :ISD_NUMTEXLIST_REM_DAKT,'
      '    PRODAVEC_NAME_REM_DAKT = :PRODAVEC_NAME_REM_DAKT,'
      '    PRODAVEC_ADR_REM_DAKT = :PRODAVEC_ADR_REM_DAKT,'
      '    PRODAVEC_TEL_REM_DAKT = :PRODAVEC_TEL_REM_DAKT,'
      '    KLIENT_NAME_REM_DAKT = :KLIENT_NAME_REM_DAKT,'
      '    KLIENT_ADR_REM_DAKT = :KLIENT_ADR_REM_DAKT,'
      '    KLIENT_PHONE_REM_DAKT = :KLIENT_PHONE_REM_DAKT'
      'WHERE'
      '    ID_REM_DAKT = :OLD_ID_REM_DAKT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DAKT'
      'WHERE'
      '        ID_REM_DAKT = :OLD_ID_REM_DAKT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DAKT('
      '    ID_REM_DAKT,'
      '    IDBASE_REM_DAKT,'
      '    IDEXT_BASE_REM_DAKT,'
      '    IDEXT_DOUT_REM_DAKT,'
      '    TYPE_TBL_REM_DAKT,'
      '    GID_REM_DAKT,'
      '    IDDOC_REM_DAKT,'
      '    IDZ_REM_DAKT,'
      '    IDHW_REM_DAKT,'
      '    IDKKT_REM_DAKT,'
      '    PRIM_REM_DAKT,'
      '    KL_SOGLASEN_REM_DAKT,'
      '    PODPISAN_REM_DAKT,'
      '    TYPE_REM_DAKT,'
      '    NUM_U_PROISV_REM_DAKT,'
      '    NEISPR_KLIENTA_REM_DAKT,'
      '    NEISPR_SC_REM_DAKT,'
      '    FL_FULL_KOMPL_REM_DAKT,'
      '    NEKOMPL_STR_REM_DAKT,'
      '    KOMPL_STR_REM_DAKT,'
      '    FL_MEXPOVR_REM_DAKT,'
      '    MEXPOVR_STR_REM_DAKT,'
      '    NEISPR_BLOK_REM_DAKT,'
      '    FL_PRICHINA_ACTA_REM_DAKT,'
      '    PRICHINA_ACTA_DR_STR_REM_DAKT,'
      '    FL_PRICHINA_SOST_REM_DAKT,'
      '    PRICHINA_SOST_DR_REM_DAKT,'
      '    FL_MESTONAX_REM_DAKT,'
      '    ISD_NAME_REM_DAKT,'
      '    ISD_DATE_PRODAGI_REM_DAKT,'
      '    ISD_MODEL_REM_DAKT,'
      '    ISD_SERNUM1_REM_DAKT,'
      '    ISD_SERNUM2_REM_DAKT,'
      '    ISD_SERNUM3_REM_DAKT,'
      '    ISD_NUMUP_REM_DAKT,'
      '    ISD_NUMTEXLIST_REM_DAKT,'
      '    PRODAVEC_NAME_REM_DAKT,'
      '    PRODAVEC_ADR_REM_DAKT,'
      '    PRODAVEC_TEL_REM_DAKT,'
      '    KLIENT_NAME_REM_DAKT,'
      '    KLIENT_ADR_REM_DAKT,'
      '    KLIENT_PHONE_REM_DAKT'
      ')'
      'VALUES('
      '    :ID_REM_DAKT,'
      '    :IDBASE_REM_DAKT,'
      '    :IDEXT_BASE_REM_DAKT,'
      '    :IDEXT_DOUT_REM_DAKT,'
      '    :TYPE_TBL_REM_DAKT,'
      '    :GID_REM_DAKT,'
      '    :IDDOC_REM_DAKT,'
      '    :IDZ_REM_DAKT,'
      '    :IDHW_REM_DAKT,'
      '    :IDKKT_REM_DAKT,'
      '    :PRIM_REM_DAKT,'
      '    :KL_SOGLASEN_REM_DAKT,'
      '    :PODPISAN_REM_DAKT,'
      '    :TYPE_REM_DAKT,'
      '    :NUM_U_PROISV_REM_DAKT,'
      '    :NEISPR_KLIENTA_REM_DAKT,'
      '    :NEISPR_SC_REM_DAKT,'
      '    :FL_FULL_KOMPL_REM_DAKT,'
      '    :NEKOMPL_STR_REM_DAKT,'
      '    :KOMPL_STR_REM_DAKT,'
      '    :FL_MEXPOVR_REM_DAKT,'
      '    :MEXPOVR_STR_REM_DAKT,'
      '    :NEISPR_BLOK_REM_DAKT,'
      '    :FL_PRICHINA_ACTA_REM_DAKT,'
      '    :PRICHINA_ACTA_DR_STR_REM_DAKT,'
      '    :FL_PRICHINA_SOST_REM_DAKT,'
      '    :PRICHINA_SOST_DR_REM_DAKT,'
      '    :FL_MESTONAX_REM_DAKT,'
      '    :ISD_NAME_REM_DAKT,'
      '    :ISD_DATE_PRODAGI_REM_DAKT,'
      '    :ISD_MODEL_REM_DAKT,'
      '    :ISD_SERNUM1_REM_DAKT,'
      '    :ISD_SERNUM2_REM_DAKT,'
      '    :ISD_SERNUM3_REM_DAKT,'
      '    :ISD_NUMUP_REM_DAKT,'
      '    :ISD_NUMTEXLIST_REM_DAKT,'
      '    :PRODAVEC_NAME_REM_DAKT,'
      '    :PRODAVEC_ADR_REM_DAKT,'
      '    :PRODAVEC_TEL_REM_DAKT,'
      '    :KLIENT_NAME_REM_DAKT,'
      '    :KLIENT_ADR_REM_DAKT,'
      '    :KLIENT_PHONE_REM_DAKT'
      ')')
    RefreshSQL.Strings = (
      'select rem_dakt.*,'
      '    rem_shardware.name_rem_shardware,'
      '    rem_shardware.sernum_rem_shardware,'
      '    rem_shardware.sernum2_rem_shardware,'
      '    rem_skkt.name_rem_skkt,'
      '    rem_skkt.sernum_rem_skkt,'
      '    rem_z.name_rem_z,'
      '    rem_z.sernum_rem_z,'
      '    rem_z.sernum2_rem_z,'
      '    rem_z.model_rem_z,'
      '    rem_smodel.name_rem_smodel'
      'from  rem_dakt'
      
        'left outer join rem_shardware on rem_dakt.idhw_rem_dakt=rem_shar' +
        'dware.id_rem_shardware'
      
        'left outer join rem_skkt on rem_dakt.idkkt_rem_dakt=rem_skkt.id_' +
        'rem_skkt'
      'left outer join rem_z on rem_dakt.idz_rem_dakt=rem_z.id_rem_z'
      
        'left outer join rem_smodel on rem_z.idmodel_rem_z=rem_smodel.id_' +
        'rem_smodel'
      'where(  rem_dakt.iddoc_rem_dakt=:PARAM_IDDOC'
      '     ) and (     REM_DAKT.ID_REM_DAKT = :OLD_ID_REM_DAKT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_dakt.*,'
      '    rem_shardware.name_rem_shardware,'
      '    rem_shardware.sernum_rem_shardware,'
      '    rem_shardware.sernum2_rem_shardware,'
      '    rem_skkt.name_rem_skkt,'
      '    rem_skkt.sernum_rem_skkt,'
      '    rem_z.name_rem_z,'
      '    rem_z.sernum_rem_z,'
      '    rem_z.sernum2_rem_z,'
      '    rem_z.model_rem_z,'
      '    rem_smodel.name_rem_smodel'
      'from  rem_dakt'
      
        'left outer join rem_shardware on rem_dakt.idhw_rem_dakt=rem_shar' +
        'dware.id_rem_shardware'
      
        'left outer join rem_skkt on rem_dakt.idkkt_rem_dakt=rem_skkt.id_' +
        'rem_skkt'
      'left outer join rem_z on rem_dakt.idz_rem_dakt=rem_z.id_rem_z'
      
        'left outer join rem_smodel on rem_z.idmodel_rem_z=rem_smodel.id_' +
        'rem_smodel'
      'where rem_dakt.iddoc_rem_dakt=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'REM_DAKT'
    AutoUpdateOptions.KeyFields = 'ID_REM_DAKT'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DAKT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object DocID_REM_DAKT: TFIBLargeIntField
      FieldName = 'ID_REM_DAKT'
    end
    object DocIDBASE_REM_DAKT: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DAKT'
    end
    object DocGID_REM_DAKT: TFIBWideStringField
      FieldName = 'GID_REM_DAKT'
      Size = 10
    end
    object DocIDDOC_REM_DAKT: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DAKT'
    end
    object DocIDZ_REM_DAKT: TFIBLargeIntField
      FieldName = 'IDZ_REM_DAKT'
    end
    object DocIDHW_REM_DAKT: TFIBLargeIntField
      FieldName = 'IDHW_REM_DAKT'
    end
    object DocIDKKT_REM_DAKT: TFIBLargeIntField
      FieldName = 'IDKKT_REM_DAKT'
    end
    object DocPRIM_REM_DAKT: TFIBWideStringField
      FieldName = 'PRIM_REM_DAKT'
      Size = 100
    end
    object DocKL_SOGLASEN_REM_DAKT: TFIBSmallIntField
      FieldName = 'KL_SOGLASEN_REM_DAKT'
    end
    object DocPODPISAN_REM_DAKT: TFIBSmallIntField
      FieldName = 'PODPISAN_REM_DAKT'
    end
    object DocTYPE_REM_DAKT: TFIBIntegerField
      FieldName = 'TYPE_REM_DAKT'
    end
    object DocNAME_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'NAME_REM_SHARDWARE'
      Size = 200
    end
    object DocSERNUM_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'SERNUM_REM_SHARDWARE'
      Size = 50
    end
    object DocSERNUM2_REM_SHARDWARE: TFIBWideStringField
      FieldName = 'SERNUM2_REM_SHARDWARE'
      Size = 50
    end
    object DocNAME_REM_SKKT: TFIBWideStringField
      FieldName = 'NAME_REM_SKKT'
      Size = 200
    end
    object DocSERNUM_REM_SKKT: TFIBWideStringField
      FieldName = 'SERNUM_REM_SKKT'
      Size = 15
    end
    object DocSERNUM_REM_Z: TFIBWideStringField
      FieldName = 'SERNUM_REM_Z'
      Size = 50
    end
    object DocSERNUM2_REM_Z: TFIBWideStringField
      FieldName = 'SERNUM2_REM_Z'
      Size = 50
    end
    object DocMODEL_REM_Z: TFIBWideStringField
      FieldName = 'MODEL_REM_Z'
      Size = 40
    end
    object DocNAME_REM_SMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SMODEL'
      Size = 200
    end
    object DocNAME_REM_Z: TFIBWideStringField
      FieldName = 'NAME_REM_Z'
      Size = 200
    end
    object DocNUM_U_PROISV_REM_DAKT: TFIBWideStringField
      FieldName = 'NUM_U_PROISV_REM_DAKT'
      Size = 50
    end
    object DocNEISPR_KLIENTA_REM_DAKT: TFIBWideStringField
      FieldName = 'NEISPR_KLIENTA_REM_DAKT'
      Size = 200
    end
    object DocNEISPR_SC_REM_DAKT: TFIBWideStringField
      FieldName = 'NEISPR_SC_REM_DAKT'
      Size = 200
    end
    object DocFL_FULL_KOMPL_REM_DAKT: TFIBIntegerField
      FieldName = 'FL_FULL_KOMPL_REM_DAKT'
    end
    object DocNEKOMPL_STR_REM_DAKT: TFIBWideStringField
      FieldName = 'NEKOMPL_STR_REM_DAKT'
      Size = 200
    end
    object DocKOMPL_STR_REM_DAKT: TFIBWideStringField
      FieldName = 'KOMPL_STR_REM_DAKT'
      Size = 200
    end
    object DocFL_MEXPOVR_REM_DAKT: TFIBIntegerField
      FieldName = 'FL_MEXPOVR_REM_DAKT'
    end
    object DocMEXPOVR_STR_REM_DAKT: TFIBWideStringField
      FieldName = 'MEXPOVR_STR_REM_DAKT'
      Size = 200
    end
    object DocNEISPR_BLOK_REM_DAKT: TFIBWideStringField
      FieldName = 'NEISPR_BLOK_REM_DAKT'
      Size = 200
    end
    object DocFL_PRICHINA_ACTA_REM_DAKT: TFIBIntegerField
      FieldName = 'FL_PRICHINA_ACTA_REM_DAKT'
    end
    object DocPRICHINA_ACTA_DR_STR_REM_DAKT: TFIBWideStringField
      FieldName = 'PRICHINA_ACTA_DR_STR_REM_DAKT'
      Size = 200
    end
    object DocFL_PRICHINA_SOST_REM_DAKT: TFIBIntegerField
      FieldName = 'FL_PRICHINA_SOST_REM_DAKT'
    end
    object DocPRICHINA_SOST_DR_REM_DAKT: TFIBWideStringField
      FieldName = 'PRICHINA_SOST_DR_REM_DAKT'
      Size = 200
    end
    object DocFL_MESTONAX_REM_DAKT: TFIBIntegerField
      FieldName = 'FL_MESTONAX_REM_DAKT'
    end
    object DocISD_NAME_REM_DAKT: TFIBWideStringField
      FieldName = 'ISD_NAME_REM_DAKT'
      Size = 100
    end
    object DocISD_DATE_PRODAGI_REM_DAKT: TFIBDateField
      FieldName = 'ISD_DATE_PRODAGI_REM_DAKT'
    end
    object DocISD_MODEL_REM_DAKT: TFIBWideStringField
      FieldName = 'ISD_MODEL_REM_DAKT'
      Size = 100
    end
    object DocISD_SERNUM1_REM_DAKT: TFIBWideStringField
      FieldName = 'ISD_SERNUM1_REM_DAKT'
      Size = 50
    end
    object DocISD_SERNUM2_REM_DAKT: TFIBWideStringField
      FieldName = 'ISD_SERNUM2_REM_DAKT'
      Size = 50
    end
    object DocISD_SERNUM3_REM_DAKT: TFIBWideStringField
      FieldName = 'ISD_SERNUM3_REM_DAKT'
      Size = 50
    end
    object DocISD_NUMUP_REM_DAKT: TFIBWideStringField
      FieldName = 'ISD_NUMUP_REM_DAKT'
      Size = 50
    end
    object DocISD_NUMTEXLIST_REM_DAKT: TFIBWideStringField
      FieldName = 'ISD_NUMTEXLIST_REM_DAKT'
      Size = 50
    end
    object DocPRODAVEC_NAME_REM_DAKT: TFIBWideStringField
      FieldName = 'PRODAVEC_NAME_REM_DAKT'
      Size = 200
    end
    object DocPRODAVEC_ADR_REM_DAKT: TFIBWideStringField
      FieldName = 'PRODAVEC_ADR_REM_DAKT'
      Size = 200
    end
    object DocPRODAVEC_TEL_REM_DAKT: TFIBWideStringField
      FieldName = 'PRODAVEC_TEL_REM_DAKT'
      Size = 200
    end
    object DocKLIENT_NAME_REM_DAKT: TFIBWideStringField
      FieldName = 'KLIENT_NAME_REM_DAKT'
      Size = 200
    end
    object DocKLIENT_ADR_REM_DAKT: TFIBWideStringField
      FieldName = 'KLIENT_ADR_REM_DAKT'
      Size = 200
    end
    object DocKLIENT_PHONE_REM_DAKT: TFIBWideStringField
      FieldName = 'KLIENT_PHONE_REM_DAKT'
      Size = 100
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_DAKTT'
      'SET '
      '    IDBASE_REM_DAKTT = :IDBASE_REM_DAKTT,'
      '    GID_REM_DAKTT = :GID_REM_DAKTT,'
      '    IDDOC_REM_DAKTT = :IDDOC_REM_DAKTT,'
      '    INDEX_REM_DAKTT = :INDEX_REM_DAKTT,'
      '    TEXT_REM_DAKTT = :TEXT_REM_DAKTT'
      'WHERE'
      '    ID_REM_DAKTT = :OLD_ID_REM_DAKTT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_DAKTT'
      'WHERE'
      '        ID_REM_DAKTT = :OLD_ID_REM_DAKTT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_DAKTT('
      '    ID_REM_DAKTT,'
      '    IDBASE_REM_DAKTT,'
      '    GID_REM_DAKTT,'
      '    IDDOC_REM_DAKTT,'
      '    INDEX_REM_DAKTT,'
      '    TEXT_REM_DAKTT'
      ')'
      'VALUES('
      '    :ID_REM_DAKTT,'
      '    :IDBASE_REM_DAKTT,'
      '    :GID_REM_DAKTT,'
      '    :IDDOC_REM_DAKTT,'
      '    :INDEX_REM_DAKTT,'
      '    :TEXT_REM_DAKTT'
      ')')
    RefreshSQL.Strings = (
      'select rem_daktt.*'
      'from  rem_daktt'
      'where(  rem_daktt.iddoc_rem_daktt=:PARAM_IDDOC'
      '     ) and (     REM_DAKTT.ID_REM_DAKTT = :OLD_ID_REM_DAKTT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_daktt.*'
      'from  rem_daktt'
      'where rem_daktt.iddoc_rem_daktt=:PARAM_IDDOC'
      'order by rem_daktt.index_rem_daktt')
    AutoUpdateOptions.UpdateTableName = 'REM_DAKTT'
    AutoUpdateOptions.KeyFields = 'ID_REM_DAKTT'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_DAKTT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
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
    object DocTID_REM_DAKTT: TFIBLargeIntField
      FieldName = 'ID_REM_DAKTT'
    end
    object DocTIDBASE_REM_DAKTT: TFIBLargeIntField
      FieldName = 'IDBASE_REM_DAKTT'
    end
    object DocTGID_REM_DAKTT: TFIBWideStringField
      FieldName = 'GID_REM_DAKTT'
      Size = 10
    end
    object DocTIDDOC_REM_DAKTT: TFIBLargeIntField
      FieldName = 'IDDOC_REM_DAKTT'
    end
    object DocTINDEX_REM_DAKTT: TFIBIntegerField
      FieldName = 'INDEX_REM_DAKTT'
    end
    object DocTTEXT_REM_DAKTT: TFIBWideStringField
      FieldName = 'TEXT_REM_DAKTT'
      Size = 1500
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
      'where TDOC_REM_GALLDOC='#39'REMAKT'#39' and POS_REM_GALLDOC > :PARAM_POS')
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
      'EXECUTE PROCEDURE REM_DOC_DAKT_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 304
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE REM_DOC_DAKT_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 240
    qoStartTransaction = True
  end
end
