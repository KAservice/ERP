object HLP_DMSprInfBlockGrp: THLP_DMSprInfBlockGrp
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 332
  Width = 372
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
      'from '
      '  hlp_ib_grp'
      'order by hlp_ib_grp.index_hlp_ib_grp')
    Transaction = IBTr
    Left = 144
    Top = 24
    poUseLargeIntField = True
    object TableID_HLP_IB_GRP: TFIBLargeIntField
      FieldName = 'ID_HLP_IB_GRP'
    end
    object TableIDBASE_HLP_IB_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_HLP_IB_GRP'
    end
    object TableGUID_HLP_IB_GRP: TFIBWideStringField
      FieldName = 'GUID_HLP_IB_GRP'
      Size = 38
    end
    object TableNAME_HLP_IB_GRP: TFIBWideStringField
      FieldName = 'NAME_HLP_IB_GRP'
      Size = 200
    end
    object TableIDGRP_HLP_IB_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_HLP_IB_GRP'
    end
    object TableGUID_GRP_HLP_IB_GRP: TFIBWideStringField
      FieldName = 'GUID_GRP_HLP_IB_GRP'
      Size = 38
    end
    object TablePOS_ISM_HLP_IB_GRP: TFIBDateTimeField
      FieldName = 'POS_ISM_HLP_IB_GRP'
    end
    object TableINDEX_HLP_IB_GRP: TFIBIntegerField
      FieldName = 'INDEX_HLP_IB_GRP'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE HLP_IB_GRP'
      'SET '
      '    IDBASE_HLP_IB_GRP = :IDBASE_HLP_IB_GRP,'
      '    GUID_HLP_IB_GRP = :GUID_HLP_IB_GRP,'
      '    NAME_HLP_IB_GRP = :NAME_HLP_IB_GRP,'
      '    IDGRP_HLP_IB_GRP = :IDGRP_HLP_IB_GRP,'
      '    GUID_GRP_HLP_IB_GRP = :GUID_GRP_HLP_IB_GRP,'
      '    POS_ISM_HLP_IB_GRP = :POS_ISM_HLP_IB_GRP,'
      '    INDEX_HLP_IB_GRP = :INDEX_HLP_IB_GRP'
      'WHERE'
      '    ID_HLP_IB_GRP = :OLD_ID_HLP_IB_GRP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    HLP_IB_GRP'
      'WHERE'
      '        ID_HLP_IB_GRP = :OLD_ID_HLP_IB_GRP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO HLP_IB_GRP('
      '    ID_HLP_IB_GRP,'
      '    IDBASE_HLP_IB_GRP,'
      '    GUID_HLP_IB_GRP,'
      '    NAME_HLP_IB_GRP,'
      '    IDGRP_HLP_IB_GRP,'
      '    GUID_GRP_HLP_IB_GRP,'
      '    POS_ISM_HLP_IB_GRP,'
      '    INDEX_HLP_IB_GRP'
      ')'
      'VALUES('
      '    :ID_HLP_IB_GRP,'
      '    :IDBASE_HLP_IB_GRP,'
      '    :GUID_HLP_IB_GRP,'
      '    :NAME_HLP_IB_GRP,'
      '    :IDGRP_HLP_IB_GRP,'
      '    :GUID_GRP_HLP_IB_GRP,'
      '    :POS_ISM_HLP_IB_GRP,'
      '    :INDEX_HLP_IB_GRP'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from '
      '  hlp_ib_grp'
      'where(  hlp_ib_grp.id_hlp_ib_grp=:PARAM_ID'
      '     ) and (     HLP_IB_GRP.ID_HLP_IB_GRP = :OLD_ID_HLP_IB_GRP'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from '
      '  hlp_ib_grp'
      'where hlp_ib_grp.id_hlp_ib_grp=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'HLP_IB_GRP'
    AutoUpdateOptions.KeyFields = 'ID_HLP_IB_GRP'
    AutoUpdateOptions.GeneratorName = 'GEN_HLP_IB_GRP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 80
    poUseLargeIntField = True
    object ElementID_HLP_IB_GRP: TFIBLargeIntField
      FieldName = 'ID_HLP_IB_GRP'
    end
    object ElementIDBASE_HLP_IB_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_HLP_IB_GRP'
    end
    object ElementGUID_HLP_IB_GRP: TFIBWideStringField
      FieldName = 'GUID_HLP_IB_GRP'
      Size = 38
    end
    object ElementNAME_HLP_IB_GRP: TFIBWideStringField
      FieldName = 'NAME_HLP_IB_GRP'
      Size = 200
    end
    object ElementIDGRP_HLP_IB_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_HLP_IB_GRP'
    end
    object ElementGUID_GRP_HLP_IB_GRP: TFIBWideStringField
      FieldName = 'GUID_GRP_HLP_IB_GRP'
      Size = 38
    end
    object ElementPOS_ISM_HLP_IB_GRP: TFIBDateTimeField
      FieldName = 'POS_ISM_HLP_IB_GRP'
    end
    object ElementINDEX_HLP_IB_GRP: TFIBIntegerField
      FieldName = 'INDEX_HLP_IB_GRP'
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
    Left = 216
    Top = 24
  end
  object IBTrUpdate: TpFIBTransaction
    TimeoutAction = TARollback
    Left = 216
    Top = 80
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 272
    Top = 56
    qoStartTransaction = True
  end
end
