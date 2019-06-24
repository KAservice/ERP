object DMXTableBase: TDMXTableBase
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 163
  Width = 334
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 24
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 48
    Top = 80
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from  XTABLE_BASE')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Database = DM.pFIBData
    Left = 152
    Top = 24
    object TableID_XTABLE_BASE: TFIBIntegerField
      FieldName = 'ID_XTABLE_BASE'
    end
    object TableGID_XTABLE_BASE: TFIBStringField
      FieldName = 'GID_XTABLE_BASE'
      Size = 10
      EmptyStrToNull = True
    end
    object TableNAMETAB_XTABLE_BASE: TFIBStringField
      FieldName = 'NAMETAB_XTABLE_BASE'
      EmptyStrToNull = True
    end
    object TableNAMEPK_XTABLE_BASE: TFIBStringField
      FieldName = 'NAMEPK_XTABLE_BASE'
      Size = 40
      EmptyStrToNull = True
    end
    object TableNAMEGID_XTABLE_BASE: TFIBStringField
      FieldName = 'NAMEGID_XTABLE_BASE'
      Size = 40
      EmptyStrToNull = True
    end
    object TableNAMEIDDOC_XTABLE_BASE: TFIBStringField
      FieldName = 'NAMEIDDOC_XTABLE_BASE'
      Size = 40
      EmptyStrToNull = True
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
      'UPDATE XTABLE_BASE'
      'SET '
      '    GID_XTABLE_BASE = :GID_XTABLE_BASE,'
      '    NAMETAB_XTABLE_BASE = :NAMETAB_XTABLE_BASE,'
      '    NAMEPK_XTABLE_BASE = :NAMEPK_XTABLE_BASE,'
      '    NAMEGID_XTABLE_BASE = :NAMEGID_XTABLE_BASE,'
      '    NAMEIDDOC_XTABLE_BASE = :NAMEIDDOC_XTABLE_BASE,'
      '    NAMEPREFIKS_XTABLE_BASE = :NAMEPREFIKS_XTABLE_BASE'
      'WHERE'
      '    ID_XTABLE_BASE = :OLD_ID_XTABLE_BASE'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    XTABLE_BASE'
      'WHERE'
      '        ID_XTABLE_BASE = :OLD_ID_XTABLE_BASE'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO XTABLE_BASE('
      '    ID_XTABLE_BASE,'
      '    GID_XTABLE_BASE,'
      '    NAMETAB_XTABLE_BASE,'
      '    NAMEPK_XTABLE_BASE,'
      '    NAMEGID_XTABLE_BASE,'
      '    NAMEIDDOC_XTABLE_BASE,'
      '    NAMEPREFIKS_XTABLE_BASE'
      ')'
      'VALUES('
      '    :ID_XTABLE_BASE,'
      '    :GID_XTABLE_BASE,'
      '    :NAMETAB_XTABLE_BASE,'
      '    :NAMEPK_XTABLE_BASE,'
      '    :NAMEGID_XTABLE_BASE,'
      '    :NAMEIDDOC_XTABLE_BASE,'
      '    :NAMEPREFIKS_XTABLE_BASE'
      ')')
    RefreshSQL.Strings = (
      'select * from XTABLE_BASE where(  ID_XTABLE_BASE=:PARAM_ID'
      
        '     ) and (     XTABLE_BASE.ID_XTABLE_BASE = :OLD_ID_XTABLE_BAS' +
        'E'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from XTABLE_BASE where ID_XTABLE_BASE=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'XTABLE_BASE'
    AutoUpdateOptions.KeyFields = 'ID_XTABLE_BASE'
    AutoUpdateOptions.GeneratorName = 'GEN_XTABLE_BASE_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    Database = DM.pFIBData
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 80
    object ElementID_XTABLE_BASE: TFIBIntegerField
      FieldName = 'ID_XTABLE_BASE'
    end
    object ElementGID_XTABLE_BASE: TFIBStringField
      FieldName = 'GID_XTABLE_BASE'
      Size = 10
      EmptyStrToNull = True
    end
    object ElementNAMETAB_XTABLE_BASE: TFIBStringField
      FieldName = 'NAMETAB_XTABLE_BASE'
      EmptyStrToNull = True
    end
    object ElementNAMEPK_XTABLE_BASE: TFIBStringField
      FieldName = 'NAMEPK_XTABLE_BASE'
      Size = 40
      EmptyStrToNull = True
    end
    object ElementNAMEGID_XTABLE_BASE: TFIBStringField
      FieldName = 'NAMEGID_XTABLE_BASE'
      Size = 40
      EmptyStrToNull = True
    end
    object ElementNAMEIDDOC_XTABLE_BASE: TFIBStringField
      FieldName = 'NAMEIDDOC_XTABLE_BASE'
      Size = 40
      EmptyStrToNull = True
    end
    object ElementNAMEPREFIKS_XTABLE_BASE: TFIBStringField
      FieldName = 'NAMEPREFIKS_XTABLE_BASE'
      Size = 2
      EmptyStrToNull = True
    end
  end
  object IBTr: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
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
    DefaultDatabase = DM.pFIBData
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
