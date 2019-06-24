object FormaDocZamena: TFormaDocZamena
  Left = 290
  Top = 119
  Caption = #1044#1086#1082#1091#1084#1077#1085#1090' "'#1047#1072#1084#1077#1085#1072'"'
  ClientHeight = 619
  ClientWidth = 849
  Color = clBtnFace
  Constraints.MinWidth = 848
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
    Top = 523
    Width = 849
    Height = 96
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object DBTextFNameUser: TDBText
      Left = 20
      Top = 10
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
      Left = 20
      Top = 30
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
    object cxButtonPrint: TcxButton
      Left = 230
      Top = 49
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionPrint
      TabOrder = 0
    end
    object cxButtonSave: TcxButton
      Left = 330
      Top = 49
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionSave
      TabOrder = 1
    end
    object cxButtonDvReg: TcxButton
      Left = 430
      Top = 49
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionDvReg
      TabOrder = 2
    end
    object cxButtonOK: TcxButton
      Left = 529
      Top = 49
      Width = 93
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionOK
      TabOrder = 3
    end
    object cxButtonClose: TcxButton
      Left = 629
      Top = 49
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      TabOrder = 4
    end
    object SumPostcxDBLabel: TcxDBLabel
      Left = 482
      Top = 12
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'P_RSUM_DZAMENA'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clWindowText
      Style.Font.Height = -20
      Style.Font.Name = 'MS Sans Serif'
      Style.Font.Style = [fsBold]
      Style.IsFontAssigned = True
      Height = 26
      Width = 149
    end
    object SumSpiscxDBLabel: TcxDBLabel
      Left = 689
      Top = 12
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'S_RSUM_DZAMENA'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clWindowText
      Style.Font.Height = -20
      Style.Font.Name = 'MS Sans Serif'
      Style.Font.Style = [fsBold]
      Style.IsFontAssigned = True
      Height = 26
      Width = 149
    end
    object cxLabel2: TcxLabel
      Left = 443
      Top = 5
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = '+'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clWindowText
      Style.Font.Height = -28
      Style.Font.Name = 'MS Sans Serif'
      Style.Font.Style = []
      Style.IsFontAssigned = True
    end
    object cxLabel3: TcxLabel
      Left = 667
      Top = 1
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = '-'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clWindowText
      Style.Font.Height = -28
      Style.Font.Name = 'MS Sans Serif'
      Style.Font.Style = []
      Style.IsFontAssigned = True
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 218
    Width = 0
    Height = 305
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 2
  end
  object Panel4: TPanel
    Left = 847
    Top = 218
    Width = 2
    Height = 305
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 3
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 849
    Height = 218
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 28
      Top = 111
      Width = 122
      Height = 26
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1047#1072#1084#1077#1085#1072'  '#8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 441
      Top = 103
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
    object Label3: TLabel
      Left = 20
      Top = 180
      Width = 86
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077':'
    end
    object Label5: TLabel
      Left = 28
      Top = 69
      Width = 47
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1060#1080#1088#1084#1072':'
    end
    object Label6: TLabel
      Left = 482
      Top = 35
      Width = 43
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1082#1083#1072#1076':'
    end
    object RTPriceLabel: TLabel
      Left = 347
      Top = 146
      Width = 138
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1058#1080#1087' '#1094#1077#1085' '#1088#1077#1072#1083#1080#1079#1072#1094#1080#1080':'
    end
    object ToolBar2: TToolBar
      Left = 0
      Top = 0
      Width = 849
      Height = 30
      Color = clBtnFace
      EdgeBorders = [ebTop, ebRight, ebBottom]
      Images = DM.ImageList1
      ParentColor = False
      TabOrder = 9
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
        Width = 171
        Caption = 'ToolButton2'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButton3: TToolButton
        Left = 234
        Top = 0
        Width = 8
        Caption = 'ToolButton3'
        ImageIndex = 4
        Style = tbsSeparator
      end
      object ToolButtonExtModule: TToolButton
        Left = 242
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
        Caption = 'ToolButtonExtModule'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
      end
    end
    object PrimcxDBTextEdit: TcxDBTextEdit
      Left = 108
      Top = 176
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'DESCR_DZAMENA'
      TabOrder = 8
      OnKeyDown = PrimcxDBTextEditKeyDown
      Width = 611
    end
    object NumDoccxDBTextEdit: TcxDBTextEdit
      Left = 333
      Top = 111
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NUMDOC'
      TabOrder = 6
      OnKeyDown = NumDoccxDBTextEditKeyDown
      Width = 100
    end
    object PosDoccxDBDateEdit: TcxDBDateEdit
      Left = 485
      Top = 111
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'POSDOC'
      Properties.Kind = ckDateTime
      TabOrder = 7
      OnKeyDown = PosDoccxDBDateEditKeyDown
      Width = 236
    end
    object NameFirmcxDBButtonEdit: TcxDBButtonEdit
      Left = 97
      Top = 65
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
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameFirmcxDBButtonEditPropertiesButtonClick
      TabOrder = 1
      Width = 336
    end
    object NameInfBasecxDBButtonEdit: TcxDBButtonEdit
      Left = 98
      Top = 38
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
      Width = 336
    end
    object cxLabel1: TcxLabel
      Left = 20
      Top = 39
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1048#1085#1092'. '#1073#1072#1079#1072':'
    end
    object NameSkladcxDBButtonEdit: TcxDBButtonEdit
      Left = 532
      Top = 32
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
      Width = 306
    end
    object TypePricecxDBLookupComboBox: TcxDBLookupComboBox
      Left = 485
      Top = 143
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'IDRTPRICE_DZAMENA'
      Properties.ImmediatePost = True
      Properties.KeyFieldNames = 'ID_TPRICE'
      Properties.ListColumns = <
        item
          FieldName = 'NAME_TPRICE'
        end>
      TabOrder = 11
      Width = 217
    end
    object EditPropPartcxButton: TcxButton
      Left = 746
      Top = 174
      Width = 92
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1072#1088#1090#1080#1103
      TabOrder = 12
      OnClick = EditPropPartcxButtonClick
    end
    object NameBusinessOpercxDBButtonEdit: TcxDBButtonEdit
      Left = 566
      Top = 60
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
      Left = 442
      Top = 61
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1041#1080#1079#1085#1077#1089' '#1086#1087#1077#1088#1072#1094#1080#1103':'
    end
    object cxLabel4: TcxLabel
      Left = 508
      Top = 86
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1088#1086#1077#1082#1090':'
    end
    object NameProjectcxDBButtonEdit: TcxDBButtonEdit
      Left = 566
      Top = 85
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
      Left = 177
      Top = 111
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'PREFIKS_NUM_GALLDOC'
      TabOrder = 5
      Width = 145
    end
  end
  object cxGrid1: TcxGrid
    Left = 0
    Top = 218
    Width = 847
    Height = 305
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    TabOrder = 4
    object cxGrid1DBTableView1: TcxGridDBTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
    end
    object cxGrid1DBBandedTableView1: TcxGridDBBandedTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsSelection.InvertSelect = False
      OptionsView.ColumnAutoWidth = True
      OptionsView.BandCaptionsInColumnAlternateCaption = True
      Styles.Header = DM.cxStyleHeaderTable
      Bands = <
        item
        end>
      object cxGrid1DBBandedTableView1S_KF_DZAMENAT: TcxGridDBBandedColumn
        Caption = #1050#1060
        DataBinding.FieldName = 'S_KF_DZAMENAT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Width = 83
        Position.BandIndex = 0
        Position.ColIndex = 4
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1S_KOL_DZAMENAT: TcxGridDBBandedColumn
        Caption = #1050#1086#1083'.'
        DataBinding.FieldName = 'S_KOL_DZAMENAT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Width = 54
        Position.BandIndex = 0
        Position.ColIndex = 2
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1S_RPRICE_DZAMENAT: TcxGridDBBandedColumn
        Caption = #1056#1086#1079#1085'. '#1094#1077#1085#1072
        DataBinding.FieldName = 'S_RPRICE_DZAMENAT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Width = 79
        Position.BandIndex = 0
        Position.ColIndex = 5
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1S_RSUM_DZAMENAT: TcxGridDBBandedColumn
        Caption = #1056#1086#1079#1085'. '#1089#1091#1084#1084#1072
        DataBinding.FieldName = 'S_RSUM_DZAMENAT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Width = 83
        Position.BandIndex = 0
        Position.ColIndex = 6
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1P_KF_DZAMENAT: TcxGridDBBandedColumn
        Caption = #1050#1060
        DataBinding.FieldName = 'P_KF_DZAMENAT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Styles.Content = DM.cxStyleVidelString
        Width = 83
        Position.BandIndex = 0
        Position.ColIndex = 4
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1P_KOL_DZAMENAT: TcxGridDBBandedColumn
        Caption = #1050#1086#1083'.'
        DataBinding.FieldName = 'P_KOL_DZAMENAT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Styles.Content = DM.cxStyleVidelString
        Width = 54
        Position.BandIndex = 0
        Position.ColIndex = 2
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1P_RPRICE_DZAMENAT: TcxGridDBBandedColumn
        Caption = #1056#1086#1079#1085'. '#1094#1077#1085#1072
        DataBinding.FieldName = 'P_RPRICE_DZAMENAT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Styles.Content = DM.cxStyleVidelString
        Width = 79
        Position.BandIndex = 0
        Position.ColIndex = 5
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1P_RSUM_DZAMENAT: TcxGridDBBandedColumn
        Caption = #1056#1086#1079#1085'. '#1089#1091#1084#1084#1072
        DataBinding.FieldName = 'P_RSUM_DZAMENAT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Styles.Content = DM.cxStyleVidelString
        Width = 83
        Position.BandIndex = 0
        Position.ColIndex = 6
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1S_NAMENOM: TcxGridDBBandedColumn
        Caption = '  - '#1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072
        DataBinding.FieldName = 'S_NAMENOM'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = cxGrid1DBBandedTableView1S_NAMENOMPropertiesButtonClick
        Width = 266
        Position.BandIndex = 0
        Position.ColIndex = 1
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1S_NAMEED: TcxGridDBBandedColumn
        Caption = #1045#1076'.'
        DataBinding.FieldName = 'S_NAMEED'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = cxGrid1DBBandedTableView1S_NAMEEDPropertiesButtonClick
        Width = 81
        Position.BandIndex = 0
        Position.ColIndex = 3
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1P_NAMENOM: TcxGridDBBandedColumn
        Caption = ' + '#1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072
        DataBinding.FieldName = 'P_NAMENOM'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = cxGrid1DBBandedTableView1P_NAMENOMPropertiesButtonClick
        Styles.Content = DM.cxStyleVidelString
        Width = 266
        Position.BandIndex = 0
        Position.ColIndex = 1
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1P_NAMEED: TcxGridDBBandedColumn
        Caption = #1045#1076'.'
        DataBinding.FieldName = 'P_NAMEED'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = cxGrid1DBBandedTableView1P_NAMEEDPropertiesButtonClick
        Styles.Content = DM.cxStyleVidelString
        Width = 81
        Position.BandIndex = 0
        Position.ColIndex = 3
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1RECNO: TcxGridDBBandedColumn
        Caption = #8470
        DataBinding.FieldName = 'RECNO'
        Width = 40
        Position.BandIndex = 0
        Position.ColIndex = 0
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1Column1: TcxGridDBBandedColumn
        Styles.Content = DM.cxStyleVidelString
        Width = 40
        Position.BandIndex = 0
        Position.ColIndex = 0
        Position.RowIndex = 1
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBBandedTableView1
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
    object ActionPrint: TAction
      Caption = #1055#1077#1095#1072#1090#1100
      ImageIndex = 43
      OnExecute = ActionPrintExecute
    end
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 280
    Top = 8
  end
end
