object REM_FormaElementaSprProducerModel: TREM_FormaElementaSprProducerModel
  Left = 454
  Top = 350
  Caption = #1052#1086#1076#1077#1083#1100' '#1087#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1103
  ClientHeight = 541
  ClientWidth = 516
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
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
    Top = 121
    Width = 53
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1052#1086#1076#1077#1083#1100':'
  end
  object cxButtonOK: TcxButton
    Left = 286
    Top = 375
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
    Left = 386
    Top = 375
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
    DataBinding.DataField = 'NAME_REM_SPRMODEL'
    TabOrder = 0
    OnKeyDown = NamecxDBTextEditKeyDown
    Width = 448
  end
  object IdcxDBLabel: TcxDBLabel
    Left = 312
    Top = 16
    DataBinding.DataField = 'ID_REM_SPRMODEL'
    Height = 21
    Width = 121
  end
  object CodecxDBTextEdit: TcxDBTextEdit
    Left = 136
    Top = 22
    DataBinding.DataField = 'CODE_REM_SPRMODEL'
    TabOrder = 4
    Width = 121
  end
  object NameModelcxDBButtonEdit: TcxDBButtonEdit
    Left = 20
    Top = 144
    DataBinding.DataField = 'NAME_REM_SMODEL'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    TabOrder = 5
    Width = 448
  end
  object cxButtonOpenInfBlock: TcxButton
    Left = 159
    Top = 375
    Width = 120
    Height = 31
    Caption = #1048#1085#1092#1086#1088#1084#1072#1094#1080#1103
    TabOrder = 6
    OnClick = cxButtonOpenInfBlockClick
  end
  object cxButtonOpenProperties: TcxButton
    Left = 32
    Top = 375
    Width = 120
    Height = 31
    Caption = #1057#1074#1086#1081#1089#1090#1074#1072
    TabOrder = 7
    OnClick = cxButtonOpenPropertiesClick
  end
  object NameProducercxDBButtonEdit: TcxDBButtonEdit
    Left = 172
    Top = 237
    DataBinding.DataField = 'NAME_SPRODUCER'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end
      item
        Caption = 'X'
        Kind = bkText
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameProducercxDBButtonEditPropertiesButtonClick
    TabOrder = 8
    Width = 320
  end
  object cxLabel10: TcxLabel
    Left = 7
    Top = 238
    Caption = #1055#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1100':'
  end
  object cxLabel9: TcxLabel
    Left = 8
    Top = 208
    Caption = #1041#1088#1077#1085#1076':'
  end
  object NameBrandcxDBButtonEdit: TcxDBButtonEdit
    Left = 172
    Top = 207
    DataBinding.DataField = 'NAME_SBRAND'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end
      item
        Caption = 'X'
        Kind = bkText
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameBrandcxDBButtonEditPropertiesButtonClick
    TabOrder = 11
    Width = 320
  end
  object NameTypeDevicecxDBButtonEdit: TcxDBButtonEdit
    Left = 172
    Top = 293
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end
      item
        Caption = 'X'
        Kind = bkText
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameTypeDevicecxDBButtonEditPropertiesButtonClick
    TabOrder = 12
    Width = 320
  end
  object cxLabel3: TcxLabel
    Left = 31
    Top = 294
    Caption = #1058#1080#1087' '#1091#1089#1090#1088#1086#1081#1089#1090#1074#1072':'
  end
  object cxLabel4: TcxLabel
    Left = 8
    Top = 264
    Caption = #1050#1072#1090#1077#1075#1086#1088#1080#1103' '#1091#1089#1090#1088#1086#1081#1089#1090#1074':'
  end
  object NameActivecategorycxDBButtonEdit: TcxDBButtonEdit
    Left = 172
    Top = 263
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end
      item
        Caption = 'X'
        Kind = bkText
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameActivecategorycxDBButtonEditPropertiesButtonClick
    TabOrder = 15
    Width = 320
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
