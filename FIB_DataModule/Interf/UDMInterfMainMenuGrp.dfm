object DMInterfMainMenuGrp: TDMInterfMainMenuGrp
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 267
  Width = 371
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
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 24
    poUseGuidField = True
    poUseLargeIntField = True
    object TableID_INTERF_MAINMENU_GRP: TFIBLargeIntField
      FieldName = 'ID_INTERF_MAINMENU_GRP'
    end
    object TableIDBASE_INTERF_MAINMENU_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_INTERF_MAINMENU_GRP'
    end
    object TableAPPLICATION_INTERF_MAINMENU_GRP: TFIBIntegerField
      FieldName = 'APPLICATION_INTERF_MAINMENU_GRP'
    end
    object TableIDGRPUSER_INTERF_MAINMENU_GRP: TFIBLargeIntField
      FieldName = 'IDGRPUSER_INTERF_MAINMENU_GRP'
    end
    object TableNAME_INTERF_MAINMENU_GRP: TFIBWideStringField
      FieldName = 'NAME_INTERF_MAINMENU_GRP'
      Size = 40
    end
    object TableIDGRP_INTERF_MAINMENU_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_INTERF_MAINMENU_GRP'
    end
    object TableINDEX_INTERF_MAINMENU_GRP: TFIBIntegerField
      FieldName = 'INDEX_INTERF_MAINMENU_GRP'
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
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
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 80
    poUseLargeIntField = True
    object ElementID_INTERF_MAINMENU_GRP: TFIBLargeIntField
      FieldName = 'ID_INTERF_MAINMENU_GRP'
    end
    object ElementIDBASE_INTERF_MAINMENU_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_INTERF_MAINMENU_GRP'
    end
    object ElementAPPLICATION_INTERF_MAINMENU_GRP: TFIBIntegerField
      FieldName = 'APPLICATION_INTERF_MAINMENU_GRP'
    end
    object ElementIDGRPUSER_INTERF_MAINMENU_GRP: TFIBLargeIntField
      FieldName = 'IDGRPUSER_INTERF_MAINMENU_GRP'
    end
    object ElementNAME_INTERF_MAINMENU_GRP: TFIBWideStringField
      FieldName = 'NAME_INTERF_MAINMENU_GRP'
      Size = 40
    end
    object ElementIDGRP_INTERF_MAINMENU_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_INTERF_MAINMENU_GRP'
    end
    object ElementINDEX_INTERF_MAINMENU_GRP: TFIBIntegerField
      FieldName = 'INDEX_INTERF_MAINMENU_GRP'
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
    Left = 248
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
    Left = 168
    Top = 144
    poUseGuidField = True
    poUseLargeIntField = True
    object MenuTableOUT_IDGRP_1: TFIBLargeIntField
      FieldName = 'OUT_IDGRP_1'
    end
    object MenuTableOUT_NAMEGRP_1: TFIBWideStringField
      FieldName = 'OUT_NAMEGRP_1'
      Size = 200
    end
    object MenuTableOUT_IDGRP_2: TFIBLargeIntField
      FieldName = 'OUT_IDGRP_2'
    end
    object MenuTableOUT_NAMEGRP_2: TFIBWideStringField
      FieldName = 'OUT_NAMEGRP_2'
      Size = 200
    end
    object MenuTableOUT_IDGRP_3: TFIBLargeIntField
      FieldName = 'OUT_IDGRP_3'
    end
    object MenuTableOUT_NAMEGRP_3: TFIBWideStringField
      FieldName = 'OUT_NAMEGRP_3'
      Size = 200
    end
    object MenuTableOUT_IDGRP: TFIBLargeIntField
      FieldName = 'OUT_IDGRP'
    end
    object MenuTableID_INTERF_MAINMENU: TFIBLargeIntField
      FieldName = 'ID_INTERF_MAINMENU'
    end
    object MenuTableIDBASE_INTERF_MAINMENU: TFIBLargeIntField
      FieldName = 'IDBASE_INTERF_MAINMENU'
    end
    object MenuTableIDGRP_INTERF_MAINMENU: TFIBLargeIntField
      FieldName = 'IDGRP_INTERF_MAINMENU'
    end
    object MenuTableNAME_INTERF_MAINMENU: TFIBWideStringField
      FieldName = 'NAME_INTERF_MAINMENU'
      Size = 40
    end
    object MenuTableMODUL_INTERF_MAINMENU: TFIBIntegerField
      FieldName = 'MODUL_INTERF_MAINMENU'
    end
    object MenuTableIDGRPUSER_INTERF_MAINMENU: TFIBLargeIntField
      FieldName = 'IDGRPUSER_INTERF_MAINMENU'
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
    object MenuTableGUIDMOD_INTERF_MAINMENU: TFIBWideStringField
      FieldName = 'GUIDMOD_INTERF_MAINMENU'
      Size = 38
    end
    object MenuTableFL_UPD_FORM_INTERF_MAINMENU: TFIBSmallIntField
      FieldName = 'FL_UPD_FORM_INTERF_MAINMENU'
    end
    object MenuTableFL_NEW_DOC_INTERF_MAINMENU: TFIBSmallIntField
      FieldName = 'FL_NEW_DOC_INTERF_MAINMENU'
    end
    object MenuTableIDEL_INTERF_MAINMENU: TFIBLargeIntField
      FieldName = 'IDEL_INTERF_MAINMENU'
    end
    object MenuTableFL_OPEN_EL_INTERF_MAINMENU: TFIBSmallIntField
      FieldName = 'FL_OPEN_EL_INTERF_MAINMENU'
    end
    object MenuTableTYPE_IDEL_INTERF_MAINMENU: TFIBIntegerField
      FieldName = 'TYPE_IDEL_INTERF_MAINMENU'
    end
  end
end
