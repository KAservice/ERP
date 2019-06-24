object FormaElementaGurOperDiscountCard: TFormaElementaGurOperDiscountCard
  Left = 447
  Top = 118
  Caption = #1069#1083#1077#1084#1077#1085#1090' '#1078#1091#1088#1085#1072#1083#1072' "'#1054#1087#1077#1088#1072#1094#1080#1080' '#1089' '#1085#1086#1082#1086#1087#1080#1090#1077#1083#1100#1085#1099#1084#1080' '#1082#1072#1088#1090#1072#1084#1080'"'
  ClientHeight = 210
  ClientWidth = 344
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
    Left = 130
    Top = 13
    Width = 29
    Height = 13
    Caption = #1044#1072#1090#1072':'
  end
  object Label1: TLabel
    Left = 130
    Top = 134
    Width = 37
    Height = 13
    Caption = #1057#1091#1084#1084#1072':'
  end
  object Label2: TLabel
    Left = 56
    Top = 35
    Width = 34
    Height = 13
    Caption = #1057#1082#1083#1072#1076':'
  end
  object Label5: TLabel
    Left = 29
    Top = 65
    Width = 61
    Height = 13
    Caption = #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090':'
  end
  object cxButtonClose: TcxButton
    Left = 246
    Top = 171
    Width = 76
    Height = 25
    Action = ActionClose
    TabOrder = 0
  end
  object cxButtonOK: TcxButton
    Left = 165
    Top = 171
    Width = 75
    Height = 25
    Action = ActionOK
    TabOrder = 1
  end
  object cxButtonSave: TcxButton
    Left = 84
    Top = 171
    Width = 75
    Height = 25
    Action = ActionSave
    TabOrder = 2
  end
  object NameKlientcxDBButtonEdit: TcxDBButtonEdit
    Left = 96
    Top = 62
    DataBinding.DataField = 'NAMEKLIENT'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = cxDBButtonEdit1PropertiesButtonClick
    TabOrder = 3
    Width = 225
  end
  object NameCardcxDBButtonEdit: TcxDBButtonEdit
    Left = 96
    Top = 96
    DataBinding.DataField = 'NAME_SDISCOUNT_CARD'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameVidcxDBButtonEditPropertiesButtonClick
    TabOrder = 4
    Width = 225
  end
  object cxLabel1: TcxLabel
    Left = 53
    Top = 97
    Caption = #1050#1072#1088#1090#1072':'
  end
  object NameSkladcxDBButtonEdit: TcxDBButtonEdit
    Left = 96
    Top = 32
    DataBinding.DataField = 'NAMESKLAD'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameSkladcxDBButtonEditPropertiesButtonClick
    TabOrder = 6
    Width = 225
  end
  object PoscxDBDateEdit: TcxDBDateEdit
    Left = 165
    Top = 8
    DataBinding.DataField = 'POS_GUROPER_DCARD'
    Properties.Kind = ckDateTime
    TabOrder = 7
    Width = 156
  end
  object SumcxDBCalcEdit: TcxDBCalcEdit
    Left = 200
    Top = 131
    DataBinding.DataField = 'SUM_GUROPER_DCARD'
    TabOrder = 8
    Width = 121
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 16
    Top = 120
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
    object ActionSave: TAction
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      ImageIndex = 55
      OnExecute = ActionSaveExecute
    end
  end
end
