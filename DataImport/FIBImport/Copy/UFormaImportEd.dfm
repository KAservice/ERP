object FormaImportEd: TFormaImportEd
  Left = 0
  Top = 0
  Caption = #1047#1072#1075#1088#1091#1079#1082#1072' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099
  ClientHeight = 513
  ClientWidth = 769
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 769
    Height = 185
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 8
      Top = 6
      Width = 152
      Height = 23
      Caption = #1048#1084#1087#1086#1088#1090' '#1077#1076#1080#1085#1080#1094
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label13: TLabel
      Left = 16
      Top = 38
      Width = 30
      Height = 13
      Caption = #1060#1072#1081#1083':'
    end
    object Label3: TLabel
      Left = 16
      Top = 64
      Width = 90
      Height = 26
      Caption = #1057#1090#1088#1086#1082#1072' '#1085#1072#1095#1072#1083#1072' '#1090#1072#1073#1083#1080#1095#1085#1086#1081' '#1095#1072#1089#1090#1080':'
      WordWrap = True
    end
    object Label4: TLabel
      Left = 356
      Top = 69
      Width = 154
      Height = 13
      Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099':'
      WordWrap = True
    end
    object Label5: TLabel
      Left = 169
      Top = 64
      Width = 90
      Height = 26
      Caption = #1057#1090#1088#1086#1082#1072' '#1082#1086#1085#1094#1072' '#1090#1072#1073#1083#1080#1095#1085#1086#1081' '#1095#1072#1089#1090#1080':'
      WordWrap = True
    end
    object FileNamecxButtonEdit: TcxButtonEdit
      Left = 52
      Top = 35
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.OnButtonClick = FileNamecxButtonEditPropertiesButtonClick
      TabOrder = 0
      Text = 'FileNamecxButtonEdit'
      Width = 312
    end
    object StartStringcxSpinEdit: TcxSpinEdit
      Left = 112
      Top = 66
      TabOrder = 1
      Width = 45
    end
    object NameNomcxSpinEdit: TcxSpinEdit
      Left = 575
      Top = 61
      TabOrder = 2
      Width = 45
    end
    object ConStringcxSpinEdit: TcxSpinEdit
      Left = 280
      Top = 66
      TabOrder = 3
      Width = 45
    end
    object cxGroupBox1: TcxGroupBox
      Left = 8
      Top = 108
      Caption = #1045#1076#1080#1085#1080#1094#1072':'
      TabOrder = 4
      Height = 70
      Width = 681
      object Label12: TLabel
        Left = 11
        Top = 14
        Width = 72
        Height = 13
        Caption = #1050#1086#1076' '#1077#1076#1080#1085#1080#1094#1099':'
      end
      object Label14: TLabel
        Left = 140
        Top = 16
        Width = 125
        Height = 13
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1077#1076#1080#1085#1080#1094#1099':'
      end
      object Label15: TLabel
        Left = 322
        Top = 14
        Width = 86
        Height = 13
        Caption = #1058#1080#1087' '#1096#1090#1088#1080#1093'-'#1082#1086#1076#1072':'
      end
      object Label16: TLabel
        Left = 500
        Top = 14
        Width = 61
        Height = 13
        Caption = #1064#1090#1088#1080#1093'-'#1082#1086#1076':'
      end
      object Label18: TLabel
        Left = 413
        Top = 46
        Width = 148
        Height = 13
        Caption = #1050#1086#1101#1092'. '#1087#1077#1088#1077#1089#1095#1077#1090#1072' '#1080#1079' '#1073#1072#1079#1086#1074#1086#1081':'
      end
      object Label17: TLabel
        Left = 120
        Top = 43
        Width = 146
        Height = 13
        Caption = #1050#1086#1101#1092'. '#1087#1077#1088#1077#1089#1095#1077#1090#1072' '#1074' '#1073#1072#1079#1086#1074#1091#1102':'
      end
      object CodeEdcxSpinEdit: TcxSpinEdit
        Left = 89
        Top = 14
        TabOrder = 0
        Width = 45
      end
      object NameEdcxSpinEdit: TcxSpinEdit
        Left = 271
        Top = 16
        TabOrder = 1
        Width = 45
      end
      object TypeShEdcxSpinEdit: TcxSpinEdit
        Left = 414
        Top = 14
        TabOrder = 2
        Width = 45
      end
      object ShEdcxSpinEdit: TcxSpinEdit
        Left = 567
        Top = 14
        TabOrder = 3
        Width = 45
      end
      object KF2EdcxSpinEdit: TcxSpinEdit
        Left = 567
        Top = 41
        TabOrder = 4
        Width = 45
      end
      object KF1EdcxSpinEdit: TcxSpinEdit
        Left = 272
        Top = 43
        TabOrder = 5
        Width = 45
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 470
    Width = 769
    Height = 43
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object LabelError: TLabel
      Left = 8
      Top = 6
      Width = 633
      Height = 27
      AutoSize = False
      Caption = 'LabelError'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      WordWrap = True
    end
    object cxButtonClose: TcxButton
      Left = 665
      Top = 6
      Width = 75
      Height = 25
      Caption = #1047#1072#1082#1088#1099#1090#1100
      TabOrder = 0
      OnClick = cxButtonCloseClick
    end
    object cxButtonImport: TcxButton
      Left = 584
      Top = 6
      Width = 75
      Height = 25
      Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100
      TabOrder = 1
      OnClick = cxButtonImportClick
    end
  end
  object cxSpreadSheet1: TcxSpreadSheet
    Left = 0
    Top = 185
    Width = 769
    Height = 285
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
    ExplicitTop = 377
    ExplicitHeight = 93
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
  object DataSetEd: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE SED'
      'SET '
      '    NAMEED = :NAMEED,'
      '    KFED = :KFED,'
      '    TSHED = :TSHED,'
      '    SHED = :SHED,'
      '    IDNOMED = :IDNOMED,'
      '    IDOKEIED = :IDOKEIED,'
      '    NEISPED = :NEISPED,'
      '    GID_SED = :GID_SED,'
      '    IDBASE_SED = :IDBASE_SED,'
      '    CODE_SED = :CODE_SED,'
      '    KF2_SED = :KF2_SED,'
      '    VES_SED = :VES_SED'
      'WHERE'
      '    IDED = :OLD_IDED'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SED'
      'WHERE'
      '        IDED = :OLD_IDED'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SED('
      '    IDED,'
      '    NAMEED,'
      '    KFED,'
      '    TSHED,'
      '    SHED,'
      '    IDNOMED,'
      '    IDOKEIED,'
      '    NEISPED,'
      '    GID_SED,'
      '    IDBASE_SED,'
      '    CODE_SED,'
      '    KF2_SED,'
      '    VES_SED'
      ')'
      'VALUES('
      '    :IDED,'
      '    :NAMEED,'
      '    :KFED,'
      '    :TSHED,'
      '    :SHED,'
      '    :IDNOMED,'
      '    :IDOKEIED,'
      '    :NEISPED,'
      '    :GID_SED,'
      '    :IDBASE_SED,'
      '    :CODE_SED,'
      '    :KF2_SED,'
      '    :VES_SED'
      ')')
    RefreshSQL.Strings = (
      'select *'
      'from sed'
      'where(  IDED=:PARAM_ID'
      '     ) and (     SED.IDED = :OLD_IDED'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select *'
      'from sed'
      'where IDED=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SED'
    AutoUpdateOptions.KeyFields = 'IDED'
    AutoUpdateOptions.GeneratorName = 'GEN_SED_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = TrUpdate
    Database = DataModuleMain.Database
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 512
    Top = 32
    object DataSetEdIDED: TFIBBCDField
      FieldName = 'IDED'
      Size = 0
      RoundByScale = True
    end
    object DataSetEdNAMEED: TFIBStringField
      FieldName = 'NAMEED'
      Size = 100
      EmptyStrToNull = True
    end
    object DataSetEdKFED: TFIBBCDField
      FieldName = 'KFED'
      Size = 3
      RoundByScale = True
    end
    object DataSetEdTSHED: TFIBIntegerField
      FieldName = 'TSHED'
    end
    object DataSetEdSHED: TFIBStringField
      FieldName = 'SHED'
      Size = 13
      EmptyStrToNull = True
    end
    object DataSetEdIDNOMED: TFIBBCDField
      FieldName = 'IDNOMED'
      Size = 0
      RoundByScale = True
    end
    object DataSetEdIDOKEIED: TFIBBCDField
      FieldName = 'IDOKEIED'
      Size = 0
      RoundByScale = True
    end
    object DataSetEdNEISPED: TFIBSmallIntField
      FieldName = 'NEISPED'
    end
    object DataSetEdGID_SED: TFIBStringField
      FieldName = 'GID_SED'
      Size = 10
      EmptyStrToNull = True
    end
    object DataSetEdIDBASE_SED: TFIBBCDField
      FieldName = 'IDBASE_SED'
      Size = 0
      RoundByScale = True
    end
    object DataSetEdCODE_SED: TFIBIntegerField
      FieldName = 'CODE_SED'
    end
    object DataSetEdKF2_SED: TFIBBCDField
      FieldName = 'KF2_SED'
      Size = 3
      RoundByScale = True
    end
    object DataSetEdVES_SED: TFIBBCDField
      FieldName = 'VES_SED'
      Size = 3
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
    CSMonitorSupport.Enabled = csmeDatabaseDriven
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
    CSMonitorSupport.Enabled = csmeDatabaseDriven
    TPBMode = tpbDefault
    Left = 728
    Top = 8
  end
  object QueryNom: TpFIBQuery
    Transaction = TrRead
    Database = DataModuleMain.Database
    SQL.Strings = (
      'select snom.idnom'
      'from snom'
      'where snom.namenom=:PARAM_NAME')
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 696
    Top = 8
    qoStartTransaction = True
  end
  object QueryCodeEd: TpFIBQuery
    Transaction = TrRead
    Database = DataModuleMain.Database
    SQL.Strings = (
      'select gen_id(gen_sed_code, 1) as code from rdb$database')
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 696
    Top = 48
    qoStartTransaction = True
  end
end
