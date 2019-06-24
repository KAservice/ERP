object DMDocRegCardBalance: TDMDocRegCardBalance
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
    object DocAllIDUSERDOC: TFIBBCDField
      FieldName = 'IDUSERDOC'
      Size = 0
      RoundByScale = True
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
    object DocAllTDOC: TFIBWideStringField
      FieldName = 'TDOC'
      Size = 10
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
      'UPDATE DRG_CARD_BALANCE'
      'SET '
      '    IDBASE_DRG_CARD_BALANCE = :IDBASE_DRG_CARD_BALANCE,'
      '    IDDOC_DRG_CARD_BALANCE = :IDDOC_DRG_CARD_BALANCE,'
      '    DESCR_DRG_CARD_BALANCE = :DESCR_DRG_CARD_BALANCE'
      'WHERE'
      '    ID_DRG_CARD_BALANCE = :OLD_ID_DRG_CARD_BALANCE'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DRG_CARD_BALANCE'
      'WHERE'
      '        ID_DRG_CARD_BALANCE = :OLD_ID_DRG_CARD_BALANCE'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DRG_CARD_BALANCE('
      '    ID_DRG_CARD_BALANCE,'
      '    IDBASE_DRG_CARD_BALANCE,'
      '    IDDOC_DRG_CARD_BALANCE,'
      '    DESCR_DRG_CARD_BALANCE'
      ')'
      'VALUES('
      '    :ID_DRG_CARD_BALANCE,'
      '    :IDBASE_DRG_CARD_BALANCE,'
      '    :IDDOC_DRG_CARD_BALANCE,'
      '    :DESCR_DRG_CARD_BALANCE'
      ')')
    RefreshSQL.Strings = (
      'select drg_card_balance.*'
      'from  drg_card_balance'
      'where(  drg_card_balance.iddoc_drg_card_balance=:PARAM_IDDOC'
      
        '     ) and (     DRG_CARD_BALANCE.ID_DRG_CARD_BALANCE = :OLD_ID_' +
        'DRG_CARD_BALANCE'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select drg_card_balance.*'
      'from  drg_card_balance'
      'where drg_card_balance.iddoc_drg_card_balance=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'DRG_CARD_BALANCE'
    AutoUpdateOptions.KeyFields = 'ID_DRG_CARD_BALANCE'
    AutoUpdateOptions.GeneratorName = 'GEN_DRG_CARD_BALANCE_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object DocID_DRG_CARD_BALANCE: TFIBLargeIntField
      FieldName = 'ID_DRG_CARD_BALANCE'
    end
    object DocIDBASE_DRG_CARD_BALANCE: TFIBLargeIntField
      FieldName = 'IDBASE_DRG_CARD_BALANCE'
    end
    object DocIDDOC_DRG_CARD_BALANCE: TFIBLargeIntField
      FieldName = 'IDDOC_DRG_CARD_BALANCE'
    end
    object DocDESCR_DRG_CARD_BALANCE: TFIBWideStringField
      FieldName = 'DESCR_DRG_CARD_BALANCE'
      Size = 150
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DRG_CARD_BALANCET'
      'SET '
      '    IDBASE_DRG_CARD_BALANCET = :IDBASE_DRG_CARD_BALANCET,'
      '    IDDOC_DRG_CARD_BALANCET = :IDDOC_DRG_CARD_BALANCET,'
      '    TDV_DRG_CARD_BALANCET = :TDV_DRG_CARD_BALANCET,'
      '    IDFIRM_DRG_CARD_BALANCET = :IDFIRM_DRG_CARD_BALANCET,'
      '    IDCARD_DRG_CARD_BALANCET = :IDCARD_DRG_CARD_BALANCET,'
      '    SUM_DRG_CARD_BALANCET = :SUM_DRG_CARD_BALANCET,'
      '    OPER_DRG_CARD_BALANCET = :OPER_DRG_CARD_BALANCET'
      'WHERE'
      '    ID_DRG_CARD_BALANCET = :OLD_ID_DRG_CARD_BALANCET'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DRG_CARD_BALANCET'
      'WHERE'
      '        ID_DRG_CARD_BALANCET = :OLD_ID_DRG_CARD_BALANCET'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DRG_CARD_BALANCET('
      '    ID_DRG_CARD_BALANCET,'
      '    IDBASE_DRG_CARD_BALANCET,'
      '    IDDOC_DRG_CARD_BALANCET,'
      '    TDV_DRG_CARD_BALANCET,'
      '    IDFIRM_DRG_CARD_BALANCET,'
      '    IDCARD_DRG_CARD_BALANCET,'
      '    SUM_DRG_CARD_BALANCET,'
      '    OPER_DRG_CARD_BALANCET'
      ')'
      'VALUES('
      '    :ID_DRG_CARD_BALANCET,'
      '    :IDBASE_DRG_CARD_BALANCET,'
      '    :IDDOC_DRG_CARD_BALANCET,'
      '    :TDV_DRG_CARD_BALANCET,'
      '    :IDFIRM_DRG_CARD_BALANCET,'
      '    :IDCARD_DRG_CARD_BALANCET,'
      '    :SUM_DRG_CARD_BALANCET,'
      '    :OPER_DRG_CARD_BALANCET'
      ')')
    RefreshSQL.Strings = (
      'select drg_card_balancet.*,'
      '    sfirm.namefirm,'
      '    sdiscount_card.name_sdiscount_card'
      'from  drg_card_balancet'
      
        'left outer join sfirm on drg_card_balancet.idfirm_drg_card_balan' +
        'cet=sfirm.idfirm'
      
        'left outer join sdiscount_card on drg_card_balancet.idcard_drg_c' +
        'ard_balancet=sdiscount_card.id_sdiscount_card'
      'where(  drg_card_balancet.iddoc_drg_card_balancet=:PARAM_IDDOC'
      
        '     ) and (     DRG_CARD_BALANCET.ID_DRG_CARD_BALANCET = :OLD_I' +
        'D_DRG_CARD_BALANCET'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select drg_card_balancet.*,'
      '    sfirm.namefirm,'
      '    sdiscount_card.name_sdiscount_card'
      'from  drg_card_balancet'
      
        'left outer join sfirm on drg_card_balancet.idfirm_drg_card_balan' +
        'cet=sfirm.idfirm'
      
        'left outer join sdiscount_card on drg_card_balancet.idcard_drg_c' +
        'ard_balancet=sdiscount_card.id_sdiscount_card'
      'where drg_card_balancet.iddoc_drg_card_balancet=:PARAM_IDDOC')
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
    object DocTID_DRG_CARD_BALANCET: TFIBLargeIntField
      FieldName = 'ID_DRG_CARD_BALANCET'
    end
    object DocTIDBASE_DRG_CARD_BALANCET: TFIBLargeIntField
      FieldName = 'IDBASE_DRG_CARD_BALANCET'
    end
    object DocTIDDOC_DRG_CARD_BALANCET: TFIBLargeIntField
      FieldName = 'IDDOC_DRG_CARD_BALANCET'
    end
    object DocTTDV_DRG_CARD_BALANCET: TFIBSmallIntField
      FieldName = 'TDV_DRG_CARD_BALANCET'
    end
    object DocTIDFIRM_DRG_CARD_BALANCET: TFIBLargeIntField
      FieldName = 'IDFIRM_DRG_CARD_BALANCET'
    end
    object DocTIDCARD_DRG_CARD_BALANCET: TFIBLargeIntField
      FieldName = 'IDCARD_DRG_CARD_BALANCET'
    end
    object DocTSUM_DRG_CARD_BALANCET: TFIBBCDField
      FieldName = 'SUM_DRG_CARD_BALANCET'
      Size = 2
      RoundByScale = True
    end
    object DocTOPER_DRG_CARD_BALANCET: TFIBIntegerField
      FieldName = 'OPER_DRG_CARD_BALANCET'
    end
    object DocTRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object DocTNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 100
    end
    object DocTNAME_SDISCOUNT_CARD: TFIBWideStringField
      FieldName = 'NAME_SDISCOUNT_CARD'
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
      'from DOC_RG_CARDBAL_GET_NUM_NEW_DOC (:PARAM_IDBASE)')
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
      
        'EXECUTE PROCEDURE DOC_RGCARD_BALANCE_CANCEL_DVREG(:PARAM_IDDOC,0' +
        ',0,0)')
    Left = 96
    Top = 304
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_RGCARD_BALANCE_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 240
    qoStartTransaction = True
  end
end
