object REM_FormaDocVigruska: TREM_FormaDocVigruska
  Left = 146
  Top = -55
  Caption = #1044#1086#1082#1091#1084#1077#1085#1090' "'#1042#1099#1075#1088#1091#1079#1082#1072'"'
  ClientHeight = 605
  ClientWidth = 1023
  Color = clBtnFace
  Constraints.MinWidth = 689
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDesigned
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TPanel
    Left = 0
    Top = 553
    Width = 1023
    Height = 52
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 0
    object DBTextFNameUser: TDBText
      Left = 33
      Top = 8
      Width = 119
      Height = 16
      AutoSize = True
      DataField = 'NAME_USER'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object ProsmotrLabel: TLabel
      Left = 34
      Top = 31
      Width = 111
      Height = 16
      Caption = #1090#1086#1083#1100#1082#1086' '#1087#1088#1086#1089#1084#1086#1090#1088
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object cxButtonPrint: TcxButton
      Left = 210
      Top = 20
      Width = 74
      Height = 26
      Action = ActionPrint
      TabOrder = 0
    end
    object cxButtonSave: TcxButton
      Left = 291
      Top = 20
      Width = 75
      Height = 26
      Action = ActionSave
      TabOrder = 1
    end
    object cxButtonOK: TcxButton
      Left = 453
      Top = 20
      Width = 75
      Height = 26
      Action = ActionOK
      TabOrder = 2
    end
    object cxButtonClose: TcxButton
      Left = 534
      Top = 20
      Width = 75
      Height = 26
      Action = ActionClose
      TabOrder = 3
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 209
    Width = 0
    Height = 344
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 1
  end
  object Panel4: TPanel
    Left = 1022
    Top = 209
    Width = 1
    Height = 344
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 2
  end
  object cxGrid1: TcxGrid
    Left = 0
    Top = 209
    Width = 1022
    Height = 344
    Align = alClient
    TabOrder = 3
    object cxGrid1DBTableView1: TcxGridDBTableView
      NavigatorButtons.ConfirmDelete = False
      OnCellDblClick = cxGrid1DBTableView1CellDblClick
      DataController.DataSource = REM_DMDocRemont.DataSourceDocT
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <
        item
          Kind = skSum
          FieldName = 'SUM_REM_DZAKTPRT'
        end
        item
          Kind = skSum
          FieldName = 'SUMMEX_REM_DZAKTPRT'
        end>
      DataController.Summary.SummaryGroups = <>
      OptionsData.Editing = False
      OptionsView.CellAutoHeight = True
      OptionsView.ColumnAutoWidth = True
      OptionsView.Footer = True
      OptionsView.GroupByBox = False
      Styles.Footer = DM.cxStyleHeaderTable
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1RECNO: TcxGridDBColumn
        Caption = #8470
        DataBinding.FieldName = 'RECNO'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 43
      end
      object cxGrid1DBTableView1OUT_IDZ: TcxGridDBColumn
        DataBinding.FieldName = 'OUT_IDZ'
        Width = 108
      end
      object cxGrid1DBTableView1IDDOCVIGR_REM_GUR_VIGRT: TcxGridDBColumn
        DataBinding.FieldName = 'IDDOCVIGR_REM_GUR_VIGRT'
        Width = 96
      end
      object cxGrid1DBTableView1TDOC_REM_GALLDOC: TcxGridDBColumn
        Caption = #1044#1086#1082#1091#1084#1077#1085#1090
        DataBinding.FieldName = 'TDOC_REM_GALLDOC'
        Width = 129
      end
      object cxGrid1DBTableView1POS_REM_GALLDOC: TcxGridDBColumn
        Caption = #1044#1072#1090#1072
        DataBinding.FieldName = 'POS_REM_GALLDOC'
        Width = 68
      end
      object cxGrid1DBTableView1PREFIKS_NUM_REM_GALLDOC: TcxGridDBColumn
        DataBinding.FieldName = 'PREFIKS_NUM_REM_GALLDOC'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Width = 31
        IsCaptionAssigned = True
      end
      object cxGrid1DBTableView1NUM_REM_GALLDOC: TcxGridDBColumn
        Caption = #1053#1086#1084#1077#1088
        DataBinding.FieldName = 'NUM_REM_GALLDOC'
        Width = 50
      end
      object cxGrid1DBTableView1PR_REM_GALLDOC: TcxGridDBColumn
        Caption = #1055#1088#1086#1074'.'
        DataBinding.FieldName = 'PR_REM_GALLDOC'
        Width = 47
      end
      object cxGrid1DBTableView1NAME_SINFBASE_OBMEN: TcxGridDBColumn
        Caption = #1048#1085#1092'. '#1073#1072#1079#1072
        DataBinding.FieldName = 'NAME_SINFBASE_OBMEN'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Width = 87
      end
      object cxGrid1DBTableView1NAMEFIRM: TcxGridDBColumn
        Caption = #1060#1080#1088#1084#1072
        DataBinding.FieldName = 'NAMEFIRM'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Width = 84
      end
      object cxGrid1DBTableView1NAMESKLAD: TcxGridDBColumn
        Caption = #1057#1082#1083#1072#1076
        DataBinding.FieldName = 'NAMESKLAD'
        Width = 114
      end
      object cxGrid1DBTableView1NAMEKLIENT: TcxGridDBColumn
        Caption = #1050#1083#1080#1077#1085#1090
        DataBinding.FieldName = 'NAMEKLIENT'
        Width = 104
      end
      object cxGrid1DBTableView1OUT_INFO: TcxGridDBColumn
        DataBinding.FieldName = 'OUT_INFO'
        Width = 295
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 1023
    Height = 209
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 4
    object Label1: TLabel
      Left = 117
      Top = 79
      Width = 125
      Height = 24
      Caption = #1042#1099#1075#1088#1091#1079#1082#1072'  '#8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 349
      Top = 76
      Width = 32
      Height = 26
      Caption = #1086#1090' '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label4: TLabel
      Left = 391
      Top = 138
      Width = 39
      Height = 13
      Caption = #1050#1083#1080#1077#1085#1090':'
    end
    object Label10: TLabel
      Left = 288
      Top = 154
      Width = 65
      Height = 13
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1050#1086#1076' '#1074#1099#1088#1091#1079#1082#1080
    end
    object Label11: TLabel
      Left = 582
      Top = 156
      Width = 78
      Height = 13
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = 'GUID '#1074#1099#1075#1088#1091#1079#1082#1080
    end
    object Label23: TLabel
      Left = 14
      Top = 156
      Width = 89
      Height = 13
      Caption = 'GUD '#1090#1088#1072#1085#1079#1072#1082#1094#1080#1080':'
    end
    object Label27: TLabel
      Left = 17
      Top = 134
      Width = 56
      Height = 13
      Caption = #1055#1088#1086#1080#1079#1074'-'#1083#1100':'
    end
    object Label3: TLabel
      Left = 726
      Top = 56
      Width = 40
      Height = 13
      Caption = #1053#1072#1095#1072#1083#1086':'
    end
    object Label7: TLabel
      Left = 726
      Top = 98
      Width = 34
      Height = 13
      Caption = #1050#1086#1085#1077#1094':'
    end
    object ToolBar2: TToolBar
      Left = 0
      Top = 0
      Width = 1023
      Height = 30
      Color = clBtnFace
      EdgeBorders = [ebTop, ebRight, ebBottom]
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
      object ToolButtonOpenExtModule: TToolButton
        Left = 242
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
        Caption = 'ToolButtonOpenExtModule'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonAddAllDocPoKlientu: TToolButton
        Left = 265
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090#1099' '#1087#1086' '#1082#1083#1080#1077#1085#1090#1091' '#1079#1072' '#1087#1077#1088#1080#1086#1076
        Caption = 'ToolButtonAddAllDocPoKlientu'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonAddAllDocPoKlientuClick
      end
      object AddDocStartAktPrToolButton: TToolButton
        Left = 288
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090#1099' '#1053#1072#1095#1072#1083#1086' '#1088#1077#1084#1086#1085#1090#1072' '#1080' '#1040#1082#1090' '#1055#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1102
        Caption = 'AddDocStartAktPrToolButton'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = AddDocStartAktPrToolButtonClick
      end
    end
    object NumDoccxDBTextEdit: TcxDBTextEdit
      Left = 253
      Top = 84
      DataBinding.DataField = 'NUM_REM_GUR_VIGR'
      TabOrder = 1
      OnKeyDown = NumDoccxDBTextEditKeyDown
      Width = 81
    end
    object PosDoccxDBDateEdit: TcxDBDateEdit
      Left = 388
      Top = 84
      DataBinding.DataField = 'POS_REM_GUR_VIGR'
      Properties.Kind = ckDateTime
      Properties.OnChange = PosDoccxDBDateEditPropertiesChange
      TabOrder = 2
      OnKeyDown = PosDoccxDBDateEditKeyDown
      Width = 160
    end
    object NameInfBasecxDBButtonEdit: TcxDBButtonEdit
      Left = 60
      Top = 31
      DataBinding.DataField = 'NAME_SINFBASE_OBMEN'
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 13
      Properties.ReadOnly = False
      Properties.OnButtonClick = NameInfBasecxDBButtonEditPropertiesButtonClick
      TabOrder = 0
      Width = 192
    end
    object cxLabel1: TcxLabel
      Left = 1
      Top = 32
      Caption = #1048#1085#1092'. '#1073#1072#1079#1072':'
    end
    object NameKlientcxDBButtonEdit: TcxDBButtonEdit
      Left = 438
      Top = 132
      DataBinding.DataField = 'NAMEKLIENT'
      DataBinding.DataSource = REM_DMDocRemont.DataSourceDocAll
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
      Properties.OnButtonClick = NameKlientcxDBButtonEditPropertiesButtonClick
      TabOrder = 5
      Width = 257
    end
    object GUID_TRANScxDBTextEdit: TcxDBTextEdit
      Left = 14
      Top = 174
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      DataBinding.DataField = 'GUID_TRANSACTION_REM_GUR_VIGR'
      TabOrder = 7
      Width = 270
    end
    object ProducercxDBButtonEdit: TcxDBButtonEdit
      Left = 80
      Top = 132
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      DataBinding.DataField = 'NAME_SPRODUCER'
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end
        item
          Caption = 'X'
          Kind = bkText
        end>
      Properties.OnButtonClick = ProducercxDBButtonEditPropertiesButtonClick
      TabOrder = 3
      Width = 258
    end
    object GUIDVigrcxDBTextEdit: TcxDBTextEdit
      Left = 582
      Top = 172
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      DataBinding.DataField = 'GUID_VIGR_REM_GUR_VIGR'
      TabOrder = 8
      Width = 264
    end
    object CodeVigrcxDBTextEdit: TcxDBTextEdit
      Left = 300
      Top = 173
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      DataBinding.DataField = 'CODE_STR_VIGR_REM_GUR_VIGR'
      TabOrder = 9
      Width = 266
    end
    object PosStartcxDateEdit: TcxDateEdit
      Left = 780
      Top = 54
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Properties.Kind = ckDateTime
      TabOrder = 10
      Width = 222
    end
    object PosEndcxDateEdit: TcxDateEdit
      Left = 780
      Top = 95
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Properties.Kind = ckDateTime
      TabOrder = 11
      Width = 222
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 184
    Top = 40
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
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
    end
    object ActionSave: TAction
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      ImageIndex = 55
      OnExecute = ActionSaveExecute
    end
    object ActionPrint: TAction
      Caption = #1055#1077#1095#1072#1090#1100
      ImageIndex = 43
    end
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 352
    Top = 24
  end
end
