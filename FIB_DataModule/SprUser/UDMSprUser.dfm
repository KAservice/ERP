object DMSprUser: TDMSprUser
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 293
  Width = 486
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
      '    SAVENAME_SUSER = :SAVENAME_SUSER,'
      '    IDACTCATEGORY_SUSER = :IDACTCATEGORY_SUSER'
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
      '    SAVENAME_SUSER,'
      '    IDACTCATEGORY_SUSER'
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
      '    :SAVENAME_SUSER,'
      '    :IDACTCATEGORY_SUSER'
      ')')
    RefreshSQL.Strings = (
      'select SUSER.*,'
      ' IDPOD,NAMEPOD, '
      'IDFIRM, NAMEFIRM, '
      'IDSKLAD, NAMESKLAD, '
      'ID_TPRICE, NAME_TPRICE, '
      'NAME_SINFBASE_OBMEN, '
      'NAMEBSCHET,'
      'NAMEKKM ,'
      '    rem_sactcategory.name_rem_sactcategory'
      'from SUSER  '
      'left outer join  SPOD on IDPOD_USER=IDPOD'
      'left outer join SFIRM on IDFIRM_USER=IDFIRM'
      'left outer join SSKLAD on IDSKLAD_USER=IDSKLAD'
      'left outer join STPRICE on IDTPRICE_USER=ID_TPRICE'
      'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_SUSER'
      'left outer join SBSCHET on IDBSCHET_USER=IDBSCHET'
      'left outer join SKKM on IDKASSA_USER=IDKKM'
      
        'left outer join rem_sactcategory on suser.idactcategory_suser=re' +
        'm_sactcategory.id_rem_sactcategory'
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
      'NAMEKKM ,'
      '    rem_sactcategory.name_rem_sactcategory'
      'from SUSER  '
      'left outer join  SPOD on IDPOD_USER=IDPOD'
      'left outer join SFIRM on IDFIRM_USER=IDFIRM'
      'left outer join SSKLAD on IDSKLAD_USER=IDSKLAD'
      'left outer join STPRICE on IDTPRICE_USER=ID_TPRICE'
      'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_SUSER'
      'left outer join SBSCHET on IDBSCHET_USER=IDBSCHET'
      'left outer join SKKM on IDKASSA_USER=IDKKM'
      
        'left outer join rem_sactcategory on suser.idactcategory_suser=re' +
        'm_sactcategory.id_rem_sactcategory'
      'where '
      'ID_USER=:ID'
      ''
      '')
    AutoUpdateOptions.UpdateTableName = 'SUSER'
    AutoUpdateOptions.KeyFields = 'ID_USER'
    AutoUpdateOptions.GeneratorName = 'GEN_SUSER_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = pFIBTr
    UpdateTransaction = pFIBTrUpdate
    Left = 144
    Top = 72
    poUseLargeIntField = True
    object ElementID_USER: TFIBLargeIntField
      FieldName = 'ID_USER'
    end
    object ElementIDPOD_USER: TFIBLargeIntField
      FieldName = 'IDPOD_USER'
    end
    object ElementIDFIRM_USER: TFIBLargeIntField
      FieldName = 'IDFIRM_USER'
    end
    object ElementIDSKLAD_USER: TFIBLargeIntField
      FieldName = 'IDSKLAD_USER'
    end
    object ElementIDTPRICE_USER: TFIBLargeIntField
      FieldName = 'IDTPRICE_USER'
    end
    object ElementNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
      Size = 200
    end
    object ElementFNAME_USER: TFIBWideStringField
      FieldName = 'FNAME_USER'
      Size = 200
    end
    object ElementPASSWORD_USER: TFIBWideStringField
      FieldName = 'PASSWORD_USER'
      Size = 10
    end
    object ElementINTERF_USER: TFIBIntegerField
      FieldName = 'INTERF_USER'
    end
    object ElementIDTPRICE1_USER: TFIBLargeIntField
      FieldName = 'IDTPRICE1_USER'
    end
    object ElementIDTPRICE2_USER: TFIBLargeIntField
      FieldName = 'IDTPRICE2_USER'
    end
    object ElementGID_SUSER: TFIBWideStringField
      FieldName = 'GID_SUSER'
      Size = 10
    end
    object ElementPREFIKS_USER: TFIBWideStringField
      FieldName = 'PREFIKS_USER'
      Size = 2
    end
    object ElementIDBSCHET_USER: TFIBLargeIntField
      FieldName = 'IDBSCHET_USER'
    end
    object ElementIDGRP_USER: TFIBLargeIntField
      FieldName = 'IDGRP_USER'
    end
    object ElementNAME2_USER: TFIBWideStringField
      FieldName = 'NAME2_USER'
    end
    object ElementIDKASSA_USER: TFIBLargeIntField
      FieldName = 'IDKASSA_USER'
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
    object ElementIDBASE_SUSER: TFIBLargeIntField
      FieldName = 'IDBASE_SUSER'
    end
    object ElementUPDGUR_AFTER_CLOSE_DOC_SUSER: TFIBSmallIntField
      FieldName = 'UPDGUR_AFTER_CLOSE_DOC_SUSER'
    end
    object ElementSPRNOM_OST_SUSER: TFIBSmallIntField
      FieldName = 'SPRNOM_OST_SUSER'
    end
    object ElementREOPEN_GUR_SUSER: TFIBSmallIntField
      FieldName = 'REOPEN_GUR_SUSER'
    end
    object ElementREOPEN_SPR_SUSER: TFIBSmallIntField
      FieldName = 'REOPEN_SPR_SUSER'
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
    object ElementIDACTCATEGORY_SUSER: TFIBLargeIntField
      FieldName = 'IDACTCATEGORY_SUSER'
    end
    object ElementIDPOD: TFIBLargeIntField
      FieldName = 'IDPOD'
    end
    object ElementNAMEPOD: TFIBWideStringField
      FieldName = 'NAMEPOD'
      Size = 200
    end
    object ElementIDFIRM: TFIBLargeIntField
      FieldName = 'IDFIRM'
    end
    object ElementNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 200
    end
    object ElementIDSKLAD: TFIBLargeIntField
      FieldName = 'IDSKLAD'
    end
    object ElementNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 200
    end
    object ElementID_TPRICE: TFIBLargeIntField
      FieldName = 'ID_TPRICE'
    end
    object ElementNAME_TPRICE: TFIBWideStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
    end
    object ElementNAME_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 200
    end
    object ElementNAMEBSCHET: TFIBWideStringField
      FieldName = 'NAMEBSCHET'
      Size = 200
    end
    object ElementNAMEKKM: TFIBWideStringField
      FieldName = 'NAMEKKM'
      Size = 200
    end
    object ElementNAME_REM_SACTCATEGORY: TFIBWideStringField
      FieldName = 'NAME_REM_SACTCATEGORY'
      Size = 200
    end
  end
  object pFIBTr: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read_committed'
      'rec_version'
      'nowait'
      'read')
    TPBMode = tpbDefault
    Left = 152
    Top = 144
  end
  object pFIBTrUpdate: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'concurrency')
    TPBMode = tpbDefault
    Left = 232
    Top = 144
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from SUSER'
      'ORDER BY NAME_USER')
    OnCalcFields = TableCalcFields
    Transaction = pFIBTr
    Left = 144
    Top = 16
    poUseLargeIntField = True
    object TableUSERID: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'USERID'
      Calculated = True
    end
    object TableID_USER: TFIBLargeIntField
      FieldName = 'ID_USER'
    end
    object TableIDPOD_USER: TFIBLargeIntField
      FieldName = 'IDPOD_USER'
    end
    object TableIDFIRM_USER: TFIBLargeIntField
      FieldName = 'IDFIRM_USER'
    end
    object TableIDSKLAD_USER: TFIBLargeIntField
      FieldName = 'IDSKLAD_USER'
    end
    object TableIDTPRICE_USER: TFIBLargeIntField
      FieldName = 'IDTPRICE_USER'
    end
    object TableNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
      Size = 200
    end
    object TableFNAME_USER: TFIBWideStringField
      FieldName = 'FNAME_USER'
      Size = 200
    end
    object TablePASSWORD_USER: TFIBWideStringField
      FieldName = 'PASSWORD_USER'
      Size = 10
    end
    object TableINTERF_USER: TFIBIntegerField
      FieldName = 'INTERF_USER'
    end
    object TableIDTPRICE1_USER: TFIBLargeIntField
      FieldName = 'IDTPRICE1_USER'
    end
    object TableIDTPRICE2_USER: TFIBLargeIntField
      FieldName = 'IDTPRICE2_USER'
    end
    object TableGID_SUSER: TFIBWideStringField
      FieldName = 'GID_SUSER'
      Size = 10
    end
    object TablePREFIKS_USER: TFIBWideStringField
      FieldName = 'PREFIKS_USER'
      Size = 2
    end
    object TableIDBSCHET_USER: TFIBLargeIntField
      FieldName = 'IDBSCHET_USER'
    end
    object TableIDGRP_USER: TFIBLargeIntField
      FieldName = 'IDGRP_USER'
    end
    object TableNAME2_USER: TFIBWideStringField
      FieldName = 'NAME2_USER'
    end
    object TableIDKASSA_USER: TFIBLargeIntField
      FieldName = 'IDKASSA_USER'
    end
    object TableTPOSREPORT_SUSER: TFIBSmallIntField
      FieldName = 'TPOSREPORT_SUSER'
    end
    object TableTPOSGOURNAL_SUSER: TFIBSmallIntField
      FieldName = 'TPOSGOURNAL_SUSER'
    end
    object TableKOLDAYREP_SUSER: TFIBSmallIntField
      FieldName = 'KOLDAYREP_SUSER'
    end
    object TableKOLDAYGUR_SUSER: TFIBSmallIntField
      FieldName = 'KOLDAYGUR_SUSER'
    end
    object TableIDBASE_SUSER: TFIBLargeIntField
      FieldName = 'IDBASE_SUSER'
    end
    object TableUPDGUR_AFTER_CLOSE_DOC_SUSER: TFIBSmallIntField
      FieldName = 'UPDGUR_AFTER_CLOSE_DOC_SUSER'
    end
    object TableSPRNOM_OST_SUSER: TFIBSmallIntField
      FieldName = 'SPRNOM_OST_SUSER'
    end
    object TableREOPEN_GUR_SUSER: TFIBSmallIntField
      FieldName = 'REOPEN_GUR_SUSER'
    end
    object TableREOPEN_SPR_SUSER: TFIBSmallIntField
      FieldName = 'REOPEN_SPR_SUSER'
    end
    object TableEDIT_CHUG_DOC_SUSER: TFIBSmallIntField
      FieldName = 'EDIT_CHUG_DOC_SUSER'
    end
    object TableDEL_CHUG_DOC_SUSER: TFIBSmallIntField
      FieldName = 'DEL_CHUG_DOC_SUSER'
    end
    object TableSHOW_LOG_SUSER: TFIBSmallIntField
      FieldName = 'SHOW_LOG_SUSER'
    end
    object TableDETALIED_LOG_SUSER: TFIBSmallIntField
      FieldName = 'DETALIED_LOG_SUSER'
    end
    object TableSAVENAME_SUSER: TFIBSmallIntField
      FieldName = 'SAVENAME_SUSER'
    end
    object TableIDACTCATEGORY_SUSER: TFIBLargeIntField
      FieldName = 'IDACTCATEGORY_SUSER'
    end
  end
  object pFIBQ: TpFIBQuery
    Transaction = pFIBTr
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
