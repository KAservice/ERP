object DMSprStorageLocation: TDMSprStorageLocation
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 330
  Width = 486
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    SelectSQL.Strings = (
      'select smhran.*'
      'from smhran'
      'where '
      '    smhran.idsklad_smhran=:PARAM_IDSKLAD  AND'
      '    smhran.idgrp_smhran=:PARAM_IDGRP'
      'order by smhran.name_smhran')
    AutoUpdateOptions.UpdateTableName = 'SNOMINETCAT'
    AutoUpdateOptions.KeyFields = 'ID_SNOMINETCAT'
    AutoUpdateOptions.GeneratorName = 'GEN_SNOMINETCAT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object TableID_SMHRAN: TFIBLargeIntField
      FieldName = 'ID_SMHRAN'
    end
    object TableIDBASE_SMHRAN: TFIBLargeIntField
      FieldName = 'IDBASE_SMHRAN'
    end
    object TableIDGRP_SMHRAN: TFIBLargeIntField
      FieldName = 'IDGRP_SMHRAN'
    end
    object TableNAME_SMHRAN: TFIBWideStringField
      FieldName = 'NAME_SMHRAN'
      Size = 200
    end
    object TableIDSKLAD_SMHRAN: TFIBLargeIntField
      FieldName = 'IDSKLAD_SMHRAN'
    end
    object TableFL_DOSTUPNO_SMHRAN: TFIBSmallIntField
      FieldName = 'FL_DOSTUPNO_SMHRAN'
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
    Left = 272
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
    Left = 272
    Top = 80
  end
  object Element: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE SMHRAN'
      'SET '
      '    IDBASE_SMHRAN = :IDBASE_SMHRAN,'
      '    IDGRP_SMHRAN = :IDGRP_SMHRAN,'
      '    NAME_SMHRAN = :NAME_SMHRAN,'
      '    IDSKLAD_SMHRAN = :IDSKLAD_SMHRAN,'
      '    FL_DOSTUPNO_SMHRAN = :FL_DOSTUPNO_SMHRAN'
      'WHERE'
      '    ID_SMHRAN = :OLD_ID_SMHRAN'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SMHRAN'
      'WHERE'
      '        ID_SMHRAN = :OLD_ID_SMHRAN'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SMHRAN('
      '    ID_SMHRAN,'
      '    IDBASE_SMHRAN,'
      '    IDGRP_SMHRAN,'
      '    NAME_SMHRAN,'
      '    IDSKLAD_SMHRAN,'
      '    FL_DOSTUPNO_SMHRAN'
      ')'
      'VALUES('
      '    :ID_SMHRAN,'
      '    :IDBASE_SMHRAN,'
      '    :IDGRP_SMHRAN,'
      '    :NAME_SMHRAN,'
      '    :IDSKLAD_SMHRAN,'
      '    :FL_DOSTUPNO_SMHRAN'
      ')')
    RefreshSQL.Strings = (
      'select *'
      'from smhran'
      'where(  smhran.id_smhran=:PARAM_ID'
      '     ) and (     SMHRAN.ID_SMHRAN = :OLD_ID_SMHRAN'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select *'
      'from smhran'
      'where smhran.id_smhran=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SMHRAN'
    AutoUpdateOptions.KeyFields = 'ID_SMHRAN'
    AutoUpdateOptions.GeneratorName = 'GEN_SMHRAN_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 80
    poUseLargeIntField = True
    object ElementID_SMHRAN: TFIBLargeIntField
      FieldName = 'ID_SMHRAN'
    end
    object ElementIDBASE_SMHRAN: TFIBLargeIntField
      FieldName = 'IDBASE_SMHRAN'
    end
    object ElementIDGRP_SMHRAN: TFIBLargeIntField
      FieldName = 'IDGRP_SMHRAN'
    end
    object ElementNAME_SMHRAN: TFIBWideStringField
      FieldName = 'NAME_SMHRAN'
      Size = 200
    end
    object ElementIDSKLAD_SMHRAN: TFIBLargeIntField
      FieldName = 'IDSKLAD_SMHRAN'
    end
    object ElementFL_DOSTUPNO_SMHRAN: TFIBSmallIntField
      FieldName = 'FL_DOSTUPNO_SMHRAN'
    end
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 48
    Top = 80
  end
end
