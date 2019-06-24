object REM_FormaElementaSprModelInfBlock: TREM_FormaElementaSprModelInfBlock
  Left = 645
  Top = 0
  Caption = #1069#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1048#1085#1092'. '#1073#1083#1086#1082#1080' '#1084#1086#1076#1077#1083#1080'"'
  ClientHeight = 197
  ClientWidth = 607
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
    Left = 24
    Top = 41
    Width = 69
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1048#1085#1092'. '#1073#1083#1086#1082':'
  end
  object cxButtonOK: TcxButton
    Left = 400
    Top = 135
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
    Left = 500
    Top = 135
    Width = 93
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    Cancel = True
    TabOrder = 1
  end
  object NameInfBlockcxDBButtonEdit: TcxDBButtonEdit
    Left = 24
    Top = 64
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_ART_IB'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ClickKey = 13
    Properties.ReadOnly = True
    Properties.OnButtonClick = NamePropcxDBButtonEditPropertiesButtonClick
    TabOrder = 2
    Width = 569
  end
  object IsmcxDBDateEdit: TcxDBDateEdit
    Left = 336
    Top = 8
    DataBinding.DataField = 'ISM_REM_SMODEL_INF'
    Properties.Kind = ckDateTime
    TabOrder = 3
    Width = 257
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 200
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
