object FormaReportKalkKarta: TFormaReportKalkKarta
  Left = 148
  Top = 92
  Caption = #1050#1072#1083#1100#1082#1091#1083#1103#1094#1080#1086#1085#1085#1072#1103' '#1082#1072#1088#1090#1086#1095#1082#1072' '#1073#1083#1102#1076#1072':'
  ClientHeight = 243
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
    Left = 8
    Top = 8
    Width = 250
    Height = 26
    Caption = #1050#1072#1083#1100#1082#1091#1083#1103#1094#1080#1086#1085#1085#1072#1103' '#1082#1072#1088#1090#1072':'
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
    Top = 104
    Width = 34
    Height = 13
    Caption = #1057#1082#1083#1072#1076':'
  end
  object Label5: TLabel
    Left = 32
    Top = 168
    Width = 43
    Height = 13
    Caption = #1058#1080#1087' '#1094#1077#1085':'
  end
  object Label6: TLabel
    Left = 8
    Top = 136
    Width = 77
    Height = 13
    Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072':'
  end
  object cxButtonCreate: TcxButton
    Left = 247
    Top = 208
    Width = 91
    Height = 25
    Caption = #1057#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 0
    OnClick = cxButtonCreateClick
  end
  object cxButtonClose: TcxButton
    Left = 344
    Top = 208
    Width = 75
    Height = 25
    Action = ActionClose
    TabOrder = 1
  end
  object TypePriceComboBox: TcxComboBox
    Left = 96
    Top = 164
    Properties.DropDownListStyle = lsFixedList
    Properties.OnChange = TypePriceComboBoxPropertiesChange
    TabOrder = 2
    Width = 293
  end
  object NameNomEdit: TcxButtonEdit
    Left = 96
    Top = 133
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameNomEditPropertiesButtonClick
    TabOrder = 3
    Text = 'NameNomEdit'
    Width = 293
  end
  object NameSkladEdit: TcxButtonEdit
    Left = 96
    Top = 99
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameSkladEditPropertiesButtonClick
    TabOrder = 4
    Text = 'NameSkladEdit'
    Width = 293
  end
  object DateNach: TcxDateEdit
    Left = 34
    Top = 53
    Properties.Kind = ckDateTime
    TabOrder = 5
    Width = 184
  end
  object DateCon: TcxDateEdit
    Left = 259
    Top = 53
    Properties.Kind = ckDateTime
    TabOrder = 6
    Width = 174
  end
  object El1: TpFIBDataSet
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
      'left outer join SED on IDBASEDNOM=IDED'
      
        'where (POSDOC_RGREAL_DV  between :PARAM_POSNACH and :PARAM_POSCO' +
        'N)'
      'and  (IDNOM_RGREAL_DV=:PARAM_IDNOM)'
      'group by NAMENOM, NAMEED, IDNOM'
      '')
    Transaction = IBTr
    Left = 56
    Top = 200
    object El1SUMREAL: TFIBBCDField
      FieldName = 'SUMREAL'
      Size = 2
      RoundByScale = True
    end
    object El1SEBREAL: TFIBBCDField
      FieldName = 'SEBREAL'
      Size = 2
      RoundByScale = True
    end
    object El1RESREAL: TFIBBCDField
      FieldName = 'RESREAL'
      Size = 2
      RoundByScale = True
    end
    object El1KOLREAL: TFIBBCDField
      FieldName = 'KOLREAL'
      Size = 3
      RoundByScale = True
    end
    object El1KOLOTRREAL: TFIBBCDField
      FieldName = 'KOLOTRREAL'
      Size = 3
      RoundByScale = True
    end
    object El1IDNOM: TFIBBCDField
      FieldName = 'IDNOM'
      Size = 0
      RoundByScale = True
    end
    object El1NAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 100
    end
    object El1NAMEED: TFIBWideStringField
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
    Left = 384
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
    Top = 88
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
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 16
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
end
