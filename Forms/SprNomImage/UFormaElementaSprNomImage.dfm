object FormaElementaSprNomImage: TFormaElementaSprNomImage
  Left = 645
  Top = 0
  Caption = #1045#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1057#1074#1086#1081#1089#1090#1074#1072' ('#1093#1072#1088#1072#1082#1090#1077#1088#1080#1089#1090#1080#1082#1080') '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099'"'
  ClientHeight = 410
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
    Width = 182
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1057#1074#1086#1081#1089#1090#1074#1086' ('#1093#1072#1088#1072#1082#1090#1077#1088#1080#1089#1090#1080#1082#1072'):'
  end
  object Label2: TLabel
    Left = 414
    Top = 19
    Width = 51
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1048#1085#1076#1077#1082#1089':'
  end
  object cxButtonOK: TcxButton
    Left = 401
    Top = 370
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
    Left = 501
    Top = 370
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
  object NameVidImagecxDBButtonEdit: TcxDBButtonEdit
    Left = 24
    Top = 64
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_SVIDIMAGE'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ClickKey = 13
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameVidImagecxDBButtonEditPropertiesButtonClick
    TabOrder = 2
    Width = 569
  end
  object ImagecxDBImage: TcxDBImage
    Left = 288
    Top = 146
    DataBinding.DataField = 'BODY_SNOMIMAGE'
    Properties.GraphicClassName = 'TJPEGImage'
    TabOrder = 3
    Height = 217
    Width = 257
  end
  object ImageSmallcxDBImage: TcxDBImage
    Left = 48
    Top = 184
    DataBinding.DataField = 'BODY_SMALL_SNOMIMAGE'
    Properties.GraphicClassName = 'TJPEGImage'
    TabOrder = 4
    Height = 108
    Width = 140
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 24
    Top = 116
    DataBinding.DataField = 'NAME_SNOMIMAGE'
    TabOrder = 5
    Width = 569
  end
  object IndexcxDBSpinEdit: TcxDBSpinEdit
    Left = 472
    Top = 16
    DataBinding.DataField = 'INDEX_SNOMIMAGE'
    TabOrder = 6
    Width = 121
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 144
    Top = 42
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
