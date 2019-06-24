object DMDocRegPaySale: TDMDocRegPaySale
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
      'UPDATE DRG_PAYSALE'
      'SET '
      '    IDDOC_DRG_PAYSALE = :IDDOC_DRG_PAYSALE,'
      '    DESCR_DRG_PAYSALE = :DESCR_DRG_PAYSALE,'
      '    IDBASE_DRG_PAYSALE = :IDBASE_DRG_PAYSALE'
      'WHERE'
      '    ID_DRG_PAYSALE = :OLD_ID_DRG_PAYSALE'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DRG_PAYSALE'
      'WHERE'
      '        ID_DRG_PAYSALE = :OLD_ID_DRG_PAYSALE'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DRG_PAYSALE('
      '    ID_DRG_PAYSALE,'
      '    IDDOC_DRG_PAYSALE,'
      '    DESCR_DRG_PAYSALE,'
      '    IDBASE_DRG_PAYSALE'
      ')'
      'VALUES('
      '    :ID_DRG_PAYSALE,'
      '    :IDDOC_DRG_PAYSALE,'
      '    :DESCR_DRG_PAYSALE,'
      '    :IDBASE_DRG_PAYSALE'
      ')')
    RefreshSQL.Strings = (
      'select drg_paysale.*'
      'from  drg_paysale'
      'where(  drg_paysale.iddoc_drg_paysale=:PARAM_IDDOC'
      
        '     ) and (     DRG_PAYSALE.ID_DRG_PAYSALE = :OLD_ID_DRG_PAYSAL' +
        'E'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select drg_paysale.*'
      'from  drg_paysale'
      'where drg_paysale.iddoc_drg_paysale=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'DRG_PAYSALE'
    AutoUpdateOptions.KeyFields = 'ID_DRG_PAYSALE'
    AutoUpdateOptions.GeneratorName = 'GEN_DRG_PAYSALE_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object DocID_DRG_PAYSALE: TFIBLargeIntField
      FieldName = 'ID_DRG_PAYSALE'
    end
    object DocIDDOC_DRG_PAYSALE: TFIBLargeIntField
      FieldName = 'IDDOC_DRG_PAYSALE'
    end
    object DocDESCR_DRG_PAYSALE: TFIBWideStringField
      FieldName = 'DESCR_DRG_PAYSALE'
      Size = 100
    end
    object DocIDBASE_DRG_PAYSALE: TFIBLargeIntField
      FieldName = 'IDBASE_DRG_PAYSALE'
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DRG_PAYSALET'
      'SET '
      '    IDDOC_DRG_PAYSALET = :IDDOC_DRG_PAYSALET,'
      '    TDV_DRG_PAYSALET = :TDV_DRG_PAYSALET,'
      '    IDFIRM_DRG_PAYSALET = :IDFIRM_DRG_PAYSALET,'
      '    IDKLIENT_DRG_PAYSALET = :IDKLIENT_DRG_PAYSALET,'
      '    IDDOG_DRG_PAYSALET = :IDDOG_DRG_PAYSALET,'
      '    IDDOCSALE_DRG_PAYSALET = :IDDOCSALE_DRG_PAYSALET,'
      '    DATE_DRG_PAYSALET = :DATE_DRG_PAYSALET,'
      '    SUM_DRG_PAYSALET = :SUM_DRG_PAYSALET,'
      '    IDBASE_DRG_PAYSALET = :IDBASE_DRG_PAYSALET,'
      '    OPER_DRG_PAYSALET = :OPER_DRG_PAYSALET'
      'WHERE'
      '    ID_DRG_PAYSALET = :OLD_ID_DRG_PAYSALET'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DRG_PAYSALET'
      'WHERE'
      '        ID_DRG_PAYSALET = :OLD_ID_DRG_PAYSALET'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DRG_PAYSALET('
      '    ID_DRG_PAYSALET,'
      '    IDDOC_DRG_PAYSALET,'
      '    TDV_DRG_PAYSALET,'
      '    IDFIRM_DRG_PAYSALET,'
      '    IDKLIENT_DRG_PAYSALET,'
      '    IDDOG_DRG_PAYSALET,'
      '    IDDOCSALE_DRG_PAYSALET,'
      '    DATE_DRG_PAYSALET,'
      '    SUM_DRG_PAYSALET,'
      '    IDBASE_DRG_PAYSALET,'
      '    OPER_DRG_PAYSALET'
      ')'
      'VALUES('
      '    :ID_DRG_PAYSALET,'
      '    :IDDOC_DRG_PAYSALET,'
      '    :TDV_DRG_PAYSALET,'
      '    :IDFIRM_DRG_PAYSALET,'
      '    :IDKLIENT_DRG_PAYSALET,'
      '    :IDDOG_DRG_PAYSALET,'
      '    :IDDOCSALE_DRG_PAYSALET,'
      '    :DATE_DRG_PAYSALET,'
      '    :SUM_DRG_PAYSALET,'
      '    :IDBASE_DRG_PAYSALET,'
      '    :OPER_DRG_PAYSALET'
      ')')
    RefreshSQL.Strings = (
      'select drg_paysalet.*,'
      '    sfirm.namefirm,'
      '    sklient.nameklient,'
      '    sdog.name_sdog,'
      '    galldoc.tdoc,'
      '    galldoc.posdoc,'
      '    galldoc.numdoc'
      'from  drg_paysalet'
      
        'left outer join sfirm on drg_paysalet.idfirm_drg_paysalet=sfirm.' +
        'idfirm'
      
        'left outer join sklient on drg_paysalet.idklient_drg_paysalet=sk' +
        'lient.idklient'
      
        'left outer join sdog on drg_paysalet.iddog_drg_paysalet=sdog.nam' +
        'e_sdog'
      
        'left outer join galldoc on drg_paysalet.iddocsale_drg_paysalet=g' +
        'alldoc.iddoc'
      'where(  drg_paysalet.iddoc_drg_paysalet=:PARAM_IDDOC'
      
        '     ) and (     DRG_PAYSALET.ID_DRG_PAYSALET = :OLD_ID_DRG_PAYS' +
        'ALET'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select drg_paysalet.*,'
      '    sfirm.namefirm,'
      '    sklient.nameklient,'
      '    sdog.name_sdog,'
      '    galldoc.tdoc,'
      '    galldoc.posdoc,'
      '    galldoc.numdoc'
      'from  drg_paysalet'
      
        'left outer join sfirm on drg_paysalet.idfirm_drg_paysalet=sfirm.' +
        'idfirm'
      
        'left outer join sklient on drg_paysalet.idklient_drg_paysalet=sk' +
        'lient.idklient'
      
        'left outer join sdog on drg_paysalet.iddog_drg_paysalet=sdog.nam' +
        'e_sdog'
      
        'left outer join galldoc on drg_paysalet.iddocsale_drg_paysalet=g' +
        'alldoc.iddoc'
      'where drg_paysalet.iddoc_drg_paysalet=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'DRG_PAYSALET'
    AutoUpdateOptions.KeyFields = 'ID_DRG_PAYSALET'
    AutoUpdateOptions.GeneratorName = 'GEN_DRG_PAYSALET_ID'
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
    object DocTTDV_DRG_PAYSALET: TFIBSmallIntField
      FieldName = 'TDV_DRG_PAYSALET'
    end
    object DocTDATE_DRG_PAYSALET: TFIBDateField
      FieldName = 'DATE_DRG_PAYSALET'
    end
    object DocTSUM_DRG_PAYSALET: TFIBBCDField
      FieldName = 'SUM_DRG_PAYSALET'
      Size = 2
      RoundByScale = True
    end
    object DocTPOSDOC: TFIBDateTimeField
      FieldName = 'POSDOC'
    end
    object DocTNUMDOC: TFIBIntegerField
      FieldName = 'NUMDOC'
    end
    object DocTID_DRG_PAYSALET: TFIBLargeIntField
      FieldName = 'ID_DRG_PAYSALET'
    end
    object DocTIDDOC_DRG_PAYSALET: TFIBLargeIntField
      FieldName = 'IDDOC_DRG_PAYSALET'
    end
    object DocTIDFIRM_DRG_PAYSALET: TFIBLargeIntField
      FieldName = 'IDFIRM_DRG_PAYSALET'
    end
    object DocTIDKLIENT_DRG_PAYSALET: TFIBLargeIntField
      FieldName = 'IDKLIENT_DRG_PAYSALET'
    end
    object DocTIDDOG_DRG_PAYSALET: TFIBLargeIntField
      FieldName = 'IDDOG_DRG_PAYSALET'
    end
    object DocTIDDOCSALE_DRG_PAYSALET: TFIBLargeIntField
      FieldName = 'IDDOCSALE_DRG_PAYSALET'
    end
    object DocTIDBASE_DRG_PAYSALET: TFIBLargeIntField
      FieldName = 'IDBASE_DRG_PAYSALET'
    end
    object DocTOPER_DRG_PAYSALET: TFIBIntegerField
      FieldName = 'OPER_DRG_PAYSALET'
    end
    object DocTNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 100
    end
    object DocTNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 100
    end
    object DocTNAME_SDOG: TFIBWideStringField
      FieldName = 'NAME_SDOG'
      Size = 100
    end
    object DocTTDOC: TFIBWideStringField
      FieldName = 'TDOC'
      Size = 10
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
      'from DOC_RG_PAYSALE_GET_NUM_NEW_DOC (:PARAM_IDBASE)')
    Transaction = IBTr
    Left = 296
    Top = 16
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
      'EXECUTE PROCEDURE DOC_RGPAYSALE_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 304
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_RGPAYSALE_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 240
    qoStartTransaction = True
  end
end
