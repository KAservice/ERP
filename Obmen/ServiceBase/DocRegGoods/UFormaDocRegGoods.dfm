object FormaDocRegGoods: TFormaDocRegGoods
  Left = 0
  Top = 0
  Caption = 'FormaDocRegGoods'
  ClientHeight = 548
  ClientWidth = 905
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 120
  TextHeight = 16
  object Label1: TLabel
    Left = 20
    Top = 8
    Width = 90
    Height = 16
    Caption = #1041#1072#1079#1072' '#1080#1089#1090#1086#1095#1085#1080#1082':'
  end
  object Label2: TLabel
    Left = 23
    Top = 117
    Width = 139
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1048#1085#1092#1086#1088#1084#1072#1094#1080#1086#1085#1085#1072#1103' '#1073#1072#1079#1072':'
  end
  object Label3: TLabel
    Left = 23
    Top = 177
    Width = 44
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1060#1080#1088#1084#1072':'
  end
  object Label4: TLabel
    Left = 23
    Top = 249
    Width = 40
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1057#1082#1083#1072#1076':'
  end
  object NameServercxTextEdit: TcxTextEdit
    Left = 117
    Top = 25
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 0
    Text = 'NameServercxTextEdit'
    Width = 158
  end
  object cxLabel1: TcxLabel
    Left = 23
    Top = 32
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1057#1077#1088#1074#1077#1088':'
  end
  object cxLabel2: TcxLabel
    Left = 326
    Top = 26
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1055#1091#1090#1100':'
  end
  object FilecxTextEdit: TcxTextEdit
    Left = 405
    Top = 25
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 3
    Text = 'FilecxTextEdit'
    Width = 315
  end
  object cxButtonViborFile: TcxButton
    Left = 728
    Top = 23
    Width = 65
    Height = 33
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1060#1072#1081#1083
    TabOrder = 4
    OnClick = cxButtonViborFileClick
  end
  object cxLabel3: TcxLabel
    Left = 16
    Top = 57
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1100':'
  end
  object NameUsercxTextEdit: TcxTextEdit
    Left = 116
    Top = 57
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 6
    Text = 'NameUsercxTextEdit'
    Width = 158
  end
  object PasswordUsercxTextEdit: TcxTextEdit
    Left = 342
    Top = 57
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 7
    Text = 'PasswordUsercxTextEdit'
    Width = 158
  end
  object cxLabel4: TcxLabel
    Left = 282
    Top = 57
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1055#1072#1088#1086#1083#1100':'
  end
  object NameBasecxLookupComboBox: TcxLookupComboBox
    Left = 23
    Top = 141
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
    TabOrder = 9
    Width = 228
  end
  object NameFirmcxLookupComboBox: TcxLookupComboBox
    Left = 23
    Top = 200
    Properties.KeyFieldNames = 'IDFIRM'
    Properties.ListColumns = <
      item
        FieldName = 'NAMEFIRM'
      end>
    Properties.ListSource = DataSourceFirm
    TabOrder = 10
    Width = 228
  end
  object NameSkladcxLookupComboBox: TcxLookupComboBox
    Left = 23
    Top = 272
    Properties.KeyFieldNames = 'IDSKLAD'
    Properties.ListColumns = <
      item
        FieldName = 'NAMESKLAD'
      end>
    Properties.ListSource = DataSourceSklad
    TabOrder = 11
    Width = 228
  end
  object Button1: TButton
    Left = 712
    Top = 107
    Width = 161
    Height = 38
    Caption = #1056#1077#1075'. '#1054#1089#1090#1072#1090#1082#1080' '#1090#1086#1074#1072#1088#1086#1074
    TabOrder = 12
    OnClick = Button1Click
  end
  object IBTr: TpFIBTransaction
    Active = True
    DefaultDatabase = DataModuleMain.pFIBDatabase
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 848
    Top = 248
  end
  object DocAll: TpFIBDataSet
    CachedUpdates = True
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
      'from '
      '  GALLDOC'
      ''
      'where(  '
      '  IDDOC=:PARAM_IDDOC'
      '     ) and (     GALLDOC.IDDOC = :OLD_IDDOC'
      '     )'
      '     ')
    SelectSQL.Strings = (
      'select *'
      'from '
      '  GALLDOC'
      ''
      'where '
      '  IDDOC=:PARAM_IDDOC ')
    AutoUpdateOptions.UpdateTableName = 'GALLDOC'
    AutoUpdateOptions.KeyFields = 'IDDOC'
    AutoUpdateOptions.GeneratorName = 'GEN_GALLDOC_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    Database = DataModuleMain.pFIBDatabase
    UpdateTransaction = IBTrUpdate
    Left = 600
    Top = 232
    poUseLargeIntField = True
    object DocAllIDDOC: TFIBLargeIntField
      FieldName = 'IDDOC'
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
    object DocAllIDFIRMDOC: TFIBLargeIntField
      FieldName = 'IDFIRMDOC'
    end
    object DocAllIDSKLDOC: TFIBLargeIntField
      FieldName = 'IDSKLDOC'
    end
    object DocAllIDKLDOC: TFIBLargeIntField
      FieldName = 'IDKLDOC'
    end
    object DocAllIDDOGDOC: TFIBLargeIntField
      FieldName = 'IDDOGDOC'
    end
    object DocAllSUMDOC: TFIBBCDField
      FieldName = 'SUMDOC'
      Size = 2
      RoundByScale = True
    end
    object DocAllIDUSERDOC: TFIBLargeIntField
      FieldName = 'IDUSERDOC'
    end
    object DocAllGID_DOC: TFIBWideStringField
      FieldName = 'GID_DOC'
      Size = 10
    end
    object DocAllPREFIKSDOC: TFIBWideStringField
      FieldName = 'PREFIKSDOC'
      Size = 2
    end
    object DocAllIDDOCOSNDOC: TFIBLargeIntField
      FieldName = 'IDDOCOSNDOC'
    end
    object DocAllIDEXTDOC: TFIBLargeIntField
      FieldName = 'IDEXTDOC'
    end
    object DocAllTYPEEXTDOC: TFIBIntegerField
      FieldName = 'TYPEEXTDOC'
    end
    object DocAllIDBASE_GALLDOC: TFIBLargeIntField
      FieldName = 'IDBASE_GALLDOC'
    end
    object DocAllIDEXT_DOUT_GALLDOC: TFIBLargeIntField
      FieldName = 'IDEXT_DOUT_GALLDOC'
    end
    object DocAllIDEXT_BASE_GALLDOC: TFIBLargeIntField
      FieldName = 'IDEXT_BASE_GALLDOC'
    end
    object DocAllIDPROJECT_GALLDOC: TFIBLargeIntField
      FieldName = 'IDPROJECT_GALLDOC'
    end
  end
  object Doc_RegGoods: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DRG_GOODS'
      'SET '
      '    IDBASE_DRG_GOODS = :IDBASE_DRG_GOODS,'
      '    IDDOC_DRG_GOODS = :IDDOC_DRG_GOODS,'
      '    DESCR_DRG_GOODS = :DESCR_DRG_GOODS'
      'WHERE'
      '    ID_DRG_GOODS = :OLD_ID_DRG_GOODS'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DRG_GOODS'
      'WHERE'
      '        ID_DRG_GOODS = :OLD_ID_DRG_GOODS'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DRG_GOODS('
      '    ID_DRG_GOODS,'
      '    IDBASE_DRG_GOODS,'
      '    IDDOC_DRG_GOODS,'
      '    DESCR_DRG_GOODS'
      ')'
      'VALUES('
      '    :ID_DRG_GOODS,'
      '    :IDBASE_DRG_GOODS,'
      '    :IDDOC_DRG_GOODS,'
      '    :DESCR_DRG_GOODS'
      ')')
    RefreshSQL.Strings = (
      'select drg_goods.*'
      'from  drg_goods'
      'where(  drg_goods.iddoc_drg_goods=:PARAM_IDDOC'
      '     ) and (     DRG_GOODS.ID_DRG_GOODS = :OLD_ID_DRG_GOODS'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select drg_goods.*'
      'from  drg_goods'
      'where drg_goods.iddoc_drg_goods=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'DRG_GOODS'
    AutoUpdateOptions.KeyFields = 'ID_DRG_GOODS'
    AutoUpdateOptions.GeneratorName = 'GEN_DRG_GOODS_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    Database = DataModuleMain.pFIBDatabase
    UpdateTransaction = IBTrUpdate
    Left = 544
    Top = 296
    poUseLargeIntField = True
    object Doc_RegGoodsID_DRG_GOODS: TFIBLargeIntField
      FieldName = 'ID_DRG_GOODS'
    end
    object Doc_RegGoodsIDBASE_DRG_GOODS: TFIBLargeIntField
      FieldName = 'IDBASE_DRG_GOODS'
    end
    object Doc_RegGoodsIDDOC_DRG_GOODS: TFIBLargeIntField
      FieldName = 'IDDOC_DRG_GOODS'
    end
    object Doc_RegGoodsDESCR_DRG_GOODS: TFIBWideStringField
      FieldName = 'DESCR_DRG_GOODS'
      Size = 150
    end
  end
  object DocT_RegGoods: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DRG_GOODST'
      'SET '
      '    IDBASE_DRG_GOODST = :IDBASE_DRG_GOODST,'
      '    IDDOC_DRG_GOODST = :IDDOC_DRG_GOODST,'
      '    TDV_DRG_GOODST = :TDV_DRG_GOODST,'
      '    IDFIRM_DRG_GOODST = :IDFIRM_DRG_GOODST,'
      '    IDSKLAD_DRG_GOODST = :IDSKLAD_DRG_GOODST,'
      '    IDNOM_DRG_GOODST = :IDNOM_DRG_GOODST,'
      '    RPRICE_DRG_GOODST = :RPRICE_DRG_GOODST,'
      '    KOL_DRG_GOODST = :KOL_DRG_GOODST,'
      '    OPER_DRG_GOODST = :OPER_DRG_GOODST,'
      '    TYPE_DRG_GOODST = :TYPE_DRG_GOODST'
      'WHERE'
      '    ID_DRG_GOODST = :OLD_ID_DRG_GOODST'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DRG_GOODST'
      'WHERE'
      '        ID_DRG_GOODST = :OLD_ID_DRG_GOODST'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DRG_GOODST('
      '    ID_DRG_GOODST,'
      '    IDBASE_DRG_GOODST,'
      '    IDDOC_DRG_GOODST,'
      '    TDV_DRG_GOODST,'
      '    IDFIRM_DRG_GOODST,'
      '    IDSKLAD_DRG_GOODST,'
      '    IDNOM_DRG_GOODST,'
      '    RPRICE_DRG_GOODST,'
      '    KOL_DRG_GOODST,'
      '    OPER_DRG_GOODST,'
      '    TYPE_DRG_GOODST'
      ')'
      'VALUES('
      '    :ID_DRG_GOODST,'
      '    :IDBASE_DRG_GOODST,'
      '    :IDDOC_DRG_GOODST,'
      '    :TDV_DRG_GOODST,'
      '    :IDFIRM_DRG_GOODST,'
      '    :IDSKLAD_DRG_GOODST,'
      '    :IDNOM_DRG_GOODST,'
      '    :RPRICE_DRG_GOODST,'
      '    :KOL_DRG_GOODST,'
      '    :OPER_DRG_GOODST,'
      '    :TYPE_DRG_GOODST'
      ')')
    RefreshSQL.Strings = (
      'select drg_goodst.*'
      'from drg_goodst'
      'where(  drg_goodst.iddoc_drg_goodst=:PARAM_IDDOC'
      '     ) and (     DRG_GOODST.ID_DRG_GOODST = :OLD_ID_DRG_GOODST'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select drg_goodst.*'
      'from drg_goodst'
      'where drg_goodst.iddoc_drg_goodst=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'DRG_GOODST'
    AutoUpdateOptions.KeyFields = 'ID_DRG_GOODST'
    AutoUpdateOptions.GeneratorName = 'GEN_DRG_GOODST_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    Database = DataModuleMain.pFIBDatabase
    UpdateTransaction = IBTrUpdate
    Left = 656
    Top = 296
    poUseLargeIntField = True
    object DocT_RegGoodsID_DRG_GOODST: TFIBLargeIntField
      FieldName = 'ID_DRG_GOODST'
    end
    object DocT_RegGoodsIDBASE_DRG_GOODST: TFIBLargeIntField
      FieldName = 'IDBASE_DRG_GOODST'
    end
    object DocT_RegGoodsIDDOC_DRG_GOODST: TFIBLargeIntField
      FieldName = 'IDDOC_DRG_GOODST'
    end
    object DocT_RegGoodsTDV_DRG_GOODST: TFIBSmallIntField
      FieldName = 'TDV_DRG_GOODST'
    end
    object DocT_RegGoodsIDFIRM_DRG_GOODST: TFIBLargeIntField
      FieldName = 'IDFIRM_DRG_GOODST'
    end
    object DocT_RegGoodsIDSKLAD_DRG_GOODST: TFIBLargeIntField
      FieldName = 'IDSKLAD_DRG_GOODST'
    end
    object DocT_RegGoodsIDNOM_DRG_GOODST: TFIBLargeIntField
      FieldName = 'IDNOM_DRG_GOODST'
    end
    object DocT_RegGoodsRPRICE_DRG_GOODST: TFIBBCDField
      FieldName = 'RPRICE_DRG_GOODST'
      Size = 2
      RoundByScale = True
    end
    object DocT_RegGoodsKOL_DRG_GOODST: TFIBBCDField
      FieldName = 'KOL_DRG_GOODST'
      Size = 3
      RoundByScale = True
    end
    object DocT_RegGoodsOPER_DRG_GOODST: TFIBIntegerField
      FieldName = 'OPER_DRG_GOODST'
    end
    object DocT_RegGoodsTYPE_DRG_GOODST: TFIBIntegerField
      FieldName = 'TYPE_DRG_GOODST'
    end
  end
  object IBTrUpdate: TpFIBTransaction
    DefaultDatabase = DataModuleMain.pFIBDatabase
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 784
    Top = 248
  end
  object DocRegGoodsSource: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      'from rggoods'
      'where rggoods.idfirm_rggoods=:PARAM_IDFIRM'
      '        and rggoods.idsklad_rggoods=:PARAM_IDSKLAD')
    Transaction = TransactionSource
    Database = DataBaseSource
    Left = 688
    Top = 160
    object DocRegGoodsSourceID_RGGOODS: TFIBBCDField
      FieldName = 'ID_RGGOODS'
      Size = 0
      RoundByScale = True
    end
    object DocRegGoodsSourceIDFIRM_RGGOODS: TFIBBCDField
      FieldName = 'IDFIRM_RGGOODS'
      Size = 0
      RoundByScale = True
    end
    object DocRegGoodsSourceIDSKLAD_RGGOODS: TFIBBCDField
      FieldName = 'IDSKLAD_RGGOODS'
      Size = 0
      RoundByScale = True
    end
    object DocRegGoodsSourceIDNOM_RGGOODS: TFIBBCDField
      FieldName = 'IDNOM_RGGOODS'
      Size = 0
      RoundByScale = True
    end
    object DocRegGoodsSourceRPRICE_RGGOODS: TFIBBCDField
      FieldName = 'RPRICE_RGGOODS'
      Size = 2
      RoundByScale = True
    end
    object DocRegGoodsSourceKOL_RGGOODS: TFIBBCDField
      FieldName = 'KOL_RGGOODS'
      Size = 3
      RoundByScale = True
    end
    object DocRegGoodsSourceIDBASE_RGGOODS: TFIBBCDField
      FieldName = 'IDBASE_RGGOODS'
      Size = 0
      RoundByScale = True
    end
  end
  object TransactionSource: TpFIBTransaction
    Active = True
    DefaultDatabase = DataBaseSource
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 688
    Top = 104
  end
  object DataBaseSource: TpFIBDatabase
    Connected = True
    DBName = 'K:\NewData\BASE_30.FDB'
    DBParams.Strings = (
      'user_name=SYSDBA'
      'password=masterkey')
    DefaultTransaction = TransactionSource
    DefaultUpdateTransaction = TransactionSource
    SQLDialect = 3
    Timeout = 0
    LibraryName = 'fbclient.dll'
    WaitForRestoreConnect = 0
    Left = 560
    Top = 104
  end
  object DataSourceBaseList: TDataSource
    DataSet = BaseList
    Left = 256
    Top = 136
  end
  object BaseList: TpFIBDataSet
    SelectSQL.Strings = (
      'select * '
      'from sinfbase_obmen')
    Transaction = IBTr
    Database = DataModuleMain.pFIBDatabase
    Left = 352
    Top = 136
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
  object FirmList: TpFIBDataSet
    SelectSQL.Strings = (
      'select sfirm.namefirm,sfirm.idfirm'
      'from sfirm')
    Transaction = IBTr
    Database = DataModuleMain.pFIBDatabase
    Left = 352
    Top = 216
    object FirmListNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 100
    end
    object FirmListIDFIRM: TFIBBCDField
      FieldName = 'IDFIRM'
      Size = 0
      RoundByScale = True
    end
  end
  object SkladList: TpFIBDataSet
    SelectSQL.Strings = (
      'select ssklad.namesklad,ssklad.idsklad'
      'from ssklad')
    Transaction = IBTr
    Database = DataModuleMain.pFIBDatabase
    Left = 352
    Top = 296
    object SkladListNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 100
    end
    object SkladListIDSKLAD: TFIBBCDField
      FieldName = 'IDSKLAD'
      Size = 0
      RoundByScale = True
    end
  end
  object DataSourceFirm: TDataSource
    DataSet = FirmList
    Left = 256
    Top = 216
  end
  object DataSourceSklad: TDataSource
    DataSet = SkladList
    Left = 256
    Top = 296
  end
  object OpenDialog1: TOpenDialog
    Left = 808
    Top = 8
  end
end
