object FormaDocRealRoznForCashier: TFormaDocRealRoznForCashier
  Left = 289
  Top = 174
  Caption = #1056#1077#1072#1083#1080#1079#1072#1094#1080#1103' '#1088#1086#1079#1085'.'
  ClientHeight = 590
  ClientWidth = 831
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
  object Panel2: TPanel
    Left = 0
    Top = 287
    Width = 4
    Height = 205
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 0
  end
  object Panel3: TPanel
    Left = 0
    Top = 492
    Width = 831
    Height = 98
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object FSummaCheck: TLabel
      Left = 517
      Top = 0
      Width = 81
      Height = 26
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1091#1084#1084#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object SumDocDBText: TDBText
      Left = 610
      Top = 2
      Width = 154
      Height = 26
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      AutoSize = True
      DataField = 'SUMDOC'
      DataSource = DMDocRealRozn.DataSourceDocAll
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object DBTextFNameUser: TDBText
      Left = 10
      Top = 76
      Width = 164
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      AutoSize = True
      DataField = 'FNAME_USER'
      DataSource = DMDocRealRozn.DataSourceDocAll
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -18
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object ProsmotrLabel: TLabel
      Left = 10
      Top = 49
      Width = 155
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1090#1086#1083#1100#1082#1086' '#1087#1088#1086#1089#1084#1086#1090#1088
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -18
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object cxButtonDvReg: TcxButton
      Left = 383
      Top = 59
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionDvReg
      TabOrder = 0
    end
    object cxButtonSave: TcxButton
      Left = 482
      Top = 59
      Width = 93
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionSave
      TabOrder = 1
    end
    object cxButtonOK: TcxButton
      Left = 582
      Top = 59
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionOK
      TabOrder = 2
    end
    object cxButtonClose: TcxButton
      Left = 682
      Top = 59
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      TabOrder = 3
    end
  end
  object Panel4: TPanel
    Left = 827
    Top = 287
    Width = 4
    Height = 205
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 2
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 831
    Height = 287
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 3
    object Label1: TLabel
      Left = 10
      Top = 98
      Width = 253
      Height = 32
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1056#1077#1072#1083#1080#1079#1072#1094#1080#1103' '#1088#1086#1079#1085'.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -28
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 586
      Top = 102
      Width = 40
      Height = 32
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1086#1090' '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -28
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label7: TLabel
      Left = 187
      Top = 260
      Width = 86
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077':'
    end
    object Label12: TLabel
      Left = 10
      Top = 47
      Width = 73
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1060#1080#1088#1084#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -18
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label13: TLabel
      Left = 414
      Top = 47
      Width = 66
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1082#1083#1072#1076':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -18
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label14: TLabel
      Left = 10
      Top = 187
      Width = 82
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1086#1082#1091#1087#1072#1090#1077#1083#1100':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 271
      Top = 96
      Width = 30
      Height = 32
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -28
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label6: TLabel
      Left = 20
      Top = 226
      Width = 58
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1044#1086#1075#1086#1074#1086#1088':'
    end
    object NameTPriceDBText: TDBText
      Left = 532
      Top = 177
      Width = 218
      Height = 21
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataField = 'NAME_TPRICE'
      DataSource = DMDocRealRozn.DataSourceDoc
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label4: TLabel
      Left = 30
      Top = 158
      Width = 30
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1050#1050#1052':'
    end
    object Label5: TLabel
      Left = 473
      Top = 223
      Width = 159
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1077#1088#1074#1086#1085#1072#1095#1072#1083#1100#1085#1099#1081' '#1074#1079#1085#1086#1089':'
    end
    object ToolBar2: TToolBar
      Left = 0
      Top = 0
      Width = 831
      Height = 33
      Color = clBtnFace
      EdgeBorders = [ebTop, ebBottom]
      Images = DM.ImageList1
      ParentColor = False
      TabOrder = 0
      object ToolButton1: TToolButton
        Left = 0
        Top = 0
        Width = 17
        Caption = 'ToolButton1'
        Style = tbsSeparator
      end
      object ToolButtonInsert: TToolButton
        Left = 17
        Top = 0
        Hint = #1053#1086#1074#1072#1103' '#1089#1090#1088#1086#1082#1072
        Caption = 'ToolButtonInsert'
        ImageIndex = 0
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonInsertClick
      end
      object ToolButtonDelete: TToolButton
        Left = 40
        Top = 0
        Hint = #1059#1076#1072#1083#1080#1090#1100' '#1089#1090#1088#1086#1082#1091
        Caption = 'ToolButtonDelete'
        ImageIndex = 2
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonDeleteClick
      end
      object ToolButton2: TToolButton
        Left = 63
        Top = 0
        Width = 138
        Caption = 'ToolButton2'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButtonPrintNakl: TToolButton
        Left = 201
        Top = 0
        Hint = #1055#1077#1095#1072#1090#1100' '#1085#1072#1082#1083#1072#1076#1085#1086#1081
        Caption = 'ToolButtonPrintNakl'
        ImageIndex = 43
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonPrintNaklClick
      end
      object ToolButtonPrintOnFR: TToolButton
        Left = 224
        Top = 0
        Hint = #1055#1077#1095#1072#1090#1100' '#1085#1072' '#1060#1056
        Caption = 'ToolButtonPrintOnFR'
        ImageIndex = 44
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonPrintOnFRClick
      end
      object ToolButton3: TToolButton
        Left = 247
        Top = 0
        Width = 8
        Caption = 'ToolButton3'
        ImageIndex = 4
        Style = tbsSeparator
      end
      object ToolButtonAddGrafikPlat: TToolButton
        Left = 255
        Top = 0
        Hint = #1057#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100' '#1075#1088#1072#1092#1080#1082' '#1087#1083#1072#1090#1077#1078#1077#1081
        Caption = 'ToolButtonAddGrafikPlat'
        ImageIndex = 46
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonAddGrafikPlatClick
      end
      object NameBaseDBText: TDBText
        Left = 278
        Top = 0
        Width = 350
        Height = 22
        Alignment = taRightJustify
        DataField = 'NAME_SINFBASE_OBMEN'
        DataSource = DMDocRealRozn.DataSourceDocAll
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
    end
    object NameFirmcxDBTextEdit: TcxDBTextEdit
      Left = 84
      Top = 46
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAMEFIRM'
      DataBinding.DataSource = DMDocRealRozn.DataSourceDocAll
      TabOrder = 1
      Width = 315
    end
    object NameSkladcxDBTextEdit: TcxDBTextEdit
      Left = 482
      Top = 46
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAMESKLAD'
      DataBinding.DataSource = DMDocRealRozn.DataSourceDocAll
      TabOrder = 2
      Width = 319
    end
    object NumDoccxDBTextEdit: TcxDBTextEdit
      Left = 470
      Top = 106
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NUMDOC'
      DataBinding.DataSource = DMDocRealRozn.DataSourceDocAll
      TabOrder = 5
      Width = 108
    end
    object PosDoccxDBDateEdit: TcxDBDateEdit
      Left = 620
      Top = 108
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'POSDOC'
      DataBinding.DataSource = DMDocRealRozn.DataSourceDocAll
      Properties.Kind = ckDateTime
      TabOrder = 6
      Width = 207
    end
    object PrimcxDBTextEdit: TcxDBTextEdit
      Left = 276
      Top = 254
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'PRIM_DREALROZN'
      DataBinding.DataSource = DMDocRealRozn.DataSourceDoc
      TabOrder = 7
      Width = 525
    end
    object FirstSumcxDBCalcEdit: TcxDBCalcEdit
      Left = 631
      Top = 217
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'FIRSTSUM_DREALROZN'
      DataBinding.DataSource = DMDocRealRozn.DataSourceDoc
      TabOrder = 8
      Width = 149
    end
    object NameKKMcxDBTextEdit: TcxDBTextEdit
      Left = 95
      Top = 154
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAMEKKM'
      DataBinding.DataSource = DMDocRealRozn.DataSourceDoc
      Properties.ReadOnly = True
      TabOrder = 9
      Width = 330
    end
    object NameKlientcxDBButtonEdit: TcxDBButtonEdit
      Left = 95
      Top = 187
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAMEKLIENT'
      DataBinding.DataSource = DMDocRealRozn.DataSourceDocAll
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameKlientcxDBButtonEditPropertiesButtonClick
      TabOrder = 10
      Width = 330
    end
    object NameDogovorcxDBButtonEdit: TcxDBButtonEdit
      Left = 95
      Top = 220
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAME_SDOG'
      DataBinding.DataSource = DMDocRealRozn.DataSourceDocAll
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameDogovorcxDBButtonEditPropertiesButtonClick
      TabOrder = 11
      Width = 330
    end
    object NameProjectcxDBButtonEdit: TcxDBButtonEdit
      Left = 482
      Top = 76
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAME_SPROJECT'
      DataBinding.DataSource = DMDocRealRozn.DataSourceDocAll
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end
        item
          Caption = 'X'
          Kind = bkText
        end>
      Properties.OnButtonClick = NameProjectcxDBButtonEditPropertiesButtonClick
      TabOrder = 3
      Width = 319
    end
    object cxLabel3: TcxLabel
      Left = 421
      Top = 78
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1088#1086#1077#1082#1090':'
    end
    object PrefiksNumcxDBTextEdit: TcxDBTextEdit
      Left = 317
      Top = 106
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'PREFIKS_NUM_GALLDOC'
      TabOrder = 4
      Width = 145
    end
  end
  object cxPageControl1: TcxPageControl
    Left = 4
    Top = 287
    Width = 823
    Height = 205
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    ActivePage = cxTabSheet1
    Align = alClient
    TabOrder = 4
    ClientRectBottom = 205
    ClientRectRight = 823
    ClientRectTop = 27
    object cxTabSheet1: TcxTabSheet
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1058#1072#1073#1083#1080#1094#1072
      ImageIndex = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object cxGrid1: TcxGrid
        Left = 0
        Top = 0
        Width = 823
        Height = 178
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Align = alClient
        TabOrder = 0
        object cxGrid1DBTableView1: TcxGridDBTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.DataSource = DMDocRealRozn.DataSourceDocT
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <>
          DataController.Summary.SummaryGroups = <>
          OptionsSelection.InvertSelect = False
          OptionsView.ColumnAutoWidth = True
          Styles.Header = DM.cxStyleHeaderTable
          object cxGrid1DBTableView1RECNO: TcxGridDBColumn
            Caption = #8470
            DataBinding.FieldName = 'RECNO'
            Options.Editing = False
            Width = 46
          end
          object cxGrid1DBTableView1NAMENOM: TcxGridDBColumn
            Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
            DataBinding.FieldName = 'NAMENOM'
            PropertiesClassName = 'TcxButtonEditProperties'
            Properties.Buttons = <
              item
                Default = True
                Kind = bkEllipsis
              end>
            Properties.ReadOnly = True
            Properties.OnButtonClick = cxGrid1DBTableView1NAMENOMPropertiesButtonClick
            Width = 296
          end
          object cxGrid1DBTableView1KOL_DREALROZNT: TcxGridDBColumn
            Caption = #1050#1086#1083'.'
            DataBinding.FieldName = 'KOL_DREALROZNT'
            PropertiesClassName = 'TcxCalcEditProperties'
            Width = 51
          end
          object cxGrid1DBTableView1NAMEED: TcxGridDBColumn
            Caption = #1045#1076#1080#1085#1080#1094#1072
            DataBinding.FieldName = 'NAMEED'
            PropertiesClassName = 'TcxButtonEditProperties'
            Properties.Buttons = <
              item
                Default = True
                Kind = bkEllipsis
              end>
            Properties.ReadOnly = True
            Properties.OnButtonClick = cxGrid1DBTableView1NAMEEDPropertiesButtonClick
            Width = 62
          end
          object cxGrid1DBTableView1KF_DREALROZNT: TcxGridDBColumn
            Caption = #1050
            DataBinding.FieldName = 'KF_DREALROZNT'
            Options.Editing = False
            Width = 46
          end
          object cxGrid1DBTableView1PRICE_DREALROZNT: TcxGridDBColumn
            Caption = #1062#1077#1085#1072
            DataBinding.FieldName = 'PRICE_DREALROZNT'
            PropertiesClassName = 'TcxCalcEditProperties'
            Width = 83
          end
          object cxGrid1DBTableView1SUM_DREALROZNT: TcxGridDBColumn
            Caption = #1057#1091#1084#1084#1072
            DataBinding.FieldName = 'SUM_DREALROZNT'
            PropertiesClassName = 'TcxCalcEditProperties'
            Width = 83
          end
        end
        object cxGrid1Level1: TcxGridLevel
          GridView = cxGrid1DBTableView1
        end
      end
    end
    object cxTabSheet2: TcxTabSheet
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1043#1088#1072#1092#1080#1082' '#1087#1083#1072#1090#1077#1078#1077#1081
      ImageIndex = 1
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object cxGrid2: TcxGrid
        Left = 0
        Top = 0
        Width = 308
        Height = 178
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Align = alLeft
        TabOrder = 0
        object cxGrid2DBTableView1: TcxGridDBTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.DataSource = DMDocRealRozn.DataSourcePay
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <>
          DataController.Summary.SummaryGroups = <>
          OptionsView.ColumnAutoWidth = True
          OptionsView.GroupByBox = False
          Styles.Header = DM.cxStyleHeaderTable
          object cxGrid2DBTableView1RECNO: TcxGridDBColumn
            Caption = #8470
            DataBinding.FieldName = 'RECNO'
            Width = 67
          end
          object cxGrid2DBTableView1DO_DREALROZN_PAY: TcxGridDBColumn
            Caption = #1044#1086
            DataBinding.FieldName = 'DO_DREALROZN_PAY'
            PropertiesClassName = 'TcxDateEditProperties'
            Width = 67
          end
          object cxGrid2DBTableView1SUM_DREALROZN_PAY: TcxGridDBColumn
            Caption = #1057#1091#1084#1084#1072
            DataBinding.FieldName = 'SUM_DREALROZN_PAY'
            PropertiesClassName = 'TcxCalcEditProperties'
            Width = 114
          end
        end
        object cxGrid2Level1: TcxGridLevel
          GridView = cxGrid2DBTableView1
        end
      end
    end
  end
  object ActionList1: TActionList
    Images = DM.ImageList1
    Left = 664
    Top = 24
    object OpenHelp: TAction
      Caption = 'OpenHelp'
      ShortCut = 112
      OnExecute = OpenHelpExecute
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
    object ActionDvReg: TAction
      Caption = #1055#1088#1086#1074#1077#1089#1090#1080
      ImageIndex = 56
      OnExecute = ActionDvRegExecute
    end
  end
end
