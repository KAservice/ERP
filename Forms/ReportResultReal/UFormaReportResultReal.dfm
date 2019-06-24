object FormaDialogaReportResultReal: TFormaDialogaReportResultReal
  Left = 308
  Top = 124
  Caption = #1054#1090#1095#1077#1090' '#1086' '#1088#1077#1079#1091#1083#1100#1090#1072#1090#1072#1093' '#1087#1088#1086#1076#1072#1078':'
  ClientHeight = 469
  ClientWidth = 427
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
    Width = 230
    Height = 26
    Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090' '#1088#1077#1072#1083#1080#1079#1072#1094#1080#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 34
    Top = 35
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
    Left = 208
    Top = 34
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
    Left = 34
    Top = 115
    Width = 34
    Height = 13
    Caption = #1057#1082#1083#1072#1076':'
  end
  object Label5: TLabel
    Left = 8
    Top = 332
    Width = 117
    Height = 52
    Caption = 
      #1058#1080#1087' '#1094#1077#1085' '#1076#1083#1103' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088', '#1082#1086#1090#1086#1088#1099#1093' '#1085#1077' '#1073#1099#1083#1086' '#1085#1072' '#1089#1082#1083#1072#1076#1077' '#1074' '#1084#1086#1084#1077#1085#1090' '#1087#1088#1086#1076 +
      #1072#1078#1080':'
    WordWrap = True
  end
  object Label6: TLabel
    Left = 30
    Top = 88
    Width = 40
    Height = 13
    Caption = #1060#1080#1088#1084#1072':'
  end
  object Label7: TLabel
    Left = 32
    Top = 134
    Width = 38
    Height = 13
    Caption = #1043#1088#1091#1087#1087#1072' '
  end
  object Label8: TLabel
    Left = 13
    Top = 148
    Width = 77
    Height = 13
    Caption = #1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099':'
  end
  object Label9: TLabel
    Left = 13
    Top = 169
    Width = 77
    Height = 13
    Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072':'
  end
  object Label10: TLabel
    Left = 250
    Top = 371
    Width = 151
    Height = 13
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Caption = '* '#1090#1086#1083#1100#1082#1086' '#1076#1083#1103' '#1074#1085#1077#1096#1085#1080#1093' '#1086#1090#1095#1077#1090#1086#1074
  end
  object DateNach: TcxDateEdit
    Left = 60
    Top = 43
    Properties.Kind = ckDateTime
    TabOrder = 0
    OnKeyDown = DateNachKeyDown
    Width = 137
  end
  object DateCon: TcxDateEdit
    Left = 268
    Top = 43
    Properties.Kind = ckDateTime
    TabOrder = 1
    OnKeyDown = DateConKeyDown
    Width = 141
  end
  object NameFirmEdit: TcxButtonEdit
    Left = 96
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
    Properties.ClickKey = 13
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameFirmEditPropertiesButtonClick
    TabOrder = 2
    Text = 'NameFirmEdit'
    Width = 313
  end
  object NameSkladEdit: TcxButtonEdit
    Left = 96
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
    Properties.ClickKey = 13
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameSkladEditPropertiesButtonClick
    TabOrder = 3
    Text = 'NameSkladEdit'
    Width = 313
  end
  object NameGrpNomEdit: TcxButtonEdit
    Left = 96
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
    Properties.ClickKey = 13
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameGrpNomEditPropertiesButtonClick
    TabOrder = 4
    Text = 'NameGrpNomEdit'
    Width = 313
  end
  object NameNomEdit: TcxButtonEdit
    Left = 96
    Top = 166
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
    Properties.OnButtonClick = NameNomEditPropertiesButtonClick
    TabOrder = 5
    Text = 'NameNomEdit'
    Width = 313
  end
  object OnlyCheckBox: TcxCheckBox
    Left = 97
    Top = 200
    Caption = #1087#1086#1082#1072#1079#1099#1074#1072#1090#1100
    TabOrder = 6
    OnKeyDown = OnlyCheckBoxKeyDown
    Width = 121
  end
  object TypeNomComboBox: TcxComboBox
    Left = 224
    Top = 200
    Properties.DropDownListStyle = lsFixedList
    Properties.Items.Strings = (
      #1090#1086#1083#1100#1082#1086' '#1090#1086#1074#1072#1088#1099' (0)'
      #1090#1086#1083#1100#1082#1086' '#1091#1089#1083#1091#1075#1080' (1)'
      #1090#1086#1083#1100#1082#1086' '#1087#1088#1086#1076#1091#1082#1094#1080#1103' (2)')
    Properties.OnChange = TypeNomComboBoxPropertiesChange
    TabOrder = 7
    Width = 185
  end
  object OnlyOperationCheckBox: TcxCheckBox
    Left = 96
    Top = 237
    Caption = #1090#1086#1083#1100#1082#1086' '#1086#1087#1077#1088#1072#1094#1080#1080
    TabOrder = 8
    OnKeyDown = OnlyOperationCheckBoxKeyDown
    Width = 121
  end
  object OperationComboBox: TcxComboBox
    Left = 224
    Top = 232
    Properties.DropDownListStyle = lsFixedList
    Properties.Items.Strings = (
      #1087#1088#1086#1095#1077#1077' (0)'
      #1056#1086#1079#1085#1080#1095#1085#1072#1103' '#1090#1086#1088#1075#1086#1074#1083#1103' (1)'
      #1056#1086#1079#1085#1080#1095#1085#1072#1103' '#1090#1086#1088#1075#1086#1074#1083#1103' '#1074' '#1082#1088#1077#1076#1080#1090' (2)'
      #1054#1087#1090#1086#1074#1072#1103' '#1090#1086#1088#1075#1086#1074#1083#1103' (3)')
    Properties.OnChange = OperationComboBoxPropertiesChange
    TabOrder = 9
    Width = 185
  end
  object TypePriceComboBox: TcxComboBox
    Left = 230
    Top = 337
    Properties.DropDownListStyle = lsFixedList
    Properties.OnChange = TypePriceComboBoxPropertiesChange
    TabOrder = 10
    Width = 185
  end
  object DocCheckBox: TcxCheckBox
    Left = 89
    Top = 364
    Caption = #1089' '#1076#1086#1082#1091#1084#1077#1085#1090#1072#1084#1080
    TabOrder = 12
    OnKeyDown = DocCheckBoxKeyDown
    Width = 121
  end
  object cxButtonCreateReport: TcxButton
    Left = 216
    Top = 443
    Width = 107
    Height = 24
    Caption = #1057#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 15
    OnClick = cxButtonCreateReportClick
  end
  object cxButtonClose: TcxButton
    Left = 329
    Top = 443
    Width = 75
    Height = 24
    Action = ActionClose
    TabOrder = 16
  end
  object cxCheckBoxVisibleOtrOst: TcxCheckBox
    Left = 96
    Top = 264
    Caption = #1087#1086#1082#1072#1079#1099#1074#1072#1090#1100' '#1090#1086#1074#1072#1088#1099', '#1082#1086#1090#1086#1088#1099#1093' '#1085#1077' '#1073#1099#1083#1086' '#1085#1072' '#1089#1082#1083#1072#1076#1077' '#1074' '#1084#1086#1084#1077#1085#1090' '#1087#1088#1086#1076#1072#1078#1080
    Properties.MultiLine = True
    TabOrder = 11
    OnKeyDown = cxCheckBoxVisibleOtrOstKeyDown
    Width = 312
  end
  object cxButtonCreateReportGrid: TcxButton
    Left = 304
    Top = 304
    Width = 100
    Height = 25
    Caption = #1057#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 17
    OnClick = cxButtonCreateReportGridClick
  end
  object cxButton1: TcxButton
    Left = 103
    Top = 443
    Width = 107
    Height = 24
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
    TabOrder = 18
  end
  object cxLabel9: TcxLabel
    Left = 1
    Top = 391
    Caption = #1041#1080#1079#1085#1077#1089' '#1086#1087#1077#1088#1072#1094#1080#1103'*:'
  end
  object cxLabel3: TcxLabel
    Left = 30
    Top = 414
    Caption = #1055#1088#1086#1077#1082#1090'*:'
  end
  object NameBusinessOpercxButtonEdit: TcxButtonEdit
    Left = 103
    Top = 391
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
    TabOrder = 13
    Text = 'NameBusinessOpercxButtonEdi'
    Width = 305
  end
  object NameProjectcxButtonEdit: TcxButtonEdit
    Left = 103
    Top = 417
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
    TabOrder = 14
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
    Left = 392
    Top = 8
  end
  object TypePrice: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from STPRICE')
    Transaction = IBTr
    Left = 312
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
      'select  sfirm.namefirm, sfirm.idfirm,'
      '        ssklad.namesklad, ssklad.idsklad,'
      '        sgrpnom.namegn, sgrpnom.idgn,'
      '        NAMENOM, IDNOM, TNOM,'
      '        NAMEED, '
      '        SUM(SUMREAL_RGREAL_DV)  AS SUMREAL,'
      '        SUM(SEBREAL_RGREAL_DV)  AS SEBREAL,'
      '        SUM(RESREAL_RGREAL_DV)  AS RESREAL,'
      '        SUM(KOL_RGREAL_DV)  AS KOLREAL,'
      '        SUM(KOLOTR_RGREAL_DV)  AS KOLOTRREAL'
      ''
      'from  RGREAL_DV'
      ''
      'left outer join sfirm on rgreal_dv.idfirm_rgreal_dv=sfirm.idfirm'
      
        'left outer join ssklad on rgreal_dv.idsklad_rgreal_dv=ssklad.ids' +
        'klad'
      'left outer join SNOM on IDNOM_RGREAL_DV=IDNOM'
      'left outer join SGRPNOM on IDGRPNOM=IDGN'
      'left outer join SED on IDBASEDNOM=IDED'
      ''
      'group by sfirm.namefirm, sfirm.idfirm,'
      '        ssklad.namesklad, ssklad.idsklad,'
      '        sgrpnom.namegn, sgrpnom.idgn,'
      '        NAMENOM, IDNOM, TNOM,'
      '        NAMEED')
    Transaction = IBTr
    Left = 48
    Top = 320
    object IBQTNOM: TFIBIntegerField
      FieldName = 'TNOM'
    end
    object IBQSUMREAL: TFIBBCDField
      FieldName = 'SUMREAL'
      Size = 2
      RoundByScale = True
    end
    object IBQSEBREAL: TFIBBCDField
      FieldName = 'SEBREAL'
      Size = 2
      RoundByScale = True
    end
    object IBQRESREAL: TFIBBCDField
      FieldName = 'RESREAL'
      Size = 2
      RoundByScale = True
    end
    object IBQKOLREAL: TFIBBCDField
      FieldName = 'KOLREAL'
      Size = 3
      RoundByScale = True
    end
    object IBQKOLOTRREAL: TFIBBCDField
      FieldName = 'KOLOTRREAL'
      Size = 3
      RoundByScale = True
    end
    object IBQIDFIRM: TFIBBCDField
      FieldName = 'IDFIRM'
      Size = 0
      RoundByScale = True
    end
    object IBQIDSKLAD: TFIBBCDField
      FieldName = 'IDSKLAD'
      Size = 0
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
    object IBQNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 100
    end
    object IBQNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 100
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
  end
  object IBQDoc: TpFIBDataSet
    SelectSQL.Strings = (
      'select  rgreal_dv.kol_rgreal_dv,'
      '        rgreal_dv.sumreal_rgreal_dv,'
      '        rgreal_dv.sebreal_rgreal_dv,'
      '        rgreal_dv.resreal_rgreal_dv,'
      '        rgreal_dv.kolotr_rgreal_dv,'
      '        galldoc.posdoc,'
      '        galldoc.numdoc,'
      '        galldoc.tdoc'
      ''
      'from rgreal_dv'
      
        'left outer join galldoc on rgreal_dv.iddoc_rgreal_dv=galldoc.idd' +
        'oc'
      'where rgreal_dv.idnom_rgreal_dv=:PARAM_IDNOM'
      'order by galldoc.posdoc')
    Transaction = IBTr
    Left = 8
    Top = 320
    object IBQDocKOL_RGREAL_DV: TFIBBCDField
      FieldName = 'KOL_RGREAL_DV'
      Size = 3
      RoundByScale = True
    end
    object IBQDocSUMREAL_RGREAL_DV: TFIBBCDField
      FieldName = 'SUMREAL_RGREAL_DV'
      Size = 2
      RoundByScale = True
    end
    object IBQDocSEBREAL_RGREAL_DV: TFIBBCDField
      FieldName = 'SEBREAL_RGREAL_DV'
      Size = 2
      RoundByScale = True
    end
    object IBQDocRESREAL_RGREAL_DV: TFIBBCDField
      FieldName = 'RESREAL_RGREAL_DV'
      Size = 2
      RoundByScale = True
    end
    object IBQDocKOLOTR_RGREAL_DV: TFIBBCDField
      FieldName = 'KOLOTR_RGREAL_DV'
      Size = 3
      RoundByScale = True
    end
    object IBQDocPOSDOC: TFIBDateTimeField
      FieldName = 'POSDOC'
    end
    object IBQDocNUMDOC: TFIBIntegerField
      FieldName = 'NUMDOC'
    end
    object IBQDocTDOC: TFIBWideStringField
      FieldName = 'TDOC'
      Size = 10
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 248
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
    Left = 64
    Top = 384
  end
end
