object HLP_DMSprPage: THLP_DMSprPage
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
      'select hlp_page.*'
      'from hlp_page'
      'where hlp_page.idgrp_hlp_page=:PARAM_IDGRP'
      'ORDER BY hlp_page.idgrp_hlp_page, hlp_page.index_hlp_page')
    Transaction = IBTr
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_HLP_PAGE: TFIBLargeIntField
      FieldName = 'ID_HLP_PAGE'
    end
    object TableIDBASE_HLP_PAGE: TFIBLargeIntField
      FieldName = 'IDBASE_HLP_PAGE'
    end
    object TableGID_HLP_PAGE: TFIBWideStringField
      FieldName = 'GID_HLP_PAGE'
      Size = 10
    end
    object TableIDGRP_HLP_PAGE: TFIBLargeIntField
      FieldName = 'IDGRP_HLP_PAGE'
    end
    object TableNAME_HLP_PAGE: TFIBWideStringField
      FieldName = 'NAME_HLP_PAGE'
      Size = 200
    end
    object TableKEYWORDS_HLP_PAGE: TFIBWideStringField
      FieldName = 'KEYWORDS_HLP_PAGE'
      Size = 200
    end
    object TableTITLE_HLP_PAGE: TFIBWideStringField
      FieldName = 'TITLE_HLP_PAGE'
      Size = 200
    end
    object TableDESCR_HLP_PAGE: TFIBWideStringField
      FieldName = 'DESCR_HLP_PAGE'
      Size = 200
    end
    object TableINDEX_HLP_PAGE: TFIBIntegerField
      FieldName = 'INDEX_HLP_PAGE'
    end
    object TableWEBKEYWORDS_HLP_PAGE: TFIBWideStringField
      FieldName = 'WEBKEYWORDS_HLP_PAGE'
      Size = 200
    end
    object TableWEBTITLE_HLP_PAGE: TFIBWideStringField
      FieldName = 'WEBTITLE_HLP_PAGE'
      Size = 200
    end
    object TableWEBDESCR_HLP_PAGE: TFIBWideStringField
      FieldName = 'WEBDESCR_HLP_PAGE'
      Size = 200
    end
    object TableGUIDGRP_HLP_PAGE: TFIBWideStringField
      FieldName = 'GUIDGRP_HLP_PAGE'
      Size = 38
    end
    object TableSTRCODE_HLP_PAGE: TFIBWideStringField
      FieldName = 'STRCODE_HLP_PAGE'
      Size = 30
    end
    object TableGUID_HLP_PAGE: TFIBWideStringField
      FieldName = 'GUID_HLP_PAGE'
      Size = 38
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE HLP_PAGE'
      'SET '
      '    IDBASE_HLP_PAGE = :IDBASE_HLP_PAGE,'
      '    GID_HLP_PAGE = :GID_HLP_PAGE,'
      '    IDGRP_HLP_PAGE = :IDGRP_HLP_PAGE,'
      '    NAME_HLP_PAGE = :NAME_HLP_PAGE,'
      '    KEYWORDS_HLP_PAGE = :KEYWORDS_HLP_PAGE,'
      '    TITLE_HLP_PAGE = :TITLE_HLP_PAGE,'
      '    DESCR_HLP_PAGE = :DESCR_HLP_PAGE,'
      '    INDEX_HLP_PAGE = :INDEX_HLP_PAGE,'
      '    WEBKEYWORDS_HLP_PAGE = :WEBKEYWORDS_HLP_PAGE,'
      '    WEBTITLE_HLP_PAGE = :WEBTITLE_HLP_PAGE,'
      '    WEBDESCR_HLP_PAGE = :WEBDESCR_HLP_PAGE,'
      '    GUIDGRP_HLP_PAGE = :GUIDGRP_HLP_PAGE,'
      '    STRCODE_HLP_PAGE = :STRCODE_HLP_PAGE,'
      '    GUID_HLP_PAGE = :GUID_HLP_PAGE'
      'WHERE'
      '    ID_HLP_PAGE = :OLD_ID_HLP_PAGE'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    HLP_PAGE'
      'WHERE'
      '        ID_HLP_PAGE = :OLD_ID_HLP_PAGE'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO HLP_PAGE('
      '    ID_HLP_PAGE,'
      '    IDBASE_HLP_PAGE,'
      '    GID_HLP_PAGE,'
      '    IDGRP_HLP_PAGE,'
      '    NAME_HLP_PAGE,'
      '    KEYWORDS_HLP_PAGE,'
      '    TITLE_HLP_PAGE,'
      '    DESCR_HLP_PAGE,'
      '    INDEX_HLP_PAGE,'
      '    WEBKEYWORDS_HLP_PAGE,'
      '    WEBTITLE_HLP_PAGE,'
      '    WEBDESCR_HLP_PAGE,'
      '    GUIDGRP_HLP_PAGE,'
      '    STRCODE_HLP_PAGE,'
      '    GUID_HLP_PAGE'
      ')'
      'VALUES('
      '    :ID_HLP_PAGE,'
      '    :IDBASE_HLP_PAGE,'
      '    :GID_HLP_PAGE,'
      '    :IDGRP_HLP_PAGE,'
      '    :NAME_HLP_PAGE,'
      '    :KEYWORDS_HLP_PAGE,'
      '    :TITLE_HLP_PAGE,'
      '    :DESCR_HLP_PAGE,'
      '    :INDEX_HLP_PAGE,'
      '    :WEBKEYWORDS_HLP_PAGE,'
      '    :WEBTITLE_HLP_PAGE,'
      '    :WEBDESCR_HLP_PAGE,'
      '    :GUIDGRP_HLP_PAGE,'
      '    :STRCODE_HLP_PAGE,'
      '    :GUID_HLP_PAGE'
      ')')
    RefreshSQL.Strings = (
      'select hlp_page.*'
      'from hlp_page'
      'where(  hlp_page.id_hlp_page=:PARAM_ID'
      '     ) and (     HLP_PAGE.ID_HLP_PAGE = :OLD_ID_HLP_PAGE'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select hlp_page.*'
      'from hlp_page'
      'where hlp_page.id_hlp_page=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'HLP_PAGE'
    AutoUpdateOptions.KeyFields = 'ID_HLP_PAGE'
    AutoUpdateOptions.GeneratorName = 'GEN_HLP_PAGE_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object ElementID_HLP_PAGE: TFIBLargeIntField
      FieldName = 'ID_HLP_PAGE'
    end
    object ElementIDBASE_HLP_PAGE: TFIBLargeIntField
      FieldName = 'IDBASE_HLP_PAGE'
    end
    object ElementGID_HLP_PAGE: TFIBWideStringField
      FieldName = 'GID_HLP_PAGE'
      Size = 10
    end
    object ElementIDGRP_HLP_PAGE: TFIBLargeIntField
      FieldName = 'IDGRP_HLP_PAGE'
    end
    object ElementNAME_HLP_PAGE: TFIBWideStringField
      FieldName = 'NAME_HLP_PAGE'
      Size = 200
    end
    object ElementKEYWORDS_HLP_PAGE: TFIBWideStringField
      FieldName = 'KEYWORDS_HLP_PAGE'
      Size = 200
    end
    object ElementTITLE_HLP_PAGE: TFIBWideStringField
      FieldName = 'TITLE_HLP_PAGE'
      Size = 200
    end
    object ElementDESCR_HLP_PAGE: TFIBWideStringField
      FieldName = 'DESCR_HLP_PAGE'
      Size = 200
    end
    object ElementINDEX_HLP_PAGE: TFIBIntegerField
      FieldName = 'INDEX_HLP_PAGE'
    end
    object ElementWEBKEYWORDS_HLP_PAGE: TFIBWideStringField
      FieldName = 'WEBKEYWORDS_HLP_PAGE'
      Size = 200
    end
    object ElementWEBTITLE_HLP_PAGE: TFIBWideStringField
      FieldName = 'WEBTITLE_HLP_PAGE'
      Size = 200
    end
    object ElementWEBDESCR_HLP_PAGE: TFIBWideStringField
      FieldName = 'WEBDESCR_HLP_PAGE'
      Size = 200
    end
    object ElementGUIDGRP_HLP_PAGE: TFIBWideStringField
      FieldName = 'GUIDGRP_HLP_PAGE'
      Size = 38
    end
    object ElementSTRCODE_HLP_PAGE: TFIBWideStringField
      FieldName = 'STRCODE_HLP_PAGE'
      Size = 30
    end
    object ElementGUID_HLP_PAGE: TFIBWideStringField
      FieldName = 'GUID_HLP_PAGE'
      Size = 38
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
    Left = 152
    Top = 144
    qoStartTransaction = True
  end
end
