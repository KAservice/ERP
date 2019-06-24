object FormaGurDocRecKDR: TFormaGurDocRecKDR
  Left = 183
  Top = 112
  Caption = #1050#1085#1080#1075#1072' '#1076#1086#1093#1086#1076#1086#1074' '#1080' '#1088#1072#1089#1093#1086#1076#1086#1074':'
  ClientHeight = 487
  ClientWidth = 712
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
    Width = 712
    Height = 49
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 0
    object LabelInterval: TLabel
      Left = 240
      Top = 32
      Width = 61
      Height = 16
      Caption = #1055#1077#1088#1080#1086#1076':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label1: TLabel
      Left = 8
      Top = 32
      Width = 199
      Height = 16
      Caption = #1050#1085#1080#1075#1072' '#1076#1086#1093#1086#1076#1086#1074' '#1080' '#1088#1072#1089#1093#1086#1076#1086#1074':'
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
      Width = 712
      Height = 29
      Caption = 'ToolBar1'
      Images = DM.ImageList1
      TabOrder = 0
      object ToolButton1: TToolButton
        Left = 0
        Top = 0
        Width = 8
        Caption = 'ToolButton1'
        Style = tbsSeparator
      end
      object ToolButtonNewDoc: TToolButton
        Left = 8
        Top = 0
        Caption = 'ToolButtonNewDoc'
        ImageIndex = 0
        OnClick = ToolButtonNewDocClick
      end
      object ToolButton4: TToolButton
        Left = 31
        Top = 0
        Caption = 'ToolButton4'
        ImageIndex = 1
        OnClick = ToolButton4Click
      end
      object ToolButtonViborPerioda: TToolButton
        Left = 54
        Top = 0
        Caption = 'ToolButtonViborPerioda'
        ImageIndex = 3
        OnClick = ToolButtonViborPeriodaClick
      end
      object ToolButton2: TToolButton
        Left = 77
        Top = 0
        Width = 51
        Caption = 'ToolButton2'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButton3: TToolButton
        Left = 128
        Top = 0
        Hint = #1054#1090#1084#1077#1085#1080#1090#1100' '#1087#1088#1086#1074#1077#1076#1077#1085#1080#1077
        Caption = 'ToolButton3'
        ImageIndex = 12
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButton3Click
      end
      object ToolButtonDelete: TToolButton
        Left = 151
        Top = 0
        Hint = #1059#1076#1072#1083#1080#1090#1100
        Caption = 'ToolButtonDelete'
        ImageIndex = 2
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonDeleteClick
      end
      object ToolButtonPrint: TToolButton
        Left = 174
        Top = 0
        Hint = #1087#1077#1095#1072#1090#1100' '#1078#1091#1088#1085#1072#1083#1072
        Caption = 'ToolButtonPrint'
        ParentShowHint = False
        ShowHint = True
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 49
    Width = 9
    Height = 381
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 1
  end
  object Panel3: TPanel
    Left = 0
    Top = 430
    Width = 712
    Height = 57
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 2
  end
  object Panel4: TPanel
    Left = 700
    Top = 49
    Width = 12
    Height = 381
    Align = alRight
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 3
  end
  object DBGrid1: TDBGrid
    Left = 9
    Top = 49
    Width = 691
    Height = 381
    Align = alClient
    DataSource = DMGurDocRecKDR.DataSourceTable
    ReadOnly = True
    TabOrder = 4
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    OnDrawColumnCell = DBGrid1DrawColumnCell
    OnDblClick = DBGrid1DblClick
    Columns = <
      item
        Expanded = False
        FieldName = 'PRDOC'
        Title.Caption = #1055#1088'.'
        Width = 23
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'NAMEFIRM'
        Title.Caption = #1060#1080#1088#1084#1072
        Width = 93
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'POSDOC'
        Title.Caption = #1044#1072#1090#1072
        Width = 129
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'NUMDOC'
        Title.Caption = #1053#1086#1084#1077#1088
        Width = 57
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'OPERATION_DREC_KDR'
        Title.Caption = #1054#1087#1077#1088#1072#1094#1080#1103
        Width = 170
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'DOHOD_DREC_KDR'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        Title.Caption = #1057#1091#1084#1084#1072' '#1076#1086#1093#1086#1076#1072
        Width = 84
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'RASHOD_DREC_KDR'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        Title.Caption = #1057#1091#1084#1084#1072' '#1088#1072#1089#1093#1086#1076#1072
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clBlack
        Title.Font.Height = -11
        Title.Font.Name = 'MS Sans Serif'
        Title.Font.Style = []
        Width = 90
        Visible = True
      end>
  end
  object ActionList: TActionList
    Left = 184
    Top = 40
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
    end
  end
end
