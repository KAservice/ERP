object FormaDocRecKDR: TFormaDocRecKDR
  Left = 23
  Top = 18
  Caption = #1047#1072#1087#1080#1089#1100' '#1082#1085#1080#1075#1080' '#1076#1086#1093#1086#1076#1086#1074' '#1080' '#1088#1072#1089#1093#1086#1076#1086#1074
  ClientHeight = 281
  ClientWidth = 460
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
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 460
    Height = 281
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 96
      Top = 72
      Width = 317
      Height = 24
      Caption = #1047#1072#1087#1080#1089#1100' '#1082#1085#1080#1075#1080' '#1076#1086#1093#1086#1076#1086#1074' '#1080' '#1088#1072#1089#1093#1086#1076#1086#1074' '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 264
      Top = 104
      Width = 26
      Height = 24
      Caption = #1086#1090' '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label12: TLabel
      Left = 24
      Top = 37
      Width = 47
      Height = 16
      Caption = #1060#1080#1088#1084#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 112
      Top = 104
      Width = 25
      Height = 24
      Caption = ' '#8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object DBTextFNameUser: TDBText
      Left = 0
      Top = 256
      Width = 119
      Height = 16
      AutoSize = True
      DataField = 'FNAME_USER'
      DataSource = DMDocPKO.DataSourceDocAll
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object NameBaseDBText: TDBText
      Left = 140
      Top = 6
      Width = 269
      Height = 15
      Alignment = taRightJustify
      DataField = 'NAME_SINFBASE_OBMEN'
      DataSource = DMDocPKO.DataSourceDocAll
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ProsmotrLabel: TLabel
      Left = 336
      Top = 256
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
    object Label5: TLabel
      Left = 16
      Top = 136
      Width = 53
      Height = 13
      Caption = #1054#1087#1077#1088#1072#1094#1080#1103':'
      FocusControl = OperationDBEdit
    end
    object Label6: TLabel
      Left = 56
      Top = 192
      Width = 75
      Height = 13
      Caption = #1057#1091#1084#1084#1072' '#1076#1086#1093#1086#1076#1072':'
      FocusControl = DohodDBEdit
    end
    object Label7: TLabel
      Left = 272
      Top = 192
      Width = 81
      Height = 13
      Caption = #1057#1091#1084#1084#1072' '#1088#1072#1089#1093#1086#1076#1072':'
      FocusControl = RashodDBEdit
    end
    object NumDoc: TDBEdit
      Left = 144
      Top = 104
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
      TabOrder = 0
    end
    object PosDoc: TDateTimePicker
      Left = 288
      Top = 104
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
      TabOrder = 1
      OnChange = PosDocChange
    end
    object ButtonEditFirm: TButton
      Left = 428
      Top = 32
      Width = 21
      Height = 21
      Caption = '...'
      TabOrder = 2
      OnClick = ButtonEditFirmClick
    end
    object ButtonProv: TButton
      Left = 208
      Top = 224
      Width = 75
      Height = 25
      Caption = #1055#1088#1086#1074#1077#1089#1090#1080
      TabOrder = 3
      OnClick = ButtonProvClick
    end
    object ButtonSave: TButton
      Left = 128
      Top = 224
      Width = 75
      Height = 25
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      TabOrder = 4
      OnClick = ButtonSaveClick
    end
    object ButtonOK: TButton
      Left = 288
      Top = 224
      Width = 75
      Height = 25
      Caption = 'OK'
      TabOrder = 5
      OnClick = ButtonOKClick
    end
    object ButtonClose: TButton
      Left = 368
      Top = 224
      Width = 75
      Height = 25
      Caption = #1047#1072#1082#1088#1099#1090#1100
      TabOrder = 6
      OnClick = ButtonCloseClick
    end
    object ViborBaseButton: TButton
      Left = 427
      Top = 2
      Width = 22
      Height = 22
      Caption = '...'
      TabOrder = 7
      OnClick = ViborBaseButtonClick
    end
    object BitBtnDateTime: TBitBtn
      Left = 383
      Top = 104
      Width = 23
      Height = 23
      TabOrder = 8
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
    object NameFirmDBEdit: TDBEdit
      Left = 80
      Top = 32
      Width = 348
      Height = 21
      Color = clBtnFace
      DataField = 'NAMEFIRM'
      DataSource = DMDocRecKDR.DataSourceDocAll
      ReadOnly = True
      TabOrder = 9
    end
    object OperationDBEdit: TDBEdit
      Left = 16
      Top = 152
      Width = 433
      Height = 21
      DataField = 'OPERATION_DREC_KDR'
      DataSource = DMDocRecKDR.DataSourceDoc
      TabOrder = 10
    end
    object DohodDBEdit: TDBEdit
      Left = 136
      Top = 184
      Width = 91
      Height = 21
      DataField = 'DOHOD_DREC_KDR'
      DataSource = DMDocRecKDR.DataSourceDoc
      TabOrder = 11
    end
    object RashodDBEdit: TDBEdit
      Left = 360
      Top = 184
      Width = 89
      Height = 21
      DataField = 'RASHOD_DREC_KDR'
      DataSource = DMDocRecKDR.DataSourceDoc
      TabOrder = 12
    end
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
