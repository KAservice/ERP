object DMSprGrpNom: TDMSprGrpNom
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 224
  Width = 345
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 64
    Top = 24
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 64
    Top = 80
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select * '
      'from '
      '  SGRPNOM'
      'order by IDGRPGN')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 144
    Top = 24
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableIDGN: TFIBBCDField
      FieldName = 'IDGN'
      Size = 0
      RoundByScale = True
    end
    object TableIDGRPGN: TFIBBCDField
      FieldName = 'IDGRPGN'
      Size = 0
      RoundByScale = True
    end
    object TableNAMEGN: TFIBWideStringField
      FieldName = 'NAMEGN'
      Size = 100
    end
    object TableGID_SGRPNOM: TFIBWideStringField
      FieldName = 'GID_SGRPNOM'
      Size = 10
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SGRPNOM'
      'SET '
      '    NAMEGN = :NAMEGN,'
      '    IDGRPGN = :IDGRPGN,'
      '    GID_SGRPNOM = :GID_SGRPNOM,'
      '    IDBASE_SGRPNOM = :IDBASE_SGRPNOM,'
      '    IDEXT_DOUT_SGRPNOM = :IDEXT_DOUT_SGRPNOM,'
      '    IDEXT_BASE_SGRPNOM = :IDEXT_BASE_SGRPNOM,'
      '    IDVIDIMAGENABOR_SGRPNOM = :IDVIDIMAGENABOR_SGRPNOM,'
      '    IDPROPNABOR_SGRPNOM = :IDPROPNABOR_SGRPNOM'
      'WHERE'
      '    IDGN = :OLD_IDGN'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SGRPNOM'
      'WHERE'
      '        IDGN = :OLD_IDGN'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SGRPNOM('
      '    IDGN,'
      '    NAMEGN,'
      '    IDGRPGN,'
      '    GID_SGRPNOM,'
      '    IDBASE_SGRPNOM,'
      '    IDEXT_DOUT_SGRPNOM,'
      '    IDEXT_BASE_SGRPNOM,'
      '    IDVIDIMAGENABOR_SGRPNOM,'
      '    IDPROPNABOR_SGRPNOM'
      ')'
      'VALUES('
      '    :IDGN,'
      '    :NAMEGN,'
      '    :IDGRPGN,'
      '    :GID_SGRPNOM,'
      '    :IDBASE_SGRPNOM,'
      '    :IDEXT_DOUT_SGRPNOM,'
      '    :IDEXT_BASE_SGRPNOM,'
      '    :IDVIDIMAGENABOR_SGRPNOM,'
      '    :IDPROPNABOR_SGRPNOM'
      ')')
    RefreshSQL.Strings = (
      'select sgrpnom.*,'
      '        spropnabor.name_spropnabor,'
      '        svidimage_nabor.name_svidimage_nabor'
      'from SGRPNOM'
      
        'left outer join spropnabor on sgrpnom.idpropnabor_sgrpnom=spropn' +
        'abor.id_spropnabor'
      
        'left outer join svidimage_nabor on sgrpnom.idvidimagenabor_sgrpn' +
        'om=svidimage_nabor.id_svidimage_nabor'
      'where(  IDGN=:ID'
      '     ) and (     SGRPNOM.IDGN = :OLD_IDGN'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select sgrpnom.*,'
      '        spropnabor.name_spropnabor,'
      '        svidimage_nabor.name_svidimage_nabor'
      'from SGRPNOM'
      
        'left outer join spropnabor on sgrpnom.idpropnabor_sgrpnom=spropn' +
        'abor.id_spropnabor'
      
        'left outer join svidimage_nabor on sgrpnom.idvidimagenabor_sgrpn' +
        'om=svidimage_nabor.id_svidimage_nabor'
      'where IDGN=:ID')
    AutoUpdateOptions.UpdateTableName = 'SGRPNOM'
    AutoUpdateOptions.KeyFields = 'IDGN'
    AutoUpdateOptions.GeneratorName = 'GEN_SGRPNOM_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 80
    object ElementIDGN: TFIBBCDField
      FieldName = 'IDGN'
      Size = 0
      RoundByScale = True
    end
    object ElementIDGRPGN: TFIBBCDField
      FieldName = 'IDGRPGN'
      Size = 0
      RoundByScale = True
    end
    object ElementNAMEGN: TFIBWideStringField
      FieldName = 'NAMEGN'
      Size = 200
    end
    object ElementGID_SGRPNOM: TFIBWideStringField
      FieldName = 'GID_SGRPNOM'
      Size = 10
    end
    object ElementIDVIDIMAGENABOR_SGRPNOM: TFIBBCDField
      FieldName = 'IDVIDIMAGENABOR_SGRPNOM'
      Size = 0
      RoundByScale = True
    end
    object ElementIDPROPNABOR_SGRPNOM: TFIBBCDField
      FieldName = 'IDPROPNABOR_SGRPNOM'
      Size = 0
      RoundByScale = True
    end
    object ElementNAME_SPROPNABOR: TFIBWideStringField
      FieldName = 'NAME_SPROPNABOR'
      Size = 200
    end
    object ElementNAME_SVIDIMAGE_NABOR: TFIBWideStringField
      FieldName = 'NAME_SVIDIMAGE_NABOR'
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
    Left = 216
    Top = 24
  end
  object IBTrUpdate: TpFIBTransaction
    TimeoutAction = TARollback
    Left = 216
    Top = 80
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 272
    Top = 56
    qoStartTransaction = True
  end
end
