object FormaElementaSprProducer: TFormaElementaSprProducer
  Left = 413
  Top = 248
  Caption = #1069#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' '#1087#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1080' ('#1087#1086#1089#1090#1072#1074#1097#1080#1082#1080')'
  ClientHeight = 397
  ClientWidth = 619
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
    Left = 20
    Top = 49
    Width = 102
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
  end
  object IdDBText: TDBText
    Left = 433
    Top = 10
    Width = 80
    Height = 21
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataField = 'ID_SPRODUCER'
  end
  object Label2: TLabel
    Left = 404
    Top = 10
    Width = 16
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'ID:'
  end
  object Label3: TLabel
    Left = 20
    Top = 83
    Width = 79
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090':'
  end
  object Label4: TLabel
    Left = 20
    Top = 123
    Width = 107
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1055#1086#1089#1090#1072#1074#1097#1080#1082' '#1047#1048#1055':'
  end
  object Label5: TLabel
    Left = 152
    Top = 171
    Width = 175
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072' '#1086#1073#1085#1086#1074#1083#1077#1085#1072':'
  end
  object Label6: TLabel
    Left = 153
    Top = 201
    Width = 174
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1059#1089#1083#1091#1075#1080' ('#1080#1085#1090#1077#1088#1085#1077#1090' '#1082#1072#1090#1072#1083#1086#1075')'
  end
  object Label7: TLabel
    Left = 20
    Top = 300
    Width = 380
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1058#1080#1087' '#1087#1086#1080#1089#1082#1072' '#1074' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1077' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072' '#1087#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1103':'
  end
  object Label8: TLabel
    Left = 153
    Top = 247
    Width = 235
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1059#1089#1083#1091#1075#1080' ('#1043#1088#1091#1087#1087#1072' '#1080#1085#1090#1077#1088#1085#1077#1090' '#1082#1072#1090#1072#1083#1086#1075#1072'):'
  end
  object cxButtonOK: TcxButton
    Left = 355
    Top = 324
    Width = 92
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionOK
    TabOrder = 0
  end
  object cxButtonClose: TcxButton
    Left = 455
    Top = 324
    Width = 92
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 1
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 153
    Top = 46
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_SPRODUCER'
    TabOrder = 2
    OnKeyDown = NamecxDBTextEditKeyDown
    Width = 396
  end
  object NameKlientcxDBButtonEdit: TcxDBButtonEdit
    Left = 152
    Top = 80
    DataBinding.DataField = 'NAMEKLIENT'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.OnButtonClick = NameKlientcxDBButtonEditPropertiesButtonClick
    TabOrder = 3
    Width = 399
  end
  object PostZipcxDBButtonEdit: TcxDBButtonEdit
    Left = 152
    Top = 120
    DataBinding.DataField = 'post_zip_name'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.OnButtonClick = PostZipcxDBButtonEditPropertiesButtonClick
    TabOrder = 4
    Width = 399
  end
  object PosZagrNomcxDBDateEdit: TcxDBDateEdit
    Left = 342
    Top = 168
    DataBinding.DataField = 'POSZAGRNOM_SPRODUCER'
    Properties.Kind = ckDateTime
    TabOrder = 5
    Width = 209
  end
  object UslNameInetCatalogcxDBButtonEdit: TcxDBButtonEdit
    Left = 153
    Top = 224
    DataBinding.DataField = 'NAME_SINETCATALOG'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.OnButtonClick = UslNameInetCatalogcxDBButtonEditPropertiesButtonClick
    TabOrder = 6
    Width = 399
  end
  object UslNameGrpInetcatalogcxDBButtonEdit: TcxDBButtonEdit
    Left = 153
    Top = 270
    DataBinding.DataField = 'NAME_SNOMINETCAT_GRP'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    TabOrder = 7
    Width = 399
  end
  object TypePoiskcxDBImageComboBox: TcxDBImageComboBox
    Left = 20
    Top = 323
    RepositoryItem = DM.cxEditRepository1ImageComboBoxTypePoiskSprNomProducer
    DataBinding.DataField = 'TYPE_POISK_SPRNOM_SPRODUCER'
    Properties.Items = <>
    TabOrder = 8
    Width = 237
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 104
    Top = 96
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
