object DMExportSale: TDMExportSale
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 249
  Width = 394
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
    Left = 176
    Top = 88
  end
  object Report: TpFIBDataSet
    SelectSQL.Strings = (
      'select  dchk.operchk,'
      '        snom.codenom,'
      '        snom.artnom,'
      '        snom.namenom,'
      '        SPRBASEED.NAMEED,'
      '        SPRBASEED.CODE_SED,'
      '        SPRBASEED.SHED,'
      '        SPRBASEED.KFED,'
      '        SUM(dchkt.kolchkt * dchkt.kfchkt) as KOL_SALE,'
      '        SUM(dchkt.sumchkt) as SUM_SALE'
      ''
      'from galldoc'
      'left outer join dchk on galldoc.iddoc=dchk.iddocchk'
      'left outer join dchkt on galldoc.iddoc=dchkt.iddocchkt'
      'left outer join snom on dchkt.idnomchkt=snom.idnom'
      
        'left outer join sed as SPRBASEED on SPRBASEED.IDED=snom.idbasedn' +
        'om'
      'left outer join sed as DOCED on DOCED.IDED=dchkt.idedchkt'
      'where galldoc.tdoc='#39'CHK'#39
      'and galldoc.posdoc between :PARAM_POS_NACH and :PARAM_POS_CON'
      'and galldoc.idfirmdoc=:PARAM_IDFIRM'
      'and galldoc.idskldoc=:PARAM_IDSKLAD'
      'and dchk.idkkmchk=:PARAM_IDKKM'
      '/*and dchk.operchk=:PARAM_TYPE*/'
      'group by  dchk.operchk,'
      '        snom.codenom,'
      '        snom.artnom,'
      '        snom.namenom,'
      '        SPRBASEED.NAMEED,'
      '        SPRBASEED.CODE_SED,'
      '        SPRBASEED.SHED,'
      '        SPRBASEED.KFED'
      ''
      'order by  snom.namenom')
    Transaction = pFIBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 176
    Top = 160
    object ReportOPERCHK: TFIBSmallIntField
      FieldName = 'OPERCHK'
    end
    object ReportCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object ReportARTNOM: TFIBStringField
      FieldName = 'ARTNOM'
      EmptyStrToNull = True
    end
    object ReportNAMENOM: TFIBStringField
      FieldName = 'NAMENOM'
      Size = 50
      EmptyStrToNull = True
    end
    object ReportNAMEED: TFIBStringField
      FieldName = 'NAMEED'
      Size = 50
      EmptyStrToNull = True
    end
    object ReportCODE_SED: TFIBIntegerField
      FieldName = 'CODE_SED'
    end
    object ReportSHED: TFIBStringField
      FieldName = 'SHED'
      Size = 13
      EmptyStrToNull = True
    end
    object ReportKFED: TFIBBCDField
      FieldName = 'KFED'
      Size = 3
      RoundByScale = True
    end
    object ReportKOL_SALE: TFIBFloatField
      FieldName = 'KOL_SALE'
    end
    object ReportSUM_SALE: TFIBBCDField
      FieldName = 'SUM_SALE'
      Size = 2
      RoundByScale = True
    end
  end
  object DataSourceReport: TDataSource
    DataSet = Report
    Left = 104
    Top = 160
  end
end
