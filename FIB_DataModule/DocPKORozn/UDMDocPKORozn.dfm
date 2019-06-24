object DMDocPKORozn: TDMDocPKORozn
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 374
  Width = 393
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
      
        'select GALLDOC.*, FNAME_USER , NAME_SINFBASE_OBMEN, NAMEFIRM, NA' +
        'MEKLIENT, NAME_SDOG,'
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from GALLDOC'
      'left outer join SFIRM on IDFIRMDOC=IDFIRM'
      'left outer join SKLIENT on IDKLDOC=IDKLIENT'
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
      
        'select GALLDOC.*, FNAME_USER , NAME_SINFBASE_OBMEN, NAMEFIRM, NA' +
        'MEKLIENT, NAME_SDOG,'
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from GALLDOC'
      'left outer join SFIRM on IDFIRMDOC=IDFIRM'
      'left outer join SKLIENT on IDKLDOC=IDKLIENT'
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
    Left = 160
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
    object DocAllTDOC: TFIBWideStringField
      FieldName = 'TDOC'
      Size = 10
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
    object DocAllGID_DOC: TFIBWideStringField
      FieldName = 'GID_DOC'
      Size = 10
    end
    object DocAllPREFIKSDOC: TFIBWideStringField
      FieldName = 'PREFIKSDOC'
      Size = 2
    end
    object DocAllIDDOCOSNDOC: TFIBLargeIntField
      FieldName = 'IDDOCOSNDOC'
    end
    object DocAllIDEXTDOC: TFIBLargeIntField
      FieldName = 'IDEXTDOC'
    end
    object DocAllTYPEEXTDOC: TFIBIntegerField
      FieldName = 'TYPEEXTDOC'
    end
    object DocAllIDBASE_GALLDOC: TFIBLargeIntField
      FieldName = 'IDBASE_GALLDOC'
      OnChange = DocAllIDBASE_GALLDOCChange
    end
    object DocAllIDPROJECT_GALLDOC: TFIBLargeIntField
      FieldName = 'IDPROJECT_GALLDOC'
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
      'UPDATE DPKOROZN'
      'SET '
      '    IDDOC_DPKOROZN = :IDDOC_DPKOROZN,'
      '    GID_DPKOROZN = :GID_DPKOROZN,'
      '    IDKKM_DPKOROZN = :IDKKM_DPKOROZN,'
      '    OPERATION_DPKOROZN = :OPERATION_DPKOROZN,'
      '    PRIM_DPKOROZN = :PRIM_DPKOROZN,'
      '    PROT_DPKOROZN = :PROT_DPKOROZN,'
      '    OSN_DPKOROZN = :OSN_DPKOROZN,'
      '    NUMCHECK_DPKOROZN = :NUMCHECK_DPKOROZN,'
      '    NUMKL_DPKOROZN = :NUMKL_DPKOROZN,'
      '    NKL_DPKOROZN = :NKL_DPKOROZN,'
      '    NCHECK_DPKOROZN = :NCHECK_DPKOROZN,'
      '    MODEL_DPKOROZN = :MODEL_DPKOROZN,'
      '    REGNUM_DPKOROZN = :REGNUM_DPKOROZN,'
      '    SAVNUM_DPKOROZN = :SAVNUM_DPKOROZN,'
      '    IDBASE_DPKOROZN = :IDBASE_DPKOROZN,'
      '    NDS_DPKOROZN = :NDS_DPKOROZN,'
      '    SUMNDS_DPKOROZN = :SUMNDS_DPKOROZN,'
      '    IDCARD_DPKOROZN = :IDCARD_DPKOROZN'
      'WHERE'
      '    ID_DPKOROZN = :OLD_ID_DPKOROZN'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DPKOROZN'
      'WHERE'
      '        ID_DPKOROZN = :OLD_ID_DPKOROZN'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DPKOROZN('
      '    ID_DPKOROZN,'
      '    IDDOC_DPKOROZN,'
      '    GID_DPKOROZN,'
      '    IDKKM_DPKOROZN,'
      '    OPERATION_DPKOROZN,'
      '    PRIM_DPKOROZN,'
      '    PROT_DPKOROZN,'
      '    OSN_DPKOROZN,'
      '    NUMCHECK_DPKOROZN,'
      '    NUMKL_DPKOROZN,'
      '    NKL_DPKOROZN,'
      '    NCHECK_DPKOROZN,'
      '    MODEL_DPKOROZN,'
      '    REGNUM_DPKOROZN,'
      '    SAVNUM_DPKOROZN,'
      '    IDBASE_DPKOROZN,'
      '    NDS_DPKOROZN,'
      '    SUMNDS_DPKOROZN,'
      '    IDCARD_DPKOROZN'
      ')'
      'VALUES('
      '    :ID_DPKOROZN,'
      '    :IDDOC_DPKOROZN,'
      '    :GID_DPKOROZN,'
      '    :IDKKM_DPKOROZN,'
      '    :OPERATION_DPKOROZN,'
      '    :PRIM_DPKOROZN,'
      '    :PROT_DPKOROZN,'
      '    :OSN_DPKOROZN,'
      '    :NUMCHECK_DPKOROZN,'
      '    :NUMKL_DPKOROZN,'
      '    :NKL_DPKOROZN,'
      '    :NCHECK_DPKOROZN,'
      '    :MODEL_DPKOROZN,'
      '    :REGNUM_DPKOROZN,'
      '    :SAVNUM_DPKOROZN,'
      '    :IDBASE_DPKOROZN,'
      '    :NDS_DPKOROZN,'
      '    :SUMNDS_DPKOROZN,'
      '    :IDCARD_DPKOROZN'
      ')')
    RefreshSQL.Strings = (
      'select DPKOROZN.*,'
      '        NAMEKKM,'
      '        sdiscount_card.name_sdiscount_card'
      'from  DPKOROZN'
      'left outer join SKKM on IDKKM_DPKOROZN=IDKKM'
      
        'left outer join sdiscount_card on sdiscount_card.id_sdiscount_ca' +
        'rd=dpkorozn.idcard_dpkorozn'
      'where(  IDDOC_DPKOROZN=:ID'
      '     ) and (     DPKOROZN.ID_DPKOROZN = :OLD_ID_DPKOROZN'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select DPKOROZN.*,'
      '        NAMEKKM,'
      '        sdiscount_card.name_sdiscount_card'
      'from  DPKOROZN'
      'left outer join SKKM on IDKKM_DPKOROZN=IDKKM'
      
        'left outer join sdiscount_card on sdiscount_card.id_sdiscount_ca' +
        'rd=dpkorozn.idcard_dpkorozn'
      'where IDDOC_DPKOROZN=:ID')
    AutoUpdateOptions.UpdateTableName = 'DPKOROZN'
    AutoUpdateOptions.KeyFields = 'ID_DPKOROZN'
    AutoUpdateOptions.GeneratorName = 'GEN_DPKOROZN_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 72
    poUseLargeIntField = True
    object DocOPERATION_DPKOROZN: TFIBIntegerField
      FieldName = 'OPERATION_DPKOROZN'
    end
    object DocNDS_DPKOROZN: TFIBIntegerField
      FieldName = 'NDS_DPKOROZN'
    end
    object DocSUMNDS_DPKOROZN: TFIBBCDField
      FieldName = 'SUMNDS_DPKOROZN'
      Size = 2
      RoundByScale = True
    end
    object DocID_DPKOROZN: TFIBLargeIntField
      FieldName = 'ID_DPKOROZN'
    end
    object DocIDDOC_DPKOROZN: TFIBLargeIntField
      FieldName = 'IDDOC_DPKOROZN'
    end
    object DocGID_DPKOROZN: TFIBWideStringField
      FieldName = 'GID_DPKOROZN'
      Size = 10
    end
    object DocIDKKM_DPKOROZN: TFIBLargeIntField
      FieldName = 'IDKKM_DPKOROZN'
      OnChange = DocIDKKM_DPKOROZNChange
    end
    object DocPRIM_DPKOROZN: TFIBWideStringField
      FieldName = 'PRIM_DPKOROZN'
      Size = 100
    end
    object DocPROT_DPKOROZN: TFIBWideStringField
      FieldName = 'PROT_DPKOROZN'
      Size = 100
    end
    object DocOSN_DPKOROZN: TFIBWideStringField
      FieldName = 'OSN_DPKOROZN'
      Size = 100
    end
    object DocNUMCHECK_DPKOROZN: TFIBIntegerField
      FieldName = 'NUMCHECK_DPKOROZN'
    end
    object DocNUMKL_DPKOROZN: TFIBIntegerField
      FieldName = 'NUMKL_DPKOROZN'
    end
    object DocNKL_DPKOROZN: TFIBIntegerField
      FieldName = 'NKL_DPKOROZN'
    end
    object DocNCHECK_DPKOROZN: TFIBIntegerField
      FieldName = 'NCHECK_DPKOROZN'
    end
    object DocMODEL_DPKOROZN: TFIBWideStringField
      FieldName = 'MODEL_DPKOROZN'
    end
    object DocREGNUM_DPKOROZN: TFIBWideStringField
      FieldName = 'REGNUM_DPKOROZN'
    end
    object DocSAVNUM_DPKOROZN: TFIBWideStringField
      FieldName = 'SAVNUM_DPKOROZN'
    end
    object DocIDBASE_DPKOROZN: TFIBLargeIntField
      FieldName = 'IDBASE_DPKOROZN'
    end
    object DocIDCARD_DPKOROZN: TFIBLargeIntField
      FieldName = 'IDCARD_DPKOROZN'
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
    Left = 240
    Top = 128
  end
  object NumDoc: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      
        'from DOC_PKOROZN_GET_NUM_NEW_DOC (:PARAM_IDBASE,:PARAM_IDFIRM,:P' +
        'ARAM_IDKASSA)')
    Transaction = IBTr
    Left = 304
    Top = 16
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_PKOROZN_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 192
    Top = 320
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_PKOROZN_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 192
    Top = 272
    qoStartTransaction = True
  end
end
