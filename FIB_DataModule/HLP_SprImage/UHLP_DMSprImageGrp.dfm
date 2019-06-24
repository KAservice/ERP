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
      '  hlp_img_grp'
      'order by hlp_img_grp.idgrp_hlp_img_grp')
    Transaction = IBTr
    Left = 144
    Top = 24
    poUseLargeIntField = True
    object TableID_HLP_IMG_GRP: TFIBLargeIntField
      FieldName = 'ID_HLP_IMG_GRP'
    end
    object TableIDBASE_HLP_IMG_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_HLP_IMG_GRP'
    end
    object TableGUID_HLP_IMG_GRP: TFIBWideStringField
      FieldName = 'GUID_HLP_IMG_GRP'
      Size = 38
    end
    object TablePOS_ISM_HLP_IMG_GRP: TFIBDateTimeField
      FieldName = 'POS_ISM_HLP_IMG_GRP'
    end
    object TableIDGRP_HLP_IMG_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_HLP_IMG_GRP'
    end
    object TableGUIDGRP_HLP_IMG_GRP: TFIBWideStringField
      FieldName = 'GUIDGRP_HLP_IMG_GRP'
      Size = 38
    end
    object TableNAME_HLP_IMG_GRP: TFIBWideStringField
      FieldName = 'NAME_HLP_IMG_GRP'
      Size = 200
    end
    object TableINDEX_HLP_IMG_GRP: TFIBIntegerField
      FieldName = 'INDEX_HLP_IMG_GRP'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE HLP_IMG_GRP'
      'SET '
      '    IDBASE_HLP_IMG_GRP = :IDBASE_HLP_IMG_GRP,'
      '    GUID_HLP_IMG_GRP = :GUID_HLP_IMG_GRP,'
      '    POS_ISM_HLP_IMG_GRP = :POS_ISM_HLP_IMG_GRP,'
      '    IDGRP_HLP_IMG_GRP = :IDGRP_HLP_IMG_GRP,'
      '    GUIDGRP_HLP_IMG_GRP = :GUIDGRP_HLP_IMG_GRP,'
      '    NAME_HLP_IMG_GRP = :NAME_HLP_IMG_GRP,'
      '    INDEX_HLP_IMG_GRP = :INDEX_HLP_IMG_GRP'
      'WHERE'
      '    ID_HLP_IMG_GRP = :OLD_ID_HLP_IMG_GRP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    HLP_IMG_GRP'
      'WHERE'
      '        ID_HLP_IMG_GRP = :OLD_ID_HLP_IMG_GRP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO HLP_IMG_GRP('
      '    ID_HLP_IMG_GRP,'
      '    IDBASE_HLP_IMG_GRP,'
      '    GUID_HLP_IMG_GRP,'
      '    POS_ISM_HLP_IMG_GRP,'
      '    IDGRP_HLP_IMG_GRP,'
      '    GUIDGRP_HLP_IMG_GRP,'
      '    NAME_HLP_IMG_GRP,'
      '    INDEX_HLP_IMG_GRP'
      ')'
      'VALUES('
      '    :ID_HLP_IMG_GRP,'
      '    :IDBASE_HLP_IMG_GRP,'
      '    :GUID_HLP_IMG_GRP,'
      '    :POS_ISM_HLP_IMG_GRP,'
      '    :IDGRP_HLP_IMG_GRP,'
      '    :GUIDGRP_HLP_IMG_GRP,'
      '    :NAME_HLP_IMG_GRP,'
      '    :INDEX_HLP_IMG_GRP'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from '
      '  hlp_img_grp'
      'where(  hlp_img_grp.id_hlp_img_grp=:PARAM_ID'
      
        '     ) and (     HLP_IMG_GRP.ID_HLP_IMG_GRP = :OLD_ID_HLP_IMG_GR' +
        'P'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from '
      '  hlp_img_grp'
      'where hlp_img_grp.id_hlp_img_grp=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'HLP_IMG_GRP'
    AutoUpdateOptions.KeyFields = 'ID_HLP_IMG_GRP'
    AutoUpdateOptions.GeneratorName = 'GEN_HLP_IMG_GRP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 80
    poUseLargeIntField = True
    object ElementID_HLP_IMG_GRP: TFIBLargeIntField
      FieldName = 'ID_HLP_IMG_GRP'
    end
    object ElementIDBASE_HLP_IMG_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_HLP_IMG_GRP'
    end
    object ElementGUID_HLP_IMG_GRP: TFIBWideStringField
      FieldName = 'GUID_HLP_IMG_GRP'
      Size = 38
    end
    object ElementPOS_ISM_HLP_IMG_GRP: TFIBDateTimeField
      FieldName = 'POS_ISM_HLP_IMG_GRP'
    end
    object ElementIDGRP_HLP_IMG_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_HLP_IMG_GRP'
    end
    object ElementGUIDGRP_HLP_IMG_GRP: TFIBWideStringField
      FieldName = 'GUIDGRP_HLP_IMG_GRP'
      Size = 38
    end
    object ElementNAME_HLP_IMG_GRP: TFIBWideStringField
      FieldName = 'NAME_HLP_IMG_GRP'
      Size = 200
    end
    object ElementINDEX_HLP_IMG_GRP: TFIBIntegerField
      FieldName = 'INDEX_HLP_IMG_GRP'
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
