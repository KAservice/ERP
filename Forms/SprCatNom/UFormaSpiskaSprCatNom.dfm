object FormaSpiskaSprCatNom: TFormaSpiskaSprCatNom
  Left = 329
  Top = 186
  Caption = #1057#1087#1088#1072#1074#1086#1095#1085#1080#1082' '#1082#1072#1090#1077#1075#1086#1088#1080#1081' '#1085#1086#1084#1077#1088#1086#1074':'
  ClientHeight = 357
  ClientWidth = 499
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
  OnCreate = FormCreate
  OnResize = FormResize
  PixelsPerInch = 120
  TextHeight = 16
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 499
    Height = 90
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 0
    ExplicitWidth = 626
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 509
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
      object ToolButtonNew: TToolButton
        Left = 8
        Top = 2
        Caption = 'ToolButtonNew'
        ImageIndex = 0
        OnClick = ToolButtonNewClick
      end
      object ToolButtonEdit: TToolButton
        Left = 31
        Top = 2
        Caption = 'ToolButtonEdit'
        ImageIndex = 1
        OnClick = ToolButtonEditClick
      end
      object ToolButtonDelete: TToolButton
        Left = 54
        Top = 2
        Caption = 'ToolButtonDelete'
        ImageIndex = 2
        OnClick = ToolButtonDeleteClick
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 90
    Width = 11
    Height = 198
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 1
    ExplicitHeight = 294
  end
  object Panel3: TPanel
    Left = 483
    Top = 90
    Width = 16
    Height = 198
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alRight
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 2
    ExplicitLeft = 610
    ExplicitHeight = 294
  end
  object Panel4: TPanel
    Left = 0
    Top = 288
    Width = 499
    Height = 69
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 3
    ExplicitTop = 384
    ExplicitWidth = 626
    object ButtonClose: TButton
      Left = 492
      Top = 20
      Width = 93
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1047#1072#1082#1088#1099#1090#1100
      TabOrder = 0
      OnClick = ButtonCloseClick
    end
  end
  object DBGrid1: TDBGrid
    Left = 11
    Top = 90
    Width = 472
    Height = 198
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    DataSource = DMSprCatNom.DataSourceTable
    TabOrder = 4
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -14
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    OnDblClick = DBGrid1DblClick
    Columns = <
      item
        Expanded = False
        FieldName = 'RECNO'
        Title.Caption = #8470
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'NAME_CATNOM'
        Title.Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
        Width = 272
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'KOL_CATNOM'
        Title.Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1085#1086#1084#1077#1088#1086#1074
        Width = 115
        Visible = True
      end>
  end
end
