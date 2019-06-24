object HOT_DMReportSvobodNF: THOT_DMReportSvobodNF
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 125
  Width = 300
  object Report: TpFIBDataSet
    SelectSQL.Strings = (
      
        'select * from HOT_REPORT_SVOBOD_NF (:PARAM_POSNACH,:PARAM_POSCON' +
        ')'
      '        ')
    Transaction = pFIBTr
    Left = 120
    Top = 32
    object ReportOUT_KOL_MEST_ALL: TFIBIntegerField
      FieldName = 'OUT_KOL_MEST_ALL'
    end
    object ReportOUT_KOL_MEST_ZAN: TFIBIntegerField
      FieldName = 'OUT_KOL_MEST_ZAN'
    end
    object ReportOUT_KOL_MEST_SVOB: TFIBIntegerField
      FieldName = 'OUT_KOL_MEST_SVOB'
    end
    object ReportOUT_ID_NF: TFIBBCDField
      FieldName = 'OUT_ID_NF'
      Size = 0
      RoundByScale = True
    end
    object ReportOUT_NAME_OBJECT: TFIBWideStringField
      FieldName = 'OUT_NAME_OBJECT'
      Size = 100
    end
    object ReportOUT_NAME_CAT: TFIBWideStringField
      FieldName = 'OUT_NAME_CAT'
      Size = 100
    end
    object ReportOUT_NAME_NOM: TFIBWideStringField
      FieldName = 'OUT_NAME_NOM'
      Size = 100
    end
  end
  object pFIBTr: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 200
    Top = 32
  end
  object DataSourceReport: TDataSource
    DataSet = Report
    Left = 40
    Top = 32
  end
end
