object FormaElementaXSetupObmen: TFormaElementaXSetupObmen
  Left = 385
  Top = 51
  Caption = #1054#1073#1084#1077#1085' '#1089' '#1073#1072#1079#1086#1081
  ClientHeight = 401
  ClientWidth = 508
  Color = clBtnFace
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
  object Label1: TLabel
    Left = 8
    Top = 64
    Width = 252
    Height = 13
    Caption = #1053#1072#1095#1072#1083#1100#1085#1086#1077' '#1079#1085#1072#1095#1077#1085#1080#1077' '#1079#1072#1087#1080#1089#1080' '#1090#1072#1073#1083#1080#1094#1099' '#1080#1079#1084#1077#1085#1077#1085#1080#1081':'
  end
  object cxButtonOK: TcxButton
    Left = 344
    Top = 357
    Width = 74
    Height = 25
    Action = ActionOK
    TabOrder = 0
  end
  object cxButtonClose: TcxButton
    Left = 425
    Top = 357
    Width = 75
    Height = 25
    Action = ActionClose
    TabOrder = 1
  end
  object NameBaseObmencxDBButtonEdit: TcxDBButtonEdit
    Left = 11
    Top = 37
    DataBinding.DataField = 'NAME_SINFBASE_OBMEN'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.OnButtonClick = NameBaseObmencxDBButtonEditPropertiesButtonClick
    TabOrder = 2
    Width = 249
  end
  object cxGrid1: TcxGrid
    Left = 8
    Top = 128
    Width = 236
    Height = 200
    TabOrder = 3
    object cxGrid1DBTableViewBase: TcxGridDBTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsData.CancelOnExit = False
      OptionsData.Deleting = False
      OptionsData.DeletingConfirmation = False
      OptionsData.Editing = False
      OptionsData.Inserting = False
      OptionsView.ColumnAutoWidth = True
      OptionsView.GroupByBox = False
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableViewBaseNAME_SINFBASE_OBMEN: TcxGridDBColumn
        Caption = #1048#1085#1092'. '#1073#1072#1079#1099
        DataBinding.FieldName = 'NAME_SINFBASE_OBMEN'
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableViewBase
    end
  end
  object cxGrid2: TcxGrid
    Left = 250
    Top = 128
    Width = 250
    Height = 200
    TabOrder = 4
    object cxGrid2DBTableViewTypePrice: TcxGridDBTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsData.CancelOnExit = False
      OptionsData.Deleting = False
      OptionsData.DeletingConfirmation = False
      OptionsData.Editing = False
      OptionsData.Inserting = False
      OptionsView.ColumnAutoWidth = True
      OptionsView.GroupByBox = False
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid2DBTableViewTypePriceNAME_TPRICE: TcxGridDBColumn
        Caption = #1058#1080#1087#1099' '#1094#1077#1085
        DataBinding.FieldName = 'NAME_TPRICE'
      end
    end
    object cxGrid2Level1: TcxGridLevel
      GridView = cxGrid2DBTableViewTypePrice
    end
  end
  object cxButton1: TcxButton
    Left = 8
    Top = 97
    Width = 111
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1073#1072#1079#1091' '
    DropDownMenu = InfBasePopupMenu
    Kind = cxbkDropDown
    TabOrder = 5
  end
  object cxButton2: TcxButton
    Left = 123
    Top = 97
    Width = 121
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100' '#1073#1072#1079#1091
    TabOrder = 6
    OnClick = cxButton2Click
  end
  object cxButton3: TcxButton
    Left = 250
    Top = 97
    Width = 128
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1090#1080#1087' '#1094#1077#1085
    DropDownMenu = TypePricePopupMenu
    Kind = cxbkDropDown
    TabOrder = 7
  end
  object cxButton4: TcxButton
    Left = 384
    Top = 97
    Width = 116
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100' '#1090#1080#1087' '#1094#1077#1085
    TabOrder = 8
    OnClick = cxButton4Click
  end
  object IdStardIdXTismcxDBLabel: TcxDBLabel
    Left = 266
    Top = 62
    AutoSize = True
    DataBinding.DataField = 'IDTISM_XSETUP_OBMEN'
    ParentFont = False
    Style.Font.Charset = DEFAULT_CHARSET
    Style.Font.Color = clWindowText
    Style.Font.Height = -12
    Style.Font.Name = 'MS Sans Serif'
    Style.Font.Style = [fsBold]
    Style.IsFontAssigned = True
  end
  object AllDoccxDBCheckBox: TcxDBCheckBox
    Left = 8
    Top = 334
    Caption = #1074#1099#1075#1088#1091#1078#1072#1090#1100' '#1074#1089#1077' '#1076#1086#1082#1091#1084#1077#1085#1090#1099' ('#1085#1077' '#1080#1089#1087#1086#1083#1100#1079#1086#1074#1072#1090#1100' '#1048#1085#1092'. '#1073#1072#1079#1091')'
    DataBinding.DataField = 'ALLDOC_XSETUP_OBMEN'
    Properties.ValueChecked = 1
    Properties.ValueUnchecked = 0
    TabOrder = 10
    Visible = False
    Width = 319
  end
  object OutZakPricecxDBCheckBox: TcxDBCheckBox
    Left = 8
    Top = 361
    Caption = #1074#1099#1075#1088#1091#1078#1072#1090#1100' '#1089#1077#1073#1077#1089#1090#1086#1080#1084#1086#1089#1090#1100
    DataBinding.DataField = 'OUTZPRICE_XSETUP_OBMEN'
    Properties.ValueChecked = 1
    Properties.ValueUnchecked = 0
    TabOrder = 11
    Width = 185
  end
  object cxLabel1: TcxLabel
    Left = 16
    Top = 8
    Caption = 
      #1042#1085#1080#1084#1072#1085#1080#1077'! '#1053#1072#1089#1090#1088#1086#1081#1082#1080' '#1086#1073#1084#1077#1085#1072' '#1084#1086#1078#1085#1086' '#1088#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100' '#1090#1086#1083#1100#1082#1086' '#1076#1086' '#1085#1072#1095#1072#1083#1072' ' +
      #1086#1073#1084#1077#1085#1072'!'
    ParentFont = False
    Style.Font.Charset = DEFAULT_CHARSET
    Style.Font.Color = clRed
    Style.Font.Height = -12
    Style.Font.Name = 'MS Sans Serif'
    Style.Font.Style = [fsBold]
    Style.IsFontAssigned = True
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 312
    Top = 8
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
      OnExecute = ActionOpenHelpExecute
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
  end
  object InfBasePopupMenu: TPopupMenu
    Left = 16
    Top = 128
  end
  object TypePricePopupMenu: TPopupMenu
    Left = 272
    Top = 144
  end
end
