object DMSprCustomerMainMenuGrp: TDMSprCustomerMainMenuGrp
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 307
  Width = 499
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
      'from  cust_mainmenu_grp'
      'where'
      
        '       cust_mainmenu_grp.idaccount_cust_mainmenu_grp=:PARAM_IDAC' +
        'COUNT'
      
        '      and cust_mainmenu_grp.idgrpuser_cust_mainmenu_grp=:PARAM_I' +
        'DGRPUSER'
      'order by cust_mainmenu_grp.idgrp_cust_mainmenu_grp')
    Transaction = IBTr
    Left = 168
    Top = 24
    poUseGuidField = True
    poUseLargeIntField = True
    object TableID_CUST_MAINMENU_GRP: TFIBLargeIntField
      FieldName = 'ID_CUST_MAINMENU_GRP'
    end
    object TableIDBASE_CUST_MAINMENU_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_CUST_MAINMENU_GRP'
    end
    object TableGID_CUST_MAINMENU_GRP: TFIBWideStringField
      FieldName = 'GID_CUST_MAINMENU_GRP'
      Size = 10
    end
    object TableIDACCOUNT_CUST_MAINMENU_GRP: TFIBLargeIntField
      FieldName = 'IDACCOUNT_CUST_MAINMENU_GRP'
    end
    object TableIDGRP_CUST_MAINMENU_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_CUST_MAINMENU_GRP'
    end
    object TableIDGRPUSER_CUST_MAINMENU_GRP: TFIBLargeIntField
      FieldName = 'IDGRPUSER_CUST_MAINMENU_GRP'
    end
    object TableNAME_CUST_MAINMENU_GRP: TFIBWideStringField
      FieldName = 'NAME_CUST_MAINMENU_GRP'
      Size = 200
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE CUST_MAINMENU_GRP'
      'SET '
      '    IDBASE_CUST_MAINMENU_GRP = :IDBASE_CUST_MAINMENU_GRP,'
      '    GID_CUST_MAINMENU_GRP = :GID_CUST_MAINMENU_GRP,'
      '    IDACCOUNT_CUST_MAINMENU_GRP = :IDACCOUNT_CUST_MAINMENU_GRP,'
      '    IDGRP_CUST_MAINMENU_GRP = :IDGRP_CUST_MAINMENU_GRP,'
      '    IDGRPUSER_CUST_MAINMENU_GRP = :IDGRPUSER_CUST_MAINMENU_GRP,'
      '    NAME_CUST_MAINMENU_GRP = :NAME_CUST_MAINMENU_GRP'
      'WHERE'
      '    ID_CUST_MAINMENU_GRP = :OLD_ID_CUST_MAINMENU_GRP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    CUST_MAINMENU_GRP'
      'WHERE'
      '        ID_CUST_MAINMENU_GRP = :OLD_ID_CUST_MAINMENU_GRP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO CUST_MAINMENU_GRP('
      '    ID_CUST_MAINMENU_GRP,'
      '    IDBASE_CUST_MAINMENU_GRP,'
      '    GID_CUST_MAINMENU_GRP,'
      '    IDACCOUNT_CUST_MAINMENU_GRP,'
      '    IDGRP_CUST_MAINMENU_GRP,'
      '    IDGRPUSER_CUST_MAINMENU_GRP,'
      '    NAME_CUST_MAINMENU_GRP'
      ')'
      'VALUES('
      '    :ID_CUST_MAINMENU_GRP,'
      '    :IDBASE_CUST_MAINMENU_GRP,'
      '    :GID_CUST_MAINMENU_GRP,'
      '    :IDACCOUNT_CUST_MAINMENU_GRP,'
      '    :IDGRP_CUST_MAINMENU_GRP,'
      '    :IDGRPUSER_CUST_MAINMENU_GRP,'
      '    :NAME_CUST_MAINMENU_GRP'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from  cust_mainmenu_grp'
      'where(  cust_mainmenu_grp.id_cust_mainmenu_grp=:PARAM_ID'
      
        '     ) and (     CUST_MAINMENU_GRP.ID_CUST_MAINMENU_GRP = :OLD_I' +
        'D_CUST_MAINMENU_GRP'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from  cust_mainmenu_grp'
      'where cust_mainmenu_grp.id_cust_mainmenu_grp=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'CUST_MAINMENU_GRP'
    AutoUpdateOptions.KeyFields = 'ID_CUST_MAINMENU_GRP'
    AutoUpdateOptions.GeneratorName = 'GEN_CUST_MAINMENU_GRP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 80
    poUseLargeIntField = True
    object ElementID_CUST_MAINMENU_GRP: TFIBLargeIntField
      FieldName = 'ID_CUST_MAINMENU_GRP'
    end
    object ElementIDBASE_CUST_MAINMENU_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_CUST_MAINMENU_GRP'
    end
    object ElementGID_CUST_MAINMENU_GRP: TFIBWideStringField
      FieldName = 'GID_CUST_MAINMENU_GRP'
      Size = 10
    end
    object ElementIDACCOUNT_CUST_MAINMENU_GRP: TFIBLargeIntField
      FieldName = 'IDACCOUNT_CUST_MAINMENU_GRP'
    end
    object ElementIDGRP_CUST_MAINMENU_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_CUST_MAINMENU_GRP'
    end
    object ElementIDGRPUSER_CUST_MAINMENU_GRP: TFIBLargeIntField
      FieldName = 'IDGRPUSER_CUST_MAINMENU_GRP'
    end
    object ElementNAME_CUST_MAINMENU_GRP: TFIBWideStringField
      FieldName = 'NAME_CUST_MAINMENU_GRP'
      Size = 200
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
