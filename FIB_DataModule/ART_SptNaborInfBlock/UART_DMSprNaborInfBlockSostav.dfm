object ART_DMSprNaborInfBlockSostav: TART_DMSprNaborInfBlockSostav
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
      'UPDATE ART_N_IB_S'
      'SET '
      '    IDBASE_ART_N_IB_S = :IDBASE_ART_N_IB_S,'
      '    GUID_ART_N_IB_S = :GUID_ART_N_IB_S,'
      '    POS_ISM_ART_N_IB_S = :POS_ISM_ART_N_IB_S,'
      '    IDGRP_ART_N_IB_S = :IDGRP_ART_N_IB_S,'
      '    IDNABOR_ART_N_IB_S = :IDNABOR_ART_N_IB_S,'
      '    IDIB_ART_N_IB_S = :IDIB_ART_N_IB_S'
      'WHERE'
      '    ID_ART_N_IB_S = :OLD_ID_ART_N_IB_S'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    ART_N_IB_S'
      'WHERE'
      '        ID_ART_N_IB_S = :OLD_ID_ART_N_IB_S'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO ART_N_IB_S('
      '    ID_ART_N_IB_S,'
      '    IDBASE_ART_N_IB_S,'
      '    GUID_ART_N_IB_S,'
      '    POS_ISM_ART_N_IB_S,'
      '    IDGRP_ART_N_IB_S,'
      '    IDNABOR_ART_N_IB_S,'
      '    IDIB_ART_N_IB_S'
      ')'
      'VALUES('
      '    :ID_ART_N_IB_S,'
      '    :IDBASE_ART_N_IB_S,'
      '    :GUID_ART_N_IB_S,'
      '    :POS_ISM_ART_N_IB_S,'
      '    :IDGRP_ART_N_IB_S,'
      '    :IDNABOR_ART_N_IB_S,'
      '    :IDIB_ART_N_IB_S'
      ')')
    RefreshSQL.Strings = (
      'select art_n_ib_s.*,'
      '       art_ib.name_art_ib'
      'from art_n_ib_s'
      
        'left outer join art_ib on art_ib.id_art_ib=art_n_ib_s.idib_art_n' +
        '_ib_s'
      'where( '
      '        art_n_ib_s.idnabor_art_n_ib_s=:PARAM_ID_GROUP_ELEMENT'
      ' AND art_n_ib_s.idgrp_art_n_ib_s=:PARAM_IDGRP'
      '     ) and (     ART_N_IB_S.ID_ART_N_IB_S = :OLD_ID_ART_N_IB_S'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select art_n_ib_s.*,'
      '       art_ib.name_art_ib'
      'from art_n_ib_s'
      
        'left outer join art_ib on art_ib.id_art_ib=art_n_ib_s.idib_art_n' +
        '_ib_s'
      'where'
      '        art_n_ib_s.idnabor_art_n_ib_s=:PARAM_ID_GROUP_ELEMENT'
      ' AND art_n_ib_s.idgrp_art_n_ib_s=:PARAM_IDGRP'
      'order by art_ib.name_art_ib')
    AutoUpdateOptions.UpdateTableName = 'ART_N_IB_S'
    AutoUpdateOptions.KeyFields = 'ID_ART_N_IB_S'
    AutoUpdateOptions.GeneratorName = 'GEN_ART_N_IB_S_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object TableID_ART_N_IB_S: TFIBLargeIntField
      FieldName = 'ID_ART_N_IB_S'
    end
    object TableIDBASE_ART_N_IB_S: TFIBLargeIntField
      FieldName = 'IDBASE_ART_N_IB_S'
    end
    object TableGUID_ART_N_IB_S: TFIBWideStringField
      FieldName = 'GUID_ART_N_IB_S'
      Size = 38
    end
    object TablePOS_ISM_ART_N_IB_S: TFIBDateTimeField
      FieldName = 'POS_ISM_ART_N_IB_S'
    end
    object TableIDGRP_ART_N_IB_S: TFIBLargeIntField
      FieldName = 'IDGRP_ART_N_IB_S'
    end
    object TableIDNABOR_ART_N_IB_S: TFIBLargeIntField
      FieldName = 'IDNABOR_ART_N_IB_S'
    end
    object TableIDIB_ART_N_IB_S: TFIBLargeIntField
      FieldName = 'IDIB_ART_N_IB_S'
    end
    object TableNAME_ART_IB: TFIBWideStringField
      FieldName = 'NAME_ART_IB'
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
      'UPDATE ART_N_IB_S'
      'SET '
      '    IDBASE_ART_N_IB_S = :IDBASE_ART_N_IB_S,'
      '    GUID_ART_N_IB_S = :GUID_ART_N_IB_S,'
      '    POS_ISM_ART_N_IB_S = :POS_ISM_ART_N_IB_S,'
      '    IDGRP_ART_N_IB_S = :IDGRP_ART_N_IB_S,'
      '    IDNABOR_ART_N_IB_S = :IDNABOR_ART_N_IB_S,'
      '    IDIB_ART_N_IB_S = :IDIB_ART_N_IB_S'
      'WHERE'
      '    ID_ART_N_IB_S = :OLD_ID_ART_N_IB_S'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    ART_N_IB_S'
      'WHERE'
      '        ID_ART_N_IB_S = :OLD_ID_ART_N_IB_S'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO ART_N_IB_S('
      '    ID_ART_N_IB_S,'
      '    IDBASE_ART_N_IB_S,'
      '    GUID_ART_N_IB_S,'
      '    POS_ISM_ART_N_IB_S,'
      '    IDGRP_ART_N_IB_S,'
      '    IDNABOR_ART_N_IB_S,'
      '    IDIB_ART_N_IB_S'
      ')'
      'VALUES('
      '    :ID_ART_N_IB_S,'
      '    :IDBASE_ART_N_IB_S,'
      '    :GUID_ART_N_IB_S,'
      '    :POS_ISM_ART_N_IB_S,'
      '    :IDGRP_ART_N_IB_S,'
      '    :IDNABOR_ART_N_IB_S,'
      '    :IDIB_ART_N_IB_S'
      ')')
    RefreshSQL.Strings = (
      'select art_n_ib_s.*,'
      '       art_ib.name_art_ib'
      'from art_n_ib_s'
      
        'left outer join art_ib on art_ib.id_art_ib=art_n_ib_s.idib_art_n' +
        '_ib_s'
      'where(  art_n_ib_s.id_art_n_ib_s=:PARAM_ID'
      '     ) and (     ART_N_IB_S.ID_ART_N_IB_S = :OLD_ID_ART_N_IB_S'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select art_n_ib_s.*,'
      '       art_ib.name_art_ib'
      'from art_n_ib_s'
      
        'left outer join art_ib on art_ib.id_art_ib=art_n_ib_s.idib_art_n' +
        '_ib_s'
      'where art_n_ib_s.id_art_n_ib_s=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'ART_N_IB_S'
    AutoUpdateOptions.KeyFields = 'ID_ART_N_IB_S'
    AutoUpdateOptions.GeneratorName = 'GEN_ART_N_IB_S_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 80
    poUseLargeIntField = True
    object ElementID_ART_N_IB_S: TFIBLargeIntField
      FieldName = 'ID_ART_N_IB_S'
    end
    object ElementIDBASE_ART_N_IB_S: TFIBLargeIntField
      FieldName = 'IDBASE_ART_N_IB_S'
    end
    object ElementGUID_ART_N_IB_S: TFIBWideStringField
      FieldName = 'GUID_ART_N_IB_S'
      Size = 38
    end
    object ElementPOS_ISM_ART_N_IB_S: TFIBDateTimeField
      FieldName = 'POS_ISM_ART_N_IB_S'
    end
    object ElementIDGRP_ART_N_IB_S: TFIBLargeIntField
      FieldName = 'IDGRP_ART_N_IB_S'
    end
    object ElementIDNABOR_ART_N_IB_S: TFIBLargeIntField
      FieldName = 'IDNABOR_ART_N_IB_S'
    end
    object ElementIDIB_ART_N_IB_S: TFIBLargeIntField
      FieldName = 'IDIB_ART_N_IB_S'
    end
    object ElementNAME_ART_IB: TFIBWideStringField
      FieldName = 'NAME_ART_IB'
      Size = 200
    end
  end
end
