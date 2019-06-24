object REM_DMSprHardwareIsp: TREM_DMSprHardwareIsp
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 355
  Width = 681
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
      'select rem_shardware_isp.*,'
      '    rem_stypuslov.name_rem_stypuslov,'
      '    suser.name_user,'
      '    rem_z.name_rem_z,'
      '    rem_z.prefiks_num_rem_z,'
      '    rem_z.pos_rem_z,'
      '    rem_z.num_rem_z,'
      '    rem_z.model_rem_z,'
      '    rem_z.sernum_rem_z'
      'from rem_shardware_isp'
      
        'left outer join rem_stypuslov on rem_stypuslov.id_rem_stypuslov=' +
        'rem_shardware_isp.idtypeusel_rem_shardware_isp'
      
        'left outer join suser on suser.id_user=rem_shardware_isp.iduser_' +
        'rem_shardware_isp'
      
        'left outer join rem_z on rem_z.id_rem_z=rem_shardware_isp.idz_re' +
        'm_shardware_isp'
      'where rem_shardware_isp.idhw_rem_shardware_isp=:PARAM_IDOWNER'
      'order by rem_shardware_isp.pos_rem_shardware_isp')
    Transaction = IBTr
    Left = 168
    Top = 8
    poUseLargeIntField = True
    object TableID_REM_SHARDWARE_ISP: TFIBLargeIntField
      FieldName = 'ID_REM_SHARDWARE_ISP'
    end
    object TableIDBASE_REM_SHARDWARE_ISP: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SHARDWARE_ISP'
    end
    object TableIDHW_REM_SHARDWARE_ISP: TFIBLargeIntField
      FieldName = 'IDHW_REM_SHARDWARE_ISP'
    end
    object TablePOS_REM_SHARDWARE_ISP: TFIBDateTimeField
      FieldName = 'POS_REM_SHARDWARE_ISP'
      DisplayFormat = 'c'
    end
    object TableIDUSER_REM_SHARDWARE_ISP: TFIBLargeIntField
      FieldName = 'IDUSER_REM_SHARDWARE_ISP'
    end
    object TableIDTYPEUSEL_REM_SHARDWARE_ISP: TFIBLargeIntField
      FieldName = 'IDTYPEUSEL_REM_SHARDWARE_ISP'
    end
    object TableKOL_REM_SHARDWARE_ISP: TFIBBCDField
      FieldName = 'KOL_REM_SHARDWARE_ISP'
      Size = 3
      RoundByScale = True
    end
    object TableDESCR_REM_SHARDWARE_ISP: TFIBWideStringField
      FieldName = 'DESCR_REM_SHARDWARE_ISP'
      Size = 150
    end
    object TableFL_OTCH_PR_REM_SHARDWARE_ISP: TFIBSmallIntField
      FieldName = 'FL_OTCH_PR_REM_SHARDWARE_ISP'
    end
    object TableFL_REAL_ISP_REM_SHARDWARE_ISP: TFIBSmallIntField
      FieldName = 'FL_REAL_ISP_REM_SHARDWARE_ISP'
    end
    object TableIDZ_REM_SHARDWARE_ISP: TFIBLargeIntField
      FieldName = 'IDZ_REM_SHARDWARE_ISP'
    end
    object TableNAME_REM_STYPUSLOV: TFIBWideStringField
      FieldName = 'NAME_REM_STYPUSLOV'
      Size = 200
    end
    object TableNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
      Size = 200
    end
    object TableNAME_REM_Z: TFIBWideStringField
      FieldName = 'NAME_REM_Z'
      Size = 200
    end
    object TablePREFIKS_NUM_REM_Z: TFIBWideStringField
      FieldName = 'PREFIKS_NUM_REM_Z'
      Size = 12
    end
    object TablePOS_REM_Z: TFIBDateTimeField
      FieldName = 'POS_REM_Z'
    end
    object TableNUM_REM_Z: TFIBIntegerField
      FieldName = 'NUM_REM_Z'
    end
    object TableMODEL_REM_Z: TFIBWideStringField
      FieldName = 'MODEL_REM_Z'
      Size = 40
    end
    object TableSERNUM_REM_Z: TFIBWideStringField
      FieldName = 'SERNUM_REM_Z'
      Size = 50
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_SHARDWARE_ISP'
      'SET '
      '    IDBASE_REM_SHARDWARE_ISP = :IDBASE_REM_SHARDWARE_ISP,'
      '    IDHW_REM_SHARDWARE_ISP = :IDHW_REM_SHARDWARE_ISP,'
      '    POS_REM_SHARDWARE_ISP = :POS_REM_SHARDWARE_ISP,'
      '    IDUSER_REM_SHARDWARE_ISP = :IDUSER_REM_SHARDWARE_ISP,'
      
        '    IDTYPEUSEL_REM_SHARDWARE_ISP = :IDTYPEUSEL_REM_SHARDWARE_ISP' +
        ','
      '    KOL_REM_SHARDWARE_ISP = :KOL_REM_SHARDWARE_ISP,'
      '    DESCR_REM_SHARDWARE_ISP = :DESCR_REM_SHARDWARE_ISP,'
      
        '    FL_OTCH_PR_REM_SHARDWARE_ISP = :FL_OTCH_PR_REM_SHARDWARE_ISP' +
        ','
      
        '    FL_REAL_ISP_REM_SHARDWARE_ISP = :FL_REAL_ISP_REM_SHARDWARE_I' +
        'SP,'
      '    IDZ_REM_SHARDWARE_ISP = :IDZ_REM_SHARDWARE_ISP'
      'WHERE'
      '    ID_REM_SHARDWARE_ISP = :OLD_ID_REM_SHARDWARE_ISP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_SHARDWARE_ISP'
      'WHERE'
      '        ID_REM_SHARDWARE_ISP = :OLD_ID_REM_SHARDWARE_ISP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_SHARDWARE_ISP('
      '    ID_REM_SHARDWARE_ISP,'
      '    IDBASE_REM_SHARDWARE_ISP,'
      '    IDHW_REM_SHARDWARE_ISP,'
      '    POS_REM_SHARDWARE_ISP,'
      '    IDUSER_REM_SHARDWARE_ISP,'
      '    IDTYPEUSEL_REM_SHARDWARE_ISP,'
      '    KOL_REM_SHARDWARE_ISP,'
      '    DESCR_REM_SHARDWARE_ISP,'
      '    FL_OTCH_PR_REM_SHARDWARE_ISP,'
      '    FL_REAL_ISP_REM_SHARDWARE_ISP,'
      '    IDZ_REM_SHARDWARE_ISP'
      ')'
      'VALUES('
      '    :ID_REM_SHARDWARE_ISP,'
      '    :IDBASE_REM_SHARDWARE_ISP,'
      '    :IDHW_REM_SHARDWARE_ISP,'
      '    :POS_REM_SHARDWARE_ISP,'
      '    :IDUSER_REM_SHARDWARE_ISP,'
      '    :IDTYPEUSEL_REM_SHARDWARE_ISP,'
      '    :KOL_REM_SHARDWARE_ISP,'
      '    :DESCR_REM_SHARDWARE_ISP,'
      '    :FL_OTCH_PR_REM_SHARDWARE_ISP,'
      '    :FL_REAL_ISP_REM_SHARDWARE_ISP,'
      '    :IDZ_REM_SHARDWARE_ISP'
      ')')
    RefreshSQL.Strings = (
      'select rem_shardware_isp.*,'
      '    rem_stypuslov.name_rem_stypuslov,'
      '    suser.name_user,'
      '    rem_z.name_rem_z,'
      '    rem_z.prefiks_num_rem_z,'
      '    rem_z.pos_rem_z,'
      '    rem_z.num_rem_z,'
      '    rem_z.model_rem_z,'
      '    rem_z.sernum_rem_z'
      'from rem_shardware_isp'
      
        'left outer join rem_stypuslov on rem_stypuslov.id_rem_stypuslov=' +
        'rem_shardware_isp.idtypeusel_rem_shardware_isp'
      
        'left outer join suser on suser.id_user=rem_shardware_isp.iduser_' +
        'rem_shardware_isp'
      
        'left outer join rem_z on rem_z.id_rem_z=rem_shardware_isp.idz_re' +
        'm_shardware_isp'
      'where(  rem_shardware_isp.id_rem_shardware_isp=:PARAM_ID'
      
        '     ) and (     REM_SHARDWARE_ISP.ID_REM_SHARDWARE_ISP = :OLD_I' +
        'D_REM_SHARDWARE_ISP'
      '     )'
      '    '
      '')
    SelectSQL.Strings = (
      'select rem_shardware_isp.*,'
      '    rem_stypuslov.name_rem_stypuslov,'
      '    suser.name_user,'
      '    rem_z.name_rem_z,'
      '    rem_z.prefiks_num_rem_z,'
      '    rem_z.pos_rem_z,'
      '    rem_z.num_rem_z,'
      '    rem_z.model_rem_z,'
      '    rem_z.sernum_rem_z'
      'from rem_shardware_isp'
      
        'left outer join rem_stypuslov on rem_stypuslov.id_rem_stypuslov=' +
        'rem_shardware_isp.idtypeusel_rem_shardware_isp'
      
        'left outer join suser on suser.id_user=rem_shardware_isp.iduser_' +
        'rem_shardware_isp'
      
        'left outer join rem_z on rem_z.id_rem_z=rem_shardware_isp.idz_re' +
        'm_shardware_isp'
      'where rem_shardware_isp.id_rem_shardware_isp=:PARAM_ID'
      '')
    AutoUpdateOptions.UpdateTableName = 'REM_SHARDWARE_ISP'
    AutoUpdateOptions.KeyFields = 'ID_REM_SHARDWARE_ISP'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SHARDWARE_ISP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 80
    poUseLargeIntField = True
    object ElementID_REM_SHARDWARE_ISP: TFIBLargeIntField
      FieldName = 'ID_REM_SHARDWARE_ISP'
    end
    object ElementIDBASE_REM_SHARDWARE_ISP: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SHARDWARE_ISP'
    end
    object ElementIDHW_REM_SHARDWARE_ISP: TFIBLargeIntField
      FieldName = 'IDHW_REM_SHARDWARE_ISP'
    end
    object ElementPOS_REM_SHARDWARE_ISP: TFIBDateTimeField
      FieldName = 'POS_REM_SHARDWARE_ISP'
      DisplayFormat = 'c'
    end
    object ElementIDUSER_REM_SHARDWARE_ISP: TFIBLargeIntField
      FieldName = 'IDUSER_REM_SHARDWARE_ISP'
    end
    object ElementIDTYPEUSEL_REM_SHARDWARE_ISP: TFIBLargeIntField
      FieldName = 'IDTYPEUSEL_REM_SHARDWARE_ISP'
    end
    object ElementKOL_REM_SHARDWARE_ISP: TFIBBCDField
      FieldName = 'KOL_REM_SHARDWARE_ISP'
      Size = 3
      RoundByScale = True
    end
    object ElementDESCR_REM_SHARDWARE_ISP: TFIBWideStringField
      FieldName = 'DESCR_REM_SHARDWARE_ISP'
      Size = 150
    end
    object ElementFL_OTCH_PR_REM_SHARDWARE_ISP: TFIBSmallIntField
      FieldName = 'FL_OTCH_PR_REM_SHARDWARE_ISP'
    end
    object ElementFL_REAL_ISP_REM_SHARDWARE_ISP: TFIBSmallIntField
      FieldName = 'FL_REAL_ISP_REM_SHARDWARE_ISP'
    end
    object ElementIDZ_REM_SHARDWARE_ISP: TFIBLargeIntField
      FieldName = 'IDZ_REM_SHARDWARE_ISP'
    end
    object ElementNAME_REM_STYPUSLOV: TFIBWideStringField
      FieldName = 'NAME_REM_STYPUSLOV'
      Size = 200
    end
    object ElementNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
      Size = 200
    end
    object ElementNAME_REM_Z: TFIBWideStringField
      FieldName = 'NAME_REM_Z'
      Size = 200
    end
    object ElementPREFIKS_NUM_REM_Z: TFIBWideStringField
      FieldName = 'PREFIKS_NUM_REM_Z'
      Size = 12
    end
    object ElementPOS_REM_Z: TFIBDateTimeField
      FieldName = 'POS_REM_Z'
    end
    object ElementNUM_REM_Z: TFIBIntegerField
      FieldName = 'NUM_REM_Z'
    end
    object ElementMODEL_REM_Z: TFIBWideStringField
      FieldName = 'MODEL_REM_Z'
      Size = 40
    end
    object ElementSERNUM_REM_Z: TFIBWideStringField
      FieldName = 'SERNUM_REM_Z'
      Size = 50
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
