object REM_DMSprKKTDv: TREM_DMSprKKTDv
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 155
  Width = 412
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 8
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 56
    Top = 80
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select rem_skkt_dv.*,'
      '    sklient.nameklient,'
      '    suser.name_user'
      'from rem_skkt_dv'
      
        'left outer join sklient on sklient.idklient=rem_skkt_dv.idklient' +
        '_rem_skkt_dv'
      
        'left outer join suser on suser.id_user=rem_skkt_dv.iduser_rem_sk' +
        'kt_dv'
      'where rem_skkt_dv.idkkt_rem_skkt_dv=:PARAM_IDOWNER'
      'order by rem_skkt_dv.pos_rem_skkt_dv')
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 8
    poUseLargeIntField = True
    object TableID_REM_SKKT_DV: TFIBLargeIntField
      FieldName = 'ID_REM_SKKT_DV'
    end
    object TableIDBASE_REM_SKKT_DV: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SKKT_DV'
    end
    object TableIDKKT_REM_SKKT_DV: TFIBLargeIntField
      FieldName = 'IDKKT_REM_SKKT_DV'
    end
    object TablePOS_REM_SKKT_DV: TFIBDateTimeField
      FieldName = 'POS_REM_SKKT_DV'
    end
    object TableIDKLIENT_REM_SKKT_DV: TFIBLargeIntField
      FieldName = 'IDKLIENT_REM_SKKT_DV'
    end
    object TableMESTOUST_REM_SKKT_DV: TFIBWideStringField
      FieldName = 'MESTOUST_REM_SKKT_DV'
      Size = 100
    end
    object TableREGNUM_REM_SKKT_DV: TFIBWideStringField
      FieldName = 'REGNUM_REM_SKKT_DV'
      Size = 15
    end
    object TableCBKGR_REM_SKKT_DV: TFIBWideStringField
      FieldName = 'CBKGR_REM_SKKT_DV'
      Size = 15
    end
    object TableCBKCO_REM_SKKT_DV: TFIBWideStringField
      FieldName = 'CBKCO_REM_SKKT_DV'
      Size = 15
    end
    object TableNUMCONTRACT_REM_SKKT_DV: TFIBWideStringField
      FieldName = 'NUMCONTRACT_REM_SKKT_DV'
      Size = 10
    end
    object TableDATECONTRACT_REM_SKKT_DV: TFIBDateField
      FieldName = 'DATECONTRACT_REM_SKKT_DV'
    end
    object TableSUMCONTRACT_REM_SKKT_DV: TFIBBCDField
      FieldName = 'SUMCONTRACT_REM_SKKT_DV'
      Size = 2
      RoundByScale = True
    end
    object TableEKLZ_SERNUM_REM_SKKT_DV: TFIBWideStringField
      FieldName = 'EKLZ_SERNUM_REM_SKKT_DV'
      Size = 15
    end
    object TableEKLZ_REGNUM_REM_SKKT_DV: TFIBWideStringField
      FieldName = 'EKLZ_REGNUM_REM_SKKT_DV'
      Size = 15
    end
    object TableEKLZ_ACT_REM_SKKT_DV: TFIBDateField
      FieldName = 'EKLZ_ACT_REM_SKKT_DV'
    end
    object TableIDUSER_REM_SKKT_DV: TFIBLargeIntField
      FieldName = 'IDUSER_REM_SKKT_DV'
    end
    object TableNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 100
    end
    object TableNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
      Size = 100
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_SKKT_DV'
      'SET '
      '    IDKKT_REM_SKKT_DV = :IDKKT_REM_SKKT_DV,'
      '    POS_REM_SKKT_DV = :POS_REM_SKKT_DV,'
      '    IDKLIENT_REM_SKKT_DV = :IDKLIENT_REM_SKKT_DV,'
      '    MESTOUST_REM_SKKT_DV = :MESTOUST_REM_SKKT_DV,'
      '    REGNUM_REM_SKKT_DV = :REGNUM_REM_SKKT_DV,'
      '    CBKGR_REM_SKKT_DV = :CBKGR_REM_SKKT_DV,'
      '    CBKCO_REM_SKKT_DV = :CBKCO_REM_SKKT_DV,'
      '    NUMCONTRACT_REM_SKKT_DV = :NUMCONTRACT_REM_SKKT_DV,'
      '    DATECONTRACT_REM_SKKT_DV = :DATECONTRACT_REM_SKKT_DV,'
      '    SUMCONTRACT_REM_SKKT_DV = :SUMCONTRACT_REM_SKKT_DV,'
      '    EKLZ_SERNUM_REM_SKKT_DV = :EKLZ_SERNUM_REM_SKKT_DV,'
      '    EKLZ_REGNUM_REM_SKKT_DV = :EKLZ_REGNUM_REM_SKKT_DV,'
      '    EKLZ_ACT_REM_SKKT_DV = :EKLZ_ACT_REM_SKKT_DV,'
      '    IDUSER_REM_SKKT_DV = :IDUSER_REM_SKKT_DV'
      'WHERE'
      '    ID_REM_SKKT_DV = :OLD_ID_REM_SKKT_DV'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_SKKT_DV'
      'WHERE'
      '        ID_REM_SKKT_DV = :OLD_ID_REM_SKKT_DV'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_SKKT_DV('
      '    ID_REM_SKKT_DV,'
      '    IDKKT_REM_SKKT_DV,'
      '    POS_REM_SKKT_DV,'
      '    IDKLIENT_REM_SKKT_DV,'
      '    MESTOUST_REM_SKKT_DV,'
      '    REGNUM_REM_SKKT_DV,'
      '    CBKGR_REM_SKKT_DV,'
      '    CBKCO_REM_SKKT_DV,'
      '    NUMCONTRACT_REM_SKKT_DV,'
      '    DATECONTRACT_REM_SKKT_DV,'
      '    SUMCONTRACT_REM_SKKT_DV,'
      '    EKLZ_SERNUM_REM_SKKT_DV,'
      '    EKLZ_REGNUM_REM_SKKT_DV,'
      '    EKLZ_ACT_REM_SKKT_DV,'
      '    IDUSER_REM_SKKT_DV'
      ')'
      'VALUES('
      '    :ID_REM_SKKT_DV,'
      '    :IDKKT_REM_SKKT_DV,'
      '    :POS_REM_SKKT_DV,'
      '    :IDKLIENT_REM_SKKT_DV,'
      '    :MESTOUST_REM_SKKT_DV,'
      '    :REGNUM_REM_SKKT_DV,'
      '    :CBKGR_REM_SKKT_DV,'
      '    :CBKCO_REM_SKKT_DV,'
      '    :NUMCONTRACT_REM_SKKT_DV,'
      '    :DATECONTRACT_REM_SKKT_DV,'
      '    :SUMCONTRACT_REM_SKKT_DV,'
      '    :EKLZ_SERNUM_REM_SKKT_DV,'
      '    :EKLZ_REGNUM_REM_SKKT_DV,'
      '    :EKLZ_ACT_REM_SKKT_DV,'
      '    :IDUSER_REM_SKKT_DV'
      ')')
    RefreshSQL.Strings = (
      'select rem_skkt_dv.*,'
      '    sklient.nameklient,'
      '    suser.name_user'
      'from rem_skkt_dv'
      
        'left outer join sklient on sklient.idklient=rem_skkt_dv.idklient' +
        '_rem_skkt_dv'
      
        'left outer join suser on suser.id_user=rem_skkt_dv.iduser_rem_sk' +
        'kt_dv'
      'where(  rem_skkt_dv.id_rem_skkt_dv=:PARAM_ID'
      
        '     ) and (     REM_SKKT_DV.ID_REM_SKKT_DV = :OLD_ID_REM_SKKT_D' +
        'V'
      '     )'
      '    '
      '')
    SelectSQL.Strings = (
      'select rem_skkt_dv.*,'
      '    sklient.nameklient,'
      '    suser.name_user'
      'from rem_skkt_dv'
      
        'left outer join sklient on sklient.idklient=rem_skkt_dv.idklient' +
        '_rem_skkt_dv'
      
        'left outer join suser on suser.id_user=rem_skkt_dv.iduser_rem_sk' +
        'kt_dv'
      'where rem_skkt_dv.id_rem_skkt_dv=:PARAM_ID'
      '')
    AutoUpdateOptions.UpdateTableName = 'REM_SKKT_DV'
    AutoUpdateOptions.KeyFields = 'ID_REM_SKKT_DV'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SKKT_DV_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 80
    poUseLargeIntField = True
    object ElementID_REM_SKKT_DV: TFIBLargeIntField
      FieldName = 'ID_REM_SKKT_DV'
    end
    object ElementIDBASE_REM_SKKT_DV: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SKKT_DV'
    end
    object ElementIDKKT_REM_SKKT_DV: TFIBLargeIntField
      FieldName = 'IDKKT_REM_SKKT_DV'
    end
    object ElementPOS_REM_SKKT_DV: TFIBDateTimeField
      FieldName = 'POS_REM_SKKT_DV'
    end
    object ElementIDKLIENT_REM_SKKT_DV: TFIBLargeIntField
      FieldName = 'IDKLIENT_REM_SKKT_DV'
    end
    object ElementMESTOUST_REM_SKKT_DV: TFIBWideStringField
      FieldName = 'MESTOUST_REM_SKKT_DV'
      Size = 100
    end
    object ElementREGNUM_REM_SKKT_DV: TFIBWideStringField
      FieldName = 'REGNUM_REM_SKKT_DV'
      Size = 15
    end
    object ElementCBKGR_REM_SKKT_DV: TFIBWideStringField
      FieldName = 'CBKGR_REM_SKKT_DV'
      Size = 15
    end
    object ElementCBKCO_REM_SKKT_DV: TFIBWideStringField
      FieldName = 'CBKCO_REM_SKKT_DV'
      Size = 15
    end
    object ElementNUMCONTRACT_REM_SKKT_DV: TFIBWideStringField
      FieldName = 'NUMCONTRACT_REM_SKKT_DV'
      Size = 10
    end
    object ElementDATECONTRACT_REM_SKKT_DV: TFIBDateField
      FieldName = 'DATECONTRACT_REM_SKKT_DV'
    end
    object ElementSUMCONTRACT_REM_SKKT_DV: TFIBBCDField
      FieldName = 'SUMCONTRACT_REM_SKKT_DV'
      Size = 2
      RoundByScale = True
    end
    object ElementEKLZ_SERNUM_REM_SKKT_DV: TFIBWideStringField
      FieldName = 'EKLZ_SERNUM_REM_SKKT_DV'
      Size = 15
    end
    object ElementEKLZ_REGNUM_REM_SKKT_DV: TFIBWideStringField
      FieldName = 'EKLZ_REGNUM_REM_SKKT_DV'
      Size = 15
    end
    object ElementEKLZ_ACT_REM_SKKT_DV: TFIBDateField
      FieldName = 'EKLZ_ACT_REM_SKKT_DV'
    end
    object ElementIDUSER_REM_SKKT_DV: TFIBLargeIntField
      FieldName = 'IDUSER_REM_SKKT_DV'
    end
    object ElementNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 100
    end
    object ElementNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
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
    Left = 264
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
    Left = 264
    Top = 80
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 344
    Top = 88
    qoStartTransaction = True
  end
end
