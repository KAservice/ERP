object FormaTableIsm: TFormaTableIsm
  Left = 0
  Top = 0
  Caption = #1058#1072#1073#1083#1080#1094#1072' '#1080#1079#1084#1077#1085#1077#1085#1080#1081
  ClientHeight = 633
  ClientWidth = 1204
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
  object Panel2: TPanel
    Left = 0
    Top = 586
    Width = 1204
    Height = 47
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 0
  end
  object DBGridFields: TDBGrid
    Left = 0
    Top = 429
    Width = 1204
    Height = 157
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    DataSource = DataSourceFields
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -14
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'FIELD_NAME_XTISM_FIELDS'
        Width = 156
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'OLD_VALUE_XTISM_FIELDS'
        Width = 200
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'NEW_VALUE_XTISM_FIELDS'
        Width = 200
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'ID_XTISM_FIELDS'
        Width = 212
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'IDXTISM_XTISM_FIELDS'
        Width = 118
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'IDBASE_XTISM_FIELDS'
        Width = 64
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'IDEXT_DOUT_XTISM_FIELDS'
        Width = 127
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'IDEXT_BASE_XTISM_FIELDS'
        Width = 64
        Visible = True
      end>
  end
  object DBGridTables: TDBGrid
    Left = 0
    Top = 127
    Width = 1204
    Height = 302
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    DataSource = DataSourceTables
    TabOrder = 2
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -14
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'ID_XTISM'
        Width = 64
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'POS_XTISM'
        Width = 64
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'OPERATION_XTISM'
        Width = 64
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'NAME_TABLE_XTISM'
        Width = 64
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'USER_XTISM'
        Width = 64
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'TYPE_OBJECT_XTISM'
        Width = 64
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'NAME_FIELD_ID_XTISM'
        Width = 150
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'VALUE_FIELD_ID_XTISM'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'IDBASE_XTISM'
        Width = 64
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'IDEXT_BASE_XTISM'
        Width = 64
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'IDEXT_DATAOUT_XTISM'
        Width = 183
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'IDEXT_DOUT_XTISM'
        Width = 185
        Visible = True
      end>
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 1204
    Height = 127
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 3
    object PosNach: TcxDateEdit
      Left = 10
      Top = 81
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      TabOrder = 0
      Width = 253
    end
    object PosCon: TcxDateEdit
      Left = 271
      Top = 81
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      TabOrder = 1
      Width = 221
    end
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 1204
      Height = 43
      ButtonHeight = 39
      ButtonWidth = 39
      Caption = 'ToolBar1'
      EdgeBorders = [ebLeft, ebTop, ebRight, ebBottom]
      Images = DataModuleMain.ImageList1
      TabOrder = 2
      object ToolButtonUpdate: TToolButton
        Left = 0
        Top = 0
        Hint = #1054#1073#1085#1086#1074#1080#1090#1100
        Caption = 'ToolButtonUpdate'
        ImageIndex = 1
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonUpdateClick
      end
    end
    object NameTable: TcxTextEdit
      Left = 711
      Top = 56
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      TabOrder = 3
      Text = 'NameTable'
      Width = 159
    end
    object OnlyTablecxCheckBox: TcxCheckBox
      Left = 522
      Top = 56
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1090#1086#1083#1100#1082#1086' '#1090#1072#1073#1083#1080#1094#1072
      TabOrder = 4
      Width = 158
    end
    object OnlyUsercxCheckBox: TcxCheckBox
      Left = 522
      Top = 92
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1090#1086#1083#1100#1082#1086' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1100
      TabOrder = 5
      Width = 182
    end
    object NameUser: TcxTextEdit
      Left = 711
      Top = 92
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      TabOrder = 6
      Text = 'NameUser'
      Width = 159
    end
    object OnlyRecordcxCheckBox: TcxCheckBox
      Left = 900
      Top = 64
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1090#1086#1083#1100#1082#1086' '#1079#1072#1087#1080#1089#1100
      TabOrder = 7
      Width = 127
    end
    object NumberRecord: TcxTextEdit
      Left = 1046
      Top = 64
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      TabOrder = 8
      Text = 'NumberRecord'
      Width = 158
    end
  end
  object Tables: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from xtism'
      'where POS_XTISM between :PARAM_NACH and :PARAM_CON')
    Transaction = pFIBTransaction1
    Database = DataModuleMain.pFIBDatabase
    Left = 536
    Top = 200
    object TablesID_XTISM: TFIBBCDField
      FieldName = 'ID_XTISM'
      Size = 0
      RoundByScale = True
    end
    object TablesPOS_XTISM: TFIBDateTimeField
      FieldName = 'POS_XTISM'
    end
    object TablesOPERATION_XTISM: TFIBIntegerField
      FieldName = 'OPERATION_XTISM'
    end
    object TablesTYPE_OBJECT_XTISM: TFIBIntegerField
      FieldName = 'TYPE_OBJECT_XTISM'
    end
    object TablesUSER_XTISM: TFIBWideStringField
      FieldName = 'USER_XTISM'
    end
    object TablesNAME_TABLE_XTISM: TFIBWideStringField
      FieldName = 'NAME_TABLE_XTISM'
    end
    object TablesNAME_FIELD_ID_XTISM: TFIBWideStringField
      FieldName = 'NAME_FIELD_ID_XTISM'
      Size = 40
    end
    object TablesVALUE_FIELD_ID_XTISM: TFIBBCDField
      FieldName = 'VALUE_FIELD_ID_XTISM'
      Size = 0
      RoundByScale = True
    end
    object TablesIDBASE_XTISM: TFIBBCDField
      FieldName = 'IDBASE_XTISM'
      Size = 0
      RoundByScale = True
    end
    object TablesIDEXT_BASE_XTISM: TFIBBCDField
      FieldName = 'IDEXT_BASE_XTISM'
      Size = 0
      RoundByScale = True
    end
    object TablesIDEXT_DATAOUT_XTISM: TFIBBCDField
      FieldName = 'IDEXT_DATAOUT_XTISM'
      Size = 0
      RoundByScale = True
    end
    object TablesIDEXT_DOUT_XTISM: TFIBBCDField
      FieldName = 'IDEXT_DOUT_XTISM'
      Size = 0
      RoundByScale = True
    end
  end
  object Fields: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from xtism_fields'
      'where IDXTISM_XTISM_FIELDS=:ID_XTISM')
    Transaction = pFIBTransaction1
    Database = DataModuleMain.pFIBDatabase
    DataSource = DataSourceTables
    Left = 600
    Top = 336
    object FieldsID_XTISM_FIELDS: TFIBBCDField
      FieldName = 'ID_XTISM_FIELDS'
      Size = 0
      RoundByScale = True
    end
    object FieldsIDXTISM_XTISM_FIELDS: TFIBBCDField
      FieldName = 'IDXTISM_XTISM_FIELDS'
      Size = 0
      RoundByScale = True
    end
    object FieldsFIELD_NAME_XTISM_FIELDS: TFIBWideStringField
      FieldName = 'FIELD_NAME_XTISM_FIELDS'
      Size = 40
    end
    object FieldsOLD_VALUE_XTISM_FIELDS: TFIBWideStringField
      FieldName = 'OLD_VALUE_XTISM_FIELDS'
      Size = 255
    end
    object FieldsNEW_VALUE_XTISM_FIELDS: TFIBWideStringField
      FieldName = 'NEW_VALUE_XTISM_FIELDS'
      Size = 255
    end
    object FieldsIDBASE_XTISM_FIELDS: TFIBBCDField
      FieldName = 'IDBASE_XTISM_FIELDS'
      Size = 0
      RoundByScale = True
    end
    object FieldsIDEXT_DOUT_XTISM_FIELDS: TFIBBCDField
      FieldName = 'IDEXT_DOUT_XTISM_FIELDS'
      Size = 0
      RoundByScale = True
    end
    object FieldsIDEXT_BASE_XTISM_FIELDS: TFIBBCDField
      FieldName = 'IDEXT_BASE_XTISM_FIELDS'
      Size = 0
      RoundByScale = True
    end
  end
  object pFIBTransaction1: TpFIBTransaction
    Active = True
    DefaultDatabase = DataModuleMain.pFIBDatabase
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 648
    Top = 200
  end
  object DataSourceTables: TDataSource
    DataSet = Tables
    Left = 456
    Top = 216
  end
  object DataSourceFields: TDataSource
    DataSet = Fields
    Left = 504
    Top = 336
  end
end
