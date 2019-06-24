object REM_DMSprKKT: TREM_DMSprKKT
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 221
  Width = 371
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 8
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 56
    Top = 64
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select'
      '    rem_skkt.id_rem_skkt,'
      '    rem_skkt.name_rem_skkt,'
      '    rem_skkt.sernum_rem_skkt,'
      '    rem_smodel.name_rem_smodel,'
      '    rem_skkt.mestoust_rem_skkt,'
      '    rem_skkt.idgrp_rem_skkt'
      'from rem_skkt'
      
        'left outer join rem_smodel on rem_smodel.id_rem_smodel=rem_skkt.' +
        'idmodel_rem_skkt'
      'where rem_skkt.idgrp_rem_skkt=:PARAM_IDGRP'
      'ORDER BY rem_skkt.name_rem_skkt')
    Transaction = IBTr
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object TableID_REM_SKKT: TFIBLargeIntField
      FieldName = 'ID_REM_SKKT'
    end
    object TableNAME_REM_SKKT: TFIBWideStringField
      FieldName = 'NAME_REM_SKKT'
      Size = 100
    end
    object TableSERNUM_REM_SKKT: TFIBWideStringField
      FieldName = 'SERNUM_REM_SKKT'
      Size = 15
    end
    object TableNAME_REM_SMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SMODEL'
      Size = 100
    end
    object TableMESTOUST_REM_SKKT: TFIBWideStringField
      FieldName = 'MESTOUST_REM_SKKT'
      Size = 100
    end
    object TableIDGRP_REM_SKKT: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SKKT'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_SKKT'
      'SET '
      '    IDBASE_REM_SKKT = :IDBASE_REM_SKKT,'
      '    NAME_REM_SKKT = :NAME_REM_SKKT,'
      '    SERNUM_REM_SKKT = :SERNUM_REM_SKKT,'
      '    IDMODEL_REM_SKKT = :IDMODEL_REM_SKKT,'
      '    REGNUM_REM_SKKT = :REGNUM_REM_SKKT,'
      '    IDKLIENT_REM_SKKT = :IDKLIENT_REM_SKKT,'
      '    MESTOUST_REM_SKKT = :MESTOUST_REM_SKKT,'
      '    RELEASE_REM_SKKT = :RELEASE_REM_SKKT,'
      '    VVOD_REM_SKKT = :VVOD_REM_SKKT,'
      '    CBKGR_REM_SKKT = :CBKGR_REM_SKKT,'
      '    CBKCO_REM_SKKT = :CBKCO_REM_SKKT,'
      '    NUMCONTRACT_REM_SKKT = :NUMCONTRACT_REM_SKKT,'
      '    DATECONTRACT_REM_SKKT = :DATECONTRACT_REM_SKKT,'
      '    SUMCONTRACT_REM_SKKT = :SUMCONTRACT_REM_SKKT,'
      '    EKLZ_SERNUM_REM_SKKT = :EKLZ_SERNUM_REM_SKKT,'
      '    EKLZ_REGNUM_REM_SKKT = :EKLZ_REGNUM_REM_SKKT,'
      '    EKLZ_ACT_REM_SKKT = :EKLZ_ACT_REM_SKKT,'
      '    PAS_NUMVER_REM_SKKT = :PAS_NUMVER_REM_SKKT,'
      '    PAS_NUMPAS_REM_SKKT = :PAS_NUMPAS_REM_SKKT,'
      '    PAS_NUMPU_REM_SKKT = :PAS_NUMPU_REM_SKKT,'
      '    PAS_NUMSP_REM_SKKT = :PAS_NUMSP_REM_SKKT,'
      '    PAS_NUMSPPO_REM_SKKT = :PAS_NUMSPPO_REM_SKKT,'
      '    PAS_NUMFP_REM_SKKT = :PAS_NUMFP_REM_SKKT,'
      '    PAS_NUMFPPO_REM_SKKT = :PAS_NUMFPPO_REM_SKKT,'
      '    PAS_NUMDO_REM_SKKT = :PAS_NUMDO_REM_SKKT,'
      '    PAS_NUMDOPO_REM_SKKT = :PAS_NUMDOPO_REM_SKKT,'
      '    PAS_NUMPPP_REM_SKKT = :PAS_NUMPPP_REM_SKKT,'
      '    PAS_DOR_REM_SKKT = :PAS_DOR_REM_SKKT,'
      '    PAS_PRIM_REM_SKKT = :PAS_PRIM_REM_SKKT,'
      '    IDGRP_REM_SKKT = :IDGRP_REM_SKKT,'
      '    PRIM_REM_SKKT = :PRIM_REM_SKKT'
      'WHERE'
      '    ID_REM_SKKT = :OLD_ID_REM_SKKT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_SKKT'
      'WHERE'
      '        ID_REM_SKKT = :OLD_ID_REM_SKKT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_SKKT('
      '    ID_REM_SKKT,'
      '    IDBASE_REM_SKKT,'
      '    NAME_REM_SKKT,'
      '    SERNUM_REM_SKKT,'
      '    IDMODEL_REM_SKKT,'
      '    REGNUM_REM_SKKT,'
      '    IDKLIENT_REM_SKKT,'
      '    MESTOUST_REM_SKKT,'
      '    RELEASE_REM_SKKT,'
      '    VVOD_REM_SKKT,'
      '    CBKGR_REM_SKKT,'
      '    CBKCO_REM_SKKT,'
      '    NUMCONTRACT_REM_SKKT,'
      '    DATECONTRACT_REM_SKKT,'
      '    SUMCONTRACT_REM_SKKT,'
      '    EKLZ_SERNUM_REM_SKKT,'
      '    EKLZ_REGNUM_REM_SKKT,'
      '    EKLZ_ACT_REM_SKKT,'
      '    PAS_NUMVER_REM_SKKT,'
      '    PAS_NUMPAS_REM_SKKT,'
      '    PAS_NUMPU_REM_SKKT,'
      '    PAS_NUMSP_REM_SKKT,'
      '    PAS_NUMSPPO_REM_SKKT,'
      '    PAS_NUMFP_REM_SKKT,'
      '    PAS_NUMFPPO_REM_SKKT,'
      '    PAS_NUMDO_REM_SKKT,'
      '    PAS_NUMDOPO_REM_SKKT,'
      '    PAS_NUMPPP_REM_SKKT,'
      '    PAS_DOR_REM_SKKT,'
      '    PAS_PRIM_REM_SKKT,'
      '    IDGRP_REM_SKKT,'
      '    PRIM_REM_SKKT'
      ')'
      'VALUES('
      '    :ID_REM_SKKT,'
      '    :IDBASE_REM_SKKT,'
      '    :NAME_REM_SKKT,'
      '    :SERNUM_REM_SKKT,'
      '    :IDMODEL_REM_SKKT,'
      '    :REGNUM_REM_SKKT,'
      '    :IDKLIENT_REM_SKKT,'
      '    :MESTOUST_REM_SKKT,'
      '    :RELEASE_REM_SKKT,'
      '    :VVOD_REM_SKKT,'
      '    :CBKGR_REM_SKKT,'
      '    :CBKCO_REM_SKKT,'
      '    :NUMCONTRACT_REM_SKKT,'
      '    :DATECONTRACT_REM_SKKT,'
      '    :SUMCONTRACT_REM_SKKT,'
      '    :EKLZ_SERNUM_REM_SKKT,'
      '    :EKLZ_REGNUM_REM_SKKT,'
      '    :EKLZ_ACT_REM_SKKT,'
      '    :PAS_NUMVER_REM_SKKT,'
      '    :PAS_NUMPAS_REM_SKKT,'
      '    :PAS_NUMPU_REM_SKKT,'
      '    :PAS_NUMSP_REM_SKKT,'
      '    :PAS_NUMSPPO_REM_SKKT,'
      '    :PAS_NUMFP_REM_SKKT,'
      '    :PAS_NUMFPPO_REM_SKKT,'
      '    :PAS_NUMDO_REM_SKKT,'
      '    :PAS_NUMDOPO_REM_SKKT,'
      '    :PAS_NUMPPP_REM_SKKT,'
      '    :PAS_DOR_REM_SKKT,'
      '    :PAS_PRIM_REM_SKKT,'
      '    :IDGRP_REM_SKKT,'
      '    :PRIM_REM_SKKT'
      ')')
    RefreshSQL.Strings = (
      'select rem_skkt.*,'
      '    rem_smodel.name_rem_smodel,'
      '    OWNER.NAMEKLIENT as OWNER_NAME'
      'from rem_skkt'
      
        'left outer join rem_smodel on rem_skkt.idmodel_rem_skkt=rem_smod' +
        'el.id_rem_smodel'
      
        'left outer join sklient as OWNER on rem_skkt.idklient_rem_skkt=O' +
        'WNER.IDKLIENT'
      'where(  rem_skkt.id_rem_skkt=:PARAM_ID'
      '     ) and (     REM_SKKT.ID_REM_SKKT = :OLD_ID_REM_SKKT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_skkt.*,'
      '    rem_smodel.name_rem_smodel,'
      '    OWNER.NAMEKLIENT as OWNER_NAME'
      'from rem_skkt'
      
        'left outer join rem_smodel on rem_skkt.idmodel_rem_skkt=rem_smod' +
        'el.id_rem_smodel'
      
        'left outer join sklient as OWNER on rem_skkt.idklient_rem_skkt=O' +
        'WNER.IDKLIENT'
      'where rem_skkt.id_rem_skkt=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_SKKT'
    AutoUpdateOptions.KeyFields = 'ID_REM_SKKT'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SKKT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object ElementID_REM_SKKT: TFIBLargeIntField
      FieldName = 'ID_REM_SKKT'
    end
    object ElementIDBASE_REM_SKKT: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SKKT'
    end
    object ElementNAME_REM_SKKT: TFIBWideStringField
      FieldName = 'NAME_REM_SKKT'
      Size = 100
    end
    object ElementSERNUM_REM_SKKT: TFIBWideStringField
      FieldName = 'SERNUM_REM_SKKT'
      Size = 15
    end
    object ElementIDMODEL_REM_SKKT: TFIBLargeIntField
      FieldName = 'IDMODEL_REM_SKKT'
    end
    object ElementREGNUM_REM_SKKT: TFIBWideStringField
      FieldName = 'REGNUM_REM_SKKT'
      OnChange = ElementREGNUM_REM_SKKTChange
      Size = 15
    end
    object ElementIDKLIENT_REM_SKKT: TFIBLargeIntField
      FieldName = 'IDKLIENT_REM_SKKT'
      OnChange = ElementIDKLIENT_REM_SKKTChange
    end
    object ElementMESTOUST_REM_SKKT: TFIBWideStringField
      FieldName = 'MESTOUST_REM_SKKT'
      OnChange = ElementMESTOUST_REM_SKKTChange
      Size = 100
    end
    object ElementRELEASE_REM_SKKT: TFIBDateField
      FieldName = 'RELEASE_REM_SKKT'
    end
    object ElementVVOD_REM_SKKT: TFIBDateField
      FieldName = 'VVOD_REM_SKKT'
    end
    object ElementCBKGR_REM_SKKT: TFIBWideStringField
      FieldName = 'CBKGR_REM_SKKT'
      OnChange = ElementCBKGR_REM_SKKTChange
      Size = 15
    end
    object ElementCBKCO_REM_SKKT: TFIBWideStringField
      FieldName = 'CBKCO_REM_SKKT'
      OnChange = ElementCBKCO_REM_SKKTChange
      Size = 15
    end
    object ElementNUMCONTRACT_REM_SKKT: TFIBWideStringField
      FieldName = 'NUMCONTRACT_REM_SKKT'
      OnChange = ElementNUMCONTRACT_REM_SKKTChange
      Size = 10
    end
    object ElementDATECONTRACT_REM_SKKT: TFIBDateField
      FieldName = 'DATECONTRACT_REM_SKKT'
      OnChange = ElementDATECONTRACT_REM_SKKTChange
    end
    object ElementSUMCONTRACT_REM_SKKT: TFIBBCDField
      FieldName = 'SUMCONTRACT_REM_SKKT'
      OnChange = ElementSUMCONTRACT_REM_SKKTChange
      Size = 2
      RoundByScale = True
    end
    object ElementEKLZ_SERNUM_REM_SKKT: TFIBWideStringField
      FieldName = 'EKLZ_SERNUM_REM_SKKT'
      OnChange = ElementEKLZ_SERNUM_REM_SKKTChange
      Size = 15
    end
    object ElementEKLZ_REGNUM_REM_SKKT: TFIBWideStringField
      FieldName = 'EKLZ_REGNUM_REM_SKKT'
      OnChange = ElementEKLZ_REGNUM_REM_SKKTChange
      Size = 15
    end
    object ElementEKLZ_ACT_REM_SKKT: TFIBDateField
      FieldName = 'EKLZ_ACT_REM_SKKT'
      OnChange = ElementEKLZ_ACT_REM_SKKTChange
    end
    object ElementPAS_NUMVER_REM_SKKT: TFIBWideStringField
      FieldName = 'PAS_NUMVER_REM_SKKT'
      Size = 3
    end
    object ElementPAS_NUMPAS_REM_SKKT: TFIBWideStringField
      FieldName = 'PAS_NUMPAS_REM_SKKT'
      Size = 10
    end
    object ElementPAS_NUMPU_REM_SKKT: TFIBWideStringField
      FieldName = 'PAS_NUMPU_REM_SKKT'
      Size = 3
    end
    object ElementPAS_NUMSP_REM_SKKT: TFIBWideStringField
      FieldName = 'PAS_NUMSP_REM_SKKT'
      Size = 3
    end
    object ElementPAS_NUMSPPO_REM_SKKT: TFIBWideStringField
      FieldName = 'PAS_NUMSPPO_REM_SKKT'
      Size = 3
    end
    object ElementPAS_NUMFP_REM_SKKT: TFIBWideStringField
      FieldName = 'PAS_NUMFP_REM_SKKT'
      Size = 3
    end
    object ElementPAS_NUMFPPO_REM_SKKT: TFIBWideStringField
      FieldName = 'PAS_NUMFPPO_REM_SKKT'
      Size = 3
    end
    object ElementPAS_NUMDO_REM_SKKT: TFIBWideStringField
      FieldName = 'PAS_NUMDO_REM_SKKT'
      Size = 3
    end
    object ElementPAS_NUMDOPO_REM_SKKT: TFIBWideStringField
      FieldName = 'PAS_NUMDOPO_REM_SKKT'
      Size = 3
    end
    object ElementPAS_NUMPPP_REM_SKKT: TFIBWideStringField
      FieldName = 'PAS_NUMPPP_REM_SKKT'
      Size = 3
    end
    object ElementPAS_DOR_REM_SKKT: TFIBWideStringField
      FieldName = 'PAS_DOR_REM_SKKT'
      Size = 10
    end
    object ElementPAS_PRIM_REM_SKKT: TFIBWideStringField
      FieldName = 'PAS_PRIM_REM_SKKT'
      Size = 10
    end
    object ElementIDGRP_REM_SKKT: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SKKT'
    end
    object ElementPRIM_REM_SKKT: TFIBWideStringField
      FieldName = 'PRIM_REM_SKKT'
      Size = 150
    end
    object ElementNAME_REM_SMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SMODEL'
      Size = 100
    end
    object ElementOWNER_NAME: TFIBWideStringField
      FieldName = 'OWNER_NAME'
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
    Left = 256
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
    Left = 256
    Top = 64
  end
  object Query: TpFIBQuery
    Transaction = IBTr
    Left = 160
    Top = 144
    qoStartTransaction = True
  end
end
