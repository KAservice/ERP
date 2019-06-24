object FormaViborSprNom: TFormaViborSprNom
  Left = 336
  Top = 155
  Caption = #1057#1087#1088#1072#1074#1086#1095#1085#1080#1082' "'#1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072'"'
  ClientHeight = 676
  ClientWidth = 969
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
  OnResize = FormResize
  PixelsPerInch = 120
  TextHeight = 16
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 969
    Height = 90
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 1
    object LabelNameGrp: TLabel
      Left = 364
      Top = 69
      Width = 64
      Height = 20
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1043#1088#1091#1087#1087#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object HintLabel: TLabel
      Left = 10
      Top = 34
      Width = 49
      Height = 20
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1058#1077#1082#1089#1090
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 969
      Height = 29
      Caption = 'ToolBar1'
      EdgeBorders = [ebTop, ebBottom]
      Images = DM.ImageList1
      TabOrder = 0
      object ToolButton1: TToolButton
        Left = 0
        Top = 0
        Width = 8
        Caption = 'ToolButton1'
        Style = tbsSeparator
      end
      object ToolButtonNewGrp: TToolButton
        Left = 8
        Top = 0
        Caption = 'ToolButtonNewGrp'
        ImageIndex = 0
        Visible = False
      end
      object ToolButtonEdiGrp: TToolButton
        Left = 31
        Top = 0
        Caption = 'ToolButtonEdiGrp'
        ImageIndex = 1
        Visible = False
      end
      object ToolButtonDeleteGrp: TToolButton
        Left = 54
        Top = 0
        Caption = 'ToolButtonDeleteGrp'
        ImageIndex = 2
        Visible = False
      end
      object ToolButton2: TToolButton
        Left = 77
        Top = 0
        Width = 84
        Caption = 'ToolButton2'
        ImageIndex = 2
        Style = tbsSeparator
      end
      object ToolButton3: TToolButton
        Left = 161
        Top = 0
        Width = 136
        Caption = 'ToolButton3'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButtonNew: TToolButton
        Left = 297
        Top = 0
        Caption = 'ToolButtonNew'
        ImageIndex = 0
        Visible = False
      end
      object ToolButtonEdit: TToolButton
        Left = 320
        Top = 0
        Caption = 'ToolButtonEdit'
        ImageIndex = 1
        Visible = False
      end
      object ToolButtonDelete: TToolButton
        Left = 343
        Top = 0
        Caption = 'ToolButtonDelete'
        ImageIndex = 2
        Visible = False
      end
      object ToolButton4: TToolButton
        Left = 366
        Top = 0
        Width = 35
        Caption = 'ToolButton4'
        ImageIndex = 6
        Style = tbsSeparator
      end
      object ToolButtonAll: TToolButton
        Left = 401
        Top = 0
        Caption = 'ToolButtonAll'
        ImageIndex = 8
        Style = tbsCheck
        OnClick = ToolButtonAllClick
      end
      object ToolButtonIsmGrp: TToolButton
        Left = 424
        Top = 0
        Caption = 'ToolButtonIsmGrp'
        ImageIndex = 9
        Visible = False
      end
      object ToolButtonOst: TToolButton
        Left = 447
        Top = 0
        Hint = #1057' '#1086#1089#1090#1072#1090#1082#1072#1084#1080
        Caption = 'ToolButtonOst'
        ImageIndex = 31
        ParentShowHint = False
        ShowHint = True
        Style = tbsCheck
        OnClick = ToolButtonOstClick
      end
      object saveSetupFormToolButton: TToolButton
        Left = 470
        Top = 0
        Hint = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1085#1072#1089#1090#1088#1086#1081#1082#1080' '#1092#1086#1088#1084#1099
        Caption = 'saveSetupFormToolButton'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = saveSetupFormToolButtonClick
      end
    end
    object SpisokTypePrice: TcxComboBox
      Left = 692
      Top = 57
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Properties.DropDownListStyle = lsFixedList
      TabOrder = 1
      Width = 259
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 90
    Width = 11
    Height = 529
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 2
  end
  object Panel3: TPanel
    Left = 0
    Top = 619
    Width = 969
    Height = 57
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 0
    object LabelFirma: TLabel
      Left = 263
      Top = 10
      Width = 79
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Alignment = taRightJustify
      Caption = 'LabelFirma'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object LabelSklad: TLabel
      Left = 263
      Top = 30
      Width = 80
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Alignment = taRightJustify
      Caption = 'LabelSklad'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object cxButtonClose: TcxButton
      Left = 859
      Top = 20
      Width = 92
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1047#1072#1082#1088#1099#1090#1100
      TabOrder = 0
      OnClick = cxButtonCloseClick
    end
  end
  object Panel4: TPanel
    Left = 951
    Top = 90
    Width = 18
    Height = 529
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alRight
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 3
  end
  object Panel5: TPanel
    Left = 331
    Top = 90
    Width = 20
    Height = 529
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 4
  end
  object cxTreeView1: TcxTreeView
    Left = 11
    Top = 90
    Width = 320
    Height = 529
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    ParentFont = False
    Style.Font.Charset = DEFAULT_CHARSET
    Style.Font.Color = clWindowText
    Style.Font.Height = -17
    Style.Font.Name = 'MS Sans Serif'
    Style.Font.Style = []
    Style.IsFontAssigned = True
    TabOrder = 5
    OnDblClick = cxTreeView1DblClick
    OnKeyPress = cxTreeView1KeyPress
  end
  object cxGrid1: TcxGrid
    Left = 351
    Top = 90
    Width = 600
    Height = 529
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    TabOrder = 6
    object cxGrid1DBTableView1: TcxGridDBTableView
      OnDblClick = cxGrid1DBTableView1DblClick
      OnKeyPress = cxGrid1DBTableView1KeyPress
      NavigatorButtons.ConfirmDelete = False
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.IncSearch = True
      OptionsData.CancelOnExit = False
      OptionsData.Deleting = False
      OptionsData.DeletingConfirmation = False
      OptionsData.Editing = False
      OptionsData.Inserting = False
      OptionsView.ColumnAutoWidth = True
      OptionsView.GroupByBox = False
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1ARTNOM: TcxGridDBColumn
        Caption = #1040#1088#1090#1080#1082#1091#1083
        DataBinding.FieldName = 'ARTNOM'
        Width = 55
      end
      object cxGrid1DBTableView1CODENOM: TcxGridDBColumn
        Caption = #1050#1086#1076
        DataBinding.FieldName = 'CODENOM'
        Width = 35
      end
      object cxGrid1DBTableView1NAMENOM: TcxGridDBColumn
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
        DataBinding.FieldName = 'NAMENOM'
        Width = 222
      end
      object cxGrid1DBTableView1NAMEED: TcxGridDBColumn
        Caption = #1045#1076#1080#1085#1080#1094#1072
        DataBinding.FieldName = 'NAMEED'
        Width = 54
      end
      object cxGrid1DBTableView1ZNACH_PRICE: TcxGridDBColumn
        Caption = #1062#1077#1085#1072
        DataBinding.FieldName = 'ZNACH_PRICE'
        Width = 60
      end
      object cxGrid1DBTableView1SUMKOL: TcxGridDBColumn
        Caption = #1054#1089#1090#1072#1090#1086#1082
        DataBinding.FieldName = 'SUMKOL'
        Width = 60
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
end
