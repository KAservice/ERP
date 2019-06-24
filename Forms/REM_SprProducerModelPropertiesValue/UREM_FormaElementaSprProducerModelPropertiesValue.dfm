object REM_FormaElementaSprProducerModelPropertiesValue: TREM_FormaElementaSprProducerModelPropertiesValue
  Left = 645
  Top = 0
  Caption = 
    #1045#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1057#1074#1086#1081#1089#1090#1074#1072' ('#1093#1072#1088#1072#1082#1090#1077#1088#1080#1089#1090#1080#1082#1080') '#1084#1086#1076#1077#1083#1080' '#1055#1088#1086#1080#1079#1074#1086#1076#1080#1090 +
    #1077#1083#1103'"'
  ClientHeight = 372
  ClientWidth = 613
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
  object Label5: TLabel
    Left = 24
    Top = 96
    Width = 68
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1047#1085#1072#1095#1077#1085#1080#1077':'
  end
  object Label1: TLabel
    Left = 24
    Top = 41
    Width = 182
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1057#1074#1086#1081#1089#1090#1074#1086' ('#1093#1072#1088#1072#1082#1090#1077#1088#1080#1089#1090#1080#1082#1072'):'
  end
  object cxButtonOK: TcxButton
    Left = 401
    Top = 319
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
    Left = 501
    Top = 319
    Width = 93
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    Cancel = True
    TabOrder = 2
  end
  object NamePropValueListcxDBButtonEdit: TcxDBButtonEdit
    Left = 24
    Top = 120
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_SPROPVALUELIST'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ClickKey = 13
    Properties.ReadOnly = True
    Properties.OnButtonClick = NamePropValueListcxDBButtonEditPropertiesButtonClick
    TabOrder = 0
    Width = 569
  end
  object ValueTextcxDBMemo: TcxDBMemo
    Left = 24
    Top = 151
    DataBinding.DataField = 'VALTEXT_REM_SPRMOD_PRVAL'
    TabOrder = 3
    Height = 89
    Width = 569
  end
  object NamePropcxDBButtonEdit: TcxDBButtonEdit
    Left = 24
    Top = 64
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_SPROP'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ClickKey = 13
    Properties.ReadOnly = True
    Properties.OnButtonClick = NamePropcxDBButtonEditPropertiesButtonClick
    TabOrder = 4
    Width = 569
  end
  object IsmcxDBDateEdit: TcxDBDateEdit
    Left = 400
    Top = 16
    DataBinding.DataField = 'ISM_REM_SPRMOD_PRVAL'
    Properties.Kind = ckDateTime
    TabOrder = 5
    Width = 193
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 336
    Top = 10
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
