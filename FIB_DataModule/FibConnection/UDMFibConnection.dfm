object DMFibConnection: TDMFibConnection
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 504
  Width = 378
  object pFIBData: TpFIBDatabase
    DBName = 'K:\NewData\BASE_30.FDB'
    DBParams.Strings = (
      'user_name=SYSDBA'
      'sql_role_name='
      'lc_ctype=UTF8'
      'password=masterkey')
    DefaultTransaction = pFIBTr
    DefaultUpdateTransaction = pFIBTr
    SQLDialect = 3
    Timeout = 0
    DesignDBOptions = [ddoIsDefaultDatabase]
    LibraryName = 'fbclient.dll'
    WaitForRestoreConnect = 0
    Left = 104
    Top = 88
  end
  object pFIBTr: TpFIBTransaction
    DefaultDatabase = pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read_committed'
      'rec_version'
      'nowait'
      'read')
    TPBMode = tpbDefault
    Left = 168
    Top = 88
  end
  object pFIBQLog: TpFIBQuery
    Transaction = pFIBTrLog
    Database = pFIBData
    SQL.Strings = (
      'INSERT INTO '
      '  LOG(IDUSER_LOG, '
      '  TYPE_LOG,'
      '  OBJECT_LOG,'
      '  MESSAGE_LOG,'
      '  OPER_LOG,'
      '  APPLICATION_LOG,'
      '  CODEOB_LOG,'
      '  IDOBJECT_LOG,'
      '  SUBSYSTEM_LOG)'
      'VALUES('
      '  :IDUSER_LOG,'
      '  :TYPE_LOG,'
      '  :OBJECT_LOG,'
      '  :MESSAGE_LOG,'
      '  :OPER_LOG,'
      '  :APPLICATION_LOG,'
      '  :CODEOB_LOG,'
      '  :IDOBJECT_LOG,'
      '  :SUBSYSTEM_LOG)')
    Left = 24
    Top = 184
    qoStartTransaction = True
  end
  object pFIBTrLog: TpFIBTransaction
    DefaultDatabase = pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 24
    Top = 240
  end
  object Query: TpFIBQuery
    Transaction = Transaction
    Database = pFIBData
    Left = 104
    Top = 312
    qoStartTransaction = True
  end
  object UserInfo: TpFIBDataSet
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
    Transaction = TransactionUserInfo
    Database = pFIBData
    Left = 104
    Top = 384
    object UserInfoTPOSREPORT_SUSER: TFIBSmallIntField
      FieldName = 'TPOSREPORT_SUSER'
    end
    object UserInfoTPOSGOURNAL_SUSER: TFIBSmallIntField
      FieldName = 'TPOSGOURNAL_SUSER'
    end
    object UserInfoKOLDAYREP_SUSER: TFIBSmallIntField
      FieldName = 'KOLDAYREP_SUSER'
    end
    object UserInfoKOLDAYGUR_SUSER: TFIBSmallIntField
      FieldName = 'KOLDAYGUR_SUSER'
    end
    object UserInfoID_USER: TFIBBCDField
      FieldName = 'ID_USER'
      Size = 0
      RoundByScale = True
    end
    object UserInfoIDPOD_USER: TFIBBCDField
      FieldName = 'IDPOD_USER'
      Size = 0
      RoundByScale = True
    end
    object UserInfoIDFIRM_USER: TFIBBCDField
      FieldName = 'IDFIRM_USER'
      Size = 0
      RoundByScale = True
    end
    object UserInfoIDSKLAD_USER: TFIBBCDField
      FieldName = 'IDSKLAD_USER'
      Size = 0
      RoundByScale = True
    end
    object UserInfoIDTPRICE_USER: TFIBBCDField
      FieldName = 'IDTPRICE_USER'
      Size = 0
      RoundByScale = True
    end
    object UserInfoIDTPRICE1_USER: TFIBBCDField
      FieldName = 'IDTPRICE1_USER'
      Size = 0
      RoundByScale = True
    end
    object UserInfoIDTPRICE2_USER: TFIBBCDField
      FieldName = 'IDTPRICE2_USER'
      Size = 0
      RoundByScale = True
    end
    object UserInfoIDBSCHET_USER: TFIBBCDField
      FieldName = 'IDBSCHET_USER'
      Size = 0
      RoundByScale = True
    end
    object UserInfoIDGRP_USER: TFIBBCDField
      FieldName = 'IDGRP_USER'
      Size = 0
      RoundByScale = True
    end
    object UserInfoIDKASSA_USER: TFIBBCDField
      FieldName = 'IDKASSA_USER'
      Size = 0
      RoundByScale = True
    end
    object UserInfoIDBASE_SUSER: TFIBBCDField
      FieldName = 'IDBASE_SUSER'
      Size = 0
      RoundByScale = True
    end
    object UserInfoREOPEN_GUR_SUSER: TFIBSmallIntField
      FieldName = 'REOPEN_GUR_SUSER'
    end
    object UserInfoREOPEN_SPR_SUSER: TFIBSmallIntField
      FieldName = 'REOPEN_SPR_SUSER'
    end
    object UserInfoSPRNOM_OST_SUSER: TFIBSmallIntField
      FieldName = 'SPRNOM_OST_SUSER'
    end
    object UserInfoEDIT_CHUG_DOC_SUSER: TFIBIntegerField
      FieldName = 'EDIT_CHUG_DOC_SUSER'
    end
    object UserInfoDEL_CHUG_DOC_SUSER: TFIBIntegerField
      FieldName = 'DEL_CHUG_DOC_SUSER'
    end
    object UserInfoSHOW_LOG_SUSER: TFIBSmallIntField
      FieldName = 'SHOW_LOG_SUSER'
    end
    object UserInfoDETALIED_LOG_SUSER: TFIBSmallIntField
      FieldName = 'DETALIED_LOG_SUSER'
    end
    object UserInfoSAVENAME_SUSER: TFIBSmallIntField
      FieldName = 'SAVENAME_SUSER'
    end
    object UserInfoNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
      Size = 100
    end
    object UserInfoFNAME_USER: TFIBWideStringField
      FieldName = 'FNAME_USER'
      Size = 100
    end
    object UserInfoINTERF_USER: TFIBIntegerField
      FieldName = 'INTERF_USER'
    end
    object UserInfoNAMEPOD: TFIBWideStringField
      FieldName = 'NAMEPOD'
      Size = 100
    end
    object UserInfoNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 100
    end
    object UserInfoNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 100
    end
    object UserInfoNAME_TPRICE: TFIBWideStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
    end
    object UserInfoNAME_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 100
    end
    object UserInfoNAMEBSCHET: TFIBWideStringField
      FieldName = 'NAMEBSCHET'
      Size = 100
    end
    object UserInfoNAMEKKM: TFIBWideStringField
      FieldName = 'NAMEKKM'
      Size = 100
    end
    object UserInfoNAME2_USER: TFIBWideStringField
      FieldName = 'NAME2_USER'
    end
  end
  object TransactionUserInfo: TpFIBTransaction
    DefaultDatabase = pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read_committed'
      'rec_version'
      'nowait'
      'read')
    TPBMode = tpbDefault
    Left = 208
    Top = 384
  end
  object Transaction: TpFIBTransaction
    DefaultDatabase = pFIBData
    TimeoutAction = TARollback
    Left = 208
    Top = 312
  end
  object ARMInfo: TpFIBDataSet
    SelectSQL.Strings = (
      'select  SARM.*,'
      '        SFIRM.namefirm,'
      '        SSKLAD.namesklad,'
      '        SKKM.namekkm,'
      '        SPOD.namepod ,'
      '        SPOD.idtpricepod ,'
      '        STPRICE.name_tprice,'
      '        sinfbase_obmen.name_sinfbase_obmen'
      'from '
      '  SARM '
      'left outer join SPOD on IDPODR_SARM=IDPOD'
      'left outer join STPRICE  on  IDTPRICEPOD=ID_TPRICE'
      'left outer join SFIRM on IDFIRM_SARM=IDFIRM'
      'left outer join SSKLAD on IDSKLAD=IDSKLAD_SARM'
      'left outer join SKKM on IDKKM=IDKKM_SARM'
      'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_SARM'
      'where '
      '  sarm.code_sarm=:PARAM_CODE')
    Transaction = TransactionARM
    Database = pFIBData
    Left = 104
    Top = 448
    poUseLargeIntField = True
    object ARMInfoID_SARM: TFIBLargeIntField
      FieldName = 'ID_SARM'
    end
    object ARMInfoNAME_SARM: TFIBWideStringField
      FieldName = 'NAME_SARM'
      Size = 100
    end
    object ARMInfoCODE_SARM: TFIBIntegerField
      FieldName = 'CODE_SARM'
    end
    object ARMInfoIDFIRM_SARM: TFIBLargeIntField
      FieldName = 'IDFIRM_SARM'
    end
    object ARMInfoIDSKLAD_SARM: TFIBLargeIntField
      FieldName = 'IDSKLAD_SARM'
    end
    object ARMInfoIDPODR_SARM: TFIBLargeIntField
      FieldName = 'IDPODR_SARM'
    end
    object ARMInfoIDKKM_SARM: TFIBLargeIntField
      FieldName = 'IDKKM_SARM'
    end
    object ARMInfoSTRPAR_SARM: TFIBWideStringField
      FieldName = 'STRPAR_SARM'
      Size = 1000
    end
    object ARMInfoNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 100
    end
    object ARMInfoNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 100
    end
    object ARMInfoNAMEKKM: TFIBWideStringField
      FieldName = 'NAMEKKM'
      Size = 100
    end
    object ARMInfoNAMEPOD: TFIBWideStringField
      FieldName = 'NAMEPOD'
      Size = 100
    end
    object ARMInfoIDTPRICEPOD: TFIBLargeIntField
      FieldName = 'IDTPRICEPOD'
    end
    object ARMInfoNAME_TPRICE: TFIBWideStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
    end
    object ARMInfoNAME_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 100
    end
    object ARMInfoIDBASE_SARM: TFIBLargeIntField
      FieldName = 'IDBASE_SARM'
    end
  end
  object TransactionARM: TpFIBTransaction
    DefaultDatabase = pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 208
    Top = 448
  end
end
