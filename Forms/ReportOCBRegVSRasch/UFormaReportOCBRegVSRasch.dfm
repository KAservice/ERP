object FormaReportOCBRegVSRasch: TFormaReportOCBRegVSRasch
  Left = 433
  Top = 274
  Caption = #1042#1079#1072#1080#1084#1086#1088#1072#1089#1095#1077#1090#1099':'
  ClientHeight = 429
  ClientWidth = 546
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 120
  TextHeight = 16
  object Label1: TLabel
    Left = 30
    Top = 10
    Width = 436
    Height = 32
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1042#1079#1072#1080#1084#1086#1088#1072#1089#1095#1077#1090#1099' '#1089' '#1082#1086#1085#1090#1088#1072#1075#1077#1085#1090#1072#1084#1080
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object Label2: TLabel
    Left = 20
    Top = 59
    Width = 14
    Height = 32
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'c'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 276
    Top = 59
    Width = 32
    Height = 32
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1087#1086
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label6: TLabel
    Left = 37
    Top = 153
    Width = 47
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1060#1080#1088#1084#1072':'
  end
  object Label4: TLabel
    Left = 39
    Top = 187
    Width = 50
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1043#1088#1091#1087#1087#1072':'
  end
  object Label14: TLabel
    Left = 10
    Top = 226
    Width = 111
    Height = 24
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -18
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label10: TLabel
    Left = 319
    Top = 267
    Width = 194
    Height = 16
    Caption = '* '#1090#1086#1083#1100#1082#1086' '#1076#1083#1103' '#1074#1085#1077#1096#1085#1080#1093' '#1086#1090#1095#1077#1090#1086#1074
  end
  object cxButtonCreate: TcxButton
    Left = 309
    Top = 375
    Width = 122
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1057#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 7
    OnClick = cxButtonCreateClick
  end
  object cxButtonClose: TcxButton
    Left = 440
    Top = 375
    Width = 91
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 8
  end
  object NameKlientEdit: TcxButtonEdit
    Left = 114
    Top = 225
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
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
    Properties.OnButtonClick = NameKlientEditPropertiesButtonClick
    TabOrder = 4
    Text = 'NameKlientEdit'
    Width = 388
  end
  object NameGrpKlientEdit: TcxButtonEdit
    Left = 114
    Top = 183
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
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
    Properties.OnButtonClick = NameGrpKlientEditPropertiesButtonClick
    TabOrder = 3
    Text = 'NameGrpKlientEdit'
    Width = 388
  end
  object NameFirmEdit: TcxButtonEdit
    Left = 114
    Top = 144
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
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
    Width = 388
  end
  object DateNach: TcxDateEdit
    Left = 69
    Top = 69
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Properties.Kind = ckDateTime
    TabOrder = 0
    Width = 149
  end
  object DateCon: TcxDateEdit
    Left = 353
    Top = 69
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Properties.Kind = ckDateTime
    TabOrder = 1
    Width = 149
  end
  object cxButton1: TcxButton
    Left = 169
    Top = 375
    Width = 131
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
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
    TabOrder = 9
  end
  object cxLabel9: TcxLabel
    Left = 5
    Top = 291
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1041#1080#1079#1085#1077#1089' '#1086#1087#1077#1088#1072#1094#1080#1103'*:'
  end
  object cxLabel3: TcxLabel
    Left = 39
    Top = 323
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1055#1088#1086#1077#1082#1090'*:'
  end
  object NameBusinessOpercxButtonEdit: TcxButtonEdit
    Left = 139
    Top = 290
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
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
    TabOrder = 5
    Text = 'NameBusinessOpercxButtonEdi'
    Width = 375
  end
  object NameProjectcxButtonEdit: TcxButtonEdit
    Left = 139
    Top = 322
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
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
    TabOrder = 6
    Text = 'NameProjectcxButtonEdit'
    Width = 375
  end
  object IBQ: TpFIBDataSet
    SelectSQL.Strings = (
      '         select   *'
      ''
      
        'from OCB_RGVSRASCH_FULL_REPORT (:PARAM_POSNACH, :PARAM_POSCON, :' +
        'PARAM_IDFIRM, :PARAM_IDGRPKLIENT, :PARAM_IDKLIENT)'
      ''
      '')
    Transaction = IBTr
    Left = 432
    Top = 272
    object IBQPRIHOD_PROC: TFIBBCDField
      FieldName = 'PRIHOD_PROC'
      Size = 2
      RoundByScale = True
    end
    object IBQRASHOD_PROC: TFIBBCDField
      FieldName = 'RASHOD_PROC'
      Size = 2
      RoundByScale = True
    end
    object IBQCONOST_PROC: TFIBBCDField
      FieldName = 'CONOST_PROC'
      Size = 2
      RoundByScale = True
    end
    object IBQIDFIRM_PROC: TFIBBCDField
      FieldName = 'IDFIRM_PROC'
      Size = 0
      RoundByScale = True
    end
    object IBQIDGRP_PROC: TFIBBCDField
      FieldName = 'IDGRP_PROC'
      Size = 0
      RoundByScale = True
    end
    object IBQIDKLIENT_PROC: TFIBBCDField
      FieldName = 'IDKLIENT_PROC'
      Size = 0
      RoundByScale = True
    end
    object IBQNAMEFIRM_PROC: TFIBWideStringField
      FieldName = 'NAMEFIRM_PROC'
      Size = 100
    end
    object IBQNAMEGRP_PROC: TFIBWideStringField
      FieldName = 'NAMEGRP_PROC'
      Size = 100
    end
    object IBQNAMEKLIENT_PROC: TFIBWideStringField
      FieldName = 'NAMEKLIENT_PROC'
      Size = 100
    end
    object IBQNACHOST_PROC: TFIBBCDField
      FieldName = 'NACHOST_PROC'
      Size = 2
      RoundByScale = True
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
    Left = 368
    Top = 272
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 24
    Top = 24
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
    Top = 272
  end
end
