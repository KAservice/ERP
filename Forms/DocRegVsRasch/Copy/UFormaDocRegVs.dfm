object FormaDocRegVsRasch: TFormaDocRegVsRasch
  Left = 290
  Top = 119
  Caption = #1044#1086#1082#1091#1084#1077#1085#1090' "'#1044#1074#1080#1078#1077#1085#1080#1103' '#1088#1077#1075#1080#1089#1090#1088#1072' '#1042#1079#1072#1080#1084#1086#1088#1072#1089#1095#1077#1090#1099'"'
  ClientHeight = 503
  ClientWidth = 690
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
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TPanel
    Left = 0
    Top = 425
    Width = 690
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
      DataSource = DMDocVipuskProd.DataSourceDocAll
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -13
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
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object cxButtonPrint: TcxButton
      Left = 187
      Top = 40
      Width = 75
      Height = 25
      Caption = #1055#1077#1095#1072#1090#1100
      TabOrder = 0
      OnClick = cxButtonPrintClick
    end
    object cxButtonSave: TcxButton
      Left = 268
      Top = 40
      Width = 75
      Height = 25
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      TabOrder = 1
      OnClick = cxButtonSaveClick
    end
    object cxButtonDvReg: TcxButton
      Left = 349
      Top = 40
      Width = 75
      Height = 25
      Caption = #1055#1088#1086#1074#1077#1089#1090#1080
      TabOrder = 2
      OnClick = cxButtonDvRegClick
    end
    object cxButtonOK: TcxButton
      Left = 430
      Top = 40
      Width = 75
      Height = 25
      Caption = 'OK'
      TabOrder = 3
      OnClick = cxButtonOKClick
    end
    object cxButtonClose: TcxButton
      Left = 511
      Top = 40
      Width = 75
      Height = 25
      Caption = #1047#1072#1082#1088#1099#1090#1100
      TabOrder = 4
      OnClick = cxButtonCloseClick
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 113
    Width = 0
    Height = 312
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 2
    ExplicitTop = 177
    ExplicitHeight = 248
  end
  object Panel4: TPanel
    Left = 688
    Top = 113
    Width = 2
    Height = 312
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 3
    ExplicitTop = 177
    ExplicitHeight = 248
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 690
    Height = 113
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 6
      Top = 58
      Width = 393
      Height = 24
      Caption = #1044#1074#1080#1078#1077#1085#1080#1103' '#1088#1077#1075#1080#1089#1090#1088#1072' '#1042#1079#1072#1080#1084#1086#1088#1072#1089#1095#1077#1090#1099'  '#8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 492
      Top = 55
      Width = 36
      Height = 29
      Caption = #1086#1090' '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -24
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label3: TLabel
      Left = 17
      Top = 88
      Width = 66
      Height = 13
      Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077':'
    end
    object ToolBar2: TToolBar
      Left = 0
      Top = 0
      Width = 690
      Height = 30
      Color = clBtnFace
      EdgeBorders = [ebTop, ebRight, ebBottom]
      Images = DM.ImageList1
      ParentColor = False
      TabOrder = 4
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
    end
    object PrimcxDBTextEdit: TcxDBTextEdit
      Left = 89
      Top = 85
      DataBinding.DataField = 'PRIM_DKORRVS'
      DataBinding.DataSource = DMDocKorrVS.DataSourceDoc
      TabOrder = 3
      OnKeyDown = PrimcxDBTextEditKeyDown
      Width = 496
    end
    object NumDoccxDBTextEdit: TcxDBTextEdit
      Left = 405
      Top = 61
      DataBinding.DataField = 'NUMDOC'
      DataBinding.DataSource = DMDocVipuskProd.DataSourceDocAll
      TabOrder = 1
      OnKeyDown = NumDoccxDBTextEditKeyDown
      Width = 81
    end
    object PosDoccxDBDateEdit: TcxDBDateEdit
      Left = 534
      Top = 61
      DataBinding.DataField = 'POSDOC'
      DataBinding.DataSource = DMDocVipuskProd.DataSourceDocAll
      Properties.Kind = ckDateTime
      Properties.OnChange = PosDoccxDBDateEditPropertiesChange
      TabOrder = 2
      OnKeyDown = PosDoccxDBDateEditKeyDown
      Width = 154
    end
    object NameInfBasecxDBButtonEdit: TcxDBButtonEdit
      Left = 80
      Top = 31
      DataBinding.DataField = 'NAME_SINFBASE_OBMEN'
      DataBinding.DataSource = DMDocVipuskProd.DataSourceDocAll
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 13
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameInfBasecxDBButtonEditPropertiesButtonClick
      TabOrder = 0
      Width = 273
    end
    object cxLabel1: TcxLabel
      Left = 16
      Top = 32
      Caption = #1048#1085#1092'. '#1073#1072#1079#1072':'
    end
  end
  object cxGrid1: TcxGrid
    Left = 0
    Top = 113
    Width = 688
    Height = 312
    Align = alClient
    TabOrder = 4
    ExplicitTop = 177
    ExplicitHeight = 248
    object cxGrid1DBTableView1: TcxGridDBTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.DataSource = DMDocKorrVS.DataSourceDocT
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsView.ColumnAutoWidth = True
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1RECNO: TcxGridDBColumn
        Caption = #8470
        DataBinding.FieldName = 'RECNO'
      end
      object cxGrid1DBTableView1NAMEKLIENT: TcxGridDBColumn
        Caption = #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090
        DataBinding.FieldName = 'NAMEKLIENT'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = cxGrid1DBTableView1NAMEKLIENTPropertiesButtonClick
        Width = 273
      end
      object cxGrid1DBTableView1PRIHOD_DKORRVST: TcxGridDBColumn
        Caption = #1055#1088#1080#1093#1086#1076
        DataBinding.FieldName = 'PRIHOD_DKORRVST'
        PropertiesClassName = 'TcxCalcEditProperties'
      end
      object cxGrid1DBTableView1RASHOD_DKORRVST: TcxGridDBColumn
        Caption = #1056#1072#1089#1093#1086#1076
        DataBinding.FieldName = 'RASHOD_DKORRVST'
        PropertiesClassName = 'TcxCalcEditProperties'
      end
      object cxGrid1DBTableView1DVREGPAYSALE_DKORRVST: TcxGridDBColumn
        Caption = #1054#1087#1083#1072#1090#1072' '#1088#1077#1072#1083'.T'
        DataBinding.FieldName = 'DVREGPAYSALE_DKORRVST'
        PropertiesClassName = 'TcxCheckBoxProperties'
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
  end
end
