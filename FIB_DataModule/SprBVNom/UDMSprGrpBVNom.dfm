object DMSprGrpBVNom: TDMSprGrpBVNom
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 150
  Width = 329
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
      'select * from  SGBVNOM'
      'where IDPOD_GBVNOM=:IDPOD'
      'order by IDGRP_GBVNOM')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 184
    Top = 24
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_GBVNOM: TFIBBCDField
      FieldName = 'ID_GBVNOM'
      Size = 0
      RoundByScale = True
    end
    object TableIDGRP_GBVNOM: TFIBBCDField
      FieldName = 'IDGRP_GBVNOM'
      Size = 0
      RoundByScale = True
    end
    object TableIDPOD_GBVNOM: TFIBBCDField
      FieldName = 'IDPOD_GBVNOM'
      Size = 0
      RoundByScale = True
    end
    object TableNAME_GBVNOM: TFIBWideStringField
      FieldName = 'NAME_GBVNOM'
      Size = 100
    end
    object TableGID_SGBVNOM: TFIBWideStringField
      FieldName = 'GID_SGBVNOM'
      Size = 10
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SGBVNOM'
      'SET '
      '    IDGRP_GBVNOM = :IDGRP_GBVNOM,'
      '    IDPOD_GBVNOM = :IDPOD_GBVNOM,'
      '    NAME_GBVNOM = :NAME_GBVNOM,'
      '    GID_SGBVNOM = :GID_SGBVNOM'
      'WHERE'
      '    ID_GBVNOM = :OLD_ID_GBVNOM'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SGBVNOM'
      'WHERE'
      '        ID_GBVNOM = :OLD_ID_GBVNOM'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SGBVNOM('
      '    ID_GBVNOM,'
      '    IDGRP_GBVNOM,'
      '    IDPOD_GBVNOM,'
      '    NAME_GBVNOM,'
      '    GID_SGBVNOM'
      ')'
      'VALUES('
      '    :ID_GBVNOM,'
      '    :IDGRP_GBVNOM,'
      '    :IDPOD_GBVNOM,'
      '    :NAME_GBVNOM,'
      '    :GID_SGBVNOM'
      ')')
    RefreshSQL.Strings = (
      'select * from  SGBVNOM where(  ID_GBVNOM=:ID'
      '     ) and (     SGBVNOM.ID_GBVNOM = :OLD_ID_GBVNOM'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from  SGBVNOM where ID_GBVNOM=:ID')
    AutoUpdateOptions.UpdateTableName = 'SGBVNOM'
    AutoUpdateOptions.KeyFields = 'ID_GBVNOM'
    AutoUpdateOptions.GeneratorName = 'GEN_SGBVNOM_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 184
    Top = 80
    object ElementID_GBVNOM: TFIBBCDField
      FieldName = 'ID_GBVNOM'
      Size = 0
      RoundByScale = True
    end
    object ElementIDGRP_GBVNOM: TFIBBCDField
      FieldName = 'IDGRP_GBVNOM'
      Size = 0
      RoundByScale = True
    end
    object ElementIDPOD_GBVNOM: TFIBBCDField
      FieldName = 'IDPOD_GBVNOM'
      Size = 0
      RoundByScale = True
    end
    object ElementNAME_GBVNOM: TFIBWideStringField
      FieldName = 'NAME_GBVNOM'
      Size = 100
    end
    object ElementGID_SGBVNOM: TFIBWideStringField
      FieldName = 'GID_SGBVNOM'
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
    Left = 248
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
    Left = 248
    Top = 80
  end
end
