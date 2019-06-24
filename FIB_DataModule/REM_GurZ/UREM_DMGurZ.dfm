object REM_DMGurZ: TREM_DMGurZ
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 281
  Width = 591
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 16
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      '/*select rem_z.*,'
      '    sinfbase_obmen.name_sinfbase_obmen,'
      '    sfirm.namefirm,'
      '    rem_smodel.name_rem_smodel,'
      '    sklad_pr.namesklad as name_sklad_pr,'
      '    sklient.nameklient,'
      '    diler.nameklient as namediler,'
      '    rem_stremont.name_stremont,'
      '    rem_ssost.name_remssost,'
      '    sklad_tec.namesklad as name_sklad_tec,'
      '    suser.name_user,'
      '    sbrand.name_sbrand'
      'from rem_z'
      
        'left outer join sinfbase_obmen on sinfbase_obmen.id_sinfbase_obm' +
        'en=rem_z.idbase_rem_z'
      'left outer join sfirm on sfirm.idfirm=rem_z.idfirm_rem_z'
      
        'left outer join rem_smodel on rem_smodel.id_rem_smodel=rem_z.idm' +
        'odel_rem_z'
      
        'left outer join ssklad as sklad_pr on sklad_pr.idsklad=rem_z.ids' +
        'klpr_rem_z'
      'left outer join sklient on sklient.idklient=rem_z.idklient_rem_z'
      
        'left outer join sklient as diler on diler.idklient=rem_z.iddiler' +
        '_rem_z'
      
        'left outer join rem_stremont on rem_stremont.id_stremont=rem_z.i' +
        'dtyperem_rem_z'
      
        'left outer join rem_ssost on rem_ssost.id_remssost=rem_z.idsost_' +
        'rem_z'
      
        'left outer join ssklad as sklad_tec on sklad_tec.idsklad=rem_z.i' +
        'dtecskl_rem_z'
      'left outer join suser on suser.id_user=rem_z.iduser_rem_z'
      'left outer join sbrand on rem_z.idbrand_rem_z=sbrand.id_sbrand'
      'where POS_REM_Z between  :PARAM_DATE_NACH and :PARAM_DATE_CON'
      'order by   rem_z.pos_rem_z*/'
      ''
      
        'select *  from rem_z_get_table(0,:PARAM_DATE_NACH,:PARAM_DATE_CO' +
        'N,0,'#39' '#39',0)')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 144
    Top = 16
    poUseLargeIntField = True
    object TableID_REM_Z: TFIBLargeIntField
      FieldName = 'ID_REM_Z'
    end
    object TableGID_REM_Z: TFIBWideStringField
      FieldName = 'GID_REM_Z'
      Size = 10
    end
    object TablePREFIKS_REM_Z: TFIBWideStringField
      FieldName = 'PREFIKS_REM_Z'
      Size = 2
    end
    object TableNUM_REM_Z: TFIBIntegerField
      FieldName = 'NUM_REM_Z'
    end
    object TablePOS_REM_Z: TFIBDateTimeField
      FieldName = 'POS_REM_Z'
      DisplayFormat = 'c'
    end
    object TableIDBASE_REM_Z: TFIBLargeIntField
      FieldName = 'IDBASE_REM_Z'
    end
    object TableIDMODEL_REM_Z: TFIBLargeIntField
      FieldName = 'IDMODEL_REM_Z'
    end
    object TableIDSKLPR_REM_Z: TFIBLargeIntField
      FieldName = 'IDSKLPR_REM_Z'
    end
    object TableIDKLIENT_REM_Z: TFIBLargeIntField
      FieldName = 'IDKLIENT_REM_Z'
    end
    object TableIDDILER_REM_Z: TFIBLargeIntField
      FieldName = 'IDDILER_REM_Z'
    end
    object TableSERNUM_REM_Z: TFIBWideStringField
      FieldName = 'SERNUM_REM_Z'
      Size = 50
    end
    object TableNAME_REM_Z: TFIBWideStringField
      FieldName = 'NAME_REM_Z'
      Size = 200
    end
    object TableDESCR_REM_Z: TFIBWideStringField
      FieldName = 'DESCR_REM_Z'
      Size = 150
    end
    object TableIDTYPEREM_REM_Z: TFIBLargeIntField
      FieldName = 'IDTYPEREM_REM_Z'
    end
    object TableIDSOST_REM_Z: TFIBLargeIntField
      FieldName = 'IDSOST_REM_Z'
    end
    object TableIDTECSKL_REM_Z: TFIBLargeIntField
      FieldName = 'IDTECSKL_REM_Z'
    end
    object TableIDUSER_REM_Z: TFIBLargeIntField
      FieldName = 'IDUSER_REM_Z'
    end
    object TableOPER_REM_Z: TFIBIntegerField
      FieldName = 'OPER_REM_Z'
    end
    object TableSUM_REM_Z: TFIBBCDField
      FieldName = 'SUM_REM_Z'
      Size = 2
      RoundByScale = True
    end
    object TableSROK_REM_Z: TFIBDateField
      FieldName = 'SROK_REM_Z'
    end
    object TableOUT_REM_Z: TFIBIntegerField
      FieldName = 'OUT_REM_Z'
    end
    object TableIDFIRM_REM_Z: TFIBLargeIntField
      FieldName = 'IDFIRM_REM_Z'
    end
    object TableNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 200
    end
    object TableNAME_REM_SMODEL: TFIBWideStringField
      FieldName = 'NAME_REM_SMODEL'
      Size = 200
    end
    object TableNAME_SKLAD_PR: TFIBWideStringField
      FieldName = 'NAME_SKLAD_PR'
      Size = 200
    end
    object TableNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 200
    end
    object TableNAMEDILER: TFIBWideStringField
      FieldName = 'NAMEDILER'
      Size = 200
    end
    object TableNAME_STREMONT: TFIBWideStringField
      FieldName = 'NAME_STREMONT'
      Size = 200
    end
    object TableNAME_REMSSOST: TFIBWideStringField
      FieldName = 'NAME_REMSSOST'
      Size = 200
    end
    object TableNAME_SKLAD_TEC: TFIBWideStringField
      FieldName = 'NAME_SKLAD_TEC'
      Size = 200
    end
    object TableNAME_USER: TFIBWideStringField
      FieldName = 'NAME_USER'
      Size = 200
    end
    object TableKLIENT_NAME_REM_Z: TFIBWideStringField
      FieldName = 'KLIENT_NAME_REM_Z'
      Size = 200
    end
    object TableMODEL_REM_Z: TFIBWideStringField
      FieldName = 'MODEL_REM_Z'
      Size = 40
    end
    object TableSERNUM2_REM_Z: TFIBWideStringField
      FieldName = 'SERNUM2_REM_Z'
      Size = 50
    end
    object TableFL_KLIENT_UVEDOML_REM_Z: TFIBIntegerField
      FieldName = 'FL_KLIENT_UVEDOML_REM_Z'
    end
    object TableFL_TREB_KONS_KL_REM_Z: TFIBIntegerField
      FieldName = 'FL_TREB_KONS_KL_REM_Z'
    end
    object TableFL_KL_OTV_NA_ZAPROS_REM_Z: TFIBIntegerField
      FieldName = 'FL_KL_OTV_NA_ZAPROS_REM_Z'
    end
    object TablePREFIKS_NUM_REM_Z: TFIBWideStringField
      FieldName = 'PREFIKS_NUM_REM_Z'
      Size = 12
    end
    object TableNAME_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 200
    end
    object TableIDBRAND_REM_Z: TFIBLargeIntField
      FieldName = 'IDBRAND_REM_Z'
    end
    object TableFL_POVTOR_REM_Z: TFIBSmallIntField
      FieldName = 'FL_POVTOR_REM_Z'
    end
    object TableFL_ADDREPORT_REM_Z: TFIBSmallIntField
      FieldName = 'FL_ADDREPORT_REM_Z'
    end
    object TableNUM_GARDOC_REM_Z: TFIBWideStringField
      FieldName = 'NUM_GARDOC_REM_Z'
      Size = 50
    end
    object TableNAME_SBRAND: TFIBWideStringField
      FieldName = 'NAME_SBRAND'
      Size = 200
    end
    object TableFL_FICTIV_REM_Z: TFIBIntegerField
      FieldName = 'FL_FICTIV_REM_Z'
    end
    object TableFL_NE_OTCH_REM_Z: TFIBSmallIntField
      FieldName = 'FL_NE_OTCH_REM_Z'
    end
    object TableFL_NADO_OTCH_REM_Z: TFIBSmallIntField
      FieldName = 'FL_NADO_OTCH_REM_Z'
    end
    object TableSOST_CQUERY: TFIBSmallIntField
      FieldName = 'SOST_CQUERY'
    end
    object TableID_REM_CQUERY: TFIBLargeIntField
      FieldName = 'ID_REM_CQUERY'
    end
    object TableSROK_REMONTA: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'SROK_REMONTA'
      Calculated = True
    end
    object TableSROK_REMONTA_NOW: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'SROK_REMONTA_NOW'
      Calculated = True
    end
    object TablePOSOUT_REM_Z: TFIBDateTimeField
      FieldName = 'POSOUT_REM_Z'
    end
    object TablePOSREMONT_REM_Z: TFIBDateTimeField
      FieldName = 'POSREMONT_REM_Z'
    end
    object TableGOTOVO_K_VIDACHE_REM_Z: TFIBSmallIntField
      FieldName = 'GOTOVO_K_VIDACHE_REM_Z'
    end
    object TableNAME_SKLAD_OST: TFIBWideStringField
      FieldName = 'NAME_SKLAD_OST'
      Size = 200
    end
    object TableIDREC_RGOTPRZ: TFIBLargeIntField
      FieldName = 'IDREC_RGOTPRZ'
    end
    object TableIDDOC_VIDACHA_HW: TFIBLargeIntField
      FieldName = 'IDDOC_VIDACHA_HW'
    end
    object TableIDDOC_VOSVRAT_HW: TFIBLargeIntField
      FieldName = 'IDDOC_VOSVRAT_HW'
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
    Left = 232
    Top = 16
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 232
    Top = 80
    qoStartTransaction = True
  end
end
