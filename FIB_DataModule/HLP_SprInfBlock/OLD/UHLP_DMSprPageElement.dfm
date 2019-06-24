object HLP_DMSprPageElement: THLP_DMSprPageElement
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 341
  Width = 435
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE HLP_PAGE_ELEMENT'
      'SET '
      '    IDBASE_HLP_PAGE_ELEMENT = :IDBASE_HLP_PAGE_ELEMENT,'
      '    GID_HLP_PAGE_ELEMENT = :GID_HLP_PAGE_ELEMENT,'
      '    GUID_HLP_PAGE_ELEMENT = :GUID_HLP_PAGE_ELEMENT,'
      '    IDPAGE_HLP_PAGE_ELEMENT = :IDPAGE_HLP_PAGE_ELEMENT,'
      '    GUIDPAGE_HLP_PAGE_ELEMENT = :GUIDPAGE_HLP_PAGE_ELEMENT,'
      '    TYPE_HLP_PAGE_ELEMENT = :TYPE_HLP_PAGE_ELEMENT,'
      '    TEXT_HLP_PAGE_ELEMENT = :TEXT_HLP_PAGE_ELEMENT,'
      '    IDIMAGE_HLP_PAGE_ELEMENT = :IDIMAGE_HLP_PAGE_ELEMENT,'
      '    GUIDIMAGE_HLP_PAGE_ELEMENT = :GUIDIMAGE_HLP_PAGE_ELEMENT,'
      '    INDEX_HLP_PAGE_ELEMENT = :INDEX_HLP_PAGE_ELEMENT'
      'WHERE'
      '    ID_HLP_PAGE_ELEMENT = :OLD_ID_HLP_PAGE_ELEMENT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    HLP_PAGE_ELEMENT'
      'WHERE'
      '        ID_HLP_PAGE_ELEMENT = :OLD_ID_HLP_PAGE_ELEMENT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO HLP_PAGE_ELEMENT('
      '    ID_HLP_PAGE_ELEMENT,'
      '    IDBASE_HLP_PAGE_ELEMENT,'
      '    GID_HLP_PAGE_ELEMENT,'
      '    GUID_HLP_PAGE_ELEMENT,'
      '    IDPAGE_HLP_PAGE_ELEMENT,'
      '    GUIDPAGE_HLP_PAGE_ELEMENT,'
      '    TYPE_HLP_PAGE_ELEMENT,'
      '    TEXT_HLP_PAGE_ELEMENT,'
      '    IDIMAGE_HLP_PAGE_ELEMENT,'
      '    GUIDIMAGE_HLP_PAGE_ELEMENT,'
      '    INDEX_HLP_PAGE_ELEMENT'
      ')'
      'VALUES('
      '    :ID_HLP_PAGE_ELEMENT,'
      '    :IDBASE_HLP_PAGE_ELEMENT,'
      '    :GID_HLP_PAGE_ELEMENT,'
      '    :GUID_HLP_PAGE_ELEMENT,'
      '    :IDPAGE_HLP_PAGE_ELEMENT,'
      '    :GUIDPAGE_HLP_PAGE_ELEMENT,'
      '    :TYPE_HLP_PAGE_ELEMENT,'
      '    :TEXT_HLP_PAGE_ELEMENT,'
      '    :IDIMAGE_HLP_PAGE_ELEMENT,'
      '    :GUIDIMAGE_HLP_PAGE_ELEMENT,'
      '    :INDEX_HLP_PAGE_ELEMENT'
      ')')
    RefreshSQL.Strings = (
      'select hlp_page_element.*,'
      '    hlp_image.name_hlp_image,'
      '    hlp_image.image_hlp_image,'
      '    hlp_image.type_hlp_image'
      'from hlp_page_element'
      
        'left outer join hlp_image on hlp_page_element.idimage_hlp_page_e' +
        'lement=hlp_image.id_hlp_image'
      'where(  hlp_page_element.idpage_hlp_page_element=:PARAM_IDPAGE'
      
        '     ) and (     HLP_PAGE_ELEMENT.ID_HLP_PAGE_ELEMENT = :OLD_ID_' +
        'HLP_PAGE_ELEMENT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select hlp_page_element.*,'
      '    hlp_image.name_hlp_image,'
      '    hlp_image.image_hlp_image,'
      '    hlp_image.type_hlp_image'
      'from hlp_page_element'
      
        'left outer join hlp_image on hlp_page_element.idimage_hlp_page_e' +
        'lement=hlp_image.id_hlp_image'
      'where hlp_page_element.idpage_hlp_page_element=:PARAM_IDPAGE')
    AutoUpdateOptions.UpdateTableName = 'HLP_PAGE_ELEMENT'
    AutoUpdateOptions.KeyFields = 'ID_HLP_PAGE_ELEMENT'
    AutoUpdateOptions.GeneratorName = 'GEN_HLP_PAGE_ELEMENT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    Left = 152
    Top = 24
    poUseLargeIntField = True
    object TableID_HLP_PAGE_ELEMENT: TFIBLargeIntField
      FieldName = 'ID_HLP_PAGE_ELEMENT'
    end
    object TableIDBASE_HLP_PAGE_ELEMENT: TFIBLargeIntField
      FieldName = 'IDBASE_HLP_PAGE_ELEMENT'
    end
    object TableGID_HLP_PAGE_ELEMENT: TFIBWideStringField
      FieldName = 'GID_HLP_PAGE_ELEMENT'
      Size = 10
    end
    object TableGUID_HLP_PAGE_ELEMENT: TFIBWideStringField
      FieldName = 'GUID_HLP_PAGE_ELEMENT'
      Size = 38
    end
    object TableIDPAGE_HLP_PAGE_ELEMENT: TFIBLargeIntField
      FieldName = 'IDPAGE_HLP_PAGE_ELEMENT'
    end
    object TableTYPE_HLP_PAGE_ELEMENT: TFIBSmallIntField
      FieldName = 'TYPE_HLP_PAGE_ELEMENT'
    end
    object TableTEXT_HLP_PAGE_ELEMENT: TFIBWideStringField
      FieldName = 'TEXT_HLP_PAGE_ELEMENT'
      Size = 1500
    end
    object TableGUIDPAGE_HLP_PAGE_ELEMENT: TFIBWideStringField
      FieldName = 'GUIDPAGE_HLP_PAGE_ELEMENT'
      Size = 38
    end
    object TableGUIDIMAGE_HLP_PAGE_ELEMENT: TFIBWideStringField
      FieldName = 'GUIDIMAGE_HLP_PAGE_ELEMENT'
      Size = 38
    end
    object TableIDIMAGE_HLP_PAGE_ELEMENT: TFIBLargeIntField
      FieldName = 'IDIMAGE_HLP_PAGE_ELEMENT'
    end
    object TableINDEX_HLP_PAGE_ELEMENT: TFIBIntegerField
      FieldName = 'INDEX_HLP_PAGE_ELEMENT'
    end
    object TableNAME_HLP_IMAGE: TFIBWideStringField
      FieldName = 'NAME_HLP_IMAGE'
      Size = 200
    end
    object TableIMAGE_HLP_IMAGE: TFIBBlobField
      FieldName = 'IMAGE_HLP_IMAGE'
      Size = 8
    end
    object TableTYPE_HLP_IMAGE: TFIBSmallIntField
      FieldName = 'TYPE_HLP_IMAGE'
    end
    object TableH_ALIGN_HLP_PAGE_ELEMENT: TFIBIntegerField
      FieldName = 'H_ALIGN_HLP_PAGE_ELEMENT'
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
    Left = 240
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
    Left = 240
    Top = 80
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 48
    Top = 80
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE HLP_PAGE_ELEMENT'
      'SET '
      '    IDBASE_HLP_PAGE_ELEMENT = :IDBASE_HLP_PAGE_ELEMENT,'
      '    GID_HLP_PAGE_ELEMENT = :GID_HLP_PAGE_ELEMENT,'
      '    GUID_HLP_PAGE_ELEMENT = :GUID_HLP_PAGE_ELEMENT,'
      '    IDPAGE_HLP_PAGE_ELEMENT = :IDPAGE_HLP_PAGE_ELEMENT,'
      '    GUIDPAGE_HLP_PAGE_ELEMENT = :GUIDPAGE_HLP_PAGE_ELEMENT,'
      '    TYPE_HLP_PAGE_ELEMENT = :TYPE_HLP_PAGE_ELEMENT,'
      '    TEXT_HLP_PAGE_ELEMENT = :TEXT_HLP_PAGE_ELEMENT,'
      '    IDIMAGE_HLP_PAGE_ELEMENT = :IDIMAGE_HLP_PAGE_ELEMENT,'
      '    GUIDIMAGE_HLP_PAGE_ELEMENT = :GUIDIMAGE_HLP_PAGE_ELEMENT,'
      '    INDEX_HLP_PAGE_ELEMENT = :INDEX_HLP_PAGE_ELEMENT,'
      '    H_ALIGN_HLP_PAGE_ELEMENT = :H_ALIGN_HLP_PAGE_ELEMENT'
      'WHERE'
      '    ID_HLP_PAGE_ELEMENT = :OLD_ID_HLP_PAGE_ELEMENT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    HLP_PAGE_ELEMENT'
      'WHERE'
      '        ID_HLP_PAGE_ELEMENT = :OLD_ID_HLP_PAGE_ELEMENT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO HLP_PAGE_ELEMENT('
      '    ID_HLP_PAGE_ELEMENT,'
      '    IDBASE_HLP_PAGE_ELEMENT,'
      '    GID_HLP_PAGE_ELEMENT,'
      '    GUID_HLP_PAGE_ELEMENT,'
      '    IDPAGE_HLP_PAGE_ELEMENT,'
      '    GUIDPAGE_HLP_PAGE_ELEMENT,'
      '    TYPE_HLP_PAGE_ELEMENT,'
      '    TEXT_HLP_PAGE_ELEMENT,'
      '    IDIMAGE_HLP_PAGE_ELEMENT,'
      '    GUIDIMAGE_HLP_PAGE_ELEMENT,'
      '    INDEX_HLP_PAGE_ELEMENT,'
      '    H_ALIGN_HLP_PAGE_ELEMENT'
      ')'
      'VALUES('
      '    :ID_HLP_PAGE_ELEMENT,'
      '    :IDBASE_HLP_PAGE_ELEMENT,'
      '    :GID_HLP_PAGE_ELEMENT,'
      '    :GUID_HLP_PAGE_ELEMENT,'
      '    :IDPAGE_HLP_PAGE_ELEMENT,'
      '    :GUIDPAGE_HLP_PAGE_ELEMENT,'
      '    :TYPE_HLP_PAGE_ELEMENT,'
      '    :TEXT_HLP_PAGE_ELEMENT,'
      '    :IDIMAGE_HLP_PAGE_ELEMENT,'
      '    :GUIDIMAGE_HLP_PAGE_ELEMENT,'
      '    :INDEX_HLP_PAGE_ELEMENT,'
      '    :H_ALIGN_HLP_PAGE_ELEMENT'
      ')')
    RefreshSQL.Strings = (
      'select hlp_page_element.*'
      'from hlp_page_element'
      'where(  hlp_page_element.id_hlp_page_element=:PARAM_ID'
      
        '     ) and (     HLP_PAGE_ELEMENT.ID_HLP_PAGE_ELEMENT = :OLD_ID_' +
        'HLP_PAGE_ELEMENT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select hlp_page_element.*'
      'from hlp_page_element'
      'where hlp_page_element.id_hlp_page_element=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'HLP_PAGE_ELEMENT'
    AutoUpdateOptions.KeyFields = 'ID_HLP_PAGE_ELEMENT'
    AutoUpdateOptions.GeneratorName = 'GEN_HLP_PAGE_ELEMENT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 80
    poUseLargeIntField = True
    object ElementID_HLP_PAGE_ELEMENT: TFIBLargeIntField
      FieldName = 'ID_HLP_PAGE_ELEMENT'
    end
    object ElementIDBASE_HLP_PAGE_ELEMENT: TFIBLargeIntField
      FieldName = 'IDBASE_HLP_PAGE_ELEMENT'
    end
    object ElementGID_HLP_PAGE_ELEMENT: TFIBWideStringField
      FieldName = 'GID_HLP_PAGE_ELEMENT'
      Size = 10
    end
    object ElementGUID_HLP_PAGE_ELEMENT: TFIBWideStringField
      FieldName = 'GUID_HLP_PAGE_ELEMENT'
      Size = 38
    end
    object ElementIDPAGE_HLP_PAGE_ELEMENT: TFIBLargeIntField
      FieldName = 'IDPAGE_HLP_PAGE_ELEMENT'
    end
    object ElementTYPE_HLP_PAGE_ELEMENT: TFIBSmallIntField
      FieldName = 'TYPE_HLP_PAGE_ELEMENT'
    end
    object ElementTEXT_HLP_PAGE_ELEMENT: TFIBWideStringField
      FieldName = 'TEXT_HLP_PAGE_ELEMENT'
      Size = 1500
    end
    object ElementGUIDPAGE_HLP_PAGE_ELEMENT: TFIBWideStringField
      FieldName = 'GUIDPAGE_HLP_PAGE_ELEMENT'
      Size = 38
    end
    object ElementGUIDIMAGE_HLP_PAGE_ELEMENT: TFIBWideStringField
      FieldName = 'GUIDIMAGE_HLP_PAGE_ELEMENT'
      Size = 38
    end
    object ElementIDIMAGE_HLP_PAGE_ELEMENT: TFIBLargeIntField
      FieldName = 'IDIMAGE_HLP_PAGE_ELEMENT'
    end
    object ElementTYPE_TBL_HLP_PAGE_ELEMENT: TFIBSmallIntField
      FieldName = 'TYPE_TBL_HLP_PAGE_ELEMENT'
    end
    object ElementINDEX_HLP_PAGE_ELEMENT: TFIBIntegerField
      FieldName = 'INDEX_HLP_PAGE_ELEMENT'
    end
    object ElementH_ALIGN_HLP_PAGE_ELEMENT: TFIBIntegerField
      FieldName = 'H_ALIGN_HLP_PAGE_ELEMENT'
    end
  end
end
