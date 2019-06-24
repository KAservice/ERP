object DMSprNomInetCatalog: TDMSprNomInetCatalog
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 299
  Width = 406
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SNOMINETCAT'
      'SET '
      '    IDBASE_SNOMINETCAT = :IDBASE_SNOMINETCAT,'
      '    GID_SNOMINETCAT = :GID_SNOMINETCAT,'
      '    IDINETCAT_SNOMINETCAT = :IDINETCAT_SNOMINETCAT,'
      '    IDGRP_SNOMINETCAT = :IDGRP_SNOMINETCAT,'
      '    IDNOM_SNOMINETCAT = :IDNOM_SNOMINETCAT'
      'WHERE'
      '    ID_SNOMINETCAT = :OLD_ID_SNOMINETCAT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SNOMINETCAT'
      'WHERE'
      '        ID_SNOMINETCAT = :OLD_ID_SNOMINETCAT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SNOMINETCAT('
      '    ID_SNOMINETCAT,'
      '    IDBASE_SNOMINETCAT,'
      '    GID_SNOMINETCAT,'
      '    IDINETCAT_SNOMINETCAT,'
      '    IDGRP_SNOMINETCAT,'
      '    IDNOM_SNOMINETCAT'
      ')'
      'VALUES('
      '    :ID_SNOMINETCAT,'
      '    :IDBASE_SNOMINETCAT,'
      '    :GID_SNOMINETCAT,'
      '    :IDINETCAT_SNOMINETCAT,'
      '    :IDGRP_SNOMINETCAT,'
      '    :IDNOM_SNOMINETCAT'
      ')')
    RefreshSQL.Strings = (
      'select snominetcat.*,'
      '         snom.namenom,'
      '         snom.codenom,'
      '         snom.artnom,'
      '         sprice.znach_price,'
      '         sed.nameed,'
      '         sed.shed'
      'from snominetcat'
      'left outer join SNOM on snom.idnom=snominetcat.idnom_snominetcat'
      
        'left outer join SPRICE on sprice.idnom_price=snominetcat.idnom_s' +
        'nominetcat'
      
        '                            and sprice.idtype_price=:PARAM_IDTYP' +
        'E_PRICE'
      'left outer join SED on  snom.idbasednom=sed.ided'
      'where(  '
      '    snominetcat.idinetcat_snominetcat=:PARAM_IDINETCATALOG  AND'
      '    snominetcat.idgrp_snominetcat=:PARAM_IDGRP'
      
        '     ) and (     SNOMINETCAT.ID_SNOMINETCAT = :OLD_ID_SNOMINETCA' +
        'T'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select snominetcat.*,'
      '         snom.namenom,'
      '         snom.codenom,'
      '         snom.artnom,'
      '         sprice.znach_price,'
      '         sed.nameed,'
      '         sed.shed'
      'from snominetcat'
      'left outer join SNOM on snom.idnom=snominetcat.idnom_snominetcat'
      
        'left outer join SPRICE on sprice.idnom_price=snominetcat.idnom_s' +
        'nominetcat'
      
        '                            and sprice.idtype_price=:PARAM_IDTYP' +
        'E_PRICE'
      'left outer join SED on  snom.idbasednom=sed.ided'
      'where '
      '    snominetcat.idinetcat_snominetcat=:PARAM_IDINETCATALOG  AND'
      '    snominetcat.idgrp_snominetcat=:PARAM_IDGRP'
      'order by snom.namenom')
    AutoUpdateOptions.UpdateTableName = 'SNOMINETCAT'
    AutoUpdateOptions.KeyFields = 'ID_SNOMINETCAT'
    AutoUpdateOptions.GeneratorName = 'GEN_SNOMINETCAT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnCalcFields = TableCalcFields
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object TableID_SNOMINETCAT: TFIBLargeIntField
      FieldName = 'ID_SNOMINETCAT'
    end
    object TableIDBASE_SNOMINETCAT: TFIBLargeIntField
      FieldName = 'IDBASE_SNOMINETCAT'
    end
    object TableGID_SNOMINETCAT: TFIBWideStringField
      FieldName = 'GID_SNOMINETCAT'
      Size = 10
    end
    object TableIDINETCAT_SNOMINETCAT: TFIBLargeIntField
      FieldName = 'IDINETCAT_SNOMINETCAT'
    end
    object TableIDGRP_SNOMINETCAT: TFIBLargeIntField
      FieldName = 'IDGRP_SNOMINETCAT'
    end
    object TableIDNOM_SNOMINETCAT: TFIBLargeIntField
      FieldName = 'IDNOM_SNOMINETCAT'
    end
    object TableNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object TableZNACH_PRICE: TFIBBCDField
      FieldName = 'ZNACH_PRICE'
      Size = 2
      RoundByScale = True
    end
    object TableNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 200
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object TableARTNOM: TFIBWideStringField
      FieldName = 'ARTNOM'
    end
    object TableSHED: TFIBWideStringField
      FieldName = 'SHED'
      Size = 13
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
    UpdateSQL.Strings = (
      'UPDATE SNOMINETCAT'
      'SET '
      '    IDBASE_SNOMINETCAT = :IDBASE_SNOMINETCAT,'
      '    GID_SNOMINETCAT = :GID_SNOMINETCAT,'
      '    IDINETCAT_SNOMINETCAT = :IDINETCAT_SNOMINETCAT,'
      '    IDGRP_SNOMINETCAT = :IDGRP_SNOMINETCAT,'
      '    IDNOM_SNOMINETCAT = :IDNOM_SNOMINETCAT'
      'WHERE'
      '    ID_SNOMINETCAT = :OLD_ID_SNOMINETCAT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SNOMINETCAT'
      'WHERE'
      '        ID_SNOMINETCAT = :OLD_ID_SNOMINETCAT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SNOMINETCAT('
      '    ID_SNOMINETCAT,'
      '    IDBASE_SNOMINETCAT,'
      '    GID_SNOMINETCAT,'
      '    IDINETCAT_SNOMINETCAT,'
      '    IDGRP_SNOMINETCAT,'
      '    IDNOM_SNOMINETCAT'
      ')'
      'VALUES('
      '    :ID_SNOMINETCAT,'
      '    :IDBASE_SNOMINETCAT,'
      '    :GID_SNOMINETCAT,'
      '    :IDINETCAT_SNOMINETCAT,'
      '    :IDGRP_SNOMINETCAT,'
      '    :IDNOM_SNOMINETCAT'
      ')')
    RefreshSQL.Strings = (
      'select *'
      'from snominetcat'
      'where(  snominetcat.id_snominetcat=:PARAM_ID'
      
        '     ) and (     SNOMINETCAT.ID_SNOMINETCAT = :OLD_ID_SNOMINETCA' +
        'T'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select *'
      'from snominetcat'
      'where snominetcat.id_snominetcat=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SNOMINETCAT'
    AutoUpdateOptions.KeyFields = 'ID_SNOMINETCAT'
    AutoUpdateOptions.GeneratorName = 'GEN_SNOMINETCAT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 136
    poUseLargeIntField = True
    object ElementID_SNOMINETCAT: TFIBLargeIntField
      FieldName = 'ID_SNOMINETCAT'
    end
    object ElementIDBASE_SNOMINETCAT: TFIBLargeIntField
      FieldName = 'IDBASE_SNOMINETCAT'
    end
    object ElementGID_SNOMINETCAT: TFIBWideStringField
      FieldName = 'GID_SNOMINETCAT'
      Size = 10
    end
    object ElementIDINETCAT_SNOMINETCAT: TFIBLargeIntField
      FieldName = 'IDINETCAT_SNOMINETCAT'
    end
    object ElementIDGRP_SNOMINETCAT: TFIBLargeIntField
      FieldName = 'IDGRP_SNOMINETCAT'
    end
    object ElementIDNOM_SNOMINETCAT: TFIBLargeIntField
      FieldName = 'IDNOM_SNOMINETCAT'
    end
  end
end
