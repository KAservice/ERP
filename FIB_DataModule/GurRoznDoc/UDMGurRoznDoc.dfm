object DMGurRoznDoc: TDMGurRoznDoc
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 186
  Width = 249
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 16
  end
  object IBQ: TpFIBDataSet
    Transaction = IBTr
    Left = 144
    Top = 72
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select '
      'GALLDOC.*, NAMEFIRM, NAMESKLAD, NAMEKLIENT, NAME_USER'
      'from '
      'GALLDOC LEFT OUTER JOIN SFIRM ON IDFIRMDOC=IDFIRM'
      'left outer join SSKLAD on IDSKLDOC=IDSKLAD'
      'left outer join SKLIENT on IDKLDOC=IDKLIENT'
      'left outer join SUSER on  IDUSERDOC= ID_USER'
      'where POSDOC between  :PARAM_DATE_NACH and :PARAM_DATE_CON AND '
      'TDOC in (:PARAM_TDOC)  AND IDBASE_GALLDOC=:PARAM_IDBASE'
      'order by POSDOC'
      ''
      '')
    Transaction = IBTr
    Left = 144
    Top = 16
    object TablePOSDOC: TFIBDateTimeField
      FieldName = 'POSDOC'
      DisplayFormat = 'c'
    end
    object TablePRDOC: TFIBSmallIntField
      FieldName = 'PRDOC'
    end
    object TableNUMDOC: TFIBIntegerField
      FieldName = 'NUMDOC'
    end
    object TableSUMDOC: TFIBBCDField
      FieldName = 'SUMDOC'
      Size = 2
      RoundByScale = True
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
    object TableIDBASE_GALLDOC: TFIBBCDField
      FieldName = 'IDBASE_GALLDOC'
      Size = 0
      RoundByScale = True
    end
    object TableTDOC: TFIBWideStringField
      FieldName = 'TDOC'
      Size = 10
    end
    object TableGID_DOC: TFIBWideStringField
      FieldName = 'GID_DOC'
      Size = 10
    end
    object TablePREFIKSDOC: TFIBWideStringField
      FieldName = 'PREFIKSDOC'
      Size = 2
    end
    object TableIDPROJECT_GALLDOC: TFIBBCDField
      FieldName = 'IDPROJECT_GALLDOC'
      Size = 0
      RoundByScale = True
    end
    object TableNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 100
    end
    object TableNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 100
    end
    object TableNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 100
    end
    object TableNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
      Size = 100
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
    Left = 144
    Top = 128
  end
  object Query: TpFIBQuery
    Transaction = IBTr
    Left = 200
    Top = 72
    qoStartTransaction = True
  end
end
