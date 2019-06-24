object REM_FormaElementaSprModel: TREM_FormaElementaSprModel
  Left = 249
  Top = 132
  Caption = #1069#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1052#1086#1076#1077#1083#1080' '#1086#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1103'"'
  ClientHeight = 522
  ClientWidth = 553
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
    Left = 31
    Top = 82
    Width = 102
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
  end
  object Label2: TLabel
    Left = 29
    Top = 146
    Width = 214
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1052#1086#1076#1077#1083#1100' '#1072#1085#1072#1083#1086#1075' ('#1085#1077#1080#1089#1087#1088#1072#1074#1085#1086#1089#1090#1080'):'
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 31
    Top = 106
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_REM_SMODEL'
    TabOrder = 2
    Width = 497
  end
  object cxButtonKolmpl: TcxButton
    Left = 9
    Top = 379
    Width = 120
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1086#1084#1087#1083#1077#1082#1090#1072#1094#1080#1103
    TabOrder = 3
    OnClick = cxButtonKolmplClick
  end
  object cxButtonSave: TcxButton
    Left = 236
    Top = 476
    Width = 92
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionSave
    TabOrder = 4
  end
  object cxButtonOK: TcxButton
    Left = 336
    Top = 476
    Width = 92
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionOK
    TabOrder = 5
  end
  object cxButtonClose: TcxButton
    Left = 435
    Top = 476
    Width = 93
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    Cancel = True
    TabOrder = 6
  end
  object NameNomcxDBButtonEdit: TcxDBButtonEdit
    Left = 31
    Top = 34
    DataBinding.DataField = 'NAMENOM'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameNomcxDBButtonEditPropertiesButtonClick
    TabOrder = 0
    Width = 497
  end
  object StrCodeModelcxDBTextEdit: TcxDBTextEdit
    Left = 360
    Top = 74
    DataBinding.DataField = 'STRCODE_REM_SMODEL'
    TabOrder = 1
    Width = 167
  end
  object cxLabel1: TcxLabel
    Left = 31
    Top = 8
    Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072':'
  end
  object cxLabel2: TcxLabel
    Left = 271
    Top = 75
    Caption = #1050#1086#1076' '#1084#1086#1076#1077#1083#1080':'
  end
  object cxButtonOpenSprModelDetal: TcxButton
    Left = 9
    Top = 424
    Width = 120
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1044#1077#1090#1072#1083#1080#1079#1072#1094#1080#1103
    TabOrder = 9
    OnClick = cxButtonOpenSprModelDetalClick
  end
  object cxButtonNeispr: TcxButton
    Left = 308
    Top = 379
    Width = 120
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1077#1080#1089#1087#1088#1072#1074#1085#1086#1089#1090#1080
    TabOrder = 10
    OnClick = cxButtonNeisprClick
  end
  object NameModelNeisprcxDBButtonEdit: TcxDBButtonEdit
    Left = 31
    Top = 169
    DataBinding.DataField = 'NAME_REM_SMODEL_NEISPR'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameModelNeisprcxDBButtonEditPropertiesButtonClick
    TabOrder = 11
    Width = 497
  end
  object cxButtonOpenProperties: TcxButton
    Left = 160
    Top = 379
    Width = 120
    Height = 31
    Caption = #1057#1074#1086#1081#1089#1090#1074#1072
    TabOrder = 12
    OnClick = cxButtonOpenPropertiesClick
  end
  object cxButtonOpenInfBlock: TcxButton
    Left = 160
    Top = 424
    Width = 120
    Height = 31
    Caption = #1048#1085#1092#1086#1088#1084#1072#1094#1080#1103
    TabOrder = 13
    OnClick = cxButtonOpenInfBlockClick
  end
  object NameProducercxDBButtonEdit: TcxDBButtonEdit
    Left = 207
    Top = 253
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
    TabOrder = 14
    Width = 320
  end
  object cxLabel10: TcxLabel
    Left = 31
    Top = 254
    Caption = #1055#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1100':'
  end
  object cxLabel9: TcxLabel
    Left = 32
    Top = 224
    Caption = #1041#1088#1077#1085#1076':'
  end
  object NameBrandcxDBButtonEdit: TcxDBButtonEdit
    Left = 207
    Top = 223
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
    TabOrder = 17
    Width = 320
  end
  object NameTypeDevicecxDBButtonEdit: TcxDBButtonEdit
    Left = 207
    Top = 309
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
    TabOrder = 18
    Width = 320
  end
  object cxLabel3: TcxLabel
    Left = 55
    Top = 310
    Caption = #1058#1080#1087' '#1091#1089#1090#1088#1086#1081#1089#1090#1074#1072':'
  end
  object cxLabel4: TcxLabel
    Left = 32
    Top = 280
    Caption = #1050#1072#1090#1077#1075#1086#1088#1080#1103' '#1091#1089#1090#1088#1086#1081#1089#1090#1074':'
  end
  object NameActivecategorycxDBButtonEdit: TcxDBButtonEdit
    Left = 207
    Top = 279
    DataBinding.DataField = 'NAME_REM_SACTCATEGORY'
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
    TabOrder = 21
    Width = 320
  end
  object cxButtonTypRabot: TcxButton
    Left = 308
    Top = 424
    Width = 120
    Height = 31
    Caption = #1058#1080#1087'.'#1088#1072#1073#1086#1090#1099
    TabOrder = 22
    OnClick = cxButtonTypRabotClick
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 264
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
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
    object ActionSave: TAction
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      ImageIndex = 55
      OnExecute = ActionSaveExecute
    end
  end
end
