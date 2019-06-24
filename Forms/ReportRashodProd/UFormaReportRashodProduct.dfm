object FormaReportRashodProduct: TFormaReportRashodProduct
  Left = 314
  Top = 124
  Caption = #1056#1072#1089#1093#1086#1076' '#1087#1088#1086#1076#1091#1082#1090#1086#1074':'
  ClientHeight = 363
  ClientWidth = 466
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
    Left = 24
    Top = 8
    Width = 188
    Height = 26
    Caption = #1056#1072#1089#1093#1086#1076' '#1087#1088#1086#1076#1091#1082#1090#1086#1074':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 16
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
    Left = 48
    Top = 112
    Width = 34
    Height = 13
    Caption = #1057#1082#1083#1072#1076':'
  end
  object Label6: TLabel
    Left = 8
    Top = 144
    Width = 77
    Height = 13
    Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072':'
  end
  object Label5: TLabel
    Left = 32
    Top = 176
    Width = 43
    Height = 13
    Caption = #1058#1080#1087' '#1094#1077#1085':'
  end
  object Label7: TLabel
    Left = 44
    Top = 88
    Width = 40
    Height = 13
    Caption = #1060#1080#1088#1084#1072':'
  end
  object Label10: TLabel
    Left = 259
    Top = 223
    Width = 151
    Height = 13
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Caption = '* '#1090#1086#1083#1100#1082#1086' '#1076#1083#1103' '#1074#1085#1077#1096#1085#1080#1093' '#1086#1090#1095#1077#1090#1086#1074
  end
  object cxButtonCreate: TcxButton
    Left = 252
    Top = 314
    Width = 92
    Height = 25
    Caption = #1057#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 9
    OnClick = cxButtonCreateClick
  end
  object cxButtonClose: TcxButton
    Left = 350
    Top = 314
    Width = 75
    Height = 25
    Action = ActionClose
    TabOrder = 10
  end
  object PoDateCheckBox: TcxCheckBox
    Left = 100
    Top = 211
    Caption = #1087#1086' '#1076#1072#1090#1072#1084
    TabOrder = 6
    Width = 121
  end
  object TypePriceComboBox: TcxComboBox
    Left = 100
    Top = 172
    Properties.DropDownListStyle = lsFixedList
    Properties.OnChange = TypePriceComboBoxPropertiesChange
    TabOrder = 5
    Width = 293
  end
  object NameNomEdit: TcxButtonEdit
    Left = 100
    Top = 139
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
    TabOrder = 4
    Text = 'NameNomEdit'
    Width = 293
  end
  object NameSkladEdit: TcxButtonEdit
    Left = 100
    Top = 112
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
    Width = 293
  end
  object DateNach: TcxDateEdit
    Left = 56
    Top = 56
    Properties.Kind = ckDateTime
    TabOrder = 0
    Width = 121
  end
  object DateCon: TcxDateEdit
    Left = 272
    Top = 56
    Properties.Kind = ckDateTime
    TabOrder = 1
    Width = 121
  end
  object NameFirmEdit: TcxButtonEdit
    Left = 100
    Top = 85
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
    Width = 293
  end
  object cxLabel9: TcxLabel
    Left = 4
    Top = 243
    Caption = #1041#1080#1079#1085#1077#1089' '#1086#1087#1077#1088#1072#1094#1080#1103'*:'
  end
  object cxLabel3: TcxLabel
    Left = 32
    Top = 269
    Caption = #1055#1088#1086#1077#1082#1090'*:'
  end
  object NameBusinessOpercxButtonEdit: TcxButtonEdit
    Left = 113
    Top = 242
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
    TabOrder = 7
    Text = 'NameBusinessOpercxButtonEdi'
    Width = 305
  end
  object NameProjectcxButtonEdit: TcxButtonEdit
    Left = 113
    Top = 268
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
    TabOrder = 8
    Text = 'NameProjectcxButtonEdit'
    Width = 305
  end
  object cxButton1: TcxButton
    Left = 139
    Top = 314
    Width = 106
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
  object TypePrice: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from STPRICE')
    Transaction = IBTr
    Left = 400
    Top = 8
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
      
        ' select sgrpnom.namegn, sgrpnom.idgn, snom.namenom, snom.idnom ,' +
        'sed.nameed, sum(rgsebprod_dv.kol_rgsebprod_dv) as KOLSUM, '
      'sum(rgsebprod_dv.sum_rgsebprod_dv) as SUM_SEB, '
      'sum(rgsebprod_dv.kolotr_rgsebprod_dv) as KOLSUM_OTR,'
      
        ' snom_VP.namenom as NAME_PROD, sed_VP.nameed as NAMEED_PROD, sum' +
        '(rgvipprod_dv.kol_rgvipprod_dv) as KOL_PROD'
      'from     rgsebprod_dv'
      
        ' left outer join snom on snom.idnom=rgsebprod_dv.idnom_rgsebprod' +
        '_dv'
      ' left outer join sgrpnom on snom.idgrpnom=sgrpnom.idgn'
      ' left outer join sed on sed.ided=snom.idbasednom'
      
        ' left outer join rgvipprod_dv on  rgvipprod_dv.id_rgvipprod_dv=r' +
        'gsebprod_dv.idvipprod_rgsebprod_dv'
      
        ' left outer join snom as snom_VP on rgvipprod_dv.idnom_rgvipprod' +
        '_dv=snom_VP.idnom'
      ' left outer join sed as sed_VP on snom_VP.idbasednom=sed_VP.ided'
      ''
      
        ' group by sgrpnom.namegn, sgrpnom.idgn, snom.namenom,  snom.idno' +
        'm, sed.nameed, snom_VP.namenom, sed_VP.nameed'
      ' order by  sgrpnom.namegn, snom.namenom')
    Transaction = IBTr
    Left = 136
    Top = 240
    object IBQKOLSUM: TFIBBCDField
      FieldName = 'KOLSUM'
      Size = 3
      RoundByScale = True
    end
    object IBQSUM_SEB: TFIBBCDField
      FieldName = 'SUM_SEB'
      Size = 2
      RoundByScale = True
    end
    object IBQKOLSUM_OTR: TFIBBCDField
      FieldName = 'KOLSUM_OTR'
      Size = 3
      RoundByScale = True
    end
    object IBQKOL_PROD: TFIBBCDField
      FieldName = 'KOL_PROD'
      Size = 3
      RoundByScale = True
    end
    object IBQIDGN: TFIBBCDField
      FieldName = 'IDGN'
      Size = 0
      RoundByScale = True
    end
    object IBQIDNOM: TFIBBCDField
      FieldName = 'IDNOM'
      Size = 0
      RoundByScale = True
    end
    object IBQNAMEGN: TFIBWideStringField
      FieldName = 'NAMEGN'
      Size = 100
    end
    object IBQNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 100
    end
    object IBQNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
    end
    object IBQNAMEED_PROD: TFIBWideStringField
      FieldName = 'NAMEED_PROD'
      Size = 100
    end
    object IBQNAME_PROD: TFIBWideStringField
      FieldName = 'NAME_PROD'
      Size = 100
    end
  end
  object IBTr: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 104
    Top = 240
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 32
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
    Left = 80
    Top = 376
  end
end
