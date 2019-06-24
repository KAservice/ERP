object ART_DMSprImage: TART_DMSprImage
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
      'select art_img.*'
      'from art_img'
      'where art_img.idgrp_art_img=:PARAM_IDGRP'
      'ORDER BY art_img.name_art_img')
    Transaction = IBTr
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object TableID_ART_IMG: TFIBLargeIntField
      FieldName = 'ID_ART_IMG'
    end
    object TableIDBASE_ART_IMG: TFIBLargeIntField
      FieldName = 'IDBASE_ART_IMG'
    end
    object TableGUID_ART_IMG: TFIBWideStringField
      FieldName = 'GUID_ART_IMG'
      Size = 38
    end
    object TablePOS_ISM_ART_IMG: TFIBDateTimeField
      FieldName = 'POS_ISM_ART_IMG'
    end
    object TableIDGRP_ART_IMG: TFIBLargeIntField
      FieldName = 'IDGRP_ART_IMG'
    end
    object TableGUIDGRP_ART_IMG: TFIBWideStringField
      FieldName = 'GUIDGRP_ART_IMG'
      Size = 38
    end
    object TableNAME_ART_IMG: TFIBWideStringField
      FieldName = 'NAME_ART_IMG'
      Size = 200
    end
    object TableTEXT_ART_IMG: TFIBWideStringField
      FieldName = 'TEXT_ART_IMG'
      Size = 200
    end
    object TableHEIGHT_ART_IMG: TFIBIntegerField
      FieldName = 'HEIGHT_ART_IMG'
    end
    object TableWIDTH_ART_IMG: TFIBIntegerField
      FieldName = 'WIDTH_ART_IMG'
    end
    object TableIMAGE_ART_IMG: TFIBBlobField
      FieldName = 'IMAGE_ART_IMG'
      Size = 8
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE ART_IMG'
      'SET '
      '    IDBASE_ART_IMG = :IDBASE_ART_IMG,'
      '    GUID_ART_IMG = :GUID_ART_IMG,'
      '    POS_ISM_ART_IMG = :POS_ISM_ART_IMG,'
      '    IDGRP_ART_IMG = :IDGRP_ART_IMG,'
      '    GUIDGRP_ART_IMG = :GUIDGRP_ART_IMG,'
      '    NAME_ART_IMG = :NAME_ART_IMG,'
      '    TEXT_ART_IMG = :TEXT_ART_IMG,'
      '    HEIGHT_ART_IMG = :HEIGHT_ART_IMG,'
      '    WIDTH_ART_IMG = :WIDTH_ART_IMG,'
      '    IMAGE_ART_IMG = :IMAGE_ART_IMG'
      'WHERE'
      '    ID_ART_IMG = :OLD_ID_ART_IMG'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    ART_IMG'
      'WHERE'
      '        ID_ART_IMG = :OLD_ID_ART_IMG'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO ART_IMG('
      '    ID_ART_IMG,'
      '    IDBASE_ART_IMG,'
      '    GUID_ART_IMG,'
      '    POS_ISM_ART_IMG,'
      '    IDGRP_ART_IMG,'
      '    GUIDGRP_ART_IMG,'
      '    NAME_ART_IMG,'
      '    TEXT_ART_IMG,'
      '    HEIGHT_ART_IMG,'
      '    WIDTH_ART_IMG,'
      '    IMAGE_ART_IMG'
      ')'
      'VALUES('
      '    :ID_ART_IMG,'
      '    :IDBASE_ART_IMG,'
      '    :GUID_ART_IMG,'
      '    :POS_ISM_ART_IMG,'
      '    :IDGRP_ART_IMG,'
      '    :GUIDGRP_ART_IMG,'
      '    :NAME_ART_IMG,'
      '    :TEXT_ART_IMG,'
      '    :HEIGHT_ART_IMG,'
      '    :WIDTH_ART_IMG,'
      '    :IMAGE_ART_IMG'
      ')')
    RefreshSQL.Strings = (
      'select art_img.*'
      'from art_img'
      'where(  art_img.id_art_img=:PARAM_ID'
      '     ) and (     ART_IMG.ID_ART_IMG = :OLD_ID_ART_IMG'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select art_img.*'
      'from art_img'
      'where art_img.id_art_img=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'ART_IMG'
    AutoUpdateOptions.KeyFields = 'ID_ART_IMG'
    AutoUpdateOptions.GeneratorName = 'GEN_ART_IMG_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object ElementID_ART_IMG: TFIBLargeIntField
      FieldName = 'ID_ART_IMG'
    end
    object ElementIDBASE_ART_IMG: TFIBLargeIntField
      FieldName = 'IDBASE_ART_IMG'
    end
    object ElementGUID_ART_IMG: TFIBWideStringField
      FieldName = 'GUID_ART_IMG'
      Size = 38
    end
    object ElementPOS_ISM_ART_IMG: TFIBDateTimeField
      FieldName = 'POS_ISM_ART_IMG'
    end
    object ElementIDGRP_ART_IMG: TFIBLargeIntField
      FieldName = 'IDGRP_ART_IMG'
    end
    object ElementGUIDGRP_ART_IMG: TFIBWideStringField
      FieldName = 'GUIDGRP_ART_IMG'
      Size = 38
    end
    object ElementNAME_ART_IMG: TFIBWideStringField
      FieldName = 'NAME_ART_IMG'
      Size = 200
    end
    object ElementTEXT_ART_IMG: TFIBWideStringField
      FieldName = 'TEXT_ART_IMG'
      Size = 200
    end
    object ElementHEIGHT_ART_IMG: TFIBIntegerField
      FieldName = 'HEIGHT_ART_IMG'
    end
    object ElementWIDTH_ART_IMG: TFIBIntegerField
      FieldName = 'WIDTH_ART_IMG'
    end
    object ElementIMAGE_ART_IMG: TFIBBlobField
      FieldName = 'IMAGE_ART_IMG'
      Size = 8
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
