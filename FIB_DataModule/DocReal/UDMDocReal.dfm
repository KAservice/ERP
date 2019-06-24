object DMDocReal: TDMDocReal
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 408
  Width = 629
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
  object IBTr: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 216
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
    Left = 216
    Top = 72
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
        'EKLIENT, FNAME_USER,'
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
        'EKLIENT, FNAME_USER,'
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
    Left = 152
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
      OnChange = DocAllIDSKLDOCChange
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
      'UPDATE DREA'
      'SET '
      '    IDDOCREA = :IDDOCREA,'
      '    PRIMREA = :PRIMREA,'
      '    GID_DREA = :GID_DREA,'
      '    IDTPRICEREA = :IDTPRICEREA,'
      '    IDGRPOLREA = :IDGRPOLREA,'
      '    IDBSCHETREA = :IDBSCHETREA,'
      '    IDBASE_DREA = :IDBASE_DREA,'
      '    IDRSCHETKLIENT_DREA = :IDRSCHETKLIENT_DREA,'
      '    IDRSCHETGRPOL_DREA = :IDRSCHETGRPOL_DREA'
      'WHERE'
      '    IDREA = :OLD_IDREA'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DREA'
      'WHERE'
      '        IDREA = :OLD_IDREA'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DREA('
      '    IDREA,'
      '    IDDOCREA,'
      '    PRIMREA,'
      '    GID_DREA,'
      '    IDTPRICEREA,'
      '    IDGRPOLREA,'
      '    IDBSCHETREA,'
      '    IDBASE_DREA,'
      '    IDRSCHETKLIENT_DREA,'
      '    IDRSCHETGRPOL_DREA'
      ')'
      'VALUES('
      '    :IDREA,'
      '    :IDDOCREA,'
      '    :PRIMREA,'
      '    :GID_DREA,'
      '    :IDTPRICEREA,'
      '    :IDGRPOLREA,'
      '    :IDBSCHETREA,'
      '    :IDBASE_DREA,'
      '    :IDRSCHETKLIENT_DREA,'
      '    :IDRSCHETGRPOL_DREA'
      ')')
    RefreshSQL.Strings = (
      'select DREA.* , NAME_TPRICE, NAMEKLIENT, NAMEBSCHET,'
      '    srschet_klient.namerschet as name_rschet_klient,'
      '    srschet_grpol.namerschet as name_rschet_grpol'
      'from  DREA'
      'left outer join STPRICE  on IDTPRICEREA=ID_TPRICE'
      'left outer join SKLIENT on IDGRPOLREA=IDKLIENT'
      'left outer join SBSCHET on IDBSCHET=IDBSCHETREA'
      
        'left outer join srschet as srschet_klient on drea.idrschetklient' +
        '_drea=srschet_klient.idrschet'
      
        'left outer join srschet as srschet_grpol on drea.idrschetklient_' +
        'drea=srschet_grpol.idrschet'
      'where(  IDDOCREA=:ID'
      '     ) and (     DREA.IDREA = :OLD_IDREA'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select DREA.* , NAME_TPRICE, NAMEKLIENT, NAMEBSCHET,'
      '    srschet_klient.namerschet as name_rschet_klient,'
      '    srschet_grpol.namerschet as name_rschet_grpol'
      'from  DREA'
      'left outer join STPRICE  on IDTPRICEREA=ID_TPRICE'
      'left outer join SKLIENT on IDGRPOLREA=IDKLIENT'
      'left outer join SBSCHET on IDBSCHET=IDBSCHETREA'
      
        'left outer join srschet as srschet_klient on drea.idrschetklient' +
        '_drea=srschet_klient.idrschet'
      
        'left outer join srschet as srschet_grpol on drea.idrschetklient_' +
        'drea=srschet_grpol.idrschet'
      'where IDDOCREA=:ID')
    AutoUpdateOptions.UpdateTableName = 'DREA'
    AutoUpdateOptions.KeyFields = 'IDREA'
    AutoUpdateOptions.GeneratorName = 'GEN_DREA_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 72
    poUseLargeIntField = True
    object DocIDREA: TFIBLargeIntField
      FieldName = 'IDREA'
    end
    object DocIDDOCREA: TFIBLargeIntField
      FieldName = 'IDDOCREA'
    end
    object DocPRIMREA: TFIBWideStringField
      FieldName = 'PRIMREA'
      Size = 100
    end
    object DocGID_DREA: TFIBWideStringField
      FieldName = 'GID_DREA'
      Size = 10
    end
    object DocIDTPRICEREA: TFIBLargeIntField
      FieldName = 'IDTPRICEREA'
    end
    object DocIDGRPOLREA: TFIBLargeIntField
      FieldName = 'IDGRPOLREA'
    end
    object DocIDBSCHETREA: TFIBLargeIntField
      FieldName = 'IDBSCHETREA'
    end
    object DocIDBASE_DREA: TFIBLargeIntField
      FieldName = 'IDBASE_DREA'
    end
    object DocNAME_TPRICE: TFIBWideStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
    end
    object DocNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 200
    end
    object DocNAMEBSCHET: TFIBWideStringField
      FieldName = 'NAMEBSCHET'
      Size = 200
    end
    object DocIDRSCHETKLIENT_DREA: TFIBLargeIntField
      FieldName = 'IDRSCHETKLIENT_DREA'
    end
    object DocIDRSCHETGRPOL_DREA: TFIBLargeIntField
      FieldName = 'IDRSCHETGRPOL_DREA'
    end
    object DocNAME_RSCHET_KLIENT: TFIBWideStringField
      FieldName = 'NAME_RSCHET_KLIENT'
      Size = 200
    end
    object DocNAME_RSCHET_GRPOL: TFIBWideStringField
      FieldName = 'NAME_RSCHET_GRPOL'
      Size = 200
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DREAT'
      'SET '
      '    IDDOCREAT = :IDDOCREAT,'
      '    IDNOMREAT = :IDNOMREAT,'
      '    IDEDREAT = :IDEDREAT,'
      '    KOLREAT = :KOLREAT,'
      '    KFREAT = :KFREAT,'
      '    PRICEREAT = :PRICEREAT,'
      '    SUMREAT = :SUMREAT,'
      '    GID_DREAT = :GID_DREAT,'
      '    IDBASE_DREAT = :IDBASE_DREAT,'
      '    NDS_DREAT = :NDS_DREAT,'
      '    SUMNDS_DREAT = :SUMNDS_DREAT'
      'WHERE'
      '    IDREAT = :OLD_IDREAT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DREAT'
      'WHERE'
      '        IDREAT = :OLD_IDREAT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DREAT('
      '    IDREAT,'
      '    IDDOCREAT,'
      '    IDNOMREAT,'
      '    IDEDREAT,'
      '    KOLREAT,'
      '    KFREAT,'
      '    PRICEREAT,'
      '    SUMREAT,'
      '    GID_DREAT,'
      '    IDBASE_DREAT,'
      '    NDS_DREAT,'
      '    SUMNDS_DREAT'
      ')'
      'VALUES('
      '    :IDREAT,'
      '    :IDDOCREAT,'
      '    :IDNOMREAT,'
      '    :IDEDREAT,'
      '    :KOLREAT,'
      '    :KFREAT,'
      '    :PRICEREAT,'
      '    :SUMREAT,'
      '    :GID_DREAT,'
      '    :IDBASE_DREAT,'
      '    :NDS_DREAT,'
      '    :SUMNDS_DREAT'
      ')')
    RefreshSQL.Strings = (
      'select DREAT.*, NAMENOM, NAMEED ,TNOM'
      'from '
      'DREAT LEFT OUTER JOIN SNOM  ON IDNOMREAT=IDNOM '
      'left outer join SED  on  IDEDREAT=IDED'
      'where(  IDDOCREAT=:ID'
      '     ) and (     DREAT.IDREAT = :OLD_IDREAT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select DREAT.*,'
      '        NAMENOM,'
      '        NAMEED,'
      '        TNOM,'
      '        snom.artnom,'
      '        snom.codenom,'
      '        sed.shed'
      'from '
      'DREAT LEFT OUTER JOIN SNOM  ON IDNOMREAT=IDNOM '
      'left outer join SED  on  IDEDREAT=IDED'
      'where IDDOCREAT=:ID')
    AutoUpdateOptions.UpdateTableName = 'DREAT'
    AutoUpdateOptions.KeyFields = 'IDREAT'
    AutoUpdateOptions.GeneratorName = 'GEN_DREAT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    AfterDelete = DocTAfterDelete
    BeforeDelete = DocTBeforeDelete
    OnCalcFields = DocTCalcFields
    OnNewRecord = DocTNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 128
    poUseLargeIntField = True
    object DocTKOLREAT: TFIBBCDField
      FieldName = 'KOLREAT'
      OnChange = DocTKOLREATChange
      Size = 3
      RoundByScale = True
    end
    object DocTKFREAT: TFIBBCDField
      FieldName = 'KFREAT'
      Size = 3
      RoundByScale = True
    end
    object DocTPRICEREAT: TFIBBCDField
      FieldName = 'PRICEREAT'
      OnChange = DocTPRICEREATChange
      Size = 2
      RoundByScale = True
    end
    object DocTSUMREAT: TFIBBCDField
      FieldName = 'SUMREAT'
      Size = 2
      RoundByScale = True
    end
    object DocTRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object DocTIDREAT: TFIBLargeIntField
      FieldName = 'IDREAT'
    end
    object DocTIDDOCREAT: TFIBLargeIntField
      FieldName = 'IDDOCREAT'
    end
    object DocTIDNOMREAT: TFIBLargeIntField
      FieldName = 'IDNOMREAT'
    end
    object DocTIDEDREAT: TFIBLargeIntField
      FieldName = 'IDEDREAT'
    end
    object DocTGID_DREAT: TFIBWideStringField
      FieldName = 'GID_DREAT'
      Size = 10
    end
    object DocTIDBASE_DREAT: TFIBLargeIntField
      FieldName = 'IDBASE_DREAT'
    end
    object DocTNDS_DREAT: TFIBIntegerField
      FieldName = 'NDS_DREAT'
    end
    object DocTSUMNDS_DREAT: TFIBBCDField
      FieldName = 'SUMNDS_DREAT'
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
    object DocTTNOM: TFIBSmallIntField
      FieldName = 'TNOM'
    end
    object DocTSUMSK_DREAT: TFIBBCDField
      FieldName = 'SUMSK_DREAT'
      Size = 2
      RoundByScale = True
    end
    object DocTPRSK_CARD_DREAT: TFIBBCDField
      FieldName = 'PRSK_CARD_DREAT'
      Size = 2
      RoundByScale = True
    end
    object DocTPRSK_AUTO_DREAT: TFIBBCDField
      FieldName = 'PRSK_AUTO_DREAT'
      Size = 2
      RoundByScale = True
    end
    object DocTPRSK_HAND_DREAT: TFIBBCDField
      FieldName = 'PRSK_HAND_DREAT'
      Size = 2
      RoundByScale = True
    end
    object DocTPRSK_DREAT: TFIBBCDField
      FieldName = 'PRSK_DREAT'
      Size = 2
      RoundByScale = True
    end
    object DocTNO_SK_DREAT: TFIBBCDField
      FieldName = 'NO_SK_DREAT'
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
  object IBTrDvReg: TpFIBTransaction
    TimeoutAction = TARollback
    Left = 360
    Top = 192
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 144
    Top = 200
    qoStartTransaction = True
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_REA_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 192
    Top = 320
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_REA_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 192
    Top = 272
    qoStartTransaction = True
  end
  object NumDoc: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      
        'from DOC_REA_GET_NUM_NEW_DOC (:PARAM_IDBASE,:PARAM_IDFIRM,:PARAM' +
        '_IDSKLAD)'
      '')
    Transaction = IBTr
    DefaultFormats.DateTimeDisplayFormat = 'c'
    Left = 296
    Top = 16
  end
end
