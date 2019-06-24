object DMGurPlat: TDMGurPlat
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 263
  Width = 375
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 48
    Top = 112
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select '
      'GURNALPLAT.*,'
      '     NAME_USER, NAMEKLIENT,'
      '          scodetel.name_codetel, '
      '          scodetel.codoper_codetel'
      'from '
      'GURNALPLAT'
      'left outer join SUSER on  IDUSER_GURNALPLAT= ID_USER'
      'left outer join SKLIENT on IDKLIENT_GURNALPLAT=IDKLIENT'
      
        'left outer join scodetel on GURNALPLAT.idcodetel_gurnalplat=scod' +
        'etel.id_codetel'
      
        'where POS_GURNALPLAT between  :PARAM_DATE_NACH and :PARAM_DATE_C' +
        'ON '
      'order by POS_GURNALPLAT'
      ''
      '')
    Transaction = IBTr
    Left = 136
    Top = 16
    poUseLargeIntField = True
    object TableID_GURNALPLAT: TFIBLargeIntField
      FieldName = 'ID_GURNALPLAT'
    end
    object TableGID_GURNALPLAT: TFIBWideStringField
      FieldName = 'GID_GURNALPLAT'
      Size = 10
    end
    object TableCODE_GURNALPLAT: TFIBWideStringField
      FieldName = 'CODE_GURNALPLAT'
      Size = 3
    end
    object TableNUMTEL_GURNALPLAT: TFIBWideStringField
      FieldName = 'NUMTEL_GURNALPLAT'
      Size = 7
    end
    object TableNUMKV_GURNALPLAT: TFIBIntegerField
      FieldName = 'NUMKV_GURNALPLAT'
    end
    object TablePOS_GURNALPLAT: TFIBDateTimeField
      FieldName = 'POS_GURNALPLAT'
    end
    object TableIDUSER_GURNALPLAT: TFIBLargeIntField
      FieldName = 'IDUSER_GURNALPLAT'
    end
    object TableSUM_GURNALPLAT: TFIBBCDField
      FieldName = 'SUM_GURNALPLAT'
      Size = 2
      RoundByScale = True
    end
    object TableOUT_GURNALPLAT: TFIBSmallIntField
      FieldName = 'OUT_GURNALPLAT'
    end
    object TableCODOPER_GURNALPLAT: TFIBWideStringField
      FieldName = 'CODOPER_GURNALPLAT'
      Size = 5
    end
    object TableSUMKL_GURNALPLAT: TFIBBCDField
      FieldName = 'SUMKL_GURNALPLAT'
      Size = 2
      RoundByScale = True
    end
    object TablePROCENT_COMMISSION_GURNALPLAT: TFIBBCDField
      FieldName = 'PROCENT_COMMISSION_GURNALPLAT'
      Size = 2
      RoundByScale = True
    end
    object TableIDKLIENT_GURNALPLAT: TFIBLargeIntField
      FieldName = 'IDKLIENT_GURNALPLAT'
    end
    object TableIDBASE_GURNALPLAT: TFIBLargeIntField
      FieldName = 'IDBASE_GURNALPLAT'
    end
    object TableIDOPERATOR_GURNALPLAT: TFIBLargeIntField
      FieldName = 'IDOPERATOR_GURNALPLAT'
    end
    object TableIDCODETEL_GURNALPLAT: TFIBLargeIntField
      FieldName = 'IDCODETEL_GURNALPLAT'
    end
    object TableNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
      Size = 200
    end
    object TableNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 200
    end
    object TableNAME_CODETEL: TFIBWideStringField
      FieldName = 'NAME_CODETEL'
      Size = 200
    end
    object TableCODOPER_CODETEL: TFIBWideStringField
      FieldName = 'CODOPER_CODETEL'
      Size = 5
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
    Top = 16
  end
  object Element: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE GURNALPLAT'
      'SET '
      '    GID_GURNALPLAT = :GID_GURNALPLAT,'
      '    CODE_GURNALPLAT = :CODE_GURNALPLAT,'
      '    NUMTEL_GURNALPLAT = :NUMTEL_GURNALPLAT,'
      '    NUMKV_GURNALPLAT = :NUMKV_GURNALPLAT,'
      '    POS_GURNALPLAT = :POS_GURNALPLAT,'
      '    IDUSER_GURNALPLAT = :IDUSER_GURNALPLAT,'
      '    SUM_GURNALPLAT = :SUM_GURNALPLAT,'
      '    OUT_GURNALPLAT = :OUT_GURNALPLAT,'
      '    CODOPER_GURNALPLAT = :CODOPER_GURNALPLAT,'
      '    SUMKL_GURNALPLAT = :SUMKL_GURNALPLAT,'
      
        '    PROCENT_COMMISSION_GURNALPLAT = :PROCENT_COMMISSION_GURNALPL' +
        'AT,'
      '    IDKLIENT_GURNALPLAT = :IDKLIENT_GURNALPLAT,'
      '    IDBASE_GURNALPLAT = :IDBASE_GURNALPLAT,'
      '    IDOPERATOR_GURNALPLAT = :IDOPERATOR_GURNALPLAT,'
      '    IDCODETEL_GURNALPLAT = :IDCODETEL_GURNALPLAT'
      'WHERE'
      '    ID_GURNALPLAT = :OLD_ID_GURNALPLAT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    GURNALPLAT'
      'WHERE'
      '        ID_GURNALPLAT = :OLD_ID_GURNALPLAT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO GURNALPLAT('
      '    ID_GURNALPLAT,'
      '    GID_GURNALPLAT,'
      '    CODE_GURNALPLAT,'
      '    NUMTEL_GURNALPLAT,'
      '    NUMKV_GURNALPLAT,'
      '    POS_GURNALPLAT,'
      '    IDUSER_GURNALPLAT,'
      '    SUM_GURNALPLAT,'
      '    OUT_GURNALPLAT,'
      '    CODOPER_GURNALPLAT,'
      '    SUMKL_GURNALPLAT,'
      '    PROCENT_COMMISSION_GURNALPLAT,'
      '    IDKLIENT_GURNALPLAT,'
      '    IDBASE_GURNALPLAT,'
      '    IDOPERATOR_GURNALPLAT,'
      '    IDCODETEL_GURNALPLAT'
      ')'
      'VALUES('
      '    :ID_GURNALPLAT,'
      '    :GID_GURNALPLAT,'
      '    :CODE_GURNALPLAT,'
      '    :NUMTEL_GURNALPLAT,'
      '    :NUMKV_GURNALPLAT,'
      '    :POS_GURNALPLAT,'
      '    :IDUSER_GURNALPLAT,'
      '    :SUM_GURNALPLAT,'
      '    :OUT_GURNALPLAT,'
      '    :CODOPER_GURNALPLAT,'
      '    :SUMKL_GURNALPLAT,'
      '    :PROCENT_COMMISSION_GURNALPLAT,'
      '    :IDKLIENT_GURNALPLAT,'
      '    :IDBASE_GURNALPLAT,'
      '    :IDOPERATOR_GURNALPLAT,'
      '    :IDCODETEL_GURNALPLAT'
      ')')
    RefreshSQL.Strings = (
      'select GURNALPLAT.*,'
      '          NAME_USER,'
      '          NAMEKLIENT,'
      '          scodetel.name_codetel, '
      '          scodetel.codoper_codetel'
      'from '
      'GURNALPLAT'
      'left outer join SUSER on  ID_USER=IDUSER_GURNALPLAT'
      'left outer join SKLIENT on IDKLIENT_GURNALPLAT=IDKLIENT'
      
        'left outer join scodetel on GURNALPLAT.idcodetel_gurnalplat=scod' +
        'etel.id_codetel'
      'where( '
      ' ID_GURNALPLAT=:PARAM_ID'
      '     ) and (     GURNALPLAT.ID_GURNALPLAT = :OLD_ID_GURNALPLAT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select GURNALPLAT.*,'
      '          NAME_USER,'
      '          NAMEKLIENT,'
      '          scodetel.name_codetel, '
      '          scodetel.codoper_codetel'
      'from '
      'GURNALPLAT'
      'left outer join SUSER on  ID_USER=IDUSER_GURNALPLAT'
      'left outer join SKLIENT on IDKLIENT_GURNALPLAT=IDKLIENT'
      
        'left outer join scodetel on GURNALPLAT.idcodetel_gurnalplat=scod' +
        'etel.id_codetel'
      'where'
      ' ID_GURNALPLAT=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'GURNALPLAT'
    AutoUpdateOptions.KeyFields = 'ID_GURNALPLAT'
    AutoUpdateOptions.GeneratorName = 'GEN_GURNALPLAT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 136
    Top = 112
    poUseLargeIntField = True
    object ElementID_GURNALPLAT: TFIBLargeIntField
      FieldName = 'ID_GURNALPLAT'
    end
    object ElementGID_GURNALPLAT: TFIBWideStringField
      FieldName = 'GID_GURNALPLAT'
      Size = 10
    end
    object ElementCODE_GURNALPLAT: TFIBWideStringField
      FieldName = 'CODE_GURNALPLAT'
      Size = 3
    end
    object ElementNUMTEL_GURNALPLAT: TFIBWideStringField
      FieldName = 'NUMTEL_GURNALPLAT'
      Size = 7
    end
    object ElementNUMKV_GURNALPLAT: TFIBIntegerField
      FieldName = 'NUMKV_GURNALPLAT'
    end
    object ElementPOS_GURNALPLAT: TFIBDateTimeField
      FieldName = 'POS_GURNALPLAT'
    end
    object ElementIDUSER_GURNALPLAT: TFIBLargeIntField
      FieldName = 'IDUSER_GURNALPLAT'
    end
    object ElementSUM_GURNALPLAT: TFIBBCDField
      FieldName = 'SUM_GURNALPLAT'
      Size = 2
      RoundByScale = True
    end
    object ElementOUT_GURNALPLAT: TFIBSmallIntField
      FieldName = 'OUT_GURNALPLAT'
    end
    object ElementCODOPER_GURNALPLAT: TFIBWideStringField
      FieldName = 'CODOPER_GURNALPLAT'
      Size = 5
    end
    object ElementSUMKL_GURNALPLAT: TFIBBCDField
      FieldName = 'SUMKL_GURNALPLAT'
      Size = 2
      RoundByScale = True
    end
    object ElementPROCENT_COMMISSION_GURNALPLAT: TFIBBCDField
      FieldName = 'PROCENT_COMMISSION_GURNALPLAT'
      Size = 2
      RoundByScale = True
    end
    object ElementIDKLIENT_GURNALPLAT: TFIBLargeIntField
      FieldName = 'IDKLIENT_GURNALPLAT'
    end
    object ElementIDBASE_GURNALPLAT: TFIBLargeIntField
      FieldName = 'IDBASE_GURNALPLAT'
    end
    object ElementIDOPERATOR_GURNALPLAT: TFIBLargeIntField
      FieldName = 'IDOPERATOR_GURNALPLAT'
    end
    object ElementIDCODETEL_GURNALPLAT: TFIBLargeIntField
      FieldName = 'IDCODETEL_GURNALPLAT'
    end
    object ElementNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
      Size = 200
    end
    object ElementNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 200
    end
    object ElementNAME_CODETEL: TFIBWideStringField
      FieldName = 'NAME_CODETEL'
      Size = 200
    end
    object ElementCODOPER_CODETEL: TFIBWideStringField
      FieldName = 'CODOPER_CODETEL'
      Size = 5
    end
  end
  object IBQ: TpFIBDataSet
    SelectSQL.Strings = (
      'select IDDOC , TDOC'
      ''
      'from GALLDOC'
      'where IDDOGDOC=:PARAM_IDDOG')
    Transaction = IBTr
    Left = 136
    Top = 168
  end
  object IBTrUpdate: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 216
    Top = 64
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 192
    Top = 168
    qoStartTransaction = True
  end
  object GurPlat: TpFIBDataSet
    SelectSQL.Strings = (
      'select  ID_GURNALPLAT from GURNALPLAT order by POS_GURNALPLAT')
    Transaction = IBTr
    Left = 272
    Top = 168
    poUseLargeIntField = True
    object GurPlatID_GURNALPLAT: TFIBLargeIntField
      FieldName = 'ID_GURNALPLAT'
    end
  end
end
