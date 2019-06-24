object FormaElementaSprOborud: TFormaElementaSprOborud
  Left = 183
  Top = 124
  Caption = #1045#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1054#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077'"'
  ClientHeight = 370
  ClientWidth = 390
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 16
  object Panel1: TPanel
    Left = 0
    Top = 327
    Width = 390
    Height = 43
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 0
    ExplicitTop = 295
    ExplicitWidth = 372
    object cxButtonOK: TcxButton
      Left = 199
      Top = 6
      Width = 75
      Height = 25
      Action = ActionOK
      TabOrder = 0
    end
    object cxButtonClose: TcxButton
      Left = 299
      Top = 6
      Width = 75
      Height = 25
      Action = ActionClose
      TabOrder = 1
    end
  end
  object cxPageControl1: TcxPageControl
    Left = 0
    Top = 0
    Width = 390
    Height = 327
    ActivePage = cxTabSheet1
    Align = alClient
    TabOrder = 1
    ExplicitWidth = 372
    ExplicitHeight = 295
    ClientRectBottom = 327
    ClientRectRight = 390
    ClientRectTop = 27
    object cxTabSheet1: TcxTabSheet
      Caption = #1054#1089#1085#1086#1074#1085#1099#1077
      ImageIndex = 0
      ExplicitWidth = 372
      ExplicitHeight = 268
      object Label5: TLabel
        Left = 71
        Top = 16
        Width = 126
        Height = 16
        Caption = #1058#1080#1087' '#1086#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1103':'
      end
      object Label6: TLabel
        Left = 144
        Top = 50
        Width = 53
        Height = 16
        Caption = #1052#1086#1076#1077#1083#1100':'
      end
      object Label1: TLabel
        Left = 8
        Top = 80
        Width = 102
        Height = 16
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
      end
      object Label2: TLabel
        Left = 3
        Top = 207
        Width = 112
        Height = 16
        Caption = #1048#1084#1103' '#1082#1086#1084#1087#1100#1102#1090#1077#1088#1072':'
      end
      object Label7: TLabel
        Left = 15
        Top = 167
        Width = 111
        Height = 16
        Caption = #1052#1086#1076#1091#1083#1100' (ProgId2):'
      end
      object Label3: TLabel
        Left = 3
        Top = 237
        Width = 65
        Height = 16
        Caption = 'Com '#1087#1086#1088#1090':'
      end
      object Label4: TLabel
        Left = 166
        Top = 237
        Width = 64
        Height = 16
        Caption = #1057#1082#1086#1088#1086#1089#1090#1100':'
      end
      object Label8: TLabel
        Left = 25
        Top = 124
        Width = 43
        Height = 16
        Caption = 'ProgId:'
      end
      object OnStartcxDBCheckBox: TcxDBCheckBox
        Left = 25
        Top = 264
        Caption = #1087#1086#1076#1082#1083#1102#1095#1072#1090#1100' '#1087#1088#1080' '#1079#1072#1087#1091#1089#1082#1077' '#1087#1088#1086#1075#1088#1072#1084#1084#1099
        DataBinding.DataField = 'ON_START_SOBORUD'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        TabOrder = 7
        OnKeyDown = OnStartcxDBCheckBoxKeyDown
        Width = 289
      end
      object TypeOborudComboBox: TcxComboBox
        Left = 221
        Top = 12
        Properties.DropDownListStyle = lsFixedList
        Properties.Items.Strings = (
          'no'
          'kkm'
          'fr'
          'printer'
          'scaner'
          'LabelPrn'
          'DisplayPok')
        Properties.OnChange = TypeOborudComboBoxPropertiesChange
        TabOrder = 0
        Width = 153
      end
      object ModelComboBox: TcxComboBox
        Left = 221
        Top = 42
        Properties.DropDownListStyle = lsFixedList
        TabOrder = 1
        Width = 153
      end
      object NamecxDBTextEdit: TcxDBTextEdit
        Left = 125
        Top = 72
        DataBinding.DataField = 'NAME_OBORUD'
        TabOrder = 2
        OnKeyDown = NamecxDBTextEditKeyDown
        Width = 249
      end
      object CompNamecxDBTextEdit: TcxDBTextEdit
        Left = 125
        Top = 204
        DataBinding.DataField = 'COMPNAME_OBORUD'
        TabOrder = 3
        OnKeyDown = CompNamecxDBTextEditKeyDown
        Width = 249
      end
      object ComPortcxDBComboBox: TcxDBComboBox
        Left = 79
        Top = 234
        DataBinding.DataField = 'COMNAME_OBORUD'
        Properties.Items.Strings = (
          '1'
          '2'
          '3'
          '4'
          '5'
          '6'
          '7'
          '8'
          '9'
          '10')
        TabOrder = 5
        Width = 81
      end
      object BaudRatecxDBComboBox: TcxDBComboBox
        Left = 253
        Top = 234
        DataBinding.DataField = 'BAUDRATE_OBORUD'
        Properties.Items.Strings = (
          '2400'
          '4800'
          '9600'
          '19200'
          '57600'
          '115200')
        TabOrder = 6
        Width = 121
      end
      object ModulcxDBComboBox: TcxDBComboBox
        Left = 125
        Top = 164
        DataBinding.DataField = 'MODUL_SOBORUD'
        TabOrder = 4
        Width = 249
      end
      object cxDBComboBoxPROGID_SOBORUD: TcxDBComboBox
        Left = 125
        Top = 121
        DataBinding.DataField = 'PROGID_SOBORUD'
        TabOrder = 8
        Width = 249
      end
    end
    object cxTabSheet2: TcxTabSheet
      Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099
      ImageIndex = 1
      ExplicitWidth = 401
      object StrParcxDBMemo: TcxDBMemo
        Left = 0
        Top = 0
        Align = alClient
        DataBinding.DataField = 'STRPAR_SOBORUD'
        TabOrder = 0
        ExplicitWidth = 401
        Height = 300
        Width = 390
      end
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 184
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
