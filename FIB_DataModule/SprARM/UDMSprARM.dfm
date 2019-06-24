object DMSprARM: TDMSprARM
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 273
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
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_SARM: TFIBLargeIntField
      FieldName = 'ID_SARM'
    end
    object TableGID_SARM: TFIBWideStringField
      FieldName = 'GID_SARM'
      Size = 10
    end
    object TableNAME_SARM: TFIBWideStringField
      FieldName = 'NAME_SARM'
      Size = 200
    end
    object TableCODE_SARM: TFIBIntegerField
      FieldName = 'CODE_SARM'
    end
    object TableIDFIRM_SARM: TFIBLargeIntField
      FieldName = 'IDFIRM_SARM'
    end
    object TableIDSKLAD_SARM: TFIBLargeIntField
      FieldName = 'IDSKLAD_SARM'
    end
    object TableIDPODR_SARM: TFIBLargeIntField
      FieldName = 'IDPODR_SARM'
    end
    object TableIDKKM_SARM: TFIBLargeIntField
      FieldName = 'IDKKM_SARM'
    end
    object TableSTRPAR_SARM: TFIBWideStringField
      FieldName = 'STRPAR_SARM'
      Size = 1000
    end
    object TablePREFIKS_SARM: TFIBWideStringField
      FieldName = 'PREFIKS_SARM'
      Size = 2
    end
    object TableIDBASE_SARM: TFIBLargeIntField
      FieldName = 'IDBASE_SARM'
    end
    object TableIDACTCATEGORY_SARM: TFIBLargeIntField
      FieldName = 'IDACTCATEGORY_SARM'
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
      '    IDBASE_SARM = :IDBASE_SARM,'
      '    IDACTCATEGORY_SARM = :IDACTCATEGORY_SARM'
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
      '    IDBASE_SARM,'
      '    IDACTCATEGORY_SARM'
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
      '    :IDBASE_SARM,'
      '    :IDACTCATEGORY_SARM'
      ')')
    RefreshSQL.Strings = (
      
        'select  SARM.*, SFIRM.*, SSKLAD.*,  SKKM.*, SPOD.* , STPRICE.*, ' +
        'NAME_SINFBASE_OBMEN,'
      '    rem_sactcategory.name_rem_sactcategory'
      'from '
      '  SARM '
      'left outer join SPOD on IDPODR_SARM=IDPOD'
      'left outer join  STPRICE  on  IDTPRICEPOD=ID_TPRICE'
      'left outer join SFIRM on IDFIRM_SARM=IDFIRM'
      'left outer join SSKLAD on IDSKLAD=IDSKLAD_SARM'
      'left outer join SKKM on IDKKM=IDKKM_SARM'
      'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_SARM'
      
        'left outer join rem_sactcategory on sarm.idactcategory_sarm=rem_' +
        'sactcategory.id_rem_sactcategory'
      'where(  '
      '  ID_SARM=:PARAM_ID'
      '     ) and (     SARM.ID_SARM = :OLD_ID_SARM'
      '     )'
      '    ')
    SelectSQL.Strings = (
      
        'select  SARM.*, SFIRM.*, SSKLAD.*,  SKKM.*, SPOD.* , STPRICE.*, ' +
        'NAME_SINFBASE_OBMEN,'
      '    rem_sactcategory.name_rem_sactcategory'
      'from '
      '  SARM '
      'left outer join SPOD on IDPODR_SARM=IDPOD'
      'left outer join  STPRICE  on  IDTPRICEPOD=ID_TPRICE'
      'left outer join SFIRM on IDFIRM_SARM=IDFIRM'
      'left outer join SSKLAD on IDSKLAD=IDSKLAD_SARM'
      'left outer join SKKM on IDKKM=IDKKM_SARM'
      'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_SARM'
      
        'left outer join rem_sactcategory on sarm.idactcategory_sarm=rem_' +
        'sactcategory.id_rem_sactcategory'
      'where '
      '  ID_SARM=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SARM'
    AutoUpdateOptions.KeyFields = 'ID_SARM'
    AutoUpdateOptions.GeneratorName = 'GEN_SARM_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 72
    poUseLargeIntField = True
    object ElementID_SARM: TFIBLargeIntField
      FieldName = 'ID_SARM'
    end
    object ElementGID_SARM: TFIBWideStringField
      FieldName = 'GID_SARM'
      Size = 10
    end
    object ElementNAME_SARM: TFIBWideStringField
      FieldName = 'NAME_SARM'
      Size = 200
    end
    object ElementCODE_SARM: TFIBIntegerField
      FieldName = 'CODE_SARM'
    end
    object ElementIDFIRM_SARM: TFIBLargeIntField
      FieldName = 'IDFIRM_SARM'
    end
    object ElementIDSKLAD_SARM: TFIBLargeIntField
      FieldName = 'IDSKLAD_SARM'
    end
    object ElementIDPODR_SARM: TFIBLargeIntField
      FieldName = 'IDPODR_SARM'
    end
    object ElementIDKKM_SARM: TFIBLargeIntField
      FieldName = 'IDKKM_SARM'
    end
    object ElementSTRPAR_SARM: TFIBWideStringField
      FieldName = 'STRPAR_SARM'
      Size = 1000
    end
    object ElementPREFIKS_SARM: TFIBWideStringField
      FieldName = 'PREFIKS_SARM'
      Size = 2
    end
    object ElementIDBASE_SARM: TFIBLargeIntField
      FieldName = 'IDBASE_SARM'
    end
    object ElementIDACTCATEGORY_SARM: TFIBLargeIntField
      FieldName = 'IDACTCATEGORY_SARM'
    end
    object ElementNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 200
    end
    object ElementNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 200
    end
    object ElementNAMEKKM: TFIBWideStringField
      FieldName = 'NAMEKKM'
      Size = 200
    end
    object ElementNAMEPOD: TFIBWideStringField
      FieldName = 'NAMEPOD'
      Size = 200
    end
    object ElementIDTPRICEPOD: TFIBLargeIntField
      FieldName = 'IDTPRICEPOD'
    end
    object ElementNAME_TPRICE: TFIBWideStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
    end
    object ElementNAME_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 200
    end
    object ElementNAME_REM_SACTCATEGORY: TFIBWideStringField
      FieldName = 'NAME_REM_SACTCATEGORY'
      Size = 200
    end
  end
  object Query: TpFIBQuery
    Transaction = IBTr
    Left = 224
    Top = 144
    qoStartTransaction = True
  end
end
