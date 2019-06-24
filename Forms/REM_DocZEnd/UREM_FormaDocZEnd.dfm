object REM_FormaDocZEnd: TREM_FormaDocZEnd
  Left = 290
  Top = 119
  Caption = #1044#1086#1082#1091#1084#1077#1085#1090' "'#1050#1086#1085#1077#1094' '#1088#1077#1084#1086#1085#1090#1072'"'
  ClientHeight = 533
  ClientWidth = 883
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
    Top = 437
    Width = 883
    Height = 96
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    ExplicitTop = 379
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
      DataSource = REM_DMDocRemont.DataSourceDocAll
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
    Top = 429
    Width = 0
    Height = 8
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 2
    ExplicitTop = 371
  end
  object Panel4: TPanel
    Left = 881
    Top = 429
    Width = 2
    Height = 8
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 3
    ExplicitTop = 371
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 883
    Height = 429
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 59
      Top = 98
      Width = 205
      Height = 26
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1050#1086#1085#1077#1094' '#1088#1077#1084#1086#1085#1090#1072'  '#8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 441
      Top = 92
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
      Top = 228
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
      Left = 30
      Top = 158
      Width = 50
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1050#1083#1080#1077#1085#1090':'
    end
    object Label7: TLabel
      Left = 30
      Top = 197
      Width = 50
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1047#1072#1103#1074#1082#1072':'
    end
    object Label8: TLabel
      Left = 517
      Top = 170
      Width = 14
      Height = 16
      Caption = #8470
    end
    object Label9: TLabel
      Left = 656
      Top = 169
      Width = 15
      Height = 16
      Caption = #1086#1090
    end
    object Label10: TLabel
      Left = 669
      Top = 136
      Width = 21
      Height = 16
      Caption = '1'#8470
    end
    object Label11: TLabel
      Left = 669
      Top = 152
      Width = 21
      Height = 16
      Caption = '2'#8470
    end
    object Label12: TLabel
      Left = 17
      Top = 395
      Width = 124
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1054' '#1087#1086#1089#1083#1077' '#1088#1077#1084#1086#1085#1090#1072':'
    end
    object Label15: TLabel
      Left = 20
      Top = 260
      Width = 360
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1044#1077#1092#1077#1082#1090' (DFC) '#1080#1079' '#1089#1087#1088'. '#1053#1077#1080#1089#1087#1088#1072#1074#1085#1086#1089#1090#1077#1081' '#1055#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1103':'
    end
    object Label13: TLabel
      Left = 20
      Top = 314
      Width = 315
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1044#1077#1092#1077#1082#1090' (DFC) '#1080#1079' '#1089#1087#1088'. '#1044#1077#1092#1077#1082#1090#1086#1074' '#1055#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1103':'
    end
    object ToolBar2: TToolBar
      Left = 0
      Top = 0
      Width = 883
      Height = 30
      Color = clBtnFace
      EdgeBorders = [ebTop, ebRight, ebBottom]
      Images = DM.ImageList1
      ParentColor = False
      TabOrder = 6
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
      object ToolButtonCreateCheck: TToolButton
        Left = 265
        Top = 0
        Hint = #1057#1086#1079#1076#1072#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' '#1063#1077#1082' '#1050#1050#1052
        Caption = 'ToolButtonCreateCheck'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonCreateRealRozn: TToolButton
        Left = 288
        Top = 0
        Hint = #1057#1086#1079#1076#1072#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' "'#1056#1077#1072#1083#1080#1079#1072#1094#1080#1103' '#1088#1086#1079#1085'."'
        Caption = 'ToolButtonCreateRealRozn'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonCreateReal: TToolButton
        Left = 311
        Top = 0
        Hint = #1057#1086#1079#1076#1072#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' "'#1056#1077#1072#1083#1080#1079#1072#1094#1080#1103'"'
        Caption = 'ToolButtonCreateReal'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
      end
    end
    object PrimcxDBTextEdit: TcxDBTextEdit
      Left = 118
      Top = 224
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'PRIM_REM_DZEND'
      DataBinding.DataSource = REM_DMDocRemont.DataSourceDoc
      TabOrder = 5
      OnKeyDown = PrimcxDBTextEditKeyDown
      Width = 611
    end
    object NumDoccxDBTextEdit: TcxDBTextEdit
      Left = 326
      Top = 102
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NUM_REM_GALLDOC'
      DataBinding.DataSource = REM_DMDocRemont.DataSourceDocAll
      TabOrder = 3
      OnKeyDown = NumDoccxDBTextEditKeyDown
      Width = 100
    end
    object PosDoccxDBDateEdit: TcxDBDateEdit
      Left = 485
      Top = 102
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'POS_REM_GALLDOC'
      DataBinding.DataSource = REM_DMDocRemont.DataSourceDocAll
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
      DataBinding.DataSource = REM_DMDocRemont.DataSourceDocAll
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
      DataBinding.DataSource = REM_DMDocRemont.DataSourceDocAll
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
      DataBinding.DataSource = REM_DMDocRemont.DataSourceDocAll
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
      Top = 154
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAMEKLIENT'
      DataBinding.DataSource = REM_DMDocRemont.DataSourceDocAll
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameKlientcxDBButtonEditPropertiesButtonClick
      TabOrder = 8
      Width = 336
    end
    object NameZcxDBButtonEdit: TcxDBButtonEdit
      Left = 98
      Top = 191
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAME_REM_Z'
      DataBinding.DataSource = REM_DMDocRemont.DataSourceDoc
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameZcxDBButtonEditPropertiesButtonClick
      TabOrder = 9
      Width = 336
    end
    object NameKlientcxDBLabel: TcxDBLabel
      Left = 457
      Top = 134
      DataBinding.DataField = 'KLIENT_NAME_REM_Z'
      Height = 21
      Width = 201
    end
    object ModelcxDBLabel: TcxDBLabel
      Left = 459
      Top = 150
      DataBinding.DataField = 'MODEL_REM_Z'
      Height = 21
      Width = 191
    end
    object PosZcxDBLabel: TcxDBLabel
      Left = 696
      Top = 167
      DataBinding.DataField = 'POS_REM_Z'
      Height = 21
      Width = 121
    end
    object NumZcxDBLabel: TcxDBLabel
      Left = 537
      Top = 169
      DataBinding.DataField = 'NUM_REM_Z'
      Height = 21
      Width = 121
    end
    object SerNumcxDBLabel: TcxDBLabel
      Left = 696
      Top = 134
      DataBinding.DataField = 'SERNUM_REM_Z'
      Height = 21
      Width = 121
    end
    object SerNum2cxDBLabel: TcxDBLabel
      Left = 696
      Top = 150
      DataBinding.DataField = 'SERNUM2_REM_Z'
      Height = 21
      Width = 121
    end
    object POPOSLEcxDBTextEdit: TcxDBTextEdit
      Left = 166
      Top = 392
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'POPOSLE_REM_DZEND'
      TabOrder = 16
      OnKeyDown = PrimcxDBTextEditKeyDown
      Width = 413
    end
    object NameProducerNeispcxDBButtonEdit: TcxDBButtonEdit
      Left = 166
      Top = 283
      DataBinding.DataField = 'NAME_REM_SPRNEISPR'
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end
        item
          Caption = 'X'
          Kind = bkText
        end>
      TabOrder = 17
      Width = 423
    end
    object NameSprProducerDefectcxDBButtonEdit: TcxDBButtonEdit
      Left = 166
      Top = 337
      DataBinding.DataField = 'NAME_REM_SPRDEFECT'
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end
        item
          Caption = 'X'
          Kind = bkText
        end>
      Properties.OnButtonClick = NameSprProducerDefectcxDBButtonEditPropertiesButtonClick
      TabOrder = 18
      Width = 423
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
    end
    object ActionDeleteString: TAction
      Caption = 'ActionDeleteString'
      ImageIndex = 2
      ShortCut = 46
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
    Left = 400
    Top = 24
  end
end
