object FormaReportOdinCod: TFormaReportOdinCod
  Left = 383
  Top = 95
  Caption = #1054#1090#1095#1077#1090' '#1086' '#1089#1086#1089#1090#1072#1074#1077' '#1087#1088#1086#1076#1091#1082#1094#1080#1080
  ClientHeight = 117
  ClientWidth = 265
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Label3: TLabel
    Left = 8
    Top = 8
    Width = 164
    Height = 24
    Caption = #1054#1076#1080#1085#1072#1082#1086#1074#1099#1077' '#1082#1086#1076#1099
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object ButtonCreateReport: TButton
    Left = 72
    Top = 80
    Width = 83
    Height = 25
    Caption = #1057#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 0
    OnClick = ButtonCreateReportClick
  end
  object ButtonClose: TButton
    Left = 160
    Top = 80
    Width = 83
    Height = 25
    Caption = #1047#1072#1082#1088#1099#1090#1100
    TabOrder = 1
    OnClick = ButtonCloseClick
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
    Left = 224
    Top = 40
  end
  object Nom: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      'from '
      '  SNOM'
      'where '
      '  IDNOM!=:PARAM_IDNOM   AND CODENOM=:PARAM_CODENOM')
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 192
    Top = 40
    object NomTNOM: TFIBIntegerField
      FieldName = 'TNOM'
    end
    object NomCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object NomNAMENOM: TFIBStringField
      FieldName = 'NAMENOM'
      Size = 50
      EmptyStrToNull = True
    end
    object NomFNAMENOM: TFIBStringField
      FieldName = 'FNAMENOM'
      Size = 100
      EmptyStrToNull = True
    end
    object NomKRNAMENOM: TFIBStringField
      FieldName = 'KRNAMENOM'
      Size = 40
      EmptyStrToNull = True
    end
    object NomARTNOM: TFIBStringField
      FieldName = 'ARTNOM'
      EmptyStrToNull = True
    end
    object NomGID_SNOM: TFIBStringField
      FieldName = 'GID_SNOM'
      Size = 10
      EmptyStrToNull = True
    end
    object NomDESCR_SNOM: TFIBStringField
      FieldName = 'DESCR_SNOM'
      Size = 1000
      EmptyStrToNull = True
    end
    object NomSTNDSNOM: TFIBIntegerField
      FieldName = 'STNDSNOM'
    end
    object NomGTDNOM: TFIBStringField
      FieldName = 'GTDNOM'
      Size = 30
      EmptyStrToNull = True
    end
    object NomIDNOM: TFIBBCDField
      FieldName = 'IDNOM'
      Size = 0
      RoundByScale = True
    end
    object NomIDBASEDNOM: TFIBBCDField
      FieldName = 'IDBASEDNOM'
      Size = 0
      RoundByScale = True
    end
    object NomIDOSNEDNOM: TFIBBCDField
      FieldName = 'IDOSNEDNOM'
      Size = 0
      RoundByScale = True
    end
    object NomIDGRPNOM: TFIBBCDField
      FieldName = 'IDGRPNOM'
      Size = 0
      RoundByScale = True
    end
    object NomIDFIRMNOM: TFIBBCDField
      FieldName = 'IDFIRMNOM'
      Size = 0
      RoundByScale = True
    end
    object NomIDCOUNTRYNOM: TFIBBCDField
      FieldName = 'IDCOUNTRYNOM'
      Size = 0
      RoundByScale = True
    end
  end
  object SpisokNom: TpFIBDataSet
    SelectSQL.Strings = (
      'select IDNOM, CODENOM, NAMENOM from SNOM')
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 160
    Top = 40
    object SpisokNomCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object SpisokNomNAMENOM: TFIBStringField
      FieldName = 'NAMENOM'
      Size = 50
      EmptyStrToNull = True
    end
    object SpisokNomIDNOM: TFIBBCDField
      FieldName = 'IDNOM'
      Size = 0
      RoundByScale = True
    end
  end
  object ActionList: TActionList
    Left = 96
    Top = 40
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
    end
  end
end
