object FormaElementaSprKlientHot: TFormaElementaSprKlientHot
  Left = 291
  Top = 115
  Width = 475
  Height = 430
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090' '#1086#1088#1075#1072#1085#1080#1079#1072#1094#1080#1080
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 8
    Top = 8
    Width = 449
    Height = 385
    ActivePage = TabSheet2
    TabIndex = 1
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = #1055#1086#1080#1089#1082
      object Label3: TLabel
        Left = 24
        Top = 24
        Width = 154
        Height = 16
        Caption = #1060#1072#1084#1080#1083#1080#1103' '#1048#1084#1103' '#1054#1090#1095#1077#1089#1090#1074#1086
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object AdrDBText: TDBText
        Left = 8
        Top = 312
        Width = 409
        Height = 17
        DataField = 'ADRKLIENT'
        DataSource = DMSprKlient.DataSourceTable
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object NameEdit: TEdit
        Left = 8
        Top = 40
        Width = 337
        Height = 24
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        Text = 'NameEdit'
        OnKeyDown = NameEditKeyDown
      end
      object ButtonFind: TButton
        Left = 352
        Top = 40
        Width = 75
        Height = 25
        Caption = #1053#1072#1081#1090#1080
        TabOrder = 1
        OnClick = ButtonFindClick
      end
      object DBGrid1: TDBGrid
        Left = 8
        Top = 72
        Width = 417
        Height = 233
        DataSource = DMSprKlient.DataSourceTable
        Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit]
        ReadOnly = True
        TabOrder = 2
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -11
        TitleFont.Name = 'MS Sans Serif'
        TitleFont.Style = []
        OnDblClick = DBGrid1DblClick
        OnKeyDown = DBGrid1KeyDown
        Columns = <
          item
            Expanded = False
            FieldName = 'NAMEKLIENT'
            Title.Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
            Width = 379
            Visible = True
          end>
      end
      object ButtonVibrat1: TButton
        Left = 176
        Top = 326
        Width = 75
        Height = 25
        Caption = #1042#1099#1073#1088#1072#1090#1100
        TabOrder = 3
        OnClick = ButtonVibrat1Click
      end
      object ButtonClose1: TButton
        Left = 350
        Top = 326
        Width = 75
        Height = 25
        Caption = #1047#1072#1082#1088#1099#1090#1100
        TabOrder = 4
        OnClick = ButtonClose1Click
      end
      object ButtonStep2: TButton
        Left = 264
        Top = 326
        Width = 75
        Height = 25
        Caption = #1053#1086#1074#1099#1081
        TabOrder = 5
        OnClick = ButtonStep2Click
      end
    end
    object TabSheet2: TTabSheet
      Caption = #1057#1074#1077#1076#1077#1085#1080#1103
      ImageIndex = 1
      object Label1: TLabel
        Left = 8
        Top = 88
        Width = 102
        Height = 16
        Caption = #1044#1072#1090#1072' '#1088#1086#1078#1076#1077#1085#1080#1103':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label2: TLabel
        Left = 8
        Top = 8
        Width = 154
        Height = 16
        Caption = #1060#1072#1084#1080#1083#1080#1103' '#1048#1084#1103' '#1054#1090#1095#1077#1089#1090#1074#1086
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label4: TLabel
        Left = 0
        Top = 112
        Width = 111
        Height = 16
        Caption = #1052#1077#1089#1090#1086' '#1088#1086#1078#1076#1077#1085#1080#1103':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label5: TLabel
        Left = 24
        Top = 64
        Width = 43
        Height = 16
        Caption = #1040#1076#1088#1077#1089':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label6: TLabel
        Left = 8
        Top = 144
        Width = 95
        Height = 16
        Caption = #1052#1077#1089#1090#1086' '#1088#1072#1073#1086#1090#1099':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label7: TLabel
        Left = 16
        Top = 176
        Width = 74
        Height = 16
        Caption = #1044#1086#1083#1078#1085#1086#1089#1090#1100':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object ButtonOK2: TButton
        Left = 264
        Top = 328
        Width = 75
        Height = 25
        Caption = #1054#1050
        TabOrder = 0
        OnClick = ButtonOK2Click
      end
      object ButtonClose2: TButton
        Left = 360
        Top = 328
        Width = 75
        Height = 25
        Caption = #1047#1072#1082#1088#1099#1090#1100
        TabOrder = 1
        OnClick = ButtonClose2Click
      end
      object DateRogDateTimePicker: TDateTimePicker
        Left = 120
        Top = 88
        Width = 81
        Height = 21
        CalAlignment = dtaLeft
        Date = 39016
        Time = 39016
        DateFormat = dfShort
        DateMode = dmComboBox
        Kind = dtkDate
        ParseInput = False
        TabOrder = 2
      end
      object MestoRogDBEdit: TDBEdit
        Left = 120
        Top = 112
        Width = 313
        Height = 21
        DataField = 'MESTOROG_SKLIENT_DOPFISL'
        DataSource = DMSprKlientDopFisL.DataSourceElement
        TabOrder = 3
      end
      object MestoRabDBEdit: TDBEdit
        Left = 120
        Top = 144
        Width = 313
        Height = 21
        DataField = 'MESTORAB_SKLIENT_DOPFISL'
        DataSource = DMSprKlientDopFisL.DataSourceElement
        TabOrder = 4
      end
      object DolRabDBEdit: TDBEdit
        Left = 120
        Top = 176
        Width = 313
        Height = 21
        DataField = 'DOLRAB_SKLIENT_DOPFISL'
        DataSource = DMSprKlientDopFisL.DataSourceElement
        TabOrder = 5
      end
      object AdrKlientDBEdit: TDBEdit
        Left = 120
        Top = 56
        Width = 313
        Height = 21
        DataField = 'ADRKLIENT'
        DataSource = DMSprKlient.DataSourceElement
        TabOrder = 6
      end
      object NameKlientDBEdit: TDBEdit
        Left = 8
        Top = 24
        Width = 425
        Height = 21
        DataField = 'NAMEKLIENT'
        DataSource = DMSprKlient.DataSourceElement
        TabOrder = 7
      end
      object GroupBox1: TGroupBox
        Left = 8
        Top = 208
        Width = 425
        Height = 105
        Caption = #1044#1086#1082#1091#1084#1077#1085#1090':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 8
        object VidDBText: TDBText
          Left = 56
          Top = 80
          Width = 353
          Height = 17
          DataField = 'VID_SDOCKLIENT'
          DataSource = DMSprDocKlient.DataSourceTable
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object Label11: TLabel
          Left = 8
          Top = 81
          Width = 45
          Height = 16
          Caption = #1042#1099#1076#1072#1085':'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object Label9: TLabel
          Left = 8
          Top = 52
          Width = 43
          Height = 16
          Caption = #1057#1077#1088#1080#1103':'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object SerDBText: TDBText
          Left = 56
          Top = 52
          Width = 65
          Height = 17
          DataField = 'SER_SDOCKLIENT'
          DataSource = DMSprDocKlient.DataSourceTable
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object Label10: TLabel
          Left = 128
          Top = 52
          Width = 46
          Height = 16
          Caption = #1053#1086#1084#1077#1088':'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object NumDBText: TDBText
          Left = 176
          Top = 52
          Width = 73
          Height = 17
          DataField = 'NUM_SDOCKLIENT'
          DataSource = DMSprDocKlient.DataSourceTable
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object Label12: TLabel
          Left = 256
          Top = 52
          Width = 87
          Height = 16
          Caption = #1044#1072#1090#1072' '#1074#1099#1076#1072#1095#1080':'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object DateVidDBText: TDBText
          Left = 344
          Top = 52
          Width = 65
          Height = 17
          DataField = 'DATEVID_SDOCKLIENT'
          DataSource = DMSprDocKlient.DataSourceTable
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object Label8: TLabel
          Left = 8
          Top = 25
          Width = 67
          Height = 16
          Caption = #1044#1086#1082#1091#1084#1077#1085#1090':'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object DocumentComboBox: TComboBox
          Left = 80
          Top = 20
          Width = 145
          Height = 24
          Style = csDropDownList
          ItemHeight = 16
          TabOrder = 0
          OnChange = DocumentComboBoxChange
        end
        object ButtonIsmdoc: TButton
          Left = 248
          Top = 18
          Width = 75
          Height = 25
          Caption = #1048#1079#1084#1077#1085#1080#1090#1100
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          OnClick = ButtonIsmdocClick
        end
        object ButtonNewDoc: TButton
          Left = 336
          Top = 18
          Width = 75
          Height = 25
          Caption = #1053#1086#1074#1099#1081' '#1076#1086#1082'.'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          OnClick = ButtonNewDocClick
        end
      end
    end
  end
end
