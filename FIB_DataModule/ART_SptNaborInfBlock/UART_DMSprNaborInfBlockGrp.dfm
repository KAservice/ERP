object ART_DMSprNaborInfBlockGrp: TART_DMSprNaborInfBlockGrp
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
      'select art_n_ib_grp.*'
      'from  art_n_ib_grp'
      'order by art_n_ib_grp.idgrp_art_n_ib_grp')
    Transaction = IBTr
    Left = 184
    Top = 24
    poUseLargeIntField = True
    object TableID_ART_N_IB_GRP: TFIBLargeIntField
      FieldName = 'ID_ART_N_IB_GRP'
    end
    object TableIDBASE_ART_N_IB_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_ART_N_IB_GRP'
    end
    object TableGUID_ART_N_IB_GRP: TFIBWideStringField
      FieldName = 'GUID_ART_N_IB_GRP'
      Size = 38
    end
    object TablePOS_ISM_ART_N_IB_GRP: TFIBDateTimeField
      FieldName = 'POS_ISM_ART_N_IB_GRP'
    end
    object TableIDGRP_ART_N_IB_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_ART_N_IB_GRP'
    end
    object TableNAME_ART_N_IB_GRP: TFIBWideStringField
      FieldName = 'NAME_ART_N_IB_GRP'
      Size = 200
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE ART_N_IB_GRP'
      'SET '
      '    IDBASE_ART_N_IB_GRP = :IDBASE_ART_N_IB_GRP,'
      '    GUID_ART_N_IB_GRP = :GUID_ART_N_IB_GRP,'
      '    POS_ISM_ART_N_IB_GRP = :POS_ISM_ART_N_IB_GRP,'
      '    IDGRP_ART_N_IB_GRP = :IDGRP_ART_N_IB_GRP,'
      '    NAME_ART_N_IB_GRP = :NAME_ART_N_IB_GRP'
      'WHERE'
      '    ID_ART_N_IB_GRP = :OLD_ID_ART_N_IB_GRP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    ART_N_IB_GRP'
      'WHERE'
      '        ID_ART_N_IB_GRP = :OLD_ID_ART_N_IB_GRP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO ART_N_IB_GRP('
      '    ID_ART_N_IB_GRP,'
      '    IDBASE_ART_N_IB_GRP,'
      '    GUID_ART_N_IB_GRP,'
      '    POS_ISM_ART_N_IB_GRP,'
      '    IDGRP_ART_N_IB_GRP,'
      '    NAME_ART_N_IB_GRP'
      ')'
      'VALUES('
      '    :ID_ART_N_IB_GRP,'
      '    :IDBASE_ART_N_IB_GRP,'
      '    :GUID_ART_N_IB_GRP,'
      '    :POS_ISM_ART_N_IB_GRP,'
      '    :IDGRP_ART_N_IB_GRP,'
      '    :NAME_ART_N_IB_GRP'
      ')')
    RefreshSQL.Strings = (
      'select art_n_ib_grp.*'
      'from  art_n_ib_grp'
      ''
      ' WHERE '
      '        ART_N_IB_GRP.ID_ART_N_IB_GRP = :OLD_ID_ART_N_IB_GRP'
      '    ')
    SelectSQL.Strings = (
      'select art_n_ib_grp.*'
      'from  art_n_ib_grp'
      'order by art_n_ib_grp.idgrp_art_n_ib_grp')
    AutoUpdateOptions.UpdateTableName = 'ART_N_IB_GRP'
    AutoUpdateOptions.KeyFields = 'ID_ART_N_IB_GRP'
    AutoUpdateOptions.GeneratorName = 'GEN_ART_N_IB_GRP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 184
    Top = 80
    poUseLargeIntField = True
    object ElementID_ART_N_IB_GRP: TFIBLargeIntField
      FieldName = 'ID_ART_N_IB_GRP'
    end
    object ElementIDBASE_ART_N_IB_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_ART_N_IB_GRP'
    end
    object ElementGUID_ART_N_IB_GRP: TFIBWideStringField
      FieldName = 'GUID_ART_N_IB_GRP'
      Size = 38
    end
    object ElementPOS_ISM_ART_N_IB_GRP: TFIBDateTimeField
      FieldName = 'POS_ISM_ART_N_IB_GRP'
    end
    object ElementIDGRP_ART_N_IB_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_ART_N_IB_GRP'
    end
    object ElementNAME_ART_N_IB_GRP: TFIBWideStringField
      FieldName = 'NAME_ART_N_IB_GRP'
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
end
