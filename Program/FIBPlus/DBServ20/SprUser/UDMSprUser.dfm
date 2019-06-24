object DMSprUser: TDMSprUser
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 184
  Width = 309
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 48
    Top = 72
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SUSER'
      'SET '
      '    IDPOD_USER = :IDPOD_USER,'
      '    IDFIRM_USER = :IDFIRM_USER,'
      '    IDSKLAD_USER = :IDSKLAD_USER,'
      '    IDTPRICE_USER = :IDTPRICE_USER,'
      '    NAME_USER = :NAME_USER,'
      '    FNAME_USER = :FNAME_USER,'
      '    PASSWORD_USER = :PASSWORD_USER,'
      '    INTERF_USER = :INTERF_USER,'
      '    IDTPRICE1_USER = :IDTPRICE1_USER,'
      '    IDTPRICE2_USER = :IDTPRICE2_USER,'
      '    GID_SUSER = :GID_SUSER,'
      '    PREFIKS_USER = :PREFIKS_USER,'
      '    IDBSCHET_USER = :IDBSCHET_USER,'
      '    IDGRP_USER = :IDGRP_USER,'
      '    NAME2_USER = :NAME2_USER,'
      '    IDKASSA_USER = :IDKASSA_USER,'
      '    TPOSREPORT_SUSER = :TPOSREPORT_SUSER,'
      '    TPOSGOURNAL_SUSER = :TPOSGOURNAL_SUSER,'
      '    KOLDAYREP_SUSER = :KOLDAYREP_SUSER,'
      '    KOLDAYGUR_SUSER = :KOLDAYGUR_SUSER,'
      '    IDBASE_SUSER = :IDBASE_SUSER,'
      
        '    UPDGUR_AFTER_CLOSE_DOC_SUSER = :UPDGUR_AFTER_CLOSE_DOC_SUSER' +
        ','
      '    SPRNOM_OST_SUSER = :SPRNOM_OST_SUSER,'
      '    REOPEN_GUR_SUSER = :REOPEN_GUR_SUSER,'
      '    REOPEN_SPR_SUSER = :REOPEN_SPR_SUSER,'
      '    EDIT_CHUG_DOC_SUSER = :EDIT_CHUG_DOC_SUSER,'
      '    DEL_CHUG_DOC_SUSER = :DEL_CHUG_DOC_SUSER,'
      '    SHOW_LOG_SUSER = :SHOW_LOG_SUSER,'
      '    DETALIED_LOG_SUSER = :DETALIED_LOG_SUSER,'
      '    SAVENAME_SUSER = :SAVENAME_SUSER'
      'WHERE'
      '    ID_USER = :OLD_ID_USER'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SUSER'
      'WHERE'
      '        ID_USER = :OLD_ID_USER'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SUSER('
      '    ID_USER,'
      '    IDPOD_USER,'
      '    IDFIRM_USER,'
      '    IDSKLAD_USER,'
      '    IDTPRICE_USER,'
      '    NAME_USER,'
      '    FNAME_USER,'
      '    PASSWORD_USER,'
      '    INTERF_USER,'
      '    IDTPRICE1_USER,'
      '    IDTPRICE2_USER,'
      '    GID_SUSER,'
      '    PREFIKS_USER,'
      '    IDBSCHET_USER,'
      '    IDGRP_USER,'
      '    NAME2_USER,'
      '    IDKASSA_USER,'
      '    TPOSREPORT_SUSER,'
      '    TPOSGOURNAL_SUSER,'
      '    KOLDAYREP_SUSER,'
      '    KOLDAYGUR_SUSER,'
      '    IDBASE_SUSER,'
      '    UPDGUR_AFTER_CLOSE_DOC_SUSER,'
      '    SPRNOM_OST_SUSER,'
      '    REOPEN_GUR_SUSER,'
      '    REOPEN_SPR_SUSER,'
      '    EDIT_CHUG_DOC_SUSER,'
      '    DEL_CHUG_DOC_SUSER,'
      '    SHOW_LOG_SUSER,'
      '    DETALIED_LOG_SUSER,'
      '    SAVENAME_SUSER'
      ')'
      'VALUES('
      '    :ID_USER,'
      '    :IDPOD_USER,'
      '    :IDFIRM_USER,'
      '    :IDSKLAD_USER,'
      '    :IDTPRICE_USER,'
      '    :NAME_USER,'
      '    :FNAME_USER,'
      '    :PASSWORD_USER,'
      '    :INTERF_USER,'
      '    :IDTPRICE1_USER,'
      '    :IDTPRICE2_USER,'
      '    :GID_SUSER,'
      '    :PREFIKS_USER,'
      '    :IDBSCHET_USER,'
      '    :IDGRP_USER,'
      '    :NAME2_USER,'
      '    :IDKASSA_USER,'
      '    :TPOSREPORT_SUSER,'
      '    :TPOSGOURNAL_SUSER,'
      '    :KOLDAYREP_SUSER,'
      '    :KOLDAYGUR_SUSER,'
      '    :IDBASE_SUSER,'
      '    :UPDGUR_AFTER_CLOSE_DOC_SUSER,'
      '    :SPRNOM_OST_SUSER,'
      '    :REOPEN_GUR_SUSER,'
      '    :REOPEN_SPR_SUSER,'
      '    :EDIT_CHUG_DOC_SUSER,'
      '    :DEL_CHUG_DOC_SUSER,'
      '    :SHOW_LOG_SUSER,'
      '    :DETALIED_LOG_SUSER,'
      '    :SAVENAME_SUSER'
      ')')
    RefreshSQL.Strings = (
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
      'where(  '
      'ID_USER=:ID'
      '     ) and (     SUSER.ID_USER = :OLD_ID_USER'
      '     )'
      '    '
      ''
      '')
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
    Transaction = pFIBTr
    Database = DM.pFIBData
    UpdateTransaction = pFIBTrUpdate
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 144
    Top = 72
    object ElementNAME_USER: TFIBStringField
      FieldName = 'NAME_USER'
      EmptyStrToNull = True
    end
    object ElementFNAME_USER: TFIBStringField
      FieldName = 'FNAME_USER'
      Size = 30
      EmptyStrToNull = True
    end
    object ElementPASSWORD_USER: TFIBStringField
      FieldName = 'PASSWORD_USER'
      Size = 10
      EmptyStrToNull = True
    end
    object ElementINTERF_USER: TFIBSmallIntField
      FieldName = 'INTERF_USER'
    end
    object ElementNAMEPOD: TFIBStringField
      FieldName = 'NAMEPOD'
      Size = 30
      EmptyStrToNull = True
    end
    object ElementNAMEFIRM: TFIBStringField
      FieldName = 'NAMEFIRM'
      Size = 50
      EmptyStrToNull = True
    end
    object ElementNAMESKLAD: TFIBStringField
      FieldName = 'NAMESKLAD'
      Size = 100
      EmptyStrToNull = True
    end
    object ElementNAME_TPRICE: TFIBStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
      EmptyStrToNull = True
    end
    object ElementNAME_SINFBASE_OBMEN: TFIBStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 100
      EmptyStrToNull = True
    end
    object ElementNAMEBSCHET: TFIBStringField
      FieldName = 'NAMEBSCHET'
      Size = 30
      EmptyStrToNull = True
    end
    object ElementNAME2_USER: TFIBStringField
      FieldName = 'NAME2_USER'
      EmptyStrToNull = True
    end
    object ElementNAMEKKM: TFIBStringField
      FieldName = 'NAMEKKM'
      Size = 100
      EmptyStrToNull = True
    end
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
    object ElementGID_SUSER: TFIBStringField
      FieldName = 'GID_SUSER'
      Size = 10
      EmptyStrToNull = True
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
      OnValidate = ElementEDIT_CHUG_DOC_SUSERValidate
    end
    object ElementDEL_CHUG_DOC_SUSER: TFIBIntegerField
      FieldName = 'DEL_CHUG_DOC_SUSER'
      OnValidate = ElementDEL_CHUG_DOC_SUSERValidate
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
  end
  object pFIBTr: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read_committed'
      'rec_version'
      'nowait'
      'read')
    CSMonitorSupport.Enabled = csmeDatabaseDriven
    TPBMode = tpbDefault
    Left = 96
    Top = 120
  end
  object pFIBTrUpdate: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'concurrency')
    CSMonitorSupport.Enabled = csmeDatabaseDriven
    TPBMode = tpbDefault
    Left = 152
    Top = 120
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from SUSER'
      'ORDER BY NAME_USER')
    OnCalcFields = TableCalcFields
    Transaction = pFIBTr
    Database = DM.pFIBData
    UpdateTransaction = DM.pFIBTr
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 144
    Top = 16
    object TableNAME_USER: TFIBStringField
      FieldName = 'NAME_USER'
      EmptyStrToNull = True
    end
    object TableFNAME_USER: TFIBStringField
      FieldName = 'FNAME_USER'
      Size = 30
      EmptyStrToNull = True
    end
    object TablePASSWORD_USER: TFIBStringField
      FieldName = 'PASSWORD_USER'
      Size = 10
      EmptyStrToNull = True
    end
    object TableINTERF_USER: TFIBSmallIntField
      FieldName = 'INTERF_USER'
    end
    object TablePREFIKS_USER: TFIBStringField
      FieldName = 'PREFIKS_USER'
      Size = 2
      EmptyStrToNull = True
    end
    object TableNAME2_USER: TFIBStringField
      FieldName = 'NAME2_USER'
      EmptyStrToNull = True
    end
    object TableUSERID: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'USERID'
      Calculated = True
    end
    object TableID_USER: TFIBBCDField
      FieldName = 'ID_USER'
      Size = 0
      RoundByScale = True
    end
    object TableIDPOD_USER: TFIBBCDField
      FieldName = 'IDPOD_USER'
      Size = 0
      RoundByScale = True
    end
    object TableIDFIRM_USER: TFIBBCDField
      FieldName = 'IDFIRM_USER'
      Size = 0
      RoundByScale = True
    end
    object TableIDSKLAD_USER: TFIBBCDField
      FieldName = 'IDSKLAD_USER'
      Size = 0
      RoundByScale = True
    end
    object TableIDTPRICE_USER: TFIBBCDField
      FieldName = 'IDTPRICE_USER'
      Size = 0
      RoundByScale = True
    end
    object TableIDTPRICE1_USER: TFIBBCDField
      FieldName = 'IDTPRICE1_USER'
      Size = 0
      RoundByScale = True
    end
    object TableIDTPRICE2_USER: TFIBBCDField
      FieldName = 'IDTPRICE2_USER'
      Size = 0
      RoundByScale = True
    end
    object TableGID_SUSER: TFIBStringField
      FieldName = 'GID_SUSER'
      Size = 10
      EmptyStrToNull = True
    end
    object TableIDBSCHET_USER: TFIBBCDField
      FieldName = 'IDBSCHET_USER'
      Size = 0
      RoundByScale = True
    end
    object TableIDGRP_USER: TFIBBCDField
      FieldName = 'IDGRP_USER'
      Size = 0
      RoundByScale = True
    end
    object TableIDKASSA_USER: TFIBBCDField
      FieldName = 'IDKASSA_USER'
      Size = 0
      RoundByScale = True
    end
    object TableTPOSREPORT_SUSER: TFIBSmallIntField
      FieldName = 'TPOSREPORT_SUSER'
    end
    object TableTPOSGOURNAL_SUSER: TFIBSmallIntField
      FieldName = 'TPOSGOURNAL_SUSER'
    end
  end
  object pFIBQ: TpFIBQuery
    Transaction = pFIBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 232
    Top = 16
    qoStartTransaction = True
  end
  object pFIBSecurityService1: TpFIBSecurityService
    LibraryName = 'fbclient.dll'
    Protocol = TCP
    LoginPrompt = False
    SecurityAction = ActionDisplayUser
    UserID = 0
    GroupID = 0
    Left = 232
    Top = 72
  end
end
