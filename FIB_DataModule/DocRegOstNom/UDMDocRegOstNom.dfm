object DMDocRegOstNom: TDMDocRegOstNom
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
      'UPDATE DRG_OSTNOM'
      'SET '
      '    IDDOC_DRG_OSTNOM = :IDDOC_DRG_OSTNOM,'
      '    DESCR_DRG_OSTNOM = :DESCR_DRG_OSTNOM,'
      '    IDBASE_DRG_OSTNOM = :IDBASE_DRG_OSTNOM'
      'WHERE'
      '    ID_DRG_OSTNOM = :OLD_ID_DRG_OSTNOM'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DRG_OSTNOM'
      'WHERE'
      '        ID_DRG_OSTNOM = :OLD_ID_DRG_OSTNOM'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DRG_OSTNOM('
      '    ID_DRG_OSTNOM,'
      '    IDDOC_DRG_OSTNOM,'
      '    DESCR_DRG_OSTNOM,'
      '    IDBASE_DRG_OSTNOM'
      ')'
      'VALUES('
      '    :ID_DRG_OSTNOM,'
      '    :IDDOC_DRG_OSTNOM,'
      '    :DESCR_DRG_OSTNOM,'
      '    :IDBASE_DRG_OSTNOM'
      ')')
    RefreshSQL.Strings = (
      'select drg_ostnom.*'
      'from  drg_ostnom'
      'where(  drg_ostnom.iddoc_drg_ostnom=:PARAM_IDDOC'
      '     ) and (     DRG_OSTNOM.ID_DRG_OSTNOM = :OLD_ID_DRG_OSTNOM'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select drg_ostnom.*'
      'from  drg_ostnom'
      'where drg_ostnom.iddoc_drg_ostnom=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'DRG_OSTNOM'
    AutoUpdateOptions.KeyFields = 'ID_DRG_OSTNOM'
    AutoUpdateOptions.GeneratorName = 'GEN_DRG_OSTNOM_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object DocID_DRG_OSTNOM: TFIBLargeIntField
      FieldName = 'ID_DRG_OSTNOM'
    end
    object DocIDDOC_DRG_OSTNOM: TFIBLargeIntField
      FieldName = 'IDDOC_DRG_OSTNOM'
    end
    object DocDESCR_DRG_OSTNOM: TFIBWideStringField
      FieldName = 'DESCR_DRG_OSTNOM'
      Size = 100
    end
    object DocIDBASE_DRG_OSTNOM: TFIBLargeIntField
      FieldName = 'IDBASE_DRG_OSTNOM'
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DRG_OSTNOMT'
      'SET '
      '    IDDOC_DRG_OSTNOMT = :IDDOC_DRG_OSTNOMT,'
      '    TDV_DRG_OSTNOMT = :TDV_DRG_OSTNOMT,'
      '    IDFIRM_DRG_OSTNOMT = :IDFIRM_DRG_OSTNOMT,'
      '    IDSKLAD_DRG_OSTNOMT = :IDSKLAD_DRG_OSTNOMT,'
      '    IDNOM_DRG_OSTNOMT = :IDNOM_DRG_OSTNOMT,'
      '    IDPART_DRG_OSTNOMT = :IDPART_DRG_OSTNOMT,'
      '    KOL_DRG_OSTNOMT = :KOL_DRG_OSTNOMT,'
      '    SUM_DRG_OSTNOMT = :SUM_DRG_OSTNOMT,'
      '    OPER_DRG_OSTNOMT = :OPER_DRG_OSTNOMT,'
      '    IDBASE_DRG_OSTNOMT = :IDBASE_DRG_OSTNOMT'
      'WHERE'
      '    ID_DRG_OSTNOMT = :OLD_ID_DRG_OSTNOMT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DRG_OSTNOMT'
      'WHERE'
      '        ID_DRG_OSTNOMT = :OLD_ID_DRG_OSTNOMT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DRG_OSTNOMT('
      '    ID_DRG_OSTNOMT,'
      '    IDDOC_DRG_OSTNOMT,'
      '    TDV_DRG_OSTNOMT,'
      '    IDFIRM_DRG_OSTNOMT,'
      '    IDSKLAD_DRG_OSTNOMT,'
      '    IDNOM_DRG_OSTNOMT,'
      '    IDPART_DRG_OSTNOMT,'
      '    KOL_DRG_OSTNOMT,'
      '    SUM_DRG_OSTNOMT,'
      '    OPER_DRG_OSTNOMT,'
      '    IDBASE_DRG_OSTNOMT'
      ')'
      'VALUES('
      '    :ID_DRG_OSTNOMT,'
      '    :IDDOC_DRG_OSTNOMT,'
      '    :TDV_DRG_OSTNOMT,'
      '    :IDFIRM_DRG_OSTNOMT,'
      '    :IDSKLAD_DRG_OSTNOMT,'
      '    :IDNOM_DRG_OSTNOMT,'
      '    :IDPART_DRG_OSTNOMT,'
      '    :KOL_DRG_OSTNOMT,'
      '    :SUM_DRG_OSTNOMT,'
      '    :OPER_DRG_OSTNOMT,'
      '    :IDBASE_DRG_OSTNOMT'
      ')')
    RefreshSQL.Strings = (
      'select drg_ostnomt.*,'
      '    sfirm.namefirm,'
      '    ssklad.namesklad,'
      '    snom.namenom,'
      '    spart.docpart'
      'from drg_ostnomt'
      
        'left outer join sfirm on drg_ostnomt.idfirm_drg_ostnomt=sfirm.id' +
        'firm'
      
        'left outer join ssklad on drg_ostnomt.idsklad_drg_ostnomt=ssklad' +
        '.idsklad'
      'left outer join snom on drg_ostnomt.idnom_drg_ostnomt=snom.idnom'
      
        'left outer join spart on drg_ostnomt.idpart_drg_ostnomt=spart.id' +
        'part'
      'where(  drg_ostnomt.iddoc_drg_ostnomt=:PARAM_IDDOC'
      
        '     ) and (     DRG_OSTNOMT.ID_DRG_OSTNOMT = :OLD_ID_DRG_OSTNOM' +
        'T'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select drg_ostnomt.*,'
      '    sfirm.namefirm,'
      '    ssklad.namesklad,'
      '    snom.namenom,'
      '    spart.docpart'
      'from drg_ostnomt'
      
        'left outer join sfirm on drg_ostnomt.idfirm_drg_ostnomt=sfirm.id' +
        'firm'
      
        'left outer join ssklad on drg_ostnomt.idsklad_drg_ostnomt=ssklad' +
        '.idsklad'
      'left outer join snom on drg_ostnomt.idnom_drg_ostnomt=snom.idnom'
      
        'left outer join spart on drg_ostnomt.idpart_drg_ostnomt=spart.id' +
        'part'
      'where drg_ostnomt.iddoc_drg_ostnomt=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'DRG_OSTNOMT'
    AutoUpdateOptions.KeyFields = 'ID_DRG_OSTNOMT'
    AutoUpdateOptions.GeneratorName = 'GEN_DRG_OSTNOMT_ID'
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
    object DocTTDV_DRG_OSTNOMT: TFIBSmallIntField
      FieldName = 'TDV_DRG_OSTNOMT'
    end
    object DocTKOL_DRG_OSTNOMT: TFIBBCDField
      FieldName = 'KOL_DRG_OSTNOMT'
      Size = 3
      RoundByScale = True
    end
    object DocTSUM_DRG_OSTNOMT: TFIBBCDField
      FieldName = 'SUM_DRG_OSTNOMT'
      Size = 2
      RoundByScale = True
    end
    object DocTOPER_DRG_OSTNOMT: TFIBSmallIntField
      FieldName = 'OPER_DRG_OSTNOMT'
    end
    object DocTID_DRG_OSTNOMT: TFIBLargeIntField
      FieldName = 'ID_DRG_OSTNOMT'
    end
    object DocTIDDOC_DRG_OSTNOMT: TFIBLargeIntField
      FieldName = 'IDDOC_DRG_OSTNOMT'
    end
    object DocTIDFIRM_DRG_OSTNOMT: TFIBLargeIntField
      FieldName = 'IDFIRM_DRG_OSTNOMT'
    end
    object DocTIDSKLAD_DRG_OSTNOMT: TFIBLargeIntField
      FieldName = 'IDSKLAD_DRG_OSTNOMT'
    end
    object DocTIDNOM_DRG_OSTNOMT: TFIBLargeIntField
      FieldName = 'IDNOM_DRG_OSTNOMT'
    end
    object DocTIDPART_DRG_OSTNOMT: TFIBLargeIntField
      FieldName = 'IDPART_DRG_OSTNOMT'
    end
    object DocTIDBASE_DRG_OSTNOMT: TFIBLargeIntField
      FieldName = 'IDBASE_DRG_OSTNOMT'
    end
    object DocTNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 100
    end
    object DocTNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 100
    end
    object DocTNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 100
    end
    object DocTDOCPART: TFIBWideStringField
      FieldName = 'DOCPART'
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
      'from DOC_RG_OSTNOM_GET_NUM_NEW_DOC (:PARAM_IDBASE)')
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
      'EXECUTE PROCEDURE DOC_RGOSTNOM_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 304
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_RGOSTNOM_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 240
    qoStartTransaction = True
  end
end
