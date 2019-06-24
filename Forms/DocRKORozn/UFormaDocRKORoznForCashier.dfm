object FormaDocRKORoznForCashier: TFormaDocRKORoznForCashier
  Left = 434
  Top = 122
  Caption = #1056#1072#1089#1093#1086#1076' '#1085#1072#1083'.'
  ClientHeight = 517
  ClientWidth = 551
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
  PixelsPerInch = 120
  TextHeight = 16
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 551
    Height = 517
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 0
    object Label2: TLabel
      Left = 304
      Top = 170
      Width = 28
      Height = 26
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1086#1090' '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label12: TLabel
      Left = 20
      Top = 85
      Width = 66
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1060#1080#1088#1084#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -18
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label14: TLabel
      Left = 14
      Top = 223
      Width = 111
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -18
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label15: TLabel
      Left = 39
      Top = 108
      Width = 45
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1050#1050#1052':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -18
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 10
      Top = 148
      Width = 148
      Height = 26
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1056#1072#1089#1093#1086#1076' '#1085#1072#1083'. '#8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 20
      Top = 289
      Width = 48
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1042#1099#1076#1072#1090#1100
    end
    object Label5: TLabel
      Left = 18
      Top = 325
      Width = 76
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1054#1089#1085#1086#1074#1072#1085#1080#1077':'
    end
    object Label6: TLabel
      Left = 10
      Top = 359
      Width = 86
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077':'
    end
    object Label7: TLabel
      Left = 309
      Top = 406
      Width = 63
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1091#1084#1084#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -18
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object ProsmotrLabel: TLabel
      Left = 394
      Top = 492
      Width = 155
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1090#1086#1083#1100#1082#1086' '#1087#1088#1086#1089#1084#1086#1090#1088
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -18
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object DBTextFNameUser: TDBText
      Left = 0
      Top = 492
      Width = 164
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      AutoSize = True
      DataField = 'FNAME_USER'
      DataSource = DMDocRKORozn.DataSourceDocAll
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -18
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object NameBaseDBText: TDBText
      Left = 208
      Top = 50
      Width = 314
      Height = 19
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Alignment = taRightJustify
      DataField = 'NAME_SINFBASE_OBMEN'
      DataSource = DMDocRKORozn.DataSourceDocAll
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label9: TLabel
      Left = 11
      Top = 384
      Width = 68
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1054#1087#1077#1088#1072#1094#1080#1103':'
    end
    object Label8: TLabel
      Left = 18
      Top = 250
      Width = 58
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1044#1086#1075#1086#1074#1086#1088':'
    end
    object CoolBar1: TCoolBar
      Left = 0
      Top = 0
      Width = 551
      Height = 43
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Bands = <
        item
          Control = ToolBar1
          ImageIndex = -1
          Width = 545
        end>
      object ToolBar1: TToolBar
        Left = 11
        Top = 0
        Width = 536
        Height = 25
        Caption = 'ToolBar1'
        Images = DM.ImageList1
        TabOrder = 0
        object ToolButtonPrintDoc: TToolButton
          Left = 0
          Top = 0
          Hint = #1055#1077#1095#1072#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090#1072
          Caption = 'ToolButtonPrintDoc'
          ImageIndex = 43
          ParentShowHint = False
          ShowHint = True
          OnClick = ToolButtonPrintDocClick
        end
        object ToolButtonPrintDocOnFR: TToolButton
          Left = 23
          Top = 0
          Hint = #1055#1077#1095#1072#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090#1072' '#1085#1072' '#1060#1056
          Caption = 'ToolButtonPrintDocOnFR'
          ImageIndex = 44
          ParentShowHint = False
          ShowHint = True
          OnClick = ToolButtonPrintDocOnFRClick
        end
      end
    end
    object cxButtonPrint: TcxButton
      Left = 49
      Top = 454
      Width = 93
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionPrint
      TabOrder = 1
    end
    object cxButtonSave: TcxButton
      Left = 149
      Top = 454
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionSave
      TabOrder = 2
    end
    object cxButtonDvReg: TcxButton
      Left = 249
      Top = 454
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionDvReg
      TabOrder = 3
    end
    object cxButtonOK: TcxButton
      Left = 350
      Top = 454
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionOK
      TabOrder = 4
    end
    object cxButtonClose: TcxButton
      Left = 449
      Top = 454
      Width = 93
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      TabOrder = 5
    end
    object OperationComboBox: TcxComboBox
      Left = 11
      Top = 404
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Properties.DropDownListStyle = lsFixedList
      Properties.Items.Strings = (
        #1055#1088#1086#1095#1077#1077
        #1056#1072#1089#1095#1077#1090#1099' '#1089' '#1082#1086#1085#1090#1088#1072#1075#1077#1085#1090#1072#1084#1080
        #1042#1099#1087#1083#1072#1090#1072
        #1056#1086#1079#1085#1080#1095#1085#1099#1081' '#1074#1086#1079#1074#1088#1072#1090
        #1042#1099#1087#1083#1072#1090#1072' '#1079#1072' '#1074#1086#1079#1074#1088#1072#1097#1077#1085#1085#1099#1081' '#1082#1088#1077#1076#1080#1090)
      Properties.OnChange = OperationComboBoxPropertiesChange
      TabOrder = 6
      Width = 238
    end
    object SumDoccxDBCalcEdit: TcxDBCalcEdit
      Left = 373
      Top = 404
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'SUMDOC'
      DataBinding.DataSource = DMDocRKORozn.DataSourceDocAll
      TabOrder = 7
      Width = 149
    end
    object PrimcxDBTextEdit: TcxDBTextEdit
      Left = 118
      Top = 354
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'PRIM_DRKOROZN'
      DataBinding.DataSource = DMDocRKORozn.DataSourceDoc
      TabOrder = 8
      Width = 405
    end
    object OsncxDBTextEdit: TcxDBTextEdit
      Left = 118
      Top = 321
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'OSN_DRKOROZN'
      DataBinding.DataSource = DMDocRKORozn.DataSourceDoc
      TabOrder = 9
      Width = 405
    end
    object VidatcxDBTextEdit: TcxDBTextEdit
      Left = 118
      Top = 286
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'VIDAT_DRKOROZN'
      DataBinding.DataSource = DMDocRKORozn.DataSourceDoc
      TabOrder = 10
      Width = 405
    end
    object NameDogovorcxDBButtonEdit: TcxDBButtonEdit
      Left = 118
      Top = 252
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAME_SDOG'
      DataBinding.DataSource = DMDocRKORozn.DataSourceDocAll
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameDogovorcxDBButtonEditPropertiesButtonClick
      TabOrder = 11
      Width = 404
    end
    object NameKlientcxDBButtonEdit: TcxDBButtonEdit
      Left = 118
      Top = 217
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAMEKLIENT'
      DataBinding.DataSource = DMDocRKORozn.DataSourceDocAll
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.OnButtonClick = NameKlientcxDBButtonEditPropertiesButtonClick
      TabOrder = 12
      Width = 404
    end
    object NumDoccxDBTextEdit: TcxDBTextEdit
      Left = 191
      Top = 176
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NUMDOC'
      DataBinding.DataSource = DMDocRKORozn.DataSourceDocAll
      TabOrder = 14
      Width = 105
    end
    object PosDoccxDBDateEdit: TcxDBDateEdit
      Left = 340
      Top = 176
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'POSDOC'
      DataBinding.DataSource = DMDocRKORozn.DataSourceDocAll
      Properties.Kind = ckDateTime
      TabOrder = 15
      Width = 187
    end
    object NameKKMcxDBTextEdit: TcxDBTextEdit
      Left = 118
      Top = 116
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAMEKKM'
      DataBinding.DataSource = DMDocRKORozn.DataSourceDoc
      TabOrder = 16
      Width = 404
    end
    object NameFirmcxDBTextEdit: TcxDBTextEdit
      Left = 118
      Top = 81
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAMEFIRM'
      DataBinding.DataSource = DMDocRKORozn.DataSourceDocAll
      TabOrder = 17
      Width = 404
    end
    object PrefiksNumcxDBTextEdit: TcxDBTextEdit
      Left = 38
      Top = 176
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'PREFIKS_NUM_GALLDOC'
      TabOrder = 13
      Width = 145
    end
  end
  object ActionList1: TActionList
    Images = DM.ImageList1
    Left = 336
    Top = 144
    object OpenHelp: TAction
      Caption = 'OpenHelp'
      ShortCut = 112
      OnExecute = OpenHelpExecute
    end
    object ActionClose: TAction
      Caption = #1047#1072#1082#1088#1099#1090#1100
      ImageIndex = 53
      OnExecute = ActionCloseExecute
    end
    object ActionOK: TAction
      Caption = #1054#1050
      ImageIndex = 54
      OnExecute = ActionOKExecute
    end
    object ActionDvReg: TAction
      Caption = #1055#1088#1086#1074#1077#1089#1090#1080
      ImageIndex = 56
      OnExecute = ActionDvRegExecute
    end
    object ActionSave: TAction
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      ImageIndex = 55
      OnExecute = ActionSaveExecute
    end
    object ActionPrint: TAction
      Caption = #1055#1077#1095#1072#1090#1100
      ImageIndex = 43
      OnExecute = ActionPrintExecute
    end
  end
end
