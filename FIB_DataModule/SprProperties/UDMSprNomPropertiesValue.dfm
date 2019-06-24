object DMSprNomPropertiesValue: TDMSprNomPropertiesValue
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 341
  Width = 435
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    SelectSQL.Strings = (
      'select snompropvalue.*,'
      '        sprop.name_sprop,'
      '        sprop.name_for_print_sprop,'
      '        spropvaluelist.name_spropvaluelist,'
      '        sprop_grp.name_sprop_grp,'
      '        sprop_grp.name_for_print_sprop_grp'
      'from snompropvalue'
      
        'left outer join sprop on snompropvalue.idprop_snompropvalue=spro' +
        'p.id_sprop'
      
        'left outer join spropvaluelist on snompropvalue.idpropvallist_sn' +
        'ompropvalue=spropvaluelist.id_spropvaluelist'
      
        'left outer join sprop_grp on sprop_grp.id_sprop_grp=sprop.idgrp_' +
        'sprop'
      'where snompropvalue.idnom_snompropvalue=:PARAM_IDNOM'
      'order by snompropvalue.index_snompropvalue')
    AutoUpdateOptions.UpdateTableName = 'SNOMPROPVALUE'
    AutoUpdateOptions.KeyFields = 'ID_SNOMPROPVALUE'
    AutoUpdateOptions.GeneratorName = 'GEN_SNOMPROPVALUE_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    Left = 152
    Top = 24
    poUseLargeIntField = True
    object TableID_SNOMPROPVALUE: TFIBLargeIntField
      FieldName = 'ID_SNOMPROPVALUE'
    end
    object TableIDBASE_SNOMPROPVALUE: TFIBLargeIntField
      FieldName = 'IDBASE_SNOMPROPVALUE'
    end
    object TableGID_SNOMPROPVALUE: TFIBWideStringField
      FieldName = 'GID_SNOMPROPVALUE'
      Size = 10
    end
    object TableIDNOM_SNOMPROPVALUE: TFIBLargeIntField
      FieldName = 'IDNOM_SNOMPROPVALUE'
    end
    object TableIDPROP_SNOMPROPVALUE: TFIBLargeIntField
      FieldName = 'IDPROP_SNOMPROPVALUE'
    end
    object TableIDPROPVALLIST_SNOMPROPVALUE: TFIBLargeIntField
      FieldName = 'IDPROPVALLIST_SNOMPROPVALUE'
    end
    object TableVALTEXT_SNOMPROPVALUE: TFIBWideStringField
      FieldName = 'VALTEXT_SNOMPROPVALUE'
      Size = 250
    end
    object TableNAME_SPROP: TFIBWideStringField
      FieldName = 'NAME_SPROP'
      Size = 200
    end
    object TableNAME_SPROPVALUELIST: TFIBWideStringField
      FieldName = 'NAME_SPROPVALUELIST'
      Size = 200
    end
    object TableINDEX_SNOMPROPVALUE: TFIBIntegerField
      FieldName = 'INDEX_SNOMPROPVALUE'
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
    object TableADD1_SNOMPROPVALUE: TFIBSmallIntField
      FieldName = 'ADD1_SNOMPROPVALUE'
    end
    object TableADD2_SNOMPROPVALUE: TFIBSmallIntField
      FieldName = 'ADD2_SNOMPROPVALUE'
    end
    object TableADD3_SNOMPROPVALUE: TFIBSmallIntField
      FieldName = 'ADD3_SNOMPROPVALUE'
    end
    object TableADD4_SNOMPROPVALUE: TFIBSmallIntField
      FieldName = 'ADD4_SNOMPROPVALUE'
    end
    object TableADD5_SNOMPROPVALUE: TFIBSmallIntField
      FieldName = 'ADD5_SNOMPROPVALUE'
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
    Left = 240
    Top = 24
  end
  object IBTrUpdate: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 240
    Top = 80
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 48
    Top = 80
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SNOMPROPVALUE'
      'SET '
      '    IDBASE_SNOMPROPVALUE = :IDBASE_SNOMPROPVALUE,'
      '    GID_SNOMPROPVALUE = :GID_SNOMPROPVALUE,'
      '    IDNOM_SNOMPROPVALUE = :IDNOM_SNOMPROPVALUE,'
      '    IDPROP_SNOMPROPVALUE = :IDPROP_SNOMPROPVALUE,'
      '    IDPROPVALLIST_SNOMPROPVALUE = :IDPROPVALLIST_SNOMPROPVALUE,'
      '    VALTEXT_SNOMPROPVALUE = :VALTEXT_SNOMPROPVALUE,'
      '    INDEX_SNOMPROPVALUE = :INDEX_SNOMPROPVALUE,'
      '    ADD1_SNOMPROPVALUE = :ADD1_SNOMPROPVALUE,'
      '    ADD2_SNOMPROPVALUE = :ADD2_SNOMPROPVALUE,'
      '    ADD3_SNOMPROPVALUE = :ADD3_SNOMPROPVALUE,'
      '    ADD4_SNOMPROPVALUE = :ADD4_SNOMPROPVALUE,'
      '    ADD5_SNOMPROPVALUE = :ADD5_SNOMPROPVALUE'
      'WHERE'
      '    ID_SNOMPROPVALUE = :OLD_ID_SNOMPROPVALUE'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SNOMPROPVALUE'
      'WHERE'
      '        ID_SNOMPROPVALUE = :OLD_ID_SNOMPROPVALUE'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SNOMPROPVALUE('
      '    ID_SNOMPROPVALUE,'
      '    IDBASE_SNOMPROPVALUE,'
      '    GID_SNOMPROPVALUE,'
      '    IDNOM_SNOMPROPVALUE,'
      '    IDPROP_SNOMPROPVALUE,'
      '    IDPROPVALLIST_SNOMPROPVALUE,'
      '    VALTEXT_SNOMPROPVALUE,'
      '    INDEX_SNOMPROPVALUE,'
      '    ADD1_SNOMPROPVALUE,'
      '    ADD2_SNOMPROPVALUE,'
      '    ADD3_SNOMPROPVALUE,'
      '    ADD4_SNOMPROPVALUE,'
      '    ADD5_SNOMPROPVALUE'
      ')'
      'VALUES('
      '    :ID_SNOMPROPVALUE,'
      '    :IDBASE_SNOMPROPVALUE,'
      '    :GID_SNOMPROPVALUE,'
      '    :IDNOM_SNOMPROPVALUE,'
      '    :IDPROP_SNOMPROPVALUE,'
      '    :IDPROPVALLIST_SNOMPROPVALUE,'
      '    :VALTEXT_SNOMPROPVALUE,'
      '    :INDEX_SNOMPROPVALUE,'
      '    :ADD1_SNOMPROPVALUE,'
      '    :ADD2_SNOMPROPVALUE,'
      '    :ADD3_SNOMPROPVALUE,'
      '    :ADD4_SNOMPROPVALUE,'
      '    :ADD5_SNOMPROPVALUE'
      ')')
    RefreshSQL.Strings = (
      'select snompropvalue.*,'
      '        sprop.name_sprop,'
      '        spropvaluelist.name_spropvaluelist'
      'from snompropvalue'
      
        'left outer join sprop on snompropvalue.idprop_snompropvalue=spro' +
        'p.id_sprop'
      
        'left outer join spropvaluelist on snompropvalue.idpropvallist_sn' +
        'ompropvalue=spropvaluelist.id_spropvaluelist'
      'where(  snompropvalue.id_snompropvalue=:PARAM_ID'
      
        '     ) and (     SNOMPROPVALUE.ID_SNOMPROPVALUE = :OLD_ID_SNOMPR' +
        'OPVALUE'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select snompropvalue.*,'
      '        sprop.name_sprop,'
      '        spropvaluelist.name_spropvaluelist'
      'from snompropvalue'
      
        'left outer join sprop on snompropvalue.idprop_snompropvalue=spro' +
        'p.id_sprop'
      
        'left outer join spropvaluelist on snompropvalue.idpropvallist_sn' +
        'ompropvalue=spropvaluelist.id_spropvaluelist'
      'where snompropvalue.id_snompropvalue=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SNOMPROPVALUE'
    AutoUpdateOptions.KeyFields = 'ID_SNOMPROPVALUE'
    AutoUpdateOptions.GeneratorName = 'GEN_SNOMPROPVALUE_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 80
    poUseLargeIntField = True
    object ElementID_SNOMPROPVALUE: TFIBLargeIntField
      FieldName = 'ID_SNOMPROPVALUE'
    end
    object ElementIDBASE_SNOMPROPVALUE: TFIBLargeIntField
      FieldName = 'IDBASE_SNOMPROPVALUE'
    end
    object ElementGID_SNOMPROPVALUE: TFIBWideStringField
      FieldName = 'GID_SNOMPROPVALUE'
      Size = 10
    end
    object ElementIDNOM_SNOMPROPVALUE: TFIBLargeIntField
      FieldName = 'IDNOM_SNOMPROPVALUE'
    end
    object ElementIDPROP_SNOMPROPVALUE: TFIBLargeIntField
      FieldName = 'IDPROP_SNOMPROPVALUE'
    end
    object ElementIDPROPVALLIST_SNOMPROPVALUE: TFIBLargeIntField
      FieldName = 'IDPROPVALLIST_SNOMPROPVALUE'
    end
    object ElementVALTEXT_SNOMPROPVALUE: TFIBWideStringField
      FieldName = 'VALTEXT_SNOMPROPVALUE'
      Size = 250
    end
    object ElementNAME_SPROP: TFIBWideStringField
      FieldName = 'NAME_SPROP'
      Size = 200
    end
    object ElementNAME_SPROPVALUELIST: TFIBWideStringField
      FieldName = 'NAME_SPROPVALUELIST'
      Size = 200
    end
    object ElementINDEX_SNOMPROPVALUE: TFIBIntegerField
      FieldName = 'INDEX_SNOMPROPVALUE'
    end
    object ElementADD1_SNOMPROPVALUE: TFIBSmallIntField
      FieldName = 'ADD1_SNOMPROPVALUE'
    end
    object ElementADD2_SNOMPROPVALUE: TFIBSmallIntField
      FieldName = 'ADD2_SNOMPROPVALUE'
    end
    object ElementADD3_SNOMPROPVALUE: TFIBSmallIntField
      FieldName = 'ADD3_SNOMPROPVALUE'
    end
    object ElementADD4_SNOMPROPVALUE: TFIBSmallIntField
      FieldName = 'ADD4_SNOMPROPVALUE'
    end
    object ElementADD5_SNOMPROPVALUE: TFIBSmallIntField
      FieldName = 'ADD5_SNOMPROPVALUE'
    end
  end
  object Query: TpFIBQuery
    Transaction = IBTr
    Left = 312
    Top = 160
  end
end
