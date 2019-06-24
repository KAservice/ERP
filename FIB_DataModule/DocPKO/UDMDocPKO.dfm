object DMDocPKO: TDMDocPKO
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 437
  Width = 726
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
      '     FNAME_USER ,'
      '     NAME_SINFBASE_OBMEN,'
      '     NAMEFIRM,'
      '     NAMEKLIENT,'
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from '
      '  GALLDOC'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      'left outer join SFIRM on IDFIRMDOC=IDFIRM'
      'left outer join SKLIENT on IDKLDOC=IDKLIENT'
      
        'left outer join SPROJECT on galldoc.idproject_galldoc=sproject.i' +
        'd_sproject'
      
        'left outer join sbusiness_oper on galldoc.idbusinop_galldoc=sbus' +
        'iness_oper.id_sbusiness_oper'
      'where(  '
      '  IDDOC=:ID'
      '     ) and (     GALLDOC.IDDOC = :OLD_IDDOC'
      '     )'
      '     ')
    SelectSQL.Strings = (
      'select GALLDOC.*,'
      '     FNAME_USER ,'
      '     NAME_SINFBASE_OBMEN,'
      '     NAMEFIRM,'
      '     NAMEKLIENT,'
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from '
      '  GALLDOC'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      'left outer join SFIRM on IDFIRMDOC=IDFIRM'
      'left outer join SKLIENT on IDKLDOC=IDKLIENT'
      
        'left outer join SPROJECT on galldoc.idproject_galldoc=sproject.i' +
        'd_sproject'
      
        'left outer join sbusiness_oper on galldoc.idbusinop_galldoc=sbus' +
        'iness_oper.id_sbusiness_oper'
      'where '
      '  IDDOC=:ID ')
    AutoUpdateOptions.UpdateTableName = 'GALLDOC'
    AutoUpdateOptions.KeyFields = 'IDDOC'
    AutoUpdateOptions.GeneratorName = 'GEN_GALLDOC_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 168
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
      'UPDATE DPKO'
      'SET '
      '    IDDOCPKO = :IDDOCPKO,'
      '    IDKKMPKO = :IDKKMPKO,'
      '    IDKLPKO = :IDKLPKO,'
      '    PROTPKO = :PROTPKO,'
      '    OSNPKO = :OSNPKO,'
      '    PRILPKO = :PRILPKO,'
      '    GID_DPKO = :GID_DPKO,'
      '    ADDKDRPKO = :ADDKDRPKO,'
      '    OPERATIONPKO = :OPERATIONPKO,'
      '    SUMUSNPKO = :SUMUSNPKO,'
      '    NKLPKO = :NKLPKO,'
      '    NCHECKPKO = :NCHECKPKO,'
      '    MODELPKO = :MODELPKO,'
      '    REGNUMPKO = :REGNUMPKO,'
      '    SAVNUMPKO = :SAVNUMPKO,'
      '    IDBASE_DPKO = :IDBASE_DPKO,'
      '    NDS_DPKO = :NDS_DPKO,'
      '    SUMNDS_DPKO = :SUMNDS_DPKO,'
      '    KORRSCHET_DPKO = :KORRSCHET_DPKO'
      'WHERE'
      '    IDPKO = :OLD_IDPKO'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DPKO'
      'WHERE'
      '        IDPKO = :OLD_IDPKO'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DPKO('
      '    IDPKO,'
      '    IDDOCPKO,'
      '    IDKKMPKO,'
      '    IDKLPKO,'
      '    PROTPKO,'
      '    OSNPKO,'
      '    PRILPKO,'
      '    GID_DPKO,'
      '    ADDKDRPKO,'
      '    OPERATIONPKO,'
      '    SUMUSNPKO,'
      '    NKLPKO,'
      '    NCHECKPKO,'
      '    MODELPKO,'
      '    REGNUMPKO,'
      '    SAVNUMPKO,'
      '    IDBASE_DPKO,'
      '    NDS_DPKO,'
      '    SUMNDS_DPKO,'
      '    KORRSCHET_DPKO'
      ')'
      'VALUES('
      '    :IDPKO,'
      '    :IDDOCPKO,'
      '    :IDKKMPKO,'
      '    :IDKLPKO,'
      '    :PROTPKO,'
      '    :OSNPKO,'
      '    :PRILPKO,'
      '    :GID_DPKO,'
      '    :ADDKDRPKO,'
      '    :OPERATIONPKO,'
      '    :SUMUSNPKO,'
      '    :NKLPKO,'
      '    :NCHECKPKO,'
      '    :MODELPKO,'
      '    :REGNUMPKO,'
      '    :SAVNUMPKO,'
      '    :IDBASE_DPKO,'
      '    :NDS_DPKO,'
      '    :SUMNDS_DPKO,'
      '    :KORRSCHET_DPKO'
      ')')
    RefreshSQL.Strings = (
      'select DPKO.*, NAMEKKM '
      'from  DPKO'
      'left outer join SKKM on IDKKMPKO=IDKKM'
      'where(  IDDOCPKO=:ID'
      '     ) and (     DPKO.IDPKO = :OLD_IDPKO'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select DPKO.*, NAMEKKM '
      'from  DPKO'
      'left outer join SKKM on IDKKMPKO=IDKKM'
      'where IDDOCPKO=:ID')
    AutoUpdateOptions.UpdateTableName = 'DPKO'
    AutoUpdateOptions.KeyFields = 'IDPKO'
    AutoUpdateOptions.GeneratorName = 'GEN_DPKO_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 72
    poUseLargeIntField = True
    object DocADDKDRPKO: TFIBSmallIntField
      FieldName = 'ADDKDRPKO'
    end
    object DocSUMUSNPKO: TFIBBCDField
      FieldName = 'SUMUSNPKO'
      Size = 2
      RoundByScale = True
    end
    object DocNKLPKO: TFIBIntegerField
      FieldName = 'NKLPKO'
    end
    object DocNCHECKPKO: TFIBIntegerField
      FieldName = 'NCHECKPKO'
    end
    object DocNDS_DPKO: TFIBIntegerField
      FieldName = 'NDS_DPKO'
    end
    object DocSUMNDS_DPKO: TFIBBCDField
      FieldName = 'SUMNDS_DPKO'
      Size = 2
      RoundByScale = True
    end
    object DocIDPKO: TFIBLargeIntField
      FieldName = 'IDPKO'
    end
    object DocIDDOCPKO: TFIBLargeIntField
      FieldName = 'IDDOCPKO'
    end
    object DocIDKKMPKO: TFIBLargeIntField
      FieldName = 'IDKKMPKO'
      OnChange = DocIDKKMPKOChange
    end
    object DocIDKLPKO: TFIBLargeIntField
      FieldName = 'IDKLPKO'
    end
    object DocPROTPKO: TFIBWideStringField
      FieldName = 'PROTPKO'
      Size = 200
    end
    object DocOSNPKO: TFIBWideStringField
      FieldName = 'OSNPKO'
      Size = 150
    end
    object DocPRILPKO: TFIBWideStringField
      FieldName = 'PRILPKO'
      Size = 150
    end
    object DocGID_DPKO: TFIBWideStringField
      FieldName = 'GID_DPKO'
      Size = 10
    end
    object DocOPERATIONPKO: TFIBIntegerField
      FieldName = 'OPERATIONPKO'
    end
    object DocMODELPKO: TFIBWideStringField
      FieldName = 'MODELPKO'
    end
    object DocREGNUMPKO: TFIBWideStringField
      FieldName = 'REGNUMPKO'
    end
    object DocSAVNUMPKO: TFIBWideStringField
      FieldName = 'SAVNUMPKO'
    end
    object DocIDBASE_DPKO: TFIBLargeIntField
      FieldName = 'IDBASE_DPKO'
    end
    object DocNAMEKKM: TFIBWideStringField
      FieldName = 'NAMEKKM'
      Size = 200
    end
    object DocKORRSCHET_DPKO: TFIBWideStringField
      FieldName = 'KORRSCHET_DPKO'
      Size = 10
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
    Top = 72
  end
  object IBTrDvReg: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 168
    Top = 136
  end
  object NumDoc: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      
        'from DOC_PKO_GET_NUM_NEW_DOC (:PARAM_IDBASE,:PARAM_IDFIRM,:PARAM' +
        '_IDKASSA)')
    Left = 328
    Top = 16
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_PKO_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 192
    Top = 320
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_PKO_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 192
    Top = 272
    qoStartTransaction = True
  end
end
