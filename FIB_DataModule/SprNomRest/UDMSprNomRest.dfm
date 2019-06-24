object DMSprNomRest: TDMSprNomRest
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 213
  Width = 375
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 48
    Top = 72
  end
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 24
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select ID_NOMREST, NAME_NOMREST, POS_NOMREST , IDNOM_NOMREST'
      'from SNOMREST'
      'where IDNOM_NOMREST=:PARAM_IDNOM'
      'order by POS_NOMREST')
    Transaction = IBTr
    Left = 168
    Top = 24
    object TablePOS_NOMREST: TFIBDateTimeField
      FieldName = 'POS_NOMREST'
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_NOMREST: TFIBBCDField
      FieldName = 'ID_NOMREST'
      Size = 0
      RoundByScale = True
    end
    object TableIDNOM_NOMREST: TFIBBCDField
      FieldName = 'IDNOM_NOMREST'
      Size = 0
      RoundByScale = True
    end
    object TableNAME_NOMREST: TFIBWideStringField
      FieldName = 'NAME_NOMREST'
      Size = 100
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SNOMREST'
      'SET '
      '    IDNOM_NOMREST = :IDNOM_NOMREST,'
      '    IDMPRIG_NOMREST = :IDMPRIG_NOMREST,'
      '    SOST_NOMREST = :SOST_NOMREST,'
      '    TEHN_NOMREST = :TEHN_NOMREST,'
      '    VIH_NOMREST = :VIH_NOMREST,'
      '    SROK_NOMREST = :SROK_NOMREST,'
      '    NOMER_NOMREST = :NOMER_NOMREST,'
      '    NAME_NOMREST = :NAME_NOMREST,'
      '    POS_NOMREST = :POS_NOMREST,'
      '    IDEDPROD_NOMREST = :IDEDPROD_NOMREST,'
      '    KOLEDPROD_NOMREST = :KOLEDPROD_NOMREST,'
      '    GID_SNOMREST = :GID_SNOMREST,'
      '    IDBASE_SNOMREST = :IDBASE_SNOMREST,'
      '    IDEDFACTOR_SNOMREST = :IDEDFACTOR_SNOMREST,'
      '    ENCEN_SNOMREST = :ENCEN_SNOMREST,'
      '    IDPRODUCE_SNOMREST = :IDPRODUCE_SNOMREST,'
      '    IDLOSSFACTOR_SNOMREST = :IDLOSSFACTOR_SNOMREST,'
      '    VID_SNOMREST = :VID_SNOMREST,'
      '    TEMP_SNOMREST = :TEMP_SNOMREST,'
      '    APPERANCE_SNOMREST = :APPERANCE_SNOMREST,'
      '    COLOUR_SNOMREST = :COLOUR_SNOMREST,'
      '    TASTE_SNOMREST = :TASTE_SNOMREST,'
      '    SMELL_SNOMREST = :SMELL_SNOMREST,'
      '    CONSISTENCE_SNOMREST = :CONSISTENCE_SNOMREST,'
      '    MDSV_SNOMREST = :MDSV_SNOMREST,'
      '    MDG_SNOMREST = :MDG_SNOMREST,'
      '    MDS_SNOMREST = :MDS_SNOMREST,'
      '    KMAM_SNOMREST = :KMAM_SNOMREST,'
      '    BGKR_SNOMREST = :BGKR_SNOMREST,'
      '    ECOLI_SNOMREST = :ECOLI_SNOMREST,'
      '    KPS_SNOMREST = :KPS_SNOMREST,'
      '    PROTEUS_SNOMREST = :PROTEUS_SNOMREST,'
      '    PMS_SNOMREST = :PMS_SNOMREST'
      'WHERE'
      '    ID_NOMREST = :OLD_ID_NOMREST'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SNOMREST'
      'WHERE'
      '        ID_NOMREST = :OLD_ID_NOMREST'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SNOMREST('
      '    ID_NOMREST,'
      '    IDNOM_NOMREST,'
      '    IDMPRIG_NOMREST,'
      '    SOST_NOMREST,'
      '    TEHN_NOMREST,'
      '    VIH_NOMREST,'
      '    SROK_NOMREST,'
      '    NOMER_NOMREST,'
      '    NAME_NOMREST,'
      '    POS_NOMREST,'
      '    IDEDPROD_NOMREST,'
      '    KOLEDPROD_NOMREST,'
      '    GID_SNOMREST,'
      '    IDBASE_SNOMREST,'
      '    IDEDFACTOR_SNOMREST,'
      '    ENCEN_SNOMREST,'
      '    IDPRODUCE_SNOMREST,'
      '    IDLOSSFACTOR_SNOMREST,'
      '    VID_SNOMREST,'
      '    TEMP_SNOMREST,'
      '    APPERANCE_SNOMREST,'
      '    COLOUR_SNOMREST,'
      '    TASTE_SNOMREST,'
      '    SMELL_SNOMREST,'
      '    CONSISTENCE_SNOMREST,'
      '    MDSV_SNOMREST,'
      '    MDG_SNOMREST,'
      '    MDS_SNOMREST,'
      '    KMAM_SNOMREST,'
      '    BGKR_SNOMREST,'
      '    ECOLI_SNOMREST,'
      '    KPS_SNOMREST,'
      '    PROTEUS_SNOMREST,'
      '    PMS_SNOMREST'
      ')'
      'VALUES('
      '    :ID_NOMREST,'
      '    :IDNOM_NOMREST,'
      '    :IDMPRIG_NOMREST,'
      '    :SOST_NOMREST,'
      '    :TEHN_NOMREST,'
      '    :VIH_NOMREST,'
      '    :SROK_NOMREST,'
      '    :NOMER_NOMREST,'
      '    :NAME_NOMREST,'
      '    :POS_NOMREST,'
      '    :IDEDPROD_NOMREST,'
      '    :KOLEDPROD_NOMREST,'
      '    :GID_SNOMREST,'
      '    :IDBASE_SNOMREST,'
      '    :IDEDFACTOR_SNOMREST,'
      '    :ENCEN_SNOMREST,'
      '    :IDPRODUCE_SNOMREST,'
      '    :IDLOSSFACTOR_SNOMREST,'
      '    :VID_SNOMREST,'
      '    :TEMP_SNOMREST,'
      '    :APPERANCE_SNOMREST,'
      '    :COLOUR_SNOMREST,'
      '    :TASTE_SNOMREST,'
      '    :SMELL_SNOMREST,'
      '    :CONSISTENCE_SNOMREST,'
      '    :MDSV_SNOMREST,'
      '    :MDG_SNOMREST,'
      '    :MDS_SNOMREST,'
      '    :KMAM_SNOMREST,'
      '    :BGKR_SNOMREST,'
      '    :ECOLI_SNOMREST,'
      '    :KPS_SNOMREST,'
      '    :PROTEUS_SNOMREST,'
      '    :PMS_SNOMREST'
      ')')
    RefreshSQL.Strings = (
      'select'
      '  SNOMREST.*, NAME_MPRIG, NAMENOM, IDSKLAD_MPRIG,'
      '  ED_PROD.NAMEED,'
      '  ED_PROD.KFED,'
      '  ED_FACTOR.NAMEED as NAME_ED_FACTOR,'
      '  ED_FACTOR.KFED as KF_ED_FACTOR,'
      '  sproduce.name_sproduce,'
      '  sloss_factor.name_sloss_factor'
      'from '
      '  SNOMREST'
      'left outer join SMPRIG on  IDMPRIG_NOMREST=ID_MPRIG'
      'left outer join SNOM on  IDNOM=IDNOM_NOMREST'
      
        'left outer join SED as ED_PROD on ED_PROD.IDED=snomrest.idedprod' +
        '_nomrest'
      
        'left outer join sed as ED_FACTOR  on ED_FACTOR.ided=snomrest.ide' +
        'dfactor_snomrest'
      
        'left outer join sproduce on snomrest.idproduce_snomrest=sproduce' +
        '.id_sproduce'
      
        'left outer join sloss_factor on snomrest.idlossfactor_snomrest=s' +
        'loss_factor.id_sloss_factor'
      'where( '
      '  ID_NOMREST=:PARAM_ID'
      '     ) and (     SNOMREST.ID_NOMREST = :OLD_ID_NOMREST'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select'
      '  SNOMREST.*, NAME_MPRIG, NAMENOM, IDSKLAD_MPRIG,'
      '  ED_PROD.NAMEED,'
      '  ED_PROD.KFED,'
      '  ED_FACTOR.NAMEED as NAME_ED_FACTOR,'
      '  ED_FACTOR.KFED as KF_ED_FACTOR,'
      '  sproduce.name_sproduce,'
      '  sloss_factor.name_sloss_factor'
      'from '
      '  SNOMREST'
      'left outer join SMPRIG on  IDMPRIG_NOMREST=ID_MPRIG'
      'left outer join SNOM on  IDNOM=IDNOM_NOMREST'
      
        'left outer join SED as ED_PROD on ED_PROD.IDED=snomrest.idedprod' +
        '_nomrest'
      
        'left outer join sed as ED_FACTOR  on ED_FACTOR.ided=snomrest.ide' +
        'dfactor_snomrest'
      
        'left outer join sproduce on snomrest.idproduce_snomrest=sproduce' +
        '.id_sproduce'
      
        'left outer join sloss_factor on snomrest.idlossfactor_snomrest=s' +
        'loss_factor.id_sloss_factor'
      'where'
      '  ID_NOMREST=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SNOMREST'
    AutoUpdateOptions.KeyFields = 'ID_NOMREST'
    AutoUpdateOptions.GeneratorName = 'GEN_SNOMREST_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 80
    object ElementID_NOMREST: TFIBBCDField
      FieldName = 'ID_NOMREST'
      Size = 0
      RoundByScale = True
    end
    object ElementIDNOM_NOMREST: TFIBBCDField
      FieldName = 'IDNOM_NOMREST'
      Size = 0
      RoundByScale = True
    end
    object ElementIDMPRIG_NOMREST: TFIBBCDField
      FieldName = 'IDMPRIG_NOMREST'
      Size = 0
      RoundByScale = True
    end
    object ElementSOST_NOMREST: TFIBWideStringField
      FieldName = 'SOST_NOMREST'
      Size = 250
    end
    object ElementTEHN_NOMREST: TFIBWideStringField
      FieldName = 'TEHN_NOMREST'
      Size = 1500
    end
    object ElementVIH_NOMREST: TFIBWideStringField
      FieldName = 'VIH_NOMREST'
      Size = 30
    end
    object ElementSROK_NOMREST: TFIBWideStringField
      FieldName = 'SROK_NOMREST'
      Size = 10
    end
    object ElementNOMER_NOMREST: TFIBWideStringField
      FieldName = 'NOMER_NOMREST'
      Size = 30
    end
    object ElementNAME_NOMREST: TFIBWideStringField
      FieldName = 'NAME_NOMREST'
      Size = 200
    end
    object ElementPOS_NOMREST: TFIBDateTimeField
      FieldName = 'POS_NOMREST'
      DisplayFormat = 'c'
    end
    object ElementIDEDPROD_NOMREST: TFIBBCDField
      FieldName = 'IDEDPROD_NOMREST'
      Size = 0
      RoundByScale = True
    end
    object ElementKOLEDPROD_NOMREST: TFIBBCDField
      FieldName = 'KOLEDPROD_NOMREST'
      Size = 3
      RoundByScale = True
    end
    object ElementGID_SNOMREST: TFIBWideStringField
      FieldName = 'GID_SNOMREST'
      Size = 10
    end
    object ElementIDBASE_SNOMREST: TFIBBCDField
      FieldName = 'IDBASE_SNOMREST'
      Size = 0
      RoundByScale = True
    end
    object ElementIDEDFACTOR_SNOMREST: TFIBBCDField
      FieldName = 'IDEDFACTOR_SNOMREST'
      Size = 0
      RoundByScale = True
    end
    object ElementENCEN_SNOMREST: TFIBBCDField
      FieldName = 'ENCEN_SNOMREST'
      Size = 3
      RoundByScale = True
    end
    object ElementIDPRODUCE_SNOMREST: TFIBBCDField
      FieldName = 'IDPRODUCE_SNOMREST'
      Size = 0
      RoundByScale = True
    end
    object ElementIDLOSSFACTOR_SNOMREST: TFIBBCDField
      FieldName = 'IDLOSSFACTOR_SNOMREST'
      Size = 0
      RoundByScale = True
    end
    object ElementVID_SNOMREST: TFIBWideStringField
      FieldName = 'VID_SNOMREST'
      Size = 150
    end
    object ElementTEMP_SNOMREST: TFIBWideStringField
      FieldName = 'TEMP_SNOMREST'
      Size = 150
    end
    object ElementAPPERANCE_SNOMREST: TFIBWideStringField
      FieldName = 'APPERANCE_SNOMREST'
      Size = 150
    end
    object ElementCOLOUR_SNOMREST: TFIBWideStringField
      FieldName = 'COLOUR_SNOMREST'
      Size = 150
    end
    object ElementTASTE_SNOMREST: TFIBWideStringField
      FieldName = 'TASTE_SNOMREST'
      Size = 150
    end
    object ElementSMELL_SNOMREST: TFIBWideStringField
      FieldName = 'SMELL_SNOMREST'
      Size = 150
    end
    object ElementCONSISTENCE_SNOMREST: TFIBWideStringField
      FieldName = 'CONSISTENCE_SNOMREST'
      Size = 150
    end
    object ElementMDSV_SNOMREST: TFIBWideStringField
      FieldName = 'MDSV_SNOMREST'
    end
    object ElementMDG_SNOMREST: TFIBWideStringField
      FieldName = 'MDG_SNOMREST'
    end
    object ElementMDS_SNOMREST: TFIBWideStringField
      FieldName = 'MDS_SNOMREST'
    end
    object ElementKMAM_SNOMREST: TFIBWideStringField
      FieldName = 'KMAM_SNOMREST'
    end
    object ElementBGKR_SNOMREST: TFIBWideStringField
      FieldName = 'BGKR_SNOMREST'
    end
    object ElementECOLI_SNOMREST: TFIBWideStringField
      FieldName = 'ECOLI_SNOMREST'
    end
    object ElementKPS_SNOMREST: TFIBWideStringField
      FieldName = 'KPS_SNOMREST'
    end
    object ElementPROTEUS_SNOMREST: TFIBWideStringField
      FieldName = 'PROTEUS_SNOMREST'
    end
    object ElementPMS_SNOMREST: TFIBWideStringField
      FieldName = 'PMS_SNOMREST'
    end
    object ElementNAME_MPRIG: TFIBWideStringField
      FieldName = 'NAME_MPRIG'
      Size = 200
    end
    object ElementNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object ElementIDSKLAD_MPRIG: TFIBBCDField
      FieldName = 'IDSKLAD_MPRIG'
      Size = 0
      RoundByScale = True
    end
    object ElementNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 200
    end
    object ElementKFED: TFIBBCDField
      FieldName = 'KFED'
      Size = 3
      RoundByScale = True
    end
    object ElementNAME_ED_FACTOR: TFIBWideStringField
      FieldName = 'NAME_ED_FACTOR'
      Size = 200
    end
    object ElementKF_ED_FACTOR: TFIBBCDField
      FieldName = 'KF_ED_FACTOR'
      Size = 3
      RoundByScale = True
    end
    object ElementNAME_SPRODUCE: TFIBWideStringField
      FieldName = 'NAME_SPRODUCE'
      Size = 200
    end
    object ElementNAME_SLOSS_FACTOR: TFIBWideStringField
      FieldName = 'NAME_SLOSS_FACTOR'
      Size = 200
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
    Top = 24
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
    Top = 80
  end
  object IBQ: TpFIBDataSet
    SelectSQL.Strings = (
      'select SSPROD.*,  NAMENOM, VALUE_SSEZKF, VALUE_SSEZKF_SPROD'
      '   from SSPROD'
      'left outer join SNOM on IDKOMPL_SPROD=IDNOM'
      'left outer join SSEZKF on IDNOM_SSEZKF=IDKOMPL_SPROD and '
      'MONTH_SSEZKF=:PARAM_MONTH'
      ''
      
        'left outer join SSEZKF_SPROD on IDSSPROD_SSEZKF_SPROD= ID_SPROD ' +
        'and '
      'MONTH_SSEZKF_SPROD=:PARAM_MONTH'
      ''
      'where IDNOMREST_SPROD=:PARAM_IDNOMREST')
    OnCalcFields = IBQCalcFields
    Transaction = IBTr
    Left = 168
    Top = 136
    object IBQNKOL_SPROD: TFIBBCDField
      FieldName = 'NKOL_SPROD'
      Size = 3
      RoundByScale = True
    end
    object IBQBKOL_SPROD: TFIBBCDField
      FieldName = 'BKOL_SPROD'
      Size = 3
      RoundByScale = True
    end
    object IBQKFPRICE_SPROD: TFIBBCDField
      FieldName = 'KFPRICE_SPROD'
      Size = 3
      RoundByScale = True
    end
    object IBQSPIS_SPROD: TFIBSmallIntField
      FieldName = 'SPIS_SPROD'
    end
    object IBQVALUE_SSEZKF: TFIBBCDField
      FieldName = 'VALUE_SSEZKF'
      Size = 3
      RoundByScale = True
    end
    object IBQSEZKF: TFloatField
      FieldKind = fkCalculated
      FieldName = 'SEZKF'
      Calculated = True
    end
    object IBQSEZKF_SPROD: TFloatField
      FieldKind = fkCalculated
      FieldName = 'SEZKF_SPROD'
      Calculated = True
    end
    object IBQVALUE_SSEZKF_SPROD: TFIBBCDField
      FieldName = 'VALUE_SSEZKF_SPROD'
      Size = 3
      RoundByScale = True
    end
    object IBQID_SPROD: TFIBBCDField
      FieldName = 'ID_SPROD'
      Size = 0
      RoundByScale = True
    end
    object IBQIDKOMPL_SPROD: TFIBBCDField
      FieldName = 'IDKOMPL_SPROD'
      Size = 0
      RoundByScale = True
    end
    object IBQNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 100
    end
  end
end
