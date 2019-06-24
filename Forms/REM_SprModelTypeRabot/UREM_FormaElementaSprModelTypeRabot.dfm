object REM_FormaElementaSprModelTypRabot: TREM_FormaElementaSprModelTypRabot
  Left = 645
  Top = 0
  Caption = #1058#1080#1087#1086#1074#1072#1103' '#1088#1072#1073#1086#1090#1072' '#1084#1086#1076#1077#1083#1080
  ClientHeight = 237
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
  object Label1: TLabel
    Left = 24
    Top = 41
    Width = 109
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1058#1080#1087#1086#1074#1072#1103' '#1088#1072#1073#1086#1090#1072':'
  end
  object cxButtonOK: TcxButton
    Left = 392
    Top = 167
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
    Left = 492
    Top = 167
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
  object cxDBButtonEditNAME_REM_STYPRABOT: TcxDBButtonEdit
    Left = 24
    Top = 64
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_REM_STYPRABOT'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ClickKey = 13
    Properties.ReadOnly = True
    Properties.OnButtonClick = cxDBButtonEditNAME_REM_STYPRABOTPropertiesButtonClick
    TabOrder = 2
    Width = 569
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
