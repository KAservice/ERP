object FormaElementaSprProduce: TFormaElementaSprProduce
  Left = 249
  Top = 132
  Caption = #1055#1088#1086#1076#1091#1082#1090
  ClientHeight = 568
  ClientWidth = 752
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
  object Label2: TLabel
    Left = 16
    Top = 126
    Width = 102
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
  end
  object Label1: TLabel
    Left = 9
    Top = 72
    Width = 40
    Height = 24
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1086#1076':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -18
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 16
    Top = 177
    Width = 92
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1086#1084#1084#1077#1085#1090#1072#1088#1080#1081':'
  end
  object Label4: TLabel
    Left = 349
    Top = 363
    Width = 56
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1046#1080#1088#1099' %:'
  end
  object Label5: TLabel
    Left = 323
    Top = 409
    Width = 82
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1059#1075#1083#1077#1074#1086#1076#1099' %:'
  end
  object Label6: TLabel
    Left = 332
    Top = 315
    Width = 58
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1041#1077#1083#1082#1080' %:'
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 752
    Height = 50
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 1
    object NameGrpLabel: TLabel
      Left = 15
      Top = 17
      Width = 93
      Height = 16
      Caption = 'NameGrpLabel'
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 517
    Width = 752
    Height = 51
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 0
    object cxButtonSave: TcxButton
      Left = 352
      Top = 10
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionSave
      TabOrder = 0
    end
    object cxButtonOK: TcxButton
      Left = 452
      Top = 10
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionOK
      TabOrder = 1
    end
    object cxButtonClose: TcxButton
      Left = 551
      Top = 10
      Width = 93
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      Cancel = True
      TabOrder = 2
    end
  end
  object GroupBox1: TGroupBox
    Left = 533
    Top = 58
    Width = 193
    Height = 439
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1047#1085#1072#1095#1077#1085#1080#1103' '#1087#1086#1082#1072#1079#1072#1090#1077#1083#1077#1081' %'
    TabOrder = 2
    object ToolBar4: TToolBar
      Left = 2
      Top = 18
      Width = 189
      Height = 28
      Caption = 'ToolBar4'
      Color = clCaptionText
      Images = DM.ImageList1
      ParentColor = False
      TabOrder = 0
      object ToolButton1: TToolButton
        Left = 0
        Top = 0
        Width = 9
        Caption = 'ToolButton1'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButtonAddPrice: TToolButton
        Left = 9
        Top = 0
        Caption = 'ToolButtonAddPrice'
        ImageIndex = 0
        OnClick = ToolButtonAddPriceClick
      end
      object ToolButtonDeletePrice: TToolButton
        Left = 32
        Top = 0
        Caption = 'ToolButtonDeletePrice'
        ImageIndex = 2
        OnClick = ToolButtonDeletePriceClick
      end
      object ToolButtonAddAllFactors: TToolButton
        Left = 55
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1074#1089#1077' '#1092#1072#1082#1090#1086#1088#1099
        Caption = 'ToolButtonAddAllFactors'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonAddAllFactorsClick
      end
    end
    object cxGrid1: TcxGrid
      Left = 2
      Top = 46
      Width = 189
      Height = 391
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
        OptionsBehavior.IncSearch = True
        OptionsSelection.InvertSelect = False
        OptionsView.ColumnAutoWidth = True
        OptionsView.GroupByBox = False
        Styles.Header = DM.cxStyleHeaderTable
        object cxGrid1DBTableView1IDFACTOR_SFACTOR_VAL: TcxGridDBColumn
          Caption = #1055#1086#1082#1072#1079#1072#1090#1077#1083#1100
          DataBinding.FieldName = 'IDFACTOR_SFACTOR_VAL'
          PropertiesClassName = 'TcxLookupComboBoxProperties'
          Properties.DropDownListStyle = lsFixedList
          Properties.KeyFieldNames = 'ID_SFACTOR'
          Properties.ListColumns = <
            item
              Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
              FieldName = 'NAME_SFACTOR'
            end>
          Styles.Header = DM.cxStyleHeaderTable
          Width = 164
        end
        object cxGrid1DBTableView1VALUE_SFACTOR_VAL: TcxGridDBColumn
          Caption = #1047#1085#1072#1095#1077#1085#1080#1077
          DataBinding.FieldName = 'VALUE_SFACTOR_VAL'
          PropertiesClassName = 'TcxCalcEditProperties'
          Properties.DisplayFormat = '0.000'
          Properties.Precision = 15
          Styles.Header = DM.cxStyleHeaderTable
          Width = 162
        end
      end
      object cxGrid1Level1: TcxGridLevel
        GridView = cxGrid1DBTableView1
      end
    end
  end
  object NameNomcxDBTextEdit: TcxDBTextEdit
    Left = 16
    Top = 145
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_SPRODUCE'
    Properties.ValidateOnEnter = True
    TabOrder = 3
    Width = 509
  end
  object CodecxDBTextEdit: TcxDBTextEdit
    Left = 57
    Top = 75
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'CODE_SPRODUCE'
    TabOrder = 4
    Width = 105
  end
  object CommentcxDBMemo: TcxDBMemo
    Left = 16
    Top = 200
    DataBinding.DataField = 'COMMENT_SPRODUCE'
    TabOrder = 5
    Height = 89
    Width = 510
  end
  object BelkicxDBCalcEdit: TcxDBCalcEdit
    Left = 397
    Top = 312
    DataBinding.DataField = 'BELKI_SPRODUCE'
    TabOrder = 6
    Width = 121
  end
  object GiricxDBCalcEdit: TcxDBCalcEdit
    Left = 397
    Top = 360
    DataBinding.DataField = 'GIRI_SPRODUCE'
    TabOrder = 7
    Width = 121
  end
  object UglcxDBCalcEdit: TcxDBCalcEdit
    Left = 397
    Top = 406
    DataBinding.DataField = 'UGL_SPRODUCE'
    TabOrder = 8
    Width = 121
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 416
    Top = 24
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
    end
    object ActionSetMainTabSheet: TAction
      Caption = 'ActionSetMainTabSheet'
      ShortCut = 116
    end
    object ActionSetAdditionallyTabSheet: TAction
      Caption = 'ActionSetAdditionallyTabSheet'
      ShortCut = 117
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
    object ActionSave: TAction
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      ImageIndex = 55
      OnExecute = ActionSaveExecute
    end
  end
end
