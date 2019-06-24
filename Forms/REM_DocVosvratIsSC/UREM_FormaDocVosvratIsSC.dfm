object REM_FormaDocVosvratIsSC: TREM_FormaDocVosvratIsSC
  Left = 290
  Top = 119
  Caption = #1044#1086#1082#1091#1084#1077#1085#1090' "'#1042#1086#1079#1074#1088#1072#1090' '#1080#1079' '#1057#1062'"'
  ClientHeight = 619
  ClientWidth = 879
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
    Width = 879
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
      Width = 139
      Height = 20
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      AutoSize = True
      DataField = 'FNAME_USER'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -17
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object ProsmotrLabel: TLabel
      Left = 20
      Top = 30
      Width = 131
      Height = 20
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1090#1086#1083#1100#1082#1086' '#1087#1088#1086#1089#1084#1086#1090#1088
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -17
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
  end
  object Panel3: TPanel
    Left = 0
    Top = 305
    Width = 0
    Height = 218
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 2
    ExplicitTop = 257
    ExplicitHeight = 266
  end
  object Panel4: TPanel
    Left = 877
    Top = 305
    Width = 2
    Height = 218
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 3
    ExplicitTop = 257
    ExplicitHeight = 266
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 879
    Height = 305
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 113
      Top = 155
      Width = 194
      Height = 26
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1042#1086#1079#1074#1088#1072#1090' '#1080#1079' '#1057#1062' '#8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 441
      Top = 148
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
      Left = 4
      Top = 266
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
      Left = 40
      Top = 237
      Width = 50
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1050#1083#1080#1077#1085#1090':'
    end
    object Label7: TLabel
      Left = 479
      Top = 190
      Width = 127
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1053#1086#1084#1077#1088' '#1087#1086#1089#1090#1072#1074#1097#1080#1082#1072':'
    end
    object Label8: TLabel
      Left = 650
      Top = 190
      Width = 35
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1044#1072#1090#1072':'
    end
    object ToolBar2: TToolBar
      Left = 0
      Top = 0
      Width = 879
      Height = 30
      Color = clBtnFace
      EdgeBorders = [ebTop, ebRight, ebBottom]
      Images = DM.ImageList1
      ParentColor = False
      TabOrder = 5
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
    end
    object PrimcxDBTextEdit: TcxDBTextEdit
      Left = 98
      Top = 266
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'PRIM_REM_DSCRET'
      TabOrder = 10
      OnKeyDown = PrimcxDBTextEditKeyDown
      Width = 611
    end
    object NumDoccxDBTextEdit: TcxDBTextEdit
      Left = 326
      Top = 158
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NUM_REM_GALLDOC'
      TabOrder = 3
      OnKeyDown = NumDoccxDBTextEditKeyDown
      Width = 100
    end
    object PosDoccxDBDateEdit: TcxDBDateEdit
      Left = 485
      Top = 158
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'POS_REM_GALLDOC'
      Properties.Kind = ckDateTime
      Properties.OnChange = PosDoccxDBDateEditPropertiesChange
      TabOrder = 4
      OnKeyDown = PosDoccxDBDateEditKeyDown
      Width = 196
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
      Properties.ReadOnly = False
      Properties.OnButtonClick = NameFirmcxDBButtonEditPropertiesButtonClick
      TabOrder = 1
      Width = 337
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
      Properties.ReadOnly = False
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
      Top = 38
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
    object NameKlientcxDBButtonEdit: TcxDBButtonEdit
      Left = 98
      Top = 234
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
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameKlientcxDBButtonEditPropertiesButtonClick
      TabOrder = 6
      Width = 336
    end
    object NumDocKlientcxDBTextEdit: TcxDBTextEdit
      Left = 485
      Top = 208
      DataBinding.DataField = 'NUMDOCSC_REM_DSCRET'
      TabOrder = 7
      OnKeyDown = NumDocKlientcxDBTextEditKeyDown
      Width = 121
    end
    object PosDocKlientcxDBDateEdit: TcxDBDateEdit
      Left = 656
      Top = 208
      DataBinding.DataField = 'POSDOCSC_REM_DSCRET'
      TabOrder = 8
      OnKeyDown = PosDocKlientcxDBDateEditKeyDown
      Width = 145
    end
    object cxLabel9: TcxLabel
      Left = 442
      Top = 95
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1041#1080#1079#1085#1077#1089' '#1086#1087#1077#1088#1072#1094#1080#1103':'
    end
    object NameBusinessOpercxDBButtonEdit: TcxDBButtonEdit
      Left = 566
      Top = 94
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
      TabOrder = 12
      Width = 272
    end
    object NameProjectcxDBButtonEdit: TcxDBButtonEdit
      Left = 566
      Top = 119
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
      TabOrder = 13
      Width = 272
    end
    object cxLabel4: TcxLabel
      Left = 508
      Top = 120
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1088#1086#1077#1082#1090':'
    end
  end
  object cxGrid1: TcxGrid
    Left = 0
    Top = 305
    Width = 877
    Height = 218
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    TabOrder = 4
    ExplicitTop = 257
    ExplicitHeight = 266
    object cxGrid1DBTableView1: TcxGridDBTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.DataSource = REM_DMDocRemont.DataSourceDocT
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <
        item
          Kind = skSum
          FieldName = 'SUM_REM_DREMONTT'
        end
        item
          Kind = skSum
          FieldName = 'SUMMEX_REM_DREMONTT'
        end>
      DataController.Summary.SummaryGroups = <>
      OptionsView.ColumnAutoWidth = True
      OptionsView.Footer = True
      Styles.Footer = DM.cxStyleHeaderTable
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1RECNO: TcxGridDBColumn
        Caption = #8470
        DataBinding.FieldName = 'RECNO'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 42
      end
      object cxGrid1DBTableView1NAME_REM_Z: TcxGridDBColumn
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
        DataBinding.FieldName = 'NAME_REM_Z'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ReadOnly = True
        Properties.OnButtonClick = cxGrid1DBTableView1NAME_REM_ZPropertiesButtonClick
        Width = 160
      end
      object cxGrid1DBTableView1MODEL_REM_Z: TcxGridDBColumn
        Caption = #1052#1086#1076#1077#1083#1100
        DataBinding.FieldName = 'MODEL_REM_Z'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 96
      end
      object cxGrid1DBTableView1SERNUM_REM_Z: TcxGridDBColumn
        Caption = #1057#1077#1088'. '#1085#1086#1084#1077#1088
        DataBinding.FieldName = 'SERNUM_REM_Z'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 97
      end
      object cxGrid1DBTableView1SERNUM2_REM_Z: TcxGridDBColumn
        Caption = #1057#1077#1088'. '#1085#1086#1084#1077#1088' 2'
        DataBinding.FieldName = 'SERNUM2_REM_Z'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 96
      end
      object cxGrid1DBTableView1KLIENT_NAME_REM_Z: TcxGridDBColumn
        Caption = #1050#1083#1080#1077#1085#1090
        DataBinding.FieldName = 'KLIENT_NAME_REM_Z'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 96
      end
      object cxGrid1DBTableView1NUM_REM_Z: TcxGridDBColumn
        Caption = #1053#1086#1084#1077#1088
        DataBinding.FieldName = 'NUM_REM_Z'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 96
      end
      object cxGrid1DBTableView1POS_REM_Z: TcxGridDBColumn
        Caption = #1044#1072#1090#1072
        DataBinding.FieldName = 'POS_REM_Z'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 96
      end
      object cxGrid1DBTableView1KOL_REM_DSCRETT: TcxGridDBColumn
        Caption = #1050#1086#1083'.'
        DataBinding.FieldName = 'KOL_REM_DSCRETT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Width = 96
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
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
    end
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 448
    Top = 40
  end
end
