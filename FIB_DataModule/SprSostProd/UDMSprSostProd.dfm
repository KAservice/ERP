object DMSprSostProd: TDMSprSostProd
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 341
  Width = 435
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SSPROD'
      'SET '
      '    IDNOMREST_SPROD = :IDNOMREST_SPROD,'
      '    NKOL_SPROD = :NKOL_SPROD,'
      '    BKOL_SPROD = :BKOL_SPROD,'
      '    KFPRICE_SPROD = :KFPRICE_SPROD,'
      '    IDKOMPL_SPROD = :IDKOMPL_SPROD,'
      '    SPIS_SPROD = :SPIS_SPROD,'
      '    IDED_SPROD = :IDED_SPROD,'
      '    KF_SPROD = :KF_SPROD,'
      '    GID_SSPROD = :GID_SSPROD,'
      '    IDBASE_SSPROD = :IDBASE_SSPROD,'
      '    IDPRODUCE_SSPROD = :IDPRODUCE_SSPROD,'
      '    IDLOSTFACTOR_SSPROD = :IDLOSTFACTOR_SSPROD'
      'WHERE'
      '    ID_SPROD = :OLD_ID_SPROD'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SSPROD'
      'WHERE'
      '        ID_SPROD = :OLD_ID_SPROD'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SSPROD('
      '    ID_SPROD,'
      '    IDNOMREST_SPROD,'
      '    NKOL_SPROD,'
      '    BKOL_SPROD,'
      '    KFPRICE_SPROD,'
      '    IDKOMPL_SPROD,'
      '    SPIS_SPROD,'
      '    IDED_SPROD,'
      '    KF_SPROD,'
      '    GID_SSPROD,'
      '    IDBASE_SSPROD,'
      '    IDPRODUCE_SSPROD,'
      '    IDLOSTFACTOR_SSPROD'
      ')'
      'VALUES('
      '    :ID_SPROD,'
      '    :IDNOMREST_SPROD,'
      '    :NKOL_SPROD,'
      '    :BKOL_SPROD,'
      '    :KFPRICE_SPROD,'
      '    :IDKOMPL_SPROD,'
      '    :SPIS_SPROD,'
      '    :IDED_SPROD,'
      '    :KF_SPROD,'
      '    :GID_SSPROD,'
      '    :IDBASE_SSPROD,'
      '    :IDPRODUCE_SSPROD,'
      '    :IDLOSTFACTOR_SSPROD'
      ')')
    RefreshSQL.Strings = (
      
        'select SSPROD.*,  NAMENOM, TNOM, NAMEED, VALUE_SSEZKF,  VALUE_SS' +
        'EZKF_SPROD,'
      '        sproduce.name_sproduce,'
      '        sloss_factor.name_sloss_factor'
      'from SSPROD'
      'left outer join SNOM on IDKOMPL_SPROD=IDNOM'
      'left outer join SED on IDED_SPROD=IDED'
      ''
      'left outer join SSEZKF on IDNOM_SSEZKF=IDKOMPL_SPROD and '
      'MONTH_SSEZKF=:PARAM_MONTH'
      ''
      
        'left outer join SSEZKF_SPROD on IDSSPROD_SSEZKF_SPROD= ID_SPROD ' +
        'and '
      'MONTH_SSEZKF_SPROD=:PARAM_MONTH'
      ''
      
        'left outer join sproduce on ssprod.idproduce_ssprod=sproduce.id_' +
        'sproduce'
      
        'left outer join sloss_factor on ssprod.idlostfactor_ssprod=sloss' +
        '_factor.id_sloss_factor'
      ''
      'where(  IDNOMREST_SPROD=:PARAM_IDNOMREST'
      '     ) and (     SSPROD.ID_SPROD = :OLD_ID_SPROD'
      '     )'
      '    ')
    SelectSQL.Strings = (
      
        'select SSPROD.*,  NAMENOM, TNOM, NAMEED, VALUE_SSEZKF,  VALUE_SS' +
        'EZKF_SPROD,'
      '        sproduce.name_sproduce,'
      '        sloss_factor.name_sloss_factor'
      'from SSPROD'
      'left outer join SNOM on IDKOMPL_SPROD=IDNOM'
      'left outer join SED on IDED_SPROD=IDED'
      ''
      'left outer join SSEZKF on IDNOM_SSEZKF=IDKOMPL_SPROD and '
      'MONTH_SSEZKF=:PARAM_MONTH'
      ''
      
        'left outer join SSEZKF_SPROD on IDSSPROD_SSEZKF_SPROD= ID_SPROD ' +
        'and '
      'MONTH_SSEZKF_SPROD=:PARAM_MONTH'
      ''
      
        'left outer join sproduce on ssprod.idproduce_ssprod=sproduce.id_' +
        'sproduce'
      
        'left outer join sloss_factor on ssprod.idlostfactor_ssprod=sloss' +
        '_factor.id_sloss_factor'
      ''
      'where IDNOMREST_SPROD=:PARAM_IDNOMREST')
    AutoUpdateOptions.UpdateTableName = 'SSPROD'
    AutoUpdateOptions.KeyFields = 'ID_SPROD'
    AutoUpdateOptions.GeneratorName = 'GEN_SSPROD_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnCalcFields = TableCalcFields
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 120
    Top = 16
    object TableNKOL_SPROD: TFIBBCDField
      FieldName = 'NKOL_SPROD'
      Size = 3
      RoundByScale = True
    end
    object TableBKOL_SPROD: TFIBBCDField
      FieldName = 'BKOL_SPROD'
      Size = 3
      RoundByScale = True
    end
    object TableKFPRICE_SPROD: TFIBBCDField
      FieldName = 'KFPRICE_SPROD'
      Size = 3
      RoundByScale = True
    end
    object TableSPIS_SPROD: TFIBSmallIntField
      FieldName = 'SPIS_SPROD'
      OnGetText = TableSPIS_SPRODGetText
      OnSetText = TableSPIS_SPRODSetText
    end
    object TableKF_SPROD: TFIBBCDField
      FieldName = 'KF_SPROD'
      Size = 3
      RoundByScale = True
    end
    object TableTNOM: TFIBIntegerField
      FieldName = 'TNOM'
    end
    object TableVALUE_SSEZKF: TFIBBCDField
      FieldName = 'VALUE_SSEZKF'
      Size = 3
      RoundByScale = True
    end
    object TableVALUE_SSEZKF_SPROD: TFIBBCDField
      FieldName = 'VALUE_SSEZKF_SPROD'
      Size = 3
      RoundByScale = True
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableNABASED: TFloatField
      FieldKind = fkCalculated
      FieldName = 'NABASED'
      Calculated = True
    end
    object TableNNABASED: TFloatField
      FieldKind = fkCalculated
      FieldName = 'NNABASED'
      Calculated = True
    end
    object TableSEZKF: TFloatField
      FieldKind = fkCalculated
      FieldName = 'SEZKF'
      Calculated = True
    end
    object TableSEZKF_SPROD: TFloatField
      FieldKind = fkCalculated
      FieldName = 'SEZKF_SPROD'
      Calculated = True
    end
    object TableID_SPROD: TFIBBCDField
      FieldName = 'ID_SPROD'
      Size = 0
      RoundByScale = True
    end
    object TableIDNOMREST_SPROD: TFIBBCDField
      FieldName = 'IDNOMREST_SPROD'
      Size = 0
      RoundByScale = True
    end
    object TableIDKOMPL_SPROD: TFIBBCDField
      FieldName = 'IDKOMPL_SPROD'
      Size = 0
      RoundByScale = True
    end
    object TableIDED_SPROD: TFIBBCDField
      FieldName = 'IDED_SPROD'
      Size = 0
      RoundByScale = True
    end
    object TableGID_SSPROD: TFIBWideStringField
      FieldName = 'GID_SSPROD'
      Size = 10
    end
    object TableNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object TableNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 200
    end
    object TableIDPRODUCE_SSPROD: TFIBBCDField
      FieldName = 'IDPRODUCE_SSPROD'
      Size = 0
      RoundByScale = True
    end
    object TableIDLOSTFACTOR_SSPROD: TFIBBCDField
      FieldName = 'IDLOSTFACTOR_SSPROD'
      Size = 0
      RoundByScale = True
    end
    object TableNAME_SPRODUCE: TFIBWideStringField
      FieldName = 'NAME_SPRODUCE'
      Size = 200
    end
    object TableNAME_SLOSS_FACTOR: TFIBWideStringField
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
    Left = 192
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
    Left = 192
    Top = 72
  end
end
