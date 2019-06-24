object FormaElementaSprDocKlient: TFormaElementaSprDocKlient
  Left = 510
  Top = 18
  Caption = #1069#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1044#1086#1082#1091#1084#1077#1085#1090#1099' '#1082#1086#1085#1090#1088#1072#1075#1077#1085#1090#1086#1074'"'
  ClientHeight = 238
  ClientWidth = 555
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
  object Label3: TLabel
    Left = 10
    Top = 20
    Width = 102
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
  end
  object Label4: TLabel
    Left = 295
    Top = 79
    Width = 84
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1044#1072#1090#1072' '#1074#1099#1076#1072#1095#1080
  end
  object Label2: TLabel
    Left = 10
    Top = 79
    Width = 43
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1057#1077#1088#1080#1103':'
  end
  object Label5: TLabel
    Left = 148
    Top = 79
    Width = 46
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1086#1084#1077#1088':'
  end
  object Label6: TLabel
    Left = 10
    Top = 138
    Width = 45
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1042#1099#1076#1072#1085':'
  end
  object NameDoccxDBComboBox: TcxDBComboBox
    Left = 10
    Top = 42
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_SDOCKLIENT'
    Properties.Items.Strings = (
      #1055#1072#1089#1087#1086#1088#1090' '#1075#1088#1072#1078#1076#1072#1085#1080#1085#1072' '#1056#1086#1089#1089#1080#1080
      #1047#1072#1075#1088#1072#1085#1087#1072#1089#1087#1086#1088#1090' '#1075#1088#1072#1078#1076#1072#1085#1080#1085#1072' '#1056#1060
      #1055#1072#1089#1087#1086#1088#1090' '#1075#1088#1072#1078#1076#1072#1085#1080#1085#1072' '#1057#1057#1057#1056
      #1047#1072#1075#1088#1072#1085#1087#1072#1089#1087#1086#1088#1090' '#1075#1088'. '#1057#1057#1057#1056
      #1059#1076#1086#1089#1090#1086#1074#1077#1088#1077#1085#1080#1077' '#1083#1080#1095#1085#1086#1089#1090#1080' '#1086#1092#1080#1094#1077#1088#1072
      #1042#1086#1077#1085#1085#1099#1081' '#1073#1080#1083#1077#1090' '#1089#1086#1083#1076#1072#1090#1072' ('#1084#1072#1090#1088#1086#1089#1072', '#1089#1077#1088#1078#1072#1085#1090#1072', '#1089#1090#1072#1088#1096#1080#1085#1099')'
      #1042#1086#1077#1085#1085#1099#1081' '#1073#1080#1083#1077#1090' '#1086#1092#1080#1094#1077#1088#1072' '#1079#1072#1087#1072#1089#1072
      #1055#1072#1089#1087#1086#1088#1090' '#1052#1080#1085#1084#1086#1088#1092#1083#1086#1090#1072
      #1055#1072#1089#1087#1086#1088#1090' '#1084#1086#1088#1103#1082#1072
      #1057#1074#1080#1076#1077#1090#1077#1083#1100#1089#1090#1074#1086' '#1086' '#1088#1086#1078#1076#1077#1085#1080#1080
      #1044#1080#1087#1083#1086#1084#1072#1090#1080#1095#1077#1089#1082#1080#1081' '#1087#1072#1089#1087#1086#1088#1090' '#1075#1088#1072#1078#1076#1072#1085#1080#1085#1072' '#1056#1060
      #1042#1088#1077#1084#1077#1085#1085#1086#1077' '#1091#1076#1086#1089#1090#1086#1074#1077#1088#1077#1085#1080#1077' '#1083#1080#1095#1085#1086#1089#1090#1080' '#1075#1088#1072#1078#1076#1072#1085#1080#1085#1072' '#1056#1060
      #1059#1076#1086#1089#1090#1086#1074#1077#1088#1077#1085#1080#1077' '#1073#1077#1078#1077#1085#1094#1072' '#1074' '#1056#1060
      #1042#1080#1076' '#1085#1072' '#1078#1080#1090#1077#1083#1100#1089#1090#1074#1086
      
        #1057#1074#1080#1076#1077#1090#1077#1083#1100#1089#1090#1074#1086' '#1086' '#1088#1077#1075#1080#1089#1090#1088#1072#1094#1080#1080' '#1093#1086#1076#1072#1090#1072#1081#1089#1090#1074#1072' '#1086' '#1087#1088#1080#1079#1085#1072#1085#1080#1080' '#1080#1084#1084#1080#1075#1088#1072#1085#1090#1072' '#1073 +
        #1077#1078#1077#1085#1094#1077#1084
      #1048#1085#1086#1089#1090#1088#1072#1085#1085#1099#1081' '#1087#1072#1089#1087#1086#1088#1090
      #1057#1087#1088#1072#1074#1082#1072' '#1086#1073' '#1086#1089#1074#1086#1073#1086#1078#1076#1077#1085#1080#1080' '#1080#1079' '#1084#1077#1089#1090#1072' '#1083#1080#1096#1077#1085#1080#1103' '#1089#1074#1086#1073#1086#1076#1099)
    Properties.OnChange = NameDoccxDBComboBoxPropertiesChange
    TabOrder = 0
    Width = 535
  end
  object cxButtonOK: TcxButton
    Left = 353
    Top = 194
    Width = 93
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionOK
    TabOrder = 5
  end
  object cxButtonClose: TcxButton
    Left = 453
    Top = 194
    Width = 92
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 6
  end
  object VidcxDBTextEdit: TcxDBTextEdit
    Left = 10
    Top = 156
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'VID_SDOCKLIENT'
    TabOrder = 4
    OnKeyDown = VidcxDBTextEditKeyDown
    Width = 535
  end
  object DateVidcxDBDateEdit: TcxDBDateEdit
    Left = 295
    Top = 98
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'DATEVID_SDOCKLIENT'
    TabOrder = 3
    OnKeyDown = DateVidcxDBDateEditKeyDown
    Width = 149
  end
  object NumcxDBTextEdit: TcxDBTextEdit
    Left = 139
    Top = 98
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NUM_SDOCKLIENT'
    TabOrder = 2
    OnKeyDown = NumcxDBTextEditKeyDown
    Width = 149
  end
  object SercxDBTextEdit: TcxDBTextEdit
    Left = 10
    Top = 98
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'SER_SDOCKLIENT'
    TabOrder = 1
    OnKeyDown = SercxDBTextEditKeyDown
    Width = 122
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 144
    Top = 192
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
