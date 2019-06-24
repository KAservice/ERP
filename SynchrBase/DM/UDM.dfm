object DM: TDM
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 393
  Width = 521
  object Database1: TpFIBDatabase
    DBParams.Strings = (
      'user_name=SYSDBA'
      'password=masterkey'
      'lc_ctype=UTF8')
    DefaultTransaction = TrRead1
    DefaultUpdateTransaction = TrRead1
    SQLDialect = 3
    Timeout = 0
    LibraryName = 'fbclient.dll'
    WaitForRestoreConnect = 0
    Left = 32
    Top = 32
  end
  object TrRead1: TpFIBTransaction
    DefaultDatabase = Database1
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 120
    Top = 32
  end
  object Database2: TpFIBDatabase
    DBParams.Strings = (
      'user_name=SYSDBA'
      'password=masterkey'
      'lc_ctype=UTF8')
    DefaultTransaction = TrRead2
    DefaultUpdateTransaction = TrUpdate2
    SQLDialect = 3
    Timeout = 0
    LibraryName = 'fbclient.dll'
    WaitForRestoreConnect = 0
    Left = 32
    Top = 208
  end
  object TrRead2: TpFIBTransaction
    DefaultDatabase = Database2
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 120
    Top = 208
  end
  object TrUpdate2: TpFIBTransaction
    DefaultDatabase = Database2
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 184
    Top = 208
  end
  object Tables: TpFIBDataSet
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
      'ORDER BY TABLE_NAME')
    Transaction = TrRead1
    Database = Database1
    Left = 424
    Top = 32
    object TablesFIELD_NAME: TFIBWideStringField
      FieldName = 'FIELD_NAME'
      Size = 31
    end
    object TablesTABLE_NAME: TFIBWideStringField
      FieldName = 'TABLE_NAME'
      Size = 31
    end
  end
  object Fields: TpFIBDataSet
    SelectSQL.Strings = (
      'select * '
      'from RDB$RELATION_FIELDS'
      
        'left outer join RDB$FIELDS on RDB$RELATION_FIELDS.RDB$FIELD_SOUR' +
        'CE=RDB$FIELDS.RDB$FIELD_NAME'
      ''
      ''
      'where RDB$RELATION_FIELDS.RDB$SYSTEM_FLAG=0'
      'and RDB$RELATION_FIELDS.RDB$RELATION_NAME=:TABLE_NAME')
    Transaction = TrRead1
    Database = Database1
    DataSource = DataSourceTables
    Left = 424
    Top = 96
    object FieldsRDBFIELD_NAME: TFIBWideStringField
      FieldName = 'RDB$FIELD_NAME'
      Size = 31
    end
    object FieldsRDBFIELD_SOURCE: TFIBWideStringField
      FieldName = 'RDB$FIELD_SOURCE'
      Size = 31
    end
  end
  object DataSourceTables: TDataSource
    DataSet = Tables
    Left = 344
    Top = 32
  end
  object DataSourceFields: TDataSource
    DataSet = Fields
    Left = 344
    Top = 96
  end
  object Table1Base: TpFIBQuery
    Transaction = TrRead1
    Database = Database1
    Left = 208
    Top = 88
    qoStartTransaction = True
  end
  object Element2Base: TpFIBQuery
    Transaction = TrUpdate2
    Database = Database2
    Left = 280
    Top = 208
    qoStartTransaction = True
  end
  object Query: TpFIBQuery
    Transaction = TrUpdate2
    Database = Database2
    Left = 280
    Top = 264
    qoStartTransaction = True
  end
  object QueryRecordCount: TpFIBQuery
    Transaction = TrRead1
    Database = Database1
    Left = 208
    Top = 24
    qoStartTransaction = True
  end
  object pFIBSecurityService1: TpFIBSecurityService
    LibraryName = 'fbclient.dll'
    Protocol = TCP
    LoginPrompt = False
    SecurityAction = ActionDisplayUser
    UserID = 0
    GroupID = 0
    Left = 280
    Top = 320
  end
  object SprUser: TpFIBDataSet
    SelectSQL.Strings = (
      'select suser.name_user,'
      '        suser.name2_user,'
      '        sgrpuser.role_sgrpuser'
      'from suser'
      
        'left outer join sgrpuser on suser.idgrp_user=sgrpuser.id_sgrpuse' +
        'r')
    Transaction = TrRead2
    Database = Database2
    Left = 400
    Top = 320
    poUseLargeIntField = True
    object SprUserNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
      Size = 100
    end
    object SprUserNAME2_USER: TFIBWideStringField
      FieldName = 'NAME2_USER'
    end
    object SprUserROLE_SGRPUSER: TFIBWideStringField
      FieldName = 'ROLE_SGRPUSER'
    end
  end
end
