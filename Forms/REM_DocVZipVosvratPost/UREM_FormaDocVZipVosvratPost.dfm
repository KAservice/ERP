object REM_FormaDocVZipVosvratPost: TREM_FormaDocVZipVosvratPost
  Left = 0
  Top = 0
  Caption = #1044#1086#1082#1091#1084#1077#1085#1090' "'#1042#1086#1079#1074#1088#1072#1090' '#1047#1048#1055' '#1055#1086#1089#1090#1072#1074#1097#1080#1082#1091'"'
  ClientHeight = 609
  ClientWidth = 843
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
    Top = 531
    Width = 843
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
    Height = 244
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 2
  end
  object Panel4: TPanel
    Left = 842
    Top = 287
    Width = 1
    Height = 244
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 3
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 843
    Height = 287
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 26
      Top = 120
      Width = 279
      Height = 24
      Caption = #1042#1086#1079#1074#1088#1072#1090' '#1047#1048#1055' '#1087#1086#1089#1090#1072#1074#1097#1080#1082#1091' '#8470
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
      Width = 843
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
      object ToolButtonAddString: TToolButton
        Left = 40
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1087#1091#1089#1090#1091#1102' '#1089#1090#1088#1086#1082#1091
        Caption = 'ToolButtonAddString'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonAddStringClick
      end
      object ToolButtonDelete: TToolButton
        Left = 63
        Top = 0
        Action = ActionDeleteString
        ParentShowHint = False
        ShowHint = True
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
      object ToolButtonOpenAktPr: TToolButton
        Left = 334
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1072#1082#1090' '#1087#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1102
        Caption = 'ToolButtonOpenAktPr'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonOpenAktPrClick
      end
    end
    object PrimcxDBTextEdit: TcxDBTextEdit
      Left = 82
      Top = 242
      DataBinding.DataField = 'DESCR_REM_DVZVPO'
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
      TabOrder = 10
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
      TabOrder = 11
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
      DataBinding.DataField = 'OPER_REM_DVZVPO'
      Properties.Items = <>
      TabOrder = 13
      Width = 300
    end
    object cxButtonEditViborGrpNom: TcxButtonEdit
      Left = 460
      Top = 183
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.OnButtonClick = cxButtonEditViborGrpNomPropertiesButtonClick
      TabOrder = 14
      Text = 'cxButtonEditViborGrpNom'
      Width = 241
    end
  end
  object cxGrid1: TcxGrid
    Left = 0
    Top = 287
    Width = 842
    Height = 244
    Align = alClient
    TabOrder = 4
    object cxGrid1DBBandedTableView1: TcxGridDBBandedTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsView.ColumnAutoWidth = True
      OptionsView.RowSeparatorWidth = 2
      Styles.Header = DM.cxStyleHeaderTable
      Bands = <
        item
          Width = 876
        end>
      object cxGrid1DBBandedTableView1NAME_REM_Z: TcxGridDBBandedColumn
        DataBinding.FieldName = 'NAME_REM_Z'
        Width = 162
        Position.BandIndex = 0
        Position.ColIndex = 1
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1NUM_REM_Z: TcxGridDBBandedColumn
        DataBinding.FieldName = 'NUM_REM_Z'
        Width = 90
        Position.BandIndex = 0
        Position.ColIndex = 2
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1POS_REM_Z: TcxGridDBBandedColumn
        DataBinding.FieldName = 'POS_REM_Z'
        Width = 87
        Position.BandIndex = 0
        Position.ColIndex = 3
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1SERNUM_REM_Z: TcxGridDBBandedColumn
        DataBinding.FieldName = 'SERNUM_REM_Z'
        Width = 88
        Position.BandIndex = 0
        Position.ColIndex = 4
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1SERNUM2_REM_Z: TcxGridDBBandedColumn
        DataBinding.FieldName = 'SERNUM2_REM_Z'
        Width = 89
        Position.BandIndex = 0
        Position.ColIndex = 5
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1KLIENT_NAME_REM_Z: TcxGridDBBandedColumn
        DataBinding.FieldName = 'KLIENT_NAME_REM_Z'
        Width = 88
        Position.BandIndex = 0
        Position.ColIndex = 6
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1MODEL_REM_Z: TcxGridDBBandedColumn
        DataBinding.FieldName = 'MODEL_REM_Z'
        Width = 90
        Position.BandIndex = 0
        Position.ColIndex = 7
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1NAME_STNOM: TcxGridDBBandedColumn
        DataBinding.FieldName = 'NAME_STNOM'
        Width = 146
        Position.BandIndex = 0
        Position.ColIndex = 2
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1ARTNOM: TcxGridDBBandedColumn
        DataBinding.FieldName = 'ARTNOM'
        Styles.Content = DM.cxStyleGroupReport
        Width = 130
        Position.BandIndex = 0
        Position.ColIndex = 1
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1CODENOM: TcxGridDBBandedColumn
        Caption = 'CODENOM'
        Width = 63
        Position.BandIndex = 0
        Position.ColIndex = 0
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1NAMENOM: TcxGridDBBandedColumn
        DataBinding.FieldName = 'NAMENOM'
        Width = 271
        Position.BandIndex = 0
        Position.ColIndex = 3
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1NAME_REM_STVZIP: TcxGridDBBandedColumn
        DataBinding.FieldName = 'NAME_REM_STVZIP'
        Width = 146
        Position.BandIndex = 0
        Position.ColIndex = 0
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1NAME_REM_SHARDWARE: TcxGridDBBandedColumn
        DataBinding.FieldName = 'NAME_REM_SHARDWARE'
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
        Properties.OnButtonClick = cxGrid1DBBandedTableView1NAME_REM_SHARDWAREPropertiesButtonClick
        Width = 146
        Position.BandIndex = 0
        Position.ColIndex = 0
        Position.RowIndex = 2
      end
      object cxGrid1DBBandedTableView1SERNUM_REM_SHARDWARE: TcxGridDBBandedColumn
        DataBinding.FieldName = 'SERNUM_REM_SHARDWARE'
        Width = 253
        Position.BandIndex = 0
        Position.ColIndex = 1
        Position.RowIndex = 2
      end
      object cxGrid1DBBandedTableView1SERNUM2_REM_SHARDWARE: TcxGridDBBandedColumn
        DataBinding.FieldName = 'SERNUM2_REM_SHARDWARE'
        Width = 211
        Position.BandIndex = 0
        Position.ColIndex = 2
        Position.RowIndex = 2
      end
      object cxGrid1DBBandedTableView1NAME_REM_SPRMODEL: TcxGridDBBandedColumn
        Caption = #1052#1086#1076#1077#1083#1100' '#1087#1088'.'
        DataBinding.FieldName = 'NAME_REM_SPRMODEL'
        Width = 230
        Position.BandIndex = 0
        Position.ColIndex = 3
        Position.RowIndex = 2
      end
      object cxGrid1DBBandedTableView1KOL_REM_DVZVPOT: TcxGridDBBandedColumn
        DataBinding.FieldName = 'KOL_REM_DVZVPOT'
        Styles.Content = DM.cxStyleGroupReport
        Width = 89
        Position.BandIndex = 0
        Position.ColIndex = 4
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1NAME_SMHRAN: TcxGridDBBandedColumn
        Caption = #1052#1077#1089#1090#1086' '#1093#1088#1072#1085'.'
        DataBinding.FieldName = 'NAME_SMHRAN'
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
        Properties.OnButtonClick = cxGrid1DBBandedTableView1NAME_SMHRANPropertiesButtonClick
        Width = 141
        Position.BandIndex = 0
        Position.ColIndex = 5
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
    end
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 448
    Top = 40
  end
end
