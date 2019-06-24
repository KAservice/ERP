object FormaObmenImport: TFormaObmenImport
  Left = 214
  Top = 128
  Width = 789
  Height = 569
  Caption = #1054#1073#1084#1077#1085' '#1076#1072#1085#1085#1099#1084#1080' '#1089' '#1091#1076#1072#1083#1077#1085#1085#1099#1084#1080' '#1073#1072#1079#1072#1084#1080' ('#1080#1084#1087#1086#1088#1090' '#1076#1072#1085#1085#1099#1093')'
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
      Width = 423
      Height = 20
      Caption = #1054#1073#1084#1077#1085' '#1076#1072#1085#1085#1099#1084#1080' '#1089' '#1091#1076#1072#1083#1077#1085#1085#1099#1084#1080' '#1073#1072#1079#1072#1084#1080' ('#1080#1084#1087#1086#1088#1090' '#1076#1072#1085#1085#1099#1093')'
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
      Top = 72
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
    object LabelPrefiksPriemnik: TLabel
      Left = 520
      Top = 32
      Width = 174
      Height = 24
      Caption = 'LabelPrefiksPriemnik'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabelGID: TLabel
      Left = 520
      Top = 64
      Width = 77
      Height = 24
      Caption = 'LabelGID'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
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
      Left = 520
      Top = 88
      Width = 97
      Height = 17
      Caption = #1074#1077#1089#1090#1080' '#1087#1088#1086#1090#1086#1082#1086#1083
      TabOrder = 2
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 129
    Width = 9
    Height = 329
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 2
  end
  object Panel4: TPanel
    Left = 769
    Top = 129
    Width = 12
    Height = 329
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 3
  end
  object Panel6: TPanel
    Left = 9
    Top = 129
    Width = 760
    Height = 329
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 4
    object PageControl1: TPageControl
      Left = 0
      Top = 0
      Width = 760
      Height = 329
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
          Height = 301
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
    Top = 458
    Width = 781
    Height = 77
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 5
    object LabelZagrIsm: TLabel
      Left = 8
      Top = 56
      Width = 192
      Height = 20
      Caption = #1047#1072#1075#1088#1091#1078#1077#1085#1086' '#1080#1079#1084#1077#1085#1077#1085#1080#1081':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object LabelTotalIsm: TLabel
      Left = 8
      Top = 33
      Width = 151
      Height = 20
      Caption = #1042#1089#1077#1075#1086' '#1080#1079#1084#1077#1085#1077#1085#1080#1081':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ProgressBar1: TProgressBar
      Left = 8
      Top = 8
      Width = 761
      Height = 17
      Min = 0
      Max = 100
      Smooth = True
      Step = 1
      TabOrder = 0
    end
    object ButtonVigr: TButton
      Left = 552
      Top = 40
      Width = 75
      Height = 25
      Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100
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
  object xml: TXMLDocument
    Left = 600
    Top = 8
    DOMVendorDesc = 'MSXML'
  end
  object IBTr: TIBTransaction
    Active = False
    DefaultDatabase = DM.IBData
    Params.Strings = (
      'read_committed'
      'rec_version'
      'nowait')
    AutoStopAction = saNone
    Left = 384
    Top = 104
  end
  object IBQ1: TIBQuery
    Database = DM.IBData
    Transaction = IBTr
    BufferChunks = 1000
    CachedUpdates = False
    Left = 352
    Top = 104
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
    Left = 552
    Top = 112
  end
  object IBQ2: TIBQuery
    Database = DM.IBData
    Transaction = IBTr1
    BufferChunks = 1000
    CachedUpdates = False
    Left = 592
    Top = 112
  end
  object IBQ3: TIBQuery
    Database = DM.IBData
    Transaction = IBTr1
    BufferChunks = 1000
    CachedUpdates = False
    Left = 632
    Top = 112
  end
  object IBQ4: TIBQuery
    Database = DM.IBData
    Transaction = IBTr1
    BufferChunks = 1000
    CachedUpdates = False
    Left = 672
    Top = 112
  end
end
