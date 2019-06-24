object DMDocRegOtchetPost: TDMDocRegOtchetPost
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
      'UPDATE DRG_OTCHPOST'
      'SET '
      '    IDBASE_DRG_OTCHPOST = :IDBASE_DRG_OTCHPOST,'
      '    IDDOC_DRG_OTCHPOST = :IDDOC_DRG_OTCHPOST,'
      '    DESCR_DRG_OTCHPOST = :DESCR_DRG_OTCHPOST'
      'WHERE'
      '    ID_DRG_OTCHPOST = :OLD_ID_DRG_OTCHPOST'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DRG_OTCHPOST'
      'WHERE'
      '        ID_DRG_OTCHPOST = :OLD_ID_DRG_OTCHPOST'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DRG_OTCHPOST('
      '    ID_DRG_OTCHPOST,'
      '    IDBASE_DRG_OTCHPOST,'
      '    IDDOC_DRG_OTCHPOST,'
      '    DESCR_DRG_OTCHPOST'
      ')'
      'VALUES('
      '    :ID_DRG_OTCHPOST,'
      '    :IDBASE_DRG_OTCHPOST,'
      '    :IDDOC_DRG_OTCHPOST,'
      '    :DESCR_DRG_OTCHPOST'
      ')')
    RefreshSQL.Strings = (
      'select drg_otchpost.*'
      'from  drg_otchpost'
      'where(  drg_otchpost.iddoc_drg_otchpost=:PARAM_IDDOC'
      
        '     ) and (     DRG_OTCHPOST.ID_DRG_OTCHPOST = :OLD_ID_DRG_OTCH' +
        'POST'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select drg_otchpost.*'
      'from  drg_otchpost'
      'where drg_otchpost.iddoc_drg_otchpost=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'DRG_OTCHPOST'
    AutoUpdateOptions.KeyFields = 'ID_DRG_OTCHPOST'
    AutoUpdateOptions.GeneratorName = 'GEN_DRG_OTCHPOST_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object DocID_DRG_OTCHPOST: TFIBLargeIntField
      FieldName = 'ID_DRG_OTCHPOST'
    end
    object DocIDBASE_DRG_OTCHPOST: TFIBLargeIntField
      FieldName = 'IDBASE_DRG_OTCHPOST'
    end
    object DocIDDOC_DRG_OTCHPOST: TFIBLargeIntField
      FieldName = 'IDDOC_DRG_OTCHPOST'
    end
    object DocDESCR_DRG_OTCHPOST: TFIBWideStringField
      FieldName = 'DESCR_DRG_OTCHPOST'
      Size = 150
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DRG_OTCHPOSTT'
      'SET '
      '    IDBASE_DRG_OTCHPOSTT = :IDBASE_DRG_OTCHPOSTT,'
      '    IDDOC_DRG_OTCHPOSTT = :IDDOC_DRG_OTCHPOSTT,'
      '    TDV_DRG_OTCHPOSTT = :TDV_DRG_OTCHPOSTT,'
      '    IDFIRM_DRG_OTCHPOSTT = :IDFIRM_DRG_OTCHPOSTT,'
      '    IDSKLAD_DRG_OTCHPOSTT = :IDSKLAD_DRG_OTCHPOSTT,'
      '    IDPOST_DRG_OTCHPOSTT = :IDPOST_DRG_OTCHPOSTT,'
      '    IDDOCPOST_DRG_OTCHPOSTT = :IDDOCPOST_DRG_OTCHPOSTT,'
      '    IDNOM_DRG_OTCHPOSTT = :IDNOM_DRG_OTCHPOSTT,'
      '    KOL_DRG_OTCHPOSTT = :KOL_DRG_OTCHPOSTT,'
      '    SUM_DRG_OTCHPOSTT = :SUM_DRG_OTCHPOSTT'
      'WHERE'
      '    ID_DRG_OTCHPOSTT = :OLD_ID_DRG_OTCHPOSTT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DRG_OTCHPOSTT'
      'WHERE'
      '        ID_DRG_OTCHPOSTT = :OLD_ID_DRG_OTCHPOSTT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DRG_OTCHPOSTT('
      '    ID_DRG_OTCHPOSTT,'
      '    IDBASE_DRG_OTCHPOSTT,'
      '    IDDOC_DRG_OTCHPOSTT,'
      '    TDV_DRG_OTCHPOSTT,'
      '    IDFIRM_DRG_OTCHPOSTT,'
      '    IDSKLAD_DRG_OTCHPOSTT,'
      '    IDPOST_DRG_OTCHPOSTT,'
      '    IDDOCPOST_DRG_OTCHPOSTT,'
      '    IDNOM_DRG_OTCHPOSTT,'
      '    KOL_DRG_OTCHPOSTT,'
      '    SUM_DRG_OTCHPOSTT'
      ')'
      'VALUES('
      '    :ID_DRG_OTCHPOSTT,'
      '    :IDBASE_DRG_OTCHPOSTT,'
      '    :IDDOC_DRG_OTCHPOSTT,'
      '    :TDV_DRG_OTCHPOSTT,'
      '    :IDFIRM_DRG_OTCHPOSTT,'
      '    :IDSKLAD_DRG_OTCHPOSTT,'
      '    :IDPOST_DRG_OTCHPOSTT,'
      '    :IDDOCPOST_DRG_OTCHPOSTT,'
      '    :IDNOM_DRG_OTCHPOSTT,'
      '    :KOL_DRG_OTCHPOSTT,'
      '    :SUM_DRG_OTCHPOSTT'
      ')')
    RefreshSQL.Strings = (
      'select drg_otchpostt.*,'
      '    sfirm.namefirm,'
      '    ssklad.namesklad,'
      '    sklient.nameklient,'
      '    galldoc.prefiks_num_galldoc,'
      '    galldoc.numdoc,'
      '    galldoc.posdoc,'
      '    snom.namenom,'
      '    snom.codenom,'
      '    snom.artnom'
      'from drg_otchpostt'
      
        'left outer join sfirm on drg_otchpostt.idfirm_drg_otchpostt=sfir' +
        'm.idfirm'
      
        'left outer join ssklad on drg_otchpostt.idsklad_drg_otchpostt=ss' +
        'klad.idsklad'
      
        'left outer join sklient on drg_otchpostt.idpost_drg_otchpostt=sk' +
        'lient.idklient'
      
        'left outer join galldoc on drg_otchpostt.iddocpost_drg_otchpostt' +
        '=galldoc.iddoc'
      
        'left outer join snom on drg_otchpostt.idnom_drg_otchpostt=snom.i' +
        'dnom'
      ''
      'where(  drg_otchpostt.iddoc_drg_otchpostt=:PARAM_IDDOC'
      
        '     ) and (     DRG_OTCHPOSTT.ID_DRG_OTCHPOSTT = :OLD_ID_DRG_OT' +
        'CHPOSTT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select drg_otchpostt.*,'
      '    sfirm.namefirm,'
      '    ssklad.namesklad,'
      '    sklient.nameklient,'
      '    galldoc.prefiks_num_galldoc,'
      '    galldoc.numdoc,'
      '    galldoc.posdoc,'
      '    snom.namenom,'
      '    snom.codenom,'
      '    snom.artnom'
      'from drg_otchpostt'
      
        'left outer join sfirm on drg_otchpostt.idfirm_drg_otchpostt=sfir' +
        'm.idfirm'
      
        'left outer join ssklad on drg_otchpostt.idsklad_drg_otchpostt=ss' +
        'klad.idsklad'
      
        'left outer join sklient on drg_otchpostt.idpost_drg_otchpostt=sk' +
        'lient.idklient'
      
        'left outer join galldoc on drg_otchpostt.iddocpost_drg_otchpostt' +
        '=galldoc.iddoc'
      
        'left outer join snom on drg_otchpostt.idnom_drg_otchpostt=snom.i' +
        'dnom'
      ''
      'where drg_otchpostt.iddoc_drg_otchpostt=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'DRG_OTCHPOSTT'
    AutoUpdateOptions.KeyFields = 'ID_DRG_OTCHPOSTT'
    AutoUpdateOptions.GeneratorName = 'GEN_DRG_OTCHPOSTT_ID'
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
    object DocTID_DRG_OTCHPOSTT: TFIBLargeIntField
      FieldName = 'ID_DRG_OTCHPOSTT'
    end
    object DocTIDBASE_DRG_OTCHPOSTT: TFIBLargeIntField
      FieldName = 'IDBASE_DRG_OTCHPOSTT'
    end
    object DocTIDDOC_DRG_OTCHPOSTT: TFIBLargeIntField
      FieldName = 'IDDOC_DRG_OTCHPOSTT'
    end
    object DocTTDV_DRG_OTCHPOSTT: TFIBSmallIntField
      FieldName = 'TDV_DRG_OTCHPOSTT'
    end
    object DocTIDFIRM_DRG_OTCHPOSTT: TFIBLargeIntField
      FieldName = 'IDFIRM_DRG_OTCHPOSTT'
    end
    object DocTIDSKLAD_DRG_OTCHPOSTT: TFIBLargeIntField
      FieldName = 'IDSKLAD_DRG_OTCHPOSTT'
    end
    object DocTIDPOST_DRG_OTCHPOSTT: TFIBLargeIntField
      FieldName = 'IDPOST_DRG_OTCHPOSTT'
    end
    object DocTIDDOCPOST_DRG_OTCHPOSTT: TFIBLargeIntField
      FieldName = 'IDDOCPOST_DRG_OTCHPOSTT'
    end
    object DocTIDNOM_DRG_OTCHPOSTT: TFIBLargeIntField
      FieldName = 'IDNOM_DRG_OTCHPOSTT'
    end
    object DocTKOL_DRG_OTCHPOSTT: TFIBBCDField
      FieldName = 'KOL_DRG_OTCHPOSTT'
      Size = 3
      RoundByScale = True
    end
    object DocTSUM_DRG_OTCHPOSTT: TFIBBCDField
      FieldName = 'SUM_DRG_OTCHPOSTT'
      Size = 2
      RoundByScale = True
    end
    object DocTNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 200
    end
    object DocTNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 200
    end
    object DocTNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 200
    end
    object DocTPREFIKS_NUM_GALLDOC: TFIBWideStringField
      FieldName = 'PREFIKS_NUM_GALLDOC'
      Size = 12
    end
    object DocTNUMDOC: TFIBIntegerField
      FieldName = 'NUMDOC'
    end
    object DocTPOSDOC: TFIBDateTimeField
      FieldName = 'POSDOC'
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
      'from DOC_RGOTCHPOST_GET_NUM_NEW_DOC (:PARAM_IDBASE)')
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
      
        'EXECUTE PROCEDURE DOC_RGOTCHPOST_CANCEL_DVREG(:PARAM_IDDOC,0,0,0' +
        ')')
    Left = 96
    Top = 304
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_RGOTCHPOST_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 240
    qoStartTransaction = True
  end
end
