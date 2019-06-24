object DMReportVosvrat: TDMReportVosvrat
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 125
  Width = 300
  object ReportNal: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      ''
      'from drkorozn'
      'left outer join galldoc on drkorozn.iddoc_drkorozn=galldoc.iddoc'
      'left outer join SKKM on IDKKM_DRKOROZN=IDKKM'
      'where galldoc.posdoc between :PARAM_POSNACH and :PARAM_POSCON')
    Transaction = pFIBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 120
    Top = 32
    object ReportNalOPERATION_DRKOROZN: TFIBIntegerField
      FieldName = 'OPERATION_DRKOROZN'
    end
    object ReportNalNCHECK_DRKOROZN: TFIBIntegerField
      FieldName = 'NCHECK_DRKOROZN'
    end
    object ReportNalNKL_DRKOROZN: TFIBIntegerField
      FieldName = 'NKL_DRKOROZN'
    end
    object ReportNalMODEL_DRKOROZN: TFIBStringField
      FieldName = 'MODEL_DRKOROZN'
      EmptyStrToNull = True
    end
    object ReportNalREGNUM_DRKOROZN: TFIBStringField
      FieldName = 'REGNUM_DRKOROZN'
      EmptyStrToNull = True
    end
    object ReportNalSAVNUM_DRKOROZN: TFIBStringField
      FieldName = 'SAVNUM_DRKOROZN'
      EmptyStrToNull = True
    end
    object ReportNalPOSDOC: TFIBDateTimeField
      FieldName = 'POSDOC'
      DisplayFormat = 'c'
    end
    object ReportNalNUMDOC: TFIBIntegerField
      FieldName = 'NUMDOC'
    end
    object ReportNalSUMDOC: TFIBBCDField
      FieldName = 'SUMDOC'
      Size = 2
      RoundByScale = True
    end
    object ReportNalNAMEKKM: TFIBStringField
      FieldName = 'NAMEKKM'
      Size = 50
      EmptyStrToNull = True
    end
    object ReportNalIDKKM: TFIBBCDField
      FieldName = 'IDKKM'
      Size = 0
      RoundByScale = True
    end
    object ReportNalIDKKM_DRKOROZN: TFIBBCDField
      FieldName = 'IDKKM_DRKOROZN'
      Size = 0
      RoundByScale = True
    end
  end
  object pFIBTr: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    CSMonitorSupport.Enabled = csmeDatabaseDriven
    TPBMode = tpbDefault
    Left = 184
    Top = 32
  end
  object DataSourceNal: TDataSource
    DataSet = ReportNal
    Left = 40
    Top = 32
  end
end
