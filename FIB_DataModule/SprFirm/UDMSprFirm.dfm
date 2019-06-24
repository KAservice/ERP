object DMSprFirm: TDMSprFirm
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 265
  Width = 360
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 64
    Top = 72
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
    Left = 168
    Top = 16
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
    object TableINNFIRM: TFIBWideStringField
      FieldName = 'INNFIRM'
      Size = 12
    end
    object TableNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 100
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
      '    KRNAMEFIRM = :KRNAMEFIRM,'
      '    PREFIKS_NUM_SFIRM = :PREFIKS_NUM_SFIRM'
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
      '    KRNAMEFIRM,'
      '    PREFIKS_NUM_SFIRM'
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
      '    :KRNAMEFIRM,'
      '    :PREFIKS_NUM_SFIRM'
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
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 72
    object ElementTYPEFIRM: TFIBSmallIntField
      FieldName = 'TYPEFIRM'
    end
    object ElementIDFIRM: TFIBBCDField
      FieldName = 'IDFIRM'
      Size = 0
      RoundByScale = True
    end
    object ElementNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 200
    end
    object ElementFNAMEFIRM: TFIBWideStringField
      FieldName = 'FNAMEFIRM'
      Size = 200
    end
    object ElementPADRFIRM: TFIBWideStringField
      FieldName = 'PADRFIRM'
      Size = 200
    end
    object ElementUADRFIRM: TFIBWideStringField
      FieldName = 'UADRFIRM'
      Size = 200
    end
    object ElementINNFIRM: TFIBWideStringField
      FieldName = 'INNFIRM'
      Size = 12
    end
    object ElementKPPFIRM: TFIBWideStringField
      FieldName = 'KPPFIRM'
      Size = 9
    end
    object ElementDIRFIRM: TFIBWideStringField
      FieldName = 'DIRFIRM'
    end
    object ElementBUHFIRM: TFIBWideStringField
      FieldName = 'BUHFIRM'
    end
    object ElementKASFIRM: TFIBWideStringField
      FieldName = 'KASFIRM'
    end
    object ElementGID_SFIRM: TFIBWideStringField
      FieldName = 'GID_SFIRM'
      Size = 10
    end
    object ElementNUMDOCREGFIRM: TFIBWideStringField
      FieldName = 'NUMDOCREGFIRM'
      Size = 10
    end
    object ElementOKPOSFIRM: TFIBWideStringField
      FieldName = 'OKPOSFIRM'
      Size = 10
    end
    object ElementOKDPSFIRM: TFIBWideStringField
      FieldName = 'OKDPSFIRM'
      Size = 10
    end
    object ElementTELFIRM: TFIBWideStringField
      FieldName = 'TELFIRM'
      Size = 200
    end
    object ElementIDBASE_SFIRM: TFIBBCDField
      FieldName = 'IDBASE_SFIRM'
      Size = 0
      RoundByScale = True
    end
    object ElementKRNAMEFIRM: TFIBWideStringField
      FieldName = 'KRNAMEFIRM'
      Size = 200
    end
    object ElementDATEDOCREGFIRM: TFIBWideStringField
      FieldName = 'DATEDOCREGFIRM'
      Size = 10
    end
    object ElementPREFIKS_NUM_SFIRM: TFIBWideStringField
      FieldName = 'PREFIKS_NUM_SFIRM'
      Size = 3
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
    Left = 264
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
    Left = 264
    Top = 72
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 320
    Top = 48
    qoStartTransaction = True
  end
end
