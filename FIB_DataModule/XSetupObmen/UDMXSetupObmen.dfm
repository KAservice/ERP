object DMXSetupObmen: TDMXSetupObmen
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 344
  Width = 317
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select  XSETUP_OBMEN.*, NAME_SINFBASE_OBMEN'
      'from XSETUP_OBMEN'
      
        'left outer join SINFBASE_OBMEN on  IDBASE_OBMEN_XSETUP_OBMEN=ID_' +
        'SINFBASE_OBMEN'
      '')
    AutoUpdateOptions.UpdateTableName = 'STYPEPRICE_OBMEN'
    AutoUpdateOptions.KeyFields = 'ID_STYPEPRICE_OBMEN'
    AutoUpdateOptions.GeneratorName = 'GEN_STYPEPRICE_OBMEN_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 128
    Top = 16
    object TableID_XSETUP_OBMEN: TFIBBCDField
      FieldName = 'ID_XSETUP_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object TableIDBASE_OBMEN_XSETUP_OBMEN: TFIBBCDField
      FieldName = 'IDBASE_OBMEN_XSETUP_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object TableIDTISM_XSETUP_OBMEN: TFIBBCDField
      FieldName = 'IDTISM_XSETUP_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object TableALLDOC_XSETUP_OBMEN: TFIBSmallIntField
      FieldName = 'ALLDOC_XSETUP_OBMEN'
    end
    object TableOUTNAC_XSETUP_OBMEN: TFIBSmallIntField
      FieldName = 'OUTNAC_XSETUP_OBMEN'
    end
    object TableOUTZPRICE_XSETUP_OBMEN: TFIBSmallIntField
      FieldName = 'OUTZPRICE_XSETUP_OBMEN'
    end
    object TableNOEDIT_XSETUP_OBMEN: TFIBSmallIntField
      FieldName = 'NOEDIT_XSETUP_OBMEN'
    end
    object TableIDBASE_XSETUP_OBMEN: TFIBBCDField
      FieldName = 'IDBASE_XSETUP_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableNAME_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 100
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
    Left = 208
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
    Left = 208
    Top = 72
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE XSETUP_OBMEN'
      'SET '
      '    IDBASE_OBMEN_XSETUP_OBMEN = :IDBASE_OBMEN_XSETUP_OBMEN,'
      '    IDTISM_XSETUP_OBMEN = :IDTISM_XSETUP_OBMEN,'
      '    ALLDOC_XSETUP_OBMEN = :ALLDOC_XSETUP_OBMEN,'
      '    OUTNAC_XSETUP_OBMEN = :OUTNAC_XSETUP_OBMEN,'
      '    OUTZPRICE_XSETUP_OBMEN = :OUTZPRICE_XSETUP_OBMEN,'
      '    NOEDIT_XSETUP_OBMEN = :NOEDIT_XSETUP_OBMEN,'
      '    IDBASE_XSETUP_OBMEN = :IDBASE_XSETUP_OBMEN,'
      '    IDFIRST_DO_XSETUP_OBMEN = :IDFIRST_DO_XSETUP_OBMEN,'
      '    OPER_XSETUP_OBMEN = :OPER_XSETUP_OBMEN'
      'WHERE'
      '    ID_XSETUP_OBMEN = :OLD_ID_XSETUP_OBMEN'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    XSETUP_OBMEN'
      'WHERE'
      '        ID_XSETUP_OBMEN = :OLD_ID_XSETUP_OBMEN'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO XSETUP_OBMEN('
      '    ID_XSETUP_OBMEN,'
      '    IDBASE_OBMEN_XSETUP_OBMEN,'
      '    IDTISM_XSETUP_OBMEN,'
      '    ALLDOC_XSETUP_OBMEN,'
      '    OUTNAC_XSETUP_OBMEN,'
      '    OUTZPRICE_XSETUP_OBMEN,'
      '    NOEDIT_XSETUP_OBMEN,'
      '    IDBASE_XSETUP_OBMEN,'
      '    IDFIRST_DO_XSETUP_OBMEN,'
      '    OPER_XSETUP_OBMEN'
      ')'
      'VALUES('
      '    :ID_XSETUP_OBMEN,'
      '    :IDBASE_OBMEN_XSETUP_OBMEN,'
      '    :IDTISM_XSETUP_OBMEN,'
      '    :ALLDOC_XSETUP_OBMEN,'
      '    :OUTNAC_XSETUP_OBMEN,'
      '    :OUTZPRICE_XSETUP_OBMEN,'
      '    :NOEDIT_XSETUP_OBMEN,'
      '    :IDBASE_XSETUP_OBMEN,'
      '    :IDFIRST_DO_XSETUP_OBMEN,'
      '    :OPER_XSETUP_OBMEN'
      ')')
    RefreshSQL.Strings = (
      'select  XSETUP_OBMEN.*, NAME_SINFBASE_OBMEN'
      'from XSETUP_OBMEN'
      
        'left outer join SINFBASE_OBMEN on  IDBASE_OBMEN_XSETUP_OBMEN=ID_' +
        'SINFBASE_OBMEN'
      'where(  IDBASE_OBMEN_XSETUP_OBMEN=:PARAM_IDBASE'
      
        '     ) and (     XSETUP_OBMEN.ID_XSETUP_OBMEN = :OLD_ID_XSETUP_O' +
        'BMEN'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select  XSETUP_OBMEN.*, NAME_SINFBASE_OBMEN'
      'from XSETUP_OBMEN'
      
        'left outer join SINFBASE_OBMEN on  IDBASE_OBMEN_XSETUP_OBMEN=ID_' +
        'SINFBASE_OBMEN'
      'where IDBASE_OBMEN_XSETUP_OBMEN=:PARAM_IDBASE')
    AutoUpdateOptions.UpdateTableName = 'XSETUP_OBMEN'
    AutoUpdateOptions.KeyFields = 'ID_XSETUP_OBMEN'
    AutoUpdateOptions.GeneratorName = 'GEN_XSETUP_OBMEN_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 224
    Top = 136
    object ElementID_XSETUP_OBMEN: TFIBBCDField
      FieldName = 'ID_XSETUP_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object ElementIDBASE_OBMEN_XSETUP_OBMEN: TFIBBCDField
      FieldName = 'IDBASE_OBMEN_XSETUP_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object ElementIDTISM_XSETUP_OBMEN: TFIBBCDField
      FieldName = 'IDTISM_XSETUP_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object ElementALLDOC_XSETUP_OBMEN: TFIBSmallIntField
      FieldName = 'ALLDOC_XSETUP_OBMEN'
    end
    object ElementOUTNAC_XSETUP_OBMEN: TFIBSmallIntField
      FieldName = 'OUTNAC_XSETUP_OBMEN'
    end
    object ElementOUTZPRICE_XSETUP_OBMEN: TFIBSmallIntField
      FieldName = 'OUTZPRICE_XSETUP_OBMEN'
    end
    object ElementNOEDIT_XSETUP_OBMEN: TFIBSmallIntField
      FieldName = 'NOEDIT_XSETUP_OBMEN'
    end
    object ElementIDBASE_XSETUP_OBMEN: TFIBBCDField
      FieldName = 'IDBASE_XSETUP_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object ElementIDFIRST_DO_XSETUP_OBMEN: TFIBBCDField
      FieldName = 'IDFIRST_DO_XSETUP_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object ElementOPER_XSETUP_OBMEN: TFIBIntegerField
      FieldName = 'OPER_XSETUP_OBMEN'
    end
    object ElementNAME_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 100
    end
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 80
    Top = 136
  end
  object BaseForObmen: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE XBASE_FOR_OBMEN'
      'SET '
      
        '    IDBASE_OBMEN_XBASE_FOR_OBMEN = :IDBASE_OBMEN_XBASE_FOR_OBMEN' +
        ','
      
        '    IDBASE_OBJECT_XBASE_FOR_OBMEN = :IDBASE_OBJECT_XBASE_FOR_OBM' +
        'EN,'
      '    IDBASE_XBASE_FOR_OBMEN = :IDBASE_XBASE_FOR_OBMEN'
      'WHERE'
      '    ID_XBASE_FOR_OBMEN = :OLD_ID_XBASE_FOR_OBMEN'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    XBASE_FOR_OBMEN'
      'WHERE'
      '        ID_XBASE_FOR_OBMEN = :OLD_ID_XBASE_FOR_OBMEN'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO XBASE_FOR_OBMEN('
      '    ID_XBASE_FOR_OBMEN,'
      '    IDBASE_OBMEN_XBASE_FOR_OBMEN,'
      '    IDBASE_OBJECT_XBASE_FOR_OBMEN,'
      '    IDBASE_XBASE_FOR_OBMEN'
      ')'
      'VALUES('
      '    :ID_XBASE_FOR_OBMEN,'
      '    :IDBASE_OBMEN_XBASE_FOR_OBMEN,'
      '    :IDBASE_OBJECT_XBASE_FOR_OBMEN,'
      '    :IDBASE_XBASE_FOR_OBMEN'
      ')')
    RefreshSQL.Strings = (
      'select XBASE_FOR_OBMEN.*, NAME_SINFBASE_OBMEN'
      'from XBASE_FOR_OBMEN'
      
        'left outer join SINFBASE_OBMEN on IDBASE_OBJECT_XBASE_FOR_OBMEN=' +
        'ID_SINFBASE_OBMEN'
      'where(  IDBASE_OBMEN_XBASE_FOR_OBMEN=:IDBASE_OBMEN_XSETUP_OBMEN'
      
        '     ) and (     XBASE_FOR_OBMEN.ID_XBASE_FOR_OBMEN = :OLD_ID_XB' +
        'ASE_FOR_OBMEN'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select XBASE_FOR_OBMEN.*, NAME_SINFBASE_OBMEN'
      'from XBASE_FOR_OBMEN'
      
        'left outer join SINFBASE_OBMEN on IDBASE_OBJECT_XBASE_FOR_OBMEN=' +
        'ID_SINFBASE_OBMEN'
      'where IDBASE_OBMEN_XBASE_FOR_OBMEN=:IDBASE_OBMEN_XSETUP_OBMEN')
    AutoUpdateOptions.UpdateTableName = 'XBASE_FOR_OBMEN'
    AutoUpdateOptions.KeyFields = 'ID_XBASE_FOR_OBMEN'
    AutoUpdateOptions.GeneratorName = 'GEN_XBASE_FOR_OBMEN_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = BaseForObmenNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    DataSource = DataSourceElement
    Left = 224
    Top = 200
    object BaseForObmenID_XBASE_FOR_OBMEN: TFIBBCDField
      FieldName = 'ID_XBASE_FOR_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object BaseForObmenIDBASE_OBMEN_XBASE_FOR_OBMEN: TFIBBCDField
      FieldName = 'IDBASE_OBMEN_XBASE_FOR_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object BaseForObmenIDBASE_OBJECT_XBASE_FOR_OBMEN: TFIBBCDField
      FieldName = 'IDBASE_OBJECT_XBASE_FOR_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object BaseForObmenIDBASE_XBASE_FOR_OBMEN: TFIBBCDField
      FieldName = 'IDBASE_XBASE_FOR_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object BaseForObmenNAME_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 100
    end
  end
  object TypePriceForObmen: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE XTPRICE_FOR_OBMEN'
      'SET '
      
        '    IDBASE_OBMEN_XTPRICE_FOR_OBMEN = :IDBASE_OBMEN_XTPRICE_FOR_O' +
        'BMEN,'
      '    IDTPRICE_XTPRICE_FOR_OBMEN = :IDTPRICE_XTPRICE_FOR_OBMEN,'
      '    IDBASE_XTPRICE_FOR_OBMEN = :IDBASE_XTPRICE_FOR_OBMEN'
      'WHERE'
      '    ID_XTPRICE_FOR_OBMEN = :OLD_ID_XTPRICE_FOR_OBMEN'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    XTPRICE_FOR_OBMEN'
      'WHERE'
      '        ID_XTPRICE_FOR_OBMEN = :OLD_ID_XTPRICE_FOR_OBMEN'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO XTPRICE_FOR_OBMEN('
      '    ID_XTPRICE_FOR_OBMEN,'
      '    IDBASE_OBMEN_XTPRICE_FOR_OBMEN,'
      '    IDTPRICE_XTPRICE_FOR_OBMEN,'
      '    IDBASE_XTPRICE_FOR_OBMEN'
      ')'
      'VALUES('
      '    :ID_XTPRICE_FOR_OBMEN,'
      '    :IDBASE_OBMEN_XTPRICE_FOR_OBMEN,'
      '    :IDTPRICE_XTPRICE_FOR_OBMEN,'
      '    :IDBASE_XTPRICE_FOR_OBMEN'
      ')')
    RefreshSQL.Strings = (
      'select XTPRICE_FOR_OBMEN.*, NAME_TPRICE '
      'from XTPRICE_FOR_OBMEN'
      'left outer join sTPRICE on IDTPRICE_XTPRICE_FOR_OBMEN=ID_TPRICE'
      
        'where(  IDBASE_OBMEN_XTPRICE_FOR_OBMEN=:IDBASE_OBMEN_XSETUP_OBME' +
        'N'
      
        '     ) and (     XTPRICE_FOR_OBMEN.ID_XTPRICE_FOR_OBMEN = :OLD_I' +
        'D_XTPRICE_FOR_OBMEN'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select XTPRICE_FOR_OBMEN.*, NAME_TPRICE '
      'from XTPRICE_FOR_OBMEN'
      'left outer join sTPRICE on IDTPRICE_XTPRICE_FOR_OBMEN=ID_TPRICE'
      'where IDBASE_OBMEN_XTPRICE_FOR_OBMEN=:IDBASE_OBMEN_XSETUP_OBMEN')
    AutoUpdateOptions.UpdateTableName = 'XTPRICE_FOR_OBMEN'
    AutoUpdateOptions.KeyFields = 'ID_XTPRICE_FOR_OBMEN'
    AutoUpdateOptions.GeneratorName = 'GEN_XTPRICE_FOR_OBMEN_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = TypePriceForObmenNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    DataSource = DataSourceElement
    Left = 232
    Top = 264
    object TypePriceForObmenID_XTPRICE_FOR_OBMEN: TFIBBCDField
      FieldName = 'ID_XTPRICE_FOR_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object TypePriceForObmenIDBASE_OBMEN_XTPRICE_FOR_OBMEN: TFIBBCDField
      FieldName = 'IDBASE_OBMEN_XTPRICE_FOR_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object TypePriceForObmenIDTPRICE_XTPRICE_FOR_OBMEN: TFIBBCDField
      FieldName = 'IDTPRICE_XTPRICE_FOR_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object TypePriceForObmenIDBASE_XTPRICE_FOR_OBMEN: TFIBBCDField
      FieldName = 'IDBASE_XTPRICE_FOR_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object TypePriceForObmenNAME_TPRICE: TFIBWideStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
    end
  end
  object DataSourceBaseForObmen: TDataSource
    DataSet = BaseForObmen
    Left = 80
    Top = 200
  end
  object DataSourceTypePriceForObmen: TDataSource
    DataSet = TypePriceForObmen
    Left = 80
    Top = 264
  end
end
