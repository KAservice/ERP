object DMReportSale: TDMReportSale
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 174
  Width = 221
  object IBQ: TpFIBDataSet
    SelectSQL.Strings = (
      '   select   sfirm.namefirm, rgreal_dv.idfirm_rgreal_dv,'
      '            ssklad.namesklad,rgreal_dv.idsklad_rgreal_dv,'
      '            sgrpnom.namegn,sgrpnom.idgn,'
      '            snom.namenom,snom.idnom,'
      '            sed.nameed,'
      '            sum (rgreal_dv.sumreal_rgreal_dv) as sumreal,'
      '            sum (rgreal_dv.kol_rgreal_dv)   as sumkol'
      'from '
      '  rgreal_dv'
      
        'left outer join sfirm  on rgreal_dv.idfirm_rgreal_dv=sfirm.idfir' +
        'm'
      
        'left outer join ssklad on rgreal_dv.idsklad_rgreal_dv=ssklad.ids' +
        'klad'
      'left outer join snom on rgreal_dv.idnom_rgreal_dv=snom.idnom'
      'left outer join sgrpnom on snom.idgrpnom=sgrpnom.idgn'
      'left outer join sed on sed.ided=snom.idbasednom'
      ''
      
        'where (POSDOC_RGREAL_DV  between :PARAM_POSNACH and :PARAM_POSCO' +
        'N)  and'
      '        rgreal_dv.idfirm_rgreal_dv=:PARAM_IDFIRM and'
      '        rgreal_dv.idsklad_rgreal_dv=:PARAM_IDSKLAD'
      ''
      'group by    sfirm.namefirm, rgreal_dv.idfirm_rgreal_dv,'
      '            ssklad.namesklad,rgreal_dv.idsklad_rgreal_dv,'
      '            sgrpnom.namegn,'
      '            sgrpnom.idgn,'
      '            snom.namenom,'
      '            snom.idnom,'
      '            sed.nameed')
    Transaction = pFIBTr
    Left = 88
    Top = 32
    object IBQSUMREAL: TFIBBCDField
      FieldName = 'SUMREAL'
      Size = 2
      RoundByScale = True
    end
    object IBQSUMKOL: TFIBBCDField
      FieldName = 'SUMKOL'
      Size = 3
      RoundByScale = True
    end
    object IBQIDFIRM_RGREAL_DV: TFIBBCDField
      FieldName = 'IDFIRM_RGREAL_DV'
      Size = 0
      RoundByScale = True
    end
    object IBQIDSKLAD_RGREAL_DV: TFIBBCDField
      FieldName = 'IDSKLAD_RGREAL_DV'
      Size = 0
      RoundByScale = True
    end
    object IBQIDGN: TFIBBCDField
      FieldName = 'IDGN'
      Size = 0
      RoundByScale = True
    end
    object IBQIDNOM: TFIBBCDField
      FieldName = 'IDNOM'
      Size = 0
      RoundByScale = True
    end
    object IBQNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 100
    end
    object IBQNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 100
    end
    object IBQNAMEGN: TFIBWideStringField
      FieldName = 'NAMEGN'
      Size = 100
    end
    object IBQNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 100
    end
    object IBQNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
    end
  end
  object pFIBTr: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 88
    Top = 88
  end
end
