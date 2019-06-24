object FormaElementaSprKlient: TFormaElementaSprKlient
  Left = 229
  Top = 167
  Caption = #1069#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1050#1086#1085#1090#1088#1072#1075#1077#1085#1090#1099'"'
  ClientHeight = 478
  ClientWidth = 501
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object cxPageControl1: TcxPageControl
    Left = 0
    Top = 35
    Width = 501
    Height = 367
    ActivePage = cxTabSheet1
    Align = alClient
    TabOrder = 0
    ClientRectBottom = 367
    ClientRectRight = 501
    ClientRectTop = 24
    object cxTabSheet1: TcxTabSheet
      Caption = #1054#1089#1085#1086#1074#1085#1099#1077
      ImageIndex = 0
      object Label1: TLabel
        Left = 16
        Top = 106
        Width = 79
        Height = 13
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
      end
      object Label3: TLabel
        Left = 64
        Top = 211
        Width = 34
        Height = 13
        Caption = #1040#1076#1088#1077#1089':'
      end
      object Label4: TLabel
        Left = 42
        Top = 295
        Width = 56
        Height = 13
        Caption = #1058#1077#1083#1077#1092#1086#1085#1099':'
      end
      object Label5: TLabel
        Left = 55
        Top = 233
        Width = 27
        Height = 13
        Caption = #1048#1053#1053':'
      end
      object Label7: TLabel
        Left = 10
        Top = 157
        Width = 118
        Height = 13
        Caption = #1055#1086#1083#1085#1086#1077' '#1085#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
      end
      object Label2: TLabel
        Left = 218
        Top = 20
        Width = 88
        Height = 13
        Caption = #1058#1080#1087' '#1082#1086#1085#1090#1088#1072#1075#1077#1085#1090#1072':'
      end
      object IDKlientDBText: TDBText
        Left = 10
        Top = 3
        Width = 124
        Height = 20
        Alignment = taRightJustify
        AutoSize = True
        DataField = 'IDKLIENT'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label9: TLabel
        Left = 218
        Top = 46
        Width = 88
        Height = 13
        Caption = #1042#1080#1076' '#1082#1086#1085#1090#1088#1072#1075#1077#1085#1090#1072':'
      end
      object Label10: TLabel
        Left = 267
        Top = 79
        Width = 39
        Height = 13
        Caption = #1057#1090#1088#1072#1085#1072':'
      end
      object Label11: TLabel
        Left = -1
        Top = 133
        Width = 96
        Height = 13
        Caption = #1050#1088'. '#1085#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
      end
      object Label6: TLabel
        Left = 344
        Top = 233
        Width = 26
        Height = 13
        Caption = #1050#1055#1055':'
      end
      object Label8: TLabel
        Left = 319
        Top = 264
        Width = 34
        Height = 13
        Caption = #1054#1050#1055#1054':'
      end
      object VidKlientcxDBButtonEdit: TcxDBButtonEdit
        Left = 312
        Top = 43
        DataBinding.DataField = 'NAME_SVIDKLIENT'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.ReadOnly = True
        Properties.OnButtonClick = VidKlientcxDBButtonEditPropertiesButtonClick
        TabOrder = 1
        Width = 168
      end
      object NameCountrycxDBButtonEdit: TcxDBButtonEdit
        Left = 312
        Top = 76
        DataBinding.DataField = 'NAME_SCOUNTRY'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameCountrycxDBButtonEditPropertiesButtonClick
        TabOrder = 2
        Width = 168
      end
      object cxButtonOpenSprDiscountCard: TcxButton
        Left = 10
        Top = 29
        Width = 88
        Height = 25
        Caption = #1044#1080#1089#1082#1086#1085#1090'. '#1082#1072#1088#1090#1099
        TabOrder = 11
        TabStop = False
        OnClick = cxButtonOpenSprDiscountCardClick
      end
      object AdresscxDBButtonEdit: TcxDBButtonEdit
        Left = 104
        Top = 203
        DataBinding.DataField = 'ADRKLIENT'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.ReadOnly = False
        Properties.OnButtonClick = AdresscxDBButtonEditPropertiesButtonClick
        TabOrder = 6
        Width = 376
      end
      object TelcxDBTextEdit: TcxDBTextEdit
        Left = 104
        Top = 292
        DataBinding.DataField = 'TELKLIENT'
        TabOrder = 10
        OnKeyDown = TelcxDBTextEditKeyDown
        Width = 376
      end
      object INNcxDBTextEdit: TcxDBTextEdit
        Left = 104
        Top = 230
        DataBinding.DataField = 'INNKLIENT'
        TabOrder = 7
        OnKeyDown = INNcxDBTextEditKeyDown
        Width = 104
      end
      object FNamecxDBTextEdit: TcxDBTextEdit
        Left = 10
        Top = 176
        DataBinding.DataField = 'FNAME'
        TabOrder = 5
        OnKeyDown = FNamecxDBTextEditKeyDown
        Width = 470
      end
      object NamecxDBTextEdit: TcxDBTextEdit
        Left = 101
        Top = 103
        DataBinding.DataField = 'NAMEKLIENT'
        TabOrder = 3
        OnKeyDown = NamecxDBTextEditKeyDown
        Width = 379
      end
      object TKlient: TcxComboBox
        Left = 312
        Top = 16
        Properties.DropDownListStyle = lsFixedList
        Properties.Items.Strings = (
          #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090
          #1043#1086#1089#1090#1100
          #1056#1086#1079#1085#1080#1095#1085#1099#1081' '#1087#1086#1082#1091#1087#1072#1090#1077#1083#1100)
        TabOrder = 0
        Width = 168
      end
      object KrNameKlientcxDBTextEdit: TcxDBTextEdit
        Left = 101
        Top = 130
        DataBinding.DataField = 'KRNAME_SKLIENT'
        TabOrder = 4
        OnKeyDown = KrNameKlientcxDBTextEditKeyDown
        Width = 379
      end
      object OKPOcxDBTextEdit: TcxDBTextEdit
        Left = 359
        Top = 261
        DataBinding.DataField = 'OKPOKLIENT'
        TabOrder = 9
        OnKeyDown = OKPOcxDBTextEditKeyDown
        Width = 121
      end
      object KPPcxDBTextEdit: TcxDBTextEdit
        Left = 376
        Top = 230
        DataBinding.DataField = 'KPPKLIENT'
        TabOrder = 8
        OnKeyDown = KPPcxDBTextEditKeyDown
        Width = 104
      end
    end
    object cxTabSheet2: TcxTabSheet
      Caption = #1044#1086#1087'.'
      ImageIndex = 1
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object Label21: TLabel
        Left = 262
        Top = 249
        Width = 43
        Height = 13
        Caption = #1058#1080#1087' '#1094#1077#1085':'
      end
      object Label12: TLabel
        Left = 24
        Top = 132
        Width = 156
        Height = 13
        Caption = #1044#1086#1087#1086#1083#1085#1080#1090#1077#1083#1100#1085#1072#1103' '#1080#1085#1092#1086#1088#1084#1072#1094#1080#1103':'
      end
      object Label13: TLabel
        Left = 24
        Top = 193
        Width = 61
        Height = 13
        Caption = #1057#1086#1086#1073#1097#1077#1085#1080#1077':'
      end
      object Label14: TLabel
        Left = 224
        Top = 275
        Width = 113
        Height = 13
        Caption = #1052#1072#1082#1089'. '#1089#1091#1084#1084#1072' '#1082#1088#1077#1076#1080#1090#1072':'
      end
      object Label16: TLabel
        Left = 53
        Top = 327
        Width = 36
        Height = 13
        Caption = 'WWW:'
      end
      object Label15: TLabel
        Left = 49
        Top = 307
        Width = 31
        Height = 13
        Caption = 'E-mail:'
      end
      object Label17: TLabel
        Left = 24
        Top = 70
        Width = 104
        Height = 13
        Caption = #1070#1088#1080#1076#1080#1095#1077#1089#1082#1080#1081' '#1072#1076#1088#1077#1089':'
      end
      object Label18: TLabel
        Left = 24
        Top = 3
        Width = 148
        Height = 13
        Caption = #1040#1076#1088#1077#1089' '#1076#1083#1103' '#1082#1086#1088#1088#1077#1089#1087#1086#1085#1076#1077#1085#1094#1080#1080':'
      end
      object Label19: TLabel
        Left = 36
        Top = 252
        Width = 61
        Height = 13
        Caption = #1058#1080#1087' '#1087#1086#1080#1089#1082#1072':'
      end
      object TypePriceComboBox: TcxComboBox
        Left = 313
        Top = 247
        Properties.DropDownListStyle = lsEditFixedList
        Properties.OnChange = TypePriceComboBoxPropertiesChange
        TabOrder = 2
        Width = 174
      end
      object DescrcxDBMemo: TcxDBMemo
        Left = 24
        Top = 147
        DataBinding.DataField = 'DESCR_SKLIENT'
        TabOrder = 0
        Height = 47
        Width = 463
      end
      object MessagecxDBMemo: TcxDBMemo
        Left = 24
        Top = 205
        DataBinding.DataField = 'MESSAGE_SKLIENT'
        TabOrder = 1
        Height = 40
        Width = 463
      end
      object MaxCreditcxDBCalcEdit: TcxDBCalcEdit
        Left = 350
        Top = 273
        DataBinding.DataField = 'MAXCREDIT_SKLIENT'
        TabOrder = 3
        Width = 137
      end
      object EmailcxDBTextEdit: TcxDBTextEdit
        Left = 111
        Top = 299
        DataBinding.DataField = 'EMAIL_SKLIENT'
        TabOrder = 4
        Width = 376
      end
      object WWWcxDBTextEdit: TcxDBTextEdit
        Left = 111
        Top = 325
        DataBinding.DataField = 'WWW_SKLIENT'
        TabOrder = 5
        Width = 376
      end
      object YurAdresscxDBMemo: TcxDBMemo
        Left = 24
        Top = 89
        DataBinding.DataField = 'YUR_ADRESS_SKLIENT'
        TabOrder = 6
        Height = 43
        Width = 463
      end
      object PochtAdresscxDBMemo: TcxDBMemo
        Left = 24
        Top = 23
        DataBinding.DataField = 'POCHT_ADRRESS_SKLIENT'
        TabOrder = 7
        Height = 47
        Width = 463
      end
      object cxDBImageComboBoxTYPE_POISK_SKLIENT: TcxDBImageComboBox
        Left = 112
        Top = 250
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        RepositoryItem = DM.cxEditRepository1ImageComboBoxItemTYPE_POISK_SKLIENT
        DataBinding.DataField = 'TYPE_POISK_SKLIENT'
        Properties.Items = <>
        TabOrder = 8
        Width = 144
      end
    end
    object cxTabSheet3: TcxTabSheet
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = 'cxTabSheet3'
      ImageIndex = 2
      object Label20: TLabel
        Left = 16
        Top = 38
        Width = 103
        Height = 28
        Alignment = taCenter
        AutoSize = False
        Caption = #1043#1088#1091#1087#1087#1072' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099':'
        WordWrap = True
      end
      object Label22: TLabel
        Left = 16
        Top = 84
        Width = 103
        Height = 27
        Alignment = taCenter
        AutoSize = False
        Caption = #1043#1088#1091#1087#1087#1072' '#1086#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1103':'
        WordWrap = True
      end
      object cxDBButtonEditNAMEGN: TcxDBButtonEdit
        Left = 169
        Top = 46
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'NAMEGN'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end
          item
            Caption = 'X'
            Kind = bkText
          end>
        Properties.OnButtonClick = cxDBButtonEditNAMEGNPropertiesButtonClick
        TabOrder = 0
        Width = 287
      end
      object cxDBButtonEditNAME_REM_SGRP_HARDWARE: TcxDBButtonEdit
        Left = 169
        Top = 92
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'NAME_REM_SGRP_HARDWARE'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end
          item
            Caption = 'X'
            Kind = bkText
          end>
        Properties.OnButtonClick = cxDBButtonEditNAME_REM_SGRP_HARDWAREPropertiesButtonClick
        TabOrder = 1
        Width = 287
      end
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 501
    Height = 35
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 1
  end
  object Panel2: TPanel
    Left = 0
    Top = 402
    Width = 501
    Height = 76
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 2
    object cxButtonDogovora: TcxButton
      Left = 7
      Top = 11
      Width = 75
      Height = 25
      Caption = #1044#1086#1075#1086#1074#1086#1088#1072
      TabOrder = 0
      OnClick = cxButtonDogovoraClick
    end
    object cxButtonTelNum: TcxButton
      Left = 88
      Top = 11
      Width = 75
      Height = 25
      Caption = #1058#1077#1083'. '#1085#1086#1084#1077#1088#1072
      TabOrder = 1
      OnClick = cxButtonTelNumClick
    end
    object cxButtonRaschScheta: TcxButton
      Left = 169
      Top = 11
      Width = 75
      Height = 25
      Caption = #1056#1072#1089#1095'. '#1089#1095#1077#1090#1072
      TabOrder = 2
      OnClick = cxButtonRaschSchetaClick
    end
    object cxButtonSave: TcxButton
      Left = 250
      Top = 42
      Width = 75
      Height = 25
      Action = ActionSave
      TabOrder = 3
    end
    object cxButtonOK: TcxButton
      Left = 331
      Top = 42
      Width = 75
      Height = 25
      Action = ActionOK
      TabOrder = 4
    end
    object cxButtonClose: TcxButton
      Left = 412
      Top = 42
      Width = 75
      Height = 25
      Action = ActionClose
      TabOrder = 5
    end
    object cxButtonDoc: TcxButton
      Left = 7
      Top = 42
      Width = 75
      Height = 25
      Caption = #1044#1086#1082#1091#1084#1077#1085#1090#1099
      TabOrder = 6
      OnClick = cxButtonDocClick
    end
    object cxButtonDopFL: TcxButton
      Left = 88
      Top = 42
      Width = 75
      Height = 25
      Caption = #1044#1086#1087'. '#1092'.'#1083'.'
      TabOrder = 7
      OnClick = cxButtonDopFLClick
    end
    object cxButtonDopUL: TcxButton
      Left = 169
      Top = 42
      Width = 75
      Height = 25
      Caption = #1044#1086#1087'. '#1102'.'#1083'.'
      TabOrder = 8
      OnClick = cxButtonDopULClick
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 384
    Top = 419
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
    object ActionSave: TAction
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      ImageIndex = 55
      OnExecute = ActionSaveExecute
    end
  end
end
