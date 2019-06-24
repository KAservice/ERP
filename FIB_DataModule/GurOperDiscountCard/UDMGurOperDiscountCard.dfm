object DMGurOperDiscountCard: TDMGurOperDiscountCard
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 242
  Width = 334
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 8
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 56
    Top = 72
  end
  object Table: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE SDISCOUNT_CARD'
      'SET '
      '    GID_SDISCOUNT_CARD = :GID_SDISCOUNT_CARD,'
      '    IDKLIENT_SDISCOUNT_CARD = :IDKLIENT_SDISCOUNT_CARD,'
      '    NAME_SDISCOUNT_CARD = :NAME_SDISCOUNT_CARD,'
      '    CODE_SDISCOUNT_CARD = :CODE_SDISCOUNT_CARD,'
      '    SHCODE_SDISCOUNT_CARD = :SHCODE_SDISCOUNT_CARD,'
      '    TYPE_SDISCOUNT_CARD = :TYPE_SDISCOUNT_CARD,'
      '    ACT_SDISCOUNT_CARD = :ACT_SDISCOUNT_CARD,'
      '    NACH_SDISCOUNT_CARD = :NACH_SDISCOUNT_CARD,'
      '    CON_SDISCOUNT_CARD = :CON_SDISCOUNT_CARD,'
      '    PRSK_SDISCOUNT_CARD = :PRSK_SDISCOUNT_CARD,'
      '    IDVID_SDISCOUNT_CARD = :IDVID_SDISCOUNT_CARD'
      'WHERE'
      '    ID_SDISCOUNT_CARD = :OLD_ID_SDISCOUNT_CARD'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SDISCOUNT_CARD'
      'WHERE'
      '        ID_SDISCOUNT_CARD = :OLD_ID_SDISCOUNT_CARD'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SDISCOUNT_CARD('
      '    ID_SDISCOUNT_CARD,'
      '    GID_SDISCOUNT_CARD,'
      '    IDKLIENT_SDISCOUNT_CARD,'
      '    NAME_SDISCOUNT_CARD,'
      '    CODE_SDISCOUNT_CARD,'
      '    SHCODE_SDISCOUNT_CARD,'
      '    TYPE_SDISCOUNT_CARD,'
      '    ACT_SDISCOUNT_CARD,'
      '    NACH_SDISCOUNT_CARD,'
      '    CON_SDISCOUNT_CARD,'
      '    PRSK_SDISCOUNT_CARD,'
      '    IDVID_SDISCOUNT_CARD'
      ')'
      'VALUES('
      '    :ID_SDISCOUNT_CARD,'
      '    :GID_SDISCOUNT_CARD,'
      '    :IDKLIENT_SDISCOUNT_CARD,'
      '    :NAME_SDISCOUNT_CARD,'
      '    :CODE_SDISCOUNT_CARD,'
      '    :SHCODE_SDISCOUNT_CARD,'
      '    :TYPE_SDISCOUNT_CARD,'
      '    :ACT_SDISCOUNT_CARD,'
      '    :NACH_SDISCOUNT_CARD,'
      '    :CON_SDISCOUNT_CARD,'
      '    :PRSK_SDISCOUNT_CARD,'
      '    :IDVID_SDISCOUNT_CARD'
      ')')
    RefreshSQL.Strings = (
      'select '
      '   SDISCOUNT_CARD .*, NAME_SVID_DCARD '
      'from SDISCOUNT_CARD '
      'left outer join SVID_DCARD on ID_SVID_DCARD=IDVID_SDISCOUNT_CARD'
      'where(  IDKLIENT_SDISCOUNT_CARD=:PARAM_IDKLIENT'
      
        '     ) and (     SDISCOUNT_CARD.ID_SDISCOUNT_CARD = :OLD_ID_SDIS' +
        'COUNT_CARD'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select '
      '   GUROPER_DCARD .*, NAMEKLIENT, NAMESKLAD, NAME_SDISCOUNT_CARD '
      'from GUROPER_DCARD'
      'left outer join SSKLAD on IDSKLAD_GUROPER_DCARD=IDSKLAD'
      'left outer join SKLIENT on IDKLIENT_GUROPER_DCARD=IDKLIENT'
      
        'left outer join SDISCOUNT_CARD on IDCARD_GUROPER_DCARD=ID_SDISCO' +
        'UNT_CARD'
      'where POS_GUROPER_DCARD between :PARAM_NACH and :PARAM_CON'
      '')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 152
    Top = 8
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableSUM_GUROPER_DCARD: TFIBBCDField
      FieldName = 'SUM_GUROPER_DCARD'
      Size = 2
      RoundByScale = True
    end
    object TablePOS_GUROPER_DCARD: TFIBDateTimeField
      FieldName = 'POS_GUROPER_DCARD'
    end
    object TableID_GUROPER_DCARD: TFIBBCDField
      FieldName = 'ID_GUROPER_DCARD'
      Size = 0
      RoundByScale = True
    end
    object TableIDKLIENT_GUROPER_DCARD: TFIBBCDField
      FieldName = 'IDKLIENT_GUROPER_DCARD'
      Size = 0
      RoundByScale = True
    end
    object TableIDSKLAD_GUROPER_DCARD: TFIBBCDField
      FieldName = 'IDSKLAD_GUROPER_DCARD'
      Size = 0
      RoundByScale = True
    end
    object TableIDCARD_GUROPER_DCARD: TFIBBCDField
      FieldName = 'IDCARD_GUROPER_DCARD'
      Size = 0
      RoundByScale = True
    end
    object TableIDDOC_GUROPER_DCARD: TFIBBCDField
      FieldName = 'IDDOC_GUROPER_DCARD'
      Size = 0
      RoundByScale = True
    end
    object TableNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 100
    end
    object TableNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 100
    end
    object TableNAME_SDISCOUNT_CARD: TFIBWideStringField
      FieldName = 'NAME_SDISCOUNT_CARD'
      Size = 100
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE GUROPER_DCARD'
      'SET '
      '    GID_GUROPER_DCARD = :GID_GUROPER_DCARD,'
      '    IDKLIENT_GUROPER_DCARD = :IDKLIENT_GUROPER_DCARD,'
      '    IDSKLAD_GUROPER_DCARD = :IDSKLAD_GUROPER_DCARD,'
      '    IDCARD_GUROPER_DCARD = :IDCARD_GUROPER_DCARD,'
      '    SUM_GUROPER_DCARD = :SUM_GUROPER_DCARD,'
      '    POS_GUROPER_DCARD = :POS_GUROPER_DCARD,'
      '    IDDOC_GUROPER_DCARD = :IDDOC_GUROPER_DCARD'
      'WHERE'
      '    ID_GUROPER_DCARD = :OLD_ID_GUROPER_DCARD'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    GUROPER_DCARD'
      'WHERE'
      '        ID_GUROPER_DCARD = :OLD_ID_GUROPER_DCARD'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO GUROPER_DCARD('
      '    ID_GUROPER_DCARD,'
      '    GID_GUROPER_DCARD,'
      '    IDKLIENT_GUROPER_DCARD,'
      '    IDSKLAD_GUROPER_DCARD,'
      '    IDCARD_GUROPER_DCARD,'
      '    SUM_GUROPER_DCARD,'
      '    POS_GUROPER_DCARD,'
      '    IDDOC_GUROPER_DCARD'
      ')'
      'VALUES('
      '    :ID_GUROPER_DCARD,'
      '    :GID_GUROPER_DCARD,'
      '    :IDKLIENT_GUROPER_DCARD,'
      '    :IDSKLAD_GUROPER_DCARD,'
      '    :IDCARD_GUROPER_DCARD,'
      '    :SUM_GUROPER_DCARD,'
      '    :POS_GUROPER_DCARD,'
      '    :IDDOC_GUROPER_DCARD'
      ')')
    RefreshSQL.Strings = (
      'select '
      '   GUROPER_DCARD .*, NAMEKLIENT, NAMESKLAD, NAME_SDISCOUNT_CARD '
      'from GUROPER_DCARD'
      'left outer join SSKLAD on IDSKLAD_GUROPER_DCARD=IDSKLAD'
      'left outer join SKLIENT on IDKLIENT_GUROPER_DCARD=IDKLIENT'
      
        'left outer join SDISCOUNT_CARD on IDCARD_GUROPER_DCARD=ID_SDISCO' +
        'UNT_CARD'
      'where(  ID_GUROPER_DCARD=:PARAM_ID'
      
        '     ) and (     GUROPER_DCARD.ID_GUROPER_DCARD = :OLD_ID_GUROPE' +
        'R_DCARD'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select '
      '   GUROPER_DCARD .*, NAMEKLIENT, NAMESKLAD, NAME_SDISCOUNT_CARD '
      'from GUROPER_DCARD'
      'left outer join SSKLAD on IDSKLAD_GUROPER_DCARD=IDSKLAD'
      'left outer join SKLIENT on IDKLIENT_GUROPER_DCARD=IDKLIENT'
      
        'left outer join SDISCOUNT_CARD on IDCARD_GUROPER_DCARD=ID_SDISCO' +
        'UNT_CARD'
      'where ID_GUROPER_DCARD=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'GUROPER_DCARD'
    AutoUpdateOptions.KeyFields = 'ID_GUROPER_DCARD'
    AutoUpdateOptions.GeneratorName = 'GEN_GUROPER_DCARD_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 72
    object ElementSUM_GUROPER_DCARD: TFIBBCDField
      FieldName = 'SUM_GUROPER_DCARD'
      Size = 2
      RoundByScale = True
    end
    object ElementPOS_GUROPER_DCARD: TFIBDateTimeField
      FieldName = 'POS_GUROPER_DCARD'
    end
    object ElementID_GUROPER_DCARD: TFIBBCDField
      FieldName = 'ID_GUROPER_DCARD'
      Size = 0
      RoundByScale = True
    end
    object ElementIDKLIENT_GUROPER_DCARD: TFIBBCDField
      FieldName = 'IDKLIENT_GUROPER_DCARD'
      Size = 0
      RoundByScale = True
    end
    object ElementIDSKLAD_GUROPER_DCARD: TFIBBCDField
      FieldName = 'IDSKLAD_GUROPER_DCARD'
      Size = 0
      RoundByScale = True
    end
    object ElementIDCARD_GUROPER_DCARD: TFIBBCDField
      FieldName = 'IDCARD_GUROPER_DCARD'
      Size = 0
      RoundByScale = True
    end
    object ElementIDDOC_GUROPER_DCARD: TFIBBCDField
      FieldName = 'IDDOC_GUROPER_DCARD'
      Size = 0
      RoundByScale = True
    end
    object ElementGID_GUROPER_DCARD: TFIBWideStringField
      FieldName = 'GID_GUROPER_DCARD'
      Size = 10
    end
    object ElementNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 100
    end
    object ElementNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 100
    end
    object ElementNAME_SDISCOUNT_CARD: TFIBWideStringField
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
    Left = 248
    Top = 8
  end
  object IBTrUpdate: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 248
    Top = 72
  end
  object Query: TpFIBQuery
    Transaction = IBTr
    Left = 152
    Top = 144
    qoStartTransaction = True
  end
end
