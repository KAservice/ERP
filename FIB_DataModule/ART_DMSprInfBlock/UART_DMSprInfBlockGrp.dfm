object ART_DMSprInfBlockGrp: TART_DMSprInfBlockGrp
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
      '  art_ib_grp'
      'order by art_ib_grp.idgrp_art_ib_grp')
    Transaction = IBTr
    Left = 144
    Top = 24
    poUseLargeIntField = True
    object TableID_ART_IB_GRP: TFIBLargeIntField
      FieldName = 'ID_ART_IB_GRP'
    end
    object TableIDBASE_ART_IB_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_ART_IB_GRP'
    end
    object TableGUID_ART_IB_GRP: TFIBWideStringField
      FieldName = 'GUID_ART_IB_GRP'
      Size = 38
    end
    object TableNAME_ART_IB_GRP: TFIBWideStringField
      FieldName = 'NAME_ART_IB_GRP'
      Size = 200
    end
    object TableIDGRP_ART_IB_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_ART_IB_GRP'
    end
    object TableGUID_GRP_ART_IB_GRP: TFIBWideStringField
      FieldName = 'GUID_GRP_ART_IB_GRP'
      Size = 38
    end
    object TablePOS_ISM_ART_IB_GRP: TFIBDateTimeField
      FieldName = 'POS_ISM_ART_IB_GRP'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE ART_IB_GRP'
      'SET '
      '    IDBASE_ART_IB_GRP = :IDBASE_ART_IB_GRP,'
      '    GUID_ART_IB_GRP = :GUID_ART_IB_GRP,'
      '    NAME_ART_IB_GRP = :NAME_ART_IB_GRP,'
      '    IDGRP_ART_IB_GRP = :IDGRP_ART_IB_GRP,'
      '    GUID_GRP_ART_IB_GRP = :GUID_GRP_ART_IB_GRP,'
      '    POS_ISM_ART_IB_GRP = :POS_ISM_ART_IB_GRP'
      'WHERE'
      '    ID_ART_IB_GRP = :OLD_ID_ART_IB_GRP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    ART_IB_GRP'
      'WHERE'
      '        ID_ART_IB_GRP = :OLD_ID_ART_IB_GRP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO ART_IB_GRP('
      '    ID_ART_IB_GRP,'
      '    IDBASE_ART_IB_GRP,'
      '    GUID_ART_IB_GRP,'
      '    NAME_ART_IB_GRP,'
      '    IDGRP_ART_IB_GRP,'
      '    GUID_GRP_ART_IB_GRP,'
      '    POS_ISM_ART_IB_GRP'
      ')'
      'VALUES('
      '    :ID_ART_IB_GRP,'
      '    :IDBASE_ART_IB_GRP,'
      '    :GUID_ART_IB_GRP,'
      '    :NAME_ART_IB_GRP,'
      '    :IDGRP_ART_IB_GRP,'
      '    :GUID_GRP_ART_IB_GRP,'
      '    :POS_ISM_ART_IB_GRP'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from '
      '  art_ib_grp'
      'where(  art_ib_grp.id_art_ib_grp=:PARAM_ID'
      '     ) and (     ART_IB_GRP.ID_ART_IB_GRP = :OLD_ID_ART_IB_GRP'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from '
      '  art_ib_grp'
      'where art_ib_grp.id_art_ib_grp=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'ART_IB_GRP'
    AutoUpdateOptions.KeyFields = 'ID_ART_IB_GRP'
    AutoUpdateOptions.GeneratorName = 'GEN_ART_IB_GRP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 80
    poUseLargeIntField = True
    object ElementID_ART_IB_GRP: TFIBLargeIntField
      FieldName = 'ID_ART_IB_GRP'
    end
    object ElementIDBASE_ART_IB_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_ART_IB_GRP'
    end
    object ElementGUID_ART_IB_GRP: TFIBWideStringField
      FieldName = 'GUID_ART_IB_GRP'
      Size = 38
    end
    object ElementNAME_ART_IB_GRP: TFIBWideStringField
      FieldName = 'NAME_ART_IB_GRP'
      Size = 200
    end
    object ElementIDGRP_ART_IB_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_ART_IB_GRP'
    end
    object ElementGUID_GRP_ART_IB_GRP: TFIBWideStringField
      FieldName = 'GUID_GRP_ART_IB_GRP'
      Size = 38
    end
    object ElementPOS_ISM_ART_IB_GRP: TFIBDateTimeField
      FieldName = 'POS_ISM_ART_IB_GRP'
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
