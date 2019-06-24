object DMObjectBasePrivGrp: TDMObjectBasePrivGrp
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 215
  Width = 329
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 64
    Top = 24
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 64
    Top = 80
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select * '
      'from  INTERF_MAINMENU_GRP'
      'where APPLICATION_INTERF_MAINMENU_GRP=:PARAM_MODUL'
      '      and IDGRPUSER_INTERF_MAINMENU_GRP=:PARAM_IDGRPUSER'
      'order by IDGRP_INTERF_MAINMENU_GRP')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Database = DM.pFIBData
    Left = 168
    Top = 24
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_INTERF_MAINMENU_GRP: TFIBBCDField
      FieldName = 'ID_INTERF_MAINMENU_GRP'
      Size = 0
      RoundByScale = True
    end
    object TableIDBASE_INTERF_MAINMENU_GRP: TFIBBCDField
      FieldName = 'IDBASE_INTERF_MAINMENU_GRP'
      Size = 0
      RoundByScale = True
    end
    object TableIDGRPUSER_INTERF_MAINMENU_GRP: TFIBBCDField
      FieldName = 'IDGRPUSER_INTERF_MAINMENU_GRP'
      Size = 0
      RoundByScale = True
    end
    object TableIDGRP_INTERF_MAINMENU_GRP: TFIBBCDField
      FieldName = 'IDGRP_INTERF_MAINMENU_GRP'
      Size = 0
      RoundByScale = True
    end
    object TableAPPLICATION_INTERF_MAINMENU_GRP: TFIBIntegerField
      FieldName = 'APPLICATION_INTERF_MAINMENU_GRP'
    end
    object TableNAME_INTERF_MAINMENU_GRP: TFIBWideStringField
      FieldName = 'NAME_INTERF_MAINMENU_GRP'
      Size = 40
    end
    object TableINDEX_INTERF_MAINMENU_GRP: TFIBIntegerField
      FieldName = 'INDEX_INTERF_MAINMENU_GRP'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE INTERF_MAINMENU_GRP'
      'SET '
      '    IDBASE_INTERF_MAINMENU_GRP = :IDBASE_INTERF_MAINMENU_GRP,'
      
        '    APPLICATION_INTERF_MAINMENU_GRP = :APPLICATION_INTERF_MAINME' +
        'NU_GRP,'
      
        '    IDGRPUSER_INTERF_MAINMENU_GRP = :IDGRPUSER_INTERF_MAINMENU_G' +
        'RP,'
      '    NAME_INTERF_MAINMENU_GRP = :NAME_INTERF_MAINMENU_GRP,'
      '    IDGRP_INTERF_MAINMENU_GRP = :IDGRP_INTERF_MAINMENU_GRP,'
      '    INDEX_INTERF_MAINMENU_GRP = :INDEX_INTERF_MAINMENU_GRP'
      'WHERE'
      '    ID_INTERF_MAINMENU_GRP = :OLD_ID_INTERF_MAINMENU_GRP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    INTERF_MAINMENU_GRP'
      'WHERE'
      '        ID_INTERF_MAINMENU_GRP = :OLD_ID_INTERF_MAINMENU_GRP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO INTERF_MAINMENU_GRP('
      '    ID_INTERF_MAINMENU_GRP,'
      '    IDBASE_INTERF_MAINMENU_GRP,'
      '    APPLICATION_INTERF_MAINMENU_GRP,'
      '    IDGRPUSER_INTERF_MAINMENU_GRP,'
      '    NAME_INTERF_MAINMENU_GRP,'
      '    IDGRP_INTERF_MAINMENU_GRP,'
      '    INDEX_INTERF_MAINMENU_GRP'
      ')'
      'VALUES('
      '    :ID_INTERF_MAINMENU_GRP,'
      '    :IDBASE_INTERF_MAINMENU_GRP,'
      '    :APPLICATION_INTERF_MAINMENU_GRP,'
      '    :IDGRPUSER_INTERF_MAINMENU_GRP,'
      '    :NAME_INTERF_MAINMENU_GRP,'
      '    :IDGRP_INTERF_MAINMENU_GRP,'
      '    :INDEX_INTERF_MAINMENU_GRP'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from  INTERF_MAINMENU_GRP'
      'where(  ID_INTERF_MAINMENU_GRP=:PARAM_ID'
      
        '     ) and (     INTERF_MAINMENU_GRP.ID_INTERF_MAINMENU_GRP = :O' +
        'LD_ID_INTERF_MAINMENU_GRP'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from  INTERF_MAINMENU_GRP'
      'where ID_INTERF_MAINMENU_GRP=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'INTERF_MAINMENU_GRP'
    AutoUpdateOptions.KeyFields = 'ID_INTERF_MAINMENU_GRP'
    AutoUpdateOptions.GeneratorName = 'GEN_INTERF_MAINMENU_GRP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    Database = DM.pFIBData
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 80
    object ElementID_INTERF_MAINMENU_GRP: TFIBBCDField
      FieldName = 'ID_INTERF_MAINMENU_GRP'
      Size = 0
      RoundByScale = True
    end
    object ElementIDBASE_INTERF_MAINMENU_GRP: TFIBBCDField
      FieldName = 'IDBASE_INTERF_MAINMENU_GRP'
      Size = 0
      RoundByScale = True
    end
    object ElementIDGRPUSER_INTERF_MAINMENU_GRP: TFIBBCDField
      FieldName = 'IDGRPUSER_INTERF_MAINMENU_GRP'
      Size = 0
      RoundByScale = True
    end
    object ElementIDGRP_INTERF_MAINMENU_GRP: TFIBBCDField
      FieldName = 'IDGRP_INTERF_MAINMENU_GRP'
      Size = 0
      RoundByScale = True
    end
    object ElementAPPLICATION_INTERF_MAINMENU_GRP: TFIBIntegerField
      FieldName = 'APPLICATION_INTERF_MAINMENU_GRP'
    end
    object ElementNAME_INTERF_MAINMENU_GRP: TFIBWideStringField
      FieldName = 'NAME_INTERF_MAINMENU_GRP'
      Size = 40
    end
    object ElementINDEX_INTERF_MAINMENU_GRP: TFIBIntegerField
      FieldName = 'INDEX_INTERF_MAINMENU_GRP'
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
    Left = 248
    Top = 24
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
    Left = 248
    Top = 80
  end
  object MenuTable: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      
        'from interf_get_table_mainmenu(:PARAM_APPLICATION,:PARAM_IDGRPUS' +
        'ER,0,0,'#39#39',0,'#39#39',0,'#39#39',1), interf_mainmenu'
      
        'where interf_get_table_mainmenu.out_idgrp=interf_mainmenu.idgrp_' +
        'interf_mainmenu')
    Transaction = IBTr
    Database = DM.pFIBData
    Left = 168
    Top = 144
    object MenuTableOUT_IDGRP_1: TFIBBCDField
      FieldName = 'OUT_IDGRP_1'
      Size = 0
      RoundByScale = True
    end
    object MenuTableOUT_IDGRP_2: TFIBBCDField
      FieldName = 'OUT_IDGRP_2'
      Size = 0
      RoundByScale = True
    end
    object MenuTableOUT_IDGRP_3: TFIBBCDField
      FieldName = 'OUT_IDGRP_3'
      Size = 0
      RoundByScale = True
    end
    object MenuTableOUT_NAMEGRP_1: TFIBWideStringField
      FieldName = 'OUT_NAMEGRP_1'
      Size = 100
    end
    object MenuTableOUT_NAMEGRP_2: TFIBWideStringField
      FieldName = 'OUT_NAMEGRP_2'
      Size = 100
    end
    object MenuTableOUT_NAMEGRP_3: TFIBWideStringField
      FieldName = 'OUT_NAMEGRP_3'
      Size = 100
    end
    object MenuTableOUT_IDGRP: TFIBBCDField
      FieldName = 'OUT_IDGRP'
      Size = 0
      RoundByScale = True
    end
    object MenuTableID_INTERF_MAINMENU: TFIBBCDField
      FieldName = 'ID_INTERF_MAINMENU'
      Size = 0
      RoundByScale = True
    end
    object MenuTableIDGRP_INTERF_MAINMENU: TFIBBCDField
      FieldName = 'IDGRP_INTERF_MAINMENU'
      Size = 0
      RoundByScale = True
    end
    object MenuTableNAME_INTERF_MAINMENU: TFIBWideStringField
      FieldName = 'NAME_INTERF_MAINMENU'
      Size = 40
    end
    object MenuTableMODUL_INTERF_MAINMENU: TFIBIntegerField
      FieldName = 'MODUL_INTERF_MAINMENU'
    end
    object MenuTableIDGRPUSER_INTERF_MAINMENU: TFIBBCDField
      FieldName = 'IDGRPUSER_INTERF_MAINMENU'
      Size = 0
      RoundByScale = True
    end
    object MenuTableAPPLICATION_INTERF_MAINMENU: TFIBIntegerField
      FieldName = 'APPLICATION_INTERF_MAINMENU'
    end
    object MenuTableSHORTCUT_INTERF_MAINMENU: TFIBWideStringField
      FieldName = 'SHORTCUT_INTERF_MAINMENU'
      Size = 10
    end
    object MenuTableINDEX_INTERF_MAINMENU: TFIBIntegerField
      FieldName = 'INDEX_INTERF_MAINMENU'
    end
  end
end
