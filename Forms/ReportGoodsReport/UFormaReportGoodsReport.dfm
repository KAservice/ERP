object FormaReportGoodsReport: TFormaReportGoodsReport
  Left = 308
  Top = 124
  Caption = #1058#1086#1074#1072#1088#1085#1099#1081' '#1086#1090#1095#1077#1090':'
  ClientHeight = 257
  ClientWidth = 450
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
  object Label1: TLabel
    Left = 24
    Top = 8
    Width = 168
    Height = 26
    Caption = #1058#1086#1074#1072#1088#1085#1099#1081' '#1086#1090#1095#1077#1090' '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 48
    Width = 12
    Height = 26
    Caption = 'c'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 208
    Top = 43
    Width = 24
    Height = 26
    Caption = #1087#1086
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 38
    Top = 143
    Width = 34
    Height = 13
    Caption = #1057#1082#1083#1072#1076':'
  end
  object Label6: TLabel
    Left = 32
    Top = 114
    Width = 40
    Height = 13
    Caption = #1060#1080#1088#1084#1072':'
  end
  object cxButtonCreateReport: TcxButton
    Left = 256
    Top = 216
    Width = 99
    Height = 25
    Caption = #1055#1086' '#1089#1077#1073#1077#1089#1090#1086#1080#1084#1086#1089#1090#1080
    TabOrder = 0
    OnClick = cxButtonCreateReportClick
  end
  object cxButtonClose: TcxButton
    Left = 361
    Top = 216
    Width = 75
    Height = 25
    Action = ActionClose
    TabOrder = 1
  end
  object GroupCheckPoDateCheckBox: TcxCheckBox
    Left = 24
    Top = 179
    Caption = #1075#1088#1091#1087#1087#1080#1088#1086#1074#1072#1090#1100' '#1095#1077#1082#1080' '#1087#1086' '#1076#1072#1090#1077
    TabOrder = 2
    Width = 161
  end
  object NameSkladEdit: TcxButtonEdit
    Left = 96
    Top = 141
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end
      item
        Caption = 'X'
        Kind = bkText
      end>
    Properties.ClickKey = 0
    Properties.OnButtonClick = NameSkladEditPropertiesButtonClick
    TabOrder = 3
    Text = 'NameSkladEdit'
    Width = 317
  end
  object NameFirmEdit: TcxButtonEdit
    Left = 96
    Top = 114
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end
      item
        Caption = 'X'
        Kind = bkText
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameFirmEditPropertiesButtonClick
    TabOrder = 4
    Text = 'NameFirmEdit'
    Width = 317
  end
  object DateNach: TcxDateEdit
    Left = 32
    Top = 52
    Properties.Kind = ckDateTime
    TabOrder = 5
    Width = 170
  end
  object DateCon: TcxDateEdit
    Left = 256
    Top = 52
    Properties.Kind = ckDateTime
    TabOrder = 6
    Width = 157
  end
  object CreateReportRozncxButton: TcxButton
    Left = 128
    Top = 216
    Width = 122
    Height = 25
    Caption = #1055#1086' '#1094#1077#1085#1072#1084' '#1088#1077#1072#1083#1080#1079#1072#1094#1080#1080
    TabOrder = 7
    OnClick = CreateReportRozncxButtonClick
  end
  object cxButtonCreateReportUnion: TcxButton
    Left = 8
    Top = 216
    Width = 114
    Height = 25
    Caption = #1054#1073#1098#1077#1076#1080#1085#1077#1085#1085#1099#1081
    TabOrder = 8
    OnClick = cxButtonCreateReportUnionClick
  end
  object cxCheckBoxSortPoTypeDoc: TcxCheckBox
    Left = 219
    Top = 179
    Caption = #1089#1086#1088#1090#1080#1088#1086#1074#1072#1090#1100' '#1087#1086' '#1090#1080#1087#1091' '#1076#1086#1082#1091#1084#1077#1085#1090#1086#1074
    TabOrder = 9
    Width = 211
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 232
    Top = 8
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
      OnExecute = ActionOpenHelpExecute
    end
    object ActionClose: TAction
      Caption = #1047#1072#1082#1088#1099#1090#1100
      ImageIndex = 53
      OnExecute = ActionCloseExecute
    end
  end
end
