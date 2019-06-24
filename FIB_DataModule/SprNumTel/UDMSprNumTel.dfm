object DMSprNumTel: TDMSprNumTel
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 131
  Width = 298
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 8
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 56
    Top = 64
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from SNUMTEL where IDKLIENT_NUMTEL=:PARAM_IDKLIENT')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 144
    Top = 8
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_NUMTEL: TFIBBCDField
      FieldName = 'ID_NUMTEL'
      Size = 0
      RoundByScale = True
    end
    object TableIDKLIENT_NUMTEL: TFIBBCDField
      FieldName = 'IDKLIENT_NUMTEL'
      Size = 0
      RoundByScale = True
    end
    object TableCODE_NUMTEL: TFIBWideStringField
      FieldName = 'CODE_NUMTEL'
      Size = 3
    end
    object TableNUMBER_NUMTEL: TFIBWideStringField
      FieldName = 'NUMBER_NUMTEL'
      Size = 7
    end
    object TableGID_SNUMTEL: TFIBWideStringField
      FieldName = 'GID_SNUMTEL'
      Size = 10
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SNUMTEL'
      'SET '
      '    IDKLIENT_NUMTEL = :IDKLIENT_NUMTEL,'
      '    CODE_NUMTEL = :CODE_NUMTEL,'
      '    NUMBER_NUMTEL = :NUMBER_NUMTEL,'
      '    GID_SNUMTEL = :GID_SNUMTEL'
      'WHERE'
      '    ID_NUMTEL = :OLD_ID_NUMTEL'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SNUMTEL'
      'WHERE'
      '        ID_NUMTEL = :OLD_ID_NUMTEL'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SNUMTEL('
      '    ID_NUMTEL,'
      '    IDKLIENT_NUMTEL,'
      '    CODE_NUMTEL,'
      '    NUMBER_NUMTEL,'
      '    GID_SNUMTEL'
      ')'
      'VALUES('
      '    :ID_NUMTEL,'
      '    :IDKLIENT_NUMTEL,'
      '    :CODE_NUMTEL,'
      '    :NUMBER_NUMTEL,'
      '    :GID_SNUMTEL'
      ')')
    RefreshSQL.Strings = (
      'select * from SNUMTEL where(  ID_NUMTEL=:PARAM_ID'
      '     ) and (     SNUMTEL.ID_NUMTEL = :OLD_ID_NUMTEL'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from SNUMTEL where ID_NUMTEL=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SNUMTEL'
    AutoUpdateOptions.KeyFields = 'ID_NUMTEL'
    AutoUpdateOptions.GeneratorName = 'GEN_SNUMTEL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 64
    object ElementID_NUMTEL: TFIBBCDField
      FieldName = 'ID_NUMTEL'
      Size = 0
      RoundByScale = True
    end
    object ElementIDKLIENT_NUMTEL: TFIBBCDField
      FieldName = 'IDKLIENT_NUMTEL'
      Size = 0
      RoundByScale = True
    end
    object ElementCODE_NUMTEL: TFIBWideStringField
      FieldName = 'CODE_NUMTEL'
      Size = 3
    end
    object ElementNUMBER_NUMTEL: TFIBWideStringField
      FieldName = 'NUMBER_NUMTEL'
      Size = 7
    end
    object ElementGID_SNUMTEL: TFIBWideStringField
      FieldName = 'GID_SNUMTEL'
      Size = 10
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
    Left = 224
    Top = 8
  end
  object IBTrUpdate: TpFIBTransaction
    TimeoutAction = TARollback
    Left = 224
    Top = 64
  end
end
