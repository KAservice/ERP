object REM_FormaElementaSprHardwareIsp: TREM_FormaElementaSprHardwareIsp
  Left = 645
  Top = 0
  Caption = #1045#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1044#1077#1090#1072#1083#1080#1079#1072#1094#1080#1103' '#1084#1086#1076#1077#1083#1080'"'
  ClientHeight = 432
  ClientWidth = 600
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 120
  TextHeight = 16
  object Label2: TLabel
    Left = 347
    Top = 179
    Width = 81
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086':'
  end
  object Label5: TLabel
    Left = 79
    Top = 122
    Width = 68
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1054#1087#1080#1089#1072#1085#1080#1077':'
  end
  object Label1: TLabel
    Left = 52
    Top = 75
    Width = 95
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1058#1080#1087#1086#1074#1086#1081' '#1091#1079#1077#1083':'
  end
  object cxButtonOK: TcxButton
    Left = 363
    Top = 388
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionOK
    TabOrder = 0
  end
  object cxButtonClose: TcxButton
    Left = 465
    Top = 388
    Width = 93
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionCloseElement
    TabOrder = 1
  end
  object NameTypUslacxDBButtonEdit: TcxDBButtonEdit
    Left = 165
    Top = 72
    DataBinding.DataField = 'NAME_REM_STYPUSLOV'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end
      item
        Caption = 'x'
        Kind = bkText
      end>
    Properties.OnButtonClick = NameTypUslacxDBButtonEditPropertiesButtonClick
    TabOrder = 2
    Width = 409
  end
  object ZayavkacxDBButtonEdit: TcxDBButtonEdit
    Left = 165
    Top = 232
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_REM_Z'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ClickKey = 13
    Properties.OnButtonClick = ZayavkacxDBButtonEditPropertiesButtonClick
    TabOrder = 3
    Width = 409
  end
  object ModelZcxDBLabel: TcxDBLabel
    Left = 165
    Top = 295
    DataBinding.DataField = 'MODEL_REM_Z'
    Height = 21
    Width = 409
  end
  object PosZcxDBLabel: TcxDBLabel
    Left = 388
    Top = 268
    DataBinding.DataField = 'POS_REM_Z'
    Height = 21
    Width = 121
  end
  object PrefikscxDBLabel: TcxDBLabel
    Left = 165
    Top = 268
    DataBinding.DataField = 'PREFIKS_NUM_REM_Z'
    Height = 21
    Width = 48
  end
  object NumZcxDBLabel: TcxDBLabel
    Left = 240
    Top = 268
    DataBinding.DataField = 'NUM_REM_Z'
    Height = 21
    Width = 121
  end
  object SerNumcxDBLabel: TcxDBLabel
    Left = 165
    Top = 322
    DataBinding.DataField = 'SERNUM_REM_Z'
    Height = 21
    Width = 289
  end
  object cxLabel20: TcxLabel
    Left = 58
    Top = 233
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072' '#1079#1072#1103#1074#1082#1091':'
  end
  object OtchitanocxDBCheckBox: TcxDBCheckBox
    Left = 267
    Top = 17
    Caption = #1086#1090#1095#1080#1090#1072#1085#1086
    DataBinding.DataField = 'FL_OTCH_PR_REM_SHARDWARE_ISP'
    Properties.ValueChecked = 1
    Properties.ValueUnchecked = 0
    TabOrder = 10
    Width = 133
  end
  object RealnoIspolsovanocxDBCheckBox: TcxDBCheckBox
    Left = 406
    Top = 17
    Caption = #1088#1077#1072#1083#1100#1085#1086' '#1080#1089#1087#1086#1083#1100#1079#1086#1074#1072#1085#1086
    DataBinding.DataField = 'FL_REAL_ISP_REM_SHARDWARE_ISP'
    Properties.ValueChecked = 1
    Properties.ValueUnchecked = 0
    TabOrder = 11
    Width = 228
  end
  object PoscxDBDateEdit: TcxDBDateEdit
    Left = 20
    Top = 17
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'POS_REM_SHARDWARE_ISP'
    Properties.Kind = ckDateTime
    TabOrder = 12
    Width = 222
  end
  object DescrcxDBMemo: TcxDBMemo
    Left = 165
    Top = 102
    DataBinding.DataField = 'DESCR_REM_SHARDWARE_ISP'
    TabOrder = 13
    Height = 59
    Width = 409
  end
  object KolcxDBCalcEdit: TcxDBCalcEdit
    Left = 453
    Top = 176
    DataBinding.DataField = 'KOL_REM_SHARDWARE_ISP'
    TabOrder = 14
    Width = 121
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 24
    Top = 9
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
    end
    object ActionSaveElement: TAction
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      ImageIndex = 55
    end
    object ActionCloseElement: TAction
      Caption = #1047#1072#1082#1088#1099#1090#1100
      ImageIndex = 53
      OnExecute = ActionCloseElementExecute
    end
    object ActionOK: TAction
      Caption = #1054#1050
      ImageIndex = 54
      OnExecute = ActionOKExecute
    end
  end
end
