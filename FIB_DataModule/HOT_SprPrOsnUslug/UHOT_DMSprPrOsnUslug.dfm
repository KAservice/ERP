object HOT_DMSprPrOsnUslug: THOT_DMSprPrOsnUslug
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 307
  Width = 369
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 40
    Top = 16
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 40
    Top = 96
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select'
      'HOT_SPROSNUSL.*,'
      'hot_scatnom.name_hot_scatnom,'
      'hot_stypepos.name_hot_stypepos,'
      'SNOMPR.NAMENOM as NAMENOMPR,'
      'SNOMBR.NAMENOM as NAMENOMBR'
      ''
      'from HOT_SPROSNUSL'
      
        'left outer join HOT_SCATNOM on IDCAT_HOT_SPROSNUSL=ID_HOT_SCATNO' +
        'M'
      
        'left outer join HOT_STYPEPOS on IDTPOS_HOT_SPROSNUSL=ID_HOT_STYP' +
        'EPOS'
      
        'left outer join SNOM as SNOMPR on hot_sprosnusl.idnompr_hot_spro' +
        'snusl=SNOMPR.IDNOM'
      
        'left outer join SNOM as SNOMBR on IDNOMBR_HOT_SPROSNUSL=SNOMBR.I' +
        'DNOM')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 152
    Top = 16
    object TableID_HOT_SPROSNUSL: TFIBBCDField
      FieldName = 'ID_HOT_SPROSNUSL'
      Size = 0
      RoundByScale = True
    end
    object TableIDCAT_HOT_SPROSNUSL: TFIBBCDField
      FieldName = 'IDCAT_HOT_SPROSNUSL'
      Size = 0
      RoundByScale = True
    end
    object TableIDNOMPR_HOT_SPROSNUSL: TFIBBCDField
      FieldName = 'IDNOMPR_HOT_SPROSNUSL'
      Size = 0
      RoundByScale = True
    end
    object TableIDNOMBR_HOT_SPROSNUSL: TFIBBCDField
      FieldName = 'IDNOMBR_HOT_SPROSNUSL'
      Size = 0
      RoundByScale = True
    end
    object TableIDTPOS_HOT_SPROSNUSL: TFIBBCDField
      FieldName = 'IDTPOS_HOT_SPROSNUSL'
      Size = 0
      RoundByScale = True
    end
    object TableIDBASE_HOT_SPROSNUSL: TFIBBCDField
      FieldName = 'IDBASE_HOT_SPROSNUSL'
      Size = 0
      RoundByScale = True
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableNAME_HOT_SCATNOM: TFIBWideStringField
      FieldName = 'NAME_HOT_SCATNOM'
      Size = 100
    end
    object TableNAME_HOT_STYPEPOS: TFIBWideStringField
      FieldName = 'NAME_HOT_STYPEPOS'
      Size = 100
    end
    object TableNAMENOMPR: TFIBWideStringField
      FieldName = 'NAMENOMPR'
      Size = 100
    end
    object TableNAMENOMBR: TFIBWideStringField
      FieldName = 'NAMENOMBR'
      Size = 100
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE HOT_SPROSNUSL'
      'SET '
      '    GID_HOT_SPROSNUSL = :GID_HOT_SPROSNUSL,'
      '    IDCAT_HOT_SPROSNUSL = :IDCAT_HOT_SPROSNUSL,'
      '    IDNOMPR_HOT_SPROSNUSL = :IDNOMPR_HOT_SPROSNUSL,'
      '    IDNOMBR_HOT_SPROSNUSL = :IDNOMBR_HOT_SPROSNUSL,'
      '    IDTPOS_HOT_SPROSNUSL = :IDTPOS_HOT_SPROSNUSL'
      'WHERE'
      '    ID_HOT_SPROSNUSL = :OLD_ID_HOT_SPROSNUSL'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    HOT_SPROSNUSL'
      'WHERE'
      '        ID_HOT_SPROSNUSL = :OLD_ID_HOT_SPROSNUSL'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO HOT_SPROSNUSL('
      '    ID_HOT_SPROSNUSL,'
      '    GID_HOT_SPROSNUSL,'
      '    IDCAT_HOT_SPROSNUSL,'
      '    IDNOMPR_HOT_SPROSNUSL,'
      '    IDNOMBR_HOT_SPROSNUSL,'
      '    IDTPOS_HOT_SPROSNUSL'
      ')'
      'VALUES('
      '    :ID_HOT_SPROSNUSL,'
      '    :GID_HOT_SPROSNUSL,'
      '    :IDCAT_HOT_SPROSNUSL,'
      '    :IDNOMPR_HOT_SPROSNUSL,'
      '    :IDNOMBR_HOT_SPROSNUSL,'
      '    :IDTPOS_HOT_SPROSNUSL'
      ')')
    RefreshSQL.Strings = (
      'select'
      'HOT_SPROSNUSL.*,'
      'hot_scatnom.name_hot_scatnom,'
      'hot_stypepos.name_hot_stypepos,'
      'SNOMPR.NAMENOM as NAMENOMPR,'
      'SNOMBR.NAMENOM as NAMENOMBR'
      ''
      'from HOT_SPROSNUSL'
      
        'left outer join HOT_SCATNOM on IDCAT_HOT_SPROSNUSL=ID_HOT_SCATNO' +
        'M'
      
        'left outer join HOT_STYPEPOS on IDTPOS_HOT_SPROSNUSL=ID_HOT_STYP' +
        'EPOS'
      
        'left outer join SNOM as SNOMPR on hot_sprosnusl.idnompr_hot_spro' +
        'snusl=SNOMPR.IDNOM'
      
        'left outer join SNOM as SNOMBR on IDNOMBR_HOT_SPROSNUSL=SNOMBR.I' +
        'DNOM'
      ''
      ' WHERE '
      '        HOT_SPROSNUSL.ID_HOT_SPROSNUSL = :OLD_ID_HOT_SPROSNUSL'
      '    ')
    SelectSQL.Strings = (
      'select'
      'HOT_SPROSNUSL.*,'
      'hot_scatnom.name_hot_scatnom,'
      'hot_stypepos.name_hot_stypepos,'
      'SNOMPR.NAMENOM as NAMENOMPR,'
      'SNOMBR.NAMENOM as NAMENOMBR'
      ''
      'from HOT_SPROSNUSL'
      
        'left outer join HOT_SCATNOM on IDCAT_HOT_SPROSNUSL=ID_HOT_SCATNO' +
        'M'
      
        'left outer join HOT_STYPEPOS on IDTPOS_HOT_SPROSNUSL=ID_HOT_STYP' +
        'EPOS'
      
        'left outer join SNOM as SNOMPR on hot_sprosnusl.idnompr_hot_spro' +
        'snusl=SNOMPR.IDNOM'
      
        'left outer join SNOM as SNOMBR on IDNOMBR_HOT_SPROSNUSL=SNOMBR.I' +
        'DNOM'
      'where ID_HOT_SPROSNUSL=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'HOT_SPROSNUSL'
    AutoUpdateOptions.KeyFields = 'ID_HOT_SPROSNUSL'
    AutoUpdateOptions.GeneratorName = 'GEN_HOT_SPROSNUSL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 96
    object ElementID_HOT_SPROSNUSL: TFIBBCDField
      FieldName = 'ID_HOT_SPROSNUSL'
      Size = 0
      RoundByScale = True
    end
    object ElementIDCAT_HOT_SPROSNUSL: TFIBBCDField
      FieldName = 'IDCAT_HOT_SPROSNUSL'
      Size = 0
      RoundByScale = True
    end
    object ElementIDNOMPR_HOT_SPROSNUSL: TFIBBCDField
      FieldName = 'IDNOMPR_HOT_SPROSNUSL'
      Size = 0
      RoundByScale = True
    end
    object ElementIDNOMBR_HOT_SPROSNUSL: TFIBBCDField
      FieldName = 'IDNOMBR_HOT_SPROSNUSL'
      Size = 0
      RoundByScale = True
    end
    object ElementIDTPOS_HOT_SPROSNUSL: TFIBBCDField
      FieldName = 'IDTPOS_HOT_SPROSNUSL'
      Size = 0
      RoundByScale = True
    end
    object ElementNAME_HOT_SCATNOM: TFIBWideStringField
      FieldName = 'NAME_HOT_SCATNOM'
      Size = 100
    end
    object ElementNAME_HOT_STYPEPOS: TFIBWideStringField
      FieldName = 'NAME_HOT_STYPEPOS'
      Size = 100
    end
    object ElementNAMENOMPR: TFIBWideStringField
      FieldName = 'NAMENOMPR'
      Size = 100
    end
    object ElementNAMENOMBR: TFIBWideStringField
      FieldName = 'NAMENOMBR'
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
    Left = 264
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
    Left = 264
    Top = 96
  end
  object Query: TpFIBQuery
    Transaction = IBTr
    Left = 264
    Top = 168
    qoStartTransaction = True
  end
end
