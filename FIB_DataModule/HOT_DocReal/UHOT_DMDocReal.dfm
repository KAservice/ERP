object HOT_DMDocReal: THOT_DMDocReal
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 272
  Width = 439
  object DataSourceDoc: TDataSource
    DataSet = Doc
    Left = 72
    Top = 72
  end
  object DataSourceDocT: TDataSource
    DataSet = DocT
    Left = 72
    Top = 128
  end
  object DataSourceDocAll: TDataSource
    DataSet = DocAll
    Left = 72
    Top = 16
  end
  object IBTr: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 216
    Top = 16
  end
  object IBTrUpdate: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 216
    Top = 72
  end
  object DocAll: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE HOT_GALLDOC'
      'SET '
      '    GID_HOT_GALLDOC = :GID_HOT_GALLDOC,'
      '    POS_HOT_GALLDOC = :POS_HOT_GALLDOC,'
      '    PR_HOT_GALLDOC = :PR_HOT_GALLDOC,'
      '    TDOC_HOT_GALLDOC = :TDOC_HOT_GALLDOC,'
      '    PREFIKS_HOT_GALLDOC = :PREFIKS_HOT_GALLDOC,'
      '    IDFIRM_HOT_GALLDOC = :IDFIRM_HOT_GALLDOC,'
      '    IDKL_HOT_GALLDOC = :IDKL_HOT_GALLDOC,'
      '    SUM_HOT_GALLDOC = :SUM_HOT_GALLDOC,'
      '    IDUSER_HOT_GALLDOC = :IDUSER_HOT_GALLDOC,'
      '    IDDOCOSN_HOT_GALLDOC = :IDDOCOSN_HOT_GALLDOC,'
      '    NUMBER_HOT_GALLDOC = :NUMBER_HOT_GALLDOC,'
      '    IDSKLAD_HOT_GALLDOC = :IDSKLAD_HOT_GALLDOC,'
      '    IDBASE_HOT_GALLDOC = :IDBASE_HOT_GALLDOC'
      'WHERE'
      '    ID_HOT_GALLDOC = :OLD_ID_HOT_GALLDOC'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    HOT_GALLDOC'
      'WHERE'
      '        ID_HOT_GALLDOC = :OLD_ID_HOT_GALLDOC'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO HOT_GALLDOC('
      '    ID_HOT_GALLDOC,'
      '    GID_HOT_GALLDOC,'
      '    POS_HOT_GALLDOC,'
      '    PR_HOT_GALLDOC,'
      '    TDOC_HOT_GALLDOC,'
      '    PREFIKS_HOT_GALLDOC,'
      '    IDFIRM_HOT_GALLDOC,'
      '    IDKL_HOT_GALLDOC,'
      '    SUM_HOT_GALLDOC,'
      '    IDUSER_HOT_GALLDOC,'
      '    IDDOCOSN_HOT_GALLDOC,'
      '    NUMBER_HOT_GALLDOC,'
      '    IDSKLAD_HOT_GALLDOC,'
      '    IDBASE_HOT_GALLDOC'
      ')'
      'VALUES('
      '    :ID_HOT_GALLDOC,'
      '    :GID_HOT_GALLDOC,'
      '    :POS_HOT_GALLDOC,'
      '    :PR_HOT_GALLDOC,'
      '    :TDOC_HOT_GALLDOC,'
      '    :PREFIKS_HOT_GALLDOC,'
      '    :IDFIRM_HOT_GALLDOC,'
      '    :IDKL_HOT_GALLDOC,'
      '    :SUM_HOT_GALLDOC,'
      '    :IDUSER_HOT_GALLDOC,'
      '    :IDDOCOSN_HOT_GALLDOC,'
      '    :NUMBER_HOT_GALLDOC,'
      '    :IDSKLAD_HOT_GALLDOC,'
      '    :IDBASE_HOT_GALLDOC'
      ')')
    RefreshSQL.Strings = (
      
        'select HOT_GALLDOC. *, NAME_SINFBASE_OBMEN, NAMEFIRM, NAMEKLIENT' +
        ', FNAME_USER, NAMESKLAD'
      'from HOT_GALLDOC'
      
        'left outer join SINFBASE_OBMEN on PREFIKS_SINFBASE_OBMEN= PREFIK' +
        'S_HOT_GALLDOC'
      'left outer join SFIRM on IDFIRM=IDFIRM_HOT_GALLDOC'
      'left outer join SKLIENT on IDKLIENT=IDKL_HOT_GALLDOC'
      'left outer join SUSER on IDUSER_HOT_GALLDOC=ID_USER'
      'left outer join SSKLAD on IDSKLAD=IDSKLAD_HOT_GALLDOC'
      'where(  ID_HOT_GALLDOC=:ID'
      
        '     ) and (     HOT_GALLDOC.ID_HOT_GALLDOC = :OLD_ID_HOT_GALLDO' +
        'C'
      '     )'
      '     ')
    SelectSQL.Strings = (
      
        'select HOT_GALLDOC. *, NAME_SINFBASE_OBMEN, NAMEFIRM, NAMEKLIENT' +
        ', FNAME_USER, NAMESKLAD'
      'from HOT_GALLDOC'
      
        'left outer join SINFBASE_OBMEN on PREFIKS_SINFBASE_OBMEN= PREFIK' +
        'S_HOT_GALLDOC'
      'left outer join SFIRM on IDFIRM=IDFIRM_HOT_GALLDOC'
      'left outer join SKLIENT on IDKLIENT=IDKL_HOT_GALLDOC'
      'left outer join SUSER on IDUSER_HOT_GALLDOC=ID_USER'
      'left outer join SSKLAD on IDSKLAD=IDSKLAD_HOT_GALLDOC'
      'where ID_HOT_GALLDOC=:ID ')
    AutoUpdateOptions.UpdateTableName = 'HOT_GALLDOC'
    AutoUpdateOptions.KeyFields = 'ID_HOT_GALLDOC'
    AutoUpdateOptions.GeneratorName = 'GEN_HOT_GALLDOC_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 16
    poUseLargeIntField = True
    object DocAllPOS_HOT_GALLDOC: TFIBDateTimeField
      FieldName = 'POS_HOT_GALLDOC'
      OnChange = DocAllPOS_HOT_GALLDOCChange
      DisplayFormat = 'c'
    end
    object DocAllPR_HOT_GALLDOC: TFIBSmallIntField
      FieldName = 'PR_HOT_GALLDOC'
    end
    object DocAllSUM_HOT_GALLDOC: TFIBBCDField
      FieldName = 'SUM_HOT_GALLDOC'
      Size = 2
      RoundByScale = True
    end
    object DocAllTDOC_HOT_GALLDOC: TFIBWideStringField
      FieldName = 'TDOC_HOT_GALLDOC'
      Size = 10
    end
    object DocAllNUMBER_HOT_GALLDOC: TFIBIntegerField
      FieldName = 'NUMBER_HOT_GALLDOC'
    end
    object DocAllNAME_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 100
    end
    object DocAllNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 100
    end
    object DocAllNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 100
    end
    object DocAllFNAME_USER: TFIBWideStringField
      FieldName = 'FNAME_USER'
      Size = 100
    end
    object DocAllNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 100
    end
    object DocAllID_HOT_GALLDOC: TFIBLargeIntField
      FieldName = 'ID_HOT_GALLDOC'
    end
    object DocAllIDFIRM_HOT_GALLDOC: TFIBLargeIntField
      FieldName = 'IDFIRM_HOT_GALLDOC'
    end
    object DocAllIDKL_HOT_GALLDOC: TFIBLargeIntField
      FieldName = 'IDKL_HOT_GALLDOC'
    end
    object DocAllIDUSER_HOT_GALLDOC: TFIBLargeIntField
      FieldName = 'IDUSER_HOT_GALLDOC'
    end
    object DocAllIDDOCOSN_HOT_GALLDOC: TFIBLargeIntField
      FieldName = 'IDDOCOSN_HOT_GALLDOC'
    end
    object DocAllIDSKLAD_HOT_GALLDOC: TFIBLargeIntField
      FieldName = 'IDSKLAD_HOT_GALLDOC'
    end
    object DocAllIDBASE_HOT_GALLDOC: TFIBLargeIntField
      FieldName = 'IDBASE_HOT_GALLDOC'
    end
  end
  object Doc: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE HOT_DREAL'
      'SET '
      '    GID_HOT_DREAL = :GID_HOT_DREAL,'
      '    IDDOCH_HOT_DREAL = :IDDOCH_HOT_DREAL,'
      '    PRIM_HOT_DREAL = :PRIM_HOT_DREAL,'
      '    NAMEKKM_HOT_DREAL = :NAMEKKM_HOT_DREAL,'
      '    ZAVNUM_HOT_DREAL = :ZAVNUM_HOT_DREAL,'
      '    REGNUM_HOT_DREAL = :REGNUM_HOT_DREAL,'
      '    NUMCHECK_HOT_DREAL = :NUMCHECK_HOT_DREAL,'
      '    NUMKL_HOT_DREAL = :NUMKL_HOT_DREAL,'
      '    IDBASE_HOT_DREAL = :IDBASE_HOT_DREAL,'
      '    IDTPRICE_HOT_DREAL = :IDTPRICE_HOT_DREAL'
      'WHERE'
      '    ID_HOT_DREAL = :OLD_ID_HOT_DREAL'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    HOT_DREAL'
      'WHERE'
      '        ID_HOT_DREAL = :OLD_ID_HOT_DREAL'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO HOT_DREAL('
      '    ID_HOT_DREAL,'
      '    GID_HOT_DREAL,'
      '    IDDOCH_HOT_DREAL,'
      '    PRIM_HOT_DREAL,'
      '    NAMEKKM_HOT_DREAL,'
      '    ZAVNUM_HOT_DREAL,'
      '    REGNUM_HOT_DREAL,'
      '    NUMCHECK_HOT_DREAL,'
      '    NUMKL_HOT_DREAL,'
      '    IDBASE_HOT_DREAL,'
      '    IDTPRICE_HOT_DREAL'
      ')'
      'VALUES('
      '    :ID_HOT_DREAL,'
      '    :GID_HOT_DREAL,'
      '    :IDDOCH_HOT_DREAL,'
      '    :PRIM_HOT_DREAL,'
      '    :NAMEKKM_HOT_DREAL,'
      '    :ZAVNUM_HOT_DREAL,'
      '    :REGNUM_HOT_DREAL,'
      '    :NUMCHECK_HOT_DREAL,'
      '    :NUMKL_HOT_DREAL,'
      '    :IDBASE_HOT_DREAL,'
      '    :IDTPRICE_HOT_DREAL'
      ')')
    RefreshSQL.Strings = (
      'select HOT_DREAL.* '
      'from  HOT_DREAL'
      'where(  IDDOCH_HOT_DREAL=:ID'
      '     ) and (     HOT_DREAL.ID_HOT_DREAL = :OLD_ID_HOT_DREAL'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select HOT_DREAL.* '
      'from  HOT_DREAL'
      'where IDDOCH_HOT_DREAL=:ID')
    AutoUpdateOptions.UpdateTableName = 'HOT_DREAL'
    AutoUpdateOptions.KeyFields = 'ID_HOT_DREAL'
    AutoUpdateOptions.GeneratorName = 'GEN_HOT_DREAL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 72
    poUseLargeIntField = True
    object DocPRIM_HOT_DREAL: TFIBWideStringField
      FieldName = 'PRIM_HOT_DREAL'
      Size = 100
    end
    object DocNAMEKKM_HOT_DREAL: TFIBWideStringField
      FieldName = 'NAMEKKM_HOT_DREAL'
    end
    object DocZAVNUM_HOT_DREAL: TFIBWideStringField
      FieldName = 'ZAVNUM_HOT_DREAL'
    end
    object DocREGNUM_HOT_DREAL: TFIBWideStringField
      FieldName = 'REGNUM_HOT_DREAL'
    end
    object DocNUMCHECK_HOT_DREAL: TFIBWideStringField
      FieldName = 'NUMCHECK_HOT_DREAL'
    end
    object DocNUMKL_HOT_DREAL: TFIBWideStringField
      FieldName = 'NUMKL_HOT_DREAL'
    end
    object DocID_HOT_DREAL: TFIBLargeIntField
      FieldName = 'ID_HOT_DREAL'
    end
    object DocIDDOCH_HOT_DREAL: TFIBLargeIntField
      FieldName = 'IDDOCH_HOT_DREAL'
    end
    object DocIDBASE_HOT_DREAL: TFIBLargeIntField
      FieldName = 'IDBASE_HOT_DREAL'
    end
    object DocIDTPRICE_HOT_DREAL: TFIBLargeIntField
      FieldName = 'IDTPRICE_HOT_DREAL'
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE HOT_DREALT'
      'SET '
      '    GID_HOT_DREALT = :GID_HOT_DREALT,'
      '    IDDOCH_HOT_DREALT = :IDDOCH_HOT_DREALT,'
      '    TUSL_HOT_DREALT = :TUSL_HOT_DREALT,'
      '    IDTPRICE_HOT_DREALT = :IDTPRICE_HOT_DREALT,'
      '    IDNOM_HOT_DREALT = :IDNOM_HOT_DREALT,'
      '    IDED_HOT_DREALT = :IDED_HOT_DREALT,'
      '    KOL_HOT_DREALT = :KOL_HOT_DREALT,'
      '    KF_HOT_DREALT = :KF_HOT_DREALT,'
      '    PRICE_HOT_DREALT = :PRICE_HOT_DREALT,'
      '    SUM_HOT_DREALT = :SUM_HOT_DREALT,'
      '    IDNOMER_HOT_DREALT = :IDNOMER_HOT_DREALT,'
      '    IDCAT_HOT_DREALT = :IDCAT_HOT_DREALT,'
      '    IDGUEST_HOT_DREALT = :IDGUEST_HOT_DREALT,'
      '    IDTPOS_HOT_DREALT = :IDTPOS_HOT_DREALT,'
      '    POSNACH_HOT_DREALT = :POSNACH_HOT_DREALT,'
      '    POSCON_HOT_DREALT = :POSCON_HOT_DREALT,'
      '    IDBASE_HOT_DREALT = :IDBASE_HOT_DREALT'
      'WHERE'
      '    ID_HOT_DREALT = :OLD_ID_HOT_DREALT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    HOT_DREALT'
      'WHERE'
      '        ID_HOT_DREALT = :OLD_ID_HOT_DREALT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO HOT_DREALT('
      '    ID_HOT_DREALT,'
      '    GID_HOT_DREALT,'
      '    IDDOCH_HOT_DREALT,'
      '    TUSL_HOT_DREALT,'
      '    IDTPRICE_HOT_DREALT,'
      '    IDNOM_HOT_DREALT,'
      '    IDED_HOT_DREALT,'
      '    KOL_HOT_DREALT,'
      '    KF_HOT_DREALT,'
      '    PRICE_HOT_DREALT,'
      '    SUM_HOT_DREALT,'
      '    IDNOMER_HOT_DREALT,'
      '    IDCAT_HOT_DREALT,'
      '    IDGUEST_HOT_DREALT,'
      '    IDTPOS_HOT_DREALT,'
      '    POSNACH_HOT_DREALT,'
      '    POSCON_HOT_DREALT,'
      '    IDBASE_HOT_DREALT'
      ')'
      'VALUES('
      '    :ID_HOT_DREALT,'
      '    :GID_HOT_DREALT,'
      '    :IDDOCH_HOT_DREALT,'
      '    :TUSL_HOT_DREALT,'
      '    :IDTPRICE_HOT_DREALT,'
      '    :IDNOM_HOT_DREALT,'
      '    :IDED_HOT_DREALT,'
      '    :KOL_HOT_DREALT,'
      '    :KF_HOT_DREALT,'
      '    :PRICE_HOT_DREALT,'
      '    :SUM_HOT_DREALT,'
      '    :IDNOMER_HOT_DREALT,'
      '    :IDCAT_HOT_DREALT,'
      '    :IDGUEST_HOT_DREALT,'
      '    :IDTPOS_HOT_DREALT,'
      '    :POSNACH_HOT_DREALT,'
      '    :POSCON_HOT_DREALT,'
      '    :IDBASE_HOT_DREALT'
      ')')
    RefreshSQL.Strings = (
      'select HOT_DREALT.*, NAMENOM, NAMEED ,TNOM, NAME_TPRICE,'
      '        hot_snf.name_hot_snf,'
      '        hot_scatnom.name_hot_scatnom,'
      '        hot_stypepos.name_hot_stypepos,'
      '        sklient.nameklient'
      'from HOT_DREALT '
      'LEFT OUTER JOIN SNOM  ON IDNOM_HOT_DREALT=IDNOM '
      'left outer join SED  on  IDED_HOT_DREALT=IDED'
      'left outer join STPRICE on ID_TPRICE=IDTPRICE_HOT_DREALT'
      
        'left outer join hot_snf on hot_snf.id_hot_snf=hot_drealt.idnomer' +
        '_hot_drealt'
      
        'left outer join hot_scatnom on hot_scatnom.id_hot_scatnom=hot_dr' +
        'ealt.idcat_hot_drealt'
      
        'left outer join hot_stypepos on hot_stypepos.id_hot_stypepos=hot' +
        '_drealt.idtpos_hot_drealt'
      
        'left outer join sklient on sklient.idklient=hot_drealt.idguest_h' +
        'ot_drealt'
      'where(  IDDOCH_HOT_DREALT=:ID'
      '     ) and (     HOT_DREALT.ID_HOT_DREALT = :OLD_ID_HOT_DREALT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select HOT_DREALT.*, NAMENOM, NAMEED ,TNOM, NAME_TPRICE,'
      '        hot_snf.name_hot_snf,'
      '        hot_scatnom.name_hot_scatnom,'
      '        hot_stypepos.name_hot_stypepos,'
      '        sklient.nameklient'
      'from HOT_DREALT '
      'LEFT OUTER JOIN SNOM  ON IDNOM_HOT_DREALT=IDNOM '
      'left outer join SED  on  IDED_HOT_DREALT=IDED'
      'left outer join STPRICE on ID_TPRICE=IDTPRICE_HOT_DREALT'
      
        'left outer join hot_snf on hot_snf.id_hot_snf=hot_drealt.idnomer' +
        '_hot_drealt'
      
        'left outer join hot_scatnom on hot_scatnom.id_hot_scatnom=hot_dr' +
        'ealt.idcat_hot_drealt'
      
        'left outer join hot_stypepos on hot_stypepos.id_hot_stypepos=hot' +
        '_drealt.idtpos_hot_drealt'
      
        'left outer join sklient on sklient.idklient=hot_drealt.idguest_h' +
        'ot_drealt'
      'where IDDOCH_HOT_DREALT=:ID')
    AutoUpdateOptions.UpdateTableName = 'HOT_DREALT'
    AutoUpdateOptions.KeyFields = 'ID_HOT_DREALT'
    AutoUpdateOptions.GeneratorName = 'GEN_HOT_DREALT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    AfterDelete = DocTAfterDelete
    BeforeDelete = DocTBeforeDelete
    OnCalcFields = DocTCalcFields
    OnNewRecord = DocTNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 128
    poUseLargeIntField = True
    object DocTTUSL_HOT_DREALT: TFIBSmallIntField
      FieldName = 'TUSL_HOT_DREALT'
      OnGetText = DocTTUSL_HOT_DREALTGetText
      OnSetText = DocTTUSL_HOT_DREALTSetText
    end
    object DocTKOL_HOT_DREALT: TFIBBCDField
      FieldName = 'KOL_HOT_DREALT'
      OnChange = DocTKOL_HOT_DREALTChange
      Size = 3
      RoundByScale = True
    end
    object DocTKF_HOT_DREALT: TFIBBCDField
      FieldName = 'KF_HOT_DREALT'
      Size = 3
      RoundByScale = True
    end
    object DocTPRICE_HOT_DREALT: TFIBBCDField
      FieldName = 'PRICE_HOT_DREALT'
      OnChange = DocTPRICE_HOT_DREALTChange
      Size = 2
      RoundByScale = True
    end
    object DocTSUM_HOT_DREALT: TFIBBCDField
      FieldName = 'SUM_HOT_DREALT'
      Size = 2
      RoundByScale = True
    end
    object DocTTNOM: TFIBIntegerField
      FieldName = 'TNOM'
    end
    object DocTRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object DocTPOSNACH_HOT_DREALT: TFIBDateTimeField
      FieldName = 'POSNACH_HOT_DREALT'
      DisplayFormat = 'c'
    end
    object DocTPOSCON_HOT_DREALT: TFIBDateTimeField
      FieldName = 'POSCON_HOT_DREALT'
      DisplayFormat = 'c'
    end
    object DocTNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 100
    end
    object DocTNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
    end
    object DocTNAME_TPRICE: TFIBWideStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
    end
    object DocTNAME_HOT_SNF: TFIBWideStringField
      FieldName = 'NAME_HOT_SNF'
      Size = 100
    end
    object DocTNAME_HOT_SCATNOM: TFIBWideStringField
      FieldName = 'NAME_HOT_SCATNOM'
      Size = 100
    end
    object DocTNAME_HOT_STYPEPOS: TFIBWideStringField
      FieldName = 'NAME_HOT_STYPEPOS'
      Size = 100
    end
    object DocTNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 100
    end
    object DocTID_HOT_DREALT: TFIBLargeIntField
      FieldName = 'ID_HOT_DREALT'
    end
    object DocTIDDOCH_HOT_DREALT: TFIBLargeIntField
      FieldName = 'IDDOCH_HOT_DREALT'
    end
    object DocTIDTPRICE_HOT_DREALT: TFIBLargeIntField
      FieldName = 'IDTPRICE_HOT_DREALT'
    end
    object DocTIDNOM_HOT_DREALT: TFIBLargeIntField
      FieldName = 'IDNOM_HOT_DREALT'
    end
    object DocTIDED_HOT_DREALT: TFIBLargeIntField
      FieldName = 'IDED_HOT_DREALT'
    end
    object DocTIDNOMER_HOT_DREALT: TFIBLargeIntField
      FieldName = 'IDNOMER_HOT_DREALT'
    end
    object DocTIDCAT_HOT_DREALT: TFIBLargeIntField
      FieldName = 'IDCAT_HOT_DREALT'
    end
    object DocTIDGUEST_HOT_DREALT: TFIBLargeIntField
      FieldName = 'IDGUEST_HOT_DREALT'
    end
    object DocTIDTPOS_HOT_DREALT: TFIBLargeIntField
      FieldName = 'IDTPOS_HOT_DREALT'
    end
    object DocTIDBASE_HOT_DREALT: TFIBLargeIntField
      FieldName = 'IDBASE_HOT_DREALT'
    end
  end
  object IBTrDvReg: TpFIBTransaction
    TimeoutAction = TARollback
    Left = 384
    Top = 80
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 256
    Top = 184
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE HOT_DOC_REAL_DVREG (:PARAM_IDDOCH,0,0,0)')
    Left = 320
    Top = 72
    qoStartTransaction = True
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE HOT_DOC_REAL_CANCEL_DVREG(:PARAM_IDDOCH,0,0,0)')
    Left = 320
    Top = 120
    qoStartTransaction = True
  end
  object TypePriceDataSet: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from STPRICE')
    Transaction = IBTr
    DefaultFormats.DateTimeDisplayFormat = 'dd.mm.yyyy hh:mm '
    DefaultFormats.DisplayFormatTime = 'hh:mm'
    Left = 152
    Top = 192
  end
  object SpisokGuestOsnUslug: TpFIBDataSet
    SelectSQL.Strings = (
      
        'select sklient.idklient, sklient.nameklient, sum(hot_drealt.kol_' +
        'hot_drealt * hot_drealt.kf_hot_drealt)  as SUMKOL'
      'from hot_drealt'
      
        'left outer join sklient on hot_drealt.idguest_hot_drealt=sklient' +
        '.idklient'
      'where hot_drealt.iddoch_hot_drealt=:PARAM_IDDOCH and'
      'hot_drealt.tusl_hot_drealt=1'
      'group by sklient.idklient, sklient.nameklient')
    Transaction = IBTr
    DefaultFormats.DateTimeDisplayFormat = 'dd.mm.yyyy hh:mm '
    DefaultFormats.DisplayFormatTime = 'hh:mm'
    Left = 352
    Top = 160
    object SpisokGuestOsnUslugSUMKOL: TFIBFloatField
      FieldName = 'SUMKOL'
    end
    object SpisokGuestOsnUslugIDKLIENT: TFIBBCDField
      FieldName = 'IDKLIENT'
      Size = 0
      RoundByScale = True
    end
    object SpisokGuestOsnUslugNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 100
    end
  end
  object SpisokGuestDopUslug: TpFIBDataSet
    SelectSQL.Strings = (
      
        'select sklient.idklient, sklient.nameklient, sum(hot_drealt.sum_' +
        'hot_drealt)'
      'from hot_drealt'
      
        'left outer join sklient on hot_drealt.idguest_hot_drealt=sklient' +
        '.idklient'
      'where hot_drealt.iddoch_hot_drealt=:PARAM_IDDOCH and'
      '(hot_drealt.tusl_hot_drealt=3 or hot_drealt.tusl_hot_drealt=4)'
      'group by sklient.idklient, sklient.nameklient')
    Transaction = IBTr
    DefaultFormats.DateTimeDisplayFormat = 'dd.mm.yyyy hh:mm '
    DefaultFormats.DisplayFormatTime = 'hh:mm'
    Left = 352
    Top = 208
    object SpisokGuestDopUslugSUM: TFIBBCDField
      FieldName = 'SUM'
      Size = 2
      RoundByScale = True
    end
    object SpisokGuestDopUslugIDKLIENT: TFIBBCDField
      FieldName = 'IDKLIENT'
      Size = 0
      RoundByScale = True
    end
    object SpisokGuestDopUslugNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 100
    end
  end
  object NumDoc: TpFIBDataSet
    SelectSQL.Strings = (
      'select max(NUMBER_HOT_GALLDOC) AS MAXNUMBER '
      'from  HOT_GALLDOC'
      'where TDOC_HOT_GALLDOC='#39'REAL'#39
      ' and POS_HOT_GALLDOC>:PARAM_POS')
    Transaction = IBTr
    Left = 328
    Top = 16
    object NumDocMAXNUMBER: TFIBIntegerField
      FieldName = 'MAXNUMBER'
    end
  end
end
