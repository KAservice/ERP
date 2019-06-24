object REM_FormaElementaSprProducerDefect: TREM_FormaElementaSprProducerDefect
  Left = 454
  Top = 350
  Caption = #1053#1077#1080#1089#1087#1088#1072#1074#1085#1086#1089#1090#1100' '#1087#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1103
  ClientHeight = 309
  ClientWidth = 491
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
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
    Left = 102
    Top = 25
    Width = 27
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1086#1076':'
  end
  object Label3: TLabel
    Left = 20
    Top = 124
    Width = 157
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' (English):'
  end
  object cxButtonOK: TcxButton
    Left = 262
    Top = 255
    Width = 92
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionOK
    TabOrder = 1
  end
  object cxButtonClose: TcxButton
    Left = 362
    Top = 255
    Width = 92
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 2
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 20
    Top = 76
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_REM_SPRDEFECT'
    TabOrder = 0
    OnKeyDown = NamecxDBTextEditKeyDown
    Width = 448
  end
  object IdcxDBLabel: TcxDBLabel
    Left = 312
    Top = 16
    DataBinding.DataField = 'ID_REM_SPRDEFECT'
    Height = 21
    Width = 121
  end
  object CodecxDBTextEdit: TcxDBTextEdit
    Left = 136
    Top = 22
    DataBinding.DataField = 'CODE_REM_SPRDEFECT'
    TabOrder = 4
    Width = 121
  end
  object NameEngcxDBTextEdit: TcxDBTextEdit
    Left = 20
    Top = 148
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_ENG_REM_SPRDEFECT'
    TabOrder = 5
    OnKeyDown = NamecxDBTextEditKeyDown
    Width = 448
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 328
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
    object ActionOK: TAction
      Caption = #1054#1050
      ImageIndex = 54
      OnExecute = ActionOKExecute
    end
  end
end
