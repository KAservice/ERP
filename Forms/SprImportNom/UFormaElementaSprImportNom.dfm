object FormaElementaSprImportNom: TFormaElementaSprImportNom
  Left = 645
  Top = 0
  Caption = #1045#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1045#1076#1080#1085#1080#1094#1099' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099'"'
  ClientHeight = 239
  ClientWidth = 412
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
    Left = 36
    Top = 96
    Width = 102
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
  end
  object Label3: TLabel
    Left = 90
    Top = 59
    Width = 58
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1040#1088#1090#1080#1082#1091#1083':'
  end
  object Label5: TLabel
    Left = 62
    Top = 133
    Width = 79
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090':'
  end
  object Label6: TLabel
    Left = 204
    Top = 18
    Width = 27
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1086#1076':'
  end
  object cxButtonOK: TcxButton
    Left = 203
    Top = 187
    Width = 92
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionOK
    TabOrder = 4
  end
  object cxButtonClose: TcxButton
    Left = 303
    Top = 187
    Width = 92
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 5
  end
  object NameKlientcxDBButtonEdit: TcxDBButtonEdit
    Left = 166
    Top = 129
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAMEKLIENT'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ClickKey = 13
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameKlientcxDBButtonEditPropertiesButtonClick
    TabOrder = 3
    Width = 228
  end
  object NameEdcxDBTextEdit: TcxDBTextEdit
    Left = 169
    Top = 92
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_SIMPORTNOM'
    TabOrder = 2
    OnKeyPress = NameEdcxDBTextEditKeyPress
    Width = 227
  end
  object ArtikulcxDBTextEdit: TcxDBTextEdit
    Left = 169
    Top = 55
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'ART_SIMPORTNOM'
    TabOrder = 1
    OnKeyPress = ArtikulcxDBTextEditKeyPress
    Width = 227
  end
  object CodecxDBTextEdit: TcxDBTextEdit
    Left = 245
    Top = 15
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'CODE_SIMPORTNOM'
    TabOrder = 0
    OnKeyPress = CodecxDBTextEditKeyPress
    Width = 149
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 48
    Top = 16
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
