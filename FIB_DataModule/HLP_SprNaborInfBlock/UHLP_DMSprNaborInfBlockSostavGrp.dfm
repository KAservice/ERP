object HLP_DMSprNaborInfBlockSostavGrp: THLP_DMSprNaborInfBlockSostavGrp
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 329
  Width = 603
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
      'select hlp_n_ib_s_grp.*'
      'from  hlp_n_ib_s_grp'
      
        'where hlp_n_ib_s_grp.idnabor_hlp_n_ib_s_grp=:PARAM_ID_GROUP_ELEM' +
        'ENT'
      'order by hlp_n_ib_s_grp.idgrp_hlp_n_ib_s_grp')
    Transaction = IBTr
    Left = 184
    Top = 24
    poUseLargeIntField = True
    object TableID_HLP_N_IB_S_GRP: TFIBLargeIntField
      FieldName = 'ID_HLP_N_IB_S_GRP'
    end
    object TableIDBASE_HLP_N_IB_S_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_HLP_N_IB_S_GRP'
    end
    object TableGUID_HLP_N_IB_S_GRP: TFIBWideStringField
      FieldName = 'GUID_HLP_N_IB_S_GRP'
      Size = 38
    end
    object TablePOS_ISM_HLP_N_IB_S_GRP: TFIBDateTimeField
      FieldName = 'POS_ISM_HLP_N_IB_S_GRP'
    end
    object TableIDGRP_HLP_N_IB_S_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_HLP_N_IB_S_GRP'
    end
    object TableNAME_HLP_N_IB_S_GRP: TFIBWideStringField
      FieldName = 'NAME_HLP_N_IB_S_GRP'
      Size = 200
    end
    object TableIDNABOR_HLP_N_IB_S_GRP: TFIBLargeIntField
      FieldName = 'IDNABOR_HLP_N_IB_S_GRP'
    end
    object TableINDEX_HLP_N_IB_S_GRP: TFIBIntegerField
      FieldName = 'INDEX_HLP_N_IB_S_GRP'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE HLP_N_IB_S_GRP'
      'SET '
      '    IDBASE_HLP_N_IB_S_GRP = :IDBASE_HLP_N_IB_S_GRP,'
      '    GUID_HLP_N_IB_S_GRP = :GUID_HLP_N_IB_S_GRP,'
      '    POS_ISM_HLP_N_IB_S_GRP = :POS_ISM_HLP_N_IB_S_GRP,'
      '    IDGRP_HLP_N_IB_S_GRP = :IDGRP_HLP_N_IB_S_GRP,'
      '    NAME_HLP_N_IB_S_GRP = :NAME_HLP_N_IB_S_GRP,'
      '    IDNABOR_HLP_N_IB_S_GRP = :IDNABOR_HLP_N_IB_S_GRP,'
      '    INDEX_HLP_N_IB_S_GRP = :INDEX_HLP_N_IB_S_GRP'
      'WHERE'
      '    ID_HLP_N_IB_S_GRP = :OLD_ID_HLP_N_IB_S_GRP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    HLP_N_IB_S_GRP'
      'WHERE'
      '        ID_HLP_N_IB_S_GRP = :OLD_ID_HLP_N_IB_S_GRP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO HLP_N_IB_S_GRP('
      '    ID_HLP_N_IB_S_GRP,'
      '    IDBASE_HLP_N_IB_S_GRP,'
      '    GUID_HLP_N_IB_S_GRP,'
      '    POS_ISM_HLP_N_IB_S_GRP,'
      '    IDGRP_HLP_N_IB_S_GRP,'
      '    NAME_HLP_N_IB_S_GRP,'
      '    IDNABOR_HLP_N_IB_S_GRP,'
      '    INDEX_HLP_N_IB_S_GRP'
      ')'
      'VALUES('
      '    :ID_HLP_N_IB_S_GRP,'
      '    :IDBASE_HLP_N_IB_S_GRP,'
      '    :GUID_HLP_N_IB_S_GRP,'
      '    :POS_ISM_HLP_N_IB_S_GRP,'
      '    :IDGRP_HLP_N_IB_S_GRP,'
      '    :NAME_HLP_N_IB_S_GRP,'
      '    :IDNABOR_HLP_N_IB_S_GRP,'
      '    :INDEX_HLP_N_IB_S_GRP'
      ')')
    RefreshSQL.Strings = (
      'select hlp_n_ib_s_grp.*'
      'from  hlp_n_ib_s_grp'
      'where(  hlp_n_ib_s_grp.id_hlp_n_ib_s_grp=:PARAM_ID'
      
        '     ) and (     HLP_N_IB_S_GRP.ID_HLP_N_IB_S_GRP = :OLD_ID_HLP_' +
        'N_IB_S_GRP'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select hlp_n_ib_s_grp.*'
      'from  hlp_n_ib_s_grp'
      'where hlp_n_ib_s_grp.id_hlp_n_ib_s_grp=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'HLP_N_IB_S_GRP'
    AutoUpdateOptions.KeyFields = 'ID_HLP_N_IB_S_GRP'
    AutoUpdateOptions.GeneratorName = 'GEN_HLP_N_IB_S_GRP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 184
    Top = 80
    poUseLargeIntField = True
    object ElementID_HLP_N_IB_S_GRP: TFIBLargeIntField
      FieldName = 'ID_HLP_N_IB_S_GRP'
    end
    object ElementIDBASE_HLP_N_IB_S_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_HLP_N_IB_S_GRP'
    end
    object ElementGUID_HLP_N_IB_S_GRP: TFIBWideStringField
      FieldName = 'GUID_HLP_N_IB_S_GRP'
      Size = 38
    end
    object ElementPOS_ISM_HLP_N_IB_S_GRP: TFIBDateTimeField
      FieldName = 'POS_ISM_HLP_N_IB_S_GRP'
    end
    object ElementIDGRP_HLP_N_IB_S_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_HLP_N_IB_S_GRP'
    end
    object ElementNAME_HLP_N_IB_S_GRP: TFIBWideStringField
      FieldName = 'NAME_HLP_N_IB_S_GRP'
      Size = 200
    end
    object ElementIDNABOR_HLP_N_IB_S_GRP: TFIBLargeIntField
      FieldName = 'IDNABOR_HLP_N_IB_S_GRP'
    end
    object ElementINDEX_HLP_N_IB_S_GRP: TFIBIntegerField
      FieldName = 'INDEX_HLP_N_IB_S_GRP'
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
end
