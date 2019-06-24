object HOT_FormaDocViezd: THOT_FormaDocViezd
  Left = 520
  Top = 131
  Caption = #1042#1099#1077#1079#1076
  ClientHeight = 549
  ClientWidth = 894
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
  object ToolBar2: TToolBar
    Left = 0
    Top = 0
    Width = 894
    Height = 30
    Color = clBtnFace
    EdgeBorders = [ebTop, ebBottom]
    Images = DM.ImageList1
    ParentColor = False
    TabOrder = 3
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
      Width = 74
      Caption = 'ToolButton2'
      ImageIndex = 3
      Style = tbsSeparator
    end
    object ToolButton3: TToolButton
      Left = 137
      Top = 0
      Width = 8
      Caption = 'ToolButton3'
      ImageIndex = 4
      Style = tbsSeparator
    end
    object ToolButtonExtModule: TToolButton
      Left = 145
      Top = 0
      Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
      Caption = 'ToolButtonExtModule'
      DropdownMenu = PopupMenuExtModule
      ImageIndex = 51
      ParentShowHint = False
      ShowHint = True
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 30
    Width = 894
    Height = 191
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label6: TLabel
      Left = 10
      Top = 161
      Width = 86
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077':'
    end
    object Label5: TLabel
      Left = 11
      Top = 128
      Width = 83
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1083#1072#1090#1077#1083#1100#1097#1080#1082':'
    end
    object Label2: TLabel
      Left = 421
      Top = 73
      Width = 25
      Height = 26
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1086#1090
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label1: TLabel
      Left = 11
      Top = 66
      Width = 241
      Height = 26
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1044#1086#1082#1091#1084#1077#1085#1090' "'#1042#1099#1077#1079#1076'" '#8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label4: TLabel
      Left = 10
      Top = 4
      Width = 47
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1060#1080#1088#1084#1072':'
    end
    object Label3: TLabel
      Left = 465
      Top = 4
      Width = 155
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1048#1085#1092#1086#1088#1084#1072#1094#1080#1086#1085#1085#1072#1103' '#1073#1072#1079#1072':'
    end
    object NameKlientcxDBButtonEdit: TcxDBButtonEdit
      Left = 101
      Top = 124
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
      Properties.OnButtonClick = NameKlientcxDBButtonEditPropertiesButtonClick
      TabOrder = 4
      Width = 336
    end
    object DescrcxDBTextEdit: TcxDBTextEdit
      Left = 98
      Top = 158
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'DESCR_HOT_DVIESD'
      TabOrder = 5
      OnKeyDown = DescrcxDBTextEditKeyDown
      Width = 415
    end
    object PosDoccxDBDateEdit: TcxDBDateEdit
      Left = 458
      Top = 73
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'POS_HOT_GALLDOC'
      Properties.InputKind = ikStandard
      Properties.Kind = ckDateTime
      TabOrder = 3
      OnKeyDown = PosDoccxDBDateEditKeyDown
      Width = 188
    end
    object NumbercxDBTextEdit: TcxDBTextEdit
      Left = 276
      Top = 73
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NUMBER_HOT_GALLDOC'
      TabOrder = 2
      OnKeyDown = NumbercxDBTextEditKeyDown
      Width = 138
    end
    object NameInfBasecxDBButtonEdit: TcxDBButtonEdit
      Left = 620
      Top = 0
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
      Properties.OnButtonClick = NameInfBasecxDBButtonEditPropertiesButtonClick
      TabOrder = 0
      Width = 258
    end
    object NameFirmcxDBButtonEdit: TcxDBButtonEdit
      Left = 111
      Top = 4
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
      Properties.OnButtonClick = NameFirmcxDBButtonEditPropertiesButtonClick
      TabOrder = 1
      Width = 257
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 469
    Width = 894
    Height = 80
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 2
    object DBTextFNameUser: TDBText
      Left = 10
      Top = 60
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
      Left = 10
      Top = 33
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
    object cxButtonSave: TcxButton
      Left = 491
      Top = 39
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionSave
      TabOrder = 0
    end
    object cxButtonDvReg: TcxButton
      Left = 591
      Top = 39
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionDvReg
      TabOrder = 1
    end
    object cxButtonOK: TcxButton
      Left = 690
      Top = 39
      Width = 93
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionOK
      TabOrder = 2
    end
    object cxButtonClose: TcxButton
      Left = 790
      Top = 39
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
  object cxGrid1: TcxGrid
    Left = 0
    Top = 221
    Width = 894
    Height = 248
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
      OptionsBehavior.GoToNextCellOnEnter = True
      OptionsData.CancelOnExit = False
      OptionsData.Deleting = False
      OptionsData.DeletingConfirmation = False
      OptionsData.Editing = False
      OptionsData.Inserting = False
      OptionsSelection.InvertSelect = False
      OptionsView.ColumnAutoWidth = True
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1POSNACH_HOT_SOSTNF: TcxGridDBColumn
        Caption = #1047#1072#1077#1079#1076
        DataBinding.FieldName = 'POSNACH_HOT_SOSTNF'
        Width = 78
      end
      object cxGrid1DBTableView1POSCON_HOT_SOSTNF: TcxGridDBColumn
        Caption = #1042#1099#1077#1079#1076
        DataBinding.FieldName = 'POSCON_HOT_SOSTNF'
        Width = 77
      end
      object cxGrid1DBTableView1NAME_HOT_SNF: TcxGridDBColumn
        Caption = #1053#1086#1084#1077#1088
        DataBinding.FieldName = 'NAME_HOT_SNF'
        Width = 135
      end
      object cxGrid1DBTableView1NAME_HOT_SCATNOM: TcxGridDBColumn
        Caption = #1050#1072#1090#1077#1075#1086#1088#1080#1103
        DataBinding.FieldName = 'NAME_HOT_SCATNOM'
        Width = 136
      end
      object cxGrid1DBTableView1NAME_HOT_STYPEPOS: TcxGridDBColumn
        Caption = #1058#1080#1087' '#1087#1086#1089#1077#1083#1077#1085#1080#1103
        DataBinding.FieldName = 'NAME_HOT_STYPEPOS'
        Width = 92
      end
      object cxGrid1DBTableView1KOLM_HOT_SOSTNF: TcxGridDBColumn
        Caption = #1052#1077#1089#1090
        DataBinding.FieldName = 'KOLM_HOT_SOSTNF'
        Width = 48
      end
      object cxGrid1DBTableView1NAMEKLIENT: TcxGridDBColumn
        Caption = #1043#1086#1089#1090#1100
        DataBinding.FieldName = 'NAMEKLIENT'
        Width = 158
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 8
    Top = 48
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
    Left = 168
    Top = 24
  end
end
