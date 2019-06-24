object DMReportGrid: TDMReportGrid
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 185
  Width = 328
  object Report: TpFIBDataSet
    SelectSQL.Strings = (
      '')
    Transaction = Tr
    Left = 176
    Top = 72
  end
  object Tr: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 240
    Top = 72
  end
  object DataSourceReport: TDataSource
    DataSet = Report
    Left = 88
    Top = 72
  end
end
