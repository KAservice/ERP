object FormaElementaTableExtPrintForm: TFormaElementaTableExtPrintForm
  Left = 443
  Top = 117
  Caption = #1042#1085#1077#1096#1085#1103#1103' '#1087#1077#1095#1072#1090#1085#1072#1103' '#1092#1086#1088#1084#1072
  ClientHeight = 288
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
  object Label1: TLabel
    Left = 3
    Top = 111
    Width = 102
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
  end
  object Label3: TLabel
    Left = 58
    Top = 145
    Width = 38
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1060#1072#1081#1083':'
  end
  object Label4: TLabel
    Left = 47
    Top = 43
    Width = 52
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1054#1073#1098#1077#1082#1090':'
  end
  object Label2: TLabel
    Left = 5
    Top = 80
    Width = 103
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1054#1073#1098#1077#1082#1090' (ProgId):'
  end
  object cxButtonOK: TcxButton
    Left = 327
    Top = 240
    Width = 93
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionOK
    TabOrder = 4
  end
  object cxButtonClose: TcxButton
    Left = 427
    Top = 240
    Width = 92
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 5
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 108
    Top = 108
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_EXTPRINT_FORM'
    TabOrder = 3
    Width = 395
  end
  object TypeModulecxDBImageComboBox: TcxDBImageComboBox
    Left = 311
    Top = 6
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    RepositoryItem = DM.cxEditRepository1ImageComboBoxTypeExtModule
    DataBinding.DataField = 'TYPEMODULE_EXTPRINT_FORM'
    Properties.Items = <>
    TabOrder = 0
    Width = 192
  end
  object cxLabel1: TcxLabel
    Left = 213
    Top = 10
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1058#1080#1087' '#1084#1086#1076#1091#1083#1103':'
  end
  object ObjectcxDBImageComboBox: TcxDBImageComboBox
    Left = 108
    Top = 39
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    RepositoryItem = DM.cxEditRepository1ImageComboBoxObjectExtModule
    DataBinding.DataField = 'OBJECT_EXTPRINT_FORM'
    Properties.Items = <>
    TabOrder = 1
    Width = 395
  end
  object cxButtonFileInBlob: TcxButton
    Left = 203
    Top = 240
    Width = 117
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1048#1079' '#1092#1072#1081#1083#1072' '#1074' '#1073#1072#1079#1091
    TabOrder = 7
    OnClick = cxButtonFileInBlobClick
  end
  object cxDBRadioGroupResidence: TcxDBRadioGroup
    Left = 108
    Top = 175
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1058#1080#1087' '#1093#1088#1072#1085#1077#1085#1080#1103' '#1084#1086#1076#1091#1083#1103
    DataBinding.DataField = 'RESIDENCE_EXTPRINT_FORM'
    Properties.Columns = 2
    Properties.Items = <
      item
        Caption = #1042' '#1092#1072#1081#1083#1077
        Value = 0
      end
      item
        Caption = #1042' '#1073#1072#1079#1077
        Value = 1
      end>
    TabOrder = 8
    Height = 45
    Width = 395
  end
  object FileNamecxDBButtonEdit: TcxDBButtonEdit
    Left = 108
    Top = 142
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'FILE_NAME_EXTPRINT_FORM'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.OnButtonClick = FileNamecxDBButtonEditPropertiesButtonClick
    TabOrder = 9
    Width = 395
  end
  object cxButtonBlobInFile: TcxButton
    Left = 79
    Top = 240
    Width = 117
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1048#1079' '#1073#1072#1079#1099' '#1074' '#1092#1072#1081#1083
    TabOrder = 10
    OnClick = cxButtonBlobInFileClick
  end
  object NameModulecxDBButtonEdit: TcxDBButtonEdit
    Left = 108
    Top = 77
    DataBinding.DataField = 'NAME_PROGRAM_MODULE'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameModulecxDBButtonEditPropertiesButtonClick
    TabOrder = 2
    Width = 395
  end
  object OpenDialog1: TOpenDialog
    Left = 64
    Top = 175
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 184
    Top = 96
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
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
  object SaveDialog1: TSaveDialog
    Left = 24
    Top = 240
  end
end
