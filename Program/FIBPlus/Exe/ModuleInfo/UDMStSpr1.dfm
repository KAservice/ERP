object DMStSpr1: TDMStSpr1
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 213
  Width = 342
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select  * from SSKLAD')
    Transaction = IBTr
    Left = 168
    Top = 48
    poUseLargeIntField = True
    object TableIDSKLAD: TFIBLargeIntField
      FieldName = 'IDSKLAD'
    end
    object TableNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 200
    end
    object TableMOLSKLAD: TFIBWideStringField
      FieldName = 'MOLSKLAD'
    end
    object TableADRSKLAD: TFIBWideStringField
      FieldName = 'ADRSKLAD'
      Size = 200
    end
    object TableTSKLAD: TFIBSmallIntField
      FieldName = 'TSKLAD'
    end
    object TableGID_SSKLAD: TFIBWideStringField
      FieldName = 'GID_SSKLAD'
      Size = 10
    end
    object TableIDBASE_SSKLAD: TFIBLargeIntField
      FieldName = 'IDBASE_SSKLAD'
    end
    object TableIDEXT_DOUT_SSKLAD: TFIBLargeIntField
      FieldName = 'IDEXT_DOUT_SSKLAD'
    end
    object TableIDEXT_BASE_SSKLAD: TFIBLargeIntField
      FieldName = 'IDEXT_BASE_SSKLAD'
    end
    object TableDBLUCHETALLNOM_SSKLAD: TFIBSmallIntField
      FieldName = 'DBLUCHETALLNOM_SSKLAD'
    end
    object TableDBLUCHET_SSKLAD: TFIBSmallIntField
      FieldName = 'DBLUCHET_SSKLAD'
    end
    object TableTYPE_TBL_SSKLAD: TFIBSmallIntField
      FieldName = 'TYPE_TBL_SSKLAD'
    end
    object TablePREFIKS_NUM_SSKLAD: TFIBWideStringField
      FieldName = 'PREFIKS_NUM_SSKLAD'
      Size = 3
    end
  end
  object IBTr: TpFIBTransaction
    TimeoutAction = TARollback
    Left = 240
    Top = 48
  end
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 72
    Top = 48
  end
end
