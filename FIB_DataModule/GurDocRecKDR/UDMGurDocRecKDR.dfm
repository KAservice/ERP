object DMGurDocRecKDR: TDMGurDocRecKDR
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 83
  Width = 271
  object DataSourceTable: TDataSource
    Left = 56
    Top = 16
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select '
      
        '  NUMDOC, POSDOC, PRDOC,  IDDOC, DOHOD_DREC_KDR, RASHOD_DREC_KDR' +
        ', OPERATION_DREC_KDR,'
      '  NAMEFIRM,'
      '  NAME_USER'
      'from '
      '  DREC_KDR'
      'left outer join GALLDOC on IDDOC_DREC_KDR=IDDOC'
      'left outer join SFIRM on IDFIRMDOC=IDFIRM'
      'left outer join SUSER on  IDUSERDOC= ID_USER'
      'where POSDOC between  :PARAM_DATE_NACH and :PARAM_DATE_CON'
      'order by POSDOC')
    Transaction = IBTr
    Database = DM.pFIBData
    Left = 152
    Top = 16
    object TableNUMDOC: TFIBIntegerField
      FieldName = 'NUMDOC'
    end
    object TablePOSDOC: TFIBDateTimeField
      FieldName = 'POSDOC'
      DisplayFormat = 'c'
    end
    object TablePRDOC: TFIBSmallIntField
      FieldName = 'PRDOC'
    end
    object TableIDDOC: TFIBIntegerField
      FieldName = 'IDDOC'
    end
    object TableDOHOD_DREC_KDR: TFIBBCDField
      FieldName = 'DOHOD_DREC_KDR'
      Size = 2
      RoundByScale = True
    end
    object TableRASHOD_DREC_KDR: TFIBBCDField
      FieldName = 'RASHOD_DREC_KDR'
      Size = 2
      RoundByScale = True
    end
    object TableOPERATION_DREC_KDR: TFIBStringField
      FieldName = 'OPERATION_DREC_KDR'
      Size = 100
      EmptyStrToNull = True
    end
    object TableNAMEFIRM: TFIBStringField
      FieldName = 'NAMEFIRM'
      Size = 50
      EmptyStrToNull = True
    end
    object TableNAME_USER: TFIBStringField
      FieldName = 'NAME_USER'
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
    TPBMode = tpbDefault
    Left = 216
    Top = 16
  end
end
