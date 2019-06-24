object HLP_DMSprNaborInfBlock: THLP_DMSprNaborInfBlock
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
      'select hlp_n_ib.*'
      'from hlp_n_ib'
      'where hlp_n_ib.idgrp_hlp_n_ib=:PARAM_IDGRP'
      'ORDER BY hlp_n_ib.idgrp_hlp_n_ib')
    Transaction = IBTr
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object TableID_HLP_N_IB: TFIBLargeIntField
      FieldName = 'ID_HLP_N_IB'
    end
    object TableIDBASE_HLP_N_IB: TFIBLargeIntField
      FieldName = 'IDBASE_HLP_N_IB'
    end
    object TableGUID_HLP_N_IB: TFIBWideStringField
      FieldName = 'GUID_HLP_N_IB'
      Size = 38
    end
    object TablePOS_ISM_HLP_N_IB: TFIBDateTimeField
      FieldName = 'POS_ISM_HLP_N_IB'
    end
    object TableIDGRP_HLP_N_IB: TFIBLargeIntField
      FieldName = 'IDGRP_HLP_N_IB'
    end
    object TableNAME_HLP_N_IB: TFIBWideStringField
      FieldName = 'NAME_HLP_N_IB'
      Size = 200
    end
    object TableINDEX_HLP_N_IB: TFIBIntegerField
      FieldName = 'INDEX_HLP_N_IB'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE HLP_N_IB'
      'SET '
      '    IDBASE_HLP_N_IB = :IDBASE_HLP_N_IB,'
      '    GUID_HLP_N_IB = :GUID_HLP_N_IB,'
      '    POS_ISM_HLP_N_IB = :POS_ISM_HLP_N_IB,'
      '    IDGRP_HLP_N_IB = :IDGRP_HLP_N_IB,'
      '    NAME_HLP_N_IB = :NAME_HLP_N_IB,'
      '    INDEX_HLP_N_IB = :INDEX_HLP_N_IB'
      'WHERE'
      '    ID_HLP_N_IB = :OLD_ID_HLP_N_IB'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    HLP_N_IB'
      'WHERE'
      '        ID_HLP_N_IB = :OLD_ID_HLP_N_IB'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO HLP_N_IB('
      '    ID_HLP_N_IB,'
      '    IDBASE_HLP_N_IB,'
      '    GUID_HLP_N_IB,'
      '    POS_ISM_HLP_N_IB,'
      '    IDGRP_HLP_N_IB,'
      '    NAME_HLP_N_IB,'
      '    INDEX_HLP_N_IB'
      ')'
      'VALUES('
      '    :ID_HLP_N_IB,'
      '    :IDBASE_HLP_N_IB,'
      '    :GUID_HLP_N_IB,'
      '    :POS_ISM_HLP_N_IB,'
      '    :IDGRP_HLP_N_IB,'
      '    :NAME_HLP_N_IB,'
      '    :INDEX_HLP_N_IB'
      ')')
    RefreshSQL.Strings = (
      'select hlp_n_ib.*'
      'from hlp_n_ib'
      'where(  hlp_n_ib.id_hlp_n_ib=:PARAM_ID'
      '     ) and (     HLP_N_IB.ID_HLP_N_IB = :OLD_ID_HLP_N_IB'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select hlp_n_ib.*'
      'from hlp_n_ib'
      'where hlp_n_ib.id_hlp_n_ib=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'HLP_N_IB'
    AutoUpdateOptions.KeyFields = 'ID_HLP_N_IB'
    AutoUpdateOptions.GeneratorName = 'GEN_HLP_N_IB_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object ElementID_HLP_N_IB: TFIBLargeIntField
      FieldName = 'ID_HLP_N_IB'
    end
    object ElementIDBASE_HLP_N_IB: TFIBLargeIntField
      FieldName = 'IDBASE_HLP_N_IB'
    end
    object ElementGUID_HLP_N_IB: TFIBWideStringField
      FieldName = 'GUID_HLP_N_IB'
      Size = 38
    end
    object ElementPOS_ISM_HLP_N_IB: TFIBDateTimeField
      FieldName = 'POS_ISM_HLP_N_IB'
    end
    object ElementIDGRP_HLP_N_IB: TFIBLargeIntField
      FieldName = 'IDGRP_HLP_N_IB'
    end
    object ElementNAME_HLP_N_IB: TFIBWideStringField
      FieldName = 'NAME_HLP_N_IB'
      Size = 200
    end
    object ElementINDEX_HLP_N_IB: TFIBIntegerField
      FieldName = 'INDEX_HLP_N_IB'
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
