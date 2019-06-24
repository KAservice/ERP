object HLP_FormaElementaSprImage: THLP_FormaElementaSprImage
  Left = 645
  Top = 0
  Caption = #1056#1080#1089#1091#1085#1086#1082
  ClientHeight = 442
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
  object ImagecxDBImage: TcxDBImage
    Left = 0
    Top = 161
    Align = alClient
    DataBinding.DataField = 'IMAGE_HLP_IMG'
    Properties.GraphicClassName = 'TJPEGImage'
    TabOrder = 0
    Height = 231
    Width = 613
  end
  object Panel1: TPanel
    Left = 0
    Top = 392
    Width = 613
    Height = 50
    Align = alBottom
    TabOrder = 1
    object cxButtonOK: TcxButton
      Left = 384
      Top = 7
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
      Left = 484
      Top = 7
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
  end
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 613
    Height = 161
    Align = alTop
    TabOrder = 2
    object NameGrpLabel: TLabel
      Left = 501
      Top = 8
      Width = 93
      Height = 16
      Alignment = taRightJustify
      Caption = 'NameGrpLabel'
    end
    object Label1: TLabel
      Left = 25
      Top = 40
      Width = 102
      Height = 16
      Alignment = taRightJustify
      Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
    end
    object Label2: TLabel
      Left = 25
      Top = 100
      Width = 33
      Height = 16
      Alignment = taRightJustify
      Caption = 'GUID'
    end
    object NamecxDBTextEdit: TcxDBTextEdit
      Left = 25
      Top = 62
      DataBinding.DataField = 'NAME_HLP_IMG'
      TabOrder = 0
      Width = 569
    end
    object GuidcxDBTextEdit: TcxDBTextEdit
      Left = 25
      Top = 122
      DataBinding.DataField = 'GUID_HLP_IMG'
      TabOrder = 1
      Width = 569
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 144
    Top = 42
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
