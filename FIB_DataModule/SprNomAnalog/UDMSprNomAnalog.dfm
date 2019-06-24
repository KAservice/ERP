object DMSprNomAnalog: TDMSprNomAnalog
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 304
  Width = 551
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object DataSourcePodr: TDataSource
    AutoEdit = False
    Left = 48
    Top = 72
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SNOM_ANALOG'
      'SET '
      '    IDBASE_SNOM_ANALOG = :IDBASE_SNOM_ANALOG,'
      '    GID_SNOM_ANALOG = :GID_SNOM_ANALOG,'
      '    IDNOM_SNOM_ANALOG = :IDNOM_SNOM_ANALOG,'
      '    IDNOMANALOG_SNOM_ANALOG = :IDNOMANALOG_SNOM_ANALOG,'
      '    IDTYPEANALOG_SNOM_ANALOG = :IDTYPEANALOG_SNOM_ANALOG'
      'WHERE'
      '    ID_SNOM_ANALOG = :OLD_ID_SNOM_ANALOG'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SNOM_ANALOG'
      'WHERE'
      '        ID_SNOM_ANALOG = :OLD_ID_SNOM_ANALOG'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SNOM_ANALOG('
      '    ID_SNOM_ANALOG,'
      '    IDBASE_SNOM_ANALOG,'
      '    GID_SNOM_ANALOG,'
      '    IDNOM_SNOM_ANALOG,'
      '    IDNOMANALOG_SNOM_ANALOG,'
      '    IDTYPEANALOG_SNOM_ANALOG'
      ')'
      'VALUES('
      '    :ID_SNOM_ANALOG,'
      '    :IDBASE_SNOM_ANALOG,'
      '    :GID_SNOM_ANALOG,'
      '    :IDNOM_SNOM_ANALOG,'
      '    :IDNOMANALOG_SNOM_ANALOG,'
      '    :IDTYPEANALOG_SNOM_ANALOG'
      ')')
    RefreshSQL.Strings = (
      'select snom_analog.*,'
      '        stype_analog.name_stype_analog,'
      '        snom.namenom,'
      '        snom.artnom,'
      '        snom.codenom,'
      '        sed.nameed,'
      '        sed.shed,'
      '        sprice.znach_price'
      'from snom_analog'
      
        'left outer join stype_analog on snom_analog.idtypeanalog_snom_an' +
        'alog=stype_analog.id_stype_analog'
      
        'left outer join snom on snom_analog.idnomanalog_snom_analog=snom' +
        '.idnom'
      'left outer join sed on snom.idbasednom=sed.ided'
      
        'left outer join sprice on sprice.idnom_price=snom.idnom and spri' +
        'ce.idtype_price=:PARAM_IDTYPE_PRICE'
      '                    and    sprice.ided_sprice=sed.ided'
      'where( '
      '        snom_analog.idnom_snom_analog=:PARAM_ID_VLAD'
      
        '     ) and (     SNOM_ANALOG.ID_SNOM_ANALOG = :OLD_ID_SNOM_ANALO' +
        'G'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select snom_analog.*,'
      '        stype_analog.name_stype_analog,'
      '        snom.namenom,'
      '        snom.artnom,'
      '        snom.codenom,'
      '        sed.nameed,'
      '        sed.shed,'
      '        sprice.znach_price'
      'from snom_analog'
      
        'left outer join stype_analog on snom_analog.idtypeanalog_snom_an' +
        'alog=stype_analog.id_stype_analog'
      
        'left outer join snom on snom_analog.idnomanalog_snom_analog=snom' +
        '.idnom'
      'left outer join sed on snom.idbasednom=sed.ided'
      
        'left outer join sprice on sprice.idnom_price=snom.idnom and spri' +
        'ce.idtype_price=:PARAM_IDTYPE_PRICE'
      '                    and    sprice.ided_sprice=sed.ided'
      'where'
      '        snom_analog.idnom_snom_analog=:PARAM_ID_VLAD'
      'order by snom.namenom')
    AutoUpdateOptions.UpdateTableName = 'SNOM_ANALOG'
    AutoUpdateOptions.KeyFields = 'ID_SNOM_ANALOG'
    AutoUpdateOptions.GeneratorName = 'GEN_SNOM_ANALOG_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnCalcFields = TableCalcFields
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_SNOM_ANALOG: TFIBLargeIntField
      FieldName = 'ID_SNOM_ANALOG'
    end
    object TableIDBASE_SNOM_ANALOG: TFIBLargeIntField
      FieldName = 'IDBASE_SNOM_ANALOG'
    end
    object TableGID_SNOM_ANALOG: TFIBWideStringField
      FieldName = 'GID_SNOM_ANALOG'
      Size = 10
    end
    object TableIDNOM_SNOM_ANALOG: TFIBLargeIntField
      FieldName = 'IDNOM_SNOM_ANALOG'
    end
    object TableIDNOMANALOG_SNOM_ANALOG: TFIBLargeIntField
      FieldName = 'IDNOMANALOG_SNOM_ANALOG'
    end
    object TableIDTYPEANALOG_SNOM_ANALOG: TFIBLargeIntField
      FieldName = 'IDTYPEANALOG_SNOM_ANALOG'
    end
    object TableNAME_STYPE_ANALOG: TFIBWideStringField
      FieldName = 'NAME_STYPE_ANALOG'
      Size = 200
    end
    object TableNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object TableARTNOM: TFIBWideStringField
      FieldName = 'ARTNOM'
    end
    object TableCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object TableNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 200
    end
    object TableSHED: TFIBWideStringField
      FieldName = 'SHED'
      Size = 13
    end
    object TableZNACH_PRICE: TFIBBCDField
      FieldName = 'ZNACH_PRICE'
      Size = 2
      RoundByScale = True
    end
    object TableNAME_TYPE_ANALOG_LOOKUP: TStringField
      FieldKind = fkLookup
      FieldName = 'NAME_TYPE_ANALOG_LOOKUP'
      LookupDataSet = SpisokTypeAnalog
      LookupKeyFields = 'ID_STYPE_ANALOG'
      LookupResultField = 'NAME_STYPE_ANALOG'
      KeyFields = 'IDTYPEANALOG_SNOM_ANALOG'
      Lookup = True
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
    Left = 272
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
    Left = 272
    Top = 72
  end
  object Element: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE SNOM_ANALOG'
      'SET '
      '    IDBASE_SNOM_ANALOG = :IDBASE_SNOM_ANALOG,'
      '    GID_SNOM_ANALOG = :GID_SNOM_ANALOG,'
      '    IDNOM_SNOM_ANALOG = :IDNOM_SNOM_ANALOG,'
      '    IDNOMANALOG_SNOM_ANALOG = :IDNOMANALOG_SNOM_ANALOG,'
      '    IDTYPEANALOG_SNOM_ANALOG = :IDTYPEANALOG_SNOM_ANALOG'
      'WHERE'
      '    ID_SNOM_ANALOG = :OLD_ID_SNOM_ANALOG'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SNOM_ANALOG'
      'WHERE'
      '        ID_SNOM_ANALOG = :OLD_ID_SNOM_ANALOG'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SNOM_ANALOG('
      '    ID_SNOM_ANALOG,'
      '    IDBASE_SNOM_ANALOG,'
      '    GID_SNOM_ANALOG,'
      '    IDNOM_SNOM_ANALOG,'
      '    IDNOMANALOG_SNOM_ANALOG,'
      '    IDTYPEANALOG_SNOM_ANALOG'
      ')'
      'VALUES('
      '    :ID_SNOM_ANALOG,'
      '    :IDBASE_SNOM_ANALOG,'
      '    :GID_SNOM_ANALOG,'
      '    :IDNOM_SNOM_ANALOG,'
      '    :IDNOMANALOG_SNOM_ANALOG,'
      '    :IDTYPEANALOG_SNOM_ANALOG'
      ')')
    RefreshSQL.Strings = (
      'select snom_analog.*,'
      '        stype_analog.name_stype_analog,'
      '        snom.namenom,'
      '        snom.artnom,'
      '        snom.codenom,'
      '        sed.nameed,'
      '        sed.shed'
      'from snom_analog'
      
        'left outer join stype_analog on snom_analog.idtypeanalog_snom_an' +
        'alog=stype_analog.id_stype_analog'
      
        'left outer join snom on snom_analog.idnomanalog_snom_analog=snom' +
        '.idnom'
      'left outer join sed on snom.idbasednom=sed.ided'
      'where( '
      '        snom_analog.id_snom_analog=:PARAM_ID'
      
        '     ) and (     SNOM_ANALOG.ID_SNOM_ANALOG = :OLD_ID_SNOM_ANALO' +
        'G'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select snom_analog.*,'
      '        stype_analog.name_stype_analog,'
      '        snom.namenom,'
      '        snom.artnom,'
      '        snom.codenom,'
      '        sed.nameed,'
      '        sed.shed'
      'from snom_analog'
      
        'left outer join stype_analog on snom_analog.idtypeanalog_snom_an' +
        'alog=stype_analog.id_stype_analog'
      
        'left outer join snom on snom_analog.idnomanalog_snom_analog=snom' +
        '.idnom'
      'left outer join sed on snom.idbasednom=sed.ided'
      'where'
      '        snom_analog.id_snom_analog=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SNOM_ANALOG'
    AutoUpdateOptions.KeyFields = 'ID_SNOM_ANALOG'
    AutoUpdateOptions.GeneratorName = 'GEN_SNOM_ANALOG_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 80
    poUseLargeIntField = True
    object ElementID_SNOM_ANALOG: TFIBLargeIntField
      FieldName = 'ID_SNOM_ANALOG'
    end
    object ElementIDBASE_SNOM_ANALOG: TFIBLargeIntField
      FieldName = 'IDBASE_SNOM_ANALOG'
    end
    object ElementGID_SNOM_ANALOG: TFIBWideStringField
      FieldName = 'GID_SNOM_ANALOG'
      Size = 10
    end
    object ElementIDNOM_SNOM_ANALOG: TFIBLargeIntField
      FieldName = 'IDNOM_SNOM_ANALOG'
    end
    object ElementIDNOMANALOG_SNOM_ANALOG: TFIBLargeIntField
      FieldName = 'IDNOMANALOG_SNOM_ANALOG'
    end
    object ElementIDTYPEANALOG_SNOM_ANALOG: TFIBLargeIntField
      FieldName = 'IDTYPEANALOG_SNOM_ANALOG'
    end
    object ElementNAME_STYPE_ANALOG: TFIBWideStringField
      FieldName = 'NAME_STYPE_ANALOG'
      Size = 200
    end
    object ElementNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object ElementARTNOM: TFIBWideStringField
      FieldName = 'ARTNOM'
    end
    object ElementCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object ElementNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 200
    end
    object ElementSHED: TFIBWideStringField
      FieldName = 'SHED'
      Size = 13
    end
  end
  object SpisokTypeAnalog: TpFIBDataSet
    SelectSQL.Strings = (
      'select stype_analog.name_stype_analog,'
      '        stype_analog.id_stype_analog'
      'from stype_analog')
    Transaction = IBTr
    Left = 240
    Top = 176
    poUseLargeIntField = True
    object SpisokTypeAnalogNAME_STYPE_ANALOG: TFIBWideStringField
      FieldName = 'NAME_STYPE_ANALOG'
      Size = 200
    end
    object SpisokTypeAnalogID_STYPE_ANALOG: TFIBLargeIntField
      FieldName = 'ID_STYPE_ANALOG'
    end
  end
  object DataSourceSpisokTypeAnalog: TDataSource
    DataSet = SpisokTypeAnalog
    Left = 80
    Top = 176
  end
end
