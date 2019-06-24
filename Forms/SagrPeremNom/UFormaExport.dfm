object FormaExport: TFormaExport
  Left = 204
  Top = 177
  Caption = #1042#1099#1075#1088#1091#1079#1082#1072' '#1086#1090#1095#1077#1090#1086#1074' '#1050#1050#1052
  ClientHeight = 500
  ClientWidth = 781
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
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 781
    Height = 500
    Align = alClient
    TabOrder = 0
    object Panel3: TPanel
      Left = 1
      Top = 1
      Width = 779
      Height = 104
      Align = alTop
      BevelOuter = bvNone
      TabOrder = 0
      object Label2: TLabel
        Left = 8
        Top = 24
        Width = 84
        Height = 24
        Caption = #1054#1090#1095#1077#1090#1099' '#1089
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label1: TLabel
        Left = 216
        Top = 24
        Width = 22
        Height = 24
        Caption = #1087#1086
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object DateCon: TDateTimePicker
        Left = 240
        Top = 24
        Width = 97
        Height = 24
        Date = 38544.624789849500000000
        Time = 38544.624789849500000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
      end
      object DateNach: TDateTimePicker
        Left = 112
        Top = 24
        Width = 97
        Height = 24
        Date = 38820.444804143500000000
        Time = 38820.444804143500000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
      end
    end
    object Panel4: TPanel
      Left = 1
      Top = 105
      Width = 8
      Height = 317
      Align = alLeft
      BevelOuter = bvNone
      TabOrder = 1
    end
    object Panel5: TPanel
      Left = 765
      Top = 105
      Width = 15
      Height = 317
      Align = alRight
      BevelOuter = bvNone
      TabOrder = 2
    end
    object Panel6: TPanel
      Left = 1
      Top = 422
      Width = 779
      Height = 77
      Align = alBottom
      BevelOuter = bvNone
      TabOrder = 3
      ExplicitTop = 423
      object cxButtonCreate: TcxButton
        Left = 17
        Top = 24
        Width = 120
        Height = 41
        Caption = #1057#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100
        TabOrder = 0
        OnClick = cxButtonCreateClick
      end
    end
    object RichEdit1: TRichEdit
      Left = 9
      Top = 105
      Width = 756
      Height = 317
      Align = alClient
      Lines.Strings = (
        'RichEdit1')
      TabOrder = 4
    end
  end
  object DataSource2: TDataSource
    DataSet = IBQuery2
    Left = 400
    Top = 56
  end
  object ADOTable1: TADOTable
    Left = 408
    Top = 16
  end
  object ADOTable2: TADOTable
    Left = 344
    Top = 64
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
    Left = 536
    Top = 24
  end
  object IBQuery2: TpFIBDataSet
    SelectSQL.Strings = (
      'select'
      'DCHKT.*, NAMENOM, CODENOM, NAMEED , SHED'
      'from DCHKT '
      'left outer join  SNOM on IDNOMCHKT=IDNOM'
      'left outer join SED on IDEDCHKT=IDED'
      'where IDDOCCHKT=:IDDOC')
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 536
    Top = 64
    object IBQuery2IDCHKT: TFIBIntegerField
      FieldName = 'IDCHKT'
    end
    object IBQuery2IDDOCCHKT: TFIBIntegerField
      FieldName = 'IDDOCCHKT'
    end
    object IBQuery2IDNOMCHKT: TFIBIntegerField
      FieldName = 'IDNOMCHKT'
    end
    object IBQuery2IDEDCHKT: TFIBIntegerField
      FieldName = 'IDEDCHKT'
    end
    object IBQuery2KOLCHKT: TFIBBCDField
      FieldName = 'KOLCHKT'
      Size = 3
      RoundByScale = True
    end
    object IBQuery2KFCHKT: TFIBBCDField
      FieldName = 'KFCHKT'
      Size = 3
      RoundByScale = True
    end
    object IBQuery2PRICECHKT: TFIBBCDField
      FieldName = 'PRICECHKT'
      Size = 2
      RoundByScale = True
    end
    object IBQuery2SUMCHKT: TFIBBCDField
      FieldName = 'SUMCHKT'
      Size = 2
      RoundByScale = True
    end
    object IBQuery2SKCHKT: TFIBBCDField
      FieldName = 'SKCHKT'
      Size = 2
      RoundByScale = True
    end
    object IBQuery2NADCHKT: TFIBBCDField
      FieldName = 'NADCHKT'
      Size = 2
      RoundByScale = True
    end
    object IBQuery2PRICEFULLCHKT: TFIBBCDField
      FieldName = 'PRICEFULLCHKT'
      Size = 2
      RoundByScale = True
    end
    object IBQuery2PRSKCHKT: TFIBBCDField
      FieldName = 'PRSKCHKT'
      Size = 2
      RoundByScale = True
    end
    object IBQuery2PRNADCHKT: TFIBBCDField
      FieldName = 'PRNADCHKT'
      Size = 2
      RoundByScale = True
    end
    object IBQuery2GID_DCHKT: TFIBStringField
      FieldName = 'GID_DCHKT'
      Size = 10
      EmptyStrToNull = True
    end
    object IBQuery2NAMENOM: TFIBStringField
      FieldName = 'NAMENOM'
      Size = 50
      EmptyStrToNull = True
    end
    object IBQuery2CODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object IBQuery2NAMEED: TFIBStringField
      FieldName = 'NAMEED'
      Size = 50
      EmptyStrToNull = True
    end
    object IBQuery2SHED: TFIBStringField
      FieldName = 'SHED'
      Size = 13
      EmptyStrToNull = True
    end
  end
  object ActionList: TActionList
    Left = 184
    Top = 40
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
    end
  end
end
