object FormaImportOstVs: TFormaImportOstVs
  Left = 0
  Top = 0
  Caption = #1047#1072#1075#1088#1091#1079#1082#1072' '#1086#1089#1090#1072#1090#1082#1086#1074' '#1074#1079#1072#1080#1084#1086#1088#1072#1089#1095#1077#1090#1086#1074
  ClientHeight = 671
  ClientWidth = 1006
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
    Width = 1006
    Height = 158
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 10
      Top = 8
      Width = 404
      Height = 28
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1048#1084#1087#1086#1088#1090' '#1086#1089#1090#1072#1090#1082#1086#1074' '#1074#1079#1072#1080#1084#1086#1088#1072#1089#1095#1077#1090#1086#1074
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -23
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label13: TLabel
      Left = 21
      Top = 50
      Width = 38
      Height = 17
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1060#1072#1081#1083':'
    end
    object Label3: TLabel
      Left = 21
      Top = 84
      Width = 96
      Height = 51
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1090#1088#1086#1082#1072' '#1085#1072#1095#1072#1083#1072' '#1090#1072#1073#1083#1080#1095#1085#1086#1081' '#1095#1072#1089#1090#1080':'
      WordWrap = True
    end
    object Label2: TLabel
      Left = 12
      Top = 126
      Width = 52
      Height = 17
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1050#1083#1080#1077#1085#1090':'
    end
    object Label4: TLabel
      Left = 140
      Top = 126
      Width = 54
      Height = 17
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1088#1080#1093#1086#1076':'
      WordWrap = True
    end
    object Label5: TLabel
      Left = 221
      Top = 84
      Width = 93
      Height = 51
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1090#1088#1086#1082#1072' '#1082#1086#1085#1094#1072' '#1090#1072#1073#1083#1080#1095#1085#1086#1081' '#1095#1072#1089#1090#1080':'
      WordWrap = True
    end
    object Label6: TLabel
      Left = 286
      Top = 126
      Width = 51
      Height = 17
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1056#1072#1089#1093#1086#1076':'
      WordWrap = True
    end
    object FileNamecxButtonEdit: TcxButtonEdit
      Left = 68
      Top = 46
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.OnButtonClick = FileNamecxButtonEditPropertiesButtonClick
      TabOrder = 0
      Text = 'FileNamecxButtonEdit'
      Width = 408
    end
    object StartStringcxSpinEdit: TcxSpinEdit
      Left = 146
      Top = 86
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      TabOrder = 1
      Width = 59
    end
    object NameKlientcxSpinEdit: TcxSpinEdit
      Left = 73
      Top = 123
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      TabOrder = 2
      Width = 59
    end
    object PrihodcxSpinEdit: TcxSpinEdit
      Left = 213
      Top = 122
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      TabOrder = 3
      Width = 59
    end
    object ConStringcxSpinEdit: TcxSpinEdit
      Left = 366
      Top = 86
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      TabOrder = 4
      Width = 59
    end
    object NameInfBasecxLookupComboBox: TcxLookupComboBox
      Left = 732
      Top = 115
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Properties.KeyFieldNames = 'ID_SINFBASE_OBMEN'
      Properties.ListColumns = <
        item
          FieldName = 'NAME_SINFBASE_OBMEN'
        end>
      Properties.ListSource = DataSourceInfBase
      TabOrder = 5
      Width = 263
    end
    object RashodcxSpinEdit: TcxSpinEdit
      Left = 366
      Top = 123
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      TabOrder = 6
      Width = 59
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 615
    Width = 1006
    Height = 56
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object LabelError: TLabel
      Left = 10
      Top = 8
      Width = 828
      Height = 35
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      AutoSize = False
      Caption = 'LabelError'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      WordWrap = True
    end
    object cxButtonClose: TcxButton
      Left = 870
      Top = 8
      Width = 98
      Height = 33
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1047#1072#1082#1088#1099#1090#1100
      TabOrder = 0
      OnClick = cxButtonCloseClick
    end
    object cxButtonImport: TcxButton
      Left = 764
      Top = 8
      Width = 98
      Height = 33
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100
      TabOrder = 1
      OnClick = cxButtonImportClick
    end
  end
  object cxSpreadSheet1: TcxSpreadSheet
    Left = 0
    Top = 158
    Width = 1006
    Height = 457
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    R1C1ReferenceStyle = True
    Align = alClient
    DefaultStyle.Font.Name = 'Tahoma'
    HeaderFont.Charset = DEFAULT_CHARSET
    HeaderFont.Color = clWindowText
    HeaderFont.Height = -11
    HeaderFont.Name = 'Tahoma'
    HeaderFont.Style = []
    PainterType = ptOfficeXPStyle
    RowHeaderWidth = 40
  end
  object OpenDialog1: TOpenDialog
    Left = 368
    Top = 32
  end
  object ActionList: TActionList
    Left = 632
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
    end
    object ActionDeleteString: TAction
      Caption = 'ActionDeleteString'
    end
  end
  object DocAll: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE GALLDOC'
      'SET '
      '    POSDOC = :POSDOC,'
      '    PRDOC = :PRDOC,'
      '    TDOC = :TDOC,'
      '    NUMDOC = :NUMDOC,'
      '    IDFIRMDOC = :IDFIRMDOC,'
      '    IDSKLDOC = :IDSKLDOC,'
      '    IDKLDOC = :IDKLDOC,'
      '    IDDOGDOC = :IDDOGDOC,'
      '    SUMDOC = :SUMDOC,'
      '    IDUSERDOC = :IDUSERDOC,'
      '    GID_DOC = :GID_DOC,'
      '    PREFIKSDOC = :PREFIKSDOC,'
      '    IDDOCOSNDOC = :IDDOCOSNDOC,'
      '    IDEXTDOC = :IDEXTDOC,'
      '    TYPEEXTDOC = :TYPEEXTDOC,'
      '    IDBASE_GALLDOC = :IDBASE_GALLDOC,'
      '    IDPROJECT_GALLDOC = :IDPROJECT_GALLDOC'
      'WHERE'
      '    IDDOC = :OLD_IDDOC'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    GALLDOC'
      'WHERE'
      '        IDDOC = :OLD_IDDOC'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO GALLDOC('
      '    IDDOC,'
      '    POSDOC,'
      '    PRDOC,'
      '    TDOC,'
      '    NUMDOC,'
      '    IDFIRMDOC,'
      '    IDSKLDOC,'
      '    IDKLDOC,'
      '    IDDOGDOC,'
      '    SUMDOC,'
      '    IDUSERDOC,'
      '    GID_DOC,'
      '    PREFIKSDOC,'
      '    IDDOCOSNDOC,'
      '    IDEXTDOC,'
      '    TYPEEXTDOC,'
      '    IDBASE_GALLDOC,'
      '    IDPROJECT_GALLDOC'
      ')'
      'VALUES('
      '    :IDDOC,'
      '    :POSDOC,'
      '    :PRDOC,'
      '    :TDOC,'
      '    :NUMDOC,'
      '    :IDFIRMDOC,'
      '    :IDSKLDOC,'
      '    :IDKLDOC,'
      '    :IDDOGDOC,'
      '    :SUMDOC,'
      '    :IDUSERDOC,'
      '    :GID_DOC,'
      '    :PREFIKSDOC,'
      '    :IDDOCOSNDOC,'
      '    :IDEXTDOC,'
      '    :TYPEEXTDOC,'
      '    :IDBASE_GALLDOC,'
      '    :IDPROJECT_GALLDOC'
      ')')
    RefreshSQL.Strings = (
      'select *'
      'from GALLDOC'
      'where(  IDDOC=:PARAM_ID'
      '     ) and (     GALLDOC.IDDOC = :OLD_IDDOC'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select *'
      'from GALLDOC'
      'where IDDOC=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'GALLDOC'
    AutoUpdateOptions.KeyFields = 'IDDOC'
    AutoUpdateOptions.GeneratorName = 'GEN_GALLDOC_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = TrUpdate
    Database = DataModuleMain.Database
    Left = 504
    Top = 8
    object DocAllIDDOC: TFIBBCDField
      FieldName = 'IDDOC'
      Size = 0
      RoundByScale = True
    end
    object DocAllPOSDOC: TFIBDateTimeField
      FieldName = 'POSDOC'
    end
    object DocAllPRDOC: TFIBSmallIntField
      FieldName = 'PRDOC'
    end
    object DocAllTDOC: TFIBWideStringField
      FieldName = 'TDOC'
      Size = 10
    end
    object DocAllNUMDOC: TFIBIntegerField
      FieldName = 'NUMDOC'
    end
    object DocAllIDFIRMDOC: TFIBBCDField
      FieldName = 'IDFIRMDOC'
      Size = 0
      RoundByScale = True
    end
    object DocAllIDSKLDOC: TFIBBCDField
      FieldName = 'IDSKLDOC'
      Size = 0
      RoundByScale = True
    end
    object DocAllIDKLDOC: TFIBBCDField
      FieldName = 'IDKLDOC'
      Size = 0
      RoundByScale = True
    end
    object DocAllIDDOGDOC: TFIBBCDField
      FieldName = 'IDDOGDOC'
      Size = 0
      RoundByScale = True
    end
    object DocAllSUMDOC: TFIBBCDField
      FieldName = 'SUMDOC'
      Size = 2
      RoundByScale = True
    end
    object DocAllIDUSERDOC: TFIBBCDField
      FieldName = 'IDUSERDOC'
      Size = 0
      RoundByScale = True
    end
    object DocAllGID_DOC: TFIBWideStringField
      FieldName = 'GID_DOC'
      Size = 10
    end
    object DocAllPREFIKSDOC: TFIBWideStringField
      FieldName = 'PREFIKSDOC'
      Size = 2
    end
    object DocAllIDDOCOSNDOC: TFIBBCDField
      FieldName = 'IDDOCOSNDOC'
      Size = 0
      RoundByScale = True
    end
    object DocAllIDEXTDOC: TFIBBCDField
      FieldName = 'IDEXTDOC'
      Size = 0
      RoundByScale = True
    end
    object DocAllTYPEEXTDOC: TFIBIntegerField
      FieldName = 'TYPEEXTDOC'
    end
    object DocAllIDBASE_GALLDOC: TFIBBCDField
      FieldName = 'IDBASE_GALLDOC'
      Size = 0
      RoundByScale = True
    end
    object DocAllIDPROJECT_GALLDOC: TFIBBCDField
      FieldName = 'IDPROJECT_GALLDOC'
      Size = 0
      RoundByScale = True
    end
  end
  object TrUpdate: TpFIBTransaction
    Active = True
    DefaultDatabase = DataModuleMain.Database
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 544
    Top = 8
  end
  object QueryKlient: TpFIBQuery
    Transaction = DataModuleMain.TrRead
    Database = DataModuleMain.Database
    SQL.Strings = (
      'select IDKLIENT'
      'from SKLIENT'
      'where NAMEKLIENT=:PARAM_NAME')
    Left = 696
    Top = 8
    qoStartTransaction = True
  end
  object TrRead: TpFIBTransaction
    Active = True
    DefaultDatabase = DataModuleMain.Database
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 728
    Top = 8
  end
  object Doc: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE DKORRVS'
      'SET '
      '    IDDOC_DKORRVS = :IDDOC_DKORRVS,'
      '    IDBASE_DKORRVS = :IDBASE_DKORRVS,'
      '    PRIM_DKORRVS = :PRIM_DKORRVS'
      'WHERE'
      '    ID_DKORRVS = :OLD_ID_DKORRVS'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DKORRVS'
      'WHERE'
      '        ID_DKORRVS = :OLD_ID_DKORRVS'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DKORRVS('
      '    ID_DKORRVS,'
      '    IDDOC_DKORRVS,'
      '    IDBASE_DKORRVS,'
      '    PRIM_DKORRVS'
      ')'
      'VALUES('
      '    :ID_DKORRVS,'
      '    :IDDOC_DKORRVS,'
      '    :IDBASE_DKORRVS,'
      '    :PRIM_DKORRVS'
      ')')
    RefreshSQL.Strings = (
      'select *'
      'from DKORRVS'
      'where(  IDDOC_DKORRVS=:PARAM_ID'
      '     ) and (     DKORRVS.ID_DKORRVS = :OLD_ID_DKORRVS'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select *'
      'from DKORRVS'
      'where IDDOC_DKORRVS=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'DKORRVS'
    AutoUpdateOptions.KeyFields = 'ID_DKORRVS'
    AutoUpdateOptions.GeneratorName = 'GEN_DKORRVS_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = TrUpdate
    Database = DataModuleMain.Database
    Left = 504
    Top = 40
    object DocID_DKORRVS: TFIBBCDField
      FieldName = 'ID_DKORRVS'
      Size = 0
      RoundByScale = True
    end
    object DocIDDOC_DKORRVS: TFIBBCDField
      FieldName = 'IDDOC_DKORRVS'
      Size = 0
      RoundByScale = True
    end
    object DocIDBASE_DKORRVS: TFIBBCDField
      FieldName = 'IDBASE_DKORRVS'
      Size = 0
      RoundByScale = True
    end
    object DocPRIM_DKORRVS: TFIBStringField
      FieldName = 'PRIM_DKORRVS'
      Size = 150
      EmptyStrToNull = True
    end
  end
  object DocT: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE DKORRVST'
      'SET '
      '    IDDOC_DKORRVST = :IDDOC_DKORRVST,'
      '    IDBASE_DKORRVST = :IDBASE_DKORRVST,'
      '    IDKLIENT_DKORRVST = :IDKLIENT_DKORRVST,'
      '    PRIHOD_DKORRVST = :PRIHOD_DKORRVST,'
      '    RASHOD_DKORRVST = :RASHOD_DKORRVST,'
      '    DVREGPAYSALE_DKORRVST = :DVREGPAYSALE_DKORRVST'
      'WHERE'
      '    ID_DKORRVST = :OLD_ID_DKORRVST'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DKORRVST'
      'WHERE'
      '        ID_DKORRVST = :OLD_ID_DKORRVST'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DKORRVST('
      '    ID_DKORRVST,'
      '    IDDOC_DKORRVST,'
      '    IDBASE_DKORRVST,'
      '    IDKLIENT_DKORRVST,'
      '    PRIHOD_DKORRVST,'
      '    RASHOD_DKORRVST,'
      '    DVREGPAYSALE_DKORRVST'
      ')'
      'VALUES('
      '    :ID_DKORRVST,'
      '    :IDDOC_DKORRVST,'
      '    :IDBASE_DKORRVST,'
      '    :IDKLIENT_DKORRVST,'
      '    :PRIHOD_DKORRVST,'
      '    :RASHOD_DKORRVST,'
      '    :DVREGPAYSALE_DKORRVST'
      ')')
    RefreshSQL.Strings = (
      'select *'
      'from DKORRVST'
      'where(  IDDOC_DKORRVST=:PARAM_ID'
      '     ) and (     DKORRVST.ID_DKORRVST = :OLD_ID_DKORRVST'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select *'
      'from DKORRVST'
      'where IDDOC_DKORRVST=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'DKORRVST'
    AutoUpdateOptions.KeyFields = 'ID_DKORRVST'
    AutoUpdateOptions.GeneratorName = 'GEN_DKORRVST_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = TrUpdate
    Database = DataModuleMain.Database
    Left = 504
    Top = 72
    object DocTID_DKORRVST: TFIBBCDField
      FieldName = 'ID_DKORRVST'
      Size = 0
      RoundByScale = True
    end
    object DocTIDDOC_DKORRVST: TFIBBCDField
      FieldName = 'IDDOC_DKORRVST'
      Size = 0
      RoundByScale = True
    end
    object DocTIDBASE_DKORRVST: TFIBBCDField
      FieldName = 'IDBASE_DKORRVST'
      Size = 0
      RoundByScale = True
    end
    object DocTIDKLIENT_DKORRVST: TFIBBCDField
      FieldName = 'IDKLIENT_DKORRVST'
      Size = 0
      RoundByScale = True
    end
    object DocTPRIHOD_DKORRVST: TFIBBCDField
      FieldName = 'PRIHOD_DKORRVST'
      Size = 2
      RoundByScale = True
    end
    object DocTRASHOD_DKORRVST: TFIBBCDField
      FieldName = 'RASHOD_DKORRVST'
      Size = 2
      RoundByScale = True
    end
    object DocTDVREGPAYSALE_DKORRVST: TFIBIntegerField
      FieldName = 'DVREGPAYSALE_DKORRVST'
    end
  end
  object InfBase: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from sinfbase_obmen')
    Transaction = TrRead
    Database = DataModuleMain.Database
    Left = 696
    Top = 88
    object InfBaseID_SINFBASE_OBMEN: TFIBBCDField
      FieldName = 'ID_SINFBASE_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object InfBaseGID_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'GID_SINFBASE_OBMEN'
      Size = 10
    end
    object InfBaseNAME_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 100
    end
    object InfBasePREFIKS_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'PREFIKS_SINFBASE_OBMEN'
      Size = 2
    end
    object InfBaseIDTIZM_SINFBASE_OBMEN: TFIBIntegerField
      FieldName = 'IDTIZM_SINFBASE_OBMEN'
    end
    object InfBaseIDBASE_SINFBASE_OBMEN: TFIBBCDField
      FieldName = 'IDBASE_SINFBASE_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object InfBaseNOACT_SINFBASE_OBMEN: TFIBSmallIntField
      FieldName = 'NOACT_SINFBASE_OBMEN'
    end
  end
  object DataSourceInfBase: TDataSource
    DataSet = InfBase
    Left = 664
    Top = 88
  end
end
