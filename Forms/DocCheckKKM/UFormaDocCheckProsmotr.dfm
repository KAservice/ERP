object FormaDocCheckProsmotr: TFormaDocCheckProsmotr
  Left = 234
  Top = 117
  Caption = #1063#1077#1082' '#1050#1050#1052
  ClientHeight = 652
  ClientWidth = 927
  Color = clBtnFace
  Constraints.MinWidth = 935
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
    Top = 267
    Width = 5
    Height = 251
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 1
  end
  object Panel3: TPanel
    Left = 0
    Top = 518
    Width = 927
    Height = 134
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 0
    object Label11: TLabel
      Left = 69
      Top = 54
      Width = 269
      Height = 20
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1086#1083#1091#1095#1077#1085#1086' '#1085#1072#1083#1080#1095#1085#1099#1093' '#1086#1090' '#1087#1086#1082#1091#1087#1072#1090#1077#1083#1103':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label9: TLabel
      Left = 20
      Top = 20
      Width = 129
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1054#1087#1083#1072#1090#1072' '#1085#1072#1083#1080#1095#1085#1099#1084#1080':'
    end
    object Label10: TLabel
      Left = 286
      Top = 20
      Width = 126
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1083#1072#1090#1077#1078#1085#1086#1081' '#1082#1072#1088#1090#1086#1081':'
    end
    object FSummaCheck: TLabel
      Left = 571
      Top = 42
      Width = 138
      Height = 26
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1091#1084#1084#1072' '#1095#1077#1082#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBTextFNameUser: TDBText
      Left = 10
      Top = 108
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
    object SumDocDBText: TDBText
      Left = 738
      Top = 39
      Width = 154
      Height = 26
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      AutoSize = True
      DataField = 'SUMDOC'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object ProsmotrLabel: TLabel
      Left = 10
      Top = 89
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
    object NalcxDBTextEdit: TcxDBTextEdit
      Left = 415
      Top = 52
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NALCHK'
      Properties.ReadOnly = True
      TabOrder = 0
      Width = 118
    end
    object OplNalcxDBTextEdit: TcxDBTextEdit
      Left = 150
      Top = 12
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'OPLNALCHK'
      Properties.ReadOnly = True
      TabOrder = 1
      Width = 117
    end
    object OplPCcxDBTextEdit: TcxDBTextEdit
      Left = 415
      Top = 15
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'OPLPCCHK'
      TabOrder = 2
      Width = 118
    end
    object cxButtonClose: TcxButton
      Left = 825
      Top = 89
      Width = 92
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      TabOrder = 3
    end
  end
  object Panel4: TPanel
    Left = 923
    Top = 267
    Width = 4
    Height = 251
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 2
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 927
    Height = 267
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 3
    object Label1: TLabel
      Left = 108
      Top = 89
      Width = 116
      Height = 32
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1063#1077#1082' '#1050#1050#1052
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -28
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 523
      Top = 85
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
    object Label4: TLabel
      Left = 689
      Top = 197
      Width = 110
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1053#1086#1084#1077#1088' '#1095#1077#1082#1072' '#1050#1050#1052':'
    end
    object Label5: TLabel
      Left = 699
      Top = 167
      Width = 96
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1053#1086#1084#1077#1088' '#1050#1051' '#1050#1050#1052':'
    end
    object Label7: TLabel
      Left = 20
      Top = 236
      Width = 86
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077':'
    end
    object Label12: TLabel
      Left = 10
      Top = 55
      Width = 54
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1060#1080#1088#1084#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label13: TLabel
      Left = 542
      Top = 55
      Width = 50
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1082#1083#1072#1076':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label14: TLabel
      Left = 10
      Top = 128
      Width = 94
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1086#1082#1091#1087#1072#1090#1077#1083#1100':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label15: TLabel
      Left = 59
      Top = 197
      Width = 35
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1050#1050#1052':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label16: TLabel
      Left = 601
      Top = 236
      Width = 89
      Height = 20
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1054#1087#1077#1088#1072#1094#1080#1103':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label3: TLabel
      Left = 630
      Top = 126
      Width = 55
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1058#1080#1087' '#1094#1077#1085':'
    end
    object Label6: TLabel
      Left = 30
      Top = 167
      Width = 67
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1044#1086#1075#1086#1074#1086#1088':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object IdKlientDBText: TDBText
      Left = 502
      Top = 138
      Width = 80
      Height = 21
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataField = 'IDKLDOC'
    end
    object Label17: TLabel
      Left = 482
      Top = 138
      Width = 16
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = 'ID:'
    end
    object LabelDateDoc: TLabel
      Left = 571
      Top = 86
      Width = 63
      Height = 32
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = 'Date'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -28
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object NamePriceLabel: TLabel
      Left = 690
      Top = 126
      Width = 117
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = 'NamePriceLabel'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ToolBar2: TToolBar
      Left = 0
      Top = 0
      Width = 927
      Height = 30
      Color = clBtnFace
      EdgeBorders = [ebLeft, ebTop, ebRight, ebBottom]
      Images = DM.ImageList1
      ParentColor = False
      TabOrder = 0
      object ToolButton1: TToolButton
        Left = 0
        Top = 0
        Width = 17
        Caption = 'ToolButton1'
        Style = tbsSeparator
      end
      object ToolButton2: TToolButton
        Left = 17
        Top = 0
        Width = 170
        Caption = 'ToolButton2'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object NameBaseDBText: TDBText
        Left = 187
        Top = 0
        Width = 550
        Height = 22
        Alignment = taRightJustify
        DataField = 'NAME_SINFBASE_OBMEN'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object ToolButton3: TToolButton
        Left = 737
        Top = 0
        Width = 8
        Caption = 'ToolButton3'
        ImageIndex = 4
        Style = tbsSeparator
      end
    end
    object PrimcxDBTextEdit: TcxDBTextEdit
      Left = 106
      Top = 234
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'PRIMCHK'
      Properties.ReadOnly = True
      TabOrder = 1
      Width = 485
    end
    object Operation: TcxComboBox
      Left = 724
      Top = 234
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Properties.Items.Strings = (
        #1055#1088#1086#1076#1072#1078#1072
        #1042#1086#1079#1074#1088#1072#1090)
      Properties.ReadOnly = True
      TabOrder = 2
      Text = 'Operation'
      Width = 183
    end
    object NKlcxDBTextEdit: TcxDBTextEdit
      Left = 806
      Top = 159
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NKLCHK'
      Properties.ReadOnly = True
      TabOrder = 3
      Width = 90
    end
    object NCheckcxDBTextEdit: TcxDBTextEdit
      Left = 806
      Top = 192
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NCHECKCHK'
      Properties.ReadOnly = True
      TabOrder = 4
      Width = 90
    end
    object NameKKMcxDBTextEdit: TcxDBTextEdit
      Left = 106
      Top = 191
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAMEKKM'
      Properties.ReadOnly = True
      TabOrder = 5
      Width = 348
    end
    object NameSDogovorcxDBTextEdit: TcxDBTextEdit
      Left = 106
      Top = 161
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAME_SDOG'
      Properties.ReadOnly = True
      TabOrder = 6
      Width = 348
    end
    object NameKlientcxDBTextEdit: TcxDBTextEdit
      Left = 106
      Top = 128
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAMEKLIENT'
      TabOrder = 7
      Width = 348
    end
    object NameFirmcxDBTextEdit: TcxDBTextEdit
      Left = 106
      Top = 55
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAMEFIRM'
      TabOrder = 8
      Width = 348
    end
    object NumDoccxDBTextEdit: TcxDBTextEdit
      Left = 392
      Top = 96
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NUMDOC'
      TabOrder = 9
      Width = 106
    end
    object NameSkladcxDBTextEdit: TcxDBTextEdit
      Left = 601
      Top = 52
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAMESKLAD'
      Properties.ReadOnly = True
      TabOrder = 10
      Width = 295
    end
    object PrefiksNumcxDBTextEdit: TcxDBTextEdit
      Left = 239
      Top = 96
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'PREFIKS_NUM_GALLDOC'
      TabOrder = 11
      Width = 145
    end
  end
  object cxGrid1: TcxGrid
    Left = 5
    Top = 267
    Width = 918
    Height = 251
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    TabOrder = 4
    object cxGrid1DBTableView1: TcxGridDBTableView
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
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1RECNO: TcxGridDBColumn
        Caption = #8470
        DataBinding.FieldName = 'RECNO'
        Width = 46
      end
      object cxGrid1DBTableView1NAMENOM: TcxGridDBColumn
        Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072
        DataBinding.FieldName = 'NAMENOM'
        Width = 233
      end
      object cxGrid1DBTableView1KOLCHKT: TcxGridDBColumn
        Caption = #1050#1086#1083'.'
        DataBinding.FieldName = 'KOLCHKT'
        Width = 42
      end
      object cxGrid1DBTableView1NAMEED: TcxGridDBColumn
        Caption = #1045#1076#1080#1085#1080#1094#1072
        DataBinding.FieldName = 'NAMEED'
        Width = 61
      end
      object cxGrid1DBTableView1KFCHKT: TcxGridDBColumn
        Caption = #1050
        DataBinding.FieldName = 'KFCHKT'
        Width = 46
      end
      object cxGrid1DBTableView1PRICECHKT: TcxGridDBColumn
        Caption = #1062#1077#1085#1072
        DataBinding.FieldName = 'PRICECHKT'
        Width = 76
      end
      object cxGrid1DBTableView1SUMCHKT: TcxGridDBColumn
        Caption = #1057#1091#1084#1084#1072
        DataBinding.FieldName = 'SUMCHKT'
        Width = 85
      end
      object cxGrid1DBTableView1PRSKCHKT: TcxGridDBColumn
        Caption = '-%'
        DataBinding.FieldName = 'PRSKCHKT'
        Width = 23
      end
      object cxGrid1DBTableView1SKCHKT: TcxGridDBColumn
        Caption = #1057#1082#1080#1076#1082#1072
        DataBinding.FieldName = 'SKCHKT'
        Width = 48
      end
      object cxGrid1DBTableView1PRNADCHKT: TcxGridDBColumn
        Caption = '+%'
        DataBinding.FieldName = 'PRNADCHKT'
        Width = 24
      end
      object cxGrid1DBTableView1NADCHKT: TcxGridDBColumn
        Caption = #1053#1072#1076#1073#1072#1074#1082#1072
        DataBinding.FieldName = 'NADCHKT'
        Width = 59
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 480
    Top = 32
    object ActionClose: TAction
      Caption = #1047#1072#1082#1088#1099#1090#1100
      ImageIndex = 53
      OnExecute = ActionCloseExecute
    end
  end
end
