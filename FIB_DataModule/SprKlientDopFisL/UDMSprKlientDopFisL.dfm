object DMSprKlientDopFisL: TDMSprKlientDopFisL
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 198
  Width = 353
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 48
    Top = 24
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SKLIENT_DOPFISL'
      'SET '
      '    IDKLIENT_SKLIENT_DOPFISL = :IDKLIENT_SKLIENT_DOPFISL,'
      '    DATEROG_SKLIENT_DOPFISL = :DATEROG_SKLIENT_DOPFISL,'
      '    MESTOROG_SKLIENT_DOPFISL = :MESTOROG_SKLIENT_DOPFISL,'
      '    DOLRAB_SKLIENT_DOPFISL = :DOLRAB_SKLIENT_DOPFISL,'
      '    MESTORAB_SKLIENT_DOPFISL = :MESTORAB_SKLIENT_DOPFISL,'
      '    GID_SKLIENT_DOPFISL = :GID_SKLIENT_DOPFISL,'
      '    POL_SKLIENT_DOPFISL = :POL_SKLIENT_DOPFISL'
      'WHERE'
      '    ID_SKLIENT_DOPFISL = :OLD_ID_SKLIENT_DOPFISL'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SKLIENT_DOPFISL'
      'WHERE'
      '        ID_SKLIENT_DOPFISL = :OLD_ID_SKLIENT_DOPFISL'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SKLIENT_DOPFISL('
      '    ID_SKLIENT_DOPFISL,'
      '    IDKLIENT_SKLIENT_DOPFISL,'
      '    DATEROG_SKLIENT_DOPFISL,'
      '    MESTOROG_SKLIENT_DOPFISL,'
      '    DOLRAB_SKLIENT_DOPFISL,'
      '    MESTORAB_SKLIENT_DOPFISL,'
      '    GID_SKLIENT_DOPFISL,'
      '    POL_SKLIENT_DOPFISL'
      ')'
      'VALUES('
      '    :ID_SKLIENT_DOPFISL,'
      '    :IDKLIENT_SKLIENT_DOPFISL,'
      '    :DATEROG_SKLIENT_DOPFISL,'
      '    :MESTOROG_SKLIENT_DOPFISL,'
      '    :DOLRAB_SKLIENT_DOPFISL,'
      '    :MESTORAB_SKLIENT_DOPFISL,'
      '    :GID_SKLIENT_DOPFISL,'
      '    :POL_SKLIENT_DOPFISL'
      ')')
    RefreshSQL.Strings = (
      'select'
      '  SKLIENT_DOPFISL.*, NAMEKLIENT'
      'from   SKLIENT_DOPFISL'
      'left outer join SKLIENT on  IDKLIENT=IDKLIENT_SKLIENT_DOPFISL'
      
        'where(   IDKLIENT_SKLIENT_DOPFISL=:PARAM_IDKLIENT_SKLIENT_DOPFIS' +
        'L'
      
        '     ) and (     SKLIENT_DOPFISL.ID_SKLIENT_DOPFISL = :OLD_ID_SK' +
        'LIENT_DOPFISL'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select'
      '  SKLIENT_DOPFISL.*, NAMEKLIENT'
      'from   SKLIENT_DOPFISL'
      'left outer join SKLIENT on  IDKLIENT=IDKLIENT_SKLIENT_DOPFISL'
      'where  IDKLIENT_SKLIENT_DOPFISL=:PARAM_IDKLIENT_SKLIENT_DOPFISL')
    AutoUpdateOptions.UpdateTableName = 'SKLIENT_DOPFISL'
    AutoUpdateOptions.KeyFields = 'ID_SKLIENT_DOPFISL'
    AutoUpdateOptions.GeneratorName = 'GEN_SKLIENT_DOPFISL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 24
    object ElementPOL_SKLIENT_DOPFISL: TFIBIntegerField
      FieldName = 'POL_SKLIENT_DOPFISL'
      OnGetText = ElementPOL_SKLIENT_DOPFISLGetText
      OnSetText = ElementPOL_SKLIENT_DOPFISLSetText
    end
    object ElementID_SKLIENT_DOPFISL: TFIBBCDField
      FieldName = 'ID_SKLIENT_DOPFISL'
      Size = 0
      RoundByScale = True
    end
    object ElementIDKLIENT_SKLIENT_DOPFISL: TFIBBCDField
      FieldName = 'IDKLIENT_SKLIENT_DOPFISL'
      Size = 0
      RoundByScale = True
    end
    object ElementDATEROG_SKLIENT_DOPFISL: TFIBDateField
      FieldName = 'DATEROG_SKLIENT_DOPFISL'
    end
    object ElementMESTOROG_SKLIENT_DOPFISL: TFIBWideStringField
      FieldName = 'MESTOROG_SKLIENT_DOPFISL'
      Size = 100
    end
    object ElementDOLRAB_SKLIENT_DOPFISL: TFIBWideStringField
      FieldName = 'DOLRAB_SKLIENT_DOPFISL'
    end
    object ElementMESTORAB_SKLIENT_DOPFISL: TFIBWideStringField
      FieldName = 'MESTORAB_SKLIENT_DOPFISL'
      Size = 100
    end
    object ElementIDBASE_SKLIENT_DOPFISL: TFIBBCDField
      FieldName = 'IDBASE_SKLIENT_DOPFISL'
      Size = 0
      RoundByScale = True
    end
    object ElementNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 100
    end
    object ElementGID_SKLIENT_DOPFISL: TFIBWideStringField
      FieldName = 'GID_SKLIENT_DOPFISL'
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
    Left = 280
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
    Left = 280
    Top = 88
  end
end
