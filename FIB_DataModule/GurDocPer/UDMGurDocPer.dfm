object DMGurDocPer: TDMGurDocPer
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 92
  Width = 327
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 16
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select '
      '  NUMDOC, POSDOC, PRDOC, IDDOC, SUMDOC,'
      '  NAMEFIRM,'
      '  SSKLAD.NAMESKLAD,'
      '  SKLADPOL.NAMESKLAD as NAMESKLADPOL,'
      '  NAME_USER,'
      '  PRIMPER'
      ''
      'from '
      '  DPER'
      'left outer join GALLDOC on IDDOCPER=IDDOC'
      'left outer join SFIRM on IDFIRMDOC=IDFIRM'
      'left outer join SSKLAD on IDSKLDOC=IDSKLAD'
      'left outer join SUSER on  IDUSERDOC= ID_USER'
      
        'left outer join ssklad as skladpol on skladpol.idsklad=dper.idsk' +
        'lpolper'
      'where POSDOC between  :PARAM_DATE_NACH and :PARAM_DATE_CON'
      'order by POSDOC')
    Transaction = IBTr
    Left = 144
    Top = 16
    object TableNUMDOC: TFIBIntegerField
      FieldName = 'NUMDOC'
    end
    object TablePOSDOC: TFIBDateTimeField
      FieldName = 'POSDOC'
      DisplayFormat = 'c'
    end
    object TablePRDOC: TFIBSmallIntField
      FieldName = 'PRDOC'
    end
    object TableSUMDOC: TFIBBCDField
      FieldName = 'SUMDOC'
      Size = 2
      RoundByScale = True
    end
    object TableIDDOC: TFIBBCDField
      FieldName = 'IDDOC'
      Size = 0
      RoundByScale = True
    end
    object TableNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 100
    end
    object TableNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 100
    end
    object TableNAMESKLADPOL: TFIBWideStringField
      FieldName = 'NAMESKLADPOL'
      Size = 100
    end
    object TableNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
      Size = 100
    end
    object TablePRIMPER: TFIBWideStringField
      FieldName = 'PRIMPER'
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
    Left = 232
    Top = 16
  end
end
