object FormaElementaSprProgramModule: TFormaElementaSprProgramModule
  Left = 385
  Top = 51
  Caption = #1069#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1055#1088#1086#1075#1088#1072#1084#1084#1085#1099#1077' '#1084#1086#1076#1091#1083#1080'"'
  ClientHeight = 338
  ClientWidth = 550
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
    Left = 9
    Top = 40
    Width = 102
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
  end
  object Label2: TLabel
    Left = 68
    Top = 72
    Width = 36
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'GUID:'
  end
  object Label3: TLabel
    Left = 51
    Top = 104
    Width = 53
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1052#1086#1076#1091#1083#1100':'
  end
  object Label4: TLabel
    Left = 18
    Top = 175
    Width = 87
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1055#1086#1083#1085#1099#1081' '#1087#1091#1090#1100':'
  end
  object Label5: TLabel
    Left = 37
    Top = 205
    Width = 68
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1054#1087#1080#1089#1072#1085#1080#1077':'
  end
  object Label6: TLabel
    Left = 62
    Top = 141
    Width = 43
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'ProgId:'
  end
  object cxButtonOK: TcxButton
    Left = 344
    Top = 298
    Width = 92
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionOK
    TabOrder = 6
  end
  object cxButtonClose: TcxButton
    Left = 444
    Top = 298
    Width = 93
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    Cancel = True
    TabOrder = 7
  end
  object ModulecxDBTextEdit: TcxDBTextEdit
    Left = 112
    Top = 101
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'MODULE_PROGRAM_MODULE'
    TabOrder = 2
    OnKeyPress = ModulecxDBTextEditKeyPress
    Width = 425
  end
  object GuidcxDBTextEdit: TcxDBTextEdit
    Left = 112
    Top = 69
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'GUID_PROGRAM_MODULE'
    TabOrder = 1
    OnKeyPress = GuidcxDBTextEditKeyPress
    Width = 425
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 112
    Top = 37
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_PROGRAM_MODULE'
    TabOrder = 0
    OnKeyPress = NamecxDBTextEditKeyPress
    Width = 425
  end
  object PatchcxDBTextEdit: TcxDBTextEdit
    Left = 112
    Top = 172
    DataBinding.DataField = 'PATCH_PROGRAM_MODULE'
    TabOrder = 4
    OnKeyPress = PatchcxDBTextEditKeyPress
    Width = 425
  end
  object DescrcxDBMemo: TcxDBMemo
    Left = 112
    Top = 202
    DataBinding.DataField = 'DESCR_PROGRAM_MODULE'
    TabOrder = 5
    OnKeyPress = DescrcxDBMemoKeyPress
    Height = 57
    Width = 425
  end
  object ProgIdcxDBTextEdit: TcxDBTextEdit
    Left = 112
    Top = 138
    DataBinding.DataField = 'PROGID_PROGRAM_MODULE'
    TabOrder = 3
    OnKeyPress = ProgIdcxDBTextEditKeyPress
    Width = 425
  end
  object TypeAppliccxDBImageComboBox: TcxDBImageComboBox
    Left = 112
    Top = 265
    RepositoryItem = DM.cxEditRepository1ImageComboBoxTypeApplication
    DataBinding.DataField = 'TYPEMOD_PROGRAM_MODULE'
    Properties.Items = <>
    TabOrder = 8
    Width = 161
  end
  object ActionList: TActionList
    Left = 24
    Top = 208
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
end
