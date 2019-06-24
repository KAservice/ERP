object REM_DMZayavkaDv: TREM_DMZayavkaDv
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 155
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
      'select rem_z_dv.*,'
      '    rem_stremont.name_stremont,'
      '    rem_ssost.name_remssost,'
      '    sklad_tec.namesklad as name_sklad_tec,'
      '    suser.name_user'
      'from rem_z_dv'
      
        'left outer join rem_stremont on rem_stremont.id_stremont=rem_z_d' +
        'v.idtremont_rem_z_dv'
      
        'left outer join rem_ssost on rem_ssost.id_remssost=rem_z_dv.idso' +
        'st_rem_z_dv'
      
        'left outer join ssklad as sklad_tec on sklad_tec.idsklad=rem_z_d' +
        'v.idtecskl_rem_z_dv'
      'left outer join suser on suser.id_user=rem_z_dv.iduser_rem_z_dv'
      'where IDZ_REM_Z_DV=:PARAM_IDZ'
      'order by POS_REM_Z_DV')
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 8
    poUseLargeIntField = True
    object TableID_REM_Z_DV: TFIBLargeIntField
      FieldName = 'ID_REM_Z_DV'
    end
    object TableGID_REM_Z_DV: TFIBWideStringField
      FieldName = 'GID_REM_Z_DV'
      Size = 10
    end
    object TablePOS_REM_Z_DV: TFIBDateTimeField
      FieldName = 'POS_REM_Z_DV'
    end
    object TableIDZ_REM_Z_DV: TFIBLargeIntField
      FieldName = 'IDZ_REM_Z_DV'
    end
    object TableOPER_REM_Z_DV: TFIBSmallIntField
      FieldName = 'OPER_REM_Z_DV'
    end
    object TableIDSOST_REM_Z_DV: TFIBLargeIntField
      FieldName = 'IDSOST_REM_Z_DV'
    end
    object TableIDTREMONT_REM_Z_DV: TFIBLargeIntField
      FieldName = 'IDTREMONT_REM_Z_DV'
    end
    object TableIDUSER_REM_Z_DV: TFIBLargeIntField
      FieldName = 'IDUSER_REM_Z_DV'
    end
    object TableSUM_REM_Z_DV: TFIBBCDField
      FieldName = 'SUM_REM_Z_DV'
      Size = 2
      RoundByScale = True
    end
    object TableSROK_REM_Z_DV: TFIBDateField
      FieldName = 'SROK_REM_Z_DV'
    end
    object TableOUT_REM_Z_DV: TFIBSmallIntField
      FieldName = 'OUT_REM_Z_DV'
    end
    object TableIDTECSKL_REM_Z_DV: TFIBLargeIntField
      FieldName = 'IDTECSKL_REM_Z_DV'
    end
    object TableIDBASE_REM_Z_DV: TFIBLargeIntField
      FieldName = 'IDBASE_REM_Z_DV'
    end
    object TableNAME_STREMONT: TFIBWideStringField
      FieldName = 'NAME_STREMONT'
      Size = 100
    end
    object TableNAME_REMSSOST: TFIBWideStringField
      FieldName = 'NAME_REMSSOST'
      Size = 100
    end
    object TableNAME_SKLAD_TEC: TFIBWideStringField
      FieldName = 'NAME_SKLAD_TEC'
      Size = 100
    end
    object TableNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
      Size = 100
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_Z_DV'
      'SET '
      '    GID_REM_Z_DV = :GID_REM_Z_DV,'
      '    POS_REM_Z_DV = :POS_REM_Z_DV,'
      '    IDZ_REM_Z_DV = :IDZ_REM_Z_DV,'
      '    OPER_REM_Z_DV = :OPER_REM_Z_DV,'
      '    IDSOST_REM_Z_DV = :IDSOST_REM_Z_DV,'
      '    IDTREMONT_REM_Z_DV = :IDTREMONT_REM_Z_DV,'
      '    IDUSER_REM_Z_DV = :IDUSER_REM_Z_DV,'
      '    SUM_REM_Z_DV = :SUM_REM_Z_DV,'
      '    SROK_REM_Z_DV = :SROK_REM_Z_DV,'
      '    OUT_REM_Z_DV = :OUT_REM_Z_DV,'
      '    IDTECSKL_REM_Z_DV = :IDTECSKL_REM_Z_DV,'
      '    IDBASE_REM_Z_DV = :IDBASE_REM_Z_DV'
      'WHERE'
      '    ID_REM_Z_DV = :OLD_ID_REM_Z_DV'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_Z_DV'
      'WHERE'
      '        ID_REM_Z_DV = :OLD_ID_REM_Z_DV'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_Z_DV('
      '    ID_REM_Z_DV,'
      '    GID_REM_Z_DV,'
      '    POS_REM_Z_DV,'
      '    IDZ_REM_Z_DV,'
      '    OPER_REM_Z_DV,'
      '    IDSOST_REM_Z_DV,'
      '    IDTREMONT_REM_Z_DV,'
      '    IDUSER_REM_Z_DV,'
      '    SUM_REM_Z_DV,'
      '    SROK_REM_Z_DV,'
      '    OUT_REM_Z_DV,'
      '    IDTECSKL_REM_Z_DV,'
      '    IDBASE_REM_Z_DV'
      ')'
      'VALUES('
      '    :ID_REM_Z_DV,'
      '    :GID_REM_Z_DV,'
      '    :POS_REM_Z_DV,'
      '    :IDZ_REM_Z_DV,'
      '    :OPER_REM_Z_DV,'
      '    :IDSOST_REM_Z_DV,'
      '    :IDTREMONT_REM_Z_DV,'
      '    :IDUSER_REM_Z_DV,'
      '    :SUM_REM_Z_DV,'
      '    :SROK_REM_Z_DV,'
      '    :OUT_REM_Z_DV,'
      '    :IDTECSKL_REM_Z_DV,'
      '    :IDBASE_REM_Z_DV'
      ')')
    RefreshSQL.Strings = (
      'select rem_z_dv.*,'
      '    rem_stremont.name_stremont,'
      '    rem_ssost.name_remssost,'
      '    sklad_tec.namesklad as name_sklad_tec,'
      '    suser.name_user'
      'from rem_z_dv'
      
        'left outer join rem_stremont on rem_stremont.id_stremont=rem_z_d' +
        'v.idtremont_rem_z_dv'
      
        'left outer join rem_ssost on rem_ssost.id_remssost=rem_z_dv.idso' +
        'st_rem_z_dv'
      
        'left outer join ssklad as sklad_tec on sklad_tec.idsklad=rem_z_d' +
        'v.idtecskl_rem_z_dv'
      'left outer join suser on suser.id_user=rem_z_dv.iduser_rem_z_dv'
      'where(  ID_REM_Z_DV=:PARAM_ID'
      '     ) and (     REM_Z_DV.ID_REM_Z_DV = :OLD_ID_REM_Z_DV'
      '     )'
      '    '
      '')
    SelectSQL.Strings = (
      'select rem_z_dv.*,'
      '    rem_stremont.name_stremont,'
      '    rem_ssost.name_remssost,'
      '    sklad_tec.namesklad as name_sklad_tec,'
      '    suser.name_user'
      'from rem_z_dv'
      
        'left outer join rem_stremont on rem_stremont.id_stremont=rem_z_d' +
        'v.idtremont_rem_z_dv'
      
        'left outer join rem_ssost on rem_ssost.id_remssost=rem_z_dv.idso' +
        'st_rem_z_dv'
      
        'left outer join ssklad as sklad_tec on sklad_tec.idsklad=rem_z_d' +
        'v.idtecskl_rem_z_dv'
      'left outer join suser on suser.id_user=rem_z_dv.iduser_rem_z_dv'
      'where ID_REM_Z_DV=:PARAM_ID'
      '')
    AutoUpdateOptions.UpdateTableName = 'REM_Z_DV'
    AutoUpdateOptions.KeyFields = 'ID_REM_Z_DV'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_Z_DV_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 80
    poUseLargeIntField = True
    object ElementID_REM_Z_DV: TFIBLargeIntField
      FieldName = 'ID_REM_Z_DV'
    end
    object ElementGID_REM_Z_DV: TFIBWideStringField
      FieldName = 'GID_REM_Z_DV'
      Size = 10
    end
    object ElementPOS_REM_Z_DV: TFIBDateTimeField
      FieldName = 'POS_REM_Z_DV'
    end
    object ElementIDZ_REM_Z_DV: TFIBLargeIntField
      FieldName = 'IDZ_REM_Z_DV'
    end
    object ElementOPER_REM_Z_DV: TFIBSmallIntField
      FieldName = 'OPER_REM_Z_DV'
    end
    object ElementIDSOST_REM_Z_DV: TFIBLargeIntField
      FieldName = 'IDSOST_REM_Z_DV'
    end
    object ElementIDTREMONT_REM_Z_DV: TFIBLargeIntField
      FieldName = 'IDTREMONT_REM_Z_DV'
    end
    object ElementIDUSER_REM_Z_DV: TFIBLargeIntField
      FieldName = 'IDUSER_REM_Z_DV'
    end
    object ElementSUM_REM_Z_DV: TFIBBCDField
      FieldName = 'SUM_REM_Z_DV'
      Size = 2
      RoundByScale = True
    end
    object ElementSROK_REM_Z_DV: TFIBDateField
      FieldName = 'SROK_REM_Z_DV'
    end
    object ElementOUT_REM_Z_DV: TFIBSmallIntField
      FieldName = 'OUT_REM_Z_DV'
    end
    object ElementIDTECSKL_REM_Z_DV: TFIBLargeIntField
      FieldName = 'IDTECSKL_REM_Z_DV'
    end
    object ElementIDBASE_REM_Z_DV: TFIBLargeIntField
      FieldName = 'IDBASE_REM_Z_DV'
    end
    object ElementNAME_STREMONT: TFIBWideStringField
      FieldName = 'NAME_STREMONT'
      Size = 200
    end
    object ElementNAME_REMSSOST: TFIBWideStringField
      FieldName = 'NAME_REMSSOST'
      Size = 200
    end
    object ElementNAME_SKLAD_TEC: TFIBWideStringField
      FieldName = 'NAME_SKLAD_TEC'
      Size = 200
    end
    object ElementNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
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
    Top = 80
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 352
    Top = 80
    qoStartTransaction = True
  end
end
