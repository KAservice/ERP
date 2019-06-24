object DMObjectBasePriv: TDMObjectBasePriv
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 219
  Width = 315
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE INTERF_MAINMENU'
      'SET '
      '    IDBASE_INTERF_MAINMENU = :IDBASE_INTERF_MAINMENU,'
      '    IDGRP_INTERF_MAINMENU = :IDGRP_INTERF_MAINMENU,'
      '    NAME_INTERF_MAINMENU = :NAME_INTERF_MAINMENU,'
      '    MODUL_INTERF_MAINMENU = :MODUL_INTERF_MAINMENU,'
      '    IDGRPUSER_INTERF_MAINMENU = :IDGRPUSER_INTERF_MAINMENU,'
      '    APPLICATION_INTERF_MAINMENU = :APPLICATION_INTERF_MAINMENU'
      'WHERE'
      '    ID_INTERF_MAINMENU = :OLD_ID_INTERF_MAINMENU'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    INTERF_MAINMENU'
      'WHERE'
      '        ID_INTERF_MAINMENU = :OLD_ID_INTERF_MAINMENU'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO INTERF_MAINMENU('
      '    ID_INTERF_MAINMENU,'
      '    IDBASE_INTERF_MAINMENU,'
      '    IDGRP_INTERF_MAINMENU,'
      '    NAME_INTERF_MAINMENU,'
      '    MODUL_INTERF_MAINMENU,'
      '    IDGRPUSER_INTERF_MAINMENU,'
      '    APPLICATION_INTERF_MAINMENU'
      ')'
      'VALUES('
      '    :ID_INTERF_MAINMENU,'
      '    :IDBASE_INTERF_MAINMENU,'
      '    :IDGRP_INTERF_MAINMENU,'
      '    :NAME_INTERF_MAINMENU,'
      '    :MODUL_INTERF_MAINMENU,'
      '    :IDGRPUSER_INTERF_MAINMENU,'
      '    :APPLICATION_INTERF_MAINMENU'
      ')')
    RefreshSQL.Strings = (
      'select INTERF_MAINMENU.*, NAME_SGRPUSER'
      'from INTERF_MAINMENU'
      
        'left outer join sgrpuser on ID_SGRPUSER=IDGRPUSER_INTERF_MAINMEN' +
        'U'
      'where(  '
      'IDGRP_INTERF_MAINMENU=:PARAM_IDGRP'
      
        '     ) and (     INTERF_MAINMENU.ID_INTERF_MAINMENU = :OLD_ID_IN' +
        'TERF_MAINMENU'
      '     )'
      '    '
      '')
    SelectSQL.Strings = (
      'select INTERF_MAINMENU.*, NAME_SGRPUSER'
      'from INTERF_MAINMENU'
      
        'left outer join sgrpuser on ID_SGRPUSER=IDGRPUSER_INTERF_MAINMEN' +
        'U'
      'where '
      'IDGRP_INTERF_MAINMENU=:PARAM_IDGRP'
      '')
    AutoUpdateOptions.UpdateTableName = 'SVESNOM'
    AutoUpdateOptions.GeneratorName = 'GEN_SVESNOM_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnCalcFields = TableCalcFields
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    Database = DM.pFIBData
    UpdateTransaction = IBTrUpdate
    Left = 136
    Top = 16
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_INTERF_MAINMENU: TFIBBCDField
      FieldName = 'ID_INTERF_MAINMENU'
      Size = 0
      RoundByScale = True
    end
    object TableIDBASE_INTERF_MAINMENU: TFIBBCDField
      FieldName = 'IDBASE_INTERF_MAINMENU'
      Size = 0
      RoundByScale = True
    end
    object TableIDGRP_INTERF_MAINMENU: TFIBBCDField
      FieldName = 'IDGRP_INTERF_MAINMENU'
      Size = 0
      RoundByScale = True
    end
    object TableIDGRPUSER_INTERF_MAINMENU: TFIBBCDField
      FieldName = 'IDGRPUSER_INTERF_MAINMENU'
      Size = 0
      RoundByScale = True
    end
    object TableNAME_INTERF_MAINMENU: TFIBWideStringField
      FieldName = 'NAME_INTERF_MAINMENU'
      Size = 40
    end
    object TableMODUL_INTERF_MAINMENU: TFIBIntegerField
      FieldName = 'MODUL_INTERF_MAINMENU'
    end
    object TableAPPLICATION_INTERF_MAINMENU: TFIBIntegerField
      FieldName = 'APPLICATION_INTERF_MAINMENU'
    end
    object TableNAME_SGRPUSER: TFIBWideStringField
      FieldName = 'NAME_SGRPUSER'
      Size = 100
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
  object IBTrUpdate: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 224
    Top = 80
  end
  object Element: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE INTERF_MAINMENU'
      'SET '
      '    IDBASE_INTERF_MAINMENU = :IDBASE_INTERF_MAINMENU,'
      '    IDGRP_INTERF_MAINMENU = :IDGRP_INTERF_MAINMENU,'
      '    NAME_INTERF_MAINMENU = :NAME_INTERF_MAINMENU,'
      '    MODUL_INTERF_MAINMENU = :MODUL_INTERF_MAINMENU,'
      '    IDGRPUSER_INTERF_MAINMENU = :IDGRPUSER_INTERF_MAINMENU,'
      '    APPLICATION_INTERF_MAINMENU = :APPLICATION_INTERF_MAINMENU'
      'WHERE'
      '    ID_INTERF_MAINMENU = :OLD_ID_INTERF_MAINMENU'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    INTERF_MAINMENU'
      'WHERE'
      '        ID_INTERF_MAINMENU = :OLD_ID_INTERF_MAINMENU'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO INTERF_MAINMENU('
      '    ID_INTERF_MAINMENU,'
      '    IDBASE_INTERF_MAINMENU,'
      '    IDGRP_INTERF_MAINMENU,'
      '    NAME_INTERF_MAINMENU,'
      '    MODUL_INTERF_MAINMENU,'
      '    IDGRPUSER_INTERF_MAINMENU,'
      '    APPLICATION_INTERF_MAINMENU'
      ')'
      'VALUES('
      '    :ID_INTERF_MAINMENU,'
      '    :IDBASE_INTERF_MAINMENU,'
      '    :IDGRP_INTERF_MAINMENU,'
      '    :NAME_INTERF_MAINMENU,'
      '    :MODUL_INTERF_MAINMENU,'
      '    :IDGRPUSER_INTERF_MAINMENU,'
      '    :APPLICATION_INTERF_MAINMENU'
      ')')
    RefreshSQL.Strings = (
      
        'select * from INTERF_MAINMENU where(  ID_INTERF_MAINMENU=:PARAM_' +
        'ID'
      
        '     ) and (     INTERF_MAINMENU.ID_INTERF_MAINMENU = :OLD_ID_IN' +
        'TERF_MAINMENU'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from INTERF_MAINMENU where ID_INTERF_MAINMENU=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'INTERF_MAINMENU'
    AutoUpdateOptions.KeyFields = 'ID_INTERF_MAINMENU'
    AutoUpdateOptions.GeneratorName = 'GEN_INTERF_MAINMENU_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    Database = DM.pFIBData
    UpdateTransaction = IBTrUpdate
    Left = 136
    Top = 80
    object ElementID_INTERF_MAINMENU: TFIBBCDField
      FieldName = 'ID_INTERF_MAINMENU'
      Size = 0
      RoundByScale = True
    end
    object ElementIDBASE_INTERF_MAINMENU: TFIBBCDField
      FieldName = 'IDBASE_INTERF_MAINMENU'
      Size = 0
      RoundByScale = True
    end
    object ElementIDGRP_INTERF_MAINMENU: TFIBBCDField
      FieldName = 'IDGRP_INTERF_MAINMENU'
      Size = 0
      RoundByScale = True
    end
    object ElementIDGRPUSER_INTERF_MAINMENU: TFIBBCDField
      FieldName = 'IDGRPUSER_INTERF_MAINMENU'
      Size = 0
      RoundByScale = True
    end
    object ElementNAME_INTERF_MAINMENU: TFIBWideStringField
      FieldName = 'NAME_INTERF_MAINMENU'
      Size = 40
    end
    object ElementMODUL_INTERF_MAINMENU: TFIBIntegerField
      FieldName = 'MODUL_INTERF_MAINMENU'
    end
    object ElementAPPLICATION_INTERF_MAINMENU: TFIBIntegerField
      FieldName = 'APPLICATION_INTERF_MAINMENU'
    end
  end
end
