object ART_DMSprInfBlockSostav: TART_DMSprInfBlockSostav
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
      'UPDATE ART_IB_S'
      'SET '
      '    IDBASE_ART_IB_S = :IDBASE_ART_IB_S,'
      '    GUID_ART_IB_S = :GUID_ART_IB_S,'
      '    POS_ISM_ART_IB_S = :POS_ISM_ART_IB_S,'
      '    IDIB_ART_IB_S = :IDIB_ART_IB_S,'
      '    TYPE_ART_IB_S = :TYPE_ART_IB_S,'
      '    TEXT_ART_IB_S = :TEXT_ART_IB_S,'
      '    IDIMG_ART_IB_S = :IDIMG_ART_IB_S,'
      '    INDEX_ART_IB_S = :INDEX_ART_IB_S,'
      '    H_ALIGN_ART_IB_S = :H_ALIGN_ART_IB_S,'
      '    V_ALIGN_ART_IB_S = :V_ALIGN_ART_IB_S,'
      '    TYPE_TEXT_ART_IB_S = :TYPE_TEXT_ART_IB_S,'
      '    FONT_SIZE_ART_IB_S = :FONT_SIZE_ART_IB_S'
      'WHERE'
      '    ID_ART_IB_S = :OLD_ID_ART_IB_S'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    ART_IB_S'
      'WHERE'
      '        ID_ART_IB_S = :OLD_ID_ART_IB_S'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO ART_IB_S('
      '    ID_ART_IB_S,'
      '    IDBASE_ART_IB_S,'
      '    GUID_ART_IB_S,'
      '    POS_ISM_ART_IB_S,'
      '    IDIB_ART_IB_S,'
      '    TYPE_ART_IB_S,'
      '    TEXT_ART_IB_S,'
      '    IDIMG_ART_IB_S,'
      '    INDEX_ART_IB_S,'
      '    H_ALIGN_ART_IB_S,'
      '    V_ALIGN_ART_IB_S,'
      '    TYPE_TEXT_ART_IB_S,'
      '    FONT_SIZE_ART_IB_S'
      ')'
      'VALUES('
      '    :ID_ART_IB_S,'
      '    :IDBASE_ART_IB_S,'
      '    :GUID_ART_IB_S,'
      '    :POS_ISM_ART_IB_S,'
      '    :IDIB_ART_IB_S,'
      '    :TYPE_ART_IB_S,'
      '    :TEXT_ART_IB_S,'
      '    :IDIMG_ART_IB_S,'
      '    :INDEX_ART_IB_S,'
      '    :H_ALIGN_ART_IB_S,'
      '    :V_ALIGN_ART_IB_S,'
      '    :TYPE_TEXT_ART_IB_S,'
      '    :FONT_SIZE_ART_IB_S'
      ')')
    RefreshSQL.Strings = (
      'select art_ib_s.*,'
      '    art_img.name_art_img'
      'from art_ib_s'
      
        'left outer join art_img on art_img.id_art_img=art_ib_s.idimg_art' +
        '_ib_s'
      'where(  art_ib_s.idib_art_ib_s=:PARAM_ID_IB'
      '     ) and (     ART_IB_S.ID_ART_IB_S = :OLD_ID_ART_IB_S'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select art_ib_s.*,'
      '    art_img.name_art_img'
      'from art_ib_s'
      
        'left outer join art_img on art_img.id_art_img=art_ib_s.idimg_art' +
        '_ib_s'
      'where art_ib_s.idib_art_ib_s=:PARAM_ID_IB'
      'order by art_ib_s.index_art_ib_s')
    AutoUpdateOptions.UpdateTableName = 'ART_IB_S'
    AutoUpdateOptions.KeyFields = 'ID_ART_IB_S'
    AutoUpdateOptions.GeneratorName = 'GEN_ART_IB_S_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 24
    poUseLargeIntField = True
    object TableID_ART_IB_S: TFIBLargeIntField
      FieldName = 'ID_ART_IB_S'
    end
    object TableIDBASE_ART_IB_S: TFIBLargeIntField
      FieldName = 'IDBASE_ART_IB_S'
    end
    object TableGUID_ART_IB_S: TFIBWideStringField
      FieldName = 'GUID_ART_IB_S'
      Size = 38
    end
    object TablePOS_ISM_ART_IB_S: TFIBDateTimeField
      FieldName = 'POS_ISM_ART_IB_S'
    end
    object TableIDIB_ART_IB_S: TFIBLargeIntField
      FieldName = 'IDIB_ART_IB_S'
    end
    object TableTYPE_ART_IB_S: TFIBSmallIntField
      FieldName = 'TYPE_ART_IB_S'
    end
    object TableTEXT_ART_IB_S: TFIBWideStringField
      FieldName = 'TEXT_ART_IB_S'
      Size = 1500
    end
    object TableIDIMG_ART_IB_S: TFIBLargeIntField
      FieldName = 'IDIMG_ART_IB_S'
    end
    object TableINDEX_ART_IB_S: TFIBIntegerField
      FieldName = 'INDEX_ART_IB_S'
    end
    object TableH_ALIGN_ART_IB_S: TFIBIntegerField
      FieldName = 'H_ALIGN_ART_IB_S'
    end
    object TableNAME_ART_IMG: TFIBWideStringField
      FieldName = 'NAME_ART_IMG'
      Size = 200
    end
    object TableV_ALIGN_ART_IB_S: TFIBIntegerField
      FieldName = 'V_ALIGN_ART_IB_S'
    end
    object TableTYPE_TEXT_ART_IB_S: TFIBIntegerField
      FieldName = 'TYPE_TEXT_ART_IB_S'
    end
    object TableFONT_SIZE_ART_IB_S: TFIBIntegerField
      FieldName = 'FONT_SIZE_ART_IB_S'
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
      'UPDATE ART_IB_S'
      'SET '
      '    IDBASE_ART_IB_S = :IDBASE_ART_IB_S,'
      '    GUID_ART_IB_S = :GUID_ART_IB_S,'
      '    POS_ISM_ART_IB_S = :POS_ISM_ART_IB_S,'
      '    IDIB_ART_IB_S = :IDIB_ART_IB_S,'
      '    TYPE_ART_IB_S = :TYPE_ART_IB_S,'
      '    TEXT_ART_IB_S = :TEXT_ART_IB_S,'
      '    IDIMG_ART_IB_S = :IDIMG_ART_IB_S,'
      '    INDEX_ART_IB_S = :INDEX_ART_IB_S,'
      '    H_ALIGN_ART_IB_S = :H_ALIGN_ART_IB_S,'
      '    V_ALIGN_ART_IB_S = :V_ALIGN_ART_IB_S,'
      '    TYPE_TEXT_ART_IB_S = :TYPE_TEXT_ART_IB_S,'
      '    FONT_SIZE_ART_IB_S = :FONT_SIZE_ART_IB_S'
      'WHERE'
      '    ID_ART_IB_S = :OLD_ID_ART_IB_S'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    ART_IB_S'
      'WHERE'
      '        ID_ART_IB_S = :OLD_ID_ART_IB_S'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO ART_IB_S('
      '    ID_ART_IB_S,'
      '    IDBASE_ART_IB_S,'
      '    GUID_ART_IB_S,'
      '    POS_ISM_ART_IB_S,'
      '    IDIB_ART_IB_S,'
      '    TYPE_ART_IB_S,'
      '    TEXT_ART_IB_S,'
      '    IDIMG_ART_IB_S,'
      '    INDEX_ART_IB_S,'
      '    H_ALIGN_ART_IB_S,'
      '    V_ALIGN_ART_IB_S,'
      '    TYPE_TEXT_ART_IB_S,'
      '    FONT_SIZE_ART_IB_S'
      ')'
      'VALUES('
      '    :ID_ART_IB_S,'
      '    :IDBASE_ART_IB_S,'
      '    :GUID_ART_IB_S,'
      '    :POS_ISM_ART_IB_S,'
      '    :IDIB_ART_IB_S,'
      '    :TYPE_ART_IB_S,'
      '    :TEXT_ART_IB_S,'
      '    :IDIMG_ART_IB_S,'
      '    :INDEX_ART_IB_S,'
      '    :H_ALIGN_ART_IB_S,'
      '    :V_ALIGN_ART_IB_S,'
      '    :TYPE_TEXT_ART_IB_S,'
      '    :FONT_SIZE_ART_IB_S'
      ')')
    RefreshSQL.Strings = (
      'select art_ib_s.*'
      'from art_ib_s'
      'where(  art_ib_s.id_art_ib_s=:PARAM_ID'
      '     ) and (     ART_IB_S.ID_ART_IB_S = :OLD_ID_ART_IB_S'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select art_ib_s.*'
      'from art_ib_s'
      'where art_ib_s.id_art_ib_s=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'ART_IB_S'
    AutoUpdateOptions.KeyFields = 'ID_ART_IB_S'
    AutoUpdateOptions.GeneratorName = 'GEN_ART_IB_S_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 80
    poUseLargeIntField = True
    object ElementID_ART_IB_S: TFIBLargeIntField
      FieldName = 'ID_ART_IB_S'
    end
    object ElementIDBASE_ART_IB_S: TFIBLargeIntField
      FieldName = 'IDBASE_ART_IB_S'
    end
    object ElementGUID_ART_IB_S: TFIBWideStringField
      FieldName = 'GUID_ART_IB_S'
      Size = 38
    end
    object ElementPOS_ISM_ART_IB_S: TFIBDateTimeField
      FieldName = 'POS_ISM_ART_IB_S'
    end
    object ElementIDIB_ART_IB_S: TFIBLargeIntField
      FieldName = 'IDIB_ART_IB_S'
    end
    object ElementTYPE_ART_IB_S: TFIBSmallIntField
      FieldName = 'TYPE_ART_IB_S'
    end
    object ElementTEXT_ART_IB_S: TFIBWideStringField
      FieldName = 'TEXT_ART_IB_S'
      Size = 1500
    end
    object ElementIDIMG_ART_IB_S: TFIBLargeIntField
      FieldName = 'IDIMG_ART_IB_S'
    end
    object ElementINDEX_ART_IB_S: TFIBIntegerField
      FieldName = 'INDEX_ART_IB_S'
    end
    object ElementH_ALIGN_ART_IB_S: TFIBIntegerField
      FieldName = 'H_ALIGN_ART_IB_S'
    end
    object ElementV_ALIGN_ART_IB_S: TFIBIntegerField
      FieldName = 'V_ALIGN_ART_IB_S'
    end
    object ElementTYPE_TEXT_ART_IB_S: TFIBIntegerField
      FieldName = 'TYPE_TEXT_ART_IB_S'
    end
    object ElementFONT_SIZE_ART_IB_S: TFIBIntegerField
      FieldName = 'FONT_SIZE_ART_IB_S'
    end
  end
end
