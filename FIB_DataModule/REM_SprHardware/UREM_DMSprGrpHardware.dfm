object REM_DMSprGrpHardware: TREM_DMSprGrpHardware
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 224
  Width = 345
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
      '  REM_SGRP_HARDWARE'
      'order by IDGRP_REM_SGRP_HARDWARE')
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
    object TableID_REM_SGRP_HARDWARE: TFIBLargeIntField
      FieldName = 'ID_REM_SGRP_HARDWARE'
    end
    object TableIDBASE_REM_SGRP_HARDWARE: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SGRP_HARDWARE'
    end
    object TableNAME_REM_SGRP_HARDWARE: TFIBWideStringField
      FieldName = 'NAME_REM_SGRP_HARDWARE'
      Size = 100
    end
    object TableIDGRP_REM_SGRP_HARDWARE: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SGRP_HARDWARE'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_SGRP_HARDWARE'
      'SET '
      '    IDBASE_REM_SGRP_HARDWARE = :IDBASE_REM_SGRP_HARDWARE,'
      '    NAME_REM_SGRP_HARDWARE = :NAME_REM_SGRP_HARDWARE,'
      '    IDGRP_REM_SGRP_HARDWARE = :IDGRP_REM_SGRP_HARDWARE'
      'WHERE'
      '    ID_REM_SGRP_HARDWARE = :OLD_ID_REM_SGRP_HARDWARE'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_SGRP_HARDWARE'
      'WHERE'
      '        ID_REM_SGRP_HARDWARE = :OLD_ID_REM_SGRP_HARDWARE'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_SGRP_HARDWARE('
      '    ID_REM_SGRP_HARDWARE,'
      '    IDBASE_REM_SGRP_HARDWARE,'
      '    NAME_REM_SGRP_HARDWARE,'
      '    IDGRP_REM_SGRP_HARDWARE'
      ')'
      'VALUES('
      '    :ID_REM_SGRP_HARDWARE,'
      '    :IDBASE_REM_SGRP_HARDWARE,'
      '    :NAME_REM_SGRP_HARDWARE,'
      '    :IDGRP_REM_SGRP_HARDWARE'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from REM_SGRP_HARDWARE '
      'where(  ID_REM_SGRP_HARDWARE=:PARAM_ID'
      
        '     ) and (     REM_SGRP_HARDWARE.ID_REM_SGRP_HARDWARE = :OLD_I' +
        'D_REM_SGRP_HARDWARE'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from REM_SGRP_HARDWARE '
      'where ID_REM_SGRP_HARDWARE=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_SGRP_HARDWARE'
    AutoUpdateOptions.KeyFields = 'ID_REM_SGRP_HARDWARE'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SGRP_HARDWARE_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 80
    poUseLargeIntField = True
    object ElementID_REM_SGRP_HARDWARE: TFIBLargeIntField
      FieldName = 'ID_REM_SGRP_HARDWARE'
    end
    object ElementIDBASE_REM_SGRP_HARDWARE: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SGRP_HARDWARE'
    end
    object ElementNAME_REM_SGRP_HARDWARE: TFIBWideStringField
      FieldName = 'NAME_REM_SGRP_HARDWARE'
      Size = 100
    end
    object ElementIDGRP_REM_SGRP_HARDWARE: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SGRP_HARDWARE'
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
