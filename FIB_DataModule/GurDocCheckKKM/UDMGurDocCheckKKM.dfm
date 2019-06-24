object DMGurDocCheckKKM: TDMGurDocCheckKKM
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 151
  Width = 299
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 16
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select '
      '  NUMDOC, POSDOC, PRDOC, SUMDOC, IDDOC,'
      '  dchk.NCHECKCHK,'
      '  dchk.NKLCHK,'
      '  dchk.OPERCHK,'
      '  NAMEKKM,'
      '  NAMEFIRM,'
      '  NAMESKLAD, '
      '  NAMEKLIENT, '
      '  NAME_USER,'
      '  dchk.oplnalchk,'
      '  dchk.oplpcchk,'
      '  dchk.oplplatcard_all_dchk,'
      '  dchk.oplcreditcard_all_dchk,'
      '  dchk.opl_other_dchk'
      ''
      'from '
      '  DCHK'
      'left outer join SKKM on IDKKMCHK=IDKKM'
      'left outer join GALLDOC on IDDOCCHK=IDDOC'
      'left outer join SFIRM on IDFIRMDOC=IDFIRM'
      'left outer join SSKLAD on IDSKLDOC=IDSKLAD'
      'left outer join SKLIENT on IDKLDOC=IDKLIENT'
      'left outer join SUSER on  IDUSERDOC= ID_USER'
      'where POSDOC between  :PARAM_DATE_NACH and :PARAM_DATE_CON'
      'order by POSDOC')
    Transaction = IBTr
    Left = 144
    Top = 16
    poUseLargeIntField = True
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
    object TableIDDOC: TFIBLargeIntField
      FieldName = 'IDDOC'
    end
    object TableNCHECKCHK: TFIBIntegerField
      FieldName = 'NCHECKCHK'
    end
    object TableNKLCHK: TFIBIntegerField
      FieldName = 'NKLCHK'
    end
    object TableOPERCHK: TFIBIntegerField
      FieldName = 'OPERCHK'
    end
    object TableNAMEKKM: TFIBWideStringField
      FieldName = 'NAMEKKM'
      Size = 200
    end
    object TableNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 200
    end
    object TableNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 200
    end
    object TableNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 200
    end
    object TableNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
      Size = 200
    end
    object TableOPLNALCHK: TFIBBCDField
      FieldName = 'OPLNALCHK'
      Size = 2
      RoundByScale = True
    end
    object TableOPLPCCHK: TFIBBCDField
      FieldName = 'OPLPCCHK'
      Size = 2
      RoundByScale = True
    end
    object TableOPLPLATCARD_ALL_DCHK: TFIBBCDField
      FieldName = 'OPLPLATCARD_ALL_DCHK'
      Size = 2
      RoundByScale = True
    end
    object TableOPLCREDITCARD_ALL_DCHK: TFIBBCDField
      FieldName = 'OPLCREDITCARD_ALL_DCHK'
      Size = 2
      RoundByScale = True
    end
    object TableOPL_OTHER_DCHK: TFIBBCDField
      FieldName = 'OPL_OTHER_DCHK'
      Size = 2
      RoundByScale = True
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
    Left = 224
    Top = 16
  end
end
