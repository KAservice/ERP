object REM_FormaElementaSprProducerRabota: TREM_FormaElementaSprProducerRabota
  Left = 454
  Top = 350
  Caption = #1056#1072#1073#1086#1090#1072' '#1055#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1103
  ClientHeight = 395
  ClientWidth = 492
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
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
  object Label3: TLabel
    Left = 20
    Top = 301
    Width = 100
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072':'
  end
  object Label4: TLabel
    Left = 24
    Top = 108
    Width = 157
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' (English):'
  end
  object Label5: TLabel
    Left = 181
    Top = 164
    Width = 27
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1086#1076':'
  end
  object Label6: TLabel
    Left = 24
    Top = 196
    Width = 59
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1059#1088#1086#1074#1077#1085#1100':'
  end
  object Label7: TLabel
    Left = 20
    Top = 237
    Width = 93
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1058#1080#1087' '#1082#1083#1080#1077#1085#1090#1086#1074':'
  end
  object Label8: TLabel
    Left = 9
    Top = 277
    Width = 108
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1058#1080#1087#1099' '#1091#1089#1090#1088#1086#1081#1089#1090#1074':'
  end
  object cxButtonOK: TcxButton
    Left = 262
    Top = 355
    Width = 92
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionOK
    TabOrder = 1
  end
  object cxButtonClose: TcxButton
    Left = 362
    Top = 355
    Width = 92
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 2
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 20
    Top = 76
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_REM_SPRRABOTA'
    TabOrder = 0
    OnKeyDown = NamecxDBTextEditKeyDown
    Width = 448
  end
  object IdcxDBLabel: TcxDBLabel
    Left = 312
    Top = 16
    DataBinding.DataField = 'ID_REM_SPRRABOTA'
    Height = 21
    Width = 121
  end
  object cxDBButtonEditNAMENOM: TcxDBButtonEdit
    Left = 20
    Top = 324
    DataBinding.DataField = 'NAMENOM'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.OnButtonClick = cxDBButtonEditNAMENOMPropertiesButtonClick
    TabOrder = 4
    Width = 448
  end
  object NameEngcxDBTextEdit: TcxDBTextEdit
    Left = 20
    Top = 132
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_ENG_REM_SPRRABOTA'
    TabOrder = 5
    OnKeyDown = NamecxDBTextEditKeyDown
    Width = 448
  end
  object cxDBTextEditCODE_REM_SPRRABOTA: TcxDBTextEdit
    Left = 216
    Top = 164
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'CODE_REM_SPRRABOTA'
    TabOrder = 6
    OnKeyDown = NamecxDBTextEditKeyDown
    Width = 252
  end
  object cxDBTextEditLEVEL_STR_REM_SPRRABOTA: TcxDBTextEdit
    Left = 216
    Top = 196
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'LEVEL_STR_REM_SPRRABOTA'
    TabOrder = 7
    OnKeyDown = NamecxDBTextEditKeyDown
    Width = 252
  end
  object cxDBImageComboBoxTYPECLIENT_REM_SPRRABOTA: TcxDBImageComboBox
    Left = 136
    Top = 234
    RepositoryItem = DM.cxEditRepository1ImageComboBoxItemTypeKlent
    DataBinding.DataField = 'TYPECLIENT_REM_SPRRABOTA'
    Properties.Items = <>
    TabOrder = 8
    Width = 332
  end
  object cxDBImageComboBoxTYPEPRODUCT_REM_SPRRABOTA: TcxDBImageComboBox
    Left = 136
    Top = 280
    RepositoryItem = DM.cxEditRepository1ImageComboBoxItemTypeDevice
    DataBinding.DataField = 'TYPEPRODUCT_REM_SPRRABOTA'
    Properties.Items = <>
    TabOrder = 9
    Width = 332
  end
  object cxDBSpinEditLEVEL_REM_SPRRABOTA: TcxDBSpinEdit
    Left = 124
    Top = 196
    DataBinding.DataField = 'LEVEL_REM_SPRRABOTA'
    TabOrder = 10
    Width = 65
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 328
    Top = 8
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
