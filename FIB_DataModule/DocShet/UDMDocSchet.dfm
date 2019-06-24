object DMDocSchet: TDMDocSchet
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 412
  Width = 705
  object DataSourceDocAll: TDataSource
    DataSet = DocAll
    Left = 72
    Top = 16
  end
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
      
        'select GALLDOC. *, FNAME_USER , NAME_SINFBASE_OBMEN, NAMEFIRM, N' +
        'AMESKLAD, NAMEKLIENT, '
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from GALLDOC'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      'left outer join SFIRM on IDFIRM=IDFIRMDOC'
      'left outer join SSKLAD on IDSKLDOC=IDSKLAD'
      'left outer join SKLIENT on IDKLDOC=IDKLIENT'
      
        'left outer join SPROJECT on galldoc.idproject_galldoc=sproject.i' +
        'd_sproject'
      
        'left outer join sbusiness_oper on galldoc.idbusinop_galldoc=sbus' +
        'iness_oper.id_sbusiness_oper'
      'where(  IDDOC=:ID'
      '     ) and (     GALLDOC.IDDOC = :OLD_IDDOC'
      '     )'
      '     ')
    SelectSQL.Strings = (
      
        'select GALLDOC. *, FNAME_USER , NAME_SINFBASE_OBMEN, NAMEFIRM, N' +
        'AMESKLAD, NAMEKLIENT, '
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from GALLDOC'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      'left outer join SFIRM on IDFIRM=IDFIRMDOC'
      'left outer join SSKLAD on IDSKLDOC=IDSKLAD'
      'left outer join SKLIENT on IDKLDOC=IDKLIENT'
      
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
    Left = 176
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
      'UPDATE DSCH'
      'SET '
      '    IDDOCSCH = :IDDOCSCH,'
      '    PRIMSCH = :PRIMSCH,'
      '    GID_DSCH = :GID_DSCH,'
      '    IDBSCHET_DSCH = :IDBSCHET_DSCH,'
      '    IDTPRICESCH = :IDTPRICESCH,'
      '    IDBASE_DSCH = :IDBASE_DSCH'
      'WHERE'
      '    IDSCH = :OLD_IDSCH'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DSCH'
      'WHERE'
      '        IDSCH = :OLD_IDSCH'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DSCH('
      '    IDSCH,'
      '    IDDOCSCH,'
      '    PRIMSCH,'
      '    GID_DSCH,'
      '    IDBSCHET_DSCH,'
      '    IDTPRICESCH,'
      '    IDBASE_DSCH'
      ')'
      'VALUES('
      '    :IDSCH,'
      '    :IDDOCSCH,'
      '    :PRIMSCH,'
      '    :GID_DSCH,'
      '    :IDBSCHET_DSCH,'
      '    :IDTPRICESCH,'
      '    :IDBASE_DSCH'
      ')')
    RefreshSQL.Strings = (
      'select DSCH .* ,  NAME_TPRICE,  NAMEBSCHET'
      'from DSCH '
      'left outer join STPRICE on ID_TPRICE=IDTPRICESCH'
      'left outer join SBSCHET on IDBSCHET=IDBSCHET_DSCH'
      'where(  IDDOCSCH=:ID'
      '     ) and (     DSCH.IDSCH = :OLD_IDSCH'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select DSCH .* ,  NAME_TPRICE,  NAMEBSCHET'
      'from DSCH '
      'left outer join STPRICE on ID_TPRICE=IDTPRICESCH'
      'left outer join SBSCHET on IDBSCHET=IDBSCHET_DSCH'
      'where IDDOCSCH=:ID')
    AutoUpdateOptions.UpdateTableName = 'DSCH'
    AutoUpdateOptions.KeyFields = 'IDSCH'
    AutoUpdateOptions.GeneratorName = 'GEN_DSCH_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 176
    Top = 64
    object DocIDSCH: TFIBBCDField
      FieldName = 'IDSCH'
      Size = 0
      RoundByScale = True
    end
    object DocIDDOCSCH: TFIBBCDField
      FieldName = 'IDDOCSCH'
      Size = 0
      RoundByScale = True
    end
    object DocIDBSCHET_DSCH: TFIBBCDField
      FieldName = 'IDBSCHET_DSCH'
      Size = 0
      RoundByScale = True
    end
    object DocIDTPRICESCH: TFIBBCDField
      FieldName = 'IDTPRICESCH'
      Size = 0
      RoundByScale = True
    end
    object DocIDBASE_DSCH: TFIBBCDField
      FieldName = 'IDBASE_DSCH'
      Size = 0
      RoundByScale = True
    end
    object DocPRIMSCH: TFIBWideStringField
      FieldName = 'PRIMSCH'
      Size = 100
    end
    object DocGID_DSCH: TFIBWideStringField
      FieldName = 'GID_DSCH'
      Size = 10
    end
    object DocNAME_TPRICE: TFIBWideStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
    end
    object DocNAMEBSCHET: TFIBWideStringField
      FieldName = 'NAMEBSCHET'
      Size = 100
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DSCHT'
      'SET '
      '    IDDOCSCHT = :IDDOCSCHT,'
      '    IDNOMSCHT = :IDNOMSCHT,'
      '    IDEDSCHT = :IDEDSCHT,'
      '    KOLSCHT = :KOLSCHT,'
      '    KFSCHT = :KFSCHT,'
      '    PRICESCHT = :PRICESCHT,'
      '    SUMSCHT = :SUMSCHT,'
      '    GID_DSCHT = :GID_DSCHT,'
      '    IDBASE_DSCHT = :IDBASE_DSCHT,'
      '    NDS_DSCHT = :NDS_DSCHT,'
      '    SUMNDS_DSCHT = :SUMNDS_DSCHT'
      'WHERE'
      '    IDSCHT = :OLD_IDSCHT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DSCHT'
      'WHERE'
      '        IDSCHT = :OLD_IDSCHT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DSCHT('
      '    IDSCHT,'
      '    IDDOCSCHT,'
      '    IDNOMSCHT,'
      '    IDEDSCHT,'
      '    KOLSCHT,'
      '    KFSCHT,'
      '    PRICESCHT,'
      '    SUMSCHT,'
      '    GID_DSCHT,'
      '    IDBASE_DSCHT,'
      '    NDS_DSCHT,'
      '    SUMNDS_DSCHT'
      ')'
      'VALUES('
      '    :IDSCHT,'
      '    :IDDOCSCHT,'
      '    :IDNOMSCHT,'
      '    :IDEDSCHT,'
      '    :KOLSCHT,'
      '    :KFSCHT,'
      '    :PRICESCHT,'
      '    :SUMSCHT,'
      '    :GID_DSCHT,'
      '    :IDBASE_DSCHT,'
      '    :NDS_DSCHT,'
      '    :SUMNDS_DSCHT'
      ')')
    RefreshSQL.Strings = (
      'select DSCHT.*, NAMENOM, NAMEED ,TNOM'
      'from '
      'DSCHT LEFT OUTER JOIN SNOM  ON IDNOMSCHT=IDNOM '
      'left outer join SED  on  IDEDSCHT=IDED'
      'where(  IDDOCSCHT=:ID'
      '     ) and (     DSCHT.IDSCHT = :OLD_IDSCHT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select DSCHT.*,'
      ' NAMENOM,'
      ' NAMEED ,'
      ' TNOM,'
      ' snom.artnom,'
      ' snom.codenom,'
      ' sed.shed'
      'from '
      'DSCHT LEFT OUTER JOIN SNOM  ON IDNOMSCHT=IDNOM '
      'left outer join SED  on  IDEDSCHT=IDED'
      'where IDDOCSCHT=:ID')
    AutoUpdateOptions.UpdateTableName = 'DSCHT'
    AutoUpdateOptions.KeyFields = 'IDSCHT'
    AutoUpdateOptions.GeneratorName = 'GEN_DSCHT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    AfterDelete = DocTAfterDelete
    BeforeDelete = DocTBeforeDelete
    OnCalcFields = DocTCalcFields
    OnNewRecord = DocTNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 176
    Top = 112
    object DocTKOLSCHT: TFIBBCDField
      FieldName = 'KOLSCHT'
      OnChange = DocTKOLSCHTChange
      Size = 3
      RoundByScale = True
    end
    object DocTKFSCHT: TFIBBCDField
      FieldName = 'KFSCHT'
      OnChange = DocTKFSCHTChange
      Size = 3
      RoundByScale = True
    end
    object DocTPRICESCHT: TFIBBCDField
      FieldName = 'PRICESCHT'
      OnChange = DocTPRICESCHTChange
      Size = 2
      RoundByScale = True
    end
    object DocTSUMSCHT: TFIBBCDField
      FieldName = 'SUMSCHT'
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
    object DocTIDSCHT: TFIBBCDField
      FieldName = 'IDSCHT'
      Size = 0
      RoundByScale = True
    end
    object DocTIDDOCSCHT: TFIBBCDField
      FieldName = 'IDDOCSCHT'
      Size = 0
      RoundByScale = True
    end
    object DocTIDNOMSCHT: TFIBBCDField
      FieldName = 'IDNOMSCHT'
      Size = 0
      RoundByScale = True
    end
    object DocTIDEDSCHT: TFIBBCDField
      FieldName = 'IDEDSCHT'
      Size = 0
      RoundByScale = True
    end
    object DocTIDBASE_DSCHT: TFIBBCDField
      FieldName = 'IDBASE_DSCHT'
      Size = 0
      RoundByScale = True
    end
    object DocTNDS_DSCHT: TFIBIntegerField
      FieldName = 'NDS_DSCHT'
    end
    object DocTSUMNDS_DSCHT: TFIBBCDField
      FieldName = 'SUMNDS_DSCHT'
      Size = 2
      RoundByScale = True
    end
    object DocTGID_DSCHT: TFIBWideStringField
      FieldName = 'GID_DSCHT'
      Size = 10
    end
    object DocTNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object DocTNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 200
    end
    object DocTSUMSK_DSCHT: TFIBBCDField
      FieldName = 'SUMSK_DSCHT'
      Size = 2
      RoundByScale = True
    end
    object DocTPRSK_DSCHT: TFIBBCDField
      FieldName = 'PRSK_DSCHT'
      Size = 2
      RoundByScale = True
    end
    object DocTNO_SK_DSCHT: TFIBSmallIntField
      FieldName = 'NO_SK_DSCHT'
    end
    object DocTPRSK_CARD_DSCHT: TFIBBCDField
      FieldName = 'PRSK_CARD_DSCHT'
      Size = 2
      RoundByScale = True
    end
    object DocTPRSK_AUTO_DSCHT: TFIBBCDField
      FieldName = 'PRSK_AUTO_DSCHT'
      Size = 2
      RoundByScale = True
    end
    object DocTPRSK_HAND_DSCHT: TFIBBCDField
      FieldName = 'PRSK_HAND_DSCHT'
      Size = 2
      RoundByScale = True
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
    Left = 144
    Top = 184
  end
  object NumDoc: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      
        'from DOC_SCH_GET_NUM_NEW_DOC (:PARAM_IDBASE,:PARAM_IDFIRM,:PARAM' +
        '_IDSKLAD)')
    Transaction = IBTr
    Left = 336
    Top = 16
  end
  object IBQ: TpFIBDataSet
    Transaction = IBTr
    Left = 256
    Top = 160
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_SCH_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 256
    Top = 320
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_SCH_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 256
    Top = 272
    qoStartTransaction = True
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 320
    Top = 160
    qoStartTransaction = True
  end
end
