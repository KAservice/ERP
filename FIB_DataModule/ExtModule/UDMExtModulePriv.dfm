object DMExtModulePriv: TDMExtModulePriv
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 273
  Width = 302
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 16
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE EXT_MODULE_PRIV'
      'SET '
      '    IDMODULE_EXT_MODULE_PRIV = :IDMODULE_EXT_MODULE_PRIV,'
      '    INS_EXT_MODULE_PRIV = :INS_EXT_MODULE_PRIV,'
      '    EDIT_EXT_MODULE_PRIV = :EDIT_EXT_MODULE_PRIV,'
      '    DEL_EXT_MODULE_PRIV = :DEL_EXT_MODULE_PRIV,'
      '    EXEC_EXT_MODULE_PRIV = :EXEC_EXT_MODULE_PRIV,'
      '    IDGRPUSER_EXT_MODULE_PRIV = :IDGRPUSER_EXT_MODULE_PRIV'
      'WHERE'
      '    ID_EXT_MODULE_PRIV = :OLD_ID_EXT_MODULE_PRIV'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    EXT_MODULE_PRIV'
      'WHERE'
      '        ID_EXT_MODULE_PRIV = :OLD_ID_EXT_MODULE_PRIV'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO EXT_MODULE_PRIV('
      '    ID_EXT_MODULE_PRIV,'
      '    IDMODULE_EXT_MODULE_PRIV,'
      '    INS_EXT_MODULE_PRIV,'
      '    EDIT_EXT_MODULE_PRIV,'
      '    DEL_EXT_MODULE_PRIV,'
      '    EXEC_EXT_MODULE_PRIV,'
      '    IDGRPUSER_EXT_MODULE_PRIV'
      ')'
      'VALUES('
      '    :ID_EXT_MODULE_PRIV,'
      '    :IDMODULE_EXT_MODULE_PRIV,'
      '    :INS_EXT_MODULE_PRIV,'
      '    :EDIT_EXT_MODULE_PRIV,'
      '    :DEL_EXT_MODULE_PRIV,'
      '    :EXEC_EXT_MODULE_PRIV,'
      '    :IDGRPUSER_EXT_MODULE_PRIV'
      ')')
    RefreshSQL.Strings = (
      'select *'
      'from '
      '  EXT_MODULE_PRIV'
      'where(  '
      '  IDMODULE_EXT_MODULE_PRIV=:PARAM_IDMODULE'
      
        '     ) and (     EXT_MODULE_PRIV.ID_EXT_MODULE_PRIV = :OLD_ID_EX' +
        'T_MODULE_PRIV'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select *'
      'from '
      '  EXT_MODULE_PRIV'
      'where '
      '  IDMODULE_EXT_MODULE_PRIV=:PARAM_IDMODULE')
    AutoUpdateOptions.UpdateTableName = 'EXT_MODULE_PRIV'
    AutoUpdateOptions.KeyFields = 'ID_EXT_MODULE_PRIV'
    AutoUpdateOptions.GeneratorName = 'GEN_EXT_MODULE_PRIV_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 16
    object TableIDMODULE_EXT_MODULE_PRIV: TFIBBCDField
      FieldName = 'IDMODULE_EXT_MODULE_PRIV'
      Size = 0
      RoundByScale = True
    end
    object TableINS_EXT_MODULE_PRIV: TFIBSmallIntField
      FieldName = 'INS_EXT_MODULE_PRIV'
    end
    object TableEDIT_EXT_MODULE_PRIV: TFIBSmallIntField
      FieldName = 'EDIT_EXT_MODULE_PRIV'
    end
    object TableDEL_EXT_MODULE_PRIV: TFIBSmallIntField
      FieldName = 'DEL_EXT_MODULE_PRIV'
    end
    object TableEXEC_EXT_MODULE_PRIV: TFIBSmallIntField
      FieldName = 'EXEC_EXT_MODULE_PRIV'
    end
    object TableID_EXT_MODULE_PRIV: TFIBBCDField
      FieldName = 'ID_EXT_MODULE_PRIV'
      Size = 0
      RoundByScale = True
    end
    object TableIDGRPUSER_EXT_MODULE_PRIV: TFIBBCDField
      FieldName = 'IDGRPUSER_EXT_MODULE_PRIV'
      Size = 0
      RoundByScale = True
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
    Left = 232
    Top = 72
  end
  object SprGrpUser: TpFIBDataSet
    SelectSQL.Strings = (
      'select * '
      'from SGRPUSER')
    Transaction = IBTr
    Left = 152
    Top = 112
    object SprGrpUserID_SGRPUSER: TFIBBCDField
      FieldName = 'ID_SGRPUSER'
      Size = 0
      RoundByScale = True
    end
    object SprGrpUserNAME_SGRPUSER: TFIBWideStringField
      FieldName = 'NAME_SGRPUSER'
      Size = 100
    end
    object SprGrpUserROLE_SGRPUSER: TFIBWideStringField
      FieldName = 'ROLE_SGRPUSER'
    end
  end
  object DataSourceSprGrpUser: TDataSource
    DataSet = SprGrpUser
    Left = 48
    Top = 112
  end
  object Query: TpFIBQuery
    Transaction = IBTr
    Left = 152
    Top = 200
    qoStartTransaction = True
  end
end
