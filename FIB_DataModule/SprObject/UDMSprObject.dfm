object DMSprObject: TDMSprObject
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
      'select sobject.*,'
      '    sinfbase_obmen.name_sinfbase_obmen,'
      '    sfirm.namefirm,'
      '    ssklad.namesklad,'
      '    skkm.namekkm,'
      '    spod.namepod'
      'from sobject'
      
        'left outer join sinfbase_obmen on sobject.idinfbase_sobject=sinf' +
        'base_obmen.id_sinfbase_obmen'
      'left outer join ssklad on sobject.idsklad_sobject=ssklad.idsklad'
      'left outer join sfirm on sobject.idfirm_sobject=sfirm.idfirm'
      'left outer join skkm on sobject.idkassa_sobject=skkm.idkkm'
      'left outer join spod on sobject.idpodr_sobject=spod.idpod')
    Transaction = IBTr
    Left = 144
    Top = 16
    poUseLargeIntField = True
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_SOBJECT: TFIBLargeIntField
      FieldName = 'ID_SOBJECT'
    end
    object TableNAME_SOBJECT: TFIBWideStringField
      FieldName = 'NAME_SOBJECT'
      Size = 200
    end
    object TableIDINFBASE_SOBJECT: TFIBLargeIntField
      FieldName = 'IDINFBASE_SOBJECT'
    end
    object TableIDFIRM_SOBJECT: TFIBLargeIntField
      FieldName = 'IDFIRM_SOBJECT'
    end
    object TableIDSKLAD_SOBJECT: TFIBLargeIntField
      FieldName = 'IDSKLAD_SOBJECT'
    end
    object TableIDKASSA_SOBJECT: TFIBLargeIntField
      FieldName = 'IDKASSA_SOBJECT'
    end
    object TableIDPODR_SOBJECT: TFIBLargeIntField
      FieldName = 'IDPODR_SOBJECT'
    end
    object TableNAME_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 200
    end
    object TableNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 200
    end
    object TableNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 200
    end
    object TableNAMEKKM: TFIBWideStringField
      FieldName = 'NAMEKKM'
      Size = 200
    end
    object TableNAMEPOD: TFIBWideStringField
      FieldName = 'NAMEPOD'
      Size = 200
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SOBJECT'
      'SET '
      '    IDBASE_SOBJECT = :IDBASE_SOBJECT,'
      '    NAME_SOBJECT = :NAME_SOBJECT,'
      '    IDINFBASE_SOBJECT = :IDINFBASE_SOBJECT,'
      '    IDFIRM_SOBJECT = :IDFIRM_SOBJECT,'
      '    IDSKLAD_SOBJECT = :IDSKLAD_SOBJECT,'
      '    IDKASSA_SOBJECT = :IDKASSA_SOBJECT,'
      '    IDPODR_SOBJECT = :IDPODR_SOBJECT'
      'WHERE'
      '    ID_SOBJECT = :OLD_ID_SOBJECT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SOBJECT'
      'WHERE'
      '        ID_SOBJECT = :OLD_ID_SOBJECT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SOBJECT('
      '    ID_SOBJECT,'
      '    IDBASE_SOBJECT,'
      '    NAME_SOBJECT,'
      '    IDINFBASE_SOBJECT,'
      '    IDFIRM_SOBJECT,'
      '    IDSKLAD_SOBJECT,'
      '    IDKASSA_SOBJECT,'
      '    IDPODR_SOBJECT'
      ')'
      'VALUES('
      '    :ID_SOBJECT,'
      '    :IDBASE_SOBJECT,'
      '    :NAME_SOBJECT,'
      '    :IDINFBASE_SOBJECT,'
      '    :IDFIRM_SOBJECT,'
      '    :IDSKLAD_SOBJECT,'
      '    :IDKASSA_SOBJECT,'
      '    :IDPODR_SOBJECT'
      ')')
    RefreshSQL.Strings = (
      'select sobject.*,'
      '    sinfbase_obmen.name_sinfbase_obmen,'
      '    sfirm.namefirm,'
      '    ssklad.namesklad,'
      '    skkm.namekkm,'
      '    spod.namepod'
      'from sobject'
      
        'left outer join sinfbase_obmen on sobject.idinfbase_sobject=sinf' +
        'base_obmen.id_sinfbase_obmen'
      'left outer join ssklad on sobject.idsklad_sobject=ssklad.idsklad'
      'left outer join sfirm on sobject.idfirm_sobject=sfirm.idfirm'
      'left outer join skkm on sobject.idkassa_sobject=skkm.idkkm'
      'left outer join spod on sobject.idpodr_sobject=spod.idpod'
      'where(  sobject.id_sobject=:PARAM_ID'
      '     ) and (     SOBJECT.ID_SOBJECT = :OLD_ID_SOBJECT'
      '     )'
      '    '
      '')
    SelectSQL.Strings = (
      'select sobject.*,'
      '    sinfbase_obmen.name_sinfbase_obmen,'
      '    sfirm.namefirm,'
      '    ssklad.namesklad,'
      '    skkm.namekkm,'
      '    spod.namepod'
      'from sobject'
      
        'left outer join sinfbase_obmen on sobject.idinfbase_sobject=sinf' +
        'base_obmen.id_sinfbase_obmen'
      'left outer join ssklad on sobject.idsklad_sobject=ssklad.idsklad'
      'left outer join sfirm on sobject.idfirm_sobject=sfirm.idfirm'
      'left outer join skkm on sobject.idkassa_sobject=skkm.idkkm'
      'left outer join spod on sobject.idpodr_sobject=spod.idpod'
      'where sobject.id_sobject=:PARAM_ID'
      '')
    AutoUpdateOptions.UpdateTableName = 'SOBJECT'
    AutoUpdateOptions.KeyFields = 'ID_SOBJECT'
    AutoUpdateOptions.GeneratorName = 'GEN_SOBJECT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 80
    poUseLargeIntField = True
    object ElementID_SOBJECT: TFIBLargeIntField
      FieldName = 'ID_SOBJECT'
    end
    object ElementIDBASE_SOBJECT: TFIBLargeIntField
      FieldName = 'IDBASE_SOBJECT'
    end
    object ElementNAME_SOBJECT: TFIBWideStringField
      FieldName = 'NAME_SOBJECT'
      Size = 200
    end
    object ElementIDINFBASE_SOBJECT: TFIBLargeIntField
      FieldName = 'IDINFBASE_SOBJECT'
    end
    object ElementIDFIRM_SOBJECT: TFIBLargeIntField
      FieldName = 'IDFIRM_SOBJECT'
    end
    object ElementIDSKLAD_SOBJECT: TFIBLargeIntField
      FieldName = 'IDSKLAD_SOBJECT'
    end
    object ElementIDKASSA_SOBJECT: TFIBLargeIntField
      FieldName = 'IDKASSA_SOBJECT'
    end
    object ElementIDPODR_SOBJECT: TFIBLargeIntField
      FieldName = 'IDPODR_SOBJECT'
    end
    object ElementNAME_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 200
    end
    object ElementNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 200
    end
    object ElementNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 200
    end
    object ElementNAMEKKM: TFIBWideStringField
      FieldName = 'NAMEKKM'
      Size = 200
    end
    object ElementNAMEPOD: TFIBWideStringField
      FieldName = 'NAMEPOD'
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
    Left = 296
    Top = 56
    qoStartTransaction = True
  end
end
