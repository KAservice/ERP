object FormaDialogaReportSaleCheck: TFormaDialogaReportSaleCheck
  Left = 152
  Top = 110
  Caption = #1054#1090#1095#1077#1090' '#1086' '#1087#1088#1086#1076#1072#1078#1072#1093' '#1090#1086#1074#1072#1088#1086#1074' '#1080' '#1091#1089#1083#1091#1075' ('#1088#1086#1079#1085'.)::'
  ClientHeight = 200
  ClientWidth = 410
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
    Width = 336
    Height = 26
    Caption = #1055#1088#1086#1076#1072#1078#1080' '#1090#1086#1074#1072#1088#1086#1074' '#1080' '#1091#1089#1083#1091#1075' ('#1088#1086#1079#1085'.):'
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
    Left = 208
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
    Top = 104
    Width = 34
    Height = 13
    Caption = #1057#1082#1083#1072#1076':'
  end
  object Label5: TLabel
    Left = 16
    Top = 176
    Width = 239
    Height = 13
    Caption = #1054#1090#1095#1077#1090' '#1092#1086#1088#1084#1080#1088#1091#1077#1090#1089#1103' '#1087#1086' '#1076#1086#1082#1091#1084#1077#1085#1090#1072#1084' "'#1063#1077#1082' '#1050#1050#1052'"'
  end
  object DateNach: TcxDateEdit
    Left = 56
    Top = 53
    Properties.Kind = ckDateTime
    TabOrder = 0
    Width = 121
  end
  object DateCon: TcxDateEdit
    Left = 259
    Top = 53
    Properties.Kind = ckDateTime
    TabOrder = 1
    Width = 121
  end
  object NameSkladEdit: TcxButtonEdit
    Left = 88
    Top = 101
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameSkladEditPropertiesButtonClick
    TabOrder = 2
    Text = 'NameSkladEdit'
    Width = 292
  end
  object cxButtonCreate: TcxButton
    Left = 182
    Top = 145
    Width = 97
    Height = 25
    Caption = #1057#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 3
    OnClick = cxButtonCreateClick
  end
  object cxButtonClose: TcxButton
    Left = 305
    Top = 145
    Width = 75
    Height = 25
    Caption = #1047#1072#1082#1088#1099#1090#1100
    TabOrder = 4
  end
  object Grp: TpFIBDataSet
    SelectSQL.Strings = (
      
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
    Transaction = IBTr
    Left = 56
    Top = 136
    object GrpSUMMA: TFIBBCDField
      FieldName = 'SUMMA'
      Size = 2
      RoundByScale = True
    end
    object GrpSUMKOL: TFIBFloatField
      FieldName = 'SUMKOL'
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
    Transaction = IBTr
    Left = 24
    Top = 136
    object ElSUMMA: TFIBBCDField
      FieldName = 'SUMMA'
      Size = 2
      RoundByScale = True
    end
    object ElSUMKOL: TFIBFloatField
      FieldName = 'SUMKOL'
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
  object IBTr: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 8
    Top = 96
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 8
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
end
