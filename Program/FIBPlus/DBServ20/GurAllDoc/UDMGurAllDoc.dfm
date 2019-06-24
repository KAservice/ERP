object DMGurAllDoc: TDMGurAllDoc
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 218
  Width = 292
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 16
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select '
      'GALLDOC.*, NAMEFIRM, NAMESKLAD, NAMEKLIENT, NAME_USER,'
      '  NAME_SPROJECT'
      'from '
      'GALLDOC LEFT OUTER JOIN SFIRM ON IDFIRMDOC=IDFIRM'
      'left outer join SSKLAD on IDSKLDOC=IDSKLAD'
      'left outer join SKLIENT on IDKLDOC=IDKLIENT'
      'left outer join SUSER on  IDUSERDOC= ID_USER'
      'left outer join SPROJECT on IDPROJECT_GALLDOC=ID_SPROJECT'
      'where POSDOC between  :PARAM_DATE_NACH and :PARAM_DATE_CON AND '
      'TDOC in (:PARAM_TDOC)'
      'order by POSDOC')
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 144
    Top = 16
    object TablePRDOC: TFIBSmallIntField
      FieldName = 'PRDOC'
    end
    object TableTDOC: TFIBStringField
      FieldName = 'TDOC'
      OnGetText = TableTDOCGetText
      Size = 10
      EmptyStrToNull = True
    end
    object TableNUMDOC: TFIBIntegerField
      FieldName = 'NUMDOC'
    end
    object TableSUMDOC: TFIBBCDField
      FieldName = 'SUMDOC'
      OnGetText = TableSUMDOCGetText
      Size = 2
      RoundByScale = True
    end
    object TableNAMEFIRM: TFIBStringField
      FieldName = 'NAMEFIRM'
      Size = 50
      EmptyStrToNull = True
    end
    object TableNAMESKLAD: TFIBStringField
      FieldName = 'NAMESKLAD'
      Size = 50
      EmptyStrToNull = True
    end
    object TableNAMEKLIENT: TFIBStringField
      FieldName = 'NAMEKLIENT'
      Size = 50
      EmptyStrToNull = True
    end
    object TableNAME_USER: TFIBStringField
      FieldName = 'NAME_USER'
      EmptyStrToNull = True
    end
    object TablePOSDOC: TFIBDateTimeField
      FieldName = 'POSDOC'
      DisplayFormat = 'c'
    end
    object TableIDDOC: TFIBBCDField
      FieldName = 'IDDOC'
      Size = 0
      RoundByScale = True
    end
    object TableIDFIRMDOC: TFIBBCDField
      FieldName = 'IDFIRMDOC'
      Size = 0
      RoundByScale = True
    end
    object TableIDSKLDOC: TFIBBCDField
      FieldName = 'IDSKLDOC'
      Size = 0
      RoundByScale = True
    end
    object TableIDKLDOC: TFIBBCDField
      FieldName = 'IDKLDOC'
      Size = 0
      RoundByScale = True
    end
    object TableIDDOGDOC: TFIBBCDField
      FieldName = 'IDDOGDOC'
      Size = 0
      RoundByScale = True
    end
    object TableIDUSERDOC: TFIBBCDField
      FieldName = 'IDUSERDOC'
      Size = 0
      RoundByScale = True
    end
    object TableIDDOCOSNDOC: TFIBBCDField
      FieldName = 'IDDOCOSNDOC'
      Size = 0
      RoundByScale = True
    end
    object TableIDEXTDOC: TFIBBCDField
      FieldName = 'IDEXTDOC'
      Size = 0
      RoundByScale = True
    end
    object TableTYPEEXTDOC: TFIBIntegerField
      FieldName = 'TYPEEXTDOC'
    end
    object TableGID_DOC: TFIBStringField
      FieldName = 'GID_DOC'
      Size = 10
      EmptyStrToNull = True
    end
    object TableIDBASE_GALLDOC: TFIBBCDField
      FieldName = 'IDBASE_GALLDOC'
      Size = 0
      RoundByScale = True
    end
    object TableIDPROJECT_GALLDOC: TFIBBCDField
      FieldName = 'IDPROJECT_GALLDOC'
      Size = 0
      RoundByScale = True
    end
    object TableNAME_SPROJECT: TFIBStringField
      FieldName = 'NAME_SPROJECT'
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
    Left = 232
    Top = 16
  end
  object RegOstNomDv: TpFIBDataSet
    SelectSQL.Strings = (
      'select '
      '  RGOSTNOM_DV.*, NAMEFIRM, NAMENOM, CODEPART, DOCPART, NAMESKLAD'
      'from '
      '  RGOSTNOM_DV'
      'left outer join SFIRM on IDFIRM_OSTNOMDV=IDFIRM'
      'left outer join SNOM on  IDNOM_OSTNOMDV=IDNOM'
      'left outer join SPART on IDPART_OSTNOMDV=IDPART'
      'left outer join SSKLAD on IDSKL_OSTNOMDV=IDSKLAD'
      ''
      'where IDDOC_OSTNOMDV=:PARAM_IDDOC')
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 144
    Top = 72
    object RegOstNomDvPOSDOC_OSTNOMDV: TFIBDateTimeField
      FieldName = 'POSDOC_OSTNOMDV'
    end
    object RegOstNomDvTDV_OSTNOMDV: TFIBSmallIntField
      FieldName = 'TDV_OSTNOMDV'
    end
    object RegOstNomDvSUM_OSTNOMDV: TFIBBCDField
      FieldName = 'SUM_OSTNOMDV'
      Size = 2
      RoundByScale = True
    end
    object RegOstNomDvKOL_OSTNOMDV: TFIBBCDField
      FieldName = 'KOL_OSTNOMDV'
      Size = 3
      RoundByScale = True
    end
    object RegOstNomDvOPER_OSTNOMDV: TFIBIntegerField
      FieldName = 'OPER_OSTNOMDV'
    end
    object RegOstNomDvSUM2_OSTNOMDV: TFIBBCDField
      FieldName = 'SUM2_OSTNOMDV'
      Size = 2
      RoundByScale = True
    end
    object RegOstNomDvNAMEFIRM: TFIBStringField
      FieldName = 'NAMEFIRM'
      Size = 50
      EmptyStrToNull = True
    end
    object RegOstNomDvNAMENOM: TFIBStringField
      FieldName = 'NAMENOM'
      Size = 50
      EmptyStrToNull = True
    end
    object RegOstNomDvCODEPART: TFIBIntegerField
      FieldName = 'CODEPART'
    end
    object RegOstNomDvDOCPART: TFIBStringField
      FieldName = 'DOCPART'
      Size = 50
      EmptyStrToNull = True
    end
    object RegOstNomDvNAMESKLAD: TFIBStringField
      FieldName = 'NAMESKLAD'
      Size = 50
      EmptyStrToNull = True
    end
    object RegOstNomDvID_OSTNOMDV: TFIBBCDField
      FieldName = 'ID_OSTNOMDV'
      Size = 0
      RoundByScale = True
    end
    object RegOstNomDvIDDOC_OSTNOMDV: TFIBBCDField
      FieldName = 'IDDOC_OSTNOMDV'
      Size = 0
      RoundByScale = True
    end
    object RegOstNomDvIDFIRM_OSTNOMDV: TFIBBCDField
      FieldName = 'IDFIRM_OSTNOMDV'
      Size = 0
      RoundByScale = True
    end
    object RegOstNomDvIDSKL_OSTNOMDV: TFIBBCDField
      FieldName = 'IDSKL_OSTNOMDV'
      Size = 0
      RoundByScale = True
    end
    object RegOstNomDvIDNOM_OSTNOMDV: TFIBBCDField
      FieldName = 'IDNOM_OSTNOMDV'
      Size = 0
      RoundByScale = True
    end
    object RegOstNomDvIDPART_OSTNOMDV: TFIBBCDField
      FieldName = 'IDPART_OSTNOMDV'
      Size = 0
      RoundByScale = True
    end
    object RegOstNomDvIDSTRDOC_OSTNOMDV: TFIBBCDField
      FieldName = 'IDSTRDOC_OSTNOMDV'
      Size = 0
      RoundByScale = True
    end
  end
  object IBQ: TpFIBDataSet
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 144
    Top = 128
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 224
    Top = 104
    qoStartTransaction = True
  end
end
