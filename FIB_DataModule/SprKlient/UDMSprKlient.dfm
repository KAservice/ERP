object DMSprKlient: TDMSprKlient
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 322
  Width = 322
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 24
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 48
    Top = 80
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      
        'select IDKLIENT, IDGRPKLIENT, NAMEKLIENT, INNKLIENT, TELKLIENT, ' +
        'ADRKLIENT from SKLIENT')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 136
    Top = 24
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableIDKLIENT: TFIBBCDField
      FieldName = 'IDKLIENT'
      Size = 0
      RoundByScale = True
    end
    object TableIDGRPKLIENT: TFIBBCDField
      FieldName = 'IDGRPKLIENT'
      Size = 0
      RoundByScale = True
    end
    object TableNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 100
    end
    object TableINNKLIENT: TFIBWideStringField
      FieldName = 'INNKLIENT'
      Size = 12
    end
    object TableTELKLIENT: TFIBWideStringField
      FieldName = 'TELKLIENT'
      Size = 100
    end
    object TableADRKLIENT: TFIBWideStringField
      FieldName = 'ADRKLIENT'
      Size = 100
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SKLIENT'
      'SET '
      '    NAMEKLIENT = :NAMEKLIENT,'
      '    FNAME = :FNAME,'
      '    ADRKLIENT = :ADRKLIENT,'
      '    TELKLIENT = :TELKLIENT,'
      '    INNKLIENT = :INNKLIENT,'
      '    KPPKLIENT = :KPPKLIENT,'
      '    TKLIENT = :TKLIENT,'
      '    IDTPRICEKLIENT = :IDTPRICEKLIENT,'
      '    IDGRPKLIENT = :IDGRPKLIENT,'
      '    GID_SKLIENT = :GID_SKLIENT,'
      '    OKPOKLIENT = :OKPOKLIENT,'
      '    IDVIDKLIENT = :IDVIDKLIENT,'
      '    IDCOUNTRYKLIENT = :IDCOUNTRYKLIENT,'
      '    IDBASE_SKLIENT = :IDBASE_SKLIENT,'
      '    KRNAME_SKLIENT = :KRNAME_SKLIENT,'
      '    DESCR_SKLIENT = :DESCR_SKLIENT,'
      '    MESSAGE_SKLIENT = :MESSAGE_SKLIENT,'
      '    EMAIL_SKLIENT = :EMAIL_SKLIENT,'
      '    WWW_SKLIENT = :WWW_SKLIENT,'
      '    MAXCREDIT_SKLIENT = :MAXCREDIT_SKLIENT,'
      '    YUR_ADRESS_SKLIENT = :YUR_ADRESS_SKLIENT,'
      '    POCHT_ADRRESS_SKLIENT = :POCHT_ADRRESS_SKLIENT,'
      '    FAMILIYA_SKLIENT = :FAMILIYA_SKLIENT,'
      '    IMYA_SKLIENT = :IMYA_SKLIENT,'
      '    OTCHESTVO_SKLIENT = :OTCHESTVO_SKLIENT,'
      '    TYPE_POISK_SKLIENT = :TYPE_POISK_SKLIENT,'
      '    IDGRPNOM_SKLIENT = :IDGRPNOM_SKLIENT,'
      '    IDGRPHW_SKLIENT = :IDGRPHW_SKLIENT'
      'WHERE'
      '    IDKLIENT = :OLD_IDKLIENT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SKLIENT'
      'WHERE'
      '        IDKLIENT = :OLD_IDKLIENT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SKLIENT('
      '    IDKLIENT,'
      '    NAMEKLIENT,'
      '    FNAME,'
      '    ADRKLIENT,'
      '    TELKLIENT,'
      '    INNKLIENT,'
      '    KPPKLIENT,'
      '    TKLIENT,'
      '    IDTPRICEKLIENT,'
      '    IDGRPKLIENT,'
      '    GID_SKLIENT,'
      '    OKPOKLIENT,'
      '    IDVIDKLIENT,'
      '    IDCOUNTRYKLIENT,'
      '    IDBASE_SKLIENT,'
      '    KRNAME_SKLIENT,'
      '    DESCR_SKLIENT,'
      '    MESSAGE_SKLIENT,'
      '    EMAIL_SKLIENT,'
      '    WWW_SKLIENT,'
      '    MAXCREDIT_SKLIENT,'
      '    YUR_ADRESS_SKLIENT,'
      '    POCHT_ADRRESS_SKLIENT,'
      '    FAMILIYA_SKLIENT,'
      '    IMYA_SKLIENT,'
      '    OTCHESTVO_SKLIENT,'
      '    TYPE_POISK_SKLIENT,'
      '    IDGRPNOM_SKLIENT,'
      '    IDGRPHW_SKLIENT'
      ')'
      'VALUES('
      '    :IDKLIENT,'
      '    :NAMEKLIENT,'
      '    :FNAME,'
      '    :ADRKLIENT,'
      '    :TELKLIENT,'
      '    :INNKLIENT,'
      '    :KPPKLIENT,'
      '    :TKLIENT,'
      '    :IDTPRICEKLIENT,'
      '    :IDGRPKLIENT,'
      '    :GID_SKLIENT,'
      '    :OKPOKLIENT,'
      '    :IDVIDKLIENT,'
      '    :IDCOUNTRYKLIENT,'
      '    :IDBASE_SKLIENT,'
      '    :KRNAME_SKLIENT,'
      '    :DESCR_SKLIENT,'
      '    :MESSAGE_SKLIENT,'
      '    :EMAIL_SKLIENT,'
      '    :WWW_SKLIENT,'
      '    :MAXCREDIT_SKLIENT,'
      '    :YUR_ADRESS_SKLIENT,'
      '    :POCHT_ADRRESS_SKLIENT,'
      '    :FAMILIYA_SKLIENT,'
      '    :IMYA_SKLIENT,'
      '    :OTCHESTVO_SKLIENT,'
      '    :TYPE_POISK_SKLIENT,'
      '    :IDGRPNOM_SKLIENT,'
      '    :IDGRPHW_SKLIENT'
      ')')
    RefreshSQL.Strings = (
      'select SKLIENT.*, NAME_SVIDKLIENT, NAME_SCOUNTRY,'
      '          sgrpnom.namegn,'
      '          rem_sgrp_hardware.name_rem_sgrp_hardware'
      'from SKLIENT '
      'left outer join SVIDKLIENT on ID_SVIDKLIENT=IDVIDKLIENT'
      'left outer join SCOUNTRY on ID_SCOUNTRY=IDCOUNTRYKLIENT'
      'left outer join sgrpnom on sklient.idgrpnom_sklient=sgrpnom.idgn'
      
        'left outer join rem_sgrp_hardware on sklient.idgrphw_sklient=rem' +
        '_sgrp_hardware.id_rem_sgrp_hardware'
      'where(  IDKLIENT=:ID'
      '     ) and (     SKLIENT.IDKLIENT = :OLD_IDKLIENT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select SKLIENT.*, NAME_SVIDKLIENT, NAME_SCOUNTRY,'
      '          sgrpnom.namegn,'
      '          rem_sgrp_hardware.name_rem_sgrp_hardware'
      'from SKLIENT '
      'left outer join SVIDKLIENT on ID_SVIDKLIENT=IDVIDKLIENT'
      'left outer join SCOUNTRY on ID_SCOUNTRY=IDCOUNTRYKLIENT'
      'left outer join sgrpnom on sklient.idgrpnom_sklient=sgrpnom.idgn'
      
        'left outer join rem_sgrp_hardware on sklient.idgrphw_sklient=rem' +
        '_sgrp_hardware.id_rem_sgrp_hardware'
      'where IDKLIENT=:ID')
    AutoUpdateOptions.UpdateTableName = 'SKLIENT'
    AutoUpdateOptions.KeyFields = 'IDKLIENT'
    AutoUpdateOptions.GeneratorName = 'GEN_SKLIENT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 136
    Top = 80
    object ElementIDKLIENT: TFIBBCDField
      FieldName = 'IDKLIENT'
      Size = 0
      RoundByScale = True
    end
    object ElementIDTPRICEKLIENT: TFIBBCDField
      FieldName = 'IDTPRICEKLIENT'
      Size = 0
      RoundByScale = True
    end
    object ElementIDGRPKLIENT: TFIBBCDField
      FieldName = 'IDGRPKLIENT'
      Size = 0
      RoundByScale = True
    end
    object ElementIDVIDKLIENT: TFIBBCDField
      FieldName = 'IDVIDKLIENT'
      Size = 0
      RoundByScale = True
    end
    object ElementIDCOUNTRYKLIENT: TFIBBCDField
      FieldName = 'IDCOUNTRYKLIENT'
      Size = 0
      RoundByScale = True
    end
    object ElementMAXCREDIT_SKLIENT: TFIBBCDField
      FieldName = 'MAXCREDIT_SKLIENT'
      Size = 2
      RoundByScale = True
    end
    object ElementNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 200
    end
    object ElementFNAME: TFIBWideStringField
      FieldName = 'FNAME'
      Size = 200
    end
    object ElementADRKLIENT: TFIBWideStringField
      FieldName = 'ADRKLIENT'
      Size = 200
    end
    object ElementTELKLIENT: TFIBWideStringField
      FieldName = 'TELKLIENT'
      Size = 200
    end
    object ElementINNKLIENT: TFIBWideStringField
      FieldName = 'INNKLIENT'
      Size = 12
    end
    object ElementKPPKLIENT: TFIBWideStringField
      FieldName = 'KPPKLIENT'
      Size = 9
    end
    object ElementTKLIENT: TFIBIntegerField
      FieldName = 'TKLIENT'
    end
    object ElementGID_SKLIENT: TFIBWideStringField
      FieldName = 'GID_SKLIENT'
      Size = 10
    end
    object ElementOKPOKLIENT: TFIBWideStringField
      FieldName = 'OKPOKLIENT'
      Size = 10
    end
    object ElementIDBASE_SKLIENT: TFIBBCDField
      FieldName = 'IDBASE_SKLIENT'
      Size = 0
      RoundByScale = True
    end
    object ElementKRNAME_SKLIENT: TFIBWideStringField
      FieldName = 'KRNAME_SKLIENT'
      Size = 200
    end
    object ElementDESCR_SKLIENT: TFIBWideStringField
      FieldName = 'DESCR_SKLIENT'
      Size = 250
    end
    object ElementMESSAGE_SKLIENT: TFIBWideStringField
      FieldName = 'MESSAGE_SKLIENT'
      Size = 150
    end
    object ElementEMAIL_SKLIENT: TFIBWideStringField
      FieldName = 'EMAIL_SKLIENT'
      Size = 200
    end
    object ElementWWW_SKLIENT: TFIBWideStringField
      FieldName = 'WWW_SKLIENT'
      Size = 200
    end
    object ElementNAME_SVIDKLIENT: TFIBWideStringField
      FieldName = 'NAME_SVIDKLIENT'
      Size = 200
    end
    object ElementNAME_SCOUNTRY: TFIBWideStringField
      FieldName = 'NAME_SCOUNTRY'
      Size = 200
    end
    object ElementYUR_ADRESS_SKLIENT: TFIBWideStringField
      FieldName = 'YUR_ADRESS_SKLIENT'
      Size = 200
    end
    object ElementPOCHT_ADRRESS_SKLIENT: TFIBWideStringField
      FieldName = 'POCHT_ADRRESS_SKLIENT'
      Size = 200
    end
    object ElementFAMILIYA_SKLIENT: TFIBWideStringField
      FieldName = 'FAMILIYA_SKLIENT'
      Size = 30
    end
    object ElementIMYA_SKLIENT: TFIBWideStringField
      FieldName = 'IMYA_SKLIENT'
      Size = 30
    end
    object ElementOTCHESTVO_SKLIENT: TFIBWideStringField
      FieldName = 'OTCHESTVO_SKLIENT'
      Size = 30
    end
    object ElementTYPE_POISK_SKLIENT: TFIBIntegerField
      FieldName = 'TYPE_POISK_SKLIENT'
    end
    object ElementIDGRPNOM_SKLIENT: TFIBBCDField
      FieldName = 'IDGRPNOM_SKLIENT'
      Size = 0
      RoundByScale = True
    end
    object ElementIDGRPHW_SKLIENT: TFIBBCDField
      FieldName = 'IDGRPHW_SKLIENT'
      Size = 0
      RoundByScale = True
    end
    object ElementNAMEGN: TFIBWideStringField
      FieldName = 'NAMEGN'
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
    Left = 232
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
    Left = 232
    Top = 80
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 216
    Top = 200
    qoStartTransaction = True
  end
end
