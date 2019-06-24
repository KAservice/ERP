object FormaElementaSprGrpNom: TFormaElementaSprGrpNom
  Left = 462
  Top = 235
  Caption = #1043#1088#1091#1087#1087#1072' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099
  ClientHeight = 304
  ClientWidth = 481
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
    Width = 152
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1075#1088#1091#1087#1087#1099':'
  end
  object IdGnDBText: TDBText
    Left = 30
    Top = 10
    Width = 80
    Height = 21
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataField = 'IDGN'
  end
  object Label2: TLabel
    Left = 10
    Top = 10
    Width = 16
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'ID:'
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 10
    Top = 76
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAMEGN'
    TabOrder = 0
    OnKeyDown = NamecxDBTextEditKeyDown
    Width = 458
  end
  object cxButtonNac: TcxButton
    Left = 165
    Top = 250
    Width = 92
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1094#1077#1085#1082#1072
    TabOrder = 2
    OnClick = cxButtonNacClick
  end
  object cxButtonOK: TcxButton
    Left = 265
    Top = 250
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
    Left = 364
    Top = 250
    Width = 93
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 3
  end
  object NamePropertiesNaborcxDBButtonEdit: TcxDBButtonEdit
    Left = 8
    Top = 138
    DataBinding.DataField = 'NAME_SPROPNABOR'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = NamePropertiesNaborcxDBButtonEditPropertiesButtonClick
    TabOrder = 4
    Width = 460
  end
  object NameVidImageNaborcxDBButtonEdit: TcxDBButtonEdit
    Left = 8
    Top = 194
    DataBinding.DataField = 'NAME_SVIDIMAGE_NABOR'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ReadOnly = True
    TabOrder = 5
    Width = 460
  end
  object cxLabel1: TcxLabel
    Left = 8
    Top = 112
    Caption = #1053#1072#1073#1086#1088' '#1089#1074#1086#1081#1089#1090#1074':'
  end
  object cxLabel2: TcxLabel
    Left = 8
    Top = 168
    Caption = #1053#1072#1073#1086#1088' '#1080#1079#1086#1073#1088#1072#1078#1077#1085#1080#1081':'
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 352
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
