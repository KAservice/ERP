object DMXVipolnObmen: TDMXVipolnObmen
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 403
  Width = 662
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 8
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 56
    Top = 64
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select xvipoln_obmen.*,'
      '    sinfbase_obmen.name_sinfbase_obmen,'
      '    sinfbase_obmen.noact_sinfbase_obmen'
      'from xvipoln_obmen'
      
        'left outer join sinfbase_obmen on xvipoln_obmen.idinfbase_xvipol' +
        'n_obmen=sinfbase_obmen.id_sinfbase_obmen')
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object TableID_XVIPOLN_OBMEN: TFIBLargeIntField
      FieldName = 'ID_XVIPOLN_OBMEN'
    end
    object TableIDBASE_XVIPOLN_OBMEN: TFIBLargeIntField
      FieldName = 'IDBASE_XVIPOLN_OBMEN'
    end
    object TableIDINFBASE_XVIPOLN_OBMEN: TFIBLargeIntField
      FieldName = 'IDINFBASE_XVIPOLN_OBMEN'
    end
    object TablePOS_ZAGR_XVIPOLN_OBMEN: TFIBDateTimeField
      FieldName = 'POS_ZAGR_XVIPOLN_OBMEN'
    end
    object TablePOS_VIGR_XVIPOLN_OBMEN: TFIBDateTimeField
      FieldName = 'POS_VIGR_XVIPOLN_OBMEN'
    end
    object TableNAME_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 200
    end
    object TableNOACT_SINFBASE_OBMEN: TFIBSmallIntField
      FieldName = 'NOACT_SINFBASE_OBMEN'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE XVIPOLN_OBMEN'
      'SET '
      '    IDBASE_XVIPOLN_OBMEN = :IDBASE_XVIPOLN_OBMEN,'
      '    IDINFBASE_XVIPOLN_OBMEN = :IDINFBASE_XVIPOLN_OBMEN,'
      '    POS_ZAGR_XVIPOLN_OBMEN = :POS_ZAGR_XVIPOLN_OBMEN,'
      '    POS_VIGR_XVIPOLN_OBMEN = :POS_VIGR_XVIPOLN_OBMEN'
      'WHERE'
      '    ID_XVIPOLN_OBMEN = :OLD_ID_XVIPOLN_OBMEN'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    XVIPOLN_OBMEN'
      'WHERE'
      '        ID_XVIPOLN_OBMEN = :OLD_ID_XVIPOLN_OBMEN'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO XVIPOLN_OBMEN('
      '    ID_XVIPOLN_OBMEN,'
      '    IDBASE_XVIPOLN_OBMEN,'
      '    IDINFBASE_XVIPOLN_OBMEN,'
      '    POS_ZAGR_XVIPOLN_OBMEN,'
      '    POS_VIGR_XVIPOLN_OBMEN'
      ')'
      'VALUES('
      '    :ID_XVIPOLN_OBMEN,'
      '    :IDBASE_XVIPOLN_OBMEN,'
      '    :IDINFBASE_XVIPOLN_OBMEN,'
      '    :POS_ZAGR_XVIPOLN_OBMEN,'
      '    :POS_VIGR_XVIPOLN_OBMEN'
      ')')
    RefreshSQL.Strings = (
      'select xvipoln_obmen.*,'
      '    sinfbase_obmen.name_sinfbase_obmen,'
      '    sinfbase_obmen.noact_sinfbase_obmen'
      'from xvipoln_obmen'
      
        'left outer join sinfbase_obmen on xvipoln_obmen.idinfbase_xvipol' +
        'n_obmen=sinfbase_obmen.id_sinfbase_obmen'
      ''
      'where(  xvipoln_obmen.id_xvipoln_obmen=:PARAM_ID'
      
        '     ) and (     XVIPOLN_OBMEN.ID_XVIPOLN_OBMEN = :OLD_ID_XVIPOL' +
        'N_OBMEN'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select xvipoln_obmen.*,'
      '    sinfbase_obmen.name_sinfbase_obmen,'
      '    sinfbase_obmen.noact_sinfbase_obmen'
      'from xvipoln_obmen'
      
        'left outer join sinfbase_obmen on xvipoln_obmen.idinfbase_xvipol' +
        'n_obmen=sinfbase_obmen.id_sinfbase_obmen'
      ''
      'where xvipoln_obmen.id_xvipoln_obmen=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'ART_IB'
    AutoUpdateOptions.KeyFields = 'ID_ART_IB'
    AutoUpdateOptions.GeneratorName = 'GEN_ART_IB_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object ElementID_XVIPOLN_OBMEN: TFIBLargeIntField
      FieldName = 'ID_XVIPOLN_OBMEN'
    end
    object ElementIDBASE_XVIPOLN_OBMEN: TFIBLargeIntField
      FieldName = 'IDBASE_XVIPOLN_OBMEN'
    end
    object ElementIDINFBASE_XVIPOLN_OBMEN: TFIBLargeIntField
      FieldName = 'IDINFBASE_XVIPOLN_OBMEN'
    end
    object ElementPOS_ZAGR_XVIPOLN_OBMEN: TFIBDateTimeField
      FieldName = 'POS_ZAGR_XVIPOLN_OBMEN'
    end
    object ElementPOS_VIGR_XVIPOLN_OBMEN: TFIBDateTimeField
      FieldName = 'POS_VIGR_XVIPOLN_OBMEN'
    end
    object ElementNAME_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 200
    end
    object ElementNOACT_SINFBASE_OBMEN: TFIBSmallIntField
      FieldName = 'NOACT_SINFBASE_OBMEN'
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
    Left = 256
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
    Left = 256
    Top = 64
  end
  object Query: TpFIBQuery
    Transaction = IBTr
    Left = 152
    Top = 144
    qoStartTransaction = True
  end
end
