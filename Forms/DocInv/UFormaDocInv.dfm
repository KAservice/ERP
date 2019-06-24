object FormaDocInv: TFormaDocInv
  Left = 276
  Top = 148
  Caption = #1044#1086#1082#1091#1084#1077#1085#1090' "'#1048#1085#1074#1077#1085#1090#1072#1088#1080#1079#1072#1094#1080#1103'"'
  ClientHeight = 550
  ClientWidth = 839
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
  OnCreate = FormCreate
  PixelsPerInch = 120
  TextHeight = 16
  object Panel2: TPanel
    Left = 0
    Top = 454
    Width = 839
    Height = 96
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 2
    object NameUserDBText: TDBText
      Left = 10
      Top = 10
      Width = 152
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
      Left = 266
      Top = 7
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
    object cxButtonPoGrp: TcxButton
      Left = 137
      Top = 49
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1086' '#1075#1088#1091#1087#1087#1072#1084
      TabOrder = 0
      OnClick = cxButtonPoGrpClick
    end
    object cxButtonPrintFaktOst: TcxButton
      Left = 236
      Top = 49
      Width = 93
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1060#1072#1082#1090'. '#1086#1089#1090#1072#1090#1086#1082
      TabOrder = 1
      OnClick = cxButtonPrintFaktOstClick
    end
    object cxButtonPrint: TcxButton
      Left = 336
      Top = 49
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionPrint
      TabOrder = 2
    end
    object cxButtonSave: TcxButton
      Left = 436
      Top = 49
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionSave
      TabOrder = 3
    end
    object cxButtonDvReg: TcxButton
      Left = 535
      Top = 49
      Width = 93
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionDvReg
      TabOrder = 4
    end
    object cxButtonOK: TcxButton
      Left = 635
      Top = 49
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionOK
      TabOrder = 5
    end
    object cxButtonClose: TcxButton
      Left = 735
      Top = 49
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      TabOrder = 6
    end
    object cxButton1: TcxButton
      Left = 37
      Top = 49
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057' '#1094#1077#1085#1072#1084#1080
      TabOrder = 7
      OnClick = cxButton1Click
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 247
    Width = 4
    Height = 207
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 3
  end
  object Panel4: TPanel
    Left = 828
    Top = 247
    Width = 11
    Height = 207
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 4
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 839
    Height = 247
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 73
      Top = 106
      Width = 222
      Height = 26
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1048#1085#1074#1077#1085#1090#1072#1088#1080#1079#1072#1094#1080#1103'  '#8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 587
      Top = 100
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
      Left = 30
      Top = 217
      Width = 86
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077':'
    end
    object Label5: TLabel
      Left = 10
      Top = 70
      Width = 47
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1060#1080#1088#1084#1072':'
    end
    object Label6: TLabel
      Left = 464
      Top = 43
      Width = 43
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1082#1083#1072#1076':'
    end
    object Label4: TLabel
      Left = 608
      Top = 197
      Width = 55
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1058#1080#1087' '#1094#1077#1085':'
    end
    object Label8: TLabel
      Left = 2
      Top = 169
      Width = 115
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1048#1085#1074#1077#1085#1090#1072#1088#1080#1079#1072#1094#1080#1103':'
    end
    object Label9: TLabel
      Left = 513
      Top = 140
      Width = 227
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1058#1080#1087' '#1087#1088#1086#1074#1077#1076#1077#1085#1080#1103'  '#1080#1085#1074#1077#1085#1090#1072#1088#1080#1079#1072#1094#1080#1080':'
    end
    object ToolBar2: TToolBar
      Left = 0
      Top = 0
      Width = 839
      Height = 30
      Color = clBtnFace
      EdgeBorders = [ebTop, ebRight, ebBottom]
      Images = DM.ImageList1
      ParentColor = False
      TabOrder = 10
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
        Action = ActionInsertRecord
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonDelete: TToolButton
        Left = 40
        Top = 0
        Action = ActionDeleteRecord
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButton2: TToolButton
        Left = 63
        Top = 0
        Width = 83
        Caption = 'ToolButton2'
        ImageIndex = 0
        Style = tbsSeparator
      end
      object AddAllTovarToolButton: TToolButton
        Left = 146
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1074#1089#1077' '#1090#1086#1074#1072#1088#1099' '#1080#1079' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072
        Caption = 'AddAllTovarToolButton'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = AddAllTovarToolButtonClick
      end
      object AddOstatkiToolButton: TToolButton
        Left = 169
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1090#1086#1074#1072#1088#1099', '#1082#1086#1090#1086#1088#1099#1077' '#1077#1089#1090#1100' '#1085#1072' '#1089#1082#1083#1072#1076#1077
        Caption = 'AddOstatkiToolButton'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = AddOstatkiToolButtonClick
      end
      object ToolButtonOstatki: TToolButton
        Left = 192
        Top = 0
        Hint = #1056#1072#1089#1089#1095#1080#1090#1072#1090#1100' '#1086#1089#1090#1072#1090#1082#1080
        Caption = 'ToolButtonOstatki'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonOstatkiClick
      end
      object ToolButtonCreateDocSpis: TToolButton
        Left = 215
        Top = 0
        Hint = #1040#1082#1090' '#1089#1087#1080#1089#1072#1085#1080#1103
        Caption = 'ToolButtonCreateDocSpis'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonCreateDocSpisClick
      end
      object ToolButtonCreateDocOstNom: TToolButton
        Left = 238
        Top = 0
        Hint = #1042#1074#1086#1076' '#1086#1089#1090#1072#1090#1082#1086#1074
        Caption = 'ToolButtonCreateDocOstNom'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonCreateDocOstNomClick
      end
      object ToolButtonAddDataRev: TToolButton
        Left = 261
        Top = 0
        Hint = #1047#1072#1087#1086#1083#1085#1080#1090#1100' '#1076#1072#1085#1085#1099#1084#1080' '#1088#1077#1074#1080#1079#1080#1081
        Caption = 'ToolButtonAddDataRev'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonAddDataRevClick
      end
      object ToolButton4: TToolButton
        Left = 284
        Top = 0
        Width = 117
        Caption = 'ToolButton4'
        ImageIndex = 1
        Style = tbsSeparator
      end
      object ToolButton3: TToolButton
        Left = 401
        Top = 0
        Width = 8
        Caption = 'ToolButton3'
        ImageIndex = 0
        Style = tbsSeparator
      end
      object ToolButtonExtModule: TToolButton
        Left = 409
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
        Caption = 'ToolButtonExtModule'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
        ParentShowHint = False
        ShowHint = True
      end
    end
    object NameFirmcxDBButtonEdit: TcxDBButtonEdit
      Left = 80
      Top = 66
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
      Properties.OnButtonClick = NamecxDBButtonEditPropertiesButtonClick
      TabOrder = 1
      Width = 320
    end
    object NameSkladcxDBButtonEdit: TcxDBButtonEdit
      Left = 513
      Top = 39
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
      Properties.OnButtonClick = cxDBButtonEdit1PropertiesButtonClick
      TabOrder = 2
      Width = 315
    end
    object PrimcxDBTextEdit: TcxDBTextEdit
      Left = 118
      Top = 213
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'PRIM_INV'
      TabOrder = 9
      OnKeyDown = PrimcxDBTextEditKeyDown
      Width = 435
    end
    object TypeInvComboBox: TcxComboBox
      Left = 510
      Top = 164
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Properties.DropDownListStyle = lsFixedList
      Properties.Items.Strings = (
        '0 - '#1058#1086#1083#1100#1082#1086' '#1087#1086' '#1074#1099#1073#1088#1072#1085#1085#1086#1081' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1077
        '1 - '#1055#1086' '#1074#1089#1077#1084#1091' '#1089#1082#1083#1072#1076#1091)
      Properties.ReadOnly = False
      Properties.OnChange = TypeInvcxComboBoxPropertiesChange
      TabOrder = 7
      Width = 317
    end
    object NameInvcxDBButtonEdit: TcxDBButtonEdit
      Left = 118
      Top = 165
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAME_SINV'
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 13
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameInvcxDBButtonEditPropertiesButtonClick
      TabOrder = 6
      Width = 348
    end
    object NumDoccxDBTextEdit: TcxDBTextEdit
      Left = 484
      Top = 108
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NUMDOC'
      TabOrder = 4
      OnKeyDown = NumDoccxDBTextEditKeyDown
      Width = 95
    end
    object PosDoccxDBDateEdit: TcxDBDateEdit
      Left = 635
      Top = 108
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'POSDOC'
      Properties.Kind = ckDateTime
      TabOrder = 5
      OnKeyDown = PosDoccxDBDateEditKeyDown
      Width = 164
    end
    object NameInfcxDBButtonEdit: TcxDBButtonEdit
      Left = 80
      Top = 41
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
      Properties.OnButtonClick = NameInfcxDBButtonEditPropertiesButtonClick
      TabOrder = 0
      Width = 320
    end
    object cxLabel1: TcxLabel
      Left = 0
      Top = 42
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1048#1085#1092'. '#1073#1072#1079#1072':'
    end
    object TypePriceComboBox: TcxComboBox
      Left = 608
      Top = 214
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Properties.DropDownListStyle = lsFixedList
      Properties.OnChange = TypePriceComboBoxPropertiesChange
      TabOrder = 8
      Width = 220
    end
    object PrefiksNumcxDBTextEdit: TcxDBTextEdit
      Left = 336
      Top = 108
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'PREFIKS_NUM_GALLDOC'
      TabOrder = 3
      Width = 145
    end
  end
  object cxGrid1: TcxGrid
    Left = 4
    Top = 247
    Width = 824
    Height = 207
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    TabOrder = 1
    object cxGrid1DBTableView1: TcxGridDBTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.Options = [dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding, dcoImmediatePost]
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <
        item
          Kind = skSum
          Column = cxGrid1DBTableView1SUMF_INVT
        end>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.GoToNextCellOnEnter = True
      OptionsBehavior.IncSearch = True
      OptionsSelection.InvertSelect = False
      OptionsView.CellAutoHeight = True
      OptionsView.ColumnAutoWidth = True
      OptionsView.Footer = True
      Styles.Footer = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1RECNO: TcxGridDBColumn
        Caption = #8470
        DataBinding.FieldName = 'RECNO'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 31
      end
      object cxGrid1DBTableView1NAMEGN: TcxGridDBColumn
        Caption = #1043#1088#1091#1087#1087#1072
        DataBinding.FieldName = 'NAMEGN'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 148
      end
      object cxGrid1DBTableView1CODENOM: TcxGridDBColumn
        Caption = #1050#1086#1076
        DataBinding.FieldName = 'CODENOM'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 31
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
        Width = 148
      end
      object cxGrid1DBTableView1NAMEED: TcxGridDBColumn
        Caption = #1045#1076#1080#1085#1080#1094#1072
        DataBinding.FieldName = 'NAMEED'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 50
      end
      object cxGrid1DBTableView1KF_INVT: TcxGridDBColumn
        Caption = #1050
        DataBinding.FieldName = 'KF_INVT'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 49
      end
      object cxGrid1DBTableView1KOLUCH_INVT: TcxGridDBColumn
        Caption = #1050#1086#1083'-'#1074#1086' '#1091#1095'.'
        DataBinding.FieldName = 'KOLUCH_INVT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 52
      end
      object cxGrid1DBTableView1KOLFAKT_INVT: TcxGridDBColumn
        Caption = #1050#1086#1083'-'#1074#1086' '#1092#1072#1082#1090'.'
        DataBinding.FieldName = 'KOLFAKT_INVT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 52
      end
      object cxGrid1DBTableView1PRICE_INVT: TcxGridDBColumn
        Caption = #1062#1077#1085#1072
        DataBinding.FieldName = 'PRICE_INVT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 52
      end
      object cxGrid1DBTableView1SUMF_INVT: TcxGridDBColumn
        Caption = #1057#1091#1084#1084#1072
        DataBinding.FieldName = 'SUMF_INVT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 49
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 8
    Top = 80
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
      OnExecute = ActionOpenHelpExecute
    end
    object ActionInsertRecord: TAction
      Caption = 'ActionInsertRecord'
      ImageIndex = 0
      ShortCut = 45
      OnExecute = ActionInsertRecordExecute
    end
    object ActionDeleteRecord: TAction
      Caption = 'ActionDeleteRecord'
      ImageIndex = 2
      ShortCut = 46
      OnExecute = ActionDeleteRecordExecute
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
    Left = 408
    Top = 56
  end
end
