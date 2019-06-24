object FormaElementaSprDiscountCard: TFormaElementaSprDiscountCard
  Left = 447
  Top = 118
  Caption = #1069#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1050#1072#1088#1090#1099'"'
  ClientHeight = 497
  ClientWidth = 533
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
  object Label3: TLabel
    Left = -1
    Top = 175
    Width = 102
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
  end
  object Label4: TLabel
    Left = 284
    Top = 46
    Width = 70
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1064#1090#1088#1080#1093'-'#1082#1086#1076':'
  end
  object Label1: TLabel
    Left = 314
    Top = 10
    Width = 27
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1086#1076':'
  end
  object Label2: TLabel
    Left = 10
    Top = 251
    Width = 70
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1058#1080#1087' '#1082#1072#1088#1090#1099':'
  end
  object Label6: TLabel
    Left = 10
    Top = 142
    Width = 148
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1057#1088#1086#1082' '#1076#1077#1081#1089#1090#1074#1080#1103' '#1082#1072#1088#1090#1099' '#1089
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label7: TLabel
    Left = 282
    Top = 303
    Width = 76
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1057#1082#1080#1076#1082#1072' (%)::'
  end
  object Label9: TLabel
    Left = 314
    Top = 138
    Width = 16
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1087#1086
  end
  object Label5: TLabel
    Left = 132
    Top = 108
    Width = 79
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090':'
  end
  object Label8: TLabel
    Left = 156
    Top = 407
    Width = 58
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1044#1086#1075#1086#1074#1086#1088':'
  end
  object cxButtonClose: TcxButton
    Left = 416
    Top = 457
    Width = 92
    Height = 30
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 16
  end
  object cxButtonOK: TcxButton
    Left = 314
    Top = 457
    Width = 92
    Height = 30
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionOK
    TabOrder = 15
  end
  object cxButtonSave: TcxButton
    Left = 214
    Top = 457
    Width = 92
    Height = 30
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionSave
    TabOrder = 17
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 103
    Top = 171
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_SDISCOUNT_CARD'
    TabOrder = 8
    OnKeyDown = NamecxDBTextEditKeyDown
    Width = 405
  end
  object ProcentcxDBCalcEdit: TcxDBCalcEdit
    Left = 359
    Top = 300
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'PRSK_SDISCOUNT_CARD'
    TabOrder = 11
    OnKeyDown = ProcentcxDBCalcEditKeyDown
    Width = 149
  end
  object ActcxDBCheckBox1: TcxDBCheckBox
    Left = 9
    Top = 2
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1072#1082#1090#1080#1074#1085#1072
    DataBinding.DataField = 'ACT_SDISCOUNT_CARD'
    Properties.ValueChecked = 1
    Properties.ValueUnchecked = 0
    TabOrder = 0
    OnKeyDown = ActcxDBCheckBox1KeyDown
    Width = 149
  end
  object NachcxDBDateEdit: TcxDBDateEdit
    Left = 158
    Top = 138
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NACH_SDISCOUNT_CARD'
    Properties.Kind = ckDateTime
    TabOrder = 6
    OnKeyDown = NachcxDBDateEditKeyDown
    Width = 148
  end
  object ConcxDBDateEdit: TcxDBDateEdit
    Left = 359
    Top = 138
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'CON_SDISCOUNT_CARD'
    Properties.Kind = ckDateTime
    TabOrder = 7
    OnKeyDown = ConcxDBDateEditKeyDown
    Width = 149
  end
  object CodecxDBTextEdit: TcxDBTextEdit
    Left = 359
    Top = 9
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'CODE_SDISCOUNT_CARD'
    TabOrder = 2
    OnKeyDown = CodecxDBTextEditKeyDown
    Width = 149
  end
  object SHCodecxDBTextEdit: TcxDBTextEdit
    Left = 359
    Top = 42
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'SHCODE_SDISCOUNT_CARD'
    TabOrder = 3
    OnKeyDown = SHCodecxDBTextEditKeyDown
    Width = 149
  end
  object NameKlientcxDBButtonEdit: TcxDBButtonEdit
    Left = 212
    Top = 105
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAMEKLIENT'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ClickKey = 13
    Properties.ReadOnly = True
    Properties.OnButtonClick = cxDBButtonEdit1PropertiesButtonClick
    TabOrder = 5
    Width = 296
  end
  object NameVidcxDBButtonEdit: TcxDBButtonEdit
    Left = 212
    Top = 71
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_SVID_DCARD'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ClickKey = 13
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameVidcxDBButtonEditPropertiesButtonClick
    TabOrder = 4
    Width = 296
  end
  object cxLabel1: TcxLabel
    Left = 174
    Top = 71
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1042#1080#1076':'
  end
  object FlPlatCardcxDBCheckBox: TcxDBCheckBox
    Left = 11
    Top = 341
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1087#1083#1072#1090#1077#1078#1085#1072#1103' '#1082#1072#1088#1090#1072
    DataBinding.DataField = 'FL_PLAT_SDISCOUNT_CARD'
    Properties.ValueChecked = 1
    Properties.ValueUnchecked = 0
    TabOrder = 12
    Width = 149
  end
  object FlDiscontcxDBCheckBox: TcxDBCheckBox
    Left = 10
    Top = 218
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1076#1080#1089#1082#1086#1085#1090#1085#1072#1103' '#1082#1072#1088#1090#1072
    DataBinding.DataField = 'FL_DISC_SDISCOUNT_CARD'
    Properties.ValueChecked = 1
    Properties.ValueUnchecked = 0
    TabOrder = 9
    Width = 149
  end
  object FlCreditcxDBCheckBox: TcxDBCheckBox
    Left = 10
    Top = 374
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1082#1088#1077#1076#1080#1090#1085#1072#1103' '#1082#1072#1088#1090#1072
    DataBinding.DataField = 'FL_CREDIT_SDISCOUNT_CARD'
    Properties.ValueChecked = 1
    Properties.ValueUnchecked = 0
    TabOrder = 13
    Width = 149
  end
  object NameDogovorcxDBButtonEdit: TcxDBButtonEdit
    Left = 222
    Top = 404
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_SDOG'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameDogovorcxDBButtonEditPropertiesButtonClick
    TabOrder = 14
    Width = 286
  end
  object TypeCardcxDBImageComboBox: TcxDBImageComboBox
    Left = 103
    Top = 249
    RepositoryItem = DM.cxEditRepository1ImageComboBoxItem1TypeDiscountCard
    DataBinding.DataField = 'TYPE_SDISCOUNT_CARD'
    Properties.Items = <>
    TabOrder = 10
    Width = 405
  end
  object SinglecxDBCheckBox: TcxDBCheckBox
    Left = 8
    Top = 24
    Caption = #1054#1076#1085#1086#1088#1072#1079#1086#1074#1072#1103
    DataBinding.DataField = 'SINGLE_SDISCOUNT_CARD'
    Properties.ValueChecked = 1
    Properties.ValueUnchecked = 0
    TabOrder = 1
    Width = 121
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 103
    Top = 61
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
      OnExecute = ActionOpenHelpExecute
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
    object ActionSave: TAction
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      ImageIndex = 55
      OnExecute = ActionSaveExecute
    end
  end
end
