object DMDocKorrVS: TDMDocKorrVS
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
        'MESKLAD,'
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
        'MESKLAD,'
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
    poUseLargeIntField = True
    object DocAllPOSDOC: TFIBDateTimeField
      FieldName = 'POSDOC'
      OnChange = DocAllPOSDOCChange
      DisplayFormat = 'c'
    end
    object DocAllPRDOC: TFIBSmallIntField
      FieldName = 'PRDOC'
    end
    object DocAllTDOC: TFIBWideStringField
      FieldName = 'TDOC'
      Size = 10
    end
    object DocAllNUMDOC: TFIBIntegerField
      FieldName = 'NUMDOC'
    end
    object DocAllSUMDOC: TFIBBCDField
      FieldName = 'SUMDOC'
      Size = 2
      RoundByScale = True
    end
    object DocAllGID_DOC: TFIBWideStringField
      FieldName = 'GID_DOC'
      Size = 10
    end
    object DocAllPREFIKSDOC: TFIBWideStringField
      FieldName = 'PREFIKSDOC'
      Size = 2
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
    object DocAllIDDOC: TFIBLargeIntField
      FieldName = 'IDDOC'
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
    object DocAllIDDOCOSNDOC: TFIBLargeIntField
      FieldName = 'IDDOCOSNDOC'
    end
    object DocAllIDEXTDOC: TFIBLargeIntField
      FieldName = 'IDEXTDOC'
    end
    object DocAllIDBASE_GALLDOC: TFIBLargeIntField
      FieldName = 'IDBASE_GALLDOC'
      OnChange = DocAllIDBASE_GALLDOCChange
    end
    object DocAllIDPROJECT_GALLDOC: TFIBLargeIntField
      FieldName = 'IDPROJECT_GALLDOC'
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
      'UPDATE DKORRVS'
      'SET '
      '    IDDOC_DKORRVS = :IDDOC_DKORRVS,'
      '    IDBASE_DKORRVS = :IDBASE_DKORRVS,'
      '    PRIM_DKORRVS = :PRIM_DKORRVS'
      'WHERE'
      '    ID_DKORRVS = :OLD_ID_DKORRVS'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DKORRVS'
      'WHERE'
      '        ID_DKORRVS = :OLD_ID_DKORRVS'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DKORRVS('
      '    ID_DKORRVS,'
      '    IDDOC_DKORRVS,'
      '    IDBASE_DKORRVS,'
      '    PRIM_DKORRVS'
      ')'
      'VALUES('
      '    :ID_DKORRVS,'
      '    :IDDOC_DKORRVS,'
      '    :IDBASE_DKORRVS,'
      '    :PRIM_DKORRVS'
      ')')
    RefreshSQL.Strings = (
      'select dkorrvs.*'
      'from  dkorrvs'
      'where(  dkorrvs.iddoc_dkorrvs=:PARAM_IDDOC'
      '     ) and (     DKORRVS.ID_DKORRVS = :OLD_ID_DKORRVS'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select dkorrvs.*'
      'from  dkorrvs'
      'where dkorrvs.iddoc_dkorrvs=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'DKORRVS'
    AutoUpdateOptions.KeyFields = 'ID_DKORRVS'
    AutoUpdateOptions.GeneratorName = 'GEN_DKORRVS_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object DocID_DKORRVS: TFIBLargeIntField
      FieldName = 'ID_DKORRVS'
    end
    object DocIDDOC_DKORRVS: TFIBLargeIntField
      FieldName = 'IDDOC_DKORRVS'
    end
    object DocIDBASE_DKORRVS: TFIBLargeIntField
      FieldName = 'IDBASE_DKORRVS'
    end
    object DocPRIM_DKORRVS: TFIBWideStringField
      FieldName = 'PRIM_DKORRVS'
      Size = 150
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DKORRVST'
      'SET '
      '    IDDOC_DKORRVST = :IDDOC_DKORRVST,'
      '    IDBASE_DKORRVST = :IDBASE_DKORRVST,'
      '    IDKLIENT_DKORRVST = :IDKLIENT_DKORRVST,'
      '    PRIHOD_DKORRVST = :PRIHOD_DKORRVST,'
      '    RASHOD_DKORRVST = :RASHOD_DKORRVST,'
      '    DVREGPAYSALE_DKORRVST = :DVREGPAYSALE_DKORRVST'
      'WHERE'
      '    ID_DKORRVST = :OLD_ID_DKORRVST'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DKORRVST'
      'WHERE'
      '        ID_DKORRVST = :OLD_ID_DKORRVST'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DKORRVST('
      '    ID_DKORRVST,'
      '    IDDOC_DKORRVST,'
      '    IDBASE_DKORRVST,'
      '    IDKLIENT_DKORRVST,'
      '    PRIHOD_DKORRVST,'
      '    RASHOD_DKORRVST,'
      '    DVREGPAYSALE_DKORRVST'
      ')'
      'VALUES('
      '    :ID_DKORRVST,'
      '    :IDDOC_DKORRVST,'
      '    :IDBASE_DKORRVST,'
      '    :IDKLIENT_DKORRVST,'
      '    :PRIHOD_DKORRVST,'
      '    :RASHOD_DKORRVST,'
      '    :DVREGPAYSALE_DKORRVST'
      ')')
    RefreshSQL.Strings = (
      'select dkorrvst.*,'
      '    sklient.nameklient'
      'from  dkorrvst'
      
        'left outer join sklient on dkorrvst.idklient_dkorrvst=sklient.id' +
        'klient'
      'where(  dkorrvst.iddoc_dkorrvst=:PARAM_IDDOC'
      '     ) and (     DKORRVST.ID_DKORRVST = :OLD_ID_DKORRVST'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select dkorrvst.*,'
      '    sklient.nameklient'
      'from  dkorrvst'
      
        'left outer join sklient on dkorrvst.idklient_dkorrvst=sklient.id' +
        'klient'
      'where dkorrvst.iddoc_dkorrvst=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'DKORRVST'
    AutoUpdateOptions.KeyFields = 'ID_DKORRVST'
    AutoUpdateOptions.GeneratorName = 'GEN_DKORRVST_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnCalcFields = DocTCalcFields
    OnNewRecord = DocTNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 112
    poUseLargeIntField = True
    object DocTID_DKORRVST: TFIBLargeIntField
      FieldName = 'ID_DKORRVST'
    end
    object DocTIDDOC_DKORRVST: TFIBLargeIntField
      FieldName = 'IDDOC_DKORRVST'
    end
    object DocTIDBASE_DKORRVST: TFIBLargeIntField
      FieldName = 'IDBASE_DKORRVST'
    end
    object DocTIDKLIENT_DKORRVST: TFIBLargeIntField
      FieldName = 'IDKLIENT_DKORRVST'
    end
    object DocTPRIHOD_DKORRVST: TFIBBCDField
      FieldName = 'PRIHOD_DKORRVST'
      Size = 2
      RoundByScale = True
    end
    object DocTRASHOD_DKORRVST: TFIBBCDField
      FieldName = 'RASHOD_DKORRVST'
      Size = 2
      RoundByScale = True
    end
    object DocTDVREGPAYSALE_DKORRVST: TFIBIntegerField
      FieldName = 'DVREGPAYSALE_DKORRVST'
    end
    object DocTNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 100
    end
    object DocTRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
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
      'from DOC_KORRVS_GET_NUM_NEW_DOC (:PARAM_IDBASE,:PARAM_IDFIRM)'
      '')
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
      'EXECUTE PROCEDURE DOC_KORRVS_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 304
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_KORRVS_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 240
    qoStartTransaction = True
  end
end
