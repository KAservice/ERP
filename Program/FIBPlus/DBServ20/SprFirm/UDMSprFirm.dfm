object DMSprFirm: TDMSprFirm
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 143
  Width = 360
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 64
    Top = 64
  end
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 64
    Top = 16
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select IDFIRM, INNFIRM, NAMEFIRM from SFIRM')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 168
    Top = 16
    object TableINNFIRM: TFIBStringField
      FieldName = 'INNFIRM'
      Size = 12
      EmptyStrToNull = True
    end
    object TableNAMEFIRM: TFIBStringField
      FieldName = 'NAMEFIRM'
      Size = 50
      EmptyStrToNull = True
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableIDFIRM: TFIBBCDField
      FieldName = 'IDFIRM'
      Size = 0
      RoundByScale = True
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SFIRM'
      'SET '
      '    NAMEFIRM = :NAMEFIRM,'
      '    FNAMEFIRM = :FNAMEFIRM,'
      '    PADRFIRM = :PADRFIRM,'
      '    UADRFIRM = :UADRFIRM,'
      '    INNFIRM = :INNFIRM,'
      '    KPPFIRM = :KPPFIRM,'
      '    DIRFIRM = :DIRFIRM,'
      '    BUHFIRM = :BUHFIRM,'
      '    KASFIRM = :KASFIRM,'
      '    GID_SFIRM = :GID_SFIRM,'
      '    NUMDOCREGFIRM = :NUMDOCREGFIRM,'
      '    DATEDOCREGFIRM = :DATEDOCREGFIRM,'
      '    TYPEFIRM = :TYPEFIRM,'
      '    OKPOSFIRM = :OKPOSFIRM,'
      '    OKDPSFIRM = :OKDPSFIRM,'
      '    TELFIRM = :TELFIRM,'
      '    IDBASE_SFIRM = :IDBASE_SFIRM,'
      '    KRNAMEFIRM = :KRNAMEFIRM'
      'WHERE'
      '    IDFIRM = :OLD_IDFIRM'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SFIRM'
      'WHERE'
      '        IDFIRM = :OLD_IDFIRM'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SFIRM('
      '    IDFIRM,'
      '    NAMEFIRM,'
      '    FNAMEFIRM,'
      '    PADRFIRM,'
      '    UADRFIRM,'
      '    INNFIRM,'
      '    KPPFIRM,'
      '    DIRFIRM,'
      '    BUHFIRM,'
      '    KASFIRM,'
      '    GID_SFIRM,'
      '    NUMDOCREGFIRM,'
      '    DATEDOCREGFIRM,'
      '    TYPEFIRM,'
      '    OKPOSFIRM,'
      '    OKDPSFIRM,'
      '    TELFIRM,'
      '    IDBASE_SFIRM,'
      '    KRNAMEFIRM'
      ')'
      'VALUES('
      '    :IDFIRM,'
      '    :NAMEFIRM,'
      '    :FNAMEFIRM,'
      '    :PADRFIRM,'
      '    :UADRFIRM,'
      '    :INNFIRM,'
      '    :KPPFIRM,'
      '    :DIRFIRM,'
      '    :BUHFIRM,'
      '    :KASFIRM,'
      '    :GID_SFIRM,'
      '    :NUMDOCREGFIRM,'
      '    :DATEDOCREGFIRM,'
      '    :TYPEFIRM,'
      '    :OKPOSFIRM,'
      '    :OKDPSFIRM,'
      '    :TELFIRM,'
      '    :IDBASE_SFIRM,'
      '    :KRNAMEFIRM'
      ')')
    RefreshSQL.Strings = (
      'select * from SFIRM where(  IDFIRM=:ID'
      '     ) and (     SFIRM.IDFIRM = :OLD_IDFIRM'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from SFIRM where IDFIRM=:ID')
    AutoUpdateOptions.UpdateTableName = 'SFIRM'
    AutoUpdateOptions.KeyFields = 'IDFIRM'
    AutoUpdateOptions.GeneratorName = 'GEN_SFIRM_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    Database = DM.pFIBData
    UpdateTransaction = IBTrUpdate
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 168
    Top = 72
    object ElementNAMEFIRM: TFIBStringField
      FieldName = 'NAMEFIRM'
      Size = 50
      EmptyStrToNull = True
    end
    object ElementFNAMEFIRM: TFIBStringField
      FieldName = 'FNAMEFIRM'
      Size = 100
      EmptyStrToNull = True
    end
    object ElementPADRFIRM: TFIBStringField
      FieldName = 'PADRFIRM'
      Size = 100
      EmptyStrToNull = True
    end
    object ElementUADRFIRM: TFIBStringField
      FieldName = 'UADRFIRM'
      Size = 100
      EmptyStrToNull = True
    end
    object ElementINNFIRM: TFIBStringField
      FieldName = 'INNFIRM'
      Size = 12
      EmptyStrToNull = True
    end
    object ElementKPPFIRM: TFIBStringField
      FieldName = 'KPPFIRM'
      Size = 9
      EmptyStrToNull = True
    end
    object ElementDIRFIRM: TFIBStringField
      FieldName = 'DIRFIRM'
      EmptyStrToNull = True
    end
    object ElementBUHFIRM: TFIBStringField
      FieldName = 'BUHFIRM'
      EmptyStrToNull = True
    end
    object ElementKASFIRM: TFIBStringField
      FieldName = 'KASFIRM'
      EmptyStrToNull = True
    end
    object ElementNUMDOCREGFIRM: TFIBStringField
      FieldName = 'NUMDOCREGFIRM'
      Size = 10
      EmptyStrToNull = True
    end
    object ElementDATEDOCREGFIRM: TFIBStringField
      FieldName = 'DATEDOCREGFIRM'
      Size = 10
      EmptyStrToNull = True
    end
    object ElementTYPEFIRM: TFIBSmallIntField
      FieldName = 'TYPEFIRM'
    end
    object ElementOKPOSFIRM: TFIBStringField
      FieldName = 'OKPOSFIRM'
      Size = 10
      EmptyStrToNull = True
    end
    object ElementOKDPSFIRM: TFIBStringField
      FieldName = 'OKDPSFIRM'
      Size = 10
      EmptyStrToNull = True
    end
    object ElementTELFIRM: TFIBStringField
      FieldName = 'TELFIRM'
      Size = 50
      EmptyStrToNull = True
    end
    object ElementIDFIRM: TFIBBCDField
      FieldName = 'IDFIRM'
      Size = 0
      RoundByScale = True
    end
    object ElementGID_SFIRM: TFIBStringField
      FieldName = 'GID_SFIRM'
      Size = 10
      EmptyStrToNull = True
    end
    object ElementKRNAMEFIRM: TFIBStringField
      FieldName = 'KRNAMEFIRM'
      Size = 50
      EmptyStrToNull = True
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
    CSMonitorSupport.Enabled = csmeDatabaseDriven
    TPBMode = tpbDefault
    Left = 264
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
    CSMonitorSupport.Enabled = csmeDatabaseDriven
    TPBMode = tpbDefault
    Left = 264
    Top = 72
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 320
    Top = 48
    qoStartTransaction = True
  end
end
