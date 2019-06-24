object HLP_DMSprImage: THLP_DMSprImage
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
      'select hlp_img.*'
      'from hlp_img'
      'where hlp_img.idgrp_hlp_img=:PARAM_IDGRP'
      'ORDER BY hlp_img.name_hlp_img')
    Transaction = IBTr
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object TableID_HLP_IMG: TFIBLargeIntField
      FieldName = 'ID_HLP_IMG'
    end
    object TableIDBASE_HLP_IMG: TFIBLargeIntField
      FieldName = 'IDBASE_HLP_IMG'
    end
    object TableGUID_HLP_IMG: TFIBWideStringField
      FieldName = 'GUID_HLP_IMG'
      Size = 38
    end
    object TablePOS_ISM_HLP_IMG: TFIBDateTimeField
      FieldName = 'POS_ISM_HLP_IMG'
    end
    object TableIDGRP_HLP_IMG: TFIBLargeIntField
      FieldName = 'IDGRP_HLP_IMG'
    end
    object TableGUIDGRP_HLP_IMG: TFIBWideStringField
      FieldName = 'GUIDGRP_HLP_IMG'
      Size = 38
    end
    object TableNAME_HLP_IMG: TFIBWideStringField
      FieldName = 'NAME_HLP_IMG'
      Size = 200
    end
    object TableTEXT_HLP_IMG: TFIBWideStringField
      FieldName = 'TEXT_HLP_IMG'
      Size = 200
    end
    object TableHEIGHT_HLP_IMG: TFIBIntegerField
      FieldName = 'HEIGHT_HLP_IMG'
    end
    object TableWIDTH_HLP_IMG: TFIBIntegerField
      FieldName = 'WIDTH_HLP_IMG'
    end
    object TableIMAGE_HLP_IMG: TFIBBlobField
      FieldName = 'IMAGE_HLP_IMG'
      Size = 8
    end
    object TableINDEX_HLP_IMG: TFIBIntegerField
      FieldName = 'INDEX_HLP_IMG'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE HLP_IMG'
      'SET '
      '    IDBASE_HLP_IMG = :IDBASE_HLP_IMG,'
      '    GUID_HLP_IMG = :GUID_HLP_IMG,'
      '    POS_ISM_HLP_IMG = :POS_ISM_HLP_IMG,'
      '    IDGRP_HLP_IMG = :IDGRP_HLP_IMG,'
      '    GUIDGRP_HLP_IMG = :GUIDGRP_HLP_IMG,'
      '    NAME_HLP_IMG = :NAME_HLP_IMG,'
      '    TEXT_HLP_IMG = :TEXT_HLP_IMG,'
      '    HEIGHT_HLP_IMG = :HEIGHT_HLP_IMG,'
      '    WIDTH_HLP_IMG = :WIDTH_HLP_IMG,'
      '    IMAGE_HLP_IMG = :IMAGE_HLP_IMG,'
      '    INDEX_HLP_IMG = :INDEX_HLP_IMG'
      'WHERE'
      '    ID_HLP_IMG = :OLD_ID_HLP_IMG'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    HLP_IMG'
      'WHERE'
      '        ID_HLP_IMG = :OLD_ID_HLP_IMG'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO HLP_IMG('
      '    ID_HLP_IMG,'
      '    IDBASE_HLP_IMG,'
      '    GUID_HLP_IMG,'
      '    POS_ISM_HLP_IMG,'
      '    IDGRP_HLP_IMG,'
      '    GUIDGRP_HLP_IMG,'
      '    NAME_HLP_IMG,'
      '    TEXT_HLP_IMG,'
      '    HEIGHT_HLP_IMG,'
      '    WIDTH_HLP_IMG,'
      '    IMAGE_HLP_IMG,'
      '    INDEX_HLP_IMG'
      ')'
      'VALUES('
      '    :ID_HLP_IMG,'
      '    :IDBASE_HLP_IMG,'
      '    :GUID_HLP_IMG,'
      '    :POS_ISM_HLP_IMG,'
      '    :IDGRP_HLP_IMG,'
      '    :GUIDGRP_HLP_IMG,'
      '    :NAME_HLP_IMG,'
      '    :TEXT_HLP_IMG,'
      '    :HEIGHT_HLP_IMG,'
      '    :WIDTH_HLP_IMG,'
      '    :IMAGE_HLP_IMG,'
      '    :INDEX_HLP_IMG'
      ')')
    RefreshSQL.Strings = (
      'select hlp_img.*'
      'from hlp_img'
      'where(  hlp_img.id_hlp_img=:PARAM_ID'
      '     ) and (     HLP_IMG.ID_HLP_IMG = :OLD_ID_HLP_IMG'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select hlp_img.*'
      'from hlp_img'
      'where hlp_img.id_hlp_img=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'HLP_IMG'
    AutoUpdateOptions.KeyFields = 'ID_HLP_IMG'
    AutoUpdateOptions.GeneratorName = 'GEN_HLP_IMG_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object ElementID_HLP_IMG: TFIBLargeIntField
      FieldName = 'ID_HLP_IMG'
    end
    object ElementIDBASE_HLP_IMG: TFIBLargeIntField
      FieldName = 'IDBASE_HLP_IMG'
    end
    object ElementGUID_HLP_IMG: TFIBWideStringField
      FieldName = 'GUID_HLP_IMG'
      Size = 38
    end
    object ElementPOS_ISM_HLP_IMG: TFIBDateTimeField
      FieldName = 'POS_ISM_HLP_IMG'
    end
    object ElementIDGRP_HLP_IMG: TFIBLargeIntField
      FieldName = 'IDGRP_HLP_IMG'
    end
    object ElementGUIDGRP_HLP_IMG: TFIBWideStringField
      FieldName = 'GUIDGRP_HLP_IMG'
      Size = 38
    end
    object ElementNAME_HLP_IMG: TFIBWideStringField
      FieldName = 'NAME_HLP_IMG'
      Size = 200
    end
    object ElementTEXT_HLP_IMG: TFIBWideStringField
      FieldName = 'TEXT_HLP_IMG'
      Size = 200
    end
    object ElementHEIGHT_HLP_IMG: TFIBIntegerField
      FieldName = 'HEIGHT_HLP_IMG'
    end
    object ElementWIDTH_HLP_IMG: TFIBIntegerField
      FieldName = 'WIDTH_HLP_IMG'
    end
    object ElementIMAGE_HLP_IMG: TFIBBlobField
      FieldName = 'IMAGE_HLP_IMG'
      Size = 8
    end
    object ElementINDEX_HLP_IMG: TFIBIntegerField
      FieldName = 'INDEX_HLP_IMG'
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
