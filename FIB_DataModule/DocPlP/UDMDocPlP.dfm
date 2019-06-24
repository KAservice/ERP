object DMDocPLP: TDMDocPLP
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 397
  Width = 349
  object DataSourceDoc: TDataSource
    DataSet = Doc
    Left = 72
    Top = 72
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
      'select GALLDOC.*,'
      ' FNAME_USER ,'
      ' NAME_SINFBASE_OBMEN,'
      ' NAMEFIRM,'
      ' NAMEKLIENT,'
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from GALLDOC'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      'left outer join SFIRM on IDFIRMDOC=IDFIRM'
      'left outer join SKLIENT on IDKLDOC=IDKLIENT'
      
        'left outer join SPROJECT on galldoc.idproject_galldoc=sproject.i' +
        'd_sproject'
      
        'left outer join sbusiness_oper on galldoc.idbusinop_galldoc=sbus' +
        'iness_oper.id_sbusiness_oper'
      'where(  IDDOC=:ID'
      '     ) and (     GALLDOC.IDDOC = :OLD_IDDOC'
      '     )'
      '     ')
    SelectSQL.Strings = (
      'select GALLDOC.*,'
      ' FNAME_USER ,'
      ' NAME_SINFBASE_OBMEN,'
      ' NAMEFIRM,'
      ' NAMEKLIENT,'
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from GALLDOC'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      'left outer join SFIRM on IDFIRMDOC=IDFIRM'
      'left outer join SKLIENT on IDKLDOC=IDKLIENT'
      
        'left outer join SPROJECT on galldoc.idproject_galldoc=sproject.i' +
        'd_sproject'
      
        'left outer join sbusiness_oper on galldoc.idbusinop_galldoc=sbus' +
        'iness_oper.id_sbusiness_oper'
      'where IDDOC=:ID ')
    AutoUpdateOptions.UpdateTableName = 'GALLDOC'
    AutoUpdateOptions.KeyFields = 'IDDOC'
    AutoUpdateOptions.GeneratorName = 'GEN_GALLDOC_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 16
    poUseLargeIntField = True
    object DocAllPOSDOC: TFIBDateTimeField
      FieldName = 'POSDOC'
      OnChange = DocAllPOSDOCChange
      DisplayFormat = 'c'
    end
    object DocAllPRDOC: TFIBSmallIntField
      FieldName = 'PRDOC'
    end
    object DocAllNUMDOC: TFIBIntegerField
      FieldName = 'NUMDOC'
    end
    object DocAllSUMDOC: TFIBBCDField
      FieldName = 'SUMDOC'
      OnChange = DocAllSUMDOCChange
      Size = 2
      RoundByScale = True
    end
    object DocAllIDDOC: TFIBLargeIntField
      FieldName = 'IDDOC'
    end
    object DocAllTDOC: TFIBWideStringField
      FieldName = 'TDOC'
      Size = 10
    end
    object DocAllIDFIRMDOC: TFIBLargeIntField
      FieldName = 'IDFIRMDOC'
      OnChange = DocAllIDFIRMDOCChange
    end
    object DocAllIDSKLDOC: TFIBLargeIntField
      FieldName = 'IDSKLDOC'
    end
    object DocAllIDKLDOC: TFIBLargeIntField
      FieldName = 'IDKLDOC'
    end
    object DocAllIDDOGDOC: TFIBLargeIntField
      FieldName = 'IDDOGDOC'
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
    object DocAllNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 200
    end
    object DocAllIDBUSINOP_GALLDOC: TFIBLargeIntField
      FieldName = 'IDBUSINOP_GALLDOC'
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
      'UPDATE DPLP'
      'SET '
      '    IDDOCPLP = :IDDOCPLP,'
      '    IDBSCHPLP = :IDBSCHPLP,'
      '    IDRSCHPLP = :IDRSCHPLP,'
      '    VIDPLP = :VIDPLP,'
      '    OCHPLP = :OCHPLP,'
      '    SROKPLP = :SROKPLP,'
      '    NASNPLP = :NASNPLP,'
      '    GID_DPLP = :GID_DPLP,'
      '    ADDKDRPLP = :ADDKDRPLP,'
      '    OPERATIONPLP = :OPERATIONPLP,'
      '    SUMUSNPLP = :SUMUSNPLP,'
      '    NALOG_STATUS_PLP = :NALOG_STATUS_PLP,'
      '    NALOG_OSN_PLP = :NALOG_OSN_PLP,'
      '    NALOG_NUM_PLP = :NALOG_NUM_PLP,'
      '    NALOG_TPLAT_PLP = :NALOG_TPLAT_PLP,'
      '    NALOG_KBK_PLP = :NALOG_KBK_PLP,'
      '    NALOG_OKATO_PLP = :NALOG_OKATO_PLP,'
      '    NALOG_PERIOD_PLP = :NALOG_PERIOD_PLP,'
      '    NALOG_DATE_PLP = :NALOG_DATE_PLP,'
      '    IDBASE_DPLP = :IDBASE_DPLP,'
      '    NDS_DPLP = :NDS_DPLP,'
      '    SUMNDS_DPLP = :SUMNDS_DPLP'
      'WHERE'
      '    IDPLP = :OLD_IDPLP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DPLP'
      'WHERE'
      '        IDPLP = :OLD_IDPLP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DPLP('
      '    IDPLP,'
      '    IDDOCPLP,'
      '    IDBSCHPLP,'
      '    IDRSCHPLP,'
      '    VIDPLP,'
      '    OCHPLP,'
      '    SROKPLP,'
      '    NASNPLP,'
      '    GID_DPLP,'
      '    ADDKDRPLP,'
      '    OPERATIONPLP,'
      '    SUMUSNPLP,'
      '    NALOG_STATUS_PLP,'
      '    NALOG_OSN_PLP,'
      '    NALOG_NUM_PLP,'
      '    NALOG_TPLAT_PLP,'
      '    NALOG_KBK_PLP,'
      '    NALOG_OKATO_PLP,'
      '    NALOG_PERIOD_PLP,'
      '    NALOG_DATE_PLP,'
      '    IDBASE_DPLP,'
      '    NDS_DPLP,'
      '    SUMNDS_DPLP'
      ')'
      'VALUES('
      '    :IDPLP,'
      '    :IDDOCPLP,'
      '    :IDBSCHPLP,'
      '    :IDRSCHPLP,'
      '    :VIDPLP,'
      '    :OCHPLP,'
      '    :SROKPLP,'
      '    :NASNPLP,'
      '    :GID_DPLP,'
      '    :ADDKDRPLP,'
      '    :OPERATIONPLP,'
      '    :SUMUSNPLP,'
      '    :NALOG_STATUS_PLP,'
      '    :NALOG_OSN_PLP,'
      '    :NALOG_NUM_PLP,'
      '    :NALOG_TPLAT_PLP,'
      '    :NALOG_KBK_PLP,'
      '    :NALOG_OKATO_PLP,'
      '    :NALOG_PERIOD_PLP,'
      '    :NALOG_DATE_PLP,'
      '    :IDBASE_DPLP,'
      '    :NDS_DPLP,'
      '    :SUMNDS_DPLP'
      ')')
    RefreshSQL.Strings = (
      'select DPLP.*,'
      '    NAMEBSCHET,'
      '    NAMERSCHET'
      'from  DPLP'
      'left outer join SBSCHET on IDBSCHPLP=IDBSCHET'
      'left outer join SRSCHET on IDRSCHPLP=IDRSCHET'
      'where(  IDDOCPLP=:ID'
      '     ) and (     DPLP.IDPLP = :OLD_IDPLP'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select DPLP.*,'
      '    NAMEBSCHET,'
      '    NAMERSCHET'
      'from  DPLP'
      'left outer join SBSCHET on IDBSCHPLP=IDBSCHET'
      'left outer join SRSCHET on IDRSCHPLP=IDRSCHET'
      'where IDDOCPLP=:ID')
    AutoUpdateOptions.UpdateTableName = 'DPLP'
    AutoUpdateOptions.KeyFields = 'IDPLP'
    AutoUpdateOptions.GeneratorName = 'GEN_DPLP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 72
    poUseLargeIntField = True
    object DocIDPLP: TFIBLargeIntField
      FieldName = 'IDPLP'
    end
    object DocIDDOCPLP: TFIBLargeIntField
      FieldName = 'IDDOCPLP'
    end
    object DocIDBSCHPLP: TFIBLargeIntField
      FieldName = 'IDBSCHPLP'
      OnChange = DocIDBSCHPLPChange
    end
    object DocIDRSCHPLP: TFIBLargeIntField
      FieldName = 'IDRSCHPLP'
    end
    object DocVIDPLP: TFIBIntegerField
      FieldName = 'VIDPLP'
    end
    object DocOCHPLP: TFIBIntegerField
      FieldName = 'OCHPLP'
    end
    object DocSROKPLP: TFIBDateField
      FieldName = 'SROKPLP'
    end
    object DocNASNPLP: TFIBWideStringField
      FieldName = 'NASNPLP'
      Size = 150
    end
    object DocGID_DPLP: TFIBWideStringField
      FieldName = 'GID_DPLP'
      Size = 10
    end
    object DocADDKDRPLP: TFIBIntegerField
      FieldName = 'ADDKDRPLP'
    end
    object DocOPERATIONPLP: TFIBIntegerField
      FieldName = 'OPERATIONPLP'
    end
    object DocSUMUSNPLP: TFIBBCDField
      FieldName = 'SUMUSNPLP'
      Size = 2
      RoundByScale = True
    end
    object DocNALOG_STATUS_PLP: TFIBWideStringField
      FieldName = 'NALOG_STATUS_PLP'
      Size = 2
    end
    object DocNALOG_OSN_PLP: TFIBWideStringField
      FieldName = 'NALOG_OSN_PLP'
      Size = 2
    end
    object DocNALOG_NUM_PLP: TFIBWideStringField
      FieldName = 'NALOG_NUM_PLP'
      Size = 18
    end
    object DocNALOG_TPLAT_PLP: TFIBWideStringField
      FieldName = 'NALOG_TPLAT_PLP'
      Size = 2
    end
    object DocNALOG_KBK_PLP: TFIBWideStringField
      FieldName = 'NALOG_KBK_PLP'
      Size = 7
    end
    object DocNALOG_OKATO_PLP: TFIBWideStringField
      FieldName = 'NALOG_OKATO_PLP'
      Size = 11
    end
    object DocNALOG_PERIOD_PLP: TFIBWideStringField
      FieldName = 'NALOG_PERIOD_PLP'
      Size = 10
    end
    object DocNALOG_DATE_PLP: TFIBDateField
      FieldName = 'NALOG_DATE_PLP'
    end
    object DocIDBASE_DPLP: TFIBLargeIntField
      FieldName = 'IDBASE_DPLP'
    end
    object DocNDS_DPLP: TFIBIntegerField
      FieldName = 'NDS_DPLP'
    end
    object DocSUMNDS_DPLP: TFIBBCDField
      FieldName = 'SUMNDS_DPLP'
      Size = 2
      RoundByScale = True
    end
    object DocNAMEBSCHET: TFIBWideStringField
      FieldName = 'NAMEBSCHET'
      Size = 100
    end
    object DocNAMERSCHET: TFIBWideStringField
      FieldName = 'NAMERSCHET'
      Size = 100
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
    Left = 208
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
    Left = 208
    Top = 72
  end
  object NumDoc: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      
        'from DOC_PLP_GET_NUM_NEW_DOC (:PARAM_IDBASE,:PARAM_IDFIRM,:PARAM' +
        '_IDBSCHET)')
    Transaction = IBTr
    Left = 272
    Top = 16
  end
  object IBTrDvReg: TpFIBTransaction
    TimeoutAction = TARollback
    Left = 176
    Top = 200
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_PLP_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 192
    Top = 320
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_PLP_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 192
    Top = 272
    qoStartTransaction = True
  end
end
