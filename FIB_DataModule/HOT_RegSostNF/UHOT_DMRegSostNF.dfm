object HOT_DMRegSostNF: THOT_DMRegSostNF
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 238
  Width = 274
  object DvRegOst: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE HOT_RGSOSTNF_DV'
      'SET '
      '    IDDOCH_HOT_RGSOSTNF_DV = :IDDOCH_HOT_RGSOSTNF_DV,'
      '    POS_HOT_RGSOSTNF_DV = :POS_HOT_RGSOSTNF_DV,'
      '    TDV_HOT_RGSOSTNF_DV = :TDV_HOT_RGSOSTNF_DV,'
      '    OPER_HOT_RGSOSTNF_DV = :OPER_HOT_RGSOSTNF_DV,'
      '    IDSOST_HOT_RGSOSTNF_DV = :IDSOST_HOT_RGSOSTNF_DV'
      'WHERE'
      '    ID_HOT_RGSOSTNF_DV = :OLD_ID_HOT_RGSOSTNF_DV'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    HOT_RGSOSTNF_DV'
      'WHERE'
      '        ID_HOT_RGSOSTNF_DV = :OLD_ID_HOT_RGSOSTNF_DV'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO HOT_RGSOSTNF_DV('
      '    ID_HOT_RGSOSTNF_DV,'
      '    IDDOCH_HOT_RGSOSTNF_DV,'
      '    POS_HOT_RGSOSTNF_DV,'
      '    TDV_HOT_RGSOSTNF_DV,'
      '    OPER_HOT_RGSOSTNF_DV,'
      '    IDSOST_HOT_RGSOSTNF_DV'
      ')'
      'VALUES('
      '    :ID_HOT_RGSOSTNF_DV,'
      '    :IDDOCH_HOT_RGSOSTNF_DV,'
      '    :POS_HOT_RGSOSTNF_DV,'
      '    :TDV_HOT_RGSOSTNF_DV,'
      '    :OPER_HOT_RGSOSTNF_DV,'
      '    :IDSOST_HOT_RGSOSTNF_DV'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from  HOT_RGSOSTNF_DV'
      'where(  IDDOCH_HOT_RGSOSTNF_DV=:PARAM_IDDOCH'
      
        '     ) and (     HOT_RGSOSTNF_DV.ID_HOT_RGSOSTNF_DV = :OLD_ID_HO' +
        'T_RGSOSTNF_DV'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from  HOT_RGSOSTNF_DV'
      'where IDDOCH_HOT_RGSOSTNF_DV=:PARAM_IDDOCH')
    AutoUpdateOptions.UpdateTableName = 'HOT_RGSOSTNF_DV'
    AutoUpdateOptions.KeyFields = 'ID_HOT_RGSOSTNF_DV'
    AutoUpdateOptions.GeneratorName = 'GEN_HOT_RGSOSTNF_DV_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTrUpdate
    Database = DM.pFIBData
    Left = 32
    Top = 16
    object DvRegOstPOS_HOT_RGSOSTNF_DV: TFIBDateTimeField
      FieldName = 'POS_HOT_RGSOSTNF_DV'
    end
    object DvRegOstTDV_HOT_RGSOSTNF_DV: TFIBIntegerField
      FieldName = 'TDV_HOT_RGSOSTNF_DV'
    end
    object DvRegOstOPER_HOT_RGSOSTNF_DV: TFIBIntegerField
      FieldName = 'OPER_HOT_RGSOSTNF_DV'
    end
    object DvRegOstID_HOT_RGSOSTNF_DV: TFIBBCDField
      FieldName = 'ID_HOT_RGSOSTNF_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDDOCH_HOT_RGSOSTNF_DV: TFIBBCDField
      FieldName = 'IDDOCH_HOT_RGSOSTNF_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDSOST_HOT_RGSOSTNF_DV: TFIBBCDField
      FieldName = 'IDSOST_HOT_RGSOSTNF_DV'
      Size = 0
      RoundByScale = True
    end
  end
  object RegOst: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE HOT_RGSOSTNF'
      'SET '
      '    IDSOST_HOT_RGSOSTNF = :IDSOST_HOT_RGSOSTNF'
      'WHERE'
      '    ID_HOT_RGSOSTNF = :OLD_ID_HOT_RGSOSTNF'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    HOT_RGSOSTNF'
      'WHERE'
      '        ID_HOT_RGSOSTNF = :OLD_ID_HOT_RGSOSTNF'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO HOT_RGSOSTNF('
      '    ID_HOT_RGSOSTNF,'
      '    IDSOST_HOT_RGSOSTNF'
      ')'
      'VALUES('
      '    :ID_HOT_RGSOSTNF,'
      '    :IDSOST_HOT_RGSOSTNF'
      ')')
    RefreshSQL.Strings = (
      'select * from HOT_RGSOSTNF'
      'where( '
      'IDSOST_HOT_RGSOSTNF=:PARAM_IDSOST'
      
        '     ) and (     HOT_RGSOSTNF.ID_HOT_RGSOSTNF = :OLD_ID_HOT_RGSO' +
        'STNF'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from HOT_RGSOSTNF'
      'where'
      'IDSOST_HOT_RGSOSTNF=:PARAM_IDSOST')
    AutoUpdateOptions.UpdateTableName = 'HOT_RGSOSTNF'
    AutoUpdateOptions.KeyFields = 'ID_HOT_RGSOSTNF'
    AutoUpdateOptions.GeneratorName = 'GEN_HOT_RGSOSTNF_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTrUpdate
    Database = DM.pFIBData
    Left = 32
    Top = 72
    object RegOstID_HOT_RGSOSTNF: TFIBBCDField
      FieldName = 'ID_HOT_RGSOSTNF'
      Size = 0
      RoundByScale = True
    end
    object RegOstIDSOST_HOT_RGSOSTNF: TFIBBCDField
      FieldName = 'IDSOST_HOT_RGSOSTNF'
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
    Database = DM.pFIBData
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
    Database = DM.pFIBData
    Left = 32
    Top = 176
    object OstatokSUMOST: TFIBBCDField
      FieldName = 'SUMOST'
      Size = 2
      RoundByScale = True
    end
  end
  object IBTr: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
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
    DefaultDatabase = DM.pFIBData
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
