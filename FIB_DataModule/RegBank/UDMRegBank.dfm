object DMRegBank: TDMRegBank
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 274
  Width = 217
  object DvRegOst: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE RGBANK_DV'
      'SET '
      '    POSDOC_RGBANK_DV = :POSDOC_RGBANK_DV,'
      '    IDDOC_RGBANK_DV = :IDDOC_RGBANK_DV,'
      '    TDV_RGBANK_DV = :TDV_RGBANK_DV,'
      '    IDFIRM_RGBANK_DV = :IDFIRM_RGBANK_DV,'
      '    IDBSCHET_RGBANK_DV = :IDBSCHET_RGBANK_DV,'
      '    SUM_RGBANK_DV = :SUM_RGBANK_DV,'
      '    OPER_RGBANK_DV = :OPER_RGBANK_DV'
      'WHERE'
      '    ID_RGBANK_DV = :OLD_ID_RGBANK_DV'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    RGBANK_DV'
      'WHERE'
      '        ID_RGBANK_DV = :OLD_ID_RGBANK_DV'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO RGBANK_DV('
      '    ID_RGBANK_DV,'
      '    POSDOC_RGBANK_DV,'
      '    IDDOC_RGBANK_DV,'
      '    TDV_RGBANK_DV,'
      '    IDFIRM_RGBANK_DV,'
      '    IDBSCHET_RGBANK_DV,'
      '    SUM_RGBANK_DV,'
      '    OPER_RGBANK_DV'
      ')'
      'VALUES('
      '    :ID_RGBANK_DV,'
      '    :POSDOC_RGBANK_DV,'
      '    :IDDOC_RGBANK_DV,'
      '    :TDV_RGBANK_DV,'
      '    :IDFIRM_RGBANK_DV,'
      '    :IDBSCHET_RGBANK_DV,'
      '    :SUM_RGBANK_DV,'
      '    :OPER_RGBANK_DV'
      ')')
    RefreshSQL.Strings = (
      'select * from  RGBANK_DV'
      'where(  IDDOC_RGBANK_DV=:PARAM_IDDOC'
      '     ) and (     RGBANK_DV.ID_RGBANK_DV = :OLD_ID_RGBANK_DV'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from  RGBANK_DV'
      'where IDDOC_RGBANK_DV=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'RGBANK_DV'
    AutoUpdateOptions.KeyFields = 'ID_RGBANK_DV'
    AutoUpdateOptions.GeneratorName = 'GEN_RGBANK_DV_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTrUpdate
    Left = 40
    Top = 24
    object DvRegOstPOSDOC_RGBANK_DV: TFIBDateTimeField
      FieldName = 'POSDOC_RGBANK_DV'
    end
    object DvRegOstTDV_RGBANK_DV: TFIBSmallIntField
      FieldName = 'TDV_RGBANK_DV'
    end
    object DvRegOstSUM_RGBANK_DV: TFIBBCDField
      FieldName = 'SUM_RGBANK_DV'
      Size = 2
      RoundByScale = True
    end
    object DvRegOstOPER_RGBANK_DV: TFIBIntegerField
      FieldName = 'OPER_RGBANK_DV'
    end
    object DvRegOstID_RGBANK_DV: TFIBBCDField
      FieldName = 'ID_RGBANK_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDDOC_RGBANK_DV: TFIBBCDField
      FieldName = 'IDDOC_RGBANK_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDFIRM_RGBANK_DV: TFIBBCDField
      FieldName = 'IDFIRM_RGBANK_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDBSCHET_RGBANK_DV: TFIBBCDField
      FieldName = 'IDBSCHET_RGBANK_DV'
      Size = 0
      RoundByScale = True
    end
  end
  object RegOst: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE RGBANK'
      'SET '
      '    IDFIRM_RGBANK = :IDFIRM_RGBANK,'
      '    IDBSCHET_RGBANK = :IDBSCHET_RGBANK,'
      '    SUM_RGBANK = :SUM_RGBANK'
      'WHERE'
      '    ID_RGBANK = :OLD_ID_RGBANK'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    RGBANK'
      'WHERE'
      '        ID_RGBANK = :OLD_ID_RGBANK'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO RGBANK('
      '    ID_RGBANK,'
      '    IDFIRM_RGBANK,'
      '    IDBSCHET_RGBANK,'
      '    SUM_RGBANK'
      ')'
      'VALUES('
      '    :ID_RGBANK,'
      '    :IDFIRM_RGBANK,'
      '    :IDBSCHET_RGBANK,'
      '    :SUM_RGBANK'
      ')')
    RefreshSQL.Strings = (
      'select * from RGBANK'
      'where( '
      'IDFIRM_RGBANK=:PARAM_IDFIRM  and'
      'IDBSCHET_RGBANK=:PARAM_IDBSCHET'
      '     ) and (     RGBANK.ID_RGBANK = :OLD_ID_RGBANK'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from RGBANK'
      'where'
      'IDFIRM_RGBANK=:PARAM_IDFIRM  and'
      'IDBSCHET_RGBANK=:PARAM_IDBSCHET')
    AutoUpdateOptions.UpdateTableName = 'RGBANK'
    AutoUpdateOptions.KeyFields = 'ID_RGBANK'
    AutoUpdateOptions.GeneratorName = 'GEN_RGBANK_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTrUpdate
    Left = 40
    Top = 88
    object RegOstSUM_RGBANK: TFIBBCDField
      FieldName = 'SUM_RGBANK'
      Size = 2
      RoundByScale = True
    end
    object RegOstID_RGBANK: TFIBBCDField
      FieldName = 'ID_RGBANK'
      Size = 0
      RoundByScale = True
    end
    object RegOstIDFIRM_RGBANK: TFIBBCDField
      FieldName = 'IDFIRM_RGBANK'
      Size = 0
      RoundByScale = True
    end
    object RegOstIDBSCHET_RGBANK: TFIBBCDField
      FieldName = 'IDBSCHET_RGBANK'
      Size = 0
      RoundByScale = True
    end
  end
  object Dv: TpFIBDataSet
    SelectSQL.Strings = (
      'select SUM(SUM_RGBANK_DV) AS SUMDV'
      'from RGBANK_DV'
      ' where '
      'POSDOC_RGBANK_DV > :PARAM_POS and'
      'IDFIRM_RGBANK_DV=:PARAM_IDFIRM  and'
      'IDBSCHET_RGBANK_DV=:PARAM_IDBSCHET   and'
      'TDV_RGBANK_DV = :PARAM_TDV'
      'group by IDBSCHET_RGBANK_DV')
    Transaction = IBTr
    Left = 40
    Top = 152
    object DvSUMDV: TFIBBCDField
      FieldName = 'SUMDV'
      Size = 2
      RoundByScale = True
    end
  end
  object Ostatok: TpFIBDataSet
    SelectSQL.Strings = (
      'select SUM(SUM_RGBANK) AS SUMOST'
      'from RGBANK'
      ' where'
      'IDFIRM_RGBANK=:PARAM_IDFIRM   and'
      ' IDBSCHET_RGBANK=:PARAM_IDBSCHET '
      'group by IDBSCHET_RGBANK')
    Transaction = IBTr
    Left = 40
    Top = 208
    object OstatokSUMOST: TFIBBCDField
      FieldName = 'SUMOST'
      Size = 2
      RoundByScale = True
    end
  end
  object IBTrUpdate: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 136
    Top = 24
  end
  object IBTr: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 136
    Top = 88
  end
end
