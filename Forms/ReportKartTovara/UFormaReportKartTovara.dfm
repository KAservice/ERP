object FormaReportKartTovara: TFormaReportKartTovara
  Left = 233
  Top = 118
  Caption = #1050#1072#1088#1090#1086#1095#1082#1072' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099':'
  ClientHeight = 302
  ClientWidth = 460
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
    Width = 254
    Height = 26
    Caption = #1050#1072#1088#1090#1086#1095#1082#1072' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099':'
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
    Top = 108
    Width = 34
    Height = 13
    Caption = #1057#1082#1083#1072#1076':'
  end
  object Label6: TLabel
    Left = 8
    Top = 136
    Width = 77
    Height = 13
    Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072':'
  end
  object Label5: TLabel
    Left = 8
    Top = 200
    Width = 118
    Height = 16
    Caption = #1041#1072#1079#1086#1074#1072#1103' '#1077#1076#1080#1085#1080#1094#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object NameBasEdLabel: TLabel
    Left = 136
    Top = 200
    Width = 127
    Height = 16
    Caption = 'NameBasEdLabel'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMaroon
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label7: TLabel
    Left = 8
    Top = 168
    Width = 85
    Height = 39
    Caption = #1056#1086#1079#1085#1080#1095#1085#1072#1103' '#1094#1077#1085#1072' ('#1076#1083#1103' '#1088#1086#1079#1085#1080#1095#1085#1086#1075#1086' '#1089#1082#1083#1072#1076#1072'):'
    WordWrap = True
  end
  object cxButtonCreate: TcxButton
    Left = 193
    Top = 232
    Width = 168
    Height = 25
    Caption = #1055#1086' '#1088#1077#1075#1080#1089#1090#1088#1091' "'#1055#1072#1088#1090#1080#1080' '#1090#1086#1074#1072#1088#1086#1074'"'
    TabOrder = 0
    OnClick = cxButtonCreateClick
  end
  object cxButtonClose: TcxButton
    Left = 367
    Top = 263
    Width = 75
    Height = 25
    Action = ActionClose
    TabOrder = 1
  end
  object NameNomEdit: TcxButtonEdit
    Left = 91
    Top = 133
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameNomEditPropertiesButtonClick
    TabOrder = 2
    Text = 'NameNomEdit'
    Width = 298
  end
  object NameSkladEdit: TcxButtonEdit
    Left = 91
    Top = 106
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
    Width = 298
  end
  object DateNach: TcxDateEdit
    Left = 48
    Top = 57
    Properties.Kind = ckDateTime
    TabOrder = 4
    Width = 143
  end
  object DateCon: TcxDateEdit
    Left = 280
    Top = 56
    Properties.Kind = ckDateTime
    TabOrder = 5
    Width = 137
  end
  object NameFirmcxButtonEdit: TcxButtonEdit
    Left = 91
    Top = 79
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
    Properties.OnButtonClick = NameFirmcxButtonEditPropertiesButtonClick
    TabOrder = 6
    Text = 'NameFirmcxButtonEdit'
    Width = 298
  end
  object cxLabel2: TcxLabel
    Left = 38
    Top = 84
    Caption = #1060#1080#1088#1084#1072':'
  end
  object cxButton1: TcxButton
    Left = 16
    Top = 232
    Width = 171
    Height = 25
    Caption = #1055#1086' '#1088#1077#1075#1080#1089#1090#1088#1091' "'#1054#1089#1090#1072#1090#1082#1080' '#1090#1086#1074#1072#1088#1086#1074'"'
    TabOrder = 8
    OnClick = cxButton1Click
  end
  object RoznPricecxCalcEdit: TcxCalcEdit
    Left = 122
    Top = 173
    EditValue = 0.000000000000000000
    TabOrder = 9
    Width = 121
  end
  object AllPricecxCheckBox: TcxCheckBox
    Left = 264
    Top = 160
    Caption = 
      #1085#1077' '#1091#1095#1080#1090#1099#1074#1072#1090#1100' '#1094#1077#1085#1091' '#1076#1083#1103' '#1088#1086#1079#1085#1080#1095#1085#1086#1075#1086' '#1089#1082#1083#1072#1076#1072' '#1087#1088#1080' '#1092#1086#1088#1084#1080#1088#1086#1074#1072#1085#1080#1080' '#1086#1090#1095#1077#1090#1072' ' +
      #1087#1086' '#1088#1077#1075#1080#1089#1090#1088#1091' "'#1054#1095#1090#1072#1090#1082#1080' '#1090#1086#1074#1072#1088#1086#1074'"'
    Properties.MultiLine = True
    Properties.ValueChecked = 1
    Properties.ValueUnchecked = 0
    State = cbsGrayed
    TabOrder = 10
    Width = 178
  end
  object cxButton2: TcxButton
    Left = 16
    Top = 263
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
    TabOrder = 11
  end
  object IBTr: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 432
    Top = 16
  end
  object Dv: TpFIBDataSet
    SelectSQL.Strings = (
      'select RGOSTNOM_DV .* , TDOC, NUMDOC'
      'from '
      'RGOSTNOM_DV '
      'left outer join GALLDOC on IDDOC_OSTNOMDV= IDDOC'
      'where '
      '( :PARAM_POSNACH <  POSDOC_OSTNOMDV  '
      'and POSDOC_OSTNOMDV < :PARAM_POSCON) '
      'and IDFIRM_OSTNOMDV=:PARAM_IDFIRM'
      'and IDSKL_OSTNOMDV=:PARAM_IDSKLAD '
      'and IDNOM_OSTNOMDV=:PARAM_IDNOM'
      'order by POSDOC_OSTNOMDV')
    Transaction = IBTr
    Left = 432
    Top = 72
    object DvPOSDOC_OSTNOMDV: TFIBDateTimeField
      FieldName = 'POSDOC_OSTNOMDV'
    end
    object DvTDV_OSTNOMDV: TFIBSmallIntField
      FieldName = 'TDV_OSTNOMDV'
    end
    object DvSUM_OSTNOMDV: TFIBBCDField
      FieldName = 'SUM_OSTNOMDV'
      Size = 2
      RoundByScale = True
    end
    object DvKOL_OSTNOMDV: TFIBBCDField
      FieldName = 'KOL_OSTNOMDV'
      Size = 3
      RoundByScale = True
    end
    object DvOPER_OSTNOMDV: TFIBIntegerField
      FieldName = 'OPER_OSTNOMDV'
    end
    object DvSUM2_OSTNOMDV: TFIBBCDField
      FieldName = 'SUM2_OSTNOMDV'
      Size = 2
      RoundByScale = True
    end
    object DvNUMDOC: TFIBIntegerField
      FieldName = 'NUMDOC'
    end
    object DvID_OSTNOMDV: TFIBBCDField
      FieldName = 'ID_OSTNOMDV'
      Size = 0
      RoundByScale = True
    end
    object DvIDDOC_OSTNOMDV: TFIBBCDField
      FieldName = 'IDDOC_OSTNOMDV'
      Size = 0
      RoundByScale = True
    end
    object DvIDFIRM_OSTNOMDV: TFIBBCDField
      FieldName = 'IDFIRM_OSTNOMDV'
      Size = 0
      RoundByScale = True
    end
    object DvIDSKL_OSTNOMDV: TFIBBCDField
      FieldName = 'IDSKL_OSTNOMDV'
      Size = 0
      RoundByScale = True
    end
    object DvIDNOM_OSTNOMDV: TFIBBCDField
      FieldName = 'IDNOM_OSTNOMDV'
      Size = 0
      RoundByScale = True
    end
    object DvIDPART_OSTNOMDV: TFIBBCDField
      FieldName = 'IDPART_OSTNOMDV'
      Size = 0
      RoundByScale = True
    end
    object DvIDSTRDOC_OSTNOMDV: TFIBBCDField
      FieldName = 'IDSTRDOC_OSTNOMDV'
      Size = 0
      RoundByScale = True
    end
    object DvTDOC: TFIBWideStringField
      FieldName = 'TDOC'
      Size = 10
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
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
  object DvRegGoods: TpFIBDataSet
    SelectSQL.Strings = (
      'select rggoods_dv .* , TDOC, NUMDOC'
      'from '
      'rggoods_dv'
      
        'left outer join galldoc on rggoods_dv.iddoc_rggoods_dv= galldoc.' +
        'iddoc'
      'where '
      '( :PARAM_POSNACH < rggoods_dv.posdoc_rggoods_dv'
      'and rggoods_dv.posdoc_rggoods_dv < :PARAM_POSCON)'
      'and rggoods_dv.idfirm_rggoods_dv=:PARAM_IDFIRM'
      'and rggoods_dv.idsklad_rggoods_dv=:PARAM_IDSKLAD'
      'and rggoods_dv.idnom_rggoods_dv=:PARAM_IDNOM'
      'order by rggoods_dv.posdoc_rggoods_dv')
    Transaction = IBTr
    Left = 432
    Top = 120
    object DvRegGoodsID_RGGOODS_DV: TFIBBCDField
      FieldName = 'ID_RGGOODS_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegGoodsPOSDOC_RGGOODS_DV: TFIBDateTimeField
      FieldName = 'POSDOC_RGGOODS_DV'
    end
    object DvRegGoodsTDV_RGGOODS_DV: TFIBSmallIntField
      FieldName = 'TDV_RGGOODS_DV'
    end
    object DvRegGoodsIDFIRM_RGGOODS_DV: TFIBBCDField
      FieldName = 'IDFIRM_RGGOODS_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegGoodsIDSKLAD_RGGOODS_DV: TFIBBCDField
      FieldName = 'IDSKLAD_RGGOODS_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegGoodsIDNOM_RGGOODS_DV: TFIBBCDField
      FieldName = 'IDNOM_RGGOODS_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegGoodsRPRICE_RGGOODS_DV: TFIBBCDField
      FieldName = 'RPRICE_RGGOODS_DV'
      Size = 2
      RoundByScale = True
    end
    object DvRegGoodsKOL_RGGOODS_DV: TFIBBCDField
      FieldName = 'KOL_RGGOODS_DV'
      Size = 3
      RoundByScale = True
    end
    object DvRegGoodsOPER_RGGOODS_DV: TFIBIntegerField
      FieldName = 'OPER_RGGOODS_DV'
    end
    object DvRegGoodsTYPE_RGGOODS_DV: TFIBIntegerField
      FieldName = 'TYPE_RGGOODS_DV'
    end
    object DvRegGoodsIDBASE_RGGOODS_DV: TFIBBCDField
      FieldName = 'IDBASE_RGGOODS_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegGoodsIDEXT_DOUT_RGGOODS_DV: TFIBBCDField
      FieldName = 'IDEXT_DOUT_RGGOODS_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegGoodsIDEXT_BASE_RGGOODS_DV: TFIBBCDField
      FieldName = 'IDEXT_BASE_RGGOODS_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegGoodsNUMDOC: TFIBIntegerField
      FieldName = 'NUMDOC'
    end
    object DvRegGoodsIDDOC_RGGOODS_DV: TFIBBCDField
      FieldName = 'IDDOC_RGGOODS_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegGoodsTDOC: TFIBWideStringField
      FieldName = 'TDOC'
      Size = 10
    end
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 176
    Top = 320
  end
end
