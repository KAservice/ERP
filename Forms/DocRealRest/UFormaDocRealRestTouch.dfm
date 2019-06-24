object FormaDocRealRestTouch: TFormaDocRealRestTouch
  Left = 188
  Top = 123
  Caption = #1040#1082#1090' '#1088#1077#1072#1083#1080#1079#1072#1094#1080#1080' '#1088#1077#1089#1090#1086#1088#1072#1085#1072
  ClientHeight = 532
  ClientWidth = 752
  Color = clBtnFace
  Constraints.MinWidth = 760
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  WindowState = wsMaximized
  OnClose = FormClose
  OnCreate = FormCreate
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TPanel
    Left = 0
    Top = 209
    Width = 15
    Height = 214
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 0
  end
  object Panel3: TPanel
    Left = 0
    Top = 423
    Width = 752
    Height = 109
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object FSummaCheck: TLabel
      Left = 520
      Top = 16
      Width = 70
      Height = 24
      Caption = #1057#1091#1084#1084#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBTextFNameUser: TDBText
      Left = 8
      Top = 88
      Width = 119
      Height = 16
      AutoSize = True
      DataField = 'NAME_USER'
      DataSource = DMDocRealRest.DataSourceDocAll
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object SumDocDBText: TDBText
      Left = 592
      Top = 16
      Width = 135
      Height = 24
      AutoSize = True
      DataField = 'SUMDOC'
      DataSource = DMDocRealRest.DataSourceDocAll
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object ButtonClose: TButton
      Left = 656
      Top = 48
      Width = 75
      Height = 57
      Caption = #1047#1072#1082#1088#1099#1090#1100
      TabOrder = 0
      OnClick = ButtonCloseClick
    end
    object ButtonOK: TButton
      Left = 576
      Top = 48
      Width = 75
      Height = 57
      Caption = 'OK'
      TabOrder = 1
      OnClick = ButtonOKClick
    end
    object ButtonPrint: TButton
      Left = 496
      Top = 48
      Width = 75
      Height = 57
      Caption = #1055#1077#1095#1072#1090#1100
      TabOrder = 2
      OnClick = ButtonPrintClick
    end
  end
  object Panel4: TPanel
    Left = 743
    Top = 209
    Width = 9
    Height = 214
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 2
  end
  object DBGrid1: TDBGrid
    Left = 15
    Top = 209
    Width = 728
    Height = 214
    Align = alClient
    DataSource = DMDocRealRest.DataSourceDocT
    Options = [dgEditing, dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgConfirmDelete, dgCancelOnExit]
    TabOrder = 3
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'RECNO'
        Title.Caption = #8470
        Width = 34
        Visible = True
      end
      item
        ButtonStyle = cbsEllipsis
        Expanded = False
        FieldName = 'NAMENOM'
        Title.Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
        Width = 292
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'KOL_REALRESTT'
        Title.Caption = #1050#1086#1083
        Width = 52
        Visible = True
      end
      item
        ButtonStyle = cbsEllipsis
        Expanded = False
        FieldName = 'NAMEED'
        Title.Caption = #1045#1076#1080#1085#1080#1094#1072
        Width = 81
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'KF_REALRESTT'
        Title.Caption = #1050#1086#1101#1092#1092'.'
        Width = 65
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'PRICE_REALRESTT'
        Title.Caption = #1062#1077#1085#1072
        Width = 77
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'SUM_REALRESTT'
        Title.Caption = #1057#1091#1084#1084#1072
        Width = 83
        Visible = True
      end>
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 752
    Height = 209
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 4
    object LabelNameDoc: TLabel
      Left = 8
      Top = 72
      Width = 233
      Height = 29
      Caption = #1040#1082#1090' '#1088#1077#1072#1083#1080#1079#1072#1094#1080#1080' '#8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -24
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object LabelPrim: TLabel
      Left = 16
      Top = 168
      Width = 66
      Height = 13
      Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077':'
    end
    object LabelFirm: TLabel
      Left = 8
      Top = 13
      Width = 54
      Height = 16
      Caption = #1060#1080#1088#1084#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object LabelSklad: TLabel
      Left = 368
      Top = 13
      Width = 50
      Height = 16
      Caption = #1057#1082#1083#1072#1076':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object LabelKlient: TLabel
      Left = 8
      Top = 120
      Width = 90
      Height = 20
      Caption = 'LabelKlient'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
  end
end
