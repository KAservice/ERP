object FormaImportSprProducerSection: TFormaImportSprProducerSection
  Left = 0
  Top = 0
  Caption = #1047#1072#1075#1088#1091#1079#1082#1072' '#1076#1086#1082#1091#1084#1077#1085#1090#1086#1074' '#1080#1079' '#1092#1072#1081#1083#1086#1074' '#1074' '#1092#1086#1088#1084#1072#1090#1077' Excel'
  ClientHeight = 519
  ClientWidth = 882
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 882
    Height = 92
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 8
      Top = 34
      Width = 587
      Height = 21
      Caption = #1047#1072#1075#1088#1091#1079#1082#1072' section ('#1087#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1103') '#1080#1079' '#1092#1072#1081#1083#1072' '#1074' '#1092#1086#1088#1084#1072#1090#1077' Excel 2003'
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
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameImportSetcxButtonEditPropertiesButtonClick
      TabOrder = 1
      Text = 'NameImportSetcxButtonEdit'
      Width = 193
    end
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 1153
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
      end
      object ToolButtonAddNewNom: TToolButton
        Left = 424
        Top = 0
        Hint = #1054#1073#1085#1086#1074#1080#1090#1100' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1091' '#1089' '#1076#1086#1073#1072#1074#1083#1077#1085#1080#1077#1084' '#1085#1086#1074#1099#1093'.'
        Caption = 'ToolButtonAddNewNom'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonSaveExcel: TToolButton
        Left = 447
        Top = 0
        Caption = 'ToolButtonSaveExcel'
        ImageIndex = 55
        OnClick = ToolButtonSaveExcelClick
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 447
    Width = 882
    Height = 72
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object LabelError: TLabel
      Left = 11
      Top = 23
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
    object LabelInfo: TLabel
      Left = 12
      Top = 55
      Width = 45
      Height = 13
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = 'LabelInfo'
    end
    object cxButtonClose: TcxButton
      Left = 665
      Top = 24
      Width = 75
      Height = 26
      Action = ActionClose
      TabOrder = 0
    end
    object cxButtonDelString: TcxButton
      Left = 536
      Top = 24
      Width = 123
      Height = 26
      Caption = #1059#1076#1072#1083#1080#1090#1100' '#1090#1077#1082'. '#1089#1090#1088#1086#1082#1091
      TabOrder = 1
      OnClick = cxButtonDelStringClick
    end
    object ProgressBar1: TProgressBar
      Left = 0
      Top = 0
      Width = 882
      Height = 17
      Align = alTop
      TabOrder = 2
    end
  end
  object cxPageControl1: TcxPageControl
    Left = 0
    Top = 92
    Width = 882
    Height = 355
    ActivePage = cxTabSheet2
    Align = alClient
    TabOrder = 2
    ClientRectBottom = 355
    ClientRectRight = 882
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
        Width = 882
        Height = 129
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
        object Label4: TLabel
          Left = 329
          Top = 0
          Width = 77
          Height = 13
          Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
          WordWrap = True
        end
        object Label21: TLabel
          Left = 174
          Top = 7
          Width = 47
          Height = 13
          Caption = #1040#1088#1090#1080#1082#1091#1083':'
        end
        object Label25: TLabel
          Left = 231
          Top = 88
          Width = 126
          Height = 26
          Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1086#1096#1080#1073#1086#1082' '#1076#1083#1103' '#1086#1089#1090#1072#1085#1086#1074#1082#1080
          WordWrap = True
        end
        object Label2: TLabel
          Left = 329
          Top = 25
          Width = 73
          Height = 26
          Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077'  (eng):'
          WordWrap = True
        end
        object StartStringcxSpinEdit: TcxSpinEdit
          Left = 92
          Top = 7
          TabOrder = 0
          Width = 45
        end
        object NamecxSpinEdit: TcxSpinEdit
          Left = 421
          Top = 5
          TabOrder = 1
          Width = 45
        end
        object TypeSearchcxComboBox: TcxComboBox
          Left = 536
          Top = 7
          Properties.DropDownListStyle = lsFixedList
          Properties.Items.Strings = (
            #1053#1077' '#1079#1072#1076#1072#1085#1086
            #1055#1086' '#1085#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1102
            #1055#1086' '#1072#1088#1090#1080#1082#1091#1083#1091
            #1055#1086' '#1072#1085#1075#1083'. '#1085#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1102)
          TabOrder = 2
          Width = 155
        end
        object cxButtonSaveParams: TcxButton
          Left = 733
          Top = 5
          Width = 75
          Height = 25
          Caption = #1047#1072#1087#1080#1089#1072#1090#1100
          TabOrder = 3
          OnClick = cxButtonSaveParamsClick
        end
        object ArtcxSpinEdit: TcxSpinEdit
          Left = 239
          Top = 5
          TabOrder = 4
          Width = 45
        end
        object KolErrorForStopcxSpinEdit: TcxSpinEdit
          Left = 421
          Top = 80
          TabOrder = 5
          Width = 45
        end
        object NameEngcxSpinEdit: TcxSpinEdit
          Left = 421
          Top = 30
          TabOrder = 6
          Width = 45
        end
        object cxCheckBoxVidelyatCod: TcxCheckBox
          Left = 544
          Top = 73
          Margins.Left = 2
          Margins.Top = 2
          Margins.Right = 2
          Margins.Bottom = 2
          Caption = #1074#1099#1076#1077#1083#1103#1090#1100' '#1082#1086#1076' '#1080#1079' '#1088#1091#1089#1089#1082#1086#1075#1086' '#1085#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1103
          TabOrder = 7
          Width = 264
        end
      end
      object cxSpreadSheet1: TcxSpreadSheet
        Left = 0
        Top = 129
        Width = 882
        Height = 204
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
      ExplicitWidth = 0
      ExplicitHeight = 0
      object TPanel
        Left = 0
        Top = 0
        Width = 882
        Height = 105
        Align = alTop
        BevelOuter = bvNone
        TabOrder = 0
        object Label14: TLabel
          Left = 11
          Top = 27
          Width = 55
          Height = 13
          Caption = #1048#1085#1092'. '#1073#1072#1079#1072':'
        end
        object Label15: TLabel
          Left = 16
          Top = 54
          Width = 36
          Height = 13
          Caption = #1060#1080#1088#1084#1072':'
        end
        object Label16: TLabel
          Left = 308
          Top = 15
          Width = 36
          Height = 13
          Caption = #1057#1082#1083#1072#1076':'
        end
        object Label17: TLabel
          Left = 304
          Top = 42
          Width = 61
          Height = 13
          Caption = #1055#1086#1089#1090#1072#1074#1097#1080#1082':'
        end
        object Label20: TLabel
          Left = 283
          Top = 61
          Width = 97
          Height = 26
          Alignment = taCenter
          AutoSize = False
          Caption = #1043#1088#1091#1087#1087#1072' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099':'
          WordWrap = True
        end
        object Label24: TLabel
          Left = 293
          Top = 93
          Width = 83
          Height = 13
          Caption = #1055#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1100':'
        end
        object Label32: TLabel
          Left = 599
          Top = -1
          Width = 142
          Height = 13
          Caption = #1053#1086#1084#1077#1088' '#1087#1086#1089#1083#1077#1076#1085#1077#1081' '#1089#1090#1088#1086#1082#1080'!!!:'
        end
        object NameInfBasecxButtonEdit: TcxButtonEdit
          Left = 72
          Top = 24
          Properties.Buttons = <
            item
              Default = True
              Kind = bkEllipsis
            end>
          Properties.ClickKey = 13
          Properties.ReadOnly = True
          Properties.OnButtonClick = NameInfBasecxButtonEditPropertiesButtonClick
          TabOrder = 0
          Text = 'NameInfBasecxButtonEdit'
          Width = 193
        end
        object NameFirmcxButtonEdit: TcxButtonEdit
          Left = 72
          Top = 51
          Properties.Buttons = <
            item
              Default = True
              Kind = bkEllipsis
            end>
          Properties.ClickKey = 13
          Properties.ReadOnly = True
          Properties.OnButtonClick = NameFirmcxButtonEditPropertiesButtonClick
          TabOrder = 1
          Text = 'NameFirmcxButtonEdit'
          Width = 193
        end
        object NameSkladcxButtonEdit: TcxButtonEdit
          Left = 392
          Top = 11
          Properties.Buttons = <
            item
              Default = True
              Kind = bkEllipsis
            end>
          Properties.ClickKey = 13
          Properties.ReadOnly = True
          Properties.OnButtonClick = NameSkladcxButtonEditPropertiesButtonClick
          TabOrder = 2
          Text = 'NameSkladcxButtonEdit'
          Width = 201
        end
        object NameKlientcxButtonEdit: TcxButtonEdit
          Left = 392
          Top = 37
          Properties.Buttons = <
            item
              Default = True
              Kind = bkEllipsis
            end>
          Properties.ClickKey = 13
          Properties.ReadOnly = True
          Properties.OnButtonClick = NameKlientcxButtonEditPropertiesButtonClick
          TabOrder = 3
          Text = 'NameKlientcxButtonEdit'
          Width = 201
        end
        object cxButtonImport: TcxButton
          Left = 608
          Top = 42
          Width = 107
          Height = 25
          Caption = #1048#1084#1087#1086#1088#1090
          TabOrder = 4
          OnClick = cxButtonImportClick
        end
        object cxButtonUpdateSpr: TcxButton
          Left = 756
          Top = 75
          Width = 107
          Height = 24
          Caption = #1054#1073#1085#1086#1074#1080#1090#1100
          TabOrder = 5
          WordWrap = True
          OnClick = cxButtonUpdateSprClick
        end
        object NameGrpNomcxButtonEdit: TcxButtonEdit
          Left = 392
          Top = 62
          Properties.Buttons = <
            item
              Default = True
              Kind = bkEllipsis
            end>
          TabOrder = 6
          Text = 'NameGrpNomcxButtonEdit'
          Width = 201
        end
        object NameProducercxButtonEdit: TcxButtonEdit
          Left = 392
          Top = 87
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
          Properties.OnButtonClick = NameProducercxButtonEditPropertiesButtonClick
          TabOrder = 7
          Text = 'NameProducercxButtonEdit'
          Width = 201
        end
        object cxButtonProverit: TcxButton
          Left = 756
          Top = 44
          Width = 107
          Height = 25
          Caption = #1055#1088#1086#1074#1077#1088#1080#1090#1100
          TabOrder = 8
          WordWrap = True
          OnClick = cxButtonProveritClick
        end
        object NumLastStringcxSpinEdit: TcxSpinEdit
          Left = 622
          Top = 18
          Margins.Left = 2
          Margins.Top = 2
          Margins.Right = 2
          Margins.Bottom = 2
          TabOrder = 9
          Width = 93
        end
      end
      object cxGrid1: TcxGrid
        Left = 0
        Top = 105
        Width = 882
        Height = 228
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
            end
            item
              Kind = skSum
            end>
          DataController.Summary.SummaryGroups = <>
          OptionsView.CellAutoHeight = True
          OptionsView.Footer = True
          Bands = <
            item
              Width = 1101
            end>
          object cxGrid1BandedTableView1ID_REM_SPRSECTION: TcxGridBandedColumn
            Caption = 'ID_REM_SPRSECTION'
            Options.Editing = False
            Width = 259
            Position.BandIndex = 0
            Position.ColIndex = 0
            Position.RowIndex = 0
          end
          object cxGrid1BandedTableView1ART: TcxGridBandedColumn
            Caption = #1040#1088#1090#1080#1082#1091#1083' '#1087#1086#1089#1090'.'
            Width = 109
            Position.BandIndex = 0
            Position.ColIndex = 1
            Position.RowIndex = 0
          end
          object cxGrid1BandedTableView1NAME: TcxGridBandedColumn
            Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1087#1086#1089#1090#1072#1074#1097#1080#1082#1072
            DataBinding.ValueType = 'WideString'
            PropertiesClassName = 'TcxMemoProperties'
            Options.Editing = False
            Width = 392
            Position.BandIndex = 0
            Position.ColIndex = 2
            Position.RowIndex = 0
          end
          object cxGrid1BandedTableView1NAME_ENG: TcxGridBandedColumn
            Caption = 'Name_eng'
            Width = 341
            Position.BandIndex = 0
            Position.ColIndex = 3
            Position.RowIndex = 0
          end
        end
        object cxGrid1Level1: TcxGridLevel
          GridView = cxGrid1BandedTableView1
        end
      end
    end
    object cxTabSheet4: TcxTabSheet
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1054#1073#1085#1086#1074#1083#1077#1085#1080#1077
      ImageIndex = 3
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object cxGrid3: TcxGrid
        Left = 0
        Top = 0
        Width = 882
        Height = 333
        Align = alClient
        TabOrder = 0
        object cxGridDBTableView2: TcxGridDBTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <>
          DataController.Summary.SummaryGroups = <>
        end
        object cxGridBandedTableView2: TcxGridBandedTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <
            item
              Kind = skCount
              Column = TableUpdateID_REM_SPRSECTION
            end>
          DataController.Summary.SummaryGroups = <>
          OptionsView.CellAutoHeight = True
          OptionsView.Footer = True
          Bands = <
            item
              Width = 1051
            end>
          object TableUpdateID_REM_SPRSECTION: TcxGridBandedColumn
            Caption = 'ID_REM_SPRSECTION'
            Options.Editing = False
            Width = 150
            Position.BandIndex = 0
            Position.ColIndex = 1
            Position.RowIndex = 0
          end
          object TableUpdateART: TcxGridBandedColumn
            Caption = 'ART'
            Width = 92
            Position.BandIndex = 0
            Position.ColIndex = 2
            Position.RowIndex = 0
          end
          object TableUpdateNAME: TcxGridBandedColumn
            Caption = 'NAME'
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
            Width = 292
            Position.BandIndex = 0
            Position.ColIndex = 3
            Position.RowIndex = 0
          end
          object TableUpdateTypeUpdate: TcxGridBandedColumn
            Caption = #1058#1080#1087' '#1086#1073#1085#1086#1074#1083'.'
            DataBinding.ValueType = 'Integer'
            Width = 97
            Position.BandIndex = 0
            Position.ColIndex = 0
            Position.RowIndex = 0
          end
          object TableUpdateNAME_ENG: TcxGridBandedColumn
            Caption = 'NAME_ENG'
            Width = 293
            Position.BandIndex = 0
            Position.ColIndex = 4
            Position.RowIndex = 0
          end
        end
        object cxGridLevel2: TcxGridLevel
          GridView = cxGridBandedTableView2
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
  object SaveDialog1: TSaveDialog
    Left = 480
    Top = 24
  end
end
