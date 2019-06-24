object REM_FormaReportKartTovara: TREM_FormaReportKartTovara
  Left = 308
  Top = 124
  Caption = #1054#1090#1095#1077#1090' '#1050#1072#1088#1090#1086#1095#1082#1072' '#1090#1086#1074#1072#1088#1072
  ClientHeight = 440
  ClientWidth = 829
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 829
    Height = 235
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 7
      Top = 7
      Width = 234
      Height = 26
      Caption = #1054#1090#1095#1077#1090' '#1050#1072#1088#1090#1086#1095#1082#1072' '#1090#1086#1074#1072#1088#1072
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 8
      Top = 48
      Width = 12
      Height = 26
      Caption = 'c'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 224
      Top = 48
      Width = 24
      Height = 26
      Caption = #1087#1086
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 32
      Top = 118
      Width = 34
      Height = 13
      Caption = #1057#1082#1083#1072#1076':'
    end
    object Label6: TLabel
      Left = 32
      Top = 92
      Width = 40
      Height = 13
      Caption = #1060#1080#1088#1084#1072':'
    end
    object Label7: TLabel
      Left = 32
      Top = 142
      Width = 38
      Height = 13
      Caption = #1043#1088#1091#1087#1087#1072' '
    end
    object Label8: TLabel
      Left = 16
      Top = 158
      Width = 77
      Height = 13
      Caption = #1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099':'
    end
    object Label9: TLabel
      Left = 16
      Top = 182
      Width = 77
      Height = 13
      Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072':'
    end
    object NameNomEdit: TcxButtonEdit
      Left = 99
      Top = 180
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end
        item
          Caption = 'X'
          Kind = bkText
        end>
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameNomEditPropertiesButtonClick
      TabOrder = 0
      Text = 'NameNomEdit'
      Width = 310
    end
    object NameGrpNomEdit: TcxButtonEdit
      Left = 99
      Top = 150
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end
        item
          Caption = 'X'
          Kind = bkText
        end>
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameGrpNomEditPropertiesButtonClick
      TabOrder = 1
      Text = 'NameGrpNomEdit'
      Width = 310
    end
    object NameSkladEdit: TcxButtonEdit
      Left = 99
      Top = 116
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end
        item
          Caption = 'X'
          Kind = bkText
        end>
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameSkladEditPropertiesButtonClick
      TabOrder = 2
      Text = 'NameSkladEdit'
      Width = 310
    end
    object NameFirmEdit: TcxButtonEdit
      Left = 99
      Top = 89
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end
        item
          Caption = 'X'
          Kind = bkText
        end>
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameFirmEditPropertiesButtonClick
      TabOrder = 3
      Text = 'NameFirmEdit'
      Width = 310
    end
    object DateNach: TcxDateEdit
      Left = 56
      Top = 56
      Properties.Kind = ckDateTime
      TabOrder = 4
      Width = 121
    end
    object DateCon: TcxDateEdit
      Left = 280
      Top = 56
      Properties.Kind = ckDateTime
      TabOrder = 5
      Width = 121
    end
    object DocDvcxCheckBox: TcxCheckBox
      Left = 453
      Top = 176
      Caption = #1089' '#1076#1086#1082#1091#1084#1077#1085#1090#1072#1084#1080' '#1076#1074#1080#1078#1077#1085#1080#1103
      TabOrder = 6
      Width = 169
    end
    object cxButtonUpdate: TcxButton
      Left = 488
      Top = 140
      Width = 91
      Height = 20
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1054#1073#1085#1086#1074#1080#1090#1100
      TabOrder = 7
      OnClick = cxButtonUpdateClick
    end
    object cxLabel1: TcxLabel
      Left = 49
      Top = 214
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1054#1089#1090#1072#1090#1086#1082' '#1085#1072' '#1085#1072#1095#1072#1083#1086':'
    end
    object OstNaNachcxLabel: TcxLabel
      Left = 160
      Top = 214
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = 'OstNaNachcxLabel'
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 377
    Width = 829
    Height = 63
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object cxButtonClose: TcxButton
      Left = 442
      Top = 28
      Width = 76
      Height = 25
      Caption = #1047#1072#1082#1088#1099#1090#1100
      TabOrder = 0
      OnClick = ActionCloseExecute
    end
    object cxButton1: TcxButton
      Left = 328
      Top = 28
      Width = 108
      Height = 25
      Caption = #1042#1085#1077#1096#1085#1080#1081' '#1086#1090#1095#1077#1090
      DropDownMenu = PopupMenuExtModule
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000523D277B6D57
        409A6D563E9A6D563E9A6E573F9A6E573F9A6D563E9A6D563E9A6D553E9A6E56
        3F9A6E563F9A6D553D9A6D553E9A6D553D9A6E57409A523C277BD1BA8DFFFFFF
        FAFFFFFFEFFFFFFFF1FFF9F2DDFFD1BA8DFFFFFEEFFFFFFAEBFFFFFBEDFFF8E9
        D8FFD1BA8DFFFFF6EAFFFFF3E7FFFFF3E9FFFAE8DCFFCCAA8FF6C8B287F4E8DC
        B4FFD1BA8DFFE7D6AFFFE1CBA3FFD1BA8DFFE7D0ACFFD1BA8DFFE7CCAAFFE0C0
        9EFFD1BA8DFFE7C5A7FFD1BA8DFFE7C1A4FFE2B99CFFC39775F460462B8D7B5E
        3CAD7A5C3AAD7A5C3AAD7B5C3AAD7A5C3AAD7A5A39AD795A39AC7C5A39AE7E5C
        3BB27C5B3AB27A5939B27A5838B27A5837B27B5939B2604429910303000B0604
        0013060400130504001305040013050400130504001305040013010100050000
        00000000000000000000000000000000000000000000000000003B4822C081AA
        78FF82A977FF86AE7BFF8CB380FF91B885FF96BD8AFF9EC493FF82A373EF1C21
        097D020100090000000000000000000000000000000000000000495B34C2A9E1
        AEFFABE0ADFFB1E6B3FFB8EDBAFFBFF4C1FFC7FCC9FFCFFFD1FFCDFFD0FF8DBF
        8CFF485E34D71011015300000002000000000000000000000000475831C1A4DA
        A7FFA6D9A6FFACDFACFFB3E6B3FFBAEDBAFFC1F4C1FFC9FCC9FFC5F8C5FF90C4
        91FF81B885FF608451FF0908002C000000000000000000000000475831C1A4DA
        A7FFA6D9A6FFACDFACFFB3E6B3FFBAEDBAFFC1F4C1FFC9FCC9FFC4F7C4FF8FC2
        8FFF7DB27FFF668F5CFF0A0A0031000000000000000000000000475831C1A4DA
        A7FFA6D9A6FFACDFACFFB3E6B3FFBAEDBAFFC1F4C1FFC9FCC9FFC4F7C4FF8FC2
        8FFF7DB27FFF658C5AFE0A090030000000000000000000000000475831C1A4DA
        A7FFA6D9A6FFACDFACFFB3E6B3FFBAEDBAFFC1F4C1FFC9FCC9FFC4F7C4FF8FC2
        8FFF7DB27FFF658C5AFE0A090030000000000000000000000000485932C1A6DD
        AAFFA8DCA9FFAEE2AFFFB5E9B6FFBCF0BDFFC3F7C4FFCCFFCCFFC6FAC7FF8FC2
        8FFF7DB27FFF658C5AFE0A09003000000000000000000000000048582FCB99CA
        97FF99C592FF9EC997FFA4D09DFFAAD6A3FFB1DCAAFFB7E2B1FFB8E5B3FF93C7
        94FF7EB380FF658C5AFE0A0900300000000000000000000000001212015A3E4D
        20E55C8350FF5E8754FF648B59FF6D9162FF678C5BFF678C5DFF658554FF6B8B
        59FF7BAE7BFF68915FFE0A090030000000000000000000000000000000000303
        001122280C90587F4DFA71A272FF7BA87BFF74A374FF74A374FF74A374FF5F8B
        58FF54713FFF55703DFF0A0A0033000000000000000000000000000000000000
        00000000000011120152242A0C93232A0C93232A0C93232A0C93232A0C93242B
        0E9322280A931E1E01920505001B000000000000000000000000}
      Kind = cxbkDropDown
      TabOrder = 1
    end
    object cxLabel3: TcxLabel
      Left = 56
      Top = 5
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1054#1089#1090#1072#1090#1086#1082' '#1085#1072' '#1082#1086#1085#1077#1094':'
    end
    object OstNaConcxLabel: TcxLabel
      Left = 169
      Top = 5
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = 'OstNaConcxLabel'
    end
  end
  object cxGrid1: TcxGrid
    Left = 0
    Top = 235
    Width = 829
    Height = 142
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Align = alClient
    TabOrder = 2
    object cxGrid1DBTableView1: TcxGridDBTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.DataSource = DataSource
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsView.ColumnAutoWidth = True
      object cxGrid1DBTableView1OUT_POS: TcxGridDBColumn
        DataBinding.FieldName = 'OUT_POS'
      end
      object cxGrid1DBTableView1OUT_TDOC: TcxGridDBColumn
        DataBinding.FieldName = 'OUT_TDOC'
      end
      object cxGrid1DBTableView1OUT_NUM: TcxGridDBColumn
        DataBinding.FieldName = 'OUT_NUM'
      end
      object cxGrid1DBTableView1OUT_TDV: TcxGridDBColumn
        DataBinding.FieldName = 'OUT_TDV'
      end
      object cxGrid1DBTableView1OUT_KOL_PRIHOD: TcxGridDBColumn
        DataBinding.FieldName = 'OUT_KOL_PRIHOD'
      end
      object cxGrid1DBTableView1OUT_KOL_RASHOD: TcxGridDBColumn
        DataBinding.FieldName = 'OUT_KOL_RASHOD'
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 56
    Top = 304
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 16
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
  end
  object pFIBTransaction: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 640
    Top = 104
  end
  object pFIBDataSet: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      
        'from REM_REPORT_KART_TOVARA (:PARAM_POS_START,:PARAM_POS_END,:PA' +
        'RAM_IDFIRM,:PARAM_IDSKLAD,:PARAM_IDNOM)')
    Transaction = pFIBTransaction
    Left = 768
    Top = 48
    object pFIBDataSetOUT_POS: TFIBDateTimeField
      FieldName = 'OUT_POS'
    end
    object pFIBDataSetOUT_TDOC: TFIBWideStringField
      FieldName = 'OUT_TDOC'
      OnGetText = pFIBDataSetOUT_TDOCGetText
      Size = 10
    end
    object pFIBDataSetOUT_NUM: TFIBIntegerField
      FieldName = 'OUT_NUM'
    end
    object pFIBDataSetOUT_TDV: TFIBSmallIntField
      FieldName = 'OUT_TDV'
    end
    object pFIBDataSetOUT_KOL_PRIHOD: TFIBBCDField
      FieldName = 'OUT_KOL_PRIHOD'
      Size = 3
      RoundByScale = True
    end
    object pFIBDataSetOUT_KOL_RASHOD: TFIBBCDField
      FieldName = 'OUT_KOL_RASHOD'
      Size = 3
      RoundByScale = True
    end
  end
  object DataSource: TDataSource
    DataSet = pFIBDataSet
    Left = 864
    Top = 48
  end
  object OstNaNach: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      
        'from REM_RGGOODS_GET_OSTATOK_NA (:PARAM_POS,:PARAM_IDFIRM,:PARAM' +
        '_IDSKLAD,:PARAM_IDNOM,:PARAM_IDTNOM)')
    Transaction = pFIBTransaction
    Left = 768
    Top = 128
    object OstNaNachOUT_KOL: TFIBBCDField
      FieldName = 'OUT_KOL'
      OnGetText = OstNaNachOUT_KOLGetText
      Size = 3
      RoundByScale = True
    end
  end
  object OstNaCon: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      
        'from REM_RGGOODS_GET_OSTATOK_NA (:PARAM_POS,:PARAM_IDFIRM,:PARAM' +
        '_IDSKLAD,:PARAM_IDNOM,:PARAM_IDTNOM)')
    Transaction = pFIBTransaction
    Left = 768
    Top = 192
    object OstNaConOUT_KOL: TFIBBCDField
      FieldName = 'OUT_KOL'
      OnGetText = OstNaConOUT_KOLGetText
      Size = 3
      RoundByScale = True
    end
  end
end
