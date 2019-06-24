object FormaElementaSprAddressVibor: TFormaElementaSprAddressVibor
  Left = 482
  Top = 263
  Caption = #1040#1076#1088#1077#1089
  ClientHeight = 451
  ClientWidth = 511
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
  PixelsPerInch = 120
  TextHeight = 16
  object Label1: TLabel
    Left = 211
    Top = 336
    Width = 66
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1074#1072#1088#1090#1080#1088#1072':'
  end
  object Label3: TLabel
    Left = 210
    Top = 295
    Width = 67
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1057#1090#1088#1086#1077#1085#1080#1077':'
  end
  object Label4: TLabel
    Left = 248
    Top = 247
    Width = 29
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1044#1086#1084':'
  end
  object Label5: TLabel
    Left = 22
    Top = 171
    Width = 44
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1059#1083#1080#1094#1072':'
  end
  object Label6: TLabel
    Left = 16
    Top = 117
    Width = 126
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1089#1077#1083#1077#1085#1085#1099#1081' '#1087#1091#1085#1082#1090':'
  end
  object Label7: TLabel
    Left = 16
    Top = 63
    Width = 44
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1056#1072#1081#1086#1085':'
  end
  object Label8: TLabel
    Left = 16
    Top = 9
    Width = 50
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1056#1077#1075#1080#1086#1085':'
  end
  object cxButtonOK: TcxButton
    Left = 185
    Top = 402
    Width = 92
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionOK
    TabOrder = 0
  end
  object cxButtonClose: TcxButton
    Left = 304
    Top = 402
    Width = 93
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 1
  end
  object RegioncxLookupComboBox: TcxLookupComboBox
    Left = 16
    Top = 32
    Properties.KeyFieldNames = 'ID_SADR_REGION'
    Properties.ListColumns = <
      item
        FieldName = 'NAME_SADR_REGION'
      end>
    Properties.OnChange = RegioncxLookupComboBoxPropertiesChange
    TabOrder = 2
    Width = 385
  end
  object RayoncxLookupComboBox: TcxLookupComboBox
    Left = 16
    Top = 86
    Properties.KeyFieldNames = 'ID_SADR_RAYON'
    Properties.ListColumns = <
      item
        FieldName = 'NAME_SADR_RAYON'
      end>
    Properties.OnChange = RayoncxLookupComboBoxPropertiesChange
    TabOrder = 3
    Width = 385
  end
  object NasPunktcxLookupComboBox: TcxLookupComboBox
    Left = 16
    Top = 140
    Properties.KeyFieldNames = 'ID_SADR_NASPUNKT'
    Properties.ListColumns = <
      item
        FieldName = 'NAME_SADR_NASPUNKT'
      end>
    Properties.OnChange = NasPunktcxLookupComboBoxPropertiesChange
    TabOrder = 4
    Width = 385
  end
  object StreetcxLookupComboBox: TcxLookupComboBox
    Left = 16
    Top = 194
    Properties.KeyFieldNames = 'ID_SADR_STREET'
    Properties.ListColumns = <
      item
        FieldName = 'NAME_SADR_STREET'
      end>
    Properties.OnChange = StreetcxLookupComboBoxPropertiesChange
    TabOrder = 5
    Width = 385
  end
  object DomcxLookupComboBox: TcxLookupComboBox
    Left = 304
    Top = 242
    Properties.KeyFieldNames = 'ID_SADR_DOM'
    Properties.ListColumns = <
      item
        FieldName = 'NAME_SADR_DOM'
      end>
    Properties.OnChange = DomcxLookupComboBoxPropertiesChange
    TabOrder = 6
    Width = 97
  end
  object StroencxLookupComboBox: TcxLookupComboBox
    Left = 304
    Top = 292
    Properties.KeyFieldNames = 'ID_SADR_STROEN'
    Properties.ListColumns = <
      item
        FieldName = 'NAME_SADR_STROEN'
      end>
    Properties.OnChange = StroencxLookupComboBoxPropertiesChange
    TabOrder = 7
    Width = 97
  end
  object KVcxLookupComboBox: TcxLookupComboBox
    Left = 304
    Top = 339
    Properties.KeyFieldNames = 'ID_SADR_KV'
    Properties.ListColumns = <
      item
        FieldName = 'NAME_SADR_KV'
      end>
    TabOrder = 8
    Width = 97
  end
  object ButtonInsRegion: TButton
    Left = 407
    Top = 32
    Width = 25
    Height = 25
    Caption = '+'
    TabOrder = 9
    OnClick = ButtonInsRegionClick
  end
  object ButtonUpdRegion: TButton
    Left = 438
    Top = 32
    Width = 27
    Height = 25
    Caption = '...'
    TabOrder = 10
    OnClick = ButtonUpdRegionClick
  end
  object ButtonDelRegion: TButton
    Left = 471
    Top = 32
    Width = 26
    Height = 25
    Caption = '-'
    TabOrder = 11
    OnClick = ButtonDelRegionClick
  end
  object ButtonInsRayon: TButton
    Left = 407
    Top = 86
    Width = 25
    Height = 25
    Caption = '+'
    TabOrder = 12
    OnClick = ButtonInsRayonClick
  end
  object ButtonUpdRayon: TButton
    Left = 438
    Top = 86
    Width = 27
    Height = 25
    Caption = '...'
    TabOrder = 13
    OnClick = ButtonUpdRayonClick
  end
  object ButtonDelRayon: TButton
    Left = 471
    Top = 86
    Width = 26
    Height = 25
    Caption = '-'
    TabOrder = 14
    OnClick = ButtonDelRayonClick
  end
  object ButtonInsNasPunkt: TButton
    Left = 407
    Top = 139
    Width = 25
    Height = 25
    Caption = '+'
    TabOrder = 15
    OnClick = ButtonInsNasPunktClick
  end
  object ButtonUpdNasPunkt: TButton
    Left = 438
    Top = 139
    Width = 27
    Height = 25
    Caption = '...'
    TabOrder = 16
    OnClick = ButtonUpdNasPunktClick
  end
  object ButtonDelNasPunkt: TButton
    Left = 471
    Top = 139
    Width = 26
    Height = 25
    Caption = '-'
    TabOrder = 17
    OnClick = ButtonDelNasPunktClick
  end
  object ButtonInsStreet: TButton
    Left = 407
    Top = 194
    Width = 25
    Height = 25
    Caption = '+'
    TabOrder = 18
    OnClick = ButtonInsStreetClick
  end
  object ButtonUpdStreet: TButton
    Left = 438
    Top = 194
    Width = 27
    Height = 25
    Caption = '...'
    TabOrder = 19
    OnClick = ButtonUpdStreetClick
  end
  object ButtonDelStreet: TButton
    Left = 471
    Top = 194
    Width = 26
    Height = 25
    Caption = '-'
    TabOrder = 20
    OnClick = ButtonDelStreetClick
  end
  object ButtonAddDom: TButton
    Left = 407
    Top = 242
    Width = 25
    Height = 25
    Caption = '+'
    TabOrder = 21
    OnClick = ButtonAddDomClick
  end
  object ButtonUpdDom: TButton
    Left = 438
    Top = 242
    Width = 27
    Height = 25
    Caption = '...'
    TabOrder = 22
    OnClick = ButtonUpdDomClick
  end
  object ButtonDelDom: TButton
    Left = 471
    Top = 242
    Width = 26
    Height = 25
    Caption = '-'
    TabOrder = 23
    OnClick = ButtonDelDomClick
  end
  object ButtonInsStroen: TButton
    Left = 407
    Top = 292
    Width = 25
    Height = 25
    Caption = '+'
    TabOrder = 24
    OnClick = ButtonInsStroenClick
  end
  object ButtonUpdStroen: TButton
    Left = 438
    Top = 292
    Width = 27
    Height = 25
    Caption = '...'
    TabOrder = 25
    OnClick = ButtonUpdStroenClick
  end
  object ButtonDelStroen: TButton
    Left = 471
    Top = 292
    Width = 26
    Height = 25
    Caption = '-'
    TabOrder = 26
    OnClick = ButtonDelStroenClick
  end
  object ButtonInsKV: TButton
    Left = 407
    Top = 339
    Width = 25
    Height = 25
    Caption = '+'
    TabOrder = 27
    OnClick = ButtonInsKVClick
  end
  object ButtonUpdKV: TButton
    Left = 438
    Top = 339
    Width = 27
    Height = 25
    Caption = '...'
    TabOrder = 28
    OnClick = ButtonUpdKVClick
  end
  object ButtonDelKV: TButton
    Left = 471
    Top = 339
    Width = 26
    Height = 25
    Caption = '-'
    TabOrder = 29
    OnClick = ButtonDelKVClick
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 32
    Top = 384
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
    end
    object ActionClose: TAction
      Caption = #1047#1072#1082#1088#1099#1090#1100
      ImageIndex = 53
      OnExecute = ActionCloseExecute
    end
    object ActionOK: TAction
      Caption = #1054#1050
      ImageIndex = 54
      OnExecute = ActionOKExecute
    end
  end
end
