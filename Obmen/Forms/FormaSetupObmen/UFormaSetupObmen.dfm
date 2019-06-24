object FormaSetupObmen: TFormaSetupObmen
  Left = 619
  Top = 119
  Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099
  ClientHeight = 452
  ClientWidth = 453
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 120
  TextHeight = 16
  object cxPageControl1: TcxPageControl
    Left = 0
    Top = 137
    Width = 453
    Height = 250
    ActivePage = cxTabSheet1
    Align = alClient
    TabOrder = 0
    ExplicitTop = 253
    ExplicitWidth = 891
    ExplicitHeight = 252
    ClientRectBottom = 250
    ClientRectRight = 453
    ClientRectTop = 27
    object cxTabSheet1: TcxTabSheet
      Caption = #1054#1089#1085#1086#1074#1085#1072#1103
      ImageIndex = 0
      ExplicitWidth = 891
      ExplicitHeight = 292
      object cxRadioGroup1: TcxRadioGroup
        Left = 18
        Top = 165
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1058#1080#1087' '#1086#1073#1084#1077#1085#1072
        Properties.Items = <>
        TabOrder = 0
        Height = 54
        Width = 421
      end
      object CatalogObmenacxRadioButton: TcxRadioButton
        Left = 42
        Top = 189
        Width = 168
        Height = 21
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1095#1077#1088#1077#1079' '#1082#1072#1090#1072#1083#1086#1075' '#1086#1073#1084#1077#1085#1072
        TabOrder = 1
      end
      object MAPIcxRadioButton: TcxRadioButton
        Left = 240
        Top = 189
        Width = 175
        Height = 21
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1095#1077#1088#1077#1079' MAPI ('#1101#1083'. '#1087#1086#1095#1090#1072')'
        TabOrder = 2
      end
      object cxGroupBox1: TcxGroupBox
        Left = 16
        Top = 23
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1055#1086#1076#1082#1083#1102#1095#1077#1085#1080#1077' '#1082' '#1073#1072#1079#1077' '#1076#1072#1085#1085#1099#1093
        TabOrder = 3
        Height = 100
        Width = 423
        object Label3: TLabel
          Left = 20
          Top = 22
          Width = 125
          Height = 16
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1048#1084#1103' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103':'
        end
        object Label4: TLabel
          Left = 276
          Top = 22
          Width = 52
          Height = 16
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1055#1072#1088#1086#1083#1100':'
        end
        object Label6: TLabel
          Left = 20
          Top = 47
          Width = 141
          Height = 16
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1057#1090#1088#1086#1082#1072' '#1087#1086#1076#1082#1083#1102#1095#1077#1085#1080#1103':'
        end
        object NameUserEdit: TEdit
          Left = 149
          Top = 18
          Width = 119
          Height = 24
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          ReadOnly = True
          TabOrder = 0
          Text = 'NameUserEdit'
        end
        object PasswordUserEdit: TEdit
          Left = 334
          Top = 18
          Width = 70
          Height = 24
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          TabOrder = 1
          Text = 'PasswordUserEdit'
        end
        object ConnectStringcxButtonEdit: TcxButtonEdit
          Left = 20
          Top = 64
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Properties.Buttons = <
            item
              Default = True
              Kind = bkEllipsis
            end>
          Properties.OnButtonClick = ConnectStringcxButtonEditPropertiesButtonClick
          TabOrder = 2
          Text = 'ConnectStringcxButtonEdit'
          Width = 384
        end
      end
    end
    object cxTabSheet2: TcxTabSheet
      Caption = 'MAPI'
      ImageIndex = 1
      ExplicitWidth = 891
      ExplicitHeight = 292
      object Label1: TLabel
        Left = 30
        Top = 32
        Width = 278
        Height = 16
        Caption = #1054#1073#1084#1077#1085' '#1074#1099#1087#1086#1083#1085#1103#1077#1090#1089#1103' '#1095#1077#1088#1077#1079' Outlook Express.'
      end
      object EMailcxTextEdit: TcxTextEdit
        Left = 145
        Top = 87
        TabOrder = 0
        Text = 'EMailcxTextEdit'
        Width = 201
      end
      object cxLabel1: TcxLabel
        Left = 74
        Top = 88
        Caption = 'E-Mail:'
      end
    end
    object cxTabSheet3: TcxTabSheet
      Caption = #1040#1074#1090#1086#1086#1073#1084#1077#1085
      ImageIndex = 2
      ExplicitTop = 35
      ExplicitWidth = 891
      ExplicitHeight = 292
      object cxGroupBox4: TcxGroupBox
        Left = 15
        Top = 33
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1072#1074#1090#1086#1086#1073#1084#1077#1085#1072
        TabOrder = 0
        Height = 122
        Width = 424
        object Label10: TLabel
          Left = 138
          Top = 48
          Width = 162
          Height = 16
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1048#1085#1090#1077#1088#1074#1072#1083'  '#1086#1073#1084#1077#1085#1072' ('#1084#1080#1085'.):'
        end
        object Label11: TLabel
          Left = 48
          Top = 84
          Width = 255
          Height = 16
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1048#1085#1090#1077#1088#1074#1072#1083'  '#1086#1073#1084#1077#1085#1072' '#1087#1086#1089#1083#1077' '#1086#1096#1080#1073#1082#1080' ('#1084#1080#1085'.):'
        end
        object AutoObmenCheckBox: TCheckBox
          Left = 29
          Top = 19
          Width = 367
          Height = 21
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1072#1074#1090#1086#1084#1072#1090#1080#1095#1077#1089#1082#1080#1081' '#1086#1073#1084#1077#1085' '#1095#1077#1088#1077#1079' '#1086#1087#1088#1077#1076#1077#1083#1077#1085#1085#1099#1081' '#1080#1085#1090#1077#1088#1074#1072#1083
          TabOrder = 0
        end
        object IntervalEdit: TEdit
          Left = 303
          Top = 50
          Width = 92
          Height = 24
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          TabOrder = 1
          Text = 'IntervalEdit'
        end
        object IntervalObmenaAfterErrorEdit: TEdit
          Left = 304
          Top = 84
          Width = 92
          Height = 24
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          TabOrder = 2
          Text = 'IntervalObmenaAfterErrorEdit'
        end
      end
    end
    object cxTabSheet4: TcxTabSheet
      Caption = #1050#1072#1090#1072#1083#1086#1075' '#1086#1073#1084#1077#1085#1072
      ImageIndex = 3
      ExplicitWidth = 891
      ExplicitHeight = 292
      object cxGroupBox6: TcxGroupBox
        Left = 18
        Top = 20
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1050#1072#1090#1072#1083#1086#1075' '#1086#1073#1084#1077#1085#1072
        TabOrder = 0
        Height = 63
        Width = 414
        object Label15: TLabel
          Left = 11
          Top = 28
          Width = 35
          Height = 16
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1055#1091#1090#1100':'
        end
        object CatalogObmenacxButtonEdit: TcxButtonEdit
          Left = 52
          Top = 23
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Properties.Buttons = <
            item
              Default = True
              Kind = bkEllipsis
            end>
          Properties.OnButtonClick = CatalogObmenacxButtonEditPropertiesButtonClick
          TabOrder = 0
          Text = 'CatalogObmenacxButtonEdit'
          Width = 343
        end
      end
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 453
    Height = 137
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 1
    object cxGroupBox2: TcxGroupBox
      Left = 10
      Top = 10
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1091#1076#1072#1083#1077#1085#1085#1086#1081' '#1073#1072#1079#1099' '#1076#1083#1103' '#1086#1073#1084#1077#1085#1072
      TabOrder = 0
      Height = 101
      Width = 423
      object Label9: TLabel
        Left = 100
        Top = 57
        Width = 130
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = 'ID '#1073#1072#1079#1099' '#1076#1083#1103' '#1086#1073#1084#1077#1085#1072':'
      end
      object Label5: TLabel
        Left = 20
        Top = 21
        Width = 164
        Height = 32
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1073#1072#1079#1099' '#1076#1083#1103' '#1086#1073#1084#1077#1085#1072':'
        WordWrap = True
      end
      object NameBaseForObmenEdit: TEdit
        Left = 236
        Top = 20
        Width = 169
        Height = 24
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        Text = 'NameBaseForObmenEdit'
      end
      object IdBaseForObmenEdit: TEdit
        Left = 236
        Top = 53
        Width = 169
        Height = 24
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
        Text = 'IdBaseForObmenEdit'
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 387
    Width = 453
    Height = 65
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 2
    ExplicitTop = 504
    ExplicitWidth = 891
    object ButtonSave: TButton
      Left = 246
      Top = 23
      Width = 93
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      TabOrder = 0
      OnClick = ButtonSaveClick
    end
    object ButtonClose: TButton
      Left = 347
      Top = 23
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1047#1072#1082#1088#1099#1090#1100
      TabOrder = 1
      OnClick = ButtonCloseClick
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 48
    Top = 504
  end
end
