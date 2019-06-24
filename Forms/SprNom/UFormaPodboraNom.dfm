object FormaPodboraNom: TFormaPodboraNom
  Left = 283
  Top = 113
  BorderStyle = bsDialog
  Caption = #1055#1086#1076#1073#1086#1088' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099
  ClientHeight = 221
  ClientWidth = 215
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 88
    Width = 81
    Height = 16
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 48
    Top = 120
    Width = 36
    Height = 16
    Caption = #1062#1077#1085#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 48
    Top = 152
    Width = 46
    Height = 16
    Caption = #1057#1091#1084#1084#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 8
    Top = 32
    Width = 105
    Height = 13
    Caption = #1045#1076#1080#1085#1080#1094#1072' '#1080#1079#1084#1077#1088#1077#1085#1080#1103':'
  end
  object NameNomLabel: TLabel
    Left = 0
    Top = 0
    Width = 209
    Height = 25
    Alignment = taCenter
    AutoSize = False
    Caption = 'NameNomLabel'
    WordWrap = True
  end
  object LabelKF: TLabel
    Left = 128
    Top = 32
    Width = 39
    Height = 13
    Caption = 'LabelKF'
  end
  object cxButtonOK: TcxButton
    Left = 51
    Top = 188
    Width = 75
    Height = 25
    Action = ActionOK
    TabOrder = 4
  end
  object cxButtonClose: TcxButton
    Left = 132
    Top = 188
    Width = 75
    Height = 25
    Action = ActionClose
    TabOrder = 5
  end
  object NameEdEdit: TcxButtonEdit
    Left = 8
    Top = 51
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ClickKey = 13
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameEdEditPropertiesButtonClick
    TabOrder = 0
    Text = 'NameEdEdit'
    OnKeyPress = NameEdEditKeyPress
    Width = 193
  end
  object KolEdit: TcxCalcEdit
    Left = 103
    Top = 85
    EditValue = 0.000000000000000000
    TabOrder = 1
    OnExit = KolEditExit
    OnKeyPress = KolEditKeyPress
    Width = 98
  end
  object PriceEdit: TcxCalcEdit
    Left = 103
    Top = 112
    EditValue = 0.000000000000000000
    TabOrder = 2
    OnExit = PriceEditExit
    OnKeyPress = PriceEditKeyPress
    Width = 98
  end
  object SummaEdit: TcxCalcEdit
    Left = 103
    Top = 151
    EditValue = 0.000000000000000000
    TabOrder = 3
    OnExit = SummaEditExit
    OnKeyPress = SummaEditKeyPress
    Width = 98
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 168
    Top = 96
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
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
