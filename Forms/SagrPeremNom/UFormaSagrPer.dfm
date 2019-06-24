object FormaSagrPer: TFormaSagrPer
  Left = 195
  Top = 155
  Caption = #1047#1072#1075#1088#1091#1079#1082#1072' '#1087#1086#1089#1090#1091#1087#1083#1077#1085#1080#1081' '#1090#1086#1074#1072#1088#1086#1074
  ClientHeight = 542
  ClientWidth = 781
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 781
    Height = 29
    Caption = 'ToolBar1'
    EdgeBorders = [ebTop, ebBottom]
    TabOrder = 0
  end
  object Panel1: TPanel
    Left = 0
    Top = 29
    Width = 781
    Height = 68
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 1
    object Label1: TLabel
      Left = 8
      Top = 1
      Width = 401
      Height = 24
      Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' '#1087#1077#1088#1077#1084#1077#1097#1077#1085#1080#1077' '#1080#1079' '#1092#1072#1081#1083#1072
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabelFileName: TLabel
      Left = 40
      Top = 44
      Width = 121
      Height = 16
      Caption = #1060#1072#1081#1083' '#1085#1077' '#1074#1099#1073#1088#1072#1085
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ButtonOpenFile: TButton
      Left = 8
      Top = 35
      Width = 25
      Height = 25
      Caption = '...'
      TabOrder = 0
      OnClick = ButtonOpenFileClick
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 97
    Width = 9
    Height = 368
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 2
  end
  object Panel4: TPanel
    Left = 769
    Top = 97
    Width = 12
    Height = 368
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 3
  end
  object Panel6: TPanel
    Left = 9
    Top = 97
    Width = 760
    Height = 368
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 4
    object PageControl1: TPageControl
      Left = 0
      Top = 0
      Width = 760
      Height = 368
      ActivePage = TabSheet1
      Align = alClient
      TabOrder = 0
      object TabSheet1: TTabSheet
        Caption = #1060#1072#1081#1083
        object Label2: TLabel
          Left = 8
          Top = 176
          Width = 48
          Height = 13
          Caption = #1045#1076#1080#1085#1080#1094#1099':'
        end
        object Label3: TLabel
          Left = 376
          Top = 176
          Width = 31
          Height = 13
          Caption = #1062#1077#1085#1099':'
        end
        object DBGrid1: TDBGrid
          Left = 0
          Top = 0
          Width = 745
          Height = 169
          DataSource = DataSource1
          ReadOnly = True
          TabOrder = 0
          TitleFont.Charset = DEFAULT_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -11
          TitleFont.Name = 'MS Sans Serif'
          TitleFont.Style = []
        end
        object DBGrid2: TDBGrid
          Left = 8
          Top = 192
          Width = 353
          Height = 209
          DataSource = DataSource2
          TabOrder = 1
          TitleFont.Charset = DEFAULT_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -11
          TitleFont.Name = 'MS Sans Serif'
          TitleFont.Style = []
        end
        object DBGrid3: TDBGrid
          Left = 376
          Top = 192
          Width = 361
          Height = 209
          DataSource = DataSource3
          TabOrder = 2
          TitleFont.Charset = DEFAULT_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -11
          TitleFont.Name = 'MS Sans Serif'
          TitleFont.Style = []
        end
      end
      object TabSheet2: TTabSheet
        Caption = #1055#1088#1086#1090#1086#1082#1086#1083
        ImageIndex = 1
        object RichEdit1: TRichEdit
          Left = 0
          Top = 0
          Width = 752
          Height = 340
          Align = alClient
          Lines.Strings = (
            'RichEdit1')
          ScrollBars = ssBoth
          TabOrder = 0
        end
      end
      object TabSheet3: TTabSheet
        Caption = #1043#1088#1091#1087#1087#1099
        ImageIndex = 2
        object DBGrid4: TDBGrid
          Left = 8
          Top = 16
          Width = 497
          Height = 313
          DataSource = DataSource4
          TabOrder = 0
          TitleFont.Charset = DEFAULT_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -11
          TitleFont.Name = 'MS Sans Serif'
          TitleFont.Style = []
        end
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 465
    Width = 781
    Height = 77
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 5
    object ButtonZagr: TButton
      Left = 128
      Top = 32
      Width = 97
      Height = 33
      Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100
      TabOrder = 0
      OnClick = ButtonZagrClick
    end
    object ButtonTest: TButton
      Left = 24
      Top = 32
      Width = 91
      Height = 33
      Caption = #1058#1077#1089#1090
      TabOrder = 1
      OnClick = ButtonTestClick
    end
    object ProgressBar1: TProgressBar
      Left = 8
      Top = 8
      Width = 753
      Height = 16
      TabOrder = 2
    end
    object ButtonBistrZagr: TButton
      Left = 232
      Top = 32
      Width = 107
      Height = 33
      Caption = #1041#1099#1089#1090#1088#1072#1103' '#1079#1072#1075#1088#1091#1079#1082#1072
      TabOrder = 3
      OnClick = ButtonBistrZagrClick
    end
    object CreatePRNCheckBox: TCheckBox
      Left = 392
      Top = 56
      Width = 273
      Height = 17
      Caption = #1089#1086#1079#1076#1072#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' "'#1055#1088#1080#1093#1086#1076#1085#1072#1103' '#1085#1072#1082#1083#1072#1076#1085#1072#1103'"'
      TabOrder = 4
    end
    object UpdateGrpCheckBox: TCheckBox
      Left = 392
      Top = 32
      Width = 161
      Height = 17
      Caption = #1086#1073#1085#1086#1074#1083#1103#1090#1100' '#1075#1088#1091#1087#1087#1099
      TabOrder = 5
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 544
  end
  object DataSource1: TDataSource
    DataSet = ADOTable1
    Left = 624
    Top = 32
  end
  object ADOTable1: TADOTable
    ConnectionString = 
      'Provider=MSDASQL.1;Persist Security Info=False;Data Source='#1060#1072#1081#1083#1099 +
      ' dBASE;Initial Catalog=F:\'#1040#1083#1083#1072#1076#1080#1085'\1'#1057
    CursorType = ctStatic
    TableName = 'Tovar.dbf'
    Left = 584
    Top = 32
  end
  object ADOTable2: TADOTable
    ConnectionString = 
      'Provider=MSDASQL.1;Persist Security Info=False;Data Source='#1060#1072#1081#1083#1099 +
      ' dBASE;Initial Catalog=F:\'#1040#1083#1083#1072#1076#1080#1085'\1'#1057
    CursorType = ctStatic
    TableName = 'Ed.dbf'
    Left = 584
    Top = 64
  end
  object ADOTable3: TADOTable
    ConnectionString = 
      'Provider=MSDASQL.1;Persist Security Info=False;Data Source='#1060#1072#1081#1083#1099 +
      ' dBASE;Initial Catalog=F:\'#1040#1083#1083#1072#1076#1080#1085'\1'#1057
    CursorType = ctStatic
    TableName = 'Price.dbf'
    Left = 584
    Top = 96
  end
  object DataSource2: TDataSource
    DataSet = ADOTable2
    Left = 624
    Top = 64
  end
  object DataSource3: TDataSource
    DataSet = ADOTable3
    Left = 624
    Top = 96
  end
  object SprTPrice1: TIBQuery
    SQL.Strings = (
      'select *  from STPRICE')
    Left = 456
    Top = 88
  end
  object ADOTable4: TADOTable
    IndexFieldNames = 'CODEGRP'
    Left = 680
    Top = 32
  end
  object DataSource4: TDataSource
    DataSet = ADOTable4
    Left = 712
    Top = 32
  end
  object Nom: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE SNOM'
      'SET '
      '    TNOM = :TNOM,'
      '    CODENOM = :CODENOM,'
      '    NAMENOM = :NAMENOM,'
      '    FNAMENOM = :FNAMENOM,'
      '    KRNAMENOM = :KRNAMENOM,'
      '    IDBASEDNOM = :IDBASEDNOM,'
      '    IDOSNEDNOM = :IDOSNEDNOM,'
      '    IDGRPNOM = :IDGRPNOM,'
      '    ARTNOM = :ARTNOM,'
      '    GID_SNOM = :GID_SNOM,'
      '    DESCR_SNOM = :DESCR_SNOM,'
      '    IDFIRMNOM = :IDFIRMNOM,'
      '    STNDSNOM = :STNDSNOM,'
      '    GTDNOM = :GTDNOM,'
      '    IDCOUNTRYNOM = :IDCOUNTRYNOM'
      'WHERE'
      '    IDNOM = :OLD_IDNOM'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SNOM'
      'WHERE'
      '        IDNOM = :OLD_IDNOM'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SNOM('
      '    IDNOM,'
      '    TNOM,'
      '    CODENOM,'
      '    NAMENOM,'
      '    FNAMENOM,'
      '    KRNAMENOM,'
      '    IDBASEDNOM,'
      '    IDOSNEDNOM,'
      '    IDGRPNOM,'
      '    ARTNOM,'
      '    GID_SNOM,'
      '    DESCR_SNOM,'
      '    IDFIRMNOM,'
      '    STNDSNOM,'
      '    GTDNOM,'
      '    IDCOUNTRYNOM'
      ')'
      'VALUES('
      '    :IDNOM,'
      '    :TNOM,'
      '    :CODENOM,'
      '    :NAMENOM,'
      '    :FNAMENOM,'
      '    :KRNAMENOM,'
      '    :IDBASEDNOM,'
      '    :IDOSNEDNOM,'
      '    :IDGRPNOM,'
      '    :ARTNOM,'
      '    :GID_SNOM,'
      '    :DESCR_SNOM,'
      '    :IDFIRMNOM,'
      '    :STNDSNOM,'
      '    :GTDNOM,'
      '    :IDCOUNTRYNOM'
      ')')
    RefreshSQL.Strings = (
      'select * from SNOM where(  CODENOM=:PARAM_CODENOM'
      '     ) and (     SNOM.IDNOM = :OLD_IDNOM'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from SNOM where CODENOM=:PARAM_CODENOM')
    AutoUpdateOptions.UpdateTableName = 'SNOM'
    AutoUpdateOptions.KeyFields = 'IDNOM'
    AutoUpdateOptions.GeneratorName = 'GEN_SNOM_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    Database = DM.pFIBData
    UpdateTransaction = IBTrUpdate
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 112
    Top = 64
    object NomIDNOM: TFIBIntegerField
      FieldName = 'IDNOM'
    end
    object NomTNOM: TFIBIntegerField
      FieldName = 'TNOM'
    end
    object NomCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object NomNAMENOM: TFIBStringField
      FieldName = 'NAMENOM'
      Size = 50
      EmptyStrToNull = True
    end
    object NomFNAMENOM: TFIBStringField
      FieldName = 'FNAMENOM'
      Size = 100
      EmptyStrToNull = True
    end
    object NomKRNAMENOM: TFIBStringField
      FieldName = 'KRNAMENOM'
      Size = 40
      EmptyStrToNull = True
    end
    object NomIDBASEDNOM: TFIBIntegerField
      FieldName = 'IDBASEDNOM'
    end
    object NomIDOSNEDNOM: TFIBIntegerField
      FieldName = 'IDOSNEDNOM'
    end
    object NomIDGRPNOM: TFIBIntegerField
      FieldName = 'IDGRPNOM'
    end
    object NomARTNOM: TFIBStringField
      FieldName = 'ARTNOM'
      EmptyStrToNull = True
    end
    object NomGID_SNOM: TFIBStringField
      FieldName = 'GID_SNOM'
      Size = 10
      EmptyStrToNull = True
    end
    object NomDESCR_SNOM: TFIBStringField
      FieldName = 'DESCR_SNOM'
      Size = 1000
      EmptyStrToNull = True
    end
    object NomIDFIRMNOM: TFIBIntegerField
      FieldName = 'IDFIRMNOM'
    end
    object NomSTNDSNOM: TFIBIntegerField
      FieldName = 'STNDSNOM'
    end
    object NomGTDNOM: TFIBStringField
      FieldName = 'GTDNOM'
      Size = 30
      EmptyStrToNull = True
    end
    object NomIDCOUNTRYNOM: TFIBIntegerField
      FieldName = 'IDCOUNTRYNOM'
    end
  end
  object Ed: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE SED'
      'SET '
      '    NAMEED = :NAMEED,'
      '    KFED = :KFED,'
      '    TSHED = :TSHED,'
      '    SHED = :SHED,'
      '    IDNOMED = :IDNOMED,'
      '    IDOKEIED = :IDOKEIED,'
      '    NEISPED = :NEISPED,'
      '    GID_SED = :GID_SED'
      'WHERE'
      '    IDED = :OLD_IDED'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SED'
      'WHERE'
      '        IDED = :OLD_IDED'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SED('
      '    IDED,'
      '    NAMEED,'
      '    KFED,'
      '    TSHED,'
      '    SHED,'
      '    IDNOMED,'
      '    IDOKEIED,'
      '    NEISPED,'
      '    GID_SED'
      ')'
      'VALUES('
      '    :IDED,'
      '    :NAMEED,'
      '    :KFED,'
      '    :TSHED,'
      '    :SHED,'
      '    :IDNOMED,'
      '    :IDOKEIED,'
      '    :NEISPED,'
      '    :GID_SED'
      ')')
    RefreshSQL.Strings = (
      'select * from SED where(  SHED=:PARAM_SHED'
      '     ) and (     SED.IDED = :OLD_IDED'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from SED where SHED=:PARAM_SHED')
    AutoUpdateOptions.UpdateTableName = 'SED'
    AutoUpdateOptions.KeyFields = 'IDED'
    AutoUpdateOptions.GeneratorName = 'GEN_SED_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    Database = DM.pFIBData
    UpdateTransaction = IBTrUpdate
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 152
    Top = 64
    object EdIDED: TFIBIntegerField
      FieldName = 'IDED'
    end
    object EdNAMEED: TFIBStringField
      FieldName = 'NAMEED'
      Size = 50
      EmptyStrToNull = True
    end
    object EdKFED: TFIBBCDField
      FieldName = 'KFED'
      Size = 3
      RoundByScale = True
    end
    object EdTSHED: TFIBIntegerField
      FieldName = 'TSHED'
    end
    object EdSHED: TFIBStringField
      FieldName = 'SHED'
      Size = 13
      EmptyStrToNull = True
    end
    object EdIDNOMED: TFIBIntegerField
      FieldName = 'IDNOMED'
    end
    object EdIDOKEIED: TFIBIntegerField
      FieldName = 'IDOKEIED'
    end
    object EdNEISPED: TFIBSmallIntField
      FieldName = 'NEISPED'
    end
    object EdGID_SED: TFIBStringField
      FieldName = 'GID_SED'
      Size = 10
      EmptyStrToNull = True
    end
  end
  object Price: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE SPRICE'
      'SET '
      '    IDNOM_PRICE = :IDNOM_PRICE,'
      '    IDTYPE_PRICE = :IDTYPE_PRICE,'
      '    ZNACH_PRICE = :ZNACH_PRICE,'
      '    GID_SPRICE = :GID_SPRICE'
      'WHERE'
      '    ID_PRICE = :OLD_ID_PRICE'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SPRICE'
      'WHERE'
      '        ID_PRICE = :OLD_ID_PRICE'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SPRICE('
      '    ID_PRICE,'
      '    IDNOM_PRICE,'
      '    IDTYPE_PRICE,'
      '    ZNACH_PRICE,'
      '    GID_SPRICE'
      ')'
      'VALUES('
      '    :ID_PRICE,'
      '    :IDNOM_PRICE,'
      '    :IDTYPE_PRICE,'
      '    :ZNACH_PRICE,'
      '    :GID_SPRICE'
      ')')
    RefreshSQL.Strings = (
      'select * from SPRICE where(  ID_PRICE=:PARAM_ID_PRICE'
      '     ) and (     SPRICE.ID_PRICE = :OLD_ID_PRICE'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from SPRICE where ID_PRICE=:PARAM_ID_PRICE')
    AutoUpdateOptions.UpdateTableName = 'SPRICE'
    AutoUpdateOptions.GeneratorName = 'GEN_SPRICE_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    Database = DM.pFIBData
    UpdateTransaction = IBTrUpdate
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 200
    Top = 64
    object PriceID_PRICE: TFIBIntegerField
      FieldName = 'ID_PRICE'
    end
    object PriceIDNOM_PRICE: TFIBIntegerField
      FieldName = 'IDNOM_PRICE'
    end
    object PriceIDTYPE_PRICE: TFIBIntegerField
      FieldName = 'IDTYPE_PRICE'
    end
    object PriceZNACH_PRICE: TFIBBCDField
      FieldName = 'ZNACH_PRICE'
      Size = 2
      RoundByScale = True
    end
    object PriceGID_SPRICE: TFIBStringField
      FieldName = 'GID_SPRICE'
      Size = 10
      EmptyStrToNull = True
    end
  end
  object IBTr: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    CSMonitorSupport.Enabled = csmeDatabaseDriven
    TPBMode = tpbDefault
    Left = 152
    Top = 24
  end
  object IBTrUpdate: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    CSMonitorSupport.Enabled = csmeDatabaseDriven
    TPBMode = tpbDefault
    Left = 200
    Top = 24
  end
  object NomR: TpFIBQuery
    Transaction = IBTr
    Database = DM.pFIBData
    SQL.Strings = (
      'select * from SNOM where CODENOM=:PARAM_CODENOM')
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 424
    Top = 16
  end
  object EdR: TpFIBQuery
    Transaction = IBTr
    Database = DM.pFIBData
    SQL.Strings = (
      'select * from SED where SHED=:PARAM_SHED')
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 464
    Top = 16
  end
  object PriceR: TpFIBQuery
    Transaction = IBTr
    Database = DM.pFIBData
    SQL.Strings = (
      'select * from SPRICE '
      'where '
      'IDNOM_PRICE=:PARAM_IDNOM  AND'
      'IDTYPE_PRICE=:PARAM_IDTYPE_PRICE')
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 496
    Top = 16
  end
  object SprTPrice: TpFIBDataSet
    SelectSQL.Strings = (
      'select *  from STPRICE')
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 424
    Top = 88
  end
  object IBSQL: TpFIBQuery
    Transaction = IBTrUpdate
    Database = DM.pFIBData
    SQL.Strings = (
      'insert into SNOM'
      
        '  (IDNOM, TNOM, CODENOM, NAMENOM, FNAMENOM, KRNAMENOM, IDBASEDNO' +
        'M, IDOSNEDNOM, '
      '   IDGRPNOM, ARTNOM, IDMPRIGNOM)'
      'values'
      
        '  (:IDNOM, :TNOM, :CODENOM, :NAMENOM, :FNAMENOM, :KRNAMENOM, :ID' +
        'BASEDNOM, '
      '   :IDOSNEDNOM, :IDGRPNOM, :ARTNOM, :IDMPRIGNOM)')
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 536
    Top = 112
  end
  object ActionList: TActionList
    Left = 184
    Top = 40
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
    end
  end
end
