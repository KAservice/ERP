object FormaDocRealRest: TFormaDocRealRest
  Left = 225
  Top = 155
  Caption = #1040#1082#1090' '#1088#1077#1072#1083#1080#1079#1072#1094#1080#1080' '#1088#1077#1089#1090#1086#1088#1072#1085#1072
  ClientHeight = 532
  ClientWidth = 752
  Color = clBtnFace
  Constraints.MinWidth = 760
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
  object Panel2: TPanel
    Left = 0
    Top = 217
    Width = 15
    Height = 206
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 0
  end
  object Panel3: TPanel
    Left = 0
    Top = 423
    Width = 752
    Height = 109
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object FSummaCheck: TLabel
      Left = 520
      Top = 16
      Width = 70
      Height = 24
      Caption = #1057#1091#1084#1084#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBTextFNameUser: TDBText
      Left = 8
      Top = 88
      Width = 119
      Height = 16
      AutoSize = True
      DataField = 'NAME_USER'
      DataSource = DMDocRealRest.DataSourceDocAll
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object SumDocDBText: TDBText
      Left = 592
      Top = 16
      Width = 135
      Height = 24
      AutoSize = True
      DataField = 'SUMDOC'
      DataSource = DMDocRealRest.DataSourceDocAll
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object ProsmotrLabel: TLabel
      Left = 8
      Top = 72
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
    object ButtonClose: TButton
      Left = 656
      Top = 68
      Width = 75
      Height = 25
      Caption = #1047#1072#1082#1088#1099#1090#1100
      TabOrder = 0
      OnClick = ButtonCloseClick
    end
    object ButtonSave: TButton
      Left = 464
      Top = 72
      Width = 75
      Height = 25
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      TabOrder = 1
      OnClick = ButtonSaveClick
    end
    object ButtonOK: TButton
      Left = 560
      Top = 72
      Width = 75
      Height = 25
      Caption = 'OK'
      TabOrder = 2
      OnClick = ButtonOKClick
    end
    object ButtonProv: TButton
      Left = 376
      Top = 72
      Width = 75
      Height = 25
      Caption = #1055#1088#1086#1074#1077#1089#1090#1080
      TabOrder = 3
      OnClick = ButtonProvClick
    end
    object ButtonPrintDoc: TButton
      Left = 288
      Top = 72
      Width = 75
      Height = 25
      Caption = #1055#1077#1095#1072#1090#1100
      TabOrder = 4
      OnClick = ButtonPrintDocClick
    end
  end
  object Panel4: TPanel
    Left = 743
    Top = 217
    Width = 9
    Height = 206
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 2
  end
  object DBGrid1: TDBGrid
    Left = 15
    Top = 217
    Width = 728
    Height = 206
    Align = alClient
    DataSource = DMDocRealRest.DataSourceDocT
    Options = [dgEditing, dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgConfirmDelete, dgCancelOnExit]
    TabOrder = 3
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    OnEditButtonClick = DBGrid1EditButtonClick
    OnTitleClick = DBGrid1TitleClick
    Columns = <
      item
        Expanded = False
        FieldName = 'RECNO'
        Title.Caption = #8470
        Width = 34
        Visible = True
      end
      item
        ButtonStyle = cbsEllipsis
        Expanded = False
        FieldName = 'NAMENOM'
        Title.Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
        Width = 292
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'KOL_REALRESTT'
        Title.Caption = #1050#1086#1083
        Width = 52
        Visible = True
      end
      item
        ButtonStyle = cbsEllipsis
        Expanded = False
        FieldName = 'NAMEED'
        Title.Caption = #1045#1076#1080#1085#1080#1094#1072
        Width = 81
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'KF_REALRESTT'
        Title.Caption = #1050#1086#1101#1092#1092'.'
        Width = 65
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'PRICE_REALRESTT'
        Title.Caption = #1062#1077#1085#1072
        Width = 77
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'SUM_REALRESTT'
        Title.Caption = #1057#1091#1084#1084#1072
        Width = 83
        Visible = True
      end>
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 752
    Height = 217
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 4
    object Label1: TLabel
      Left = 8
      Top = 72
      Width = 233
      Height = 29
      Caption = #1040#1082#1090' '#1088#1077#1072#1083#1080#1079#1072#1094#1080#1080' '#8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -24
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 384
      Top = 64
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
    object Label7: TLabel
      Left = 48
      Top = 176
      Width = 66
      Height = 13
      Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077':'
    end
    object Label12: TLabel
      Left = 8
      Top = 45
      Width = 54
      Height = 16
      Caption = #1060#1080#1088#1084#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label13: TLabel
      Left = 456
      Top = 45
      Width = 50
      Height = 16
      Caption = #1057#1082#1083#1072#1076':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label14: TLabel
      Left = 24
      Top = 136
      Width = 94
      Height = 16
      Caption = #1055#1086#1082#1091#1087#1072#1090#1077#1083#1100':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label3: TLabel
      Left = 472
      Top = 128
      Width = 43
      Height = 13
      Caption = #1058#1080#1087' '#1094#1077#1085':'
    end
    object PrimChk: TDBEdit
      Left = 136
      Top = 168
      Width = 345
      Height = 21
      DataField = 'PRIM_REALREST'
      DataSource = DMDocRealRest.DataSourceDoc
      TabOrder = 0
    end
    object NumDoc: TDBEdit
      Left = 256
      Top = 72
      Width = 113
      Height = 24
      DataField = 'NUMDOC'
      DataSource = DMDocCheck.DataSourceDocAll
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
    end
    object DateDoc: TDateTimePicker
      Left = 424
      Top = 72
      Width = 97
      Height = 24
      Date = 38458.536769548600000000
      Time = 38458.536769548600000000
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnChange = DateDocChange
    end
    object ToolBar2: TToolBar
      Left = 0
      Top = 0
      Width = 752
      Height = 33
      Color = clBtnFace
      EdgeBorders = [ebTop, ebBottom]
      Images = DM.ImageList1
      ParentColor = False
      TabOrder = 3
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
        Hint = #1053#1086#1074#1072#1103' '#1089#1090#1088#1086#1082#1072
        Caption = 'ToolButtonInsert'
        ImageIndex = 0
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonInsertClick
      end
      object ToolButtonDelete: TToolButton
        Left = 40
        Top = 0
        Hint = #1059#1076#1072#1083#1080#1090#1100' '#1089#1090#1088#1086#1082#1091
        Caption = 'ToolButtonDelete'
        ImageIndex = 2
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonDeleteClick
      end
      object ToolButton2: TToolButton
        Left = 63
        Top = 0
        Width = 170
        Caption = 'ToolButton2'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object NameBaseDBText: TDBText
        Left = 233
        Top = 0
        Width = 472
        Height = 22
        Alignment = taRightJustify
        DataField = 'NAME_SINFBASE_OBMEN'
        DataSource = DMDocRealRest.DataSourceDocAll
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object ToolButton3: TToolButton
        Left = 705
        Top = 0
        Width = 8
        Caption = 'ToolButton3'
        ImageIndex = 4
        Style = tbsSeparator
      end
      object ViborBaseButton: TButton
        Left = 713
        Top = 0
        Width = 22
        Height = 22
        Caption = '...'
        TabOrder = 0
        OnClick = ViborBaseButtonClick
      end
    end
    object EditFirm: TEdit
      Left = 64
      Top = 40
      Width = 193
      Height = 24
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      ReadOnly = True
      TabOrder = 4
      Text = 'EditFirm'
    end
    object EditSklad: TEdit
      Left = 512
      Top = 40
      Width = 201
      Height = 24
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      ReadOnly = True
      TabOrder = 5
      Text = 'EditSklad'
    end
    object EditKlient: TEdit
      Left = 136
      Top = 128
      Width = 201
      Height = 24
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      ReadOnly = True
      TabOrder = 6
      Text = 'EditKlient'
    end
    object ButtonEditFirm: TButton
      Left = 256
      Top = 40
      Width = 25
      Height = 25
      Caption = '...'
      TabOrder = 7
      OnClick = ButtonEditFirmClick
    end
    object ButtonEditSklad: TButton
      Left = 712
      Top = 40
      Width = 27
      Height = 25
      Caption = '...'
      TabOrder = 8
      OnClick = ButtonEditSkladClick
    end
    object ButtonEditKlient: TButton
      Left = 336
      Top = 128
      Width = 25
      Height = 25
      Caption = '...'
      TabOrder = 9
      OnClick = ButtonEditKlientClick
    end
    object BitBtnDateTime: TBitBtn
      Left = 520
      Top = 72
      Width = 23
      Height = 23
      TabOrder = 10
      OnClick = BitBtnDateTimeClick
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000120B0000120B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        3333333333FFFFF3333333333000003333333333F77777FFF333333009999900
        3333333777777777FF33330998FFF899033333777333F3777FF33099FFFCFFF9
        903337773337333777F3309FFFFFFFCF9033377333F3337377FF098FF0FFFFFF
        890377F3373F3333377F09FFFF0FFFFFF90377F3F373FFFFF77F09FCFFF90000
        F90377F733377777377F09FFFFFFFFFFF90377F333333333377F098FFFFFFFFF
        890377FF3F33333F3773309FCFFFFFCF9033377F7333F37377F33099FFFCFFF9
        90333777FF37F3377733330998FCF899033333777FF7FF777333333009999900
        3333333777777777333333333000003333333333377777333333}
      NumGlyphs = 2
    end
    object TypePriceComboBox: TComboBox
      Left = 529
      Top = 125
      Width = 206
      Height = 21
      Style = csDropDownList
      ItemHeight = 0
      TabOrder = 11
      TabStop = False
      OnChange = TypePriceComboBoxChange
    end
  end
  object ActionList: TActionList
    Left = 184
    Top = 40
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
      OnExecute = ActionOpenHelpExecute
    end
  end
end
