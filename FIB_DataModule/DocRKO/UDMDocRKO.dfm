object DMDocRKO: TDMDocRKO
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 394
  Width = 710
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
      'select  GALLDOC.* , FNAME_USER,'
      ' NAME_SINFBASE_OBMEN,'
      '  NAMEFIRM,'
      '  NAMEKLIENT, '
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
      'select  GALLDOC.* , FNAME_USER,'
      ' NAME_SINFBASE_OBMEN,'
      '  NAMEFIRM,'
      '  NAMEKLIENT, '
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
    Left = 168
    Top = 16
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
    object DocAllIDDOC: TFIBBCDField
      FieldName = 'IDDOC'
      Size = 0
      RoundByScale = True
    end
    object DocAllIDFIRMDOC: TFIBBCDField
      FieldName = 'IDFIRMDOC'
      OnChange = DocAllIDFIRMDOCChange
      Size = 0
      RoundByScale = True
    end
    object DocAllIDSKLDOC: TFIBBCDField
      FieldName = 'IDSKLDOC'
      Size = 0
      RoundByScale = True
    end
    object DocAllIDKLDOC: TFIBBCDField
      FieldName = 'IDKLDOC'
      Size = 0
      RoundByScale = True
    end
    object DocAllIDDOGDOC: TFIBBCDField
      FieldName = 'IDDOGDOC'
      Size = 0
      RoundByScale = True
    end
    object DocAllIDUSERDOC: TFIBBCDField
      FieldName = 'IDUSERDOC'
      Size = 0
      RoundByScale = True
    end
    object DocAllIDDOCOSNDOC: TFIBBCDField
      FieldName = 'IDDOCOSNDOC'
      Size = 0
      RoundByScale = True
    end
    object DocAllIDEXTDOC: TFIBBCDField
      FieldName = 'IDEXTDOC'
      Size = 0
      RoundByScale = True
    end
    object DocAllIDBASE_GALLDOC: TFIBBCDField
      FieldName = 'IDBASE_GALLDOC'
      OnChange = DocAllIDBASE_GALLDOCChange
      Size = 0
      RoundByScale = True
    end
    object DocAllGID_DOC: TFIBWideStringField
      FieldName = 'GID_DOC'
      Size = 10
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
    object DocAllTDOC: TFIBWideStringField
      FieldName = 'TDOC'
      Size = 10
    end
    object DocAllTYPEEXTDOC: TFIBIntegerField
      FieldName = 'TYPEEXTDOC'
    end
    object DocAllIDPROJECT_GALLDOC: TFIBBCDField
      FieldName = 'IDPROJECT_GALLDOC'
      Size = 0
      RoundByScale = True
    end
    object DocAllIDBUSINOP_GALLDOC: TFIBBCDField
      FieldName = 'IDBUSINOP_GALLDOC'
      Size = 0
      RoundByScale = True
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
      Size = 9
    end
  end
  object Doc: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DRKO'
      'SET '
      '    IDDOCRKO = :IDDOCRKO,'
      '    IDKKMRKO = :IDKKMRKO,'
      '    IDKLRKO = :IDKLRKO,'
      '    VIDATRKO = :VIDATRKO,'
      '    OSNRKO = :OSNRKO,'
      '    PRILRKO = :PRILRKO,'
      '    DOCPOLRKO = :DOCPOLRKO,'
      '    GID_DRKO = :GID_DRKO,'
      '    ADDKDRRKO = :ADDKDRRKO,'
      '    SUMUSNRKO = :SUMUSNRKO,'
      '    OPERATIONRKO = :OPERATIONRKO,'
      '    NKLRKO = :NKLRKO,'
      '    NCHECKRKO = :NCHECKRKO,'
      '    MODELRKO = :MODELRKO,'
      '    REGNUMRKO = :REGNUMRKO,'
      '    SAVNUMRKO = :SAVNUMRKO,'
      '    IDBASE_DRKO = :IDBASE_DRKO,'
      '    NDS_DRKO = :NDS_DRKO,'
      '    SUMNDS_DRKO = :SUMNDS_DRKO,'
      '    KORRSCHET_DRKO = :KORRSCHET_DRKO'
      'WHERE'
      '    IDRKO = :OLD_IDRKO'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DRKO'
      'WHERE'
      '        IDRKO = :OLD_IDRKO'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DRKO('
      '    IDRKO,'
      '    IDDOCRKO,'
      '    IDKKMRKO,'
      '    IDKLRKO,'
      '    VIDATRKO,'
      '    OSNRKO,'
      '    PRILRKO,'
      '    DOCPOLRKO,'
      '    GID_DRKO,'
      '    ADDKDRRKO,'
      '    SUMUSNRKO,'
      '    OPERATIONRKO,'
      '    NKLRKO,'
      '    NCHECKRKO,'
      '    MODELRKO,'
      '    REGNUMRKO,'
      '    SAVNUMRKO,'
      '    IDBASE_DRKO,'
      '    NDS_DRKO,'
      '    SUMNDS_DRKO,'
      '    KORRSCHET_DRKO'
      ')'
      'VALUES('
      '    :IDRKO,'
      '    :IDDOCRKO,'
      '    :IDKKMRKO,'
      '    :IDKLRKO,'
      '    :VIDATRKO,'
      '    :OSNRKO,'
      '    :PRILRKO,'
      '    :DOCPOLRKO,'
      '    :GID_DRKO,'
      '    :ADDKDRRKO,'
      '    :SUMUSNRKO,'
      '    :OPERATIONRKO,'
      '    :NKLRKO,'
      '    :NCHECKRKO,'
      '    :MODELRKO,'
      '    :REGNUMRKO,'
      '    :SAVNUMRKO,'
      '    :IDBASE_DRKO,'
      '    :NDS_DRKO,'
      '    :SUMNDS_DRKO,'
      '    :KORRSCHET_DRKO'
      ')')
    RefreshSQL.Strings = (
      'select DRKO.*,'
      '  NAMEKKM '
      'from  DRKO'
      'left outer join SKKM on IDKKMRKO=IDKKM'
      'where(  IDDOCRKO=:ID'
      '     ) and (     DRKO.IDRKO = :OLD_IDRKO'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select DRKO.*,'
      '  NAMEKKM '
      'from  DRKO'
      'left outer join SKKM on IDKKMRKO=IDKKM'
      'where IDDOCRKO=:ID')
    AutoUpdateOptions.UpdateTableName = 'DRKO'
    AutoUpdateOptions.KeyFields = 'IDRKO'
    AutoUpdateOptions.GeneratorName = 'GEN_DRKO_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 80
    object DocADDKDRRKO: TFIBSmallIntField
      FieldName = 'ADDKDRRKO'
    end
    object DocSUMUSNRKO: TFIBBCDField
      FieldName = 'SUMUSNRKO'
      Size = 2
      RoundByScale = True
    end
    object DocOPERATIONRKO: TFIBSmallIntField
      FieldName = 'OPERATIONRKO'
    end
    object DocIDRKO: TFIBBCDField
      FieldName = 'IDRKO'
      Size = 0
      RoundByScale = True
    end
    object DocIDDOCRKO: TFIBBCDField
      FieldName = 'IDDOCRKO'
      Size = 0
      RoundByScale = True
    end
    object DocIDKKMRKO: TFIBBCDField
      FieldName = 'IDKKMRKO'
      OnChange = DocIDKKMRKOChange
      Size = 0
      RoundByScale = True
    end
    object DocIDKLRKO: TFIBBCDField
      FieldName = 'IDKLRKO'
      Size = 0
      RoundByScale = True
    end
    object DocIDBASE_DRKO: TFIBBCDField
      FieldName = 'IDBASE_DRKO'
      Size = 0
      RoundByScale = True
    end
    object DocNDS_DRKO: TFIBIntegerField
      FieldName = 'NDS_DRKO'
    end
    object DocSUMNDS_DRKO: TFIBBCDField
      FieldName = 'SUMNDS_DRKO'
      Size = 2
      RoundByScale = True
    end
    object DocVIDATRKO: TFIBWideStringField
      FieldName = 'VIDATRKO'
      Size = 150
    end
    object DocOSNRKO: TFIBWideStringField
      FieldName = 'OSNRKO'
      Size = 150
    end
    object DocPRILRKO: TFIBWideStringField
      FieldName = 'PRILRKO'
      Size = 150
    end
    object DocDOCPOLRKO: TFIBWideStringField
      FieldName = 'DOCPOLRKO'
      Size = 150
    end
    object DocGID_DRKO: TFIBWideStringField
      FieldName = 'GID_DRKO'
      Size = 10
    end
    object DocNKLRKO: TFIBIntegerField
      FieldName = 'NKLRKO'
    end
    object DocNCHECKRKO: TFIBIntegerField
      FieldName = 'NCHECKRKO'
    end
    object DocMODELRKO: TFIBWideStringField
      FieldName = 'MODELRKO'
    end
    object DocREGNUMRKO: TFIBWideStringField
      FieldName = 'REGNUMRKO'
    end
    object DocSAVNUMRKO: TFIBWideStringField
      FieldName = 'SAVNUMRKO'
    end
    object DocNAMEKKM: TFIBWideStringField
      FieldName = 'NAMEKKM'
      Size = 200
    end
    object DocKORRSCHET_DRKO: TFIBWideStringField
      FieldName = 'KORRSCHET_DRKO'
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
    Left = 240
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
    Left = 240
    Top = 80
  end
  object NumDoc: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      
        'from DOC_RKO_GET_NUM_NEW_DOC (:PARAM_IDBASE,:PARAM_IDFIRM,:PARAM' +
        '_IDKASSA)')
    Transaction = IBTr
    Left = 328
    Top = 16
  end
  object IBTrDvReg: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 208
    Top = 144
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_RKO_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 256
    Top = 320
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_RKO_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 256
    Top = 272
    qoStartTransaction = True
  end
end
