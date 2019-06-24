object HOT_FormaElementaSprNF: THOT_FormaElementaSprNF
  Left = 385
  Top = 51
  Caption = #1069#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1053#1086#1084#1077#1088#1085#1086#1081' '#1092#1086#1085#1076'"'
  ClientHeight = 375
  ClientWidth = 449
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 120
  TextHeight = 20
  object Label1: TLabel
    Left = 10
    Top = 10
    Width = 117
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
  end
  object Label2: TLabel
    Left = 10
    Top = 65
    Width = 88
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1072#1090#1077#1075#1086#1088#1080#1103'::'
  end
  object Label3: TLabel
    Left = 10
    Top = 125
    Width = 62
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1054#1073#1098#1077#1082#1090':'
  end
  object Label4: TLabel
    Left = 129
    Top = 200
    Width = 136
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1084#1077#1089#1090':'
  end
  object Label5: TLabel
    Left = 39
    Top = 238
    Width = 219
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1044#1072#1090#1072' '#1074#1074#1086#1076#1072' '#1074' '#1101#1082#1089#1087#1083#1091#1072#1090#1072#1094#1080#1102':'
  end
  object Label6: TLabel
    Left = 29
    Top = 275
    Width = 227
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1044#1072#1090#1072' '#1074#1099#1074#1086#1076#1072' '#1080#1079' '#1101#1082#1087#1083#1091#1072#1090#1072#1094#1080#1080':'
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 10
    Top = 28
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_HOT_SNF'
    TabOrder = 0
    Width = 421
  end
  object cxButtonOK: TcxButton
    Left = 236
    Top = 335
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionOK
    TabOrder = 6
  end
  object cxButtonClose: TcxButton
    Left = 338
    Top = 334
    Width = 93
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 7
  end
  object NameCatNomcxDBButtonEdit: TcxDBButtonEdit
    Left = 10
    Top = 88
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_HOT_SCATNOM'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ClickKey = 13
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameSkladcxDBButtonEditPropertiesButtonClick
    TabOrder = 1
    Width = 421
  end
  object NameObjectcxDBButtonEdit: TcxDBButtonEdit
    Left = 10
    Top = 153
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_HOT_SOBJECT'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ClickKey = 13
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameObjectcxDBButtonEditPropertiesButtonClick
    TabOrder = 2
    Width = 421
  end
  object KolMestcxDBCalcEdit: TcxDBCalcEdit
    Left = 280
    Top = 190
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'KOLM_HOT_SNF'
    TabOrder = 3
    Width = 151
  end
  object PosIncxDBDateEdit: TcxDBDateEdit
    Left = 280
    Top = 228
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'POSIN_HOT_SNF'
    Properties.Kind = ckDateTime
    TabOrder = 4
    Width = 151
  end
  object PosOutcxDBDateEdit: TcxDBDateEdit
    Left = 280
    Top = 265
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'POSOUT_HOT_SNF'
    Properties.Kind = ckDateTime
    TabOrder = 5
    Width = 151
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 184
    Top = 40
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
