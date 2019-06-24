object HLP_DMSprInfBlockPriv: THLP_DMSprInfBlockPriv
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
      'UPDATE HLP_IB_PRIV'
      'SET '
      '    IDBASE_HLP_IB_PRIV = :IDBASE_HLP_IB_PRIV,'
      '    IDIB_HLP_IB_PRIV = :IDIB_HLP_IB_PRIV,'
      '    IDGRPUSER_HLP_IB_PRIV = :IDGRPUSER_HLP_IB_PRIV,'
      '    SEL_HLP_IB_PRIV = :SEL_HLP_IB_PRIV,'
      '    INS_HLP_IB_PRIV = :INS_HLP_IB_PRIV,'
      '    UPD_HLP_IB_PRIV = :UPD_HLP_IB_PRIV,'
      '    DEL_HLP_IB_PRIV = :DEL_HLP_IB_PRIV'
      'WHERE'
      '    ID_HLP_IB_PRIV = :OLD_ID_HLP_IB_PRIV'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    HLP_IB_PRIV'
      'WHERE'
      '        ID_HLP_IB_PRIV = :OLD_ID_HLP_IB_PRIV'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO HLP_IB_PRIV('
      '    ID_HLP_IB_PRIV,'
      '    IDBASE_HLP_IB_PRIV,'
      '    IDIB_HLP_IB_PRIV,'
      '    IDGRPUSER_HLP_IB_PRIV,'
      '    SEL_HLP_IB_PRIV,'
      '    INS_HLP_IB_PRIV,'
      '    UPD_HLP_IB_PRIV,'
      '    DEL_HLP_IB_PRIV'
      ')'
      'VALUES('
      '    :ID_HLP_IB_PRIV,'
      '    :IDBASE_HLP_IB_PRIV,'
      '    :IDIB_HLP_IB_PRIV,'
      '    :IDGRPUSER_HLP_IB_PRIV,'
      '    :SEL_HLP_IB_PRIV,'
      '    :INS_HLP_IB_PRIV,'
      '    :UPD_HLP_IB_PRIV,'
      '    :DEL_HLP_IB_PRIV'
      ')')
    RefreshSQL.Strings = (
      'select hlp_ib_priv.*,'
      '        sgrpuser.name_sgrpuser'
      'from hlp_ib_priv'
      
        'left outer join sgrpuser on sgrpuser.id_sgrpuser=hlp_ib_priv.idg' +
        'rpuser_hlp_ib_priv'
      'where(  hlp_ib_priv.idib_hlp_ib_priv=:PARAM_ID_IB'
      
        '     ) and (     HLP_IB_PRIV.ID_HLP_IB_PRIV = :OLD_ID_HLP_IB_PRI' +
        'V'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select hlp_ib_priv.*,'
      '        sgrpuser.name_sgrpuser'
      'from hlp_ib_priv'
      
        'left outer join sgrpuser on sgrpuser.id_sgrpuser=hlp_ib_priv.idg' +
        'rpuser_hlp_ib_priv'
      'where hlp_ib_priv.idib_hlp_ib_priv=:PARAM_ID_IB'
      'order by sgrpuser.name_sgrpuser')
    AutoUpdateOptions.UpdateTableName = 'HLP_IB_PRIV'
    AutoUpdateOptions.KeyFields = 'ID_HLP_IB_PRIV'
    AutoUpdateOptions.GeneratorName = 'GEN_HLP_IB_PRIV_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 24
    poUseLargeIntField = True
    object TableID_HLP_IB_PRIV: TFIBLargeIntField
      FieldName = 'ID_HLP_IB_PRIV'
    end
    object TableIDBASE_HLP_IB_PRIV: TFIBLargeIntField
      FieldName = 'IDBASE_HLP_IB_PRIV'
    end
    object TableIDIB_HLP_IB_PRIV: TFIBLargeIntField
      FieldName = 'IDIB_HLP_IB_PRIV'
    end
    object TableIDGRPUSER_HLP_IB_PRIV: TFIBLargeIntField
      FieldName = 'IDGRPUSER_HLP_IB_PRIV'
    end
    object TableSEL_HLP_IB_PRIV: TFIBSmallIntField
      FieldName = 'SEL_HLP_IB_PRIV'
    end
    object TableINS_HLP_IB_PRIV: TFIBSmallIntField
      FieldName = 'INS_HLP_IB_PRIV'
    end
    object TableUPD_HLP_IB_PRIV: TFIBSmallIntField
      FieldName = 'UPD_HLP_IB_PRIV'
    end
    object TableDEL_HLP_IB_PRIV: TFIBSmallIntField
      FieldName = 'DEL_HLP_IB_PRIV'
    end
    object TableNAME_SGRPUSER: TFIBWideStringField
      FieldName = 'NAME_SGRPUSER'
      Size = 200
    end
    object TableNAME_GRP_USER_LOOKUP: TStringField
      FieldKind = fkLookup
      FieldName = 'NAME_GRP_USER_LOOKUP'
      LookupDataSet = GrpUser
      LookupKeyFields = 'ID_SGRPUSER'
      LookupResultField = 'NAME_SGRPUSER'
      KeyFields = 'IDGRPUSER_HLP_IB_PRIV'
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
      'UPDATE HLP_IB_PRIV'
      'SET '
      '    IDBASE_HLP_IB_PRIV = :IDBASE_HLP_IB_PRIV,'
      '    IDIB_HLP_IB_PRIV = :IDIB_HLP_IB_PRIV,'
      '    IDGRPUSER_HLP_IB_PRIV = :IDGRPUSER_HLP_IB_PRIV,'
      '    SEL_HLP_IB_PRIV = :SEL_HLP_IB_PRIV,'
      '    INS_HLP_IB_PRIV = :INS_HLP_IB_PRIV,'
      '    UPD_HLP_IB_PRIV = :UPD_HLP_IB_PRIV,'
      '    DEL_HLP_IB_PRIV = :DEL_HLP_IB_PRIV'
      'WHERE'
      '    ID_HLP_IB_PRIV = :OLD_ID_HLP_IB_PRIV'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    HLP_IB_PRIV'
      'WHERE'
      '        ID_HLP_IB_PRIV = :OLD_ID_HLP_IB_PRIV'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO HLP_IB_PRIV('
      '    ID_HLP_IB_PRIV,'
      '    IDBASE_HLP_IB_PRIV,'
      '    IDIB_HLP_IB_PRIV,'
      '    IDGRPUSER_HLP_IB_PRIV,'
      '    SEL_HLP_IB_PRIV,'
      '    INS_HLP_IB_PRIV,'
      '    UPD_HLP_IB_PRIV,'
      '    DEL_HLP_IB_PRIV'
      ')'
      'VALUES('
      '    :ID_HLP_IB_PRIV,'
      '    :IDBASE_HLP_IB_PRIV,'
      '    :IDIB_HLP_IB_PRIV,'
      '    :IDGRPUSER_HLP_IB_PRIV,'
      '    :SEL_HLP_IB_PRIV,'
      '    :INS_HLP_IB_PRIV,'
      '    :UPD_HLP_IB_PRIV,'
      '    :DEL_HLP_IB_PRIV'
      ')')
    RefreshSQL.Strings = (
      'select hlp_ib_priv.*'
      'from hlp_ib_priv'
      'where(  hlp_ib_priv.id_hlp_ib_priv=:PARAM_ID'
      
        '     ) and (     HLP_IB_PRIV.ID_HLP_IB_PRIV = :OLD_ID_HLP_IB_PRI' +
        'V'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select hlp_ib_priv.*'
      'from hlp_ib_priv'
      'where hlp_ib_priv.id_hlp_ib_priv=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'HLP_IB_PRIV'
    AutoUpdateOptions.KeyFields = 'ID_HLP_IB_PRIV'
    AutoUpdateOptions.GeneratorName = 'GEN_HLP_IB_PRIV_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 80
    poUseLargeIntField = True
    object ElementID_HLP_IB_PRIV: TFIBLargeIntField
      FieldName = 'ID_HLP_IB_PRIV'
    end
    object ElementIDBASE_HLP_IB_PRIV: TFIBLargeIntField
      FieldName = 'IDBASE_HLP_IB_PRIV'
    end
    object ElementIDIB_HLP_IB_PRIV: TFIBLargeIntField
      FieldName = 'IDIB_HLP_IB_PRIV'
    end
    object ElementIDGRPUSER_HLP_IB_PRIV: TFIBLargeIntField
      FieldName = 'IDGRPUSER_HLP_IB_PRIV'
    end
    object ElementSEL_HLP_IB_PRIV: TFIBSmallIntField
      FieldName = 'SEL_HLP_IB_PRIV'
    end
    object ElementINS_HLP_IB_PRIV: TFIBSmallIntField
      FieldName = 'INS_HLP_IB_PRIV'
    end
    object ElementUPD_HLP_IB_PRIV: TFIBSmallIntField
      FieldName = 'UPD_HLP_IB_PRIV'
    end
    object ElementDEL_HLP_IB_PRIV: TFIBSmallIntField
      FieldName = 'DEL_HLP_IB_PRIV'
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
