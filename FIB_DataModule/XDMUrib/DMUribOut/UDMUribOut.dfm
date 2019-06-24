object DMUribOut: TDMUribOut
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 339
  Width = 541
  object IBQ: TpFIBQuery
    Transaction = DM.pFIBTr
    Database = DM.pFIBData
    Left = 248
    Top = 16
    qoStartTransaction = True
  end
  object IBTr1: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 288
    Top = 16
  end
  object TableDataOut: TpFIBDataSet
    UpdateSQL.Strings = (
      'update XDATA_OUT'
      'set'
      '  IDMESSAGE_XDATA_OUT = :IDMESSAGE_XDATA_OUT'
      'where'
      '  ID_XDATA_OUT = :OLD_ID_XDATA_OUT')
    RefreshSQL.Strings = (
      'Select '
      '  ID_XDATA_OUT,'
      '  GID_XDATA_OUT,'
      '  IDTISM_XDATA_OUT,'
      '  IDBASE_XDATA_OUT,'
      '  IDMESSAGE_XDATA_OUT'
      'from XDATA_OUT '
      'where'
      '  ID_XDATA_OUT = :ID_XDATA_OUT')
    SelectSQL.Strings = (
      'select * '
      'from XDATA_OUT'
      'left outer join XTISM on IDTISM_XDATA_OUT=ID_XTISM'
      'where  IDMESSAGE_XDATA_OUT=:PARAM_IDMESSAGE')
    Transaction = IBTr
    Database = DM.pFIBData
    Left = 360
    Top = 16
    object TableDataOutID_XDATA_OUT: TFIBIntegerField
      FieldName = 'ID_XDATA_OUT'
    end
    object TableDataOutGID_XDATA_OUT: TFIBStringField
      FieldName = 'GID_XDATA_OUT'
      Size = 10
      EmptyStrToNull = True
    end
    object TableDataOutIDTISM_XDATA_OUT: TFIBIntegerField
      FieldName = 'IDTISM_XDATA_OUT'
    end
    object TableDataOutIDBASE_XDATA_OUT: TFIBIntegerField
      FieldName = 'IDBASE_XDATA_OUT'
    end
    object TableDataOutIDMESSAGE_XDATA_OUT: TFIBIntegerField
      FieldName = 'IDMESSAGE_XDATA_OUT'
    end
    object TableDataOutID_XTISM: TFIBIntegerField
      FieldName = 'ID_XTISM'
    end
    object TableDataOutGID_XTISM: TFIBStringField
      FieldName = 'GID_XTISM'
      Size = 10
      EmptyStrToNull = True
    end
    object TableDataOutPOS_XTISM: TFIBDateTimeField
      FieldName = 'POS_XTISM'
    end
    object TableDataOutNAMETAB_XTISM: TFIBStringField
      FieldName = 'NAMETAB_XTISM'
      EmptyStrToNull = True
    end
    object TableDataOutIDREC_XTISM: TFIBIntegerField
      FieldName = 'IDREC_XTISM'
    end
    object TableDataOutTYPEOB_XTISM: TFIBIntegerField
      FieldName = 'TYPEOB_XTISM'
    end
    object TableDataOutPRBASE_XTISM: TFIBStringField
      FieldName = 'PRBASE_XTISM'
      Size = 2
      EmptyStrToNull = True
    end
    object TableDataOutOPER_XTISM: TFIBIntegerField
      FieldName = 'OPER_XTISM'
    end
    object TableDataOutGIDREC_XTISM: TFIBStringField
      FieldName = 'GIDREC_XTISM'
      Size = 10
      EmptyStrToNull = True
    end
  end
  object IBTr: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 416
    Top = 16
  end
  object DocAll: TpFIBQuery
    Transaction = IBTr1
    Database = DM.pFIBData
    SQL.Strings = (
      'select TDOC,  PREFIKSDOC  from GALLDOC'
      'where IDDOC=:PARAM_IDDOC')
    Left = 200
    Top = 104
    qoStartTransaction = True
  end
  object Doc: TpFIBQuery
    Transaction = IBTr1
    Database = DM.pFIBData
    Left = 240
    Top = 104
    qoStartTransaction = True
  end
  object DocT: TpFIBQuery
    Transaction = IBTr1
    Database = DM.pFIBData
    Left = 280
    Top = 104
    qoStartTransaction = True
  end
  object IBQ2: TpFIBQuery
    Transaction = IBTr2
    Database = DM.pFIBData
    Left = 200
    Top = 168
    qoStartTransaction = True
  end
  object IBTr2: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 248
    Top = 168
  end
  object IBTrSys: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 464
    Top = 240
  end
  object TableFK: TpFIBDataSet
    SelectSQL.Strings = (
      
        'select re1.RDB$FIELD_NAME as field_name , RDB$RELATION_FIELDS.RD' +
        'B$FIELD_SOURCE as field_source,'
      
        'RDB$INDEX_SEGMENTS.RDB$FIELD_NAME as field_fk, RDB$RELATION_FIEL' +
        'DS.RDB$RELATION_NAME as table_fk'
      'from RDB$RELATION_FIELDS as       re1'
      
        'left outer join RDB$FIELDS  on re1.RDB$FIELD_SOURCE=RDB$FIELDS.R' +
        'DB$FIELD_NAME'
      
        'left outer join RDB$INDEX_SEGMENTS  as in1 on in1.RDB$FIELD_NAME' +
        '=re1.RDB$FIELD_NAME'
      
        'left outer join RDB$INDICES on in1.RDB$INDEX_NAME=RDB$INDICES.RD' +
        'B$INDEX_NAME'
      
        'left outer join RDB$INDEX_SEGMENTS on RDB$INDEX_SEGMENTS.RDB$IND' +
        'EX_NAME=RDB$INDICES.RDB$FOREIGN_KEY'
      
        'left outer join RDB$RELATION_FIELDS on RDB$RELATION_FIELDS.RDB$F' +
        'IELD_NAME=RDB$INDEX_SEGMENTS.RDB$FIELD_NAME'
      'where RDB$RELATION_FIELDS.RDB$SYSTEM_FLAG=0 '
      '')
    Transaction = IBTrSys
    Database = DM.pFIBData
    Left = 408
    Top = 240
    object TableFKFIELD_NAME: TFIBStringField
      FieldName = 'FIELD_NAME'
      Size = 31
      EmptyStrToNull = True
    end
    object TableFKFIELD_SOURCE: TFIBStringField
      FieldName = 'FIELD_SOURCE'
      Size = 31
      EmptyStrToNull = True
    end
    object TableFKFIELD_FK: TFIBStringField
      FieldName = 'FIELD_FK'
      Size = 31
      EmptyStrToNull = True
    end
    object TableFKTABLE_FK: TFIBStringField
      FieldName = 'TABLE_FK'
      Size = 31
      EmptyStrToNull = True
    end
  end
  object TablePK: TpFIBDataSet
    SelectSQL.Strings = (
      
        'select RDB$RELATION_FIELDS.RDB$FIELD_NAME AS FIELD_NAME, RDB$REL' +
        'ATION_FIELDS.RDB$RELATION_NAME AS TABLE_NAME'
      'from RDB$RELATION_FIELDS'
      
        'left outer join RDB$FIELDS on RDB$RELATION_FIELDS.RDB$FIELD_SOUR' +
        'CE=RDB$FIELDS.RDB$FIELD_NAME'
      ''
      ''
      'where RDB$RELATION_FIELDS.RDB$SYSTEM_FLAG=0  and'
      'RDB$RELATION_FIELDS.RDB$FIELD_SOURCE='#39'DOMAIN_IDTABLE'#39'  '
      '')
    Transaction = IBTrSys
    Database = DM.pFIBData
    Left = 352
    Top = 240
    object TablePKFIELD_NAME: TFIBStringField
      FieldName = 'FIELD_NAME'
      Size = 31
      EmptyStrToNull = True
    end
    object TablePKTABLE_NAME: TFIBStringField
      FieldName = 'TABLE_NAME'
      Size = 31
      EmptyStrToNull = True
    end
  end
  object TableFields: TpFIBDataSet
    SelectSQL.Strings = (
      'select * '
      'from RDB$RELATION_FIELDS'
      
        'left outer join RDB$FIELDS on RDB$RELATION_FIELDS.RDB$FIELD_SOUR' +
        'CE=RDB$FIELDS.RDB$FIELD_NAME'
      ''
      ''
      'where RDB$RELATION_FIELDS.RDB$SYSTEM_FLAG=0'
      'and RDB$RELATION_FIELDS.RDB$RELATION_NAME=:PARAM_NAMETABLE')
    Transaction = IBTrSys
    Database = DM.pFIBData
    Left = 296
    Top = 240
    object TableFieldsRDBFIELD_NAME: TFIBStringField
      FieldName = 'RDB$FIELD_NAME'
      Size = 31
      EmptyStrToNull = True
    end
    object TableFieldsRDBRELATION_NAME: TFIBStringField
      FieldName = 'RDB$RELATION_NAME'
      Size = 31
      EmptyStrToNull = True
    end
    object TableFieldsRDBFIELD_SOURCE: TFIBStringField
      FieldName = 'RDB$FIELD_SOURCE'
      Size = 31
      EmptyStrToNull = True
    end
    object TableFieldsRDBFIELD_TYPE: TFIBSmallIntField
      FieldName = 'RDB$FIELD_TYPE'
    end
    object TableFieldsRDBFIELD_SCALE: TFIBSmallIntField
      FieldName = 'RDB$FIELD_SCALE'
    end
  end
end
