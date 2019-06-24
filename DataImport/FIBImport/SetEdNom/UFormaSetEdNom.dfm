object FormaSetEdNom: TFormaSetEdNom
  Left = 0
  Top = 0
  Caption = #1059#1089#1090#1072#1085#1086#1074#1082#1072' '#1077#1076#1080#1085#1080#1094' '#1080#1079#1084#1077#1088#1077#1085#1080#1103
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
    Height = 200
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
      Width = 403
      Height = 28
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1059#1089#1090#1072#1085#1086#1074#1082#1072' '#1077#1076#1080#1085#1080#1094' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099
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
      Left = 21
      Top = 150
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
    object Label9: TLabel
      Left = 315
      Top = 150
      Width = 113
      Height = 17
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1041#1072#1079#1086#1074#1072#1103' '#1077#1076#1080#1085#1080#1094#1072':'
    end
    object Label10: TLabel
      Left = 547
      Top = 150
      Width = 125
      Height = 17
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1054#1089#1085#1086#1074#1085#1072#1103' '#1077#1076#1080#1085#1080#1094#1072':'
    end
    object Label11: TLabel
      Left = 753
      Top = 150
      Width = 138
      Height = 17
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1060#1080#1079#1080#1095#1077#1089#1082#1072#1103' '#1077#1076#1080#1085#1080#1094#1072':'
    end
    object Label2: TLabel
      Left = 315
      Top = 179
      Width = 335
      Height = 17
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1041#1072#1079#1086#1074#1072#1103' '#1077#1076#1080#1085#1080#1094#1072' '#1076#1086#1083#1078#1085#1072' '#1073#1099#1090#1100' '#1079#1072#1076#1072#1085#1072' '#1086#1073#1103#1079#1072#1090#1077#1083#1100#1085#1086'!'
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
      Left = 230
      Top = 146
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
    object BasEdcxSpinEdit: TcxSpinEdit
      Left = 442
      Top = 144
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      TabOrder = 4
      Width = 59
    end
    object OsnEdcxSpinEdit: TcxSpinEdit
      Left = 684
      Top = 144
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      TabOrder = 5
      Width = 59
    end
    object FisEdcxSpinEdit: TcxSpinEdit
      Left = 905
      Top = 144
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
    Top = 200
    Width = 1006
    Height = 415
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
  object DataSetNom: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE SNOM'
      'SET '
      '    IDBASEDNOM = :IDBASEDNOM,'
      '    IDOSNEDNOM = :IDOSNEDNOM,'
      '    IDFISED_SNOM = :IDFISED_SNOM'
      'WHERE'
      '    IDNOM = :OLD_IDNOM'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SNOM'
      'WHERE'
      '        IDNOM = :OLD_IDNOM'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SNOM('
      '    IDBASEDNOM,'
      '    IDOSNEDNOM,'
      '    IDFISED_SNOM'
      ')'
      'VALUES('
      '    :IDBASEDNOM,'
      '    :IDOSNEDNOM,'
      '    :IDFISED_SNOM'
      ')')
    RefreshSQL.Strings = (
      'select *'
      'from snom'
      'where(  IDNOM=:PARAM_ID'
      '     ) and (     SNOM.IDNOM = :OLD_IDNOM'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select *'
      'from snom'
      'where IDNOM=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SNOM'
    AutoUpdateOptions.KeyFields = 'IDNOM'
    AutoUpdateOptions.GeneratorName = 'GEN_SNOM_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = TrUpdate
    Database = DataModuleMain.Database
    Left = 512
    Top = 32
    object DataSetNomIDNOM: TFIBBCDField
      FieldName = 'IDNOM'
      Size = 0
      RoundByScale = True
    end
    object DataSetNomIDBASEDNOM: TFIBBCDField
      FieldName = 'IDBASEDNOM'
      Size = 0
      RoundByScale = True
    end
    object DataSetNomIDOSNEDNOM: TFIBBCDField
      FieldName = 'IDOSNEDNOM'
      Size = 0
      RoundByScale = True
    end
    object DataSetNomIDFISED_SNOM: TFIBBCDField
      FieldName = 'IDFISED_SNOM'
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
      'select snom.idnom'
      'from snom'
      'where snom.namenom=:PARAM_NAME')
    Left = 696
    Top = 8
    qoStartTransaction = True
  end
  object QueryEd: TpFIBQuery
    Transaction = TrRead
    Database = DataModuleMain.Database
    SQL.Strings = (
      'select sed.ided'
      'from sed'
      'where sed.nameed=:PARAM_NAME'
      '    and sed.idnomed=:PARAM_IDNOM')
    Left = 696
    Top = 48
    qoStartTransaction = True
  end
end
