object FormaElementaGurPlat: TFormaElementaGurPlat
  Left = 466
  Top = 206
  Caption = #1055#1083#1072#1090#1077#1078
  ClientHeight = 551
  ClientWidth = 352
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 120
  TextHeight = 20
  object Label4: TLabel
    Left = 199
    Top = 194
    Width = 38
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1054#1044':'
  end
  object Label5: TLabel
    Left = 9
    Top = 234
    Width = 137
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1086#1084#1077#1088' '#1090#1077#1083#1077#1092#1086#1085#1072':'
  end
  object Label6: TLabel
    Left = 9
    Top = 154
    Width = 138
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1086#1084#1077#1088' '#1082#1074#1080#1090#1072#1085#1094#1080#1080':'
  end
  object Label7: TLabel
    Left = 69
    Top = 274
    Width = 53
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1057#1091#1084#1084#1072':'
  end
  object Label1: TLabel
    Left = 33
    Top = 397
    Width = 51
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1040#1074#1090#1086#1088':'
  end
  object Label2: TLabel
    Left = 19
    Top = 83
    Width = 119
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1086#1076' '#1086#1087#1077#1088#1072#1090#1086#1088#1072':'
  end
  object Label3: TLabel
    Left = 19
    Top = 354
    Width = 118
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1057#1091#1084#1084#1072' '#1082#1083#1080#1077#1085#1090#1091':'
  end
  object Label8: TLabel
    Left = 9
    Top = 314
    Width = 145
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1055#1088#1086#1094#1077#1085#1090' '#1082#1086#1084#1080#1089#1089#1080#1080':'
  end
  object Label9: TLabel
    Left = 17
    Top = 49
    Width = 79
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1054#1087#1077#1088#1072#1090#1086#1088':'
  end
  object cxButtonOK: TcxButton
    Left = 137
    Top = 511
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionOK
    TabOrder = 0
  end
  object cxButtonClose: TcxButton
    Left = 239
    Top = 511
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 1
  end
  object OutcxDBCheckBox: TcxDBCheckBox
    Left = -1
    Top = 464
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1074#1099#1075#1088#1091#1078#1077#1085
    DataBinding.DataField = 'OUT_GURNALPLAT'
    DataBinding.DataSource = DMGurPlat.DataSourceElement
    Properties.ValueChecked = 1
    Properties.ValueUnchecked = 0
    TabOrder = 2
    Width = 151
  end
  object NameKlientcxDBButtonEdit: TcxDBButtonEdit
    Left = 104
    Top = 430
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAMEKLIENT'
    DataBinding.DataSource = DMGurPlat.DataSourceElement
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameKlientcxDBButtonEditPropertiesButtonClick
    TabOrder = 3
    Width = 220
  end
  object NameUsercxDBButtonEdit: TcxDBButtonEdit
    Left = 103
    Top = 393
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_USER'
    DataBinding.DataSource = DMGurPlat.DataSourceElement
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    TabOrder = 4
    Width = 220
  end
  object SummKlientcxDBCalcEdit: TcxDBCalcEdit
    Left = 173
    Top = 355
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'SUMKL_GURNALPLAT'
    DataBinding.DataSource = DMGurPlat.DataSourceElement
    TabOrder = 5
    Width = 151
  end
  object ProcentcxDBCalcEdit: TcxDBCalcEdit
    Left = 173
    Top = 318
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'PROCENT_COMMISSION_GURNALPLAT'
    DataBinding.DataSource = DMGurPlat.DataSourceElement
    TabOrder = 6
    Width = 151
  end
  object SumcxDBCalcEdit: TcxDBCalcEdit
    Left = 172
    Top = 277
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'SUM_GURNALPLAT'
    DataBinding.DataSource = DMGurPlat.DataSourceElement
    TabOrder = 7
    Width = 151
  end
  object NumTelcxDBTextEdit: TcxDBTextEdit
    Left = 173
    Top = 227
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NUMTEL_GURNALPLAT'
    DataBinding.DataSource = DMGurPlat.DataSourceElement
    TabOrder = 8
    Width = 151
  end
  object CodeTelcxDBTextEdit: TcxDBTextEdit
    Left = 245
    Top = 189
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'CODE_GURNALPLAT'
    DataBinding.DataSource = DMGurPlat.DataSourceElement
    TabOrder = 9
    Width = 78
  end
  object NumKvcxDBTextEdit: TcxDBTextEdit
    Left = 165
    Top = 152
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NUMKV_GURNALPLAT'
    DataBinding.DataSource = DMGurPlat.DataSourceElement
    TabOrder = 10
    Width = 152
  end
  object CodeOpercxDBTextEdit: TcxDBTextEdit
    Left = 172
    Top = 114
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'CODOPER_GURNALPLAT'
    DataBinding.DataSource = DMGurPlat.DataSourceElement
    TabOrder = 11
    Width = 151
  end
  object PoscxDBDateEdit: TcxDBDateEdit
    Left = 70
    Top = 10
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'POS_GURNALPLAT'
    DataBinding.DataSource = DMGurPlat.DataSourceElement
    Properties.Kind = ckDateTime
    TabOrder = 12
    Width = 254
  end
  object cxLabel1: TcxLabel
    Left = 19
    Top = 434
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1083#1080#1077#1085#1090':'
  end
  object NameCodeTelcxDBButtonEdit: TcxDBButtonEdit
    Left = 104
    Top = 46
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_CODETEL'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameCodeTelcxDBButtonEditPropertiesButtonClick
    TabOrder = 14
    Width = 220
  end
  object CodeOperatorcxDBLabel: TcxDBLabel
    Left = 196
    Top = 81
    DataBinding.DataField = 'CODOPER_CODETEL'
    Height = 21
    Width = 121
  end
  object ActionList1: TActionList
    Images = DM.ImageList1
    Left = 24
    Top = 16
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
  end
end
