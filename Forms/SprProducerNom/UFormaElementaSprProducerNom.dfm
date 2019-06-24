object FormaElementaSprProducerNom: TFormaElementaSprProducerNom
  Left = 249
  Top = 132
  Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072
  ClientHeight = 668
  ClientWidth = 934
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
  OnActivate = FormActivate
  OnClose = FormClose
  OnDeactivate = FormDeactivate
  PixelsPerInch = 120
  TextHeight = 16
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 934
    Height = 50
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 2
    ExplicitWidth = 923
    object cxButtonPrice: TcxButton
      Left = 67
      Top = 11
      Width = 72
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1062#1077#1085#1099
      TabOrder = 0
      OnClick = cxButtonPriceClick
    end
    object cxButtonEd: TcxButton
      Left = 5
      Top = 11
      Width = 64
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1045#1076#1080#1085#1080#1094#1099
      TabOrder = 1
      OnClick = cxButtonEdClick
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 624
    Width = 934
    Height = 44
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    ExplicitWidth = 923
    object Label11: TLabel
      Left = 20
      Top = -2
      Width = 175
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072' '#1086#1073#1085#1086#1074#1083#1077#1085#1072':'
    end
    object cxButtonSave: TcxButton
      Left = 352
      Top = 10
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionSave
      TabOrder = 0
    end
    object cxButtonOK: TcxButton
      Left = 452
      Top = 10
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
      Left = 551
      Top = 10
      Width = 93
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      Cancel = True
      TabOrder = 2
    end
    object IamcxDBDateEdit: TcxDBDateEdit
      Left = 53
      Top = 13
      DataBinding.DataField = 'ISM_SPRNOM'
      Properties.Kind = ckDateTime
      TabOrder = 3
      Width = 209
    end
  end
  object cxPageControl1: TcxPageControl
    Left = 0
    Top = 50
    Width = 934
    Height = 574
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    ActivePage = cxTabSheet1
    Align = alClient
    TabOrder = 0
    ExplicitWidth = 923
    ClientRectBottom = 574
    ClientRectRight = 934
    ClientRectTop = 27
    object cxTabSheet1: TcxTabSheet
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1054#1089#1085#1086#1074#1085#1072#1103' (F5)'
      ImageIndex = 0
      ExplicitWidth = 923
      object Label9: TLabel
        Left = 50
        Top = 59
        Width = 28
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1058#1080#1087':'
      end
      object Label1: TLabel
        Left = 522
        Top = 44
        Width = 40
        Height = 24
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1050#1086#1076':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -18
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label12: TLabel
        Left = 384
        Top = 82
        Width = 143
        Height = 24
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1040#1088#1090'/'#1089#1077#1088'. '#1085#1086#1084#1077#1088':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -18
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label4: TLabel
        Left = 187
        Top = 191
        Width = 157
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1050#1088#1072#1090#1082#1086#1077' '#1085#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
      end
      object Label2: TLabel
        Left = 39
        Top = 118
        Width = 102
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
      end
      object Label3: TLabel
        Left = 33
        Top = 142
        Width = 153
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1055#1086#1083#1085#1086#1077' '#1085#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
      end
      object NameGrpLabel: TLabel
        Left = 574
        Top = 4
        Width = 93
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Alignment = taRightJustify
        Caption = 'NameGrpLabel'
      end
      object Label5: TLabel
        Left = 53
        Top = 311
        Width = 53
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1052#1086#1076#1077#1083#1100':'
      end
      object Label6: TLabel
        Left = 53
        Top = 341
        Width = 50
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1040#1085#1072#1083#1086#1075':'
      end
      object Label7: TLabel
        Left = 132
        Top = 371
        Width = 65
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1062#1077#1085#1072' '#1079#1072#1082'.:'
      end
      object Label8: TLabel
        Left = 150
        Top = 401
        Width = 36
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1062#1077#1085#1072':'
      end
      object Label10: TLabel
        Left = 24
        Top = 221
        Width = 100
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072':'
      end
      object Label13: TLabel
        Left = 683
        Top = 19
        Width = 54
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = 'Location:'
      end
      object Label14: TLabel
        Left = 683
        Top = 69
        Width = 86
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1050#1086#1076' '#1088#1077#1084#1086#1085#1090#1072':'
      end
      object Label15: TLabel
        Left = 683
        Top = 117
        Width = 68
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1040#1088#1090#1080#1082#1091#1083' 2:'
      end
      object Label16: TLabel
        Left = 683
        Top = 185
        Width = 137
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1040#1085#1075#1083'. '#1085#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
      end
      object FNamecxDBTextEdit: TcxDBTextEdit
        Left = 33
        Top = 156
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'FNAME_SPRNOM'
        Properties.ValidateOnEnter = True
        TabOrder = 4
        OnKeyPress = FNamecxDBTextEditKeyPress
        Width = 634
      end
      object KrNamecxDBTextEdit: TcxDBTextEdit
        Left = 345
        Top = 187
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'KRNAME_SPRNOM'
        Properties.MaxLength = 40
        TabOrder = 5
        OnKeyDown = KrNamecxDBTextEditKeyDown
        Width = 322
      end
      object NameNomcxDBTextEdit: TcxDBTextEdit
        Left = 158
        Top = 114
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NAME_SPRNOM'
        Properties.ValidateOnEnter = True
        TabOrder = 3
        OnKeyPress = NameNomcxDBTextEditKeyPress
        Width = 509
      end
      object ArtcxDBTextEdit: TcxDBTextEdit
        Left = 518
        Top = 81
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'ART_SPRNOM'
        TabOrder = 2
        OnKeyDown = ArtcxDBTextEditKeyDown
        Width = 149
      end
      object CodecxDBTextEdit: TcxDBTextEdit
        Left = 562
        Top = 43
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'CODE_SPRNOM'
        TabOrder = 1
        OnKeyDown = CodecxDBTextEditKeyDown
        Width = 105
      end
      object TNomcxDBImageComboBox: TcxDBImageComboBox
        Left = 92
        Top = 55
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        RepositoryItem = DM.cxEditRepository1ImageComboBoxTNOM
        DataBinding.DataField = 'TYPE_SPRNOM'
        Properties.Items = <>
        TabOrder = 0
        Width = 163
      end
      object GroupBoxBasEd: TGroupBox
        Left = 33
        Top = 436
        Width = 294
        Height = 93
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1041#1072#1079#1086#1074#1072#1103' '#1077#1076#1080#1085#1080#1094#1072
        TabOrder = 6
        object NameBasEdcxDBLabel: TcxDBLabel
          Left = 20
          Top = 20
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          DataBinding.DataField = 'NAMEED'
          ParentFont = False
          Style.Font.Charset = DEFAULT_CHARSET
          Style.Font.Color = clWindowText
          Style.Font.Height = -15
          Style.Font.Name = 'MS Sans Serif'
          Style.Font.Style = [fsBold]
          Style.IsFontAssigned = True
          Height = 26
          Width = 149
        end
        object CodeBasEdcxDBLabel: TcxDBLabel
          Left = 20
          Top = 66
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          DataBinding.DataField = 'CODE_SED'
          Properties.Alignment.Horz = taRightJustify
          Height = 26
          Width = 86
          AnchorX = 106
        end
        object cxLabel2: TcxLabel
          Left = 111
          Top = 66
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = '/'
        end
        object BarCodeBasEdcxDBLabel: TcxDBLabel
          Left = 127
          Top = 66
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          DataBinding.DataField = 'SHED'
          Height = 26
          Width = 149
        end
        object cxLabel3: TcxLabel
          Left = 20
          Top = 46
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1050#1060'1:'
        end
        object cxLabel4: TcxLabel
          Left = 129
          Top = 46
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1050#1060'2:'
        end
        object KFBasEdcxDBLabel: TcxDBLabel
          Left = 58
          Top = 46
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          DataBinding.DataField = 'KFED'
          Height = 25
          Width = 53
        end
        object KF2BasEdcxDBLabel: TcxDBLabel
          Left = 171
          Top = 46
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          DataBinding.DataField = 'KF2_SED'
          Height = 25
          Width = 99
        end
        object cxButtonEditBasEd: TcxButton
          Left = 217
          Top = 14
          Width = 28
          Height = 28
          Hint = #1048#1079#1084#1077#1085#1080#1090#1100' '#1087#1072#1088#1072#1084#1077#1090#1088#1099' '#1073#1072#1079#1086#1074#1086#1081' '#1077#1076#1080#1085#1080#1094#1099
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Glyph.Data = {
            36040000424D3604000000000000360000002800000010000000100000000100
            2000000000000004000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000384738868FB1
            8FEA85A485E582A182E57F9E7FE5809E7FE5809E7FE5809E7FE5809E7FE5809E
            7FE5809E7FE57F9E7FE581A081E583A283E58FB18FE93E4E3E90070A071986A5
            86E28EAF8EFF799778FF8EAE8DFF8BAD8AFF8BAD8AFF8BAD8AFF8BAD8AFF8BAD
            8AFF8BAD8AFF8EAE8DFF7C9B7CFF86A686FF8AAA8AEB0B0E0B2200000000212A
            214F9ABE99FE8AAC89FFC9F6C6FFD0FECDFFCEFDCBFFCEFDCBFFCEFDCBFFCDFD
            CBFFCEFDCBFFCDFACAFF8BAE8AFF96BA96FF2731275D00000000000000000000
            00005267529FA5CBA5FFA4CCA2FFD4FFD1FFD0FFCDFFD0FFCDFFD0FFCDFFD0FF
            CDFFD5FFD2FFA8D1A7FFA0C5A0FF5A6F59AD0000000000000000000000000000
            000006070618809E80DDA3C9A3FFBCEABAFFD2FFCFFFCFFFCCFFCFFFCCFFD2FF
            CFFFC1EFBEFFA0C59FFF86A385E7070907200000000000000000000000000000
            0000000000001D261D49A3C6A3FDAAD2A9FFCDFBCAFFD0FFCDFFD0FFCDFFCFFD
            CCFFA9D2A8FFA5C8A5FF212A2157000000000000000000000000000000000000
            000000000000000000004C5F4C98B4DDB4FFB6E3B5FFD1FFCEFFD1FFCEFFB9E6
            B7FFB6DDB5FF546653A600000000000000000000000000000000000000000000
            0000000000000000000004060414809F80DCBBE7BBFFC6F6C4FFC9F9C6FFBCE9
            BCFF8AA889E50608051D00000000000000000000000000000000000000000000
            00000000000000000000000000001F281F4FA7CEA7FEC1F0C0FFC1F1C1FFB1D8
            B0FF242D245D0000000000000000000000000000000000000000000000000000
            00000000000000000000000000000000000047594795C2EDC1FFCAF5C9FF4F62
            4FA4000000000000000000000000000000000000000000000000000000000000
            00000000000000000000000000000000000003040310809F80DF89A989E90406
            0518000000000000000000000000000000000000000000000000000000000000
            000000000000000000000000000000000000000000002029204D232D235A0000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000}
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
          OnClick = cxButtonEditBasEdClick
        end
      end
      object cxLabel14: TcxLabel
        Left = 30
        Top = 10
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1054#1089#1085#1086#1074#1085#1099#1077' '#1087#1072#1088#1072#1084#1077#1090#1088#1099' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099
        ParentFont = False
        Style.Font.Charset = DEFAULT_CHARSET
        Style.Font.Color = clNavy
        Style.Font.Height = -23
        Style.Font.Name = 'MS Sans Serif'
        Style.Font.Style = [fsBold]
        Style.IsFontAssigned = True
      end
      object GroupBox1: TGroupBox
        Left = 335
        Top = 243
        Width = 332
        Height = 283
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1062#1077#1085#1099
        TabOrder = 8
        object ToolBar4: TToolBar
          Left = 2
          Top = 18
          Width = 328
          Height = 28
          Caption = 'ToolBar4'
          Color = clCaptionText
          Images = DM.ImageList1
          ParentColor = False
          TabOrder = 0
          object ToolButton1: TToolButton
            Left = 0
            Top = 0
            Width = 9
            Caption = 'ToolButton1'
            ImageIndex = 3
            Style = tbsSeparator
          end
          object ToolButtonAddPrice: TToolButton
            Left = 9
            Top = 0
            Caption = 'ToolButtonAddPrice'
            ImageIndex = 0
            OnClick = ToolButtonAddPriceClick
          end
          object ToolButtonDeletePrice: TToolButton
            Left = 32
            Top = 0
            Caption = 'ToolButtonDeletePrice'
            ImageIndex = 2
            OnClick = ToolButtonDeletePriceClick
          end
        end
        object cxGrid1: TcxGrid
          Left = 2
          Top = 46
          Width = 328
          Height = 235
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Align = alClient
          TabOrder = 1
          object cxGrid1DBTableView1: TcxGridDBTableView
            NavigatorButtons.ConfirmDelete = False
            DataController.Summary.DefaultGroupSummaryItems = <>
            DataController.Summary.FooterSummaryItems = <>
            DataController.Summary.SummaryGroups = <>
            OptionsBehavior.IncSearch = True
            OptionsSelection.InvertSelect = False
            OptionsView.ColumnAutoWidth = True
            OptionsView.GroupByBox = False
            Styles.Header = DM.cxStyleHeaderTable
            object cxGrid1DBTableView1NAMETPRICE: TcxGridDBColumn
              Caption = #1058#1080#1087' '#1094#1077#1085
              DataBinding.FieldName = 'NAME_SPRTYPE_PRICE'
              Styles.Header = DM.cxStyleHeaderTable
              Width = 91
            end
            object cxGrid1DBTableView1ZNACH_PRICE: TcxGridDBColumn
              Caption = #1047#1085#1072#1095#1077#1085#1080#1077
              DataBinding.FieldName = 'VALUE_SPRPRICE'
              PropertiesClassName = 'TcxCalcEditProperties'
              Properties.DisplayFormat = '0.00'
              Properties.Precision = 15
              Styles.Header = DM.cxStyleHeaderTable
              Width = 93
            end
          end
          object cxGrid1Level1: TcxGridLevel
            GridView = cxGrid1DBTableView1
          end
        end
      end
      object ModelcxDBTextEdit: TcxDBTextEdit
        Left = 131
        Top = 308
        DataBinding.DataField = 'MODEL_STR_SPRNOM'
        TabOrder = 9
        Width = 194
      end
      object CodeAnalogcxDBTextEdit: TcxDBTextEdit
        Left = 131
        Top = 338
        DataBinding.DataField = 'CODE_ANALOG_STR_SPRNOM'
        TabOrder = 10
        Width = 194
      end
      object DostupnocxDBCheckBox: TcxDBCheckBox
        Left = 39
        Top = 87
        Caption = #1076#1086#1089#1090#1091#1087#1085#1086' '#1082' '#1079#1072#1082#1072#1079#1091
        DataBinding.DataField = 'FL_DOSTUPNO_SPRNOM'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        TabOrder = 11
        Width = 170
      end
      object PriceZakupcxDBCalcEdit: TcxDBCalcEdit
        Left = 204
        Top = 368
        DataBinding.DataField = 'PRICE_ZAKUP_SPRNOM'
        TabOrder = 12
        Width = 121
      end
      object PricecxDBCalcEdit: TcxDBCalcEdit
        Left = 207
        Top = 398
        DataBinding.DataField = 'PRICE_SPRNOM'
        TabOrder = 13
        Width = 121
      end
      object NameNomcxDBButtonEdit: TcxDBButtonEdit
        Left = 131
        Top = 218
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
        TabOrder = 14
        Width = 534
      end
      object CodeNomcxDBLabel: TcxDBLabel
        Left = 20
        Top = 248
        DataBinding.DataField = 'CODENOM'
        Height = 21
        Width = 121
      end
      object ArtNomcxDBLabel: TcxDBLabel
        Left = 24
        Top = 281
        DataBinding.DataField = 'ARTNOM'
        Height = 21
        Width = 121
      end
      object BarCodecxDBLabel: TcxDBLabel
        Left = 166
        Top = 248
        DataBinding.DataField = 'SHED'
        Height = 21
        Width = 121
      end
      object LocationcxDBTextEdit: TcxDBTextEdit
        Left = 683
        Top = 43
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'LOCATION_SPRNOM'
        TabOrder = 18
        OnKeyDown = ArtcxDBTextEditKeyDown
        Width = 149
      end
      object RepairCodecxDBTextEdit: TcxDBTextEdit
        Left = 683
        Top = 85
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'REPAIRCODE_SPRNOM'
        TabOrder = 19
        OnKeyDown = ArtcxDBTextEditKeyDown
        Width = 149
      end
      object Art2cxDBTextEdit: TcxDBTextEdit
        Left = 683
        Top = 134
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'ART2_SPRNOM'
        TabOrder = 20
        OnKeyDown = ArtcxDBTextEditKeyDown
        Width = 238
      end
      object Angl_NamecxDBMemo: TcxDBMemo
        Left = 680
        Top = 208
        DataBinding.DataField = 'ANGL_NAME_SPRNOM'
        TabOrder = 21
        Height = 89
        Width = 241
      end
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 288
    Top = 120
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
      OnExecute = ActionOpenHelpExecute
    end
    object ActionSetMainTabSheet: TAction
      Caption = 'ActionSetMainTabSheet'
      ShortCut = 116
    end
    object ActionSetAdditionallyTabSheet: TAction
      Caption = 'ActionSetAdditionallyTabSheet'
      ShortCut = 117
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
