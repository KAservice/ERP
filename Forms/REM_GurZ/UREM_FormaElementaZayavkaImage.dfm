object REM_FormaElementaZayavkaImage: TREM_FormaElementaZayavkaImage
  Left = 462
  Top = 235
  Caption = #1069#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1060#1086#1090#1086#1075#1088#1072#1092#1080#1080'"'
  ClientHeight = 512
  ClientWidth = 538
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 120
  TextHeight = 16
  object ImagecxDBImage: TcxDBImage
    Left = 0
    Top = 113
    Align = alClient
    DataBinding.DataField = 'IMAGE_REM_ZIMAGE'
    Properties.GraphicClassName = 'TJPEGImage'
    TabOrder = 0
    ExplicitLeft = 8
    ExplicitTop = 136
    ExplicitWidth = 522
    ExplicitHeight = 177
    Height = 319
    Width = 538
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 538
    Height = 113
    Align = alTop
    TabOrder = 1
    object Label1: TLabel
      Left = 11
      Top = 49
      Width = 102
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
    end
    object NamecxDBTextEdit: TcxDBTextEdit
      Left = 15
      Top = 73
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAME_REM_ZIMAGE'
      TabOrder = 0
      Width = 515
    end
    object ShowUsercxDBCheckBox: TcxDBCheckBox
      Left = 15
      Top = 10
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1087#1086#1082#1072#1079#1099#1074#1072#1090#1100' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1102
      DataBinding.DataField = 'SHOWUSER_REM_ZIMAGE'
      Properties.ValueChecked = 1
      Properties.ValueUnchecked = 0
      TabOrder = 1
      Width = 210
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 432
    Width = 538
    Height = 80
    Align = alBottom
    TabOrder = 2
    object cxButtonFileInBlob: TcxButton
      Left = 192
      Top = 26
      Width = 130
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1048#1079' '#1092#1072#1081#1083#1072' '#1074' '#1073#1072#1079#1091
      TabOrder = 0
      OnClick = cxButtonFileInBlobClick
    end
    object cxButtonOK: TcxButton
      Left = 330
      Top = 26
      Width = 92
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionOK
      TabOrder = 1
    end
    object cxButtonClose: TcxButton
      Left = 430
      Top = 26
      Width = 92
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      TabOrder = 2
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 416
    Top = 8
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
  object OpenDialog1: TOpenDialog
    Left = 488
    Top = 8
  end
end
