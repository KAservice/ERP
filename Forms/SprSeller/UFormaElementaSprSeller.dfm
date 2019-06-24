object FormaElementaSprSeller: TFormaElementaSprSeller
  Left = 413
  Top = 248
  Caption = #1069#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' '#1055#1088#1086#1076#1072#1074#1094#1099
  ClientHeight = 397
  ClientWidth = 619
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
    Top = 49
    Width = 102
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
  end
  object IdDBText: TDBText
    Left = 433
    Top = 10
    Width = 80
    Height = 21
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataField = 'ID_SSELLER'
  end
  object Label2: TLabel
    Left = 404
    Top = 10
    Width = 16
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'ID:'
  end
  object Label3: TLabel
    Left = 20
    Top = 83
    Width = 79
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090':'
  end
  object Label4: TLabel
    Left = 20
    Top = 166
    Width = 178
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1076#1083#1103' '#1087#1077#1095#1072#1090#1080':'
  end
  object Label5: TLabel
    Left = 79
    Top = 225
    Width = 43
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1040#1076#1088#1077#1089':'
  end
  object Label6: TLabel
    Left = 59
    Top = 257
    Width = 63
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1058#1077#1083#1077#1092#1086#1085':'
  end
  object cxButtonOK: TcxButton
    Left = 363
    Top = 316
    Width = 92
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionOK
    TabOrder = 0
  end
  object cxButtonClose: TcxButton
    Left = 479
    Top = 316
    Width = 92
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 1
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 153
    Top = 46
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_SSELLER'
    TabOrder = 2
    OnKeyDown = NamecxDBTextEditKeyDown
    Width = 396
  end
  object NameKlientcxDBButtonEdit: TcxDBButtonEdit
    Left = 152
    Top = 80
    DataBinding.DataField = 'NAMEKLIENT'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.OnButtonClick = NameKlientcxDBButtonEditPropertiesButtonClick
    TabOrder = 3
    Width = 399
  end
  object NameForPrintcxDBTextEdit: TcxDBTextEdit
    Left = 155
    Top = 190
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_FOR_PRINT_SSELLER'
    TabOrder = 4
    OnKeyDown = NamecxDBTextEditKeyDown
    Width = 396
  end
  object AdresscxDBTextEdit: TcxDBTextEdit
    Left = 155
    Top = 222
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'ADR_SSELLER'
    TabOrder = 5
    OnKeyDown = NamecxDBTextEditKeyDown
    Width = 396
  end
  object PhonecxDBTextEdit: TcxDBTextEdit
    Left = 155
    Top = 254
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'PHONE_SSELLER'
    TabOrder = 6
    OnKeyDown = NamecxDBTextEditKeyDown
    Width = 396
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 104
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
  end
end
