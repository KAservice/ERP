object DMPriemPlat: TDMPriemPlat
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 257
  Width = 280
  object IBQNumTel: TpFIBDataSet
    SelectSQL.Strings = (
      'select  IDKLIENT_NUMTEL '
      'from '
      '  SNUMTEL'
      'where '
      '  CODE_NUMTEL=:PARAM_CODE AND '
      '  NUMBER_NUMTEL=:PARAM_NUMBER')
    Transaction = IBTr
    DefaultFormats.DateTimeDisplayFormat = 'c'
    DefaultFormats.DisplayFormatTime = 'hh:mm'
    Left = 40
    Top = 24
    object IBQNumTelIDKLIENT_NUMTEL: TFIBBCDField
      FieldName = 'IDKLIENT_NUMTEL'
      Size = 0
      RoundByScale = True
    end
  end
  object IBQNom: TpFIBDataSet
    SelectSQL.Strings = (
      'select  SCODETEL.*,'
      ' IDNOM, NAMENOM, KRNAMENOM,IDBASEDNOM,'
      ' IDED, NAMEED, KFED'
      'from '
      '  SCODETEL'
      'left outer join SNOM on IDNOM_CODETEL=IDNOM'
      'left outer join SED on  IDOSNEDNOM=IDED'
      'where ID_CODETEL=:PARAM_ID'
      '  ')
    Transaction = IBTr
    DefaultFormats.DateTimeDisplayFormat = 'c'
    DefaultFormats.DisplayFormatTime = 'hh:mm'
    Left = 40
    Top = 72
    object IBQNomID_CODETEL: TFIBBCDField
      FieldName = 'ID_CODETEL'
      Size = 0
      RoundByScale = True
    end
    object IBQNomIDNOM_CODETEL: TFIBBCDField
      FieldName = 'IDNOM_CODETEL'
      Size = 0
      RoundByScale = True
    end
    object IBQNomCODE_CODETEL: TFIBWideStringField
      FieldName = 'CODE_CODETEL'
      Size = 3
    end
    object IBQNomGID_SCODETEL: TFIBWideStringField
      FieldName = 'GID_SCODETEL'
      Size = 10
    end
    object IBQNomNAME_CODETEL: TFIBWideStringField
      FieldName = 'NAME_CODETEL'
      Size = 200
    end
    object IBQNomCODOPER_CODETEL: TFIBWideStringField
      FieldName = 'CODOPER_CODETEL'
      Size = 5
    end
    object IBQNomIDNOMCOM_CODETEL: TFIBBCDField
      FieldName = 'IDNOMCOM_CODETEL'
      Size = 0
      RoundByScale = True
    end
    object IBQNomIDBASE_SCODETEL: TFIBBCDField
      FieldName = 'IDBASE_SCODETEL'
      Size = 0
      RoundByScale = True
    end
    object IBQNomIDEXT_DOUT_SCODETEL: TFIBBCDField
      FieldName = 'IDEXT_DOUT_SCODETEL'
      Size = 0
      RoundByScale = True
    end
    object IBQNomIDEXT_BASE_SCODETEL: TFIBBCDField
      FieldName = 'IDEXT_BASE_SCODETEL'
      Size = 0
      RoundByScale = True
    end
    object IBQNomTYPE_TBL_SCODETEL: TFIBSmallIntField
      FieldName = 'TYPE_TBL_SCODETEL'
    end
    object IBQNomIDNOM: TFIBBCDField
      FieldName = 'IDNOM'
      Size = 0
      RoundByScale = True
    end
    object IBQNomNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object IBQNomKRNAMENOM: TFIBWideStringField
      FieldName = 'KRNAMENOM'
      Size = 40
    end
    object IBQNomIDED: TFIBBCDField
      FieldName = 'IDED'
      Size = 0
      RoundByScale = True
    end
    object IBQNomNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 200
    end
    object IBQNomKFED: TFIBBCDField
      FieldName = 'KFED'
      Size = 3
      RoundByScale = True
    end
    object IBQNomIDBASEDNOM: TFIBBCDField
      FieldName = 'IDBASEDNOM'
      Size = 0
      RoundByScale = True
    end
    object IBQNomPRCOMIS_SCODETEL: TFIBBCDField
      FieldName = 'PRCOMIS_SCODETEL'
      Size = 2
      RoundByScale = True
    end
  end
  object IBQCom: TpFIBDataSet
    SelectSQL.Strings = (
      'select  SCODETEL.*,'
      ' IDNOM, NAMENOM, KRNAMENOM,IDBASEDNOM,'
      ' IDED, NAMEED, KFED'
      'from '
      '  SCODETEL'
      'left outer join SNOM on IDNOMCOM_CODETEL=IDNOM'
      'left outer join SED on  IDOSNEDNOM=IDED'
      'where ID_CODETEL=:PARAM_ID')
    Transaction = IBTr
    DefaultFormats.DateTimeDisplayFormat = 'c'
    DefaultFormats.DisplayFormatTime = 'hh:mm'
    Left = 40
    Top = 120
    object IBQComID_CODETEL: TFIBBCDField
      FieldName = 'ID_CODETEL'
      Size = 0
      RoundByScale = True
    end
    object IBQComIDNOM_CODETEL: TFIBBCDField
      FieldName = 'IDNOM_CODETEL'
      Size = 0
      RoundByScale = True
    end
    object IBQComCODE_CODETEL: TFIBWideStringField
      FieldName = 'CODE_CODETEL'
      Size = 3
    end
    object IBQComGID_SCODETEL: TFIBWideStringField
      FieldName = 'GID_SCODETEL'
      Size = 10
    end
    object IBQComNAME_CODETEL: TFIBWideStringField
      FieldName = 'NAME_CODETEL'
      Size = 200
    end
    object IBQComCODOPER_CODETEL: TFIBWideStringField
      FieldName = 'CODOPER_CODETEL'
      Size = 5
    end
    object IBQComIDNOMCOM_CODETEL: TFIBBCDField
      FieldName = 'IDNOMCOM_CODETEL'
      Size = 0
      RoundByScale = True
    end
    object IBQComIDBASE_SCODETEL: TFIBBCDField
      FieldName = 'IDBASE_SCODETEL'
      Size = 0
      RoundByScale = True
    end
    object IBQComIDEXT_DOUT_SCODETEL: TFIBBCDField
      FieldName = 'IDEXT_DOUT_SCODETEL'
      Size = 0
      RoundByScale = True
    end
    object IBQComIDEXT_BASE_SCODETEL: TFIBBCDField
      FieldName = 'IDEXT_BASE_SCODETEL'
      Size = 0
      RoundByScale = True
    end
    object IBQComTYPE_TBL_SCODETEL: TFIBSmallIntField
      FieldName = 'TYPE_TBL_SCODETEL'
    end
    object IBQComIDNOM: TFIBBCDField
      FieldName = 'IDNOM'
      Size = 0
      RoundByScale = True
    end
    object IBQComNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object IBQComKRNAMENOM: TFIBWideStringField
      FieldName = 'KRNAMENOM'
      Size = 40
    end
    object IBQComIDED: TFIBBCDField
      FieldName = 'IDED'
      Size = 0
      RoundByScale = True
    end
    object IBQComNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 200
    end
    object IBQComKFED: TFIBBCDField
      FieldName = 'KFED'
      Size = 3
      RoundByScale = True
    end
    object IBQComIDBASEDNOM: TFIBBCDField
      FieldName = 'IDBASEDNOM'
      Size = 0
      RoundByScale = True
    end
    object IBQComPRCOMIS_SCODETEL: TFIBBCDField
      FieldName = 'PRCOMIS_SCODETEL'
      Size = 2
      RoundByScale = True
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
    Left = 120
    Top = 72
  end
end
