object DMDocSborkaKompl: TDMDocSborkaKompl
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 369
  Width = 773
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
        'MESKLAD, '
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
        'MESKLAD, '
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
    object DocAllIDDOC: TFIBBCDField
      FieldName = 'IDDOC'
      Size = 0
      RoundByScale = True
    end
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
    object DocAllIDFIRMDOC: TFIBBCDField
      FieldName = 'IDFIRMDOC'
      OnChange = DocAllIDFIRMDOCChange
      Size = 0
      RoundByScale = True
    end
    object DocAllIDSKLDOC: TFIBBCDField
      FieldName = 'IDSKLDOC'
      OnChange = DocAllIDSKLDOCChange
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
    object DocAllIDBASE_GALLDOC: TFIBBCDField
      FieldName = 'IDBASE_GALLDOC'
      OnChange = DocAllIDBASE_GALLDOCChange
      Size = 0
      RoundByScale = True
    end
    object DocAllGID_DOC: TFIBWideStringField
      FieldName = 'GID_DOC'
      Size = 10
    end
    object DocAllTYPEEXTDOC: TFIBIntegerField
      FieldName = 'TYPEEXTDOC'
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
    object DocAllTDOC: TFIBWideStringField
      FieldName = 'TDOC'
      Size = 10
    end
    object DocAllIDPROJECT_GALLDOC: TFIBBCDField
      FieldName = 'IDPROJECT_GALLDOC'
      Size = 0
      RoundByScale = True
    end
    object DocAllIDBUSINOP_GALLDOC: TFIBBCDField
      FieldName = 'IDBUSINOP_GALLDOC'
      Size = 0
      RoundByScale = True
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
      'UPDATE DSBKOMPL'
      'SET '
      '    IDBASE_DSBKOMPL = :IDBASE_DSBKOMPL,'
      '    IDDOC_DSBKOMPL = :IDDOC_DSBKOMPL,'
      '    IDNOM_DSBKOMPL = :IDNOM_DSBKOMPL,'
      '    IDED_DSBKOMPL = :IDED_DSBKOMPL,'
      '    IDPART_DSBKOMPL = :IDPART_DSBKOMPL,'
      '    KF_DSBKOMPL = :KF_DSBKOMPL,'
      '    KOL_DSBKOMPL = :KOL_DSBKOMPL,'
      '    RPRICE_DSBKOMPL = :RPRICE_DSBKOMPL,'
      '    DESCR_DSBKOMPL = :DESCR_DSBKOMPL,'
      '    IDRTPRICE_DSBKOMPL = :IDRTPRICE_DSBKOMPL'
      'WHERE'
      '    ID_DSBKOMPL = :OLD_ID_DSBKOMPL'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DSBKOMPL'
      'WHERE'
      '        ID_DSBKOMPL = :OLD_ID_DSBKOMPL'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DSBKOMPL('
      '    ID_DSBKOMPL,'
      '    IDBASE_DSBKOMPL,'
      '    IDDOC_DSBKOMPL,'
      '    IDNOM_DSBKOMPL,'
      '    IDED_DSBKOMPL,'
      '    IDPART_DSBKOMPL,'
      '    KF_DSBKOMPL,'
      '    KOL_DSBKOMPL,'
      '    RPRICE_DSBKOMPL,'
      '    DESCR_DSBKOMPL,'
      '    IDRTPRICE_DSBKOMPL'
      ')'
      'VALUES('
      '    :ID_DSBKOMPL,'
      '    :IDBASE_DSBKOMPL,'
      '    :IDDOC_DSBKOMPL,'
      '    :IDNOM_DSBKOMPL,'
      '    :IDED_DSBKOMPL,'
      '    :IDPART_DSBKOMPL,'
      '    :KF_DSBKOMPL,'
      '    :KOL_DSBKOMPL,'
      '    :RPRICE_DSBKOMPL,'
      '    :DESCR_DSBKOMPL,'
      '    :IDRTPRICE_DSBKOMPL'
      ')')
    RefreshSQL.Strings = (
      'select dsbkompl.*,'
      '        snom.namenom,'
      '        sed.nameed'
      'from  dsbkompl'
      '    left outer join snom on snom.idnom=dsbkompl.idnom_dsbkompl'
      '    left outer join sed on sed.ided=dsbkompl.ided_dsbkompl'
      'where(  dsbkompl.iddoc_dsbkompl=:PARAM_IDDOC'
      '     ) and (     DSBKOMPL.ID_DSBKOMPL = :OLD_ID_DSBKOMPL'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select dsbkompl.*,'
      '        snom.namenom,'
      '        sed.nameed'
      'from  dsbkompl'
      '    left outer join snom on snom.idnom=dsbkompl.idnom_dsbkompl'
      '    left outer join sed on sed.ided=dsbkompl.ided_dsbkompl'
      'where dsbkompl.iddoc_dsbkompl=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'DSBKOMPL'
    AutoUpdateOptions.KeyFields = 'ID_DSBKOMPL'
    AutoUpdateOptions.GeneratorName = 'GEN_DSBKOMPL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    object DocID_DSBKOMPL: TFIBBCDField
      FieldName = 'ID_DSBKOMPL'
      Size = 0
      RoundByScale = True
    end
    object DocIDBASE_DSBKOMPL: TFIBBCDField
      FieldName = 'IDBASE_DSBKOMPL'
      Size = 0
      RoundByScale = True
    end
    object DocIDDOC_DSBKOMPL: TFIBBCDField
      FieldName = 'IDDOC_DSBKOMPL'
      Size = 0
      RoundByScale = True
    end
    object DocIDNOM_DSBKOMPL: TFIBBCDField
      FieldName = 'IDNOM_DSBKOMPL'
      Size = 0
      RoundByScale = True
    end
    object DocIDED_DSBKOMPL: TFIBBCDField
      FieldName = 'IDED_DSBKOMPL'
      Size = 0
      RoundByScale = True
    end
    object DocKF_DSBKOMPL: TFIBBCDField
      FieldName = 'KF_DSBKOMPL'
      Size = 3
      RoundByScale = True
    end
    object DocKOL_DSBKOMPL: TFIBBCDField
      FieldName = 'KOL_DSBKOMPL'
      Size = 3
      RoundByScale = True
    end
    object DocRPRICE_DSBKOMPL: TFIBBCDField
      FieldName = 'RPRICE_DSBKOMPL'
      Size = 2
      RoundByScale = True
    end
    object DocIDRTPRICE_DSBKOMPL: TFIBBCDField
      FieldName = 'IDRTPRICE_DSBKOMPL'
      Size = 0
      RoundByScale = True
    end
    object DocIDPART_DSBKOMPL: TFIBBCDField
      FieldName = 'IDPART_DSBKOMPL'
      Size = 0
      RoundByScale = True
    end
    object DocDESCR_DSBKOMPL: TFIBWideStringField
      FieldName = 'DESCR_DSBKOMPL'
      Size = 150
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
      'UPDATE DSBKOMPLT'
      'SET '
      '    IDBASE_DSBKOMPLT = :IDBASE_DSBKOMPLT,'
      '    IDDOC_DSBKOMPLT = :IDDOC_DSBKOMPLT,'
      '    IDNOM_DSBKOMPLT = :IDNOM_DSBKOMPLT,'
      '    IDED_DSBKOMPLT = :IDED_DSBKOMPLT,'
      '    KF_DSBKOMPLT = :KF_DSBKOMPLT,'
      '    KOL_DSBKOMPLT = :KOL_DSBKOMPLT,'
      '    RPRICE_DSBKOMPLT = :RPRICE_DSBKOMPLT,'
      '    RSUM_DSBKOMPLT = :RSUM_DSBKOMPLT'
      'WHERE'
      '    ID_DSBKOMPLT = :OLD_ID_DSBKOMPLT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DSBKOMPLT'
      'WHERE'
      '        ID_DSBKOMPLT = :OLD_ID_DSBKOMPLT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DSBKOMPLT('
      '    ID_DSBKOMPLT,'
      '    IDBASE_DSBKOMPLT,'
      '    IDDOC_DSBKOMPLT,'
      '    IDNOM_DSBKOMPLT,'
      '    IDED_DSBKOMPLT,'
      '    KF_DSBKOMPLT,'
      '    KOL_DSBKOMPLT,'
      '    RPRICE_DSBKOMPLT,'
      '    RSUM_DSBKOMPLT'
      ')'
      'VALUES('
      '    :ID_DSBKOMPLT,'
      '    :IDBASE_DSBKOMPLT,'
      '    :IDDOC_DSBKOMPLT,'
      '    :IDNOM_DSBKOMPLT,'
      '    :IDED_DSBKOMPLT,'
      '    :KF_DSBKOMPLT,'
      '    :KOL_DSBKOMPLT,'
      '    :RPRICE_DSBKOMPLT,'
      '    :RSUM_DSBKOMPLT'
      ')')
    RefreshSQL.Strings = (
      'select dsbkomplt.*,'
      '        snom.namenom,'
      '        sed.nameed'
      'from  dsbkomplt'
      '    left outer join snom on snom.idnom=dsbkomplt.idnom_dsbkomplt'
      '    left outer join sed on sed.ided=dsbkomplt.ided_dsbkomplt'
      'where(  dsbkomplt.iddoc_dsbkomplt=:PARAM_IDDOC'
      '     ) and (     DSBKOMPLT.ID_DSBKOMPLT = :OLD_ID_DSBKOMPLT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select dsbkomplt.*,'
      '        snom.namenom,'
      '        sed.nameed,'
      '        snom.artnom,'
      '        snom.codenom,'
      '        sed.shed'
      'from  dsbkomplt'
      '    left outer join snom on snom.idnom=dsbkomplt.idnom_dsbkomplt'
      '    left outer join sed on sed.ided=dsbkomplt.ided_dsbkomplt'
      'where dsbkomplt.iddoc_dsbkomplt=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'DSBKOMPLT'
    AutoUpdateOptions.KeyFields = 'ID_DSBKOMPLT'
    AutoUpdateOptions.GeneratorName = 'GEN_DSBKOMPLT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    AfterDelete = DocTAfterDelete
    BeforeDelete = DocTBeforeDelete
    OnCalcFields = DocTCalcFields
    OnNewRecord = DocTNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 112
    object DocTID_DSBKOMPLT: TFIBBCDField
      FieldName = 'ID_DSBKOMPLT'
      Size = 0
      RoundByScale = True
    end
    object DocTIDBASE_DSBKOMPLT: TFIBBCDField
      FieldName = 'IDBASE_DSBKOMPLT'
      Size = 0
      RoundByScale = True
    end
    object DocTIDDOC_DSBKOMPLT: TFIBBCDField
      FieldName = 'IDDOC_DSBKOMPLT'
      Size = 0
      RoundByScale = True
    end
    object DocTIDNOM_DSBKOMPLT: TFIBBCDField
      FieldName = 'IDNOM_DSBKOMPLT'
      Size = 0
      RoundByScale = True
    end
    object DocTIDED_DSBKOMPLT: TFIBBCDField
      FieldName = 'IDED_DSBKOMPLT'
      Size = 0
      RoundByScale = True
    end
    object DocTKF_DSBKOMPLT: TFIBBCDField
      FieldName = 'KF_DSBKOMPLT'
      Size = 3
      RoundByScale = True
    end
    object DocTKOL_DSBKOMPLT: TFIBBCDField
      FieldName = 'KOL_DSBKOMPLT'
      OnChange = DocTKOL_DSBKOMPLTChange
      Size = 3
      RoundByScale = True
    end
    object DocTRPRICE_DSBKOMPLT: TFIBBCDField
      FieldName = 'RPRICE_DSBKOMPLT'
      OnChange = DocTRPRICE_DSBKOMPLTChange
      Size = 2
      RoundByScale = True
    end
    object DocTRSUM_DSBKOMPLT: TFIBBCDField
      FieldName = 'RSUM_DSBKOMPLT'
      Size = 2
      RoundByScale = True
    end
    object DocTRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
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
      
        'from DOC_SBKOMPL_GET_NUM_NEW_DOC (:PARAM_IDBASE,:PARAM_IDFIRM,:P' +
        'ARAM_IDSKLAD)')
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
      'EXECUTE PROCEDURE DOC_SBKOMPL_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 304
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_SBKOMPL_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 240
    qoStartTransaction = True
  end
end
