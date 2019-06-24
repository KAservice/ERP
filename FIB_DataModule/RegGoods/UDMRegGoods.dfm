object DMRegGoods: TDMRegGoods
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 288
  Width = 243
  object DvRegOst: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE RGGOODS_DV'
      'SET '
      '    POSDOC_RGGOODS_DV = :POSDOC_RGGOODS_DV,'
      '    IDDOC_RGGOODS_DV = :IDDOC_RGGOODS_DV,'
      '    TDV_RGGOODS_DV = :TDV_RGGOODS_DV,'
      '    IDFIRM_RGGOODS_DV = :IDFIRM_RGGOODS_DV,'
      '    IDSKLAD_RGGOODS_DV = :IDSKLAD_RGGOODS_DV,'
      '    IDNOM_RGGOODS_DV = :IDNOM_RGGOODS_DV,'
      '    RPRICE_RGGOODS_DV = :RPRICE_RGGOODS_DV,'
      '    KOL_RGGOODS_DV = :KOL_RGGOODS_DV,'
      '    OPER_RGGOODS_DV = :OPER_RGGOODS_DV,'
      '    TYPE_RGGOODS_DV = :TYPE_RGGOODS_DV'
      'WHERE'
      '    ID_RGGOODS_DV = :OLD_ID_RGGOODS_DV'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    RGGOODS_DV'
      'WHERE'
      '        ID_RGGOODS_DV = :OLD_ID_RGGOODS_DV'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO RGGOODS_DV('
      '    ID_RGGOODS_DV,'
      '    POSDOC_RGGOODS_DV,'
      '    IDDOC_RGGOODS_DV,'
      '    TDV_RGGOODS_DV,'
      '    IDFIRM_RGGOODS_DV,'
      '    IDSKLAD_RGGOODS_DV,'
      '    IDNOM_RGGOODS_DV,'
      '    RPRICE_RGGOODS_DV,'
      '    KOL_RGGOODS_DV,'
      '    OPER_RGGOODS_DV,'
      '    TYPE_RGGOODS_DV'
      ')'
      'VALUES('
      '    :ID_RGGOODS_DV,'
      '    :POSDOC_RGGOODS_DV,'
      '    :IDDOC_RGGOODS_DV,'
      '    :TDV_RGGOODS_DV,'
      '    :IDFIRM_RGGOODS_DV,'
      '    :IDSKLAD_RGGOODS_DV,'
      '    :IDNOM_RGGOODS_DV,'
      '    :RPRICE_RGGOODS_DV,'
      '    :KOL_RGGOODS_DV,'
      '    :OPER_RGGOODS_DV,'
      '    :TYPE_RGGOODS_DV'
      ')')
    RefreshSQL.Strings = (
      'select * from  RGGOODS_DV'
      'where(  IDDOC_RGGOODS_DV=:IDDOC'
      '     ) and (     RGGOODS_DV.ID_RGGOODS_DV = :OLD_ID_RGGOODS_DV'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from  RGGOODS_DV'
      'where IDDOC_RGGOODS_DV=:IDDOC')
    AutoUpdateOptions.UpdateTableName = 'RGGOODS_DV'
    AutoUpdateOptions.KeyFields = 'ID_RGGOODS_DV'
    AutoUpdateOptions.GeneratorName = 'GEN_RGGOODS_DV_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTrUpdate
    Left = 32
    Top = 16
    object DvRegOstPOSDOC_RGGOODS_DV: TFIBDateTimeField
      FieldName = 'POSDOC_RGGOODS_DV'
    end
    object DvRegOstTDV_RGGOODS_DV: TFIBSmallIntField
      FieldName = 'TDV_RGGOODS_DV'
    end
    object DvRegOstRPRICE_RGGOODS_DV: TFIBBCDField
      FieldName = 'RPRICE_RGGOODS_DV'
      Size = 2
      RoundByScale = True
    end
    object DvRegOstKOL_RGGOODS_DV: TFIBBCDField
      FieldName = 'KOL_RGGOODS_DV'
      Size = 3
      RoundByScale = True
    end
    object DvRegOstOPER_RGGOODS_DV: TFIBIntegerField
      FieldName = 'OPER_RGGOODS_DV'
    end
    object DvRegOstTYPE_RGGOODS_DV: TFIBIntegerField
      FieldName = 'TYPE_RGGOODS_DV'
    end
    object DvRegOstID_RGGOODS_DV: TFIBBCDField
      FieldName = 'ID_RGGOODS_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDDOC_RGGOODS_DV: TFIBBCDField
      FieldName = 'IDDOC_RGGOODS_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDFIRM_RGGOODS_DV: TFIBBCDField
      FieldName = 'IDFIRM_RGGOODS_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDSKLAD_RGGOODS_DV: TFIBBCDField
      FieldName = 'IDSKLAD_RGGOODS_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDNOM_RGGOODS_DV: TFIBBCDField
      FieldName = 'IDNOM_RGGOODS_DV'
      Size = 0
      RoundByScale = True
    end
  end
  object RegOst: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE RGGOODS'
      'SET '
      '    IDFIRM_RGGOODS = :IDFIRM_RGGOODS,'
      '    IDSKLAD_RGGOODS = :IDSKLAD_RGGOODS,'
      '    IDNOM_RGGOODS = :IDNOM_RGGOODS,'
      '    RPRICE_RGGOODS = :RPRICE_RGGOODS,'
      '    KOL_RGGOODS = :KOL_RGGOODS'
      'WHERE'
      '    ID_RGGOODS = :OLD_ID_RGGOODS'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    RGGOODS'
      'WHERE'
      '        ID_RGGOODS = :OLD_ID_RGGOODS'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO RGGOODS('
      '    ID_RGGOODS,'
      '    IDFIRM_RGGOODS,'
      '    IDSKLAD_RGGOODS,'
      '    IDNOM_RGGOODS,'
      '    RPRICE_RGGOODS,'
      '    KOL_RGGOODS'
      ')'
      'VALUES('
      '    :ID_RGGOODS,'
      '    :IDFIRM_RGGOODS,'
      '    :IDSKLAD_RGGOODS,'
      '    :IDNOM_RGGOODS,'
      '    :RPRICE_RGGOODS,'
      '    :KOL_RGGOODS'
      ')')
    RefreshSQL.Strings = (
      'select * from RGGOODS'
      'where( '
      'IDFIRM_RGGOODS=:IDFIRM  and'
      'IDSKLAD_RGGOODS=:IDSKL  and'
      'IDNOM_RGGOODS=:IDNOM and'
      'RPRICE_RGGOODS=:PRICE'
      '     ) and (     RGGOODS.ID_RGGOODS = :OLD_ID_RGGOODS'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from RGGOODS'
      'where'
      'IDFIRM_RGGOODS=:IDFIRM  and'
      'IDSKLAD_RGGOODS=:IDSKL  and'
      'IDNOM_RGGOODS=:IDNOM and'
      'RPRICE_RGGOODS=:PRICE')
    AutoUpdateOptions.UpdateTableName = 'RGGOODS'
    AutoUpdateOptions.KeyFields = 'ID_RGGOODS'
    AutoUpdateOptions.GeneratorName = 'GEN_RGGOODS_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTrUpdate
    Left = 32
    Top = 72
    object RegOstRPRICE_RGGOODS: TFIBBCDField
      FieldName = 'RPRICE_RGGOODS'
      Size = 2
      RoundByScale = True
    end
    object RegOstKOL_RGGOODS: TFIBBCDField
      FieldName = 'KOL_RGGOODS'
      Size = 3
      RoundByScale = True
    end
    object RegOstID_RGGOODS: TFIBBCDField
      FieldName = 'ID_RGGOODS'
      Size = 0
      RoundByScale = True
    end
    object RegOstIDFIRM_RGGOODS: TFIBBCDField
      FieldName = 'IDFIRM_RGGOODS'
      Size = 0
      RoundByScale = True
    end
    object RegOstIDSKLAD_RGGOODS: TFIBBCDField
      FieldName = 'IDSKLAD_RGGOODS'
      Size = 0
      RoundByScale = True
    end
    object RegOstIDNOM_RGGOODS: TFIBBCDField
      FieldName = 'IDNOM_RGGOODS'
      Size = 0
      RoundByScale = True
    end
  end
  object DvNom: TpFIBDataSet
    SelectSQL.Strings = (
      'select SUM(KOL_RGGOODS_DV) AS KOLDV'
      'from RGGOODS_DV'
      ' where '
      'POSDOC_RGGOODS_DV > :PARAM_POS and'
      'IDFIRM_RGGOODS_DV=:PARAM_IDFIRM and'
      'IDSKLAD_RGGOODS_DV=:PARAM_IDSKLAD   and'
      'IDNOM_RGGOODS_DV=:PARAM_IDNOM  and'
      'TDV_RGGOODS_DV = :PARAM_TDV'
      'group by IDNOM_RGGOODS_DV')
    Transaction = IBTr
    Left = 32
    Top = 120
    object DvNomKOLDV: TFIBBCDField
      FieldName = 'KOLDV'
      Size = 3
      RoundByScale = True
    end
  end
  object Ostatok: TpFIBDataSet
    SelectSQL.Strings = (
      'select SUM(KOL_RGGOODS) AS KOLOST'
      'from RGGOODS'
      ' where '
      'IDFIRM_RGGOODS=:PARAM_IDFIRM and'
      'IDSKLAD_RGGOODS=:PARAM_IDSKLAD and'
      'IDNOM_RGGOODS=:PARAM_IDNOM'
      'group by IDNOM_RGGOODS')
    Transaction = IBTr
    Left = 32
    Top = 176
    object OstatokKOLOST: TFIBBCDField
      FieldName = 'KOLOST'
      Size = 3
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
    Left = 160
    Top = 24
  end
  object IBTrUpdate: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 160
    Top = 88
  end
  object TableOst: TpFIBDataSet
    Transaction = IBTr
    Left = 160
    Top = 152
  end
  object Query: TpFIBDataSet
    Transaction = IBTr
    Left = 32
    Top = 232
  end
end
