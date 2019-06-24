object DMSprCatNom: TDMSprCatNom
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 173
  Width = 273
  object Table: TIBQuery
    Transaction = IBTr
    OnCalcFields = TableCalcFields
    SQL.Strings = (
      'select'
      '   ID_CATNOM,  KOL_CATNOM,  NAME_CATNOM'
      'from'
      '  SCATNOM')
    Left = 144
    Top = 16
    object TableID_CATNOM: TIntegerField
      FieldName = 'ID_CATNOM'
      Origin = 'SCATNOM.ID_CATNOM'
      Required = True
    end
    object TableKOL_CATNOM: TIntegerField
      FieldName = 'KOL_CATNOM'
      Origin = 'SCATNOM.KOL_CATNOM'
    end
    object TableNAME_CATNOM: TIBStringField
      FieldName = 'NAME_CATNOM'
      Origin = 'SCATNOM.NAME_CATNOM'
      Size = 50
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
  end
  object IBTr: TIBTransaction
    Params.Strings = (
      'read_committed'
      'rec_version'
      'nowait')
    Left = 208
    Top = 48
  end
  object Element: TIBDataSet
    Transaction = IBTr
    OnCalcFields = ElementCalcFields
    OnNewRecord = ElementNewRecord
    CachedUpdates = True
    DeleteSQL.Strings = (
      'delete from SCATNOM'
      'where'
      '  ID_CATNOM = :OLD_ID_CATNOM')
    InsertSQL.Strings = (
      'insert into SCATNOM'
      
        '  (ID_CATNOM, IDNOM_CATNOM, NAME_CATNOM, KOL_CATNOM, GID_SCATNOM' +
        ')'
      'values'
      
        '  (:ID_CATNOM, :IDNOM_CATNOM, :NAME_CATNOM, :KOL_CATNOM, :GID_SC' +
        'ATNOM)')
    RefreshSQL.Strings = (
      'select SCATNOM.*, NAMENOM'
      'from '
      '  SCATNOM'
      'left outer join SNOM on IDNOM_CATNOM=IDNOM'
      'where'
      '  ID_CATNOM = :ID_CATNOM')
    SelectSQL.Strings = (
      'select SCATNOM.*, NAMENOM'
      'from '
      '  SCATNOM'
      'left outer join SNOM on IDNOM_CATNOM=IDNOM'
      'where '
      '  ID_CATNOM=:PARAM_ID')
    ModifySQL.Strings = (
      'update SCATNOM'
      'set'
      '  ID_CATNOM = :ID_CATNOM,'
      '  IDNOM_CATNOM = :IDNOM_CATNOM,'
      '  NAME_CATNOM = :NAME_CATNOM,'
      '  KOL_CATNOM = :KOL_CATNOM,'
      '  GID_SCATNOM = :GID_SCATNOM'
      'where'
      '  ID_CATNOM = :OLD_ID_CATNOM')
    GeneratorField.Field = 'ID_CATNOM'
    GeneratorField.Generator = 'GEN_SCATNOM_ID'
    Left = 144
    Top = 72
    object ElementID_CATNOM: TIntegerField
      FieldName = 'ID_CATNOM'
      Origin = 'SCATNOM.ID_CATNOM'
      Required = True
    end
    object ElementIDNOM_CATNOM: TIntegerField
      FieldName = 'IDNOM_CATNOM'
      Origin = 'SCATNOM.IDNOM_CATNOM'
    end
    object ElementNAME_CATNOM: TIBStringField
      FieldName = 'NAME_CATNOM'
      Origin = 'SCATNOM.NAME_CATNOM'
      Size = 50
    end
    object ElementKOL_CATNOM: TIntegerField
      FieldName = 'KOL_CATNOM'
      Origin = 'SCATNOM.KOL_CATNOM'
    end
    object ElementNAMENOM: TIBStringField
      FieldName = 'NAMENOM'
      Origin = 'SNOM.NAMENOM'
      Size = 50
    end
    object ElementGID_SCATNOM: TIBStringField
      FieldName = 'GID_SCATNOM'
      Origin = 'SCATNOM.GID_SCATNOM'
      Size = 10
    end
  end
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
end
