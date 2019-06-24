object FormaSpiskaSprSostProd: TFormaSpiskaSprSostProd
  Left = 135
  Top = 137
  Caption = #1057#1086#1089#1090#1072#1074' '#1087#1088#1086#1076#1091#1082#1094#1080#1080
  ClientHeight = 562
  ClientWidth = 971
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
    Width = 971
    Height = 110
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 1
    object LabelNom: TLabel
      Left = 138
      Top = 30
      Width = 167
      Height = 32
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1085#1077#1080#1079#1074#1077#1089#1090#1085#1086
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -28
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object LabelKolEd: TLabel
      Left = 7
      Top = 70
      Width = 167
      Height = 32
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1085#1077#1080#1079#1074#1077#1089#1090#1085#1086
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -28
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label1: TLabel
      Left = 10
      Top = 30
      Width = 108
      Height = 32
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1086#1089#1090#1072#1074':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -28
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 971
      Height = 29
      Caption = 'ToolBar1'
      EdgeBorders = [ebTop, ebBottom]
      Images = DM.ImageList1
      ParentShowHint = False
      ShowHint = False
      TabOrder = 0
      object ToolButton1: TToolButton
        Left = 0
        Top = 0
        Width = 8
        Caption = 'ToolButton1'
        Style = tbsSeparator
      end
      object ToolButtonNew: TToolButton
        Left = 8
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1080#1085#1075#1088#1080#1076#1080#1077#1085#1090
        Caption = 'ToolButtonNew'
        ImageIndex = 0
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonNewClick
      end
      object ToolButtonDelete: TToolButton
        Left = 31
        Top = 0
        Hint = #1059#1076#1072#1083#1080#1090#1100' '#1080#1085#1075#1088#1080#1076#1080#1077#1085#1090
        Caption = 'ToolButtonDelete'
        ImageIndex = 2
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonDeleteClick
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 110
    Width = 11
    Height = 368
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
    Top = 478
    Width = 971
    Height = 84
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 3
    object cxButtonClose: TcxButton
      Left = 769
      Top = 38
      Width = 93
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      TabOrder = 0
    end
    object cxButtonOK: TcxButton
      Left = 533
      Top = 38
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionOK
      TabOrder = 1
    end
    object cxButtonSave: TcxButton
      Left = 433
      Top = 38
      Width = 93
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionSave
      TabOrder = 2
    end
    object cxButtonReport: TcxButton
      Left = 334
      Top = 38
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1054#1090#1095#1077#1090
      TabOrder = 3
      OnClick = cxButtonReportClick
    end
    object cxButtonSezKF: TcxButton
      Left = 11
      Top = 38
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1077#1079#1086#1085#1085#1099#1081' '#1050
      TabOrder = 4
      OnClick = cxButtonSezKFClick
    end
  end
  object Panel4: TPanel
    Left = 956
    Top = 110
    Width = 15
    Height = 368
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alRight
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 4
  end
  object cxGrid1: TcxGrid
    Left = 11
    Top = 110
    Width = 945
    Height = 368
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    TabOrder = 0
    object cxGrid1DBTableView1: TcxGridDBTableView
      OnDblClick = cxGrid1DBTableView1DblClick
      OnKeyDown = cxGrid1DBTableView1KeyDown
      NavigatorButtons.ConfirmDelete = False
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsView.ColumnAutoWidth = True
      OptionsView.GroupByBox = False
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1RECNO: TcxGridDBColumn
        Caption = #8470
        DataBinding.FieldName = 'RECNO'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 27
      end
      object cxGrid1DBTableView1SPIS_SPROD: TcxGridDBColumn
        Caption = #1044#1074'.'
        DataBinding.FieldName = 'SPIS_SPROD'
        PropertiesClassName = 'TcxComboBoxProperties'
        Properties.Items.Strings = (
          #1044#1072
          #1053#1077#1090)
        Styles.Header = DM.cxStyleHeaderTable
        Width = 27
      end
      object cxGrid1DBTableView1NAMENOM: TcxGridDBColumn
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
        DataBinding.FieldName = 'NAMENOM'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ReadOnly = True
        Properties.OnButtonClick = cxGrid1DBTableView1NAMENOMPropertiesButtonClick
        Styles.Header = DM.cxStyleHeaderTable
        Width = 271
      end
      object cxGrid1DBTableView1NKOL_SPROD: TcxGridDBColumn
        Caption = #1050#1086#1083'. '#1085#1077#1090#1090#1086
        DataBinding.FieldName = 'NKOL_SPROD'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 79
      end
      object cxGrid1DBTableView1BKOL_SPROD: TcxGridDBColumn
        Caption = #1050#1086#1083'. '#1073#1088#1091#1090#1090#1086
        DataBinding.FieldName = 'BKOL_SPROD'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 87
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
        Styles.Header = DM.cxStyleHeaderTable
        Width = 54
      end
      object cxGrid1DBTableView1KF_SPROD: TcxGridDBColumn
        Caption = #1050' '#1077#1076'.'
        DataBinding.FieldName = 'KF_SPROD'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 40
      end
      object cxGrid1DBTableView1SEZKF: TcxGridDBColumn
        Caption = #1057#1077#1079'. '#1050
        DataBinding.FieldName = 'SEZKF'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 32
      end
      object cxGrid1DBTableView1SEZKF_SPROD: TcxGridDBColumn
        Caption = #1057#1077#1079'. '#1050'2'
        DataBinding.FieldName = 'SEZKF_SPROD'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 32
      end
      object cxGrid1DBTableView1NAME_SPRODUCE: TcxGridDBColumn
        Caption = #1055#1088#1086#1076#1091#1082#1090
        DataBinding.FieldName = 'NAME_SPRODUCE'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = cxGrid1DBTableView1NAME_SPRODUCEPropertiesButtonClick
        Width = 132
      end
      object cxGrid1DBTableView1NAME_SLOSS_FACTOR: TcxGridDBColumn
        Caption = #1055#1086#1090#1077#1088#1080
        DataBinding.FieldName = 'NAME_SLOSS_FACTOR'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = cxGrid1DBTableView1NAME_SLOSS_FACTORPropertiesButtonClick
        Width = 162
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
