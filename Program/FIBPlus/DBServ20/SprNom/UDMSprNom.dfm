object DMSprNom: TDMSprNom
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 403
  Width = 371
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 8
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 56
    Top = 64
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      
        'select IDNOM,ARTNOM,CODENOM, TNOM, NAMENOM, NAMEED, ZNACH_PRICE,' +
        ' IDGRPNOM, sum(rgostnom.kolostnom) AS SUMKOL'
      'from SNOM'
      
        ' left outer join SPRICE on IDNOM_PRICE=IDNOM AND IDTYPE_PRICE=:P' +
        'ARAM_IDTPRICE'
      ' left outer join SED on IDBASEDNOM=IDED'
      ' left outer join rgostnom on snom.idnom=rgostnom.idnomostnom'
      
        'and rgostnom.idfirmostnom=:PARAM_IDFIRM and rgostnom.idsklostnom' +
        '=:PARAM_IDSKLAD'
      
        ' group by IDNOM,ARTNOM, CODENOM, TNOM, NAMENOM, NAMEED, ZNACH_PR' +
        'ICE, IDGRPNOM'
      'ORDER BY NAMENOM')
    AfterScroll = TableAfterScroll
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 160
    Top = 16
    object TableCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object TableTNOM: TFIBIntegerField
      FieldName = 'TNOM'
    end
    object TableNAMENOM: TFIBStringField
      FieldName = 'NAMENOM'
      Size = 100
      EmptyStrToNull = True
    end
    object TableNAMEED: TFIBStringField
      FieldName = 'NAMEED'
      Size = 100
      EmptyStrToNull = True
    end
    object TableZNACH_PRICE: TFIBBCDField
      FieldName = 'ZNACH_PRICE'
      Size = 2
      RoundByScale = True
    end
    object TableSUMKOL: TFIBBCDField
      FieldName = 'SUMKOL'
      Size = 3
      RoundByScale = True
    end
    object TableARTNOM: TFIBStringField
      FieldName = 'ARTNOM'
      EmptyStrToNull = True
    end
    object TableIDNOM: TFIBBCDField
      FieldName = 'IDNOM'
      Size = 0
      RoundByScale = True
    end
    object TableIDGRPNOM: TFIBBCDField
      FieldName = 'IDGRPNOM'
      Size = 0
      RoundByScale = True
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SNOM'
      'SET '
      '    TNOM = :TNOM,'
      '    CODENOM = :CODENOM,'
      '    NAMENOM = :NAMENOM,'
      '    FNAMENOM = :FNAMENOM,'
      '    KRNAMENOM = :KRNAMENOM,'
      '    IDBASEDNOM = :IDBASEDNOM,'
      '    IDOSNEDNOM = :IDOSNEDNOM,'
      '    IDFISED_SNOM = :IDFISED_SNOM,'
      '    IDGRPNOM = :IDGRPNOM,'
      '    ARTNOM = :ARTNOM,'
      '    GID_SNOM = :GID_SNOM,'
      '    DESCR_SNOM = :DESCR_SNOM,'
      '    IDFIRMNOM = :IDFIRMNOM,'
      '    STNDSNOM = :STNDSNOM,'
      '    GTDNOM = :GTDNOM,'
      '    IDCOUNTRYNOM = :IDCOUNTRYNOM,'
      '    FL_CHANGE_NOM = :FL_CHANGE_NOM,'
      '    MINOSTNOM = :MINOSTNOM,'
      '    IDBASE_SNOM = :IDBASE_SNOM,'
      '    SKIDKA1_SNOM = :SKIDKA1_SNOM,'
      '    SKIDKA2_SNOM = :SKIDKA2_SNOM,'
      '    SKIDKA3_SNOM = :SKIDKA3_SNOM,'
      '    IDVID_SNOM = :IDVID_SNOM,'
      '    TYPESRGODN_SNOM = :TYPESRGODN_SNOM,'
      '    SRGODN_SNOM = :SRGODN_SNOM,'
      '    GODEN_DO_SNOM = :GODEN_DO_SNOM,'
      '    IDSUPPLIER_SNOM = :IDSUPPLIER_SNOM,'
      '    IDPRODUCER_SNOM = :IDPRODUCER_SNOM,'
      '    POGR_SNOM = :POGR_SNOM,'
      '    WARRANTY_SNOM = :WARRANTY_SNOM,'
      '    FL_CREDIT_SNOM = :FL_CREDIT_SNOM,'
      '    FL_TRANSPORT_SNOM = :FL_TRANSPORT_SNOM,'
      '    IDBRAND_SNOM = :IDBRAND_SNOM'
      'WHERE'
      '    IDNOM = :OLD_IDNOM'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SNOM'
      'WHERE'
      '        IDNOM = :OLD_IDNOM'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SNOM('
      '    IDNOM,'
      '    TNOM,'
      '    CODENOM,'
      '    NAMENOM,'
      '    FNAMENOM,'
      '    KRNAMENOM,'
      '    IDBASEDNOM,'
      '    IDOSNEDNOM,'
      '    IDFISED_SNOM,'
      '    IDGRPNOM,'
      '    ARTNOM,'
      '    GID_SNOM,'
      '    DESCR_SNOM,'
      '    IDFIRMNOM,'
      '    STNDSNOM,'
      '    GTDNOM,'
      '    IDCOUNTRYNOM,'
      '    FL_CHANGE_NOM,'
      '    MINOSTNOM,'
      '    IDBASE_SNOM,'
      '    SKIDKA1_SNOM,'
      '    SKIDKA2_SNOM,'
      '    SKIDKA3_SNOM,'
      '    IDVID_SNOM,'
      '    TYPESRGODN_SNOM,'
      '    SRGODN_SNOM,'
      '    GODEN_DO_SNOM,'
      '    IDSUPPLIER_SNOM,'
      '    IDPRODUCER_SNOM,'
      '    POGR_SNOM,'
      '    WARRANTY_SNOM,'
      '    FL_CREDIT_SNOM,'
      '    FL_TRANSPORT_SNOM,'
      '    IDBRAND_SNOM'
      ')'
      'VALUES('
      '    :IDNOM,'
      '    :TNOM,'
      '    :CODENOM,'
      '    :NAMENOM,'
      '    :FNAMENOM,'
      '    :KRNAMENOM,'
      '    :IDBASEDNOM,'
      '    :IDOSNEDNOM,'
      '    :IDFISED_SNOM,'
      '    :IDGRPNOM,'
      '    :ARTNOM,'
      '    :GID_SNOM,'
      '    :DESCR_SNOM,'
      '    :IDFIRMNOM,'
      '    :STNDSNOM,'
      '    :GTDNOM,'
      '    :IDCOUNTRYNOM,'
      '    :FL_CHANGE_NOM,'
      '    :MINOSTNOM,'
      '    :IDBASE_SNOM,'
      '    :SKIDKA1_SNOM,'
      '    :SKIDKA2_SNOM,'
      '    :SKIDKA3_SNOM,'
      '    :IDVID_SNOM,'
      '    :TYPESRGODN_SNOM,'
      '    :SRGODN_SNOM,'
      '    :GODEN_DO_SNOM,'
      '    :IDSUPPLIER_SNOM,'
      '    :IDPRODUCER_SNOM,'
      '    :POGR_SNOM,'
      '    :WARRANTY_SNOM,'
      '    :FL_CREDIT_SNOM,'
      '    :FL_TRANSPORT_SNOM,'
      '    :IDBRAND_SNOM'
      ')')
    RefreshSQL.Strings = (
      
        'select SNOM.*,  ZNACH_PRICE, NAMEFIRM, NAME_SCOUNTRY, NAME_SVIDN' +
        'OM,'
      '    SUPPLIER.NAMEKLIENT as SUPPLIER_NAME,'
      '    PRODUCER.NAMEKLIENT as PRODUCER_NAME,'
      '    NAME_SBRAND'
      'from SNOM'
      
        ' left outer join SPRICE on IDNOM_PRICE=IDNOM AND IDTYPE_PRICE=:P' +
        'ARAM_IDTYPE_PRICE'
      '      and IDED_SPRICE=IDBASEDNOM'
      'left outer join SFIRM on IDFIRM=IDFIRMNOM'
      'left outer join SCOUNTRY on IDCOUNTRYNOM=ID_SCOUNTRY'
      'left outer join SVIDNOM on IDVID_SNOM=ID_SVIDNOM'
      
        'left outer join sklient as SUPPLIER on snom.idsupplier_snom=SUPP' +
        'LIER.IDKLIENT'
      
        'left outer join sklient as PRODUCER on snom.idproducer_snom=PROD' +
        'UCER.IDKLIENT'
      'left outer join sbrand on ID_SBRAND=IDBRAND_SNOM'
      'where(  IDNOM=:ID'
      '     ) and (     SNOM.IDNOM = :OLD_IDNOM'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select '
      '    snom.*,'
      '    ZNACH_PRICE,'
      '    NAMEFIRM,'
      '    NAME_SCOUNTRY,'
      '    NAME_SVIDNOM,'
      '    SUPPLIER.NAMEKLIENT as SUPPLIER_NAME,'
      '    PRODUCER.NAMEKLIENT as PRODUCER_NAME,'
      '    NAME_SBRAND'
      'from SNOM'
      
        ' left outer join SPRICE on IDNOM_PRICE=IDNOM AND IDTYPE_PRICE=:P' +
        'ARAM_IDTYPE_PRICE'
      '      and IDED_SPRICE=IDBASEDNOM'
      'left outer join SFIRM on IDFIRM=IDFIRMNOM'
      'left outer join SCOUNTRY on IDCOUNTRYNOM=ID_SCOUNTRY'
      'left outer join SVIDNOM on IDVID_SNOM=ID_SVIDNOM'
      
        'left outer join sklient as SUPPLIER on snom.idsupplier_snom=SUPP' +
        'LIER.IDKLIENT'
      
        'left outer join sklient as PRODUCER on snom.idproducer_snom=PROD' +
        'UCER.IDKLIENT'
      'left outer join sbrand on ID_SBRAND=IDBRAND_SNOM'
      'where IDNOM=:ID')
    AutoUpdateOptions.UpdateTableName = 'SNOM'
    AutoUpdateOptions.KeyFields = 'IDNOM'
    AutoUpdateOptions.GeneratorName = 'GEN_SNOM_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    Database = DM.pFIBData
    UpdateTransaction = IBTrUpdate
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object ElementTNOM: TFIBIntegerField
      FieldName = 'TNOM'
    end
    object ElementCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object ElementFNAMENOM: TFIBStringField
      FieldName = 'FNAMENOM'
      Size = 100
      EmptyStrToNull = True
    end
    object ElementKRNAMENOM: TFIBStringField
      FieldName = 'KRNAMENOM'
      Size = 40
      EmptyStrToNull = True
    end
    object ElementARTNOM: TFIBStringField
      FieldName = 'ARTNOM'
      EmptyStrToNull = True
    end
    object ElementDESCR_SNOM: TFIBStringField
      FieldName = 'DESCR_SNOM'
      Size = 250
      EmptyStrToNull = True
    end
    object ElementSTNDSNOM: TFIBIntegerField
      FieldName = 'STNDSNOM'
    end
    object ElementGTDNOM: TFIBStringField
      FieldName = 'GTDNOM'
      Size = 30
      EmptyStrToNull = True
    end
    object ElementZNACH_PRICE: TFIBBCDField
      FieldName = 'ZNACH_PRICE'
      Size = 2
      RoundByScale = True
    end
    object ElementNAMEFIRM: TFIBStringField
      FieldName = 'NAMEFIRM'
      Size = 50
      EmptyStrToNull = True
    end
    object ElementNAME_SCOUNTRY: TFIBStringField
      FieldName = 'NAME_SCOUNTRY'
      Size = 100
      EmptyStrToNull = True
    end
    object ElementFL_CHANGE_NOM: TFIBSmallIntField
      FieldName = 'FL_CHANGE_NOM'
    end
    object ElementMINOSTNOM: TFIBBCDField
      FieldName = 'MINOSTNOM'
      Size = 3
      RoundByScale = True
    end
    object ElementGID_SNOM: TFIBStringField
      FieldName = 'GID_SNOM'
      Size = 10
      EmptyStrToNull = True
    end
    object ElementSKIDKA1_SNOM: TFIBBCDField
      FieldName = 'SKIDKA1_SNOM'
      Size = 2
      RoundByScale = True
    end
    object ElementSKIDKA2_SNOM: TFIBBCDField
      FieldName = 'SKIDKA2_SNOM'
      Size = 2
      RoundByScale = True
    end
    object ElementSKIDKA3_SNOM: TFIBBCDField
      FieldName = 'SKIDKA3_SNOM'
      Size = 2
      RoundByScale = True
    end
    object ElementNAME_SVIDNOM: TFIBStringField
      FieldName = 'NAME_SVIDNOM'
      Size = 100
      EmptyStrToNull = True
    end
    object ElementTYPESRGODN_SNOM: TFIBSmallIntField
      FieldName = 'TYPESRGODN_SNOM'
    end
    object ElementSRGODN_SNOM: TFIBSmallIntField
      FieldName = 'SRGODN_SNOM'
    end
    object ElementGODEN_DO_SNOM: TFIBDateTimeField
      FieldName = 'GODEN_DO_SNOM'
      DisplayFormat = 'c'
    end
    object ElementSUPPLIER_NAME: TFIBStringField
      FieldName = 'SUPPLIER_NAME'
      Size = 100
      EmptyStrToNull = True
    end
    object ElementPRODUCER_NAME: TFIBStringField
      FieldName = 'PRODUCER_NAME'
      Size = 100
      EmptyStrToNull = True
    end
    object ElementNAMENOM: TFIBStringField
      FieldName = 'NAMENOM'
      Size = 100
      EmptyStrToNull = True
    end
    object ElementWARRANTY_SNOM: TFIBIntegerField
      FieldName = 'WARRANTY_SNOM'
    end
    object ElementFL_CREDIT_SNOM: TFIBSmallIntField
      FieldName = 'FL_CREDIT_SNOM'
    end
    object ElementFL_TRANSPORT_SNOM: TFIBSmallIntField
      FieldName = 'FL_TRANSPORT_SNOM'
    end
    object ElementNAME_SBRAND: TFIBStringField
      FieldName = 'NAME_SBRAND'
      Size = 100
      EmptyStrToNull = True
    end
    object ElementPOGR_SNOM: TFIBBCDField
      FieldName = 'POGR_SNOM'
      Size = 3
      RoundByScale = True
    end
    object ElementIDNOM: TFIBLargeIntField
      FieldName = 'IDNOM'
    end
    object ElementIDBASEDNOM: TFIBLargeIntField
      FieldName = 'IDBASEDNOM'
    end
    object ElementIDOSNEDNOM: TFIBLargeIntField
      FieldName = 'IDOSNEDNOM'
    end
    object ElementIDFISED_SNOM: TFIBLargeIntField
      FieldName = 'IDFISED_SNOM'
    end
    object ElementIDGRPNOM: TFIBLargeIntField
      FieldName = 'IDGRPNOM'
    end
    object ElementIDFIRMNOM: TFIBLargeIntField
      FieldName = 'IDFIRMNOM'
    end
    object ElementIDCOUNTRYNOM: TFIBLargeIntField
      FieldName = 'IDCOUNTRYNOM'
    end
    object ElementIDVID_SNOM: TFIBLargeIntField
      FieldName = 'IDVID_SNOM'
    end
    object ElementIDSUPPLIER_SNOM: TFIBLargeIntField
      FieldName = 'IDSUPPLIER_SNOM'
    end
    object ElementIDPRODUCER_SNOM: TFIBLargeIntField
      FieldName = 'IDPRODUCER_SNOM'
    end
    object ElementIDBRAND_SNOM: TFIBLargeIntField
      FieldName = 'IDBRAND_SNOM'
    end
  end
  object IBTr: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    CSMonitorSupport.Enabled = csmeDatabaseDriven
    TPBMode = tpbDefault
    Left = 256
    Top = 16
  end
  object IBTrUpdate: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    CSMonitorSupport.Enabled = csmeDatabaseDriven
    TPBMode = tpbDefault
    Left = 256
    Top = 64
  end
  object BasEd: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from SED where IDED=:IDBASED')
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 112
    Top = 176
    object BasEdNAMEED: TFIBStringField
      FieldName = 'NAMEED'
      Size = 50
      EmptyStrToNull = True
    end
    object BasEdKFED: TFIBBCDField
      FieldName = 'KFED'
      Size = 3
      RoundByScale = True
    end
    object BasEdTSHED: TFIBIntegerField
      FieldName = 'TSHED'
    end
    object BasEdSHED: TFIBStringField
      FieldName = 'SHED'
      Size = 13
      EmptyStrToNull = True
    end
    object BasEdNEISPED: TFIBSmallIntField
      FieldName = 'NEISPED'
    end
    object BasEdIDED: TFIBBCDField
      FieldName = 'IDED'
      Size = 0
      RoundByScale = True
    end
    object BasEdIDNOMED: TFIBBCDField
      FieldName = 'IDNOMED'
      Size = 0
      RoundByScale = True
    end
    object BasEdIDOKEIED: TFIBBCDField
      FieldName = 'IDOKEIED'
      Size = 0
      RoundByScale = True
    end
    object BasEdCODE_SED: TFIBIntegerField
      FieldName = 'CODE_SED'
    end
    object BasEdKF2_SED: TFIBBCDField
      FieldName = 'KF2_SED'
      Size = 3
      RoundByScale = True
    end
    object BasEdVES_SED: TFIBBCDField
      FieldName = 'VES_SED'
      Size = 3
      RoundByScale = True
    end
  end
  object OsnEd: TpFIBDataSet
    SelectSQL.Strings = (
      'select  * from SED where IDED=:IDOSNED')
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 112
    Top = 224
    object OsnEdNAMEED: TFIBStringField
      FieldName = 'NAMEED'
      Size = 50
      EmptyStrToNull = True
    end
    object OsnEdKFED: TFIBBCDField
      FieldName = 'KFED'
      Size = 3
      RoundByScale = True
    end
    object OsnEdTSHED: TFIBIntegerField
      FieldName = 'TSHED'
    end
    object OsnEdSHED: TFIBStringField
      FieldName = 'SHED'
      Size = 13
      EmptyStrToNull = True
    end
    object OsnEdNEISPED: TFIBSmallIntField
      FieldName = 'NEISPED'
    end
    object OsnEdIDED: TFIBBCDField
      FieldName = 'IDED'
      Size = 0
      RoundByScale = True
    end
    object OsnEdIDNOMED: TFIBBCDField
      FieldName = 'IDNOMED'
      Size = 0
      RoundByScale = True
    end
    object OsnEdIDOKEIED: TFIBBCDField
      FieldName = 'IDOKEIED'
      Size = 0
      RoundByScale = True
    end
    object OsnEdCODE_SED: TFIBIntegerField
      FieldName = 'CODE_SED'
    end
    object OsnEdKF2_SED: TFIBBCDField
      FieldName = 'KF2_SED'
      Size = 3
      RoundByScale = True
    end
    object OsnEdVES_SED: TFIBBCDField
      FieldName = 'VES_SED'
      Size = 3
      RoundByScale = True
    end
  end
  object IBQSprGrpBV: TpFIBDataSet
    SelectSQL.Strings = (
      'select NAMEPOD, IDPOD_GBVNOM, ID_GBVNOM, NAME_GBVNOM'
      'from SGBVNOM '
      'left outer join SPOD  on IDPOD=IDPOD_GBVNOM'
      'order by NAMEPOD, NAME_GBVNOM')
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 256
    Top = 120
    object IBQSprGrpBVNAMEPOD: TFIBStringField
      FieldName = 'NAMEPOD'
      Size = 30
      EmptyStrToNull = True
    end
    object IBQSprGrpBVNAME_GBVNOM: TFIBStringField
      FieldName = 'NAME_GBVNOM'
      Size = 50
      EmptyStrToNull = True
    end
    object IBQSprGrpBVIDPOD_GBVNOM: TFIBBCDField
      FieldName = 'IDPOD_GBVNOM'
      Size = 0
      RoundByScale = True
    end
    object IBQSprGrpBVID_GBVNOM: TFIBBCDField
      FieldName = 'ID_GBVNOM'
      Size = 0
      RoundByScale = True
    end
  end
  object SpTPrice: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from STPRICE')
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 128
    Top = 120
    object SpTPriceNAME_TPRICE: TFIBStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
      EmptyStrToNull = True
    end
    object SpTPriceID_TPRICE: TFIBBCDField
      FieldName = 'ID_TPRICE'
      Size = 0
      RoundByScale = True
    end
  end
  object Code: TpFIBDataSet
    SelectSQL.Strings = (
      'select max(CODENOM) AS MAXCODE '
      'from  SNOM'
      'where CODENOM between  :PARAM_CODEMIN and :PARAM_CODEMAX')
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 176
    Top = 120
    object CodeMAXCODE: TFIBIntegerField
      FieldName = 'MAXCODE'
    end
  end
  object pFIBQuery: TpFIBQuery
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 184
    Top = 248
    qoStartTransaction = True
  end
  object pFIBTrUpdate: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    CSMonitorSupport.Enabled = csmeDatabaseDriven
    TPBMode = tpbDefault
    Left = 240
    Top = 248
  end
  object pFIBTr: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    CSMonitorSupport.Enabled = csmeDatabaseDriven
    TPBMode = tpbDefault
    Left = 320
    Top = 248
  end
  object SprScaleAndGrpVesNom: TpFIBDataSet
    SelectSQL.Strings = (
      
        'select NAME_SSCALE, IDSCALE_SGRPVESNOM, ID_SGRPVESNOM, NAME_SGRP' +
        'VESNOM'
      'from SGRPVESNOM'
      'left outer join SSCALE  on ID_SSCALE=IDSCALE_SGRPVESNOM'
      'order by NAME_SSCALE, NAME_SGRPVESNOM')
    Transaction = pFIBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 256
    Top = 168
    object SprScaleAndGrpVesNomNAME_SSCALE: TFIBStringField
      FieldName = 'NAME_SSCALE'
      Size = 50
      EmptyStrToNull = True
    end
    object SprScaleAndGrpVesNomIDSCALE_SGRPVESNOM: TFIBBCDField
      FieldName = 'IDSCALE_SGRPVESNOM'
      Size = 0
      RoundByScale = True
    end
    object SprScaleAndGrpVesNomID_SGRPVESNOM: TFIBBCDField
      FieldName = 'ID_SGRPVESNOM'
      Size = 0
      RoundByScale = True
    end
    object SprScaleAndGrpVesNomNAME_SGRPVESNOM: TFIBStringField
      FieldName = 'NAME_SGRPVESNOM'
      Size = 50
      EmptyStrToNull = True
    end
  end
  object FisEd: TpFIBDataSet
    SelectSQL.Strings = (
      'select  * from SED where IDED=:IDFISED')
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 112
    Top = 280
    object FIBStringField1: TFIBStringField
      FieldName = 'NAMEED'
      Size = 50
      EmptyStrToNull = True
    end
    object FIBBCDField1: TFIBBCDField
      FieldName = 'KFED'
      Size = 3
      RoundByScale = True
    end
    object FIBIntegerField1: TFIBIntegerField
      FieldName = 'TSHED'
    end
    object FIBStringField2: TFIBStringField
      FieldName = 'SHED'
      Size = 13
      EmptyStrToNull = True
    end
    object FIBSmallIntField1: TFIBSmallIntField
      FieldName = 'NEISPED'
    end
    object FIBBCDField2: TFIBBCDField
      FieldName = 'IDED'
      Size = 0
      RoundByScale = True
    end
    object FIBBCDField3: TFIBBCDField
      FieldName = 'IDNOMED'
      Size = 0
      RoundByScale = True
    end
    object FIBBCDField4: TFIBBCDField
      FieldName = 'IDOKEIED'
      Size = 0
      RoundByScale = True
    end
    object FisEdCODE_SED: TFIBIntegerField
      FieldName = 'CODE_SED'
    end
    object FisEdKF2_SED: TFIBBCDField
      FieldName = 'KF2_SED'
      Size = 3
      RoundByScale = True
    end
    object FisEdVES_SED: TFIBBCDField
      FieldName = 'VES_SED'
      Size = 3
      RoundByScale = True
    end
  end
  object SpisokEd: TpFIBDataSet
    SelectSQL.Strings = (
      'select sed.ided,'
      '        sed.nameed,'
      '        sed.kfed'
      'from SED'
      'where IDNOMED=:PARAM_IDNOM')
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 112
    Top = 336
    poUseLargeIntField = True
    object SpisokEdNAMEED: TFIBStringField
      FieldName = 'NAMEED'
      Size = 100
      EmptyStrToNull = True
    end
    object SpisokEdKFED: TFIBBCDField
      FieldName = 'KFED'
      Size = 3
      RoundByScale = True
    end
    object SpisokEdIDED: TFIBLargeIntField
      FieldName = 'IDED'
    end
  end
  object DataSourceSpisokEd: TDataSource
    DataSet = SpisokEd
    Left = 32
    Top = 336
  end
  object DataSourceBasEd: TDataSource
    DataSet = BasEd
    Left = 32
    Top = 176
  end
  object DataSourceOsnEd: TDataSource
    DataSet = OsnEd
    Left = 32
    Top = 224
  end
  object DataSourceFisEd: TDataSource
    DataSet = FisEd
    Left = 32
    Top = 272
  end
  object ClientDataSet1: TClientDataSet
    Aggregates = <>
    Params = <>
    Left = 264
    Top = 336
  end
end
