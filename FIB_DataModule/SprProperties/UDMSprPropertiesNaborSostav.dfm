object DMSprPropertiesNaborSostav: TDMSprPropertiesNaborSostav
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 283
  Width = 412
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 8
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 56
    Top = 80
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select spropnabor_sost.*,'
      '        sprop.name_sprop,'
      '        sprop.name_for_print_sprop,'
      '        sprop_grp.name_sprop_grp,'
      '        sprop_grp.name_for_print_sprop_grp'
      'from spropnabor_sost'
      
        'left outer join sprop on spropnabor_sost.idprop_spropnabor_sost=' +
        'sprop.id_sprop'
      
        'left outer join sprop_grp on sprop.idgrp_sprop=sprop_grp.id_spro' +
        'p_grp'
      'where spropnabor_sost.idpropnabor_spropnabor_sost=:PARAM_IDNABOR'
      'order by spropnabor_sost.indexsort_spropnabor_sost')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 160
    Top = 8
    poUseLargeIntField = True
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_SPROPNABOR_SOST: TFIBLargeIntField
      FieldName = 'ID_SPROPNABOR_SOST'
    end
    object TableIDBASE_SPROPNABOR_SOST: TFIBLargeIntField
      FieldName = 'IDBASE_SPROPNABOR_SOST'
    end
    object TableGID_SPROPNABOR_SOST: TFIBWideStringField
      FieldName = 'GID_SPROPNABOR_SOST'
      Size = 10
    end
    object TableIDPROPNABOR_SPROPNABOR_SOST: TFIBLargeIntField
      FieldName = 'IDPROPNABOR_SPROPNABOR_SOST'
    end
    object TableIDPROP_SPROPNABOR_SOST: TFIBLargeIntField
      FieldName = 'IDPROP_SPROPNABOR_SOST'
    end
    object TableINDEXSORT_SPROPNABOR_SOST: TFIBIntegerField
      FieldName = 'INDEXSORT_SPROPNABOR_SOST'
    end
    object TableNAME_SPROP: TFIBWideStringField
      FieldName = 'NAME_SPROP'
      Size = 200
    end
    object TableNAME_FOR_PRINT_SPROP: TFIBWideStringField
      FieldName = 'NAME_FOR_PRINT_SPROP'
      Size = 200
    end
    object TableNAME_SPROP_GRP: TFIBWideStringField
      FieldName = 'NAME_SPROP_GRP'
      Size = 200
    end
    object TableNAME_FOR_PRINT_SPROP_GRP: TFIBWideStringField
      FieldName = 'NAME_FOR_PRINT_SPROP_GRP'
      Size = 200
    end
    object TableADD1_SPROPNABOR_SOST: TFIBSmallIntField
      FieldName = 'ADD1_SPROPNABOR_SOST'
    end
    object TableADD2_SPROPNABOR_SOST: TFIBSmallIntField
      FieldName = 'ADD2_SPROPNABOR_SOST'
    end
    object TableADD3_SPROPNABOR_SOST: TFIBSmallIntField
      FieldName = 'ADD3_SPROPNABOR_SOST'
    end
    object TableADD4_SPROPNABOR_SOST: TFIBSmallIntField
      FieldName = 'ADD4_SPROPNABOR_SOST'
    end
    object TableADD5_SPROPNABOR_SOST: TFIBSmallIntField
      FieldName = 'ADD5_SPROPNABOR_SOST'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SPROPNABOR_SOST'
      'SET '
      '    IDBASE_SPROPNABOR_SOST = :IDBASE_SPROPNABOR_SOST,'
      '    GID_SPROPNABOR_SOST = :GID_SPROPNABOR_SOST,'
      '    IDPROPNABOR_SPROPNABOR_SOST = :IDPROPNABOR_SPROPNABOR_SOST,'
      '    IDPROP_SPROPNABOR_SOST = :IDPROP_SPROPNABOR_SOST,'
      '    INDEXSORT_SPROPNABOR_SOST = :INDEXSORT_SPROPNABOR_SOST,'
      '    ADD1_SPROPNABOR_SOST = :ADD1_SPROPNABOR_SOST,'
      '    ADD2_SPROPNABOR_SOST = :ADD2_SPROPNABOR_SOST,'
      '    ADD3_SPROPNABOR_SOST = :ADD3_SPROPNABOR_SOST,'
      '    ADD4_SPROPNABOR_SOST = :ADD4_SPROPNABOR_SOST,'
      '    ADD5_SPROPNABOR_SOST = :ADD5_SPROPNABOR_SOST'
      'WHERE'
      '    ID_SPROPNABOR_SOST = :OLD_ID_SPROPNABOR_SOST'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SPROPNABOR_SOST'
      'WHERE'
      '        ID_SPROPNABOR_SOST = :OLD_ID_SPROPNABOR_SOST'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SPROPNABOR_SOST('
      '    ID_SPROPNABOR_SOST,'
      '    IDBASE_SPROPNABOR_SOST,'
      '    GID_SPROPNABOR_SOST,'
      '    IDPROPNABOR_SPROPNABOR_SOST,'
      '    IDPROP_SPROPNABOR_SOST,'
      '    INDEXSORT_SPROPNABOR_SOST,'
      '    ADD1_SPROPNABOR_SOST,'
      '    ADD2_SPROPNABOR_SOST,'
      '    ADD3_SPROPNABOR_SOST,'
      '    ADD4_SPROPNABOR_SOST,'
      '    ADD5_SPROPNABOR_SOST'
      ')'
      'VALUES('
      '    :ID_SPROPNABOR_SOST,'
      '    :IDBASE_SPROPNABOR_SOST,'
      '    :GID_SPROPNABOR_SOST,'
      '    :IDPROPNABOR_SPROPNABOR_SOST,'
      '    :IDPROP_SPROPNABOR_SOST,'
      '    :INDEXSORT_SPROPNABOR_SOST,'
      '    :ADD1_SPROPNABOR_SOST,'
      '    :ADD2_SPROPNABOR_SOST,'
      '    :ADD3_SPROPNABOR_SOST,'
      '    :ADD4_SPROPNABOR_SOST,'
      '    :ADD5_SPROPNABOR_SOST'
      ')')
    RefreshSQL.Strings = (
      'select spropnabor_sost.*,'
      '       sprop.name_sprop'
      ' from spropnabor_sost'
      
        ' left outer join sprop on spropnabor_sost.idprop_spropnabor_sost' +
        '=sprop.id_sprop'
      ' where(  spropnabor_sost.id_spropnabor_sost=:PARAM_ID'
      
        '     ) and (     SPROPNABOR_SOST.ID_SPROPNABOR_SOST = :OLD_ID_SP' +
        'ROPNABOR_SOST'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select spropnabor_sost.*,'
      '       sprop.name_sprop'
      ' from spropnabor_sost'
      
        ' left outer join sprop on spropnabor_sost.idprop_spropnabor_sost' +
        '=sprop.id_sprop'
      ' where spropnabor_sost.id_spropnabor_sost=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SPROPNABOR_SOST'
    AutoUpdateOptions.KeyFields = 'ID_SPROPNABOR_SOST'
    AutoUpdateOptions.GeneratorName = 'GEN_SPROPNABOR_SOST_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 88
    poUseLargeIntField = True
    object ElementID_SPROPNABOR_SOST: TFIBLargeIntField
      FieldName = 'ID_SPROPNABOR_SOST'
    end
    object ElementIDBASE_SPROPNABOR_SOST: TFIBLargeIntField
      FieldName = 'IDBASE_SPROPNABOR_SOST'
    end
    object ElementGID_SPROPNABOR_SOST: TFIBWideStringField
      FieldName = 'GID_SPROPNABOR_SOST'
      Size = 10
    end
    object ElementIDPROPNABOR_SPROPNABOR_SOST: TFIBLargeIntField
      FieldName = 'IDPROPNABOR_SPROPNABOR_SOST'
    end
    object ElementIDPROP_SPROPNABOR_SOST: TFIBLargeIntField
      FieldName = 'IDPROP_SPROPNABOR_SOST'
    end
    object ElementINDEXSORT_SPROPNABOR_SOST: TFIBIntegerField
      FieldName = 'INDEXSORT_SPROPNABOR_SOST'
    end
    object ElementNAME_SPROP: TFIBWideStringField
      FieldName = 'NAME_SPROP'
      Size = 200
    end
    object ElementADD1_SPROPNABOR_SOST: TFIBSmallIntField
      FieldName = 'ADD1_SPROPNABOR_SOST'
    end
    object ElementADD2_SPROPNABOR_SOST: TFIBSmallIntField
      FieldName = 'ADD2_SPROPNABOR_SOST'
    end
    object ElementADD3_SPROPNABOR_SOST: TFIBSmallIntField
      FieldName = 'ADD3_SPROPNABOR_SOST'
    end
    object ElementADD4_SPROPNABOR_SOST: TFIBSmallIntField
      FieldName = 'ADD4_SPROPNABOR_SOST'
    end
    object ElementADD5_SPROPNABOR_SOST: TFIBSmallIntField
      FieldName = 'ADD5_SPROPNABOR_SOST'
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
    Left = 264
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
    Left = 264
    Top = 88
  end
  object Query: TpFIBQuery
    Transaction = IBTr
    Left = 344
    Top = 88
    qoStartTransaction = True
  end
end
