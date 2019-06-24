object DMSprStrObject: TDMSprStrObject
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 199
  Width = 348
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 64
    Top = 24
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 64
    Top = 80
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select *  from SSTROB')
    Transaction = IBTr
    Left = 168
    Top = 24
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_STROB: TFIBBCDField
      FieldName = 'ID_STROB'
      Size = 0
      RoundByScale = True
    end
    object TableIDGRP_STROB: TFIBBCDField
      FieldName = 'IDGRP_STROB'
      Size = 0
      RoundByScale = True
    end
    object TableGRP_STROB: TFIBSmallIntField
      FieldName = 'GRP_STROB'
    end
    object TableNAME_STROB: TFIBWideStringField
      FieldName = 'NAME_STROB'
      Size = 100
    end
    object TableCODE_STROB: TFIBIntegerField
      FieldName = 'CODE_STROB'
    end
    object TableGID_SSTROB: TFIBWideStringField
      FieldName = 'GID_SSTROB'
      Size = 10
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SSTROB'
      'SET '
      '    IDGRP_STROB = :IDGRP_STROB,'
      '    NAME_STROB = :NAME_STROB,'
      '    GRP_STROB = :GRP_STROB,'
      '    CODE_STROB = :CODE_STROB,'
      '    GID_SSTROB = :GID_SSTROB'
      'WHERE'
      '    ID_STROB = :OLD_ID_STROB'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SSTROB'
      'WHERE'
      '        ID_STROB = :OLD_ID_STROB'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SSTROB('
      '    ID_STROB,'
      '    IDGRP_STROB,'
      '    NAME_STROB,'
      '    GRP_STROB,'
      '    CODE_STROB,'
      '    GID_SSTROB'
      ')'
      'VALUES('
      '    :ID_STROB,'
      '    :IDGRP_STROB,'
      '    :NAME_STROB,'
      '    :GRP_STROB,'
      '    :CODE_STROB,'
      '    :GID_SSTROB'
      ')')
    RefreshSQL.Strings = (
      'select * from SSTROB where(  ID_STROB=:ID'
      '     ) and (     SSTROB.ID_STROB = :OLD_ID_STROB'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from SSTROB where ID_STROB=:ID')
    AutoUpdateOptions.UpdateTableName = 'SSTROB'
    AutoUpdateOptions.KeyFields = 'ID_STROB'
    AutoUpdateOptions.GeneratorName = 'GEN_SSTROB_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 80
    object ElementID_STROB: TFIBBCDField
      FieldName = 'ID_STROB'
      Size = 0
      RoundByScale = True
    end
    object ElementIDGRP_STROB: TFIBBCDField
      FieldName = 'IDGRP_STROB'
      Size = 0
      RoundByScale = True
    end
    object ElementGRP_STROB: TFIBSmallIntField
      FieldName = 'GRP_STROB'
    end
    object ElementNAME_STROB: TFIBWideStringField
      FieldName = 'NAME_STROB'
      Size = 100
    end
    object ElementCODE_STROB: TFIBIntegerField
      FieldName = 'CODE_STROB'
    end
    object ElementGID_SSTROB: TFIBWideStringField
      FieldName = 'GID_SSTROB'
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
    Left = 272
    Top = 24
  end
  object IBTrUpdate: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 272
    Top = 80
  end
  object Code: TpFIBDataSet
    SelectSQL.Strings = (
      'select max(CODE_STROB) AS MAXCODE from  SSTROB')
    Transaction = IBTr
    Left = 168
    Top = 136
    object CodeMAXCODE: TFIBIntegerField
      FieldName = 'MAXCODE'
    end
  end
end
