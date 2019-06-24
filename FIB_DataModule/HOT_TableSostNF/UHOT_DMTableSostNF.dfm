object HOT_DMTableSostNF: THOT_DMTableSostNF
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
      'select hot_sostnf.*,'
      '    PLAT.NAMEKLIENT as NAMEPLAT,'
      '    GUEST.NAMEKLIENT as NAMEGUEST,'
      '    hot_snf.name_hot_snf,'
      '    hot_ssostnom.name_hot_ssostnom,'
      '    hot_stypepos.name_hot_stypepos'
      'from hot_sostnf'
      
        'left outer join sklient as PLAT on PLAT.IDKLIENT=hot_sostnf.idpl' +
        'at_hot_sostnf'
      
        'left outer join sklient as GUEST on GUEST.IDKLIENT=hot_sostnf.id' +
        'guest_hot_sostnf'
      
        'left outer join hot_snf on hot_snf.id_hot_snf=hot_sostnf.idnomer' +
        '_hot_sostnf'
      
        'left outer join hot_stypepos on hot_stypepos.id_hot_stypepos=hot' +
        '_sostnf.idtpos_hot_sostnf'
      
        'left outer join hot_ssostnom on hot_ssostnom.id_hot_ssostnom=hot' +
        '_sostnf.idsost_hot_sostnf')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 160
    Top = 16
    object TableKOLM_HOT_SOSTNF: TFIBIntegerField
      FieldName = 'KOLM_HOT_SOSTNF'
    end
    object TablePOSNACH_HOT_SOSTNF: TFIBDateTimeField
      FieldName = 'POSNACH_HOT_SOSTNF'
      DisplayFormat = 'c'
    end
    object TablePOSCON_HOT_SOSTNF: TFIBDateTimeField
      FieldName = 'POSCON_HOT_SOSTNF'
      DisplayFormat = 'c'
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_HOT_SOSTNF: TFIBBCDField
      FieldName = 'ID_HOT_SOSTNF'
      Size = 0
      RoundByScale = True
    end
    object TableIDNOMER_HOT_SOSTNF: TFIBBCDField
      FieldName = 'IDNOMER_HOT_SOSTNF'
      Size = 0
      RoundByScale = True
    end
    object TableIDPLAT_HOT_SOSTNF: TFIBBCDField
      FieldName = 'IDPLAT_HOT_SOSTNF'
      Size = 0
      RoundByScale = True
    end
    object TableIDGUEST_HOT_SOSTNF: TFIBBCDField
      FieldName = 'IDGUEST_HOT_SOSTNF'
      Size = 0
      RoundByScale = True
    end
    object TableIDSOST_HOT_SOSTNF: TFIBBCDField
      FieldName = 'IDSOST_HOT_SOSTNF'
      Size = 0
      RoundByScale = True
    end
    object TableIDTPOS_HOT_SOSTNF: TFIBBCDField
      FieldName = 'IDTPOS_HOT_SOSTNF'
      Size = 0
      RoundByScale = True
    end
    object TableIDCAT_HOT_SOSTNF: TFIBBCDField
      FieldName = 'IDCAT_HOT_SOSTNF'
      Size = 0
      RoundByScale = True
    end
    object TableIDDOCH_HOT_SOSTNF: TFIBBCDField
      FieldName = 'IDDOCH_HOT_SOSTNF'
      Size = 0
      RoundByScale = True
    end
    object TableNAMEPLAT: TFIBWideStringField
      FieldName = 'NAMEPLAT'
      Size = 100
    end
    object TableNAMEGUEST: TFIBWideStringField
      FieldName = 'NAMEGUEST'
      Size = 100
    end
    object TableNAME_HOT_SNF: TFIBWideStringField
      FieldName = 'NAME_HOT_SNF'
      Size = 100
    end
    object TableNAME_HOT_SSOSTNOM: TFIBWideStringField
      FieldName = 'NAME_HOT_SSOSTNOM'
      Size = 100
    end
    object TableNAME_HOT_STYPEPOS: TFIBWideStringField
      FieldName = 'NAME_HOT_STYPEPOS'
      Size = 100
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE HOT_SOSTNF'
      'SET '
      '    GID_HOT_SOSTNF = :GID_HOT_SOSTNF,'
      '    IDNOMER_HOT_SOSTNF = :IDNOMER_HOT_SOSTNF,'
      '    IDPLAT_HOT_SOSTNF = :IDPLAT_HOT_SOSTNF,'
      '    IDGUEST_HOT_SOSTNF = :IDGUEST_HOT_SOSTNF,'
      '    IDSOST_HOT_SOSTNF = :IDSOST_HOT_SOSTNF,'
      '    IDTPOS_HOT_SOSTNF = :IDTPOS_HOT_SOSTNF,'
      '    IDCAT_HOT_SOSTNF = :IDCAT_HOT_SOSTNF,'
      '    IDDOCH_HOT_SOSTNF = :IDDOCH_HOT_SOSTNF,'
      '    KOLM_HOT_SOSTNF = :KOLM_HOT_SOSTNF,'
      '    POSNACH_HOT_SOSTNF = :POSNACH_HOT_SOSTNF,'
      '    POSCON_HOT_SOSTNF = :POSCON_HOT_SOSTNF,'
      '    IDCEL_HOT_SOSTNF = :IDCEL_HOT_SOSTNF'
      'WHERE'
      '    ID_HOT_SOSTNF = :OLD_ID_HOT_SOSTNF'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    HOT_SOSTNF'
      'WHERE'
      '        ID_HOT_SOSTNF = :OLD_ID_HOT_SOSTNF'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO HOT_SOSTNF('
      '    ID_HOT_SOSTNF,'
      '    GID_HOT_SOSTNF,'
      '    IDNOMER_HOT_SOSTNF,'
      '    IDPLAT_HOT_SOSTNF,'
      '    IDGUEST_HOT_SOSTNF,'
      '    IDSOST_HOT_SOSTNF,'
      '    IDTPOS_HOT_SOSTNF,'
      '    IDCAT_HOT_SOSTNF,'
      '    IDDOCH_HOT_SOSTNF,'
      '    KOLM_HOT_SOSTNF,'
      '    POSNACH_HOT_SOSTNF,'
      '    POSCON_HOT_SOSTNF,'
      '    IDCEL_HOT_SOSTNF'
      ')'
      'VALUES('
      '    :ID_HOT_SOSTNF,'
      '    :GID_HOT_SOSTNF,'
      '    :IDNOMER_HOT_SOSTNF,'
      '    :IDPLAT_HOT_SOSTNF,'
      '    :IDGUEST_HOT_SOSTNF,'
      '    :IDSOST_HOT_SOSTNF,'
      '    :IDTPOS_HOT_SOSTNF,'
      '    :IDCAT_HOT_SOSTNF,'
      '    :IDDOCH_HOT_SOSTNF,'
      '    :KOLM_HOT_SOSTNF,'
      '    :POSNACH_HOT_SOSTNF,'
      '    :POSCON_HOT_SOSTNF,'
      '    :IDCEL_HOT_SOSTNF'
      ')')
    RefreshSQL.Strings = (
      'select hot_sostnf.*,'
      '    PLAT.NAMEKLIENT as NAMEPLAT,'
      '    GUEST.NAMEKLIENT as NAMEGUEST,'
      '    hot_snf.name_hot_snf,'
      '    hot_ssostnom.name_hot_ssostnom,'
      '    hot_stypepos.name_hot_stypepos,'
      '    hot_scatnom.name_hot_scatnom,'
      '    NAME_HOT_SCELPR'
      'from hot_sostnf'
      
        'left outer join sklient as PLAT on PLAT.IDKLIENT=hot_sostnf.idpl' +
        'at_hot_sostnf'
      
        'left outer join sklient as GUEST on GUEST.IDKLIENT=hot_sostnf.id' +
        'guest_hot_sostnf'
      
        'left outer join hot_snf on hot_snf.id_hot_snf=hot_sostnf.idnomer' +
        '_hot_sostnf'
      
        'left outer join hot_stypepos on hot_stypepos.id_hot_stypepos=hot' +
        '_sostnf.idtpos_hot_sostnf'
      
        'left outer join hot_ssostnom on hot_ssostnom.id_hot_ssostnom=hot' +
        '_sostnf.idsost_hot_sostnf'
      
        'left outer join hot_scatnom  on hot_scatnom.id_hot_scatnom=hot_s' +
        'ostnf.idcat_hot_sostnf'
      'left outer join HOT_SCELPR on ID_HOT_SCELPR=IDCEL_HOT_SOSTNF'
      'where(  '
      '  ID_HOT_SOSTNF=:PARAM_ID'
      '     ) and (     HOT_SOSTNF.ID_HOT_SOSTNF = :OLD_ID_HOT_SOSTNF'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select hot_sostnf.*,'
      '    PLAT.NAMEKLIENT as NAMEPLAT,'
      '    GUEST.NAMEKLIENT as NAMEGUEST,'
      '    hot_snf.name_hot_snf,'
      '    hot_ssostnom.name_hot_ssostnom,'
      '    hot_stypepos.name_hot_stypepos,'
      '    hot_scatnom.name_hot_scatnom,'
      '    NAME_HOT_SCELPR'
      'from hot_sostnf'
      
        'left outer join sklient as PLAT on PLAT.IDKLIENT=hot_sostnf.idpl' +
        'at_hot_sostnf'
      
        'left outer join sklient as GUEST on GUEST.IDKLIENT=hot_sostnf.id' +
        'guest_hot_sostnf'
      
        'left outer join hot_snf on hot_snf.id_hot_snf=hot_sostnf.idnomer' +
        '_hot_sostnf'
      
        'left outer join hot_stypepos on hot_stypepos.id_hot_stypepos=hot' +
        '_sostnf.idtpos_hot_sostnf'
      
        'left outer join hot_ssostnom on hot_ssostnom.id_hot_ssostnom=hot' +
        '_sostnf.idsost_hot_sostnf'
      
        'left outer join hot_scatnom  on hot_scatnom.id_hot_scatnom=hot_s' +
        'ostnf.idcat_hot_sostnf'
      'left outer join HOT_SCELPR on ID_HOT_SCELPR=IDCEL_HOT_SOSTNF'
      'where '
      '  ID_HOT_SOSTNF=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'HOT_SOSTNF'
    AutoUpdateOptions.KeyFields = 'ID_HOT_SOSTNF'
    AutoUpdateOptions.GeneratorName = 'GEN_HOT_SOSTNF_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 72
    object ElementKOLM_HOT_SOSTNF: TFIBIntegerField
      FieldName = 'KOLM_HOT_SOSTNF'
    end
    object ElementPOSNACH_HOT_SOSTNF: TFIBDateTimeField
      FieldName = 'POSNACH_HOT_SOSTNF'
      DisplayFormat = 'c'
    end
    object ElementPOSCON_HOT_SOSTNF: TFIBDateTimeField
      FieldName = 'POSCON_HOT_SOSTNF'
      DisplayFormat = 'c'
    end
    object ElementID_HOT_SOSTNF: TFIBBCDField
      FieldName = 'ID_HOT_SOSTNF'
      Size = 0
      RoundByScale = True
    end
    object ElementIDNOMER_HOT_SOSTNF: TFIBBCDField
      FieldName = 'IDNOMER_HOT_SOSTNF'
      Size = 0
      RoundByScale = True
    end
    object ElementIDPLAT_HOT_SOSTNF: TFIBBCDField
      FieldName = 'IDPLAT_HOT_SOSTNF'
      Size = 0
      RoundByScale = True
    end
    object ElementIDGUEST_HOT_SOSTNF: TFIBBCDField
      FieldName = 'IDGUEST_HOT_SOSTNF'
      Size = 0
      RoundByScale = True
    end
    object ElementIDSOST_HOT_SOSTNF: TFIBBCDField
      FieldName = 'IDSOST_HOT_SOSTNF'
      Size = 0
      RoundByScale = True
    end
    object ElementIDTPOS_HOT_SOSTNF: TFIBBCDField
      FieldName = 'IDTPOS_HOT_SOSTNF'
      Size = 0
      RoundByScale = True
    end
    object ElementIDCAT_HOT_SOSTNF: TFIBBCDField
      FieldName = 'IDCAT_HOT_SOSTNF'
      Size = 0
      RoundByScale = True
    end
    object ElementIDDOCH_HOT_SOSTNF: TFIBBCDField
      FieldName = 'IDDOCH_HOT_SOSTNF'
      Size = 0
      RoundByScale = True
    end
    object ElementIDCEL_HOT_SOSTNF: TFIBBCDField
      FieldName = 'IDCEL_HOT_SOSTNF'
      Size = 0
      RoundByScale = True
    end
    object ElementNAMEPLAT: TFIBWideStringField
      FieldName = 'NAMEPLAT'
      Size = 100
    end
    object ElementNAMEGUEST: TFIBWideStringField
      FieldName = 'NAMEGUEST'
      Size = 100
    end
    object ElementNAME_HOT_SNF: TFIBWideStringField
      FieldName = 'NAME_HOT_SNF'
      Size = 100
    end
    object ElementNAME_HOT_SSOSTNOM: TFIBWideStringField
      FieldName = 'NAME_HOT_SSOSTNOM'
      Size = 100
    end
    object ElementNAME_HOT_STYPEPOS: TFIBWideStringField
      FieldName = 'NAME_HOT_STYPEPOS'
      Size = 100
    end
    object ElementNAME_HOT_SCATNOM: TFIBWideStringField
      FieldName = 'NAME_HOT_SCATNOM'
      Size = 100
    end
    object ElementNAME_HOT_SCELPR: TFIBWideStringField
      FieldName = 'NAME_HOT_SCELPR'
      Size = 100
    end
  end
end
