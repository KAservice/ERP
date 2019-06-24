object DMSprVesNomForScale: TDMSprVesNomForScale
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 230
  Width = 375
  object Element: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from SVESNOM where ID_SVESNOM=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SVESNOM'
    AutoUpdateOptions.KeyFields = 'ID_SVESNOM'
    AutoUpdateOptions.GeneratorName = 'GEN_SVESNOM_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    Database = DM.pFIBData
    Left = 136
    Top = 80
    object ElementCODE_SVESNOM: TFIBIntegerField
      FieldName = 'CODE_SVESNOM'
    end
    object ElementID_SVESNOM: TFIBBCDField
      FieldName = 'ID_SVESNOM'
      Size = 0
      RoundByScale = True
    end
    object ElementIDSCALE_SVESNOM: TFIBBCDField
      FieldName = 'IDSCALE_SVESNOM'
      Size = 0
      RoundByScale = True
    end
    object ElementIDNOM_SVESNOM: TFIBBCDField
      FieldName = 'IDNOM_SVESNOM'
      Size = 0
      RoundByScale = True
    end
    object ElementIDBASE_SVESNOM: TFIBBCDField
      FieldName = 'IDBASE_SVESNOM'
      Size = 0
      RoundByScale = True
    end
    object ElementGID_SVESNOM: TFIBWideStringField
      FieldName = 'GID_SVESNOM'
      Size = 10
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
    Left = 224
    Top = 16
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SVESNOM'
      'SET '
      '    GID_SVESNOM = :GID_SVESNOM,'
      '    IDSCALE_SVESNOM = :IDSCALE_SVESNOM,'
      '    IDNOM_SVESNOM = :IDNOM_SVESNOM,'
      '    CODE_SVESNOM = :CODE_SVESNOM'
      'WHERE'
      '    ID_SVESNOM = :OLD_ID_SVESNOM'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SVESNOM'
      'WHERE'
      '        ID_SVESNOM = :OLD_ID_SVESNOM'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SVESNOM('
      '    ID_SVESNOM,'
      '    GID_SVESNOM,'
      '    IDSCALE_SVESNOM,'
      '    IDNOM_SVESNOM,'
      '    CODE_SVESNOM'
      ')'
      'VALUES('
      '    :ID_SVESNOM,'
      '    :GID_SVESNOM,'
      '    :IDSCALE_SVESNOM,'
      '    :IDNOM_SVESNOM,'
      '    :CODE_SVESNOM'
      ')')
    RefreshSQL.Strings = (
      'select SVESNOM.*,  NAMENOM, NAMEED,  ZNACH_PRICE'
      'from SVESNOM'
      'left outer join SNOM on IDNOM_SVESNOM=IDNOM'
      
        'left outer join SPRICE on IDNOM_PRICE=IDNOM_SVESNOM  AND IDTYPE_' +
        'PRICE=:PARAM_IDTYPE_PRICE'
      'left outer join SED on  IDBASEDNOM=IDED'
      'where(  '
      'IDSCALE_SVESNOM=:PARAM_IDSCALE'
      '     ) and (     SVESNOM.ID_SVESNOM = :OLD_ID_SVESNOM'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select SVESNOM.*,'
      '  NAMENOM, NAMEED,  '
      '  ZNACH_PRICE, '
      '  CODE_SED'
      'from SVESNOM'
      'left outer join SNOM on IDNOM_SVESNOM=IDNOM'
      
        'left outer join SPRICE on IDNOM_PRICE=IDNOM_SVESNOM  AND IDTYPE_' +
        'PRICE=:PARAM_IDTYPE_PRICE'
      
        '                                                     AND IDED_SP' +
        'RICE=IDBASEDNOM'
      'left outer join SED on  IDBASEDNOM=IDED'
      'where '
      'IDSCALE_SVESNOM=:PARAM_IDSCALE'
      'order by NAMENOM')
    AutoUpdateOptions.UpdateTableName = 'SVESNOM'
    AutoUpdateOptions.GeneratorName = 'GEN_SVESNOM_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    Database = DM.pFIBData
    Left = 136
    Top = 16
    object TableCODE_SVESNOM: TFIBIntegerField
      FieldName = 'CODE_SVESNOM'
    end
    object TableZNACH_PRICE: TFIBBCDField
      FieldName = 'ZNACH_PRICE'
      Size = 2
      RoundByScale = True
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableCODE_SED: TFIBIntegerField
      FieldName = 'CODE_SED'
    end
    object TableID_SVESNOM: TFIBBCDField
      FieldName = 'ID_SVESNOM'
      Size = 0
      RoundByScale = True
    end
    object TableIDSCALE_SVESNOM: TFIBBCDField
      FieldName = 'IDSCALE_SVESNOM'
      Size = 0
      RoundByScale = True
    end
    object TableIDNOM_SVESNOM: TFIBBCDField
      FieldName = 'IDNOM_SVESNOM'
      Size = 0
      RoundByScale = True
    end
    object TableIDBASE_SVESNOM: TFIBBCDField
      FieldName = 'IDBASE_SVESNOM'
      Size = 0
      RoundByScale = True
    end
    object TableGID_SVESNOM: TFIBWideStringField
      FieldName = 'GID_SVESNOM'
      Size = 10
    end
    object TableNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 100
    end
    object TableNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
    end
  end
end
