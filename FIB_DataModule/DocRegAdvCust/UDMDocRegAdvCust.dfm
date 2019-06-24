object DMDocRegAdvCust: TDMDocRegAdvCust
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 369
  Width = 398
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
      'select GALLDOC.*, FNAME_USER , NAME_SINFBASE_OBMEN, '
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from '
      '  GALLDOC'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      
        'left outer join SPROJECT on galldoc.idproject_galldoc=sproject.i' +
        'd_sproject'
      
        'left outer join sbusiness_oper on galldoc.idbusinop_galldoc=sbus' +
        'iness_oper.id_sbusiness_oper'
      'where(  '
      '  IDDOC=:PARAM_IDDOC'
      '     ) and (     GALLDOC.IDDOC = :OLD_IDDOC'
      '     )'
      '     ')
    SelectSQL.Strings = (
      'select GALLDOC.*, FNAME_USER , NAME_SINFBASE_OBMEN, '
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from '
      '  GALLDOC'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      
        'left outer join SPROJECT on galldoc.idproject_galldoc=sproject.i' +
        'd_sproject'
      
        'left outer join sbusiness_oper on galldoc.idbusinop_galldoc=sbus' +
        'iness_oper.id_sbusiness_oper'
      'where '
      '  IDDOC=:PARAM_IDDOC ')
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
    object DocAllIDFIRMDOC: TFIBLargeIntField
      FieldName = 'IDFIRMDOC'
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
      'UPDATE DRG_ADVCUST'
      'SET '
      '    IDDOC_DRG_ADVCUST = :IDDOC_DRG_ADVCUST,'
      '    DESCR_DRG_ADVCUST = :DESCR_DRG_ADVCUST,'
      '    IDBASE_DRG_ADVCUST = :IDBASE_DRG_ADVCUST'
      'WHERE'
      '    ID_DRG_ADVCUST = :OLD_ID_DRG_ADVCUST'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DRG_ADVCUST'
      'WHERE'
      '        ID_DRG_ADVCUST = :OLD_ID_DRG_ADVCUST'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DRG_ADVCUST('
      '    ID_DRG_ADVCUST,'
      '    IDDOC_DRG_ADVCUST,'
      '    DESCR_DRG_ADVCUST,'
      '    IDBASE_DRG_ADVCUST'
      ')'
      'VALUES('
      '    :ID_DRG_ADVCUST,'
      '    :IDDOC_DRG_ADVCUST,'
      '    :DESCR_DRG_ADVCUST,'
      '    :IDBASE_DRG_ADVCUST'
      ')')
    RefreshSQL.Strings = (
      'select drg_advcust.*'
      'from  drg_advcust'
      'where(  drg_advcust.iddoc_drg_advcust=:PARAM_IDDOC'
      
        '     ) and (     DRG_ADVCUST.ID_DRG_ADVCUST = :OLD_ID_DRG_ADVCUS' +
        'T'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select drg_advcust.*'
      'from  drg_advcust'
      'where drg_advcust.iddoc_drg_advcust=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'DRG_ADVCUST'
    AutoUpdateOptions.KeyFields = 'ID_DRG_ADVCUST'
    AutoUpdateOptions.GeneratorName = 'GEN_DRG_ADVCUST_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object DocID_DRG_ADVCUST: TFIBLargeIntField
      FieldName = 'ID_DRG_ADVCUST'
    end
    object DocIDDOC_DRG_ADVCUST: TFIBLargeIntField
      FieldName = 'IDDOC_DRG_ADVCUST'
    end
    object DocDESCR_DRG_ADVCUST: TFIBWideStringField
      FieldName = 'DESCR_DRG_ADVCUST'
      Size = 100
    end
    object DocIDBASE_DRG_ADVCUST: TFIBLargeIntField
      FieldName = 'IDBASE_DRG_ADVCUST'
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DRG_ADVCUSTT'
      'SET '
      '    IDDOC_DRG_ADVCUSTT = :IDDOC_DRG_ADVCUSTT,'
      '    TDV_DRG_ADVCUSTT = :TDV_DRG_ADVCUSTT,'
      '    IDFIRM_DRG_ADVCUSTT = :IDFIRM_DRG_ADVCUSTT,'
      '    IDKLIENT_DRG_ADVCUSTT = :IDKLIENT_DRG_ADVCUSTT,'
      '    OPER_DRG_ADVCUSTT = :OPER_DRG_ADVCUSTT,'
      '    SUM_DRG_ADVCUSTT = :SUM_DRG_ADVCUSTT,'
      '    IDBASE_DRG_ADVCUSTT = :IDBASE_DRG_ADVCUSTT'
      'WHERE'
      '    ID_DRG_ADVCUSTT = :OLD_ID_DRG_ADVCUSTT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DRG_ADVCUSTT'
      'WHERE'
      '        ID_DRG_ADVCUSTT = :OLD_ID_DRG_ADVCUSTT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DRG_ADVCUSTT('
      '    ID_DRG_ADVCUSTT,'
      '    IDDOC_DRG_ADVCUSTT,'
      '    TDV_DRG_ADVCUSTT,'
      '    IDFIRM_DRG_ADVCUSTT,'
      '    IDKLIENT_DRG_ADVCUSTT,'
      '    OPER_DRG_ADVCUSTT,'
      '    SUM_DRG_ADVCUSTT,'
      '    IDBASE_DRG_ADVCUSTT'
      ')'
      'VALUES('
      '    :ID_DRG_ADVCUSTT,'
      '    :IDDOC_DRG_ADVCUSTT,'
      '    :TDV_DRG_ADVCUSTT,'
      '    :IDFIRM_DRG_ADVCUSTT,'
      '    :IDKLIENT_DRG_ADVCUSTT,'
      '    :OPER_DRG_ADVCUSTT,'
      '    :SUM_DRG_ADVCUSTT,'
      '    :IDBASE_DRG_ADVCUSTT'
      ')')
    RefreshSQL.Strings = (
      'select drg_advcustt.*,'
      '    sfirm.namefirm,'
      '    sklient.nameklient'
      'from  drg_advcustt'
      
        'left outer join sklient on drg_advcustt.idklient_drg_advcustt=sk' +
        'lient.idklient'
      
        'left outer join sfirm on drg_advcustt.idfirm_drg_advcustt=sfirm.' +
        'idfirm'
      'where(  drg_advcustt.iddoc_drg_advcustt=:PARAM_IDDOC'
      
        '     ) and (     DRG_ADVCUSTT.ID_DRG_ADVCUSTT = :OLD_ID_DRG_ADVC' +
        'USTT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select drg_advcustt.*,'
      '    sfirm.namefirm,'
      '    sklient.nameklient'
      'from  drg_advcustt'
      
        'left outer join sklient on drg_advcustt.idklient_drg_advcustt=sk' +
        'lient.idklient'
      
        'left outer join sfirm on drg_advcustt.idfirm_drg_advcustt=sfirm.' +
        'idfirm'
      'where drg_advcustt.iddoc_drg_advcustt=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'DRG_ADVCUSTT'
    AutoUpdateOptions.KeyFields = 'ID_DRG_ADVCUSTT'
    AutoUpdateOptions.GeneratorName = 'GEN_DRG_ADVCUSTT_ID'
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
    object DocTTDV_DRG_ADVCUSTT: TFIBSmallIntField
      FieldName = 'TDV_DRG_ADVCUSTT'
    end
    object DocTOPER_DRG_ADVCUSTT: TFIBSmallIntField
      FieldName = 'OPER_DRG_ADVCUSTT'
    end
    object DocTSUM_DRG_ADVCUSTT: TFIBBCDField
      FieldName = 'SUM_DRG_ADVCUSTT'
      Size = 2
      RoundByScale = True
    end
    object DocTID_DRG_ADVCUSTT: TFIBLargeIntField
      FieldName = 'ID_DRG_ADVCUSTT'
    end
    object DocTIDDOC_DRG_ADVCUSTT: TFIBLargeIntField
      FieldName = 'IDDOC_DRG_ADVCUSTT'
    end
    object DocTIDFIRM_DRG_ADVCUSTT: TFIBLargeIntField
      FieldName = 'IDFIRM_DRG_ADVCUSTT'
    end
    object DocTIDKLIENT_DRG_ADVCUSTT: TFIBLargeIntField
      FieldName = 'IDKLIENT_DRG_ADVCUSTT'
    end
    object DocTIDBASE_DRG_ADVCUSTT: TFIBLargeIntField
      FieldName = 'IDBASE_DRG_ADVCUSTT'
    end
    object DocTNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 100
    end
    object DocTNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
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
      'from DOC_RG_ADVCUST_GET_NUM_NEW_DOC (:PARAM_IDBASE)')
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
      'EXECUTE PROCEDURE DOC_RGADVCUST_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 304
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_RGADVCUST_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 240
    qoStartTransaction = True
  end
end
