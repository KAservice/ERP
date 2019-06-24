object REM_DMGurProverok: TREM_DMGurProverok
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 280
  Width = 292
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 16
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select '
      '    rem_gur_prov.*,'
      '    sfirm.namefirm,'
      '    ssklad.namesklad,'
      '    sklient.NAMEKLIENT,'
      '    USER_DOC.NAME_USER as NAME_USER_DOC,'
      '    USER_PROV.NAME_USER as NAME_USER_PROV,'
      '    sinfbase_obmen.name_sinfbase_obmen,'
      '    rem_galldoc.prefiks_num_rem_galldoc,'
      '    rem_galldoc.pr_rem_galldoc,'
      '    rem_galldoc.num_rem_galldoc,'
      '    rem_galldoc.pos_rem_galldoc,'
      '    rem_galldoc.tdoc_rem_galldoc'
      ''
      'from   rem_gur_prov'
      
        'left outer join rem_galldoc on rem_gur_prov.iddoc_rem_gur_prov=r' +
        'em_galldoc.id_rem_galldoc'
      
        'left outer join SINFBASE_OBMEN on rem_galldoc.idbase_rem_galldoc' +
        '=sinfbase_obmen.id_sinfbase_obmen'
      
        'LEFT OUTER JOIN SFIRM ON rem_galldoc.idfirm_rem_galldoc = sfirm.' +
        'IDFIRM'
      
        'left outer join SSKLAD on rem_galldoc.idsklad_rem_galldoc = sskl' +
        'ad.idsklad'
      
        'left outer join SKLIENT on rem_galldoc.idklient_rem_galldoc =skl' +
        'ient.IDKLIENT'
      
        'left outer join SUSER as USER_DOC on  rem_galldoc.iduser_rem_gal' +
        'ldoc = USER_DOC.ID_USER'
      
        'left outer join SUSER as USER_PROV on  rem_gur_prov.iduser_rem_g' +
        'ur_prov = USER_PROV.ID_USER'
      
        'where rem_gur_prov.pos_rem_gur_prov between  :PARAM_POSNACH and ' +
        ':PARAM_POSCON'
      'order by rem_gur_prov.pos_rem_gur_prov')
    Left = 144
    Top = 16
    poUseLargeIntField = True
    object TableID_REM_GUR_PROV: TFIBLargeIntField
      FieldName = 'ID_REM_GUR_PROV'
    end
    object TableIDBASE_REM_GUR_PROV: TFIBLargeIntField
      FieldName = 'IDBASE_REM_GUR_PROV'
    end
    object TablePOS_REM_GUR_PROV: TFIBDateTimeField
      FieldName = 'POS_REM_GUR_PROV'
      DisplayFormat = 'c'
    end
    object TableNUM_REM_GUR_PROV: TFIBIntegerField
      FieldName = 'NUM_REM_GUR_PROV'
    end
    object TableDESCR_REM_GUR_PROV: TFIBWideStringField
      FieldName = 'DESCR_REM_GUR_PROV'
      Size = 150
    end
    object TableIDDOC_REM_GUR_PROV: TFIBLargeIntField
      FieldName = 'IDDOC_REM_GUR_PROV'
    end
    object TableIDUSER_REM_GUR_PROV: TFIBLargeIntField
      FieldName = 'IDUSER_REM_GUR_PROV'
    end
    object TableRES_REM_GUR_PROV: TFIBIntegerField
      FieldName = 'RES_REM_GUR_PROV'
    end
    object TableNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 200
    end
    object TableNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 200
    end
    object TableNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 200
    end
    object TableNAME_USER_DOC: TFIBWideStringField
      FieldName = 'NAME_USER_DOC'
      Size = 200
    end
    object TableNAME_USER_PROV: TFIBWideStringField
      FieldName = 'NAME_USER_PROV'
      Size = 200
    end
    object TableNAME_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 200
    end
    object TablePREFIKS_NUM_REM_GALLDOC: TFIBWideStringField
      FieldName = 'PREFIKS_NUM_REM_GALLDOC'
      Size = 12
    end
    object TablePR_REM_GALLDOC: TFIBSmallIntField
      FieldName = 'PR_REM_GALLDOC'
    end
    object TableNUM_REM_GALLDOC: TFIBIntegerField
      FieldName = 'NUM_REM_GALLDOC'
    end
    object TablePOS_REM_GALLDOC: TFIBDateTimeField
      FieldName = 'POS_REM_GALLDOC'
    end
    object TableTDOC_REM_GALLDOC: TFIBWideStringField
      FieldName = 'TDOC_REM_GALLDOC'
      OnGetText = TableTDOC_REM_GALLDOCGetText
      Size = 15
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
  object IBQ: TpFIBDataSet
    Left = 144
    Top = 128
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 224
    Top = 104
    qoStartTransaction = True
  end
end
