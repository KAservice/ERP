object DMSprPart: TDMSprPart
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 223
  Width = 316
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 40
    Top = 24
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 40
    Top = 80
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select SPART.* , NAMEFIRM, NAMEKLIENT,KOLOSTNOM'
      'from SPART left outer join SFIRM'
      'on  IDFIRMPART=IDFIRM'
      'left outer join SKLIENT on IDKLPART=IDKLIENT'
      'left outer join RGOSTNOM on IDPART=IDPARTOSTNOM'
      'where IDNOMPART=:IDNOM')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 136
    Top = 24
    object TablePRICEZPART: TFIBBCDField
      FieldName = 'PRICEZPART'
      Size = 2
      RoundByScale = True
    end
    object TableKOLOSTNOM: TFIBBCDField
      FieldName = 'KOLOSTNOM'
      Size = 3
      RoundByScale = True
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableIDPART: TFIBBCDField
      FieldName = 'IDPART'
      Size = 0
      RoundByScale = True
    end
    object TableIDKLPART: TFIBBCDField
      FieldName = 'IDKLPART'
      Size = 0
      RoundByScale = True
    end
    object TableIDFIRMPART: TFIBBCDField
      FieldName = 'IDFIRMPART'
      Size = 0
      RoundByScale = True
    end
    object TableIDNOMPART: TFIBBCDField
      FieldName = 'IDNOMPART'
      Size = 0
      RoundByScale = True
    end
    object TableIDDOCPART: TFIBBCDField
      FieldName = 'IDDOCPART'
      Size = 0
      RoundByScale = True
    end
    object TableSRGODNPART: TFIBDateTimeField
      FieldName = 'SRGODNPART'
    end
    object TableCODEPART: TFIBIntegerField
      FieldName = 'CODEPART'
    end
    object TableDOCPART: TFIBWideStringField
      FieldName = 'DOCPART'
      Size = 100
    end
    object TableGTDPART: TFIBWideStringField
      FieldName = 'GTDPART'
      Size = 100
    end
    object TableSERTPART: TFIBWideStringField
      FieldName = 'SERTPART'
      Size = 11
    end
    object TableGID_SPART: TFIBWideStringField
      FieldName = 'GID_SPART'
      Size = 10
    end
    object TableIDBASE_SPART: TFIBBCDField
      FieldName = 'IDBASE_SPART'
      Size = 0
      RoundByScale = True
    end
    object TableIDEXT_DOUT_SPART: TFIBBCDField
      FieldName = 'IDEXT_DOUT_SPART'
      Size = 0
      RoundByScale = True
    end
    object TableIDEXT_BASE_SPART: TFIBBCDField
      FieldName = 'IDEXT_BASE_SPART'
      Size = 0
      RoundByScale = True
    end
    object TableNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 100
    end
    object TableNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 100
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SPART'
      'SET '
      '    CODEPART = :CODEPART,'
      '    DOCPART = :DOCPART,'
      '    GTDPART = :GTDPART,'
      '    IDKLPART = :IDKLPART,'
      '    PRICEZPART = :PRICEZPART,'
      '    SERTPART = :SERTPART,'
      '    SRGODNPART = :SRGODNPART,'
      '    IDFIRMPART = :IDFIRMPART,'
      '    IDNOMPART = :IDNOMPART,'
      '    IDDOCPART = :IDDOCPART,'
      '    GID_SPART = :GID_SPART'
      'WHERE'
      '    IDPART = :OLD_IDPART'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SPART'
      'WHERE'
      '        IDPART = :OLD_IDPART'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SPART('
      '    IDPART,'
      '    CODEPART,'
      '    DOCPART,'
      '    GTDPART,'
      '    IDKLPART,'
      '    PRICEZPART,'
      '    SERTPART,'
      '    SRGODNPART,'
      '    IDFIRMPART,'
      '    IDNOMPART,'
      '    IDDOCPART,'
      '    GID_SPART'
      ')'
      'VALUES('
      '    :IDPART,'
      '    :CODEPART,'
      '    :DOCPART,'
      '    :GTDPART,'
      '    :IDKLPART,'
      '    :PRICEZPART,'
      '    :SERTPART,'
      '    :SRGODNPART,'
      '    :IDFIRMPART,'
      '    :IDNOMPART,'
      '    :IDDOCPART,'
      '    :GID_SPART'
      ')')
    RefreshSQL.Strings = (
      'select SPART.* ,NAMEKLIENT, NAMENOM, NAMEFIRM'
      'from SPART '
      'left outer join SNOM on IDNOM=IDNOMPART'
      'left outer join SFIRM on IDFIRMPART=IDFIRM'
      'left outer join SKLIENT on IDKLPART=IDKLIENT'
      'where(  IDPART=:ID'
      '     ) and (     SPART.IDPART = :OLD_IDPART'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select SPART.* ,NAMEKLIENT, NAMENOM, NAMEFIRM'
      'from SPART '
      'left outer join SNOM on IDNOM=IDNOMPART'
      'left outer join SFIRM on IDFIRMPART=IDFIRM'
      'left outer join SKLIENT on IDKLPART=IDKLIENT'
      'where IDPART=:ID')
    AutoUpdateOptions.UpdateTableName = 'SPART'
    AutoUpdateOptions.KeyFields = 'IDPART'
    AutoUpdateOptions.GeneratorName = 'GEN_SPART_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 136
    Top = 80
    object ElementPRICEZPART: TFIBBCDField
      FieldName = 'PRICEZPART'
      Size = 2
      RoundByScale = True
    end
    object ElementIDKLPART: TFIBBCDField
      FieldName = 'IDKLPART'
      Size = 0
      RoundByScale = True
    end
    object ElementIDFIRMPART: TFIBBCDField
      FieldName = 'IDFIRMPART'
      Size = 0
      RoundByScale = True
    end
    object ElementIDNOMPART: TFIBBCDField
      FieldName = 'IDNOMPART'
      Size = 0
      RoundByScale = True
    end
    object ElementIDDOCPART: TFIBBCDField
      FieldName = 'IDDOCPART'
      Size = 0
      RoundByScale = True
    end
    object ElementIDPART: TFIBBCDField
      FieldName = 'IDPART'
      Size = 0
      RoundByScale = True
    end
    object ElementSRGODNPART: TFIBDateTimeField
      FieldName = 'SRGODNPART'
      DisplayFormat = 'c'
    end
    object ElementCODEPART: TFIBIntegerField
      FieldName = 'CODEPART'
    end
    object ElementDOCPART: TFIBWideStringField
      FieldName = 'DOCPART'
      Size = 100
    end
    object ElementGTDPART: TFIBWideStringField
      FieldName = 'GTDPART'
      Size = 100
    end
    object ElementGID_SPART: TFIBWideStringField
      FieldName = 'GID_SPART'
      Size = 10
    end
    object ElementIDBASE_SPART: TFIBBCDField
      FieldName = 'IDBASE_SPART'
      Size = 0
      RoundByScale = True
    end
    object ElementNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 100
    end
    object ElementNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 100
    end
    object ElementNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 100
    end
    object ElementSERTPART: TFIBWideStringField
      FieldName = 'SERTPART'
      Size = 11
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
    Left = 224
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
    Left = 224
    Top = 80
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 120
    Top = 152
    qoStartTransaction = True
  end
end
