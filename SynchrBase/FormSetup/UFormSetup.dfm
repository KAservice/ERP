object FormSetup: TFormSetup
  Left = 0
  Top = 0
  Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072
  ClientHeight = 609
  ClientWidth = 760
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 120
  TextHeight = 17
  object cxPageControl1: TcxPageControl
    Left = 0
    Top = 0
    Width = 760
    Height = 609
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    ActivePage = cxTabSheet1
    Align = alClient
    TabOrder = 0
    ClientRectBottom = 609
    ClientRectRight = 760
    ClientRectTop = 28
    object cxTabSheet1: TcxTabSheet
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1086#1076#1082#1083#1102#1095#1077#1085#1080#1077
      ImageIndex = 0
      object cxGroupBox2: TcxGroupBox
        Left = 4
        Top = 221
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1048#1085#1092'. '#1073#1072#1079#1072' 2 ('#1087#1088#1080#1077#1084#1085#1080#1082'):'
        TabOrder = 0
        Height = 114
        Width = 697
        object cxLabel4: TcxLabel
          Left = 345
          Top = 33
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1100':'
        end
        object cxLabel6: TcxLabel
          Left = 556
          Top = 33
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1055#1072#1088#1086#1083#1100':'
        end
        object cxLabel7: TcxLabel
          Left = 12
          Top = 33
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1057#1090#1088#1086#1082#1072' '#1087#1086#1076#1082#1083#1102#1095#1077#1085#1080#1103':'
        end
        object ConnectString2cxTextEdit: TcxTextEdit
          Left = 4
          Top = 63
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          TabOrder = 3
          Text = 'ConnectString2cxTextEdit'
          Width = 326
        end
        object NameUser2cxTextEdit: TcxTextEdit
          Left = 337
          Top = 63
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          TabOrder = 4
          Text = 'NameUsercxTextEdit'
          Width = 159
        end
        object PasswordUser2cxTextEdit: TcxTextEdit
          Left = 503
          Top = 63
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          TabOrder = 5
          Text = 'PasswordUsercxTextEdit'
          Width = 159
        end
      end
      object cxGroupBox1: TcxGroupBox
        Left = 4
        Top = 21
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1048#1085#1092'. '#1073#1072#1079#1072' 1 ('#1048#1089#1090#1086#1095#1085#1080#1082'):'
        TabOrder = 1
        Height = 112
        Width = 697
        object cxLabel1: TcxLabel
          Left = 4
          Top = 29
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1057#1090#1088#1086#1082#1072' '#1087#1086#1076#1082#1083#1102#1095#1077#1085#1080#1103':'
        end
        object cxLabel3: TcxLabel
          Left = 337
          Top = 29
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1100':'
        end
        object cxLabel5: TcxLabel
          Left = 503
          Top = 29
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1055#1072#1088#1086#1083#1100':'
        end
        object ConnectStringcxTextEdit: TcxTextEdit
          Left = 4
          Top = 59
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          TabOrder = 3
          Text = 'ConnectStringcxTextEdit'
          Width = 326
        end
        object NameUsercxTextEdit: TcxTextEdit
          Left = 337
          Top = 59
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          TabOrder = 4
          Text = 'NameUsercxTextEdit'
          Width = 159
        end
        object PasswordUsercxTextEdit: TcxTextEdit
          Left = 503
          Top = 59
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          TabOrder = 5
          Text = 'PasswordUsercxTextEdit'
          Width = 159
        end
      end
      object cxButton5: TcxButton
        Left = 475
        Top = 407
        Width = 226
        Height = 44
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1085#1072#1089#1090#1088#1086#1081#1082#1080' '#1087#1086#1076#1082#1083#1102#1095#1077#1085#1080#1103
        TabOrder = 2
        WordWrap = True
        OnClick = cxButton5Click
      end
      object cxButtonConnect: TcxButton
        Left = 41
        Top = 157
        Width = 98
        Height = 30
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = 'Connect'
        TabOrder = 3
        OnClick = cxButtonConnectClick
      end
      object cxButtonDisconnect: TcxButton
        Left = 166
        Top = 156
        Width = 98
        Height = 32
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = 'Disconnect'
        TabOrder = 4
        OnClick = cxButtonDisconnectClick
      end
      object UpdateUsercxCheckBox: TcxCheckBox
        Left = 63
        Top = 356
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1086#1073#1085#1086#1074#1083#1103#1090#1100' '#1089#1087#1080#1089#1086#1082' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1077#1081
        TabOrder = 5
        Width = 304
      end
    end
    object cxTabSheet2: TcxTabSheet
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1058#1072#1073#1083#1080#1094#1099' '#1080' '#1087#1086#1083#1103
      ImageIndex = 1
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object cxGridFields: TcxGrid
        Left = 378
        Top = 54
        Width = 382
        Height = 473
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Align = alClient
        TabOrder = 0
        object cxGridFieldsDBTableView1: TcxGridDBTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <>
          DataController.Summary.SummaryGroups = <>
          OptionsView.ColumnAutoWidth = True
          OptionsView.GroupByBox = False
          object cxGridFieldsDBTableView1NameFields: TcxGridDBColumn
          end
        end
        object cxGridFieldsTableView1: TcxGridTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <>
          DataController.Summary.SummaryGroups = <>
          OptionsView.ColumnAutoWidth = True
          OptionsView.GroupByBox = False
          object cxGridFieldsTableView1Out: TcxGridColumn
            PropertiesClassName = 'TcxCheckBoxProperties'
            Properties.ValueChecked = 1
            Properties.ValueUnchecked = 0
            Width = 68
          end
          object cxGridFieldsTableView1NameField: TcxGridColumn
            Width = 187
          end
        end
        object cxGridFieldsLevel1: TcxGridLevel
          GridView = cxGridFieldsTableView1
        end
      end
      object cxGridTables: TcxGrid
        Left = 0
        Top = 54
        Width = 367
        Height = 473
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Align = alLeft
        TabOrder = 1
        object cxGridTablesDBTableView1: TcxGridDBTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <>
          DataController.Summary.SummaryGroups = <>
        end
        object cxGridTablesTableView1: TcxGridTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <>
          DataController.Summary.SummaryGroups = <>
          OptionsCustomize.ColumnSorting = False
          OptionsView.ColumnAutoWidth = True
          OptionsView.GroupByBox = False
          object cxGridTablesTableView1Number: TcxGridColumn
            Width = 57
          end
          object cxGridTablesTableView1NameTable: TcxGridColumn
            PropertiesClassName = 'TcxLookupComboBoxProperties'
            Properties.KeyFieldNames = 'TABLE_NAME'
            Properties.ListColumns = <
              item
                FieldName = 'TABLE_NAME'
              end>
            Properties.ListSource = DM.DataSourceTables
            Width = 111
          end
          object cxGridTablesTableView1NameFieldId: TcxGridColumn
            Width = 111
          end
        end
        object cxGridTablesLevel1: TcxGridLevel
          GridView = cxGridTablesTableView1
        end
      end
      object Panel1: TPanel
        Left = 0
        Top = 0
        Width = 760
        Height = 54
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Align = alTop
        BevelOuter = bvNone
        TabOrder = 2
        object cxButton1: TcxButton
          Left = 112
          Top = 9
          Width = 99
          Height = 33
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1044#1086#1073#1072#1074#1080#1090#1100
          TabOrder = 0
          OnClick = cxButton1Click
        end
        object cxButtonUpdateFields: TcxButton
          Left = 378
          Top = 9
          Width = 98
          Height = 33
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1054#1073#1085#1086#1074#1080#1090#1100
          TabOrder = 1
          OnClick = cxButtonUpdateFieldsClick
        end
        object cxButton3: TcxButton
          Left = 484
          Top = 9
          Width = 98
          Height = 33
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
          TabOrder = 2
          OnClick = cxButton3Click
        end
        object cxButton4: TcxButton
          Left = 7
          Top = 9
          Width = 98
          Height = 33
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100
          TabOrder = 3
          OnClick = cxButton4Click
        end
      end
      object Panel2: TPanel
        Left = 367
        Top = 54
        Width = 11
        Height = 473
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Align = alLeft
        BevelOuter = bvNone
        TabOrder = 3
      end
      object Panel3: TPanel
        Left = 0
        Top = 527
        Width = 760
        Height = 54
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Align = alBottom
        BevelOuter = bvNone
        TabOrder = 4
      end
    end
  end
end
