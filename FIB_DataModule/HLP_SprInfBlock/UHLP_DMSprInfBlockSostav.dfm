object HLP_DMSprInfBlockSostav: THLP_DMSprInfBlockSostav
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
      'UPDATE HLP_IB_S'
      'SET '
      '    IDBASE_HLP_IB_S = :IDBASE_HLP_IB_S,'
      '    GUID_HLP_IB_S = :GUID_HLP_IB_S,'
      '    POS_ISM_HLP_IB_S = :POS_ISM_HLP_IB_S,'
      '    IDIB_HLP_IB_S = :IDIB_HLP_IB_S,'
      '    TYPE_HLP_IB_S = :TYPE_HLP_IB_S,'
      '    TEXT_HLP_IB_S = :TEXT_HLP_IB_S,'
      '    IDIMG_HLP_IB_S = :IDIMG_HLP_IB_S,'
      '    INDEX_HLP_IB_S = :INDEX_HLP_IB_S,'
      '    H_ALIGN_HLP_IB_S = :H_ALIGN_HLP_IB_S,'
      '    V_ALIGN_HLP_IB_S = :V_ALIGN_HLP_IB_S,'
      '    TYPE_TEXT_HLP_IB_S = :TYPE_TEXT_HLP_IB_S,'
      '    FONT_SIZE_HLP_IB_S = :FONT_SIZE_HLP_IB_S'
      'WHERE'
      '    ID_HLP_IB_S = :OLD_ID_HLP_IB_S'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    HLP_IB_S'
      'WHERE'
      '        ID_HLP_IB_S = :OLD_ID_HLP_IB_S'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO HLP_IB_S('
      '    ID_HLP_IB_S,'
      '    IDBASE_HLP_IB_S,'
      '    GUID_HLP_IB_S,'
      '    POS_ISM_HLP_IB_S,'
      '    IDIB_HLP_IB_S,'
      '    TYPE_HLP_IB_S,'
      '    TEXT_HLP_IB_S,'
      '    IDIMG_HLP_IB_S,'
      '    INDEX_HLP_IB_S,'
      '    H_ALIGN_HLP_IB_S,'
      '    V_ALIGN_HLP_IB_S,'
      '    TYPE_TEXT_HLP_IB_S,'
      '    FONT_SIZE_HLP_IB_S'
      ')'
      'VALUES('
      '    :ID_HLP_IB_S,'
      '    :IDBASE_HLP_IB_S,'
      '    :GUID_HLP_IB_S,'
      '    :POS_ISM_HLP_IB_S,'
      '    :IDIB_HLP_IB_S,'
      '    :TYPE_HLP_IB_S,'
      '    :TEXT_HLP_IB_S,'
      '    :IDIMG_HLP_IB_S,'
      '    :INDEX_HLP_IB_S,'
      '    :H_ALIGN_HLP_IB_S,'
      '    :V_ALIGN_HLP_IB_S,'
      '    :TYPE_TEXT_HLP_IB_S,'
      '    :FONT_SIZE_HLP_IB_S'
      ')')
    RefreshSQL.Strings = (
      'select hlp_ib_s.*,'
      '    hlp_img.name_hlp_img'
      'from hlp_ib_s'
      
        'left outer join hlp_img on hlp_img.id_hlp_img=hlp_ib_s.idimg_hlp' +
        '_ib_s'
      'where(  hlp_ib_s.idib_hlp_ib_s=:PARAM_ID_IB'
      '     ) and (     HLP_IB_S.ID_HLP_IB_S = :OLD_ID_HLP_IB_S'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select hlp_ib_s.*,'
      '    hlp_img.name_hlp_img'
      'from hlp_ib_s'
      
        'left outer join hlp_img on hlp_img.id_hlp_img=hlp_ib_s.idimg_hlp' +
        '_ib_s'
      'where hlp_ib_s.idib_hlp_ib_s=:PARAM_ID_IB'
      'order by hlp_ib_s.index_hlp_ib_s')
    AutoUpdateOptions.UpdateTableName = 'HLP_IB_S'
    AutoUpdateOptions.KeyFields = 'ID_HLP_IB_S'
    AutoUpdateOptions.GeneratorName = 'GEN_HLP_IB_S_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 24
    poUseLargeIntField = True
    object TableID_HLP_IB_S: TFIBLargeIntField
      FieldName = 'ID_HLP_IB_S'
    end
    object TableIDBASE_HLP_IB_S: TFIBLargeIntField
      FieldName = 'IDBASE_HLP_IB_S'
    end
    object TableGUID_HLP_IB_S: TFIBWideStringField
      FieldName = 'GUID_HLP_IB_S'
      Size = 38
    end
    object TablePOS_ISM_HLP_IB_S: TFIBDateTimeField
      FieldName = 'POS_ISM_HLP_IB_S'
    end
    object TableIDIB_HLP_IB_S: TFIBLargeIntField
      FieldName = 'IDIB_HLP_IB_S'
    end
    object TableTYPE_HLP_IB_S: TFIBSmallIntField
      FieldName = 'TYPE_HLP_IB_S'
    end
    object TableTEXT_HLP_IB_S: TFIBWideStringField
      FieldName = 'TEXT_HLP_IB_S'
      Size = 1500
    end
    object TableIDIMG_HLP_IB_S: TFIBLargeIntField
      FieldName = 'IDIMG_HLP_IB_S'
    end
    object TableINDEX_HLP_IB_S: TFIBIntegerField
      FieldName = 'INDEX_HLP_IB_S'
    end
    object TableH_ALIGN_HLP_IB_S: TFIBIntegerField
      FieldName = 'H_ALIGN_HLP_IB_S'
    end
    object TableV_ALIGN_HLP_IB_S: TFIBIntegerField
      FieldName = 'V_ALIGN_HLP_IB_S'
    end
    object TableTYPE_TEXT_HLP_IB_S: TFIBIntegerField
      FieldName = 'TYPE_TEXT_HLP_IB_S'
    end
    object TableFONT_SIZE_HLP_IB_S: TFIBIntegerField
      FieldName = 'FONT_SIZE_HLP_IB_S'
    end
    object TableNAME_HLP_IMG: TFIBWideStringField
      FieldName = 'NAME_HLP_IMG'
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
      'UPDATE HLP_IB_S'
      'SET '
      '    IDBASE_HLP_IB_S = :IDBASE_HLP_IB_S,'
      '    GUID_HLP_IB_S = :GUID_HLP_IB_S,'
      '    POS_ISM_HLP_IB_S = :POS_ISM_HLP_IB_S,'
      '    IDIB_HLP_IB_S = :IDIB_HLP_IB_S,'
      '    TYPE_HLP_IB_S = :TYPE_HLP_IB_S,'
      '    TEXT_HLP_IB_S = :TEXT_HLP_IB_S,'
      '    IDIMG_HLP_IB_S = :IDIMG_HLP_IB_S,'
      '    INDEX_HLP_IB_S = :INDEX_HLP_IB_S,'
      '    H_ALIGN_HLP_IB_S = :H_ALIGN_HLP_IB_S,'
      '    V_ALIGN_HLP_IB_S = :V_ALIGN_HLP_IB_S,'
      '    TYPE_TEXT_HLP_IB_S = :TYPE_TEXT_HLP_IB_S,'
      '    FONT_SIZE_HLP_IB_S = :FONT_SIZE_HLP_IB_S'
      'WHERE'
      '    ID_HLP_IB_S = :OLD_ID_HLP_IB_S'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    HLP_IB_S'
      'WHERE'
      '        ID_HLP_IB_S = :OLD_ID_HLP_IB_S'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO HLP_IB_S('
      '    ID_HLP_IB_S,'
      '    IDBASE_HLP_IB_S,'
      '    GUID_HLP_IB_S,'
      '    POS_ISM_HLP_IB_S,'
      '    IDIB_HLP_IB_S,'
      '    TYPE_HLP_IB_S,'
      '    TEXT_HLP_IB_S,'
      '    IDIMG_HLP_IB_S,'
      '    INDEX_HLP_IB_S,'
      '    H_ALIGN_HLP_IB_S,'
      '    V_ALIGN_HLP_IB_S,'
      '    TYPE_TEXT_HLP_IB_S,'
      '    FONT_SIZE_HLP_IB_S'
      ')'
      'VALUES('
      '    :ID_HLP_IB_S,'
      '    :IDBASE_HLP_IB_S,'
      '    :GUID_HLP_IB_S,'
      '    :POS_ISM_HLP_IB_S,'
      '    :IDIB_HLP_IB_S,'
      '    :TYPE_HLP_IB_S,'
      '    :TEXT_HLP_IB_S,'
      '    :IDIMG_HLP_IB_S,'
      '    :INDEX_HLP_IB_S,'
      '    :H_ALIGN_HLP_IB_S,'
      '    :V_ALIGN_HLP_IB_S,'
      '    :TYPE_TEXT_HLP_IB_S,'
      '    :FONT_SIZE_HLP_IB_S'
      ')')
    RefreshSQL.Strings = (
      'select hlp_ib_s.*'
      'from hlp_ib_s'
      'where(  hlp_ib_s.id_hlp_ib_s=:PARAM_ID'
      '     ) and (     HLP_IB_S.ID_HLP_IB_S = :OLD_ID_HLP_IB_S'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select hlp_ib_s.*'
      'from hlp_ib_s'
      'where hlp_ib_s.id_hlp_ib_s=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'HLP_IB_S'
    AutoUpdateOptions.KeyFields = 'ID_HLP_IB_S'
    AutoUpdateOptions.GeneratorName = 'GEN_HLP_IB_S_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 80
    poUseLargeIntField = True
    object ElementID_HLP_IB_S: TFIBLargeIntField
      FieldName = 'ID_HLP_IB_S'
    end
    object ElementIDBASE_HLP_IB_S: TFIBLargeIntField
      FieldName = 'IDBASE_HLP_IB_S'
    end
    object ElementGUID_HLP_IB_S: TFIBWideStringField
      FieldName = 'GUID_HLP_IB_S'
      Size = 38
    end
    object ElementPOS_ISM_HLP_IB_S: TFIBDateTimeField
      FieldName = 'POS_ISM_HLP_IB_S'
    end
    object ElementIDIB_HLP_IB_S: TFIBLargeIntField
      FieldName = 'IDIB_HLP_IB_S'
    end
    object ElementTYPE_HLP_IB_S: TFIBSmallIntField
      FieldName = 'TYPE_HLP_IB_S'
    end
    object ElementTEXT_HLP_IB_S: TFIBWideStringField
      FieldName = 'TEXT_HLP_IB_S'
      Size = 1500
    end
    object ElementIDIMG_HLP_IB_S: TFIBLargeIntField
      FieldName = 'IDIMG_HLP_IB_S'
    end
    object ElementINDEX_HLP_IB_S: TFIBIntegerField
      FieldName = 'INDEX_HLP_IB_S'
    end
    object ElementH_ALIGN_HLP_IB_S: TFIBIntegerField
      FieldName = 'H_ALIGN_HLP_IB_S'
    end
    object ElementV_ALIGN_HLP_IB_S: TFIBIntegerField
      FieldName = 'V_ALIGN_HLP_IB_S'
    end
    object ElementTYPE_TEXT_HLP_IB_S: TFIBIntegerField
      FieldName = 'TYPE_TEXT_HLP_IB_S'
    end
    object ElementFONT_SIZE_HLP_IB_S: TFIBIntegerField
      FieldName = 'FONT_SIZE_HLP_IB_S'
    end
  end
end
