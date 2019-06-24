object FormaElementaSprKlientDopFisL: TFormaElementaSprKlientDopFisL
  Left = 289
  Top = 170
  Caption = #1044#1086#1087'. '#1089#1074#1077#1076#1077#1085#1080#1103' '#1086' '#1082#1086#1085#1090#1088#1072#1075#1077#1085#1090#1077' '#1092#1080#1079#1080#1095#1077#1089#1082#1086#1084' '#1083#1080#1094#1077
  ClientHeight = 263
  ClientWidth = 604
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
  object Label6: TLabel
    Left = 10
    Top = 59
    Width = 102
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1044#1072#1090#1072' '#1088#1086#1078#1076#1077#1085#1080#1103':'
  end
  object NameNomDBText: TDBText
    Left = 108
    Top = 10
    Width = 142
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    AutoSize = True
    DataField = 'NAMEKLIENT'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -17
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label7: TLabel
    Left = 10
    Top = 98
    Width = 111
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1052#1077#1089#1090#1086' '#1088#1086#1078#1076#1077#1085#1080#1103':'
  end
  object Label8: TLabel
    Left = 20
    Top = 148
    Width = 74
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1044#1086#1083#1078#1085#1086#1089#1090#1100':'
  end
  object Label9: TLabel
    Left = 10
    Top = 187
    Width = 95
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1052#1077#1089#1090#1086' '#1088#1072#1073#1086#1090#1099':'
  end
  object Label1: TLabel
    Left = 10
    Top = 10
    Width = 92
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1060#1080#1079'. '#1083#1080#1094#1086':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -17
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 410
    Top = 54
    Width = 29
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1055#1086#1083':'
  end
  object PolcxDBComboBox: TcxDBComboBox
    Left = 446
    Top = 49
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'POL_SKLIENT_DOPFISL'
    Properties.DropDownListStyle = lsFixedList
    Properties.Items.Strings = (
      #1053#1077' '#1079#1072#1076#1072#1085
      #1052#1091#1078#1089#1082#1086#1081
      #1046#1077#1085#1089#1082#1080#1081)
    Properties.ReadOnly = False
    TabOrder = 1
    Width = 148
  end
  object cxButtonSave: TcxButton
    Left = 286
    Top = 223
    Width = 92
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionSave
    TabOrder = 5
  end
  object cxButtonOK: TcxButton
    Left = 395
    Top = 223
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
    Left = 503
    Top = 223
    Width = 92
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 7
  end
  object DateRogcxDBDateEdit: TcxDBDateEdit
    Left = 128
    Top = 55
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'DATEROG_SKLIENT_DOPFISL'
    TabOrder = 0
    OnKeyDown = DateRogcxDBDateEditKeyDown
    Width = 149
  end
  object MestoRogcxDBTextEdit: TcxDBTextEdit
    Left = 128
    Top = 94
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'MESTOROG_SKLIENT_DOPFISL'
    TabOrder = 2
    OnKeyDown = MestoRogcxDBTextEditKeyDown
    Width = 466
  end
  object DolcxDBTextEdit: TcxDBTextEdit
    Left = 128
    Top = 138
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'DOLRAB_SKLIENT_DOPFISL'
    TabOrder = 3
    OnKeyDown = DolcxDBTextEditKeyDown
    Width = 208
  end
  object MestoRabcxDBTextEdit: TcxDBTextEdit
    Left = 128
    Top = 183
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'MESTORAB_SKLIENT_DOPFISL'
    TabOrder = 4
    OnKeyDown = MestoRabcxDBTextEditKeyDown
    Width = 466
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 288
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
    object ActionSave: TAction
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      ImageIndex = 55
      OnExecute = ActionSaveExecute
    end
  end
end
