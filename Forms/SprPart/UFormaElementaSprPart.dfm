object FormaElementaSprPart: TFormaElementaSprPart
  Left = 436
  Top = 105
  Caption = #1069#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1055#1072#1088#1090#1080#1080'"'
  ClientHeight = 393
  ClientWidth = 666
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
  object Label1: TLabel
    Left = 49
    Top = 69
    Width = 28
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1043#1058#1044':'
  end
  object Label2: TLabel
    Left = 452
    Top = 153
    Width = 36
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1062#1077#1085#1072':'
  end
  object Label3: TLabel
    Left = 30
    Top = 108
    Width = 84
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1057#1077#1088#1090#1080#1092#1080#1082#1072#1090':'
  end
  object Label4: TLabel
    Left = 30
    Top = 153
    Width = 98
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1057#1088#1086#1082' '#1075#1086#1076#1085#1086#1089#1090#1080':'
  end
  object NameNom: TDBText
    Left = 148
    Top = 10
    Width = 66
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    AutoSize = True
    DataField = 'NAMENOM'
  end
  object Label5: TLabel
    Left = 10
    Top = 10
    Width = 100
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072':'
  end
  object Label6: TLabel
    Left = 443
    Top = 30
    Width = 77
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1086#1076' '#1087#1072#1088#1090#1080#1080':'
  end
  object CodePart: TDBText
    Left = 551
    Top = 30
    Width = 80
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataField = 'CODEPART'
  end
  object cxButtonOK: TcxButton
    Left = 452
    Top = 335
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
    Left = 551
    Top = 335
    Width = 93
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 5
  end
  object GTDcxDBTextEdit: TcxDBTextEdit
    Left = 148
    Top = 62
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'GTDPART'
    TabOrder = 0
    OnKeyDown = GTDcxDBTextEditKeyDown
    Width = 508
  end
  object SertcxDBTextEdit: TcxDBTextEdit
    Left = 148
    Top = 105
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'SERTPART'
    TabOrder = 2
    OnKeyDown = SertcxDBTextEditKeyDown
    Width = 268
  end
  object PricecxDBCalcEdit: TcxDBCalcEdit
    Left = 507
    Top = 142
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'PRICEZPART'
    TabOrder = 3
    OnKeyDown = PricecxDBCalcEditKeyDown
    Width = 149
  end
  object cxGroupBox1: TcxGroupBox
    Left = 30
    Top = 176
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1044#1086#1087#1086#1083#1085#1080#1090#1077#1083#1100#1085#1072#1103' '#1080#1085#1092#1086#1088#1084#1072#1094#1080#1103':'
    TabOrder = 6
    Height = 140
    Width = 626
    object FirmPart: TDBText
      Left = 118
      Top = 30
      Width = 50
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      AutoSize = True
      DataField = 'NAMEFIRM'
    end
    object Label7: TLabel
      Left = 20
      Top = 30
      Width = 47
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1060#1080#1088#1084#1072':'
    end
    object Label8: TLabel
      Left = 20
      Top = 59
      Width = 75
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1086#1089#1090#1072#1074#1097#1080#1082':'
    end
    object DocPart: TDBText
      Left = 187
      Top = 89
      Width = 49
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      AutoSize = True
      DataField = 'DOCPART'
    end
    object Label9: TLabel
      Left = 20
      Top = 89
      Width = 131
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1044#1086#1082#1091#1084#1077#1085#1090' '#1087#1086#1089#1090#1072#1074#1082#1080':'
    end
    object NameKlientcxDBButtonEdit: TcxDBButtonEdit
      Left = 118
      Top = 55
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
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameKlientcxDBButtonEditPropertiesButtonClick
      TabOrder = 0
      Width = 313
    end
  end
  object SrokGodncxDBDateEdit: TcxDBDateEdit
    Left = 148
    Top = 142
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'SRGODNPART'
    Properties.Kind = ckDateTime
    TabOrder = 1
    Width = 268
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 224
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
  end
end
