object DMStSpr1: TDMStSpr1
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 213
  Width = 342
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      '')
    Transaction = IBTr
    Left = 168
    Top = 48
    poUseLargeIntField = True
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
