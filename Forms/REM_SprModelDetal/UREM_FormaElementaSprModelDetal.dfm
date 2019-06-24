object REM_FormaElementaSprModelDetal: TREM_FormaElementaSprModelDetal
  Left = 645
  Top = 0
  Caption = #1045#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1044#1077#1090#1072#1083#1080#1079#1072#1094#1080#1103' '#1084#1086#1076#1077#1083#1080'"'
  ClientHeight = 516
  ClientWidth = 608
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
  object Label2: TLabel
    Left = 320
    Top = 83
    Width = 95
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086':'
  end
  object Label3: TLabel
    Left = 9
    Top = 198
    Width = 115
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072':'
  end
  object Label4: TLabel
    Left = 9
    Top = 260
    Width = 238
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072' '#1087#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1103':'
  end
  object Label5: TLabel
    Left = 36
    Top = 119
    Width = 78
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1054#1087#1080#1089#1072#1085#1080#1077':'
  end
  object Label6: TLabel
    Left = 36
    Top = 19
    Width = 98
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1055#1072#1088#1090'. '#1085#1086#1084#1077#1088':'
  end
  object Label7: TLabel
    Left = 19
    Top = 348
    Width = 105
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1058#1080#1087#1086#1074#1086#1081' '#1091#1079#1077#1083':'
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 142
    Top = 44
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_REM_SMODEL_DETAL'
    TabOrder = 0
    Width = 408
  end
  object KolcxDBTextEdit: TcxDBTextEdit
    Left = 423
    Top = 80
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'KOL_REM_SMODEL_DETAL'
    TabOrder = 1
    Width = 127
  end
  object cxButtonOK: TcxButton
    Left = 331
    Top = 460
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionOK
    TabOrder = 2
  end
  object cxButtonClose: TcxButton
    Left = 433
    Top = 460
    Width = 93
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 3
  end
  object PartNumbercxDBTextEdit: TcxDBTextEdit
    Left = 142
    Top = 11
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'PARTNUM_REM_SMODEL_DETAL'
    TabOrder = 4
    Width = 283
  end
  object DescrcxDBTextEdit: TcxDBTextEdit
    Left = 142
    Top = 116
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'DESCR_REM_SMODEL_DETAL'
    TabOrder = 5
    Width = 408
  end
  object NameNomcxDBButtonEdit: TcxDBButtonEdit
    Left = 142
    Top = 190
    DataBinding.DataField = 'NAMENOM'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end
      item
        Caption = 'x'
        Kind = bkText
      end>
    Properties.OnButtonClick = NameNomcxDBButtonEditPropertiesButtonClick
    TabOrder = 6
    Width = 409
  end
  object NameProducerNomcxDBButtonEdit: TcxDBButtonEdit
    Left = 141
    Top = 287
    DataBinding.DataField = 'NAME_SPRNOM'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end
      item
        Caption = 'x'
        Kind = bkText
      end>
    Properties.OnButtonClick = NameProducerNomcxDBButtonEditPropertiesButtonClick
    TabOrder = 7
    Width = 409
  end
  object ArtikulNomcxDBLabel: TcxDBLabel
    Left = 275
    Top = 224
    DataBinding.DataField = 'ARTNOM'
    Height = 21
    Width = 276
  end
  object CodeNomcxDBLabel: TcxDBLabel
    Left = 142
    Top = 224
    DataBinding.DataField = 'CODENOM'
    Height = 21
    Width = 121
  end
  object CodePrNomcxDBLabel: TcxDBLabel
    Left = 142
    Top = 329
    DataBinding.DataField = 'CODE_SPRNOM'
    Height = 21
    Width = 121
  end
  object ArtikulPrNomcxDBLabel: TcxDBLabel
    Left = 275
    Top = 329
    DataBinding.DataField = 'ART_SPRNOM'
    Height = 21
    Width = 275
  end
  object NameTypUslacxDBButtonEdit: TcxDBButtonEdit
    Left = 141
    Top = 375
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
    TabOrder = 12
    Width = 409
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
