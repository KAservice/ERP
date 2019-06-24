object DMDocRKORozn: TDMDocRKORozn
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 410
  Width = 400
  object DataSourceDoc: TDataSource
    DataSet = Doc
    Left = 72
    Top = 72
  end
  object DataSourceDocAll: TDataSource
    DataSet = DocAll
    Left = 72
    Top = 16
  end
  object DocAll: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE GALLDOC'
      'SET '
      '    POSDOC = :POSDOC,'
      '    PRDOC = :PRDOC,'
      '    TDOC = :TDOC,'
      '    NUMDOC = :NUMDOC,'
      '    IDFIRMDOC = :IDFIRMDOC,'
      '    IDSKLDOC = :IDSKLDOC,'
      '    IDKLDOC = :IDKLDOC,'
      '    IDDOGDOC = :IDDOGDOC,'
      '    SUMDOC = :SUMDOC,'
      '    IDUSERDOC = :IDUSERDOC,'
      '    GID_DOC = :GID_DOC,'
      '    PREFIKSDOC = :PREFIKSDOC,'
      '    IDDOCOSNDOC = :IDDOCOSNDOC,'
      '    IDEXTDOC = :IDEXTDOC,'
      '    TYPEEXTDOC = :TYPEEXTDOC,'
      '    IDBASE_GALLDOC = :IDBASE_GALLDOC,'
      '    IDPROJECT_GALLDOC = :IDPROJECT_GALLDOC,'
      '    IDBUSINOP_GALLDOC = :IDBUSINOP_GALLDOC,'
      '    PREFIKS_NUM_GALLDOC = :PREFIKS_NUM_GALLDOC'
      'WHERE'
      '    IDDOC = :OLD_IDDOC'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    GALLDOC'
      'WHERE'
      '        IDDOC = :OLD_IDDOC'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO GALLDOC('
      '    IDDOC,'
      '    POSDOC,'
      '    PRDOC,'
      '    TDOC,'
      '    NUMDOC,'
      '    IDFIRMDOC,'
      '    IDSKLDOC,'
      '    IDKLDOC,'
      '    IDDOGDOC,'
      '    SUMDOC,'
      '    IDUSERDOC,'
      '    GID_DOC,'
      '    PREFIKSDOC,'
      '    IDDOCOSNDOC,'
      '    IDEXTDOC,'
      '    TYPEEXTDOC,'
      '    IDBASE_GALLDOC,'
      '    IDPROJECT_GALLDOC,'
      '    IDBUSINOP_GALLDOC,'
      '    PREFIKS_NUM_GALLDOC'
      ')'
      'VALUES('
      '    :IDDOC,'
      '    :POSDOC,'
      '    :PRDOC,'
      '    :TDOC,'
      '    :NUMDOC,'
      '    :IDFIRMDOC,'
      '    :IDSKLDOC,'
      '    :IDKLDOC,'
      '    :IDDOGDOC,'
      '    :SUMDOC,'
      '    :IDUSERDOC,'
      '    :GID_DOC,'
      '    :PREFIKSDOC,'
      '    :IDDOCOSNDOC,'
      '    :IDEXTDOC,'
      '    :TYPEEXTDOC,'
      '    :IDBASE_GALLDOC,'
      '    :IDPROJECT_GALLDOC,'
      '    :IDBUSINOP_GALLDOC,'
      '    :PREFIKS_NUM_GALLDOC'
      ')')
    RefreshSQL.Strings = (
      
        'select  GALLDOC.* , FNAME_USER, NAME_SINFBASE_OBMEN, NAMEFIRM, N' +
        'AMEKLIENT, NAME_SDOG, '
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from GALLDOC'
      'left outer join SFIRM on IDFIRMDOC=IDFIRM'
      'left outer join SKLIENT on  IDKLDOC=IDKLIENT'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      'left outer join SDOG on IDDOGDOC=ID_SDOG'
      
        'left outer join SPROJECT on galldoc.idproject_galldoc=sproject.i' +
        'd_sproject'
      
        'left outer join sbusiness_oper on galldoc.idbusinop_galldoc=sbus' +
        'iness_oper.id_sbusiness_oper'
      'where(  IDDOC=:ID'
      '     ) and (     GALLDOC.IDDOC = :OLD_IDDOC'
      '     )'
      '     ')
    SelectSQL.Strings = (
      
        'select  GALLDOC.* , FNAME_USER, NAME_SINFBASE_OBMEN, NAMEFIRM, N' +
        'AMEKLIENT, NAME_SDOG, '
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from GALLDOC'
      'left outer join SFIRM on IDFIRMDOC=IDFIRM'
      'left outer join SKLIENT on  IDKLDOC=IDKLIENT'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      'left outer join SDOG on IDDOGDOC=ID_SDOG'
      
        'left outer join SPROJECT on galldoc.idproject_galldoc=sproject.i' +
        'd_sproject'
      
        'left outer join sbusiness_oper on galldoc.idbusinop_galldoc=sbus' +
        'iness_oper.id_sbusiness_oper'
      'where IDDOC=:ID ')
    AutoUpdateOptions.UpdateTableName = 'GALLDOC'
    AutoUpdateOptions.KeyFields = 'IDDOC'
    AutoUpdateOptions.GeneratorName = 'GEN_GALLDOC_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 16
    poUseLargeIntField = True
    object DocAllPOSDOC: TFIBDateTimeField
      FieldName = 'POSDOC'
      OnChange = DocAllPOSDOCChange
      DisplayFormat = 'c'
    end
    object DocAllPRDOC: TFIBSmallIntField
      FieldName = 'PRDOC'
    end
    object DocAllNUMDOC: TFIBIntegerField
      FieldName = 'NUMDOC'
    end
    object DocAllSUMDOC: TFIBBCDField
      FieldName = 'SUMDOC'
      Size = 2
      RoundByScale = True
    end
    object DocAllIDDOC: TFIBLargeIntField
      FieldName = 'IDDOC'
    end
    object DocAllIDFIRMDOC: TFIBLargeIntField
      FieldName = 'IDFIRMDOC'
      OnChange = DocAllIDFIRMDOCChange
    end
    object DocAllIDSKLDOC: TFIBLargeIntField
      FieldName = 'IDSKLDOC'
    end
    object DocAllIDKLDOC: TFIBLargeIntField
      FieldName = 'IDKLDOC'
    end
    object DocAllIDDOGDOC: TFIBLargeIntField
      FieldName = 'IDDOGDOC'
    end
    object DocAllIDUSERDOC: TFIBLargeIntField
      FieldName = 'IDUSERDOC'
    end
    object DocAllIDDOCOSNDOC: TFIBLargeIntField
      FieldName = 'IDDOCOSNDOC'
    end
    object DocAllIDEXTDOC: TFIBLargeIntField
      FieldName = 'IDEXTDOC'
    end
    object DocAllIDBASE_GALLDOC: TFIBLargeIntField
      FieldName = 'IDBASE_GALLDOC'
      OnChange = DocAllIDBASE_GALLDOCChange
    end
    object DocAllIDPROJECT_GALLDOC: TFIBLargeIntField
      FieldName = 'IDPROJECT_GALLDOC'
    end
    object DocAllGID_DOC: TFIBWideStringField
      FieldName = 'GID_DOC'
      Size = 10
    end
    object DocAllPREFIKSDOC: TFIBWideStringField
      FieldName = 'PREFIKSDOC'
      Size = 2
    end
    object DocAllTYPEEXTDOC: TFIBIntegerField
      FieldName = 'TYPEEXTDOC'
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
    object DocAllNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 200
    end
    object DocAllNAME_SDOG: TFIBWideStringField
      FieldName = 'NAME_SDOG'
      Size = 200
    end
    object DocAllTDOC: TFIBWideStringField
      FieldName = 'TDOC'
      Size = 10
    end
    object DocAllIDBUSINOP_GALLDOC: TFIBLargeIntField
      FieldName = 'IDBUSINOP_GALLDOC'
    end
    object DocAllNAME_SPROJECT: TFIBWideStringField
      FieldName = 'NAME_SPROJECT'
      Size = 200
    end
    object DocAllNAME_SBUSINESS_OPER: TFIBWideStringField
      FieldName = 'NAME_SBUSINESS_OPER'
      Size = 200
    end
    object DocAllPREFIKS_NUM_GALLDOC: TFIBWideStringField
      FieldName = 'PREFIKS_NUM_GALLDOC'
      Size = 12
    end
  end
  object Doc: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DRKOROZN'
      'SET '
      '    IDDOC_DRKOROZN = :IDDOC_DRKOROZN,'
      '    GID_DRKOROZN = :GID_DRKOROZN,'
      '    IDKKM_DRKOROZN = :IDKKM_DRKOROZN,'
      '    OPERATION_DRKOROZN = :OPERATION_DRKOROZN,'
      '    VIDAT_DRKOROZN = :VIDAT_DRKOROZN,'
      '    OSN_DRKOROZN = :OSN_DRKOROZN,'
      '    PRIM_DRKOROZN = :PRIM_DRKOROZN,'
      '    NCHECK_DRKOROZN = :NCHECK_DRKOROZN,'
      '    NKL_DRKOROZN = :NKL_DRKOROZN,'
      '    MODEL_DRKOROZN = :MODEL_DRKOROZN,'
      '    REGNUM_DRKOROZN = :REGNUM_DRKOROZN,'
      '    SAVNUM_DRKOROZN = :SAVNUM_DRKOROZN,'
      '    IDBASE_DRKOROZN = :IDBASE_DRKOROZN,'
      '    NDS_DRKOROZN = :NDS_DRKOROZN,'
      '    SUMNDS_DRKOROZN = :SUMNDS_DRKOROZN,'
      '    IDCARD_DRKOROZN = :IDCARD_DRKOROZN'
      'WHERE'
      '    ID_DRKOROZN = :OLD_ID_DRKOROZN'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DRKOROZN'
      'WHERE'
      '        ID_DRKOROZN = :OLD_ID_DRKOROZN'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DRKOROZN('
      '    ID_DRKOROZN,'
      '    IDDOC_DRKOROZN,'
      '    GID_DRKOROZN,'
      '    IDKKM_DRKOROZN,'
      '    OPERATION_DRKOROZN,'
      '    VIDAT_DRKOROZN,'
      '    OSN_DRKOROZN,'
      '    PRIM_DRKOROZN,'
      '    NCHECK_DRKOROZN,'
      '    NKL_DRKOROZN,'
      '    MODEL_DRKOROZN,'
      '    REGNUM_DRKOROZN,'
      '    SAVNUM_DRKOROZN,'
      '    IDBASE_DRKOROZN,'
      '    NDS_DRKOROZN,'
      '    SUMNDS_DRKOROZN,'
      '    IDCARD_DRKOROZN'
      ')'
      'VALUES('
      '    :ID_DRKOROZN,'
      '    :IDDOC_DRKOROZN,'
      '    :GID_DRKOROZN,'
      '    :IDKKM_DRKOROZN,'
      '    :OPERATION_DRKOROZN,'
      '    :VIDAT_DRKOROZN,'
      '    :OSN_DRKOROZN,'
      '    :PRIM_DRKOROZN,'
      '    :NCHECK_DRKOROZN,'
      '    :NKL_DRKOROZN,'
      '    :MODEL_DRKOROZN,'
      '    :REGNUM_DRKOROZN,'
      '    :SAVNUM_DRKOROZN,'
      '    :IDBASE_DRKOROZN,'
      '    :NDS_DRKOROZN,'
      '    :SUMNDS_DRKOROZN,'
      '    :IDCARD_DRKOROZN'
      ')')
    RefreshSQL.Strings = (
      'select DRKOROZN.*,'
      '            NAMEKKM,'
      '            sdiscount_card.name_sdiscount_card'
      'from  DRKOROZN'
      'left outer join SKKM on IDKKM_DRKOROZN=IDKKM'
      
        'left outer join sdiscount_card on sdiscount_card.id_sdiscount_ca' +
        'rd=drkorozn.idcard_drkorozn'
      'where(  IDDOC_DRKOROZN=:ID'
      '     ) and (     DRKOROZN.ID_DRKOROZN = :OLD_ID_DRKOROZN'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select DRKOROZN.*,'
      '            NAMEKKM,'
      '            sdiscount_card.name_sdiscount_card'
      'from  DRKOROZN'
      'left outer join SKKM on IDKKM_DRKOROZN=IDKKM'
      
        'left outer join sdiscount_card on sdiscount_card.id_sdiscount_ca' +
        'rd=drkorozn.idcard_drkorozn'
      'where IDDOC_DRKOROZN=:ID')
    AutoUpdateOptions.UpdateTableName = 'DRKOROZN'
    AutoUpdateOptions.KeyFields = 'ID_DRKOROZN'
    AutoUpdateOptions.GeneratorName = 'GEN_DRKOROZN_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 72
    poUseLargeIntField = True
    object DocOPERATION_DRKOROZN: TFIBIntegerField
      FieldName = 'OPERATION_DRKOROZN'
    end
    object DocNDS_DRKOROZN: TFIBIntegerField
      FieldName = 'NDS_DRKOROZN'
    end
    object DocSUMNDS_DRKOROZN: TFIBBCDField
      FieldName = 'SUMNDS_DRKOROZN'
      Size = 2
      RoundByScale = True
    end
    object DocID_DRKOROZN: TFIBLargeIntField
      FieldName = 'ID_DRKOROZN'
    end
    object DocIDDOC_DRKOROZN: TFIBLargeIntField
      FieldName = 'IDDOC_DRKOROZN'
    end
    object DocIDKKM_DRKOROZN: TFIBLargeIntField
      FieldName = 'IDKKM_DRKOROZN'
      OnChange = DocIDKKM_DRKOROZNChange
    end
    object DocIDBASE_DRKOROZN: TFIBLargeIntField
      FieldName = 'IDBASE_DRKOROZN'
    end
    object DocIDCARD_DRKOROZN: TFIBLargeIntField
      FieldName = 'IDCARD_DRKOROZN'
    end
    object DocGID_DRKOROZN: TFIBWideStringField
      FieldName = 'GID_DRKOROZN'
      Size = 10
    end
    object DocVIDAT_DRKOROZN: TFIBWideStringField
      FieldName = 'VIDAT_DRKOROZN'
      Size = 100
    end
    object DocOSN_DRKOROZN: TFIBWideStringField
      FieldName = 'OSN_DRKOROZN'
      Size = 100
    end
    object DocPRIM_DRKOROZN: TFIBWideStringField
      FieldName = 'PRIM_DRKOROZN'
      Size = 100
    end
    object DocNCHECK_DRKOROZN: TFIBIntegerField
      FieldName = 'NCHECK_DRKOROZN'
    end
    object DocNKL_DRKOROZN: TFIBIntegerField
      FieldName = 'NKL_DRKOROZN'
    end
    object DocMODEL_DRKOROZN: TFIBWideStringField
      FieldName = 'MODEL_DRKOROZN'
    end
    object DocREGNUM_DRKOROZN: TFIBWideStringField
      FieldName = 'REGNUM_DRKOROZN'
    end
    object DocSAVNUM_DRKOROZN: TFIBWideStringField
      FieldName = 'SAVNUM_DRKOROZN'
    end
    object DocNAMEKKM: TFIBWideStringField
      FieldName = 'NAMEKKM'
      Size = 100
    end
    object DocNAME_SDISCOUNT_CARD: TFIBWideStringField
      FieldName = 'NAME_SDISCOUNT_CARD'
      Size = 100
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
    Left = 264
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
    Left = 264
    Top = 72
  end
  object NumDoc: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      
        'from DOC_RKOROZN_GET_NUM_NEW_DOC (:PARAM_IDBASE,:PARAM_IDFIRM,:P' +
        'ARAM_IDKASSA)')
    Left = 328
    Top = 16
  end
  object IBTrDvReg: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 248
    Top = 144
  end
  object pFIBQAdvance: TpFIBDataSet
    SelectSQL.Strings = (
      'select SUM_RGADVCUST from RGADVCUST'
      'where'
      'IDFIRM_RGADVCUST=:PARAM_IDFIRM AND'
      'IDKLIENT_RGADVCUST=:PARAM_IDKLIENT')
    Transaction = IBTrDvReg
    Left = 336
    Top = 144
    object pFIBQAdvanceSUM_RGADVCUST: TFIBBCDField
      FieldName = 'SUM_RGADVCUST'
      Size = 2
      RoundByScale = True
    end
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_RKOROZN_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 256
    Top = 320
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_RKOROZN_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 256
    Top = 272
    qoStartTransaction = True
  end
end
