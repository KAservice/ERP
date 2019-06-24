object DMRegKassa: TDMRegKassa
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 238
  Width = 274
  object DvRegOst: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE RGKASSA_DV'
      'SET '
      '    POSDOC_RGKASSA_DV = :POSDOC_RGKASSA_DV,'
      '    IDDOC_RGKASSA_DV = :IDDOC_RGKASSA_DV,'
      '    TDV_RGKASSA_DV = :TDV_RGKASSA_DV,'
      '    IDFIRM_RGKASSA_DV = :IDFIRM_RGKASSA_DV,'
      '    IDKKM_RGKASSA_DV = :IDKKM_RGKASSA_DV,'
      '    SUM_RGKASSA_DV = :SUM_RGKASSA_DV,'
      '    OPER_RGKASSA_DV = :OPER_RGKASSA_DV'
      'WHERE'
      '    ID_RGKASSA_DV = :OLD_ID_RGKASSA_DV'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    RGKASSA_DV'
      'WHERE'
      '        ID_RGKASSA_DV = :OLD_ID_RGKASSA_DV'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO RGKASSA_DV('
      '    ID_RGKASSA_DV,'
      '    POSDOC_RGKASSA_DV,'
      '    IDDOC_RGKASSA_DV,'
      '    TDV_RGKASSA_DV,'
      '    IDFIRM_RGKASSA_DV,'
      '    IDKKM_RGKASSA_DV,'
      '    SUM_RGKASSA_DV,'
      '    OPER_RGKASSA_DV'
      ')'
      'VALUES('
      '    :ID_RGKASSA_DV,'
      '    :POSDOC_RGKASSA_DV,'
      '    :IDDOC_RGKASSA_DV,'
      '    :TDV_RGKASSA_DV,'
      '    :IDFIRM_RGKASSA_DV,'
      '    :IDKKM_RGKASSA_DV,'
      '    :SUM_RGKASSA_DV,'
      '    :OPER_RGKASSA_DV'
      ')')
    RefreshSQL.Strings = (
      'select * from  RGKASSA_DV'
      'where(  IDDOC_RGKASSA_DV=:PARAM_IDDOC'
      '     ) and (     RGKASSA_DV.ID_RGKASSA_DV = :OLD_ID_RGKASSA_DV'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from  RGKASSA_DV'
      'where IDDOC_RGKASSA_DV=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'RGKASSA_DV'
    AutoUpdateOptions.KeyFields = 'ID_RGKASSA_DV'
    AutoUpdateOptions.GeneratorName = 'GEN_RGKASSA_DV_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTrUpdate
    Left = 32
    Top = 16
    object DvRegOstPOSDOC_RGKASSA_DV: TFIBDateTimeField
      FieldName = 'POSDOC_RGKASSA_DV'
    end
    object DvRegOstTDV_RGKASSA_DV: TFIBSmallIntField
      FieldName = 'TDV_RGKASSA_DV'
    end
    object DvRegOstSUM_RGKASSA_DV: TFIBBCDField
      FieldName = 'SUM_RGKASSA_DV'
      Size = 2
      RoundByScale = True
    end
    object DvRegOstOPER_RGKASSA_DV: TFIBIntegerField
      FieldName = 'OPER_RGKASSA_DV'
    end
    object DvRegOstID_RGKASSA_DV: TFIBBCDField
      FieldName = 'ID_RGKASSA_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDDOC_RGKASSA_DV: TFIBBCDField
      FieldName = 'IDDOC_RGKASSA_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDFIRM_RGKASSA_DV: TFIBBCDField
      FieldName = 'IDFIRM_RGKASSA_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDKKM_RGKASSA_DV: TFIBBCDField
      FieldName = 'IDKKM_RGKASSA_DV'
      Size = 0
      RoundByScale = True
    end
  end
  object RegOst: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE RGKASSA'
      'SET '
      '    IDFIRM_RGKASSA = :IDFIRM_RGKASSA,'
      '    IDKKM_RGKASSA = :IDKKM_RGKASSA,'
      '    SUM_RGKASSA = :SUM_RGKASSA'
      'WHERE'
      '    ID_RGKASSA = :OLD_ID_RGKASSA'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    RGKASSA'
      'WHERE'
      '        ID_RGKASSA = :OLD_ID_RGKASSA'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO RGKASSA('
      '    ID_RGKASSA,'
      '    IDFIRM_RGKASSA,'
      '    IDKKM_RGKASSA,'
      '    SUM_RGKASSA'
      ')'
      'VALUES('
      '    :ID_RGKASSA,'
      '    :IDFIRM_RGKASSA,'
      '    :IDKKM_RGKASSA,'
      '    :SUM_RGKASSA'
      ')')
    RefreshSQL.Strings = (
      'select * from RGKASSA'
      'where( '
      'IDFIRM_RGKASSA=:PARAM_IDFIRM  and'
      'IDKKM_RGKASSA=:PARAM_IDKKM'
      '     ) and (     RGKASSA.ID_RGKASSA = :OLD_ID_RGKASSA'
      '     )'
      '     ')
    SelectSQL.Strings = (
      'select * from RGKASSA'
      'where'
      'IDFIRM_RGKASSA=:PARAM_IDFIRM  and'
      'IDKKM_RGKASSA=:PARAM_IDKKM ')
    AutoUpdateOptions.UpdateTableName = 'RGKASSA'
    AutoUpdateOptions.KeyFields = 'ID_RGKASSA'
    AutoUpdateOptions.GeneratorName = 'GEN_RGKASSA_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTrUpdate
    Left = 32
    Top = 72
    object RegOstSUM_RGKASSA: TFIBBCDField
      FieldName = 'SUM_RGKASSA'
      Size = 2
      RoundByScale = True
    end
    object RegOstID_RGKASSA: TFIBBCDField
      FieldName = 'ID_RGKASSA'
      Size = 0
      RoundByScale = True
    end
    object RegOstIDFIRM_RGKASSA: TFIBBCDField
      FieldName = 'IDFIRM_RGKASSA'
      Size = 0
      RoundByScale = True
    end
    object RegOstIDKKM_RGKASSA: TFIBBCDField
      FieldName = 'IDKKM_RGKASSA'
      Size = 0
      RoundByScale = True
    end
  end
  object Dv: TpFIBDataSet
    SelectSQL.Strings = (
      'select SUM(SUM_RGKASSA_DV) AS SUMDV'
      'from RGKASSA_DV'
      ' where '
      'POSDOC_RGKASSA_DV > :PARAM_POS and'
      'IDFIRM_RGKASSA_DV=:PARAM_IDFIRM  and'
      'IDKKM_RGKASSA_DV=:PARAM_IDKASSA   and'
      'TDV_RGKASSA_DV = :PARAM_TDV'
      'group by IDKKM_RGKASSA_DV')
    Transaction = IBTr
    Left = 32
    Top = 128
    object DvSUMDV: TFIBBCDField
      FieldName = 'SUMDV'
      Size = 2
      RoundByScale = True
    end
  end
  object Ostatok: TpFIBDataSet
    SelectSQL.Strings = (
      'select  SUM(SUM_RGKASSA)  AS SUMOST'
      'from RGKASSA'
      ' where'
      'IDFIRM_RGKASSA=:PARAM_IDFIRM and'
      'IDKKM_RGKASSA=:PARAM_IDKASSA  '
      ''
      'group by IDKKM_RGKASSA')
    Transaction = IBTr
    Left = 32
    Top = 176
    object OstatokSUMOST: TFIBBCDField
      FieldName = 'SUMOST'
      Size = 2
      RoundByScale = True
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
    Left = 136
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
    Left = 136
    Top = 72
  end
end
