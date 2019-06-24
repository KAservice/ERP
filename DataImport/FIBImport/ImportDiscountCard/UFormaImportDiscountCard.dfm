object FormaImportDiscountCard: TFormaImportDiscountCard
  Left = 0
  Top = 0
  Caption = #1047#1072#1075#1088#1091#1079#1082#1072' '#1076#1080#1089#1082#1086#1085#1090#1085#1099#1093' '#1082#1072#1088#1090
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
    Height = 242
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
      Width = 186
      Height = 28
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1048#1084#1087#1086#1088#1090' '#1077#1076#1080#1085#1080#1094
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
      Width = 97
      Height = 34
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1082#1083#1080#1077#1085#1090#1072':'
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
    object NameKlientcxSpinEdit: TcxSpinEdit
      Left = 647
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
    object cxGroupBox1: TcxGroupBox
      Left = 10
      Top = 141
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1050#1072#1088#1090#1072':'
      TabOrder = 4
      Height = 92
      Width = 891
      object Label12: TLabel
        Left = 14
        Top = 18
        Width = 33
        Height = 17
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1050#1086#1076' :'
      end
      object Label14: TLabel
        Left = 246
        Top = 21
        Width = 98
        Height = 17
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
      end
      object Label15: TLabel
        Left = 421
        Top = 18
        Width = 95
        Height = 17
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1058#1080#1087' (1,2,3,4..):'
      end
      object Label16: TLabel
        Left = 654
        Top = 18
        Width = 77
        Height = 17
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1064#1090#1088#1080#1093'-'#1082#1086#1076':'
      end
      object Label17: TLabel
        Left = 286
        Top = 56
        Width = 61
        Height = 17
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1055#1088#1086#1094#1077#1085#1090':'
      end
      object CodeCardcxSpinEdit: TcxSpinEdit
        Left = 116
        Top = 18
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        TabOrder = 0
        Width = 59
      end
      object NameCardcxSpinEdit: TcxSpinEdit
        Left = 354
        Top = 21
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        TabOrder = 1
        Width = 59
      end
      object TypeCardcxSpinEdit: TcxSpinEdit
        Left = 541
        Top = 18
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        TabOrder = 2
        Width = 59
      end
      object ShCardcxSpinEdit: TcxSpinEdit
        Left = 741
        Top = 18
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        TabOrder = 3
        Width = 59
      end
      object ProcentcxSpinEdit: TcxSpinEdit
        Left = 356
        Top = 56
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        TabOrder = 4
        Width = 59
      end
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
    Top = 242
    Width = 1006
    Height = 373
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
      'UPDATE SDISCOUNT_CARD'
      'SET '
      '    GID_SDISCOUNT_CARD = :GID_SDISCOUNT_CARD,'
      '    IDKLIENT_SDISCOUNT_CARD = :IDKLIENT_SDISCOUNT_CARD,'
      '    NAME_SDISCOUNT_CARD = :NAME_SDISCOUNT_CARD,'
      '    CODE_SDISCOUNT_CARD = :CODE_SDISCOUNT_CARD,'
      '    SHCODE_SDISCOUNT_CARD = :SHCODE_SDISCOUNT_CARD,'
      '    TYPE_SDISCOUNT_CARD = :TYPE_SDISCOUNT_CARD,'
      '    ACT_SDISCOUNT_CARD = :ACT_SDISCOUNT_CARD,'
      '    NACH_SDISCOUNT_CARD = :NACH_SDISCOUNT_CARD,'
      '    CON_SDISCOUNT_CARD = :CON_SDISCOUNT_CARD,'
      '    PRSK_SDISCOUNT_CARD = :PRSK_SDISCOUNT_CARD,'
      '    IDVID_SDISCOUNT_CARD = :IDVID_SDISCOUNT_CARD,'
      '    IDBASE_SDISCOUNT_CARD = :IDBASE_SDISCOUNT_CARD'
      'WHERE'
      '    ID_SDISCOUNT_CARD = :OLD_ID_SDISCOUNT_CARD'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SDISCOUNT_CARD'
      'WHERE'
      '        ID_SDISCOUNT_CARD = :OLD_ID_SDISCOUNT_CARD'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SDISCOUNT_CARD('
      '    ID_SDISCOUNT_CARD,'
      '    GID_SDISCOUNT_CARD,'
      '    IDKLIENT_SDISCOUNT_CARD,'
      '    NAME_SDISCOUNT_CARD,'
      '    CODE_SDISCOUNT_CARD,'
      '    SHCODE_SDISCOUNT_CARD,'
      '    TYPE_SDISCOUNT_CARD,'
      '    ACT_SDISCOUNT_CARD,'
      '    NACH_SDISCOUNT_CARD,'
      '    CON_SDISCOUNT_CARD,'
      '    PRSK_SDISCOUNT_CARD,'
      '    IDVID_SDISCOUNT_CARD,'
      '    IDBASE_SDISCOUNT_CARD'
      ')'
      'VALUES('
      '    :ID_SDISCOUNT_CARD,'
      '    :GID_SDISCOUNT_CARD,'
      '    :IDKLIENT_SDISCOUNT_CARD,'
      '    :NAME_SDISCOUNT_CARD,'
      '    :CODE_SDISCOUNT_CARD,'
      '    :SHCODE_SDISCOUNT_CARD,'
      '    :TYPE_SDISCOUNT_CARD,'
      '    :ACT_SDISCOUNT_CARD,'
      '    :NACH_SDISCOUNT_CARD,'
      '    :CON_SDISCOUNT_CARD,'
      '    :PRSK_SDISCOUNT_CARD,'
      '    :IDVID_SDISCOUNT_CARD,'
      '    :IDBASE_SDISCOUNT_CARD'
      ')')
    RefreshSQL.Strings = (
      'select *'
      'from sdiscount_card'
      'where(  ID_SDISCOUNT_CARD=:PARAM_ID'
      
        '     ) and (     SDISCOUNT_CARD.ID_SDISCOUNT_CARD = :OLD_ID_SDIS' +
        'COUNT_CARD'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select *'
      'from sdiscount_card'
      'where ID_SDISCOUNT_CARD=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SDISCOUNT_CARD'
    AutoUpdateOptions.KeyFields = 'ID_SDISCOUNT_CARD'
    AutoUpdateOptions.GeneratorName = 'GEN_SDISCOUNT_CARD_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = TrUpdate
    Database = DataModuleMain.Database
    Left = 512
    Top = 32
    object DataSetID_SDISCOUNT_CARD: TFIBBCDField
      FieldName = 'ID_SDISCOUNT_CARD'
      Size = 0
      RoundByScale = True
    end
    object DataSetGID_SDISCOUNT_CARD: TFIBWideStringField
      FieldName = 'GID_SDISCOUNT_CARD'
      Size = 10
    end
    object DataSetIDKLIENT_SDISCOUNT_CARD: TFIBBCDField
      FieldName = 'IDKLIENT_SDISCOUNT_CARD'
      Size = 0
      RoundByScale = True
    end
    object DataSetNAME_SDISCOUNT_CARD: TFIBWideStringField
      FieldName = 'NAME_SDISCOUNT_CARD'
      Size = 100
    end
    object DataSetCODE_SDISCOUNT_CARD: TFIBIntegerField
      FieldName = 'CODE_SDISCOUNT_CARD'
    end
    object DataSetSHCODE_SDISCOUNT_CARD: TFIBWideStringField
      FieldName = 'SHCODE_SDISCOUNT_CARD'
      Size = 13
    end
    object DataSetTYPE_SDISCOUNT_CARD: TFIBIntegerField
      FieldName = 'TYPE_SDISCOUNT_CARD'
    end
    object DataSetACT_SDISCOUNT_CARD: TFIBIntegerField
      FieldName = 'ACT_SDISCOUNT_CARD'
    end
    object DataSetNACH_SDISCOUNT_CARD: TFIBDateTimeField
      FieldName = 'NACH_SDISCOUNT_CARD'
    end
    object DataSetCON_SDISCOUNT_CARD: TFIBDateTimeField
      FieldName = 'CON_SDISCOUNT_CARD'
    end
    object DataSetPRSK_SDISCOUNT_CARD: TFIBBCDField
      FieldName = 'PRSK_SDISCOUNT_CARD'
      Size = 2
      RoundByScale = True
    end
    object DataSetIDVID_SDISCOUNT_CARD: TFIBBCDField
      FieldName = 'IDVID_SDISCOUNT_CARD'
      Size = 0
      RoundByScale = True
    end
    object DataSetIDBASE_SDISCOUNT_CARD: TFIBBCDField
      FieldName = 'IDBASE_SDISCOUNT_CARD'
      Size = 0
      RoundByScale = True
    end
    object DataSetFL_DISC_SDISCOUNT_CARD: TFIBSmallIntField
      FieldName = 'FL_DISC_SDISCOUNT_CARD'
    end
    object DataSetFL_PLAT_SDISCOUNT_CARD: TFIBSmallIntField
      FieldName = 'FL_PLAT_SDISCOUNT_CARD'
    end
    object DataSetFL_CREDIT_SDISCOUNT_CARD: TFIBSmallIntField
      FieldName = 'FL_CREDIT_SDISCOUNT_CARD'
    end
    object DataSetIDDOG_SDISCOUNT_CARD: TFIBBCDField
      FieldName = 'IDDOG_SDISCOUNT_CARD'
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
  object QueryKlient: TpFIBQuery
    Transaction = TrRead
    Database = DataModuleMain.Database
    SQL.Strings = (
      'select sklient.idklient'
      'from sklient'
      'where sklient.nameklient=:PARAM_NAME')
    Left = 696
    Top = 8
    qoStartTransaction = True
  end
  object QueryCodeCard: TpFIBQuery
    Transaction = TrRead
    Database = DataModuleMain.Database
    SQL.Strings = (
      
        'select gen_id(GEN_SDISCOUNT_CARD_CODE, 1) as code from rdb$datab' +
        'ase')
    Left = 696
    Top = 48
    qoStartTransaction = True
  end
end
