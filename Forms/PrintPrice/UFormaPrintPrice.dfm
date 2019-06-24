object FormaPrintPrice: TFormaPrintPrice
  Left = 235
  Top = 216
  Caption = #1055#1077#1095#1072#1090#1100' '#1094#1077#1085#1085#1080#1082#1086#1074
  ClientHeight = 558
  ClientWidth = 847
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 120
  TextHeight = 16
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 847
    Height = 90
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 688
      Height = 29
      Caption = 'ToolBar1'
      EdgeBorders = [ebTop, ebBottom]
      Images = DM.ImageList1
      TabOrder = 0
      object ToolButton2: TToolButton
        Left = 0
        Top = 0
        Width = 8
        Caption = 'ToolButton2'
        ImageIndex = 1
        Style = tbsSeparator
      end
      object AddNomToolButton: TToolButton
        Left = 8
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1091
        Caption = 'AddNomToolButton'
        ImageIndex = 0
        ParentShowHint = False
        ShowHint = True
        OnClick = AddNomToolButtonClick
      end
      object AddGrpToolButton: TToolButton
        Left = 31
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1075#1088#1091#1087#1087#1091' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099
        Caption = 'AddGrpToolButton'
        ImageIndex = 34
        ParentShowHint = False
        ShowHint = True
        OnClick = AddGrpToolButtonClick
      end
      object DelNomToolButton: TToolButton
        Left = 54
        Top = 0
        Hint = #1059#1076#1072#1083#1080#1090#1100
        Caption = 'DelNomToolButton'
        ImageIndex = 2
        ParentShowHint = False
        ShowHint = True
        OnClick = DelNomToolButtonClick
      end
      object ToolButton1: TToolButton
        Left = 77
        Top = 0
        Caption = 'ToolButton1'
        ImageIndex = 3
      end
      object ToolButtonEditKol: TToolButton
        Left = 100
        Top = 0
        Caption = 'ToolButtonEditKol'
        ImageIndex = 36
        OnClick = ToolButtonEditKolClick
      end
      object ToolButton3: TToolButton
        Left = 123
        Top = 0
        Width = 133
        Caption = 'ToolButton3'
        ImageIndex = 4
        Style = tbsSeparator
      end
      object ToolButton4: TToolButton
        Left = 256
        Top = 0
        Hint = #1055#1077#1095#1072#1090#1100' '#1094#1077#1085#1085#1080#1082#1086#1074' '#8470'1'
        Caption = 'ToolButton4'
        ImageIndex = 38
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButton4Click
      end
      object ToolButtonPrintNumber2: TToolButton
        Left = 279
        Top = 0
        Hint = #1055#1077#1095#1072#1090#1100' '#1094#1077#1085#1085#1082#1080#1086#1074' '#8470'2'
        Caption = 'ToolButtonPrintNumber2'
        ImageIndex = 38
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonPrintNumber2Click
      end
      object ToolButtonPrintNumber3: TToolButton
        Left = 302
        Top = 0
        Hint = #1055#1077#1095#1072#1090#1100' '#1094#1077#1085#1085#1080#1082#1072' '#8470'3'
        Caption = 'ToolButtonPrintNumber3'
        ImageIndex = 38
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonPrintNumber3Click
      end
      object ToolButtonPrintNumber4: TToolButton
        Left = 325
        Top = 0
        Hint = #1055#1077#1095#1072#1090#1100' '#1094#1077#1085#1085#1080#1082#1072' '#8470'4'
        Caption = 'ToolButtonPrintNumber4'
        ImageIndex = 38
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonPrintNumber4Click
      end
    end
    object ToolBar2: TToolBar
      Left = 0
      Top = 29
      Width = 688
      Height = 28
      Caption = 'ToolBar2'
      EdgeBorders = [ebBottom]
      Images = DM.ImageList1
      TabOrder = 1
      object ToolButton7: TToolButton
        Left = 0
        Top = 0
        Width = 8
        Caption = 'ToolButton7'
        ImageIndex = 0
        Style = tbsSeparator
      end
      object ToolButton5: TToolButton
        Left = 8
        Top = 0
        Width = 233
        Caption = 'ToolButton5'
        Style = tbsSeparator
      end
      object ToolButtonPrintBarCode1: TToolButton
        Left = 241
        Top = 0
        Caption = 'ToolButtonPrintBarCode1'
        ImageIndex = 37
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 90
    Width = 21
    Height = 383
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 1
  end
  object Panel3: TPanel
    Left = 807
    Top = 90
    Width = 40
    Height = 383
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 2
  end
  object Panel4: TPanel
    Left = 0
    Top = 473
    Width = 847
    Height = 85
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 3
  end
  object StringGrid1: TStringGrid
    Left = 21
    Top = 90
    Width = 786
    Height = 383
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    RowCount = 4
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnDrawCell = StringGrid1DrawCell
    ColWidths = (
      64
      64
      300
      113
      64)
    RowHeights = (
      24
      24
      24
      24)
  end
  object ActionList1: TActionList
    Left = 8
    Top = 32
    object OpenHelp: TAction
      Caption = 'OpenHelp'
      ShortCut = 112
      OnExecute = OpenHelpExecute
    end
  end
end
