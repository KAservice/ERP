object FormaImportEd: TFormaImportEd
  Left = 0
  Top = 0
  Caption = #1047#1072#1075#1088#1091#1079#1082#1072' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099
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
      Left = 752
      Top = 80
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
      Caption = #1045#1076#1080#1085#1080#1094#1072':'
      TabOrder = 4
      Height = 92
      Width = 891
      object Label12: TLabel
        Left = 14
        Top = 18
        Width = 90
        Height = 17
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1050#1086#1076' '#1077#1076#1080#1085#1080#1094#1099':'
      end
      object Label14: TLabel
        Left = 183
        Top = 21
        Width = 159
        Height = 17
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1077#1076#1080#1085#1080#1094#1099':'
      end
      object Label15: TLabel
        Left = 421
        Top = 18
        Width = 110
        Height = 17
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1058#1080#1087' '#1096#1090#1088#1080#1093'-'#1082#1086#1076#1072':'
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
      object Label18: TLabel
        Left = 540
        Top = 60
        Width = 187
        Height = 17
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1050#1086#1101#1092'. '#1087#1077#1088#1077#1089#1095#1077#1090#1072' '#1080#1079' '#1073#1072#1079#1086#1074#1086#1081':'
      end
      object Label17: TLabel
        Left = 157
        Top = 56
        Width = 183
        Height = 17
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1050#1086#1101#1092'. '#1087#1077#1088#1077#1089#1095#1077#1090#1072' '#1074' '#1073#1072#1079#1086#1074#1091#1102':'
      end
      object CodeEdcxSpinEdit: TcxSpinEdit
        Left = 116
        Top = 18
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        TabOrder = 0
        Width = 59
      end
      object NameEdcxSpinEdit: TcxSpinEdit
        Left = 354
        Top = 21
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        TabOrder = 1
        Width = 59
      end
      object TypeShEdcxSpinEdit: TcxSpinEdit
        Left = 541
        Top = 18
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        TabOrder = 2
        Width = 59
      end
      object ShEdcxSpinEdit: TcxSpinEdit
        Left = 741
        Top = 18
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        TabOrder = 3
        Width = 59
      end
      object KF2EdcxSpinEdit: TcxSpinEdit
        Left = 741
        Top = 54
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        TabOrder = 4
        Width = 59
      end
      object KF1EdcxSpinEdit: TcxSpinEdit
        Left = 356
        Top = 56
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        TabOrder = 5
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
    Left = 512
    Top = 32
    object DataSetEdIDED: TFIBBCDField
      FieldName = 'IDED'
      Size = 0
      RoundByScale = True
    end
    object DataSetEdNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
    end
    object DataSetEdKFED: TFIBBCDField
      FieldName = 'KFED'
      Size = 3
      RoundByScale = True
    end
    object DataSetEdTSHED: TFIBSmallIntField
      FieldName = 'TSHED'
    end
    object DataSetEdSHED: TFIBWideStringField
      FieldName = 'SHED'
      Size = 13
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
    object DataSetEdGID_SED: TFIBWideStringField
      FieldName = 'GID_SED'
      Size = 10
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
      'select snom.idnom'
      'from snom'
      'where snom.namenom=:PARAM_NAME')
    Left = 696
    Top = 8
    qoStartTransaction = True
  end
  object QueryCodeEd: TpFIBQuery
    Transaction = TrRead
    Database = DataModuleMain.Database
    SQL.Strings = (
      'select gen_id(gen_sed_code, 1) as code from rdb$database')
    Left = 696
    Top = 48
    qoStartTransaction = True
  end
end
