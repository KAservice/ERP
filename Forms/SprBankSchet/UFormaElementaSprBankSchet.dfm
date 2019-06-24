object FormaElementaSprBankSchet: TFormaElementaSprBankSchet
  Left = 519
  Top = 16
  HelpContext = 3
  Caption = #1041#1072#1085#1082#1086#1074#1089#1082#1080#1081' '#1089#1095#1077#1090':'
  ClientHeight = 343
  ClientWidth = 429
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
    Left = 30
    Top = 39
    Width = 102
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
  end
  object Label2: TLabel
    Left = 30
    Top = 98
    Width = 49
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1057#1095#1077#1090' '#8470
  end
  object Label3: TLabel
    Left = 30
    Top = 158
    Width = 32
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1041#1072#1085#1082
  end
  object Label4: TLabel
    Left = 110
    Top = 236
    Width = 204
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1055#1088#1077#1092#1080#1082#1089' '#1085#1086#1084#1077#1088#1086#1074' '#1076#1086#1082#1091#1084#1077#1085#1090#1086#1074':'
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 30
    Top = 62
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAMEBSCHET'
    TabOrder = 0
    OnKeyDown = NamecxDBTextEditKeyDown
    Width = 385
  end
  object NumcxDBTextEdit: TcxDBTextEdit
    Left = 30
    Top = 121
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NUMBSCHET'
    TabOrder = 1
    OnKeyDown = NumcxDBTextEditKeyDown
    Width = 385
  end
  object NameBankcxDBButtonEdit: TcxDBButtonEdit
    Left = 30
    Top = 185
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAMEBANK'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ClickKey = 13
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameBankcxDBButtonEditPropertiesButtonClick
    TabOrder = 2
    Width = 385
  end
  object cxButtonClose: TcxButton
    Left = 322
    Top = 295
    Width = 93
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 5
  end
  object cxButtonOK: TcxButton
    Left = 215
    Top = 295
    Width = 93
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionOK
    TabOrder = 4
  end
  object IdBSchetcxDBLabel: TcxDBLabel
    Left = 30
    Top = 0
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'IDBSCHET'
    Height = 26
    Width = 208
  end
  object cxLabel1: TcxLabel
    Left = 0
    Top = 0
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'ID:'
  end
  object PrefiksNumDoccxDBTextEdit: TcxDBTextEdit
    Left = 322
    Top = 233
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'PREFIKS_NUM_SBSCHET'
    TabOrder = 3
    OnKeyDown = NumcxDBTextEditKeyDown
    Width = 93
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 312
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
