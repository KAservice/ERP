object DMSprSeller: TDMSprSeller
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 200
  Width = 675
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 40
    Top = 16
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 40
    Top = 80
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select sseller.*,'
      '    sklient.nameklient,'
      '    sklient.innklient'
      'from sseller'
      
        'left outer join sklient on sseller.idklient_sseller=sklient.idkl' +
        'ient'
      'order by sseller.name_sseller')
    Transaction = IBTr
    Left = 144
    Top = 16
    poUseLargeIntField = True
    object TableID_SSELLER: TFIBLargeIntField
      FieldName = 'ID_SSELLER'
    end
    object TableIDBASE_SSELLER: TFIBLargeIntField
      FieldName = 'IDBASE_SSELLER'
    end
    object TableNAME_SSELLER: TFIBWideStringField
      FieldName = 'NAME_SSELLER'
      Size = 200
    end
    object TableADR_SSELLER: TFIBWideStringField
      FieldName = 'ADR_SSELLER'
      Size = 200
    end
    object TablePHONE_SSELLER: TFIBWideStringField
      FieldName = 'PHONE_SSELLER'
      Size = 200
    end
    object TableIDKLIENT_SSELLER: TFIBLargeIntField
      FieldName = 'IDKLIENT_SSELLER'
    end
    object TableNAME_FOR_PRINT_SSELLER: TFIBWideStringField
      FieldName = 'NAME_FOR_PRINT_SSELLER'
      Size = 200
    end
    object TableNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 200
    end
    object TableINNKLIENT: TFIBWideStringField
      FieldName = 'INNKLIENT'
      Size = 12
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SSELLER'
      'SET '
      '    IDBASE_SSELLER = :IDBASE_SSELLER,'
      '    NAME_SSELLER = :NAME_SSELLER,'
      '    ADR_SSELLER = :ADR_SSELLER,'
      '    PHONE_SSELLER = :PHONE_SSELLER,'
      '    IDKLIENT_SSELLER = :IDKLIENT_SSELLER,'
      '    NAME_FOR_PRINT_SSELLER = :NAME_FOR_PRINT_SSELLER'
      'WHERE'
      '    ID_SSELLER = :OLD_ID_SSELLER'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SSELLER'
      'WHERE'
      '        ID_SSELLER = :OLD_ID_SSELLER'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SSELLER('
      '    ID_SSELLER,'
      '    IDBASE_SSELLER,'
      '    NAME_SSELLER,'
      '    ADR_SSELLER,'
      '    PHONE_SSELLER,'
      '    IDKLIENT_SSELLER,'
      '    NAME_FOR_PRINT_SSELLER'
      ')'
      'VALUES('
      '    :ID_SSELLER,'
      '    :IDBASE_SSELLER,'
      '    :NAME_SSELLER,'
      '    :ADR_SSELLER,'
      '    :PHONE_SSELLER,'
      '    :IDKLIENT_SSELLER,'
      '    :NAME_FOR_PRINT_SSELLER'
      ')')
    RefreshSQL.Strings = (
      'select sseller.*,'
      '       sklient.nameklient'
      'from sseller'
      
        'left outer join sklient on sseller.idklient_sseller=sklient.idkl' +
        'ient'
      'where(  sseller.id_sseller=:PARAM_ID'
      '     ) and (     SSELLER.ID_SSELLER = :OLD_ID_SSELLER'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select sseller.*,'
      '       sklient.nameklient'
      'from sseller'
      
        'left outer join sklient on sseller.idklient_sseller=sklient.idkl' +
        'ient'
      'where sseller.id_sseller=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SSELLER'
    AutoUpdateOptions.KeyFields = 'ID_SSELLER'
    AutoUpdateOptions.GeneratorName = 'GEN_SSELLER_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 80
    poUseLargeIntField = True
    object ElementID_SSELLER: TFIBLargeIntField
      FieldName = 'ID_SSELLER'
    end
    object ElementIDBASE_SSELLER: TFIBLargeIntField
      FieldName = 'IDBASE_SSELLER'
    end
    object ElementNAME_SSELLER: TFIBWideStringField
      FieldName = 'NAME_SSELLER'
      Size = 200
    end
    object ElementADR_SSELLER: TFIBWideStringField
      FieldName = 'ADR_SSELLER'
      Size = 200
    end
    object ElementPHONE_SSELLER: TFIBWideStringField
      FieldName = 'PHONE_SSELLER'
      Size = 200
    end
    object ElementIDKLIENT_SSELLER: TFIBLargeIntField
      FieldName = 'IDKLIENT_SSELLER'
    end
    object ElementNAME_FOR_PRINT_SSELLER: TFIBWideStringField
      FieldName = 'NAME_FOR_PRINT_SSELLER'
      Size = 200
    end
    object ElementNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
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
    Left = 224
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
    Left = 224
    Top = 80
  end
  object pFIBQ: TpFIBQuery
    Left = 280
    Top = 56
    qoStartTransaction = True
  end
end
