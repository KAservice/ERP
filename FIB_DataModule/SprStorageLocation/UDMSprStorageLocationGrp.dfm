object DMSprStorageLocationGrp: TDMSprStorageLocationGrp
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 351
  Width = 479
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
      'select * from  smhran_grp'
      'where smhran_grp.idsklad_smhran_grp=:PARAM_IDSKLAD'
      'order by smhran_grp.idgrp_smhran_grp')
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
    object TableID_SMHRAN_GRP: TFIBLargeIntField
      FieldName = 'ID_SMHRAN_GRP'
    end
    object TableIDBASE_SMHRAN_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_SMHRAN_GRP'
    end
    object TableIDGRP_SMHRAN_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_SMHRAN_GRP'
    end
    object TableNAME_SMHRAN_GRP: TFIBWideStringField
      FieldName = 'NAME_SMHRAN_GRP'
      Size = 200
    end
    object TableIDSKLAD_SMHRAN_GRP: TFIBLargeIntField
      FieldName = 'IDSKLAD_SMHRAN_GRP'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SMHRAN_GRP'
      'SET '
      '    IDBASE_SMHRAN_GRP = :IDBASE_SMHRAN_GRP,'
      '    IDGRP_SMHRAN_GRP = :IDGRP_SMHRAN_GRP,'
      '    NAME_SMHRAN_GRP = :NAME_SMHRAN_GRP,'
      '    IDSKLAD_SMHRAN_GRP = :IDSKLAD_SMHRAN_GRP'
      'WHERE'
      '    ID_SMHRAN_GRP = :OLD_ID_SMHRAN_GRP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SMHRAN_GRP'
      'WHERE'
      '        ID_SMHRAN_GRP = :OLD_ID_SMHRAN_GRP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SMHRAN_GRP('
      '    ID_SMHRAN_GRP,'
      '    IDBASE_SMHRAN_GRP,'
      '    IDGRP_SMHRAN_GRP,'
      '    NAME_SMHRAN_GRP,'
      '    IDSKLAD_SMHRAN_GRP'
      ')'
      'VALUES('
      '    :ID_SMHRAN_GRP,'
      '    :IDBASE_SMHRAN_GRP,'
      '    :IDGRP_SMHRAN_GRP,'
      '    :NAME_SMHRAN_GRP,'
      '    :IDSKLAD_SMHRAN_GRP'
      ')')
    RefreshSQL.Strings = (
      
        'select * from  smhran_grp where(  smhran_grp.id_smhran_grp=:PARA' +
        'M_ID'
      '     ) and (     SMHRAN_GRP.ID_SMHRAN_GRP = :OLD_ID_SMHRAN_GRP'
      '     )'
      '    ')
    SelectSQL.Strings = (
      
        'select * from  smhran_grp where smhran_grp.id_smhran_grp=:PARAM_' +
        'ID')
    AutoUpdateOptions.UpdateTableName = 'SMHRAN_GRP'
    AutoUpdateOptions.KeyFields = 'ID_SMHRAN_GRP'
    AutoUpdateOptions.GeneratorName = 'GEN_SMHRAN_GRP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 184
    Top = 80
    poUseLargeIntField = True
    object ElementID_SMHRAN_GRP: TFIBLargeIntField
      FieldName = 'ID_SMHRAN_GRP'
    end
    object ElementIDBASE_SMHRAN_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_SMHRAN_GRP'
    end
    object ElementIDGRP_SMHRAN_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_SMHRAN_GRP'
    end
    object ElementNAME_SMHRAN_GRP: TFIBWideStringField
      FieldName = 'NAME_SMHRAN_GRP'
      Size = 200
    end
    object ElementIDSKLAD_SMHRAN_GRP: TFIBLargeIntField
      FieldName = 'IDSKLAD_SMHRAN_GRP'
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
