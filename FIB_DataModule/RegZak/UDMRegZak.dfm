object DMRegZak: TDMRegZak
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 243
  Width = 423
  object DataSourceDoc: TDataSource
    DataSet = Doc
    Left = 64
    Top = 16
  end
  object DataSourceDocT: TDataSource
    DataSet = DocT
    Left = 64
    Top = 72
  end
  object DataSourceOb: TDataSource
    DataSet = Ob
    Left = 56
    Top = 136
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
    Top = 72
  end
  object Doc: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE RGZAK'
      'SET '
      '    IDOB_ZAK = :IDOB_ZAK,'
      '    SUM_ZAK = :SUM_ZAK,'
      '    SOST_ZAK = :SOST_ZAK,'
      '    IDKLIENT_ZAK = :IDKLIENT_ZAK,'
      '    IDUSER_ZAK = :IDUSER_ZAK,'
      '    IDTYPEPRICE_ZAK = :IDTYPEPRICE_ZAK,'
      '    IDDISCOUNTCARD_ZAK = :IDDISCOUNTCARD_ZAK'
      'WHERE'
      '    ID_ZAK = :OLD_ID_ZAK'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    RGZAK'
      'WHERE'
      '        ID_ZAK = :OLD_ID_ZAK'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO RGZAK('
      '    ID_ZAK,'
      '    IDOB_ZAK,'
      '    SUM_ZAK,'
      '    SOST_ZAK,'
      '    IDKLIENT_ZAK,'
      '    IDUSER_ZAK,'
      '    IDTYPEPRICE_ZAK,'
      '    IDDISCOUNTCARD_ZAK'
      ')'
      'VALUES('
      '    :ID_ZAK,'
      '    :IDOB_ZAK,'
      '    :SUM_ZAK,'
      '    :SOST_ZAK,'
      '    :IDKLIENT_ZAK,'
      '    :IDUSER_ZAK,'
      '    :IDTYPEPRICE_ZAK,'
      '    :IDDISCOUNTCARD_ZAK'
      ')')
    RefreshSQL.Strings = (
      'select '
      
        '  RGZAK.* , NAME_STROB, SKLIENT.*, NAME_USER, NAME_TPRICE, NAME_' +
        'SDISCOUNT_CARD'
      'from '
      '  RGZAK'
      'left outer join SSTROB on   IDOB_ZAK=ID_STROB'
      'left outer join SKLIENT on IDKLIENT_ZAK=IDKLIENT'
      'left outer join SUSER on IDUSER_ZAK=ID_USER'
      'left outer join STPRICE on IDTYPEPRICE_ZAK=ID_TPRICE'
      
        'left outer join SDISCOUNT_CARD on IDDISCOUNTCARD_ZAK=ID_SDISCOUN' +
        'T_CARD'
      'where(  '
      '  ID_ZAK=:ID'
      '     ) and (     RGZAK.ID_ZAK = :OLD_ID_ZAK'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select '
      
        '  RGZAK.* , NAME_STROB, SKLIENT.*, NAME_USER, NAME_TPRICE, NAME_' +
        'SDISCOUNT_CARD'
      'from '
      '  RGZAK'
      'left outer join SSTROB on   IDOB_ZAK=ID_STROB'
      'left outer join SKLIENT on IDKLIENT_ZAK=IDKLIENT'
      'left outer join SUSER on IDUSER_ZAK=ID_USER'
      'left outer join STPRICE on IDTYPEPRICE_ZAK=ID_TPRICE'
      
        'left outer join SDISCOUNT_CARD on IDDISCOUNTCARD_ZAK=ID_SDISCOUN' +
        'T_CARD'
      'where '
      '  ID_ZAK=:ID')
    AutoUpdateOptions.UpdateTableName = 'RGZAK'
    AutoUpdateOptions.KeyFields = 'ID_ZAK'
    AutoUpdateOptions.GeneratorName = 'GEN_RGZAK_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnCalcFields = DocCalcFields
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 16
    object DocSUM_ZAK: TFIBBCDField
      FieldName = 'SUM_ZAK'
      Size = 2
      RoundByScale = True
    end
    object DocSOST_ZAK: TFIBSmallIntField
      FieldName = 'SOST_ZAK'
    end
    object DocID_ZAK: TFIBBCDField
      FieldName = 'ID_ZAK'
      Size = 0
      RoundByScale = True
    end
    object DocIDOB_ZAK: TFIBBCDField
      FieldName = 'IDOB_ZAK'
      Size = 0
      RoundByScale = True
    end
    object DocIDKLIENT_ZAK: TFIBBCDField
      FieldName = 'IDKLIENT_ZAK'
      Size = 0
      RoundByScale = True
    end
    object DocIDUSER_ZAK: TFIBBCDField
      FieldName = 'IDUSER_ZAK'
      Size = 0
      RoundByScale = True
    end
    object DocIDKLIENT: TFIBBCDField
      FieldName = 'IDKLIENT'
      Size = 0
      RoundByScale = True
    end
    object DocIDTYPEPRICE_ZAK: TFIBBCDField
      FieldName = 'IDTYPEPRICE_ZAK'
      Size = 0
      RoundByScale = True
    end
    object DocIDDISCOUNTCARD_ZAK: TFIBBCDField
      FieldName = 'IDDISCOUNTCARD_ZAK'
      Size = 0
      RoundByScale = True
    end
    object DocNAME_STROB: TFIBWideStringField
      FieldName = 'NAME_STROB'
      Size = 100
    end
    object DocNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 100
    end
    object DocNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
      Size = 100
    end
    object DocNAME_TPRICE: TFIBWideStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
    end
    object DocNAME_SDISCOUNT_CARD: TFIBWideStringField
      FieldName = 'NAME_SDISCOUNT_CARD'
      Size = 100
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE RGZAKT'
      'SET '
      '    IDZ_ZAKT = :IDZ_ZAKT,'
      '    IDNOM_ZAKT = :IDNOM_ZAKT,'
      '    IDED_ZAKT = :IDED_ZAKT,'
      '    IDMPRIG_ZAKT = :IDMPRIG_ZAKT,'
      '    KOLPR_ZAKT = :KOLPR_ZAKT,'
      '    KOLOT_ZAKT = :KOLOT_ZAKT,'
      '    KOLZ_ZAKT = :KOLZ_ZAKT,'
      '    KF_ZAKT = :KF_ZAKT,'
      '    PRICE_ZAKT = :PRICE_ZAKT,'
      '    SUM_ZAKT = :SUM_ZAKT,'
      '    OTKAZ_ZAKT = :OTKAZ_ZAKT,'
      '    PRSK_ZAKT = :PRSK_ZAKT,'
      '    PRNAD_ZAKT = :PRNAD_ZAKT,'
      '    SUMSK_ZAKT = :SUMSK_ZAKT,'
      '    SUMNAD_ZAKT = :SUMNAD_ZAKT,'
      '    IDBASE_RGZAKT = :IDBASE_RGZAKT,'
      '    PRSK_CARD_RGZAKT = :PRSK_CARD_RGZAKT,'
      '    PRSK_AUTO_RGZAKT = :PRSK_AUTO_RGZAKT'
      'WHERE'
      '    ID_ZAKT = :OLD_ID_ZAKT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    RGZAKT'
      'WHERE'
      '        ID_ZAKT = :OLD_ID_ZAKT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO RGZAKT('
      '    ID_ZAKT,'
      '    IDZ_ZAKT,'
      '    IDNOM_ZAKT,'
      '    IDED_ZAKT,'
      '    IDMPRIG_ZAKT,'
      '    KOLPR_ZAKT,'
      '    KOLOT_ZAKT,'
      '    KOLZ_ZAKT,'
      '    KF_ZAKT,'
      '    PRICE_ZAKT,'
      '    SUM_ZAKT,'
      '    OTKAZ_ZAKT,'
      '    PRSK_ZAKT,'
      '    PRNAD_ZAKT,'
      '    SUMSK_ZAKT,'
      '    SUMNAD_ZAKT,'
      '    IDBASE_RGZAKT,'
      '    PRSK_CARD_RGZAKT,'
      '    PRSK_AUTO_RGZAKT'
      ')'
      'VALUES('
      '    :ID_ZAKT,'
      '    :IDZ_ZAKT,'
      '    :IDNOM_ZAKT,'
      '    :IDED_ZAKT,'
      '    :IDMPRIG_ZAKT,'
      '    :KOLPR_ZAKT,'
      '    :KOLOT_ZAKT,'
      '    :KOLZ_ZAKT,'
      '    :KF_ZAKT,'
      '    :PRICE_ZAKT,'
      '    :SUM_ZAKT,'
      '    :OTKAZ_ZAKT,'
      '    :PRSK_ZAKT,'
      '    :PRNAD_ZAKT,'
      '    :SUMSK_ZAKT,'
      '    :SUMNAD_ZAKT,'
      '    :IDBASE_RGZAKT,'
      '    :PRSK_CARD_RGZAKT,'
      '    :PRSK_AUTO_RGZAKT'
      ')')
    RefreshSQL.Strings = (
      
        'select RGZAKT.*, NAMENOM, KRNAMENOM,NAMEED ,TNOM,  ZNACH_PRICE, ' +
        'NAME_MPRIG'
      'from '
      'RGZAKT LEFT OUTER JOIN SNOM  ON IDNOM_ZAKT=IDNOM '
      'left outer join SED  on  IDED_ZAKT=IDED'
      'left outer join SMPRIG on  IDMPRIG_ZAKT=ID_MPRIG '
      
        'left outer join SPRICE on IDNOM=IDNOM_PRICE AND IDTYPE_PRICE=:PA' +
        'RAM_ID_TYPE_PRICE'
      ''
      'where(  '
      '  IDZ_ZAKT=:IDZAK'
      '     ) and (     RGZAKT.ID_ZAKT = :OLD_ID_ZAKT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      
        'select RGZAKT.*, NAMENOM, KRNAMENOM,NAMEED ,TNOM,  ZNACH_PRICE, ' +
        'NAME_MPRIG'
      'from '
      'RGZAKT LEFT OUTER JOIN SNOM  ON IDNOM_ZAKT=IDNOM '
      'left outer join SED  on  IDED_ZAKT=IDED'
      'left outer join SMPRIG on  IDMPRIG_ZAKT=ID_MPRIG '
      
        'left outer join SPRICE on IDNOM=IDNOM_PRICE AND IDTYPE_PRICE=:PA' +
        'RAM_ID_TYPE_PRICE'
      ''
      'where '
      '  IDZ_ZAKT=:IDZAK'
      'order by ID_ZAKT')
    AutoUpdateOptions.UpdateTableName = 'RGZAKT'
    AutoUpdateOptions.KeyFields = 'ID_ZAKT'
    AutoUpdateOptions.GeneratorName = 'GEN_RGZAKT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    AfterDelete = DocTAfterDelete
    BeforeDelete = DocTBeforeDelete
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 72
    object DocTKOLPR_ZAKT: TFIBBCDField
      FieldName = 'KOLPR_ZAKT'
      DisplayFormat = '#.###'
      Size = 3
      RoundByScale = True
    end
    object DocTKOLOT_ZAKT: TFIBBCDField
      FieldName = 'KOLOT_ZAKT'
      OnChange = DocTKOLOT_ZAKTChange
      DisplayFormat = '#.###'
      Size = 3
      RoundByScale = True
    end
    object DocTKOLZ_ZAKT: TFIBBCDField
      FieldName = 'KOLZ_ZAKT'
      DisplayFormat = '#.###'
      Size = 3
      RoundByScale = True
    end
    object DocTKF_ZAKT: TFIBBCDField
      FieldName = 'KF_ZAKT'
      OnChange = DocTKF_ZAKTChange
      Size = 3
      RoundByScale = True
    end
    object DocTPRICE_ZAKT: TFIBBCDField
      FieldName = 'PRICE_ZAKT'
      OnChange = DocTPRICE_ZAKTChange
      Size = 2
      RoundByScale = True
    end
    object DocTSUM_ZAKT: TFIBBCDField
      FieldName = 'SUM_ZAKT'
      Size = 2
      RoundByScale = True
    end
    object DocTOTKAZ_ZAKT: TFIBBCDField
      FieldName = 'OTKAZ_ZAKT'
      DisplayFormat = '0.0'
      Size = 3
      RoundByScale = True
    end
    object DocTTNOM: TFIBIntegerField
      FieldName = 'TNOM'
    end
    object DocTZNACH_PRICE: TFIBBCDField
      FieldName = 'ZNACH_PRICE'
      Size = 2
      RoundByScale = True
    end
    object DocTRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object DocTPRSK_ZAKT: TFIBBCDField
      FieldName = 'PRSK_ZAKT'
      OnChange = DocTPRSK_ZAKTChange
      Size = 2
      RoundByScale = True
    end
    object DocTPRNAD_ZAKT: TFIBBCDField
      FieldName = 'PRNAD_ZAKT'
      OnChange = DocTPRNAD_ZAKTChange
      Size = 2
      RoundByScale = True
    end
    object DocTSUMSK_ZAKT: TFIBBCDField
      FieldName = 'SUMSK_ZAKT'
      Size = 2
      RoundByScale = True
    end
    object DocTSUMNAD_ZAKT: TFIBBCDField
      FieldName = 'SUMNAD_ZAKT'
      Size = 2
      RoundByScale = True
    end
    object DocTID_ZAKT: TFIBBCDField
      FieldName = 'ID_ZAKT'
      Size = 0
      RoundByScale = True
    end
    object DocTIDZ_ZAKT: TFIBBCDField
      FieldName = 'IDZ_ZAKT'
      Size = 0
      RoundByScale = True
    end
    object DocTIDNOM_ZAKT: TFIBBCDField
      FieldName = 'IDNOM_ZAKT'
      Size = 0
      RoundByScale = True
    end
    object DocTIDED_ZAKT: TFIBBCDField
      FieldName = 'IDED_ZAKT'
      Size = 0
      RoundByScale = True
    end
    object DocTIDMPRIG_ZAKT: TFIBBCDField
      FieldName = 'IDMPRIG_ZAKT'
      Size = 0
      RoundByScale = True
    end
    object DocTIDBASE_RGZAKT: TFIBBCDField
      FieldName = 'IDBASE_RGZAKT'
      Size = 0
      RoundByScale = True
    end
    object DocTPRSK_CARD_RGZAKT: TFIBBCDField
      FieldName = 'PRSK_CARD_RGZAKT'
      Size = 2
      RoundByScale = True
    end
    object DocTPRSK_AUTO_RGZAKT: TFIBBCDField
      FieldName = 'PRSK_AUTO_RGZAKT'
      Size = 2
      RoundByScale = True
    end
    object DocTNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 100
    end
    object DocTKRNAMENOM: TFIBWideStringField
      FieldName = 'KRNAMENOM'
      Size = 40
    end
    object DocTNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
    end
    object DocTNAME_MPRIG: TFIBWideStringField
      FieldName = 'NAME_MPRIG'
      Size = 100
    end
  end
  object Ob: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from SSTROB'
      'where ID_STROB=:ID')
    Transaction = IBTr
    Left = 152
    Top = 136
    object ObGRP_STROB: TFIBSmallIntField
      FieldName = 'GRP_STROB'
    end
    object ObID_STROB: TFIBBCDField
      FieldName = 'ID_STROB'
      Size = 0
      RoundByScale = True
    end
    object ObIDGRP_STROB: TFIBBCDField
      FieldName = 'IDGRP_STROB'
      Size = 0
      RoundByScale = True
    end
    object ObNAME_STROB: TFIBWideStringField
      FieldName = 'NAME_STROB'
      Size = 100
    end
    object ObCODE_STROB: TFIBIntegerField
      FieldName = 'CODE_STROB'
    end
    object ObGID_SSTROB: TFIBWideStringField
      FieldName = 'GID_SSTROB'
      Size = 10
    end
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from RGZAK')
    Transaction = IBTr
    Left = 272
    Top = 168
    object TableSUM_ZAK: TFIBBCDField
      FieldName = 'SUM_ZAK'
      Size = 2
      RoundByScale = True
    end
    object TableSOST_ZAK: TFIBSmallIntField
      FieldName = 'SOST_ZAK'
    end
    object TableID_ZAK: TFIBBCDField
      FieldName = 'ID_ZAK'
      Size = 0
      RoundByScale = True
    end
    object TableIDOB_ZAK: TFIBBCDField
      FieldName = 'IDOB_ZAK'
      Size = 0
      RoundByScale = True
    end
    object TableIDKLIENT_ZAK: TFIBBCDField
      FieldName = 'IDKLIENT_ZAK'
      Size = 0
      RoundByScale = True
    end
    object TableIDUSER_ZAK: TFIBBCDField
      FieldName = 'IDUSER_ZAK'
      Size = 0
      RoundByScale = True
    end
  end
  object IBQPrint: TpFIBDataSet
    SelectSQL.Strings = (
      'select '
      
        '  ID_ZAKT, KF_ZAKT, KOLZ_ZAKT, KOLPR_ZAKT, OTKAZ_ZAKT, KRNAMENOM' +
        ', NAMEED, IDMPRIG_ZAKT'
      'from '
      '  RGZAKT '
      'LEFT OUTER JOIN SNOM  ON IDNOM_ZAKT=IDNOM '
      'left outer join SED  on  IDED_ZAKT=IDED'
      ''
      
        'where IDZ_ZAKT=:PARAM_IDZAK AND (KOLPR_ZAKT IS NULL OR KOLZ_ZAKT' +
        '-OTKAZ_ZAKT!=KOLPR_ZAKT)'
      'order by'
      '  IDMPRIG_ZAKT')
    Transaction = IBTr
    Left = 352
    Top = 40
    object IBQPrintKF_ZAKT: TFIBBCDField
      FieldName = 'KF_ZAKT'
      Size = 3
      RoundByScale = True
    end
    object IBQPrintKOLZ_ZAKT: TFIBBCDField
      FieldName = 'KOLZ_ZAKT'
      Size = 3
      RoundByScale = True
    end
    object IBQPrintKOLPR_ZAKT: TFIBBCDField
      FieldName = 'KOLPR_ZAKT'
      Size = 3
      RoundByScale = True
    end
    object IBQPrintOTKAZ_ZAKT: TFIBBCDField
      FieldName = 'OTKAZ_ZAKT'
      Size = 3
      RoundByScale = True
    end
    object IBQPrintID_ZAKT: TFIBBCDField
      FieldName = 'ID_ZAKT'
      Size = 0
      RoundByScale = True
    end
    object IBQPrintIDMPRIG_ZAKT: TFIBBCDField
      FieldName = 'IDMPRIG_ZAKT'
      Size = 0
      RoundByScale = True
    end
    object IBQPrintKRNAMENOM: TFIBWideStringField
      FieldName = 'KRNAMENOM'
      Size = 40
    end
    object IBQPrintNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
    end
  end
  object IBQMPrig: TpFIBDataSet
    SelectSQL.Strings = (
      'select '
      'NAME_MPRIG, COMPNAME_OBORUD, COMNAME_OBORUD, BAUDRATE_OBORUD'
      'from'
      '  SMPRIG'
      '  left outer join SOBORUD on IDOBORUD_MPRIG=ID_OBORUD'
      'where'
      '  ID_MPRIG=:PARAM_ID_MPRIG')
    Transaction = IBTr
    Left = 352
    Top = 96
    object IBQMPrigNAME_MPRIG: TFIBWideStringField
      FieldName = 'NAME_MPRIG'
      Size = 100
    end
    object IBQMPrigCOMPNAME_OBORUD: TFIBWideStringField
      FieldName = 'COMPNAME_OBORUD'
      Size = 10
    end
    object IBQMPrigCOMNAME_OBORUD: TFIBWideStringField
      FieldName = 'COMNAME_OBORUD'
      Size = 5
    end
    object IBQMPrigBAUDRATE_OBORUD: TFIBWideStringField
      FieldName = 'BAUDRATE_OBORUD'
      Size = 10
    end
  end
  object IBQNom: TpFIBDataSet
    SelectSQL.Strings = (
      'select SNOM.* , NAME_MPRIG'
      ''
      'from '
      '  SNOM'
      'left outer join SNOMREST on  IDNOM_NOMREST=IDNOM'
      'left outer join SMPRIG on IDMPRIG_NOMREST=ID_MPRIG'
      'where'
      ' IDNOM=:PARAM_IDNOM')
    Transaction = IBTr
    Left = 352
    Top = 168
    object IBQNomNAME_MPRIG: TFIBWideStringField
      FieldName = 'NAME_MPRIG'
      Size = 100
    end
  end
end
