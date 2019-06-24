object FormaElementaSprCodeTel: TFormaElementaSprCodeTel
  Left = 434
  Top = 309
  Caption = #1069#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1054#1087#1077#1088#1072#1090#1086#1088#1099' '#1091#1089#1083#1091#1075' "'
  ClientHeight = 311
  ClientWidth = 559
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
    Top = 30
    Width = 99
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1086#1076' '#1090#1077#1083#1077#1092#1086#1085#1072'::'
  end
  object Label11: TLabel
    Left = 20
    Top = 118
    Width = 100
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072':'
  end
  object Label2: TLabel
    Left = 286
    Top = 30
    Width = 101
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1086#1076' '#1086#1087#1077#1088#1072#1090#1086#1088#1072':'
  end
  object Label3: TLabel
    Left = 20
    Top = 79
    Width = 102
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
  end
  object Label4: TLabel
    Left = 30
    Top = 158
    Width = 65
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1086#1084#1080#1089#1089#1080#1103':'
  end
  object Label5: TLabel
    Left = 290
    Top = 195
    Width = 125
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1055#1088#1086#1094#1077#1085#1090' '#1082#1086#1084#1080#1089#1089#1080#1080':'
  end
  object cxButtonOK: TcxButton
    Left = 359
    Top = 249
    Width = 93
    Height = 30
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionOK
    TabOrder = 0
  end
  object cxButtonClose: TcxButton
    Left = 460
    Top = 249
    Width = 92
    Height = 30
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 1
  end
  object NameComcxDBButtonEdit: TcxDBButtonEdit
    Left = 128
    Top = 154
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAMENOMCOM'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameComcxDBButtonEditPropertiesButtonClick
    TabOrder = 2
    Width = 415
  end
  object NameNomcxDBButtonEdit: TcxDBButtonEdit
    Left = 128
    Top = 113
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAMENOM'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameNomcxDBButtonEditPropertiesButtonClick
    TabOrder = 3
    Width = 415
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 128
    Top = 71
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_CODETEL'
    TabOrder = 4
    Width = 415
  end
  object CodeOpercxDBTextEdit: TcxDBTextEdit
    Left = 394
    Top = 26
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'CODOPER_CODETEL'
    TabOrder = 5
    Width = 149
  end
  object CodecxDBTextEdit: TcxDBTextEdit
    Left = 128
    Top = 26
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'CODE_CODETEL'
    TabOrder = 6
    Width = 143
  end
  object ProcentComissioncxDBCalcEdit: TcxDBCalcEdit
    Left = 422
    Top = 192
    DataBinding.DataField = 'PRCOMIS_SCODETEL'
    TabOrder = 7
    Width = 121
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 304
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
