object ART_DMSprNaborInfBlockSostavGrp: TART_DMSprNaborInfBlockSostavGrp
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
      'select art_n_ib_s_grp.*'
      'from  art_n_ib_s_grp'
      
        'where art_n_ib_s_grp.idnabor_art_n_ib_s_grp=:PARAM_ID_GROUP_ELEM' +
        'ENT'
      'order by art_n_ib_s_grp.idgrp_art_n_ib_s_grp')
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 184
    Top = 24
    poUseLargeIntField = True
    object TableID_ART_N_IB_S_GRP: TFIBLargeIntField
      FieldName = 'ID_ART_N_IB_S_GRP'
    end
    object TableIDBASE_ART_N_IB_S_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_ART_N_IB_S_GRP'
    end
    object TableGUID_ART_N_IB_S_GRP: TFIBWideStringField
      FieldName = 'GUID_ART_N_IB_S_GRP'
      Size = 38
    end
    object TablePOS_ISM_ART_N_IB_S_GRP: TFIBDateTimeField
      FieldName = 'POS_ISM_ART_N_IB_S_GRP'
    end
    object TableIDGRP_ART_N_IB_S_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_ART_N_IB_S_GRP'
    end
    object TableNAME_ART_N_IB_S_GRP: TFIBWideStringField
      FieldName = 'NAME_ART_N_IB_S_GRP'
      Size = 200
    end
    object TableIDNABOR_ART_N_IB_S_GRP: TFIBLargeIntField
      FieldName = 'IDNABOR_ART_N_IB_S_GRP'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE ART_N_IB_S_GRP'
      'SET '
      '    IDBASE_ART_N_IB_S_GRP = :IDBASE_ART_N_IB_S_GRP,'
      '    GUID_ART_N_IB_S_GRP = :GUID_ART_N_IB_S_GRP,'
      '    POS_ISM_ART_N_IB_S_GRP = :POS_ISM_ART_N_IB_S_GRP,'
      '    IDGRP_ART_N_IB_S_GRP = :IDGRP_ART_N_IB_S_GRP,'
      '    NAME_ART_N_IB_S_GRP = :NAME_ART_N_IB_S_GRP,'
      '    IDNABOR_ART_N_IB_S_GRP = :IDNABOR_ART_N_IB_S_GRP'
      'WHERE'
      '    ID_ART_N_IB_S_GRP = :OLD_ID_ART_N_IB_S_GRP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    ART_N_IB_S_GRP'
      'WHERE'
      '        ID_ART_N_IB_S_GRP = :OLD_ID_ART_N_IB_S_GRP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO ART_N_IB_S_GRP('
      '    ID_ART_N_IB_S_GRP,'
      '    IDBASE_ART_N_IB_S_GRP,'
      '    GUID_ART_N_IB_S_GRP,'
      '    POS_ISM_ART_N_IB_S_GRP,'
      '    IDGRP_ART_N_IB_S_GRP,'
      '    NAME_ART_N_IB_S_GRP,'
      '    IDNABOR_ART_N_IB_S_GRP'
      ')'
      'VALUES('
      '    :ID_ART_N_IB_S_GRP,'
      '    :IDBASE_ART_N_IB_S_GRP,'
      '    :GUID_ART_N_IB_S_GRP,'
      '    :POS_ISM_ART_N_IB_S_GRP,'
      '    :IDGRP_ART_N_IB_S_GRP,'
      '    :NAME_ART_N_IB_S_GRP,'
      '    :IDNABOR_ART_N_IB_S_GRP'
      ')')
    RefreshSQL.Strings = (
      'select art_n_ib_s_grp.*'
      'from  art_n_ib_s_grp'
      'where(  art_n_ib_s_grp.id_art_n_ib_s_grp=:PARAM_ID'
      
        '     ) and (     ART_N_IB_S_GRP.ID_ART_N_IB_S_GRP = :OLD_ID_ART_' +
        'N_IB_S_GRP'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select art_n_ib_s_grp.*'
      'from  art_n_ib_s_grp'
      'where art_n_ib_s_grp.id_art_n_ib_s_grp=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'ART_N_IB_S_GRP'
    AutoUpdateOptions.KeyFields = 'ID_ART_N_IB_S_GRP'
    AutoUpdateOptions.GeneratorName = 'GEN_ART_N_IB_S_GRP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 184
    Top = 80
    poUseLargeIntField = True
    object ElementID_ART_N_IB_S_GRP: TFIBLargeIntField
      FieldName = 'ID_ART_N_IB_S_GRP'
    end
    object ElementIDBASE_ART_N_IB_S_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_ART_N_IB_S_GRP'
    end
    object ElementGUID_ART_N_IB_S_GRP: TFIBWideStringField
      FieldName = 'GUID_ART_N_IB_S_GRP'
      Size = 38
    end
    object ElementPOS_ISM_ART_N_IB_S_GRP: TFIBDateTimeField
      FieldName = 'POS_ISM_ART_N_IB_S_GRP'
    end
    object ElementIDGRP_ART_N_IB_S_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_ART_N_IB_S_GRP'
    end
    object ElementNAME_ART_N_IB_S_GRP: TFIBWideStringField
      FieldName = 'NAME_ART_N_IB_S_GRP'
      Size = 200
    end
    object ElementIDNABOR_ART_N_IB_S_GRP: TFIBLargeIntField
      FieldName = 'IDNABOR_ART_N_IB_S_GRP'
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
