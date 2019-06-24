object FormaReportDvDoc: TFormaReportDvDoc
  Left = 198
  Top = 115
  Caption = #1044#1074#1080#1078#1077#1085#1080#1103' '#1076#1086#1082#1091#1084#1077#1085#1090#1072
  ClientHeight = 131
  ClientWidth = 410
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object IBQ: TpFIBDataSet
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 136
    Top = 16
  end
  object DvRegOstNom: TpFIBDataSet
    SelectSQL.Strings = (
      'select '
      '  RGOSTNOM_DV.*, NAMEFIRM, NAMENOM, CODEPART, DOCPART, NAMESKLAD'
      'from '
      '  RGOSTNOM_DV'
      'left outer join SFIRM on IDFIRM_OSTNOMDV=IDFIRM'
      'left outer join SNOM on  IDNOM_OSTNOMDV=IDNOM'
      'left outer join SPART on IDPART_OSTNOMDV=IDPART'
      'left outer join SSKLAD on IDSKL_OSTNOMDV=IDSKLAD'
      ''
      'where IDDOC_OSTNOMDV=:PARAM_IDDOC')
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 136
    Top = 64
    object DvRegOstNomPOSDOC_OSTNOMDV: TFIBDateTimeField
      FieldName = 'POSDOC_OSTNOMDV'
    end
    object DvRegOstNomTDV_OSTNOMDV: TFIBSmallIntField
      FieldName = 'TDV_OSTNOMDV'
    end
    object DvRegOstNomSUM_OSTNOMDV: TFIBBCDField
      FieldName = 'SUM_OSTNOMDV'
      Size = 2
      RoundByScale = True
    end
    object DvRegOstNomKOL_OSTNOMDV: TFIBBCDField
      FieldName = 'KOL_OSTNOMDV'
      Size = 3
      RoundByScale = True
    end
    object DvRegOstNomOPER_OSTNOMDV: TFIBIntegerField
      FieldName = 'OPER_OSTNOMDV'
    end
    object DvRegOstNomSUM2_OSTNOMDV: TFIBBCDField
      FieldName = 'SUM2_OSTNOMDV'
      Size = 2
      RoundByScale = True
    end
    object DvRegOstNomNAMEFIRM: TFIBStringField
      FieldName = 'NAMEFIRM'
      Size = 50
      EmptyStrToNull = True
    end
    object DvRegOstNomNAMENOM: TFIBStringField
      FieldName = 'NAMENOM'
      Size = 50
      EmptyStrToNull = True
    end
    object DvRegOstNomCODEPART: TFIBIntegerField
      FieldName = 'CODEPART'
    end
    object DvRegOstNomDOCPART: TFIBStringField
      FieldName = 'DOCPART'
      Size = 50
      EmptyStrToNull = True
    end
    object DvRegOstNomNAMESKLAD: TFIBStringField
      FieldName = 'NAMESKLAD'
      Size = 50
      EmptyStrToNull = True
    end
    object DvRegOstNomID_OSTNOMDV: TFIBBCDField
      FieldName = 'ID_OSTNOMDV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstNomIDDOC_OSTNOMDV: TFIBBCDField
      FieldName = 'IDDOC_OSTNOMDV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstNomIDFIRM_OSTNOMDV: TFIBBCDField
      FieldName = 'IDFIRM_OSTNOMDV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstNomIDSKL_OSTNOMDV: TFIBBCDField
      FieldName = 'IDSKL_OSTNOMDV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstNomIDNOM_OSTNOMDV: TFIBBCDField
      FieldName = 'IDNOM_OSTNOMDV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstNomIDPART_OSTNOMDV: TFIBBCDField
      FieldName = 'IDPART_OSTNOMDV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstNomIDSTRDOC_OSTNOMDV: TFIBBCDField
      FieldName = 'IDSTRDOC_OSTNOMDV'
      Size = 0
      RoundByScale = True
    end
  end
  object IBTr: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    CSMonitorSupport.Enabled = csmeDatabaseDriven
    TPBMode = tpbDefault
    Left = 192
    Top = 16
  end
end
