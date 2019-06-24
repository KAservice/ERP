object DMSprVidDiscountCard: TDMSprVidDiscountCard
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 231
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
      'select  * from SVID_DCARD')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 152
    Top = 24
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_SVID_DCARD: TFIBBCDField
      FieldName = 'ID_SVID_DCARD'
      Size = 0
      RoundByScale = True
    end
    object TableGID_SVID_DCARD: TFIBWideStringField
      FieldName = 'GID_SVID_DCARD'
      Size = 10
    end
    object TableNAME_SVID_DCARD: TFIBWideStringField
      FieldName = 'NAME_SVID_DCARD'
      Size = 100
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SVID_DCARD'
      'SET '
      '    GID_SVID_DCARD = :GID_SVID_DCARD,'
      '    NAME_SVID_DCARD = :NAME_SVID_DCARD'
      'WHERE'
      '    ID_SVID_DCARD = :OLD_ID_SVID_DCARD'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SVID_DCARD'
      'WHERE'
      '        ID_SVID_DCARD = :OLD_ID_SVID_DCARD'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SVID_DCARD('
      '    ID_SVID_DCARD,'
      '    GID_SVID_DCARD,'
      '    NAME_SVID_DCARD'
      ')'
      'VALUES('
      '    :ID_SVID_DCARD,'
      '    :GID_SVID_DCARD,'
      '    :NAME_SVID_DCARD'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from SVID_DCARD '
      'where(  ID_SVID_DCARD=:PARAM_ID'
      '     ) and (     SVID_DCARD.ID_SVID_DCARD = :OLD_ID_SVID_DCARD'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from SVID_DCARD '
      'where ID_SVID_DCARD=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SVID_DCARD'
    AutoUpdateOptions.KeyFields = 'ID_SVID_DCARD'
    AutoUpdateOptions.GeneratorName = 'GEN_SVID_DCARD_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 96
    object ElementID_SVID_DCARD: TFIBBCDField
      FieldName = 'ID_SVID_DCARD'
      Size = 0
      RoundByScale = True
    end
    object ElementGID_SVID_DCARD: TFIBWideStringField
      FieldName = 'GID_SVID_DCARD'
      Size = 10
    end
    object ElementNAME_SVID_DCARD: TFIBWideStringField
      FieldName = 'NAME_SVID_DCARD'
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
    Left = 152
    Top = 160
    qoStartTransaction = True
  end
end
