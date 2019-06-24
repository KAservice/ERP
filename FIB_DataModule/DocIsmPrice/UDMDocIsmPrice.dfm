object DMDocIsmPrice: TDMDocIsmPrice
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 451
  Width = 653
  object DataSourceDoc: TDataSource
    DataSet = Doc
    Left = 72
    Top = 72
  end
  object DataSourceDocT: TDataSource
    DataSet = DocT
    Left = 72
    Top = 120
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
      
        'select GALLDOC. *, NAME_SINFBASE_OBMEN, NAMEFIRM, NAMESKLAD, NAM' +
        'EKLIENT, FNAME_USER,'
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from GALLDOC'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN= IDBASE_GALL' +
        'DOC'
      'left outer join SFIRM on IDFIRM=IDFIRMDOC'
      'left outer join SSKLAD on IDSKLAD=IDSKLDOC'
      'left outer join SKLIENT on IDKLIENT=IDKLDOC'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      
        'left outer join SPROJECT on galldoc.idproject_galldoc=sproject.i' +
        'd_sproject'
      
        'left outer join sbusiness_oper on galldoc.idbusinop_galldoc=sbus' +
        'iness_oper.id_sbusiness_oper'
      'where(  IDDOC=:ID'
      '     ) and (     GALLDOC.IDDOC = :OLD_IDDOC'
      '     )'
      '     ')
    SelectSQL.Strings = (
      
        'select GALLDOC. *, NAME_SINFBASE_OBMEN, NAMEFIRM, NAMESKLAD, NAM' +
        'EKLIENT, FNAME_USER,'
      ' sproject.name_sproject,'
      ' sbusiness_oper.name_sbusiness_oper'
      'from GALLDOC'
      
        'left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN= IDBASE_GALL' +
        'DOC'
      'left outer join SFIRM on IDFIRM=IDFIRMDOC'
      'left outer join SSKLAD on IDSKLAD=IDSKLDOC'
      'left outer join SKLIENT on IDKLIENT=IDKLDOC'
      'left outer join SUSER on IDUSERDOC=ID_USER'
      
        'left outer join SPROJECT on galldoc.idproject_galldoc=sproject.i' +
        'd_sproject'
      
        'left outer join sbusiness_oper on galldoc.idbusinop_galldoc=sbus' +
        'iness_oper.id_sbusiness_oper'
      'where IDDOC=:ID ')
    AutoUpdateOptions.UpdateTableName = 'GALLDOC'
    AutoUpdateOptions.KeyFields = 'IDDOC'
    AutoUpdateOptions.GeneratorName = 'GEN_GALLDOC_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 16
    poUseLargeIntField = True
    object DocAllIDDOC: TFIBLargeIntField
      FieldName = 'IDDOC'
    end
    object DocAllPOSDOC: TFIBDateTimeField
      FieldName = 'POSDOC'
      OnChange = DocAllPOSDOCChange
      DisplayFormat = 'c'
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
    object DocAllNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 200
    end
    object DocAllFNAME_USER: TFIBWideStringField
      FieldName = 'FNAME_USER'
      Size = 200
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
      'UPDATE DISMPRICE'
      'SET '
      '    GID_DISMPRICE = :GID_DISMPRICE,'
      '    IDDOC_DISMPRICE = :IDDOC_DISMPRICE,'
      '    DESCR_DISMPRICE = :DESCR_DISMPRICE,'
      '    IDNEWTPRICE_DISMPRICE = :IDNEWTPRICE_DISMPRICE,'
      '    IDOLDTPRICE_DISMPRICE = :IDOLDTPRICE_DISMPRICE,'
      '    IDBASE_DISMPRICE = :IDBASE_DISMPRICE,'
      '    OPER_DISMPRICE = :OPER_DISMPRICE,'
      '    IDINV_DISMPRICE = :IDINV_DISMPRICE'
      'WHERE'
      '    ID_DISMPRICE = :OLD_ID_DISMPRICE'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DISMPRICE'
      'WHERE'
      '        ID_DISMPRICE = :OLD_ID_DISMPRICE'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DISMPRICE('
      '    ID_DISMPRICE,'
      '    GID_DISMPRICE,'
      '    IDDOC_DISMPRICE,'
      '    DESCR_DISMPRICE,'
      '    IDNEWTPRICE_DISMPRICE,'
      '    IDOLDTPRICE_DISMPRICE,'
      '    IDBASE_DISMPRICE,'
      '    OPER_DISMPRICE,'
      '    IDINV_DISMPRICE'
      ')'
      'VALUES('
      '    :ID_DISMPRICE,'
      '    :GID_DISMPRICE,'
      '    :IDDOC_DISMPRICE,'
      '    :DESCR_DISMPRICE,'
      '    :IDNEWTPRICE_DISMPRICE,'
      '    :IDOLDTPRICE_DISMPRICE,'
      '    :IDBASE_DISMPRICE,'
      '    :OPER_DISMPRICE,'
      '    :IDINV_DISMPRICE'
      ')')
    RefreshSQL.Strings = (
      'select DISMPRICE.*, NAME_SINV '
      'from  DISMPRICE'
      'left outer join sinv on sinv.id_sinv=dismprice.idinv_dismprice'
      'where(  IDDOC_DISMPRICE=:ID'
      '     ) and (     DISMPRICE.ID_DISMPRICE = :OLD_ID_DISMPRICE'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select DISMPRICE.*, NAME_SINV '
      'from  DISMPRICE'
      'left outer join sinv on sinv.id_sinv=dismprice.idinv_dismprice'
      'where IDDOC_DISMPRICE=:ID')
    AutoUpdateOptions.UpdateTableName = 'DISMPRICE'
    AutoUpdateOptions.KeyFields = 'ID_DISMPRICE'
    AutoUpdateOptions.GeneratorName = 'GEN_DISMPRICE_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 72
    poUseLargeIntField = True
    object DocID_DISMPRICE: TFIBLargeIntField
      FieldName = 'ID_DISMPRICE'
    end
    object DocGID_DISMPRICE: TFIBWideStringField
      FieldName = 'GID_DISMPRICE'
      Size = 10
    end
    object DocIDDOC_DISMPRICE: TFIBLargeIntField
      FieldName = 'IDDOC_DISMPRICE'
    end
    object DocDESCR_DISMPRICE: TFIBWideStringField
      FieldName = 'DESCR_DISMPRICE'
      Size = 150
    end
    object DocIDNEWTPRICE_DISMPRICE: TFIBLargeIntField
      FieldName = 'IDNEWTPRICE_DISMPRICE'
    end
    object DocIDBASE_DISMPRICE: TFIBLargeIntField
      FieldName = 'IDBASE_DISMPRICE'
    end
    object DocOPER_DISMPRICE: TFIBIntegerField
      FieldName = 'OPER_DISMPRICE'
    end
    object DocIDINV_DISMPRICE: TFIBLargeIntField
      FieldName = 'IDINV_DISMPRICE'
    end
    object DocNAME_SINV: TFIBWideStringField
      FieldName = 'NAME_SINV'
      Size = 100
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DISMPRICET'
      'SET '
      '    GID_DISMPRICET = :GID_DISMPRICET,'
      '    IDDOC_DISMPRICET = :IDDOC_DISMPRICET,'
      '    IDNOM_DISMPRICET = :IDNOM_DISMPRICET,'
      '    IDED_DISMPRICET = :IDED_DISMPRICET,'
      '    KOL_DISMPRICET = :KOL_DISMPRICET,'
      '    KF_DISMPRICET = :KF_DISMPRICET,'
      '    OLDPRICE_DISMPRICET = :OLDPRICE_DISMPRICET,'
      '    NEWPRICE_DISMPRICET = :NEWPRICE_DISMPRICET,'
      '    IDBASE_DISMPRICET = :IDBASE_DISMPRICET,'
      '    SEB_PRICE_DISMPRICET = :SEB_PRICE_DISMPRICET,'
      '    SEB_SUM_DISMPRICET = :SEB_SUM_DISMPRICET,'
      '    NAC_NEW_DISMPRICET = :NAC_NEW_DISMPRICET,'
      '    NAC_OLD_DISMPRICET = :NAC_OLD_DISMPRICET'
      'WHERE'
      '    ID_DISMPRICET = :OLD_ID_DISMPRICET'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DISMPRICET'
      'WHERE'
      '        ID_DISMPRICET = :OLD_ID_DISMPRICET'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DISMPRICET('
      '    ID_DISMPRICET,'
      '    GID_DISMPRICET,'
      '    IDDOC_DISMPRICET,'
      '    IDNOM_DISMPRICET,'
      '    IDED_DISMPRICET,'
      '    KOL_DISMPRICET,'
      '    KF_DISMPRICET,'
      '    OLDPRICE_DISMPRICET,'
      '    NEWPRICE_DISMPRICET,'
      '    IDBASE_DISMPRICET,'
      '    SEB_PRICE_DISMPRICET,'
      '    SEB_SUM_DISMPRICET,'
      '    NAC_NEW_DISMPRICET,'
      '    NAC_OLD_DISMPRICET'
      ')'
      'VALUES('
      '    :ID_DISMPRICET,'
      '    :GID_DISMPRICET,'
      '    :IDDOC_DISMPRICET,'
      '    :IDNOM_DISMPRICET,'
      '    :IDED_DISMPRICET,'
      '    :KOL_DISMPRICET,'
      '    :KF_DISMPRICET,'
      '    :OLDPRICE_DISMPRICET,'
      '    :NEWPRICE_DISMPRICET,'
      '    :IDBASE_DISMPRICET,'
      '    :SEB_PRICE_DISMPRICET,'
      '    :SEB_SUM_DISMPRICET,'
      '    :NAC_NEW_DISMPRICET,'
      '    :NAC_OLD_DISMPRICET'
      ')')
    RefreshSQL.Strings = (
      'select DISMPRICET.*,'
      '    snom.NAMENOM,'
      '    sed.NAMEED ,'
      '    sed.shed,'
      '    snom.TNOM,'
      '    snom.artnom,'
      '    snom.codenom'
      'from '
      'DISMPRICET '
      'LEFT OUTER JOIN SNOM  ON IDNOM_DISMPRICET=IDNOM '
      'left outer join SED  on  IDED_DISMPRICET=IDED'
      'where(  IDDOC_DISMPRICET=:ID'
      '     ) and (     DISMPRICET.ID_DISMPRICET = :OLD_ID_DISMPRICET'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select DISMPRICET.*,'
      '    snom.NAMENOM,'
      '    sed.NAMEED ,'
      '    sed.shed,'
      '    snom.TNOM,'
      '    snom.artnom,'
      '    snom.codenom'
      'from '
      'DISMPRICET '
      'LEFT OUTER JOIN SNOM  ON IDNOM_DISMPRICET=IDNOM '
      'left outer join SED  on  IDED_DISMPRICET=IDED'
      'where IDDOC_DISMPRICET=:ID')
    AutoUpdateOptions.UpdateTableName = 'DISMPRICET'
    AutoUpdateOptions.KeyFields = 'ID_DISMPRICET'
    AutoUpdateOptions.GeneratorName = 'GEN_DISMPRICET_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnCalcFields = DocTCalcFields
    OnNewRecord = DocTNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 120
    poUseLargeIntField = True
    object DocTRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object DocTOLDSUM: TFloatField
      FieldKind = fkCalculated
      FieldName = 'OLDSUM'
      Calculated = True
    end
    object DocTNEWSUM: TFloatField
      FieldKind = fkCalculated
      FieldName = 'NEWSUM'
      Calculated = True
    end
    object DocTSUMISM: TFloatField
      FieldKind = fkCalculated
      FieldName = 'SUMISM'
      Calculated = True
    end
    object DocTID_DISMPRICET: TFIBLargeIntField
      FieldName = 'ID_DISMPRICET'
    end
    object DocTGID_DISMPRICET: TFIBWideStringField
      FieldName = 'GID_DISMPRICET'
      Size = 10
    end
    object DocTIDDOC_DISMPRICET: TFIBLargeIntField
      FieldName = 'IDDOC_DISMPRICET'
    end
    object DocTIDNOM_DISMPRICET: TFIBLargeIntField
      FieldName = 'IDNOM_DISMPRICET'
    end
    object DocTIDED_DISMPRICET: TFIBLargeIntField
      FieldName = 'IDED_DISMPRICET'
    end
    object DocTKOL_DISMPRICET: TFIBBCDField
      FieldName = 'KOL_DISMPRICET'
      OnChange = DocTKOL_DISMPRICETChange
      Size = 3
      RoundByScale = True
    end
    object DocTKF_DISMPRICET: TFIBBCDField
      FieldName = 'KF_DISMPRICET'
      Size = 3
      RoundByScale = True
    end
    object DocTOLDPRICE_DISMPRICET: TFIBBCDField
      FieldName = 'OLDPRICE_DISMPRICET'
      OnChange = DocTOLDPRICE_DISMPRICETChange
      Size = 2
      RoundByScale = True
    end
    object DocTNEWPRICE_DISMPRICET: TFIBBCDField
      FieldName = 'NEWPRICE_DISMPRICET'
      OnChange = DocTNEWPRICE_DISMPRICETChange
      Size = 2
      RoundByScale = True
    end
    object DocTIDBASE_DISMPRICET: TFIBLargeIntField
      FieldName = 'IDBASE_DISMPRICET'
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
    object DocTSEB_PRICE_DISMPRICET: TFIBBCDField
      FieldName = 'SEB_PRICE_DISMPRICET'
      OnChange = DocTSEB_PRICE_DISMPRICETChange
      Size = 2
      RoundByScale = True
    end
    object DocTSEB_SUM_DISMPRICET: TFIBBCDField
      FieldName = 'SEB_SUM_DISMPRICET'
      OnChange = DocTSEB_SUM_DISMPRICETChange
      Size = 2
      RoundByScale = True
    end
    object DocTNAC_SUM_ED: TFIBBCDField
      FieldKind = fkCalculated
      FieldName = 'NAC_SUM_ED'
      Size = 2
      RoundByScale = True
      Calculated = True
    end
    object DocTNAC_SUM: TFIBBCDField
      FieldKind = fkCalculated
      FieldName = 'NAC_SUM'
      Size = 2
      RoundByScale = True
      Calculated = True
    end
    object DocTNAC_NEW_DISMPRICET: TFIBBCDField
      FieldName = 'NAC_NEW_DISMPRICET'
      Size = 2
      RoundByScale = True
    end
    object DocTNAC_OLD_DISMPRICET: TFIBBCDField
      FieldName = 'NAC_OLD_DISMPRICET'
      Size = 2
      RoundByScale = True
    end
    object DocTSHED: TFIBWideStringField
      FieldName = 'SHED'
      Size = 13
    end
    object DocTARTNOM: TFIBWideStringField
      FieldName = 'ARTNOM'
      Size = 40
    end
    object DocTCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
  end
  object IBTrDvReg: TpFIBTransaction
    TimeoutAction = TARollback
    Left = 360
    Top = 192
  end
  object QueryCancelDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_ISMPRICE_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 192
    Top = 320
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_ISMPRICE_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 192
    Top = 272
    qoStartTransaction = True
  end
  object NumDoc: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      
        'from DOC_ISMPRICE_GET_NUM_NEW_DOC (:PARAM_IDBASE,:PARAM_IDFIRM,:' +
        'PARAM_IDSKLAD)'
      '')
    Transaction = IBTr
    DefaultFormats.DateTimeDisplayFormat = 'c'
    Left = 336
    Top = 16
  end
end
