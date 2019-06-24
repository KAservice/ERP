object DMSprMPrig: TDMSprMPrig
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 156
  Width = 306
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 48
    Top = 88
  end
  object Table: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE SMPRIG'
      'SET '
      '    IDSKLAD_MPRIG = :IDSKLAD_MPRIG,'
      '    IDOBORUD_MPRIG = :IDOBORUD_MPRIG,'
      '    NAME_MPRIG = :NAME_MPRIG,'
      '    GID_SMPRIG = :GID_SMPRIG'
      'WHERE'
      '    ID_MPRIG = :OLD_ID_MPRIG'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SMPRIG'
      'WHERE'
      '        ID_MPRIG = :OLD_ID_MPRIG'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SMPRIG('
      '    ID_MPRIG,'
      '    IDSKLAD_MPRIG,'
      '    IDOBORUD_MPRIG,'
      '    NAME_MPRIG,'
      '    GID_SMPRIG'
      ')'
      'VALUES('
      '    :ID_MPRIG,'
      '    :IDSKLAD_MPRIG,'
      '    :IDOBORUD_MPRIG,'
      '    :NAME_MPRIG,'
      '    :GID_SMPRIG'
      ')')
    RefreshSQL.Strings = (
      'select '
      '  SMPRIG.*,  NAMESKLAD, NAME_OBORUD'
      'from '
      '  SMPRIG'
      'left outer join   SSKLAD on IDSKLAD_MPRIG=IDSKLAD'
      'left outer join SOBORUD on  IDOBORUD_MPRIG=ID_OBORUD'
      ' WHERE '
      '        SMPRIG.ID_MPRIG = :OLD_ID_MPRIG'
      '    ')
    SelectSQL.Strings = (
      'select '
      '  SMPRIG.*,  NAMESKLAD, NAME_OBORUD'
      'from '
      '  SMPRIG'
      'left outer join   SSKLAD on IDSKLAD_MPRIG=IDSKLAD'
      'left outer join SOBORUD on  IDOBORUD_MPRIG=ID_OBORUD')
    Transaction = IBTr
    Left = 152
    Top = 16
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_MPRIG: TFIBBCDField
      FieldName = 'ID_MPRIG'
      Size = 0
      RoundByScale = True
    end
    object TableIDSKLAD_MPRIG: TFIBBCDField
      FieldName = 'IDSKLAD_MPRIG'
      Size = 0
      RoundByScale = True
    end
    object TableIDOBORUD_MPRIG: TFIBBCDField
      FieldName = 'IDOBORUD_MPRIG'
      Size = 0
      RoundByScale = True
    end
    object TableIDBASE_SMPRIG: TFIBBCDField
      FieldName = 'IDBASE_SMPRIG'
      Size = 0
      RoundByScale = True
    end
    object TableNAME_MPRIG: TFIBWideStringField
      FieldName = 'NAME_MPRIG'
      Size = 100
    end
    object TableGID_SMPRIG: TFIBWideStringField
      FieldName = 'GID_SMPRIG'
      Size = 10
    end
    object TableNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 100
    end
    object TableNAME_OBORUD: TFIBWideStringField
      FieldName = 'NAME_OBORUD'
      Size = 100
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SMPRIG'
      'SET '
      '    IDSKLAD_MPRIG = :IDSKLAD_MPRIG,'
      '    IDOBORUD_MPRIG = :IDOBORUD_MPRIG,'
      '    NAME_MPRIG = :NAME_MPRIG,'
      '    GID_SMPRIG = :GID_SMPRIG'
      'WHERE'
      '    ID_MPRIG = :OLD_ID_MPRIG'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SMPRIG'
      'WHERE'
      '        ID_MPRIG = :OLD_ID_MPRIG'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SMPRIG('
      '    ID_MPRIG,'
      '    IDSKLAD_MPRIG,'
      '    IDOBORUD_MPRIG,'
      '    NAME_MPRIG,'
      '    GID_SMPRIG'
      ')'
      'VALUES('
      '    :ID_MPRIG,'
      '    :IDSKLAD_MPRIG,'
      '    :IDOBORUD_MPRIG,'
      '    :NAME_MPRIG,'
      '    :GID_SMPRIG'
      ')')
    RefreshSQL.Strings = (
      'select '
      '  SMPRIG.*,  NAMESKLAD, NAME_OBORUD'
      'from '
      '  SMPRIG'
      'left outer join   SSKLAD on IDSKLAD_MPRIG=IDSKLAD'
      'left outer join SOBORUD on  IDOBORUD_MPRIG=ID_OBORUD'
      'where(  '
      '  ID_MPRIG=:PARAM_ID_MPRIG'
      '     ) and (     SMPRIG.ID_MPRIG = :OLD_ID_MPRIG'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select '
      '  SMPRIG.*,  NAMESKLAD, NAME_OBORUD'
      'from '
      '  SMPRIG'
      'left outer join   SSKLAD on IDSKLAD_MPRIG=IDSKLAD'
      'left outer join SOBORUD on  IDOBORUD_MPRIG=ID_OBORUD'
      'where '
      '  ID_MPRIG=:PARAM_ID_MPRIG')
    AutoUpdateOptions.UpdateTableName = 'SMPRIG'
    AutoUpdateOptions.KeyFields = 'ID_MPRIG'
    AutoUpdateOptions.GeneratorName = 'GEN_SMPRIG_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 88
    object ElementID_MPRIG: TFIBBCDField
      FieldName = 'ID_MPRIG'
      Size = 0
      RoundByScale = True
    end
    object ElementIDSKLAD_MPRIG: TFIBBCDField
      FieldName = 'IDSKLAD_MPRIG'
      Size = 0
      RoundByScale = True
    end
    object ElementIDOBORUD_MPRIG: TFIBBCDField
      FieldName = 'IDOBORUD_MPRIG'
      Size = 0
      RoundByScale = True
    end
    object ElementIDBASE_SMPRIG: TFIBBCDField
      FieldName = 'IDBASE_SMPRIG'
      Size = 0
      RoundByScale = True
    end
    object ElementNAME_MPRIG: TFIBWideStringField
      FieldName = 'NAME_MPRIG'
      Size = 100
    end
    object ElementGID_SMPRIG: TFIBWideStringField
      FieldName = 'GID_SMPRIG'
      Size = 10
    end
    object ElementNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 100
    end
    object ElementNAME_OBORUD: TFIBWideStringField
      FieldName = 'NAME_OBORUD'
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
    Left = 240
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
    Left = 240
    Top = 88
  end
end
