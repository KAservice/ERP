object FormaElementaSprNakSkidok: TFormaElementaSprNakSkidok
  Left = 447
  Top = 118
  Caption = #1069#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1053#1072#1082#1086#1087#1080#1090#1077#1083#1100#1085#1099#1077' '#1089#1082#1080#1076#1082#1080'"'
  ClientHeight = 203
  ClientWidth = 425
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
    Left = 244
    Top = 126
    Width = 46
    Height = 13
    Caption = #1055#1088#1086#1094#1077#1085#1090':'
  end
  object Label2: TLabel
    Left = 244
    Top = 99
    Width = 37
    Height = 13
    Caption = #1057#1091#1084#1084#1072':'
  end
  object Label5: TLabel
    Left = 133
    Top = 35
    Width = 34
    Height = 13
    Caption = #1057#1082#1083#1072#1076':'
  end
  object cxButtonClose: TcxButton
    Left = 339
    Top = 160
    Width = 75
    Height = 25
    Action = ActionClose
    TabOrder = 0
  end
  object cxButtonOK: TcxButton
    Left = 256
    Top = 160
    Width = 75
    Height = 25
    Action = ActionOK
    TabOrder = 1
  end
  object cxButtonSave: TcxButton
    Left = 175
    Top = 160
    Width = 75
    Height = 25
    Action = ActionSave
    TabOrder = 2
  end
  object NAmeSkladcxDBButtonEdit: TcxDBButtonEdit
    Left = 173
    Top = 35
    DataBinding.DataField = 'NAMESKLAD'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = cxDBButtonEdit1PropertiesButtonClick
    TabOrder = 3
    Width = 241
  end
  object NameVidcxDBButtonEdit: TcxDBButtonEdit
    Left = 173
    Top = 8
    DataBinding.DataField = 'NAME_SVID_DCARD'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameVidcxDBButtonEditPropertiesButtonClick
    TabOrder = 4
    Width = 241
  end
  object cxLabel1: TcxLabel
    Left = 141
    Top = 8
    Caption = #1042#1080#1076':'
  end
  object SumcxDBCalcEdit: TcxDBCalcEdit
    Left = 293
    Top = 96
    DataBinding.DataField = 'SUM_SNAK_SKIDOK'
    TabOrder = 6
    Width = 121
  end
  object ProcentcxDBCalcEdit: TcxDBCalcEdit
    Left = 293
    Top = 123
    DataBinding.DataField = 'PROCENT_SNAK_SKIDOK'
    TabOrder = 7
    Width = 121
  end
  object PeriodcxDBSpinEdit: TcxDBSpinEdit
    Left = 293
    Top = 69
    DataBinding.DataField = 'PERIOD_SNAK_SKIDOK'
    TabOrder = 8
    Width = 121
  end
  object cxLabel2: TcxLabel
    Left = 210
    Top = 73
    Caption = #1055#1077#1088#1080#1086#1076' ('#1076#1085#1077#1081'):'
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 56
    Top = 96
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
