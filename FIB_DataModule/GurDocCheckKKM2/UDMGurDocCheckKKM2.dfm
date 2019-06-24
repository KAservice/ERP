object DMGurDocCheckKKM2: TDMGurDocCheckKKM2
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 173
  Width = 261
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 16
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
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select '
      
        '  NUMDOC, POSDOC, PRDOC, SUMDOC, IDDOC, NCHECKCHK,   NKLCHK, OPE' +
        'RCHK,'
      '  NAMEKKM,'
      '  NAMEFIRM,'
      '  NAMESKLAD, '
      '  NAMEKLIENT, '
      '  NAME_USER'
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
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 144
    Top = 16
    object TableNUMDOC: TFIBIntegerField
      FieldName = 'NUMDOC'
    end
    object TablePOSDOC: TFIBDateTimeField
      FieldName = 'POSDOC'
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
      Size = 100
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
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
  end
end
