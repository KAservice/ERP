object ART_DMSprNaborInfBlock: TART_DMSprNaborInfBlock
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 403
  Width = 371
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 8
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 56
    Top = 64
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select art_n_ib.*'
      'from art_n_ib'
      'where art_n_ib.idgrp_art_n_ib=:PARAM_IDGRP'
      'ORDER BY art_n_ib.idgrp_art_n_ib')
    Transaction = IBTr
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object TableID_ART_N_IB: TFIBLargeIntField
      FieldName = 'ID_ART_N_IB'
    end
    object TableIDBASE_ART_N_IB: TFIBLargeIntField
      FieldName = 'IDBASE_ART_N_IB'
    end
    object TableGUID_ART_N_IB: TFIBWideStringField
      FieldName = 'GUID_ART_N_IB'
      Size = 38
    end
    object TablePOS_ISM_ART_N_IB: TFIBDateTimeField
      FieldName = 'POS_ISM_ART_N_IB'
    end
    object TableIDGRP_ART_N_IB: TFIBLargeIntField
      FieldName = 'IDGRP_ART_N_IB'
    end
    object TableNAME_ART_N_IB: TFIBWideStringField
      FieldName = 'NAME_ART_N_IB'
      Size = 200
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE ART_N_IB'
      'SET '
      '    IDBASE_ART_N_IB = :IDBASE_ART_N_IB,'
      '    GUID_ART_N_IB = :GUID_ART_N_IB,'
      '    POS_ISM_ART_N_IB = :POS_ISM_ART_N_IB,'
      '    IDGRP_ART_N_IB = :IDGRP_ART_N_IB,'
      '    NAME_ART_N_IB = :NAME_ART_N_IB'
      'WHERE'
      '    ID_ART_N_IB = :OLD_ID_ART_N_IB'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    ART_N_IB'
      'WHERE'
      '        ID_ART_N_IB = :OLD_ID_ART_N_IB'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO ART_N_IB('
      '    ID_ART_N_IB,'
      '    IDBASE_ART_N_IB,'
      '    GUID_ART_N_IB,'
      '    POS_ISM_ART_N_IB,'
      '    IDGRP_ART_N_IB,'
      '    NAME_ART_N_IB'
      ')'
      'VALUES('
      '    :ID_ART_N_IB,'
      '    :IDBASE_ART_N_IB,'
      '    :GUID_ART_N_IB,'
      '    :POS_ISM_ART_N_IB,'
      '    :IDGRP_ART_N_IB,'
      '    :NAME_ART_N_IB'
      ')')
    RefreshSQL.Strings = (
      'select art_n_ib.*'
      'from art_n_ib'
      'where(  art_n_ib.id_art_n_ib=:PARAM_ID'
      '     ) and (     ART_N_IB.ID_ART_N_IB = :OLD_ID_ART_N_IB'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select art_n_ib.*'
      'from art_n_ib'
      'where art_n_ib.id_art_n_ib=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'ART_N_IB'
    AutoUpdateOptions.KeyFields = 'ID_ART_N_IB'
    AutoUpdateOptions.GeneratorName = 'GEN_ART_N_IB_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object ElementID_ART_N_IB: TFIBLargeIntField
      FieldName = 'ID_ART_N_IB'
    end
    object ElementIDBASE_ART_N_IB: TFIBLargeIntField
      FieldName = 'IDBASE_ART_N_IB'
    end
    object ElementGUID_ART_N_IB: TFIBWideStringField
      FieldName = 'GUID_ART_N_IB'
      Size = 38
    end
    object ElementPOS_ISM_ART_N_IB: TFIBDateTimeField
      FieldName = 'POS_ISM_ART_N_IB'
    end
    object ElementIDGRP_ART_N_IB: TFIBLargeIntField
      FieldName = 'IDGRP_ART_N_IB'
    end
    object ElementNAME_ART_N_IB: TFIBWideStringField
      FieldName = 'NAME_ART_N_IB'
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
    Left = 256
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
    Left = 256
    Top = 64
  end
  object Query: TpFIBQuery
    Transaction = IBTr
    Left = 152
    Top = 144
    qoStartTransaction = True
  end
end
