object DMSprKlientDopUrL: TDMSprKlientDopUrL
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 136
  Width = 331
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 48
    Top = 24
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SKLIENT_DOPURL'
      'SET '
      '    IDKLIENT_SKLIENT_DOPURL = :IDKLIENT_SKLIENT_DOPURL,'
      '    GID_SKLIENT_DOPURL = :GID_SKLIENT_DOPURL'
      'WHERE'
      '    ID_SKLIENT_DOPURL = :OLD_ID_SKLIENT_DOPURL'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SKLIENT_DOPURL'
      'WHERE'
      '        ID_SKLIENT_DOPURL = :OLD_ID_SKLIENT_DOPURL'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SKLIENT_DOPURL('
      '    ID_SKLIENT_DOPURL,'
      '    IDKLIENT_SKLIENT_DOPURL,'
      '    GID_SKLIENT_DOPURL'
      ')'
      'VALUES('
      '    :ID_SKLIENT_DOPURL,'
      '    :IDKLIENT_SKLIENT_DOPURL,'
      '    :GID_SKLIENT_DOPURL'
      ')')
    RefreshSQL.Strings = (
      'select '
      'SKLIENT_DOPURL.* , NAMEKLIENT'
      'from  SKLIENT_DOPURL'
      'left outer join SKLIENT on IDKLIENT=IDKLIENT_SKLIENT_DOPURL '
      'where( '
      'IDKLIENT_SKLIENT_DOPURL =:PARAM_IDKLIENT_SKLIENT_DOPURL'
      
        '     ) and (     SKLIENT_DOPURL.ID_SKLIENT_DOPURL = :OLD_ID_SKLI' +
        'ENT_DOPURL'
      '     )'
      '     '
      '')
    SelectSQL.Strings = (
      'select '
      'SKLIENT_DOPURL.* , NAMEKLIENT'
      'from  SKLIENT_DOPURL'
      'left outer join SKLIENT on IDKLIENT=IDKLIENT_SKLIENT_DOPURL '
      'where'
      'IDKLIENT_SKLIENT_DOPURL =:PARAM_IDKLIENT_SKLIENT_DOPURL '
      '')
    AutoUpdateOptions.UpdateTableName = 'SKLIENT_DOPURL'
    AutoUpdateOptions.KeyFields = 'ID_SKLIENT_DOPURL'
    AutoUpdateOptions.GeneratorName = 'GEN_SKLIENT_DOPURL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 24
    object ElementID_SKLIENT_DOPURL: TFIBBCDField
      FieldName = 'ID_SKLIENT_DOPURL'
      Size = 0
      RoundByScale = True
    end
    object ElementIDKLIENT_SKLIENT_DOPURL: TFIBBCDField
      FieldName = 'IDKLIENT_SKLIENT_DOPURL'
      Size = 0
      RoundByScale = True
    end
    object ElementGID_SKLIENT_DOPURL: TFIBWideStringField
      FieldName = 'GID_SKLIENT_DOPURL'
      Size = 10
    end
    object ElementNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
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
    Left = 232
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
    Left = 232
    Top = 72
  end
end
