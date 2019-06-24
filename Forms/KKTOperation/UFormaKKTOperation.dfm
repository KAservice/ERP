object FormaKKTOperation: TFormaKKTOperation
  Left = 0
  Top = 0
  Caption = #1056#1072#1073#1086#1090#1072' '#1089' '#1082#1086#1085#1090#1088#1086#1083#1100#1085#1086'-'#1082#1072#1089#1089#1086#1074#1086#1081' '#1090#1077#1093#1085#1080#1082#1086#1081
  ClientHeight = 560
  ClientWidth = 742
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  PixelsPerInch = 96
  TextHeight = 13
  object cxPageControl1: TcxPageControl
    Left = 0
    Top = 41
    Width = 742
    Height = 471
    ActivePage = cxTabSheet2
    Align = alClient
    TabOrder = 0
    ClientRectBottom = 471
    ClientRectRight = 742
    ClientRectTop = 24
    object cxTabSheet1: TcxTabSheet
      Caption = #1056#1077#1075#1080#1089#1090#1088#1072#1094#1080#1103
      ImageIndex = 0
      object cxGrid1: TcxGrid
        Left = 0
        Top = 57
        Width = 742
        Height = 295
        Align = alClient
        TabOrder = 0
        object cxGrid1DBTableView1: TcxGridDBTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <>
          DataController.Summary.SummaryGroups = <>
        end
        object cxGrid1TableView1: TcxGridTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <
            item
              Kind = skSum
              Column = cxGrid1TableView1Sum
            end>
          DataController.Summary.SummaryGroups = <>
          DataController.Data = {
            9D0100000F00000044617461436F6E74726F6C6C657231050000001300000054
            6378496E746567657256616C75655479706512000000546378537472696E6756
            616C75655479706511000000546378466C6F617456616C756554797065110000
            00546378466C6F617456616C75655479706511000000546378466C6F61745661
            6C75655479706504000000445855464D54000001000000000700000022043E04
            32043004400420003200000000000000000080FF3F0000000000000000C00040
            0000000000000000C00040445855464D54000001000000000500000022043E04
            3204300440040000000000000000800040000000000000000080014000000000
            00000000800240445855464D54000001000000000E0000001504490435042000
            3E04340438043D04200042043E043204300440040000000000000000C0004000
            0000000000000080FF3F0000000000000000C00040445855464D540000010000
            00000D00000022043E0432043004400420003D043E043C043504400420003400
            0000000000000000800040000000000000000080004000000000000000008001
            40}
          OptionsCustomize.ColumnHiding = True
          OptionsCustomize.ColumnsQuickCustomization = True
          OptionsView.Navigator = True
          OptionsView.ColumnAutoWidth = True
          OptionsView.Footer = True
          object cxGrid1TableView1Department: TcxGridColumn
            Caption = #1054#1090#1076#1077#1083
            DataBinding.ValueType = 'Integer'
            PropertiesClassName = 'TcxCalcEditProperties'
            Width = 77
          end
          object cxGrid1TableView1NameTovar: TcxGridColumn
            Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
            Width = 427
          end
          object cxGrid1TableView1Kol: TcxGridColumn
            Caption = #1050#1086#1083'.'
            DataBinding.ValueType = 'Float'
            PropertiesClassName = 'TcxCalcEditProperties'
            Width = 54
          end
          object cxGrid1TableView1Price: TcxGridColumn
            Caption = #1062#1077#1085#1072
            DataBinding.ValueType = 'Float'
            PropertiesClassName = 'TcxCalcEditProperties'
            SortIndex = 0
            SortOrder = soAscending
            Width = 75
          end
          object cxGrid1TableView1Sum: TcxGridColumn
            Caption = #1057#1091#1084#1084#1072
            DataBinding.ValueType = 'Float'
            PropertiesClassName = 'TcxCalcEditProperties'
            Width = 107
          end
        end
        object cxGrid1Level1: TcxGridLevel
          GridView = cxGrid1TableView1
        end
      end
      object Panel3: TPanel
        Left = 0
        Top = 0
        Width = 742
        Height = 57
        Align = alTop
        BevelOuter = bvNone
        TabOrder = 1
        object GroupBox1: TGroupBox
          Left = 17
          Top = 10
          Width = 302
          Height = 41
          Caption = #1058#1080#1087' '#1095#1077#1082#1072
          TabOrder = 0
          object RadioButtonSale: TRadioButton
            Left = 17
            Top = 16
            Width = 113
            Height = 17
            Caption = #1087#1088#1086#1076#1072#1078#1072
            Checked = True
            TabOrder = 0
            TabStop = True
          end
          object RadioButtonReturnSale: TRadioButton
            Left = 168
            Top = 16
            Width = 113
            Height = 17
            Caption = #1074#1086#1079#1074#1088#1072#1090
            TabOrder = 1
          end
        end
      end
      object Panel4: TPanel
        Left = 0
        Top = 352
        Width = 742
        Height = 95
        Align = alBottom
        BevelOuter = bvNone
        TabOrder = 2
        object cxButtonSale: TcxButton
          Left = 518
          Top = 30
          Width = 131
          Height = 38
          Caption = #1055#1088#1086#1073#1080#1090#1100' '#1095#1077#1082
          TabOrder = 0
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          OnClick = cxButtonSaleClick
        end
        object OplataNalcxCalcEdit: TcxCalcEdit
          Left = 34
          Top = 40
          EditValue = 18.000000000000000000
          ParentFont = False
          Style.Font.Charset = DEFAULT_CHARSET
          Style.Font.Color = clWindowText
          Style.Font.Height = -13
          Style.Font.Name = 'Tahoma'
          Style.Font.Style = [fsBold]
          Style.IsFontAssigned = True
          TabOrder = 1
          Width = 121
        end
        object OplataPlatCardcxCalcEdit: TcxCalcEdit
          Left = 213
          Top = 40
          EditValue = 10.000000000000000000
          ParentFont = False
          Style.Font.Charset = DEFAULT_CHARSET
          Style.Font.Color = clWindowText
          Style.Font.Height = -13
          Style.Font.Name = 'Tahoma'
          Style.Font.Style = [fsBold]
          Style.IsFontAssigned = True
          TabOrder = 2
          Width = 124
        end
        object cxLabel2: TcxLabel
          Left = 17
          Top = 14
          Caption = #1054#1087#1083#1072#1090#1072' '#1085#1072#1083#1080#1095#1085#1099#1084#1080':'
          ParentFont = False
          Style.Font.Charset = DEFAULT_CHARSET
          Style.Font.Color = clWindowText
          Style.Font.Height = -13
          Style.Font.Name = 'Tahoma'
          Style.Font.Style = [fsBold]
          Style.IsFontAssigned = True
        end
        object cxLabel3: TcxLabel
          Left = 197
          Top = 14
          Caption = #1054#1087#1083#1072#1090#1072' '#1087#1083#1072#1090'. '#1082#1072#1088#1090#1086#1081':'
          ParentFont = False
          Style.Font.Charset = DEFAULT_CHARSET
          Style.Font.Color = clWindowText
          Style.Font.Height = -13
          Style.Font.Name = 'Tahoma'
          Style.Font.Style = [fsBold]
          Style.IsFontAssigned = True
        end
      end
    end
    object cxTabSheet2: TcxTabSheet
      Caption = #1054#1090#1095#1077#1090#1099
      ImageIndex = 1
      object cxButtonXReport: TcxButton
        Left = 86
        Top = 48
        Width = 199
        Height = 40
        Caption = #1061' '#1086#1090#1095#1077#1090
        TabOrder = 0
        OnClick = cxButtonXReportClick
      end
      object cxButtonZReport: TcxButton
        Left = 86
        Top = 128
        Width = 199
        Height = 40
        Caption = 'Z '#1086#1090#1095#1077#1090
        TabOrder = 1
        OnClick = cxButtonZReportClick
      end
    end
    object cxTabSheet3: TcxTabSheet
      Caption = #1044#1072#1090#1072' '#1080' '#1074#1088#1077#1084#1103
      ImageIndex = 2
      object cxGroupBox1: TcxGroupBox
        Left = 3
        Top = 3
        Caption = #1042#1088#1077#1084#1103
        TabOrder = 0
        Height = 102
        Width = 366
        object Label1: TLabel
          Left = 224
          Top = 29
          Width = 34
          Height = 13
          Caption = #1042#1088#1077#1084#1103':'
        end
        object cxButtonSetTimeKKM: TcxButton
          Left = 16
          Top = 63
          Width = 145
          Height = 25
          Caption = #1059#1089#1090#1072#1085#1086#1074#1080#1090#1100' '#1074#1088#1077#1084#1103
          TabOrder = 0
          OnClick = cxButtonSetTimeKKMClick
        end
        object cxButtonGetTekPCTime: TcxButton
          Left = 16
          Top = 24
          Width = 145
          Height = 25
          Caption = #1058#1077#1082#1091#1097#1077#1077' '#1074#1088#1077#1084#1103' ('#1082#1086#1084#1087'.)'
          TabOrder = 1
          OnClick = cxButtonGetTekPCTimeClick
        end
        object cxButtonGetTimeFR: TcxButton
          Left = 198
          Top = 63
          Width = 145
          Height = 25
          Caption = #1055#1086#1083#1091#1095#1080#1090#1100' '#1074#1088#1077#1084#1103' '#1080#1079' '#1050#1050#1052
          TabOrder = 2
          OnClick = cxButtonGetTimeFRClick
        end
        object cxTimeEdit: TcxTimeEdit
          Left = 264
          Top = 26
          EditValue = 0d
          TabOrder = 3
          Width = 79
        end
      end
      object cxGroupBox2: TcxGroupBox
        Left = 3
        Top = 109
        Caption = #1044#1072#1090#1072
        TabOrder = 1
        Height = 108
        Width = 366
        object Label2: TLabel
          Left = 204
          Top = 33
          Width = 30
          Height = 13
          Caption = #1044#1072#1090#1072':'
        end
        object cxButtonGetTekPCDate: TcxButton
          Left = 16
          Top = 26
          Width = 145
          Height = 25
          Caption = #1058#1077#1082#1091#1097#1072#1103' '#1076#1072#1090#1072' ('#1082#1086#1084#1087'.)'
          TabOrder = 0
          OnClick = cxButtonGetTekPCDateClick
        end
        object cxButtonSetDateKKM: TcxButton
          Left = 16
          Top = 65
          Width = 145
          Height = 25
          Caption = #1059#1089#1090#1072#1085#1086#1074#1080#1090#1100' '#1076#1072#1090#1091
          TabOrder = 1
          OnClick = cxButtonSetDateKKMClick
        end
        object cxButtonGetDateFR: TcxButton
          Left = 200
          Top = 63
          Width = 145
          Height = 25
          Caption = #1055#1086#1083#1091#1095#1080#1090#1100' '#1076#1072#1090#1091' '#1080#1079' '#1050#1050#1052
          TabOrder = 2
          OnClick = cxButtonGetDateFRClick
        end
        object cxDateEdit: TcxDateEdit
          Left = 240
          Top = 28
          TabOrder = 3
          Width = 105
        end
      end
    end
    object cxTabSheet4: TcxTabSheet
      Caption = #1057#1084#1077#1085#1072
      ImageIndex = 3
      object cxButtonOpenShift: TcxButton
        Left = 75
        Top = 32
        Width = 118
        Height = 33
        Caption = #1054#1090#1082#1088#1099#1090#1100' '#1089#1084#1077#1085#1091
        TabOrder = 0
        OnClick = cxButtonOpenShiftClick
      end
      object cxButtonCloseShift: TcxButton
        Left = 75
        Top = 80
        Width = 118
        Height = 33
        Caption = #1047#1072#1082#1088#1099#1090#1100' '#1089#1084#1077#1085#1091
        TabOrder = 1
        OnClick = cxButtonCloseShiftClick
      end
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 742
    Height = 41
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 1
    object Label3: TLabel
      Left = 75
      Top = 8
      Width = 32
      Height = 16
      Caption = #1050#1050#1052':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold, fsUnderline]
      ParentFont = False
    end
    object cxComboBoxFR: TcxComboBox
      Left = 121
      Top = 6
      Properties.DropDownListStyle = lsFixedList
      TabOrder = 0
      Width = 198
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 512
    Width = 742
    Height = 48
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 2
    object cxButtonClose: TcxButton
      Left = 646
      Top = 6
      Width = 75
      Height = 25
      Caption = #1047#1072#1082#1088#1099#1090#1100
      TabOrder = 0
      OnClick = cxButtonCloseClick
    end
    object cxLabel1: TcxLabel
      Left = 324
      Top = 95
      Caption = #1057#1091#1084#1084#1072':'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clWindowText
      Style.Font.Height = -13
      Style.Font.Name = 'Tahoma'
      Style.Font.Style = [fsBold]
      Style.IsFontAssigned = True
    end
  end
end
