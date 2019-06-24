object FormaReportVipuskProd: TFormaReportVipuskProd
  Left = 396
  Top = 347
  Caption = #1042#1099#1087#1091#1089#1082' '#1087#1088#1086#1076#1091#1082#1094#1080#1080':'
  ClientHeight = 295
  ClientWidth = 452
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
    Width = 194
    Height = 26
    Caption = #1042#1099#1087#1091#1089#1082' '#1087#1088#1086#1076#1091#1082#1094#1080#1080':'
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
    Left = 216
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
    Left = 46
    Top = 126
    Width = 34
    Height = 13
    Caption = #1057#1082#1083#1072#1076':'
  end
  object Label5: TLabel
    Left = 37
    Top = 181
    Width = 43
    Height = 13
    Caption = #1058#1080#1087' '#1094#1077#1085':'
  end
  object Label6: TLabel
    Left = 3
    Top = 153
    Width = 77
    Height = 13
    Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072':'
  end
  object Label7: TLabel
    Left = 40
    Top = 99
    Width = 40
    Height = 13
    Caption = #1060#1080#1088#1084#1072':'
  end
  object cxButtonCreate: TcxButton
    Left = 256
    Top = 262
    Width = 99
    Height = 25
    Caption = #1057#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 0
    OnClick = cxButtonCreateClick
  end
  object cxButtonClose: TcxButton
    Left = 361
    Top = 262
    Width = 75
    Height = 25
    Action = ActionClose
    TabOrder = 1
  end
  object PoDateCheckBox: TcxCheckBox
    Left = 96
    Top = 231
    Caption = #1087#1086' '#1076#1072#1090#1072#1084
    TabOrder = 2
    Width = 121
  end
  object StrRealCheckBox: TcxCheckBox
    Left = 96
    Top = 204
    Caption = #1087#1086#1082#1072#1079#1099#1074#1072#1090#1100' '#1089#1090#1088#1086#1082#1091' '#1088#1077#1072#1083#1080#1079#1072#1094#1080#1080
    TabOrder = 3
    Width = 209
  end
  object TypePriceComboBox: TcxComboBox
    Left = 96
    Top = 177
    Properties.DropDownListStyle = lsFixedList
    Properties.OnChange = TypePriceComboBoxPropertiesChange
    TabOrder = 4
    Width = 293
  end
  object NameNomEdit: TcxButtonEdit
    Left = 96
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
    Properties.OnButtonClick = NameNomEditPropertiesButtonClick
    TabOrder = 5
    Text = 'NameNomEdit'
    Width = 293
  end
  object NameSkladEdit: TcxButtonEdit
    Left = 96
    Top = 123
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
    TabOrder = 6
    Text = 'NameSkladEdit'
    Width = 293
  end
  object DateNach: TcxDateEdit
    Left = 40
    Top = 56
    Properties.Kind = ckDateTime
    TabOrder = 7
    Width = 121
  end
  object DateCon: TcxDateEdit
    Left = 280
    Top = 56
    Properties.Kind = ckDateTime
    TabOrder = 8
    Width = 121
  end
  object NameFirmEdit: TcxButtonEdit
    Left = 96
    Top = 96
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
    TabOrder = 9
    Text = 'NameFirmEdit'
    Width = 293
  end
  object cxButton1: TcxButton
    Left = 137
    Top = 262
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
    TabOrder = 10
  end
  object IBTr: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 296
    Top = 8
  end
  object TypePrice: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from STPRICE')
    Transaction = IBTr
    Left = 264
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
  object Grp: TpFIBDataSet
    SelectSQL.Strings = (
      'select  NAMEGN, IDGN,'
      '  SUM(SEB_RGVIPPROD_DV)  AS SEBPROD'
      'from '
      '  RGVIPPROD_DV'
      'left outer join SNOM on IDNOM_RGVIPPROD_DV=IDNOM'
      'left outer join SGRPNOM on IDGRPNOM=IDGN'
      
        'where POSDOC_RGVIPPROD_DV  between :PARAM_POSNACH and :PARAM_POS' +
        'CON'
      'group by NAMEGN, IDGN')
    Transaction = IBTr
    Left = 408
    Top = 80
    object GrpSEBPROD: TFIBBCDField
      FieldName = 'SEBPROD'
      Size = 2
      RoundByScale = True
    end
    object GrpIDGN: TFIBBCDField
      FieldName = 'IDGN'
      Size = 0
      RoundByScale = True
    end
    object GrpNAMEGN: TFIBWideStringField
      FieldName = 'NAMEGN'
      Size = 100
    end
  end
  object El: TpFIBDataSet
    SelectSQL.Strings = (
      'select  NAMENOM, NAMEED, IDNOM,'
      '  SUM(SEB_RGVIPPROD_DV)  AS SEBPROD,'
      '  SUM(KOL_RGVIPPROD_DV)  AS KOLPROD'
      'from '
      '   RGVIPPROD_DV'
      'left outer join SNOM on IDNOM_RGVIPPROD_DV=IDNOM'
      'left outer join SGRPNOM on IDGRPNOM=IDGN'
      'left outer join SED on IDBASEDNOM=IDED'
      
        'where (POSDOC_RGVIPPROD_DV  between :PARAM_POSNACH and :PARAM_PO' +
        'SCON)'
      'and  (IDGN=:PARAM_IDGN)'
      'group by NAMENOM, NAMEED, IDNOM'
      '')
    Transaction = IBTr
    Left = 408
    Top = 120
    object ElSEBPROD: TFIBBCDField
      FieldName = 'SEBPROD'
      Size = 2
      RoundByScale = True
    end
    object ElKOLPROD: TFIBBCDField
      FieldName = 'KOLPROD'
      Size = 3
      RoundByScale = True
    end
    object ElIDNOM: TFIBBCDField
      FieldName = 'IDNOM'
      Size = 0
      RoundByScale = True
    end
    object ElNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 100
    end
    object ElNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
    end
  end
  object IBQSebProd: TpFIBDataSet
    SelectSQL.Strings = (
      'select  NAMENOM, NAMEED, IDNOM,'
      '  SUM(SUM_RGSEBPROD_DV)  AS SEBPROD,'
      '  SUM(KOL_RGSEBPROD_DV)  AS KOLPROD,'
      '  SUM(KOLOTR_RGSEBPROD_DV)  AS KOLOTRPROD'
      ''
      'from '
      '   RGSEBPROD_DV'
      
        'left outer join RGVIPPROD_DV on IDVIPPROD_RGSEBPROD_DV=ID_RGVIPP' +
        'ROD_DV'
      'left outer join SNOM on IDNOM_RGSEBPROD_DV=IDNOM'
      'left outer join SED on IDBASEDNOM=IDED'
      
        'where (POSDOC_RGSEBPROD_DV  between :PARAM_POSNACH and :PARAM_PO' +
        'SCON)'
      'and  (IDNOM_RGVIPPROD_DV='#39'933'#39')'
      'group by NAMENOM, NAMEED, IDNOM')
    Transaction = IBTr
    Left = 408
    Top = 152
    object IBQSebProdSEBPROD: TFIBBCDField
      FieldName = 'SEBPROD'
      Size = 2
      RoundByScale = True
    end
    object IBQSebProdKOLPROD: TFIBBCDField
      FieldName = 'KOLPROD'
      Size = 3
      RoundByScale = True
    end
    object IBQSebProdKOLOTRPROD: TFIBBCDField
      FieldName = 'KOLOTRPROD'
      Size = 3
      RoundByScale = True
    end
    object IBQSebProdIDNOM: TFIBBCDField
      FieldName = 'IDNOM'
      Size = 0
      RoundByScale = True
    end
    object IBQSebProdNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 100
    end
    object IBQSebProdNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
    end
  end
  object IBQRealGrp: TpFIBDataSet
    SelectSQL.Strings = (
      'select  NAMEGN, IDGN,'
      '  SUM(SUMREAL_RGREAL_DV)  AS SUMREAL,'
      '  SUM(SEBREAL_RGREAL_DV)  AS SEBREAL,'
      '  SUM(RESREAL_RGREAL_DV)  AS RESREAL,'
      '  SUM(KOL_RGREAL_DV)  AS KOLREAL'
      'from '
      '  RGREAL_DV'
      'left outer join SNOM on IDNOM_RGREAL_DV=IDNOM'
      'left outer join SGRPNOM on IDGRPNOM=IDGN'
      'where POSDOC_RGREAL_DV  between :PARAM_POSNACH and :PARAM_POSCON'
      'group by NAMEGN, IDGN')
    Transaction = IBTr
    Left = 8
    Top = 224
    object IBQRealGrpSUMREAL: TFIBBCDField
      FieldName = 'SUMREAL'
      Size = 2
      RoundByScale = True
    end
    object IBQRealGrpSEBREAL: TFIBBCDField
      FieldName = 'SEBREAL'
      Size = 2
      RoundByScale = True
    end
    object IBQRealGrpRESREAL: TFIBBCDField
      FieldName = 'RESREAL'
      Size = 2
      RoundByScale = True
    end
    object IBQRealGrpKOLREAL: TFIBBCDField
      FieldName = 'KOLREAL'
      Size = 3
      RoundByScale = True
    end
    object IBQRealGrpIDGN: TFIBBCDField
      FieldName = 'IDGN'
      Size = 0
      RoundByScale = True
    end
    object IBQRealGrpNAMEGN: TFIBWideStringField
      FieldName = 'NAMEGN'
      Size = 100
    end
  end
  object IBQRealEl: TpFIBDataSet
    SelectSQL.Strings = (
      'select  NAMENOM, NAMEED, IDNOM,'
      '  SUM(SUMREAL_RGREAL_DV)  AS SUMREAL,'
      '  SUM(SEBREAL_RGREAL_DV)  AS SEBREAL,'
      '  SUM(RESREAL_RGREAL_DV)  AS RESREAL,'
      '  SUM(KOL_RGREAL_DV)  AS KOLREAL,'
      '  SUM(KOLOTR_RGREAL_DV) AS KOLOTRREAL'
      'from '
      '   RGREAL_DV'
      'left outer join SNOM on IDNOM_RGREAL_DV=IDNOM'
      'left outer join SGRPNOM on IDGRPNOM=IDGN'
      'left outer join SED on IDBASEDNOM=IDED'
      
        'where (POSDOC_RGREAL_DV  between :PARAM_POSNACH and :PARAM_POSCO' +
        'N)'
      'and  (IDNOM=:PARAM_IDNOM)'
      'group by NAMENOM, NAMEED, IDNOM')
    Transaction = IBTr
    Left = 40
    Top = 224
    object IBQRealElSUMREAL: TFIBBCDField
      FieldName = 'SUMREAL'
      Size = 2
      RoundByScale = True
    end
    object IBQRealElSEBREAL: TFIBBCDField
      FieldName = 'SEBREAL'
      Size = 2
      RoundByScale = True
    end
    object IBQRealElRESREAL: TFIBBCDField
      FieldName = 'RESREAL'
      Size = 2
      RoundByScale = True
    end
    object IBQRealElKOLREAL: TFIBBCDField
      FieldName = 'KOLREAL'
      Size = 3
      RoundByScale = True
    end
    object IBQRealElKOLOTRREAL: TFIBBCDField
      FieldName = 'KOLOTRREAL'
      Size = 3
      RoundByScale = True
    end
    object IBQRealElIDNOM: TFIBBCDField
      FieldName = 'IDNOM'
      Size = 0
      RoundByScale = True
    end
    object IBQRealElNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 100
    end
    object IBQRealElNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 152
    Top = 16
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
    Left = 104
    Top = 264
  end
end
