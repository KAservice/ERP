object FormaSprNomFind: TFormaSprNomFind
  Left = 337
  Top = 195
  Caption = #1055#1086#1080#1089#1082' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099
  ClientHeight = 676
  ClientWidth = 1229
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
  WindowState = wsMaximized
  OnClose = FormClose
  PixelsPerInch = 120
  TextHeight = 16
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 1229
    Height = 73
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 1
    object LabelNameGrp: TLabel
      Left = 331
      Top = 33
      Width = 76
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1043#1088#1091#1087#1087#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -18
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object HintLabel: TLabel
      Left = 10
      Top = 34
      Width = 58
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1058#1077#1082#1089#1090
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -18
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 1229
      Height = 26
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
      object ToolButton2: TToolButton
        Left = 8
        Top = 0
        Width = 84
        Caption = 'ToolButton2'
        ImageIndex = 2
        Style = tbsSeparator
      end
      object ToolButton3: TToolButton
        Left = 92
        Top = 0
        Width = 90
        Caption = 'ToolButton3'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButton4: TToolButton
        Left = 182
        Top = 0
        Width = 161
        Caption = 'ToolButton4'
        ImageIndex = 6
        Style = tbsSeparator
      end
      object ToolButtonOnlyOstatok: TToolButton
        Left = 343
        Top = 0
        Hint = #1055#1086#1082#1072#1079#1072#1090#1100' '#1090#1086#1083#1100#1082#1086' '#1085#1077#1085#1091#1083#1077#1074#1099#1077' '#1086#1089#1090#1072#1090#1082#1080
        Caption = 'ToolButtonOnlyOstatok'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        Style = tbsCheck
      end
      object ToolButtonPriceSklad: TToolButton
        Left = 366
        Top = 0
        Hint = #1062#1077#1085#1099' '#1089#1082#1083#1072#1076#1072
        Caption = 'ToolButtonPriceSklad'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        Style = tbsCheck
      end
      object ToolButtonSaveSetup: TToolButton
        Left = 389
        Top = 0
        Hint = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1085#1072#1089#1090#1088#1086#1081#1082#1080' '#1092#1086#1088#1084#1099
        Caption = 'ToolButtonSaveSetup'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonSaveSetupClick
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 73
    Width = 11
    Height = 546
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
    Width = 1229
    Height = 57
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 3
    TabStop = True
    object cxButtonClose: TcxButton
      Left = 859
      Top = 20
      Width = 92
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      TabOrder = 0
    end
  end
  object Panel4: TPanel
    Left = 1219
    Top = 73
    Width = 10
    Height = 546
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alRight
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 4
  end
  object Panel5: TPanel
    Left = 331
    Top = 73
    Width = 12
    Height = 546
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 5
  end
  object cxTreeView1: TcxTreeView
    Left = 11
    Top = 73
    Width = 320
    Height = 546
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    ParentFont = False
    Style.Font.Charset = DEFAULT_CHARSET
    Style.Font.Color = clWindowText
    Style.Font.Height = -18
    Style.Font.Name = 'MS Sans Serif'
    Style.Font.Style = []
    Style.IsFontAssigned = True
    TabOrder = 0
    OnDblClick = cxTreeView1DblClick
    OnKeyDown = cxTreeView1KeyDown
    HideSelection = False
    ReadOnly = True
    RowSelect = True
  end
  object Panel6: TPanel
    Left = 343
    Top = 73
    Width = 876
    Height = 546
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 6
    object Panel7: TPanel
      Left = 0
      Top = 0
      Width = 876
      Height = 194
      Align = alTop
      BevelOuter = bvNone
      TabOrder = 0
      object cxTextEditWord: TcxTextEdit
        Left = 7
        Top = 152
        TabOrder = 0
        Text = 'cxTextEditWord'
        Width = 394
      end
      object cxButtonFind: TcxButton
        Left = 468
        Top = 153
        Width = 75
        Height = 25
        Caption = #1055#1086#1080#1089#1082
        TabOrder = 1
        OnClick = cxButtonFindClick
      end
      object cxLabel1: TcxLabel
        Left = 7
        Top = 126
        Caption = #1050#1083#1102#1095#1077#1074#1086#1077' '#1089#1083#1086#1074#1086
      end
      object cxMemoIshodNom: TcxMemo
        Left = 7
        Top = 26
        Lines.Strings = (
          'cxMemoIshodNom')
        TabOrder = 3
        Height = 94
        Width = 490
      end
      object cxLabel2: TcxLabel
        Left = 7
        Top = 7
        Caption = #1048#1089#1093#1086#1076#1085#1072#1103' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072':'
      end
      object TypePricecxLookupComboBox: TcxLookupComboBox
        Left = 632
        Top = 96
        Properties.KeyFieldNames = 'ID_TPRICE'
        Properties.ListColumns = <
          item
            FieldName = 'NAME_TPRICE'
          end>
        TabOrder = 5
        Width = 237
      end
      object NameFirmcxLookupComboBox: TcxLookupComboBox
        Left = 632
        Top = 26
        Properties.KeyFieldNames = 'IDFIRM'
        Properties.ListColumns = <
          item
            FieldName = 'NAMEFIRM'
          end>
        TabOrder = 6
        Width = 237
      end
      object NameSkladcxLookupComboBox: TcxLookupComboBox
        Left = 632
        Top = 60
        Properties.KeyFieldNames = 'IDSKLAD'
        Properties.ListColumns = <
          item
            FieldName = 'NAMESKLAD'
          end>
        TabOrder = 7
        Width = 237
      end
      object cxButtonGetPrice: TcxButton
        Left = 549
        Top = 153
        Width = 76
        Height = 25
        Caption = #1062#1077#1085#1099
        TabOrder = 8
        OnClick = cxButtonGetPriceClick
      end
      object cxButtonGetOstatki: TcxButton
        Left = 631
        Top = 153
        Width = 76
        Height = 25
        Caption = #1054#1089#1090#1072#1090#1082#1080
        TabOrder = 9
        OnClick = cxButtonGetOstatkiClick
      end
      object cxLabel3: TcxLabel
        Left = 564
        Top = 28
        Caption = #1060#1080#1088#1084#1072':'
      end
      object cxLabel4: TcxLabel
        Left = 572
        Top = 61
        Caption = #1057#1082#1083#1072#1076':'
      end
      object cxLabel5: TcxLabel
        Left = 567
        Top = 100
        Caption = #1058#1080#1087' '#1094#1077#1085':'
      end
      object cxButtonOstPoServ: TcxButton
        Left = 713
        Top = 153
        Width = 112
        Height = 25
        Caption = #1054#1089#1090#1072#1090#1082#1080' ('#1089#1077#1088#1074'.)'
        TabOrder = 13
        OnClick = cxButtonOstPoServClick
      end
    end
    object cxGrid1: TcxGrid
      Left = 0
      Top = 194
      Width = 876
      Height = 352
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Align = alClient
      TabOrder = 1
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
        OptionsSelection.InvertSelect = False
        OptionsSelection.MultiSelect = True
        OptionsView.NoDataToDisplayInfoText = '<'#1053#1077#1090' '#1076#1072#1085#1085#1099#1093'>'
        OptionsView.CellAutoHeight = True
        OptionsView.ColumnAutoWidth = True
        Styles.Header = DM.cxStyleHeaderTable
        object cxGrid1DBTableView1NAMEGN: TcxGridDBColumn
          Caption = #1043#1088#1091#1087#1087#1072
          DataBinding.FieldName = 'NAMEGN'
          Width = 130
        end
        object cxGrid1DBTableView1CODENOM: TcxGridDBColumn
          Caption = #1050#1086#1076
          DataBinding.FieldName = 'CODENOM'
          Styles.Header = DM.cxStyleHeaderTable
          Width = 53
        end
        object cxGrid1DBTableView1NAMENOM: TcxGridDBColumn
          Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
          DataBinding.FieldName = 'NAMENOM'
          Styles.Header = DM.cxStyleHeaderTable
          Width = 389
        end
        object cxGrid1DBTableView1NAMEED: TcxGridDBColumn
          Caption = #1045#1076#1080#1085#1080#1094#1072
          DataBinding.FieldName = 'NAMEED'
          Styles.Header = DM.cxStyleHeaderTable
          Width = 38
        end
        object cxGrid1DBTableView1ZNACH_PRICE: TcxGridDBColumn
          Caption = #1062#1077#1085#1072
          DataBinding.FieldName = 'ZNACH_PRICE'
          Styles.Content = DM.cxStyleHeaderTable
          Styles.Header = DM.cxStyleHeaderTable
          Width = 52
        end
        object cxGrid1DBTableView1SUMKOL: TcxGridDBColumn
          Caption = #1054#1089#1090#1072#1090#1086#1082
          DataBinding.FieldName = 'SUMKOL'
          Styles.Content = DM.cxStyleHeaderTable
          Styles.Header = DM.cxStyleHeaderTable
          Width = 45
        end
        object cxGrid1DBTableView1IDNOM: TcxGridDBColumn
          DataBinding.FieldName = 'IDNOM'
          Visible = False
        end
        object cxGrid1DBTableView1IDGRPNOM: TcxGridDBColumn
          DataBinding.FieldName = 'IDGRPNOM'
          Visible = False
        end
        object cxGrid1DBTableView1REM_OST: TcxGridDBColumn
          Caption = #1054#1089#1090'. ('#1088#1077#1084#1086#1085#1090')'
          DataBinding.FieldName = 'REM_OST'
          Styles.Content = DM.cxStyleHeaderTable
          Width = 50
        end
        object cxGrid1DBTableView1SHED: TcxGridDBColumn
          DataBinding.FieldName = 'SHED'
          Width = 117
        end
      end
      object cxGrid1Level1: TcxGridLevel
        GridView = cxGrid1DBTableView1
      end
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 88
    Top = 32
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
    end
    object ActionClose: TAction
      Caption = #1047#1072#1082#1088#1099#1090#1100
      ImageIndex = 53
      OnExecute = ActionCloseExecute
    end
  end
end
