object DMSprVidImage: TDMSprVidImage
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
      'select svidimage.*'
      'from svidimage'
      'where svidimage.idgrp_svidimage=:PARAM_IDGRP'
      'ORDER BY svidimage.name_svidimage')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_SVIDIMAGE: TFIBLargeIntField
      FieldName = 'ID_SVIDIMAGE'
    end
    object TableIDBASE_SVIDIMAGE: TFIBLargeIntField
      FieldName = 'IDBASE_SVIDIMAGE'
    end
    object TableGID_SVIDIMAGE: TFIBWideStringField
      FieldName = 'GID_SVIDIMAGE'
      Size = 10
    end
    object TableIDGRP_SVIDIMAGE: TFIBLargeIntField
      FieldName = 'IDGRP_SVIDIMAGE'
    end
    object TableNAME_SVIDIMAGE: TFIBWideStringField
      FieldName = 'NAME_SVIDIMAGE'
      Size = 200
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SVIDIMAGE'
      'SET '
      '    IDBASE_SVIDIMAGE = :IDBASE_SVIDIMAGE,'
      '    GID_SVIDIMAGE = :GID_SVIDIMAGE,'
      '    IDGRP_SVIDIMAGE = :IDGRP_SVIDIMAGE,'
      '    NAME_SVIDIMAGE = :NAME_SVIDIMAGE'
      'WHERE'
      '    ID_SVIDIMAGE = :OLD_ID_SVIDIMAGE'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SVIDIMAGE'
      'WHERE'
      '        ID_SVIDIMAGE = :OLD_ID_SVIDIMAGE'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SVIDIMAGE('
      '    ID_SVIDIMAGE,'
      '    IDBASE_SVIDIMAGE,'
      '    GID_SVIDIMAGE,'
      '    IDGRP_SVIDIMAGE,'
      '    NAME_SVIDIMAGE'
      ')'
      'VALUES('
      '    :ID_SVIDIMAGE,'
      '    :IDBASE_SVIDIMAGE,'
      '    :GID_SVIDIMAGE,'
      '    :IDGRP_SVIDIMAGE,'
      '    :NAME_SVIDIMAGE'
      ')')
    RefreshSQL.Strings = (
      'select svidimage.*'
      'from svidimage'
      'where(  svidimage.id_svidimage=:PARAM_ID'
      '     ) and (     SVIDIMAGE.ID_SVIDIMAGE = :OLD_ID_SVIDIMAGE'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select svidimage.*'
      'from svidimage'
      'where svidimage.id_svidimage=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SVIDIMAGE'
    AutoUpdateOptions.KeyFields = 'ID_SVIDIMAGE'
    AutoUpdateOptions.GeneratorName = 'GEN_SVIDIMAGE_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object ElementID_SVIDIMAGE: TFIBLargeIntField
      FieldName = 'ID_SVIDIMAGE'
    end
    object ElementIDBASE_SVIDIMAGE: TFIBLargeIntField
      FieldName = 'IDBASE_SVIDIMAGE'
    end
    object ElementGID_SVIDIMAGE: TFIBWideStringField
      FieldName = 'GID_SVIDIMAGE'
      Size = 10
    end
    object ElementIDGRP_SVIDIMAGE: TFIBLargeIntField
      FieldName = 'IDGRP_SVIDIMAGE'
    end
    object ElementNAME_SVIDIMAGE: TFIBWideStringField
      FieldName = 'NAME_SVIDIMAGE'
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
