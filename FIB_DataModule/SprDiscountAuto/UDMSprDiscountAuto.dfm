object DMSprDiscountAuto: TDMSprDiscountAuto
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 326
  Width = 363
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 40
    Top = 16
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 40
    Top = 96
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select  SDISCOUNT_AUTO.*,'
      '    ssklad.NAMESKLAD,'
      '    sgrpnom.namegn,'
      '    svidnom.name_svidnom'
      'from SDISCOUNT_AUTO'
      'left outer join SSKLAD on IDSKLAD_SDISCOUNT_AUTO=IDSKLAD'
      
        'left outer join sgrpnom on sdiscount_auto.idgrpnom_sdiscount_aut' +
        'o=sgrpnom.idgn'
      
        'left outer join svidnom on sdiscount_auto.idvidnom_sdiscount_aut' +
        'o=svidnom.id_svidnom')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object TableID_SDISCOUNT_AUTO: TFIBLargeIntField
      FieldName = 'ID_SDISCOUNT_AUTO'
    end
    object TableGID_SDISCOUNT_AUTO: TFIBWideStringField
      FieldName = 'GID_SDISCOUNT_AUTO'
      Size = 10
    end
    object TableNAME_SDISCOUNT_AUTO: TFIBWideStringField
      FieldName = 'NAME_SDISCOUNT_AUTO'
      Size = 200
    end
    object TableACT_SDISCOUNT_AUTO: TFIBSmallIntField
      FieldName = 'ACT_SDISCOUNT_AUTO'
    end
    object TableNACH_SDISCOUNT_AUTO: TFIBDateTimeField
      FieldName = 'NACH_SDISCOUNT_AUTO'
    end
    object TableCON_SDISCOUNT_AUTO: TFIBDateTimeField
      FieldName = 'CON_SDISCOUNT_AUTO'
    end
    object TablePRSK_SDISCOUNT_AUTO: TFIBBCDField
      FieldName = 'PRSK_SDISCOUNT_AUTO'
      Size = 2
      RoundByScale = True
    end
    object TableSUM_SDISCOUNT_AUTO: TFIBBCDField
      FieldName = 'SUM_SDISCOUNT_AUTO'
      Size = 2
      RoundByScale = True
    end
    object TableTIME_NACH_SDISCOUNT_AUTO: TFIBTimeField
      FieldName = 'TIME_NACH_SDISCOUNT_AUTO'
    end
    object TableTIME_CON_SDISCOUNT_AUTO: TFIBTimeField
      FieldName = 'TIME_CON_SDISCOUNT_AUTO'
    end
    object TableDAY_SDISCOUNT_AUTO: TFIBSmallIntField
      FieldName = 'DAY_SDISCOUNT_AUTO'
    end
    object TableIDVIDNOM_SDISCOUNT_AUTO: TFIBLargeIntField
      FieldName = 'IDVIDNOM_SDISCOUNT_AUTO'
    end
    object TableIDSKLAD_SDISCOUNT_AUTO: TFIBLargeIntField
      FieldName = 'IDSKLAD_SDISCOUNT_AUTO'
    end
    object TableIDBASE_SDISCOUNT_AUTO: TFIBLargeIntField
      FieldName = 'IDBASE_SDISCOUNT_AUTO'
    end
    object TableNUM_SKIDKI_SDISCOUNT_AUTO: TFIBSmallIntField
      FieldName = 'NUM_SKIDKI_SDISCOUNT_AUTO'
    end
    object TableIDGRPNOM_SDISCOUNT_AUTO: TFIBLargeIntField
      FieldName = 'IDGRPNOM_SDISCOUNT_AUTO'
    end
    object TableTYPE_ACTION_SDISCOUNT_AUTO: TFIBIntegerField
      FieldName = 'TYPE_ACTION_SDISCOUNT_AUTO'
    end
    object TableMESSAGE_SDISCOUNT_AUTO: TFIBWideStringField
      FieldName = 'MESSAGE_SDISCOUNT_AUTO'
      Size = 150
    end
    object TableNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 200
    end
    object TableNAMEGN: TFIBWideStringField
      FieldName = 'NAMEGN'
      Size = 200
    end
    object TableNAME_SVIDNOM: TFIBWideStringField
      FieldName = 'NAME_SVIDNOM'
      Size = 200
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SDISCOUNT_AUTO'
      'SET '
      '    GID_SDISCOUNT_AUTO = :GID_SDISCOUNT_AUTO,'
      '    NAME_SDISCOUNT_AUTO = :NAME_SDISCOUNT_AUTO,'
      '    ACT_SDISCOUNT_AUTO = :ACT_SDISCOUNT_AUTO,'
      '    NACH_SDISCOUNT_AUTO = :NACH_SDISCOUNT_AUTO,'
      '    CON_SDISCOUNT_AUTO = :CON_SDISCOUNT_AUTO,'
      '    PRSK_SDISCOUNT_AUTO = :PRSK_SDISCOUNT_AUTO,'
      '    SUM_SDISCOUNT_AUTO = :SUM_SDISCOUNT_AUTO,'
      '    TIME_NACH_SDISCOUNT_AUTO = :TIME_NACH_SDISCOUNT_AUTO,'
      '    TIME_CON_SDISCOUNT_AUTO = :TIME_CON_SDISCOUNT_AUTO,'
      '    DAY_SDISCOUNT_AUTO = :DAY_SDISCOUNT_AUTO,'
      '    IDVIDNOM_SDISCOUNT_AUTO = :IDVIDNOM_SDISCOUNT_AUTO,'
      '    IDSKLAD_SDISCOUNT_AUTO = :IDSKLAD_SDISCOUNT_AUTO,'
      '    IDBASE_SDISCOUNT_AUTO = :IDBASE_SDISCOUNT_AUTO,'
      '    NUM_SKIDKI_SDISCOUNT_AUTO = :NUM_SKIDKI_SDISCOUNT_AUTO,'
      '    IDGRPNOM_SDISCOUNT_AUTO = :IDGRPNOM_SDISCOUNT_AUTO,'
      '    TYPE_ACTION_SDISCOUNT_AUTO = :TYPE_ACTION_SDISCOUNT_AUTO,'
      '    MESSAGE_SDISCOUNT_AUTO = :MESSAGE_SDISCOUNT_AUTO'
      'WHERE'
      '    ID_SDISCOUNT_AUTO = :OLD_ID_SDISCOUNT_AUTO'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SDISCOUNT_AUTO'
      'WHERE'
      '        ID_SDISCOUNT_AUTO = :OLD_ID_SDISCOUNT_AUTO'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SDISCOUNT_AUTO('
      '    ID_SDISCOUNT_AUTO,'
      '    GID_SDISCOUNT_AUTO,'
      '    NAME_SDISCOUNT_AUTO,'
      '    ACT_SDISCOUNT_AUTO,'
      '    NACH_SDISCOUNT_AUTO,'
      '    CON_SDISCOUNT_AUTO,'
      '    PRSK_SDISCOUNT_AUTO,'
      '    SUM_SDISCOUNT_AUTO,'
      '    TIME_NACH_SDISCOUNT_AUTO,'
      '    TIME_CON_SDISCOUNT_AUTO,'
      '    DAY_SDISCOUNT_AUTO,'
      '    IDVIDNOM_SDISCOUNT_AUTO,'
      '    IDSKLAD_SDISCOUNT_AUTO,'
      '    IDBASE_SDISCOUNT_AUTO,'
      '    NUM_SKIDKI_SDISCOUNT_AUTO,'
      '    IDGRPNOM_SDISCOUNT_AUTO,'
      '    TYPE_ACTION_SDISCOUNT_AUTO,'
      '    MESSAGE_SDISCOUNT_AUTO'
      ')'
      'VALUES('
      '    :ID_SDISCOUNT_AUTO,'
      '    :GID_SDISCOUNT_AUTO,'
      '    :NAME_SDISCOUNT_AUTO,'
      '    :ACT_SDISCOUNT_AUTO,'
      '    :NACH_SDISCOUNT_AUTO,'
      '    :CON_SDISCOUNT_AUTO,'
      '    :PRSK_SDISCOUNT_AUTO,'
      '    :SUM_SDISCOUNT_AUTO,'
      '    :TIME_NACH_SDISCOUNT_AUTO,'
      '    :TIME_CON_SDISCOUNT_AUTO,'
      '    :DAY_SDISCOUNT_AUTO,'
      '    :IDVIDNOM_SDISCOUNT_AUTO,'
      '    :IDSKLAD_SDISCOUNT_AUTO,'
      '    :IDBASE_SDISCOUNT_AUTO,'
      '    :NUM_SKIDKI_SDISCOUNT_AUTO,'
      '    :IDGRPNOM_SDISCOUNT_AUTO,'
      '    :TYPE_ACTION_SDISCOUNT_AUTO,'
      '    :MESSAGE_SDISCOUNT_AUTO'
      ')')
    RefreshSQL.Strings = (
      'select  SDISCOUNT_AUTO.*,'
      '    ssklad.NAMESKLAD,'
      '    sgrpnom.namegn,'
      '    svidnom.name_svidnom'
      'from SDISCOUNT_AUTO'
      'left outer join SSKLAD on IDSKLAD_SDISCOUNT_AUTO=IDSKLAD'
      
        'left outer join sgrpnom on sdiscount_auto.idgrpnom_sdiscount_aut' +
        'o=sgrpnom.idgn'
      
        'left outer join svidnom on sdiscount_auto.idvidnom_sdiscount_aut' +
        'o=svidnom.name_svidnom'
      ''
      'where(  ID_SDISCOUNT_AUTO=:ID'
      
        '     ) and (     SDISCOUNT_AUTO.ID_SDISCOUNT_AUTO = :OLD_ID_SDIS' +
        'COUNT_AUTO'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select  SDISCOUNT_AUTO.*,'
      '    ssklad.NAMESKLAD,'
      '    sgrpnom.namegn,'
      '    svidnom.name_svidnom'
      'from SDISCOUNT_AUTO'
      'left outer join SSKLAD on IDSKLAD_SDISCOUNT_AUTO=IDSKLAD'
      
        'left outer join sgrpnom on sdiscount_auto.idgrpnom_sdiscount_aut' +
        'o=sgrpnom.idgn'
      
        'left outer join svidnom on sdiscount_auto.idvidnom_sdiscount_aut' +
        'o=svidnom.id_svidnom'
      ''
      'where ID_SDISCOUNT_AUTO=:ID')
    AutoUpdateOptions.UpdateTableName = 'SDISCOUNT_AUTO'
    AutoUpdateOptions.KeyFields = 'ID_SDISCOUNT_AUTO'
    AutoUpdateOptions.GeneratorName = 'GEN_SDISCOUNT_AUTO_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 96
    poUseLargeIntField = True
    object ElementID_SDISCOUNT_AUTO: TFIBLargeIntField
      FieldName = 'ID_SDISCOUNT_AUTO'
    end
    object ElementGID_SDISCOUNT_AUTO: TFIBWideStringField
      FieldName = 'GID_SDISCOUNT_AUTO'
      Size = 10
    end
    object ElementNAME_SDISCOUNT_AUTO: TFIBWideStringField
      FieldName = 'NAME_SDISCOUNT_AUTO'
      Size = 200
    end
    object ElementACT_SDISCOUNT_AUTO: TFIBSmallIntField
      FieldName = 'ACT_SDISCOUNT_AUTO'
    end
    object ElementNACH_SDISCOUNT_AUTO: TFIBDateTimeField
      FieldName = 'NACH_SDISCOUNT_AUTO'
    end
    object ElementCON_SDISCOUNT_AUTO: TFIBDateTimeField
      FieldName = 'CON_SDISCOUNT_AUTO'
    end
    object ElementPRSK_SDISCOUNT_AUTO: TFIBBCDField
      FieldName = 'PRSK_SDISCOUNT_AUTO'
      Size = 2
      RoundByScale = True
    end
    object ElementSUM_SDISCOUNT_AUTO: TFIBBCDField
      FieldName = 'SUM_SDISCOUNT_AUTO'
      Size = 2
      RoundByScale = True
    end
    object ElementTIME_NACH_SDISCOUNT_AUTO: TFIBTimeField
      FieldName = 'TIME_NACH_SDISCOUNT_AUTO'
    end
    object ElementTIME_CON_SDISCOUNT_AUTO: TFIBTimeField
      FieldName = 'TIME_CON_SDISCOUNT_AUTO'
    end
    object ElementDAY_SDISCOUNT_AUTO: TFIBSmallIntField
      FieldName = 'DAY_SDISCOUNT_AUTO'
    end
    object ElementIDVIDNOM_SDISCOUNT_AUTO: TFIBLargeIntField
      FieldName = 'IDVIDNOM_SDISCOUNT_AUTO'
    end
    object ElementIDSKLAD_SDISCOUNT_AUTO: TFIBLargeIntField
      FieldName = 'IDSKLAD_SDISCOUNT_AUTO'
    end
    object ElementIDBASE_SDISCOUNT_AUTO: TFIBLargeIntField
      FieldName = 'IDBASE_SDISCOUNT_AUTO'
    end
    object ElementNUM_SKIDKI_SDISCOUNT_AUTO: TFIBSmallIntField
      FieldName = 'NUM_SKIDKI_SDISCOUNT_AUTO'
    end
    object ElementIDGRPNOM_SDISCOUNT_AUTO: TFIBLargeIntField
      FieldName = 'IDGRPNOM_SDISCOUNT_AUTO'
    end
    object ElementTYPE_ACTION_SDISCOUNT_AUTO: TFIBIntegerField
      FieldName = 'TYPE_ACTION_SDISCOUNT_AUTO'
    end
    object ElementMESSAGE_SDISCOUNT_AUTO: TFIBWideStringField
      FieldName = 'MESSAGE_SDISCOUNT_AUTO'
      Size = 150
    end
    object ElementNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 200
    end
    object ElementNAMEGN: TFIBWideStringField
      FieldName = 'NAMEGN'
      Size = 200
    end
    object ElementNAME_SVIDNOM: TFIBWideStringField
      FieldName = 'NAME_SVIDNOM'
      Size = 200
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
    Left = 264
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
    Left = 264
    Top = 96
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 160
    Top = 160
    qoStartTransaction = True
  end
  object TableDiscountAuto: TpFIBDataSet
    SelectSQL.Strings = (
      'select  SDISCOUNT_AUTO.*'
      'from SDISCOUNT_AUTO'
      'where IDSKLAD_SDISCOUNT_AUTO=:PARAM_IDSKLAD '
      'and ACT_SDISCOUNT_AUTO=1')
    Transaction = IBTr
    Left = 160
    Top = 224
    poUseLargeIntField = True
    object TableDiscountAutoID_SDISCOUNT_AUTO: TFIBLargeIntField
      FieldName = 'ID_SDISCOUNT_AUTO'
    end
    object TableDiscountAutoGID_SDISCOUNT_AUTO: TFIBWideStringField
      FieldName = 'GID_SDISCOUNT_AUTO'
      Size = 10
    end
    object TableDiscountAutoNAME_SDISCOUNT_AUTO: TFIBWideStringField
      FieldName = 'NAME_SDISCOUNT_AUTO'
      Size = 200
    end
    object TableDiscountAutoACT_SDISCOUNT_AUTO: TFIBSmallIntField
      FieldName = 'ACT_SDISCOUNT_AUTO'
    end
    object TableDiscountAutoNACH_SDISCOUNT_AUTO: TFIBDateTimeField
      FieldName = 'NACH_SDISCOUNT_AUTO'
    end
    object TableDiscountAutoCON_SDISCOUNT_AUTO: TFIBDateTimeField
      FieldName = 'CON_SDISCOUNT_AUTO'
    end
    object TableDiscountAutoPRSK_SDISCOUNT_AUTO: TFIBBCDField
      FieldName = 'PRSK_SDISCOUNT_AUTO'
      Size = 2
      RoundByScale = True
    end
    object TableDiscountAutoSUM_SDISCOUNT_AUTO: TFIBBCDField
      FieldName = 'SUM_SDISCOUNT_AUTO'
      Size = 2
      RoundByScale = True
    end
    object TableDiscountAutoTIME_NACH_SDISCOUNT_AUTO: TFIBTimeField
      FieldName = 'TIME_NACH_SDISCOUNT_AUTO'
    end
    object TableDiscountAutoTIME_CON_SDISCOUNT_AUTO: TFIBTimeField
      FieldName = 'TIME_CON_SDISCOUNT_AUTO'
    end
    object TableDiscountAutoDAY_SDISCOUNT_AUTO: TFIBSmallIntField
      FieldName = 'DAY_SDISCOUNT_AUTO'
    end
    object TableDiscountAutoIDVIDNOM_SDISCOUNT_AUTO: TFIBLargeIntField
      FieldName = 'IDVIDNOM_SDISCOUNT_AUTO'
    end
    object TableDiscountAutoIDSKLAD_SDISCOUNT_AUTO: TFIBLargeIntField
      FieldName = 'IDSKLAD_SDISCOUNT_AUTO'
    end
    object TableDiscountAutoIDBASE_SDISCOUNT_AUTO: TFIBLargeIntField
      FieldName = 'IDBASE_SDISCOUNT_AUTO'
    end
    object TableDiscountAutoNUM_SKIDKI_SDISCOUNT_AUTO: TFIBSmallIntField
      FieldName = 'NUM_SKIDKI_SDISCOUNT_AUTO'
    end
    object TableDiscountAutoIDGRPNOM_SDISCOUNT_AUTO: TFIBLargeIntField
      FieldName = 'IDGRPNOM_SDISCOUNT_AUTO'
    end
    object TableDiscountAutoTYPE_ACTION_SDISCOUNT_AUTO: TFIBIntegerField
      FieldName = 'TYPE_ACTION_SDISCOUNT_AUTO'
    end
    object TableDiscountAutoMESSAGE_SDISCOUNT_AUTO: TFIBWideStringField
      FieldName = 'MESSAGE_SDISCOUNT_AUTO'
      Size = 150
    end
  end
end
