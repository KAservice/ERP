object FormaElementaSprUser: TFormaElementaSprUser
  Left = 238
  Top = 246
  Caption = #1069#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1080'"'
  ClientHeight = 490
  ClientWidth = 434
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
    Top = 0
    Width = 434
    Height = 436
    ActivePage = cxTabSheet1
    Align = alClient
    TabOrder = 0
    ClientRectBottom = 436
    ClientRectRight = 434
    ClientRectTop = 24
    object cxTabSheet1: TcxTabSheet
      Caption = #1054#1089#1085#1086#1074#1085#1072#1103
      ImageIndex = 0
      ExplicitTop = 22
      ExplicitHeight = 414
      object Label1: TLabel
        Left = 40
        Top = 40
        Width = 25
        Height = 13
        Caption = #1048#1084#1103':'
      end
      object Label6: TLabel
        Left = 24
        Top = 168
        Width = 54
        Height = 16
        Caption = #1060#1080#1088#1084#1072':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label7: TLabel
        Left = 32
        Top = 232
        Width = 50
        Height = 16
        Caption = #1057#1082#1083#1072#1076':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label2: TLabel
        Left = 8
        Top = 72
        Width = 38
        Height = 13
        Caption = #1055#1086#1083#1085#1086#1077
      end
      object Label3: TLabel
        Left = 228
        Top = 314
        Width = 43
        Height = 13
        Caption = #1058#1080#1087' '#1094#1077#1085':'
      end
      object Label4: TLabel
        Left = 48
        Top = 72
        Width = 23
        Height = 13
        Caption = #1080#1084#1103':'
      end
      object Label5: TLabel
        Left = 3
        Top = 138
        Width = 83
        Height = 13
        Caption = #1055#1086#1076#1088#1072#1079#1076#1077#1083#1077#1085#1080#1077':'
      end
      object Label8: TLabel
        Left = 219
        Top = 337
        Width = 52
        Height = 13
        Caption = #1058#1080#1087' '#1094#1077#1085' 1:'
      end
      object Label9: TLabel
        Left = 219
        Top = 377
        Width = 52
        Height = 13
        Caption = #1058#1080#1087' '#1094#1077#1085' 2:'
      end
      object Label10: TLabel
        Left = 16
        Top = 104
        Width = 55
        Height = 13
        Caption = #1048#1085#1092'. '#1073#1072#1079#1072':'
      end
      object Label11: TLabel
        Left = 40
        Top = 205
        Width = 26
        Height = 13
        Caption = 'C'#1095#1077#1090':'
      end
      object Label14: TLabel
        Left = 263
        Top = 37
        Width = 34
        Height = 13
        Caption = #1048#1084#1103' 2:'
      end
      object Label15: TLabel
        Left = 96
        Top = 8
        Width = 99
        Height = 13
        Caption = #1050#1086#1076' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103': '
      end
      object IdDBText: TDBText
        Left = 201
        Top = 8
        Width = 65
        Height = 17
        DataField = 'ID_USER'
      end
      object cxLabel1: TcxLabel
        Left = 40
        Top = 254
        Caption = #1050#1072#1089#1089#1072':'
      end
      object NameKassacxDBButtonEdit: TcxDBButtonEdit
        Left = 92
        Top = 256
        DataBinding.DataField = 'NAMEKKM'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameKassacxDBButtonEditPropertiesButtonClick
        TabOrder = 8
        Width = 337
      end
      object NamecxDBTextEdit: TcxDBTextEdit
        Left = 93
        Top = 31
        DataBinding.DataField = 'NAME_USER'
        TabOrder = 0
        OnKeyDown = NamecxDBTextEditKeyDown
        Width = 121
      end
      object Name2cxDBTextEdit: TcxDBTextEdit
        Left = 308
        Top = 32
        DataBinding.DataField = 'NAME2_USER'
        TabOrder = 1
        OnKeyDown = Name2cxDBTextEditKeyDown
        Width = 121
      end
      object FNamecxDBTextEdit: TcxDBTextEdit
        Left = 92
        Top = 68
        DataBinding.DataField = 'FNAME_USER'
        TabOrder = 2
        OnKeyDown = FNamecxDBTextEditKeyDown
        Width = 337
      end
      object NameInfcxDBButtonEdit: TcxDBButtonEdit
        Left = 92
        Top = 100
        DataBinding.DataField = 'NAME_SINFBASE_OBMEN'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameInfcxDBButtonEditPropertiesButtonClick
        TabOrder = 3
        Width = 337
      end
      object NamePodcxDBButtonEdit: TcxDBButtonEdit
        Left = 93
        Top = 136
        DataBinding.DataField = 'NAMEPOD'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.ReadOnly = True
        Properties.OnButtonClick = NamePodcxDBButtonEditPropertiesButtonClick
        TabOrder = 4
        Width = 336
      end
      object NameFirmcxDBButtonEdit: TcxDBButtonEdit
        Left = 93
        Top = 168
        DataBinding.DataField = 'NAMEFIRM'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameFirmcxDBButtonEditPropertiesButtonClick
        TabOrder = 5
        Width = 336
      end
      object NameBSchetcxDBButtonEdit: TcxDBButtonEdit
        Left = 93
        Top = 202
        DataBinding.DataField = 'NAMEBSCHET'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.ReadOnly = True
        Properties.OnButtonClick = cxDBButtonEdit1PropertiesButtonClick
        TabOrder = 6
        Width = 336
      end
      object NameSkladcxDBButtonEdit: TcxDBButtonEdit
        Left = 93
        Top = 229
        DataBinding.DataField = 'NAMESKLAD'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameSkladcxDBButtonEditPropertiesButtonClick
        TabOrder = 7
        Width = 336
      end
      object NameTPricecxDBButtonEdit: TcxDBButtonEdit
        Left = 279
        Top = 311
        DataBinding.DataField = 'NAME_TPRICE'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameTPricecxDBButtonEditPropertiesButtonClick
        TabOrder = 9
        Width = 152
      end
      object NameTPrice1Edit: TcxButtonEdit
        Left = 279
        Top = 337
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameTPrice1EditPropertiesButtonClick
        TabOrder = 10
        Text = 'NameTPrice1Edit'
        Width = 152
      end
      object NameTPrice2Edit: TcxButtonEdit
        Left = 279
        Top = 375
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameTPrice2EditPropertiesButtonClick
        TabOrder = 11
        Text = 'NameTPrice2Edit'
        Width = 152
      end
      object NameActivecategorycxDBButtonEdit: TcxDBButtonEdit
        Left = 165
        Top = 281
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
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
        TabOrder = 13
        Width = 260
      end
      object cxLabel4: TcxLabel
        Left = 34
        Top = 282
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1050#1072#1090#1077#1075#1086#1088#1080#1103' '#1091#1089#1090#1088#1086#1081#1089#1090#1074':'
      end
    end
    object cxTabSheet2: TcxTabSheet
      Caption = #1044#1086#1087#1086#1083#1085#1080#1090#1077#1083#1100#1085#1086
      ImageIndex = 1
      ExplicitTop = 22
      ExplicitHeight = 414
      object TPosGournalcxDBRadioGroup: TcxDBRadioGroup
        Left = 16
        Top = 16
        Caption = #1053#1072#1095#1072#1083#1086' '#1078#1091#1088#1085#1072#1083#1072
        DataBinding.DataField = 'TPOSGOURNAL_SUSER'
        Properties.Items = <
          item
            Caption = #1085#1077' '#1079#1072#1076#1072#1085#1086
            Value = 0
          end
          item
            Caption = #1085#1072#1095#1072#1083#1086' '#1075#1086#1076#1072
            Value = 1
          end
          item
            Caption = #1085#1072#1095#1072#1083#1086' '#1082#1074#1072#1088#1090#1072#1083#1072
            Value = 2
          end
          item
            Caption = #1085#1072#1095#1072#1083#1086' '#1084#1077#1089#1103#1094#1072
            Value = 3
          end
          item
            Caption = #1085#1072#1095#1072#1083#1086' '#1076#1085#1103
            Value = 4
          end
          item
            Caption = #1047#1072#1076#1072#1085#1085#1086#1077' '#1082#1086#1083'. '#1076#1085#1077#1081
            Value = 5
          end>
        TabOrder = 0
        Height = 101
        Width = 185
      end
      object TPosReportcxDBRadioGroup: TcxDBRadioGroup
        Left = 220
        Top = 16
        Caption = #1053#1072#1095#1072#1083#1086' '#1086#1090#1095#1077#1090#1086#1074
        DataBinding.DataField = 'TPOSREPORT_SUSER'
        Properties.Items = <
          item
            Caption = #1053#1077' '#1079#1072#1076#1072#1085#1086
            Value = 0
          end
          item
            Caption = #1053#1072#1095#1072#1083#1086' '#1075#1086#1076#1072
            Value = 1
          end
          item
            Caption = #1053#1072#1095#1072#1083#1086' '#1082#1074#1072#1088#1090#1072#1083#1072
            Value = 2
          end
          item
            Caption = #1053#1072#1095#1072#1083#1086' '#1084#1077#1089#1103#1094#1072
            Value = 3
          end
          item
            Caption = #1053#1072#1095#1072#1083#1086' '#1076#1085#1103
            Value = 4
          end
          item
            Caption = #1047#1072#1076#1072#1085#1085#1086#1077' '#1082#1086#1083'. '#1076#1085#1077#1081
            Value = 5
          end>
        TabOrder = 1
        Height = 101
        Width = 197
      end
      object KolDayGurcxDBSpinEdit: TcxDBSpinEdit
        Left = 128
        Top = 123
        DataBinding.DataField = 'KOLDAYGUR_SUSER'
        TabOrder = 2
        Width = 73
      end
      object KolDayRepcxDBSpinEdit: TcxDBSpinEdit
        Left = 344
        Top = 123
        DataBinding.DataField = 'KOLDAYREP_SUSER'
        TabOrder = 3
        Width = 73
      end
      object cxLabel2: TcxLabel
        Left = 17
        Top = 123
        Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086#1074#1086' '#1076#1085#1077#1081':'
      end
      object cxLabel3: TcxLabel
        Left = 245
        Top = 123
        Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1076#1085#1077#1081':'
      end
      object ReOpenSprcxDBCheckBox: TcxDBCheckBox
        Left = 16
        Top = 168
        Caption = 
          #1087#1077#1088#1077#1086#1090#1082#1088#1099#1074#1072#1090#1100' '#1090#1072#1073#1083#1080#1095#1085#1091#1102' '#1095#1072#1089#1090#1100' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' '#1087#1086#1089#1083#1077' '#1079#1072#1082#1088#1099#1090#1080#1103' '#1101#1083#1077#1084#1077#1085#1090 +
          #1072
        DataBinding.DataField = 'REOPEN_SPR_SUSER'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        TabOrder = 6
        Width = 401
      end
      object ReOpenGurcxDBCheckBox: TcxDBCheckBox
        Left = 16
        Top = 195
        Caption = #1087#1077#1088#1077#1086#1090#1082#1088#1099#1074#1072#1090#1100' '#1078#1091#1088#1085#1072#1083' '#1087#1086#1089#1083#1077' '#1079#1072#1082#1088#1099#1090#1080#1103' '#1076#1086#1082#1091#1084#1077#1085#1090#1072
        DataBinding.DataField = 'REOPEN_GUR_SUSER'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        TabOrder = 7
        Width = 304
      end
      object EditChugDoccxDBCheckBox: TcxDBCheckBox
        Left = 16
        Top = 222
        Caption = #1088#1072#1079#1088#1077#1096#1080#1090#1100' '#1088#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100' '#1095#1091#1078#1080#1077' '#1076#1086#1082#1091#1084#1077#1085#1090#1099
        DataBinding.DataField = 'EDIT_CHUG_DOC_SUSER'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        TabOrder = 8
        Width = 265
      end
      object DelChugDoccxDBCheckBox: TcxDBCheckBox
        Left = 16
        Top = 249
        Caption = #1088#1072#1079#1088#1077#1096#1080#1090#1100' '#1091#1076#1072#1083#1103#1090#1100' '#1095#1091#1078#1080#1077' '#1076#1086#1082#1091#1084#1077#1085#1090#1099
        DataBinding.DataField = 'DEL_CHUG_DOC_SUSER'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        TabOrder = 9
        Width = 225
      end
      object ShowLogcxDBCheckBox: TcxDBCheckBox
        Left = 16
        Top = 276
        Caption = #1087#1086#1082#1072#1079#1099#1074#1072#1090#1100' '#1087#1088#1086#1090#1086#1082#1086#1083
        DataBinding.DataField = 'SHOW_LOG_SUSER'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        TabOrder = 10
        Width = 161
      end
      object DetailedLogcxDBCheckBox: TcxDBCheckBox
        Left = 16
        Top = 303
        Caption = #1087#1086#1076#1088#1086#1073#1085#1099#1081' '#1087#1088#1086#1090#1086#1082#1086#1083
        DataBinding.DataField = 'DETALIED_LOG_SUSER'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        TabOrder = 11
        Width = 161
      end
      object SaveNamecxDBCheckBox: TcxDBCheckBox
        Left = 16
        Top = 330
        Caption = #1089#1086#1093#1088#1072#1085#1103#1090#1100' '#1080#1084#1103' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103' '#1076#1083#1103' '#1087#1086#1074#1090#1086#1088#1085#1086#1075#1086' '#1079#1072#1087#1091#1089#1082#1072
        DataBinding.DataField = 'SAVENAME_SUSER'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        TabOrder = 12
        Width = 321
      end
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 436
    Width = 434
    Height = 54
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object Label13: TLabel
      Left = 16
      Top = 28
      Width = 198
      Height = 13
      Caption = #1085#1077#1086#1073#1093#1086#1076#1080#1084#1086' '#1087#1077#1088#1077#1079#1072#1087#1091#1089#1090#1080#1090#1100' '#1087#1088#1086#1075#1088#1072#1084#1084#1091
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -12
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label12: TLabel
      Left = 16
      Top = 9
      Width = 176
      Height = 13
      Caption = #1063#1090#1086#1073#1099' '#1080#1079#1084#1077#1085#1077#1085#1080#1103' '#1074#1089#1090#1091#1087#1080#1083#1080' '#1074' '#1089#1080#1083#1091
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -12
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object cxButtonClose: TcxButton
      Left = 350
      Top = 16
      Width = 75
      Height = 25
      Action = ActionClose
      TabOrder = 0
    end
    object cxButtonOK: TcxButton
      Left = 269
      Top = 16
      Width = 75
      Height = 25
      Action = ActionOK
      TabOrder = 1
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 400
    Top = 24
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
