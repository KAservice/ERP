object DMSprBVNom: TDMSprBVNom
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 189
  Width = 343
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object DataSourcePodr: TDataSource
    AutoEdit = False
    DataSet = Podr
    Left = 48
    Top = 72
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SBVNOM'
      'SET '
      '    IDPOD_BVNOM = :IDPOD_BVNOM,'
      '    IDNOM_BVNOM = :IDNOM_BVNOM,'
      '    IDGRP_BVNOM = :IDGRP_BVNOM,'
      '    CODE_BVNOM = :CODE_BVNOM,'
      '    GID_SBVNOM = :GID_SBVNOM'
      'WHERE'
      '    ID_BVNOM = :OLD_ID_BVNOM'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SBVNOM'
      'WHERE'
      '        ID_BVNOM = :OLD_ID_BVNOM'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SBVNOM('
      '    ID_BVNOM,'
      '    IDPOD_BVNOM,'
      '    IDNOM_BVNOM,'
      '    IDGRP_BVNOM,'
      '    CODE_BVNOM,'
      '    GID_SBVNOM'
      ')'
      'VALUES('
      '    :ID_BVNOM,'
      '    :IDPOD_BVNOM,'
      '    :IDNOM_BVNOM,'
      '    :IDGRP_BVNOM,'
      '    :CODE_BVNOM,'
      '    :GID_SBVNOM'
      ')')
    RefreshSQL.Strings = (
      'select SBVNOM.*,  NAMENOM,  ZNACH_PRICE, NAMEED'
      ''
      '   from SBVNOM'
      ''
      'left outer join SNOM on IDNOM_BVNOM=IDNOM'
      ''
      
        'left outer join SPRICE on IDNOM_PRICE=IDNOM_BVNOM  AND IDTYPE_PR' +
        'ICE=:PARAM_IDTYPE_PRICE'
      ''
      'left outer join SED on  IDBASEDNOM=IDED'
      ''
      'where(  '
      'IDPOD_BVNOM=:IDPOD'
      ' AND '
      'IDGRP_BVNOM=:IDGRP'
      '     ) and (     SBVNOM.ID_BVNOM = :OLD_ID_BVNOM'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select SBVNOM.*,  NAMENOM,  ZNACH_PRICE, NAMEED'
      ''
      '   from SBVNOM'
      ''
      'left outer join SNOM on IDNOM_BVNOM=IDNOM'
      ''
      
        'left outer join SPRICE on IDNOM_PRICE=IDNOM_BVNOM  AND IDTYPE_PR' +
        'ICE=:PARAM_IDTYPE_PRICE'
      ''
      'left outer join SED on  IDBASEDNOM=IDED'
      ''
      'where '
      'IDPOD_BVNOM=:IDPOD'
      ' AND '
      'IDGRP_BVNOM=:IDGRP'
      'order by NAMENOM')
    AutoUpdateOptions.UpdateTableName = 'SBVNOM'
    AutoUpdateOptions.KeyFields = 'ID_BVNOM'
    AutoUpdateOptions.GeneratorName = 'GEN_SBVNOM_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnCalcFields = TableCalcFields
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 16
    object TableCODE_BVNOM: TFIBIntegerField
      FieldName = 'CODE_BVNOM'
    end
    object TableZNACH_PRICE: TFIBBCDField
      FieldName = 'ZNACH_PRICE'
      Size = 2
      RoundByScale = True
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_BVNOM: TFIBBCDField
      FieldName = 'ID_BVNOM'
      Size = 0
      RoundByScale = True
    end
    object TableIDPOD_BVNOM: TFIBBCDField
      FieldName = 'IDPOD_BVNOM'
      Size = 0
      RoundByScale = True
    end
    object TableIDNOM_BVNOM: TFIBBCDField
      FieldName = 'IDNOM_BVNOM'
      Size = 0
      RoundByScale = True
    end
    object TableIDGRP_BVNOM: TFIBBCDField
      FieldName = 'IDGRP_BVNOM'
      Size = 0
      RoundByScale = True
    end
    object TableGID_SBVNOM: TFIBWideStringField
      FieldName = 'GID_SBVNOM'
      Size = 10
    end
    object TableNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 100
    end
    object TableNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
    end
  end
  object Podr: TpFIBDataSet
    SelectSQL.Strings = (
      'select SPOD.* , NAME_TPRICE'
      'from '
      '  SPOD left outer join STPRICE on IDTPRICEPOD= ID_TPRICE'
      'where '
      '  IDPOD=:PARAM_IDPOD')
    Transaction = IBTr
    Left = 160
    Top = 72
    object PodrIDPOD: TFIBBCDField
      FieldName = 'IDPOD'
      Size = 0
      RoundByScale = True
    end
    object PodrIDTPRICEPOD: TFIBBCDField
      FieldName = 'IDTPRICEPOD'
      Size = 0
      RoundByScale = True
    end
    object PodrNAMEPOD: TFIBWideStringField
      FieldName = 'NAMEPOD'
      Size = 100
    end
    object PodrNAME_TPRICE: TFIBWideStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
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
    Top = 72
  end
  object Element: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      'from SBVNOM'
      'where ID_BVNOM=:PARAM_ID')
    Transaction = IBTr
    Left = 160
    Top = 120
    object ElementCODE_BVNOM: TFIBIntegerField
      FieldName = 'CODE_BVNOM'
    end
    object ElementID_BVNOM: TFIBBCDField
      FieldName = 'ID_BVNOM'
      Size = 0
      RoundByScale = True
    end
    object ElementIDPOD_BVNOM: TFIBBCDField
      FieldName = 'IDPOD_BVNOM'
      Size = 0
      RoundByScale = True
    end
    object ElementIDNOM_BVNOM: TFIBBCDField
      FieldName = 'IDNOM_BVNOM'
      Size = 0
      RoundByScale = True
    end
    object ElementIDGRP_BVNOM: TFIBBCDField
      FieldName = 'IDGRP_BVNOM'
      Size = 0
      RoundByScale = True
    end
    object ElementGID_SBVNOM: TFIBWideStringField
      FieldName = 'GID_SBVNOM'
      Size = 10
    end
  end
end
