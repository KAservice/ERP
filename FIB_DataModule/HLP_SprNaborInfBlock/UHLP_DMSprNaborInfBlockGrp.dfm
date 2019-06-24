object HLP_DMSprNaborInfBlockGrp: THLP_DMSprNaborInfBlockGrp
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 325
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
      'select hlp_n_ib_grp.*'
      'from  hlp_n_ib_grp'
      'order by hlp_n_ib_grp.idgrp_hlp_n_ib_grp')
    Transaction = IBTr
    Left = 184
    Top = 24
    poUseLargeIntField = True
    object TableID_HLP_N_IB_GRP: TFIBLargeIntField
      FieldName = 'ID_HLP_N_IB_GRP'
    end
    object TableIDBASE_HLP_N_IB_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_HLP_N_IB_GRP'
    end
    object TableGUID_HLP_N_IB_GRP: TFIBWideStringField
      FieldName = 'GUID_HLP_N_IB_GRP'
      Size = 38
    end
    object TablePOS_ISM_HLP_N_IB_GRP: TFIBDateTimeField
      FieldName = 'POS_ISM_HLP_N_IB_GRP'
    end
    object TableIDGRP_HLP_N_IB_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_HLP_N_IB_GRP'
    end
    object TableNAME_HLP_N_IB_GRP: TFIBWideStringField
      FieldName = 'NAME_HLP_N_IB_GRP'
      Size = 200
    end
    object TableINDEX_HLP_N_IB_GRP: TFIBIntegerField
      FieldName = 'INDEX_HLP_N_IB_GRP'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE HLP_N_IB_GRP'
      'SET '
      '    IDBASE_HLP_N_IB_GRP = :IDBASE_HLP_N_IB_GRP,'
      '    GUID_HLP_N_IB_GRP = :GUID_HLP_N_IB_GRP,'
      '    POS_ISM_HLP_N_IB_GRP = :POS_ISM_HLP_N_IB_GRP,'
      '    IDGRP_HLP_N_IB_GRP = :IDGRP_HLP_N_IB_GRP,'
      '    NAME_HLP_N_IB_GRP = :NAME_HLP_N_IB_GRP,'
      '    INDEX_HLP_N_IB_GRP = :INDEX_HLP_N_IB_GRP'
      'WHERE'
      '    ID_HLP_N_IB_GRP = :OLD_ID_HLP_N_IB_GRP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    HLP_N_IB_GRP'
      'WHERE'
      '        ID_HLP_N_IB_GRP = :OLD_ID_HLP_N_IB_GRP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO HLP_N_IB_GRP('
      '    ID_HLP_N_IB_GRP,'
      '    IDBASE_HLP_N_IB_GRP,'
      '    GUID_HLP_N_IB_GRP,'
      '    POS_ISM_HLP_N_IB_GRP,'
      '    IDGRP_HLP_N_IB_GRP,'
      '    NAME_HLP_N_IB_GRP,'
      '    INDEX_HLP_N_IB_GRP'
      ')'
      'VALUES('
      '    :ID_HLP_N_IB_GRP,'
      '    :IDBASE_HLP_N_IB_GRP,'
      '    :GUID_HLP_N_IB_GRP,'
      '    :POS_ISM_HLP_N_IB_GRP,'
      '    :IDGRP_HLP_N_IB_GRP,'
      '    :NAME_HLP_N_IB_GRP,'
      '    :INDEX_HLP_N_IB_GRP'
      ')')
    RefreshSQL.Strings = (
      'select hlp_n_ib_grp.*'
      'from  hlp_n_ib_grp'
      ''
      ' WHERE '
      '        HLP_N_IB_GRP.ID_HLP_N_IB_GRP = :OLD_ID_HLP_N_IB_GRP'
      '    ')
    SelectSQL.Strings = (
      'select hlp_n_ib_grp.*'
      'from  hlp_n_ib_grp'
      'order by hlp_n_ib_grp.idgrp_hlp_n_ib_grp')
    AutoUpdateOptions.UpdateTableName = 'HLP_N_IB_GRP'
    AutoUpdateOptions.KeyFields = 'ID_HLP_N_IB_GRP'
    AutoUpdateOptions.GeneratorName = 'GEN_HLP_N_IB_GRP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 184
    Top = 80
    poUseLargeIntField = True
    object ElementID_HLP_N_IB_GRP: TFIBLargeIntField
      FieldName = 'ID_HLP_N_IB_GRP'
    end
    object ElementIDBASE_HLP_N_IB_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_HLP_N_IB_GRP'
    end
    object ElementGUID_HLP_N_IB_GRP: TFIBWideStringField
      FieldName = 'GUID_HLP_N_IB_GRP'
      Size = 38
    end
    object ElementPOS_ISM_HLP_N_IB_GRP: TFIBDateTimeField
      FieldName = 'POS_ISM_HLP_N_IB_GRP'
    end
    object ElementIDGRP_HLP_N_IB_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_HLP_N_IB_GRP'
    end
    object ElementNAME_HLP_N_IB_GRP: TFIBWideStringField
      FieldName = 'NAME_HLP_N_IB_GRP'
      Size = 200
    end
    object ElementINDEX_HLP_N_IB_GRP: TFIBIntegerField
      FieldName = 'INDEX_HLP_N_IB_GRP'
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
