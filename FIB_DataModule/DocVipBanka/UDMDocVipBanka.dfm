object DMDocVipBanka: TDMDocVipBanka
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 369
  Width = 398
  object DataSourceDoc: TDataSource
    DataSet = Doc
    Left = 72
    Top = 64
  end
  object DataSourceDocT: TDataSource
    DataSet = DocT
    Left = 72
    Top = 112
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
      
        'select GALLDOC.*, FNAME_USER , NAME_SINFBASE_OBMEN, NAMEFIRM, NA' +
        'MESKLAD, '
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from '
      '  GALLDOC'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      'left outer join SFIRM on IDFIRMDOC=IDFIRM'
      'left outer join SSKLAD on IDSKLDOC=IDSKLAD'
      
        'left outer join SPROJECT on galldoc.idproject_galldoc=sproject.i' +
        'd_sproject'
      
        'left outer join sbusiness_oper on galldoc.idbusinop_galldoc=sbus' +
        'iness_oper.id_sbusiness_oper'
      'where(  '
      '  IDDOC=:PARAM_IDDOC'
      '     ) and (     GALLDOC.IDDOC = :OLD_IDDOC'
      '     )'
      '     ')
    SelectSQL.Strings = (
      
        'select GALLDOC.*, FNAME_USER , NAME_SINFBASE_OBMEN, NAMEFIRM, NA' +
        'MESKLAD, '
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from '
      '  GALLDOC'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      'left outer join SFIRM on IDFIRMDOC=IDFIRM'
      'left outer join SSKLAD on IDSKLDOC=IDSKLAD'
      
        'left outer join SPROJECT on galldoc.idproject_galldoc=sproject.i' +
        'd_sproject'
      
        'left outer join sbusiness_oper on galldoc.idbusinop_galldoc=sbus' +
        'iness_oper.id_sbusiness_oper'
      'where '
      '  IDDOC=:PARAM_IDDOC ')
    AutoUpdateOptions.UpdateTableName = 'GALLDOC'
    AutoUpdateOptions.KeyFields = 'IDDOC'
    AutoUpdateOptions.GeneratorName = 'GEN_GALLDOC_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 16
    object DocAllIDDOC: TFIBBCDField
      FieldName = 'IDDOC'
      Size = 0
      RoundByScale = True
    end
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
    object DocAllSUMDOC: TFIBBCDField
      FieldName = 'SUMDOC'
      Size = 2
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
    object DocAllTDOC: TFIBWideStringField
      FieldName = 'TDOC'
      Size = 10
    end
    object DocAllGID_DOC: TFIBWideStringField
      FieldName = 'GID_DOC'
      Size = 10
    end
    object DocAllTYPEEXTDOC: TFIBIntegerField
      FieldName = 'TYPEEXTDOC'
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
    object DocAllNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 200
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
      Size = 12
    end
  end
  object Doc: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DVIPBANK'
      'SET '
      '    IDDOC_DVIPBANK = :IDDOC_DVIPBANK,'
      '    IDBASE_DVIPBANK = :IDBASE_DVIPBANK,'
      '    PRIM_DVIPBANK = :PRIM_DVIPBANK,'
      '    IDBSCHET_DVIPBANK = :IDBSCHET_DVIPBANK'
      'WHERE'
      '    ID_DVIPBANK = :OLD_ID_DVIPBANK'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DVIPBANK'
      'WHERE'
      '        ID_DVIPBANK = :OLD_ID_DVIPBANK'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DVIPBANK('
      '    ID_DVIPBANK,'
      '    IDDOC_DVIPBANK,'
      '    IDBASE_DVIPBANK,'
      '    PRIM_DVIPBANK,'
      '    IDBSCHET_DVIPBANK'
      ')'
      'VALUES('
      '    :ID_DVIPBANK,'
      '    :IDDOC_DVIPBANK,'
      '    :IDBASE_DVIPBANK,'
      '    :PRIM_DVIPBANK,'
      '    :IDBSCHET_DVIPBANK'
      ')')
    RefreshSQL.Strings = (
      'select dvipbank.*,'
      '    sbschet.namebschet'
      'from  dvipbank'
      
        'left outer join sbschet on dvipbank.idbschet_dvipbank=sbschet.id' +
        'bschet'
      'where(  dvipbank.iddoc_dvipbank=:PARAM_IDDOC'
      '     ) and (     DVIPBANK.ID_DVIPBANK = :OLD_ID_DVIPBANK'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select dvipbank.*,'
      '    sbschet.namebschet'
      'from  dvipbank'
      
        'left outer join sbschet on dvipbank.idbschet_dvipbank=sbschet.id' +
        'bschet'
      'where dvipbank.iddoc_dvipbank=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'DVIPBANK'
    AutoUpdateOptions.KeyFields = 'ID_DVIPBANK'
    AutoUpdateOptions.GeneratorName = 'GEN_DVIPBANK_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    object DocID_DVIPBANK: TFIBBCDField
      FieldName = 'ID_DVIPBANK'
      Size = 0
      RoundByScale = True
    end
    object DocIDDOC_DVIPBANK: TFIBBCDField
      FieldName = 'IDDOC_DVIPBANK'
      Size = 0
      RoundByScale = True
    end
    object DocIDBASE_DVIPBANK: TFIBBCDField
      FieldName = 'IDBASE_DVIPBANK'
      Size = 0
      RoundByScale = True
    end
    object DocIDBSCHET_DVIPBANK: TFIBBCDField
      FieldName = 'IDBSCHET_DVIPBANK'
      OnChange = DocIDBSCHET_DVIPBANKChange
      Size = 0
      RoundByScale = True
    end
    object DocPRIM_DVIPBANK: TFIBWideStringField
      FieldName = 'PRIM_DVIPBANK'
      Size = 150
    end
    object DocNAMEBSCHET: TFIBWideStringField
      FieldName = 'NAMEBSCHET'
      Size = 100
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DVIPBANKT'
      'SET '
      '    IDBASE_DVIPBANKT = :IDBASE_DVIPBANKT,'
      '    IDDOC_DVIPBANKT = :IDDOC_DVIPBANKT,'
      '    IDKLIENT_DVIPBANKT = :IDKLIENT_DVIPBANKT,'
      '    NUMPP_DVIPBANKT = :NUMPP_DVIPBANKT,'
      '    DATEPP_DVIPBANKT = :DATEPP_DVIPBANKT,'
      '    TEXTPP_DVIPBANKT = :TEXTPP_DVIPBANKT,'
      '    PRIHOD_DVIPBANKT = :PRIHOD_DVIPBANKT,'
      '    PRIHODNDS_DVIPBANKT = :PRIHODNDS_DVIPBANKT,'
      '    PRIHODSUMNDS_DVIPBANKT = :PRIHODSUMNDS_DVIPBANKT,'
      '    RASHOD_DVIPBANKT = :RASHOD_DVIPBANKT,'
      '    RASHODNDS_DVIPBANKT = :RASHODNDS_DVIPBANKT,'
      '    RASHODSUMNDS_DVIPBANKT = :RASHODSUMNDS_DVIPBANKT,'
      '    OPER_DVIPBANKT = :OPER_DVIPBANKT'
      'WHERE'
      '    ID_DVIPBANKT = :OLD_ID_DVIPBANKT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DVIPBANKT'
      'WHERE'
      '        ID_DVIPBANKT = :OLD_ID_DVIPBANKT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DVIPBANKT('
      '    ID_DVIPBANKT,'
      '    IDBASE_DVIPBANKT,'
      '    IDDOC_DVIPBANKT,'
      '    IDKLIENT_DVIPBANKT,'
      '    NUMPP_DVIPBANKT,'
      '    DATEPP_DVIPBANKT,'
      '    TEXTPP_DVIPBANKT,'
      '    PRIHOD_DVIPBANKT,'
      '    PRIHODNDS_DVIPBANKT,'
      '    PRIHODSUMNDS_DVIPBANKT,'
      '    RASHOD_DVIPBANKT,'
      '    RASHODNDS_DVIPBANKT,'
      '    RASHODSUMNDS_DVIPBANKT,'
      '    OPER_DVIPBANKT'
      ')'
      'VALUES('
      '    :ID_DVIPBANKT,'
      '    :IDBASE_DVIPBANKT,'
      '    :IDDOC_DVIPBANKT,'
      '    :IDKLIENT_DVIPBANKT,'
      '    :NUMPP_DVIPBANKT,'
      '    :DATEPP_DVIPBANKT,'
      '    :TEXTPP_DVIPBANKT,'
      '    :PRIHOD_DVIPBANKT,'
      '    :PRIHODNDS_DVIPBANKT,'
      '    :PRIHODSUMNDS_DVIPBANKT,'
      '    :RASHOD_DVIPBANKT,'
      '    :RASHODNDS_DVIPBANKT,'
      '    :RASHODSUMNDS_DVIPBANKT,'
      '    :OPER_DVIPBANKT'
      ')')
    RefreshSQL.Strings = (
      'select dvipbankt.*,'
      '    sklient.nameklient'
      'from  dvipbankt'
      
        'left outer join sklient on dvipbankt.idklient_dvipbankt=sklient.' +
        'idklient'
      'where(  dvipbankt.iddoc_dvipbankt=:PARAM_IDDOC'
      '     ) and (     DVIPBANKT.ID_DVIPBANKT = :OLD_ID_DVIPBANKT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select dvipbankt.*,'
      '    sklient.nameklient'
      'from  dvipbankt'
      
        'left outer join sklient on dvipbankt.idklient_dvipbankt=sklient.' +
        'idklient'
      'where dvipbankt.iddoc_dvipbankt=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'DVIPBANKT'
    AutoUpdateOptions.KeyFields = 'ID_DVIPBANKT'
    AutoUpdateOptions.GeneratorName = 'GEN_DVIPBANKT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnCalcFields = DocTCalcFields
    OnNewRecord = DocTNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 112
    object DocTRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object DocTID_DVIPBANKT: TFIBBCDField
      FieldName = 'ID_DVIPBANKT'
      Size = 0
      RoundByScale = True
    end
    object DocTIDBASE_DVIPBANKT: TFIBBCDField
      FieldName = 'IDBASE_DVIPBANKT'
      Size = 0
      RoundByScale = True
    end
    object DocTIDDOC_DVIPBANKT: TFIBBCDField
      FieldName = 'IDDOC_DVIPBANKT'
      Size = 0
      RoundByScale = True
    end
    object DocTIDKLIENT_DVIPBANKT: TFIBBCDField
      FieldName = 'IDKLIENT_DVIPBANKT'
      Size = 0
      RoundByScale = True
    end
    object DocTDATEPP_DVIPBANKT: TFIBDateField
      FieldName = 'DATEPP_DVIPBANKT'
    end
    object DocTPRIHOD_DVIPBANKT: TFIBBCDField
      FieldName = 'PRIHOD_DVIPBANKT'
      Size = 2
      RoundByScale = True
    end
    object DocTPRIHODNDS_DVIPBANKT: TFIBIntegerField
      FieldName = 'PRIHODNDS_DVIPBANKT'
    end
    object DocTPRIHODSUMNDS_DVIPBANKT: TFIBBCDField
      FieldName = 'PRIHODSUMNDS_DVIPBANKT'
      Size = 2
      RoundByScale = True
    end
    object DocTRASHOD_DVIPBANKT: TFIBBCDField
      FieldName = 'RASHOD_DVIPBANKT'
      Size = 2
      RoundByScale = True
    end
    object DocTRASHODNDS_DVIPBANKT: TFIBIntegerField
      FieldName = 'RASHODNDS_DVIPBANKT'
    end
    object DocTRASHODSUMNDS_DVIPBANKT: TFIBBCDField
      FieldName = 'RASHODSUMNDS_DVIPBANKT'
      Size = 2
      RoundByScale = True
    end
    object DocTOPER_DVIPBANKT: TFIBIntegerField
      FieldName = 'OPER_DVIPBANKT'
    end
    object DocTNUMPP_DVIPBANKT: TFIBWideStringField
      FieldName = 'NUMPP_DVIPBANKT'
      Size = 15
    end
    object DocTTEXTPP_DVIPBANKT: TFIBWideStringField
      FieldName = 'TEXTPP_DVIPBANKT'
      Size = 150
    end
    object DocTNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
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
    Top = 64
  end
  object IBTrDvReg: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 24
    Top = 272
  end
  object NumDoc: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      
        'from DOC_VIPBANK_GET_NUM_NEW_DOC (:PARAM_IDBASE,:PARAM_IDFIRM,:P' +
        'ARAM_IDBSCHET)')
    Transaction = IBTr
    Left = 296
    Top = 16
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 336
    Top = 176
    qoStartTransaction = True
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_VIPBANK_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 304
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_VIPBANK_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 240
    qoStartTransaction = True
  end
end
