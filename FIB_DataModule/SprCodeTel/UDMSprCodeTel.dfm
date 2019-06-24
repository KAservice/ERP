object DMSprCodeTel: TDMSprCodeTel
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 266
  Width = 435
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 48
    Top = 72
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      '   select SCODETEL.*,'
      '   NOM.NAMENOM as NAMENOM,'
      
        '   nom_department.numotdkkt_sdepartment as nom_department_numotd' +
        'kkt_sdepartment,'
      
        '   nom_department.id_sdepartment as  nom_department_id_sdepartme' +
        'nt,'
      '   NOMCOM.NAMENOM as NAMENOMCOM,'
      
        '   com_department.numotdkkt_sdepartment as com_department_numotd' +
        'kkt_sdepartment,'
      
        '   com_department.id_sdepartment as  com_department_id_sdepartme' +
        'nt'
      'from '
      '  SCODETEL'
      'left outer join SNOM as NOM on IDNOM_CODETEL=NOM.IDNOM'
      
        'left outer join sdepartment as nom_department on NOM.iddepartmen' +
        't_snom=nom_department.id_sdepartment'
      ''
      ''
      'left outer join SNOM as NOMCOM on IDNOMCOM_CODETEL=NOMCOM.IDNOM'
      
        'left outer join sdepartment as com_department on NOMCOM.iddepart' +
        'ment_snom=com_department.id_sdepartment')
    Transaction = IBTr
    Left = 152
    Top = 16
    poUseLargeIntField = True
    object TableID_CODETEL: TFIBLargeIntField
      FieldName = 'ID_CODETEL'
    end
    object TableIDNOM_CODETEL: TFIBLargeIntField
      FieldName = 'IDNOM_CODETEL'
    end
    object TableCODE_CODETEL: TFIBWideStringField
      FieldName = 'CODE_CODETEL'
      Size = 3
    end
    object TableGID_SCODETEL: TFIBWideStringField
      FieldName = 'GID_SCODETEL'
      Size = 10
    end
    object TableNAME_CODETEL: TFIBWideStringField
      FieldName = 'NAME_CODETEL'
      Size = 200
    end
    object TableCODOPER_CODETEL: TFIBWideStringField
      FieldName = 'CODOPER_CODETEL'
      Size = 5
    end
    object TableIDNOMCOM_CODETEL: TFIBLargeIntField
      FieldName = 'IDNOMCOM_CODETEL'
    end
    object TableIDBASE_SCODETEL: TFIBLargeIntField
      FieldName = 'IDBASE_SCODETEL'
    end
    object TablePRCOMIS_SCODETEL: TFIBBCDField
      FieldName = 'PRCOMIS_SCODETEL'
      Size = 2
      RoundByScale = True
    end
    object TableNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object TableNOM_DEPARTMENT_NUMOTDKKT_SDEPAR: TFIBIntegerField
      FieldName = 'NOM_DEPARTMENT_NUMOTDKKT_SDEPAR'
    end
    object TableNOM_DEPARTMENT_ID_SDEPARTMENT: TFIBLargeIntField
      FieldName = 'NOM_DEPARTMENT_ID_SDEPARTMENT'
    end
    object TableNAMENOMCOM: TFIBWideStringField
      FieldName = 'NAMENOMCOM'
      Size = 200
    end
    object TableCOM_DEPARTMENT_NUMOTDKKT_SDEPAR: TFIBIntegerField
      FieldName = 'COM_DEPARTMENT_NUMOTDKKT_SDEPAR'
    end
    object TableCOM_DEPARTMENT_ID_SDEPARTMENT: TFIBLargeIntField
      FieldName = 'COM_DEPARTMENT_ID_SDEPARTMENT'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SCODETEL'
      'SET '
      '    IDNOM_CODETEL = :IDNOM_CODETEL,'
      '    CODE_CODETEL = :CODE_CODETEL,'
      '    GID_SCODETEL = :GID_SCODETEL,'
      '    NAME_CODETEL = :NAME_CODETEL,'
      '    CODOPER_CODETEL = :CODOPER_CODETEL,'
      '    IDNOMCOM_CODETEL = :IDNOMCOM_CODETEL,'
      '    IDBASE_SCODETEL = :IDBASE_SCODETEL,'
      '    PRCOMIS_SCODETEL = :PRCOMIS_SCODETEL'
      'WHERE'
      '    ID_CODETEL = :OLD_ID_CODETEL'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SCODETEL'
      'WHERE'
      '        ID_CODETEL = :OLD_ID_CODETEL'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SCODETEL('
      '    ID_CODETEL,'
      '    IDNOM_CODETEL,'
      '    CODE_CODETEL,'
      '    GID_SCODETEL,'
      '    NAME_CODETEL,'
      '    CODOPER_CODETEL,'
      '    IDNOMCOM_CODETEL,'
      '    IDBASE_SCODETEL,'
      '    PRCOMIS_SCODETEL'
      ')'
      'VALUES('
      '    :ID_CODETEL,'
      '    :IDNOM_CODETEL,'
      '    :CODE_CODETEL,'
      '    :GID_SCODETEL,'
      '    :NAME_CODETEL,'
      '    :CODOPER_CODETEL,'
      '    :IDNOMCOM_CODETEL,'
      '    :IDBASE_SCODETEL,'
      '    :PRCOMIS_SCODETEL'
      ')')
    RefreshSQL.Strings = (
      
        '   select SCODETEL.*, NOM.NAMENOM as NAMENOM, NOMCOM.NAMENOM as ' +
        'NAMENOMCOM'
      'from '
      '  SCODETEL'
      'left outer join SNOM as NOM on IDNOM_CODETEL=NOM.IDNOM'
      'left outer join SNOM as NOMCOM on IDNOMCOM_CODETEL=NOMCOM.IDNOM'
      'where(  '
      '  ID_CODETEL=:PARAM_ID'
      '     ) and (     SCODETEL.ID_CODETEL = :OLD_ID_CODETEL'
      '     )'
      '    ')
    SelectSQL.Strings = (
      
        '   select SCODETEL.*, NOM.NAMENOM as NAMENOM, NOMCOM.NAMENOM as ' +
        'NAMENOMCOM'
      'from '
      '  SCODETEL'
      'left outer join SNOM as NOM on IDNOM_CODETEL=NOM.IDNOM'
      'left outer join SNOM as NOMCOM on IDNOMCOM_CODETEL=NOMCOM.IDNOM'
      'where '
      '  ID_CODETEL=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SCODETEL'
    AutoUpdateOptions.KeyFields = 'ID_CODETEL'
    AutoUpdateOptions.GeneratorName = 'GEN_SCODETEL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 72
    poUseLargeIntField = True
    object ElementID_CODETEL: TFIBLargeIntField
      FieldName = 'ID_CODETEL'
    end
    object ElementIDNOM_CODETEL: TFIBLargeIntField
      FieldName = 'IDNOM_CODETEL'
    end
    object ElementCODE_CODETEL: TFIBWideStringField
      FieldName = 'CODE_CODETEL'
      Size = 3
    end
    object ElementGID_SCODETEL: TFIBWideStringField
      FieldName = 'GID_SCODETEL'
      Size = 10
    end
    object ElementNAME_CODETEL: TFIBWideStringField
      FieldName = 'NAME_CODETEL'
      Size = 200
    end
    object ElementCODOPER_CODETEL: TFIBWideStringField
      FieldName = 'CODOPER_CODETEL'
      Size = 5
    end
    object ElementIDNOMCOM_CODETEL: TFIBLargeIntField
      FieldName = 'IDNOMCOM_CODETEL'
    end
    object ElementIDBASE_SCODETEL: TFIBLargeIntField
      FieldName = 'IDBASE_SCODETEL'
    end
    object ElementPRCOMIS_SCODETEL: TFIBBCDField
      FieldName = 'PRCOMIS_SCODETEL'
      Size = 2
      RoundByScale = True
    end
    object ElementNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object ElementNAMENOMCOM: TFIBWideStringField
      FieldName = 'NAMENOMCOM'
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
    Left = 248
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
    Left = 248
    Top = 72
  end
end
