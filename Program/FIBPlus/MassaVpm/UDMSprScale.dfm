object DMSprScale: TDMSprScale
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 162
  Width = 373
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
      '  SSCALE')
    Transaction = IBTr
    Database = DM.pFIBData
    Left = 168
    Top = 24
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_SSCALE: TFIBBCDField
      FieldName = 'ID_SSCALE'
      Size = 0
      RoundByScale = True
    end
    object TableGID_SSCALE: TFIBWideStringField
      FieldName = 'GID_SSCALE'
      Size = 10
    end
    object TableNAME_SSCALE: TFIBWideStringField
      FieldName = 'NAME_SSCALE'
      Size = 100
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SSCALE'
      'SET '
      '    GID_SSCALE = :GID_SSCALE,'
      '    NAME_SSCALE = :NAME_SSCALE'
      'WHERE'
      '    ID_SSCALE = :OLD_ID_SSCALE'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SSCALE'
      'WHERE'
      '        ID_SSCALE = :OLD_ID_SSCALE'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SSCALE('
      '    ID_SSCALE,'
      '    GID_SSCALE,'
      '    NAME_SSCALE'
      ')'
      'VALUES('
      '    :ID_SSCALE,'
      '    :GID_SSCALE,'
      '    :NAME_SSCALE'
      ')')
    RefreshSQL.Strings = (
      'select * from SSCALE where(  ID_SSCALE=:PARAM_ID'
      '     ) and (     SSCALE.ID_SSCALE = :OLD_ID_SSCALE'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from SSCALE where ID_SSCALE=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SSCALE'
    AutoUpdateOptions.KeyFields = 'ID_SSCALE'
    AutoUpdateOptions.GeneratorName = 'GEN_SSCALE_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    Database = DM.pFIBData
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 80
    object ElementID_SSCALE: TFIBBCDField
      FieldName = 'ID_SSCALE'
      Size = 0
      RoundByScale = True
    end
    object ElementGID_SSCALE: TFIBWideStringField
      FieldName = 'GID_SSCALE'
      Size = 10
    end
    object ElementNAME_SSCALE: TFIBWideStringField
      FieldName = 'NAME_SSCALE'
      Size = 100
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
    Left = 256
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
    Left = 256
    Top = 80
  end
end
