object FormaDocRepKKM: TFormaDocRepKKM
  Left = 245
  Top = 381
  Caption = #1054#1090#1095#1077#1090' '#1050#1050#1052
  ClientHeight = 615
  ClientWidth = 926
  Color = clBtnFace
  Constraints.MinWidth = 935
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
    Top = 279
    Width = 7
    Height = 202
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 2
  end
  object Panel3: TPanel
    Left = 0
    Top = 481
    Width = 926
    Height = 134
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object Label9: TLabel
      Left = 20
      Top = 42
      Width = 129
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1054#1087#1083#1072#1090#1072' '#1085#1072#1083#1080#1095#1085#1099#1084#1080':'
    end
    object Label10: TLabel
      Left = 325
      Top = 42
      Width = 126
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1083#1072#1090#1077#1078#1085#1086#1081' '#1082#1072#1088#1090#1086#1081':'
    end
    object DBTextFNameUser: TDBText
      Left = 10
      Top = 108
      Width = 164
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      AutoSize = True
      DataField = 'FNAME_USER'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -18
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object ProsmotrLabel: TLabel
      Left = 10
      Top = 89
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
      Left = 623
      Top = 79
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionDvReg
      TabOrder = 3
    end
    object cxButtonSave: TcxButton
      Left = 523
      Top = 79
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionSave
      TabOrder = 2
    end
    object cxButtonOK: TcxButton
      Left = 722
      Top = 79
      Width = 93
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionOK
      TabOrder = 4
    end
    object cxButtonClose: TcxButton
      Left = 822
      Top = 79
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      TabOrder = 5
    end
    object OplPCcxDBCalcEdit: TcxDBCalcEdit
      Left = 453
      Top = 36
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'OPLPC_DREPKKM'
      TabOrder = 1
      OnKeyDown = OplPCcxDBCalcEditKeyDown
      Width = 149
    end
    object OplNalcxDBCalcEdit: TcxDBCalcEdit
      Left = 169
      Top = 39
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'OPLNAL_DREPKKM'
      TabOrder = 0
      OnKeyDown = OplNalcxDBCalcEditKeyDown
      Width = 149
    end
  end
  object Panel4: TPanel
    Left = 914
    Top = 279
    Width = 12
    Height = 202
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 3
  end
  object cxGrid1: TcxGrid
    Left = 7
    Top = 279
    Width = 907
    Height = 202
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    TabOrder = 0
    object cxGrid1DBTableView1: TcxGridDBTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <
        item
          Kind = skSum
          Column = cxGrid1DBTableView1SUM_DREPKKMT
        end
        item
          Kind = skSum
          Column = cxGrid1DBTableView1SK_DREPKKMT
        end>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.GoToNextCellOnEnter = True
      OptionsBehavior.IncSearch = True
      OptionsSelection.InvertSelect = False
      OptionsView.CellAutoHeight = True
      OptionsView.ColumnAutoWidth = True
      OptionsView.Footer = True
      object cxGrid1DBTableView1RECNO: TcxGridDBColumn
        Caption = #8470
        DataBinding.FieldName = 'RECNO'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 42
      end
      object cxGrid1DBTableView1NAMENOM: TcxGridDBColumn
        Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072
        DataBinding.FieldName = 'NAMENOM'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ReadOnly = True
        Properties.OnButtonClick = cxGrid1DBTableView1NAMENOMPropertiesButtonClick
        Styles.Header = DM.cxStyleHeaderTable
        Width = 198
      end
      object cxGrid1DBTableView1KOL_DREPKKMT: TcxGridDBColumn
        Caption = #1050#1086#1083'.'
        DataBinding.FieldName = 'KOL_DREPKKMT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 42
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
        Styles.Header = DM.cxStyleHeaderTable
        Width = 59
      end
      object cxGrid1DBTableView1KF_DREPKKMT: TcxGridDBColumn
        Caption = #1050
        DataBinding.FieldName = 'KF_DREPKKMT'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 70
      end
      object cxGrid1DBTableView1PRICE_DREPKKMT: TcxGridDBColumn
        Caption = #1062#1077#1085#1072
        DataBinding.FieldName = 'PRICE_DREPKKMT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 70
      end
      object cxGrid1DBTableView1SUM_DREPKKMT: TcxGridDBColumn
        Caption = #1057#1091#1084#1084#1072
        DataBinding.FieldName = 'SUM_DREPKKMT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 69
      end
      object cxGrid1DBTableView1SK_DREPKKMT: TcxGridDBColumn
        Caption = #1057#1082#1080#1076#1082#1072
        DataBinding.FieldName = 'SK_DREPKKMT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 70
      end
      object cxGrid1DBTableView1NAD_DREPKKMT: TcxGridDBColumn
        Caption = #1053#1072#1076#1073#1072#1074#1082#1072
        DataBinding.FieldName = 'NAD_DREPKKMT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 70
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object ToolBar2: TToolBar
    Left = 0
    Top = 0
    Width = 926
    Height = 33
    Color = clBtnFace
    EdgeBorders = [ebTop, ebBottom]
    Images = DM.ImageList1
    ParentColor = False
    TabOrder = 4
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
      Action = ActionAddString
      ParentShowHint = False
      ShowHint = True
    end
    object ToolButtonDelete: TToolButton
      Left = 40
      Top = 0
      Action = ActionDeleteString
      ParentShowHint = False
      ShowHint = True
    end
    object ToolButton2: TToolButton
      Left = 63
      Top = 0
      Width = 170
      Caption = 'ToolButton2'
      ImageIndex = 3
      Style = tbsSeparator
    end
    object ToolButton3: TToolButton
      Left = 233
      Top = 0
      Width = 8
      Caption = 'ToolButton3'
      ImageIndex = 4
      Style = tbsSeparator
    end
    object ToolButtonExtModule: TToolButton
      Left = 241
      Top = 0
      Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
      Caption = 'ToolButtonExtModule'
      DropdownMenu = PopupMenuExtModule
      ImageIndex = 51
      ParentShowHint = False
      ShowHint = True
    end
  end
  object cxPageControl1: TcxPageControl
    Left = 0
    Top = 33
    Width = 926
    Height = 246
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    ActivePage = cxTabSheet1
    Align = alTop
    TabOrder = 5
    ClientRectBottom = 246
    ClientRectRight = 926
    ClientRectTop = 27
    object cxTabSheet1: TcxTabSheet
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1054#1089#1085#1086#1074#1085#1072#1103
      ImageIndex = 0
      object Label12: TLabel
        Left = 20
        Top = 36
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
      object Label1: TLabel
        Left = 4
        Top = 66
        Width = 150
        Height = 32
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1054#1090#1095#1077#1090' '#1050#1050#1052
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -28
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label2: TLabel
        Left = 453
        Top = 66
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
      object Label13: TLabel
        Left = 516
        Top = -2
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
      object Label4: TLabel
        Left = 620
        Top = 187
        Width = 55
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1058#1080#1087' '#1094#1077#1085':'
      end
      object Label6: TLabel
        Left = 30
        Top = 142
        Width = 67
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1044#1086#1075#1086#1074#1086#1088':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label15: TLabel
        Left = 496
        Top = 110
        Width = 35
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1050#1050#1052':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label14: TLabel
        Left = 10
        Top = 110
        Width = 94
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
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label7: TLabel
        Left = 17
        Top = 192
        Width = 86
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077':'
      end
      object Label11: TLabel
        Left = 471
        Top = 139
        Width = 83
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1041#1072#1085#1082'. '#1089#1095#1077#1090':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object NameKlientcxDBButtonEdit: TcxDBButtonEdit
        Left = 110
        Top = 106
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NAMEKLIENT'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameKlientcxDBButtonEditPropertiesButtonClick
        TabOrder = 8
        Width = 354
      end
      object cxLabel1: TcxLabel
        Left = 14
        Top = 7
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1048#1085#1092'. '#1073#1072#1079#1072':'
      end
      object NameInfBasecxDBButtonEdit: TcxDBButtonEdit
        Left = 110
        Top = 6
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NAME_SINFBASE_OBMEN'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameInfBasecxDBButtonEditPropertiesButtonClick
        TabOrder = 0
        Width = 354
      end
      object NameFirmcxDBButtonEdit: TcxDBButtonEdit
        Left = 108
        Top = 39
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NAMEFIRM'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.OnButtonClick = NameFirmcxDBButtonEditPropertiesButtonClick
        TabOrder = 1
        Width = 356
      end
      object NumDoccxDBTextEdit: TcxDBTextEdit
        Left = 312
        Top = 71
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NUMDOC'
        TabOrder = 6
        OnKeyDown = NumDoccxDBTextEditKeyDown
        Width = 139
      end
      object PosDoccxDBDateEdit: TcxDBDateEdit
        Left = 486
        Top = 74
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'POSDOC'
        TabOrder = 7
        OnKeyDown = PosDoccxDBDateEditKeyDown
        Width = 148
      end
      object NameSkladcxDBButtonEdit: TcxDBButtonEdit
        Left = 585
        Top = 0
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NAMESKLAD'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameSkladcxDBButtonEditPropertiesButtonClick
        TabOrder = 2
        Width = 329
      end
      object DvRegcxDBCheckBox: TcxDBCheckBox
        Left = 681
        Top = 74
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1076#1074#1080#1078#1077#1085#1080#1103' '#1087#1086' '#1088#1077#1075#1080#1089#1090#1088#1072#1084
        DataBinding.DataField = 'DVREG_DREPKKM'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        TabOrder = 10
        Width = 192
      end
      object TypePriceComboBox: TcxComboBox
        Left = 681
        Top = 182
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Properties.DropDownListStyle = lsFixedList
        Properties.ImmediatePost = True
        Properties.OnValidate = TypePriceComboBoxPropertiesValidate
        TabOrder = 14
        Width = 216
      end
      object PrimcxDBTextEdit: TcxDBTextEdit
        Left = 106
        Top = 183
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'PRIM_DREPKKM'
        TabOrder = 15
        OnKeyDown = PrimcxDBTextEditKeyDown
        Width = 507
      end
      object NameKKMcxDBButtonEdit: TcxDBButtonEdit
        Left = 562
        Top = 106
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NAMEKKM'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameKKMcxDBButtonEditPropertiesButtonClick
        TabOrder = 11
        Width = 335
      end
      object NameDogovorcxDBButtonEdit: TcxDBButtonEdit
        Left = 108
        Top = 135
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NAME_SDOG'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameDogovorcxDBButtonEditPropertiesButtonClick
        TabOrder = 9
        Width = 356
      end
      object NameBSchetcxDBButtonEdit: TcxDBButtonEdit
        Left = 562
        Top = 135
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NAMEBSCHET'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        TabOrder = 12
        Width = 335
      end
      object NameBusinessOpercxDBButtonEdit: TcxDBButtonEdit
        Left = 642
        Top = 26
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NAME_SBUSINESS_OPER'
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
        Properties.OnButtonClick = NameBusinessOpercxDBButtonEditPropertiesButtonClick
        TabOrder = 3
        Width = 272
      end
      object cxLabel9: TcxLabel
        Left = 518
        Top = 27
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1041#1080#1079#1085#1077#1089' '#1086#1087#1077#1088#1072#1094#1080#1103':'
      end
      object cxLabel3: TcxLabel
        Left = 584
        Top = 52
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1055#1088#1086#1077#1082#1090':'
      end
      object NameProjectcxDBButtonEdit: TcxDBButtonEdit
        Left = 642
        Top = 51
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NAME_SPROJECT'
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
        Properties.OnButtonClick = NameProjectcxDBButtonEditPropertiesButtonClick
        TabOrder = 4
        Width = 272
      end
      object PrefiksNumcxDBTextEdit: TcxDBTextEdit
        Left = 159
        Top = 71
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'PREFIKS_NUM_GALLDOC'
        TabOrder = 5
        Width = 145
      end
    end
    object cxTabSheet2: TcxTabSheet
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1050#1050#1052
      ImageIndex = 1
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object Label5: TLabel
        Left = 346
        Top = 92
        Width = 96
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1053#1086#1084#1077#1088' '#1050#1051' '#1050#1050#1052':'
      end
      object Label18: TLabel
        Left = 73
        Top = 92
        Width = 83
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1052#1086#1076#1077#1083#1100' '#1050#1050#1052':'
      end
      object Label19: TLabel
        Left = 71
        Top = 126
        Width = 88
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1047#1072#1074#1086#1076#1089#1082#1086#1081' '#8470
      end
      object Label3: TLabel
        Left = 33
        Top = 164
        Width = 135
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1056#1077#1075#1080#1089#1090#1088#1072#1094#1080#1086#1085#1085#1099#1081' '#8470
      end
      object Label8: TLabel
        Left = 358
        Top = 148
        Width = 110
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1053#1086#1084#1077#1088' '#1095#1077#1082#1072' '#1050#1050#1052':'
      end
      object Label20: TLabel
        Left = 49
        Top = 17
        Width = 472
        Height = 26
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1056#1077#1082#1074#1080#1079#1080#1090#1099' '#1082#1086#1085#1090#1088#1086#1083#1100#1085#1086'-'#1082#1072#1089#1089#1086#1074#1086#1081' '#1084#1072#1096#1080#1085#1099':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -23
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object NumKLcxDBTextEdit: TcxDBTextEdit
        Left = 466
        Top = 82
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NKL_DREPKKM'
        TabOrder = 0
        OnKeyDown = NumKLcxDBTextEditKeyDown
        Width = 149
      end
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 32
    Top = 128
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
      OnExecute = ActionOpenHelpExecute
    end
    object ActionAddString: TAction
      Caption = 'ActionAddString'
      ImageIndex = 0
      ShortCut = 45
      OnExecute = ActionAddStringExecute
    end
    object ActionDeleteString: TAction
      Caption = 'ActionDeleteString'
      ImageIndex = 2
      ShortCut = 46
      OnExecute = ActionDeleteStringExecute
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
    object ActionDvReg: TAction
      Caption = #1055#1088#1086#1074#1077#1089#1090#1080
      ImageIndex = 56
      OnExecute = ActionDvRegExecute
    end
    object ActionSave: TAction
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      ImageIndex = 55
      OnExecute = ActionSaveExecute
    end
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 256
    Top = 16
  end
end
