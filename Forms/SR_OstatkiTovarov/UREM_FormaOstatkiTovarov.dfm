object SR_FormaOstatkiTovarov: TSR_FormaOstatkiTovarov
  Left = 308
  Top = 124
  Caption = #1057#1088#1072#1074#1085#1077#1085#1080#1077' '#1086#1089#1090#1072#1090#1082#1086#1074' '#1089#1080#1089#1090#1077#1084#1099' '#1056#1077#1084#1086#1085#1090' '#1080' '#1054#1089#1085#1086#1074#1085#1086#1075#1086' '#1084#1086#1076#1091#1083#1103':'
  ClientHeight = 542
  ClientWidth = 976
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
    Left = 9
    Top = 9
    Width = 770
    Height = 32
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1057#1088#1072#1074#1085#1077#1085#1080#1077' '#1086#1089#1090#1072#1090#1082#1086#1074' '#1089#1080#1089#1090#1077#1084#1099' '#1056#1077#1084#1086#1085#1090' '#1080' '#1054#1089#1085#1086#1074#1085#1086#1075#1086' '#1084#1086#1076#1091#1083#1103':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 10
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
  object Label4: TLabel
    Left = 39
    Top = 145
    Width = 43
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1057#1082#1083#1072#1076':'
  end
  object Label6: TLabel
    Left = 39
    Top = 113
    Width = 47
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1060#1080#1088#1084#1072':'
  end
  object Label7: TLabel
    Left = 39
    Top = 175
    Width = 50
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1043#1088#1091#1087#1087#1072' '
  end
  object Label8: TLabel
    Left = 20
    Top = 194
    Width = 99
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099':'
  end
  object Label9: TLabel
    Left = 20
    Top = 224
    Width = 100
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072':'
  end
  object cxButtonClose: TcxButton
    Left = 416
    Top = 502
    Width = 93
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 7
  end
  object NameNomEdit: TcxButtonEdit
    Left = 122
    Top = 221
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
    Properties.OnButtonClick = NameNomEditPropertiesButtonClick
    TabOrder = 5
    Text = 'NameNomEdit'
    Width = 381
  end
  object NameGrpNomEdit: TcxButtonEdit
    Left = 122
    Top = 185
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
    Properties.OnButtonClick = NameGrpNomEditPropertiesButtonClick
    TabOrder = 4
    Text = 'NameGrpNomEdit'
    Width = 381
  end
  object NameSkladEdit: TcxButtonEdit
    Left = 122
    Top = 143
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
    Properties.OnButtonClick = NameSkladEditPropertiesButtonClick
    TabOrder = 3
    Text = 'NameSkladEdit'
    Width = 381
  end
  object NameFirmEdit: TcxButtonEdit
    Left = 122
    Top = 110
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
    Width = 381
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
    Left = 345
    Top = 69
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Properties.Kind = ckDateTime
    TabOrder = 1
    Width = 149
  end
  object DocDvcxCheckBox: TcxCheckBox
    Left = 557
    Top = 216
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1089' '#1076#1086#1082#1091#1084#1077#1085#1090#1072#1084#1080' '#1076#1074#1080#1078#1077#1085#1080#1103
    TabOrder = 6
    Width = 208
  end
  object cxButton1: TcxButton
    Left = 276
    Top = 502
    Width = 132
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
    TabOrder = 8
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
    Left = 56
    Top = 304
  end
end
