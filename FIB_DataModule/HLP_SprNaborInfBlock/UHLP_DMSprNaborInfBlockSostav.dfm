object HLP_DMSprNaborInfBlockSostav: THLP_DMSprNaborInfBlockSostav
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 304
  Width = 551
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object DataSourcePodr: TDataSource
    AutoEdit = False
    Left = 48
    Top = 72
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE HLP_N_IB_S'
      'SET '
      '    IDBASE_HLP_N_IB_S = :IDBASE_HLP_N_IB_S,'
      '    GUID_HLP_N_IB_S = :GUID_HLP_N_IB_S,'
      '    POS_ISM_HLP_N_IB_S = :POS_ISM_HLP_N_IB_S,'
      '    IDGRP_HLP_N_IB_S = :IDGRP_HLP_N_IB_S,'
      '    IDNABOR_HLP_N_IB_S = :IDNABOR_HLP_N_IB_S,'
      '    IDIB_HLP_N_IB_S = :IDIB_HLP_N_IB_S,'
      '    INDEX_HLP_N_IB_S = :INDEX_HLP_N_IB_S'
      'WHERE'
      '    ID_HLP_N_IB_S = :OLD_ID_HLP_N_IB_S'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    HLP_N_IB_S'
      'WHERE'
      '        ID_HLP_N_IB_S = :OLD_ID_HLP_N_IB_S'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO HLP_N_IB_S('
      '    ID_HLP_N_IB_S,'
      '    IDBASE_HLP_N_IB_S,'
      '    GUID_HLP_N_IB_S,'
      '    POS_ISM_HLP_N_IB_S,'
      '    IDGRP_HLP_N_IB_S,'
      '    IDNABOR_HLP_N_IB_S,'
      '    IDIB_HLP_N_IB_S,'
      '    INDEX_HLP_N_IB_S'
      ')'
      'VALUES('
      '    :ID_HLP_N_IB_S,'
      '    :IDBASE_HLP_N_IB_S,'
      '    :GUID_HLP_N_IB_S,'
      '    :POS_ISM_HLP_N_IB_S,'
      '    :IDGRP_HLP_N_IB_S,'
      '    :IDNABOR_HLP_N_IB_S,'
      '    :IDIB_HLP_N_IB_S,'
      '    :INDEX_HLP_N_IB_S'
      ')')
    RefreshSQL.Strings = (
      'select hlp_n_ib_s.*,'
      '       hlp_ib.name_hlp_ib'
      'from hlp_n_ib_s'
      
        'left outer join hlp_ib on hlp_ib.id_hlp_ib=hlp_n_ib_s.idib_hlp_n' +
        '_ib_s'
      'where( '
      '        hlp_n_ib_s.idnabor_hlp_n_ib_s=:PARAM_ID_GROUP_ELEMENT'
      ' AND hlp_n_ib_s.idgrp_hlp_n_ib_s=:PARAM_IDGRP'
      '     ) and (     HLP_N_IB_S.ID_HLP_N_IB_S = :OLD_ID_HLP_N_IB_S'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select hlp_n_ib_s.*,'
      '       hlp_ib.name_hlp_ib'
      'from hlp_n_ib_s'
      
        'left outer join hlp_ib on hlp_ib.id_hlp_ib=hlp_n_ib_s.idib_hlp_n' +
        '_ib_s'
      'where'
      '        hlp_n_ib_s.idnabor_hlp_n_ib_s=:PARAM_ID_GROUP_ELEMENT'
      ' AND hlp_n_ib_s.idgrp_hlp_n_ib_s=:PARAM_IDGRP'
      'order by hlp_ib.name_hlp_ib')
    AutoUpdateOptions.UpdateTableName = 'HLP_N_IB_S'
    AutoUpdateOptions.KeyFields = 'ID_HLP_N_IB_S'
    AutoUpdateOptions.GeneratorName = 'GEN_HLP_N_IB_S_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object TableID_HLP_N_IB_S: TFIBLargeIntField
      FieldName = 'ID_HLP_N_IB_S'
    end
    object TableIDBASE_HLP_N_IB_S: TFIBLargeIntField
      FieldName = 'IDBASE_HLP_N_IB_S'
    end
    object TableGUID_HLP_N_IB_S: TFIBWideStringField
      FieldName = 'GUID_HLP_N_IB_S'
      Size = 38
    end
    object TablePOS_ISM_HLP_N_IB_S: TFIBDateTimeField
      FieldName = 'POS_ISM_HLP_N_IB_S'
    end
    object TableIDGRP_HLP_N_IB_S: TFIBLargeIntField
      FieldName = 'IDGRP_HLP_N_IB_S'
    end
    object TableIDNABOR_HLP_N_IB_S: TFIBLargeIntField
      FieldName = 'IDNABOR_HLP_N_IB_S'
    end
    object TableIDIB_HLP_N_IB_S: TFIBLargeIntField
      FieldName = 'IDIB_HLP_N_IB_S'
    end
    object TableINDEX_HLP_N_IB_S: TFIBIntegerField
      FieldName = 'INDEX_HLP_N_IB_S'
    end
    object TableNAME_HLP_IB: TFIBWideStringField
      FieldName = 'NAME_HLP_IB'
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
    Left = 272
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
    Left = 272
    Top = 72
  end
  object Element: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE HLP_N_IB_S'
      'SET '
      '    IDBASE_HLP_N_IB_S = :IDBASE_HLP_N_IB_S,'
      '    GUID_HLP_N_IB_S = :GUID_HLP_N_IB_S,'
      '    POS_ISM_HLP_N_IB_S = :POS_ISM_HLP_N_IB_S,'
      '    IDGRP_HLP_N_IB_S = :IDGRP_HLP_N_IB_S,'
      '    IDNABOR_HLP_N_IB_S = :IDNABOR_HLP_N_IB_S,'
      '    IDIB_HLP_N_IB_S = :IDIB_HLP_N_IB_S,'
      '    INDEX_HLP_N_IB_S = :INDEX_HLP_N_IB_S'
      'WHERE'
      '    ID_HLP_N_IB_S = :OLD_ID_HLP_N_IB_S'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    HLP_N_IB_S'
      'WHERE'
      '        ID_HLP_N_IB_S = :OLD_ID_HLP_N_IB_S'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO HLP_N_IB_S('
      '    ID_HLP_N_IB_S,'
      '    IDBASE_HLP_N_IB_S,'
      '    GUID_HLP_N_IB_S,'
      '    POS_ISM_HLP_N_IB_S,'
      '    IDGRP_HLP_N_IB_S,'
      '    IDNABOR_HLP_N_IB_S,'
      '    IDIB_HLP_N_IB_S,'
      '    INDEX_HLP_N_IB_S'
      ')'
      'VALUES('
      '    :ID_HLP_N_IB_S,'
      '    :IDBASE_HLP_N_IB_S,'
      '    :GUID_HLP_N_IB_S,'
      '    :POS_ISM_HLP_N_IB_S,'
      '    :IDGRP_HLP_N_IB_S,'
      '    :IDNABOR_HLP_N_IB_S,'
      '    :IDIB_HLP_N_IB_S,'
      '    :INDEX_HLP_N_IB_S'
      ')')
    RefreshSQL.Strings = (
      'select hlp_n_ib_s.*,'
      '       hlp_ib.name_hlp_ib'
      'from hlp_n_ib_s'
      
        'left outer join hlp_ib on hlp_ib.id_hlp_ib=hlp_n_ib_s.idib_hlp_n' +
        '_ib_s'
      'where(  hlp_n_ib_s.id_hlp_n_ib_s=:PARAM_ID'
      '     ) and (     HLP_N_IB_S.ID_HLP_N_IB_S = :OLD_ID_HLP_N_IB_S'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select hlp_n_ib_s.*,'
      '       hlp_ib.name_hlp_ib'
      'from hlp_n_ib_s'
      
        'left outer join hlp_ib on hlp_ib.id_hlp_ib=hlp_n_ib_s.idib_hlp_n' +
        '_ib_s'
      'where hlp_n_ib_s.id_hlp_n_ib_s=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'HLP_N_IB_S'
    AutoUpdateOptions.KeyFields = 'ID_HLP_N_IB_S'
    AutoUpdateOptions.GeneratorName = 'GEN_HLP_N_IB_S_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 80
    poUseLargeIntField = True
    object ElementID_HLP_N_IB_S: TFIBLargeIntField
      FieldName = 'ID_HLP_N_IB_S'
    end
    object ElementIDBASE_HLP_N_IB_S: TFIBLargeIntField
      FieldName = 'IDBASE_HLP_N_IB_S'
    end
    object ElementGUID_HLP_N_IB_S: TFIBWideStringField
      FieldName = 'GUID_HLP_N_IB_S'
      Size = 38
    end
    object ElementPOS_ISM_HLP_N_IB_S: TFIBDateTimeField
      FieldName = 'POS_ISM_HLP_N_IB_S'
    end
    object ElementIDGRP_HLP_N_IB_S: TFIBLargeIntField
      FieldName = 'IDGRP_HLP_N_IB_S'
    end
    object ElementIDNABOR_HLP_N_IB_S: TFIBLargeIntField
      FieldName = 'IDNABOR_HLP_N_IB_S'
    end
    object ElementIDIB_HLP_N_IB_S: TFIBLargeIntField
      FieldName = 'IDIB_HLP_N_IB_S'
    end
    object ElementINDEX_HLP_N_IB_S: TFIBIntegerField
      FieldName = 'INDEX_HLP_N_IB_S'
    end
    object ElementNAME_HLP_IB: TFIBWideStringField
      FieldName = 'NAME_HLP_IB'
      Size = 200
    end
  end
end
