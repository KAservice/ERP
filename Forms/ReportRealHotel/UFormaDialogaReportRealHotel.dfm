object FormaDialogaReportRealRest: TFormaDialogaReportRealRest
  Left = 296
  Top = 121
  Width = 463
  Height = 281
  Caption = #1054#1090#1095#1077#1090' '#1086' '#1087#1088#1086#1076#1072#1078#1072#1093' '#1090#1086#1074#1072#1088#1086#1074' '#1080' '#1091#1089#1083#1091#1075' ('#1088#1086#1079#1085'.):'
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
    Width = 371
    Height = 24
    Caption = #1056#1077#1072#1083#1080#1079#1072#1094#1080#1103'  '#1090#1086#1074#1072#1088#1086#1074' '#1080' '#1091#1089#1083#1091#1075' ('#1088#1077#1089#1090#1086#1088#1072#1085'.):'
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
    Left = 48
    Top = 104
    Width = 34
    Height = 13
    Caption = #1057#1082#1083#1072#1076':'
  end
  object Label5: TLabel
    Left = 24
    Top = 136
    Width = 61
    Height = 13
    Caption = #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090':'
  end
  object ButtonRun: TButton
    Left = 192
    Top = 176
    Width = 91
    Height = 33
    Caption = #1057#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 0
    OnClick = ButtonRunClick
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
    TabOrder = 1
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
    TabOrder = 2
  end
  object ButtonClose: TButton
    Left = 296
    Top = 176
    Width = 97
    Height = 33
    Caption = #1047#1072#1082#1088#1099#1090#1100
    TabOrder = 3
    OnClick = ButtonCloseClick
  end
  object NameSkladEdit: TEdit
    Left = 96
    Top = 96
    Width = 273
    Height = 21
    Color = clBtnFace
    TabOrder = 4
    Text = 'NameSkladEdit'
  end
  object ButtonViborSklad: TButton
    Left = 368
    Top = 96
    Width = 21
    Height = 21
    Caption = '...'
    TabOrder = 5
    OnClick = ButtonViborSkladClick
  end
  object NameKlientEdit: TEdit
    Left = 96
    Top = 128
    Width = 273
    Height = 21
    Color = clBtnFace
    TabOrder = 6
    Text = 'NameKlientEdit'
  end
  object ButtonViborKlienta: TButton
    Left = 368
    Top = 128
    Width = 21
    Height = 21
    Caption = '...'
    TabOrder = 7
    OnClick = ButtonViborKlientaClick
  end
  object IBQGrp: TIBQuery
    Database = DM.IBData
    Transaction = IBTr
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      
        'select  NAMEGN, IDGN,SUM(SUMCHKT)  AS SUMMA, SUM(KFCHKT*KOLCHKT)' +
        '  AS SUMKOL'
      ''
      'from '
      '  DCHKT'
      'left outer join SNOM on IDNOMCHKT=IDNOM'
      'left outer join SGRPNOM on IDGRPNOM=IDGN'
      'left outer join GALLDOC on IDDOCCHKT=IDDOC'
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
      
        'select  NAMENOM, NAMEED, SUM(SUMCHKT)  AS SUMMA, SUM(KFCHKT*KOLC' +
        'HKT)  AS SUMKOL'
      'from '
      '  DCHKT'
      'left outer join SNOM on IDNOMCHKT=IDNOM'
      'left outer join SGRPNOM on IDGRPNOM=IDGN'
      'left outer join SED on IDBASEDNOM=IDED'
      'left outer join GALLDOC on IDDOCCHKT=IDDOC'
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
end
