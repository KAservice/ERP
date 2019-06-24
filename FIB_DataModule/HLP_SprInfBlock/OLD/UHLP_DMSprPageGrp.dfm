object HLP_DMSprPageGrp: THLP_DMSprPageGrp
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
      '  hlp_page_grp'
      'order by hlp_page_grp.idgrp_hlp_page_grp')
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
    object TableID_HLP_PAGE_GRP: TFIBLargeIntField
      FieldName = 'ID_HLP_PAGE_GRP'
    end
    object TableIDBASE_HLP_PAGE_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_HLP_PAGE_GRP'
    end
    object TableGID_HLP_PAGE_GRP: TFIBWideStringField
      FieldName = 'GID_HLP_PAGE_GRP'
      Size = 10
    end
    object TableGUID_HLP_PAGE_GRP: TFIBWideStringField
      FieldName = 'GUID_HLP_PAGE_GRP'
      Size = 38
    end
    object TableIDGRP_HLP_PAGE_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_HLP_PAGE_GRP'
    end
    object TableNAME_HLP_PAGE_GRP: TFIBWideStringField
      FieldName = 'NAME_HLP_PAGE_GRP'
      Size = 200
    end
    object TableINDEX_HLP_PAGE_GRP: TFIBIntegerField
      FieldName = 'INDEX_HLP_PAGE_GRP'
    end
    object TableGUIDGRP_HLP_PAGE_GRP: TFIBWideStringField
      FieldName = 'GUIDGRP_HLP_PAGE_GRP'
      Size = 38
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE HLP_PAGE_GRP'
      'SET '
      '    IDBASE_HLP_PAGE_GRP = :IDBASE_HLP_PAGE_GRP,'
      '    GID_HLP_PAGE_GRP = :GID_HLP_PAGE_GRP,'
      '    GUID_HLP_PAGE_GRP = :GUID_HLP_PAGE_GRP,'
      '    IDGRP_HLP_PAGE_GRP = :IDGRP_HLP_PAGE_GRP,'
      '    NAME_HLP_PAGE_GRP = :NAME_HLP_PAGE_GRP,'
      '    INDEX_HLP_PAGE_GRP = :INDEX_HLP_PAGE_GRP,'
      '    GUIDGRP_HLP_PAGE_GRP = :GUIDGRP_HLP_PAGE_GRP'
      'WHERE'
      '    ID_HLP_PAGE_GRP = :OLD_ID_HLP_PAGE_GRP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    HLP_PAGE_GRP'
      'WHERE'
      '        ID_HLP_PAGE_GRP = :OLD_ID_HLP_PAGE_GRP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO HLP_PAGE_GRP('
      '    ID_HLP_PAGE_GRP,'
      '    IDBASE_HLP_PAGE_GRP,'
      '    GID_HLP_PAGE_GRP,'
      '    GUID_HLP_PAGE_GRP,'
      '    IDGRP_HLP_PAGE_GRP,'
      '    NAME_HLP_PAGE_GRP,'
      '    INDEX_HLP_PAGE_GRP,'
      '    GUIDGRP_HLP_PAGE_GRP'
      ')'
      'VALUES('
      '    :ID_HLP_PAGE_GRP,'
      '    :IDBASE_HLP_PAGE_GRP,'
      '    :GID_HLP_PAGE_GRP,'
      '    :GUID_HLP_PAGE_GRP,'
      '    :IDGRP_HLP_PAGE_GRP,'
      '    :NAME_HLP_PAGE_GRP,'
      '    :INDEX_HLP_PAGE_GRP,'
      '    :GUIDGRP_HLP_PAGE_GRP'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from '
      '  hlp_page_grp'
      'where(  hlp_page_grp.guid_hlp_page_grp=:PARAM_GUID'
      
        '     ) and (     HLP_PAGE_GRP.ID_HLP_PAGE_GRP = :OLD_ID_HLP_PAGE' +
        '_GRP'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from '
      '  hlp_page_grp'
      'where hlp_page_grp.id_hlp_page_grp=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'HLP_PAGE_GRP'
    AutoUpdateOptions.KeyFields = 'ID_HLP_PAGE_GRP'
    AutoUpdateOptions.GeneratorName = 'GEN_HLP_PAGE_GRP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 80
    poUseLargeIntField = True
    object ElementID_HLP_PAGE_GRP: TFIBLargeIntField
      FieldName = 'ID_HLP_PAGE_GRP'
    end
    object ElementIDBASE_HLP_PAGE_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_HLP_PAGE_GRP'
    end
    object ElementGID_HLP_PAGE_GRP: TFIBWideStringField
      FieldName = 'GID_HLP_PAGE_GRP'
      Size = 10
    end
    object ElementGUID_HLP_PAGE_GRP: TFIBWideStringField
      FieldName = 'GUID_HLP_PAGE_GRP'
      Size = 38
    end
    object ElementIDGRP_HLP_PAGE_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_HLP_PAGE_GRP'
    end
    object ElementNAME_HLP_PAGE_GRP: TFIBWideStringField
      FieldName = 'NAME_HLP_PAGE_GRP'
      Size = 200
    end
    object ElementINDEX_HLP_PAGE_GRP: TFIBIntegerField
      FieldName = 'INDEX_HLP_PAGE_GRP'
    end
    object ElementGUIDGRP_HLP_PAGE_GRP: TFIBWideStringField
      FieldName = 'GUIDGRP_HLP_PAGE_GRP'
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
    Left = 216
    Top = 24
  end
  object IBTrUpdate: TpFIBTransaction
    TimeoutAction = TARollback
    Left = 216
    Top = 80
  end
  object pFIBQ: TpFIBQuery
    Left = 272
    Top = 56
    qoStartTransaction = True
  end
end
