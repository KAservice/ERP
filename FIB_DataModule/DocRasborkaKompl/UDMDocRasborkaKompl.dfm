object DMDocRasborkaKompl: TDMDocRasborkaKompl
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 369
  Width = 695
  object DataSourceDoc: TDataSource
    DataSet = Doc
    Left = 72
    Top = 64
  end
  object DataSourceDocT: TDataSource
    DataSet = DocT
    Left = 72
    Top = 112
  end
  object DataSourceDocAll: TDataSource
    DataSet = DocAll
    Left = 72
    Top = 16
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
      '    IDPROJECT_GALLDOC = :IDPROJECT_GALLDOC,'
      '    IDBUSINOP_GALLDOC = :IDBUSINOP_GALLDOC,'
      '    PREFIKS_NUM_GALLDOC = :PREFIKS_NUM_GALLDOC'
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
      '    IDPROJECT_GALLDOC,'
      '    IDBUSINOP_GALLDOC,'
      '    PREFIKS_NUM_GALLDOC'
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
      '    :IDPROJECT_GALLDOC,'
      '    :IDBUSINOP_GALLDOC,'
      '    :PREFIKS_NUM_GALLDOC'
      ')')
    RefreshSQL.Strings = (
      
        'select GALLDOC.*, FNAME_USER , NAME_SINFBASE_OBMEN, NAMEFIRM, NA' +
        'MESKLAD,'
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from '
      '  GALLDOC'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      'left outer join SFIRM on IDFIRMDOC=IDFIRM'
      'left outer join SSKLAD on IDSKLDOC=IDSKLAD'
      
        'left outer join SPROJECT on galldoc.idproject_galldoc=sproject.i' +
        'd_sproject'
      
        'left outer join sbusiness_oper on galldoc.idbusinop_galldoc=sbus' +
        'iness_oper.id_sbusiness_oper'
      'where(  '
      '  IDDOC=:ID'
      '     ) and (     GALLDOC.IDDOC = :OLD_IDDOC'
      '     )'
      '     ')
    SelectSQL.Strings = (
      
        'select GALLDOC.*, FNAME_USER , NAME_SINFBASE_OBMEN, NAMEFIRM, NA' +
        'MESKLAD,'
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from '
      '  GALLDOC'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_GALLD' +
        'OC'
      'left outer join SFIRM on IDFIRMDOC=IDFIRM'
      'left outer join SSKLAD on IDSKLDOC=IDSKLAD'
      
        'left outer join SPROJECT on galldoc.idproject_galldoc=sproject.i' +
        'd_sproject'
      
        'left outer join sbusiness_oper on galldoc.idbusinop_galldoc=sbus' +
        'iness_oper.id_sbusiness_oper'
      'where '
      '  IDDOC=:ID ')
    AutoUpdateOptions.UpdateTableName = 'GALLDOC'
    AutoUpdateOptions.KeyFields = 'IDDOC'
    AutoUpdateOptions.GeneratorName = 'GEN_GALLDOC_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object DocAllPOSDOC: TFIBDateTimeField
      FieldName = 'POSDOC'
      OnChange = DocAllPOSDOCChange
      DisplayFormat = 'c'
    end
    object DocAllPRDOC: TFIBSmallIntField
      FieldName = 'PRDOC'
    end
    object DocAllNUMDOC: TFIBIntegerField
      FieldName = 'NUMDOC'
    end
    object DocAllSUMDOC: TFIBBCDField
      FieldName = 'SUMDOC'
      Size = 2
      RoundByScale = True
    end
    object DocAllIDDOC: TFIBLargeIntField
      FieldName = 'IDDOC'
    end
    object DocAllTDOC: TFIBWideStringField
      FieldName = 'TDOC'
      Size = 10
    end
    object DocAllIDFIRMDOC: TFIBLargeIntField
      FieldName = 'IDFIRMDOC'
      OnChange = DocAllIDFIRMDOCChange
    end
    object DocAllIDSKLDOC: TFIBLargeIntField
      FieldName = 'IDSKLDOC'
      OnChange = DocAllIDSKLDOCChange
    end
    object DocAllIDKLDOC: TFIBLargeIntField
      FieldName = 'IDKLDOC'
    end
    object DocAllIDDOGDOC: TFIBLargeIntField
      FieldName = 'IDDOGDOC'
    end
    object DocAllIDUSERDOC: TFIBLargeIntField
      FieldName = 'IDUSERDOC'
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
      OnChange = DocAllIDBASE_GALLDOCChange
    end
    object DocAllIDPROJECT_GALLDOC: TFIBLargeIntField
      FieldName = 'IDPROJECT_GALLDOC'
    end
    object DocAllFNAME_USER: TFIBWideStringField
      FieldName = 'FNAME_USER'
      Size = 200
    end
    object DocAllNAME_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 200
    end
    object DocAllNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 200
    end
    object DocAllNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 200
    end
    object DocAllGID_DOC: TFIBWideStringField
      FieldName = 'GID_DOC'
      Size = 10
    end
    object DocAllIDBUSINOP_GALLDOC: TFIBLargeIntField
      FieldName = 'IDBUSINOP_GALLDOC'
    end
    object DocAllNAME_SPROJECT: TFIBWideStringField
      FieldName = 'NAME_SPROJECT'
      Size = 200
    end
    object DocAllNAME_SBUSINESS_OPER: TFIBWideStringField
      FieldName = 'NAME_SBUSINESS_OPER'
      Size = 200
    end
    object DocAllPREFIKS_NUM_GALLDOC: TFIBWideStringField
      FieldName = 'PREFIKS_NUM_GALLDOC'
      Size = 12
    end
  end
  object Doc: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DRASBKOMPL'
      'SET '
      '    IDBASE_DRASBKOMPL = :IDBASE_DRASBKOMPL,'
      '    IDDOC_DRASBKOMPL = :IDDOC_DRASBKOMPL,'
      '    IDNOM_DRASBKOMPL = :IDNOM_DRASBKOMPL,'
      '    IDED_DRASBKOMPL = :IDED_DRASBKOMPL,'
      '    KF_DRASBKOMPL = :KF_DRASBKOMPL,'
      '    KOL_DRASBKOMPL = :KOL_DRASBKOMPL,'
      '    RPRICE_DRASBKOMPL = :RPRICE_DRASBKOMPL,'
      '    DESCR_DRASBKOMPL = :DESCR_DRASBKOMPL,'
      '    IDRTPRICE_DRASBKOMPL = :IDRTPRICE_DRASBKOMPL'
      'WHERE'
      '    ID_DRASBKOMPL = :OLD_ID_DRASBKOMPL'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DRASBKOMPL'
      'WHERE'
      '        ID_DRASBKOMPL = :OLD_ID_DRASBKOMPL'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DRASBKOMPL('
      '    ID_DRASBKOMPL,'
      '    IDBASE_DRASBKOMPL,'
      '    IDDOC_DRASBKOMPL,'
      '    IDNOM_DRASBKOMPL,'
      '    IDED_DRASBKOMPL,'
      '    KF_DRASBKOMPL,'
      '    KOL_DRASBKOMPL,'
      '    RPRICE_DRASBKOMPL,'
      '    DESCR_DRASBKOMPL,'
      '    IDRTPRICE_DRASBKOMPL'
      ')'
      'VALUES('
      '    :ID_DRASBKOMPL,'
      '    :IDBASE_DRASBKOMPL,'
      '    :IDDOC_DRASBKOMPL,'
      '    :IDNOM_DRASBKOMPL,'
      '    :IDED_DRASBKOMPL,'
      '    :KF_DRASBKOMPL,'
      '    :KOL_DRASBKOMPL,'
      '    :RPRICE_DRASBKOMPL,'
      '    :DESCR_DRASBKOMPL,'
      '    :IDRTPRICE_DRASBKOMPL'
      ')')
    RefreshSQL.Strings = (
      'select drasbkompl.*,'
      '        snom.namenom,'
      '        sed.nameed'
      'from  drasbkompl'
      
        '    left outer join snom on snom.idnom=drasbkompl.idnom_drasbkom' +
        'pl'
      '    left outer join sed on sed.ided=drasbkompl.ided_drasbkompl'
      'where(  drasbkompl.iddoc_drasbkompl=:PARAM_IDDOC'
      '     ) and (     DRASBKOMPL.ID_DRASBKOMPL = :OLD_ID_DRASBKOMPL'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select drasbkompl.*,'
      '        snom.namenom,'
      '        sed.nameed'
      'from  drasbkompl'
      
        '    left outer join snom on snom.idnom=drasbkompl.idnom_drasbkom' +
        'pl'
      '    left outer join sed on sed.ided=drasbkompl.ided_drasbkompl'
      'where drasbkompl.iddoc_drasbkompl=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'DRASBKOMPL'
    AutoUpdateOptions.KeyFields = 'ID_DRASBKOMPL'
    AutoUpdateOptions.GeneratorName = 'GEN_DRASBKOMPL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object DocKF_DRASBKOMPL: TFIBBCDField
      FieldName = 'KF_DRASBKOMPL'
      Size = 3
      RoundByScale = True
    end
    object DocKOL_DRASBKOMPL: TFIBBCDField
      FieldName = 'KOL_DRASBKOMPL'
      Size = 3
      RoundByScale = True
    end
    object DocRPRICE_DRASBKOMPL: TFIBBCDField
      FieldName = 'RPRICE_DRASBKOMPL'
      Size = 2
      RoundByScale = True
    end
    object DocID_DRASBKOMPL: TFIBLargeIntField
      FieldName = 'ID_DRASBKOMPL'
    end
    object DocIDBASE_DRASBKOMPL: TFIBLargeIntField
      FieldName = 'IDBASE_DRASBKOMPL'
    end
    object DocIDDOC_DRASBKOMPL: TFIBLargeIntField
      FieldName = 'IDDOC_DRASBKOMPL'
    end
    object DocIDNOM_DRASBKOMPL: TFIBLargeIntField
      FieldName = 'IDNOM_DRASBKOMPL'
    end
    object DocIDED_DRASBKOMPL: TFIBLargeIntField
      FieldName = 'IDED_DRASBKOMPL'
    end
    object DocDESCR_DRASBKOMPL: TFIBWideStringField
      FieldName = 'DESCR_DRASBKOMPL'
      Size = 150
    end
    object DocIDRTPRICE_DRASBKOMPL: TFIBLargeIntField
      FieldName = 'IDRTPRICE_DRASBKOMPL'
    end
    object DocNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 100
    end
    object DocNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DRASBKOMPLT'
      'SET '
      '    IDBASE_DRASBKOMPLT = :IDBASE_DRASBKOMPLT,'
      '    IDDOC_DRASBKOMPLT = :IDDOC_DRASBKOMPLT,'
      '    IDNOM_DRASBKOMPLT = :IDNOM_DRASBKOMPLT,'
      '    IDED_DRASBKOMPLT = :IDED_DRASBKOMPLT,'
      '    IDPART_DRASBKOMPLT = :IDPART_DRASBKOMPLT,'
      '    KF_DRASBKOMPLT = :KF_DRASBKOMPLT,'
      '    KOL_DRASBKOMPLT = :KOL_DRASBKOMPLT,'
      '    RPRICE_DRASBKOMPLT = :RPRICE_DRASBKOMPLT,'
      '    RSUM_DRASBKOMPLT = :RSUM_DRASBKOMPLT,'
      '    KFSEB_DRASBKOMPLT = :KFSEB_DRASBKOMPLT'
      'WHERE'
      '    ID_DRASBKOMPLT = :OLD_ID_DRASBKOMPLT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DRASBKOMPLT'
      'WHERE'
      '        ID_DRASBKOMPLT = :OLD_ID_DRASBKOMPLT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DRASBKOMPLT('
      '    ID_DRASBKOMPLT,'
      '    IDBASE_DRASBKOMPLT,'
      '    IDDOC_DRASBKOMPLT,'
      '    IDNOM_DRASBKOMPLT,'
      '    IDED_DRASBKOMPLT,'
      '    IDPART_DRASBKOMPLT,'
      '    KF_DRASBKOMPLT,'
      '    KOL_DRASBKOMPLT,'
      '    RPRICE_DRASBKOMPLT,'
      '    RSUM_DRASBKOMPLT,'
      '    KFSEB_DRASBKOMPLT'
      ')'
      'VALUES('
      '    :ID_DRASBKOMPLT,'
      '    :IDBASE_DRASBKOMPLT,'
      '    :IDDOC_DRASBKOMPLT,'
      '    :IDNOM_DRASBKOMPLT,'
      '    :IDED_DRASBKOMPLT,'
      '    :IDPART_DRASBKOMPLT,'
      '    :KF_DRASBKOMPLT,'
      '    :KOL_DRASBKOMPLT,'
      '    :RPRICE_DRASBKOMPLT,'
      '    :RSUM_DRASBKOMPLT,'
      '    :KFSEB_DRASBKOMPLT'
      ')')
    RefreshSQL.Strings = (
      'select drasbkomplt.*,'
      '        snom.namenom,'
      '        sed.nameed'
      'from  drasbkomplt'
      
        '    left outer join snom on snom.idnom=drasbkomplt.idnom_drasbko' +
        'mplt'
      '    left outer join sed on sed.ided=drasbkomplt.ided_drasbkomplt'
      'where(  drasbkomplt.iddoc_drasbkomplt=:PARAM_IDDOC'
      
        '     ) and (     DRASBKOMPLT.ID_DRASBKOMPLT = :OLD_ID_DRASBKOMPL' +
        'T'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select drasbkomplt.*,'
      '        snom.namenom,'
      '        sed.nameed,'
      '        snom.artnom, '
      '        snom.codenom, '
      '        sed.shed'
      'from  drasbkomplt'
      
        '    left outer join snom on snom.idnom=drasbkomplt.idnom_drasbko' +
        'mplt'
      '    left outer join sed on sed.ided=drasbkomplt.ided_drasbkomplt'
      'where drasbkomplt.iddoc_drasbkomplt=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'DRASBKOMPLT'
    AutoUpdateOptions.KeyFields = 'ID_DRASBKOMPLT'
    AutoUpdateOptions.GeneratorName = 'GEN_DRASBKOMPLT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    AfterDelete = DocTAfterDelete
    BeforeDelete = DocTBeforeDelete
    OnCalcFields = DocTCalcFields
    OnNewRecord = DocTNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 112
    poUseLargeIntField = True
    object DocTKF_DRASBKOMPLT: TFIBBCDField
      FieldName = 'KF_DRASBKOMPLT'
      Size = 3
      RoundByScale = True
    end
    object DocTKOL_DRASBKOMPLT: TFIBBCDField
      FieldName = 'KOL_DRASBKOMPLT'
      OnChange = DocTKOL_DRASBKOMPLTChange
      Size = 3
      RoundByScale = True
    end
    object DocTRPRICE_DRASBKOMPLT: TFIBBCDField
      FieldName = 'RPRICE_DRASBKOMPLT'
      OnChange = DocTRPRICE_DRASBKOMPLTChange
      Size = 2
      RoundByScale = True
    end
    object DocTRSUM_DRASBKOMPLT: TFIBBCDField
      FieldName = 'RSUM_DRASBKOMPLT'
      Size = 2
      RoundByScale = True
    end
    object DocTRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object DocTKFSEB_DRASBKOMPLT: TFIBBCDField
      FieldName = 'KFSEB_DRASBKOMPLT'
      Size = 3
      RoundByScale = True
    end
    object DocTID_DRASBKOMPLT: TFIBLargeIntField
      FieldName = 'ID_DRASBKOMPLT'
    end
    object DocTIDBASE_DRASBKOMPLT: TFIBLargeIntField
      FieldName = 'IDBASE_DRASBKOMPLT'
    end
    object DocTIDDOC_DRASBKOMPLT: TFIBLargeIntField
      FieldName = 'IDDOC_DRASBKOMPLT'
    end
    object DocTIDNOM_DRASBKOMPLT: TFIBLargeIntField
      FieldName = 'IDNOM_DRASBKOMPLT'
    end
    object DocTIDED_DRASBKOMPLT: TFIBLargeIntField
      FieldName = 'IDED_DRASBKOMPLT'
    end
    object DocTIDPART_DRASBKOMPLT: TFIBLargeIntField
      FieldName = 'IDPART_DRASBKOMPLT'
    end
    object DocTNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object DocTNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 200
    end
    object DocTARTNOM: TFIBWideStringField
      FieldName = 'ARTNOM'
      Size = 40
    end
    object DocTCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object DocTSHED: TFIBWideStringField
      FieldName = 'SHED'
      Size = 13
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
    Left = 240
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
    Left = 240
    Top = 64
  end
  object IBTrDvReg: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 24
    Top = 272
  end
  object NumDoc: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      
        'from DOC_RASBKOMPL_GET_NUM_NEW_DOC (:PARAM_IDBASE,:PARAM_IDFIRM,' +
        ':PARAM_IDSKLAD)')
    Transaction = IBTr
    Left = 296
    Top = 16
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 336
    Top = 176
    qoStartTransaction = True
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_RASBKOMPL_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 304
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_RASBKOMPL_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 240
    qoStartTransaction = True
  end
end
