object DMDocVipuskProd: TDMDocVipuskProd
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 369
  Width = 398
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
    poUseLargeIntField = True
    object DocAllIDDOC: TFIBLargeIntField
      FieldName = 'IDDOC'
    end
    object DocAllPOSDOC: TFIBDateTimeField
      FieldName = 'POSDOC'
      OnChange = DocAllPOSDOCChange
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
      OnChange = DocAllIDBASE_GALLDOCChange
    end
    object DocAllIDPROJECT_GALLDOC: TFIBLargeIntField
      FieldName = 'IDPROJECT_GALLDOC'
    end
    object DocAllIDBUSINOP_GALLDOC: TFIBLargeIntField
      FieldName = 'IDBUSINOP_GALLDOC'
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
      'UPDATE DVIPPROD'
      'SET '
      '    IDDOC_DVIPPROD = :IDDOC_DVIPPROD,'
      '    IDBASE_DVIPPROD = :IDBASE_DVIPPROD,'
      '    PRIM_DVIPPROD = :PRIM_DVIPPROD,'
      '    IDRTPRICE_DVIPPROD = :IDRTPRICE_DVIPPROD'
      'WHERE'
      '    ID_DVIPPROD = :OLD_ID_DVIPPROD'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DVIPPROD'
      'WHERE'
      '        ID_DVIPPROD = :OLD_ID_DVIPPROD'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DVIPPROD('
      '    ID_DVIPPROD,'
      '    IDDOC_DVIPPROD,'
      '    IDBASE_DVIPPROD,'
      '    PRIM_DVIPPROD,'
      '    IDRTPRICE_DVIPPROD'
      ')'
      'VALUES('
      '    :ID_DVIPPROD,'
      '    :IDDOC_DVIPPROD,'
      '    :IDBASE_DVIPPROD,'
      '    :PRIM_DVIPPROD,'
      '    :IDRTPRICE_DVIPPROD'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from  DVIPPROD'
      'where(  IDDOC_DVIPPROD=:ID'
      '     ) and (     DVIPPROD.ID_DVIPPROD = :OLD_ID_DVIPPROD'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from  DVIPPROD'
      'where IDDOC_DVIPPROD=:ID')
    AutoUpdateOptions.UpdateTableName = 'DVIPPROD'
    AutoUpdateOptions.KeyFields = 'ID_DVIPPROD'
    AutoUpdateOptions.GeneratorName = 'GEN_DVIPPROD_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object DocID_DVIPPROD: TFIBLargeIntField
      FieldName = 'ID_DVIPPROD'
    end
    object DocIDDOC_DVIPPROD: TFIBLargeIntField
      FieldName = 'IDDOC_DVIPPROD'
    end
    object DocIDBASE_DVIPPROD: TFIBLargeIntField
      FieldName = 'IDBASE_DVIPPROD'
    end
    object DocPRIM_DVIPPROD: TFIBWideStringField
      FieldName = 'PRIM_DVIPPROD'
      Size = 200
    end
    object DocIDRTPRICE_DVIPPROD: TFIBLargeIntField
      FieldName = 'IDRTPRICE_DVIPPROD'
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DVIPPRODT'
      'SET '
      '    IDDOC_DVIPPRODT = :IDDOC_DVIPPRODT,'
      '    IDBASE_DVIPPRODT = :IDBASE_DVIPPRODT,'
      '    IDNOM_DVIPPRODT = :IDNOM_DVIPPRODT,'
      '    IDED_DVIPPRODT = :IDED_DVIPPRODT,'
      '    IDPART_DVIPPRODT = :IDPART_DVIPPRODT,'
      '    KOL_DVIPPRODT = :KOL_DVIPPRODT,'
      '    KF_DVIPPRODT = :KF_DVIPPRODT,'
      '    RPRICE_DVIPPRODT = :RPRICE_DVIPPRODT,'
      '    RSUM_DVIPPRODT = :RSUM_DVIPPRODT'
      'WHERE'
      '    ID_DVIPPRODT = :OLD_ID_DVIPPRODT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DVIPPRODT'
      'WHERE'
      '        ID_DVIPPRODT = :OLD_ID_DVIPPRODT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DVIPPRODT('
      '    ID_DVIPPRODT,'
      '    IDDOC_DVIPPRODT,'
      '    IDBASE_DVIPPRODT,'
      '    IDNOM_DVIPPRODT,'
      '    IDED_DVIPPRODT,'
      '    IDPART_DVIPPRODT,'
      '    KOL_DVIPPRODT,'
      '    KF_DVIPPRODT,'
      '    RPRICE_DVIPPRODT,'
      '    RSUM_DVIPPRODT'
      ')'
      'VALUES('
      '    :ID_DVIPPRODT,'
      '    :IDDOC_DVIPPRODT,'
      '    :IDBASE_DVIPPRODT,'
      '    :IDNOM_DVIPPRODT,'
      '    :IDED_DVIPPRODT,'
      '    :IDPART_DVIPPRODT,'
      '    :KOL_DVIPPRODT,'
      '    :KF_DVIPPRODT,'
      '    :RPRICE_DVIPPRODT,'
      '    :RSUM_DVIPPRODT'
      ')')
    RefreshSQL.Strings = (
      'select DVIPPRODT.*, NAMENOM, NAMEED ,TNOM'
      'from '
      'DVIPPRODT LEFT OUTER JOIN SNOM  ON IDNOM_DVIPPRODT=IDNOM '
      'left outer join SED  on  IDED_DVIPPRODT=IDED'
      'where(  IDDOC_DVIPPRODT=:ID'
      '     ) and (     DVIPPRODT.ID_DVIPPRODT = :OLD_ID_DVIPPRODT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select DVIPPRODT.*, NAMENOM, NAMEED ,TNOM'
      'from '
      'DVIPPRODT LEFT OUTER JOIN SNOM  ON IDNOM_DVIPPRODT=IDNOM '
      'left outer join SED  on  IDED_DVIPPRODT=IDED'
      'where IDDOC_DVIPPRODT=:ID')
    AutoUpdateOptions.UpdateTableName = 'DVIPPRODT'
    AutoUpdateOptions.KeyFields = 'ID_DVIPPRODT'
    AutoUpdateOptions.GeneratorName = 'GEN_DVIPPRODT_ID'
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
    object DocTRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object DocTID_DVIPPRODT: TFIBLargeIntField
      FieldName = 'ID_DVIPPRODT'
    end
    object DocTIDDOC_DVIPPRODT: TFIBLargeIntField
      FieldName = 'IDDOC_DVIPPRODT'
    end
    object DocTIDBASE_DVIPPRODT: TFIBLargeIntField
      FieldName = 'IDBASE_DVIPPRODT'
    end
    object DocTIDNOM_DVIPPRODT: TFIBLargeIntField
      FieldName = 'IDNOM_DVIPPRODT'
    end
    object DocTIDED_DVIPPRODT: TFIBLargeIntField
      FieldName = 'IDED_DVIPPRODT'
    end
    object DocTIDPART_DVIPPRODT: TFIBLargeIntField
      FieldName = 'IDPART_DVIPPRODT'
    end
    object DocTKOL_DVIPPRODT: TFIBBCDField
      FieldName = 'KOL_DVIPPRODT'
      OnChange = DocTKOL_DVIPPRODTChange
      Size = 3
      RoundByScale = True
    end
    object DocTKF_DVIPPRODT: TFIBBCDField
      FieldName = 'KF_DVIPPRODT'
      Size = 3
      RoundByScale = True
    end
    object DocTRPRICE_DVIPPRODT: TFIBBCDField
      FieldName = 'RPRICE_DVIPPRODT'
      OnChange = DocTRPRICE_DVIPPRODTChange
      Size = 2
      RoundByScale = True
    end
    object DocTRSUM_DVIPPRODT: TFIBBCDField
      FieldName = 'RSUM_DVIPPRODT'
      Size = 2
      RoundByScale = True
    end
    object DocTNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object DocTNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 200
    end
    object DocTTNOM: TFIBIntegerField
      FieldName = 'TNOM'
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
      
        'from DOC_VIPPROD_GET_NUM_NEW_DOC (:PARAM_IDBASE,:PARAM_IDFIRM,:P' +
        'ARAM_IDSKLAD)')
    Left = 296
    Top = 16
  end
  object pFIBQ: TpFIBQuery
    Left = 336
    Top = 176
    qoStartTransaction = True
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_VIPPROD_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 304
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_VIPPROD_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 240
    qoStartTransaction = True
  end
end
