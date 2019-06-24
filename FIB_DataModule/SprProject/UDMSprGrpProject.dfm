object DMSprGrpProject: TDMSprGrpProject
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 224
  Width = 345
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
      'select * '
      'from '
      '  SGRPPROJECT'
      'order by IDGRP_SGRPPROJECT')
    Transaction = IBTr
    Left = 144
    Top = 24
    object TableID_SGRPPROJECT: TFIBBCDField
      FieldName = 'ID_SGRPPROJECT'
      Size = 0
      RoundByScale = True
    end
    object TableIDGRP_SGRPPROJECT: TFIBBCDField
      FieldName = 'IDGRP_SGRPPROJECT'
      Size = 0
      RoundByScale = True
    end
    object TableNAME_SGRPPROJECT: TFIBWideStringField
      FieldName = 'NAME_SGRPPROJECT'
      Size = 100
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SGRPPROJECT'
      'SET '
      '    IDGRP_SGRPPROJECT = :IDGRP_SGRPPROJECT,'
      '    NAME_SGRPPROJECT = :NAME_SGRPPROJECT'
      'WHERE'
      '    ID_SGRPPROJECT = :OLD_ID_SGRPPROJECT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SGRPPROJECT'
      'WHERE'
      '        ID_SGRPPROJECT = :OLD_ID_SGRPPROJECT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SGRPPROJECT('
      '    ID_SGRPPROJECT,'
      '    IDGRP_SGRPPROJECT,'
      '    NAME_SGRPPROJECT'
      ')'
      'VALUES('
      '    :ID_SGRPPROJECT,'
      '    :IDGRP_SGRPPROJECT,'
      '    :NAME_SGRPPROJECT'
      ')')
    RefreshSQL.Strings = (
      'select * from SGRPPROJECT '
      'where(  ID_SGRPPROJECT=:PARAM_ID'
      
        '     ) and (     SGRPPROJECT.ID_SGRPPROJECT = :OLD_ID_SGRPPROJEC' +
        'T'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from SGRPPROJECT '
      'where ID_SGRPPROJECT=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SGRPPROJECT'
    AutoUpdateOptions.KeyFields = 'ID_SGRPPROJECT'
    AutoUpdateOptions.GeneratorName = 'GEN_SGRPPROJECT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 80
    object ElementID_SGRPPROJECT: TFIBBCDField
      FieldName = 'ID_SGRPPROJECT'
      Size = 0
      RoundByScale = True
    end
    object ElementIDGRP_SGRPPROJECT: TFIBBCDField
      FieldName = 'IDGRP_SGRPPROJECT'
      Size = 0
      RoundByScale = True
    end
    object ElementNAME_SGRPPROJECT: TFIBWideStringField
      FieldName = 'NAME_SGRPPROJECT'
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
    Left = 216
    Top = 24
  end
  object IBTrUpdate: TpFIBTransaction
    TimeoutAction = TARollback
    Left = 216
    Top = 80
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 272
    Top = 56
    qoStartTransaction = True
  end
end
