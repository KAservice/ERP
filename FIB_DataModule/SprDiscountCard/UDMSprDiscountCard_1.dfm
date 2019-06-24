object DMSprDiscountCard_1: TDMSprDiscountCard_1
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 209
  Width = 317
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
    SelectSQL.Strings = (
      'select '
      
        '   SDISCOUNT_CARD .*, svid_dcard.name_svid_dcard, sklient.namekl' +
        'ient'
      'from SDISCOUNT_CARD '
      
        'left outer join SVID_DCARD on svid_dcard.id_svid_dcard=sdiscount' +
        '_card.idvid_sdiscount_card'
      
        'left outer join sklient on sklient.idklient=sdiscount_card.idkli' +
        'ent_sdiscount_card'
      
        'left outer join sgrpkl on sdiscount_card.idklient_sdiscount_card' +
        '=sgrpkl.idgrpkl'
      'where sgrpkl.grpkl=:PARAM_IDGRP'
      'order by  sklient.nameklient')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 152
    Top = 8
    poUseLargeIntField = True
    object TableCODE_SDISCOUNT_CARD: TFIBIntegerField
      FieldName = 'CODE_SDISCOUNT_CARD'
    end
    object TableTYPE_SDISCOUNT_CARD: TFIBIntegerField
      FieldName = 'TYPE_SDISCOUNT_CARD'
    end
    object TableNACH_SDISCOUNT_CARD: TFIBDateTimeField
      FieldName = 'NACH_SDISCOUNT_CARD'
    end
    object TableCON_SDISCOUNT_CARD: TFIBDateTimeField
      FieldName = 'CON_SDISCOUNT_CARD'
    end
    object TablePRSK_SDISCOUNT_CARD: TFIBBCDField
      FieldName = 'PRSK_SDISCOUNT_CARD'
      Size = 2
      RoundByScale = True
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableACT_SDISCOUNT_CARD: TFIBIntegerField
      FieldName = 'ACT_SDISCOUNT_CARD'
    end
    object TableFL_DISC_SDISCOUNT_CARD: TFIBSmallIntField
      FieldName = 'FL_DISC_SDISCOUNT_CARD'
    end
    object TableFL_PLAT_SDISCOUNT_CARD: TFIBSmallIntField
      FieldName = 'FL_PLAT_SDISCOUNT_CARD'
    end
    object TableIDBASE_SDISCOUNT_CARD: TFIBLargeIntField
      FieldName = 'IDBASE_SDISCOUNT_CARD'
    end
    object TableFL_CREDIT_SDISCOUNT_CARD: TFIBSmallIntField
      FieldName = 'FL_CREDIT_SDISCOUNT_CARD'
    end
    object TableIDDOG_SDISCOUNT_CARD: TFIBLargeIntField
      FieldName = 'IDDOG_SDISCOUNT_CARD'
    end
    object TableID_SDISCOUNT_CARD: TFIBLargeIntField
      FieldName = 'ID_SDISCOUNT_CARD'
    end
    object TableIDKLIENT_SDISCOUNT_CARD: TFIBLargeIntField
      FieldName = 'IDKLIENT_SDISCOUNT_CARD'
    end
    object TableIDVID_SDISCOUNT_CARD: TFIBLargeIntField
      FieldName = 'IDVID_SDISCOUNT_CARD'
    end
    object TableNAME_SDISCOUNT_CARD: TFIBWideStringField
      FieldName = 'NAME_SDISCOUNT_CARD'
      Size = 200
    end
    object TableNAME_SVID_DCARD: TFIBWideStringField
      FieldName = 'NAME_SVID_DCARD'
      Size = 200
    end
    object TableNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 200
    end
    object TableSHCODE_SDISCOUNT_CARD: TFIBWideStringField
      FieldName = 'SHCODE_SDISCOUNT_CARD'
      Size = 13
    end
    object TableGID_SDISCOUNT_CARD: TFIBWideStringField
      FieldName = 'GID_SDISCOUNT_CARD'
      Size = 10
    end
    object TableSINGLE_SDISCOUNT_CARD: TFIBSmallIntField
      FieldName = 'SINGLE_SDISCOUNT_CARD'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
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
      '    IDVID_SDISCOUNT_CARD = :IDVID_SDISCOUNT_CARD,'
      '    IDBASE_SDISCOUNT_CARD = :IDBASE_SDISCOUNT_CARD,'
      '    FL_DISC_SDISCOUNT_CARD = :FL_DISC_SDISCOUNT_CARD,'
      '    FL_PLAT_SDISCOUNT_CARD = :FL_PLAT_SDISCOUNT_CARD,'
      '    FL_CREDIT_SDISCOUNT_CARD = :FL_CREDIT_SDISCOUNT_CARD,'
      '    IDDOG_SDISCOUNT_CARD = :IDDOG_SDISCOUNT_CARD,'
      '    SINGLE_SDISCOUNT_CARD = :SINGLE_SDISCOUNT_CARD'
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
      '    IDVID_SDISCOUNT_CARD,'
      '    IDBASE_SDISCOUNT_CARD,'
      '    FL_DISC_SDISCOUNT_CARD,'
      '    FL_PLAT_SDISCOUNT_CARD,'
      '    FL_CREDIT_SDISCOUNT_CARD,'
      '    IDDOG_SDISCOUNT_CARD,'
      '    SINGLE_SDISCOUNT_CARD'
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
      '    :IDVID_SDISCOUNT_CARD,'
      '    :IDBASE_SDISCOUNT_CARD,'
      '    :FL_DISC_SDISCOUNT_CARD,'
      '    :FL_PLAT_SDISCOUNT_CARD,'
      '    :FL_CREDIT_SDISCOUNT_CARD,'
      '    :IDDOG_SDISCOUNT_CARD,'
      '    :SINGLE_SDISCOUNT_CARD'
      ')')
    RefreshSQL.Strings = (
      'select SDISCOUNT_CARD.*,'
      '            NAMEKLIENT,'
      '            NAME_SVID_DCARD,'
      '            sdog.name_sdog'
      'from SDISCOUNT_CARD'
      'left outer join SKLIENT on IDKLIENT=IDKLIENT_SDISCOUNT_CARD '
      'left outer join SVID_DCARD on ID_SVID_DCARD=IDVID_SDISCOUNT_CARD'
      
        'left outer join sdog on sdog.id_sdog=sdiscount_card.iddog_sdisco' +
        'unt_card'
      'where(  ID_SDISCOUNT_CARD=:PARAM_ID'
      
        '     ) and (     SDISCOUNT_CARD.ID_SDISCOUNT_CARD = :OLD_ID_SDIS' +
        'COUNT_CARD'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select SDISCOUNT_CARD.*,'
      '            NAMEKLIENT,'
      '            NAME_SVID_DCARD,'
      '            sdog.name_sdog'
      'from SDISCOUNT_CARD'
      'left outer join SKLIENT on IDKLIENT=IDKLIENT_SDISCOUNT_CARD '
      'left outer join SVID_DCARD on ID_SVID_DCARD=IDVID_SDISCOUNT_CARD'
      
        'left outer join sdog on sdog.id_sdog=sdiscount_card.iddog_sdisco' +
        'unt_card'
      'where ID_SDISCOUNT_CARD=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SDISCOUNT_CARD'
    AutoUpdateOptions.KeyFields = 'ID_SDISCOUNT_CARD'
    AutoUpdateOptions.GeneratorName = 'GEN_SDISCOUNT_CARD_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 72
    poUseLargeIntField = True
    object ElementCODE_SDISCOUNT_CARD: TFIBIntegerField
      FieldName = 'CODE_SDISCOUNT_CARD'
    end
    object ElementTYPE_SDISCOUNT_CARD: TFIBIntegerField
      FieldName = 'TYPE_SDISCOUNT_CARD'
    end
    object ElementNACH_SDISCOUNT_CARD: TFIBDateTimeField
      FieldName = 'NACH_SDISCOUNT_CARD'
    end
    object ElementCON_SDISCOUNT_CARD: TFIBDateTimeField
      FieldName = 'CON_SDISCOUNT_CARD'
    end
    object ElementPRSK_SDISCOUNT_CARD: TFIBBCDField
      FieldName = 'PRSK_SDISCOUNT_CARD'
      Size = 2
      RoundByScale = True
    end
    object ElementACT_SDISCOUNT_CARD: TFIBIntegerField
      FieldName = 'ACT_SDISCOUNT_CARD'
    end
    object ElementFL_DISC_SDISCOUNT_CARD: TFIBSmallIntField
      FieldName = 'FL_DISC_SDISCOUNT_CARD'
    end
    object ElementFL_PLAT_SDISCOUNT_CARD: TFIBSmallIntField
      FieldName = 'FL_PLAT_SDISCOUNT_CARD'
    end
    object ElementFL_CREDIT_SDISCOUNT_CARD: TFIBSmallIntField
      FieldName = 'FL_CREDIT_SDISCOUNT_CARD'
    end
    object ElementID_SDISCOUNT_CARD: TFIBLargeIntField
      FieldName = 'ID_SDISCOUNT_CARD'
    end
    object ElementIDKLIENT_SDISCOUNT_CARD: TFIBLargeIntField
      FieldName = 'IDKLIENT_SDISCOUNT_CARD'
    end
    object ElementIDVID_SDISCOUNT_CARD: TFIBLargeIntField
      FieldName = 'IDVID_SDISCOUNT_CARD'
    end
    object ElementIDBASE_SDISCOUNT_CARD: TFIBLargeIntField
      FieldName = 'IDBASE_SDISCOUNT_CARD'
    end
    object ElementIDDOG_SDISCOUNT_CARD: TFIBLargeIntField
      FieldName = 'IDDOG_SDISCOUNT_CARD'
    end
    object ElementGID_SDISCOUNT_CARD: TFIBWideStringField
      FieldName = 'GID_SDISCOUNT_CARD'
      Size = 10
    end
    object ElementNAME_SDISCOUNT_CARD: TFIBWideStringField
      FieldName = 'NAME_SDISCOUNT_CARD'
      Size = 200
    end
    object ElementSHCODE_SDISCOUNT_CARD: TFIBWideStringField
      FieldName = 'SHCODE_SDISCOUNT_CARD'
      Size = 13
    end
    object ElementNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 200
    end
    object ElementNAME_SVID_DCARD: TFIBWideStringField
      FieldName = 'NAME_SVID_DCARD'
      Size = 200
    end
    object ElementNAME_SDOG: TFIBWideStringField
      FieldName = 'NAME_SDOG'
      Size = 200
    end
    object ElementSINGLE_SDISCOUNT_CARD: TFIBSmallIntField
      FieldName = 'SINGLE_SDISCOUNT_CARD'
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
    SQL.Strings = (
      
        'select ID_SDISCOUNT_CARD from SDISCOUNT_CARD where CODE_SDISCOUN' +
        'T_CARD=:PARAM_CODE')
    Left = 152
    Top = 144
    qoStartTransaction = True
  end
end
