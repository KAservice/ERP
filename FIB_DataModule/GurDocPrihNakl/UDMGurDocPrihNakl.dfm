object DMGurDocPrihNakl: TDMGurDocPrihNakl
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 173
  Width = 261
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 16
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select '
      '  NUMDOC, POSDOC, PRDOC, SUMDOC, IDDOC,'
      '  NAMEFIRM,'
      '  NAMESKLAD, '
      '  NAMEKLIENT, '
      '  NAME_USER,'
      '  RSUM_DPRN,'
      '  PRIMDOC,'
      '  NUMDOCPOST_DPRN,'
      '  POSDOCPOST_DPRN'
      'from '
      '  DPRN'
      'left outer join GALLDOC on IDDOCPRN=IDDOC'
      'left outer join SFIRM on IDFIRMDOC=IDFIRM'
      'left outer join SSKLAD on IDSKLDOC=IDSKLAD'
      'left outer join SKLIENT on IDKLDOC=IDKLIENT'
      'left outer join SUSER on  IDUSERDOC= ID_USER'
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
    object TableRSUM_DPRN: TFIBBCDField
      FieldName = 'RSUM_DPRN'
      Size = 2
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
    object TableNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 100
    end
    object TableNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
      Size = 100
    end
    object TablePRIMDOC: TFIBWideStringField
      FieldName = 'PRIMDOC'
      Size = 100
    end
    object TableNUMDOCPOST_DPRN: TFIBWideStringField
      FieldName = 'NUMDOCPOST_DPRN'
    end
    object TablePOSDOCPOST_DPRN: TFIBDateTimeField
      FieldName = 'POSDOCPOST_DPRN'
      DisplayFormat = 'c'
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
    Left = 200
    Top = 16
  end
end
