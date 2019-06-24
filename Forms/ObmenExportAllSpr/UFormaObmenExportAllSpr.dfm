object FormaObmenExportAllSpr: TFormaObmenExportAllSpr
  Left = 134
  Top = 114
  Width = 789
  Height = 587
  Caption = 
    #1054#1073#1084#1077#1085' '#1076#1072#1085#1085#1099#1084#1080' '#1089' '#1091#1076#1072#1083#1077#1085#1085#1099#1084#1080' '#1073#1072#1079#1072#1084#1080' ('#1087#1077#1088#1074#1086#1085#1072#1095#1072#1083#1100#1085#1086#1077' '#1079#1072#1087#1086#1083#1085#1077#1085#1080#1077' '#1080#1085#1092 +
    #1086#1088#1084#1072#1094#1080#1086#1085#1085#1086#1081' '#1073#1072#1079#1099')'
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
  OnClose = FormClose
  OnCreate = FormCreate
  OnResize = FormResize
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
    Height = 100
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 1
    object Label1: TLabel
      Left = 8
      Top = 1
      Width = 666
      Height = 20
      Caption = 
        #1042#1099#1075#1088#1091#1079#1082#1072' '#1074#1089#1077#1093' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1086#1074' '#1076#1083#1103' '#1087#1077#1088#1074#1086#1085#1072#1095#1072#1083#1100#1085#1086#1075#1086' '#1079#1072#1087#1086#1083#1085#1077#1085#1080#1103' '#1080#1085#1092#1086#1088#1084 +
        #1072#1094#1080#1086#1085#1085#1086#1081' '#1073#1072#1079#1099':'
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
    object NameBaseLabel: TLabel
      Left = 96
      Top = 64
      Width = 118
      Height = 20
      Caption = 'NameBaseLabel'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabelFileNameOut: TLabel
      Left = 104
      Top = 88
      Width = 87
      Height = 13
      Caption = 'LabelFileNameOut'
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
    object ButtonViborBase: TButton
      Left = 8
      Top = 72
      Width = 75
      Height = 25
      Caption = #1041#1072#1079#1072
      TabOrder = 1
      OnClick = ButtonViborBaseClick
    end
    object CheckBoxOutProtocol: TCheckBox
      Left = 384
      Top = 67
      Width = 145
      Height = 17
      Caption = #1074#1077#1089#1090#1080' '#1087#1088#1086#1090#1086#1082#1086#1083
      TabOrder = 2
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 129
    Width = 9
    Height = 327
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 2
  end
  object Panel4: TPanel
    Left = 769
    Top = 129
    Width = 12
    Height = 327
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 3
  end
  object Panel6: TPanel
    Left = 9
    Top = 129
    Width = 760
    Height = 327
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 4
    object PageControl1: TPageControl
      Left = 0
      Top = 0
      Width = 760
      Height = 327
      ActivePage = TabSheet2
      Align = alClient
      TabIndex = 0
      TabOrder = 0
      object TabSheet2: TTabSheet
        Caption = #1055#1088#1086#1090#1086#1082#1086#1083
        ImageIndex = 1
        object RichEdit1: TRichEdit
          Left = 0
          Top = 0
          Width = 752
          Height = 299
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
    Top = 456
    Width = 781
    Height = 97
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 5
    object LabelNameTable: TLabel
      Left = 8
      Top = 41
      Width = 77
      Height = 20
      Caption = #1090#1072#1073#1083#1080#1094#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object LabelZagrIsm: TLabel
      Left = 224
      Top = 64
      Width = 194
      Height = 20
      Caption = #1042#1099#1075#1088#1091#1078#1077#1085#1086' '#1080#1079#1084#1077#1085#1077#1085#1080#1081':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object LabelTotalIsm: TLabel
      Left = 8
      Top = 64
      Width = 194
      Height = 20
      Caption = #1042#1099#1075#1088#1091#1078#1077#1085#1086' '#1080#1079#1084#1077#1085#1077#1085#1080#1081':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ProgressBar1: TProgressBar
      Left = 8
      Top = 16
      Width = 761
      Height = 17
      Min = 0
      Max = 100
      Smooth = True
      Step = 1
      TabOrder = 0
    end
    object ButtonVigr: TButton
      Left = 608
      Top = 40
      Width = 75
      Height = 25
      Caption = #1042#1099#1075#1088#1091#1079#1080#1090#1100
      TabOrder = 1
      OnClick = ButtonVigrClick
    end
    object ButtonClose: TButton
      Left = 688
      Top = 40
      Width = 75
      Height = 25
      Caption = #1047#1072#1082#1088#1099#1090#1100
      TabOrder = 2
      OnClick = ButtonCloseClick
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 544
  end
  object IBQ: TIBQuery
    Database = DM.IBData
    Transaction = IBTr1
    BufferChunks = 1000
    CachedUpdates = False
    Left = 312
    Top = 56
  end
  object IBTr1: TIBTransaction
    Active = False
    DefaultDatabase = DM.IBData
    Params.Strings = (
      'read_committed'
      'rec_version'
      'nowait'
      'read')
    AutoStopAction = saNone
    Left = 352
    Top = 56
  end
  object IBQ2: TIBQuery
    Database = DM.IBData
    Transaction = IBTr2
    BufferChunks = 1000
    CachedUpdates = False
    Left = 464
    Top = 56
  end
  object IBTr2: TIBTransaction
    Active = False
    DefaultDatabase = DM.IBData
    Params.Strings = (
      'read_committed'
      'rec_version'
      'nowait'
      'read')
    AutoStopAction = saNone
    Left = 496
    Top = 56
  end
end
