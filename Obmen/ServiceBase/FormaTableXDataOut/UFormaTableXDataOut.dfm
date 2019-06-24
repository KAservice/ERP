object FormaTableXDataOut: TFormaTableXDataOut
  Left = 0
  Top = 0
  Caption = #1058#1072#1073#1083#1080#1094#1072' '#1087#1086#1076#1075#1086#1090#1086#1074#1083#1077#1085#1085#1099#1093' '#1076#1072#1085#1085#1099#1093' '#1076#1083#1103' '#1086#1073#1084#1077#1085#1072
  ClientHeight = 688
  ClientWidth = 935
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
    Width = 935
    Height = 95
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 534
      Top = 64
      Width = 150
      Height = 17
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1048#1085#1092#1086#1088#1084#1072#1094#1080#1086#1085#1085#1072#1103' '#1073#1072#1079#1072':'
    end
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 935
      Height = 43
      ButtonHeight = 38
      ButtonWidth = 39
      Caption = 'ToolBar1'
      EdgeBorders = [ebLeft, ebTop, ebRight, ebBottom]
      Images = DataModuleMain.ImageList1
      TabOrder = 0
      object ToolButtonUpdateForm: TToolButton
        Left = 0
        Top = 0
        Hint = #1054#1073#1085#1086#1074#1080#1090#1100
        Caption = 'ToolButtonUpdateForm'
        ImageIndex = 1
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonUpdateFormClick
      end
    end
    object NachcxDateEdit: TcxDateEdit
      Left = 21
      Top = 60
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Properties.Kind = ckDateTime
      TabOrder = 1
      Width = 254
    end
    object ConcxDateEdit: TcxDateEdit
      Left = 282
      Top = 60
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Properties.Kind = ckDateTime
      TabOrder = 2
      Width = 244
    end
    object NameBasecxLookupComboBox: TcxLookupComboBox
      Left = 694
      Top = 60
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Properties.KeyFieldNames = 'ID_SINFBASE_OBMEN'
      Properties.ListColumns = <
        item
          FieldName = 'NAME_SINFBASE_OBMEN'
        end>
      Properties.ListSource = DataSourceBaseList
      TabOrder = 3
      Width = 228
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 607
    Width = 935
    Height = 81
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
  end
  object cxGrid1: TcxGrid
    Left = 0
    Top = 95
    Width = 935
    Height = 512
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    TabOrder = 2
    object cxGrid1DBTableView1: TcxGridDBTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.DataSource = DataSourceTable
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsData.Deleting = False
      OptionsData.Editing = False
      OptionsData.Inserting = False
      object cxGrid1DBTableView1ID_XTISM: TcxGridDBColumn
        DataBinding.FieldName = 'ID_XTISM'
      end
      object cxGrid1DBTableView1POS_XTISM: TcxGridDBColumn
        DataBinding.FieldName = 'POS_XTISM'
      end
      object cxGrid1DBTableView1OPERATION_XTISM: TcxGridDBColumn
        DataBinding.FieldName = 'OPERATION_XTISM'
      end
      object cxGrid1DBTableView1TYPE_OBJECT_XTISM: TcxGridDBColumn
        DataBinding.FieldName = 'TYPE_OBJECT_XTISM'
      end
      object cxGrid1DBTableView1USER_XTISM: TcxGridDBColumn
        DataBinding.FieldName = 'USER_XTISM'
      end
      object cxGrid1DBTableView1NAME_TABLE_XTISM: TcxGridDBColumn
        DataBinding.FieldName = 'NAME_TABLE_XTISM'
      end
      object cxGrid1DBTableView1NAME_FIELD_ID_XTISM: TcxGridDBColumn
        DataBinding.FieldName = 'NAME_FIELD_ID_XTISM'
      end
      object cxGrid1DBTableView1VALUE_FIELD_ID_XTISM: TcxGridDBColumn
        DataBinding.FieldName = 'VALUE_FIELD_ID_XTISM'
      end
      object cxGrid1DBTableView1IDBASE_XTISM: TcxGridDBColumn
        DataBinding.FieldName = 'IDBASE_XTISM'
      end
      object cxGrid1DBTableView1IDEXT_BASE_XTISM: TcxGridDBColumn
        DataBinding.FieldName = 'IDEXT_BASE_XTISM'
      end
      object cxGrid1DBTableView1IDEXT_DATAOUT_XTISM: TcxGridDBColumn
        DataBinding.FieldName = 'IDEXT_DATAOUT_XTISM'
      end
      object cxGrid1DBTableView1IDEXT_DOUT_XTISM: TcxGridDBColumn
        DataBinding.FieldName = 'IDEXT_DOUT_XTISM'
      end
      object cxGrid1DBTableView1ID_XDATA_OUT: TcxGridDBColumn
        DataBinding.FieldName = 'ID_XDATA_OUT'
      end
      object cxGrid1DBTableView1GID_XDATA_OUT: TcxGridDBColumn
        DataBinding.FieldName = 'GID_XDATA_OUT'
      end
      object cxGrid1DBTableView1IDTISM_XDATA_OUT: TcxGridDBColumn
        DataBinding.FieldName = 'IDTISM_XDATA_OUT'
      end
      object cxGrid1DBTableView1IDBASE_XDATA_OUT: TcxGridDBColumn
        DataBinding.FieldName = 'IDBASE_XDATA_OUT'
      end
      object cxGrid1DBTableView1TYPE_XDATA_OUT: TcxGridDBColumn
        DataBinding.FieldName = 'TYPE_XDATA_OUT'
      end
      object cxGrid1DBTableView1RESULT_XDATA_OUT: TcxGridDBColumn
        DataBinding.FieldName = 'RESULT_XDATA_OUT'
      end
      object cxGrid1DBTableView1IDEXT_DOUT_XDATA_OUT: TcxGridDBColumn
        DataBinding.FieldName = 'IDEXT_DOUT_XDATA_OUT'
      end
      object cxGrid1DBTableView1IDEXT_BASE_XDATA_OUT: TcxGridDBColumn
        DataBinding.FieldName = 'IDEXT_BASE_XDATA_OUT'
      end
    end
    object cxGrid1DBBandedTableView1: TcxGridDBBandedTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.DataSource = DataSourceTable
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      Bands = <
        item
        end>
      object cxGrid1DBBandedTableView1ID_XTISM: TcxGridDBBandedColumn
        DataBinding.FieldName = 'ID_XTISM'
        Position.BandIndex = 0
        Position.ColIndex = 0
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1POS_XTISM: TcxGridDBBandedColumn
        DataBinding.FieldName = 'POS_XTISM'
        Position.BandIndex = 0
        Position.ColIndex = 1
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1OPERATION_XTISM: TcxGridDBBandedColumn
        DataBinding.FieldName = 'OPERATION_XTISM'
        Position.BandIndex = 0
        Position.ColIndex = 2
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1TYPE_OBJECT_XTISM: TcxGridDBBandedColumn
        DataBinding.FieldName = 'TYPE_OBJECT_XTISM'
        Position.BandIndex = 0
        Position.ColIndex = 3
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1USER_XTISM: TcxGridDBBandedColumn
        DataBinding.FieldName = 'USER_XTISM'
        Position.BandIndex = 0
        Position.ColIndex = 4
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1NAME_TABLE_XTISM: TcxGridDBBandedColumn
        DataBinding.FieldName = 'NAME_TABLE_XTISM'
        Position.BandIndex = 0
        Position.ColIndex = 5
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1NAME_FIELD_ID_XTISM: TcxGridDBBandedColumn
        DataBinding.FieldName = 'NAME_FIELD_ID_XTISM'
        Position.BandIndex = 0
        Position.ColIndex = 6
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1VALUE_FIELD_ID_XTISM: TcxGridDBBandedColumn
        DataBinding.FieldName = 'VALUE_FIELD_ID_XTISM'
        Position.BandIndex = 0
        Position.ColIndex = 7
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1IDBASE_XTISM: TcxGridDBBandedColumn
        DataBinding.FieldName = 'IDBASE_XTISM'
        Position.BandIndex = 0
        Position.ColIndex = 8
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1IDEXT_BASE_XTISM: TcxGridDBBandedColumn
        DataBinding.FieldName = 'IDEXT_BASE_XTISM'
        Position.BandIndex = 0
        Position.ColIndex = 9
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1IDEXT_DATAOUT_XTISM: TcxGridDBBandedColumn
        DataBinding.FieldName = 'IDEXT_DATAOUT_XTISM'
        Position.BandIndex = 0
        Position.ColIndex = 10
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1IDEXT_DOUT_XTISM: TcxGridDBBandedColumn
        DataBinding.FieldName = 'IDEXT_DOUT_XTISM'
        Position.BandIndex = 0
        Position.ColIndex = 11
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1ID_XDATA_OUT: TcxGridDBBandedColumn
        DataBinding.FieldName = 'ID_XDATA_OUT'
        Position.BandIndex = 0
        Position.ColIndex = 12
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1GID_XDATA_OUT: TcxGridDBBandedColumn
        DataBinding.FieldName = 'GID_XDATA_OUT'
        Position.BandIndex = 0
        Position.ColIndex = 13
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1IDTISM_XDATA_OUT: TcxGridDBBandedColumn
        DataBinding.FieldName = 'IDTISM_XDATA_OUT'
        Position.BandIndex = 0
        Position.ColIndex = 14
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1IDBASE_XDATA_OUT: TcxGridDBBandedColumn
        DataBinding.FieldName = 'IDBASE_XDATA_OUT'
        Position.BandIndex = 0
        Position.ColIndex = 15
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1TYPE_XDATA_OUT: TcxGridDBBandedColumn
        DataBinding.FieldName = 'TYPE_XDATA_OUT'
        Position.BandIndex = 0
        Position.ColIndex = 16
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1RESULT_XDATA_OUT: TcxGridDBBandedColumn
        DataBinding.FieldName = 'RESULT_XDATA_OUT'
        Position.BandIndex = 0
        Position.ColIndex = 17
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1IDEXT_DOUT_XDATA_OUT: TcxGridDBBandedColumn
        DataBinding.FieldName = 'IDEXT_DOUT_XDATA_OUT'
        Position.BandIndex = 0
        Position.ColIndex = 18
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1IDEXT_BASE_XDATA_OUT: TcxGridDBBandedColumn
        DataBinding.FieldName = 'IDEXT_BASE_XDATA_OUT'
        Position.BandIndex = 0
        Position.ColIndex = 19
        Position.RowIndex = 0
      end
    end
    object cxGrid1DBTableView2: TcxGridDBTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.DataSource = DataSourceTable
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      object cxGrid1DBTableView2ID_XTISM: TcxGridDBColumn
        DataBinding.FieldName = 'ID_XTISM'
        PropertiesClassName = 'TcxTextEditProperties'
      end
      object cxGrid1DBTableView2POS_XTISM: TcxGridDBColumn
        DataBinding.FieldName = 'POS_XTISM'
      end
      object cxGrid1DBTableView2OPERATION_XTISM: TcxGridDBColumn
        DataBinding.FieldName = 'OPERATION_XTISM'
      end
      object cxGrid1DBTableView2TYPE_OBJECT_XTISM: TcxGridDBColumn
        DataBinding.FieldName = 'TYPE_OBJECT_XTISM'
      end
      object cxGrid1DBTableView2USER_XTISM: TcxGridDBColumn
        DataBinding.FieldName = 'USER_XTISM'
      end
      object cxGrid1DBTableView2NAME_TABLE_XTISM: TcxGridDBColumn
        DataBinding.FieldName = 'NAME_TABLE_XTISM'
      end
      object cxGrid1DBTableView2NAME_FIELD_ID_XTISM: TcxGridDBColumn
        DataBinding.FieldName = 'NAME_FIELD_ID_XTISM'
      end
      object cxGrid1DBTableView2VALUE_FIELD_ID_XTISM: TcxGridDBColumn
        DataBinding.FieldName = 'VALUE_FIELD_ID_XTISM'
      end
      object cxGrid1DBTableView2IDBASE_XTISM: TcxGridDBColumn
        DataBinding.FieldName = 'IDBASE_XTISM'
        PropertiesClassName = 'TcxTextEditProperties'
      end
      object cxGrid1DBTableView2IDEXT_BASE_XTISM: TcxGridDBColumn
        DataBinding.FieldName = 'IDEXT_BASE_XTISM'
        PropertiesClassName = 'TcxTextEditProperties'
      end
      object cxGrid1DBTableView2IDEXT_DATAOUT_XTISM: TcxGridDBColumn
        DataBinding.FieldName = 'IDEXT_DATAOUT_XTISM'
        PropertiesClassName = 'TcxTextEditProperties'
      end
      object cxGrid1DBTableView2IDEXT_DOUT_XTISM: TcxGridDBColumn
        DataBinding.FieldName = 'IDEXT_DOUT_XTISM'
        PropertiesClassName = 'TcxTextEditProperties'
      end
      object cxGrid1DBTableView2ID_XDATA_OUT: TcxGridDBColumn
        DataBinding.FieldName = 'ID_XDATA_OUT'
        PropertiesClassName = 'TcxTextEditProperties'
      end
      object cxGrid1DBTableView2GID_XDATA_OUT: TcxGridDBColumn
        DataBinding.FieldName = 'GID_XDATA_OUT'
        PropertiesClassName = 'TcxTextEditProperties'
      end
      object cxGrid1DBTableView2IDTISM_XDATA_OUT: TcxGridDBColumn
        DataBinding.FieldName = 'IDTISM_XDATA_OUT'
        PropertiesClassName = 'TcxTextEditProperties'
      end
      object cxGrid1DBTableView2IDBASE_XDATA_OUT: TcxGridDBColumn
        DataBinding.FieldName = 'IDBASE_XDATA_OUT'
        PropertiesClassName = 'TcxTextEditProperties'
      end
      object cxGrid1DBTableView2TYPE_XDATA_OUT: TcxGridDBColumn
        DataBinding.FieldName = 'TYPE_XDATA_OUT'
        PropertiesClassName = 'TcxTextEditProperties'
      end
      object cxGrid1DBTableView2RESULT_XDATA_OUT: TcxGridDBColumn
        DataBinding.FieldName = 'RESULT_XDATA_OUT'
        PropertiesClassName = 'TcxTextEditProperties'
      end
      object cxGrid1DBTableView2IDEXT_DOUT_XDATA_OUT: TcxGridDBColumn
        DataBinding.FieldName = 'IDEXT_DOUT_XDATA_OUT'
        PropertiesClassName = 'TcxTextEditProperties'
      end
      object cxGrid1DBTableView2IDEXT_BASE_XDATA_OUT: TcxGridDBColumn
        DataBinding.FieldName = 'IDEXT_BASE_XDATA_OUT'
        PropertiesClassName = 'TcxTextEditProperties'
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView2
    end
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      '        select *'
      '        from xtism'
      
        '        left outer join xdata_out on xtism.id_xtism=xdata_out.id' +
        'tism_xdata_out'
      '        where xdata_out.result_xdata_out!=1'
      '        and xdata_out.idbase_xdata_out=:PARAM_IDBASE'
      '        and xtism.pos_xtism between :PARAM_NACH and :PARAM_CON')
    Transaction = pFIBTransaction1
    Database = DataModuleMain.pFIBDatabase
    Left = 480
    Top = 168
    object TableID_XTISM: TFIBBCDField
      FieldName = 'ID_XTISM'
      Size = 0
      RoundByScale = True
    end
    object TablePOS_XTISM: TFIBDateTimeField
      FieldName = 'POS_XTISM'
    end
    object TableOPERATION_XTISM: TFIBIntegerField
      FieldName = 'OPERATION_XTISM'
    end
    object TableTYPE_OBJECT_XTISM: TFIBIntegerField
      FieldName = 'TYPE_OBJECT_XTISM'
    end
    object TableUSER_XTISM: TFIBWideStringField
      FieldName = 'USER_XTISM'
    end
    object TableNAME_TABLE_XTISM: TFIBWideStringField
      FieldName = 'NAME_TABLE_XTISM'
    end
    object TableNAME_FIELD_ID_XTISM: TFIBWideStringField
      FieldName = 'NAME_FIELD_ID_XTISM'
      Size = 40
    end
    object TableVALUE_FIELD_ID_XTISM: TFIBBCDField
      FieldName = 'VALUE_FIELD_ID_XTISM'
      Size = 0
      RoundByScale = True
    end
    object TableIDBASE_XTISM: TFIBBCDField
      FieldName = 'IDBASE_XTISM'
      Size = 0
      RoundByScale = True
    end
    object TableIDEXT_BASE_XTISM: TFIBBCDField
      FieldName = 'IDEXT_BASE_XTISM'
      Size = 0
      RoundByScale = True
    end
    object TableIDEXT_DATAOUT_XTISM: TFIBBCDField
      FieldName = 'IDEXT_DATAOUT_XTISM'
      Size = 0
      RoundByScale = True
    end
    object TableIDEXT_DOUT_XTISM: TFIBBCDField
      FieldName = 'IDEXT_DOUT_XTISM'
      Size = 0
      RoundByScale = True
    end
    object TableID_XDATA_OUT: TFIBBCDField
      FieldName = 'ID_XDATA_OUT'
      Size = 0
      RoundByScale = True
    end
    object TableGID_XDATA_OUT: TFIBWideStringField
      FieldName = 'GID_XDATA_OUT'
      Size = 10
    end
    object TableIDTISM_XDATA_OUT: TFIBBCDField
      FieldName = 'IDTISM_XDATA_OUT'
      Size = 0
      RoundByScale = True
    end
    object TableIDBASE_XDATA_OUT: TFIBBCDField
      FieldName = 'IDBASE_XDATA_OUT'
      Size = 0
      RoundByScale = True
    end
    object TableTYPE_XDATA_OUT: TFIBSmallIntField
      FieldName = 'TYPE_XDATA_OUT'
    end
    object TableRESULT_XDATA_OUT: TFIBSmallIntField
      FieldName = 'RESULT_XDATA_OUT'
    end
    object TableIDEXT_DOUT_XDATA_OUT: TFIBBCDField
      FieldName = 'IDEXT_DOUT_XDATA_OUT'
      Size = 0
      RoundByScale = True
    end
    object TableIDEXT_BASE_XDATA_OUT: TFIBBCDField
      FieldName = 'IDEXT_BASE_XDATA_OUT'
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
    Left = 568
    Top = 168
  end
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 376
    Top = 160
  end
  object BaseList: TpFIBDataSet
    SelectSQL.Strings = (
      'select * '
      'from sinfbase_obmen')
    Transaction = pFIBTransaction1
    Database = DataModuleMain.pFIBDatabase
    Left = 576
    Top = 256
    object BaseListID_SINFBASE_OBMEN: TFIBBCDField
      FieldName = 'ID_SINFBASE_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object BaseListGID_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'GID_SINFBASE_OBMEN'
      Size = 10
    end
    object BaseListNAME_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 100
    end
    object BaseListPREFIKS_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'PREFIKS_SINFBASE_OBMEN'
      Size = 2
    end
    object BaseListIDTIZM_SINFBASE_OBMEN: TFIBIntegerField
      FieldName = 'IDTIZM_SINFBASE_OBMEN'
    end
    object BaseListIDBASE_SINFBASE_OBMEN: TFIBBCDField
      FieldName = 'IDBASE_SINFBASE_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object BaseListNOACT_SINFBASE_OBMEN: TFIBSmallIntField
      FieldName = 'NOACT_SINFBASE_OBMEN'
    end
  end
  object DataSourceBaseList: TDataSource
    DataSet = BaseList
    Left = 464
    Top = 264
  end
end
