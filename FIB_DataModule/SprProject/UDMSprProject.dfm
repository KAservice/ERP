object DMSprProject: TDMSprProject
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 327
  Width = 371
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
      'select *'
      'from SPROJECT'
      'where IDGRP_SPROJECT=:PARAM_IDGRP')
    Transaction = IBTr
    Left = 160
    Top = 16
    object TableID_SPROJECT: TFIBBCDField
      FieldName = 'ID_SPROJECT'
      Size = 0
      RoundByScale = True
    end
    object TableIDGRP_SPROJECT: TFIBBCDField
      FieldName = 'IDGRP_SPROJECT'
      Size = 0
      RoundByScale = True
    end
    object TableCODE_SPROJECT: TFIBIntegerField
      FieldName = 'CODE_SPROJECT'
    end
    object TableNAME_SPROJECT: TFIBWideStringField
      FieldName = 'NAME_SPROJECT'
      Size = 100
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SPROJECT'
      'SET '
      '    IDGRP_SPROJECT = :IDGRP_SPROJECT,'
      '    NAME_SPROJECT = :NAME_SPROJECT,'
      '    IDBASE_SPROJECT = :IDBASE_SPROJECT,'
      '    CODE_SPROJECT = :CODE_SPROJECT'
      'WHERE'
      '    ID_SPROJECT = :OLD_ID_SPROJECT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SPROJECT'
      'WHERE'
      '        ID_SPROJECT = :OLD_ID_SPROJECT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SPROJECT('
      '    ID_SPROJECT,'
      '    IDGRP_SPROJECT,'
      '    NAME_SPROJECT,'
      '    IDBASE_SPROJECT,'
      '    CODE_SPROJECT'
      ')'
      'VALUES('
      '    :ID_SPROJECT,'
      '    :IDGRP_SPROJECT,'
      '    :NAME_SPROJECT,'
      '    :IDBASE_SPROJECT,'
      '    :CODE_SPROJECT'
      ')')
    RefreshSQL.Strings = (
      'select *'
      'from SPROJECT'
      'where(  ID_SPROJECT=:PARAM_ID'
      '     ) and (     SPROJECT.ID_SPROJECT = :OLD_ID_SPROJECT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select *'
      'from SPROJECT'
      'where ID_SPROJECT=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SPROJECT'
    AutoUpdateOptions.KeyFields = 'ID_SPROJECT'
    AutoUpdateOptions.GeneratorName = 'GEN_SPROJECT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    object ElementID_SPROJECT: TFIBBCDField
      FieldName = 'ID_SPROJECT'
      Size = 0
      RoundByScale = True
    end
    object ElementIDGRP_SPROJECT: TFIBBCDField
      FieldName = 'IDGRP_SPROJECT'
      Size = 0
      RoundByScale = True
    end
    object ElementCODE_SPROJECT: TFIBIntegerField
      FieldName = 'CODE_SPROJECT'
    end
    object ElementNAME_SPROJECT: TFIBWideStringField
      FieldName = 'NAME_SPROJECT'
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
    Left = 256
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
    Left = 256
    Top = 64
  end
  object Code: TpFIBDataSet
    SelectSQL.Strings = (
      'select max(CODE_SPROJECT) AS MAXCODE '
      'from  SPROJECT'
      '')
    Transaction = IBTr
    Left = 160
    Top = 128
    object CodeMAXCODE: TFIBIntegerField
      FieldName = 'MAXCODE'
    end
  end
end
