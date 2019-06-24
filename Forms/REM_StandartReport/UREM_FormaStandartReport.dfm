object REM_FormaStandartReport: TREM_FormaStandartReport
  Left = 308
  Top = 124
  Caption = #1057#1090#1072#1085#1076#1072#1088#1090#1085#1099#1077' '#1086#1090#1095#1077#1090#1099' '#1087#1086#1076#1089#1080#1089#1090#1077#1084#1099' '#1056#1077#1084#1086#1085#1090':'
  ClientHeight = 463
  ClientWidth = 799
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
    Left = 7
    Top = 15
    Width = 430
    Height = 26
    Caption = #1057#1090#1072#1085#1076#1072#1088#1090#1085#1099#1077' '#1086#1090#1095#1077#1090#1099' '#1087#1086#1076#1089#1080#1089#1090#1077#1084#1099' '#1056#1077#1084#1086#1085#1090':'
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
  object Label5: TLabel
    Left = 11
    Top = 221
    Width = 76
    Height = 13
    Caption = #1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1100':'
  end
  object Label10: TLabel
    Left = 13
    Top = 260
    Width = 43
    Height = 13
    Caption = #1058#1080#1087' '#1094#1077#1085':'
  end
  object Label11: TLabel
    Left = 3
    Top = 293
    Width = 84
    Height = 13
    Caption = #1058#1080#1087' '#1085#1072#1095#1080#1089#1083#1077#1085#1080#1081':'
  end
  object Label12: TLabel
    Left = 26
    Top = 319
    Width = 39
    Height = 13
    Caption = #1050#1083#1080#1077#1085#1090':'
  end
  object Label13: TLabel
    Left = 7
    Top = 349
    Width = 82
    Height = 13
    Caption = #1055#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1100':'
  end
  object Label16: TLabel
    Left = 444
    Top = 118
    Width = 42
    Height = 13
    Caption = #1052#1086#1076#1077#1083#1100':'
  end
  object Label14: TLabel
    Left = 428
    Top = 142
    Width = 84
    Height = 13
    Caption = #1052#1086#1076#1077#1083#1100' '#1087#1088#1086#1080#1079#1074'.:'
  end
  object Label15: TLabel
    Left = 435
    Top = 170
    Width = 72
    Height = 13
    Caption = #1058#1080#1087#1086#1074#1086#1081' '#1091#1079#1077#1083':'
  end
  object Label17: TLabel
    Left = 435
    Top = 193
    Width = 68
    Height = 13
    Caption = #1058#1080#1087' '#1088#1077#1084#1086#1085#1090#1072':'
  end
  object cxButtonClose: TcxButton
    Left = 359
    Top = 429
    Width = 76
    Height = 25
    Action = ActionClose
    TabOrder = 7
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
    TabOrder = 5
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
    TabOrder = 4
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
    TabOrder = 3
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
    TabOrder = 2
    Text = 'NameFirmEdit'
    Width = 308
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
    Top = 418
    Caption = #1089' '#1076#1086#1082#1091#1084#1077#1085#1090#1072#1084#1080' '#1076#1074#1080#1078#1077#1085#1080#1103
    TabOrder = 6
    Width = 169
  end
  object cxButton1: TcxButton
    Left = 245
    Top = 429
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
    TabOrder = 8
  end
  object NameUsercxButtonEdit: TcxButtonEdit
    Left = 98
    Top = 219
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
    Properties.OnButtonClick = NameUsercxButtonEditPropertiesButtonClick
    TabOrder = 9
    Text = 'NameUsercxButtonEdit'
    Width = 309
  end
  object NameTypePricecxButtonEdit: TcxButtonEdit
    Left = 99
    Top = 258
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
    Properties.OnButtonClick = NameTypePricecxButtonEditPropertiesButtonClick
    TabOrder = 10
    Text = 'NameTypePricecxButtonEdit'
    Width = 310
  end
  object NameTypeNachislcxButtonEdit: TcxButtonEdit
    Left = 99
    Top = 290
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
    Properties.OnButtonClick = NameTypeNachislcxButtonEditPropertiesButtonClick
    TabOrder = 11
    Text = 'NameTypeNachislcxButtonEdit'
    Width = 310
  end
  object NameKlientcxButtonEdit: TcxButtonEdit
    Left = 99
    Top = 316
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
    Properties.OnButtonClick = NameKlientcxButtonEditPropertiesButtonClick
    TabOrder = 12
    Text = 'NameKlientcxButtonEdit'
    Width = 310
  end
  object NameProducercxButtonEdit: TcxButtonEdit
    Left = 101
    Top = 342
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
    Properties.OnButtonClick = NameProducercxButtonEditPropertiesButtonClick
    TabOrder = 13
    Text = 'NameProducercxButtonEdit'
    Width = 309
  end
  object cxLabel9: TcxLabel
    Left = 2
    Top = 368
    Caption = #1041#1080#1079#1085#1077#1089' '#1086#1087#1077#1088#1072#1094#1080#1103':'
  end
  object cxLabel4: TcxLabel
    Left = 32
    Top = 395
    Caption = #1055#1088#1086#1077#1082#1090':'
  end
  object NameBusinessOpercxButtonEdit: TcxButtonEdit
    Left = 99
    Top = 368
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
    Properties.OnButtonClick = NameBusinessOpercxButtonEditPropertiesButtonClick
    TabOrder = 16
    Text = 'NameBusinessOpercxButtonEdit'
    Width = 310
  end
  object NameProjectcxButtonEdit: TcxButtonEdit
    Left = 99
    Top = 394
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
    Properties.OnButtonClick = NameProjectcxButtonEditPropertiesButtonClick
    TabOrder = 17
    Text = 'NameProjectcxButtonEdit'
    Width = 310
  end
  object cxButton2: TcxButton
    Left = 548
    Top = 215
    Width = 202
    Height = 30
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Caption = #1047#1072#1087#1086#1083#1085#1080#1090#1100' '#1088#1077#1072#1083#1080#1079#1072#1094#1080#1102' '#1085#1072' '#1086#1089#1085#1086#1074#1072#1085#1080#1080' '#1040#1082#1090#1086#1074' '#1055#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1102
    TabOrder = 18
    WordWrap = True
    OnClick = cxButton2Click
  end
  object cxButtonZapolnitOtchetPost: TcxButton
    Left = 548
    Top = 249
    Width = 202
    Height = 33
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Caption = #1047#1072#1087#1086#1083#1085#1080#1090#1100' '#1054#1090#1095#1077#1090' '#1087#1086#1089#1090#1072#1074#1097#1080#1082#1091' '#1085#1072' '#1086#1089#1085#1086#1074#1072#1085#1080#1080' '#1040#1082#1090#1086#1074' '#1055#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1102
    TabOrder = 19
    WordWrap = True
    OnClick = cxButtonZapolnitOtchetPostClick
  end
  object cxButtonCreateAktSpisNom: TcxButton
    Left = 548
    Top = 287
    Width = 202
    Height = 55
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Caption = 
      #1057#1086#1079#1076#1072#1090#1100' '#1057#1087#1080#1089#1072#1085#1080#1077' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099' '#1085#1072' '#1086#1089#1085#1086#1074#1077' '#1089#1087#1080#1089#1072#1085#1099#1093' '#1080#1079' '#1088#1077#1075#1080#1089#1090#1088#1072' '#1085#1086#1084 +
      #1077#1085#1082#1083#1072#1090#1091#1088' '#1089' '#1074#1099#1073#1088#1072#1085#1085#1086#1081' '#1086#1087#1077#1088#1072#1094#1080#1077#1081
    TabOrder = 20
    WordWrap = True
    OnClick = cxButtonCreateAktSpisNomClick
  end
  object cxButtonProvGarTalon: TcxButton
    Left = 548
    Top = 347
    Width = 202
    Height = 43
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Caption = #1055#1088#1086#1074#1077#1088#1080#1090#1100' '#1075#1072#1088'. '#1090#1072#1083#1086#1085#1099', '#1074#1099#1073#1088#1072#1085#1085#1086#1075#1086' '#1087#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1103
    TabOrder = 21
    WordWrap = True
    OnClick = cxButtonProvGarTalonClick
  end
  object cxButtonProvAktPoTalonam: TcxButton
    Left = 548
    Top = 395
    Width = 202
    Height = 43
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Caption = #1055#1088#1086#1074#1077#1088#1080#1090#1100' '#1072#1082#1090#1099' '#1055#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1102' '#1087#1086' '#1090#1072#1083#1086#1085#1072#1084' '#1074' '#1082#1072#1090#1072#1083#1086#1075#1077
    TabOrder = 22
    WordWrap = True
    OnClick = cxButtonProvAktPoTalonamClick
  end
  object cxLabel1: TcxLabel
    Left = 444
    Top = 90
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Caption = #1041#1088#1077#1085#1076':'
  end
  object NameBrandcxButtonEdit: TcxButtonEdit
    Left = 548
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
    Properties.OnButtonClick = NameBrandcxButtonEditPropertiesButtonClick
    TabOrder = 24
    Text = 'NameBrandcxButtonEdit'
    Width = 239
  end
  object NameModelcxButtonEdit: TcxButtonEdit
    Left = 548
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
    Properties.OnButtonClick = NameModelcxButtonEditPropertiesButtonClick
    TabOrder = 25
    Text = 'NameModelcxButtonEdit'
    Width = 239
  end
  object NameProducerModelcxButtonEdit: TcxButtonEdit
    Left = 548
    Top = 141
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
    Properties.OnButtonClick = NameProducerModelcxButtonEditPropertiesButtonClick
    TabOrder = 26
    Text = 'NameProducerModelcxButtonEdit'
    Width = 239
  end
  object NameTypUselcxButtonEdit: TcxButtonEdit
    Left = 548
    Top = 167
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
    Properties.OnButtonClick = NameTypUselcxButtonEditPropertiesButtonClick
    TabOrder = 27
    Text = 'NameTypUselcxButtonEdit'
    Width = 239
  end
  object NameTypeRemontcxButtonEdit: TcxButtonEdit
    Left = 548
    Top = 190
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
    Properties.OnButtonClick = NameTypeRemontcxButtonEditPropertiesButtonClick
    TabOrder = 28
    Text = 'NameTypeRemontcxButtonEdit'
    Width = 239
  end
  object cxButtonViborExtPrintForm: TcxButton
    Left = 132
    Top = 431
    Width = 107
    Height = 25
    Caption = #1042#1085#1077#1096#1085#1080#1081' '#1086#1090#1095#1077#1090
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
    TabOrder = 29
    OnClick = cxButtonViborExtPrintFormClick
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
  object PopupMenuExtModule: TPopupMenu
    Left = 520
    Top = 48
  end
  object OpenDialog1: TOpenDialog
    Left = 688
    Top = 48
  end
end
