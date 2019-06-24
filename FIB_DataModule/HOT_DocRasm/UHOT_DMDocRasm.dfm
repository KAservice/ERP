object HOT_DMDocRasm: THOT_DMDocRasm
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 215
  Width = 539
  object DataSourceDoc: TDataSource
    DataSet = Doc
    Left = 72
    Top = 72
  end
  object DataSourceDocAll: TDataSource
    DataSet = DocAll
    Left = 72
    Top = 16
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
      
        'select HOT_GALLDOC.*, FNAME_USER , NAME_SINFBASE_OBMEN, NAMEFIRM' +
        ', NAMEKLIENT'
      'from HOT_GALLDOC'
      'left outer join SUSER on IDUSER_HOT_GALLDOC=ID_USER'
      
        'left outer join SINFBASE_OBMEN on PREFIKS_SINFBASE_OBMEN=PREFIKS' +
        '_HOT_GALLDOC'
      'left outer join SFIRM on IDFIRM_HOT_GALLDOC=IDFIRM'
      'left outer join SKLIENT on IDKL_HOT_GALLDOC=IDKLIENT'
      'where(  ID_HOT_GALLDOC=:PARAM_ID'
      
        '     ) and (     HOT_GALLDOC.ID_HOT_GALLDOC = :OLD_ID_HOT_GALLDO' +
        'C'
      '     )'
      '     ')
    SelectSQL.Strings = (
      
        'select HOT_GALLDOC.*, FNAME_USER , NAME_SINFBASE_OBMEN, NAMEFIRM' +
        ', NAMEKLIENT'
      'from HOT_GALLDOC'
      'left outer join SUSER on IDUSER_HOT_GALLDOC=ID_USER'
      
        'left outer join SINFBASE_OBMEN on PREFIKS_SINFBASE_OBMEN=PREFIKS' +
        '_HOT_GALLDOC'
      'left outer join SFIRM on IDFIRM_HOT_GALLDOC=IDFIRM'
      'left outer join SKLIENT on IDKL_HOT_GALLDOC=IDKLIENT'
      'where ID_HOT_GALLDOC=:PARAM_ID ')
    AutoUpdateOptions.UpdateTableName = 'HOT_GALLDOC'
    AutoUpdateOptions.KeyFields = 'ID_HOT_GALLDOC'
    AutoUpdateOptions.GeneratorName = 'GEN_HOT_GALLDOC_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 16
    poUseLargeIntField = True
    object DocAllPOS_HOT_GALLDOC: TFIBDateTimeField
      FieldName = 'POS_HOT_GALLDOC'
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
    object DocAllNUMBER_HOT_GALLDOC: TFIBIntegerField
      FieldName = 'NUMBER_HOT_GALLDOC'
    end
    object DocAllTDOC_HOT_GALLDOC: TFIBWideStringField
      FieldName = 'TDOC_HOT_GALLDOC'
      Size = 10
    end
    object DocAllFNAME_USER: TFIBWideStringField
      FieldName = 'FNAME_USER'
      Size = 100
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
    object DocAllIDBASE_HOT_GALLDOC: TFIBLargeIntField
      FieldName = 'IDBASE_HOT_GALLDOC'
    end
  end
  object Doc: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE HOT_DRASM'
      'SET '
      '    GID_HOT_DRASM = :GID_HOT_DRASM,'
      '    IDDOCH_HOT_DRASM = :IDDOCH_HOT_DRASM,'
      '    DESCR_HOT_DRASM = :DESCR_HOT_DRASM,'
      '    IDCELPR_HOT_DRASM = :IDCELPR_HOT_DRASM,'
      '    ORG_HOT_DRASM = :ORG_HOT_DRASM,'
      '    IDBASE_HOT_DRASM = :IDBASE_HOT_DRASM,'
      '    IDTPRICE_HOT_DRASM = :IDTPRICE_HOT_DRASM'
      'WHERE'
      '    ID_HOT_DRASM = :OLD_ID_HOT_DRASM'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    HOT_DRASM'
      'WHERE'
      '        ID_HOT_DRASM = :OLD_ID_HOT_DRASM'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO HOT_DRASM('
      '    ID_HOT_DRASM,'
      '    GID_HOT_DRASM,'
      '    IDDOCH_HOT_DRASM,'
      '    DESCR_HOT_DRASM,'
      '    IDCELPR_HOT_DRASM,'
      '    ORG_HOT_DRASM,'
      '    IDBASE_HOT_DRASM,'
      '    IDTPRICE_HOT_DRASM'
      ')'
      'VALUES('
      '    :ID_HOT_DRASM,'
      '    :GID_HOT_DRASM,'
      '    :IDDOCH_HOT_DRASM,'
      '    :DESCR_HOT_DRASM,'
      '    :IDCELPR_HOT_DRASM,'
      '    :ORG_HOT_DRASM,'
      '    :IDBASE_HOT_DRASM,'
      '    :IDTPRICE_HOT_DRASM'
      ')')
    RefreshSQL.Strings = (
      'select HOT_DRASM.*, NAME_HOT_SCELPR '
      'from  HOT_DRASM'
      'left outer join HOT_SCELPR on ID_HOT_SCELPR=IDCELPR_HOT_DRASM'
      'where(  IDDOCH_HOT_DRASM=:PARAM_IDDOC'
      '     ) and (     HOT_DRASM.ID_HOT_DRASM = :OLD_ID_HOT_DRASM'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select HOT_DRASM.*, NAME_HOT_SCELPR '
      'from  HOT_DRASM'
      'left outer join HOT_SCELPR on ID_HOT_SCELPR=IDCELPR_HOT_DRASM'
      'where IDDOCH_HOT_DRASM=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'HOT_DRASM'
    AutoUpdateOptions.KeyFields = 'ID_HOT_DRASM'
    AutoUpdateOptions.GeneratorName = 'GEN_HOT_DRASM_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 72
    poUseLargeIntField = True
    object DocDESCR_HOT_DRASM: TFIBWideStringField
      FieldName = 'DESCR_HOT_DRASM'
      Size = 100
    end
    object DocORG_HOT_DRASM: TFIBWideStringField
      FieldName = 'ORG_HOT_DRASM'
      Size = 30
    end
    object DocNAME_HOT_SCELPR: TFIBWideStringField
      FieldName = 'NAME_HOT_SCELPR'
      Size = 100
    end
    object DocID_HOT_DRASM: TFIBLargeIntField
      FieldName = 'ID_HOT_DRASM'
    end
    object DocIDDOCH_HOT_DRASM: TFIBLargeIntField
      FieldName = 'IDDOCH_HOT_DRASM'
    end
    object DocIDCELPR_HOT_DRASM: TFIBLargeIntField
      FieldName = 'IDCELPR_HOT_DRASM'
    end
    object DocIDBASE_HOT_DRASM: TFIBLargeIntField
      FieldName = 'IDBASE_HOT_DRASM'
    end
    object DocIDTPRICE_HOT_DRASM: TFIBLargeIntField
      FieldName = 'IDTPRICE_HOT_DRASM'
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
    Left = 256
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
    Left = 256
    Top = 72
  end
  object IBTrDvReg: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 424
    Top = 88
  end
  object NumDoc: TpFIBDataSet
    SelectSQL.Strings = (
      'select max(NUMBER_HOT_GALLDOC) AS MAXNUMBER '
      'from  HOT_GALLDOC'
      'where TDOC_HOT_GALLDOC='#39'RASM'#39
      ' and POS_HOT_GALLDOC>:PARAM_POS')
    Transaction = IBTr
    Left = 328
    Top = 16
    object NumDocMAXNUMBER: TFIBIntegerField
      FieldName = 'MAXNUMBER'
    end
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE HOT_DOC_RASM_DVREG (:PARAM_IDDOCH,0,0,0)')
    Left = 368
    Top = 88
    qoStartTransaction = True
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE HOT_DOC_RASM_CANCEL_DVREG(:PARAM_IDDOCH,0,0,0)')
    Left = 368
    Top = 136
    qoStartTransaction = True
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE HOT_DRASMT'
      'SET '
      '    GID_HOT_DRASMT = :GID_HOT_DRASMT,'
      '    IDDOCH_HOT_DRASMT = :IDDOCH_HOT_DRASMT,'
      '    IDSOSTBR_HOT_DRASMT = :IDSOSTBR_HOT_DRASMT,'
      '    IDSOSTRASM_HOT_DRASMT = :IDSOSTRASM_HOT_DRASMT,'
      '    IDSOSTBR2_HOT_DRASMT = :IDSOSTBR2_HOT_DRASMT,'
      '    IDBASE_HOT_DRASMT = :IDBASE_HOT_DRASMT'
      'WHERE'
      '    ID_HOT_DRASMT = :OLD_ID_HOT_DRASMT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    HOT_DRASMT'
      'WHERE'
      '        ID_HOT_DRASMT = :OLD_ID_HOT_DRASMT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO HOT_DRASMT('
      '    ID_HOT_DRASMT,'
      '    GID_HOT_DRASMT,'
      '    IDDOCH_HOT_DRASMT,'
      '    IDSOSTBR_HOT_DRASMT,'
      '    IDSOSTRASM_HOT_DRASMT,'
      '    IDSOSTBR2_HOT_DRASMT,'
      '    IDBASE_HOT_DRASMT'
      ')'
      'VALUES('
      '    :ID_HOT_DRASMT,'
      '    :GID_HOT_DRASMT,'
      '    :IDDOCH_HOT_DRASMT,'
      '    :IDSOSTBR_HOT_DRASMT,'
      '    :IDSOSTRASM_HOT_DRASMT,'
      '    :IDSOSTBR2_HOT_DRASMT,'
      '    :IDBASE_HOT_DRASMT'
      ')')
    RefreshSQL.Strings = (
      'select HOT_DRASMT.*,'
      '        BRNF.name_hot_snf as BR_NAME_HOT_SNF,'
      '        BRCAT.name_hot_scatnom as BR_NAME_HOT_SCATNOM,'
      '        BRTPOS.name_hot_stypepos as BR_NAME_HOT_STYPEPOS,'
      '        BRGUEST.nameklient as BR_NAMEGUEST,'
      '        BRSOST.name_hot_ssostnom as BR_NAME_HOT_SSOSTNOM,'
      '        BR.posnach_hot_sostnf as BR_posnach_hot_sostnf,'
      '        BR.poscon_hot_sostnf as BR_poscon_hot_sostnf,'
      '        BR.kolm_hot_sostnf as BR_kolm_hot_sostnf,'
      ''
      '        RASMNF.name_hot_snf as RASM_NAME_HOT_SNF,'
      '        RASMNF.id_hot_snf as RASM_ID_HOT_SNF,'
      '        RASMCAT.name_hot_scatnom as RASM_NAME_HOT_SCATNOM,'
      '        RASMCAT.id_hot_scatnom as RASM_ID_HOT_SCATNOM,'
      '        RASMTPOS.name_hot_stypepos as RASM_NAME_HOT_STYPEPOS,'
      '        RASMTPOS.id_hot_stypepos as RASM_ID_HOT_STYPEPOS,'
      '        RASMGUEST.nameklient as RASM_NAMEGUEST,'
      '        RASMGUEST.idklient as RASM_IDGUEST,'
      '        RASMSOST.name_hot_ssostnom as RASM_NAME_HOT_SSOSTNOM,'
      '        RASMSOST.id_hot_ssostnom as RASM_ID_HOT_SSOSTNOM,'
      '        RASM.posnach_hot_sostnf as RASM_posnach_hot_sostnf,'
      '        RASM.poscon_hot_sostnf as RASM_poscon_hot_sostnf,'
      '        RASM.kolm_hot_sostnf as RASM_kolm_hot_sostnf,'
      ''
      '        BR2NF.name_hot_snf as BR2_NAME_HOT_SNF,'
      '        BR2NF.id_hot_snf as BR2_ID_HOT_SNF,'
      '        BR2CAT.name_hot_scatnom as BR2_NAME_HOT_SCATNOM,'
      '        BR2CAT.id_hot_scatnom as BR2_ID_HOT_SCATNOM,'
      '        BR2TPOS.name_hot_stypepos as BR2_NAME_HOT_STYPEPOS,'
      '        BR2TPOS.id_hot_stypepos as BR2_ID_HOT_STYPEPOS,'
      '        BR2GUEST.nameklient as BR2_NAMEGUEST,'
      '        BR2GUEST.idklient as BR2_IDGUEST,'
      '        BR2SOST.name_hot_ssostnom as BR2_NAME_HOT_SSOSTNOM,'
      '        BR2SOST.id_hot_ssostnom as BR2_ID_HOT_SSOSTNOM,'
      '        BR2.posnach_hot_sostnf as BR2_posnach_hot_sostnf,'
      '        BR2.poscon_hot_sostnf as BR2_poscon_hot_sostnf,'
      '        BR2.kolm_hot_sostnf as BR2_kolm_hot_sostnf'
      ''
      'from HOT_DRASMT'
      
        'left outer join hot_sostnf as BR  on hot_drasmt.idsostbr_hot_dra' +
        'smt=BR.id_hot_sostnf'
      
        'left outer join hot_snf  as BRNF on BRNF.id_hot_snf=BR.idnomer_h' +
        'ot_sostnf'
      
        'left outer join hot_scatnom as BRCAT on BRCAT.id_hot_scatnom=BR.' +
        'idcat_hot_sostnf'
      
        'left outer join hot_stypepos as BRTPOS on BRTPOS.id_hot_stypepos' +
        '=BR.idtpos_hot_sostnf'
      
        'left outer join sklient as BRGUEST on BRGUEST.idklient=BR.idgues' +
        't_hot_sostnf'
      
        'left outer join hot_ssostnom as BRSOST on BRSOST.id_hot_ssostnom' +
        '=BR.idsost_hot_sostnf'
      ''
      
        'left outer join hot_sostnf as RASM  on hot_drasmt.idsostrasm_hot' +
        '_drasmt=RASM.id_hot_sostnf'
      
        'left outer join hot_snf  as RASMNF on RASMNF.id_hot_snf=RASM.idn' +
        'omer_hot_sostnf'
      
        'left outer join hot_scatnom as RASMCAT on RASMCAT.id_hot_scatnom' +
        '=RASM.idcat_hot_sostnf'
      
        'left outer join hot_stypepos as RASMTPOS on RASMTPOS.id_hot_styp' +
        'epos=RASM.idtpos_hot_sostnf'
      
        'left outer join sklient as RASMGUEST on RASMGUEST.idklient=RASM.' +
        'idguest_hot_sostnf'
      
        'left outer join hot_ssostnom as RASMSOST on RASMSOST.id_hot_ssos' +
        'tnom=RASM.idsost_hot_sostnf'
      ''
      
        'left outer join hot_sostnf as BR2  on hot_drasmt.idsostbr2_hot_d' +
        'rasmt=BR2.id_hot_sostnf'
      
        'left outer join hot_snf  as BR2NF on BR2NF.id_hot_snf=BR2.idnome' +
        'r_hot_sostnf'
      
        'left outer join hot_scatnom as BR2CAT on BR2CAT.id_hot_scatnom=B' +
        'R2.idcat_hot_sostnf'
      
        'left outer join hot_stypepos as BR2TPOS on BR2TPOS.id_hot_stypep' +
        'os=BR2.idtpos_hot_sostnf'
      
        'left outer join sklient as BR2GUEST on BR2GUEST.idklient=BR2.idg' +
        'uest_hot_sostnf'
      
        'left outer join hot_ssostnom as BR2SOST on BR2SOST.id_hot_ssostn' +
        'om=BR2.idsost_hot_sostnf'
      ''
      'where(  IDDOCH_HOT_DRASMT=:PARAM_IDDOCH'
      '     ) and (     HOT_DRASMT.ID_HOT_DRASMT = :OLD_ID_HOT_DRASMT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select HOT_DRASMT.*,'
      '        BRNF.name_hot_snf as BR_NAME_HOT_SNF,'
      '        BRCAT.name_hot_scatnom as BR_NAME_HOT_SCATNOM,'
      '        BRTPOS.name_hot_stypepos as BR_NAME_HOT_STYPEPOS,'
      '        BRGUEST.nameklient as BR_NAMEGUEST,'
      '        BRSOST.name_hot_ssostnom as BR_NAME_HOT_SSOSTNOM,'
      '        BR.posnach_hot_sostnf as BR_posnach_hot_sostnf,'
      '        BR.poscon_hot_sostnf as BR_poscon_hot_sostnf,'
      '        BR.kolm_hot_sostnf as BR_kolm_hot_sostnf,'
      ''
      '        RASMNF.name_hot_snf as RASM_NAME_HOT_SNF,'
      '        RASMNF.id_hot_snf as RASM_ID_HOT_SNF,'
      '        RASMCAT.name_hot_scatnom as RASM_NAME_HOT_SCATNOM,'
      '        RASMCAT.id_hot_scatnom as RASM_ID_HOT_SCATNOM,'
      '        RASMTPOS.name_hot_stypepos as RASM_NAME_HOT_STYPEPOS,'
      '        RASMTPOS.id_hot_stypepos as RASM_ID_HOT_STYPEPOS,'
      '        RASMGUEST.nameklient as RASM_NAMEGUEST,'
      '        RASMGUEST.idklient as RASM_IDGUEST,'
      '        RASMSOST.name_hot_ssostnom as RASM_NAME_HOT_SSOSTNOM,'
      '        RASMSOST.id_hot_ssostnom as RASM_ID_HOT_SSOSTNOM,'
      '        RASM.posnach_hot_sostnf as RASM_posnach_hot_sostnf,'
      '        RASM.poscon_hot_sostnf as RASM_poscon_hot_sostnf,'
      '        RASM.kolm_hot_sostnf as RASM_kolm_hot_sostnf,'
      ''
      '        BR2NF.name_hot_snf as BR2_NAME_HOT_SNF,'
      '        BR2NF.id_hot_snf as BR2_ID_HOT_SNF,'
      '        BR2CAT.name_hot_scatnom as BR2_NAME_HOT_SCATNOM,'
      '        BR2CAT.id_hot_scatnom as BR2_ID_HOT_SCATNOM,'
      '        BR2TPOS.name_hot_stypepos as BR2_NAME_HOT_STYPEPOS,'
      '        BR2TPOS.id_hot_stypepos as BR2_ID_HOT_STYPEPOS,'
      '        BR2GUEST.nameklient as BR2_NAMEGUEST,'
      '        BR2GUEST.idklient as BR2_IDGUEST,'
      '        BR2SOST.name_hot_ssostnom as BR2_NAME_HOT_SSOSTNOM,'
      '        BR2SOST.id_hot_ssostnom as BR2_ID_HOT_SSOSTNOM,'
      '        BR2.posnach_hot_sostnf as BR2_posnach_hot_sostnf,'
      '        BR2.poscon_hot_sostnf as BR2_poscon_hot_sostnf,'
      '        BR2.kolm_hot_sostnf as BR2_kolm_hot_sostnf'
      ''
      'from HOT_DRASMT'
      
        'left outer join hot_sostnf as BR  on hot_drasmt.idsostbr_hot_dra' +
        'smt=BR.id_hot_sostnf'
      
        'left outer join hot_snf  as BRNF on BRNF.id_hot_snf=BR.idnomer_h' +
        'ot_sostnf'
      
        'left outer join hot_scatnom as BRCAT on BRCAT.id_hot_scatnom=BR.' +
        'idcat_hot_sostnf'
      
        'left outer join hot_stypepos as BRTPOS on BRTPOS.id_hot_stypepos' +
        '=BR.idtpos_hot_sostnf'
      
        'left outer join sklient as BRGUEST on BRGUEST.idklient=BR.idgues' +
        't_hot_sostnf'
      
        'left outer join hot_ssostnom as BRSOST on BRSOST.id_hot_ssostnom' +
        '=BR.idsost_hot_sostnf'
      ''
      
        'left outer join hot_sostnf as RASM  on hot_drasmt.idsostrasm_hot' +
        '_drasmt=RASM.id_hot_sostnf'
      
        'left outer join hot_snf  as RASMNF on RASMNF.id_hot_snf=RASM.idn' +
        'omer_hot_sostnf'
      
        'left outer join hot_scatnom as RASMCAT on RASMCAT.id_hot_scatnom' +
        '=RASM.idcat_hot_sostnf'
      
        'left outer join hot_stypepos as RASMTPOS on RASMTPOS.id_hot_styp' +
        'epos=RASM.idtpos_hot_sostnf'
      
        'left outer join sklient as RASMGUEST on RASMGUEST.idklient=RASM.' +
        'idguest_hot_sostnf'
      
        'left outer join hot_ssostnom as RASMSOST on RASMSOST.id_hot_ssos' +
        'tnom=RASM.idsost_hot_sostnf'
      ''
      
        'left outer join hot_sostnf as BR2  on hot_drasmt.idsostbr2_hot_d' +
        'rasmt=BR2.id_hot_sostnf'
      
        'left outer join hot_snf  as BR2NF on BR2NF.id_hot_snf=BR2.idnome' +
        'r_hot_sostnf'
      
        'left outer join hot_scatnom as BR2CAT on BR2CAT.id_hot_scatnom=B' +
        'R2.idcat_hot_sostnf'
      
        'left outer join hot_stypepos as BR2TPOS on BR2TPOS.id_hot_stypep' +
        'os=BR2.idtpos_hot_sostnf'
      
        'left outer join sklient as BR2GUEST on BR2GUEST.idklient=BR2.idg' +
        'uest_hot_sostnf'
      
        'left outer join hot_ssostnom as BR2SOST on BR2SOST.id_hot_ssostn' +
        'om=BR2.idsost_hot_sostnf'
      ''
      'where IDDOCH_HOT_DRASMT=:PARAM_IDDOCH')
    AutoUpdateOptions.UpdateTableName = 'HOT_DRASMT'
    AutoUpdateOptions.KeyFields = 'ID_HOT_DRASMT'
    AutoUpdateOptions.GeneratorName = 'GEN_HOT_DRASMT_ID'
    OnCalcFields = DocTCalcFields
    OnNewRecord = DocTNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 144
    poUseLargeIntField = True
    object DocTBR_NAME_HOT_SNF: TFIBWideStringField
      FieldName = 'BR_NAME_HOT_SNF'
      Size = 100
    end
    object DocTBR_NAME_HOT_SCATNOM: TFIBWideStringField
      FieldName = 'BR_NAME_HOT_SCATNOM'
      Size = 100
    end
    object DocTBR_NAME_HOT_STYPEPOS: TFIBWideStringField
      FieldName = 'BR_NAME_HOT_STYPEPOS'
      Size = 100
    end
    object DocTBR_NAMEGUEST: TFIBWideStringField
      FieldName = 'BR_NAMEGUEST'
      Size = 100
    end
    object DocTBR_NAME_HOT_SSOSTNOM: TFIBWideStringField
      FieldName = 'BR_NAME_HOT_SSOSTNOM'
      Size = 100
    end
    object DocTBR_POSNACH_HOT_SOSTNF: TFIBDateTimeField
      FieldName = 'BR_POSNACH_HOT_SOSTNF'
    end
    object DocTBR_POSCON_HOT_SOSTNF: TFIBDateTimeField
      FieldName = 'BR_POSCON_HOT_SOSTNF'
    end
    object DocTBR_KOLM_HOT_SOSTNF: TFIBIntegerField
      FieldName = 'BR_KOLM_HOT_SOSTNF'
    end
    object DocTRASM_NAME_HOT_SNF: TFIBWideStringField
      FieldName = 'RASM_NAME_HOT_SNF'
      Size = 100
    end
    object DocTRASM_NAME_HOT_SCATNOM: TFIBWideStringField
      FieldName = 'RASM_NAME_HOT_SCATNOM'
      Size = 100
    end
    object DocTRASM_NAME_HOT_STYPEPOS: TFIBWideStringField
      FieldName = 'RASM_NAME_HOT_STYPEPOS'
      Size = 100
    end
    object DocTRASM_NAMEGUEST: TFIBWideStringField
      FieldName = 'RASM_NAMEGUEST'
      Size = 100
    end
    object DocTRASM_NAME_HOT_SSOSTNOM: TFIBWideStringField
      FieldName = 'RASM_NAME_HOT_SSOSTNOM'
      Size = 100
    end
    object DocTRASM_POSNACH_HOT_SOSTNF: TFIBDateTimeField
      FieldName = 'RASM_POSNACH_HOT_SOSTNF'
    end
    object DocTRASM_POSCON_HOT_SOSTNF: TFIBDateTimeField
      FieldName = 'RASM_POSCON_HOT_SOSTNF'
    end
    object DocTRASM_KOLM_HOT_SOSTNF: TFIBIntegerField
      FieldName = 'RASM_KOLM_HOT_SOSTNF'
    end
    object DocTBR2_NAME_HOT_SNF: TFIBWideStringField
      FieldName = 'BR2_NAME_HOT_SNF'
      Size = 100
    end
    object DocTBR2_NAME_HOT_SCATNOM: TFIBWideStringField
      FieldName = 'BR2_NAME_HOT_SCATNOM'
      Size = 100
    end
    object DocTBR2_NAME_HOT_STYPEPOS: TFIBWideStringField
      FieldName = 'BR2_NAME_HOT_STYPEPOS'
      Size = 100
    end
    object DocTBR2_NAMEGUEST: TFIBWideStringField
      FieldName = 'BR2_NAMEGUEST'
      Size = 100
    end
    object DocTBR2_NAME_HOT_SSOSTNOM: TFIBWideStringField
      FieldName = 'BR2_NAME_HOT_SSOSTNOM'
      Size = 100
    end
    object DocTBR2_POSNACH_HOT_SOSTNF: TFIBDateTimeField
      FieldName = 'BR2_POSNACH_HOT_SOSTNF'
    end
    object DocTBR2_POSCON_HOT_SOSTNF: TFIBDateTimeField
      FieldName = 'BR2_POSCON_HOT_SOSTNF'
    end
    object DocTBR2_KOLM_HOT_SOSTNF: TFIBIntegerField
      FieldName = 'BR2_KOLM_HOT_SOSTNF'
    end
    object DocTBR: TStringField
      FieldKind = fkCalculated
      FieldName = 'BR'
      Calculated = True
    end
    object DocTRASM: TStringField
      FieldKind = fkCalculated
      FieldName = 'RASM'
      Calculated = True
    end
    object DocTBR2: TStringField
      FieldKind = fkCalculated
      FieldName = 'BR2'
      Calculated = True
    end
    object DocTID_HOT_DRASMT: TFIBLargeIntField
      FieldName = 'ID_HOT_DRASMT'
    end
    object DocTIDDOCH_HOT_DRASMT: TFIBLargeIntField
      FieldName = 'IDDOCH_HOT_DRASMT'
    end
    object DocTIDSOSTBR_HOT_DRASMT: TFIBLargeIntField
      FieldName = 'IDSOSTBR_HOT_DRASMT'
    end
    object DocTIDSOSTRASM_HOT_DRASMT: TFIBLargeIntField
      FieldName = 'IDSOSTRASM_HOT_DRASMT'
    end
    object DocTIDSOSTBR2_HOT_DRASMT: TFIBLargeIntField
      FieldName = 'IDSOSTBR2_HOT_DRASMT'
    end
    object DocTIDBASE_HOT_DRASMT: TFIBLargeIntField
      FieldName = 'IDBASE_HOT_DRASMT'
    end
    object DocTRASM_ID_HOT_SNF: TFIBLargeIntField
      FieldName = 'RASM_ID_HOT_SNF'
    end
    object DocTRASM_ID_HOT_SCATNOM: TFIBLargeIntField
      FieldName = 'RASM_ID_HOT_SCATNOM'
    end
    object DocTRASM_ID_HOT_STYPEPOS: TFIBLargeIntField
      FieldName = 'RASM_ID_HOT_STYPEPOS'
    end
    object DocTRASM_IDGUEST: TFIBLargeIntField
      FieldName = 'RASM_IDGUEST'
    end
    object DocTRASM_ID_HOT_SSOSTNOM: TFIBLargeIntField
      FieldName = 'RASM_ID_HOT_SSOSTNOM'
    end
    object DocTBR2_ID_HOT_SNF: TFIBLargeIntField
      FieldName = 'BR2_ID_HOT_SNF'
    end
    object DocTBR2_ID_HOT_SCATNOM: TFIBLargeIntField
      FieldName = 'BR2_ID_HOT_SCATNOM'
    end
    object DocTBR2_ID_HOT_STYPEPOS: TFIBLargeIntField
      FieldName = 'BR2_ID_HOT_STYPEPOS'
    end
    object DocTBR2_IDGUEST: TFIBLargeIntField
      FieldName = 'BR2_IDGUEST'
    end
    object DocTBR2_ID_HOT_SSOSTNOM: TFIBLargeIntField
      FieldName = 'BR2_ID_HOT_SSOSTNOM'
    end
  end
  object DataSourceDocT: TDataSource
    DataSet = DocT
    Left = 72
    Top = 144
  end
end
