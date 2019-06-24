object FormaReportOCBRegOstNom: TFormaReportOCBRegOstNom
  Left = 308
  Top = 124
  Caption = #1086#1089#1090#1072#1090#1082#1080' '#1080' '#1076#1074#1080#1078#1077#1085#1080#1103' '#1087#1072#1088#1090#1080#1081':'
  ClientHeight = 414
  ClientWidth = 449
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
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 378
    Height = 26
    Caption = #1054#1089#1090#1072#1090#1082#1080' '#1080' '#1076#1074#1080#1078#1077#1085#1080#1103' '#1087#1072#1088#1090#1080#1081' '#1090#1086#1074#1072#1088#1086#1074':'
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
    Top = 144
    Width = 34
    Height = 13
    Caption = #1057#1082#1083#1072#1076':'
  end
  object Label6: TLabel
    Left = 32
    Top = 118
    Width = 40
    Height = 13
    Caption = #1060#1080#1088#1084#1072':'
  end
  object Label7: TLabel
    Left = 32
    Top = 168
    Width = 38
    Height = 13
    Caption = #1043#1088#1091#1087#1087#1072' '
  end
  object Label8: TLabel
    Left = 16
    Top = 184
    Width = 77
    Height = 13
    Caption = #1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099':'
  end
  object Label9: TLabel
    Left = 16
    Top = 208
    Width = 77
    Height = 13
    Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072':'
  end
  object Label10: TLabel
    Left = 259
    Top = 301
    Width = 151
    Height = 13
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Caption = '* '#1090#1086#1083#1100#1082#1086' '#1076#1083#1103' '#1074#1085#1077#1096#1085#1080#1093' '#1086#1090#1095#1077#1090#1086#1074
  end
  object cxButtonCreate: TcxButton
    Left = 248
    Top = 382
    Width = 99
    Height = 25
    Caption = #1057#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 11
    OnClick = cxButtonCreateClick
  end
  object cxButtonClose: TcxButton
    Left = 353
    Top = 382
    Width = 75
    Height = 25
    Action = ActionClose
    TabOrder = 12
  end
  object TypePriceComboBox: TcxComboBox
    Left = 99
    Top = 267
    Properties.DropDownListStyle = lsFixedList
    Properties.OnChange = TypePriceComboBoxPropertiesChange
    TabOrder = 7
    Width = 297
  end
  object PriceCheckBox: TcxCheckBox
    Left = 96
    Top = 240
    Caption = #1042#1099#1074#1086#1076#1080#1090#1100' '#1086#1089#1090#1072#1090#1082#1080' '#1080' '#1076#1074#1080#1078#1077#1085#1080#1103' '#1090#1086#1074#1072#1088#1086#1074' '#1074' '#1094#1077#1085#1072#1093':'
    TabOrder = 6
    Width = 273
  end
  object NameNomEdit: TcxButtonEdit
    Left = 99
    Top = 203
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
    TabOrder = 5
    Text = 'NameNomEdit'
    Width = 313
  end
  object NameGrpNomEdit: TcxButtonEdit
    Left = 99
    Top = 176
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
    TabOrder = 4
    Text = 'NameGrpNomEdit'
    Width = 313
  end
  object NameSkladEdit: TcxButtonEdit
    Left = 99
    Top = 142
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
    TabOrder = 3
    Text = 'NameSkladEdit'
    Width = 310
  end
  object NameFirmEdit: TcxButtonEdit
    Left = 99
    Top = 115
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
    TabOrder = 2
    Text = 'NameFirmEdit'
    Width = 310
  end
  object DateNach: TcxDateEdit
    Left = 56
    Top = 56
    Properties.Kind = ckDateTime
    TabOrder = 0
    Width = 121
  end
  object DateCon: TcxDateEdit
    Left = 280
    Top = 56
    Properties.Kind = ckDateTime
    TabOrder = 1
    Width = 121
  end
  object DocDvcxCheckBox: TcxCheckBox
    Left = 16
    Top = 294
    Caption = #1089' '#1076#1086#1082#1091#1084#1077#1085#1090#1072#1084#1080' '#1076#1074#1080#1078#1077#1085#1080#1103
    TabOrder = 8
    Width = 169
  end
  object cxButton1: TcxButton
    Left = 135
    Top = 382
    Width = 107
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
    TabOrder = 13
  end
  object cxLabel9: TcxLabel
    Left = 4
    Top = 321
    Caption = #1041#1080#1079#1085#1077#1089' '#1086#1087#1077#1088#1072#1094#1080#1103'*:'
  end
  object cxLabel3: TcxLabel
    Left = 32
    Top = 347
    Caption = #1055#1088#1086#1077#1082#1090'*:'
  end
  object NameBusinessOpercxButtonEdit: TcxButtonEdit
    Left = 113
    Top = 320
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end
      item
        Caption = 'X'
        Kind = bkText
      end>
    Properties.ClickKey = 13
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameBusinessOpercxButtonEditPropertiesButtonClick
    TabOrder = 9
    Text = 'NameBusinessOpercxButtonEdi'
    Width = 305
  end
  object NameProjectcxButtonEdit: TcxButtonEdit
    Left = 113
    Top = 346
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end
      item
        Caption = 'X'
        Kind = bkText
      end>
    Properties.ClickKey = 13
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameProjectcxButtonEditPropertiesButtonClick
    TabOrder = 10
    Text = 'NameProjectcxButtonEdit'
    Width = 305
  end
  object IBTr: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 416
    Top = 24
  end
  object TypePrice: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from STPRICE')
    Transaction = IBTr
    Left = 416
    Top = 88
    object TypePriceID_TPRICE: TFIBBCDField
      FieldName = 'ID_TPRICE'
      Size = 0
      RoundByScale = True
    end
    object TypePriceNAME_TPRICE: TFIBWideStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
    end
  end
  object IBQ: TpFIBDataSet
    SelectSQL.Strings = (
      'select  *'
      ''
      
        'from  OCB_RGOSTNOM_FULL_REPORT  (:PARAM_POSNACH, :PARAM_POSCON, ' +
        ':PARAM_IDFIRM, :PARAM_IDSKLAD, :PARAM_IDGRP, :PARAM_IDNOM)'
      ''
      '')
    Transaction = IBTr
    Left = 408
    Top = 248
    oFetchAll = True
    object IBQPOSDOC_PROC: TFIBDateTimeField
      FieldName = 'POSDOC_PROC'
    end
    object IBQNACHOSTKOL_PROC: TFIBBCDField
      FieldName = 'NACHOSTKOL_PROC'
      Size = 3
      RoundByScale = True
    end
    object IBQNACHOSTSUM_PROC: TFIBBCDField
      FieldName = 'NACHOSTSUM_PROC'
      Size = 2
      RoundByScale = True
    end
    object IBQPRIHODKOL_PROC: TFIBBCDField
      FieldName = 'PRIHODKOL_PROC'
      Size = 3
      RoundByScale = True
    end
    object IBQPRIHODSUM_PROC: TFIBBCDField
      FieldName = 'PRIHODSUM_PROC'
      Size = 2
      RoundByScale = True
    end
    object IBQRASHODKOL_PROC: TFIBBCDField
      FieldName = 'RASHODKOL_PROC'
      Size = 3
      RoundByScale = True
    end
    object IBQRASHODSUM_PROC: TFIBBCDField
      FieldName = 'RASHODSUM_PROC'
      Size = 2
      RoundByScale = True
    end
    object IBQCONOSTKOL_PROC: TFIBBCDField
      FieldName = 'CONOSTKOL_PROC'
      Size = 3
      RoundByScale = True
    end
    object IBQCONOSTSUM_PROC: TFIBBCDField
      FieldName = 'CONOSTSUM_PROC'
      Size = 2
      RoundByScale = True
    end
    object IBQIDFIRM_PROC: TFIBBCDField
      FieldName = 'IDFIRM_PROC'
      Size = 0
      RoundByScale = True
    end
    object IBQIDSKLAD_PROC: TFIBBCDField
      FieldName = 'IDSKLAD_PROC'
      Size = 0
      RoundByScale = True
    end
    object IBQIDGRP_PROC: TFIBBCDField
      FieldName = 'IDGRP_PROC'
      Size = 0
      RoundByScale = True
    end
    object IBQIDNOM_PROC: TFIBBCDField
      FieldName = 'IDNOM_PROC'
      Size = 0
      RoundByScale = True
    end
    object IBQIDPART_PROC: TFIBBCDField
      FieldName = 'IDPART_PROC'
      Size = 0
      RoundByScale = True
    end
    object IBQIDED_PROC: TFIBBCDField
      FieldName = 'IDED_PROC'
      Size = 0
      RoundByScale = True
    end
    object IBQNAMEFIRM_PROC: TFIBWideStringField
      FieldName = 'NAMEFIRM_PROC'
      Size = 100
    end
    object IBQNAMESKLAD_PROC: TFIBWideStringField
      FieldName = 'NAMESKLAD_PROC'
      Size = 100
    end
    object IBQNAMEGRP_PROC: TFIBWideStringField
      FieldName = 'NAMEGRP_PROC'
      Size = 100
    end
    object IBQNAMENOM_PROC: TFIBWideStringField
      FieldName = 'NAMENOM_PROC'
      Size = 100
    end
    object IBQNAMEPART_PROC: TFIBWideStringField
      FieldName = 'NAMEPART_PROC'
      Size = 100
    end
    object IBQNAMEED_PROC: TFIBWideStringField
      FieldName = 'NAMEED_PROC'
      Size = 30
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 16
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
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 88
    Top = 320
  end
end
