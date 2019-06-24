object DMSprVesNom: TDMSprVesNom
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Left = 750
  Top = 327
  Height = 119
  Width = 273
  object IBTr: TIBTransaction
    Active = False
    DefaultDatabase = DM.IBData
    DefaultAction = TARollback
    Params.Strings = (
      'read_committed'
      'rec_version'
      'nowait')
    AutoStopAction = saNone
    Left = 200
    Top = 16
  end
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object Table: TIBDataSet
    Database = DM.IBData
    Transaction = IBTr
    OnCalcFields = TableCalcFields
    OnNewRecord = TableNewRecord
    BufferChunks = 1000
    CachedUpdates = True
    DeleteSQL.Strings = (
      'delete from SSPROD'
      'where'
      '  ID_SPROD = :OLD_ID_SPROD')
    InsertSQL.Strings = (
      'insert into SSPROD'
      
        '  (ID_SPROD, IDNOMREST_SPROD, IDNOM_SPROD, NKOL_SPROD, BKOL_SPRO' +
        'D, KFPRICE_SPROD, '
      '   IDKOMPL_SPROD, SPIS_SPROD, IDED_SPROD, KF_SPROD, GID_SSPROD)'
      'values'
      
        '  (:ID_SPROD, :IDNOMREST_SPROD, :IDNOM_SPROD, :NKOL_SPROD, :BKOL' +
        '_SPROD, '
      
        '   :KFPRICE_SPROD, :IDKOMPL_SPROD, :SPIS_SPROD, :IDED_SPROD, :KF' +
        '_SPROD, '
      '   :GID_SSPROD)')
    RefreshSQL.Strings = (
      'select SSPROD.*,  NAMENOM, TNOM, NAMEED, VALUE_SSEZKF,  '
      'VALUE_SSEZKF_SPROD'
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
      'where'
      '  ID_SPROD = :ID_SPROD')
    SelectSQL.Strings = (
      
        'select SSPROD.*,  NAMENOM, TNOM, NAMEED, VALUE_SSEZKF,  VALUE_SS' +
        'EZKF_SPROD'
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
      'where IDNOMREST_SPROD=:PARAM_IDNOMREST')
    ModifySQL.Strings = (
      'update SSPROD'
      'set'
      '  ID_SPROD = :ID_SPROD,'
      '  IDNOMREST_SPROD = :IDNOMREST_SPROD,'
      '  IDNOM_SPROD = :IDNOM_SPROD,'
      '  NKOL_SPROD = :NKOL_SPROD,'
      '  BKOL_SPROD = :BKOL_SPROD,'
      '  KFPRICE_SPROD = :KFPRICE_SPROD,'
      '  IDKOMPL_SPROD = :IDKOMPL_SPROD,'
      '  SPIS_SPROD = :SPIS_SPROD,'
      '  IDED_SPROD = :IDED_SPROD,'
      '  KF_SPROD = :KF_SPROD,'
      '  GID_SSPROD = :GID_SSPROD'
      'where'
      '  ID_SPROD = :OLD_ID_SPROD')
    GeneratorField.Field = 'ID_SPROD'
    GeneratorField.Generator = 'GEN_SSPROD_ID'
    Left = 136
    Top = 16
    object TableID_SPROD: TIntegerField
      FieldName = 'ID_SPROD'
      Origin = 'SSPROD.ID_SPROD'
      Required = True
    end
    object TableIDNOM_SPROD: TIntegerField
      FieldName = 'IDNOM_SPROD'
      Origin = 'SSPROD.IDNOM_SPROD'
    end
    object TableNKOL_SPROD: TIBBCDField
      FieldName = 'NKOL_SPROD'
      Origin = 'SSPROD.NKOL_SPROD'
      Precision = 18
      Size = 3
    end
    object TableBKOL_SPROD: TIBBCDField
      FieldName = 'BKOL_SPROD'
      Origin = 'SSPROD.BKOL_SPROD'
      Precision = 18
      Size = 3
    end
    object TableKFPRICE_SPROD: TIBBCDField
      FieldName = 'KFPRICE_SPROD'
      Origin = 'SSPROD.KFPRICE_SPROD'
      Precision = 18
      Size = 3
    end
    object TableIDKOMPL_SPROD: TIntegerField
      FieldName = 'IDKOMPL_SPROD'
      Origin = 'SSPROD.IDKOMPL_SPROD'
    end
    object TableNAMENOM: TIBStringField
      FieldName = 'NAMENOM'
      Origin = 'SNOM.NAMENOM'
      Size = 50
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableSPIS_SPROD: TSmallintField
      FieldName = 'SPIS_SPROD'
      Origin = 'SSPROD.SPIS_SPROD'
      OnGetText = TableSPIS_SPRODGetText
      OnSetText = TableSPIS_SPRODSetText
    end
    object TableIDED_SPROD: TIntegerField
      FieldName = 'IDED_SPROD'
      Origin = 'SSPROD.IDED_SPROD'
    end
    object TableKF_SPROD: TIBBCDField
      FieldName = 'KF_SPROD'
      Origin = 'SSPROD.KF_SPROD'
      Precision = 18
      Size = 3
    end
    object TableNAMEED: TIBStringField
      FieldName = 'NAMEED'
      Origin = 'SED.NAMEED'
      Size = 50
    end
    object TableTNOM: TIntegerField
      FieldName = 'TNOM'
      Origin = 'SNOM.TNOM'
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
    object TableVALUE_SSEZKF: TIBBCDField
      FieldName = 'VALUE_SSEZKF'
      Origin = 'SSEZKF.VALUE_SSEZKF'
      Precision = 18
      Size = 3
    end
    object TableSEZKF: TFloatField
      FieldKind = fkCalculated
      FieldName = 'SEZKF'
      Calculated = True
    end
    object TableVALUE_SSEZKF_SPROD: TIBBCDField
      FieldName = 'VALUE_SSEZKF_SPROD'
      Origin = 'SSEZKF_SPROD.VALUE_SSEZKF_SPROD'
      Precision = 18
      Size = 3
    end
    object TableSEZKF_SPROD: TFloatField
      FieldKind = fkCalculated
      FieldName = 'SEZKF_SPROD'
      Calculated = True
    end
    object TableIDNOMREST_SPROD: TIntegerField
      FieldName = 'IDNOMREST_SPROD'
      Origin = 'SSPROD.IDNOMREST_SPROD'
    end
    object TableGID_SSPROD: TIBStringField
      FieldName = 'GID_SSPROD'
      Origin = 'SSPROD.GID_SSPROD'
      Size = 10
    end
  end
end
