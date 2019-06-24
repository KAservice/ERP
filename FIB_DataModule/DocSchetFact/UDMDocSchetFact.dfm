object DMDocSchetFact: TDMDocSchetFact
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 430
  Width = 742
  object DataSourceDoc: TDataSource
    DataSet = Doc
    Left = 72
    Top = 72
  end
  object DataSourceDocT: TDataSource
    DataSet = DocT
    Left = 72
    Top = 120
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
      
        'select GALLDOC. *, NAME_SINFBASE_OBMEN, NAMEFIRM, NAMESKLAD, NAM' +
        'EKLIENT, FNAME_USER, '
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from GALLDOC'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      'left outer join SFIRM on IDFIRM=IDFIRMDOC'
      'left outer join SSKLAD on IDSKLAD=IDSKLDOC'
      'left outer join SKLIENT on IDKLIENT=IDKLDOC'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      
        'left outer join SPROJECT on galldoc.idproject_galldoc=sproject.i' +
        'd_sproject'
      
        'left outer join sbusiness_oper on galldoc.idbusinop_galldoc=sbus' +
        'iness_oper.id_sbusiness_oper'
      'where(  IDDOC=:ID'
      '     ) and (     GALLDOC.IDDOC = :OLD_IDDOC'
      '     )'
      '     ')
    SelectSQL.Strings = (
      
        'select GALLDOC. *, NAME_SINFBASE_OBMEN, NAMEFIRM, NAMESKLAD, NAM' +
        'EKLIENT, FNAME_USER, '
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from GALLDOC'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      'left outer join SFIRM on IDFIRM=IDFIRMDOC'
      'left outer join SSKLAD on IDSKLAD=IDSKLDOC'
      'left outer join SKLIENT on IDKLIENT=IDKLDOC'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      
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
    object DocAllIDDOC: TFIBBCDField
      FieldName = 'IDDOC'
      Size = 0
      RoundByScale = True
    end
    object DocAllIDFIRMDOC: TFIBBCDField
      FieldName = 'IDFIRMDOC'
      OnChange = DocAllIDFIRMDOCChange
      Size = 0
      RoundByScale = True
    end
    object DocAllIDSKLDOC: TFIBBCDField
      FieldName = 'IDSKLDOC'
      OnChange = DocAllIDSKLDOCChange
      Size = 0
      RoundByScale = True
    end
    object DocAllIDKLDOC: TFIBBCDField
      FieldName = 'IDKLDOC'
      Size = 0
      RoundByScale = True
    end
    object DocAllIDDOGDOC: TFIBBCDField
      FieldName = 'IDDOGDOC'
      Size = 0
      RoundByScale = True
    end
    object DocAllIDUSERDOC: TFIBBCDField
      FieldName = 'IDUSERDOC'
      Size = 0
      RoundByScale = True
    end
    object DocAllIDDOCOSNDOC: TFIBBCDField
      FieldName = 'IDDOCOSNDOC'
      Size = 0
      RoundByScale = True
    end
    object DocAllIDEXTDOC: TFIBBCDField
      FieldName = 'IDEXTDOC'
      Size = 0
      RoundByScale = True
    end
    object DocAllIDBASE_GALLDOC: TFIBBCDField
      FieldName = 'IDBASE_GALLDOC'
      OnChange = DocAllIDBASE_GALLDOCChange
      Size = 0
      RoundByScale = True
    end
    object DocAllTDOC: TFIBWideStringField
      FieldName = 'TDOC'
      Size = 10
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
    object DocAllFNAME_USER: TFIBWideStringField
      FieldName = 'FNAME_USER'
      Size = 200
    end
    object DocAllIDPROJECT_GALLDOC: TFIBBCDField
      FieldName = 'IDPROJECT_GALLDOC'
      Size = 0
      RoundByScale = True
    end
    object DocAllIDBUSINOP_GALLDOC: TFIBBCDField
      FieldName = 'IDBUSINOP_GALLDOC'
      Size = 0
      RoundByScale = True
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
      'UPDATE DSCHFACT'
      'SET '
      '    GID_DSCHFACT = :GID_DSCHFACT,'
      '    IDDOC_DSCHFACT = :IDDOC_DSCHFACT,'
      '    IDGRPOL_DSCHFACT = :IDGRPOL_DSCHFACT,'
      '    PRIM_DSCHFACT = :PRIM_DSCHFACT,'
      '    IDTPRICE_DSCHFACT = :IDTPRICE_DSCHFACT,'
      '    IDBASE_DSCHFACT = :IDBASE_DSCHFACT,'
      '    NUMPLAT_RASCH_DOC_DSCHFACT = :NUMPLAT_RASCH_DOC_DSCHFACT,'
      '    DATEPLAT_RASCH_DOC_DSCHFACT = :DATEPLAT_RASCH_DOC_DSCHFACT'
      'WHERE'
      '    ID_DSCHFACT = :OLD_ID_DSCHFACT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DSCHFACT'
      'WHERE'
      '        ID_DSCHFACT = :OLD_ID_DSCHFACT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DSCHFACT('
      '    ID_DSCHFACT,'
      '    GID_DSCHFACT,'
      '    IDDOC_DSCHFACT,'
      '    IDGRPOL_DSCHFACT,'
      '    PRIM_DSCHFACT,'
      '    IDTPRICE_DSCHFACT,'
      '    IDBASE_DSCHFACT,'
      '    NUMPLAT_RASCH_DOC_DSCHFACT,'
      '    DATEPLAT_RASCH_DOC_DSCHFACT'
      ')'
      'VALUES('
      '    :ID_DSCHFACT,'
      '    :GID_DSCHFACT,'
      '    :IDDOC_DSCHFACT,'
      '    :IDGRPOL_DSCHFACT,'
      '    :PRIM_DSCHFACT,'
      '    :IDTPRICE_DSCHFACT,'
      '    :IDBASE_DSCHFACT,'
      '    :NUMPLAT_RASCH_DOC_DSCHFACT,'
      '    :DATEPLAT_RASCH_DOC_DSCHFACT'
      ')')
    RefreshSQL.Strings = (
      'select DSCHFACT.* ,  NAMEKLIENT'
      'from  DSCHFACT'
      'left outer join SKLIENT on IDGRPOL_DSCHFACT=IDKLIENT'
      'where(  IDDOC_DSCHFACT=:ID'
      '     ) and (     DSCHFACT.ID_DSCHFACT = :OLD_ID_DSCHFACT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select DSCHFACT.* ,  NAMEKLIENT'
      'from  DSCHFACT'
      'left outer join SKLIENT on IDGRPOL_DSCHFACT=IDKLIENT'
      'where IDDOC_DSCHFACT=:ID')
    AutoUpdateOptions.UpdateTableName = 'DSCHFACT'
    AutoUpdateOptions.KeyFields = 'ID_DSCHFACT'
    AutoUpdateOptions.GeneratorName = 'GEN_DSCHFACT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 72
    object DocID_DSCHFACT: TFIBBCDField
      FieldName = 'ID_DSCHFACT'
      Size = 0
      RoundByScale = True
    end
    object DocIDDOC_DSCHFACT: TFIBBCDField
      FieldName = 'IDDOC_DSCHFACT'
      Size = 0
      RoundByScale = True
    end
    object DocIDTPRICE_DSCHFACT: TFIBBCDField
      FieldName = 'IDTPRICE_DSCHFACT'
      Size = 0
      RoundByScale = True
    end
    object DocIDGRPOL_DSCHFACT: TFIBBCDField
      FieldName = 'IDGRPOL_DSCHFACT'
      Size = 0
      RoundByScale = True
    end
    object DocIDBASE_DSCHFACT: TFIBBCDField
      FieldName = 'IDBASE_DSCHFACT'
      Size = 0
      RoundByScale = True
    end
    object DocGID_DSCHFACT: TFIBWideStringField
      FieldName = 'GID_DSCHFACT'
      Size = 10
    end
    object DocPRIM_DSCHFACT: TFIBWideStringField
      FieldName = 'PRIM_DSCHFACT'
      Size = 100
    end
    object DocNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 200
    end
    object DocNUMPLAT_RASCH_DOC_DSCHFACT: TFIBWideStringField
      FieldName = 'NUMPLAT_RASCH_DOC_DSCHFACT'
    end
    object DocDATEPLAT_RASCH_DOC_DSCHFACT: TFIBDateTimeField
      FieldName = 'DATEPLAT_RASCH_DOC_DSCHFACT'
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DSCHFACTT'
      'SET '
      '    GID_DSCHFACTT = :GID_DSCHFACTT,'
      '    IDDOC_DSCHFACTT = :IDDOC_DSCHFACTT,'
      '    IDNOM_DSCHFACTT = :IDNOM_DSCHFACTT,'
      '    IDED_DSCHFACTT = :IDED_DSCHFACTT,'
      '    KOL_DSCHFACTT = :KOL_DSCHFACTT,'
      '    KF_DSCHFACTT = :KF_DSCHFACTT,'
      '    PRICE_DSCHFACTT = :PRICE_DSCHFACTT,'
      '    SUM_DSCHFACTT = :SUM_DSCHFACTT,'
      '    STNDS_DSCHFACTT = :STNDS_DSCHFACTT,'
      '    SUMNDS_DSCHFACTT = :SUMNDS_DSCHFACTT,'
      '    IDBASE_DSCHFACTT = :IDBASE_DSCHFACTT'
      'WHERE'
      '    ID_DSCHFACTT = :OLD_ID_DSCHFACTT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DSCHFACTT'
      'WHERE'
      '        ID_DSCHFACTT = :OLD_ID_DSCHFACTT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DSCHFACTT('
      '    ID_DSCHFACTT,'
      '    GID_DSCHFACTT,'
      '    IDDOC_DSCHFACTT,'
      '    IDNOM_DSCHFACTT,'
      '    IDED_DSCHFACTT,'
      '    KOL_DSCHFACTT,'
      '    KF_DSCHFACTT,'
      '    PRICE_DSCHFACTT,'
      '    SUM_DSCHFACTT,'
      '    STNDS_DSCHFACTT,'
      '    SUMNDS_DSCHFACTT,'
      '    IDBASE_DSCHFACTT'
      ')'
      'VALUES('
      '    :ID_DSCHFACTT,'
      '    :GID_DSCHFACTT,'
      '    :IDDOC_DSCHFACTT,'
      '    :IDNOM_DSCHFACTT,'
      '    :IDED_DSCHFACTT,'
      '    :KOL_DSCHFACTT,'
      '    :KF_DSCHFACTT,'
      '    :PRICE_DSCHFACTT,'
      '    :SUM_DSCHFACTT,'
      '    :STNDS_DSCHFACTT,'
      '    :SUMNDS_DSCHFACTT,'
      '    :IDBASE_DSCHFACTT'
      ')')
    RefreshSQL.Strings = (
      'select DSCHFACTT.*, NAMENOM, NAMEED ,TNOM'
      'from '
      'DSCHFACTT'
      'LEFT OUTER JOIN SNOM  ON IDNOM_DSCHFACTT=IDNOM '
      'left outer join SED  on  IDED_DSCHFACTT=IDED'
      'where(  IDDOC_DSCHFACTT=:ID'
      '     ) and (     DSCHFACTT.ID_DSCHFACTT = :OLD_ID_DSCHFACTT'
      '     )'
      '    '
      ''
      '')
    SelectSQL.Strings = (
      'select DSCHFACTT.*,'
      'NAMENOM,'
      ' NAMEED ,'
      ' TNOM,'
      ' snom.artnom,'
      ' snom.codenom,'
      ' sed.shed'
      'from '
      'DSCHFACTT'
      'LEFT OUTER JOIN SNOM  ON IDNOM_DSCHFACTT=IDNOM '
      'left outer join SED  on  IDED_DSCHFACTT=IDED'
      'where IDDOC_DSCHFACTT=:ID'
      '')
    AutoUpdateOptions.UpdateTableName = 'DSCHFACTT'
    AutoUpdateOptions.KeyFields = 'ID_DSCHFACTT'
    AutoUpdateOptions.GeneratorName = 'GEN_DSCHFACTT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    AfterDelete = DocTAfterDelete
    BeforeDelete = DocTBeforeDelete
    OnCalcFields = DocTCalcFields
    OnNewRecord = DocTNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 120
    object DocTKOL_DSCHFACTT: TFIBBCDField
      FieldName = 'KOL_DSCHFACTT'
      OnChange = DocTKOL_DSCHFACTTChange
      Size = 3
      RoundByScale = True
    end
    object DocTKF_DSCHFACTT: TFIBBCDField
      FieldName = 'KF_DSCHFACTT'
      Size = 3
      RoundByScale = True
    end
    object DocTPRICE_DSCHFACTT: TFIBBCDField
      FieldName = 'PRICE_DSCHFACTT'
      OnChange = DocTPRICE_DSCHFACTTChange
      Size = 2
      RoundByScale = True
    end
    object DocTSUM_DSCHFACTT: TFIBBCDField
      FieldName = 'SUM_DSCHFACTT'
      Size = 2
      RoundByScale = True
    end
    object DocTSTNDS_DSCHFACTT: TFIBIntegerField
      FieldName = 'STNDS_DSCHFACTT'
    end
    object DocTSUMNDS_DSCHFACTT: TFIBBCDField
      FieldName = 'SUMNDS_DSCHFACTT'
      Size = 2
      RoundByScale = True
    end
    object DocTTNOM: TFIBIntegerField
      FieldName = 'TNOM'
    end
    object DocTRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object DocTID_DSCHFACTT: TFIBBCDField
      FieldName = 'ID_DSCHFACTT'
      Size = 0
      RoundByScale = True
    end
    object DocTIDDOC_DSCHFACTT: TFIBBCDField
      FieldName = 'IDDOC_DSCHFACTT'
      Size = 0
      RoundByScale = True
    end
    object DocTIDNOM_DSCHFACTT: TFIBBCDField
      FieldName = 'IDNOM_DSCHFACTT'
      Size = 0
      RoundByScale = True
    end
    object DocTIDED_DSCHFACTT: TFIBBCDField
      FieldName = 'IDED_DSCHFACTT'
      Size = 0
      RoundByScale = True
    end
    object DocTIDBASE_DSCHFACTT: TFIBBCDField
      FieldName = 'IDBASE_DSCHFACTT'
      Size = 0
      RoundByScale = True
    end
    object DocTGID_DSCHFACTT: TFIBWideStringField
      FieldName = 'GID_DSCHFACTT'
      Size = 10
    end
    object DocTNDS_DSCHFACTT: TFIBIntegerField
      FieldName = 'NDS_DSCHFACTT'
    end
    object DocTNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object DocTNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 200
    end
    object DocTARTNOM: TFIBWideStringField
      FieldName = 'ARTNOM'
      Size = 40
    end
    object DocTCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object DocTSHED: TFIBWideStringField
      FieldName = 'SHED'
      Size = 13
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
    Left = 256
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
    Left = 256
    Top = 72
  end
  object NumDoc: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      
        'from DOC_SCHFACT_GET_NUM_NEW_DOC (:PARAM_IDBASE,:PARAM_IDFIRM,:P' +
        'ARAM_IDSKLAD)')
    Transaction = IBTr
    Left = 320
    Top = 24
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
    Top = 184
  end
  object IBQ: TpFIBDataSet
    Transaction = IBTr
    Left = 272
    Top = 160
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_SCHFACT_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 256
    Top = 320
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_SCHFACT_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 256
    Top = 272
    qoStartTransaction = True
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 328
    Top = 160
    qoStartTransaction = True
  end
end
