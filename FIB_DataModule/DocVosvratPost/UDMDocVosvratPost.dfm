object DMDocVosvratPost: TDMDocVosvratPost
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 412
  Width = 485
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
      'select galldoc. *,'
      '  FNAME_USER ,'
      '  NAME_SINFBASE_OBMEN,'
      '  NAMEFIRM,'
      '  NAMESKLAD,'
      '  NAMEKLIENT, '
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from GALLDOC '
      'left outer join SFIRM on IDFIRM=galldoc.IDFIRMDOC'
      'left outer join SSKLAD on IDSKLAD=galldoc.IDSKLDOC'
      'left outer join SKLIENT on IDKLIENT=galldoc.IDKLDOC'
      'left outer join SUSER on galldoc.IDUSERDOC=ID_USER'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=galldoc.IDBA' +
        'SE_GALLDOC'
      
        'left outer join SPROJECT on galldoc.idproject_galldoc=sproject.i' +
        'd_sproject'
      
        'left outer join sbusiness_oper on galldoc.idbusinop_galldoc=sbus' +
        'iness_oper.id_sbusiness_oper'
      'where(  galldoc.IDDOC=:ID'
      '     ) and (     GALLDOC.IDDOC = :OLD_IDDOC'
      '     )'
      '     ')
    SelectSQL.Strings = (
      'select GURNAL. *,'
      '  FNAME_USER ,'
      '  NAME_SINFBASE_OBMEN,'
      '  NAMEFIRM,'
      '  NAMESKLAD,'
      '  NAMEKLIENT,'
      '  GUR_OSN.TDOC as TDOC_OSN,'
      '  GUR_OSN.NUMDOC as NUMDOC_OSN,'
      '  GUR_OSN.POSDOC as POSDOC_OSN, '
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from GALLDOC as GURNAL'
      'left outer join SFIRM on IDFIRM=GURNAL.IDFIRMDOC'
      'left outer join SSKLAD on IDSKLAD=GURNAL.IDSKLDOC'
      'left outer join SKLIENT on IDKLIENT=GURNAL.IDKLDOC'
      'left outer join SUSER on GURNAL.IDUSERDOC=ID_USER'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=GURNAL.IDBAS' +
        'E_GALLDOC'
      
        'left outer join GALLDOC as GUR_OSN on GUR_OSN.IDDOC=GURNAL.IDDOC' +
        'OSNDOC'
      
        'left outer join SPROJECT on GURNAL.idproject_galldoc=sproject.id' +
        '_sproject'
      
        'left outer join sbusiness_oper on GURNAL.idbusinop_galldoc=sbusi' +
        'ness_oper.id_sbusiness_oper'
      'where GURNAL.IDDOC=:ID ')
    AutoUpdateOptions.UpdateTableName = 'GALLDOC'
    AutoUpdateOptions.KeyFields = 'IDDOC'
    AutoUpdateOptions.GeneratorName = 'GEN_GALLDOC_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 16
    poUseLargeIntField = True
    object DocAllIDDOC: TFIBLargeIntField
      FieldName = 'IDDOC'
    end
    object DocAllPOSDOC: TFIBDateTimeField
      FieldName = 'POSDOC'
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
    object DocAllTDOC_OSN: TFIBWideStringField
      FieldName = 'TDOC_OSN'
      Size = 10
    end
    object DocAllNUMDOC_OSN: TFIBIntegerField
      FieldName = 'NUMDOC_OSN'
    end
    object DocAllPOSDOC_OSN: TFIBDateTimeField
      FieldName = 'POSDOC_OSN'
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
      'UPDATE DVPO'
      'SET '
      '    IDDOCVPO = :IDDOCVPO,'
      '    PRIMVPO = :PRIMVPO,'
      '    GID_DVPO = :GID_DVPO,'
      '    IDTPRICE_DVPO = :IDTPRICE_DVPO,'
      '    IDBASE_DVPO = :IDBASE_DVPO,'
      '    IDRTPRICE_DVPO = :IDRTPRICE_DVPO,'
      '    OPER_DVPO = :OPER_DVPO,'
      '    NUMDOCPOST_DVPO = :NUMDOCPOST_DVPO,'
      '    POSDOCPOST_DVPO = :POSDOCPOST_DVPO,'
      '    IDGRPOL_DVPO = :IDGRPOL_DVPO,'
      '    IDBSCHET_DVPO = :IDBSCHET_DVPO,'
      '    IDRSCHETKLIENT_DVPO = :IDRSCHETKLIENT_DVPO,'
      '    IDRSCHETGRPOL_DVPO = :IDRSCHETGRPOL_DVPO'
      'WHERE'
      '    IDVPO = :OLD_IDVPO'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DVPO'
      'WHERE'
      '        IDVPO = :OLD_IDVPO'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DVPO('
      '    IDVPO,'
      '    IDDOCVPO,'
      '    PRIMVPO,'
      '    GID_DVPO,'
      '    IDTPRICE_DVPO,'
      '    IDBASE_DVPO,'
      '    IDRTPRICE_DVPO,'
      '    OPER_DVPO,'
      '    NUMDOCPOST_DVPO,'
      '    POSDOCPOST_DVPO,'
      '    IDGRPOL_DVPO,'
      '    IDBSCHET_DVPO,'
      '    IDRSCHETKLIENT_DVPO,'
      '    IDRSCHETGRPOL_DVPO'
      ')'
      'VALUES('
      '    :IDVPO,'
      '    :IDDOCVPO,'
      '    :PRIMVPO,'
      '    :GID_DVPO,'
      '    :IDTPRICE_DVPO,'
      '    :IDBASE_DVPO,'
      '    :IDRTPRICE_DVPO,'
      '    :OPER_DVPO,'
      '    :NUMDOCPOST_DVPO,'
      '    :POSDOCPOST_DVPO,'
      '    :IDGRPOL_DVPO,'
      '    :IDBSCHET_DVPO,'
      '    :IDRSCHETKLIENT_DVPO,'
      '    :IDRSCHETGRPOL_DVPO'
      ')')
    RefreshSQL.Strings = (
      'select DVPO.*,'
      '    STPRICE.name_tprice,'
      '    SKLIENT.nameklient,'
      '    SBSCHET.namebschet,'
      '    srschet_klient.namerschet as name_rschet_klient,'
      '    srschet_grpol.namerschet as name_rschet_grpol '
      'from  DVPO'
      'left outer join STPRICE on DVPO.idtprice_dvpo=ID_TPRICE'
      'left outer join SKLIENT on DVPO.idgrpol_dvpo=IDKLIENT'
      'left outer join SBSCHET on IDBSCHET=DVPO.idbschet_dvpo'
      
        'left outer join srschet as srschet_klient on DVPO.idrschetklient' +
        '_dvpo=srschet_klient.idrschet'
      
        'left outer join srschet as srschet_grpol on DVPO.idrschetklient_' +
        'dvpo=srschet_grpol.idrschet'
      'where(  DVPO.iddocvpo=:ID'
      '     ) and (     DVPO.IDVPO = :OLD_IDVPO'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select DVPO.*,'
      '    STPRICE.name_tprice,'
      '    SKLIENT.nameklient,'
      '    SBSCHET.namebschet,'
      '    srschet_klient.namerschet as name_rschet_klient,'
      '    srschet_grpol.namerschet as name_rschet_grpol '
      'from  DVPO'
      'left outer join STPRICE on DVPO.idtprice_dvpo=ID_TPRICE'
      'left outer join SKLIENT on DVPO.idgrpol_dvpo=IDKLIENT'
      'left outer join SBSCHET on IDBSCHET=DVPO.idbschet_dvpo'
      
        'left outer join srschet as srschet_klient on DVPO.idrschetklient' +
        '_dvpo=srschet_klient.idrschet'
      
        'left outer join srschet as srschet_grpol on DVPO.idrschetklient_' +
        'dvpo=srschet_grpol.idrschet'
      'where DVPO.iddocvpo=:ID')
    AutoUpdateOptions.UpdateTableName = 'DVPO'
    AutoUpdateOptions.KeyFields = 'IDVPO'
    AutoUpdateOptions.GeneratorName = 'GEN_DVPO_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 72
    poUseLargeIntField = True
    object DocIDVPO: TFIBLargeIntField
      FieldName = 'IDVPO'
    end
    object DocIDDOCVPO: TFIBLargeIntField
      FieldName = 'IDDOCVPO'
    end
    object DocPRIMVPO: TFIBWideStringField
      FieldName = 'PRIMVPO'
      Size = 100
    end
    object DocGID_DVPO: TFIBWideStringField
      FieldName = 'GID_DVPO'
      Size = 10
    end
    object DocIDTPRICE_DVPO: TFIBLargeIntField
      FieldName = 'IDTPRICE_DVPO'
    end
    object DocIDBASE_DVPO: TFIBLargeIntField
      FieldName = 'IDBASE_DVPO'
    end
    object DocIDRTPRICE_DVPO: TFIBLargeIntField
      FieldName = 'IDRTPRICE_DVPO'
    end
    object DocOPER_DVPO: TFIBIntegerField
      FieldName = 'OPER_DVPO'
    end
    object DocNUMDOCPOST_DVPO: TFIBWideStringField
      FieldName = 'NUMDOCPOST_DVPO'
    end
    object DocPOSDOCPOST_DVPO: TFIBDateTimeField
      FieldName = 'POSDOCPOST_DVPO'
    end
    object DocNAME_TPRICE: TFIBWideStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
    end
    object DocIDGRPOL_DVPO: TFIBLargeIntField
      FieldName = 'IDGRPOL_DVPO'
    end
    object DocIDBSCHET_DVPO: TFIBLargeIntField
      FieldName = 'IDBSCHET_DVPO'
    end
    object DocIDRSCHETKLIENT_DVPO: TFIBLargeIntField
      FieldName = 'IDRSCHETKLIENT_DVPO'
    end
    object DocIDRSCHETGRPOL_DVPO: TFIBLargeIntField
      FieldName = 'IDRSCHETGRPOL_DVPO'
    end
    object DocNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 200
    end
    object DocNAMEBSCHET: TFIBWideStringField
      FieldName = 'NAMEBSCHET'
      Size = 200
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
      'UPDATE DVPOT'
      'SET '
      '    IDDOCVPOT = :IDDOCVPOT,'
      '    IDNOMVPOT = :IDNOMVPOT,'
      '    IDEDVPOT = :IDEDVPOT,'
      '    KOLVPOT = :KOLVPOT,'
      '    KFVPOT = :KFVPOT,'
      '    PRICEVPOT = :PRICEVPOT,'
      '    SUMVPOT = :SUMVPOT,'
      '    GID_DVPOT = :GID_DVPOT,'
      '    IDBASE_DVPOT = :IDBASE_DVPOT,'
      '    RPRICE_DVPOT = :RPRICE_DVPOT,'
      '    RSUM_DVPOT = :RSUM_DVPOT,'
      '    NDS_DVPOT = :NDS_DVPOT,'
      '    SUMNDS_DVPOT = :SUMNDS_DVPOT'
      'WHERE'
      '    IDVPOT = :OLD_IDVPOT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DVPOT'
      'WHERE'
      '        IDVPOT = :OLD_IDVPOT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DVPOT('
      '    IDVPOT,'
      '    IDDOCVPOT,'
      '    IDNOMVPOT,'
      '    IDEDVPOT,'
      '    KOLVPOT,'
      '    KFVPOT,'
      '    PRICEVPOT,'
      '    SUMVPOT,'
      '    GID_DVPOT,'
      '    IDBASE_DVPOT,'
      '    RPRICE_DVPOT,'
      '    RSUM_DVPOT,'
      '    NDS_DVPOT,'
      '    SUMNDS_DVPOT'
      ')'
      'VALUES('
      '    :IDVPOT,'
      '    :IDDOCVPOT,'
      '    :IDNOMVPOT,'
      '    :IDEDVPOT,'
      '    :KOLVPOT,'
      '    :KFVPOT,'
      '    :PRICEVPOT,'
      '    :SUMVPOT,'
      '    :GID_DVPOT,'
      '    :IDBASE_DVPOT,'
      '    :RPRICE_DVPOT,'
      '    :RSUM_DVPOT,'
      '    :NDS_DVPOT,'
      '    :SUMNDS_DVPOT'
      ')')
    RefreshSQL.Strings = (
      'select DVPOT.*,'
      '    snom.namenom,'
      '    snom.artnom,'
      '    snom.codenom,'
      '    snom.tnom,'
      '    sed.nameed,'
      '    sed.shed'
      'from DVPOT'
      'LEFT OUTER JOIN SNOM  ON DVPOT.idnomvpot=snom.idnom'
      'left outer join SED  on  DVPOT.idedvpot=sed.ided'
      'where(  DVPOT.iddocvpot=:ID'
      '     ) and (     DVPOT.IDVPOT = :OLD_IDVPOT'
      '     )'
      '    '
      ''
      '')
    SelectSQL.Strings = (
      'select DVPOT.*,'
      '    snom.namenom,'
      '    snom.artnom,'
      '    snom.codenom,'
      '    snom.tnom,'
      '    sed.nameed,'
      '    sed.shed'
      'from DVPOT'
      'LEFT OUTER JOIN SNOM  ON DVPOT.idnomvpot=snom.idnom'
      'left outer join SED  on  DVPOT.idedvpot=sed.ided'
      'where DVPOT.iddocvpot=:ID'
      ''
      '')
    AutoUpdateOptions.UpdateTableName = 'DVPOT'
    AutoUpdateOptions.KeyFields = 'IDVPOT'
    AutoUpdateOptions.GeneratorName = 'GEN_DVPOT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    AfterDelete = DocTAfterDelete
    BeforeDelete = DocTBeforeDelete
    OnCalcFields = DocTCalcFields
    OnNewRecord = DocTNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 128
    poUseLargeIntField = True
    object DocTRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object DocTIDVPOT: TFIBLargeIntField
      FieldName = 'IDVPOT'
    end
    object DocTIDDOCVPOT: TFIBLargeIntField
      FieldName = 'IDDOCVPOT'
    end
    object DocTIDNOMVPOT: TFIBLargeIntField
      FieldName = 'IDNOMVPOT'
    end
    object DocTIDEDVPOT: TFIBLargeIntField
      FieldName = 'IDEDVPOT'
    end
    object DocTKOLVPOT: TFIBBCDField
      FieldName = 'KOLVPOT'
      OnChange = DocTKOLVPOTChange
      Size = 3
      RoundByScale = True
    end
    object DocTKFVPOT: TFIBBCDField
      FieldName = 'KFVPOT'
      Size = 3
      RoundByScale = True
    end
    object DocTPRICEVPOT: TFIBBCDField
      FieldName = 'PRICEVPOT'
      OnChange = DocTPRICEVPOTChange
      Size = 2
      RoundByScale = True
    end
    object DocTSUMVPOT: TFIBBCDField
      FieldName = 'SUMVPOT'
      Size = 2
      RoundByScale = True
    end
    object DocTGID_DVPOT: TFIBWideStringField
      FieldName = 'GID_DVPOT'
      Size = 10
    end
    object DocTIDBASE_DVPOT: TFIBLargeIntField
      FieldName = 'IDBASE_DVPOT'
    end
    object DocTRPRICE_DVPOT: TFIBBCDField
      FieldName = 'RPRICE_DVPOT'
      OnChange = DocTRPRICE_DVPOTChange
      Size = 2
      RoundByScale = True
    end
    object DocTRSUM_DVPOT: TFIBBCDField
      FieldName = 'RSUM_DVPOT'
      Size = 2
      RoundByScale = True
    end
    object DocTNDS_DVPOT: TFIBIntegerField
      FieldName = 'NDS_DVPOT'
    end
    object DocTSUMNDS_DVPOT: TFIBBCDField
      FieldName = 'SUMNDS_DVPOT'
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
    object DocTARTNOM: TFIBWideStringField
      FieldName = 'ARTNOM'
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
      
        'from DOC_VPO_GET_NUM_NEW_DOC (:PARAM_IDBASE,:PARAM_IDFIRM,:PARAM' +
        '_IDSKLAD)')
    Transaction = IBTr
    Left = 352
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
    Left = 112
    Top = 192
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_VPO_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 256
    Top = 320
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_VPO_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 256
    Top = 272
    qoStartTransaction = True
  end
end
