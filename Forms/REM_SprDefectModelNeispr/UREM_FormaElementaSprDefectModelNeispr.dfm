object REM_FormaElementaSprDefectModelNeispr: TREM_FormaElementaSprDefectModelNeispr
  Left = 645
  Top = 0
  Caption = #1069#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1044#1077#1092#1077#1082#1090#1086#1074' '#1084#1086#1076#1077#1083#1080'"'
  ClientHeight = 377
  ClientWidth = 573
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
    Left = 17
    Top = 47
    Width = 117
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
  end
  object Label3: TLabel
    Left = 9
    Top = 185
    Width = 132
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1058#1080#1087#1086#1074#1086#1081' '#1076#1077#1092#1077#1082#1090':'
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 142
    Top = 44
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_REM_SDEFECT_MODNE'
    TabOrder = 0
    Width = 408
  end
  object cxButtonOK: TcxButton
    Left = 323
    Top = 324
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionOK
    TabOrder = 1
  end
  object cxButtonClose: TcxButton
    Left = 425
    Top = 324
    Width = 93
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 2
  end
  object NameTypDefectcxDBButtonEdit: TcxDBButtonEdit
    Left = 141
    Top = 182
    DataBinding.DataField = 'NAME_REM_STYPDEFECT'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.OnButtonClick = NameNomcxDBButtonEditPropertiesButtonClick
    TabOrder = 3
    Width = 409
  end
  object CodeTypDefectcxDBLabel: TcxDBLabel
    Left = 444
    Top = 144
    DataBinding.DataField = 'CODE_REM_STYPDEFECT'
    Height = 21
    Width = 121
  end
  object DescrcxDBTextEdit: TcxDBTextEdit
    Left = 142
    Top = 100
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'DESCR_REM_SDEFECT_MODNE'
    TabOrder = 5
    Width = 408
  end
  object cxButtonTrebUslov: TcxButton
    Left = 40
    Top = 324
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1059#1079#1083#1099
    TabOrder = 6
    OnClick = cxButtonTrebUslovClick
  end
  object cxButtonTrebRabot: TcxButton
    Left = 153
    Top = 324
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1056#1072#1073#1086#1090#1099
    TabOrder = 7
    OnClick = cxButtonTrebRabotClick
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 240
    Top = 32
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
