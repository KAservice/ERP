object FormaReportRealHotel: TFormaReportRealHotel
  Left = 394
  Top = 196
  Width = 457
  Height = 323
  Caption = #1054#1090#1095#1077#1090' '#1086' '#1087#1088#1086#1076#1072#1078#1072#1093' '#1090#1086#1074#1072#1088#1086#1074' '#1080' '#1091#1089#1083#1091#1075' '#1074' '#1075#1086#1089#1090#1080#1085#1080#1094#1077':'
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
    Width = 375
    Height = 24
    Caption = #1056#1077#1072#1083#1080#1079#1072#1094#1080#1103'  '#1090#1086#1074#1072#1088#1086#1074' '#1080' '#1091#1089#1083#1091#1075' ('#1075#1086#1089#1090#1080#1085#1080#1094#1072'):'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 16
    Top = 48
    Width = 12
    Height = 29
    Caption = 'c'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 200
    Top = 48
    Width = 29
    Height = 29
    Caption = #1087#1086
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 32
    Top = 112
    Width = 37
    Height = 13
    Caption = #1057#1082#1083#1072#1076' :'
  end
  object Label5: TLabel
    Left = 24
    Top = 168
    Width = 61
    Height = 13
    Caption = #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090':'
  end
  object Label6: TLabel
    Left = 32
    Top = 192
    Width = 35
    Height = 13
    Caption = #1043#1088#1091#1087#1087#1072
  end
  object Label7: TLabel
    Left = 16
    Top = 208
    Width = 77
    Height = 13
    Caption = #1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099':'
  end
  object DateNach: TDateTimePicker
    Left = 40
    Top = 48
    Width = 153
    Height = 28
    CalAlignment = dtaLeft
    Date = 38654
    Time = 38654
    DateFormat = dfShort
    DateMode = dmComboBox
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Kind = dtkDate
    ParseInput = False
    ParentFont = False
    TabOrder = 0
  end
  object DateCon: TDateTimePicker
    Left = 240
    Top = 48
    Width = 153
    Height = 28
    CalAlignment = dtaLeft
    Date = 38654.9999884259
    Time = 38654.9999884259
    DateFormat = dfShort
    DateMode = dmComboBox
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Kind = dtkDate
    ParseInput = False
    ParentFont = False
    TabOrder = 1
  end
  object ButtonClose: TButton
    Left = 320
    Top = 240
    Width = 89
    Height = 33
    Caption = #1047#1072#1082#1088#1099#1090#1100
    TabOrder = 2
    OnClick = ButtonCloseClick
  end
  object NameSkladEdit: TEdit
    Left = 96
    Top = 104
    Width = 273
    Height = 21
    Color = clBtnFace
    TabOrder = 3
    Text = 'NameSkladEdit'
  end
  object ButtonViborSklad: TButton
    Left = 368
    Top = 104
    Width = 21
    Height = 21
    Caption = '...'
    TabOrder = 4
    OnClick = ButtonViborSkladClick
  end
  object NameKlientEdit: TEdit
    Left = 96
    Top = 160
    Width = 273
    Height = 21
    Color = clBtnFace
    TabOrder = 5
    Text = 'NameKlientEdit'
  end
  object ButtonViborKlienta: TButton
    Left = 368
    Top = 160
    Width = 21
    Height = 21
    Caption = '...'
    TabOrder = 6
    OnClick = ButtonViborKlientaClick
  end
  object PoDateCheckBox: TCheckBox
    Left = 8
    Top = 248
    Width = 97
    Height = 17
    Caption = #1087#1086' '#1076#1072#1090#1072#1084
    TabOrder = 7
  end
  object AllSkladCheckBox: TCheckBox
    Left = 96
    Top = 80
    Width = 97
    Height = 17
    Caption = #1074#1089#1077' '#1089#1082#1083#1072#1076#1099
    TabOrder = 8
    OnClick = AllSkladCheckBoxClick
  end
  object AllKlientCheckBox: TCheckBox
    Left = 96
    Top = 136
    Width = 113
    Height = 17
    Caption = #1074#1089#1077' '#1082#1086#1085#1090#1088#1072#1075#1077#1085#1090#1099
    TabOrder = 9
    OnClick = AllKlientCheckBoxClick
  end
  object RasvorotSkladCheckBox: TCheckBox
    Left = 216
    Top = 80
    Width = 161
    Height = 17
    Caption = #1088#1072#1079#1074#1086#1088#1072#1095#1080#1074#1072#1090#1100' '#1087#1086' '#1089#1082#1083#1072#1076#1072#1084
    TabOrder = 10
  end
  object RasvorotKlientCheckBox: TCheckBox
    Left = 216
    Top = 136
    Width = 185
    Height = 17
    Caption = #1088#1072#1079#1074#1086#1088#1072#1095#1080#1074#1072#1090#1100' '#1087#1086' '#1082#1086#1085#1090#1088#1072#1075#1077#1085#1090#1072#1084
    TabOrder = 11
  end
  object ButtonCreateReport: TButton
    Left = 216
    Top = 240
    Width = 99
    Height = 33
    Caption = #1054#1090#1095#1077#1090
    TabOrder = 12
    OnClick = ButtonCreateReportClick
  end
  object NameGrpNomEdit: TEdit
    Left = 96
    Top = 200
    Width = 273
    Height = 21
    Color = clBtnFace
    ReadOnly = True
    TabOrder = 13
    Text = 'NameGrpNomEdit'
  end
  object OpenGrpNomButton: TButton
    Left = 368
    Top = 200
    Width = 21
    Height = 21
    Caption = '...'
    TabOrder = 14
    OnClick = OpenGrpNomButtonClick
  end
  object ClearViborGrpNomButton: TButton
    Left = 392
    Top = 200
    Width = 21
    Height = 21
    Caption = 'X'
    TabOrder = 15
    OnClick = ClearViborGrpNomButtonClick
  end
  object IBQGrp: TIBQuery
    Database = DM.IBData
    Transaction = IBTr
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      
        'select  NAMEGN, IDGN,SUM(SUM_SCHET_HOT_T)  AS SUMMA, SUM(KF_SCHE' +
        'T_HOT_T*KOL_SCHET_HOT_T)  AS SUMKOL'
      ''
      'from '
      '  DSCHET_HOT_T'
      'left outer join SNOM on IDNOM_SHET_HOT_T=IDNOM'
      'left outer join SGRPNOM on IDGRPNOM=IDGN'
      'left outer join GALLDOC on IDDOC_SCHET_HOT_T=IDDOC'
      'where POSDOC  between :PARAM_POSNACH and :PARAM_POSCON'
      'group by NAMEGN, IDGN')
    Left = 416
    Top = 112
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'PARAM_POSNACH'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'PARAM_POSCON'
        ParamType = ptUnknown
      end>
    object IBQGrpNAMEGN: TIBStringField
      FieldName = 'NAMEGN'
      Size = 50
    end
    object IBQGrpSUMMA: TIBBCDField
      FieldName = 'SUMMA'
      DisplayFormat = '.00'
      Precision = 18
      Size = 2
    end
    object IBQGrpSUMKOL: TFloatField
      FieldName = 'SUMKOL'
    end
    object IBQGrpIDGN: TIntegerField
      FieldName = 'IDGN'
    end
  end
  object IBTr: TIBTransaction
    Active = False
    DefaultDatabase = DM.IBData
    Params.Strings = (
      'read_committed'
      'rec_version'
      'nowait')
    AutoStopAction = saNone
    Left = 416
    Top = 8
  end
  object IBQEl: TIBQuery
    Database = DM.IBData
    Transaction = IBTr
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      
        'select  NAMENOM, NAMEED, SUM(SUM_SCHET_HOT_T)  AS SUMMA, SUM(KF_' +
        'SCHET_HOT_T*KOL_SCHET_HOT_T)  AS SUMKOL'
      'from '
      '  D_SCHET_HOT_T'
      'left outer join SNOM on IDNOM_SCHET_HOT_T=IDNOM'
      'left outer join SGRPNOM on IDGRPNOM=IDGN'
      'left outer join SED on IDBASEDNOM=IDED'
      'left outer join GALLDOC on IDDOC_SCHET_HOT_T=IDDOC'
      'where (POSDOC  between :PARAM_POSNACH and :PARAM_POSCON)'
      'and  (IDGN=:PARAM_IDGN)'
      'group by NAMENOM, NAMEED')
    Left = 416
    Top = 144
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'PARAM_POSNACH'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'PARAM_POSCON'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'PARAM_IDGN'
        ParamType = ptUnknown
      end>
    object IBQElNAMENOM: TIBStringField
      FieldName = 'NAMENOM'
      Size = 50
    end
    object IBQElSUMMA: TIBBCDField
      FieldName = 'SUMMA'
      Precision = 18
      Size = 2
    end
    object IBQElSUMKOL: TFloatField
      FieldName = 'SUMKOL'
    end
    object IBQElNAMEED: TIBStringField
      FieldName = 'NAMEED'
      Size = 50
    end
  end
  object IBQSkl: TIBQuery
    Database = DM.IBData
    Transaction = IBTr
    BufferChunks = 1000
    CachedUpdates = False
    Left = 416
    Top = 48
  end
  object IBQKl: TIBQuery
    Database = DM.IBData
    Transaction = IBTr
    BufferChunks = 1000
    CachedUpdates = False
    Left = 416
    Top = 80
  end
  object IBQ: TIBQuery
    Database = DM.IBData
    Transaction = IBTr
    BufferChunks = 1000
    CachedUpdates = False
    Left = 8
    Top = 176
  end
end
