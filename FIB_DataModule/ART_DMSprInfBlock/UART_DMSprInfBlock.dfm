object ART_DMSprInfBlock: TART_DMSprInfBlock
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
      'select art_ib.*'
      'from art_ib'
      'where art_ib.idgrp_art_ib=:PARAM_IDGRP'
      'ORDER BY art_ib.idgrp_art_ib, art_ib.index_art_ib')
    Transaction = IBTr
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object TableID_ART_IB: TFIBLargeIntField
      FieldName = 'ID_ART_IB'
    end
    object TableIDBASE_ART_IB: TFIBLargeIntField
      FieldName = 'IDBASE_ART_IB'
    end
    object TablePOS_ISM_ART_IB: TFIBDateTimeField
      FieldName = 'POS_ISM_ART_IB'
    end
    object TableGUID_ART_IB: TFIBWideStringField
      FieldName = 'GUID_ART_IB'
      Size = 38
    end
    object TableIDGRP_ART_IB: TFIBLargeIntField
      FieldName = 'IDGRP_ART_IB'
    end
    object TableGUIDGRP_ART_IB: TFIBWideStringField
      FieldName = 'GUIDGRP_ART_IB'
      Size = 38
    end
    object TableNAME_ART_IB: TFIBWideStringField
      FieldName = 'NAME_ART_IB'
      Size = 200
    end
    object TableKEYWORDS_ART_IB: TFIBWideStringField
      FieldName = 'KEYWORDS_ART_IB'
      Size = 200
    end
    object TableTITLE_ART_IB: TFIBWideStringField
      FieldName = 'TITLE_ART_IB'
      Size = 200
    end
    object TableDESCR_ART_IB: TFIBWideStringField
      FieldName = 'DESCR_ART_IB'
      Size = 200
    end
    object TableINDEX_ART_IB: TFIBIntegerField
      FieldName = 'INDEX_ART_IB'
    end
    object TableWEB_KEYWORDS_ART_IB: TFIBWideStringField
      FieldName = 'WEB_KEYWORDS_ART_IB'
      Size = 200
    end
    object TableWEB_TITLE_ART_IB: TFIBWideStringField
      FieldName = 'WEB_TITLE_ART_IB'
      Size = 200
    end
    object TableWEB_DESCR_ART_IB: TFIBWideStringField
      FieldName = 'WEB_DESCR_ART_IB'
      Size = 200
    end
    object TableFL_ADD_SITEMAP_ART_IB: TFIBSmallIntField
      FieldName = 'FL_ADD_SITEMAP_ART_IB'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE ART_IB'
      'SET '
      '    IDBASE_ART_IB = :IDBASE_ART_IB,'
      '    POS_ISM_ART_IB = :POS_ISM_ART_IB,'
      '    GUID_ART_IB = :GUID_ART_IB,'
      '    IDGRP_ART_IB = :IDGRP_ART_IB,'
      '    GUIDGRP_ART_IB = :GUIDGRP_ART_IB,'
      '    NAME_ART_IB = :NAME_ART_IB,'
      '    KEYWORDS_ART_IB = :KEYWORDS_ART_IB,'
      '    TITLE_ART_IB = :TITLE_ART_IB,'
      '    DESCR_ART_IB = :DESCR_ART_IB,'
      '    INDEX_ART_IB = :INDEX_ART_IB,'
      '    WEB_KEYWORDS_ART_IB = :WEB_KEYWORDS_ART_IB,'
      '    WEB_TITLE_ART_IB = :WEB_TITLE_ART_IB,'
      '    WEB_DESCR_ART_IB = :WEB_DESCR_ART_IB,'
      '    FL_ADD_SITEMAP_ART_IB = :FL_ADD_SITEMAP_ART_IB'
      'WHERE'
      '    ID_ART_IB = :OLD_ID_ART_IB'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    ART_IB'
      'WHERE'
      '        ID_ART_IB = :OLD_ID_ART_IB'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO ART_IB('
      '    ID_ART_IB,'
      '    IDBASE_ART_IB,'
      '    POS_ISM_ART_IB,'
      '    GUID_ART_IB,'
      '    IDGRP_ART_IB,'
      '    GUIDGRP_ART_IB,'
      '    NAME_ART_IB,'
      '    KEYWORDS_ART_IB,'
      '    TITLE_ART_IB,'
      '    DESCR_ART_IB,'
      '    INDEX_ART_IB,'
      '    WEB_KEYWORDS_ART_IB,'
      '    WEB_TITLE_ART_IB,'
      '    WEB_DESCR_ART_IB,'
      '    FL_ADD_SITEMAP_ART_IB'
      ')'
      'VALUES('
      '    :ID_ART_IB,'
      '    :IDBASE_ART_IB,'
      '    :POS_ISM_ART_IB,'
      '    :GUID_ART_IB,'
      '    :IDGRP_ART_IB,'
      '    :GUIDGRP_ART_IB,'
      '    :NAME_ART_IB,'
      '    :KEYWORDS_ART_IB,'
      '    :TITLE_ART_IB,'
      '    :DESCR_ART_IB,'
      '    :INDEX_ART_IB,'
      '    :WEB_KEYWORDS_ART_IB,'
      '    :WEB_TITLE_ART_IB,'
      '    :WEB_DESCR_ART_IB,'
      '    :FL_ADD_SITEMAP_ART_IB'
      ')')
    RefreshSQL.Strings = (
      'select art_ib.*'
      'from art_ib'
      'where(  art_ib.id_art_ib=:PARAM_ID'
      '     ) and (     ART_IB.ID_ART_IB = :OLD_ID_ART_IB'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select art_ib.*'
      'from art_ib'
      'where art_ib.id_art_ib=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'ART_IB'
    AutoUpdateOptions.KeyFields = 'ID_ART_IB'
    AutoUpdateOptions.GeneratorName = 'GEN_ART_IB_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object ElementID_ART_IB: TFIBLargeIntField
      FieldName = 'ID_ART_IB'
    end
    object ElementIDBASE_ART_IB: TFIBLargeIntField
      FieldName = 'IDBASE_ART_IB'
    end
    object ElementPOS_ISM_ART_IB: TFIBDateTimeField
      FieldName = 'POS_ISM_ART_IB'
    end
    object ElementGUID_ART_IB: TFIBWideStringField
      FieldName = 'GUID_ART_IB'
      Size = 38
    end
    object ElementIDGRP_ART_IB: TFIBLargeIntField
      FieldName = 'IDGRP_ART_IB'
    end
    object ElementGUIDGRP_ART_IB: TFIBWideStringField
      FieldName = 'GUIDGRP_ART_IB'
      Size = 38
    end
    object ElementNAME_ART_IB: TFIBWideStringField
      FieldName = 'NAME_ART_IB'
      Size = 200
    end
    object ElementKEYWORDS_ART_IB: TFIBWideStringField
      FieldName = 'KEYWORDS_ART_IB'
      Size = 200
    end
    object ElementTITLE_ART_IB: TFIBWideStringField
      FieldName = 'TITLE_ART_IB'
      Size = 200
    end
    object ElementDESCR_ART_IB: TFIBWideStringField
      FieldName = 'DESCR_ART_IB'
      Size = 200
    end
    object ElementINDEX_ART_IB: TFIBIntegerField
      FieldName = 'INDEX_ART_IB'
    end
    object ElementWEB_KEYWORDS_ART_IB: TFIBWideStringField
      FieldName = 'WEB_KEYWORDS_ART_IB'
      Size = 200
    end
    object ElementWEB_TITLE_ART_IB: TFIBWideStringField
      FieldName = 'WEB_TITLE_ART_IB'
      Size = 200
    end
    object ElementWEB_DESCR_ART_IB: TFIBWideStringField
      FieldName = 'WEB_DESCR_ART_IB'
      Size = 200
    end
    object ElementFL_ADD_SITEMAP_ART_IB: TFIBSmallIntField
      FieldName = 'FL_ADD_SITEMAP_ART_IB'
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
