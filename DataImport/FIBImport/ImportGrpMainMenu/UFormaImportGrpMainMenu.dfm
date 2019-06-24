object FormaImportGrpMainMenu: TFormaImportGrpMainMenu
  Left = 0
  Top = 0
  Caption = #1047#1072#1075#1088#1091#1079#1082#1072' '#1075#1088#1091#1087#1087' '#1075#1083#1072#1074#1085#1086#1075#1086' '#1084#1077#1085#1102
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
    Height = 190
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
      Width = 354
      Height = 28
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1048#1084#1087#1086#1088#1090' '#1075#1088#1091#1087#1087' '#1075#1083#1072#1074#1085#1086#1075#1086' '#1084#1077#1085#1102
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
    object Label2: TLabel
      Left = 21
      Top = 126
      Width = 246
      Height = 17
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1088#1086#1076#1080#1090#1077#1083#1100#1089#1082#1086#1081' '#1075#1088#1091#1087#1087#1099':'
    end
    object Label4: TLabel
      Left = 115
      Top = 153
      Width = 97
      Height = 34
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1075#1088#1091#1087#1087#1099':'
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
    object NameOwnerGrpcxSpinEdit: TcxSpinEdit
      Left = 280
      Top = 115
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      TabOrder = 2
      Width = 59
    end
    object NameGrpcxSpinEdit: TcxSpinEdit
      Left = 280
      Top = 150
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      TabOrder = 3
      Width = 59
    end
    object ConStringcxSpinEdit: TcxSpinEdit
      Left = 366
      Top = 86
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      TabOrder = 4
      Width = 59
    end
    object NameGrpcxLookupComboBox: TcxLookupComboBox
      Left = 680
      Top = 153
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Properties.KeyFieldNames = 'ID_SGRPUSER'
      Properties.ListColumns = <
        item
          FieldName = 'NAME_SGRPUSER'
        end>
      Properties.ListSource = DataSourceSpisokGrpUser
      EditValue = 0
      TabOrder = 5
      Width = 305
    end
    object cxLabel1: TcxLabel
      Left = 680
      Top = 123
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1043#1088#1091#1087#1087#1072' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1077#1081':'
    end
    object ApplicationcxImageComboBox: TcxImageComboBox
      Left = 680
      Top = 90
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      EditValue = 0
      Properties.Items = <
        item
          Description = #1054#1089#1085#1086#1074#1085#1086#1081' '#1084#1086#1076#1091#1083#1100
          ImageIndex = 0
          Value = 1
        end
        item
          Description = #1056#1077#1084#1086#1085#1090
          Value = 2
        end
        item
          Description = #1043#1086#1089#1090#1080#1085#1080#1094#1072
          Value = 3
        end>
      TabOrder = 7
      Width = 305
    end
    object cxLabel2: TcxLabel
      Left = 680
      Top = 60
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1088#1080#1083#1086#1078#1077#1085#1080#1077':'
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
    Top = 190
    Width = 1006
    Height = 425
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
  object DataSetGrp: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE INTERF_MAINMENU_GRP'
      'SET '
      '    IDBASE_INTERF_MAINMENU_GRP = :IDBASE_INTERF_MAINMENU_GRP,'
      
        '    APPLICATION_INTERF_MAINMENU_GRP = :APPLICATION_INTERF_MAINME' +
        'NU_GRP,'
      
        '    IDGRPUSER_INTERF_MAINMENU_GRP = :IDGRPUSER_INTERF_MAINMENU_G' +
        'RP,'
      '    NAME_INTERF_MAINMENU_GRP = :NAME_INTERF_MAINMENU_GRP,'
      '    IDGRP_INTERF_MAINMENU_GRP = :IDGRP_INTERF_MAINMENU_GRP'
      'WHERE'
      '    ID_INTERF_MAINMENU_GRP = :OLD_ID_INTERF_MAINMENU_GRP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    INTERF_MAINMENU_GRP'
      'WHERE'
      '        ID_INTERF_MAINMENU_GRP = :OLD_ID_INTERF_MAINMENU_GRP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO INTERF_MAINMENU_GRP('
      '    ID_INTERF_MAINMENU_GRP,'
      '    IDBASE_INTERF_MAINMENU_GRP,'
      '    APPLICATION_INTERF_MAINMENU_GRP,'
      '    IDGRPUSER_INTERF_MAINMENU_GRP,'
      '    NAME_INTERF_MAINMENU_GRP,'
      '    IDGRP_INTERF_MAINMENU_GRP'
      ')'
      'VALUES('
      '    :ID_INTERF_MAINMENU_GRP,'
      '    :IDBASE_INTERF_MAINMENU_GRP,'
      '    :APPLICATION_INTERF_MAINMENU_GRP,'
      '    :IDGRPUSER_INTERF_MAINMENU_GRP,'
      '    :NAME_INTERF_MAINMENU_GRP,'
      '    :IDGRP_INTERF_MAINMENU_GRP'
      ')')
    RefreshSQL.Strings = (
      'select *'
      'from INTERF_MAINMENU_GRP'
      'where(  ID_INTERF_MAINMENU_GRP=:PARAM_ID'
      
        '     ) and (     INTERF_MAINMENU_GRP.ID_INTERF_MAINMENU_GRP = :O' +
        'LD_ID_INTERF_MAINMENU_GRP'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select *'
      'from INTERF_MAINMENU_GRP'
      'where ID_INTERF_MAINMENU_GRP=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'INTERF_MAINMENU_GRP'
    AutoUpdateOptions.KeyFields = 'ID_INTERF_MAINMENU_GRP'
    AutoUpdateOptions.GeneratorName = 'GEN_INTERF_MAINMENU_GRP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = TrUpdate
    Database = DataModuleMain.Database
    Left = 424
    Top = 32
    object DataSetGrpID_INTERF_MAINMENU_GRP: TFIBBCDField
      FieldName = 'ID_INTERF_MAINMENU_GRP'
      Size = 0
      RoundByScale = True
    end
    object DataSetGrpAPPLICATION_INTERF_MAINMENU_GRP: TFIBIntegerField
      FieldName = 'APPLICATION_INTERF_MAINMENU_GRP'
    end
    object DataSetGrpIDGRPUSER_INTERF_MAINMENU_GRP: TFIBBCDField
      FieldName = 'IDGRPUSER_INTERF_MAINMENU_GRP'
      Size = 0
      RoundByScale = True
    end
    object DataSetGrpNAME_INTERF_MAINMENU_GRP: TFIBWideStringField
      FieldName = 'NAME_INTERF_MAINMENU_GRP'
      Size = 40
    end
    object DataSetGrpIDGRP_INTERF_MAINMENU_GRP: TFIBBCDField
      FieldName = 'IDGRP_INTERF_MAINMENU_GRP'
      Size = 0
      RoundByScale = True
    end
    object DataSetGrpINDEX_INTERF_MAINMENU_GRP: TFIBIntegerField
      FieldName = 'INDEX_INTERF_MAINMENU_GRP'
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
    Left = 456
    Top = 32
  end
  object QueryOwnerGrp: TpFIBQuery
    Transaction = DataModuleMain.TrRead
    Database = DataModuleMain.Database
    SQL.Strings = (
      'select ID_INTERF_MAINMENU_GRP'
      'from INTERF_MAINMENU_GRP'
      'where NAME_INTERF_MAINMENU_GRP=:PARAM_NAME')
    Left = 560
    Top = 48
    qoStartTransaction = True
  end
  object TrRead: TpFIBTransaction
    Active = True
    DefaultDatabase = DataModuleMain.Database
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 592
    Top = 48
  end
  object SpisokGrpUser: TpFIBDataSet
    SelectSQL.Strings = (
      'select * '
      'from sgrpuser')
    Transaction = TrRead
    Database = DataModuleMain.Database
    Left = 720
    Top = 104
    object SpisokGrpUserID_SGRPUSER: TFIBBCDField
      FieldName = 'ID_SGRPUSER'
      Size = 0
      RoundByScale = True
    end
    object SpisokGrpUserNAME_SGRPUSER: TFIBWideStringField
      FieldName = 'NAME_SGRPUSER'
      Size = 100
    end
  end
  object DataSourceSpisokGrpUser: TDataSource
    DataSet = SpisokGrpUser
    Left = 688
    Top = 104
  end
end
