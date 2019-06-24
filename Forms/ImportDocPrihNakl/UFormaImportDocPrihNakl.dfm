object FormaImportDocPrihNakl: TFormaImportDocPrihNakl
  Left = 0
  Top = 0
  Caption = #1047#1072#1075#1088#1091#1079#1082#1072' '#1076#1086#1082#1091#1084#1077#1085#1090#1086#1074' '#1080#1079' '#1092#1072#1081#1083#1086#1074' '#1074' '#1092#1086#1088#1084#1072#1090#1077' Excel'
  ClientHeight = 513
  ClientWidth = 973
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Visible = True
  OnActivate = FormActivate
  OnClose = FormClose
  OnCreate = FormCreate
  OnDeactivate = FormDeactivate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 973
    Height = 92
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 8
      Top = 34
      Width = 474
      Height = 21
      Caption = #1047#1072#1075#1088#1091#1079#1082#1072' '#1076#1086#1082#1091#1084#1077#1085#1090#1086#1074' '#1080#1079' '#1092#1072#1081#1083#1072' '#1074' '#1092#1086#1088#1084#1072#1090#1077' Excel 2003'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label13: TLabel
      Left = 16
      Top = 63
      Width = 30
      Height = 13
      Caption = #1060#1072#1081#1083':'
    end
    object Label11: TLabel
      Left = 420
      Top = 63
      Width = 103
      Height = 13
      Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080' '#1080#1084#1087#1086#1088#1090#1072':'
    end
    object FileNamecxButtonEdit: TcxButtonEdit
      Left = 51
      Top = 60
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.MaxLength = 0
      Properties.OnButtonClick = FileNamecxButtonEditPropertiesButtonClick
      TabOrder = 0
      Text = 'FileNamecxButtonEdit'
      Width = 312
    end
    object NameImportSetcxButtonEdit: TcxButtonEdit
      Left = 547
      Top = 60
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.MaxLength = 0
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameImportSetcxButtonEditPropertiesButtonClick
      TabOrder = 1
      Text = 'NameImportSetcxButtonEdit'
      Width = 193
    end
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 1273
      Height = 29
      Caption = 'ToolBar1'
      EdgeBorders = [ebLeft, ebTop, ebRight, ebBottom]
      Images = DM.ImageList1
      TabOrder = 2
      object ToolButton2: TToolButton
        Left = 0
        Top = 0
        Width = 401
        Caption = 'ToolButton2'
        ImageIndex = 1
        Style = tbsSeparator
      end
      object ToolButtonNoAddNomInSpr: TToolButton
        Left = 401
        Top = 0
        Hint = #1054#1073#1085#1086#1074#1080#1090#1100' '#1089#1080#1085#1093#1088#1086#1085#1080#1079#1080#1088#1086#1074#1072#1085#1085#1091#1102' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1091'. '#1041#1077#1079' '#1076#1086#1073#1072#1074#1083#1077#1085#1080#1103' '#1085#1086#1074#1099#1093'.'
        Caption = 'ToolButtonNoAddNomInSpr'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonNoAddNomInSprClick
      end
      object ToolButtonAddNewNom: TToolButton
        Left = 424
        Top = 0
        Hint = #1054#1073#1085#1086#1074#1080#1090#1100' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1091' '#1089' '#1076#1086#1073#1072#1074#1083#1077#1085#1080#1077#1084' '#1085#1086#1074#1099#1093'.'
        Caption = 'ToolButtonAddNewNom'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonAddNewNomClick
      end
      object ToolButtonZapolnitReal: TToolButton
        Left = 447
        Top = 0
        Hint = #1047#1072#1087#1086#1085#1080#1090#1100' '#1074#1099#1073#1088#1072#1085#1085#1099#1081' '#1076#1086#1082#1091#1084#1077#1085#1090' '#1056#1077#1072#1083#1080#1079#1072#1094#1080#1103
        Caption = 'ToolButtonZapolnitReal'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonZapolnitRealClick
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 470
    Width = 973
    Height = 43
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object LabelError: TLabel
      Left = 8
      Top = 6
      Width = 633
      Height = 27
      AutoSize = False
      Caption = 'LabelError'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      WordWrap = True
    end
    object cxButtonClose: TcxButton
      Left = 665
      Top = 6
      Width = 75
      Height = 25
      Action = ActionClose
      TabOrder = 0
    end
    object cxButtonDelString: TcxButton
      Left = 528
      Top = 6
      Width = 123
      Height = 25
      Caption = #1059#1076#1072#1083#1080#1090#1100' '#1090#1077#1082'. '#1089#1090#1088#1086#1082#1091
      TabOrder = 1
      OnClick = cxButtonDelStringClick
    end
  end
  object cxPageControl1: TcxPageControl
    Left = 0
    Top = 92
    Width = 973
    Height = 378
    ActivePage = cxTabSheet2
    Align = alClient
    TabOrder = 2
    ClientRectBottom = 378
    ClientRectRight = 973
    ClientRectTop = 24
    object cxTabSheet1: TcxTabSheet
      Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
      ImageIndex = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object Panel3: TPanel
        Left = 0
        Top = 0
        Width = 973
        Height = 105
        Align = alTop
        BevelOuter = bvNone
        TabOrder = 0
        object Label3: TLabel
          Left = 8
          Top = 0
          Width = 54
          Height = 52
          Caption = #1057#1090#1088#1086#1082#1072' '#1085#1072#1095#1072#1083#1072' '#1090#1072#1073#1083#1080#1095#1085#1086#1081' '#1095#1072#1089#1090#1080':'
          WordWrap = True
        end
        object Label2: TLabel
          Left = 151
          Top = 10
          Width = 63
          Height = 13
          Caption = #1050#1086#1076' '#1090#1086#1074#1072#1088#1072':'
        end
        object Label5: TLabel
          Left = 397
          Top = 6
          Width = 64
          Height = 13
          Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086':'
        end
        object Label4: TLabel
          Left = 268
          Top = 0
          Width = 78
          Height = 26
          Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099':'
          WordWrap = True
        end
        object Label7: TLabel
          Left = 32
          Top = 31
          Width = 30
          Height = 13
          Caption = #1062#1077#1085#1072':'
        end
        object Label9: TLabel
          Left = 268
          Top = 31
          Width = 53
          Height = 26
          Caption = #1056#1086#1079#1085#1080#1095#1085#1072#1103' '#1094#1077#1085#1072':'
          WordWrap = True
        end
        object Label6: TLabel
          Left = 516
          Top = 1
          Width = 73
          Height = 26
          Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1077#1076#1080#1085#1080#1094#1099':'
          WordWrap = True
        end
        object Label8: TLabel
          Left = 168
          Top = 29
          Width = 35
          Height = 13
          Caption = #1057#1091#1084#1084#1072':'
        end
        object Label10: TLabel
          Left = 404
          Top = 28
          Width = 53
          Height = 26
          Caption = #1056#1086#1079#1085#1080#1095#1085#1072#1103' '#1089#1091#1084#1084#1072':'
          WordWrap = True
        end
        object Label12: TLabel
          Left = 521
          Top = 36
          Width = 60
          Height = 13
          Caption = #1058#1080#1087' '#1087#1086#1080#1089#1082#1072':'
        end
        object Label18: TLabel
          Left = 16
          Top = 58
          Width = 61
          Height = 13
          Caption = #1064#1090#1088#1080#1093'-'#1082#1086#1076':'
        end
        object Label21: TLabel
          Left = 162
          Top = 62
          Width = 53
          Height = 13
          Caption = #1040#1088#1090'. '#1087#1086#1089#1090':'
        end
        object Label22: TLabel
          Left = 32
          Top = 82
          Width = 41
          Height = 13
          Caption = #1057#1090#1088#1072#1085#1072':'
        end
        object Label23: TLabel
          Left = 191
          Top = 82
          Width = 24
          Height = 13
          Caption = #1043#1058#1044':'
        end
        object StartStringcxSpinEdit: TcxSpinEdit
          Left = 104
          Top = 2
          TabOrder = 0
          Width = 45
        end
        object CodeNomcxSpinEdit: TcxSpinEdit
          Left = 220
          Top = 4
          TabOrder = 1
          Width = 45
        end
        object KolcxSpinEdit: TcxSpinEdit
          Left = 467
          Top = 2
          TabOrder = 2
          Width = 45
        end
        object NameNomcxSpinEdit: TcxSpinEdit
          Left = 351
          Top = 4
          TabOrder = 3
          Width = 45
        end
        object PricecxSpinEdit: TcxSpinEdit
          Left = 105
          Top = 29
          TabOrder = 4
          Width = 45
        end
        object RoznPricecxSpinEdit: TcxSpinEdit
          Left = 351
          Top = 29
          TabOrder = 5
          Width = 45
        end
        object NameEdcxSpinEdit: TcxSpinEdit
          Left = 599
          Top = 2
          TabOrder = 6
          Width = 45
        end
        object SumcxSpinEdit: TcxSpinEdit
          Left = 220
          Top = 29
          TabOrder = 7
          Width = 45
        end
        object RoznSumcxSpinEdit: TcxSpinEdit
          Left = 467
          Top = 29
          TabOrder = 8
          Width = 45
        end
        object TypeSearchcxComboBox: TcxComboBox
          Left = 599
          Top = 29
          Properties.DropDownListStyle = lsFixedList
          Properties.Items.Strings = (
            #1053#1077' '#1079#1072#1076#1072#1085#1086
            #1055#1086' '#1082#1086#1076#1091
            #1055#1086' '#1085#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1102
            #1055#1086' '#1072#1088#1090#1080#1082#1091#1083#1091' '#1087#1086#1089#1090#1072#1074#1097#1080#1082#1072)
          Properties.MaxLength = 0
          TabOrder = 9
          Width = 154
        end
        object cxButtonSaveParams: TcxButton
          Left = 678
          Top = 2
          Width = 75
          Height = 25
          Caption = #1047#1072#1087#1080#1089#1072#1090#1100
          TabOrder = 10
          OnClick = cxButtonSaveParamsClick
        end
        object BarCodecxSpinEdit: TcxSpinEdit
          Left = 104
          Top = 56
          TabOrder = 11
          Width = 46
        end
        object ExternalCodcxCheckBox: TcxCheckBox
          Left = 329
          Top = 54
          Caption = #1080#1089#1087#1086#1083#1100#1079#1086#1074#1072#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1082#1086#1076
          Properties.OnValidate = ExternalCodcxCheckBoxPropertiesValidate
          Style.TextColor = clRed
          TabOrder = 12
          Width = 186
        end
        object ExternalBarCodecxCheckBox: TcxCheckBox
          Left = 528
          Top = 56
          Caption = #1080#1089#1087#1086#1083#1100#1079#1086#1074#1072#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1096#1090#1088#1080#1093'-'#1082#1086#1076
          Properties.OnValidate = ExternalBarCodecxCheckBoxPropertiesValidate
          Style.TextColor = clRed
          TabOrder = 13
          Width = 212
        end
        object ArtNomcxSpinEdit: TcxSpinEdit
          Left = 220
          Top = 56
          TabOrder = 14
          Width = 45
        end
        object CountrycxSpinEdit: TcxSpinEdit
          Left = 103
          Top = 80
          TabOrder = 15
          Width = 46
        end
        object GTDcxSpinEdit: TcxSpinEdit
          Left = 220
          Top = 80
          TabOrder = 16
          Width = 46
        end
      end
      object cxSpreadSheet1: TcxSpreadSheet
        Left = 0
        Top = 105
        Width = 973
        Height = 252
        R1C1ReferenceStyle = True
        RowsAutoHeight = False
        Align = alClient
        AutoRecalc = False
        DefaultStyle.Font.Name = 'Tahoma'
        HeaderFont.Charset = DEFAULT_CHARSET
        HeaderFont.Color = clWindowText
        HeaderFont.Height = -11
        HeaderFont.Name = 'Tahoma'
        HeaderFont.Style = []
        PainterType = ptOfficeXPStyle
        RowHeaderWidth = 40
      end
    end
    object cxTabSheet2: TcxTabSheet
      Caption = #1044#1086#1082#1091#1084#1077#1085#1090
      ImageIndex = 1
      ExplicitTop = 0
      ExplicitWidth = 1244
      ExplicitHeight = 0
      object TPanel
        Left = 0
        Top = 0
        Width = 973
        Height = 105
        Align = alTop
        BevelOuter = bvNone
        TabOrder = 0
        object Label14: TLabel
          Left = 8
          Top = 8
          Width = 55
          Height = 13
          Caption = #1048#1085#1092'. '#1073#1072#1079#1072':'
        end
        object Label15: TLabel
          Left = 16
          Top = 28
          Width = 36
          Height = 13
          Caption = #1060#1080#1088#1084#1072':'
        end
        object Label16: TLabel
          Left = 275
          Top = 8
          Width = 36
          Height = 13
          Caption = #1057#1082#1083#1072#1076':'
        end
        object Label17: TLabel
          Left = 265
          Top = 31
          Width = 61
          Height = 13
          Caption = #1055#1086#1089#1090#1072#1074#1097#1080#1082':'
        end
        object Label19: TLabel
          Left = 8
          Top = 86
          Width = 252
          Height = 13
          Caption = #1048#1089#1087#1086#1083#1100#1079#1091#1077#1084' '#1090#1086#1083#1100#1082#1086' '#1073#1072#1079#1086#1074#1099#1077' '#1077#1076#1080#1085#1080#1094#1099' '#1080#1079#1084#1077#1088#1077#1085#1080#1103'!'
        end
        object Label20: TLabel
          Left = 190
          Top = 54
          Width = 147
          Height = 14
          Alignment = taCenter
          AutoSize = False
          Caption = #1043#1088#1091#1087#1087#1072' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099':'
          WordWrap = True
        end
        object Label24: TLabel
          Left = -11
          Top = 67
          Width = 85
          Height = 13
          Alignment = taCenter
          AutoSize = False
          Caption = #1044#1086#1082#1091#1084#1077#1085#1090':'
          WordWrap = True
        end
        object NameInfBasecxButtonEdit: TcxButtonEdit
          Left = 66
          Top = 5
          Properties.Buttons = <
            item
              Default = True
              Kind = bkEllipsis
            end>
          Properties.ClickKey = 13
          Properties.MaxLength = 0
          Properties.ReadOnly = True
          Properties.OnButtonClick = NameInfBasecxButtonEditPropertiesButtonClick
          TabOrder = 0
          Text = 'NameInfBasecxButtonEdit'
          Width = 193
        end
        object NameFirmcxButtonEdit: TcxButtonEdit
          Left = 66
          Top = 31
          Properties.Buttons = <
            item
              Default = True
              Kind = bkEllipsis
            end>
          Properties.ClickKey = 13
          Properties.MaxLength = 0
          Properties.ReadOnly = True
          Properties.OnButtonClick = NameFirmcxButtonEditPropertiesButtonClick
          TabOrder = 1
          Text = 'NameFirmcxButtonEdit'
          Width = 193
        end
        object NameSkladcxButtonEdit: TcxButtonEdit
          Left = 330
          Top = 5
          Properties.Buttons = <
            item
              Default = True
              Kind = bkEllipsis
            end>
          Properties.ClickKey = 13
          Properties.MaxLength = 0
          Properties.ReadOnly = True
          Properties.OnButtonClick = NameSkladcxButtonEditPropertiesButtonClick
          TabOrder = 2
          Text = 'NameSkladcxButtonEdit'
          Width = 201
        end
        object NameKlientcxButtonEdit: TcxButtonEdit
          Left = 330
          Top = 31
          Properties.Buttons = <
            item
              Default = True
              Kind = bkEllipsis
            end>
          Properties.ClickKey = 13
          Properties.MaxLength = 0
          Properties.ReadOnly = True
          Properties.OnButtonClick = NameKlientcxButtonEditPropertiesButtonClick
          TabOrder = 3
          Text = 'NameKlientcxButtonEdit'
          Width = 201
        end
        object cxButtonImport: TcxButton
          Left = 547
          Top = 10
          Width = 107
          Height = 25
          Caption = #1048#1084#1087#1086#1088#1090
          TabOrder = 4
          OnClick = cxButtonImportClick
        end
        object cxButtonSynhro: TcxButton
          Left = 547
          Top = 41
          Width = 107
          Height = 26
          Caption = #1057#1080#1085#1093#1088#1086#1085#1080#1079#1080#1088#1086#1074#1072#1090#1100
          TabOrder = 5
          OnClick = cxButtonSynhroClick
        end
        object cxButtonCreateDoc: TcxButton
          Left = 694
          Top = 7
          Width = 107
          Height = 50
          Caption = #1057#1086#1079#1076#1072#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' "'#1055#1088#1080#1093#1086#1076#1085#1072#1103' '#1085#1072#1082#1083#1072#1076#1085#1072#1103'"'
          TabOrder = 6
          WordWrap = True
          OnClick = cxButtonCreateDocClick
        end
        object NameGrpNomcxButtonEdit: TcxButtonEdit
          Left = 330
          Top = 56
          Properties.Buttons = <
            item
              Default = True
              Kind = bkEllipsis
            end>
          Properties.MaxLength = 0
          Properties.OnButtonClick = NameGrpNomcxButtonEditPropertiesButtonClick
          TabOrder = 7
          Text = 'NameGrpNomcxButtonEdit'
          Width = 201
        end
        object cxButtonCreateDocRev: TcxButton
          Left = 694
          Top = 63
          Width = 107
          Height = 36
          Caption = #1057#1086#1079#1076#1072#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' "'#1056#1077#1074#1080#1079#1080#1103'"'
          TabOrder = 8
          WordWrap = True
          OnClick = cxButtonCreateDocRevClick
        end
        object cxButtonCreateDocRegOtchetPost: TcxButton
          Left = 807
          Top = 7
          Width = 144
          Height = 37
          Caption = #1044#1074#1080#1078#1077#1085#1080#1103' '#1088#1077#1075#1080#1089#1090#1088#1072' '#1054#1090#1095#1077#1090' '#1087#1086#1089#1090#1072#1074#1097#1080#1082#1091
          TabOrder = 9
          WordWrap = True
          OnClick = cxButtonCreateDocRegOtchetPostClick
        end
        object cxButton1: TcxButton
          Left = 807
          Top = 54
          Width = 144
          Height = 45
          Caption = #1044#1074#1080#1078#1077#1085#1080#1103' '#1088#1077#1075#1080#1089#1090#1088#1072' '#1054#1090#1095#1077#1090' '#1087#1086#1089#1090#1072#1074#1097#1080#1082#1091' ('#1088#1077#1084#1086#1085#1090')'
          TabOrder = 10
          WordWrap = True
          OnClick = cxButton1Click
        end
        object VibDoccxButtonEdit: TcxButtonEdit
          Left = 66
          Top = 67
          Properties.Buttons = <
            item
              Default = True
              Kind = bkEllipsis
            end>
          Properties.MaxLength = 0
          Properties.OnButtonClick = VibDoccxButtonEditPropertiesButtonClick
          TabOrder = 11
          Text = 'VibDoccxButtonEdit'
          Width = 200
        end
      end
      object cxGrid1: TcxGrid
        Left = 0
        Top = 105
        Width = 973
        Height = 252
        Align = alClient
        TabOrder = 1
        object cxGrid1DBTableView1: TcxGridDBTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <>
          DataController.Summary.SummaryGroups = <>
        end
        object cxGrid1BandedTableView1: TcxGridBandedTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <
            item
              Kind = skSum
              Column = cxGrid1BandedTableView1ROZNSUM
            end
            item
              Kind = skSum
              Column = cxGrid1BandedTableView1SUM
            end>
          DataController.Summary.SummaryGroups = <>
          OptionsView.CellAutoHeight = True
          OptionsView.Footer = True
          Bands = <
            item
            end>
          object cxGrid1BandedTableView1IDNOM: TcxGridBandedColumn
            Caption = 'IDNOM'
            Options.Editing = False
            Width = 69
            Position.BandIndex = 0
            Position.ColIndex = 0
            Position.RowIndex = 0
          end
          object cxGrid1BandedTableView1CODENOM: TcxGridBandedColumn
            Caption = #1050#1086#1076
            Options.Editing = False
            Width = 59
            Position.BandIndex = 0
            Position.ColIndex = 1
            Position.RowIndex = 0
          end
          object cxGrid1BandedTableView1ARTNOM: TcxGridBandedColumn
            Caption = #1040#1088#1090#1080#1082#1091#1083' '#1087#1086#1089#1090'.'
            Position.BandIndex = 0
            Position.ColIndex = 2
            Position.RowIndex = 0
          end
          object cxGrid1BandedTableView1NAMENOMPOST: TcxGridBandedColumn
            Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1087#1086#1089#1090#1072#1074#1097#1080#1082#1072
            DataBinding.ValueType = 'WideString'
            PropertiesClassName = 'TcxMemoProperties'
            Options.Editing = False
            Width = 239
            Position.BandIndex = 0
            Position.ColIndex = 3
            Position.RowIndex = 0
          end
          object cxGrid1BandedTableView1NAMENOM: TcxGridBandedColumn
            Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072
            PropertiesClassName = 'TcxButtonEditProperties'
            Properties.Buttons = <
              item
                Caption = '...'
                Default = True
                Kind = bkEllipsis
              end
              item
                Caption = '<>'
                Kind = bkText
              end
              item
                Caption = 'X'
                Kind = bkText
              end>
            Properties.ReadOnly = True
            Properties.OnButtonClick = cxGrid1BandedTableView1NAMENOMPropertiesButtonClick
            Width = 299
            Position.BandIndex = 0
            Position.ColIndex = 4
            Position.RowIndex = 0
          end
          object cxGrid1BandedTableView1KOL: TcxGridBandedColumn
            Caption = #1050#1086#1083'.'
            DataBinding.ValueType = 'Float'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.Alignment.Horz = taRightJustify
            Width = 50
            Position.BandIndex = 0
            Position.ColIndex = 5
            Position.RowIndex = 0
          end
          object cxGrid1BandedTableView1NAMEED: TcxGridBandedColumn
            Caption = #1045#1076#1080#1085#1080#1094#1072
            Width = 58
            Position.BandIndex = 0
            Position.ColIndex = 6
            Position.RowIndex = 0
          end
          object cxGrid1BandedTableView1BARCODE: TcxGridBandedColumn
            Caption = #1064#1090#1088#1080#1093' '#1082#1086#1076
            Options.Editing = False
            Width = 64
            Position.BandIndex = 0
            Position.ColIndex = 7
            Position.RowIndex = 0
          end
          object cxGrid1BandedTableView1PRICE: TcxGridBandedColumn
            Caption = #1062#1077#1085#1072
            DataBinding.ValueType = 'Float'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.Alignment.Horz = taRightJustify
            Position.BandIndex = 0
            Position.ColIndex = 8
            Position.RowIndex = 0
          end
          object cxGrid1BandedTableView1SUM: TcxGridBandedColumn
            Caption = #1057#1091#1084#1084#1072
            DataBinding.ValueType = 'Float'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.Alignment.Horz = taRightJustify
            Position.BandIndex = 0
            Position.ColIndex = 9
            Position.RowIndex = 0
          end
          object cxGrid1BandedTableView1ROZNPRICE: TcxGridBandedColumn
            Caption = #1056#1086#1079#1085'. '#1094#1077#1085#1072
            DataBinding.ValueType = 'Float'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.Alignment.Horz = taRightJustify
            Width = 69
            Position.BandIndex = 0
            Position.ColIndex = 10
            Position.RowIndex = 0
          end
          object cxGrid1BandedTableView1ROZNSUM: TcxGridBandedColumn
            Caption = #1056#1086#1079#1085'. '#1089#1091#1084#1084#1072
            DataBinding.ValueType = 'Float'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.Alignment.Horz = taRightJustify
            Width = 121
            Position.BandIndex = 0
            Position.ColIndex = 11
            Position.RowIndex = 0
          end
          object cxGrid1BandedTableView1COUNTRY: TcxGridBandedColumn
            Caption = #1057#1090#1088#1072#1085#1072
            Width = 124
            Position.BandIndex = 0
            Position.ColIndex = 12
            Position.RowIndex = 0
          end
          object cxGrid1BandedTableView1GTD: TcxGridBandedColumn
            Caption = #1043#1058#1044
            Width = 250
            Position.BandIndex = 0
            Position.ColIndex = 13
            Position.RowIndex = 0
          end
        end
        object cxGrid1Level1: TcxGridLevel
          GridView = cxGrid1BandedTableView1
        end
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 384
    Top = 64
  end
  object ActionList: TActionList
    Left = 632
    Top = 8
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
      OnExecute = ActionOpenHelpExecute
    end
    object ActionDeleteString: TAction
      Caption = 'ActionDeleteString'
    end
    object ActionClose: TAction
      Caption = #1047#1072#1082#1088#1099#1090#1100
      ImageIndex = 53
      OnExecute = ActionCloseExecute
    end
  end
end
