object DMDocZamena: TDMDocZamena
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
      'UPDATE DZAMENA'
      'SET '
      '    IDBASE_DZAMENA = :IDBASE_DZAMENA,'
      '    IDDOC_DZAMENA = :IDDOC_DZAMENA,'
      '    OPER_DZAMENA = :OPER_DZAMENA,'
      '    DESCR_DZAMENA = :DESCR_DZAMENA,'
      '    IDRTPRICE_DZAMENA = :IDRTPRICE_DZAMENA,'
      '    S_RSUM_DZAMENA = :S_RSUM_DZAMENA,'
      '    P_RSUM_DZAMENA = :P_RSUM_DZAMENA'
      'WHERE'
      '    ID_DZAMENA = :OLD_ID_DZAMENA'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DZAMENA'
      'WHERE'
      '        ID_DZAMENA = :OLD_ID_DZAMENA'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DZAMENA('
      '    ID_DZAMENA,'
      '    IDBASE_DZAMENA,'
      '    IDDOC_DZAMENA,'
      '    OPER_DZAMENA,'
      '    DESCR_DZAMENA,'
      '    IDRTPRICE_DZAMENA,'
      '    S_RSUM_DZAMENA,'
      '    P_RSUM_DZAMENA'
      ')'
      'VALUES('
      '    :ID_DZAMENA,'
      '    :IDBASE_DZAMENA,'
      '    :IDDOC_DZAMENA,'
      '    :OPER_DZAMENA,'
      '    :DESCR_DZAMENA,'
      '    :IDRTPRICE_DZAMENA,'
      '    :S_RSUM_DZAMENA,'
      '    :P_RSUM_DZAMENA'
      ')')
    RefreshSQL.Strings = (
      'select dzamena.*'
      'from  dzamena'
      'where(  dzamena.iddoc_dzamena=:PARAM_IDDOC'
      '     ) and (     DZAMENA.ID_DZAMENA = :OLD_ID_DZAMENA'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select dzamena.*'
      'from  dzamena'
      'where dzamena.iddoc_dzamena=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'DZAMENA'
    AutoUpdateOptions.KeyFields = 'ID_DZAMENA'
    AutoUpdateOptions.GeneratorName = 'GEN_DZAMENA_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = DocNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object DocID_DZAMENA: TFIBLargeIntField
      FieldName = 'ID_DZAMENA'
    end
    object DocIDBASE_DZAMENA: TFIBLargeIntField
      FieldName = 'IDBASE_DZAMENA'
    end
    object DocIDDOC_DZAMENA: TFIBLargeIntField
      FieldName = 'IDDOC_DZAMENA'
    end
    object DocOPER_DZAMENA: TFIBIntegerField
      FieldName = 'OPER_DZAMENA'
    end
    object DocDESCR_DZAMENA: TFIBWideStringField
      FieldName = 'DESCR_DZAMENA'
      Size = 150
    end
    object DocIDRTPRICE_DZAMENA: TFIBLargeIntField
      FieldName = 'IDRTPRICE_DZAMENA'
    end
    object DocS_RSUM_DZAMENA: TFIBBCDField
      FieldName = 'S_RSUM_DZAMENA'
      Size = 2
      RoundByScale = True
    end
    object DocP_RSUM_DZAMENA: TFIBBCDField
      FieldName = 'P_RSUM_DZAMENA'
      Size = 2
      RoundByScale = True
    end
  end
  object DocT: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE DZAMENAT'
      'SET '
      '    IDBASE_DZAMENAT = :IDBASE_DZAMENAT,'
      '    IDDOC_DZAMENAT = :IDDOC_DZAMENAT,'
      '    S_IDNOM_DZAMENAT = :S_IDNOM_DZAMENAT,'
      '    S_IDED_DZAMENAT = :S_IDED_DZAMENAT,'
      '    S_KF_DZAMENAT = :S_KF_DZAMENAT,'
      '    S_KOL_DZAMENAT = :S_KOL_DZAMENAT,'
      '    S_RPRICE_DZAMENAT = :S_RPRICE_DZAMENAT,'
      '    S_RSUM_DZAMENAT = :S_RSUM_DZAMENAT,'
      '    P_IDNOM_DZAMENAT = :P_IDNOM_DZAMENAT,'
      '    P_IDED_DZAMENAT = :P_IDED_DZAMENAT,'
      '    P_IDPART_DZAMENAT = :P_IDPART_DZAMENAT,'
      '    P_KF_DZAMENAT = :P_KF_DZAMENAT,'
      '    P_KOL_DZAMENAT = :P_KOL_DZAMENAT,'
      '    P_RPRICE_DZAMENAT = :P_RPRICE_DZAMENAT,'
      '    P_RSUM_DZAMENAT = :P_RSUM_DZAMENAT'
      'WHERE'
      '    ID_DZAMENAT = :OLD_ID_DZAMENAT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    DZAMENAT'
      'WHERE'
      '        ID_DZAMENAT = :OLD_ID_DZAMENAT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO DZAMENAT('
      '    ID_DZAMENAT,'
      '    IDBASE_DZAMENAT,'
      '    IDDOC_DZAMENAT,'
      '    S_IDNOM_DZAMENAT,'
      '    S_IDED_DZAMENAT,'
      '    S_KF_DZAMENAT,'
      '    S_KOL_DZAMENAT,'
      '    S_RPRICE_DZAMENAT,'
      '    S_RSUM_DZAMENAT,'
      '    P_IDNOM_DZAMENAT,'
      '    P_IDED_DZAMENAT,'
      '    P_IDPART_DZAMENAT,'
      '    P_KF_DZAMENAT,'
      '    P_KOL_DZAMENAT,'
      '    P_RPRICE_DZAMENAT,'
      '    P_RSUM_DZAMENAT'
      ')'
      'VALUES('
      '    :ID_DZAMENAT,'
      '    :IDBASE_DZAMENAT,'
      '    :IDDOC_DZAMENAT,'
      '    :S_IDNOM_DZAMENAT,'
      '    :S_IDED_DZAMENAT,'
      '    :S_KF_DZAMENAT,'
      '    :S_KOL_DZAMENAT,'
      '    :S_RPRICE_DZAMENAT,'
      '    :S_RSUM_DZAMENAT,'
      '    :P_IDNOM_DZAMENAT,'
      '    :P_IDED_DZAMENAT,'
      '    :P_IDPART_DZAMENAT,'
      '    :P_KF_DZAMENAT,'
      '    :P_KOL_DZAMENAT,'
      '    :P_RPRICE_DZAMENAT,'
      '    :P_RSUM_DZAMENAT'
      ')')
    RefreshSQL.Strings = (
      'select dzamenat.*,'
      '        S_NOM.namenom,'
      '        S_ED.nameed,'
      '        P_NOM.namenom,'
      '        P_ED.nameed'
      'from  dzamenat'
      
        '    left outer join snom as S_NOM on S_NOM.idnom=dzamenat.s_idno' +
        'm_dzamenat'
      
        '    left outer join sed as S_ED on S_ED.ided=dzamenat.s_ided_dza' +
        'menat'
      
        '    left outer join snom as P_NOM on P_NOM.idnom=dzamenat.p_idno' +
        'm_dzamenat'
      
        '    left outer join sed as P_ED on P_ED.ided=dzamenat.p_ided_dza' +
        'menat'
      'where(  dzamenat.iddoc_dzamenat=:PARAM_IDDOC'
      '     ) and (     DZAMENAT.ID_DZAMENAT = :OLD_ID_DZAMENAT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select dzamenat.*,'
      '        S_NOM.namenom as S_NAMENOM,'
      '        S_ED.nameed as S_NAMEED,'
      '        P_NOM.namenom as P_NAMENOM,'
      '        P_ED.nameed as P_NAMEED'
      'from  dzamenat'
      
        '    left outer join snom as S_NOM on S_NOM.idnom=dzamenat.s_idno' +
        'm_dzamenat'
      
        '    left outer join sed as S_ED on S_ED.ided=dzamenat.s_ided_dza' +
        'menat'
      
        '    left outer join snom as P_NOM on P_NOM.idnom=dzamenat.p_idno' +
        'm_dzamenat'
      
        '    left outer join sed as P_ED on P_ED.ided=dzamenat.p_ided_dza' +
        'menat'
      'where dzamenat.iddoc_dzamenat=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'DZAMENAT'
    AutoUpdateOptions.KeyFields = 'ID_DZAMENAT'
    AutoUpdateOptions.GeneratorName = 'GEN_DZAMENAT_ID'
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
    object DocTID_DZAMENAT: TFIBLargeIntField
      FieldName = 'ID_DZAMENAT'
    end
    object DocTIDBASE_DZAMENAT: TFIBLargeIntField
      FieldName = 'IDBASE_DZAMENAT'
    end
    object DocTIDDOC_DZAMENAT: TFIBLargeIntField
      FieldName = 'IDDOC_DZAMENAT'
    end
    object DocTS_IDNOM_DZAMENAT: TFIBLargeIntField
      FieldName = 'S_IDNOM_DZAMENAT'
    end
    object DocTS_IDED_DZAMENAT: TFIBLargeIntField
      FieldName = 'S_IDED_DZAMENAT'
    end
    object DocTS_KF_DZAMENAT: TFIBBCDField
      FieldName = 'S_KF_DZAMENAT'
      Size = 3
      RoundByScale = True
    end
    object DocTS_KOL_DZAMENAT: TFIBBCDField
      FieldName = 'S_KOL_DZAMENAT'
      OnChange = DocTS_KOL_DZAMENATChange
      Size = 3
      RoundByScale = True
    end
    object DocTS_RPRICE_DZAMENAT: TFIBBCDField
      FieldName = 'S_RPRICE_DZAMENAT'
      OnChange = DocTS_RPRICE_DZAMENATChange
      Size = 2
      RoundByScale = True
    end
    object DocTS_RSUM_DZAMENAT: TFIBBCDField
      FieldName = 'S_RSUM_DZAMENAT'
      Size = 2
      RoundByScale = True
    end
    object DocTP_IDNOM_DZAMENAT: TFIBLargeIntField
      FieldName = 'P_IDNOM_DZAMENAT'
    end
    object DocTP_IDED_DZAMENAT: TFIBLargeIntField
      FieldName = 'P_IDED_DZAMENAT'
    end
    object DocTP_IDPART_DZAMENAT: TFIBLargeIntField
      FieldName = 'P_IDPART_DZAMENAT'
    end
    object DocTP_KF_DZAMENAT: TFIBBCDField
      FieldName = 'P_KF_DZAMENAT'
      Size = 3
      RoundByScale = True
    end
    object DocTP_KOL_DZAMENAT: TFIBBCDField
      FieldName = 'P_KOL_DZAMENAT'
      OnChange = DocTP_KOL_DZAMENATChange
      Size = 3
      RoundByScale = True
    end
    object DocTP_RPRICE_DZAMENAT: TFIBBCDField
      FieldName = 'P_RPRICE_DZAMENAT'
      OnChange = DocTP_RPRICE_DZAMENATChange
      Size = 2
      RoundByScale = True
    end
    object DocTP_RSUM_DZAMENAT: TFIBBCDField
      FieldName = 'P_RSUM_DZAMENAT'
      Size = 2
      RoundByScale = True
    end
    object DocTS_NAMENOM: TFIBWideStringField
      FieldName = 'S_NAMENOM'
      Size = 200
    end
    object DocTS_NAMEED: TFIBWideStringField
      FieldName = 'S_NAMEED'
      Size = 200
    end
    object DocTP_NAMENOM: TFIBWideStringField
      FieldName = 'P_NAMENOM'
      Size = 200
    end
    object DocTP_NAMEED: TFIBWideStringField
      FieldName = 'P_NAMEED'
      Size = 200
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
      
        'from DOC_ZAMENA_GET_NUM_NEW_DOC (:PARAM_IDBASE,:PARAM_IDFIRM,:PA' +
        'RAM_IDSKLAD)')
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
      'EXECUTE PROCEDURE DOC_ZAMENA_CANCEL_DVREG(:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 304
    qoStartTransaction = True
  end
  object QueryDvReg: TpFIBQuery
    Transaction = IBTrDvReg
    SQL.Strings = (
      'EXECUTE PROCEDURE DOC_ZAMENA_DVREG (:PARAM_IDDOC,0,0,0)')
    Left = 96
    Top = 240
    qoStartTransaction = True
  end
end
