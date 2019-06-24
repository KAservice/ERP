object DMRegVsRasch: TDMRegVsRasch
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 224
  Width = 225
  object DvRegOst: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE RGVSRASCH_DV'
      'SET '
      '    IDDOC_VSRASCH_DV = :IDDOC_VSRASCH_DV,'
      '    IDFIRM_VSRASCH_DV = :IDFIRM_VSRASCH_DV,'
      '    IDKLIENT_VSRASCH_DV = :IDKLIENT_VSRASCH_DV,'
      '    POSDOC_VSRASCH_DV = :POSDOC_VSRASCH_DV,'
      '    TDV_VSRASCH_DV = :TDV_VSRASCH_DV,'
      '    SUM_VSRASCH_DV = :SUM_VSRASCH_DV,'
      '    IDDOG_VSRASCH_DV = :IDDOG_VSRASCH_DV'
      'WHERE'
      '    ID_VSRASCH_DV = :OLD_ID_VSRASCH_DV'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    RGVSRASCH_DV'
      'WHERE'
      '        ID_VSRASCH_DV = :OLD_ID_VSRASCH_DV'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO RGVSRASCH_DV('
      '    ID_VSRASCH_DV,'
      '    IDDOC_VSRASCH_DV,'
      '    IDFIRM_VSRASCH_DV,'
      '    IDKLIENT_VSRASCH_DV,'
      '    POSDOC_VSRASCH_DV,'
      '    TDV_VSRASCH_DV,'
      '    SUM_VSRASCH_DV,'
      '    IDDOG_VSRASCH_DV'
      ')'
      'VALUES('
      '    :ID_VSRASCH_DV,'
      '    :IDDOC_VSRASCH_DV,'
      '    :IDFIRM_VSRASCH_DV,'
      '    :IDKLIENT_VSRASCH_DV,'
      '    :POSDOC_VSRASCH_DV,'
      '    :TDV_VSRASCH_DV,'
      '    :SUM_VSRASCH_DV,'
      '    :IDDOG_VSRASCH_DV'
      ')')
    RefreshSQL.Strings = (
      'select * from  RGVSRASCH_DV'
      'where(  IDDOC_VSRASCH_DV=:IDDOC'
      '     ) and (     RGVSRASCH_DV.ID_VSRASCH_DV = :OLD_ID_VSRASCH_DV'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from  RGVSRASCH_DV'
      'where IDDOC_VSRASCH_DV=:IDDOC')
    AutoUpdateOptions.UpdateTableName = 'RGVSRASCH_DV'
    AutoUpdateOptions.KeyFields = 'ID_VSRASCH_DV'
    AutoUpdateOptions.GeneratorName = 'GEN_RGVSRASCH_DV_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTrUpdate
    Left = 32
    Top = 8
    object DvRegOstPOSDOC_VSRASCH_DV: TFIBDateTimeField
      FieldName = 'POSDOC_VSRASCH_DV'
    end
    object DvRegOstTDV_VSRASCH_DV: TFIBSmallIntField
      FieldName = 'TDV_VSRASCH_DV'
    end
    object DvRegOstSUM_VSRASCH_DV: TFIBBCDField
      FieldName = 'SUM_VSRASCH_DV'
      Size = 2
      RoundByScale = True
    end
    object DvRegOstID_VSRASCH_DV: TFIBBCDField
      FieldName = 'ID_VSRASCH_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDDOC_VSRASCH_DV: TFIBBCDField
      FieldName = 'IDDOC_VSRASCH_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDFIRM_VSRASCH_DV: TFIBBCDField
      FieldName = 'IDFIRM_VSRASCH_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDKLIENT_VSRASCH_DV: TFIBBCDField
      FieldName = 'IDKLIENT_VSRASCH_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDDOG_VSRASCH_DV: TFIBBCDField
      FieldName = 'IDDOG_VSRASCH_DV'
      Size = 0
      RoundByScale = True
    end
  end
  object RegOst: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE RGVSRASCH'
      'SET '
      '    IDFIRM_VSRASCH = :IDFIRM_VSRASCH,'
      '    IDKLIENT_VSRASCH = :IDKLIENT_VSRASCH,'
      '    SUM_VSRASCH = :SUM_VSRASCH,'
      '    IDDOG_VSRASCH = :IDDOG_VSRASCH'
      'WHERE'
      '    ID_VSRASCH = :OLD_ID_VSRASCH'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    RGVSRASCH'
      'WHERE'
      '        ID_VSRASCH = :OLD_ID_VSRASCH'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO RGVSRASCH('
      '    ID_VSRASCH,'
      '    IDFIRM_VSRASCH,'
      '    IDKLIENT_VSRASCH,'
      '    SUM_VSRASCH,'
      '    IDDOG_VSRASCH'
      ')'
      'VALUES('
      '    :ID_VSRASCH,'
      '    :IDFIRM_VSRASCH,'
      '    :IDKLIENT_VSRASCH,'
      '    :SUM_VSRASCH,'
      '    :IDDOG_VSRASCH'
      ')')
    RefreshSQL.Strings = (
      'select * from RGVSRASCH'
      'where( '
      'IDFIRM_VSRASCH=:IDFIRM  and'
      'IDKLIENT_VSRASCH=:IDKLIENT'
      '     ) and (     RGVSRASCH.ID_VSRASCH = :OLD_ID_VSRASCH'
      '     )'
      '     ')
    SelectSQL.Strings = (
      'select * from RGVSRASCH'
      'where'
      'IDFIRM_VSRASCH=:IDFIRM  and'
      'IDKLIENT_VSRASCH=:IDKLIENT ')
    AutoUpdateOptions.UpdateTableName = 'RGVSRASCH'
    AutoUpdateOptions.KeyFields = 'ID_VSRASCH'
    AutoUpdateOptions.GeneratorName = 'GEN_RGVSRASCH_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTrUpdate
    Left = 32
    Top = 56
    object RegOstSUM_VSRASCH: TFIBBCDField
      FieldName = 'SUM_VSRASCH'
      Size = 2
      RoundByScale = True
    end
    object RegOstID_VSRASCH: TFIBBCDField
      FieldName = 'ID_VSRASCH'
      Size = 0
      RoundByScale = True
    end
    object RegOstIDFIRM_VSRASCH: TFIBBCDField
      FieldName = 'IDFIRM_VSRASCH'
      Size = 0
      RoundByScale = True
    end
    object RegOstIDKLIENT_VSRASCH: TFIBBCDField
      FieldName = 'IDKLIENT_VSRASCH'
      Size = 0
      RoundByScale = True
    end
    object RegOstIDDOG_VSRASCH: TFIBBCDField
      FieldName = 'IDDOG_VSRASCH'
      Size = 0
      RoundByScale = True
    end
  end
  object Dv: TpFIBDataSet
    SelectSQL.Strings = (
      'select  SUM(SUM_VSRASCH_DV) AS SUMDV'
      'from RGVSRASCH_DV'
      ' where '
      'POSDOC_VSRASCH_DV> :PARAM_POS and'
      'IDKLIENT_VSRASCH_DV=:PARAM_IDKLIENT  and'
      'TDV_VSRASCH_DV = :PARAM_TDV'
      ' and rgvsrasch_dv.idfirm_vsrasch_dv=:PARAM_IDFIRM'
      'group by IDKLIENT_VSRASCH_DV')
    Transaction = IBTr
    Left = 32
    Top = 104
    object DvSUMDV: TFIBBCDField
      FieldName = 'SUMDV'
      Size = 2
      RoundByScale = True
    end
  end
  object Ostatok: TpFIBDataSet
    SelectSQL.Strings = (
      'select SUM(SUM_VSRASCH) AS SUMOST'
      'from RGVSRASCH'
      ' where IDKLIENT_VSRASCH=:PARAM_IDKLIENT'
      ' and rgvsrasch.idfirm_vsrasch=:PARAM_IDFIRM'
      'group by IDKLIENT_VSRASCH')
    Transaction = IBTr
    Left = 32
    Top = 152
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
    Top = 8
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
    Top = 64
  end
end
