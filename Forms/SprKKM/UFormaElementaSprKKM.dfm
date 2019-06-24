object FormaElementaSprKKM: TFormaElementaSprKKM
  Left = 434
  Top = 316
  Caption = #1069#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1050#1050#1052'"'
  ClientHeight = 253
  ClientWidth = 516
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
    Top = 49
    Width = 102
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
  end
  object Label2: TLabel
    Left = 20
    Top = 79
    Width = 108
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1072#1090#1072#1083#1086#1075' '#1086#1073#1084#1077#1085#1072':'
  end
  object Label3: TLabel
    Left = 156
    Top = 153
    Width = 204
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1055#1088#1077#1092#1080#1082#1089' '#1085#1086#1084#1077#1088#1086#1074' '#1076#1086#1082#1091#1084#1077#1085#1090#1086#1074':'
  end
  object cxButtonOK: TcxButton
    Left = 292
    Top = 206
    Width = 93
    Height = 30
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionOK
    TabOrder = 3
  end
  object cxButtonClose: TcxButton
    Left = 392
    Top = 206
    Width = 92
    Height = 30
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 4
  end
  object CatalogcxDBTextEdit: TcxDBTextEdit
    Left = 10
    Top = 102
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'CATOBMKKM'
    TabOrder = 1
    OnKeyDown = CatalogcxDBTextEditKeyDown
    Width = 474
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 124
    Top = 44
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAMEKKM'
    TabOrder = 0
    OnKeyDown = NamecxDBTextEditKeyDown
    Width = 360
  end
  object PrefiksNumDoccxDBTextEdit: TcxDBTextEdit
    Left = 368
    Top = 150
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'PREFIKS_NUM_SKKM'
    TabOrder = 2
    OnKeyDown = CatalogcxDBTextEditKeyDown
    Width = 115
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 328
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
    object ActionOK: TAction
      Caption = #1054#1050
      ImageIndex = 54
      OnExecute = ActionOKExecute
    end
  end
end
