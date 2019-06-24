object DMDocOstVs: TDMDocOstVs
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 390
  Width = 372
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
        'MEKLIENT,'
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from GALLDOC'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      'left outer join SFIRM on IDFIRMDOC=IDFIRM'
      'left outer join SKLIENT on IDKLDOC=IDKLIENT'
      
        'left outer join SPROJECT on galldoc.idproject_galldoc=sproject.i' +
        'd_sproject'
      
        'left outer join sbusiness_oper on galldoc.idbusinop_galldoc=sbus' +
        'iness_oper.id_sbusiness_oper'
      ''
      'where(  IDDOC=:ID'
      '     ) and (     GALLDOC.IDDOC = :OLD_IDDOC'
      '     )'
      '     ')
    SelectSQL.Strings = (
      
        'select GALLDOC.*, FNAME_USER , NAME_SINFBASE_OBMEN, NAMEFIRM, NA' +
        'MEKLIENT,'
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from GALLDOC'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      'left outer join SFIRM on IDFIRMDOC=IDFIRM'
      'left outer join SKLIENT on IDKLDOC=IDKLIENT'
      
        'left outer join SPROJECT on galldoc.idproject_galldoc=sproject.i' +
        'd_sproject'
      
        'left outer join sbusiness_oper on galldoc.idbusinop_galldoc=sbus' +
        'iness_oper.id_sbusiness_oper'
      ''
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
      'UPDATE DOSTVS'
      'SET '
      '    GID_DOSTVS = :GID_DOSTVS,'
      '    IDDOC_DOSTVS = :IDDOC_DOSTVS,'
      '    IDFIRM_DOSTVS = :IDFIRM_DOSTVS,'
      '    IDKLIENT_DOSTVS = :IDKLIENT_DOSTVS,'
      '    PRIM_DOSTVS = :PRIM_DOSTVS,'
      '    PRIHOD_DOSTVS = :PRIHOD_DOSTVS,'
      '    RASHOD_DOSTVS = :RASHOD_DOSTVS,'
      '    DVRGPAYSALE_DOSTVS = :DVRGPAYSALE_DOSTVS,'
      '    IDBASE_DOSTVS = :IDBASE_DOSTVS'
      'WHERE'
      '    ID_DOSTVS = :OLD_ID_DOSTVS'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DOSTVS'
      'WHERE'
      '        ID_DOSTVS = :OLD_ID_DOSTVS'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DOSTVS('
      '    ID_DOSTVS,'
      '    GID_DOSTVS,'
      '    IDDOC_DOSTVS,'
      '    IDFIRM_DOSTVS,'
      '    IDKLIENT_DOSTVS,'
      '    PRIM_DOSTVS,'
      '    PRIHOD_DOSTVS,'
      '    RASHOD_DOSTVS,'
      '    DVRGPAYSALE_DOSTVS,'
      '    IDBASE_DOSTVS'
      ')'
      'VALUES('
      '    :ID_DOSTVS,'
      '    :GID_DOSTVS,'
      '    :IDDOC_DOSTVS,'
      '    :IDFIRM_DOSTVS,'
      '    :IDKLIENT_DOSTVS,'
      '    :PRIM_DOSTVS,'
      '    :PRIHOD_DOSTVS,'
      '    :RASHOD_DOSTVS,'
      '    :DVRGPAYSALE_DOSTVS,'
      '    :IDBASE_DOSTVS'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from  DOSTVS'
      'where(  IDDOC_DOSTVS=:ID'
      '     ) and (     DOSTVS.ID_DOSTVS = :OLD_ID_DOSTVS'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from  DOSTVS'
      'where IDDOC_DOSTVS=:ID')
    AutoUpdateOptions.UpdateTableName = 'DOSTVS'
    AutoUpdateOptions.KeyFields = 'ID_DOSTVS'
    AutoUpdateOptions.GeneratorName = 'GEN_DOSTVS_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 72
    poUseLargeIntField = True
    object DocPRIHOD_DOSTVS: TFIBBCDField
      FieldName = 'PRIHOD_DOSTVS'
      Size = 2
      RoundByScale = True
    end
    object DocRASHOD_DOSTVS: TFIBBCDField
      FieldName = 'RASHOD_DOSTVS'
      Size = 2
      RoundByScale = True
    end
    object DocDVRGPAYSALE_DOSTVS: TFIBIntegerField
      FieldName = 'DVRGPAYSALE_DOSTVS'
    end
    object DocID_DOSTVS: TFIBLargeIntField
      FieldName = 'ID_DOSTVS'
    end
    object DocGID_DOSTVS: TFIBWideStringField
      FieldName = 'GID_DOSTVS'
      Size = 10
    end
    object DocIDDOC_DOSTVS: TFIBLargeIntField
      FieldName = 'IDDOC_DOSTVS'
    end
    object DocIDFIRM_DOSTVS: TFIBLargeIntField
      FieldName = 'IDFIRM_DOSTVS'
    end
    object DocIDKLIENT_DOSTVS: TFIBLargeIntField
      FieldName = 'IDKLIENT_DOSTVS'
    end
    object DocPRIM_DOSTVS: TFIBWideStringField
      FieldName = 'PRIM_DOSTVS'
      Size = 100
    end
    object DocIDBASE_DOSTVS: TFIBLargeIntField
      FieldName = 'IDBASE_DOSTVS'
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
  object NumDoc: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      'from DOC_OSTVS_GET_NUM_NEW_DOC (:PARAM_IDBASE,:PARAM_IDFIRM)')
    Left = 312
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
    Left = 168
    Top = 144
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_OSTVS_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 192
    Top = 320
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_OSTVS_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 192
    Top = 272
    qoStartTransaction = True
  end
end
