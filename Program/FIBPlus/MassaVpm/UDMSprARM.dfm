object DMSprARM: TDMSprARM
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 199
  Width = 280
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 48
    Top = 72
  end
  object IBTr: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 224
    Top = 16
  end
  object IBTrUpdate: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 224
    Top = 72
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from SARM')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Database = DM.pFIBData
    Left = 160
    Top = 16
    object TableCODE_SARM: TFIBIntegerField
      FieldName = 'CODE_SARM'
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_SARM: TFIBBCDField
      FieldName = 'ID_SARM'
      Size = 0
      RoundByScale = True
    end
    object TableIDFIRM_SARM: TFIBBCDField
      FieldName = 'IDFIRM_SARM'
      Size = 0
      RoundByScale = True
    end
    object TableIDSKLAD_SARM: TFIBBCDField
      FieldName = 'IDSKLAD_SARM'
      Size = 0
      RoundByScale = True
    end
    object TableIDPODR_SARM: TFIBBCDField
      FieldName = 'IDPODR_SARM'
      Size = 0
      RoundByScale = True
    end
    object TableIDKKM_SARM: TFIBBCDField
      FieldName = 'IDKKM_SARM'
      Size = 0
      RoundByScale = True
    end
    object TableGID_SARM: TFIBWideStringField
      FieldName = 'GID_SARM'
      Size = 10
    end
    object TableNAME_SARM: TFIBWideStringField
      FieldName = 'NAME_SARM'
      Size = 100
    end
    object TableSTRPAR_SARM: TFIBWideStringField
      FieldName = 'STRPAR_SARM'
      Size = 1000
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SARM'
      'SET '
      '    GID_SARM = :GID_SARM,'
      '    NAME_SARM = :NAME_SARM,'
      '    CODE_SARM = :CODE_SARM,'
      '    IDFIRM_SARM = :IDFIRM_SARM,'
      '    IDSKLAD_SARM = :IDSKLAD_SARM,'
      '    IDPODR_SARM = :IDPODR_SARM,'
      '    IDKKM_SARM = :IDKKM_SARM,'
      '    STRPAR_SARM = :STRPAR_SARM,'
      '    PREFIKS_SARM = :PREFIKS_SARM,'
      '    IDBASE_SARM = :IDBASE_SARM'
      'WHERE'
      '    ID_SARM = :OLD_ID_SARM'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SARM'
      'WHERE'
      '        ID_SARM = :OLD_ID_SARM'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SARM('
      '    ID_SARM,'
      '    GID_SARM,'
      '    NAME_SARM,'
      '    CODE_SARM,'
      '    IDFIRM_SARM,'
      '    IDSKLAD_SARM,'
      '    IDPODR_SARM,'
      '    IDKKM_SARM,'
      '    STRPAR_SARM,'
      '    PREFIKS_SARM,'
      '    IDBASE_SARM'
      ')'
      'VALUES('
      '    :ID_SARM,'
      '    :GID_SARM,'
      '    :NAME_SARM,'
      '    :CODE_SARM,'
      '    :IDFIRM_SARM,'
      '    :IDSKLAD_SARM,'
      '    :IDPODR_SARM,'
      '    :IDKKM_SARM,'
      '    :STRPAR_SARM,'
      '    :PREFIKS_SARM,'
      '    :IDBASE_SARM'
      ')')
    RefreshSQL.Strings = (
      
        'select  SARM.*, SFIRM.*, SSKLAD.*,  SKKM.*, SPOD.* , STPRICE.*, ' +
        'NAME_SINFBASE_OBMEN'
      'from '
      '  SARM '
      'left outer join SPOD on IDPODR_SARM=IDPOD'
      'left outer join  STPRICE  on  IDTPRICEPOD=ID_TPRICE'
      'left outer join SFIRM on IDFIRM_SARM=IDFIRM'
      'left outer join SSKLAD on IDSKLAD=IDSKLAD_SARM'
      'left outer join SKKM on IDKKM=IDKKM_SARM'
      'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_SARM'
      'where(  '
      '  ID_SARM=:PARAM_ID'
      '     ) and (     SARM.ID_SARM = :OLD_ID_SARM'
      '     )'
      '    ')
    SelectSQL.Strings = (
      
        'select  SARM.*, SFIRM.*, SSKLAD.*,  SKKM.*, SPOD.* , STPRICE.*, ' +
        'NAME_SINFBASE_OBMEN'
      'from '
      '  SARM '
      'left outer join SPOD on IDPODR_SARM=IDPOD'
      'left outer join  STPRICE  on  IDTPRICEPOD=ID_TPRICE'
      'left outer join SFIRM on IDFIRM_SARM=IDFIRM'
      'left outer join SSKLAD on IDSKLAD=IDSKLAD_SARM'
      'left outer join SKKM on IDKKM=IDKKM_SARM'
      'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_SARM'
      'where '
      '  ID_SARM=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SARM'
    AutoUpdateOptions.KeyFields = 'ID_SARM'
    AutoUpdateOptions.GeneratorName = 'GEN_SARM_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    Database = DM.pFIBData
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 72
    object ElementID_SARM: TFIBBCDField
      FieldName = 'ID_SARM'
      Size = 0
      RoundByScale = True
    end
    object ElementIDFIRM_SARM: TFIBBCDField
      FieldName = 'IDFIRM_SARM'
      Size = 0
      RoundByScale = True
    end
    object ElementIDSKLAD_SARM: TFIBBCDField
      FieldName = 'IDSKLAD_SARM'
      Size = 0
      RoundByScale = True
    end
    object ElementIDPODR_SARM: TFIBBCDField
      FieldName = 'IDPODR_SARM'
      Size = 0
      RoundByScale = True
    end
    object ElementIDKKM_SARM: TFIBBCDField
      FieldName = 'IDKKM_SARM'
      Size = 0
      RoundByScale = True
    end
    object ElementIDTPRICEPOD: TFIBBCDField
      FieldName = 'IDTPRICEPOD'
      Size = 0
      RoundByScale = True
    end
    object ElementIDBASE_SARM: TFIBBCDField
      FieldName = 'IDBASE_SARM'
      Size = 0
      RoundByScale = True
    end
    object ElementGID_SARM: TFIBWideStringField
      FieldName = 'GID_SARM'
      Size = 10
    end
    object ElementNAME_SARM: TFIBWideStringField
      FieldName = 'NAME_SARM'
      Size = 100
    end
    object ElementCODE_SARM: TFIBIntegerField
      FieldName = 'CODE_SARM'
    end
    object ElementSTRPAR_SARM: TFIBWideStringField
      FieldName = 'STRPAR_SARM'
      Size = 1000
    end
    object ElementNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 100
    end
    object ElementNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 100
    end
    object ElementNAMEKKM: TFIBWideStringField
      FieldName = 'NAMEKKM'
      Size = 100
    end
    object ElementNAMEPOD: TFIBWideStringField
      FieldName = 'NAMEPOD'
      Size = 100
    end
    object ElementNAME_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 100
    end
    object ElementNAME_TPRICE: TFIBWideStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
    end
  end
  object Query: TpFIBQuery
    Transaction = IBTr
    Database = DM.pFIBData
    Left = 224
    Top = 144
    qoStartTransaction = True
  end
end
