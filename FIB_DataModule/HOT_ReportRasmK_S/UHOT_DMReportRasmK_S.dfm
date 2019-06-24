object HOT_DMReportRasmK_S: THOT_DMReportRasmK_S
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 125
  Width = 300
  object Report: TpFIBDataSet
    SelectSQL.Strings = (
      'select'
      '        hot_sobject.name_hot_sobject,'
      '        sklient.nameklient,'
      '        scountry.name_scountry,'
      '        svidklient.name_svidklient,'
      '        hot_sostnf.kolm_hot_sostnf,'
      '        hot_sostnf.posnach_hot_sostnf,'
      '        hot_sostnf.poscon_hot_sostnf,'
      '        NAME_HOT_SCELPR'
      'from hot_sostnf'
      
        'left outer join sklient on sklient.idklient=hot_sostnf.idguest_h' +
        'ot_sostnf'
      
        'left outer join scountry on sklient.idcountryklient=scountry.id_' +
        'scountry'
      
        'left outer join svidklient on sklient.idvidklient=svidklient.id_' +
        'svidklient'
      
        'left outer join hot_snf on hot_snf.id_hot_snf=hot_sostnf.idnomer' +
        '_hot_sostnf'
      
        'left outer join hot_sobject on hot_sobject.id_hot_sobject=hot_sn' +
        'f.idob_hot_snf'
      'left outer join HOT_SCELPR on IDCEL_HOT_SOSTNF=ID_HOT_SCELPR'
      
        'where (hot_sostnf.posnach_hot_sostnf between :PARAM_POSNACH and ' +
        ':PARAM_POSCON)'
      
        'or (hot_sostnf.poscon_hot_sostnf between :PARAM_POSNACH and :PAR' +
        'AM_POSCON)'
      
        'or (hot_sostnf.posnach_hot_sostnf<=:PARAM_POSNACH and hot_sostnf' +
        '.poscon_hot_sostnf>=:PARAM_POSCON)'
      
        'or ((hot_sostnf.posnach_hot_sostnf between :PARAM_POSNACH and :P' +
        'ARAM_POSCON)'
      
        'and (hot_sostnf.poscon_hot_sostnf between :PARAM_POSNACH and :PA' +
        'RAM_POSCON))')
    OnCalcFields = ReportCalcFields
    Transaction = pFIBTr
    Left = 120
    Top = 32
    object ReportKOLM_HOT_SOSTNF: TFIBIntegerField
      FieldName = 'KOLM_HOT_SOSTNF'
    end
    object ReportPOSNACH_HOT_SOSTNF: TFIBDateTimeField
      FieldName = 'POSNACH_HOT_SOSTNF'
      DisplayFormat = 'c'
    end
    object ReportPOSCON_HOT_SOSTNF: TFIBDateTimeField
      FieldName = 'POSCON_HOT_SOSTNF'
      DisplayFormat = 'c'
    end
    object ReportKOL_K_S: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'KOL_K_S'
      Calculated = True
    end
    object ReportKOLSUTOK: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'KOLSUTOK'
      Calculated = True
    end
    object ReportINTERVAL: TStringField
      DisplayWidth = 15
      FieldKind = fkCalculated
      FieldName = 'INTERVAL'
      Size = 10
      Calculated = True
    end
    object ReportNAME_HOT_SOBJECT: TFIBWideStringField
      FieldName = 'NAME_HOT_SOBJECT'
      Size = 100
    end
    object ReportNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 100
    end
    object ReportNAME_SCOUNTRY: TFIBWideStringField
      FieldName = 'NAME_SCOUNTRY'
      Size = 100
    end
    object ReportNAME_SVIDKLIENT: TFIBWideStringField
      FieldName = 'NAME_SVIDKLIENT'
      Size = 100
    end
    object ReportNAME_HOT_SCELPR: TFIBWideStringField
      FieldName = 'NAME_HOT_SCELPR'
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
