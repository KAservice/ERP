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
      'select hlp_image.*'
      'from hlp_image'
      'where hlp_image.idgrp_hlp_image=:PARAM_IDGRP'
      'ORDER BY hlp_image.name_hlp_image')
    Transaction = IBTr
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_HLP_IMAGE: TFIBLargeIntField
      FieldName = 'ID_HLP_IMAGE'
    end
    object TableIDBASE_HLP_IMAGE: TFIBLargeIntField
      FieldName = 'IDBASE_HLP_IMAGE'
    end
    object TableGID_HLP_IMAGE: TFIBWideStringField
      FieldName = 'GID_HLP_IMAGE'
      Size = 10
    end
    object TableGUID_HLP_IMAGE: TFIBWideStringField
      FieldName = 'GUID_HLP_IMAGE'
      Size = 38
    end
    object TableGUIDELEMENT_HLP_IMAGE: TFIBWideStringField
      FieldName = 'GUIDELEMENT_HLP_IMAGE'
      Size = 38
    end
    object TableTEXT_HLP_IMAGE: TFIBWideStringField
      FieldName = 'TEXT_HLP_IMAGE'
      Size = 200
    end
    object TableTYPE_HLP_IMAGE: TFIBSmallIntField
      FieldName = 'TYPE_HLP_IMAGE'
    end
    object TableNAME_HLP_IMAGE: TFIBWideStringField
      FieldName = 'NAME_HLP_IMAGE'
      Size = 200
    end
    object TableIMAGE_HLP_IMAGE: TFIBBlobField
      FieldName = 'IMAGE_HLP_IMAGE'
      Size = 8
    end
    object TableGUIDGRP_HLP_IMAGE: TFIBWideStringField
      FieldName = 'GUIDGRP_HLP_IMAGE'
      Size = 38
    end
    object TableIDGRP_HLP_IMAGE: TFIBLargeIntField
      FieldName = 'IDGRP_HLP_IMAGE'
    end
    object TableHEIGHT_HLP_IMAGE: TFIBIntegerField
      FieldName = 'HEIGHT_HLP_IMAGE'
    end
    object TableWIDTH_HLP_IMAGE: TFIBIntegerField
      FieldName = 'WIDTH_HLP_IMAGE'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE HLP_IMAGE'
      'SET '
      '    IDBASE_HLP_IMAGE = :IDBASE_HLP_IMAGE,'
      '    GID_HLP_IMAGE = :GID_HLP_IMAGE,'
      '    GUID_HLP_IMAGE = :GUID_HLP_IMAGE,'
      '    GUIDELEMENT_HLP_IMAGE = :GUIDELEMENT_HLP_IMAGE,'
      '    TEXT_HLP_IMAGE = :TEXT_HLP_IMAGE,'
      '    NAME_HLP_IMAGE = :NAME_HLP_IMAGE,'
      '    IMAGE_HLP_IMAGE = :IMAGE_HLP_IMAGE,'
      '    TYPE_TBL_HLP_IMAGE = :TYPE_TBL_HLP_IMAGE,'
      '    GUIDGRP_HLP_IMAGE = :GUIDGRP_HLP_IMAGE,'
      '    IDGRP_HLP_IMAGE = :IDGRP_HLP_IMAGE,'
      '    HEIGHT_HLP_IMAGE = :HEIGHT_HLP_IMAGE,'
      '    WIDTH_HLP_IMAGE = :WIDTH_HLP_IMAGE'
      'WHERE'
      '    ID_HLP_IMAGE = :OLD_ID_HLP_IMAGE'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    HLP_IMAGE'
      'WHERE'
      '        ID_HLP_IMAGE = :OLD_ID_HLP_IMAGE'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO HLP_IMAGE('
      '    ID_HLP_IMAGE,'
      '    IDBASE_HLP_IMAGE,'
      '    GID_HLP_IMAGE,'
      '    GUID_HLP_IMAGE,'
      '    GUIDELEMENT_HLP_IMAGE,'
      '    TEXT_HLP_IMAGE,'
      '    NAME_HLP_IMAGE,'
      '    IMAGE_HLP_IMAGE,'
      '    TYPE_TBL_HLP_IMAGE,'
      '    GUIDGRP_HLP_IMAGE,'
      '    IDGRP_HLP_IMAGE,'
      '    HEIGHT_HLP_IMAGE,'
      '    WIDTH_HLP_IMAGE'
      ')'
      'VALUES('
      '    :ID_HLP_IMAGE,'
      '    :IDBASE_HLP_IMAGE,'
      '    :GID_HLP_IMAGE,'
      '    :GUID_HLP_IMAGE,'
      '    :GUIDELEMENT_HLP_IMAGE,'
      '    :TEXT_HLP_IMAGE,'
      '    :NAME_HLP_IMAGE,'
      '    :IMAGE_HLP_IMAGE,'
      '    :TYPE_TBL_HLP_IMAGE,'
      '    :GUIDGRP_HLP_IMAGE,'
      '    :IDGRP_HLP_IMAGE,'
      '    :HEIGHT_HLP_IMAGE,'
      '    :WIDTH_HLP_IMAGE'
      ')')
    RefreshSQL.Strings = (
      'select hlp_image.*'
      'from hlp_image'
      'where(  hlp_image.id_hlp_image=:PARAM_ID'
      '     ) and (     HLP_IMAGE.ID_HLP_IMAGE = :OLD_ID_HLP_IMAGE'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select hlp_image.*'
      'from hlp_image'
      'where hlp_image.id_hlp_image=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'HLP_IMAGE'
    AutoUpdateOptions.KeyFields = 'ID_HLP_IMAGE'
    AutoUpdateOptions.GeneratorName = 'GEN_HLP_IMAGE_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object ElementID_HLP_IMAGE: TFIBLargeIntField
      FieldName = 'ID_HLP_IMAGE'
    end
    object ElementIDBASE_HLP_IMAGE: TFIBLargeIntField
      FieldName = 'IDBASE_HLP_IMAGE'
    end
    object ElementGID_HLP_IMAGE: TFIBWideStringField
      FieldName = 'GID_HLP_IMAGE'
      Size = 10
    end
    object ElementGUID_HLP_IMAGE: TFIBWideStringField
      FieldName = 'GUID_HLP_IMAGE'
      Size = 38
    end
    object ElementGUIDELEMENT_HLP_IMAGE: TFIBWideStringField
      FieldName = 'GUIDELEMENT_HLP_IMAGE'
      Size = 38
    end
    object ElementTEXT_HLP_IMAGE: TFIBWideStringField
      FieldName = 'TEXT_HLP_IMAGE'
      Size = 200
    end
    object ElementTYPE_HLP_IMAGE: TFIBSmallIntField
      FieldName = 'TYPE_HLP_IMAGE'
    end
    object ElementNAME_HLP_IMAGE: TFIBWideStringField
      FieldName = 'NAME_HLP_IMAGE'
      Size = 200
    end
    object ElementIMAGE_HLP_IMAGE: TFIBBlobField
      FieldName = 'IMAGE_HLP_IMAGE'
      Size = 8
    end
    object ElementGUIDGRP_HLP_IMAGE: TFIBWideStringField
      FieldName = 'GUIDGRP_HLP_IMAGE'
      Size = 38
    end
    object ElementIDGRP_HLP_IMAGE: TFIBLargeIntField
      FieldName = 'IDGRP_HLP_IMAGE'
    end
    object ElementHEIGHT_HLP_IMAGE: TFIBIntegerField
      FieldName = 'HEIGHT_HLP_IMAGE'
    end
    object ElementWIDTH_HLP_IMAGE: TFIBIntegerField
      FieldName = 'WIDTH_HLP_IMAGE'
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
