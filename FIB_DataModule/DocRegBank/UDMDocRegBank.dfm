object DMDocRegBank: TDMDocRegBank
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
    object DocAllTDOC: TFIBWideStringField
      FieldName = 'TDOC'
      Size = 10
    end
    object DocAllIDDOC: TFIBLargeIntField
      FieldName = 'IDDOC'
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
      'UPDATE DRG_BANK'
      'SET '
      '    IDBASE_DRG_BANK = :IDBASE_DRG_BANK,'
      '    DESCR_DRG_BANK = :DESCR_DRG_BANK,'
      '    IDDOC_DRG_BANK = :IDDOC_DRG_BANK'
      'WHERE'
      '    ID_DRG_BANK = :OLD_ID_DRG_BANK'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DRG_BANK'
      'WHERE'
      '        ID_DRG_BANK = :OLD_ID_DRG_BANK'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DRG_BANK('
      '    ID_DRG_BANK,'
      '    IDBASE_DRG_BANK,'
      '    DESCR_DRG_BANK,'
      '    IDDOC_DRG_BANK'
      ')'
      'VALUES('
      '    :ID_DRG_BANK,'
      '    :IDBASE_DRG_BANK,'
      '    :DESCR_DRG_BANK,'
      '    :IDDOC_DRG_BANK'
      ')')
    RefreshSQL.Strings = (
      'select drg_bank.*'
      'from  drg_bank'
      'where(  drg_bank.iddoc_drg_bank=:PARAM_IDDOC'
      '     ) and (     DRG_BANK.ID_DRG_BANK = :OLD_ID_DRG_BANK'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select drg_bank.*'
      'from  drg_bank'
      'where drg_bank.iddoc_drg_bank=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'DRG_BANK'
    AutoUpdateOptions.KeyFields = 'ID_DRG_BANK'
    AutoUpdateOptions.GeneratorName = 'GEN_DRG_BANK_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object DocID_DRG_BANK: TFIBLargeIntField
      FieldName = 'ID_DRG_BANK'
    end
    object DocIDBASE_DRG_BANK: TFIBLargeIntField
      FieldName = 'IDBASE_DRG_BANK'
    end
    object DocDESCR_DRG_BANK: TFIBWideStringField
      FieldName = 'DESCR_DRG_BANK'
      Size = 100
    end
    object DocIDDOC_DRG_BANK: TFIBLargeIntField
      FieldName = 'IDDOC_DRG_BANK'
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DRG_BANKT'
      'SET '
      '    IDDOC_DRG_BANKT = :IDDOC_DRG_BANKT,'
      '    TDV_DRG_BANKT = :TDV_DRG_BANKT,'
      '    IDFIRM_DRG_BANKT = :IDFIRM_DRG_BANKT,'
      '    IDBSCHET_DRG_BANKT = :IDBSCHET_DRG_BANKT,'
      '    OPER_DRG_BANKT = :OPER_DRG_BANKT,'
      '    SUM_DRG_BANKT = :SUM_DRG_BANKT,'
      '    IDBASE_DRG_BANKT = :IDBASE_DRG_BANKT'
      'WHERE'
      '    ID_DRG_BANKT = :OLD_ID_DRG_BANKT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DRG_BANKT'
      'WHERE'
      '        ID_DRG_BANKT = :OLD_ID_DRG_BANKT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DRG_BANKT('
      '    ID_DRG_BANKT,'
      '    IDDOC_DRG_BANKT,'
      '    TDV_DRG_BANKT,'
      '    IDFIRM_DRG_BANKT,'
      '    IDBSCHET_DRG_BANKT,'
      '    OPER_DRG_BANKT,'
      '    SUM_DRG_BANKT,'
      '    IDBASE_DRG_BANKT'
      ')'
      'VALUES('
      '    :ID_DRG_BANKT,'
      '    :IDDOC_DRG_BANKT,'
      '    :TDV_DRG_BANKT,'
      '    :IDFIRM_DRG_BANKT,'
      '    :IDBSCHET_DRG_BANKT,'
      '    :OPER_DRG_BANKT,'
      '    :SUM_DRG_BANKT,'
      '    :IDBASE_DRG_BANKT'
      ')')
    RefreshSQL.Strings = (
      'select drg_bankt.*,'
      '    sfirm.namefirm,'
      '    sbschet.namebschet'
      'from  drg_bankt'
      'left outer join sfirm on drg_bankt.idfirm_drg_bankt=sfirm.idfirm'
      
        'left outer join sbschet on drg_bankt.idbschet_drg_bankt=sbschet.' +
        'idbschet'
      'where(  drg_bankt.iddoc_drg_bankt=:PARAM_IDDOC'
      '     ) and (     DRG_BANKT.ID_DRG_BANKT = :OLD_ID_DRG_BANKT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select drg_bankt.*,'
      '    sfirm.namefirm,'
      '    sbschet.namebschet'
      'from  drg_bankt'
      'left outer join sfirm on drg_bankt.idfirm_drg_bankt=sfirm.idfirm'
      
        'left outer join sbschet on drg_bankt.idbschet_drg_bankt=sbschet.' +
        'idbschet'
      'where drg_bankt.iddoc_drg_bankt=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'DRG_BANKT'
    AutoUpdateOptions.KeyFields = 'ID_DRG_BANKT'
    AutoUpdateOptions.GeneratorName = 'GEN_DRG_BANKT_ID'
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
    object DocTTDV_DRG_BANKT: TFIBSmallIntField
      FieldName = 'TDV_DRG_BANKT'
    end
    object DocTOPER_DRG_BANKT: TFIBSmallIntField
      FieldName = 'OPER_DRG_BANKT'
    end
    object DocTSUM_DRG_BANKT: TFIBBCDField
      FieldName = 'SUM_DRG_BANKT'
      Size = 2
      RoundByScale = True
    end
    object DocTID_DRG_BANKT: TFIBLargeIntField
      FieldName = 'ID_DRG_BANKT'
    end
    object DocTIDDOC_DRG_BANKT: TFIBLargeIntField
      FieldName = 'IDDOC_DRG_BANKT'
    end
    object DocTIDFIRM_DRG_BANKT: TFIBLargeIntField
      FieldName = 'IDFIRM_DRG_BANKT'
    end
    object DocTIDBSCHET_DRG_BANKT: TFIBLargeIntField
      FieldName = 'IDBSCHET_DRG_BANKT'
    end
    object DocTIDBASE_DRG_BANKT: TFIBLargeIntField
      FieldName = 'IDBASE_DRG_BANKT'
    end
    object DocTNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 100
    end
    object DocTNAMEBSCHET: TFIBWideStringField
      FieldName = 'NAMEBSCHET'
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
      'from DOC_RG_BANK_GET_NUM_NEW_DOC (:PARAM_IDBASE)'
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
      'EXECUTE PROCEDURE DOC_RGBANK_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 304
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_RGBANK_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 240
    qoStartTransaction = True
  end
end
