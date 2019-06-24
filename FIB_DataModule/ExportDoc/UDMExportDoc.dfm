object DMExportDoc: TDMExportDoc
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 360
  Width = 651
  object GurAllDoc: TpFIBDataSet
    SelectSQL.Strings = (
      'select '
      'GALLDOC.*, NAMEFIRM, NAMESKLAD, NAMEKLIENT, NAME_USER,'
      ''
      '  sklient.innklient'
      ''
      'from '
      'GALLDOC LEFT OUTER JOIN SFIRM ON IDFIRMDOC=IDFIRM'
      'left outer join SSKLAD on IDSKLDOC=IDSKLAD'
      'left outer join SKLIENT on IDKLDOC=IDKLIENT'
      'left outer join SUSER on  IDUSERDOC= ID_USER'
      'where POSDOC between  :PARAM_DATE_NACH and :PARAM_DATE_CON '
      'order by POSDOC')
    Transaction = pFIBTr
    Left = 408
    Top = 16
    object GurAllDocIDDOC: TFIBBCDField
      FieldName = 'IDDOC'
      Size = 0
      RoundByScale = True
    end
    object GurAllDocPOSDOC: TFIBDateTimeField
      FieldName = 'POSDOC'
    end
    object GurAllDocPRDOC: TFIBSmallIntField
      FieldName = 'PRDOC'
    end
    object GurAllDocNUMDOC: TFIBIntegerField
      FieldName = 'NUMDOC'
    end
    object GurAllDocIDFIRMDOC: TFIBBCDField
      FieldName = 'IDFIRMDOC'
      Size = 0
      RoundByScale = True
    end
    object GurAllDocIDSKLDOC: TFIBBCDField
      FieldName = 'IDSKLDOC'
      Size = 0
      RoundByScale = True
    end
    object GurAllDocIDKLDOC: TFIBBCDField
      FieldName = 'IDKLDOC'
      Size = 0
      RoundByScale = True
    end
    object GurAllDocIDDOGDOC: TFIBBCDField
      FieldName = 'IDDOGDOC'
      Size = 0
      RoundByScale = True
    end
    object GurAllDocSUMDOC: TFIBBCDField
      FieldName = 'SUMDOC'
      Size = 2
      RoundByScale = True
    end
    object GurAllDocIDUSERDOC: TFIBBCDField
      FieldName = 'IDUSERDOC'
      Size = 0
      RoundByScale = True
    end
    object GurAllDocIDDOCOSNDOC: TFIBBCDField
      FieldName = 'IDDOCOSNDOC'
      Size = 0
      RoundByScale = True
    end
    object GurAllDocIDEXTDOC: TFIBBCDField
      FieldName = 'IDEXTDOC'
      Size = 0
      RoundByScale = True
    end
    object GurAllDocIDBASE_GALLDOC: TFIBBCDField
      FieldName = 'IDBASE_GALLDOC'
      Size = 0
      RoundByScale = True
    end
    object GurAllDocIDEXT_DOUT_GALLDOC: TFIBBCDField
      FieldName = 'IDEXT_DOUT_GALLDOC'
      Size = 0
      RoundByScale = True
    end
    object GurAllDocIDEXT_BASE_GALLDOC: TFIBBCDField
      FieldName = 'IDEXT_BASE_GALLDOC'
      Size = 0
      RoundByScale = True
    end
    object GurAllDocTDOC: TFIBWideStringField
      FieldName = 'TDOC'
      Size = 10
    end
    object GurAllDocGID_DOC: TFIBWideStringField
      FieldName = 'GID_DOC'
      Size = 10
    end
    object GurAllDocTYPEEXTDOC: TFIBIntegerField
      FieldName = 'TYPEEXTDOC'
    end
    object GurAllDocNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 100
    end
    object GurAllDocNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 100
    end
    object GurAllDocNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 100
    end
    object GurAllDocNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
      Size = 100
    end
    object GurAllDocINNKLIENT: TFIBWideStringField
      FieldName = 'INNKLIENT'
      Size = 12
    end
  end
  object pFIBTr: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 480
    Top = 16
  end
  object Check_Doc: TpFIBDataSet
    SelectSQL.Strings = (
      'select DCHK.ncheckchk,'
      '  dchk.nklchk,'
      '  dchk.operchk,'
      '  skkm.namekkm,'
      '  skkm.idkkm,'
      '  stprice.name_tprice,'
      '  stprice.id_tprice,'
      '  sdiscount_card.name_sdiscount_card,'
      '  sdiscount_card.code_sdiscount_card,'
      '  sdiscount_card.shcode_sdiscount_card'
      'from  DCHK'
      'left outer join SKKM on IDKKM=IDKKMCHK'
      'left outer join SDISCOUNT_CARD on ID_SDISCOUNT_CARD=IDDCARDCHK'
      'left outer join stprice on stprice.id_tprice=dchk.idtprice'
      'where IDDOCCHK=:PARAM_ID')
    Transaction = pFIBTr
    Left = 488
    Top = 120
    object Check_DocOPERCHK: TFIBSmallIntField
      FieldName = 'OPERCHK'
    end
    object Check_DocCODE_SDISCOUNT_CARD: TFIBIntegerField
      FieldName = 'CODE_SDISCOUNT_CARD'
    end
    object Check_DocIDKKM: TFIBBCDField
      FieldName = 'IDKKM'
      Size = 0
      RoundByScale = True
    end
    object Check_DocID_TPRICE: TFIBBCDField
      FieldName = 'ID_TPRICE'
      Size = 0
      RoundByScale = True
    end
    object Check_DocNCHECKCHK: TFIBIntegerField
      FieldName = 'NCHECKCHK'
    end
    object Check_DocNKLCHK: TFIBIntegerField
      FieldName = 'NKLCHK'
    end
    object Check_DocNAMEKKM: TFIBWideStringField
      FieldName = 'NAMEKKM'
      Size = 100
    end
    object Check_DocNAME_TPRICE: TFIBWideStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
    end
    object Check_DocNAME_SDISCOUNT_CARD: TFIBWideStringField
      FieldName = 'NAME_SDISCOUNT_CARD'
      Size = 100
    end
    object Check_DocSHCODE_SDISCOUNT_CARD: TFIBWideStringField
      FieldName = 'SHCODE_SDISCOUNT_CARD'
      Size = 13
    end
  end
  object Check_DocT: TpFIBDataSet
    SelectSQL.Strings = (
      'select'
      '        snom.namenom,'
      '        snom.codenom,'
      '        DCHKT.kolchkt,'
      '        dchkt.kfchkt,'
      '        sed.nameed,'
      '        sed.code_sed,'
      '        sed.shed,'
      '        dchkt.pricechkt,'
      '        dchkt.sumchkt,'
      '        dchkt.skchkt,'
      '        dchkt.prskchkt'
      'from '
      'DCHKT LEFT OUTER JOIN SNOM  ON IDNOMCHKT=IDNOM '
      'left outer join SED  on  IDEDCHKT=IDED'
      'where IDDOCCHKT=:PARAM_ID')
    Transaction = pFIBTr
    Left = 488
    Top = 176
    object Check_DocTCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object Check_DocTKOLCHKT: TFIBBCDField
      FieldName = 'KOLCHKT'
      Size = 3
      RoundByScale = True
    end
    object Check_DocTKFCHKT: TFIBBCDField
      FieldName = 'KFCHKT'
      Size = 3
      RoundByScale = True
    end
    object Check_DocTCODE_SED: TFIBIntegerField
      FieldName = 'CODE_SED'
    end
    object Check_DocTPRICECHKT: TFIBBCDField
      FieldName = 'PRICECHKT'
      Size = 2
      RoundByScale = True
    end
    object Check_DocTSUMCHKT: TFIBBCDField
      FieldName = 'SUMCHKT'
      Size = 2
      RoundByScale = True
    end
    object Check_DocTSKCHKT: TFIBBCDField
      FieldName = 'SKCHKT'
      Size = 2
      RoundByScale = True
    end
    object Check_DocTPRSKCHKT: TFIBBCDField
      FieldName = 'PRSKCHKT'
      Size = 2
      RoundByScale = True
    end
    object Check_DocTNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 100
    end
    object Check_DocTNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
    end
    object Check_DocTSHED: TFIBWideStringField
      FieldName = 'SHED'
      Size = 13
    end
  end
  object TableFirm: TpFIBDataSet
    SelectSQL.Strings = (
      'select '
      '     IDFIRM,'
      '     NAMEFIRM'
      'from SFIRM')
    Transaction = pFIBTr
    Left = 48
    Top = 152
    object TableFirmIDFIRM: TFIBBCDField
      FieldName = 'IDFIRM'
      Size = 0
      RoundByScale = True
    end
    object TableFirmNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 100
    end
  end
  object TableSklad: TpFIBDataSet
    SelectSQL.Strings = (
      'select'
      '   IDSKLAD,'
      '   NAMESKLAD'
      'from SSKLAD')
    Transaction = pFIBTr
    Left = 48
    Top = 200
    object TableSkladIDSKLAD: TFIBBCDField
      FieldName = 'IDSKLAD'
      Size = 0
      RoundByScale = True
    end
    object TableSkladNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 100
    end
  end
  object TableKassa: TpFIBDataSet
    SelectSQL.Strings = (
      'select '
      '   IDKKM,'
      '   NAMEKKM'
      'from SKKM')
    Transaction = pFIBTr
    Left = 48
    Top = 248
    object TableKassaIDKKM: TFIBBCDField
      FieldName = 'IDKKM'
      Size = 0
      RoundByScale = True
    end
    object TableKassaNAMEKKM: TFIBWideStringField
      FieldName = 'NAMEKKM'
      Size = 100
    end
  end
  object Per_Doc: TpFIBDataSet
    SelectSQL.Strings = (
      'select dper.idsklpolper,'
      '  ssklad.namesklad,'
      '  dper.idrtprice_dper,'
      '  stprice.name_tprice'
      'from  dper'
      'left outer join SSKLAD on dper.idsklpolper=ssklad.idsklad'
      'left outer join stprice on stprice.id_tprice=dper.idrtprice_dper'
      'where dper.iddocper=:PARAM_ID')
    Transaction = pFIBTr
    Left = 160
    Top = 232
    object Per_DocIDSKLPOLPER: TFIBBCDField
      FieldName = 'IDSKLPOLPER'
      Size = 0
      RoundByScale = True
    end
    object Per_DocIDRTPRICE_DPER: TFIBBCDField
      FieldName = 'IDRTPRICE_DPER'
      Size = 0
      RoundByScale = True
    end
    object Per_DocNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 100
    end
    object Per_DocNAME_TPRICE: TFIBWideStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
    end
  end
  object Per_DocT: TpFIBDataSet
    SelectSQL.Strings = (
      'select'
      '        snom.namenom,'
      '        snom.codenom,'
      '        dpert.kolpert,'
      '        dpert.kfpert,'
      '        sed.nameed,'
      '        sed.code_sed,'
      '        sed.shed,'
      '        dpert.pricepert,'
      '        dpert.sumpert'
      'from '
      'dpert left outer join SNOM  on dpert.idnompert=snom.idnom'
      'left outer join SED  on  dpert.idedpert=sed.ided'
      'where dpert.iddocpert=:PARAM_ID')
    Transaction = pFIBTr
    Left = 160
    Top = 280
    object Per_DocTCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object Per_DocTKOLPERT: TFIBBCDField
      FieldName = 'KOLPERT'
      Size = 3
      RoundByScale = True
    end
    object Per_DocTKFPERT: TFIBBCDField
      FieldName = 'KFPERT'
      Size = 3
      RoundByScale = True
    end
    object Per_DocTCODE_SED: TFIBIntegerField
      FieldName = 'CODE_SED'
    end
    object Per_DocTPRICEPERT: TFIBBCDField
      FieldName = 'PRICEPERT'
      Size = 2
      RoundByScale = True
    end
    object Per_DocTSUMPERT: TFIBBCDField
      FieldName = 'SUMPERT'
      Size = 2
      RoundByScale = True
    end
    object Per_DocTNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 100
    end
    object Per_DocTNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
    end
    object Per_DocTSHED: TFIBWideStringField
      FieldName = 'SHED'
      Size = 13
    end
  end
  object PrihNakl_Doc: TpFIBDataSet
    SelectSQL.Strings = (
      'select dprn.rsum_dprn,'
      '  dprn.idtprice,'
      '  dprn.idrtprice_dprn,'
      '  dprn.numdocpost_dprn,'
      '  dprn.posdocpost_dprn,'
      '  ZAKTPRICE.name_tprice as NAME_ZAKTPRICE,'
      '  ROZNTPRICE.name_tprice as NAME_ROZNTPRICE'
      'from  dprn'
      
        'left outer join stprice as ZAKTPRICE   on ZAKTPRICE.id_tprice=dp' +
        'rn.idtprice'
      
        'left outer join stprice as ROZNTPRICE  on ROZNTPRICE.id_tprice=d' +
        'prn.idrtprice_dprn'
      'where dprn.iddocprn=:PARAM_ID')
    Transaction = pFIBTr
    Left = 248
    Top = 232
    object PrihNakl_DocRSUM_DPRN: TFIBBCDField
      FieldName = 'RSUM_DPRN'
      Size = 2
      RoundByScale = True
    end
    object PrihNakl_DocIDTPRICE: TFIBBCDField
      FieldName = 'IDTPRICE'
      Size = 0
      RoundByScale = True
    end
    object PrihNakl_DocIDRTPRICE_DPRN: TFIBBCDField
      FieldName = 'IDRTPRICE_DPRN'
      Size = 0
      RoundByScale = True
    end
    object PrihNakl_DocNAME_ZAKTPRICE: TFIBWideStringField
      FieldName = 'NAME_ZAKTPRICE'
      Size = 30
    end
    object PrihNakl_DocNAME_ROZNTPRICE: TFIBWideStringField
      FieldName = 'NAME_ROZNTPRICE'
      Size = 30
    end
    object PrihNakl_DocNUMDOCPOST_DPRN: TFIBWideStringField
      FieldName = 'NUMDOCPOST_DPRN'
    end
    object PrihNakl_DocPOSDOCPOST_DPRN: TFIBDateTimeField
      FieldName = 'POSDOCPOST_DPRN'
    end
  end
  object PrihNakl_DocT: TpFIBDataSet
    SelectSQL.Strings = (
      'select'
      '        snom.namenom,'
      '        snom.codenom,'
      '        dprnt.kolprnt,'
      '        dprnt.kfprnt,'
      '        sed.nameed,'
      '        sed.code_sed,'
      '        sed.shed,'
      '        dprnt.priceprnt,'
      '        dprnt.sumprnt,'
      '        dprnt.nac_dprnt,'
      '        dprnt.rprice_dprnt,'
      '        dprnt.rsum_dprnt'
      'from dprnt'
      'left outer join SNOM  on dprnt.idnomprnt=snom.idnom'
      'left outer join SED  on  dprnt.idedprnt=sed.ided'
      'where dprnt.iddocprnt=:PARAM_ID')
    Transaction = pFIBTr
    Left = 248
    Top = 280
    object PrihNakl_DocTCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object PrihNakl_DocTKOLPRNT: TFIBBCDField
      FieldName = 'KOLPRNT'
      Size = 3
      RoundByScale = True
    end
    object PrihNakl_DocTKFPRNT: TFIBBCDField
      FieldName = 'KFPRNT'
      Size = 3
      RoundByScale = True
    end
    object PrihNakl_DocTCODE_SED: TFIBIntegerField
      FieldName = 'CODE_SED'
    end
    object PrihNakl_DocTPRICEPRNT: TFIBBCDField
      FieldName = 'PRICEPRNT'
      Size = 2
      RoundByScale = True
    end
    object PrihNakl_DocTSUMPRNT: TFIBBCDField
      FieldName = 'SUMPRNT'
      Size = 2
      RoundByScale = True
    end
    object PrihNakl_DocTNAC_DPRNT: TFIBBCDField
      FieldName = 'NAC_DPRNT'
      Size = 2
      RoundByScale = True
    end
    object PrihNakl_DocTRPRICE_DPRNT: TFIBBCDField
      FieldName = 'RPRICE_DPRNT'
      Size = 2
      RoundByScale = True
    end
    object PrihNakl_DocTRSUM_DPRNT: TFIBBCDField
      FieldName = 'RSUM_DPRNT'
      Size = 2
      RoundByScale = True
    end
    object PrihNakl_DocTNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 100
    end
    object PrihNakl_DocTNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
    end
    object PrihNakl_DocTSHED: TFIBWideStringField
      FieldName = 'SHED'
      Size = 13
    end
  end
  object VPO_Doc: TpFIBDataSet
    SelectSQL.Strings = (
      'select'
      '  dvpo.idtprice_dvpo,'
      '  dvpo.idrtprice_dvpo,'
      '  dvpo.numdocpost_dvpo,'
      '  dvpo.posdocpost_dvpo,'
      '  ZAKTPRICE.name_tprice as NAME_ZAKTPRICE,'
      '  ROZNTPRICE.name_tprice as NAME_ROZNTPRICE'
      'from  dvpo'
      
        'left outer join stprice as ZAKTPRICE   on ZAKTPRICE.id_tprice=dv' +
        'po.idtprice_dvpo'
      
        'left outer join stprice as ROZNTPRICE  on ROZNTPRICE.id_tprice=d' +
        'vpo.idrtprice_dvpo'
      'where dvpo.iddocvpo=:PARAM_ID')
    Transaction = pFIBTr
    Left = 336
    Top = 232
    object VPO_DocIDTPRICE_DVPO: TFIBBCDField
      FieldName = 'IDTPRICE_DVPO'
      Size = 0
      RoundByScale = True
    end
    object VPO_DocIDRTPRICE_DVPO: TFIBBCDField
      FieldName = 'IDRTPRICE_DVPO'
      Size = 0
      RoundByScale = True
    end
    object VPO_DocNAME_ZAKTPRICE: TFIBWideStringField
      FieldName = 'NAME_ZAKTPRICE'
      Size = 30
    end
    object VPO_DocNAME_ROZNTPRICE: TFIBWideStringField
      FieldName = 'NAME_ROZNTPRICE'
      Size = 30
    end
    object VPO_DocNUMDOCPOST_DVPO: TFIBWideStringField
      FieldName = 'NUMDOCPOST_DVPO'
    end
    object VPO_DocPOSDOCPOST_DVPO: TFIBDateTimeField
      FieldName = 'POSDOCPOST_DVPO'
    end
  end
  object VPO_DocT: TpFIBDataSet
    SelectSQL.Strings = (
      'select'
      '        snom.namenom,'
      '        snom.codenom,'
      '        dvpot.kolvpot,'
      '        dvpot.kfvpot,'
      '        sed.nameed,'
      '        sed.code_sed,'
      '        sed.shed,'
      '        dvpot.pricevpot,'
      '        dvpot.sumvpot,'
      '        dvpot.rprice_dvpot,'
      '        dvpot.rsum_dvpot'
      'from dvpot'
      'left outer join SNOM  on dvpot.idnomvpot=snom.idnom'
      'left outer join SED  on  dvpot.idedvpot=sed.ided'
      'where dvpot.iddocvpot=:PARAM_ID')
    Transaction = pFIBTr
    Left = 336
    Top = 280
    object VPO_DocTCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object VPO_DocTKOLVPOT: TFIBBCDField
      FieldName = 'KOLVPOT'
      Size = 3
      RoundByScale = True
    end
    object VPO_DocTKFVPOT: TFIBBCDField
      FieldName = 'KFVPOT'
      Size = 3
      RoundByScale = True
    end
    object VPO_DocTCODE_SED: TFIBIntegerField
      FieldName = 'CODE_SED'
    end
    object VPO_DocTPRICEVPOT: TFIBBCDField
      FieldName = 'PRICEVPOT'
      Size = 2
      RoundByScale = True
    end
    object VPO_DocTSUMVPOT: TFIBBCDField
      FieldName = 'SUMVPOT'
      Size = 2
      RoundByScale = True
    end
    object VPO_DocTRPRICE_DVPOT: TFIBBCDField
      FieldName = 'RPRICE_DVPOT'
      Size = 2
      RoundByScale = True
    end
    object VPO_DocTRSUM_DVPOT: TFIBBCDField
      FieldName = 'RSUM_DVPOT'
      Size = 2
      RoundByScale = True
    end
    object VPO_DocTNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 100
    end
    object VPO_DocTNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
    end
    object VPO_DocTSHED: TFIBWideStringField
      FieldName = 'SHED'
      Size = 13
    end
  end
  object IsmPrice_Doc: TpFIBDataSet
    SelectSQL.Strings = (
      'select'
      '    dismprice.descr_dismprice,'
      '  dismprice.idoldtprice_dismprice,'
      '  dismprice.idnewtprice_dismprice,'
      '  OLDTPRICE.name_tprice as NAME_OLDTPRICE,'
      '  NEWTPRICE.name_tprice as NAME_NEWTPRICE'
      'from  dismprice'
      
        'left outer join stprice as OLDTPRICE   on OLDTPRICE.id_tprice=di' +
        'smprice.idoldtprice_dismprice'
      
        'left outer join stprice as NEWTPRICE  on NEWTPRICE.id_tprice=dis' +
        'mprice.idnewtprice_dismprice'
      'where dismprice.iddoc_dismprice=:PARAM_ID')
    Transaction = pFIBTr
    Left = 424
    Top = 232
    object IsmPrice_DocIDOLDTPRICE_DISMPRICE: TFIBBCDField
      FieldName = 'IDOLDTPRICE_DISMPRICE'
      Size = 0
      RoundByScale = True
    end
    object IsmPrice_DocIDNEWTPRICE_DISMPRICE: TFIBBCDField
      FieldName = 'IDNEWTPRICE_DISMPRICE'
      Size = 0
      RoundByScale = True
    end
    object IsmPrice_DocDESCR_DISMPRICE: TFIBWideStringField
      FieldName = 'DESCR_DISMPRICE'
      Size = 150
    end
    object IsmPrice_DocNAME_OLDTPRICE: TFIBWideStringField
      FieldName = 'NAME_OLDTPRICE'
      Size = 30
    end
    object IsmPrice_DocNAME_NEWTPRICE: TFIBWideStringField
      FieldName = 'NAME_NEWTPRICE'
      Size = 30
    end
  end
  object IsmPrice_DocT: TpFIBDataSet
    SelectSQL.Strings = (
      'select'
      '        snom.namenom,'
      '        snom.codenom,'
      '        dismpricet.kol_dismpricet,'
      '        dismpricet.kf_dismpricet,'
      '        sed.nameed,'
      '        sed.code_sed,'
      '        sed.shed,'
      '        dismpricet.oldprice_dismpricet,'
      '        dismpricet.newprice_dismpricet'
      'from dismpricet'
      'left outer join SNOM  on dismpricet.idnom_dismpricet=snom.idnom'
      'left outer join SED  on  dismpricet.ided_dismpricet=sed.ided'
      'where dismpricet.iddoc_dismpricet=:PARAM_ID')
    Transaction = pFIBTr
    Left = 424
    Top = 280
    object IsmPrice_DocTCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object IsmPrice_DocTKOL_DISMPRICET: TFIBBCDField
      FieldName = 'KOL_DISMPRICET'
      Size = 3
      RoundByScale = True
    end
    object IsmPrice_DocTKF_DISMPRICET: TFIBBCDField
      FieldName = 'KF_DISMPRICET'
      Size = 3
      RoundByScale = True
    end
    object IsmPrice_DocTCODE_SED: TFIBIntegerField
      FieldName = 'CODE_SED'
    end
    object IsmPrice_DocTOLDPRICE_DISMPRICET: TFIBBCDField
      FieldName = 'OLDPRICE_DISMPRICET'
      Size = 2
      RoundByScale = True
    end
    object IsmPrice_DocTNEWPRICE_DISMPRICET: TFIBBCDField
      FieldName = 'NEWPRICE_DISMPRICET'
      Size = 2
      RoundByScale = True
    end
    object IsmPrice_DocTNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 100
    end
    object IsmPrice_DocTNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
    end
    object IsmPrice_DocTSHED: TFIBWideStringField
      FieldName = 'SHED'
      Size = 13
    end
  end
  object Inv_Doc: TpFIBDataSet
    SelectSQL.Strings = (
      'select dinv.idtprice_inv,'
      '  dinv.type_inv,'
      '  dinv.prim_inv,'
      '  sinv.name_sinv,'
      '  stprice.name_tprice'
      'from  dinv'
      'left outer join stprice  on stprice.id_tprice=dinv.idtprice_inv'
      'left outer join sinv on sinv.id_sinv=dinv.idinv_inv'
      'where dinv.iddoc_inv=:PARAM_ID')
    Transaction = pFIBTr
    Left = 512
    Top = 232
    object Inv_DocIDTPRICE_INV: TFIBBCDField
      FieldName = 'IDTPRICE_INV'
      Size = 0
      RoundByScale = True
    end
    object Inv_DocTYPE_INV: TFIBIntegerField
      FieldName = 'TYPE_INV'
    end
    object Inv_DocPRIM_INV: TFIBWideStringField
      FieldName = 'PRIM_INV'
      Size = 100
    end
    object Inv_DocNAME_SINV: TFIBWideStringField
      FieldName = 'NAME_SINV'
      Size = 100
    end
    object Inv_DocNAME_TPRICE: TFIBWideStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
    end
  end
  object Inv_DocT: TpFIBDataSet
    SelectSQL.Strings = (
      'select'
      '        snom.namenom,'
      '        snom.codenom,'
      '        dinvt.koluch_invt,'
      '        dinvt.kolfakt_invt,'
      '        dinvt.kf_invt,'
      '        sed.nameed,'
      '        sed.code_sed,'
      '        sed.shed,'
      '        dinvt.price_invt,'
      '        dinvt.sumf_invt'
      'from dinvt'
      'left outer join SNOM  on dinvt.idnom_invt=snom.idnom'
      'left outer join SED  on  dinvt.ided_invt=sed.ided'
      'where dinvt.iddoc_invt=:PARAM_ID')
    Transaction = pFIBTr
    Left = 512
    Top = 280
    object Inv_DocTKOLUCH_INVT: TFIBBCDField
      FieldName = 'KOLUCH_INVT'
      Size = 3
      RoundByScale = True
    end
    object Inv_DocTKOLFAKT_INVT: TFIBBCDField
      FieldName = 'KOLFAKT_INVT'
      Size = 3
      RoundByScale = True
    end
    object Inv_DocTKF_INVT: TFIBBCDField
      FieldName = 'KF_INVT'
      Size = 3
      RoundByScale = True
    end
    object Inv_DocTCODE_SED: TFIBIntegerField
      FieldName = 'CODE_SED'
    end
    object Inv_DocTPRICE_INVT: TFIBBCDField
      FieldName = 'PRICE_INVT'
      Size = 2
      RoundByScale = True
    end
    object Inv_DocTSUMF_INVT: TFIBBCDField
      FieldName = 'SUMF_INVT'
      Size = 2
      RoundByScale = True
    end
    object Inv_DocTNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 100
    end
    object Inv_DocTCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object Inv_DocTNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
    end
    object Inv_DocTSHED: TFIBWideStringField
      FieldName = 'SHED'
      Size = 13
    end
  end
  object Rev_Doc: TpFIBDataSet
    SelectSQL.Strings = (
      'select drev.idrtprice_drev,'
      '  sinv.name_sinv,'
      '  drev.descr_drev,'
      '  stprice.name_tprice'
      'from  drev'
      
        'left outer join stprice  on stprice.id_tprice=drev.idrtprice_dre' +
        'v'
      'left outer join sinv on sinv.id_sinv=drev.idinv_drev'
      'where drev.iddoc_drev=:PARAM_ID')
    Transaction = pFIBTr
    Left = 592
    Top = 232
    object Rev_DocIDRTPRICE_DREV: TFIBBCDField
      FieldName = 'IDRTPRICE_DREV'
      Size = 0
      RoundByScale = True
    end
    object Rev_DocNAME_SINV: TFIBWideStringField
      FieldName = 'NAME_SINV'
      Size = 100
    end
    object Rev_DocDESCR_DREV: TFIBWideStringField
      FieldName = 'DESCR_DREV'
      Size = 100
    end
    object Rev_DocNAME_TPRICE: TFIBWideStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
    end
  end
  object Rev_DocT: TpFIBDataSet
    SelectSQL.Strings = (
      'select'
      '        snom.namenom,'
      '        snom.codenom,'
      '        drevt.kol_drevt,'
      '        drevt.kf_drevt,'
      '        sed.nameed,'
      '        sed.code_sed,'
      '        sed.shed,'
      '        drevt.rprice_drevt,'
      '        drevt.rsum_drevt'
      'from drevt'
      'left outer join SNOM  on drevt.idnom_drevt=snom.idnom'
      'left outer join SED  on  drevt.ided_drevt=sed.ided'
      'where drevt.iddoc_drevt=:PARAM_ID')
    Transaction = pFIBTr
    Left = 592
    Top = 280
    object Rev_DocTKOL_DREVT: TFIBBCDField
      FieldName = 'KOL_DREVT'
      Size = 3
      RoundByScale = True
    end
    object Rev_DocTKF_DREVT: TFIBBCDField
      FieldName = 'KF_DREVT'
      Size = 3
      RoundByScale = True
    end
    object Rev_DocTCODE_SED: TFIBIntegerField
      FieldName = 'CODE_SED'
    end
    object Rev_DocTRPRICE_DREVT: TFIBBCDField
      FieldName = 'RPRICE_DREVT'
      Size = 2
      RoundByScale = True
    end
    object Rev_DocTRSUM_DREVT: TFIBBCDField
      FieldName = 'RSUM_DREVT'
      Size = 2
      RoundByScale = True
    end
    object Rev_DocTNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 100
    end
    object Rev_DocTCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object Rev_DocTNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
    end
    object Rev_DocTSHED: TFIBWideStringField
      FieldName = 'SHED'
      Size = 13
    end
  end
  object XML: TXMLDocument
    Left = 64
    Top = 40
    DOMVendorDesc = 'MSXML'
  end
end
