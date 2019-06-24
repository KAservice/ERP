object MainForm: TMainForm
  Left = 218
  Top = 129
  Caption = #1055#1088#1086#1074#1077#1076#1077#1085#1080#1077' '#1076#1086#1082#1091#1084#1077#1085#1090#1086#1074
  ClientHeight = 329
  ClientWidth = 516
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 120
  TextHeight = 16
  object ProgressBar1: TProgressBar
    Left = 0
    Top = 284
    Width = 516
    Height = 26
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    TabOrder = 0
  end
  object Memo1: TMemo
    Left = 0
    Top = 0
    Width = 516
    Height = 284
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    Lines.Strings = (
      'Memo1')
    TabOrder = 1
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 310
    Width = 516
    Height = 19
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Panels = <
      item
        Width = 100
      end
      item
        Width = 50
      end>
  end
  object Timer1: TTimer
    Interval = 60000
    OnTimer = Timer1Timer
    Left = 152
    Top = 56
  end
  object Database: TpFIBDatabase
    DBParams.Strings = (
      'lc_ctype=UTF8'
      'user_name=SYSDBA'
      'password=masterkey')
    DefaultTransaction = DefaultTransaction
    DefaultUpdateTransaction = DefaultTransaction
    SQLDialect = 3
    Timeout = 0
    LibraryName = 'fbclient.dll'
    WaitForRestoreConnect = 0
    Left = 40
    Top = 152
  end
  object DefaultTransaction: TpFIBTransaction
    DefaultDatabase = Database
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 136
    Top = 152
  end
  object Query: TpFIBQuery
    Transaction = TransactionRead
    Database = Database
    Left = 336
    Top = 72
    qoStartTransaction = True
  end
  object TransactionRead: TpFIBTransaction
    DefaultDatabase = Database
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 424
    Top = 72
  end
  object QueryUpdate: TpFIBQuery
    Transaction = TransactionUpdate
    Database = Database
    Left = 336
    Top = 184
    qoStartTransaction = True
  end
  object TransactionUpdate: TpFIBTransaction
    DefaultDatabase = Database
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 432
    Top = 184
  end
  object GurAllDoc: TpFIBDataSet
    SelectSQL.Strings = (
      'select '
      'rem_galldoc.*'
      'from rem_galldoc'
      
        'where rem_galldoc.pos_rem_galldoc between  :PARAM_DATE_NACH and ' +
        ':PARAM_DATE_CON'
      'order by rem_galldoc.pos_rem_galldoc')
    Transaction = DefaultTransaction
    Database = Database
    Left = 48
    Top = 224
    object GurAllDocID_REM_GALLDOC: TFIBBCDField
      FieldName = 'ID_REM_GALLDOC'
      Size = 0
      RoundByScale = True
    end
    object GurAllDocPOS_REM_GALLDOC: TFIBDateTimeField
      FieldName = 'POS_REM_GALLDOC'
    end
    object GurAllDocNUM_REM_GALLDOC: TFIBIntegerField
      FieldName = 'NUM_REM_GALLDOC'
    end
    object GurAllDocPR_REM_GALLDOC: TFIBSmallIntField
      FieldName = 'PR_REM_GALLDOC'
    end
    object GurAllDocTDOC_REM_GALLDOC: TFIBWideStringField
      FieldName = 'TDOC_REM_GALLDOC'
      Size = 10
    end
  end
end
