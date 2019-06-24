object ART_DMSprInfBlockPriv: TART_DMSprInfBlockPriv
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 341
  Width = 435
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE ART_IB_PRIV'
      'SET '
      '    IDBASE_ART_IB_PRIV = :IDBASE_ART_IB_PRIV,'
      '    IDIB_ART_IB_PRIV = :IDIB_ART_IB_PRIV,'
      '    IDGRPUSER_ART_IB_PRIV = :IDGRPUSER_ART_IB_PRIV,'
      '    SEL_ART_IB_PRIV = :SEL_ART_IB_PRIV,'
      '    INS_ART_IB_PRIV = :INS_ART_IB_PRIV,'
      '    UPD_ART_IB_PRIV = :UPD_ART_IB_PRIV,'
      '    DEL_ART_IB_PRIV = :DEL_ART_IB_PRIV'
      'WHERE'
      '    ID_ART_IB_PRIV = :OLD_ID_ART_IB_PRIV'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    ART_IB_PRIV'
      'WHERE'
      '        ID_ART_IB_PRIV = :OLD_ID_ART_IB_PRIV'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO ART_IB_PRIV('
      '    ID_ART_IB_PRIV,'
      '    IDBASE_ART_IB_PRIV,'
      '    IDIB_ART_IB_PRIV,'
      '    IDGRPUSER_ART_IB_PRIV,'
      '    SEL_ART_IB_PRIV,'
      '    INS_ART_IB_PRIV,'
      '    UPD_ART_IB_PRIV,'
      '    DEL_ART_IB_PRIV'
      ')'
      'VALUES('
      '    :ID_ART_IB_PRIV,'
      '    :IDBASE_ART_IB_PRIV,'
      '    :IDIB_ART_IB_PRIV,'
      '    :IDGRPUSER_ART_IB_PRIV,'
      '    :SEL_ART_IB_PRIV,'
      '    :INS_ART_IB_PRIV,'
      '    :UPD_ART_IB_PRIV,'
      '    :DEL_ART_IB_PRIV'
      ')')
    RefreshSQL.Strings = (
      'select art_ib_priv.*,'
      '        sgrpuser.name_sgrpuser'
      'from art_ib_priv'
      
        'left outer join sgrpuser on sgrpuser.id_sgrpuser=art_ib_priv.idg' +
        'rpuser_art_ib_priv'
      'where(  art_ib_priv.idib_art_ib_priv=:PARAM_ID_IB'
      
        '     ) and (     ART_IB_PRIV.ID_ART_IB_PRIV = :OLD_ID_ART_IB_PRI' +
        'V'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select art_ib_priv.*,'
      '        sgrpuser.name_sgrpuser'
      'from art_ib_priv'
      
        'left outer join sgrpuser on sgrpuser.id_sgrpuser=art_ib_priv.idg' +
        'rpuser_art_ib_priv'
      'where art_ib_priv.idib_art_ib_priv=:PARAM_ID_IB'
      'order by sgrpuser.name_sgrpuser')
    AutoUpdateOptions.UpdateTableName = 'ART_IB_PRIV'
    AutoUpdateOptions.KeyFields = 'ID_ART_IB_PRIV'
    AutoUpdateOptions.GeneratorName = 'GEN_ART_IB_PRIV_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 24
    poUseLargeIntField = True
    object TableID_ART_IB_PRIV: TFIBLargeIntField
      FieldName = 'ID_ART_IB_PRIV'
    end
    object TableIDBASE_ART_IB_PRIV: TFIBLargeIntField
      FieldName = 'IDBASE_ART_IB_PRIV'
    end
    object TableIDIB_ART_IB_PRIV: TFIBLargeIntField
      FieldName = 'IDIB_ART_IB_PRIV'
    end
    object TableIDGRPUSER_ART_IB_PRIV: TFIBLargeIntField
      FieldName = 'IDGRPUSER_ART_IB_PRIV'
    end
    object TableSEL_ART_IB_PRIV: TFIBSmallIntField
      FieldName = 'SEL_ART_IB_PRIV'
    end
    object TableINS_ART_IB_PRIV: TFIBSmallIntField
      FieldName = 'INS_ART_IB_PRIV'
    end
    object TableUPD_ART_IB_PRIV: TFIBSmallIntField
      FieldName = 'UPD_ART_IB_PRIV'
    end
    object TableDEL_ART_IB_PRIV: TFIBSmallIntField
      FieldName = 'DEL_ART_IB_PRIV'
    end
    object TableNAME_SGRPUSER: TFIBWideStringField
      FieldName = 'NAME_SGRPUSER'
      Size = 200
    end
    object TableNAME_GRPUSER_LOOKUP: TStringField
      FieldKind = fkLookup
      FieldName = 'NAME_GRPUSER_LOOKUP'
      LookupDataSet = GrpUser
      LookupKeyFields = 'ID_SGRPUSER'
      LookupResultField = 'NAME_SGRPUSER'
      KeyFields = 'IDGRPUSER_ART_IB_PRIV'
      Size = 50
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
    Left = 240
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
    Left = 240
    Top = 80
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 48
    Top = 80
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE ART_IB_PRIV'
      'SET '
      '    IDBASE_ART_IB_PRIV = :IDBASE_ART_IB_PRIV,'
      '    IDIB_ART_IB_PRIV = :IDIB_ART_IB_PRIV,'
      '    IDGRPUSER_ART_IB_PRIV = :IDGRPUSER_ART_IB_PRIV,'
      '    SEL_ART_IB_PRIV = :SEL_ART_IB_PRIV,'
      '    INS_ART_IB_PRIV = :INS_ART_IB_PRIV,'
      '    UPD_ART_IB_PRIV = :UPD_ART_IB_PRIV,'
      '    DEL_ART_IB_PRIV = :DEL_ART_IB_PRIV'
      'WHERE'
      '    ID_ART_IB_PRIV = :OLD_ID_ART_IB_PRIV'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    ART_IB_PRIV'
      'WHERE'
      '        ID_ART_IB_PRIV = :OLD_ID_ART_IB_PRIV'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO ART_IB_PRIV('
      '    ID_ART_IB_PRIV,'
      '    IDBASE_ART_IB_PRIV,'
      '    IDIB_ART_IB_PRIV,'
      '    IDGRPUSER_ART_IB_PRIV,'
      '    SEL_ART_IB_PRIV,'
      '    INS_ART_IB_PRIV,'
      '    UPD_ART_IB_PRIV,'
      '    DEL_ART_IB_PRIV'
      ')'
      'VALUES('
      '    :ID_ART_IB_PRIV,'
      '    :IDBASE_ART_IB_PRIV,'
      '    :IDIB_ART_IB_PRIV,'
      '    :IDGRPUSER_ART_IB_PRIV,'
      '    :SEL_ART_IB_PRIV,'
      '    :INS_ART_IB_PRIV,'
      '    :UPD_ART_IB_PRIV,'
      '    :DEL_ART_IB_PRIV'
      ')')
    RefreshSQL.Strings = (
      'select art_ib_priv.*'
      'from art_ib_priv'
      'where(  art_ib_priv.id_art_ib_priv=:PARAM_ID'
      
        '     ) and (     ART_IB_PRIV.ID_ART_IB_PRIV = :OLD_ID_ART_IB_PRI' +
        'V'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select art_ib_priv.*'
      'from art_ib_priv'
      'where art_ib_priv.id_art_ib_priv=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'ART_IB_PRIV'
    AutoUpdateOptions.KeyFields = 'ID_ART_IB_PRIV'
    AutoUpdateOptions.GeneratorName = 'GEN_ART_IB_PRIV_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 80
    poUseLargeIntField = True
    object ElementID_ART_IB_PRIV: TFIBLargeIntField
      FieldName = 'ID_ART_IB_PRIV'
    end
    object ElementIDBASE_ART_IB_PRIV: TFIBLargeIntField
      FieldName = 'IDBASE_ART_IB_PRIV'
    end
    object ElementIDIB_ART_IB_PRIV: TFIBLargeIntField
      FieldName = 'IDIB_ART_IB_PRIV'
    end
    object ElementIDGRPUSER_ART_IB_PRIV: TFIBLargeIntField
      FieldName = 'IDGRPUSER_ART_IB_PRIV'
    end
    object ElementSEL_ART_IB_PRIV: TFIBSmallIntField
      FieldName = 'SEL_ART_IB_PRIV'
    end
    object ElementINS_ART_IB_PRIV: TFIBSmallIntField
      FieldName = 'INS_ART_IB_PRIV'
    end
    object ElementUPD_ART_IB_PRIV: TFIBSmallIntField
      FieldName = 'UPD_ART_IB_PRIV'
    end
    object ElementDEL_ART_IB_PRIV: TFIBSmallIntField
      FieldName = 'DEL_ART_IB_PRIV'
    end
  end
  object GrpUser: TpFIBDataSet
    SelectSQL.Strings = (
      'select sgrpuser.id_sgrpuser,'
      '       sgrpuser.name_sgrpuser'
      'from sgrpuser'
      'order by sgrpuser.name_sgrpuser')
    Transaction = IBTr
    Left = 240
    Top = 192
    poUseLargeIntField = True
    object GrpUserID_SGRPUSER: TFIBLargeIntField
      FieldName = 'ID_SGRPUSER'
    end
    object GrpUserNAME_SGRPUSER: TFIBWideStringField
      FieldName = 'NAME_SGRPUSER'
      Size = 200
    end
  end
end
