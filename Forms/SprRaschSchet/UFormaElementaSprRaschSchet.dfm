object FormaElementaSprRaschSchet: TFormaElementaSprRaschSchet
  Left = 549
  Top = 111
  Caption = #1056#1072#1089#1095#1077#1090#1085#1099#1081' '#1089#1095#1077#1090':'
  ClientHeight = 299
  ClientWidth = 476
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
  object cxButtonOK: TcxButton
    Left = 252
    Top = 236
    Width = 93
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionOK
    TabOrder = 3
  end
  object cxButtonClose: TcxButton
    Left = 352
    Top = 236
    Width = 92
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 4
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
    Width = 404
  end
  object NumcxDBTextEdit: TcxDBTextEdit
    Left = 30
    Top = 126
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NUMRSCHET'
    TabOrder = 1
    OnKeyDown = NumcxDBTextEditKeyDown
    Width = 404
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 30
    Top = 62
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAMERSCHET'
    TabOrder = 0
    OnKeyDown = NamecxDBTextEditKeyDown
    Width = 404
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 352
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
