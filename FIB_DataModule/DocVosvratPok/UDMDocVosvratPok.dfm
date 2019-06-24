object DMDocVosvratPok: TDMDocVosvratPok
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 406
  Width = 420
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
      
        'select GALLDOC.*, FNAME_USER , NAME_SINFBASE_OBMEN, NAMEFIRM, NA' +
        'MESKLAD,'
      ' NAMEKLIENT, NAME_SDOG, '
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from '
      '  GALLDOC'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      'left outer join SFIRM on IDFIRMDOC=IDFIRM'
      'left outer join SSKLAD on IDSKLDOC=IDSKLAD'
      'left outer join SKLIENT on IDKLDOC=IDKLIENT'
      'left outer join SDOG on IDDOGDOC=ID_SDOG'
      
        'left outer join SPROJECT on galldoc.idproject_galldoc=sproject.i' +
        'd_sproject'
      
        'left outer join sbusiness_oper on galldoc.idbusinop_galldoc=sbus' +
        'iness_oper.id_sbusiness_oper'
      'where(  '
      '  IDDOC=:ID'
      '     ) and (     GALLDOC.IDDOC = :OLD_IDDOC'
      '     )'
      '     ')
    SelectSQL.Strings = (
      
        'select GALLDOC.*, FNAME_USER , NAME_SINFBASE_OBMEN, NAMEFIRM, NA' +
        'MESKLAD,'
      ' NAMEKLIENT, NAME_SDOG, '
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from '
      '  GALLDOC'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      'left outer join SFIRM on IDFIRMDOC=IDFIRM'
      'left outer join SSKLAD on IDSKLDOC=IDSKLAD'
      'left outer join SKLIENT on IDKLDOC=IDKLIENT'
      'left outer join SDOG on IDDOGDOC=ID_SDOG'
      
        'left outer join SPROJECT on galldoc.idproject_galldoc=sproject.i' +
        'd_sproject'
      
        'left outer join sbusiness_oper on galldoc.idbusinop_galldoc=sbus' +
        'iness_oper.id_sbusiness_oper'
      'where '
      '  IDDOC=:ID ')
    AutoUpdateOptions.UpdateTableName = 'GALLDOC'
    AutoUpdateOptions.KeyFields = 'IDDOC'
    AutoUpdateOptions.GeneratorName = 'GEN_GALLDOC_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object DocAllIDDOC: TFIBLargeIntField
      FieldName = 'IDDOC'
    end
    object DocAllPOSDOC: TFIBDateTimeField
      FieldName = 'POSDOC'
      OnChange = DocAllPOSDOCChange
    end
    object DocAllPRDOC: TFIBSmallIntField
      FieldName = 'PRDOC'
    end
    object DocAllTDOC: TFIBWideStringField
      FieldName = 'TDOC'
      Size = 10
    end
    object DocAllNUMDOC: TFIBIntegerField
      FieldName = 'NUMDOC'
    end
    object DocAllIDFIRMDOC: TFIBLargeIntField
      FieldName = 'IDFIRMDOC'
      OnChange = DocAllIDFIRMDOCChange
    end
    object DocAllIDSKLDOC: TFIBLargeIntField
      FieldName = 'IDSKLDOC'
      OnChange = DocAllIDSKLDOCChange
    end
    object DocAllIDKLDOC: TFIBLargeIntField
      FieldName = 'IDKLDOC'
    end
    object DocAllIDDOGDOC: TFIBLargeIntField
      FieldName = 'IDDOGDOC'
    end
    object DocAllSUMDOC: TFIBBCDField
      FieldName = 'SUMDOC'
      Size = 2
      RoundByScale = True
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
    object DocAllIDBUSINOP_GALLDOC: TFIBLargeIntField
      FieldName = 'IDBUSINOP_GALLDOC'
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
    object DocAllNAME_SDOG: TFIBWideStringField
      FieldName = 'NAME_SDOG'
      Size = 200
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
      Size = 9
    end
  end
  object Doc: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DVPOK'
      'SET '
      '    GID_DVPOK = :GID_DVPOK,'
      '    IDDOC_DVPOK = :IDDOC_DVPOK,'
      '    IDTPRICE_DVPOK = :IDTPRICE_DVPOK,'
      '    IDRTPRICE_DVPOK = :IDRTPRICE_DVPOK,'
      '    DESCR_DVPOK = :DESCR_DVPOK,'
      '    OPER_DVPOK = :OPER_DVPOK,'
      '    SUM_DVPOK = :SUM_DVPOK,'
      '    IDBASE_DVPOK = :IDBASE_DVPOK,'
      '    KLIENT_NAME_DVPOK = :KLIENT_NAME_DVPOK,'
      '    KLIENT_ADR_DVPOK = :KLIENT_ADR_DVPOK,'
      '    KLIENT_PHONE_DVPOK = :KLIENT_PHONE_DVPOK,'
      '    KLIENT_PASSPORT_DVPOK = :KLIENT_PASSPORT_DVPOK,'
      '    PRICHINA_DVPOK = :PRICHINA_DVPOK,'
      '    NUMDOCSALE_DVPOK = :NUMDOCSALE_DVPOK,'
      '    POSDOCSALE_DVPOK = :POSDOCSALE_DVPOK,'
      '    NUMDOCKL_DVPOK = :NUMDOCKL_DVPOK,'
      '    POSDOCKL_DVPOK = :POSDOCKL_DVPOK'
      'WHERE'
      '    ID_DVPOK = :OLD_ID_DVPOK'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DVPOK'
      'WHERE'
      '        ID_DVPOK = :OLD_ID_DVPOK'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DVPOK('
      '    ID_DVPOK,'
      '    GID_DVPOK,'
      '    IDDOC_DVPOK,'
      '    IDTPRICE_DVPOK,'
      '    IDRTPRICE_DVPOK,'
      '    DESCR_DVPOK,'
      '    OPER_DVPOK,'
      '    SUM_DVPOK,'
      '    IDBASE_DVPOK,'
      '    KLIENT_NAME_DVPOK,'
      '    KLIENT_ADR_DVPOK,'
      '    KLIENT_PHONE_DVPOK,'
      '    KLIENT_PASSPORT_DVPOK,'
      '    PRICHINA_DVPOK,'
      '    NUMDOCSALE_DVPOK,'
      '    POSDOCSALE_DVPOK,'
      '    NUMDOCKL_DVPOK,'
      '    POSDOCKL_DVPOK'
      ')'
      'VALUES('
      '    :ID_DVPOK,'
      '    :GID_DVPOK,'
      '    :IDDOC_DVPOK,'
      '    :IDTPRICE_DVPOK,'
      '    :IDRTPRICE_DVPOK,'
      '    :DESCR_DVPOK,'
      '    :OPER_DVPOK,'
      '    :SUM_DVPOK,'
      '    :IDBASE_DVPOK,'
      '    :KLIENT_NAME_DVPOK,'
      '    :KLIENT_ADR_DVPOK,'
      '    :KLIENT_PHONE_DVPOK,'
      '    :KLIENT_PASSPORT_DVPOK,'
      '    :PRICHINA_DVPOK,'
      '    :NUMDOCSALE_DVPOK,'
      '    :POSDOCSALE_DVPOK,'
      '    :NUMDOCKL_DVPOK,'
      '    :POSDOCKL_DVPOK'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from  DVPOK'
      'where(  IDDOC_DVPOK=:ID'
      '     ) and (     DVPOK.ID_DVPOK = :OLD_ID_DVPOK'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from  DVPOK'
      'where IDDOC_DVPOK=:ID')
    AutoUpdateOptions.UpdateTableName = 'DVPOK'
    AutoUpdateOptions.KeyFields = 'ID_DVPOK'
    AutoUpdateOptions.GeneratorName = 'GEN_DVPOK_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object DocID_DVPOK: TFIBLargeIntField
      FieldName = 'ID_DVPOK'
    end
    object DocGID_DVPOK: TFIBWideStringField
      FieldName = 'GID_DVPOK'
      Size = 10
    end
    object DocIDDOC_DVPOK: TFIBLargeIntField
      FieldName = 'IDDOC_DVPOK'
    end
    object DocIDTPRICE_DVPOK: TFIBLargeIntField
      FieldName = 'IDTPRICE_DVPOK'
    end
    object DocIDRTPRICE_DVPOK: TFIBLargeIntField
      FieldName = 'IDRTPRICE_DVPOK'
    end
    object DocDESCR_DVPOK: TFIBWideStringField
      FieldName = 'DESCR_DVPOK'
      Size = 150
    end
    object DocOPER_DVPOK: TFIBIntegerField
      FieldName = 'OPER_DVPOK'
    end
    object DocSUM_DVPOK: TFIBBCDField
      FieldName = 'SUM_DVPOK'
      Size = 2
      RoundByScale = True
    end
    object DocIDBASE_DVPOK: TFIBLargeIntField
      FieldName = 'IDBASE_DVPOK'
    end
    object DocKLIENT_NAME_DVPOK: TFIBWideStringField
      FieldName = 'KLIENT_NAME_DVPOK'
      Size = 200
    end
    object DocKLIENT_ADR_DVPOK: TFIBWideStringField
      FieldName = 'KLIENT_ADR_DVPOK'
      Size = 200
    end
    object DocKLIENT_PHONE_DVPOK: TFIBWideStringField
      FieldName = 'KLIENT_PHONE_DVPOK'
      Size = 200
    end
    object DocKLIENT_PASSPORT_DVPOK: TFIBWideStringField
      FieldName = 'KLIENT_PASSPORT_DVPOK'
      Size = 200
    end
    object DocPRICHINA_DVPOK: TFIBWideStringField
      FieldName = 'PRICHINA_DVPOK'
      Size = 200
    end
    object DocNUMDOCSALE_DVPOK: TFIBWideStringField
      FieldName = 'NUMDOCSALE_DVPOK'
    end
    object DocPOSDOCSALE_DVPOK: TFIBDateTimeField
      FieldName = 'POSDOCSALE_DVPOK'
    end
    object DocNUMDOCKL_DVPOK: TFIBWideStringField
      FieldName = 'NUMDOCKL_DVPOK'
    end
    object DocPOSDOCKL_DVPOK: TFIBDateTimeField
      FieldName = 'POSDOCKL_DVPOK'
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DVPOKT'
      'SET '
      '    GID_DVPOKT = :GID_DVPOKT,'
      '    IDDOC_DVPOKT = :IDDOC_DVPOKT,'
      '    IDNOM_DVPOKT = :IDNOM_DVPOKT,'
      '    IDED_DVPOKT = :IDED_DVPOKT,'
      '    IDPART_DVPOKT = :IDPART_DVPOKT,'
      '    KOL_DVPOKT = :KOL_DVPOKT,'
      '    KF_DVPOKT = :KF_DVPOKT,'
      '    PRICE_DVPOKT = :PRICE_DVPOKT,'
      '    SUM_DVPOKT = :SUM_DVPOKT,'
      '    RPRICE_DVPOKT = :RPRICE_DVPOKT,'
      '    RSUM_DVPOKT = :RSUM_DVPOKT,'
      '    IDBASE_DVPOKT = :IDBASE_DVPOKT,'
      '    NDS_DVPOKT = :NDS_DVPOKT,'
      '    SUMNDS_DVPOKT = :SUMNDS_DVPOKT'
      'WHERE'
      '    ID_DVPOKT = :OLD_ID_DVPOKT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DVPOKT'
      'WHERE'
      '        ID_DVPOKT = :OLD_ID_DVPOKT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DVPOKT('
      '    ID_DVPOKT,'
      '    GID_DVPOKT,'
      '    IDDOC_DVPOKT,'
      '    IDNOM_DVPOKT,'
      '    IDED_DVPOKT,'
      '    IDPART_DVPOKT,'
      '    KOL_DVPOKT,'
      '    KF_DVPOKT,'
      '    PRICE_DVPOKT,'
      '    SUM_DVPOKT,'
      '    RPRICE_DVPOKT,'
      '    RSUM_DVPOKT,'
      '    IDBASE_DVPOKT,'
      '    NDS_DVPOKT,'
      '    SUMNDS_DVPOKT'
      ')'
      'VALUES('
      '    :ID_DVPOKT,'
      '    :GID_DVPOKT,'
      '    :IDDOC_DVPOKT,'
      '    :IDNOM_DVPOKT,'
      '    :IDED_DVPOKT,'
      '    :IDPART_DVPOKT,'
      '    :KOL_DVPOKT,'
      '    :KF_DVPOKT,'
      '    :PRICE_DVPOKT,'
      '    :SUM_DVPOKT,'
      '    :RPRICE_DVPOKT,'
      '    :RSUM_DVPOKT,'
      '    :IDBASE_DVPOKT,'
      '    :NDS_DVPOKT,'
      '    :SUMNDS_DVPOKT'
      ')')
    RefreshSQL.Strings = (
      'select DVPOKT.*, NAMENOM, NAMEED ,TNOM'
      'from '
      'DVPOKT '
      'LEFT OUTER JOIN SNOM  ON IDNOM_DVPOKT=IDNOM '
      'left outer join SED  on  IDED_DVPOKT=IDED'
      'where(  IDDOC_DVPOKT=:ID'
      '     ) and (     DVPOKT.ID_DVPOKT = :OLD_ID_DVPOKT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select DVPOKT.*, NAMENOM, NAMEED ,TNOM'
      'from '
      'DVPOKT '
      'LEFT OUTER JOIN SNOM  ON IDNOM_DVPOKT=IDNOM '
      'left outer join SED  on  IDED_DVPOKT=IDED'
      'where IDDOC_DVPOKT=:ID')
    AutoUpdateOptions.UpdateTableName = 'DVPOKT'
    AutoUpdateOptions.KeyFields = 'ID_DVPOKT'
    AutoUpdateOptions.GeneratorName = 'GEN_DVPOKT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    AfterDelete = DocTAfterDelete
    AfterInsert = DocTAfterInsert
    BeforeDelete = DocTBeforeDelete
    BeforeEdit = DocTBeforeEdit
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
    object DocTID_DVPOKT: TFIBLargeIntField
      FieldName = 'ID_DVPOKT'
    end
    object DocTGID_DVPOKT: TFIBWideStringField
      FieldName = 'GID_DVPOKT'
      Size = 10
    end
    object DocTIDDOC_DVPOKT: TFIBLargeIntField
      FieldName = 'IDDOC_DVPOKT'
    end
    object DocTIDNOM_DVPOKT: TFIBLargeIntField
      FieldName = 'IDNOM_DVPOKT'
    end
    object DocTIDED_DVPOKT: TFIBLargeIntField
      FieldName = 'IDED_DVPOKT'
    end
    object DocTIDPART_DVPOKT: TFIBLargeIntField
      FieldName = 'IDPART_DVPOKT'
    end
    object DocTKOL_DVPOKT: TFIBBCDField
      FieldName = 'KOL_DVPOKT'
      OnChange = DocTKOL_DVPOKTChange
      Size = 3
      RoundByScale = True
    end
    object DocTKF_DVPOKT: TFIBBCDField
      FieldName = 'KF_DVPOKT'
      OnChange = DocTKF_DVPOKTChange
      Size = 3
      RoundByScale = True
    end
    object DocTPRICE_DVPOKT: TFIBBCDField
      FieldName = 'PRICE_DVPOKT'
      OnChange = DocTPRICE_DVPOKTChange
      Size = 2
      RoundByScale = True
    end
    object DocTSUM_DVPOKT: TFIBBCDField
      FieldName = 'SUM_DVPOKT'
      Size = 2
      RoundByScale = True
    end
    object DocTRPRICE_DVPOKT: TFIBBCDField
      FieldName = 'RPRICE_DVPOKT'
      OnChange = DocTRPRICE_DVPOKTChange
      Size = 2
      RoundByScale = True
    end
    object DocTRSUM_DVPOKT: TFIBBCDField
      FieldName = 'RSUM_DVPOKT'
      OnChange = DocTRSUM_DVPOKTChange
      Size = 2
      RoundByScale = True
    end
    object DocTIDBASE_DVPOKT: TFIBLargeIntField
      FieldName = 'IDBASE_DVPOKT'
    end
    object DocTNDS_DVPOKT: TFIBIntegerField
      FieldName = 'NDS_DVPOKT'
    end
    object DocTSUMNDS_DVPOKT: TFIBBCDField
      FieldName = 'SUMNDS_DVPOKT'
      Size = 2
      RoundByScale = True
    end
    object DocTNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object DocTNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
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
    Left = 160
    Top = 176
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_VPOK_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 256
    Top = 320
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_VPOK_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 256
    Top = 272
    qoStartTransaction = True
  end
  object NumDoc: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      
        'from DOC_VPOK_GET_NUM_NEW_DOC (:PARAM_IDBASE,:PARAM_IDFIRM,:PARA' +
        'M_IDSKLAD)')
    Transaction = IBTr
    DefaultFormats.DateTimeDisplayFormat = 'c'
    Left = 336
    Top = 16
  end
  object DocOsn: TpFIBDataSet
    SelectSQL.Strings = (
      'select'
      '  TDOC,'
      '  POSDOC,'
      '  NUMDOC'
      'from GALLDOC'
      'where '
      '  IDDOC=:PARAM_IDDOC')
    Transaction = IBTr
    Left = 160
    Top = 248
    poUseLargeIntField = True
    object DocOsnTDOC: TFIBWideStringField
      FieldName = 'TDOC'
      OnGetText = DocOsnTDOCGetText
      Size = 10
    end
    object DocOsnPOSDOC: TFIBDateTimeField
      FieldName = 'POSDOC'
    end
    object DocOsnNUMDOC: TFIBIntegerField
      FieldName = 'NUMDOC'
    end
  end
  object DataSourceDocOsn: TDataSource
    DataSet = DocOsn
    Left = 72
    Top = 248
  end
end
