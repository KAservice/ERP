object HOT_DMReportRasm: THOT_DMReportRasm
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 125
  Width = 300
  object Report: TpFIBDataSet
    SelectSQL.Strings = (
      'select'
      '        hot_sobject.name_hot_sobject,'
      '        hot_scatnom.name_hot_scatnom,'
      '        hot_ssostnom.name_hot_ssostnom,'
      '        hot_snf.name_hot_snf,'
      '        sklient.nameklient,'
      '        hot_sostnf.kolm_hot_sostnf,'
      '        hot_sostnf.posnach_hot_sostnf,'
      '        hot_sostnf.poscon_hot_sostnf'
      'from hot_sostnf'
      
        'left outer join hot_snf on hot_snf.id_hot_snf=hot_sostnf.idnomer' +
        '_hot_sostnf'
      
        'left outer join hot_sobject on hot_sobject.id_hot_sobject=hot_sn' +
        'f.idob_hot_snf'
      
        'left outer join hot_scatnom on hot_scatnom.id_hot_scatnom=hot_sn' +
        'f.idcat_hot_snf'
      
        'left outer join sklient on sklient.idklient=hot_sostnf.idguest_h' +
        'ot_sostnf'
      
        'left outer join hot_ssostnom on hot_ssostnom.id_hot_ssostnom=hot' +
        '_sostnf.idsost_hot_sostnf'
      ''
      
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
    Transaction = pFIBTr
    Left = 120
    Top = 32
    object ReportKOLM_HOT_SOSTNF: TFIBIntegerField
      FieldName = 'KOLM_HOT_SOSTNF'
    end
    object ReportPOSNACH_HOT_SOSTNF: TFIBDateTimeField
      FieldName = 'POSNACH_HOT_SOSTNF'
    end
    object ReportPOSCON_HOT_SOSTNF: TFIBDateTimeField
      FieldName = 'POSCON_HOT_SOSTNF'
    end
    object ReportNAME_HOT_SOBJECT: TFIBWideStringField
      FieldName = 'NAME_HOT_SOBJECT'
      Size = 100
    end
    object ReportNAME_HOT_SCATNOM: TFIBWideStringField
      FieldName = 'NAME_HOT_SCATNOM'
      Size = 100
    end
    object ReportNAME_HOT_SSOSTNOM: TFIBWideStringField
      FieldName = 'NAME_HOT_SSOSTNOM'
      Size = 100
    end
    object ReportNAME_HOT_SNF: TFIBWideStringField
      FieldName = 'NAME_HOT_SNF'
      Size = 100
    end
    object ReportNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
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
