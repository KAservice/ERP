object DMUserInfo: TDMUserInfo
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 206
  Width = 408
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 48
    Top = 72
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    SelectSQL.Strings = (
      'select SUSER.*,'
      ' IDPOD,NAMEPOD, '
      'IDFIRM, NAMEFIRM, '
      'IDSKLAD, NAMESKLAD, '
      'ID_TPRICE, NAME_TPRICE, '
      'NAME_SINFBASE_OBMEN, '
      'NAMEBSCHET,'
      'NAMEKKM'
      'from SUSER  '
      'left outer join  SPOD on IDPOD_USER=IDPOD'
      'left outer join SFIRM on IDFIRM_USER=IDFIRM'
      'left outer join SSKLAD on IDSKLAD_USER=IDSKLAD'
      'left outer join STPRICE on IDTPRICE_USER=ID_TPRICE'
      'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_SUSER'
      'left outer join SBSCHET on IDBSCHET_USER=IDBSCHET'
      'left outer join SKKM on IDKASSA_USER=IDKKM'
      'where '
      'ID_USER=:ID'
      ''
      '')
    AutoUpdateOptions.UpdateTableName = 'SUSER'
    AutoUpdateOptions.KeyFields = 'ID_USER'
    AutoUpdateOptions.GeneratorName = 'GEN_SUSER_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = Transaction
    Database = DM.pFIBData
    Left = 144
    Top = 72
    object ElementTPOSREPORT_SUSER: TFIBSmallIntField
      FieldName = 'TPOSREPORT_SUSER'
    end
    object ElementTPOSGOURNAL_SUSER: TFIBSmallIntField
      FieldName = 'TPOSGOURNAL_SUSER'
    end
    object ElementKOLDAYREP_SUSER: TFIBSmallIntField
      FieldName = 'KOLDAYREP_SUSER'
    end
    object ElementKOLDAYGUR_SUSER: TFIBSmallIntField
      FieldName = 'KOLDAYGUR_SUSER'
    end
    object ElementID_USER: TFIBBCDField
      FieldName = 'ID_USER'
      Size = 0
      RoundByScale = True
    end
    object ElementIDPOD_USER: TFIBBCDField
      FieldName = 'IDPOD_USER'
      Size = 0
      RoundByScale = True
    end
    object ElementIDFIRM_USER: TFIBBCDField
      FieldName = 'IDFIRM_USER'
      Size = 0
      RoundByScale = True
    end
    object ElementIDSKLAD_USER: TFIBBCDField
      FieldName = 'IDSKLAD_USER'
      Size = 0
      RoundByScale = True
    end
    object ElementIDTPRICE_USER: TFIBBCDField
      FieldName = 'IDTPRICE_USER'
      Size = 0
      RoundByScale = True
    end
    object ElementIDTPRICE1_USER: TFIBBCDField
      FieldName = 'IDTPRICE1_USER'
      Size = 0
      RoundByScale = True
    end
    object ElementIDTPRICE2_USER: TFIBBCDField
      FieldName = 'IDTPRICE2_USER'
      Size = 0
      RoundByScale = True
    end
    object ElementIDBSCHET_USER: TFIBBCDField
      FieldName = 'IDBSCHET_USER'
      Size = 0
      RoundByScale = True
    end
    object ElementIDGRP_USER: TFIBBCDField
      FieldName = 'IDGRP_USER'
      Size = 0
      RoundByScale = True
    end
    object ElementIDKASSA_USER: TFIBBCDField
      FieldName = 'IDKASSA_USER'
      Size = 0
      RoundByScale = True
    end
    object ElementIDBASE_SUSER: TFIBBCDField
      FieldName = 'IDBASE_SUSER'
      Size = 0
      RoundByScale = True
    end
    object ElementREOPEN_GUR_SUSER: TFIBSmallIntField
      FieldName = 'REOPEN_GUR_SUSER'
    end
    object ElementREOPEN_SPR_SUSER: TFIBSmallIntField
      FieldName = 'REOPEN_SPR_SUSER'
    end
    object ElementSPRNOM_OST_SUSER: TFIBSmallIntField
      FieldName = 'SPRNOM_OST_SUSER'
    end
    object ElementEDIT_CHUG_DOC_SUSER: TFIBIntegerField
      FieldName = 'EDIT_CHUG_DOC_SUSER'
    end
    object ElementDEL_CHUG_DOC_SUSER: TFIBIntegerField
      FieldName = 'DEL_CHUG_DOC_SUSER'
    end
    object ElementSHOW_LOG_SUSER: TFIBSmallIntField
      FieldName = 'SHOW_LOG_SUSER'
    end
    object ElementDETALIED_LOG_SUSER: TFIBSmallIntField
      FieldName = 'DETALIED_LOG_SUSER'
    end
    object ElementSAVENAME_SUSER: TFIBSmallIntField
      FieldName = 'SAVENAME_SUSER'
    end
    object ElementNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
      Size = 100
    end
    object ElementFNAME_USER: TFIBWideStringField
      FieldName = 'FNAME_USER'
      Size = 100
    end
    object ElementINTERF_USER: TFIBIntegerField
      FieldName = 'INTERF_USER'
    end
    object ElementNAMEPOD: TFIBWideStringField
      FieldName = 'NAMEPOD'
      Size = 100
    end
    object ElementNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 100
    end
    object ElementNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 100
    end
    object ElementNAME_TPRICE: TFIBWideStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
    end
    object ElementNAME_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 100
    end
    object ElementNAMEBSCHET: TFIBWideStringField
      FieldName = 'NAMEBSCHET'
      Size = 100
    end
    object ElementNAMEKKM: TFIBWideStringField
      FieldName = 'NAMEKKM'
      Size = 100
    end
    object ElementNAME2_USER: TFIBWideStringField
      FieldName = 'NAME2_USER'
    end
  end
  object Transaction: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read_committed'
      'rec_version'
      'nowait'
      'read')
    TPBMode = tpbDefault
    Left = 216
    Top = 72
  end
  object Query: TpFIBQuery
    Transaction = Transaction
    Database = DM.pFIBData
    Left = 144
    Top = 128
    qoStartTransaction = True
  end
end
