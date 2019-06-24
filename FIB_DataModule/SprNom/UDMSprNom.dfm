object DMSprNom: TDMSprNom
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 446
  Width = 438
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
      'select *'
      'from SNOM_GET_TABLE_FULL ('
      '    :PARAM_IDGRP,'
      '    :PARAM_FL_ALL_GRP,'
      '    :PARAM_IDFIRM,'
      '    :PARAM_FL_RASV_FIRM,'
      '    :PARAM_IDSKLAD,'
      '    :PARAM_FL_RASV_SKLAD,'
      '    :PARAM_IDTNOM,'
      '    :PARAM_FL_RASV_TNOM,'
      '    :PARAM_FL_PRICE_SKLAD,'
      '    :PARAM_FL_RASV_PRICE_PO_ED,'
      '    :PARAM_IDTYPE_PRICE,'
      '    :PARAM_FL_OST,'
      '    :PARAM_IDINET_CAT)')
    AfterScroll = TableAfterScroll
    Transaction = IBTr
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object TableIDNOM: TFIBLargeIntField
      FieldName = 'IDNOM'
    end
    object TableARTNOM: TFIBWideStringField
      FieldName = 'ARTNOM'
      Size = 40
    end
    object TableCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object TableTNOM: TFIBSmallIntField
      FieldName = 'TNOM'
    end
    object TableNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object TableNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 200
    end
    object TableZNACH_PRICE: TFIBBCDField
      FieldName = 'ZNACH_PRICE'
      Size = 2
      RoundByScale = True
    end
    object TableIDGRPNOM: TFIBLargeIntField
      FieldName = 'IDGRPNOM'
    end
    object TableID_SNOMINETCAT: TFIBLargeIntField
      FieldName = 'ID_SNOMINETCAT'
    end
    object TableSUMKOL: TFIBBCDField
      FieldName = 'SUMKOL'
      Size = 3
      RoundByScale = True
    end
    object TableSHED: TFIBWideStringField
      FieldName = 'SHED'
      Size = 13
    end
    object TableREM_OST: TFIBBCDField
      FieldName = 'REM_OST'
      Size = 3
      RoundByScale = True
    end
    object TableIDFIRM: TFIBLargeIntField
      FieldName = 'IDFIRM'
    end
    object TableNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 200
    end
    object TableIDSKLAD: TFIBLargeIntField
      FieldName = 'IDSKLAD'
    end
    object TableNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 200
    end
    object TableIDTNOM: TFIBLargeIntField
      FieldName = 'IDTNOM'
    end
    object TableNAME_STNOM: TFIBWideStringField
      FieldName = 'NAME_STNOM'
      Size = 200
    end
    object TableIDED: TFIBLargeIntField
      FieldName = 'IDED'
    end
    object TableOUT_PRICE_SKLAD: TFIBBCDField
      FieldName = 'OUT_PRICE_SKLAD'
      Size = 2
      RoundByScale = True
    end
    object TableOUT_KFED: TFIBBCDField
      FieldName = 'OUT_KFED'
      Size = 3
      RoundByScale = True
    end
    object TableOUT_KF2ED: TFIBBCDField
      FieldName = 'OUT_KF2ED'
      Size = 3
      RoundByScale = True
    end
    object TableOUT_IDMHRAN: TFIBLargeIntField
      FieldName = 'OUT_IDMHRAN'
    end
    object TableOUT_NAME_MHRAN: TFIBWideStringField
      FieldName = 'OUT_NAME_MHRAN'
      Size = 200
    end
    object TableOUT_IDMHRAN_REM: TFIBLargeIntField
      FieldName = 'OUT_IDMHRAN_REM'
    end
    object TableOUT_NAME_MHRAN_REM: TFIBWideStringField
      FieldName = 'OUT_NAME_MHRAN_REM'
      Size = 200
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
      '    IDBRAND_SNOM = :IDBRAND_SNOM,'
      '    FL_ADD_IN_SOBORUD_SNOM = :FL_ADD_IN_SOBORUD_SNOM,'
      '    FL_DVREG_SNOM = :FL_DVREG_SNOM,'
      '    IDVIDIMAGENABOR_SNOM = :IDVIDIMAGENABOR_SNOM,'
      '    IDPROPNABOR_SNOM = :IDPROPNABOR_SNOM,'
      '    IDDEPARTMENT_SNOM = :IDDEPARTMENT_SNOM'
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
      '    IDBRAND_SNOM,'
      '    FL_ADD_IN_SOBORUD_SNOM,'
      '    FL_DVREG_SNOM,'
      '    IDVIDIMAGENABOR_SNOM,'
      '    IDPROPNABOR_SNOM,'
      '    IDDEPARTMENT_SNOM'
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
      '    :IDBRAND_SNOM,'
      '    :FL_ADD_IN_SOBORUD_SNOM,'
      '    :FL_DVREG_SNOM,'
      '    :IDVIDIMAGENABOR_SNOM,'
      '    :IDPROPNABOR_SNOM,'
      '    :IDDEPARTMENT_SNOM'
      ')')
    RefreshSQL.Strings = (
      'select '
      '    snom.*,'
      '    ZNACH_PRICE,'
      '    NAMEFIRM,'
      '    NAME_SCOUNTRY,'
      '    NAME_SVIDNOM,'
      '    SUPPLIER.NAMEKLIENT as SUPPLIER_NAME,'
      '    PRODUCER.NAMEKLIENT as PRODUCER_NAME,'
      '    NAME_SBRAND,'
      '    sdepartment.name_sdepartment,'
      '    spropnabor.name_spropnabor,'
      '    svidimage_nabor.name_svidimage_nabor'
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
      
        'left outer join sdepartment on sdepartment.id_sdepartment=snom.i' +
        'ddepartment_snom'
      
        'left outer join spropnabor on spropnabor.id_spropnabor=snom.idpr' +
        'opnabor_snom'
      
        'left outer join svidimage_nabor on svidimage_nabor.id_svidimage_' +
        'nabor=snom.idvidimagenabor_snom'
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
      '    NAME_SBRAND,'
      '    sdepartment.name_sdepartment,'
      '    spropnabor.name_spropnabor,'
      '    svidimage_nabor.name_svidimage_nabor'
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
      
        'left outer join sdepartment on sdepartment.id_sdepartment=snom.i' +
        'ddepartment_snom'
      
        'left outer join spropnabor on spropnabor.id_spropnabor=snom.idpr' +
        'opnabor_snom'
      
        'left outer join svidimage_nabor on svidimage_nabor.id_svidimage_' +
        'nabor=snom.idvidimagenabor_snom'
      'where IDNOM=:ID')
    AutoUpdateOptions.UpdateTableName = 'SNOM'
    AutoUpdateOptions.KeyFields = 'IDNOM'
    AutoUpdateOptions.GeneratorName = 'GEN_SNOM_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object ElementTNOM: TFIBIntegerField
      FieldName = 'TNOM'
    end
    object ElementCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object ElementSTNDSNOM: TFIBIntegerField
      FieldName = 'STNDSNOM'
    end
    object ElementZNACH_PRICE: TFIBBCDField
      FieldName = 'ZNACH_PRICE'
      Size = 2
      RoundByScale = True
    end
    object ElementFL_CHANGE_NOM: TFIBSmallIntField
      FieldName = 'FL_CHANGE_NOM'
    end
    object ElementMINOSTNOM: TFIBBCDField
      FieldName = 'MINOSTNOM'
      Size = 3
      RoundByScale = True
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
    object ElementWARRANTY_SNOM: TFIBIntegerField
      FieldName = 'WARRANTY_SNOM'
    end
    object ElementFL_CREDIT_SNOM: TFIBSmallIntField
      FieldName = 'FL_CREDIT_SNOM'
    end
    object ElementFL_TRANSPORT_SNOM: TFIBSmallIntField
      FieldName = 'FL_TRANSPORT_SNOM'
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
    object ElementNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object ElementFNAMENOM: TFIBWideStringField
      FieldName = 'FNAMENOM'
      Size = 200
    end
    object ElementKRNAMENOM: TFIBWideStringField
      FieldName = 'KRNAMENOM'
      Size = 40
    end
    object ElementARTNOM: TFIBWideStringField
      FieldName = 'ARTNOM'
      Size = 40
    end
    object ElementDESCR_SNOM: TFIBWideStringField
      FieldName = 'DESCR_SNOM'
      Size = 250
    end
    object ElementGTDNOM: TFIBWideStringField
      FieldName = 'GTDNOM'
      Size = 40
    end
    object ElementIDBASE_SNOM: TFIBLargeIntField
      FieldName = 'IDBASE_SNOM'
    end
    object ElementIDEXT_DOUT_SNOM: TFIBLargeIntField
      FieldName = 'IDEXT_DOUT_SNOM'
    end
    object ElementIDEXT_BASE_SNOM: TFIBLargeIntField
      FieldName = 'IDEXT_BASE_SNOM'
    end
    object ElementNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 200
    end
    object ElementNAME_SCOUNTRY: TFIBWideStringField
      FieldName = 'NAME_SCOUNTRY'
      Size = 200
    end
    object ElementNAME_SVIDNOM: TFIBWideStringField
      FieldName = 'NAME_SVIDNOM'
      Size = 200
    end
    object ElementSUPPLIER_NAME: TFIBWideStringField
      FieldName = 'SUPPLIER_NAME'
      Size = 200
    end
    object ElementPRODUCER_NAME: TFIBWideStringField
      FieldName = 'PRODUCER_NAME'
      Size = 200
    end
    object ElementNAME_SBRAND: TFIBWideStringField
      FieldName = 'NAME_SBRAND'
      Size = 200
    end
    object ElementGID_SNOM: TFIBWideStringField
      FieldName = 'GID_SNOM'
      Size = 10
    end
    object ElementFL_ADD_IN_SOBORUD_SNOM: TFIBSmallIntField
      FieldName = 'FL_ADD_IN_SOBORUD_SNOM'
    end
    object ElementFL_DVREG_SNOM: TFIBSmallIntField
      FieldName = 'FL_DVREG_SNOM'
    end
    object ElementIDVIDIMAGENABOR_SNOM: TFIBLargeIntField
      FieldName = 'IDVIDIMAGENABOR_SNOM'
    end
    object ElementIDPROPNABOR_SNOM: TFIBLargeIntField
      FieldName = 'IDPROPNABOR_SNOM'
    end
    object ElementIDDEPARTMENT_SNOM: TFIBLargeIntField
      FieldName = 'IDDEPARTMENT_SNOM'
    end
    object ElementNAME_SDEPARTMENT: TFIBWideStringField
      FieldName = 'NAME_SDEPARTMENT'
      Size = 200
    end
    object ElementNAME_SPROPNABOR: TFIBWideStringField
      FieldName = 'NAME_SPROPNABOR'
      Size = 200
    end
    object ElementNAME_SVIDIMAGE_NABOR: TFIBWideStringField
      FieldName = 'NAME_SVIDIMAGE_NABOR'
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
    Top = 64
  end
  object BasEd: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from SED where IDED=:IDBASED')
    Transaction = IBTr
    Left = 112
    Top = 176
    object BasEdKFED: TFIBBCDField
      FieldName = 'KFED'
      Size = 3
      RoundByScale = True
    end
    object BasEdTSHED: TFIBIntegerField
      FieldName = 'TSHED'
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
    object BasEdNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
    end
    object BasEdSHED: TFIBWideStringField
      FieldName = 'SHED'
      Size = 13
    end
  end
  object OsnEd: TpFIBDataSet
    SelectSQL.Strings = (
      'select  * from SED where IDED=:IDOSNED')
    Transaction = IBTr
    Left = 112
    Top = 224
    object OsnEdKFED: TFIBBCDField
      FieldName = 'KFED'
      Size = 3
      RoundByScale = True
    end
    object OsnEdTSHED: TFIBIntegerField
      FieldName = 'TSHED'
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
    object OsnEdNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
    end
    object OsnEdSHED: TFIBWideStringField
      FieldName = 'SHED'
      Size = 13
    end
  end
  object IBQSprGrpBV: TpFIBDataSet
    SelectSQL.Strings = (
      'select NAMEPOD, IDPOD_GBVNOM, ID_GBVNOM, NAME_GBVNOM'
      'from SGBVNOM '
      'left outer join SPOD  on IDPOD=IDPOD_GBVNOM'
      'order by NAMEPOD, NAME_GBVNOM')
    Transaction = IBTr
    Left = 256
    Top = 120
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
    object IBQSprGrpBVNAMEPOD: TFIBWideStringField
      FieldName = 'NAMEPOD'
      Size = 100
    end
    object IBQSprGrpBVNAME_GBVNOM: TFIBWideStringField
      FieldName = 'NAME_GBVNOM'
      Size = 100
    end
  end
  object SpTPrice: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from STPRICE')
    Transaction = IBTr
    Left = 128
    Top = 120
    object SpTPriceID_TPRICE: TFIBBCDField
      FieldName = 'ID_TPRICE'
      Size = 0
      RoundByScale = True
    end
    object SpTPriceNAME_TPRICE: TFIBWideStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
    end
  end
  object Code: TpFIBDataSet
    SelectSQL.Strings = (
      'select max(CODENOM) AS MAXCODE '
      'from  SNOM'
      'where CODENOM between  :PARAM_CODEMIN and :PARAM_CODEMAX')
    Transaction = IBTr
    Left = 176
    Top = 120
    object CodeMAXCODE: TFIBIntegerField
      FieldName = 'MAXCODE'
    end
  end
  object pFIBQuery: TpFIBQuery
    Transaction = IBTr
    Left = 184
    Top = 248
    qoStartTransaction = True
  end
  object pFIBTrUpdate: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 264
    Top = 248
  end
  object pFIBTr: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 328
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
    Left = 256
    Top = 168
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
    object SprScaleAndGrpVesNomNAME_SSCALE: TFIBWideStringField
      FieldName = 'NAME_SSCALE'
      Size = 100
    end
    object SprScaleAndGrpVesNomNAME_SGRPVESNOM: TFIBWideStringField
      FieldName = 'NAME_SGRPVESNOM'
      Size = 100
    end
  end
  object FisEd: TpFIBDataSet
    SelectSQL.Strings = (
      'select  * from SED where IDED=:IDFISED')
    Transaction = IBTr
    Left = 112
    Top = 280
    object FIBBCDField1: TFIBBCDField
      FieldName = 'KFED'
      Size = 3
      RoundByScale = True
    end
    object FIBIntegerField1: TFIBIntegerField
      FieldName = 'TSHED'
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
    object FisEdNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
    end
    object FisEdSHED: TFIBWideStringField
      FieldName = 'SHED'
      Size = 13
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
    Left = 112
    Top = 336
    poUseLargeIntField = True
    object SpisokEdKFED: TFIBBCDField
      FieldName = 'KFED'
      Size = 3
      RoundByScale = True
    end
    object SpisokEdIDED: TFIBLargeIntField
      FieldName = 'IDED'
    end
    object SpisokEdNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
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
end
