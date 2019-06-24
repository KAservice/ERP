object FormaImportPrice: TFormaImportPrice
  Left = 0
  Top = 0
  Caption = #1047#1072#1075#1088#1091#1079#1082#1072' '#1094#1077#1085' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099
  ClientHeight = 671
  ClientWidth = 1006
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 120
  TextHeight = 17
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 1006
    Height = 169
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 10
      Top = 8
      Width = 141
      Height = 28
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1048#1084#1087#1086#1088#1090' '#1094#1077#1085
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -23
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label13: TLabel
      Left = 21
      Top = 50
      Width = 38
      Height = 17
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1060#1072#1081#1083':'
    end
    object Label3: TLabel
      Left = 21
      Top = 84
      Width = 96
      Height = 51
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1090#1088#1086#1082#1072' '#1085#1072#1095#1072#1083#1072' '#1090#1072#1073#1083#1080#1095#1085#1086#1081' '#1095#1072#1089#1090#1080':'
      WordWrap = True
    end
    object Label4: TLabel
      Left = 466
      Top = 90
      Width = 101
      Height = 34
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099':'
      WordWrap = True
    end
    object Label5: TLabel
      Left = 221
      Top = 84
      Width = 93
      Height = 51
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1090#1088#1086#1082#1072' '#1082#1086#1085#1094#1072' '#1090#1072#1073#1083#1080#1095#1085#1086#1081' '#1095#1072#1089#1090#1080':'
      WordWrap = True
    end
    object Label2: TLabel
      Left = 21
      Top = 129
      Width = 97
      Height = 34
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1090#1080#1087#1072' '#1094#1077#1085':'
      WordWrap = True
    end
    object Label6: TLabel
      Left = 277
      Top = 129
      Width = 97
      Height = 34
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1077#1076#1080#1085#1080#1094#1099':'
      WordWrap = True
    end
    object Label7: TLabel
      Left = 628
      Top = 129
      Width = 37
      Height = 17
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1062#1077#1085#1072':'
      WordWrap = True
    end
    object FileNamecxButtonEdit: TcxButtonEdit
      Left = 68
      Top = 46
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.OnButtonClick = FileNamecxButtonEditPropertiesButtonClick
      TabOrder = 0
      Text = 'FileNamecxButtonEdit'
      Width = 408
    end
    object StartStringcxSpinEdit: TcxSpinEdit
      Left = 146
      Top = 86
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      TabOrder = 1
      Width = 59
    end
    object NameNomcxSpinEdit: TcxSpinEdit
      Left = 685
      Top = 86
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      TabOrder = 2
      Width = 59
    end
    object ConStringcxSpinEdit: TcxSpinEdit
      Left = 366
      Top = 86
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      TabOrder = 3
      Width = 59
    end
    object NameTypePricecxSpinEdit: TcxSpinEdit
      Left = 197
      Top = 126
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      TabOrder = 4
      Width = 59
    end
    object NameEdcxSpinEdit: TcxSpinEdit
      Left = 459
      Top = 126
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      TabOrder = 5
      Width = 59
    end
    object PricecxSpinEdit: TcxSpinEdit
      Left = 685
      Top = 126
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      TabOrder = 6
      Width = 59
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 615
    Width = 1006
    Height = 56
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object LabelError: TLabel
      Left = 10
      Top = 8
      Width = 828
      Height = 35
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      AutoSize = False
      Caption = 'LabelError'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      WordWrap = True
    end
    object cxButtonClose: TcxButton
      Left = 870
      Top = 8
      Width = 98
      Height = 33
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1047#1072#1082#1088#1099#1090#1100
      TabOrder = 0
      OnClick = cxButtonCloseClick
    end
    object cxButtonImport: TcxButton
      Left = 764
      Top = 8
      Width = 98
      Height = 33
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100
      TabOrder = 1
      OnClick = cxButtonImportClick
    end
  end
  object cxSpreadSheet1: TcxSpreadSheet
    Left = 0
    Top = 169
    Width = 1006
    Height = 446
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    R1C1ReferenceStyle = True
    Align = alClient
    DefaultStyle.Font.Name = 'Tahoma'
    HeaderFont.Charset = DEFAULT_CHARSET
    HeaderFont.Color = clWindowText
    HeaderFont.Height = -11
    HeaderFont.Name = 'Tahoma'
    HeaderFont.Style = []
    PainterType = ptOfficeXPStyle
    RowHeaderWidth = 40
  end
  object OpenDialog1: TOpenDialog
    Left = 368
    Top = 32
  end
  object ActionList: TActionList
    Left = 632
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
    end
    object ActionDeleteString: TAction
      Caption = 'ActionDeleteString'
    end
  end
  object DataSet: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE SPRICE'
      'SET '
      '    IDNOM_PRICE = :IDNOM_PRICE,'
      '    IDTYPE_PRICE = :IDTYPE_PRICE,'
      '    ZNACH_PRICE = :ZNACH_PRICE,'
      '    GID_SPRICE = :GID_SPRICE,'
      '    FL_CHANGE_PRICE = :FL_CHANGE_PRICE,'
      '    IDED_SPRICE = :IDED_SPRICE'
      'WHERE'
      '    ID_PRICE = :OLD_ID_PRICE'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SPRICE'
      'WHERE'
      '        ID_PRICE = :OLD_ID_PRICE'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SPRICE('
      '    ID_PRICE,'
      '    IDNOM_PRICE,'
      '    IDTYPE_PRICE,'
      '    ZNACH_PRICE,'
      '    GID_SPRICE,'
      '    FL_CHANGE_PRICE,'
      '    IDED_SPRICE'
      ')'
      'VALUES('
      '    :ID_PRICE,'
      '    :IDNOM_PRICE,'
      '    :IDTYPE_PRICE,'
      '    :ZNACH_PRICE,'
      '    :GID_SPRICE,'
      '    :FL_CHANGE_PRICE,'
      '    :IDED_SPRICE'
      ')')
    RefreshSQL.Strings = (
      'select *'
      'from sprice'
      'where(  ID_PRICE=:PARAM_ID'
      '     ) and (     SPRICE.ID_PRICE = :OLD_ID_PRICE'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select *'
      'from sprice'
      'where ID_PRICE=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SPRICE'
    AutoUpdateOptions.KeyFields = 'ID_PRICE'
    AutoUpdateOptions.GeneratorName = 'GEN_SPRICE_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = TrUpdate
    Database = DataModuleMain.Database
    Left = 512
    Top = 32
    object DataSetID_PRICE: TFIBBCDField
      FieldName = 'ID_PRICE'
      Size = 0
      RoundByScale = True
    end
    object DataSetIDNOM_PRICE: TFIBBCDField
      FieldName = 'IDNOM_PRICE'
      Size = 0
      RoundByScale = True
    end
    object DataSetIDTYPE_PRICE: TFIBBCDField
      FieldName = 'IDTYPE_PRICE'
      Size = 0
      RoundByScale = True
    end
    object DataSetZNACH_PRICE: TFIBBCDField
      FieldName = 'ZNACH_PRICE'
      Size = 2
      RoundByScale = True
    end
    object DataSetGID_SPRICE: TFIBWideStringField
      FieldName = 'GID_SPRICE'
      Size = 10
    end
    object DataSetFL_CHANGE_PRICE: TFIBSmallIntField
      FieldName = 'FL_CHANGE_PRICE'
    end
    object DataSetIDBASE_SPRICE: TFIBBCDField
      FieldName = 'IDBASE_SPRICE'
      Size = 0
      RoundByScale = True
    end
    object DataSetIDED_SPRICE: TFIBBCDField
      FieldName = 'IDED_SPRICE'
      Size = 0
      RoundByScale = True
    end
  end
  object TrUpdate: TpFIBTransaction
    Active = True
    DefaultDatabase = DataModuleMain.Database
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 544
    Top = 32
  end
  object TrRead: TpFIBTransaction
    DefaultDatabase = DataModuleMain.Database
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 728
    Top = 8
  end
  object QueryNom: TpFIBQuery
    Transaction = TrRead
    Database = DataModuleMain.Database
    SQL.Strings = (
      'select snom.idnom,'
      '       snom.idbasednom'
      'from snom'
      'where snom.namenom=:PARAM_NAME')
    Left = 696
    Top = 8
    qoStartTransaction = True
  end
  object QueryTypePrice: TpFIBQuery
    Transaction = TrRead
    Database = DataModuleMain.Database
    SQL.Strings = (
      'select ID_TPRICE'
      'from stprice'
      'where NAME_TPRICE=:PARAM_NAME')
    Left = 696
    Top = 40
    qoStartTransaction = True
  end
  object QueryEd: TpFIBQuery
    Transaction = TrRead
    Database = DataModuleMain.Database
    SQL.Strings = (
      'select IDED'
      'from sed'
      'where NAMEED=:PARAM_NAME and'
      '      IDNOMED=:PARAM_IDNOM')
    Left = 696
    Top = 80
    qoStartTransaction = True
  end
end
