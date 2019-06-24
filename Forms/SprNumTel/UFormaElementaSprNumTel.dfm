object FormaElementaSprNumTel: TFormaElementaSprNumTel
  Left = 650
  Top = 33
  Caption = #1045#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1058#1077#1083#1077#1092#1086#1085#1085#1099#1077' '#1085#1086#1084#1077#1088#1072'"'
  ClientHeight = 215
  ClientWidth = 420
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
    Width = 115
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1086#1084#1077#1088' '#1090#1077#1083#1077#1092#1086#1085#1072':'
  end
  object Label2: TLabel
    Left = 20
    Top = 30
    Width = 27
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1086#1076':'
  end
  object cxButtonOK: TcxButton
    Left = 206
    Top = 158
    Width = 92
    Height = 30
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionOK
    TabOrder = 2
  end
  object cxButtonClose: TcxButton
    Left = 305
    Top = 158
    Width = 93
    Height = 30
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 3
  end
  object NumbercxDBTextEdit: TcxDBTextEdit
    Left = 169
    Top = 75
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NUMBER_NUMTEL'
    TabOrder = 1
    OnKeyDown = NumbercxDBTextEditKeyDown
    Width = 149
  end
  object CodecxDBTextEdit: TcxDBTextEdit
    Left = 169
    Top = 26
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'CODE_NUMTEL'
    TabOrder = 0
    OnKeyDown = CodecxDBTextEditKeyDown
    Width = 149
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 64
    Top = 144
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
