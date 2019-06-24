object FormaAddDataInNewBase: TFormaAddDataInNewBase
  Left = 0
  Top = 0
  Caption = #1057#1086#1079#1076#1072#1085#1080#1077' '#1085#1086#1074#1086#1081' '#1073#1072#1079#1099
  ClientHeight = 540
  ClientWidth = 968
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 120
  TextHeight = 17
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 968
    Height = 145
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 3
      Top = 29
      Width = 150
      Height = 17
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1048#1085#1092#1086#1088#1084#1072#1094#1080#1086#1085#1085#1072#1103' '#1073#1072#1079#1072':'
    end
    object Label2: TLabel
      Left = 10
      Top = 0
      Width = 793
      Height = 18
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = 
        #1042#1085#1080#1084#1072#1085#1080#1077'! '#1056#1072#1079#1076#1077#1083#1080#1090#1077#1083#1100' '#1094#1077#1083#1086#1081' '#1080' '#1076#1088#1086#1073#1085#1086#1081' '#1095#1072#1089#1090#1080' '#1095#1080#1089#1077#1083' - '#1090#1086#1095#1082#1072'! '#1053#1072#1089#1090#1088 +
        #1086#1081#1090#1077' '#1085#1091#1078#1085#1086#1077' '#1079#1085#1072#1095#1077#1085#1080#1077' '#1074' '#1087#1072#1085#1077#1083#1080' '#1091#1087#1088#1072#1074#1083#1077#1085#1080#1103'. '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object NameServercxTextEdit: TcxTextEdit
      Left = 157
      Top = 73
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      TabOrder = 0
      Text = 'NameServercxTextEdit'
      Width = 158
    end
    object FilecxTextEdit: TcxTextEdit
      Left = 157
      Top = 109
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      TabOrder = 1
      Text = 'FilecxTextEdit'
      Width = 315
    end
    object NameUsercxTextEdit: TcxTextEdit
      Left = 632
      Top = 73
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      TabOrder = 2
      Text = 'NameUsercxTextEdit'
      Width = 158
    end
    object PasswordUsercxTextEdit: TcxTextEdit
      Left = 632
      Top = 109
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      TabOrder = 3
      Text = 'PasswordUsercxTextEdit'
      Width = 158
    end
    object cxLabel1: TcxLabel
      Left = 63
      Top = 80
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1077#1088#1074#1077#1088':'
    end
    object cxLabel2: TcxLabel
      Left = 78
      Top = 110
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1091#1090#1100':'
    end
    object cxLabel3: TcxLabel
      Left = 519
      Top = 80
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1100':'
    end
    object cxLabel4: TcxLabel
      Left = 565
      Top = 110
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1072#1088#1086#1083#1100':'
    end
    object NameBasecxLookupComboBox: TcxLookupComboBox
      Left = 157
      Top = 25
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Properties.KeyFieldNames = 'ID_SINFBASE_OBMEN'
      Properties.ListColumns = <
        item
          FieldName = 'NAME_SINFBASE_OBMEN'
        end>
      Properties.ListSource = DataSourceBaseList
      TabOrder = 8
      Width = 227
    end
    object cxButtonViborFile: TcxButton
      Left = 480
      Top = 107
      Width = 65
      Height = 33
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1060#1072#1081#1083
      TabOrder = 9
      OnClick = cxButtonViborFileClick
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 398
    Width = 968
    Height = 142
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object cxButtonAddData: TcxButton
      Left = 664
      Top = 65
      Width = 291
      Height = 33
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1047#1072#1087#1086#1083#1085#1080#1090#1100' '#1085#1086#1074#1091#1102' '#1073#1072#1079#1091
      TabOrder = 0
      OnClick = cxButtonAddDataClick
    end
    object CodeNom1cxCalcEdit: TcxCalcEdit
      Left = 186
      Top = 21
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      EditValue = 0.000000000000000000
      TabOrder = 1
      Width = 103
    end
    object CodeNom2cxCalcEdit: TcxCalcEdit
      Left = 326
      Top = 21
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      EditValue = 0.000000000000000000
      TabOrder = 2
      Width = 106
    end
    object cxLabel5: TcxLabel
      Left = 16
      Top = 21
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1050#1086#1076' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099' '#1089
    end
    object cxLabel6: TcxLabel
      Left = 13
      Top = 69
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1050#1086#1076' '#1077#1076#1080#1085#1080#1094' '#1080#1079#1084#1077#1088#1077#1085#1080#1103' c'
    end
    object cxLabel7: TcxLabel
      Left = 297
      Top = 26
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1087#1086
    end
    object CodeEd1cxCalcEdit: TcxCalcEdit
      Left = 186
      Top = 67
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      EditValue = 0.000000000000000000
      TabOrder = 6
      Width = 103
    end
    object CodeEd2cxCalcEdit: TcxCalcEdit
      Left = 326
      Top = 67
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      EditValue = 0.000000000000000000
      TabOrder = 7
      Width = 106
    end
    object cxLabel8: TcxLabel
      Left = 297
      Top = 102
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1087#1086
    end
    object cxLabel9: TcxLabel
      Left = 297
      Top = 69
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1087#1086
    end
    object CodeCard1cxCalcEdit: TcxCalcEdit
      Left = 186
      Top = 102
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      EditValue = 0.000000000000000000
      TabOrder = 10
      Width = 103
    end
    object CodeCard2cxCalcEdit: TcxCalcEdit
      Left = 326
      Top = 102
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      EditValue = 0.000000000000000000
      TabOrder = 11
      Width = 106
    end
    object cxLabel10: TcxLabel
      Left = 42
      Top = 99
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1050#1086#1076' '#1076#1080#1089#1082'. '#1082#1072#1088#1090' '#1089
    end
    object cxButtonDeleteConstraints: TcxButton
      Left = 664
      Top = 25
      Width = 291
      Height = 25
      Caption = #1059#1076#1072#1083#1080#1090#1100' '#1086#1075#1088#1072#1085#1080#1095#1077#1085#1080#1103' '#1073#1072#1079#1099' ('#1085#1086#1074#1086#1081')'
      TabOrder = 13
      OnClick = cxButtonDeleteConstraintsClick
    end
    object MoveDoccxCheckBox: TcxCheckBox
      Left = 439
      Top = 24
      Caption = #1087#1077#1088#1077#1085#1086#1089#1080#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090#1099
      TabOrder = 14
      Width = 194
    end
  end
  object Memo1: TMemo
    Left = 0
    Top = 145
    Width = 968
    Height = 253
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    Lines.Strings = (
      'Memo1')
    TabOrder = 2
  end
  object BaseList: TpFIBDataSet
    SelectSQL.Strings = (
      'select * '
      'from sinfbase_obmen')
    Transaction = pFIBTransaction1
    Database = DataModuleMain.pFIBDatabase
    Left = 408
    Top = 8
    object BaseListID_SINFBASE_OBMEN: TFIBBCDField
      FieldName = 'ID_SINFBASE_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object BaseListGID_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'GID_SINFBASE_OBMEN'
      Size = 10
    end
    object BaseListNAME_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 100
    end
    object BaseListPREFIKS_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'PREFIKS_SINFBASE_OBMEN'
      Size = 2
    end
    object BaseListIDTIZM_SINFBASE_OBMEN: TFIBIntegerField
      FieldName = 'IDTIZM_SINFBASE_OBMEN'
    end
    object BaseListIDBASE_SINFBASE_OBMEN: TFIBBCDField
      FieldName = 'IDBASE_SINFBASE_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object BaseListNOACT_SINFBASE_OBMEN: TFIBSmallIntField
      FieldName = 'NOACT_SINFBASE_OBMEN'
    end
  end
  object DataSourceBaseList: TDataSource
    DataSet = BaseList
    Left = 320
    Top = 8
  end
  object pFIBTransaction1: TpFIBTransaction
    DefaultDatabase = DataModuleMain.pFIBDatabase
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 496
    Top = 8
  end
  object TableTypePrice: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from XTPRICE_FOR_OBMEN '
      'where IDBASE_OBMEN_XTPRICE_FOR_OBMEN=:PARAM_IDBASE')
    Transaction = pFIBTransaction1
    Database = DataModuleMain.pFIBDatabase
    Left = 616
    Top = 8
    object TableTypePriceID_XTPRICE_FOR_OBMEN: TFIBBCDField
      FieldName = 'ID_XTPRICE_FOR_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object TableTypePriceIDBASE_OBMEN_XTPRICE_FOR_OBMEN: TFIBBCDField
      FieldName = 'IDBASE_OBMEN_XTPRICE_FOR_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object TableTypePriceIDTPRICE_XTPRICE_FOR_OBMEN: TFIBBCDField
      FieldName = 'IDTPRICE_XTPRICE_FOR_OBMEN'
      Size = 0
      RoundByScale = True
    end
  end
  object Query: TpFIBQuery
    Transaction = pFIBTransaction1
    Database = DataModuleMain.pFIBDatabase
    Left = 832
    Top = 72
    qoStartTransaction = True
  end
  object TableBaseForObmen: TpFIBDataSet
    SelectSQL.Strings = (
      
        'select * from XBASE_FOR_OBMEN where IDBASE_OBMEN_XBASE_FOR_OBMEN' +
        '=:PARAM_IDBASE_FOR_OBMEN')
    Transaction = pFIBTransaction1
    Database = DataModuleMain.pFIBDatabase
    Left = 720
    Top = 16
    object TableBaseForObmenID_XBASE_FOR_OBMEN: TFIBBCDField
      FieldName = 'ID_XBASE_FOR_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object TableBaseForObmenIDBASE_OBMEN_XBASE_FOR_OBMEN: TFIBBCDField
      FieldName = 'IDBASE_OBMEN_XBASE_FOR_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object TableBaseForObmenIDBASE_OBJECT_XBASE_FOR_OBMEN: TFIBBCDField
      FieldName = 'IDBASE_OBJECT_XBASE_FOR_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object TableBaseForObmenIDBASE_XBASE_FOR_OBMEN: TFIBBCDField
      FieldName = 'IDBASE_XBASE_FOR_OBMEN'
      Size = 0
      RoundByScale = True
    end
  end
  object QueryUpdate: TpFIBQuery
    Transaction = pFIBTrUpdate
    Database = NewDataBase
    Left = 624
    Top = 344
    qoStartTransaction = True
  end
  object pFIBTrUpdate: TpFIBTransaction
    DefaultDatabase = NewDataBase
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 720
    Top = 344
  end
  object NewDataBase: TpFIBDatabase
    DBParams.Strings = (
      'user_name=SYSDBA'
      'password=masterkey')
    DefaultTransaction = pFIBTrUpdate
    DefaultUpdateTransaction = pFIBTrUpdate
    SQLDialect = 3
    Timeout = 0
    LibraryName = 'fbclient.dll'
    WaitForRestoreConnect = 0
    Left = 536
    Top = 344
  end
  object TableGenerators: TpFIBDataSet
    SelectSQL.Strings = (
      
        'select * from    rdb$generators where (rdb$generators.rdb$system' +
        '_flag is null)'
      '        or (rdb$generators.rdb$system_flag=0)')
    Transaction = NewBaseTrRead
    Database = NewDataBase
    Left = 608
    Top = 264
  end
  object NewBaseTrRead: TpFIBTransaction
    DefaultDatabase = NewDataBase
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 720
    Top = 264
  end
  object TableConstraints: TpFIBDataSet
    SelectSQL.Strings = (
      'SELECT'
      '  C1.RDB$CONSTRAINT_NAME CONST_NAME, '
      
        '  C1.RDB$RELATION_NAME TABLE_NAME, R1.RDB$DESCRIPTION TABLE_DESC' +
        ', '
      '  I1.RDB$FIELD_NAME FIELD_NAME, RF1.RDB$DESCRIPTION FIELD_DESC, '
      
        '  C2.RDB$RELATION_NAME R_TABLE_NAME,  R2.RDB$DESCRIPTION R_TABLE' +
        '_DESC,'
      
        '  I2.RDB$FIELD_NAME R_FIELD_NAME,  RF2.RDB$DESCRIPTION R_FIELD_D' +
        'ESC,'
      
        '  C2.RDB$CONSTRAINT_NAME R_CONST_NAME, C2.RDB$CONSTRAINT_TYPE R_' +
        'CONST_TYPE'
      'FROM'
      '  RDB$RELATION_CONSTRAINTS C1, RDB$REF_CONSTRAINTS RC, '
      '  RDB$RELATION_CONSTRAINTS C2, RDB$INDEX_SEGMENTS I1,'
      '  RDB$INDEX_SEGMENTS I2,  RDB$RELATIONS R1,'
      
        '  RDB$RELATIONS R2,  RDB$RELATION_FIELDS RF1, RDB$RELATION_FIELD' +
        'S RF2'
      'WHERE'
      ' /* C1.RDB$CONSTRAINT_NAME = :FKEY_NAME'
      '  AND */ C1.RDB$CONSTRAINT_NAME = RC.RDB$CONSTRAINT_NAME'
      '  AND C1.RDB$INDEX_NAME = I1.RDB$INDEX_NAME'
      '  AND C1.RDB$CONSTRAINT_TYPE = '#39'FOREIGN KEY'#39
      '  AND I1.RDB$FIELD_POSITION = I2.RDB$FIELD_POSITION'
      '  AND R1.RDB$RELATION_NAME = C1.RDB$RELATION_NAME'
      '  AND (RF1.RDB$SYSTEM_FLAG = 0)'
      '  AND (RF1.RDB$FIELD_NAME = I1.RDB$FIELD_NAME)'
      '  AND (RF1.RDB$RELATION_NAME = C1.RDB$RELATION_NAME)'
      '  AND RC.RDB$CONST_NAME_UQ = C2.RDB$CONSTRAINT_NAME'
      '  AND (C2.RDB$CONSTRAINT_TYPE = '
      '    '#39'PRIMARY KEY'#39' OR  C2.RDB$CONSTRAINT_TYPE = '#39'UNIQUE'#39')'
      '  AND I2.RDB$INDEX_NAME = C2.RDB$INDEX_NAME'
      '  AND R2.RDB$RELATION_NAME = C2.RDB$RELATION_NAME'
      '  AND (RF2.RDB$SYSTEM_FLAG = 0)'
      '  AND (RF2.RDB$FIELD_NAME = I1.RDB$FIELD_NAME)'
      '  AND (RF2.RDB$RELATION_NAME = C1.RDB$RELATION_NAME)')
    Transaction = NewBaseTrRead
    Database = NewDataBase
    Left = 480
    Top = 264
  end
  object OpenDialog1: TOpenDialog
    Left = 344
    Top = 88
  end
  object XSetupObmen: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from XSETUP_OBMEN'
      'where IDBASE_OBMEN_XSETUP_OBMEN=:PARAM_IDBASE')
    Transaction = pFIBTransaction1
    Database = DataModuleMain.pFIBDatabase
    Left = 40
    Top = 32
    object XSetupObmenID_XSETUP_OBMEN: TFIBBCDField
      FieldName = 'ID_XSETUP_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object XSetupObmenIDBASE_OBMEN_XSETUP_OBMEN: TFIBBCDField
      FieldName = 'IDBASE_OBMEN_XSETUP_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object XSetupObmenIDTISM_XSETUP_OBMEN: TFIBBCDField
      FieldName = 'IDTISM_XSETUP_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object XSetupObmenALLDOC_XSETUP_OBMEN: TFIBSmallIntField
      FieldName = 'ALLDOC_XSETUP_OBMEN'
    end
    object XSetupObmenOUTNAC_XSETUP_OBMEN: TFIBSmallIntField
      FieldName = 'OUTNAC_XSETUP_OBMEN'
    end
    object XSetupObmenOUTZPRICE_XSETUP_OBMEN: TFIBSmallIntField
      FieldName = 'OUTZPRICE_XSETUP_OBMEN'
    end
    object XSetupObmenNOEDIT_XSETUP_OBMEN: TFIBSmallIntField
      FieldName = 'NOEDIT_XSETUP_OBMEN'
    end
    object XSetupObmenIDBASE_XSETUP_OBMEN: TFIBBCDField
      FieldName = 'IDBASE_XSETUP_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object XSetupObmenIDEXT_DOUT_XSETUP_OBMEN: TFIBBCDField
      FieldName = 'IDEXT_DOUT_XSETUP_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object XSetupObmenIDEXT_BASE_XSETUP_OBMEN: TFIBBCDField
      FieldName = 'IDEXT_BASE_XSETUP_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object XSetupObmenIDFIRST_DO_XSETUP_OBMEN: TFIBBCDField
      FieldName = 'IDFIRST_DO_XSETUP_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object XSetupObmenOPER_XSETUP_OBMEN: TFIBIntegerField
      FieldName = 'OPER_XSETUP_OBMEN'
    end
  end
  object IBTr: TpFIBTransaction
    DefaultDatabase = DataModuleMain.pFIBDatabase
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 40
    Top = 208
  end
  object DataSource1: TDataSource
    DataSet = Tables
    Left = 40
    Top = 264
  end
  object Tables: TpFIBDataSet
    SelectSQL.Strings = (
      
        'select RDB$RELATION_FIELDS.RDB$FIELD_NAME AS FIELD_NAME, RDB$REL' +
        'ATION_FIELDS.RDB$RELATION_NAME AS TABLE_NAME'
      'from RDB$RELATION_FIELDS'
      
        'left outer join RDB$FIELDS on RDB$RELATION_FIELDS.RDB$FIELD_SOUR' +
        'CE=RDB$FIELDS.RDB$FIELD_NAME'
      ''
      ''
      'where RDB$RELATION_FIELDS.RDB$SYSTEM_FLAG=0  and'
      'RDB$RELATION_FIELDS.RDB$FIELD_SOURCE='#39'DOMAIN_IDTABLE'#39'  '
      'ORDER BY TABLE_NAME')
    Transaction = IBTr
    Database = DataModuleMain.pFIBDatabase
    Left = 128
    Top = 264
    object TablesRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TablesFIELD_NAME: TFIBWideStringField
      FieldName = 'FIELD_NAME'
      Size = 31
    end
    object TablesTABLE_NAME: TFIBWideStringField
      FieldName = 'TABLE_NAME'
      Size = 31
    end
  end
  object Fields: TpFIBDataSet
    SelectSQL.Strings = (
      'select * '
      'from RDB$RELATION_FIELDS'
      
        'left outer join RDB$FIELDS on RDB$RELATION_FIELDS.RDB$FIELD_SOUR' +
        'CE=RDB$FIELDS.RDB$FIELD_NAME'
      ''
      ''
      'where RDB$RELATION_FIELDS.RDB$SYSTEM_FLAG=0'
      'and RDB$RELATION_FIELDS.RDB$RELATION_NAME=:TABLE_NAME')
    Transaction = IBTr
    Database = DataModuleMain.pFIBDatabase
    DataSource = DataSource1
    Left = 128
    Top = 328
    object FieldsRDBFIELD_NAME: TFIBWideStringField
      FieldName = 'RDB$FIELD_NAME'
      Size = 31
    end
    object FieldsRDBFIELD_SOURCE: TFIBWideStringField
      FieldName = 'RDB$FIELD_SOURCE'
      Size = 31
    end
    object FieldsRDBFIELD_SCALE: TFIBSmallIntField
      FieldName = 'RDB$FIELD_SCALE'
    end
    object FieldsRDBFIELD_TYPE: TFIBSmallIntField
      FieldName = 'RDB$FIELD_TYPE'
    end
    object FieldsRDBFIELD_PRECISION: TFIBSmallIntField
      FieldName = 'RDB$FIELD_PRECISION'
    end
  end
end
