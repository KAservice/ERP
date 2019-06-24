object DMGurZakRest: TDMGurZakRest
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Left = 744
  Top = 156
  Height = 173
  Width = 261
  object Table: TIBQuery
    Database = DM.IBData
    Transaction = IBTr
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      'select '
      '  NUMDOC, POSDOC, PRDOC, SUMDOC, IDDOC,'
      '  NAMEKKM,'
      '  NAMEFIRM,'
      '  NAMESKLAD, '
      '  NAMEKLIENT, '
      '  NAME_USER'
      'from '
      '  DCHK'
      'left outer join SKKM on IDKKMCHK=IDKKM'
      'left outer join GALLDOC on IDDOCCHK=IDDOC'
      'left outer join SFIRM on IDFIRMDOC=IDFIRM'
      'left outer join SSKLAD on IDSKLDOC=IDSKLAD'
      'left outer join SKLIENT on IDKLDOC=IDKLIENT'
      'left outer join SUSER on  IDUSERDOC= ID_USER'
      'where POSDOC between  :PARAM_DATE_NACH and :PARAM_DATE_CON'
      'order by POSDOC')
    Left = 136
    Top = 16
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'PARAM_DATE_NACH'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'PARAM_DATE_CON'
        ParamType = ptUnknown
      end>
    object TableNUMDOC: TIntegerField
      FieldName = 'NUMDOC'
      Origin = 'GALLDOC.NUMDOC'
    end
    object TablePOSDOC: TDateTimeField
      FieldName = 'POSDOC'
      Origin = 'GALLDOC.POSDOC'
    end
    object TablePRDOC: TSmallintField
      FieldName = 'PRDOC'
      Origin = 'GALLDOC.PRDOC'
    end
    object TableSUMDOC: TIBBCDField
      FieldName = 'SUMDOC'
      Origin = 'GALLDOC.SUMDOC'
      DisplayFormat = '.00'
      Precision = 18
      Size = 2
    end
    object TableIDDOC: TIntegerField
      FieldName = 'IDDOC'
      Origin = 'GALLDOC.IDDOC'
    end
    object TableNAMEKKM: TIBStringField
      FieldName = 'NAMEKKM'
      Origin = 'SKKM.NAMEKKM'
      Size = 50
    end
    object TableNAMEFIRM: TIBStringField
      FieldName = 'NAMEFIRM'
      Origin = 'SFIRM.NAMEFIRM'
      Size = 50
    end
    object TableNAMESKLAD: TIBStringField
      FieldName = 'NAMESKLAD'
      Origin = 'SSKLAD.NAMESKLAD'
      Size = 50
    end
    object TableNAMEKLIENT: TIBStringField
      FieldName = 'NAMEKLIENT'
      Origin = 'SKLIENT.NAMEKLIENT'
      Size = 50
    end
    object TableNAME_USER: TIBStringField
      FieldName = 'NAME_USER'
      Origin = 'SUSER.NAME_USER'
    end
  end
  object IBTr: TIBTransaction
    Active = True
    DefaultDatabase = DM.IBData
    DefaultAction = TARollback
    Params.Strings = (
      'read_committed'
      'rec_version'
      'nowait')
    AutoStopAction = saNone
    Left = 200
    Top = 16
  end
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 16
  end
end
