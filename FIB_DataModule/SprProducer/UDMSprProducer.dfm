object DMSprProducer: TDMSprProducer
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
      'select sproducer.*,'
      '    sklient.nameklient,'
      '    sklient.innklient'
      'from sproducer'
      
        'left outer join sklient on sproducer.idklient_sproducer=sklient.' +
        'idklient'
      'order by sproducer.name_sproducer')
    Transaction = IBTr
    Left = 144
    Top = 16
    poUseLargeIntField = True
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_SPRODUCER: TFIBLargeIntField
      FieldName = 'ID_SPRODUCER'
    end
    object TableIDBASE_SPRODUCER: TFIBLargeIntField
      FieldName = 'IDBASE_SPRODUCER'
    end
    object TableGID_SPRODUCER: TFIBWideStringField
      FieldName = 'GID_SPRODUCER'
      Size = 10
    end
    object TableNAME_SPRODUCER: TFIBWideStringField
      FieldName = 'NAME_SPRODUCER'
      Size = 200
    end
    object TableIDKLIENT_SPRODUCER: TFIBLargeIntField
      FieldName = 'IDKLIENT_SPRODUCER'
    end
    object TableNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 200
    end
    object TableINNKLIENT: TFIBWideStringField
      FieldName = 'INNKLIENT'
      Size = 12
    end
    object TablePOSZAGRNOM_SPRODUCER: TFIBDateTimeField
      FieldName = 'POSZAGRNOM_SPRODUCER'
      DisplayFormat = 'c'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SPRODUCER'
      'SET '
      '    IDBASE_SPRODUCER = :IDBASE_SPRODUCER,'
      '    GID_SPRODUCER = :GID_SPRODUCER,'
      '    NAME_SPRODUCER = :NAME_SPRODUCER,'
      '    IDKLIENT_SPRODUCER = :IDKLIENT_SPRODUCER,'
      '    IDPOST_ZIP_SPRODUCER = :IDPOST_ZIP_SPRODUCER,'
      '    POSZAGRNOM_SPRODUCER = :POSZAGRNOM_SPRODUCER,'
      '    TYPE_POISK_SPRNOM_SPRODUCER = :TYPE_POISK_SPRNOM_SPRODUCER,'
      '    IDINETCAT_USL_SPRODUCER = :IDINETCAT_USL_SPRODUCER,'
      '    IDGRPINETCAT_USL_SPRODUCER = :IDGRPINETCAT_USL_SPRODUCER,'
      '    IDGRPNOM_ZIP_SPRODUCER = :IDGRPNOM_ZIP_SPRODUCER,'
      '    IDGRPNOM_RAB_SPRODUCER = :IDGRPNOM_RAB_SPRODUCER,'
      '    IDGRP_HW_SPRODUCER = :IDGRP_HW_SPRODUCER'
      'WHERE'
      '    ID_SPRODUCER = :OLD_ID_SPRODUCER'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SPRODUCER'
      'WHERE'
      '        ID_SPRODUCER = :OLD_ID_SPRODUCER'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SPRODUCER('
      '    ID_SPRODUCER,'
      '    IDBASE_SPRODUCER,'
      '    GID_SPRODUCER,'
      '    NAME_SPRODUCER,'
      '    IDKLIENT_SPRODUCER,'
      '    IDPOST_ZIP_SPRODUCER,'
      '    POSZAGRNOM_SPRODUCER,'
      '    TYPE_POISK_SPRNOM_SPRODUCER,'
      '    IDINETCAT_USL_SPRODUCER,'
      '    IDGRPINETCAT_USL_SPRODUCER,'
      '    IDGRPNOM_ZIP_SPRODUCER,'
      '    IDGRPNOM_RAB_SPRODUCER,'
      '    IDGRP_HW_SPRODUCER'
      ')'
      'VALUES('
      '    :ID_SPRODUCER,'
      '    :IDBASE_SPRODUCER,'
      '    :GID_SPRODUCER,'
      '    :NAME_SPRODUCER,'
      '    :IDKLIENT_SPRODUCER,'
      '    :IDPOST_ZIP_SPRODUCER,'
      '    :POSZAGRNOM_SPRODUCER,'
      '    :TYPE_POISK_SPRNOM_SPRODUCER,'
      '    :IDINETCAT_USL_SPRODUCER,'
      '    :IDGRPINETCAT_USL_SPRODUCER,'
      '    :IDGRPNOM_ZIP_SPRODUCER,'
      '    :IDGRPNOM_RAB_SPRODUCER,'
      '    :IDGRP_HW_SPRODUCER'
      ')')
    RefreshSQL.Strings = (
      'select sproducer.*,'
      '       sklient.nameklient,'
      '       post_zip.nameklient  as post_zip_name,'
      '       sinetcatalog.name_sinetcatalog, '
      '       snominetcat_grp.name_snominetcat_grp,'
      '       sgrpnom.namegn,'
      '       RAB.namegn as RAB_namegn,'
      '       rem_sgrp_hardware.name_rem_sgrp_hardware'
      'from sproducer'
      
        'left outer join sklient on sproducer.idklient_sproducer=sklient.' +
        'idklient'
      
        'left outer join sklient as post_zip on sproducer.idpost_zip_spro' +
        'ducer=post_zip.idklient'
      
        'left outer join sinetcatalog on sinetcatalog.id_sinetcatalog=spr' +
        'oducer.idinetcat_usl_sproducer'
      
        'left outer join snominetcat_grp on snominetcat_grp.id_snominetca' +
        't_grp=sproducer.idgrpinetcat_usl_sproducer'
      
        'left outer join sgrpnom on sproducer.idgrpnom_zip_sproducer=sgrp' +
        'nom.idgn'
      
        'left outer join sgrpnom as RAB on sproducer.idgrpnom_rab_sproduc' +
        'er=RAB.idgn'
      
        'left outer join rem_sgrp_hardware on sproducer.idgrp_hw_sproduce' +
        'r=rem_sgrp_hardware.id_rem_sgrp_hardware'
      'where(  sproducer.id_sproducer=:PARAM_ID'
      '     ) and (     SPRODUCER.ID_SPRODUCER = :OLD_ID_SPRODUCER'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select sproducer.*,'
      '       sklient.nameklient,'
      '       post_zip.nameklient  as post_zip_name,'
      '       sinetcatalog.name_sinetcatalog, '
      '       snominetcat_grp.name_snominetcat_grp,'
      '       sgrpnom.namegn,'
      '       RAB.namegn as RAB_namegn,'
      '       rem_sgrp_hardware.name_rem_sgrp_hardware'
      'from sproducer'
      
        'left outer join sklient on sproducer.idklient_sproducer=sklient.' +
        'idklient'
      
        'left outer join sklient as post_zip on sproducer.idpost_zip_spro' +
        'ducer=post_zip.idklient'
      
        'left outer join sinetcatalog on sinetcatalog.id_sinetcatalog=spr' +
        'oducer.idinetcat_usl_sproducer'
      
        'left outer join snominetcat_grp on snominetcat_grp.id_snominetca' +
        't_grp=sproducer.idgrpinetcat_usl_sproducer'
      
        'left outer join sgrpnom on sproducer.idgrpnom_zip_sproducer=sgrp' +
        'nom.idgn'
      
        'left outer join sgrpnom as RAB on sproducer.idgrpnom_rab_sproduc' +
        'er=RAB.idgn'
      
        'left outer join rem_sgrp_hardware on sproducer.idgrp_hw_sproduce' +
        'r=rem_sgrp_hardware.id_rem_sgrp_hardware'
      'where sproducer.id_sproducer=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SPRODUCER'
    AutoUpdateOptions.KeyFields = 'ID_SPRODUCER'
    AutoUpdateOptions.GeneratorName = 'GEN_SPRODUCER_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 80
    poUseLargeIntField = True
    object ElementID_SPRODUCER: TFIBLargeIntField
      FieldName = 'ID_SPRODUCER'
    end
    object ElementIDBASE_SPRODUCER: TFIBLargeIntField
      FieldName = 'IDBASE_SPRODUCER'
    end
    object ElementGID_SPRODUCER: TFIBWideStringField
      FieldName = 'GID_SPRODUCER'
      Size = 10
    end
    object ElementNAME_SPRODUCER: TFIBWideStringField
      FieldName = 'NAME_SPRODUCER'
      Size = 200
    end
    object ElementIDKLIENT_SPRODUCER: TFIBLargeIntField
      FieldName = 'IDKLIENT_SPRODUCER'
    end
    object ElementNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 200
    end
    object ElementIDPOST_ZIP_SPRODUCER: TFIBLargeIntField
      FieldName = 'IDPOST_ZIP_SPRODUCER'
    end
    object ElementPOST_ZIP_NAME: TFIBWideStringField
      FieldName = 'POST_ZIP_NAME'
      Size = 200
    end
    object ElementPOSZAGRNOM_SPRODUCER: TFIBDateTimeField
      FieldName = 'POSZAGRNOM_SPRODUCER'
      DisplayFormat = 'c'
    end
    object ElementTYPE_POISK_SPRNOM_SPRODUCER: TFIBIntegerField
      FieldName = 'TYPE_POISK_SPRNOM_SPRODUCER'
    end
    object ElementIDINETCAT_USL_SPRODUCER: TFIBLargeIntField
      FieldName = 'IDINETCAT_USL_SPRODUCER'
    end
    object ElementIDGRPINETCAT_USL_SPRODUCER: TFIBLargeIntField
      FieldName = 'IDGRPINETCAT_USL_SPRODUCER'
    end
    object ElementNAME_SINETCATALOG: TFIBWideStringField
      FieldName = 'NAME_SINETCATALOG'
      Size = 200
    end
    object ElementNAME_SNOMINETCAT_GRP: TFIBWideStringField
      FieldName = 'NAME_SNOMINETCAT_GRP'
      Size = 200
    end
    object ElementIDGRPNOM_ZIP_SPRODUCER: TFIBLargeIntField
      FieldName = 'IDGRPNOM_ZIP_SPRODUCER'
    end
    object ElementIDGRPNOM_RAB_SPRODUCER: TFIBLargeIntField
      FieldName = 'IDGRPNOM_RAB_SPRODUCER'
    end
    object ElementIDGRP_HW_SPRODUCER: TFIBLargeIntField
      FieldName = 'IDGRP_HW_SPRODUCER'
    end
    object ElementNAMEGN: TFIBWideStringField
      FieldName = 'NAMEGN'
      Size = 200
    end
    object ElementRAB_NAMEGN: TFIBWideStringField
      FieldName = 'RAB_NAMEGN'
      Size = 200
    end
    object ElementNAME_REM_SGRP_HARDWARE: TFIBWideStringField
      FieldName = 'NAME_REM_SGRP_HARDWARE'
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
