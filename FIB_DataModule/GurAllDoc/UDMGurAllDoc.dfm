object DMGurAllDoc: TDMGurAllDoc
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 297
  Width = 428
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 16
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select '
      'GALLDOC.*, NAMEFIRM, NAMESKLAD, NAMEKLIENT, NAME_USER,'
      '  NAME_SPROJECT,'
      '  sinfbase_obmen.name_sinfbase_obmen'
      'from '
      'GALLDOC'
      ''
      
        'left outer join sinfbase_obmen on sinfbase_obmen.id_sinfbase_obm' +
        'en=galldoc.idbase_galldoc'
      'LEFT OUTER JOIN SFIRM ON IDFIRMDOC=IDFIRM'
      'left outer join SSKLAD on IDSKLDOC=IDSKLAD'
      'left outer join SKLIENT on IDKLDOC=IDKLIENT'
      'left outer join SUSER on  IDUSERDOC= ID_USER'
      'left outer join SPROJECT on IDPROJECT_GALLDOC=ID_SPROJECT'
      'where POSDOC between  :PARAM_DATE_NACH and :PARAM_DATE_CON AND '
      'TDOC in (:PARAM_TDOC)'
      'order by POSDOC')
    Transaction = IBTr
    Left = 144
    Top = 16
    object TablePRDOC: TFIBSmallIntField
      FieldName = 'PRDOC'
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
    object TableTDOC: TFIBWideStringField
      FieldName = 'TDOC'
      OnGetText = TableTDOCGetText
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
    object TableTYPEEXTDOC: TFIBIntegerField
      FieldName = 'TYPEEXTDOC'
    end
    object TableNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 200
    end
    object TableNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 200
    end
    object TableNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 200
    end
    object TableNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
      Size = 200
    end
    object TableNAME_SPROJECT: TFIBWideStringField
      FieldName = 'NAME_SPROJECT'
      Size = 200
    end
    object TablePREFIKS_NUM_GALLDOC: TFIBWideStringField
      FieldName = 'PREFIKS_NUM_GALLDOC'
      Size = 12
    end
    object TableIDBUSINOP_GALLDOC: TFIBBCDField
      FieldName = 'IDBUSINOP_GALLDOC'
      Size = 0
      RoundByScale = True
    end
    object TableNAME_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 200
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
    Left = 232
    Top = 16
  end
  object IBQ: TpFIBDataSet
    Transaction = IBTr
    Left = 144
    Top = 128
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 224
    Top = 104
    qoStartTransaction = True
  end
end
