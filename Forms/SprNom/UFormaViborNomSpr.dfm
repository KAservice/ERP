object FormaViborNomSpr: TFormaViborNomSpr
  Left = 219
  Top = 91
  Width = 795
  Height = 576
  Caption = #1057#1087#1088#1072#1074#1086#1095#1085#1080#1082' "'#1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072'"'
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
  OnCreate = FormCreate
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 787
    Height = 73
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 3
    object LabelNameGrp: TLabel
      Left = 296
      Top = 56
      Width = 58
      Height = 16
      Caption = #1043#1088#1091#1087#1087#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object HintLabel: TLabel
      Left = 8
      Top = 28
      Width = 44
      Height = 16
      Caption = #1058#1077#1082#1089#1090
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 787
      Height = 29
      Caption = 'ToolBar1'
      Images = DM.ImageList1
      TabOrder = 0
      object ToolButton1: TToolButton
        Left = 0
        Top = 2
        Width = 8
        Caption = 'ToolButton1'
        Style = tbsSeparator
      end
      object ToolButtonNewGrp: TToolButton
        Left = 8
        Top = 2
        Caption = 'ToolButtonNewGrp'
        ImageIndex = 0
      end
      object ToolButtonEdiGrp: TToolButton
        Left = 31
        Top = 2
        Caption = 'ToolButtonEdiGrp'
        ImageIndex = 1
      end
      object ToolButtonDeleteGrp: TToolButton
        Left = 54
        Top = 2
        Caption = 'ToolButtonDeleteGrp'
        ImageIndex = 2
      end
      object ToolButton2: TToolButton
        Left = 77
        Top = 2
        Width = 84
        Caption = 'ToolButton2'
        ImageIndex = 2
        Style = tbsSeparator
      end
      object ToolButton3: TToolButton
        Left = 161
        Top = 2
        Width = 136
        Caption = 'ToolButton3'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButtonNew: TToolButton
        Left = 297
        Top = 2
        Caption = 'ToolButtonNew'
        ImageIndex = 0
      end
      object ToolButtonEdit: TToolButton
        Left = 320
        Top = 2
        Caption = 'ToolButtonEdit'
        ImageIndex = 1
      end
      object ToolButtonDelete: TToolButton
        Left = 343
        Top = 2
        Caption = 'ToolButtonDelete'
        ImageIndex = 2
      end
      object ToolButton4: TToolButton
        Left = 366
        Top = 2
        Width = 35
        Caption = 'ToolButton4'
        ImageIndex = 6
        Style = tbsSeparator
      end
      object ToolButtonAll: TToolButton
        Left = 401
        Top = 2
        Caption = 'ToolButtonAll'
        ImageIndex = 8
        OnClick = ToolButtonAllClick
      end
      object ToolButtonIsmGrp: TToolButton
        Left = 424
        Top = 2
        Caption = 'ToolButtonIsmGrp'
        ImageIndex = 9
      end
    end
    object SpisokTypePrice: TComboBox
      Left = 599
      Top = 26
      Width = 178
      Height = 21
      Style = csDropDownList
      ItemHeight = 13
      TabOrder = 1
      OnChange = SpisokTypePriceChange
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 73
    Width = 9
    Height = 430
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 4
  end
  object Panel3: TPanel
    Left = 0
    Top = 503
    Width = 787
    Height = 46
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 2
    object ButtonClose: TButton
      Left = 696
      Top = 16
      Width = 75
      Height = 25
      Caption = #1047#1072#1082#1088#1099#1090#1100
      TabOrder = 0
      OnClick = ButtonCloseClick
    end
    object PoiskEdit: TEdit
      Left = 296
      Top = 0
      Width = 169
      Height = 21
      AutoSelect = False
      TabOrder = 1
      Text = 'PoiskEdit'
      OnChange = PoiskEditChange
      OnExit = PoiskEditExit
      OnKeyPress = PoiskEditKeyPress
    end
  end
  object Panel4: TPanel
    Left = 773
    Top = 73
    Width = 14
    Height = 430
    Align = alRight
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 5
  end
  object TreeView1: TTreeView
    Left = 9
    Top = 73
    Width = 272
    Height = 430
    Align = alLeft
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Indent = 19
    ParentFont = False
    TabOrder = 0
    OnCustomDrawItem = TreeView1CustomDrawItem
    OnDblClick = TreeView1DblClick
    OnKeyPress = TreeView1KeyPress
  end
  object Panel5: TPanel
    Left = 281
    Top = 73
    Width = 16
    Height = 430
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 6
  end
  object DBGrid1: TDBGrid
    Left = 297
    Top = 73
    Width = 476
    Height = 430
    Align = alClient
    DataSource = DMSprNom.DataSourceTable
    ReadOnly = True
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    OnDblClick = DBGrid1DblClick
    OnKeyPress = DBGrid1KeyPress
    Columns = <
      item
        Expanded = False
        FieldName = 'CODENOM'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        Title.Caption = #1050#1086#1076
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clNavy
        Title.Font.Height = -11
        Title.Font.Name = 'MS Sans Serif'
        Title.Font.Style = []
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'NAMENOM'
        Title.Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clNavy
        Title.Font.Height = -11
        Title.Font.Name = 'MS Sans Serif'
        Title.Font.Style = []
        Width = 288
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'ZNACH_PRICE'
        Title.Caption = #1062#1077#1085#1072
        Width = 64
        Visible = True
      end>
  end
end
