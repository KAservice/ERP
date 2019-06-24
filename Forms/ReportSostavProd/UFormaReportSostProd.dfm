object FormaReportSostProd: TFormaReportSostProd
  Left = 383
  Top = 95
  Caption = #1054#1090#1095#1077#1090' '#1086' '#1089#1086#1089#1090#1072#1074#1077' '#1087#1088#1086#1076#1091#1082#1094#1080#1080
  ClientHeight = 235
  ClientWidth = 556
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 120
  TextHeight = 16
  object Label1: TLabel
    Left = 20
    Top = 79
    Width = 100
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072':'
  end
  object Label2: TLabel
    Left = 59
    Top = 118
    Width = 55
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1058#1080#1087' '#1094#1077#1085':'
  end
  object Label3: TLabel
    Left = 128
    Top = 10
    Width = 276
    Height = 26
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1054#1090#1095#1077#1090' '#1086' '#1089#1086#1089#1090#1072#1074#1077' '#1087#1088#1086#1076#1091#1082#1094#1080#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object cxButtonCreate: TcxButton
    Left = 286
    Top = 177
    Width = 121
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1057#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 0
    OnClick = cxButtonCreateClick
  end
  object cxButtonClose: TcxButton
    Left = 415
    Top = 177
    Width = 92
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 1
  end
  object TypePriceComboBox: TcxComboBox
    Left = 134
    Top = 113
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Properties.DropDownListStyle = lsFixedList
    Properties.OnChange = TypePriceComboBoxPropertiesChange
    TabOrder = 2
    Width = 355
  end
  object NameNomDBEdit: TcxButtonEdit
    Left = 134
    Top = 74
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameNomDBEditPropertiesButtonClick
    TabOrder = 3
    Text = 'NameNomDBEdit'
    Width = 355
  end
  object DataSourceNom: TDataSource
    DataSet = IBQNom
    Left = 192
    Top = 120
  end
  object IBTr: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 328
    Top = 8
  end
  object TypePrice: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from STPRICE')
    Transaction = IBTr
    Left = 280
    Top = 8
    object TypePriceID_TPRICE: TFIBBCDField
      FieldName = 'ID_TPRICE'
      Size = 0
      RoundByScale = True
    end
    object TypePriceNAME_TPRICE: TFIBWideStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
    end
  end
  object IBQNom: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      'from '
      '  SNOM'
      'where '
      '  IDNOM=:PARAM_IDNOM')
    Transaction = IBTr
    Left = 416
    Top = 16
    object IBQNomTNOM: TFIBIntegerField
      FieldName = 'TNOM'
    end
    object IBQNomCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object IBQNomIDNOM: TFIBBCDField
      FieldName = 'IDNOM'
      Size = 0
      RoundByScale = True
    end
    object IBQNomIDBASEDNOM: TFIBBCDField
      FieldName = 'IDBASEDNOM'
      Size = 0
      RoundByScale = True
    end
    object IBQNomIDOSNEDNOM: TFIBBCDField
      FieldName = 'IDOSNEDNOM'
      Size = 0
      RoundByScale = True
    end
    object IBQNomIDGRPNOM: TFIBBCDField
      FieldName = 'IDGRPNOM'
      Size = 0
      RoundByScale = True
    end
    object IBQNomIDFIRMNOM: TFIBBCDField
      FieldName = 'IDFIRMNOM'
      Size = 0
      RoundByScale = True
    end
    object IBQNomIDCOUNTRYNOM: TFIBBCDField
      FieldName = 'IDCOUNTRYNOM'
      Size = 0
      RoundByScale = True
    end
    object IBQNomNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 100
    end
    object IBQNomFNAMENOM: TFIBWideStringField
      FieldName = 'FNAMENOM'
      Size = 100
    end
    object IBQNomKRNAMENOM: TFIBWideStringField
      FieldName = 'KRNAMENOM'
      Size = 40
    end
    object IBQNomARTNOM: TFIBWideStringField
      FieldName = 'ARTNOM'
    end
    object IBQNomDESCR_SNOM: TFIBWideStringField
      FieldName = 'DESCR_SNOM'
      Size = 250
    end
  end
  object IBQNomRest: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      'from '
      '  SNOMREST'
      'where '
      '  ID_NOMREST=:PARAM_ID_NOMREST')
    Transaction = IBTr
    Left = 416
    Top = 48
    object IBQNomRestPOS_NOMREST: TFIBDateTimeField
      FieldName = 'POS_NOMREST'
    end
    object IBQNomRestKOLEDPROD_NOMREST: TFIBBCDField
      FieldName = 'KOLEDPROD_NOMREST'
      Size = 3
      RoundByScale = True
    end
    object IBQNomRestID_NOMREST: TFIBBCDField
      FieldName = 'ID_NOMREST'
      Size = 0
      RoundByScale = True
    end
    object IBQNomRestIDNOM_NOMREST: TFIBBCDField
      FieldName = 'IDNOM_NOMREST'
      Size = 0
      RoundByScale = True
    end
    object IBQNomRestIDMPRIG_NOMREST: TFIBBCDField
      FieldName = 'IDMPRIG_NOMREST'
      Size = 0
      RoundByScale = True
    end
    object IBQNomRestIDEDPROD_NOMREST: TFIBBCDField
      FieldName = 'IDEDPROD_NOMREST'
      Size = 0
      RoundByScale = True
    end
    object IBQNomRestSOST_NOMREST: TFIBWideStringField
      FieldName = 'SOST_NOMREST'
      Size = 250
    end
    object IBQNomRestTEHN_NOMREST: TFIBWideStringField
      FieldName = 'TEHN_NOMREST'
      Size = 1500
    end
    object IBQNomRestVIH_NOMREST: TFIBWideStringField
      FieldName = 'VIH_NOMREST'
      Size = 30
    end
    object IBQNomRestSROK_NOMREST: TFIBWideStringField
      FieldName = 'SROK_NOMREST'
      Size = 10
    end
    object IBQNomRestNOMER_NOMREST: TFIBWideStringField
      FieldName = 'NOMER_NOMREST'
      Size = 30
    end
    object IBQNomRestNAME_NOMREST: TFIBWideStringField
      FieldName = 'NAME_NOMREST'
      Size = 100
    end
    object IBQNomRestGID_SNOMREST: TFIBWideStringField
      FieldName = 'GID_SNOMREST'
      Size = 10
    end
  end
  object BasEd: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from SED'
      'where IDED=:PARAM_IDED')
    Transaction = IBTr
    Left = 8
    Top = 120
    object BasEdKFED: TFIBBCDField
      FieldName = 'KFED'
      Size = 3
      RoundByScale = True
    end
    object BasEdTSHED: TFIBIntegerField
      FieldName = 'TSHED'
    end
    object BasEdNEISPED: TFIBSmallIntField
      FieldName = 'NEISPED'
    end
    object BasEdIDED: TFIBBCDField
      FieldName = 'IDED'
      Size = 0
      RoundByScale = True
    end
    object BasEdIDNOMED: TFIBBCDField
      FieldName = 'IDNOMED'
      Size = 0
      RoundByScale = True
    end
    object BasEdIDOKEIED: TFIBBCDField
      FieldName = 'IDOKEIED'
      Size = 0
      RoundByScale = True
    end
    object BasEdNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
    end
    object BasEdSHED: TFIBWideStringField
      FieldName = 'SHED'
      Size = 13
    end
    object BasEdGID_SED: TFIBWideStringField
      FieldName = 'GID_SED'
      Size = 10
    end
  end
  object OsnEd: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from SED'
      'where IDED=:PARAM_IDED')
    Transaction = IBTr
    Left = 40
    Top = 120
    object OsnEdKFED: TFIBBCDField
      FieldName = 'KFED'
      Size = 3
      RoundByScale = True
    end
    object OsnEdTSHED: TFIBIntegerField
      FieldName = 'TSHED'
    end
    object OsnEdNEISPED: TFIBSmallIntField
      FieldName = 'NEISPED'
    end
    object OsnEdIDED: TFIBBCDField
      FieldName = 'IDED'
      Size = 0
      RoundByScale = True
    end
    object OsnEdIDNOMED: TFIBBCDField
      FieldName = 'IDNOMED'
      Size = 0
      RoundByScale = True
    end
    object OsnEdIDOKEIED: TFIBBCDField
      FieldName = 'IDOKEIED'
      Size = 0
      RoundByScale = True
    end
    object OsnEdNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
    end
  end
  object EdProd: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from SED'
      'where IDED=:PARAM_IDED')
    Transaction = IBTr
    Left = 72
    Top = 120
    object EdProdKFED: TFIBBCDField
      FieldName = 'KFED'
      Size = 3
      RoundByScale = True
    end
    object EdProdTSHED: TFIBIntegerField
      FieldName = 'TSHED'
    end
    object EdProdNEISPED: TFIBSmallIntField
      FieldName = 'NEISPED'
    end
    object EdProdIDED: TFIBBCDField
      FieldName = 'IDED'
      Size = 0
      RoundByScale = True
    end
    object EdProdIDNOMED: TFIBBCDField
      FieldName = 'IDNOMED'
      Size = 0
      RoundByScale = True
    end
    object EdProdIDOKEIED: TFIBBCDField
      FieldName = 'IDOKEIED'
      Size = 0
      RoundByScale = True
    end
    object EdProdNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 184
    Top = 40
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
    end
    object ActionClose: TAction
      Caption = #1047#1072#1082#1088#1099#1090#1100
      ImageIndex = 53
      OnExecute = ActionCloseExecute
    end
  end
end
