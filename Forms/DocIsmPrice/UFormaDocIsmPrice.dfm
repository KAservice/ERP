object FormaDocIsmPrice: TFormaDocIsmPrice
  Left = 288
  Top = 180
  Caption = #1055#1077#1088#1077#1086#1094#1077#1085#1082#1072
  ClientHeight = 577
  ClientWidth = 817
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
  object Panel2: TPanel
    Left = 0
    Top = 247
    Width = 4
    Height = 239
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 3
  end
  object Panel3: TPanel
    Left = 0
    Top = 486
    Width = 817
    Height = 91
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 2
    object DBTextFNameUser: TDBText
      Left = 4
      Top = 12
      Width = 164
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      AutoSize = True
      DataField = 'FNAME_USER'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -18
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object ProsmotrLabel: TLabel
      Left = 4
      Top = 39
      Width = 155
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1090#1086#1083#1100#1082#1086' '#1087#1088#1086#1089#1084#1086#1090#1088
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -18
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object ProsmotrTextLabel: TLabel
      Left = 4
      Top = 73
      Width = 114
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = 'ProsmotrTextLabel'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object cxButtonDvReg: TcxButton
      Left = 394
      Top = 50
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionDvReg
      TabOrder = 0
    end
    object cxButtonSave: TcxButton
      Left = 494
      Top = 50
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionSave
      TabOrder = 1
    end
    object cxButtonOK: TcxButton
      Left = 593
      Top = 50
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
      Left = 693
      Top = 50
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      TabOrder = 3
    end
    object cxButtonPrint: TcxButton
      Left = 294
      Top = 50
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionPrint
      TabOrder = 4
    end
  end
  object Panel4: TPanel
    Left = 814
    Top = 247
    Width = 3
    Height = 239
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 4
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 817
    Height = 247
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 59
      Top = 118
      Width = 209
      Height = 32
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1077#1088#1077#1086#1094#1077#1085#1082#1072' '#8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -28
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 546
      Top = 120
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
    object Label7: TLabel
      Left = 4
      Top = 210
      Width = 86
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077':'
    end
    object Label12: TLabel
      Left = 34
      Top = 81
      Width = 47
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1060#1080#1088#1084#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label13: TLabel
      Left = 471
      Top = 38
      Width = 43
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1082#1083#1072#1076':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 10
      Top = 182
      Width = 55
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1058#1080#1087' '#1094#1077#1085':'
    end
    object ToolBar2: TToolBar
      Left = 0
      Top = 0
      Width = 817
      Height = 30
      Color = clBtnFace
      EdgeBorders = [ebTop, ebBottom]
      Images = DM.ImageList1
      ParentColor = False
      TabOrder = 10
      object ToolButton1: TToolButton
        Left = 0
        Top = 0
        Width = 17
        Caption = 'ToolButton1'
        Style = tbsSeparator
      end
      object AddNomSoSkladaToolButtonInsert: TToolButton
        Left = 17
        Top = 0
        Action = ActionAddNomSoSklada
        ParentShowHint = False
        ShowHint = True
      end
      object AddNomToolButton: TToolButton
        Left = 40
        Top = 0
        Action = ActionAddNom
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonDelete: TToolButton
        Left = 63
        Top = 0
        Action = ActionDeleteRecord
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButton2: TToolButton
        Left = 86
        Top = 0
        Width = 74
        Caption = 'ToolButton2'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButton3: TToolButton
        Left = 160
        Top = 0
        Width = 8
        Caption = 'ToolButton3'
        ImageIndex = 4
        Style = tbsSeparator
      end
      object ToolButton4: TToolButton
        Left = 168
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
        Caption = 'ToolButton4'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonUpdatePriceInSpr: TToolButton
        Left = 191
        Top = 0
        Hint = #1054#1073#1085#1086#1074#1080#1090#1100' '#1094#1077#1085#1099' '#1079#1072' '#1073#1072#1079#1086#1074#1099#1077' '#1077#1076#1080#1085#1080#1094#1099' '#1080#1079#1084#1077#1088#1077#1085#1080#1103
        Caption = 'ToolButtonUpdatePriceInSpr'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonUpdatePriceInSprClick
      end
      object ToolButtonAddAllOstatki: TToolButton
        Left = 214
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1074#1089#1077' '#1090#1086#1074#1072#1088#1099' '#1089#1086' '#1089#1082#1083#1072#1076#1072
        Caption = 'ToolButtonAddAllOstatki'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonAddAllOstatkiClick
      end
      object ToolButtonAddOstatkiPoGrp: TToolButton
        Left = 237
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1086#1089#1090#1072#1090#1082#1080' '#1090#1086#1074#1072#1088#1086#1074' '#1080#1079' '#1075#1088#1091#1087#1087#1099
        Caption = 'ToolButtonAddOstatkiPoGrp'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonAddOstatkiPoGrpClick
      end
      object ToolButtonAddSebest: TToolButton
        Left = 260
        Top = 0
        Hint = #1056#1072#1089#1089#1095#1080#1090#1072#1090#1100' '#1089#1077#1073#1077#1089#1090#1086#1080#1084#1086#1089#1090#1100
        Caption = 'ToolButtonAddSebest'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonAddSebestClick
      end
    end
    object NumDoccxDBTextEdit: TcxDBTextEdit
      Left = 429
      Top = 128
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NUMDOC'
      TabOrder = 6
      OnKeyDown = NumDoccxDBTextEditKeyDown
      Width = 109
    end
    object PosDoccxDBDateEdit: TcxDBDateEdit
      Left = 587
      Top = 128
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'POSDOC'
      Properties.Kind = ckDateTime
      TabOrder = 7
      OnKeyDown = PosDoccxDBDateEditKeyDown
      Width = 198
    end
    object NameSkladcxDBButtonEdit: TcxDBButtonEdit
      Left = 524
      Top = 35
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
      Width = 272
    end
    object NameFirmcxDBButtonEdit: TcxDBButtonEdit
      Left = 89
      Top = 78
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
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameFirmcxDBButtonEditPropertiesButtonClick
      TabOrder = 1
      Width = 296
    end
    object NameInfBasecxDBButtonEdit: TcxDBButtonEdit
      Left = 89
      Top = 44
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
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameInfBasecxDBButtonEditPropertiesButtonClick
      TabOrder = 0
      Width = 296
    end
    object cxLabel1: TcxLabel
      Left = 9
      Top = 45
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1048#1085#1092'. '#1073#1072#1079#1072':'
    end
    object TypePriceComboBox: TcxComboBox
      Left = 89
      Top = 177
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Properties.DropDownListStyle = lsFixedList
      Properties.OnValidate = TypePriceComboBoxPropertiesValidate
      TabOrder = 8
      Width = 267
    end
    object DescrcxDBTextEdit: TcxDBTextEdit
      Left = 89
      Top = 210
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'DESCR_DISMPRICE'
      TabOrder = 9
      OnKeyDown = DescrcxDBTextEditKeyDown
      Width = 496
    end
    object NameInvcxDBButtonEdit: TcxDBButtonEdit
      Left = 516
      Top = 178
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAME_SINV'
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
      Properties.OnButtonClick = NameInvcxDBButtonEditPropertiesButtonClick
      TabOrder = 12
      Width = 280
    end
    object cxLabel2: TcxLabel
      Left = 516
      Top = 160
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1048#1085#1074#1077#1085#1090#1072#1088#1080#1079#1072#1094#1080#1103':'
    end
    object NameBusinessOpercxDBButtonEdit: TcxDBButtonEdit
      Left = 524
      Top = 60
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
      TabOrder = 3
      Width = 272
    end
    object cxLabel9: TcxLabel
      Left = 400
      Top = 61
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1041#1080#1079#1085#1077#1089' '#1086#1087#1077#1088#1072#1094#1080#1103':'
    end
    object NameProjectcxDBButtonEdit: TcxDBButtonEdit
      Left = 524
      Top = 85
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
      TabOrder = 4
      Width = 272
    end
    object cxLabel3: TcxLabel
      Left = 466
      Top = 86
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1088#1086#1077#1082#1090':'
    end
    object PrefiksNumcxDBTextEdit: TcxDBTextEdit
      Left = 276
      Top = 128
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'PREFIKS_NUM_GALLDOC'
      TabOrder = 5
      Width = 145
    end
  end
  object cxGrid1: TcxGrid
    Left = 4
    Top = 247
    Width = 810
    Height = 239
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    TabOrder = 1
    object cxGrid1DBTableView1: TcxGridDBTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.Options = [dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding, dcoImmediatePost]
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <
        item
          Kind = skSum
          FieldName = 'OLDSUM'
          Column = cxGrid1DBTableView1OLDSUM
        end
        item
          Kind = skSum
          FieldName = 'NEWSUM'
          Column = cxGrid1DBTableView1NEWSUM
        end
        item
          Kind = skSum
          FieldName = 'SUMISM'
          Column = cxGrid1DBTableView1SUMISM
        end
        item
          Kind = skSum
          FieldName = 'KOL_DISMPRICET'
          Column = cxGrid1DBTableView1KOL_DISMPRICET
        end
        item
          Kind = skSum
          FieldName = 'SEB_SUM_DISMPRICET'
          Column = cxGrid1DBTableView1SEB_SUM_DISMPRICET
        end
        item
          Kind = skSum
          FieldName = 'NAC_SUM'
          Column = cxGrid1DBTableView1NAC_SUM
        end>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.GoToNextCellOnEnter = True
      OptionsSelection.InvertSelect = False
      OptionsView.CellAutoHeight = True
      OptionsView.ColumnAutoWidth = True
      OptionsView.Footer = True
      Styles.Header = DM.cxStyleFooterSum
      object cxGrid1DBTableView1RECNO: TcxGridDBColumn
        Caption = #8470
        DataBinding.FieldName = 'RECNO'
        Options.Editing = False
        Width = 24
      end
      object cxGrid1DBTableView1CODENOM: TcxGridDBColumn
        Caption = #1050#1086#1076
        DataBinding.FieldName = 'CODENOM'
        Width = 41
      end
      object cxGrid1DBTableView1ARTNOM: TcxGridDBColumn
        Caption = #1040#1088#1090#1080#1082#1091#1083
        DataBinding.FieldName = 'ARTNOM'
        Width = 44
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
        Properties.ReadOnly = True
        Properties.OnButtonClick = cxGrid1DBTableView1NAMENOMPropertiesButtonClick
        Width = 117
      end
      object cxGrid1DBTableView1KOL_DISMPRICET: TcxGridDBColumn
        Caption = #1050#1086#1083'.'
        DataBinding.FieldName = 'KOL_DISMPRICET'
        PropertiesClassName = 'TcxCalcEditProperties'
        Width = 35
      end
      object cxGrid1DBTableView1NAMEED: TcxGridDBColumn
        Caption = #1045#1076#1080#1085#1080#1094#1072
        DataBinding.FieldName = 'NAMEED'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ReadOnly = True
        Properties.OnButtonClick = cxGrid1DBTableView1NAMEEDPropertiesButtonClick
        Width = 46
      end
      object cxGrid1DBTableView1SHED: TcxGridDBColumn
        Caption = #1064#1050
        DataBinding.FieldName = 'SHED'
        Width = 43
      end
      object cxGrid1DBTableView1KF_DISMPRICET: TcxGridDBColumn
        Caption = #1050
        DataBinding.FieldName = 'KF_DISMPRICET'
        PropertiesClassName = 'TcxCalcEditProperties'
        Width = 27
      end
      object cxGrid1DBTableView1SEB_PRICE_DISMPRICET: TcxGridDBColumn
        Caption = #1047#1072#1082'. '#1094#1077#1085#1072
        DataBinding.FieldName = 'SEB_PRICE_DISMPRICET'
        Styles.Content = DM.cxStyleZakPrice
        Width = 44
      end
      object cxGrid1DBTableView1NAC_OLD_DISMPRICET: TcxGridDBColumn
        Caption = #1053#1072#1094#1077#1085#1082#1072' '#1089#1090#1072#1088'. %'
        DataBinding.FieldName = 'NAC_OLD_DISMPRICET'
        PropertiesClassName = 'TcxCalcEditProperties'
        Properties.Alignment.Horz = taRightJustify
        Styles.Content = DM.cxStyleProcentNacenka
        Width = 27
      end
      object cxGrid1DBTableView1OLDPRICE_DISMPRICET: TcxGridDBColumn
        Caption = #1057#1090#1072#1088'. '#1094#1077#1085#1072
        DataBinding.FieldName = 'OLDPRICE_DISMPRICET'
        PropertiesClassName = 'TcxCalcEditProperties'
        Styles.Content = DM.cxStyleYellow
        Width = 56
      end
      object cxGrid1DBTableView1NAC_NEW_DISMPRICET: TcxGridDBColumn
        Caption = #1053#1072#1094#1077#1085#1082#1072' '#1085#1086#1074'. %'
        DataBinding.FieldName = 'NAC_NEW_DISMPRICET'
        PropertiesClassName = 'TcxCalcEditProperties'
        Properties.Alignment.Horz = taRightJustify
        Properties.OnValidate = cxGrid1DBTableView1NAC_NEW_DISMPRICETPropertiesValidate
        Styles.Content = DM.cxStyleProcentNacenka
        Width = 30
      end
      object cxGrid1DBTableView1NEWPRICE_DISMPRICET: TcxGridDBColumn
        Caption = #1053#1086#1074'. '#1094#1077#1085#1072
        DataBinding.FieldName = 'NEWPRICE_DISMPRICET'
        PropertiesClassName = 'TcxCalcEditProperties'
        Styles.Content = DM.cxStyleYellow
        Width = 46
      end
      object cxGrid1DBTableView1OLDSUM: TcxGridDBColumn
        Caption = #1057#1091#1084#1084#1072' '#1087#1086' '#1089#1090#1072#1088'. '#1094#1077#1085#1077
        DataBinding.FieldName = 'OLDSUM'
        Width = 44
      end
      object cxGrid1DBTableView1NEWSUM: TcxGridDBColumn
        Caption = #1057#1091#1084#1084#1072' '#1087#1086' '#1085#1086#1074'. '#1094#1077#1085#1077
        DataBinding.FieldName = 'NEWSUM'
        Width = 43
      end
      object cxGrid1DBTableView1SUMISM: TcxGridDBColumn
        Caption = #1048#1079#1084#1077#1085#1077#1085#1080#1077
        DataBinding.FieldName = 'SUMISM'
        Width = 51
      end
      object cxGrid1DBTableView1SEB_SUM_DISMPRICET: TcxGridDBColumn
        Caption = #1057#1077#1073#1077#1089#1090#1086#1080#1084#1086#1089#1090#1100
        DataBinding.FieldName = 'SEB_SUM_DISMPRICET'
        Width = 40
      end
      object cxGrid1DBTableView1NAC_SUM: TcxGridDBColumn
        Caption = #1044#1086#1093#1086#1076
        DataBinding.FieldName = 'NAC_SUM'
        PropertiesClassName = 'TcxCalcEditProperties'
        Properties.Precision = 15
        Styles.Content = DM.cxStyleDoxod
        Width = 50
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 8
    Top = 136
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
      OnExecute = ActionOpenHelpExecute
    end
    object ActionAddNomSoSklada: TAction
      Caption = 'ActionAddRecordSoSklada'
      Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1090#1086#1074#1072#1088' '#1089#1086' '#1089#1082#1083#1072#1076#1072
      ImageIndex = 0
      OnExecute = ActionAddNomSoSkladaExecute
    end
    object ActionDeleteRecord: TAction
      Caption = 'ActionDeleteRecord'
      Hint = #1059#1076#1072#1083#1080#1090#1100' '#1089#1090#1088#1086#1082#1091
      ImageIndex = 2
      OnExecute = ActionDeleteRecordExecute
    end
    object ActionAddNom: TAction
      Caption = 'ActionAddNom'
      Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1090#1086#1074#1072#1088
      ImageIndex = 0
      OnExecute = ActionAddNomExecute
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
      OnExecute = ActionPrintExecute
    end
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 328
  end
end
