object DMDocRegVsRasch: TDMDocRegVsRasch
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
      'select GALLDOC.*, FNAME_USER , NAME_SINFBASE_OBMEN, '
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from '
      '  GALLDOC'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      
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
      'select GALLDOC.*, FNAME_USER , NAME_SINFBASE_OBMEN, '
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from '
      '  GALLDOC'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      
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
    object DocAllIDFIRMDOC: TFIBLargeIntField
      FieldName = 'IDFIRMDOC'
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
    object DocAllTDOC: TFIBWideStringField
      FieldName = 'TDOC'
      Size = 10
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
      'UPDATE DRG_VSRASCH'
      'SET '
      '    IDDOC_DRG_VSRASCH = :IDDOC_DRG_VSRASCH,'
      '    DESCR_DRG_VSRASCH = :DESCR_DRG_VSRASCH,'
      '    IDBASE_DRG_VSRASCH = :IDBASE_DRG_VSRASCH'
      'WHERE'
      '    ID_DRG_VSRASCH = :OLD_ID_DRG_VSRASCH'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DRG_VSRASCH'
      'WHERE'
      '        ID_DRG_VSRASCH = :OLD_ID_DRG_VSRASCH'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DRG_VSRASCH('
      '    ID_DRG_VSRASCH,'
      '    IDDOC_DRG_VSRASCH,'
      '    DESCR_DRG_VSRASCH,'
      '    IDBASE_DRG_VSRASCH'
      ')'
      'VALUES('
      '    :ID_DRG_VSRASCH,'
      '    :IDDOC_DRG_VSRASCH,'
      '    :DESCR_DRG_VSRASCH,'
      '    :IDBASE_DRG_VSRASCH'
      ')')
    RefreshSQL.Strings = (
      'select drg_vsrasch.*'
      'from  drg_vsrasch'
      'where(  drg_vsrasch.iddoc_drg_vsrasch=:PARAM_IDDOC'
      
        '     ) and (     DRG_VSRASCH.ID_DRG_VSRASCH = :OLD_ID_DRG_VSRASC' +
        'H'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select drg_vsrasch.*'
      'from  drg_vsrasch'
      'where drg_vsrasch.iddoc_drg_vsrasch=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'DRG_VSRASCH'
    AutoUpdateOptions.KeyFields = 'ID_DRG_VSRASCH'
    AutoUpdateOptions.GeneratorName = 'GEN_DRG_VSRASCH_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object DocID_DRG_VSRASCH: TFIBLargeIntField
      FieldName = 'ID_DRG_VSRASCH'
    end
    object DocIDDOC_DRG_VSRASCH: TFIBLargeIntField
      FieldName = 'IDDOC_DRG_VSRASCH'
    end
    object DocDESCR_DRG_VSRASCH: TFIBWideStringField
      FieldName = 'DESCR_DRG_VSRASCH'
      Size = 100
    end
    object DocIDBASE_DRG_VSRASCH: TFIBLargeIntField
      FieldName = 'IDBASE_DRG_VSRASCH'
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DRG_VSRASCHT'
      'SET '
      '    IDDOC_DRG_VSRASCHT = :IDDOC_DRG_VSRASCHT,'
      '    TDV_DRG_VSRASCHT = :TDV_DRG_VSRASCHT,'
      '    IDFIRM_DRG_VSRASCHT = :IDFIRM_DRG_VSRASCHT,'
      '    IDKLIENT_DRG_VSRASCHT = :IDKLIENT_DRG_VSRASCHT,'
      '    SUM_DRG_VSRASCHT = :SUM_DRG_VSRASCHT,'
      '    IDBASE_DRG_VSRASCHT = :IDBASE_DRG_VSRASCHT,'
      '    OPER_DRG_VSRASCHT = :OPER_DRG_VSRASCHT'
      'WHERE'
      '    ID_DRG_VSRASCHT = :OLD_ID_DRG_VSRASCHT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DRG_VSRASCHT'
      'WHERE'
      '        ID_DRG_VSRASCHT = :OLD_ID_DRG_VSRASCHT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DRG_VSRASCHT('
      '    ID_DRG_VSRASCHT,'
      '    IDDOC_DRG_VSRASCHT,'
      '    TDV_DRG_VSRASCHT,'
      '    IDFIRM_DRG_VSRASCHT,'
      '    IDKLIENT_DRG_VSRASCHT,'
      '    SUM_DRG_VSRASCHT,'
      '    IDBASE_DRG_VSRASCHT,'
      '    OPER_DRG_VSRASCHT'
      ')'
      'VALUES('
      '    :ID_DRG_VSRASCHT,'
      '    :IDDOC_DRG_VSRASCHT,'
      '    :TDV_DRG_VSRASCHT,'
      '    :IDFIRM_DRG_VSRASCHT,'
      '    :IDKLIENT_DRG_VSRASCHT,'
      '    :SUM_DRG_VSRASCHT,'
      '    :IDBASE_DRG_VSRASCHT,'
      '    :OPER_DRG_VSRASCHT'
      ')')
    RefreshSQL.Strings = (
      'select drg_vsrascht.*,'
      '    sfirm.namefirm,'
      '    sklient.nameklient'
      'from  drg_vsrascht'
      
        'left outer join sfirm on drg_vsrascht.idfirm_drg_vsrascht=sfirm.' +
        'idfirm'
      
        'left outer join sklient on drg_vsrascht.idklient_drg_vsrascht=sk' +
        'lient.idklient'
      'where(  drg_vsrascht.iddoc_drg_vsrascht=:PARAM_IDDOC'
      
        '     ) and (     DRG_VSRASCHT.ID_DRG_VSRASCHT = :OLD_ID_DRG_VSRA' +
        'SCHT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select drg_vsrascht.*,'
      '    sfirm.namefirm,'
      '    sklient.nameklient'
      'from  drg_vsrascht'
      
        'left outer join sfirm on drg_vsrascht.idfirm_drg_vsrascht=sfirm.' +
        'idfirm'
      
        'left outer join sklient on drg_vsrascht.idklient_drg_vsrascht=sk' +
        'lient.idklient'
      'where drg_vsrascht.iddoc_drg_vsrascht=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'DRG_VSRASCHT'
    AutoUpdateOptions.KeyFields = 'ID_DRG_VSRASCHT'
    AutoUpdateOptions.GeneratorName = 'GEN_DRG_VSRASCHT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnCalcFields = DocTCalcFields
    OnNewRecord = DocTNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 112
    poUseLargeIntField = True
    object DocTRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object DocTTDV_DRG_VSRASCHT: TFIBSmallIntField
      FieldName = 'TDV_DRG_VSRASCHT'
    end
    object DocTSUM_DRG_VSRASCHT: TFIBBCDField
      FieldName = 'SUM_DRG_VSRASCHT'
      Size = 2
      RoundByScale = True
    end
    object DocTOPER_DRG_VSRASCHT: TFIBIntegerField
      FieldName = 'OPER_DRG_VSRASCHT'
    end
    object DocTID_DRG_VSRASCHT: TFIBLargeIntField
      FieldName = 'ID_DRG_VSRASCHT'
    end
    object DocTIDDOC_DRG_VSRASCHT: TFIBLargeIntField
      FieldName = 'IDDOC_DRG_VSRASCHT'
    end
    object DocTIDFIRM_DRG_VSRASCHT: TFIBLargeIntField
      FieldName = 'IDFIRM_DRG_VSRASCHT'
    end
    object DocTIDKLIENT_DRG_VSRASCHT: TFIBLargeIntField
      FieldName = 'IDKLIENT_DRG_VSRASCHT'
    end
    object DocTIDBASE_DRG_VSRASCHT: TFIBLargeIntField
      FieldName = 'IDBASE_DRG_VSRASCHT'
    end
    object DocTNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 100
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
      'from DOC_RG_VSRASCH_GET_NUM_NEW_DOC (:PARAM_IDBASE)')
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
      'EXECUTE PROCEDURE DOC_RGVSRASCH_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 304
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_RGVSRASCH_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 240
    qoStartTransaction = True
  end
end
