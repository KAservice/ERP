object DMSprGrpUser: TDMSprGrpUser
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 144
  Width = 299
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
      '  SGRPUSER'
      'order by IDGRP_SGRPUSER')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 144
    Top = 24
    object TableINTERF_SGRPUSER: TFIBIntegerField
      FieldName = 'INTERF_SGRPUSER'
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_SGRPUSER: TFIBBCDField
      FieldName = 'ID_SGRPUSER'
      Size = 0
      RoundByScale = True
    end
    object TableIDGRP_SGRPUSER: TFIBBCDField
      FieldName = 'IDGRP_SGRPUSER'
      Size = 0
      RoundByScale = True
    end
    object TableGID_SGRPUSER: TFIBWideStringField
      FieldName = 'GID_SGRPUSER'
      Size = 10
    end
    object TableNAME_SGRPUSER: TFIBWideStringField
      FieldName = 'NAME_SGRPUSER'
      Size = 100
    end
    object TableROLE_SGRPUSER: TFIBWideStringField
      FieldName = 'ROLE_SGRPUSER'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SGRPUSER'
      'SET '
      '    GID_SGRPUSER = :GID_SGRPUSER,'
      '    IDGRP_SGRPUSER = :IDGRP_SGRPUSER,'
      '    NAME_SGRPUSER = :NAME_SGRPUSER,'
      '    INTERF_SGRPUSER = :INTERF_SGRPUSER,'
      '    ROLE_SGRPUSER = :ROLE_SGRPUSER'
      'WHERE'
      '    ID_SGRPUSER = :OLD_ID_SGRPUSER'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SGRPUSER'
      'WHERE'
      '        ID_SGRPUSER = :OLD_ID_SGRPUSER'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SGRPUSER('
      '    ID_SGRPUSER,'
      '    GID_SGRPUSER,'
      '    IDGRP_SGRPUSER,'
      '    NAME_SGRPUSER,'
      '    INTERF_SGRPUSER,'
      '    ROLE_SGRPUSER'
      ')'
      'VALUES('
      '    :ID_SGRPUSER,'
      '    :GID_SGRPUSER,'
      '    :IDGRP_SGRPUSER,'
      '    :NAME_SGRPUSER,'
      '    :INTERF_SGRPUSER,'
      '    :ROLE_SGRPUSER'
      ')')
    RefreshSQL.Strings = (
      'select * from SGRPUSER where(  ID_SGRPUSER=:ID'
      '     ) and (     SGRPUSER.ID_SGRPUSER = :OLD_ID_SGRPUSER'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from SGRPUSER where ID_SGRPUSER=:ID')
    AutoUpdateOptions.UpdateTableName = 'SGRPUSER'
    AutoUpdateOptions.KeyFields = 'ID_SGRPUSER'
    AutoUpdateOptions.GeneratorName = 'GEN_SGRPUSER_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 80
    object ElementID_SGRPUSER: TFIBBCDField
      FieldName = 'ID_SGRPUSER'
      Size = 0
      RoundByScale = True
    end
    object ElementIDGRP_SGRPUSER: TFIBBCDField
      FieldName = 'IDGRP_SGRPUSER'
      Size = 0
      RoundByScale = True
    end
    object ElementGID_SGRPUSER: TFIBWideStringField
      FieldName = 'GID_SGRPUSER'
      Size = 10
    end
    object ElementNAME_SGRPUSER: TFIBWideStringField
      FieldName = 'NAME_SGRPUSER'
      Size = 100
    end
    object ElementINTERF_SGRPUSER: TFIBSmallIntField
      FieldName = 'INTERF_SGRPUSER'
    end
    object ElementROLE_SGRPUSER: TFIBWideStringField
      FieldName = 'ROLE_SGRPUSER'
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
end
