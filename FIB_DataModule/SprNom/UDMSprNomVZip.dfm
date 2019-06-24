object DMSprNomVZip: TDMSprNomVZip
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 259
  Width = 440
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 8
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      'from SNOM_VZIP_GET_TABLE_FULL ('
      '    :PARAM_IDGRP,'
      '    :PARAM_FL_ALL_GRP,'
      '    :PARAM_IDFIRM,'
      '    :PARAM_FL_RASV_FIRM,'
      '    :PARAM_IDSKLAD,'
      '    :PARAM_FL_RASV_SKLAD,'
      '    :PARAM_IDKLIENT,'
      '    :PARAM_FL_RASV_KLIENT,'
      '    :PARAM_IDTNOM,'
      '    :PARAM_FL_RASV_TNOM,'
      '    :PARAM_IDTYPE_PRICE,'
      '    :PARAM_IDNOM,'
      '    :PARAM_FL_RASV_PO_Z,'
      '    :PARAM_FL_OST,'
      '    :PARAM_FL_POISK,'
      '    :PARAM_STR_FOR_POISK)')
    AfterScroll = TableAfterScroll
    Transaction = IBTr
    Left = 160
    Top = 8
    poUseLargeIntField = True
    object TableOUT_IDNOM: TFIBLargeIntField
      FieldName = 'OUT_IDNOM'
    end
    object TableOUT_NAME_NOM: TFIBWideStringField
      FieldName = 'OUT_NAME_NOM'
      Size = 200
    end
    object TableOUT_CODE: TFIBIntegerField
      FieldName = 'OUT_CODE'
    end
    object TableOUT_ARTIKUL: TFIBWideStringField
      FieldName = 'OUT_ARTIKUL'
      Size = 40
    end
    object TableOUT_IDED: TFIBLargeIntField
      FieldName = 'OUT_IDED'
    end
    object TableOUT_NAME_ED: TFIBWideStringField
      FieldName = 'OUT_NAME_ED'
      Size = 200
    end
    object TableOUT_SHED: TFIBWideStringField
      FieldName = 'OUT_SHED'
      Size = 13
    end
    object TableOUT_PRICE: TFIBBCDField
      FieldName = 'OUT_PRICE'
      Size = 2
      RoundByScale = True
    end
    object TableOUT_OST: TFIBBCDField
      FieldName = 'OUT_OST'
      Size = 3
      RoundByScale = True
    end
    object TableOUT_IDFIRM: TFIBLargeIntField
      FieldName = 'OUT_IDFIRM'
    end
    object TableOUT_NAME_FIRM: TFIBWideStringField
      FieldName = 'OUT_NAME_FIRM'
      Size = 200
    end
    object TableOUT_IDSKLAD: TFIBLargeIntField
      FieldName = 'OUT_IDSKLAD'
    end
    object TableOUT_NAME_SKLAD: TFIBWideStringField
      FieldName = 'OUT_NAME_SKLAD'
      Size = 200
    end
    object TableOUT_IDKLIENT: TFIBLargeIntField
      FieldName = 'OUT_IDKLIENT'
    end
    object TableOUT_NAME_KLIENT: TFIBWideStringField
      FieldName = 'OUT_NAME_KLIENT'
      Size = 200
    end
    object TableOUT_IDTNOM: TFIBLargeIntField
      FieldName = 'OUT_IDTNOM'
    end
    object TableOUT_NAME_TNOM: TFIBWideStringField
      FieldName = 'OUT_NAME_TNOM'
      Size = 200
    end
    object TableOUT_IDZ: TFIBLargeIntField
      FieldName = 'OUT_IDZ'
    end
    object TableOUT_NAME_Z: TFIBWideStringField
      FieldName = 'OUT_NAME_Z'
      Size = 200
    end
    object TableOUT_IDGRPNOM: TFIBLargeIntField
      FieldName = 'OUT_IDGRPNOM'
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableOUT_IDMHRAN: TFIBLargeIntField
      FieldName = 'OUT_IDMHRAN'
    end
    object TableOUT_NAME_MHRAN: TFIBWideStringField
      FieldName = 'OUT_NAME_MHRAN'
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
    Left = 256
    Top = 8
  end
  object pFIBQuery: TpFIBQuery
    Left = 160
    Top = 72
    qoStartTransaction = True
  end
  object SpTPrice: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from STPRICE')
    Transaction = IBTr
    Left = 72
    Top = 72
    object SpTPriceID_TPRICE: TFIBBCDField
      FieldName = 'ID_TPRICE'
      Size = 0
      RoundByScale = True
    end
    object SpTPriceNAME_TPRICE: TFIBWideStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
    end
  end
end
