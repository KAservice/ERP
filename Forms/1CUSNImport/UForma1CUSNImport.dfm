object Forma1CUSNImport: TForma1CUSNImport
  Left = 228
  Top = 110
  Caption = #1047#1072#1075#1088#1091#1079#1082#1072' '#1080#1079' 1'#1057':'#1059#1057#1053
  ClientHeight = 542
  ClientWidth = 781
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  WindowState = wsMaximized
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 781
    Height = 29
    Caption = 'ToolBar1'
    EdgeBorders = [ebTop, ebBottom]
    TabOrder = 0
  end
  object Panel1: TPanel
    Left = 0
    Top = 29
    Width = 781
    Height = 68
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 1
    object Label1: TLabel
      Left = 8
      Top = 1
      Width = 740
      Height = 20
      Caption = 
        #1047#1072#1075#1088#1091#1079#1082#1072' '#1076#1086#1082#1091#1084#1077#1085#1090#1086#1074' '#1080#1079' '#1082#1086#1085#1092#1080#1075#1091#1088#1072#1094#1080#1080' 1'#1057':'#1055#1088#1077#1076#1087#1088#1080#1103#1090#1080#1077'. '#1059#1087#1088#1086#1097#1077#1085#1085#1072#1103' '#1089 +
        #1080#1089#1090#1077#1084#1072' '#1085#1072#1083#1086#1075#1086#1086#1073#1083#1086#1078#1077#1085#1080#1103
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      ParentFont = False
    end
    object LabelFileName: TLabel
      Left = 40
      Top = 44
      Width = 121
      Height = 16
      Caption = #1060#1072#1081#1083' '#1085#1077' '#1074#1099#1073#1088#1072#1085
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ButtonOpenFile: TButton
      Left = 8
      Top = 35
      Width = 25
      Height = 25
      Caption = '...'
      TabOrder = 0
      OnClick = ButtonOpenFileClick
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 97
    Width = 9
    Height = 368
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 2
  end
  object Panel4: TPanel
    Left = 769
    Top = 97
    Width = 12
    Height = 368
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 3
  end
  object Panel6: TPanel
    Left = 9
    Top = 97
    Width = 760
    Height = 368
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 4
    object PageControl1: TPageControl
      Left = 0
      Top = 0
      Width = 760
      Height = 368
      ActivePage = TabSheet2
      Align = alClient
      TabOrder = 0
      object TabSheet2: TTabSheet
        Caption = #1055#1088#1086#1090#1086#1082#1086#1083
        ImageIndex = 1
        ExplicitLeft = 0
        ExplicitTop = 0
        ExplicitWidth = 0
        ExplicitHeight = 0
        object RichEdit1: TRichEdit
          Left = 0
          Top = 0
          Width = 752
          Height = 340
          Align = alClient
          Lines.Strings = (
            'RichEdit1')
          ScrollBars = ssBoth
          TabOrder = 0
        end
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 465
    Width = 781
    Height = 77
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 5
    object ProgressBar1: TProgressBar
      Left = 8
      Top = 8
      Width = 753
      Height = 16
      TabOrder = 0
    end
    object ButtonZagr: TButton
      Left = 16
      Top = 40
      Width = 75
      Height = 25
      Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100
      TabOrder = 1
      OnClick = ButtonZagrClick
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 544
  end
  object xml: TXMLDocument
    Left = 600
    Top = 8
    DOMVendorDesc = 'MSXML'
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
