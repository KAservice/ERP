object DataModuleMain: TDataModuleMain
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 226
  Width = 433
  object Database: TpFIBDatabase
    Connected = True
    DBName = 'K:\NewData\BASE_30.FDB'
    DBParams.Strings = (
      'lc_ctype=UTF8'
      'user_name=SYSDBA'
      'password=masterkey')
    DefaultTransaction = TrRead
    DefaultUpdateTransaction = TrRead
    SQLDialect = 3
    Timeout = 0
    LibraryName = 'fbclient.dll'
    WaitForRestoreConnect = 0
    Left = 184
    Top = 24
  end
  object TrRead: TpFIBTransaction
    Active = True
    DefaultDatabase = Database
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 304
    Top = 24
  end
  object UserDataSet: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from suser'
      'where NAME_USER=:PARAM_NAME')
    Transaction = TrRead
    Database = Database
    Left = 224
    Top = 112
    object UserDataSetID_USER: TFIBBCDField
      FieldName = 'ID_USER'
      Size = 0
      RoundByScale = True
    end
    object UserDataSetIDPOD_USER: TFIBBCDField
      FieldName = 'IDPOD_USER'
      Size = 0
      RoundByScale = True
    end
    object UserDataSetIDFIRM_USER: TFIBBCDField
      FieldName = 'IDFIRM_USER'
      Size = 0
      RoundByScale = True
    end
    object UserDataSetIDSKLAD_USER: TFIBBCDField
      FieldName = 'IDSKLAD_USER'
      Size = 0
      RoundByScale = True
    end
    object UserDataSetIDTPRICE_USER: TFIBBCDField
      FieldName = 'IDTPRICE_USER'
      Size = 0
      RoundByScale = True
    end
    object UserDataSetNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
      Size = 100
    end
    object UserDataSetFNAME_USER: TFIBWideStringField
      FieldName = 'FNAME_USER'
      Size = 100
    end
    object UserDataSetPASSWORD_USER: TFIBWideStringField
      FieldName = 'PASSWORD_USER'
      Size = 10
    end
    object UserDataSetINTERF_USER: TFIBIntegerField
      FieldName = 'INTERF_USER'
    end
    object UserDataSetIDTPRICE1_USER: TFIBBCDField
      FieldName = 'IDTPRICE1_USER'
      Size = 0
      RoundByScale = True
    end
    object UserDataSetIDTPRICE2_USER: TFIBBCDField
      FieldName = 'IDTPRICE2_USER'
      Size = 0
      RoundByScale = True
    end
    object UserDataSetGID_SUSER: TFIBWideStringField
      FieldName = 'GID_SUSER'
      Size = 10
    end
    object UserDataSetPREFIKS_USER: TFIBWideStringField
      FieldName = 'PREFIKS_USER'
      Size = 2
    end
    object UserDataSetIDBSCHET_USER: TFIBBCDField
      FieldName = 'IDBSCHET_USER'
      Size = 0
      RoundByScale = True
    end
    object UserDataSetIDGRP_USER: TFIBBCDField
      FieldName = 'IDGRP_USER'
      Size = 0
      RoundByScale = True
    end
    object UserDataSetNAME2_USER: TFIBWideStringField
      FieldName = 'NAME2_USER'
    end
    object UserDataSetIDKASSA_USER: TFIBBCDField
      FieldName = 'IDKASSA_USER'
      Size = 0
      RoundByScale = True
    end
    object UserDataSetTPOSREPORT_SUSER: TFIBSmallIntField
      FieldName = 'TPOSREPORT_SUSER'
    end
    object UserDataSetTPOSGOURNAL_SUSER: TFIBSmallIntField
      FieldName = 'TPOSGOURNAL_SUSER'
    end
    object UserDataSetKOLDAYREP_SUSER: TFIBSmallIntField
      FieldName = 'KOLDAYREP_SUSER'
    end
    object UserDataSetKOLDAYGUR_SUSER: TFIBSmallIntField
      FieldName = 'KOLDAYGUR_SUSER'
    end
    object UserDataSetIDBASE_SUSER: TFIBBCDField
      FieldName = 'IDBASE_SUSER'
      Size = 0
      RoundByScale = True
    end
    object UserDataSetUPDGUR_AFTER_CLOSE_DOC_SUSER: TFIBSmallIntField
      FieldName = 'UPDGUR_AFTER_CLOSE_DOC_SUSER'
    end
    object UserDataSetSPRNOM_OST_SUSER: TFIBSmallIntField
      FieldName = 'SPRNOM_OST_SUSER'
    end
    object UserDataSetREOPEN_GUR_SUSER: TFIBSmallIntField
      FieldName = 'REOPEN_GUR_SUSER'
    end
    object UserDataSetREOPEN_SPR_SUSER: TFIBSmallIntField
      FieldName = 'REOPEN_SPR_SUSER'
    end
    object UserDataSetEDIT_CHUG_DOC_SUSER: TFIBIntegerField
      FieldName = 'EDIT_CHUG_DOC_SUSER'
    end
    object UserDataSetDEL_CHUG_DOC_SUSER: TFIBIntegerField
      FieldName = 'DEL_CHUG_DOC_SUSER'
    end
    object UserDataSetSHOW_LOG_SUSER: TFIBSmallIntField
      FieldName = 'SHOW_LOG_SUSER'
    end
    object UserDataSetDETALIED_LOG_SUSER: TFIBSmallIntField
      FieldName = 'DETALIED_LOG_SUSER'
    end
    object UserDataSetSAVENAME_SUSER: TFIBSmallIntField
      FieldName = 'SAVENAME_SUSER'
    end
  end
end
