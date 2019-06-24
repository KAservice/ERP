object DMDocCheck: TDMDocCheck
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 456
  Width = 742
  object DataSourceDoc: TDataSource
    DataSet = Doc
    Left = 72
    Top = 72
  end
  object DataSourceDocT: TDataSource
    DataSet = DocT
    Left = 72
    Top = 128
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
      'select GALLDOC.*,'
      ' FNAME_USER,'
      ' NAME_SDOG , '
      ' NAMEKLIENT,'
      ' NAME_SINFBASE_OBMEN,'
      ' NAMEFIRM,'
      ' NAMESKLAD,'
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      ''
      'from '
      '  GALLDOC '
      'left outer join SUSER on IDUSERDOC=ID_USER'
      'left outer join SDOG on IDDOGDOC=ID_SDOG'
      'left outer join SKLIENT on IDKLDOC=IDKLIENT'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      'left outer join SFIRM on IDFIRM=IDFIRMDOC'
      'left outer join SSKLAD on IDSKLAD=IDSKLDOC'
      
        'left outer join SPROJECT on galldoc.idproject_galldoc=sproject.i' +
        'd_sproject'
      
        'left outer join sbusiness_oper on galldoc.idbusinop_galldoc=sbus' +
        'iness_oper.id_sbusiness_oper'
      'where(  '
      ' IDDOC=:ID'
      '     ) and (     GALLDOC.IDDOC = :OLD_IDDOC'
      '     )'
      '     ')
    SelectSQL.Strings = (
      'select GALLDOC.*,'
      ' FNAME_USER,'
      ' NAME_SDOG , '
      ' NAMEKLIENT,'
      ' NAME_SINFBASE_OBMEN,'
      ' NAMEFIRM,'
      ' NAMESKLAD,'
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      ''
      'from '
      '  GALLDOC '
      'left outer join SUSER on IDUSERDOC=ID_USER'
      'left outer join SDOG on IDDOGDOC=ID_SDOG'
      'left outer join SKLIENT on IDKLDOC=IDKLIENT'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      'left outer join SFIRM on IDFIRM=IDFIRMDOC'
      'left outer join SSKLAD on IDSKLAD=IDSKLDOC'
      
        'left outer join SPROJECT on galldoc.idproject_galldoc=sproject.i' +
        'd_sproject'
      
        'left outer join sbusiness_oper on galldoc.idbusinop_galldoc=sbus' +
        'iness_oper.id_sbusiness_oper'
      'where '
      ' IDDOC=:ID ')
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
      OnChange = DocAllSUMDOCChange
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
    object DocAllFNAME_USER: TFIBWideStringField
      FieldName = 'FNAME_USER'
      Size = 200
    end
    object DocAllNAME_SDOG: TFIBWideStringField
      FieldName = 'NAME_SDOG'
      Size = 200
    end
    object DocAllNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 200
    end
    object DocAllNAME_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      OnGetText = DocAllNAME_SINFBASE_OBMENGetText
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
    object DocAllNAME_SPROJECT: TFIBWideStringField
      FieldName = 'NAME_SPROJECT'
      Size = 200
    end
    object DocAllIDBUSINOP_GALLDOC: TFIBLargeIntField
      FieldName = 'IDBUSINOP_GALLDOC'
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
      'UPDATE DCHK'
      'SET '
      '    IDDOCCHK = :IDDOCCHK,'
      '    IDKKMCHK = :IDKKMCHK,'
      '    IDTPRICE = :IDTPRICE,'
      '    NCHECKCHK = :NCHECKCHK,'
      '    NKLCHK = :NKLCHK,'
      '    OPERCHK = :OPERCHK,'
      '    OPLNALCHK = :OPLNALCHK,'
      '    OPLPCCHK = :OPLPCCHK,'
      '    NALCHK = :NALCHK,'
      '    PRIMCHK = :PRIMCHK,'
      '    GID_DCHK = :GID_DCHK,'
      '    DVREGCHK = :DVREGCHK,'
      '    SAVNUMCHK = :SAVNUMCHK,'
      '    MODELCHK = :MODELCHK,'
      '    REGNUMCHK = :REGNUMCHK,'
      '    IDDCARDCHK = :IDDCARDCHK,'
      '    IDBASE_DCHK = :IDBASE_DCHK,'
      '    SDACHA_DCHK = :SDACHA_DCHK,'
      '    IDBSCHET_DCHK = :IDBSCHET_DCHK,'
      '    OPLPLATCARD_DCHK = :OPLPLATCARD_DCHK,'
      '    OPLCREDITCARD_DCHK = :OPLCREDITCARD_DCHK,'
      '    OPLPLATCARD_ALL_DCHK = :OPLPLATCARD_ALL_DCHK,'
      '    OPLCREDITCARD_ALL_DCHK = :OPLCREDITCARD_ALL_DCHK,'
      '    OPL_OTHER_DCHK = :OPL_OTHER_DCHK,'
      '    FISCALSIGN_DCHK = :FISCALSIGN_DCHK,'
      '    PHONE_DCHK = :PHONE_DCHK,'
      '    EMAIL_DCHK = :EMAIL_DCHK'
      'WHERE'
      '    IDCHK = :OLD_IDCHK'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DCHK'
      'WHERE'
      '        IDCHK = :OLD_IDCHK'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DCHK('
      '    IDCHK,'
      '    IDDOCCHK,'
      '    IDKKMCHK,'
      '    IDTPRICE,'
      '    NCHECKCHK,'
      '    NKLCHK,'
      '    OPERCHK,'
      '    OPLNALCHK,'
      '    OPLPCCHK,'
      '    NALCHK,'
      '    PRIMCHK,'
      '    GID_DCHK,'
      '    DVREGCHK,'
      '    SAVNUMCHK,'
      '    MODELCHK,'
      '    REGNUMCHK,'
      '    IDDCARDCHK,'
      '    IDBASE_DCHK,'
      '    SDACHA_DCHK,'
      '    IDBSCHET_DCHK,'
      '    OPLPLATCARD_DCHK,'
      '    OPLCREDITCARD_DCHK,'
      '    OPLPLATCARD_ALL_DCHK,'
      '    OPLCREDITCARD_ALL_DCHK,'
      '    OPL_OTHER_DCHK,'
      '    FISCALSIGN_DCHK,'
      '    PHONE_DCHK,'
      '    EMAIL_DCHK'
      ')'
      'VALUES('
      '    :IDCHK,'
      '    :IDDOCCHK,'
      '    :IDKKMCHK,'
      '    :IDTPRICE,'
      '    :NCHECKCHK,'
      '    :NKLCHK,'
      '    :OPERCHK,'
      '    :OPLNALCHK,'
      '    :OPLPCCHK,'
      '    :NALCHK,'
      '    :PRIMCHK,'
      '    :GID_DCHK,'
      '    :DVREGCHK,'
      '    :SAVNUMCHK,'
      '    :MODELCHK,'
      '    :REGNUMCHK,'
      '    :IDDCARDCHK,'
      '    :IDBASE_DCHK,'
      '    :SDACHA_DCHK,'
      '    :IDBSCHET_DCHK,'
      '    :OPLPLATCARD_DCHK,'
      '    :OPLCREDITCARD_DCHK,'
      '    :OPLPLATCARD_ALL_DCHK,'
      '    :OPLCREDITCARD_ALL_DCHK,'
      '    :OPL_OTHER_DCHK,'
      '    :FISCALSIGN_DCHK,'
      '    :PHONE_DCHK,'
      '    :EMAIL_DCHK'
      ')')
    RefreshSQL.Strings = (
      'select DCHK.*,'
      '  NAMEKKM,'
      '  NAME_SDISCOUNT_CARD,'
      '  NAMEBSCHET'
      'from  DCHK'
      'left outer join SKKM on IDKKM=IDKKMCHK'
      'left outer join SDISCOUNT_CARD on ID_SDISCOUNT_CARD=IDDCARDCHK'
      'left outer join SBSCHET on IDBSCHET_DCHK=IDBSCHET'
      'where(  IDDOCCHK=:ID'
      '     ) and (     DCHK.IDCHK = :OLD_IDCHK'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select DCHK.*,'
      '  NAMEKKM,'
      '  NAME_SDISCOUNT_CARD,'
      '  NAMEBSCHET'
      'from  DCHK'
      'left outer join SKKM on IDKKM=IDKKMCHK'
      'left outer join SDISCOUNT_CARD on ID_SDISCOUNT_CARD=IDDCARDCHK'
      'left outer join SBSCHET on IDBSCHET_DCHK=IDBSCHET'
      'where IDDOCCHK=:ID')
    AutoUpdateOptions.UpdateTableName = 'DCHK'
    AutoUpdateOptions.KeyFields = 'IDCHK'
    AutoUpdateOptions.GeneratorName = 'GEN_DCHK_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    BeforeEdit = DocBeforeEdit
    OnCalcFields = DocCalcFields
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 72
    poUseLargeIntField = True
    object DocIDCHK: TFIBLargeIntField
      FieldName = 'IDCHK'
    end
    object DocIDDOCCHK: TFIBLargeIntField
      FieldName = 'IDDOCCHK'
    end
    object DocIDKKMCHK: TFIBLargeIntField
      FieldName = 'IDKKMCHK'
      OnChange = DocIDKKMCHKChange
    end
    object DocIDTPRICE: TFIBLargeIntField
      FieldName = 'IDTPRICE'
    end
    object DocNCHECKCHK: TFIBIntegerField
      FieldName = 'NCHECKCHK'
    end
    object DocNKLCHK: TFIBIntegerField
      FieldName = 'NKLCHK'
    end
    object DocOPERCHK: TFIBIntegerField
      FieldName = 'OPERCHK'
      OnGetText = DocOPERCHKGetText
    end
    object DocOPLNALCHK: TFIBBCDField
      FieldName = 'OPLNALCHK'
      Size = 2
      RoundByScale = True
    end
    object DocOPLPCCHK: TFIBBCDField
      FieldName = 'OPLPCCHK'
      OnChange = DocOPLPCCHKChange
      Size = 2
      RoundByScale = True
    end
    object DocNALCHK: TFIBBCDField
      FieldName = 'NALCHK'
      OnChange = DocNALCHKChange
      Size = 2
      RoundByScale = True
    end
    object DocPRIMCHK: TFIBWideStringField
      FieldName = 'PRIMCHK'
      Size = 200
    end
    object DocGID_DCHK: TFIBWideStringField
      FieldName = 'GID_DCHK'
      Size = 10
    end
    object DocDVREGCHK: TFIBSmallIntField
      FieldName = 'DVREGCHK'
    end
    object DocSAVNUMCHK: TFIBWideStringField
      FieldName = 'SAVNUMCHK'
    end
    object DocMODELCHK: TFIBWideStringField
      FieldName = 'MODELCHK'
    end
    object DocREGNUMCHK: TFIBWideStringField
      FieldName = 'REGNUMCHK'
    end
    object DocIDDCARDCHK: TFIBLargeIntField
      FieldName = 'IDDCARDCHK'
    end
    object DocIDBASE_DCHK: TFIBLargeIntField
      FieldName = 'IDBASE_DCHK'
    end
    object DocSDACHA_DCHK: TFIBBCDField
      FieldName = 'SDACHA_DCHK'
      Size = 2
      RoundByScale = True
    end
    object DocIDBSCHET_DCHK: TFIBLargeIntField
      FieldName = 'IDBSCHET_DCHK'
    end
    object DocOPLPLATCARD_DCHK: TFIBBCDField
      FieldName = 'OPLPLATCARD_DCHK'
      OnChange = DocOPLPLATCARD_DCHKChange
      Size = 2
      RoundByScale = True
    end
    object DocOPLCREDITCARD_DCHK: TFIBBCDField
      FieldName = 'OPLCREDITCARD_DCHK'
      OnChange = DocOPLCREDITCARD_DCHKChange
      Size = 2
      RoundByScale = True
    end
    object DocOPLPLATCARD_ALL_DCHK: TFIBBCDField
      FieldName = 'OPLPLATCARD_ALL_DCHK'
      OnChange = DocOPLPLATCARD_ALL_DCHKChange
      Size = 2
      RoundByScale = True
    end
    object DocOPLCREDITCARD_ALL_DCHK: TFIBBCDField
      FieldName = 'OPLCREDITCARD_ALL_DCHK'
      OnChange = DocOPLCREDITCARD_ALL_DCHKChange
      Size = 2
      RoundByScale = True
    end
    object DocNAMEKKM: TFIBWideStringField
      FieldName = 'NAMEKKM'
      Size = 200
    end
    object DocNAME_SDISCOUNT_CARD: TFIBWideStringField
      FieldName = 'NAME_SDISCOUNT_CARD'
      Size = 200
    end
    object DocNAMEBSCHET: TFIBWideStringField
      FieldName = 'NAMEBSCHET'
      Size = 200
    end
    object DocALLOPL: TFloatField
      FieldKind = fkCalculated
      FieldName = 'ALLOPL'
      DisplayFormat = '0.00'
      Calculated = True
    end
    object DocOPL_OTHER_DCHK: TFIBBCDField
      FieldName = 'OPL_OTHER_DCHK'
      Size = 2
      RoundByScale = True
    end
    object DocFISCALSIGN_DCHK: TFIBWideStringField
      FieldName = 'FISCALSIGN_DCHK'
      Size = 10
    end
    object DocPHONE_DCHK: TFIBWideStringField
      FieldName = 'PHONE_DCHK'
      Size = 12
    end
    object DocEMAIL_DCHK: TFIBWideStringField
      FieldName = 'EMAIL_DCHK'
      Size = 30
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DCHKT'
      'SET '
      '    IDDOCCHKT = :IDDOCCHKT,'
      '    IDNOMCHKT = :IDNOMCHKT,'
      '    IDEDCHKT = :IDEDCHKT,'
      '    KOLCHKT = :KOLCHKT,'
      '    KFCHKT = :KFCHKT,'
      '    PRICECHKT = :PRICECHKT,'
      '    SUMCHKT = :SUMCHKT,'
      '    SKCHKT = :SKCHKT,'
      '    NADCHKT = :NADCHKT,'
      '    PRICEFULLCHKT = :PRICEFULLCHKT,'
      '    PRSKCHKT = :PRSKCHKT,'
      '    PRNADCHKT = :PRNADCHKT,'
      '    GID_DCHKT = :GID_DCHKT,'
      '    IDBASE_DCHKT = :IDBASE_DCHKT,'
      '    PRSK_CARD_DCHKT = :PRSK_CARD_DCHKT,'
      '    PRSK_AUTO_DCHKT = :PRSK_AUTO_DCHKT,'
      '    NDS_DCHKT = :NDS_DCHKT,'
      '    SUMNDS_DCHKT = :SUMNDS_DCHKT,'
      '    PRSK_HAND_DCHKT = :PRSK_HAND_DCHKT,'
      '    NO_SK_DCHKT = :NO_SK_DCHKT,'
      '    IDTNOM_DCHKT = :IDTNOM_DCHKT,'
      '    IDDEPARTMENT_DCHKT = :IDDEPARTMENT_DCHKT'
      'WHERE'
      '    IDCHKT = :OLD_IDCHKT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DCHKT'
      'WHERE'
      '        IDCHKT = :OLD_IDCHKT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DCHKT('
      '    IDCHKT,'
      '    IDDOCCHKT,'
      '    IDNOMCHKT,'
      '    IDEDCHKT,'
      '    KOLCHKT,'
      '    KFCHKT,'
      '    PRICECHKT,'
      '    SUMCHKT,'
      '    SKCHKT,'
      '    NADCHKT,'
      '    PRICEFULLCHKT,'
      '    PRSKCHKT,'
      '    PRNADCHKT,'
      '    GID_DCHKT,'
      '    IDBASE_DCHKT,'
      '    PRSK_CARD_DCHKT,'
      '    PRSK_AUTO_DCHKT,'
      '    NDS_DCHKT,'
      '    SUMNDS_DCHKT,'
      '    PRSK_HAND_DCHKT,'
      '    NO_SK_DCHKT,'
      '    IDTNOM_DCHKT,'
      '    IDDEPARTMENT_DCHKT'
      ')'
      'VALUES('
      '    :IDCHKT,'
      '    :IDDOCCHKT,'
      '    :IDNOMCHKT,'
      '    :IDEDCHKT,'
      '    :KOLCHKT,'
      '    :KFCHKT,'
      '    :PRICECHKT,'
      '    :SUMCHKT,'
      '    :SKCHKT,'
      '    :NADCHKT,'
      '    :PRICEFULLCHKT,'
      '    :PRSKCHKT,'
      '    :PRNADCHKT,'
      '    :GID_DCHKT,'
      '    :IDBASE_DCHKT,'
      '    :PRSK_CARD_DCHKT,'
      '    :PRSK_AUTO_DCHKT,'
      '    :NDS_DCHKT,'
      '    :SUMNDS_DCHKT,'
      '    :PRSK_HAND_DCHKT,'
      '    :NO_SK_DCHKT,'
      '    :IDTNOM_DCHKT,'
      '    :IDDEPARTMENT_DCHKT'
      ')')
    RefreshSQL.Strings = (
      'select DCHKT.*,'
      '  KRNAMENOM, NAMENOM, NAMEED ,TNOM,CODENOM,ARTNOM,'
      '  snom.idgrpnom,'
      '  snom.idvid_snom,'
      '  sed.shed,'
      '  sgrpnom.namegn,'
      '  svidnom.name_svidnom ,'
      '  sdepartment.numotdkkt_sdepartment,'
      '  sdepartment.name_sdepartment,'
      '  stnom.name_stnom'
      'from DCHKT'
      'LEFT OUTER JOIN SNOM  ON IDNOMCHKT=IDNOM '
      'left outer join SED  on  IDEDCHKT=IDED'
      'left outer join sgrpnom on snom.idgrpnom=sgrpnom.idgn'
      'left outer join svidnom on snom.idvid_snom=svidnom.id_svidnom'
      
        'left outer join sdepartment on sdepartment.id_sdepartment=dchkt.' +
        'iddepartment_dchkt'
      'left outer join stnom on stnom.id_stnom=dchkt.idtnom_dchkt'
      ''
      ''
      'where(  dchkt.iddocchkt=:ID'
      '     ) and (     DCHKT.IDCHKT = :OLD_IDCHKT'
      '     )'
      '    '
      '')
    SelectSQL.Strings = (
      'select DCHKT.*,'
      '  KRNAMENOM, NAMENOM, NAMEED ,TNOM,CODENOM,ARTNOM,'
      '  snom.idgrpnom,'
      '  snom.idvid_snom,'
      '  sed.shed,'
      '  sgrpnom.namegn,'
      '  svidnom.name_svidnom ,'
      '  sdepartment.numotdkkt_sdepartment,'
      '  sdepartment.name_sdepartment,'
      '  stnom.name_stnom'
      'from DCHKT'
      'LEFT OUTER JOIN SNOM  ON IDNOMCHKT=IDNOM '
      'left outer join SED  on  IDEDCHKT=IDED'
      'left outer join sgrpnom on snom.idgrpnom=sgrpnom.idgn'
      'left outer join svidnom on snom.idvid_snom=svidnom.id_svidnom'
      
        'left outer join sdepartment on sdepartment.id_sdepartment=dchkt.' +
        'iddepartment_dchkt'
      'left outer join stnom on stnom.id_stnom=dchkt.idtnom_dchkt'
      ''
      ''
      'where dchkt.iddocchkt=:ID'
      '')
    AutoUpdateOptions.UpdateTableName = 'DCHKT'
    AutoUpdateOptions.KeyFields = 'IDCHKT'
    AutoUpdateOptions.GeneratorName = 'GEN_DCHKT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    AfterDelete = DocTAfterDelete
    BeforeDelete = DocTBeforeDelete
    OnCalcFields = DocTCalcFields
    OnNewRecord = DocTNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 128
    poUseLargeIntField = True
    object DocTIDCHKT: TFIBLargeIntField
      FieldName = 'IDCHKT'
    end
    object DocTIDDOCCHKT: TFIBLargeIntField
      FieldName = 'IDDOCCHKT'
    end
    object DocTIDNOMCHKT: TFIBLargeIntField
      FieldName = 'IDNOMCHKT'
    end
    object DocTIDEDCHKT: TFIBLargeIntField
      FieldName = 'IDEDCHKT'
    end
    object DocTKOLCHKT: TFIBBCDField
      FieldName = 'KOLCHKT'
      OnChange = DocTKOLCHKTChange
      DisplayFormat = '#,##0.000'
      EditFormat = '0.000'
      Size = 3
      RoundByScale = True
    end
    object DocTKFCHKT: TFIBBCDField
      FieldName = 'KFCHKT'
      DisplayFormat = '#,##0.000'
      EditFormat = '0.000'
      Size = 3
      RoundByScale = True
    end
    object DocTPRICECHKT: TFIBBCDField
      FieldName = 'PRICECHKT'
      OnChange = DocTPRICECHKTChange
      DisplayFormat = '#,##0.00'
      EditFormat = '0.00'
      Size = 2
      RoundByScale = True
    end
    object DocTSUMCHKT: TFIBBCDField
      FieldName = 'SUMCHKT'
      OnChange = DocTSUMCHKTChange
      DisplayFormat = '#,##0.00'
      EditFormat = '0.00'
      Size = 2
      RoundByScale = True
    end
    object DocTSKCHKT: TFIBBCDField
      FieldName = 'SKCHKT'
      OnGetText = DocTSKCHKTGetText
      DisplayFormat = '#,##0.00'
      EditFormat = '0.00'
      Size = 2
      RoundByScale = True
    end
    object DocTNADCHKT: TFIBBCDField
      FieldName = 'NADCHKT'
      OnGetText = DocTNADCHKTGetText
      DisplayFormat = '#,##0.00'
      EditFormat = '0.00'
      Size = 2
      RoundByScale = True
    end
    object DocTPRSKCHKT: TFIBBCDField
      FieldName = 'PRSKCHKT'
      OnChange = DocTPRSKCHKTChange
      DisplayFormat = '#,##0.00'
      EditFormat = '0.00'
      Size = 2
      RoundByScale = True
    end
    object DocTPRNADCHKT: TFIBBCDField
      FieldName = 'PRNADCHKT'
      OnChange = DocTPRNADCHKTChange
      DisplayFormat = '#,##0.00'
      EditFormat = '0.00'
      Size = 2
      RoundByScale = True
    end
    object DocTGID_DCHKT: TFIBWideStringField
      FieldName = 'GID_DCHKT'
      Size = 10
    end
    object DocTIDBASE_DCHKT: TFIBLargeIntField
      FieldName = 'IDBASE_DCHKT'
    end
    object DocTPRSK_CARD_DCHKT: TFIBBCDField
      FieldName = 'PRSK_CARD_DCHKT'
      DisplayFormat = '#,##0.00'
      EditFormat = '0.00'
      Size = 2
      RoundByScale = True
    end
    object DocTPRSK_AUTO_DCHKT: TFIBBCDField
      FieldName = 'PRSK_AUTO_DCHKT'
      DisplayFormat = '#,##0.00'
      EditFormat = '0.00'
      Size = 2
      RoundByScale = True
    end
    object DocTNDS_DCHKT: TFIBIntegerField
      FieldName = 'NDS_DCHKT'
    end
    object DocTSUMNDS_DCHKT: TFIBBCDField
      FieldName = 'SUMNDS_DCHKT'
      DisplayFormat = '#,##0.00'
      EditFormat = '0.00'
      Size = 2
      RoundByScale = True
    end
    object DocTKRNAMENOM: TFIBWideStringField
      FieldName = 'KRNAMENOM'
      Size = 40
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
    object DocTRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object DocTCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object DocTARTNOM: TFIBWideStringField
      FieldName = 'ARTNOM'
      Size = 40
    end
    object DocTSHED: TFIBWideStringField
      FieldName = 'SHED'
      Size = 13
    end
    object DocTPRSK_HAND_DCHKT: TFIBBCDField
      FieldName = 'PRSK_HAND_DCHKT'
      Size = 2
      RoundByScale = True
    end
    object DocTNO_SK_DCHKT: TFIBSmallIntField
      FieldName = 'NO_SK_DCHKT'
    end
    object DocTIDGRPNOM: TFIBLargeIntField
      FieldName = 'IDGRPNOM'
    end
    object DocTIDVID_SNOM: TFIBLargeIntField
      FieldName = 'IDVID_SNOM'
    end
    object DocTNAMEGN: TFIBWideStringField
      FieldName = 'NAMEGN'
      Size = 200
    end
    object DocTNAME_SVIDNOM: TFIBWideStringField
      FieldName = 'NAME_SVIDNOM'
      Size = 200
    end
    object DocTIDTNOM_DCHKT: TFIBLargeIntField
      FieldName = 'IDTNOM_DCHKT'
    end
    object DocTIDDEPARTMENT_DCHKT: TFIBLargeIntField
      FieldName = 'IDDEPARTMENT_DCHKT'
    end
    object DocTNUMOTDKKT_SDEPARTMENT: TFIBIntegerField
      FieldName = 'NUMOTDKKT_SDEPARTMENT'
    end
    object DocTNAME_SDEPARTMENT: TFIBWideStringField
      FieldName = 'NAME_SDEPARTMENT'
      Size = 200
    end
    object DocTNAME_STNOM: TFIBWideStringField
      FieldName = 'NAME_STNOM'
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
  object IBTrDvReg: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 432
    Top = 192
  end
  object NumDoc: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      
        'from DOC_CHK_GET_NUM_NEW_DOC (:PARAM_IDBASE,:PARAM_IDFIRM,:PARAM' +
        '_IDSKLAD,:PARAM_IDKASSA)')
    Transaction = IBTr
    Left = 368
    Top = 16
  end
  object SpisokTypePrice: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from STPRICE')
    Transaction = IBTr
    Left = 368
    Top = 72
    object SpisokTypePriceID_TPRICE: TFIBIntegerField
      FieldName = 'ID_TPRICE'
    end
    object SpisokTypePriceNAME_TPRICE: TFIBWideStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
    end
    object SpisokTypePriceGID_STPRICE: TFIBWideStringField
      FieldName = 'GID_STPRICE'
      Size = 10
    end
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_CHK_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 360
    Top = 224
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_CHK_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 360
    Top = 168
    qoStartTransaction = True
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
    Top = 192
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
    Top = 192
  end
  object DocOpl: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DCHK_OPL'
      'SET '
      '    IDBASE_DCHK_OPL = :IDBASE_DCHK_OPL,'
      '    IDCARD_DCHK_OPL = :IDCARD_DCHK_OPL,'
      '    SUMPLAT_DCHK_OPL = :SUMPLAT_DCHK_OPL,'
      '    SUMCREDIT_DCHK_OPL = :SUMCREDIT_DCHK_OPL,'
      '    IDDOC_DCHK_OPL = :IDDOC_DCHK_OPL'
      'WHERE'
      '    ID_DCHK_OPL = :OLD_ID_DCHK_OPL'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DCHK_OPL'
      'WHERE'
      '        ID_DCHK_OPL = :OLD_ID_DCHK_OPL'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DCHK_OPL('
      '    ID_DCHK_OPL,'
      '    IDBASE_DCHK_OPL,'
      '    IDCARD_DCHK_OPL,'
      '    SUMPLAT_DCHK_OPL,'
      '    SUMCREDIT_DCHK_OPL,'
      '    IDDOC_DCHK_OPL'
      ')'
      'VALUES('
      '    :ID_DCHK_OPL,'
      '    :IDBASE_DCHK_OPL,'
      '    :IDCARD_DCHK_OPL,'
      '    :SUMPLAT_DCHK_OPL,'
      '    :SUMCREDIT_DCHK_OPL,'
      '    :IDDOC_DCHK_OPL'
      ')')
    RefreshSQL.Strings = (
      'select dchk_opl.*,'
      '  sdiscount_card.name_sdiscount_card'
      'from  dchk_opl'
      
        'left outer join SDISCOUNT_CARD on sdiscount_card.id_sdiscount_ca' +
        'rd=dchk_opl.idcard_dchk_opl'
      'where(  dchk_opl.iddoc_dchk_opl=:IDDOC'
      '     ) and (     DCHK_OPL.ID_DCHK_OPL = :OLD_ID_DCHK_OPL'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select dchk_opl.*,'
      '  sdiscount_card.name_sdiscount_card'
      'from  dchk_opl'
      
        'left outer join SDISCOUNT_CARD on sdiscount_card.id_sdiscount_ca' +
        'rd=dchk_opl.idcard_dchk_opl'
      'where dchk_opl.iddoc_dchk_opl=:IDDOC')
    AutoUpdateOptions.UpdateTableName = 'DCHK_OPL'
    AutoUpdateOptions.KeyFields = 'ID_DCHK_OPL'
    AutoUpdateOptions.GeneratorName = 'GEN_DCHK_OPL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    AfterDelete = DocOplAfterDelete
    BeforeDelete = DocOplBeforeDelete
    BeforeEdit = DocOplBeforeEdit
    OnCalcFields = DocOplCalcFields
    OnNewRecord = DocOplNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 248
    poUseLargeIntField = True
    object DocOplRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object DocOplID_DCHK_OPL: TFIBLargeIntField
      FieldName = 'ID_DCHK_OPL'
    end
    object DocOplIDBASE_DCHK_OPL: TFIBLargeIntField
      FieldName = 'IDBASE_DCHK_OPL'
    end
    object DocOplIDCARD_DCHK_OPL: TFIBLargeIntField
      FieldName = 'IDCARD_DCHK_OPL'
    end
    object DocOplSUMPLAT_DCHK_OPL: TFIBBCDField
      FieldName = 'SUMPLAT_DCHK_OPL'
      OnChange = DocOplSUMPLAT_DCHK_OPLChange
      Size = 2
      RoundByScale = True
    end
    object DocOplSUMCREDIT_DCHK_OPL: TFIBBCDField
      FieldName = 'SUMCREDIT_DCHK_OPL'
      OnChange = DocOplSUMCREDIT_DCHK_OPLChange
      Size = 2
      RoundByScale = True
    end
    object DocOplIDDOC_DCHK_OPL: TFIBLargeIntField
      FieldName = 'IDDOC_DCHK_OPL'
    end
    object DocOplNAME_SDISCOUNT_CARD: TFIBWideStringField
      FieldName = 'NAME_SDISCOUNT_CARD'
      Size = 100
    end
  end
  object DataSourceDocOpl: TDataSource
    DataSet = DocOpl
    Left = 72
    Top = 248
  end
end
