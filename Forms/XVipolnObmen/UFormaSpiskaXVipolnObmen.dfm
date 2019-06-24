object FormaSpiskaXVipolnObmen: TFormaSpiskaXVipolnObmen
  Left = 240
  Top = 20
  Caption = #1054#1073#1084#1077#1085
  ClientHeight = 560
  ClientWidth = 646
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
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 646
    Height = 113
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 0
    object HintLabel: TLabel
      Left = 9
      Top = 39
      Width = 44
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1058#1077#1082#1089#1090
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object LabelNom: TLabel
      Left = 11
      Top = 25
      Width = 232
      Height = 20
      Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072' '#1085#1077#1080#1079#1074#1077#1089#1090#1085#1072'!'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -17
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 646
      Height = 29
      Caption = 'ToolBar1'
      EdgeBorders = [ebTop, ebBottom]
      Images = DM.ImageList1
      TabOrder = 0
      object ToolButton1: TToolButton
        Left = 0
        Top = 0
        Width = 9
        Caption = 'ToolButton1'
        Style = tbsSeparator
      end
      object ToolButton3: TToolButton
        Left = 9
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
        Caption = 'ToolButton3'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButton2: TToolButton
        Left = 32
        Top = 0
        Width = 6
        Caption = 'ToolButton2'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButtonClose: TToolButton
        Left = 38
        Top = 0
        Hint = #1047#1072#1082#1088#1099#1090#1100
        Action = ActionClose
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButton4: TToolButton
        Left = 61
        Top = 0
        Width = 200
        Caption = 'ToolButton4'
        ImageIndex = 54
        Style = tbsSeparator
      end
      object ToolButtonUpdateForm: TToolButton
        Left = 261
        Top = 0
        Caption = 'ToolButtonUpdateForm'
        ImageIndex = 48
        OnClick = ToolButtonUpdateFormClick
      end
    end
    object IntrvalcxSpinEdit: TcxSpinEdit
      Left = 296
      Top = 71
      TabOrder = 1
      Width = 121
    end
    object cxLabel1: TcxLabel
      Left = 40
      Top = 72
      Caption = #1048#1085#1090#1077#1088#1074#1072#1083' '#1086#1073#1085#1086#1074#1083#1077#1085#1080#1103' '#1092#1086#1088#1084#1099' ('#1084#1080#1085'):'
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 113
    Width = 11
    Height = 439
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 1
    ExplicitTop = 57
    ExplicitHeight = 495
  end
  object Panel3: TPanel
    Left = 0
    Top = 552
    Width = 646
    Height = 8
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 2
  end
  object Panel4: TPanel
    Left = 630
    Top = 113
    Width = 16
    Height = 439
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alRight
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 3
    ExplicitTop = 57
    ExplicitHeight = 495
  end
  object cxPageControl1: TcxPageControl
    Left = 11
    Top = 113
    Width = 619
    Height = 439
    Align = alClient
    TabOrder = 4
    ExplicitTop = 57
    ExplicitHeight = 495
    ClientRectBottom = 439
    ClientRectRight = 619
    ClientRectTop = 0
  end
  object cxGrid1: TcxGrid
    Left = 11
    Top = 113
    Width = 619
    Height = 439
    Align = alClient
    TabOrder = 5
    ExplicitTop = 96
    ExplicitHeight = 456
    object cxGrid1DBTableView1: TcxGridDBTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsView.CellAutoHeight = True
      OptionsView.ColumnAutoWidth = True
      object cxGrid1DBTableView1NOACT_SINFBASE_OBMEN: TcxGridDBColumn
        DataBinding.FieldName = 'NOACT_SINFBASE_OBMEN'
        Width = 50
      end
      object cxGrid1DBTableView1NAME_SINFBASE_OBMEN: TcxGridDBColumn
        DataBinding.FieldName = 'NAME_SINFBASE_OBMEN'
        Width = 263
      end
      object cxGrid1DBTableView1POS_ZAGR_XVIPOLN_OBMEN: TcxGridDBColumn
        DataBinding.FieldName = 'POS_ZAGR_XVIPOLN_OBMEN'
        Width = 152
      end
      object cxGrid1DBTableView1POS_VIGR_XVIPOLN_OBMEN: TcxGridDBColumn
        DataBinding.FieldName = 'POS_VIGR_XVIPOLN_OBMEN'
        Width = 152
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 304
    Top = 144
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
    end
    object ActionClose: TAction
      Caption = #1047#1072#1082#1088#1099#1090#1100
      ImageIndex = 53
      OnExecute = ActionCloseExecute
    end
    object ActionSaveIsmen: TAction
      Caption = 'ActionSaveIsmen'
    end
    object ActionCancelIsmen: TAction
      Caption = 'ActionCancelIsmen'
    end
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 384
    Top = 24
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 480
    Top = 32
  end
end
