object HOT_DMDocRaschet: THOT_DMDocRaschet
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 265
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
      'UPDATE HOT_DRASCHET'
      'SET '
      '    GID_HOT_DRASCHET = :GID_HOT_DRASCHET,'
      '    IDDOCH_HOT_DRASCHET = :IDDOCH_HOT_DRASCHET,'
      '    PRIM_HOT_DRASCHET = :PRIM_HOT_DRASCHET,'
      '    IDBSCHET_HOT_DRASCHET = :IDBSCHET_HOT_DRASCHET,'
      '    IDBASE_HOT_DRASCHET = :IDBASE_HOT_DRASCHET,'
      '    IDTPRICE_HOT_DRASCHET = :IDTPRICE_HOT_DRASCHET'
      'WHERE'
      '    ID_HOT_DRASCHET = :OLD_ID_HOT_DRASCHET'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    HOT_DRASCHET'
      'WHERE'
      '        ID_HOT_DRASCHET = :OLD_ID_HOT_DRASCHET'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO HOT_DRASCHET('
      '    ID_HOT_DRASCHET,'
      '    GID_HOT_DRASCHET,'
      '    IDDOCH_HOT_DRASCHET,'
      '    PRIM_HOT_DRASCHET,'
      '    IDBSCHET_HOT_DRASCHET,'
      '    IDBASE_HOT_DRASCHET,'
      '    IDTPRICE_HOT_DRASCHET'
      ')'
      'VALUES('
      '    :ID_HOT_DRASCHET,'
      '    :GID_HOT_DRASCHET,'
      '    :IDDOCH_HOT_DRASCHET,'
      '    :PRIM_HOT_DRASCHET,'
      '    :IDBSCHET_HOT_DRASCHET,'
      '    :IDBASE_HOT_DRASCHET,'
      '    :IDTPRICE_HOT_DRASCHET'
      ')')
    RefreshSQL.Strings = (
      'select HOT_DRASCHET.*, NAMEBSCHET '
      'from  HOT_DRASCHET'
      'left outer join SBSCHET on IDBSCHET_HOT_DRASCHET=IDBSCHET'
      'where(  IDDOCH_HOT_DRASCHET=:ID'
      
        '     ) and (     HOT_DRASCHET.ID_HOT_DRASCHET = :OLD_ID_HOT_DRAS' +
        'CHET'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select HOT_DRASCHET.*, NAMEBSCHET '
      'from  HOT_DRASCHET'
      'left outer join SBSCHET on IDBSCHET_HOT_DRASCHET=IDBSCHET'
      'where IDDOCH_HOT_DRASCHET=:ID')
    AutoUpdateOptions.UpdateTableName = 'HOT_DRASCHET'
    AutoUpdateOptions.KeyFields = 'ID_HOT_DRASCHET'
    AutoUpdateOptions.GeneratorName = 'GEN_HOT_DRASCHET_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 72
    poUseLargeIntField = True
    object DocPRIM_HOT_DRASCHET: TFIBWideStringField
      FieldName = 'PRIM_HOT_DRASCHET'
      Size = 100
    end
    object DocNAMEBSCHET: TFIBWideStringField
      FieldName = 'NAMEBSCHET'
      Size = 100
    end
    object DocID_HOT_DRASCHET: TFIBLargeIntField
      FieldName = 'ID_HOT_DRASCHET'
    end
    object DocIDDOCH_HOT_DRASCHET: TFIBLargeIntField
      FieldName = 'IDDOCH_HOT_DRASCHET'
    end
    object DocIDBSCHET_HOT_DRASCHET: TFIBLargeIntField
      FieldName = 'IDBSCHET_HOT_DRASCHET'
    end
    object DocIDBASE_HOT_DRASCHET: TFIBLargeIntField
      FieldName = 'IDBASE_HOT_DRASCHET'
    end
    object DocIDTPRICE_HOT_DRASCHET: TFIBLargeIntField
      FieldName = 'IDTPRICE_HOT_DRASCHET'
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE HOT_DRASCHETT'
      'SET '
      '    GID_HOT_DRASCHETT = :GID_HOT_DRASCHETT,'
      '    IDDOCH_HOT_DRASCHETT = :IDDOCH_HOT_DRASCHETT,'
      '    TUSL_HOT_DRASCHETT = :TUSL_HOT_DRASCHETT,'
      '    IDTPRICE_HOT_DRASCHETT = :IDTPRICE_HOT_DRASCHETT,'
      '    IDNOM_HOT_DRASCHETT = :IDNOM_HOT_DRASCHETT,'
      '    IDED_HOT_DRASCHETT = :IDED_HOT_DRASCHETT,'
      '    KOL_HOT_DRASCHETT = :KOL_HOT_DRASCHETT,'
      '    KF_HOT_DRASCHETT = :KF_HOT_DRASCHETT,'
      '    PRICE_HOT_DRASCHETT = :PRICE_HOT_DRASCHETT,'
      '    SUM_HOT_DRASCHETT = :SUM_HOT_DRASCHETT,'
      '    IDNOMER_HOT_DRASCHETT = :IDNOMER_HOT_DRASCHETT,'
      '    IDCAT_HOT_DRASCHETT = :IDCAT_HOT_DRASCHETT,'
      '    IDGUEST_HOT_DRASCHETT = :IDGUEST_HOT_DRASCHETT,'
      '    IDTPOS_HOT_DRASCHETT = :IDTPOS_HOT_DRASCHETT,'
      '    POSNACH_HOT_DRASCHETT = :POSNACH_HOT_DRASCHETT,'
      '    POSCON_HOT_DRASCHETT = :POSCON_HOT_DRASCHETT,'
      '    IDBASE_HOT_DRASCHETT = :IDBASE_HOT_DRASCHETT'
      'WHERE'
      '    ID_HOT_DRASCHETT = :OLD_ID_HOT_DRASCHETT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    HOT_DRASCHETT'
      'WHERE'
      '        ID_HOT_DRASCHETT = :OLD_ID_HOT_DRASCHETT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO HOT_DRASCHETT('
      '    ID_HOT_DRASCHETT,'
      '    GID_HOT_DRASCHETT,'
      '    IDDOCH_HOT_DRASCHETT,'
      '    TUSL_HOT_DRASCHETT,'
      '    IDTPRICE_HOT_DRASCHETT,'
      '    IDNOM_HOT_DRASCHETT,'
      '    IDED_HOT_DRASCHETT,'
      '    KOL_HOT_DRASCHETT,'
      '    KF_HOT_DRASCHETT,'
      '    PRICE_HOT_DRASCHETT,'
      '    SUM_HOT_DRASCHETT,'
      '    IDNOMER_HOT_DRASCHETT,'
      '    IDCAT_HOT_DRASCHETT,'
      '    IDGUEST_HOT_DRASCHETT,'
      '    IDTPOS_HOT_DRASCHETT,'
      '    POSNACH_HOT_DRASCHETT,'
      '    POSCON_HOT_DRASCHETT,'
      '    IDBASE_HOT_DRASCHETT'
      ')'
      'VALUES('
      '    :ID_HOT_DRASCHETT,'
      '    :GID_HOT_DRASCHETT,'
      '    :IDDOCH_HOT_DRASCHETT,'
      '    :TUSL_HOT_DRASCHETT,'
      '    :IDTPRICE_HOT_DRASCHETT,'
      '    :IDNOM_HOT_DRASCHETT,'
      '    :IDED_HOT_DRASCHETT,'
      '    :KOL_HOT_DRASCHETT,'
      '    :KF_HOT_DRASCHETT,'
      '    :PRICE_HOT_DRASCHETT,'
      '    :SUM_HOT_DRASCHETT,'
      '    :IDNOMER_HOT_DRASCHETT,'
      '    :IDCAT_HOT_DRASCHETT,'
      '    :IDGUEST_HOT_DRASCHETT,'
      '    :IDTPOS_HOT_DRASCHETT,'
      '    :POSNACH_HOT_DRASCHETT,'
      '    :POSCON_HOT_DRASCHETT,'
      '    :IDBASE_HOT_DRASCHETT'
      ')')
    RefreshSQL.Strings = (
      'select HOT_DRASCHETT.*, NAMENOM, NAMEED ,TNOM, NAME_TPRICE,'
      '        hot_snf.name_hot_snf,'
      '        hot_scatnom.name_hot_scatnom,'
      '        hot_stypepos.name_hot_stypepos,'
      '        sklient.nameklient'
      'from HOT_DRASCHETT '
      'LEFT OUTER JOIN SNOM  ON IDNOM_HOT_DRASCHETT=IDNOM '
      'left outer join SED  on  IDED_HOT_DRASCHETT=IDED'
      'left outer join STPRICE on ID_TPRICE=IDTPRICE_HOT_DRASCHETT'
      
        'left outer join hot_snf on hot_snf.id_hot_snf=hot_draschett.idno' +
        'mer_hot_draschett'
      
        'left outer join hot_scatnom on hot_scatnom.id_hot_scatnom=hot_dr' +
        'aschett.idcat_hot_draschett'
      
        'left outer join hot_stypepos on hot_stypepos.id_hot_stypepos=hot' +
        '_draschett.idtpos_hot_draschett'
      
        'left outer join sklient on sklient.idklient=hot_draschett.idgues' +
        't_hot_draschett'
      'where(  IDDOCH_HOT_DRASCHETT=:PARAM_IDDOCH'
      
        '     ) and (     HOT_DRASCHETT.ID_HOT_DRASCHETT = :OLD_ID_HOT_DR' +
        'ASCHETT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select HOT_DRASCHETT.*, NAMENOM, NAMEED ,TNOM, NAME_TPRICE,'
      '        hot_snf.name_hot_snf,'
      '        hot_scatnom.name_hot_scatnom,'
      '        hot_stypepos.name_hot_stypepos,'
      '        sklient.nameklient'
      'from HOT_DRASCHETT '
      'LEFT OUTER JOIN SNOM  ON IDNOM_HOT_DRASCHETT=IDNOM '
      'left outer join SED  on  IDED_HOT_DRASCHETT=IDED'
      'left outer join STPRICE on ID_TPRICE=IDTPRICE_HOT_DRASCHETT'
      
        'left outer join hot_snf on hot_snf.id_hot_snf=hot_draschett.idno' +
        'mer_hot_draschett'
      
        'left outer join hot_scatnom on hot_scatnom.id_hot_scatnom=hot_dr' +
        'aschett.idcat_hot_draschett'
      
        'left outer join hot_stypepos on hot_stypepos.id_hot_stypepos=hot' +
        '_draschett.idtpos_hot_draschett'
      
        'left outer join sklient on sklient.idklient=hot_draschett.idgues' +
        't_hot_draschett'
      'where IDDOCH_HOT_DRASCHETT=:PARAM_IDDOCH')
    AutoUpdateOptions.UpdateTableName = 'HOT_DRASCHETT'
    AutoUpdateOptions.KeyFields = 'ID_DRASCHETT'
    AutoUpdateOptions.GeneratorName = 'GEN_HOT_DRASCHETT_ID'
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
    object DocTTUSL_HOT_DRASCHETT: TFIBSmallIntField
      FieldName = 'TUSL_HOT_DRASCHETT'
      OnGetText = DocTTUSL_HOT_DRASCHETTGetText
      OnSetText = DocTTUSL_HOT_DRASCHETTSetText
    end
    object DocTKOL_HOT_DRASCHETT: TFIBBCDField
      FieldName = 'KOL_HOT_DRASCHETT'
      OnChange = DocTKOL_HOT_DRASCHETTChange
      Size = 3
      RoundByScale = True
    end
    object DocTKF_HOT_DRASCHETT: TFIBBCDField
      FieldName = 'KF_HOT_DRASCHETT'
      Size = 3
      RoundByScale = True
    end
    object DocTPRICE_HOT_DRASCHETT: TFIBBCDField
      FieldName = 'PRICE_HOT_DRASCHETT'
      OnChange = DocTPRICE_HOT_DRASCHETTChange
      Size = 2
      RoundByScale = True
    end
    object DocTRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object DocTSUM_HOT_DRASCHETT: TFIBBCDField
      FieldName = 'SUM_HOT_DRASCHETT'
      Size = 2
      RoundByScale = True
    end
    object DocTPOSNACH_HOT_DRASCHETT: TFIBDateTimeField
      FieldName = 'POSNACH_HOT_DRASCHETT'
      DisplayFormat = 'c'
    end
    object DocTPOSCON_HOT_DRASCHETT: TFIBDateTimeField
      FieldName = 'POSCON_HOT_DRASCHETT'
      DisplayFormat = 'c'
    end
    object DocTVIBOR_TYPE_PRICE: TStringField
      FieldKind = fkLookup
      FieldName = 'VIBOR_TYPE_PRICE'
      LookupDataSet = TypePriceDataSet
      LookupKeyFields = 'ID_TPRICE'
      LookupResultField = 'NAME_TPRICE'
      KeyFields = 'IDTPRICE_HOT_DRASCHETT'
      Lookup = True
    end
    object DocTNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 100
    end
    object DocTNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
    end
    object DocTTNOM: TFIBSmallIntField
      FieldName = 'TNOM'
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
    object DocTID_HOT_DRASCHETT: TFIBLargeIntField
      FieldName = 'ID_HOT_DRASCHETT'
    end
    object DocTIDDOCH_HOT_DRASCHETT: TFIBLargeIntField
      FieldName = 'IDDOCH_HOT_DRASCHETT'
    end
    object DocTIDTPRICE_HOT_DRASCHETT: TFIBLargeIntField
      FieldName = 'IDTPRICE_HOT_DRASCHETT'
    end
    object DocTIDNOM_HOT_DRASCHETT: TFIBLargeIntField
      FieldName = 'IDNOM_HOT_DRASCHETT'
    end
    object DocTIDED_HOT_DRASCHETT: TFIBLargeIntField
      FieldName = 'IDED_HOT_DRASCHETT'
    end
    object DocTIDNOMER_HOT_DRASCHETT: TFIBLargeIntField
      FieldName = 'IDNOMER_HOT_DRASCHETT'
    end
    object DocTIDCAT_HOT_DRASCHETT: TFIBLargeIntField
      FieldName = 'IDCAT_HOT_DRASCHETT'
    end
    object DocTIDGUEST_HOT_DRASCHETT: TFIBLargeIntField
      FieldName = 'IDGUEST_HOT_DRASCHETT'
    end
    object DocTIDTPOS_HOT_DRASCHETT: TFIBLargeIntField
      FieldName = 'IDTPOS_HOT_DRASCHETT'
    end
    object DocTIDBASE_HOT_DRASCHETT: TFIBLargeIntField
      FieldName = 'IDBASE_HOT_DRASCHETT'
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
    Top = 208
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE HOT_DOC_RASCHET_DVREG (:PARAM_IDDOCH,0,0,0)')
    Left = 320
    Top = 72
    qoStartTransaction = True
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      
        'EXECUTE PROCEDURE HOT_DOC_RASCHET_CANCEL_DVREG(:PARAM_IDDOCH,0,0' +
        ',0)')
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
      
        'select sklient.idklient, sklient.nameklient, sum(hot_draschett.k' +
        'ol_hot_draschett * hot_draschett.kf_hot_draschett)  as SUMKOL'
      'from hot_draschett'
      
        'left outer join sklient on hot_draschett.idguest_hot_draschett=s' +
        'klient.idklient'
      'where hot_draschett.iddoch_hot_draschett=:PARAM_IDDOCH and'
      'hot_draschett.tusl_hot_draschett=1'
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
      
        'select sklient.idklient, sklient.nameklient, sum(hot_draschett.s' +
        'um_hot_draschett)'
      'from hot_draschett'
      
        'left outer join sklient on hot_draschett.idguest_hot_draschett=s' +
        'klient.idklient'
      'where hot_draschett.iddoch_hot_draschett=:PARAM_IDDOCH and'
      
        '(hot_draschett.tusl_hot_draschett=3 or hot_draschett.tusl_hot_dr' +
        'aschett=4)'
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
      'where TDOC_HOT_GALLDOC='#39'RASCHET'#39
      ' and POS_HOT_GALLDOC>:PARAM_POS')
    Transaction = IBTr
    Left = 328
    Top = 16
    object NumDocMAXNUMBER: TFIBIntegerField
      FieldName = 'MAXNUMBER'
    end
  end
end
