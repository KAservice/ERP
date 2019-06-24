object DMSprProducerNomGrp: TDMSprProducerNomGrp
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 193
  Width = 612
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
      'from  sprnomgrp'
      'where sprnomgrp.idprod_sprnomgrp=:PARAM_IDPRODUCER'
      'order by sprnomgrp.idgrp_sprnomgrp')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 184
    Top = 24
    poUseLargeIntField = True
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_SPRNOMGRP: TFIBLargeIntField
      FieldName = 'ID_SPRNOMGRP'
    end
    object TableIDBASE_SPRNOMGRP: TFIBLargeIntField
      FieldName = 'IDBASE_SPRNOMGRP'
    end
    object TableGID_SPRNOMGRP: TFIBWideStringField
      FieldName = 'GID_SPRNOMGRP'
      Size = 10
    end
    object TableIDGRP_SPRNOMGRP: TFIBLargeIntField
      FieldName = 'IDGRP_SPRNOMGRP'
    end
    object TableIDPROD_SPRNOMGRP: TFIBLargeIntField
      FieldName = 'IDPROD_SPRNOMGRP'
    end
    object TableNAME_SPRNOMGRP: TFIBWideStringField
      FieldName = 'NAME_SPRNOMGRP'
      Size = 200
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SPRNOMGRP'
      'SET '
      '    IDBASE_SPRNOMGRP = :IDBASE_SPRNOMGRP,'
      '    GID_SPRNOMGRP = :GID_SPRNOMGRP,'
      '    IDGRP_SPRNOMGRP = :IDGRP_SPRNOMGRP,'
      '    IDPROD_SPRNOMGRP = :IDPROD_SPRNOMGRP,'
      '    NAME_SPRNOMGRP = :NAME_SPRNOMGRP'
      'WHERE'
      '    ID_SPRNOMGRP = :OLD_ID_SPRNOMGRP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SPRNOMGRP'
      'WHERE'
      '        ID_SPRNOMGRP = :OLD_ID_SPRNOMGRP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SPRNOMGRP('
      '    ID_SPRNOMGRP,'
      '    IDBASE_SPRNOMGRP,'
      '    GID_SPRNOMGRP,'
      '    IDGRP_SPRNOMGRP,'
      '    IDPROD_SPRNOMGRP,'
      '    NAME_SPRNOMGRP'
      ')'
      'VALUES('
      '    :ID_SPRNOMGRP,'
      '    :IDBASE_SPRNOMGRP,'
      '    :GID_SPRNOMGRP,'
      '    :IDGRP_SPRNOMGRP,'
      '    :IDPROD_SPRNOMGRP,'
      '    :NAME_SPRNOMGRP'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from  sprnomgrp'
      'where(  sprnomgrp.id_sprnomgrp=:PARAM_ID'
      '     ) and (     SPRNOMGRP.ID_SPRNOMGRP = :OLD_ID_SPRNOMGRP'
      '     )'
      '    '
      '')
    SelectSQL.Strings = (
      'select * '
      'from  sprnomgrp'
      'where sprnomgrp.id_sprnomgrp=:PARAM_ID'
      '')
    AutoUpdateOptions.UpdateTableName = 'SPRNOMGRP'
    AutoUpdateOptions.KeyFields = 'ID_SPRNOMGRP'
    AutoUpdateOptions.GeneratorName = 'GEN_SPRNOMGRP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 184
    Top = 80
    poUseLargeIntField = True
    object ElementID_SPRNOMGRP: TFIBLargeIntField
      FieldName = 'ID_SPRNOMGRP'
    end
    object ElementIDBASE_SPRNOMGRP: TFIBLargeIntField
      FieldName = 'IDBASE_SPRNOMGRP'
    end
    object ElementGID_SPRNOMGRP: TFIBWideStringField
      FieldName = 'GID_SPRNOMGRP'
      Size = 10
    end
    object ElementIDGRP_SPRNOMGRP: TFIBLargeIntField
      FieldName = 'IDGRP_SPRNOMGRP'
    end
    object ElementIDPROD_SPRNOMGRP: TFIBLargeIntField
      FieldName = 'IDPROD_SPRNOMGRP'
    end
    object ElementNAME_SPRNOMGRP: TFIBWideStringField
      FieldName = 'NAME_SPRNOMGRP'
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
    Left = 248
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
    Left = 248
    Top = 80
  end
end
