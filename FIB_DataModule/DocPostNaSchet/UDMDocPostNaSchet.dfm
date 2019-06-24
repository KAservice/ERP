object DMDocPostNaSchet: TDMDocPostNaSchet
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 391
  Width = 407
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
  object IBTr: TpFIBTransaction
    TimeoutAction = TARollback
    Left = 216
    Top = 16
  end
  object IBTrDvReg: TpFIBTransaction
    TimeoutAction = TARollback
    Left = 184
    Top = 216
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
      'select GALLDOC. *, '
      '  FNAME_USER , '
      '  NAME_SINFBASE_OBMEN,'
      '  NAMEFIRM,'
      '  NAMEKLIENT,'
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
      'select GALLDOC. *, '
      '  FNAME_USER , '
      '  NAME_SINFBASE_OBMEN,'
      '  NAMEFIRM,'
      '  NAMEKLIENT,'
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
    Left = 160
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
      'UPDATE DPNS'
      'SET '
      '    IDDOCPNS = :IDDOCPNS,'
      '    IDBSCHPNS = :IDBSCHPNS,'
      '    IDRSCHPNS = :IDRSCHPNS,'
      '    NUMPNS = :NUMPNS,'
      '    DATEPNS = :DATEPNS,'
      '    NASNPNS = :NASNPNS,'
      '    GID_DPNS = :GID_DPNS,'
      '    ADDKDRPNS = :ADDKDRPNS,'
      '    OPERATIONPNS = :OPERATIONPNS,'
      '    SUMUSNPNS = :SUMUSNPNS,'
      '    IDBASE_DPNS = :IDBASE_DPNS,'
      '    NDS_DPNS = :NDS_DPNS,'
      '    SUMNDS_DPNS = :SUMNDS_DPNS'
      'WHERE'
      '    IDPNS = :OLD_IDPNS'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DPNS'
      'WHERE'
      '        IDPNS = :OLD_IDPNS'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DPNS('
      '    IDPNS,'
      '    IDDOCPNS,'
      '    IDBSCHPNS,'
      '    IDRSCHPNS,'
      '    NUMPNS,'
      '    DATEPNS,'
      '    NASNPNS,'
      '    GID_DPNS,'
      '    ADDKDRPNS,'
      '    OPERATIONPNS,'
      '    SUMUSNPNS,'
      '    IDBASE_DPNS,'
      '    NDS_DPNS,'
      '    SUMNDS_DPNS'
      ')'
      'VALUES('
      '    :IDPNS,'
      '    :IDDOCPNS,'
      '    :IDBSCHPNS,'
      '    :IDRSCHPNS,'
      '    :NUMPNS,'
      '    :DATEPNS,'
      '    :NASNPNS,'
      '    :GID_DPNS,'
      '    :ADDKDRPNS,'
      '    :OPERATIONPNS,'
      '    :SUMUSNPNS,'
      '    :IDBASE_DPNS,'
      '    :NDS_DPNS,'
      '    :SUMNDS_DPNS'
      ')')
    RefreshSQL.Strings = (
      'select  DPNS.*, '
      '    NAMEBSCHET,'
      '    NAMERSCHET'
      'from  DPNS'
      'left outer join SBSCHET on IDBSCHPNS=IDBSCHET'
      'left outer join SRSCHET on IDRSCHPNS=IDRSCHET'
      'where(  IDDOCPNS=:ID'
      '     ) and (     DPNS.IDPNS = :OLD_IDPNS'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select  DPNS.*, '
      '    NAMEBSCHET,'
      '    NAMERSCHET'
      'from  DPNS'
      'left outer join SBSCHET on IDBSCHPNS=IDBSCHET'
      'left outer join SRSCHET on IDRSCHPNS=IDRSCHET'
      'where IDDOCPNS=:ID')
    AutoUpdateOptions.UpdateTableName = 'DPNS'
    AutoUpdateOptions.KeyFields = 'IDPNS'
    AutoUpdateOptions.GeneratorName = 'GEN_DPNS_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 72
    poUseLargeIntField = True
    object DocDATEPNS: TFIBDateField
      FieldName = 'DATEPNS'
    end
    object DocOPERATIONPNS: TFIBSmallIntField
      FieldName = 'OPERATIONPNS'
    end
    object DocSUMUSNPNS: TFIBBCDField
      FieldName = 'SUMUSNPNS'
      Size = 2
      RoundByScale = True
    end
    object DocNDS_DPNS: TFIBIntegerField
      FieldName = 'NDS_DPNS'
    end
    object DocSUMNDS_DPNS: TFIBBCDField
      FieldName = 'SUMNDS_DPNS'
      Size = 2
      RoundByScale = True
    end
    object DocIDPNS: TFIBLargeIntField
      FieldName = 'IDPNS'
    end
    object DocIDDOCPNS: TFIBLargeIntField
      FieldName = 'IDDOCPNS'
    end
    object DocIDBSCHPNS: TFIBLargeIntField
      FieldName = 'IDBSCHPNS'
      OnChange = DocIDBSCHPNSChange
    end
    object DocIDRSCHPNS: TFIBLargeIntField
      FieldName = 'IDRSCHPNS'
    end
    object DocNASNPNS: TFIBWideStringField
      FieldName = 'NASNPNS'
      Size = 150
    end
    object DocGID_DPNS: TFIBWideStringField
      FieldName = 'GID_DPNS'
      Size = 10
    end
    object DocADDKDRPNS: TFIBIntegerField
      FieldName = 'ADDKDRPNS'
    end
    object DocIDBASE_DPNS: TFIBLargeIntField
      FieldName = 'IDBASE_DPNS'
    end
    object DocNAMEBSCHET: TFIBWideStringField
      FieldName = 'NAMEBSCHET'
      Size = 100
    end
    object DocNAMERSCHET: TFIBWideStringField
      FieldName = 'NAMERSCHET'
      Size = 100
    end
    object DocNUMPNS: TFIBWideStringField
      FieldName = 'NUMPNS'
      Size = 10
    end
  end
  object NumDoc: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      
        'from DOC_PNS_GET_NUM_NEW_DOC (:PARAM_IDBASE,:PARAM_IDFIRM,:PARAM' +
        '_IDBSCHET)')
    Transaction = IBTr
    Left = 304
    Top = 16
  end
  object IBTrUpdate: TpFIBTransaction
    TimeoutAction = TARollback
    Left = 224
    Top = 72
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_PNS_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 192
    Top = 320
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_PNS_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 192
    Top = 272
    qoStartTransaction = True
  end
end
