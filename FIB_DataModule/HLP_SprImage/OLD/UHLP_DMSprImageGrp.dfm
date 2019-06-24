object HLP_DMSprImageGrp: THLP_DMSprImageGrp
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
      '  hlp_image_grp'
      'order by hlp_image_grp.idgrp_hlp_image_grp')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 144
    Top = 24
    poUseLargeIntField = True
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_HLP_IMAGE_GRP: TFIBLargeIntField
      FieldName = 'ID_HLP_IMAGE_GRP'
    end
    object TableIDBASE_HLP_IMAGE_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_HLP_IMAGE_GRP'
    end
    object TableGID_HLP_IMAGE_GRP: TFIBWideStringField
      FieldName = 'GID_HLP_IMAGE_GRP'
      Size = 10
    end
    object TableGUID_HLP_IMAGE_GRP: TFIBWideStringField
      FieldName = 'GUID_HLP_IMAGE_GRP'
      Size = 38
    end
    object TableIDGRP_HLP_IMAGE_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_HLP_IMAGE_GRP'
    end
    object TableGUIDGRP_HLP_IMAGE_GRP: TFIBWideStringField
      FieldName = 'GUIDGRP_HLP_IMAGE_GRP'
      Size = 38
    end
    object TableNAME_HLP_IMAGE_GRP: TFIBWideStringField
      FieldName = 'NAME_HLP_IMAGE_GRP'
      Size = 200
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE HLP_IMAGE_GRP'
      'SET '
      '    IDBASE_HLP_IMAGE_GRP = :IDBASE_HLP_IMAGE_GRP,'
      '    GID_HLP_IMAGE_GRP = :GID_HLP_IMAGE_GRP,'
      '    GUID_HLP_IMAGE_GRP = :GUID_HLP_IMAGE_GRP,'
      '    IDGRP_HLP_IMAGE_GRP = :IDGRP_HLP_IMAGE_GRP,'
      '    GUIDGRP_HLP_IMAGE_GRP = :GUIDGRP_HLP_IMAGE_GRP,'
      '    NAME_HLP_IMAGE_GRP = :NAME_HLP_IMAGE_GRP'
      'WHERE'
      '    ID_HLP_IMAGE_GRP = :OLD_ID_HLP_IMAGE_GRP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    HLP_IMAGE_GRP'
      'WHERE'
      '        ID_HLP_IMAGE_GRP = :OLD_ID_HLP_IMAGE_GRP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO HLP_IMAGE_GRP('
      '    ID_HLP_IMAGE_GRP,'
      '    IDBASE_HLP_IMAGE_GRP,'
      '    GID_HLP_IMAGE_GRP,'
      '    GUID_HLP_IMAGE_GRP,'
      '    IDGRP_HLP_IMAGE_GRP,'
      '    GUIDGRP_HLP_IMAGE_GRP,'
      '    NAME_HLP_IMAGE_GRP'
      ')'
      'VALUES('
      '    :ID_HLP_IMAGE_GRP,'
      '    :IDBASE_HLP_IMAGE_GRP,'
      '    :GID_HLP_IMAGE_GRP,'
      '    :GUID_HLP_IMAGE_GRP,'
      '    :IDGRP_HLP_IMAGE_GRP,'
      '    :GUIDGRP_HLP_IMAGE_GRP,'
      '    :NAME_HLP_IMAGE_GRP'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from '
      '  hlp_image_grp'
      'where(  hlp_image_grp.id_hlp_image_grp=:PARAM_ID'
      
        '     ) and (     HLP_IMAGE_GRP.ID_HLP_IMAGE_GRP = :OLD_ID_HLP_IM' +
        'AGE_GRP'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from '
      '  hlp_image_grp'
      'where hlp_image_grp.id_hlp_image_grp=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'HLP_IMAGE_GRP'
    AutoUpdateOptions.KeyFields = 'ID_HLP_IMAGE_GRP'
    AutoUpdateOptions.GeneratorName = 'GEN_HLP_IMAGE_GRP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 80
    poUseLargeIntField = True
    object ElementID_HLP_IMAGE_GRP: TFIBLargeIntField
      FieldName = 'ID_HLP_IMAGE_GRP'
    end
    object ElementIDBASE_HLP_IMAGE_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_HLP_IMAGE_GRP'
    end
    object ElementGID_HLP_IMAGE_GRP: TFIBWideStringField
      FieldName = 'GID_HLP_IMAGE_GRP'
      Size = 10
    end
    object ElementGUID_HLP_IMAGE_GRP: TFIBWideStringField
      FieldName = 'GUID_HLP_IMAGE_GRP'
      Size = 38
    end
    object ElementIDGRP_HLP_IMAGE_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_HLP_IMAGE_GRP'
    end
    object ElementGUIDGRP_HLP_IMAGE_GRP: TFIBWideStringField
      FieldName = 'GUIDGRP_HLP_IMAGE_GRP'
      Size = 38
    end
    object ElementNAME_HLP_IMAGE_GRP: TFIBWideStringField
      FieldName = 'NAME_HLP_IMAGE_GRP'
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
