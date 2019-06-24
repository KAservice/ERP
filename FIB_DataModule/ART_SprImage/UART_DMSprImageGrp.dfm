object ART_DMSprImageGrp: TART_DMSprImageGrp
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 332
  Width = 372
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 64
    Top = 24
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 64
    Top = 80
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select * '
      'from '
      '  art_img_grp'
      'order by art_img_grp.idgrp_art_img_grp')
    Transaction = IBTr
    Left = 144
    Top = 24
    poUseLargeIntField = True
    object TableID_ART_IMG_GRP: TFIBLargeIntField
      FieldName = 'ID_ART_IMG_GRP'
    end
    object TableIDBASE_ART_IMG_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_ART_IMG_GRP'
    end
    object TableGUID_ART_IMG_GRP: TFIBWideStringField
      FieldName = 'GUID_ART_IMG_GRP'
      Size = 38
    end
    object TablePOS_ISM_ART_IMG_GRP: TFIBDateTimeField
      FieldName = 'POS_ISM_ART_IMG_GRP'
    end
    object TableIDGRP_ART_IMG_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_ART_IMG_GRP'
    end
    object TableGUIDGRP_ART_IMG_GRP: TFIBWideStringField
      FieldName = 'GUIDGRP_ART_IMG_GRP'
      Size = 38
    end
    object TableNAME_ART_IMG_GRP: TFIBWideStringField
      FieldName = 'NAME_ART_IMG_GRP'
      Size = 200
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE ART_IMG_GRP'
      'SET '
      '    IDBASE_ART_IMG_GRP = :IDBASE_ART_IMG_GRP,'
      '    GUID_ART_IMG_GRP = :GUID_ART_IMG_GRP,'
      '    POS_ISM_ART_IMG_GRP = :POS_ISM_ART_IMG_GRP,'
      '    IDGRP_ART_IMG_GRP = :IDGRP_ART_IMG_GRP,'
      '    GUIDGRP_ART_IMG_GRP = :GUIDGRP_ART_IMG_GRP,'
      '    NAME_ART_IMG_GRP = :NAME_ART_IMG_GRP'
      'WHERE'
      '    ID_ART_IMG_GRP = :OLD_ID_ART_IMG_GRP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    ART_IMG_GRP'
      'WHERE'
      '        ID_ART_IMG_GRP = :OLD_ID_ART_IMG_GRP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO ART_IMG_GRP('
      '    ID_ART_IMG_GRP,'
      '    IDBASE_ART_IMG_GRP,'
      '    GUID_ART_IMG_GRP,'
      '    POS_ISM_ART_IMG_GRP,'
      '    IDGRP_ART_IMG_GRP,'
      '    GUIDGRP_ART_IMG_GRP,'
      '    NAME_ART_IMG_GRP'
      ')'
      'VALUES('
      '    :ID_ART_IMG_GRP,'
      '    :IDBASE_ART_IMG_GRP,'
      '    :GUID_ART_IMG_GRP,'
      '    :POS_ISM_ART_IMG_GRP,'
      '    :IDGRP_ART_IMG_GRP,'
      '    :GUIDGRP_ART_IMG_GRP,'
      '    :NAME_ART_IMG_GRP'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from '
      '  art_img_grp'
      'where(  art_img_grp.id_art_img_grp=:PARAM_ID'
      
        '     ) and (     ART_IMG_GRP.ID_ART_IMG_GRP = :OLD_ID_ART_IMG_GR' +
        'P'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from '
      '  art_img_grp'
      'where art_img_grp.id_art_img_grp=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'ART_IMG_GRP'
    AutoUpdateOptions.KeyFields = 'ID_ART_IMG_GRP'
    AutoUpdateOptions.GeneratorName = 'GEN_ART_IMG_GRP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 80
    poUseLargeIntField = True
    object ElementID_ART_IMG_GRP: TFIBLargeIntField
      FieldName = 'ID_ART_IMG_GRP'
    end
    object ElementIDBASE_ART_IMG_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_ART_IMG_GRP'
    end
    object ElementGUID_ART_IMG_GRP: TFIBWideStringField
      FieldName = 'GUID_ART_IMG_GRP'
      Size = 38
    end
    object ElementPOS_ISM_ART_IMG_GRP: TFIBDateTimeField
      FieldName = 'POS_ISM_ART_IMG_GRP'
    end
    object ElementIDGRP_ART_IMG_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_ART_IMG_GRP'
    end
    object ElementGUIDGRP_ART_IMG_GRP: TFIBWideStringField
      FieldName = 'GUIDGRP_ART_IMG_GRP'
      Size = 38
    end
    object ElementNAME_ART_IMG_GRP: TFIBWideStringField
      FieldName = 'NAME_ART_IMG_GRP'
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
    Left = 216
    Top = 24
  end
  object IBTrUpdate: TpFIBTransaction
    TimeoutAction = TARollback
    Left = 216
    Top = 80
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 272
    Top = 56
    qoStartTransaction = True
  end
end
