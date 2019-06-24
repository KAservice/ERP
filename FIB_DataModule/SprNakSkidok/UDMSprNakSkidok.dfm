object DMSprNakSkidok: TDMSprNakSkidok
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 275
  Width = 334
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 8
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 56
    Top = 72
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select '
      '   SNAK_SKIDOK .*, NAMESKLAD, NAME_SVID_DCARD'
      'from SNAK_SKIDOK'
      'left outer join SSKLAD on IDSKLAD=IDSKLAD_SNAK_SKIDOK'
      'left outer join SVID_DCARD on ID_SVID_DCARD=IDVID_SNAK_SKIDOK')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 152
    Top = 8
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableSUM_SNAK_SKIDOK: TFIBBCDField
      FieldName = 'SUM_SNAK_SKIDOK'
      Size = 2
      RoundByScale = True
    end
    object TablePROCENT_SNAK_SKIDOK: TFIBBCDField
      FieldName = 'PROCENT_SNAK_SKIDOK'
      Size = 2
      RoundByScale = True
    end
    object TablePERIOD_SNAK_SKIDOK: TFIBSmallIntField
      FieldName = 'PERIOD_SNAK_SKIDOK'
    end
    object TableID_SNAK_SKIDOK: TFIBBCDField
      FieldName = 'ID_SNAK_SKIDOK'
      Size = 0
      RoundByScale = True
    end
    object TableIDSKLAD_SNAK_SKIDOK: TFIBBCDField
      FieldName = 'IDSKLAD_SNAK_SKIDOK'
      Size = 0
      RoundByScale = True
    end
    object TableIDVID_SNAK_SKIDOK: TFIBBCDField
      FieldName = 'IDVID_SNAK_SKIDOK'
      Size = 0
      RoundByScale = True
    end
    object TableGID_SNAK_SKIDOK: TFIBWideStringField
      FieldName = 'GID_SNAK_SKIDOK'
      Size = 10
    end
    object TableNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 100
    end
    object TableNAME_SVID_DCARD: TFIBWideStringField
      FieldName = 'NAME_SVID_DCARD'
      Size = 100
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SNAK_SKIDOK'
      'SET '
      '    GID_SNAK_SKIDOK = :GID_SNAK_SKIDOK,'
      '    IDSKLAD_SNAK_SKIDOK = :IDSKLAD_SNAK_SKIDOK,'
      '    IDVID_SNAK_SKIDOK = :IDVID_SNAK_SKIDOK,'
      '    SUM_SNAK_SKIDOK = :SUM_SNAK_SKIDOK,'
      '    PROCENT_SNAK_SKIDOK = :PROCENT_SNAK_SKIDOK,'
      '    PERIOD_SNAK_SKIDOK = :PERIOD_SNAK_SKIDOK'
      'WHERE'
      '    ID_SNAK_SKIDOK = :OLD_ID_SNAK_SKIDOK'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SNAK_SKIDOK'
      'WHERE'
      '        ID_SNAK_SKIDOK = :OLD_ID_SNAK_SKIDOK'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SNAK_SKIDOK('
      '    ID_SNAK_SKIDOK,'
      '    GID_SNAK_SKIDOK,'
      '    IDSKLAD_SNAK_SKIDOK,'
      '    IDVID_SNAK_SKIDOK,'
      '    SUM_SNAK_SKIDOK,'
      '    PROCENT_SNAK_SKIDOK,'
      '    PERIOD_SNAK_SKIDOK'
      ')'
      'VALUES('
      '    :ID_SNAK_SKIDOK,'
      '    :GID_SNAK_SKIDOK,'
      '    :IDSKLAD_SNAK_SKIDOK,'
      '    :IDVID_SNAK_SKIDOK,'
      '    :SUM_SNAK_SKIDOK,'
      '    :PROCENT_SNAK_SKIDOK,'
      '    :PERIOD_SNAK_SKIDOK'
      ')')
    RefreshSQL.Strings = (
      'select '
      '   SNAK_SKIDOK .*, NAMESKLAD, NAME_SVID_DCARD'
      'from SNAK_SKIDOK'
      'left outer join SSKLAD on IDSKLAD=IDSKLAD_SNAK_SKIDOK'
      'left outer join SVID_DCARD on ID_SVID_DCARD=IDVID_SNAK_SKIDOK'
      ''
      'where(  ID_SNAK_SKIDOK=:PARAM_ID'
      
        '     ) and (     SNAK_SKIDOK.ID_SNAK_SKIDOK = :OLD_ID_SNAK_SKIDO' +
        'K'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select '
      '   SNAK_SKIDOK .*, NAMESKLAD, NAME_SVID_DCARD'
      'from SNAK_SKIDOK'
      'left outer join SSKLAD on IDSKLAD=IDSKLAD_SNAK_SKIDOK'
      'left outer join SVID_DCARD on ID_SVID_DCARD=IDVID_SNAK_SKIDOK'
      ''
      'where ID_SNAK_SKIDOK=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SNAK_SKIDOK'
    AutoUpdateOptions.KeyFields = 'ID_SNAK_SKIDOK'
    AutoUpdateOptions.GeneratorName = 'GEN_SNAK_SKIDOK_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 72
    object ElementSUM_SNAK_SKIDOK: TFIBBCDField
      FieldName = 'SUM_SNAK_SKIDOK'
      Size = 2
      RoundByScale = True
    end
    object ElementPROCENT_SNAK_SKIDOK: TFIBBCDField
      FieldName = 'PROCENT_SNAK_SKIDOK'
      Size = 2
      RoundByScale = True
    end
    object ElementPERIOD_SNAK_SKIDOK: TFIBSmallIntField
      FieldName = 'PERIOD_SNAK_SKIDOK'
    end
    object ElementID_SNAK_SKIDOK: TFIBBCDField
      FieldName = 'ID_SNAK_SKIDOK'
      Size = 0
      RoundByScale = True
    end
    object ElementIDSKLAD_SNAK_SKIDOK: TFIBBCDField
      FieldName = 'IDSKLAD_SNAK_SKIDOK'
      Size = 0
      RoundByScale = True
    end
    object ElementIDVID_SNAK_SKIDOK: TFIBBCDField
      FieldName = 'IDVID_SNAK_SKIDOK'
      Size = 0
      RoundByScale = True
    end
    object ElementGID_SNAK_SKIDOK: TFIBWideStringField
      FieldName = 'GID_SNAK_SKIDOK'
      Size = 10
    end
    object ElementNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 100
    end
    object ElementNAME_SVID_DCARD: TFIBWideStringField
      FieldName = 'NAME_SVID_DCARD'
      Size = 100
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
    Top = 8
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
  object Query: TpFIBQuery
    Left = 152
    Top = 128
    qoStartTransaction = True
  end
  object TableNakSkidok: TpFIBDataSet
    SelectSQL.Strings = (
      'select * '
      'from SNAK_SKIDOK '
      'where snak_skidok.idvid_snak_skidok=:PARAM_VID '
      'and snak_skidok.idsklad_snak_skidok=:PARAM_IDSKLAD ')
    Transaction = IBTr
    Left = 152
    Top = 200
    object TableNakSkidokID_SNAK_SKIDOK: TFIBBCDField
      FieldName = 'ID_SNAK_SKIDOK'
      Size = 0
      RoundByScale = True
    end
    object TableNakSkidokIDSKLAD_SNAK_SKIDOK: TFIBBCDField
      FieldName = 'IDSKLAD_SNAK_SKIDOK'
      Size = 0
      RoundByScale = True
    end
    object TableNakSkidokIDVID_SNAK_SKIDOK: TFIBBCDField
      FieldName = 'IDVID_SNAK_SKIDOK'
      Size = 0
      RoundByScale = True
    end
    object TableNakSkidokSUM_SNAK_SKIDOK: TFIBBCDField
      FieldName = 'SUM_SNAK_SKIDOK'
      Size = 2
      RoundByScale = True
    end
    object TableNakSkidokPROCENT_SNAK_SKIDOK: TFIBBCDField
      FieldName = 'PROCENT_SNAK_SKIDOK'
      Size = 2
      RoundByScale = True
    end
    object TableNakSkidokPERIOD_SNAK_SKIDOK: TFIBSmallIntField
      FieldName = 'PERIOD_SNAK_SKIDOK'
    end
    object TableNakSkidokGID_SNAK_SKIDOK: TFIBWideStringField
      FieldName = 'GID_SNAK_SKIDOK'
      Size = 10
    end
  end
end
