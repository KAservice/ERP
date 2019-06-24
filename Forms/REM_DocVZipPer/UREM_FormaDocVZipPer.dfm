object REM_FormaDocVZipPer: TREM_FormaDocVZipPer
  Left = 290
  Top = 119
  Caption = #1044#1086#1082#1091#1084#1077#1085#1090' "'#1055#1077#1088#1077#1084#1077#1097#1077#1085#1080#1077'"'
  ClientHeight = 548
  ClientWidth = 878
  Color = clBtnFace
  Constraints.MinWidth = 689
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TPanel
    Left = 0
    Top = 470
    Width = 878
    Height = 78
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object DBTextFNameUser: TDBText
      Left = 16
      Top = 8
      Width = 119
      Height = 16
      AutoSize = True
      DataField = 'FNAME_USER'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object ProsmotrLabel: TLabel
      Left = 16
      Top = 24
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
      Left = 187
      Top = 40
      Width = 75
      Height = 25
      Action = ActionPrint
      TabOrder = 0
    end
    object cxButtonSave: TcxButton
      Left = 268
      Top = 40
      Width = 75
      Height = 25
      Action = ActionSave
      TabOrder = 1
    end
    object cxButtonDvReg: TcxButton
      Left = 349
      Top = 40
      Width = 75
      Height = 25
      Action = ActionDvReg
      TabOrder = 2
    end
    object cxButtonOK: TcxButton
      Left = 430
      Top = 40
      Width = 75
      Height = 25
      Action = ActionOK
      TabOrder = 3
    end
    object cxButtonClose: TcxButton
      Left = 511
      Top = 40
      Width = 75
      Height = 25
      Action = ActionClose
      TabOrder = 4
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 287
    Width = 0
    Height = 183
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 2
  end
  object Panel4: TPanel
    Left = 877
    Top = 287
    Width = 1
    Height = 183
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 3
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 878
    Height = 287
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 26
      Top = 120
      Width = 285
      Height = 24
      Caption = #1055#1077#1088#1077#1084#1077#1097#1077#1085#1080#1077' '#1074#1086#1079#1074#1088'. '#1047#1048#1055' '#8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 422
      Top = 121
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
    object Label3: TLabel
      Left = 6
      Top = 245
      Width = 66
      Height = 13
      Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077':'
    end
    object Label5: TLabel
      Left = 23
      Top = 56
      Width = 40
      Height = 13
      Caption = #1060#1080#1088#1084#1072':'
    end
    object Label6: TLabel
      Left = 392
      Top = 35
      Width = 34
      Height = 13
      Caption = #1057#1082#1083#1072#1076':'
    end
    object Label4: TLabel
      Left = 80
      Top = 186
      Width = 39
      Height = 13
      Caption = #1050#1083#1080#1077#1085#1090':'
    end
    object Label7: TLabel
      Left = 7
      Top = 164
      Width = 110
      Height = 13
      Caption = #1054#1087#1077#1088#1072#1094#1080#1103' '#1076#1086#1082#1091#1084#1077#1085#1090#1072':'
    end
    object ToolBar2: TToolBar
      Left = 0
      Top = 0
      Width = 878
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
      object ToolButtonViborOborud: TToolButton
        Left = 63
        Top = 0
        Hint = #1042#1099#1073#1088#1072#1090#1100' '#1086#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077' '#1080#1079' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' '#1074#1086#1079#1074#1088#1072#1090#1085#1086#1075#1086' '#1047#1048#1055'.'
        Caption = 'ToolButtonViborOborud'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonViborOborudClick
      end
      object ToolButton2: TToolButton
        Left = 86
        Top = 0
        Width = 171
        Caption = 'ToolButton2'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButton3: TToolButton
        Left = 257
        Top = 0
        Width = 8
        Caption = 'ToolButton3'
        ImageIndex = 4
        Style = tbsSeparator
      end
      object ToolButtonOpenExtModule: TToolButton
        Left = 265
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
        Caption = 'ToolButtonOpenExtModule'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonCreatePost: TToolButton
        Left = 288
        Top = 0
        Hint = #1057#1086#1079#1076#1072#1090#1100' '#1055#1077#1088#1077#1084#1077#1097#1077#1085#1080#1077' ('#1055#1089#1090#1091#1087#1083#1077#1085#1080#1077') '#1079#1072#1103#1074#1086#1082
        Caption = 'ToolButtonCreatePost'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonCreatePostClick
      end
      object ToolButtonAddAllOstatki: TToolButton
        Left = 311
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1074#1089#1077' '#1086#1089#1090#1072#1090#1082#1080
        Caption = 'ToolButtonAddAllOstatki'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonAddAllOstatkiClick
      end
    end
    object PrimcxDBTextEdit: TcxDBTextEdit
      Left = 82
      Top = 242
      DataBinding.DataField = 'PRIM_REM_DVZPER'
      TabOrder = 8
      OnKeyDown = PrimcxDBTextEditKeyDown
      Width = 497
    end
    object NumDoccxDBTextEdit: TcxDBTextEdit
      Left = 317
      Top = 124
      DataBinding.DataField = 'NUM_REM_GALLDOC'
      TabOrder = 3
      OnKeyDown = NumDoccxDBTextEditKeyDown
      Width = 81
    end
    object PosDoccxDBDateEdit: TcxDBDateEdit
      Left = 469
      Top = 124
      DataBinding.DataField = 'POS_REM_GALLDOC'
      Properties.Kind = ckDateTime
      Properties.OnChange = PosDoccxDBDateEditPropertiesChange
      TabOrder = 4
      OnKeyDown = PosDoccxDBDateEditKeyDown
      Width = 160
    end
    object NameFirmcxDBButtonEdit: TcxDBButtonEdit
      Left = 79
      Top = 53
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
      Width = 274
    end
    object NameInfBasecxDBButtonEdit: TcxDBButtonEdit
      Left = 80
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
      Width = 273
    end
    object cxLabel1: TcxLabel
      Left = 16
      Top = 32
      Caption = #1048#1085#1092'. '#1073#1072#1079#1072':'
    end
    object NameSkladcxDBButtonEdit: TcxDBButtonEdit
      Left = 432
      Top = 31
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
      Width = 249
    end
    object NameKlientcxDBButtonEdit: TcxDBButtonEdit
      Left = 128
      Top = 184
      DataBinding.DataField = 'NAMEKLIENT'
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameKlientcxDBButtonEditPropertiesButtonClick
      TabOrder = 6
      Width = 299
    end
    object cxLabel2: TcxLabel
      Left = 17
      Top = 210
      Caption = #1057#1082#1083#1072#1076' '#1087#1086#1083#1091#1095#1072#1090#1077#1083#1100':'
    end
    object NameSkladPolcxDBButtonEdit: TcxDBButtonEdit
      Left = 128
      Top = 210
      DataBinding.DataField = 'NAMESKLAD'
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 13
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameSkladPolcxDBButtonEditPropertiesButtonClick
      TabOrder = 10
      Width = 300
    end
    object cxLabel9: TcxLabel
      Left = 359
      Top = 77
      Caption = #1041#1080#1079#1085#1077#1089' '#1086#1087#1077#1088#1072#1094#1080#1103':'
    end
    object NameBusinessOpercxDBButtonEdit: TcxDBButtonEdit
      Left = 460
      Top = 76
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
      Width = 221
    end
    object NameProjectcxDBButtonEdit: TcxDBButtonEdit
      Left = 460
      Top = 97
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
      Width = 221
    end
    object cxLabel4: TcxLabel
      Left = 413
      Top = 98
      Caption = #1055#1088#1086#1077#1082#1090':'
    end
    object OperationDoccxDBImageComboBox: TcxDBImageComboBox
      Left = 128
      Top = 158
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      RepositoryItem = DM.cxEditRepository1ImageComboBoxItemOperationRemDocZPer
      DataBinding.DataField = 'OPER_REM_DVZPER'
      Properties.Items = <>
      TabOrder = 15
      Width = 300
    end
  end
  object cxGrid1: TcxGrid
    Left = 0
    Top = 287
    Width = 877
    Height = 183
    Align = alClient
    TabOrder = 4
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
        Width = 36
      end
      object cxGrid1DBTableView1NAMEKLIENT: TcxGridDBColumn
        Caption = #1050#1083#1080#1077#1085#1090
        DataBinding.FieldName = 'NAMEKLIENT'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Caption = '...'
            Default = True
            Kind = bkText
          end
          item
            Caption = #1061
            Kind = bkText
          end>
        Properties.OnButtonClick = cxGrid1DBTableView1NAMEKLIENTPropertiesButtonClick
        Width = 59
      end
      object cxGrid1DBTableView1NAME_STNOM: TcxGridDBColumn
        Caption = #1058#1080#1087' '#1085#1086#1084'.'
        DataBinding.FieldName = 'NAME_STNOM'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = cxGrid1DBTableView1NAME_STNOMPropertiesButtonClick
        Width = 52
      end
      object cxGrid1DBTableView1NAME_REM_Z: TcxGridDBColumn
        Caption = #1047#1072#1103#1074#1082#1072
        DataBinding.FieldName = 'NAME_REM_Z'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ReadOnly = True
        Properties.OnButtonClick = cxGrid1DBTableView1NAME_REM_ZPropertiesButtonClick
        Width = 49
      end
      object cxGrid1DBTableView1MODEL_REM_Z: TcxGridDBColumn
        Caption = #1052#1086#1076#1077#1083#1100
        DataBinding.FieldName = 'MODEL_REM_Z'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 42
      end
      object cxGrid1DBTableView1SERNUM_REM_Z: TcxGridDBColumn
        Caption = #1057#1077#1088'. '#1085#1086#1084#1077#1088
        DataBinding.FieldName = 'SERNUM_REM_Z'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 38
      end
      object cxGrid1DBTableView1SERNUM2_REM_Z: TcxGridDBColumn
        Caption = #1057#1077#1088'. '#1085#1086#1084#1077#1088' 2'
        DataBinding.FieldName = 'SERNUM2_REM_Z'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 36
      end
      object cxGrid1DBTableView1KLIENT_NAME_REM_Z: TcxGridDBColumn
        Caption = #1050#1083#1080#1077#1085#1090
        DataBinding.FieldName = 'KLIENT_NAME_REM_Z'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 36
      end
      object cxGrid1DBTableView1NUM_REM_Z: TcxGridDBColumn
        Caption = #1053#1086#1084#1077#1088
        DataBinding.FieldName = 'NUM_REM_Z'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 37
      end
      object cxGrid1DBTableView1POS_REM_Z: TcxGridDBColumn
        Caption = #1044#1072#1090#1072
        DataBinding.FieldName = 'POS_REM_Z'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 35
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
        Properties.OnButtonClick = cxGrid1DBTableView1NAMENOMPropertiesButtonClick
        Width = 49
      end
      object cxGrid1DBTableView1NAME_REM_SHARDWARE: TcxGridDBColumn
        Caption = #1054#1073#1086#1088#1091#1076#1086#1074#1072#1072#1085#1080#1077
        DataBinding.FieldName = 'NAME_REM_SHARDWARE'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = cxGrid1DBTableView1NAME_REM_SHARDWAREPropertiesButtonClick
        Width = 63
      end
      object cxGrid1DBTableView1NAME_REM_SPRMODEL: TcxGridDBColumn
        Caption = #1052#1086#1076#1077#1083#1100
        DataBinding.FieldName = 'NAME_REM_SPRMODEL'
        Width = 49
      end
      object cxGrid1DBTableView1SERNUM_REM_SHARDWARE: TcxGridDBColumn
        DataBinding.FieldName = 'SERNUM_REM_SHARDWARE'
        Width = 35
      end
      object cxGrid1DBTableView1NAME_REM_STVZIP: TcxGridDBColumn
        Caption = #1058#1080#1087' '#1074#1086#1079#1074#1088'. '#1047#1048#1055
        DataBinding.FieldName = 'NAME_REM_STVZIP'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Width = 51
      end
      object cxGrid1DBTableView1KOL_REM_DVZPERT: TcxGridDBColumn
        Caption = #1050#1086#1083'.'
        DataBinding.FieldName = 'KOL_REM_DVZPERT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Width = 46
      end
      object cxGrid1DBTableView1NAME_SMHRAN_OTPR: TcxGridDBColumn
        Caption = #1052#1077#1089#1090#1086' '#1093#1088#1072#1085'. '#1086#1090#1087#1088'.'
        DataBinding.FieldName = 'NAME_SMHRAN_OTPR'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end
          item
            Caption = 'X'
            Kind = bkText
          end>
        Properties.OnButtonClick = cxGrid1DBTableView1NAME_SMHRAN_OTPRPropertiesButtonClick
        Width = 83
      end
      object cxGrid1DBTableView1NAME_SMHRAN_POL: TcxGridDBColumn
        Caption = #1052#1077#1089#1090#1086' '#1093#1088#1072#1085'. '#1087#1086#1083'.'
        DataBinding.FieldName = 'NAME_SMHRAN_POL'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end
          item
            Caption = 'X'
            Kind = bkText
          end>
        Properties.OnButtonClick = cxGrid1DBTableView1NAME_SMHRAN_POLPropertiesButtonClick
        Width = 79
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
