object FormaObmenExport: TFormaObmenExport
  Left = 245
  Top = 199
  Width = 789
  Height = 587
  Caption = #1054#1073#1084#1077#1085' '#1076#1072#1085#1085#1099#1084#1080' '#1089' '#1091#1076#1072#1083#1077#1085#1085#1099#1084#1080' '#1073#1072#1079#1072#1084#1080' ('#1101#1082#1089#1087#1086#1088#1090' '#1076#1072#1085#1085#1099#1093')'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 781
    Height = 29
    Caption = 'ToolBar1'
    EdgeBorders = [ebTop, ebBottom]
    TabOrder = 0
  end
  object Panel1: TPanel
    Left = 0
    Top = 29
    Width = 781
    Height = 100
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 1
    object Label1: TLabel
      Left = 8
      Top = 1
      Width = 428
      Height = 20
      Caption = #1054#1073#1084#1077#1085' '#1076#1072#1085#1085#1099#1084#1080' '#1089' '#1091#1076#1072#1083#1077#1085#1085#1099#1084#1080' '#1073#1072#1079#1072#1084#1080' ('#1101#1082#1089#1087#1086#1088#1090' '#1076#1072#1085#1085#1099#1093')'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsUnderline]
      ParentFont = False
    end
    object LabelFileName: TLabel
      Left = 40
      Top = 44
      Width = 121
      Height = 16
      Caption = #1060#1072#1081#1083' '#1085#1077' '#1074#1099#1073#1088#1072#1085
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object NameBaseLabel: TLabel
      Left = 96
      Top = 64
      Width = 118
      Height = 20
      Caption = 'NameBaseLabel'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabelFileNameOut: TLabel
      Left = 104
      Top = 88
      Width = 87
      Height = 13
      Caption = 'LabelFileNameOut'
    end
    object ButtonOpenFile: TButton
      Left = 8
      Top = 35
      Width = 25
      Height = 25
      Caption = '...'
      TabOrder = 0
      OnClick = ButtonOpenFileClick
    end
    object ButtonViborBase: TButton
      Left = 8
      Top = 72
      Width = 75
      Height = 25
      Caption = #1041#1072#1079#1072
      TabOrder = 1
      OnClick = ButtonViborBaseClick
    end
    object CheckBoxOutProtocol: TCheckBox
      Left = 520
      Top = 83
      Width = 97
      Height = 17
      Caption = #1074#1077#1089#1090#1080' '#1087#1088#1086#1090#1086#1082#1086#1083
      TabOrder = 2
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 129
    Width = 9
    Height = 327
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 2
  end
  object Panel4: TPanel
    Left = 769
    Top = 129
    Width = 12
    Height = 327
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 3
  end
  object Panel6: TPanel
    Left = 9
    Top = 129
    Width = 760
    Height = 327
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 4
    object PageControl1: TPageControl
      Left = 0
      Top = 0
      Width = 760
      Height = 327
      ActivePage = TabSheet2
      Align = alClient
      TabIndex = 0
      TabOrder = 0
      object TabSheet2: TTabSheet
        Caption = #1055#1088#1086#1090#1086#1082#1086#1083
        ImageIndex = 1
        object RichEdit1: TRichEdit
          Left = 0
          Top = 0
          Width = 752
          Height = 299
          Align = alClient
          Lines.Strings = (
            'RichEdit1')
          ScrollBars = ssBoth
          TabOrder = 0
        end
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 456
    Width = 781
    Height = 97
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 5
    object LabelTotalIsm: TLabel
      Left = 8
      Top = 73
      Width = 151
      Height = 20
      Caption = #1042#1089#1077#1075#1086' '#1080#1079#1084#1077#1085#1077#1085#1080#1081':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object LabelZagrIsm: TLabel
      Left = 320
      Top = 72
      Width = 194
      Height = 20
      Caption = #1042#1099#1075#1088#1091#1078#1077#1085#1086' '#1080#1079#1084#1077#1085#1077#1085#1080#1081':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ProgressBar1: TProgressBar
      Left = 8
      Top = 16
      Width = 761
      Height = 17
      Min = 0
      Max = 100
      Smooth = True
      Step = 1
      TabOrder = 0
    end
    object ButtonVigr: TButton
      Left = 608
      Top = 40
      Width = 75
      Height = 25
      Caption = #1042#1099#1075#1088#1091#1079#1080#1090#1100
      TabOrder = 1
      OnClick = ButtonVigrClick
    end
    object ButtonCreateData: TButton
      Left = 472
      Top = 40
      Width = 129
      Height = 25
      Caption = #1055#1086#1076#1075#1086#1090#1086#1074#1080#1090#1100' '#1076#1072#1085#1085#1099#1077
      TabOrder = 2
      OnClick = ButtonCreateDataClick
    end
    object ButtonClose: TButton
      Left = 688
      Top = 40
      Width = 75
      Height = 25
      Caption = #1047#1072#1082#1088#1099#1090#1100
      TabOrder = 3
      OnClick = ButtonCloseClick
    end
    object ButtonStrBase: TButton
      Left = 216
      Top = 40
      Width = 145
      Height = 25
      Caption = #1047#1072#1087#1086#1083#1085#1080#1090#1100' '#1089#1090#1088#1091#1082#1090#1091#1088#1091' '#1073#1072#1079#1099
      TabOrder = 4
      OnClick = ButtonStrBaseClick
    end
    object Button1: TButton
      Left = 8
      Top = 40
      Width = 201
      Height = 25
      Caption = #1054#1095#1080#1089#1090#1080#1090#1100' '#1076#1072#1085#1085#1099#1077' '#1074#1089#1077#1093' '#1089#1086#1086#1073#1097#1077#1085#1080#1081
      TabOrder = 5
      OnClick = Button1Click
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 544
  end
  object IBTr: TIBTransaction
    Active = False
    DefaultDatabase = DM.IBData
    Params.Strings = (
      'read_committed'
      'rec_version'
      'nowait')
    AutoStopAction = saNone
    Left = 352
    Top = 64
  end
  object IBQ: TIBQuery
    Database = DM.IBData
    Transaction = IBTr1
    BufferChunks = 1000
    CachedUpdates = False
    Left = 312
    Top = 104
  end
  object IBTr1: TIBTransaction
    Active = False
    DefaultDatabase = DM.IBData
    Params.Strings = (
      'read_committed'
      'rec_version'
      'nowait'
      'read')
    AutoStopAction = saNone
    Left = 344
    Top = 104
  end
  object IBQ2: TIBQuery
    Database = DM.IBData
    Transaction = IBTr2
    BufferChunks = 1000
    CachedUpdates = False
    Left = 472
    Top = 88
  end
  object IBTr2: TIBTransaction
    Active = False
    DefaultDatabase = DM.IBData
    Params.Strings = (
      'read_committed'
      'rec_version'
      'nowait'
      'read')
    AutoStopAction = saNone
    Left = 504
    Top = 88
  end
  object TableFields: TIBQuery
    Database = DM.IBData
    Transaction = DM.IBTr
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      'select * '
      'from RDB$RELATION_FIELDS'
      
        'left outer join RDB$FIELDS on RDB$RELATION_FIELDS.RDB$FIELD_SOUR' +
        'CE=RDB$FIELDS.RDB$FIELD_NAME'
      ''
      ''
      'where RDB$RELATION_FIELDS.RDB$SYSTEM_FLAG=0'
      'and RDB$RELATION_FIELDS.RDB$RELATION_NAME=:PARAM_NAMETABLE')
    Left = 600
    Top = 40
    ParamData = <
      item
        DataType = ftString
        Name = 'PARAM_NAMETABLE'
        ParamType = ptUnknown
        Value = 'SNOM'
      end>
    object TableFieldsRDBFIELD_NAME: TIBStringField
      FieldName = 'RDB$FIELD_NAME'
      Origin = 'RDB$RELATION_FIELDS.RDB$FIELD_NAME'
      FixedChar = True
      Size = 31
    end
    object TableFieldsRDBRELATION_NAME: TIBStringField
      FieldName = 'RDB$RELATION_NAME'
      Origin = 'RDB$RELATION_FIELDS.RDB$RELATION_NAME'
      FixedChar = True
      Size = 31
    end
    object TableFieldsRDBFIELD_SOURCE: TIBStringField
      FieldName = 'RDB$FIELD_SOURCE'
      Origin = 'RDB$RELATION_FIELDS.RDB$FIELD_SOURCE'
      FixedChar = True
      Size = 31
    end
    object TableFieldsRDBFIELD_SCALE: TSmallintField
      FieldName = 'RDB$FIELD_SCALE'
      Origin = 'RDB$FIELDS.RDB$FIELD_SCALE'
    end
    object TableFieldsRDBFIELD_TYPE: TSmallintField
      FieldName = 'RDB$FIELD_TYPE'
      Origin = 'RDB$FIELDS.RDB$FIELD_TYPE'
    end
  end
  object TableFK: TIBQuery
    Database = DM.IBData
    Transaction = IBTrSys
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      'select * '
      'from RDB$RELATION_FIELDS'
      
        'left outer join RDB$FIELDS on RDB$RELATION_FIELDS.RDB$FIELD_SOUR' +
        'CE=RDB$FIELDS.RDB$FIELD_NAME '
      
        'left outer join RDB$INDEX_SEGMENTS on RDB$INDEX_SEGMENTS.RDB$FIE' +
        'LD_NAME=RDB$RELATION_FIELDS.RDB$FIELD_NAME'
      
        'left outer join RDB$INDICES on RDB$INDEX_SEGMENTS.RDB$INDEX_NAME' +
        '=RDB$INDICES.RDB$INDEX_NAME'
      
        'left outer join RDB$INDEX_SEGMENTS on RDB$INDEX_SEGMENTS.RDB$IND' +
        'EX_NAME=RDB$INDICES.RDB$FOREIGN_KEY'
      
        'left outer join RDB$RELATION_FIELDS on RDB$RELATION_FIELDS.RDB$F' +
        'IELD_NAME=RDB$INDEX_SEGMENTS.RDB$FIELD_NAME'
      'where RDB$RELATION_FIELDS.RDB$SYSTEM_FLAG=0 '
      '')
    Left = 600
    Top = 72
    object TableFKRDBFIELD_NAME: TIBStringField
      FieldName = 'RDB$FIELD_NAME'
      Origin = 'RDB$RELATION_FIELDS.RDB$FIELD_NAME'
      FixedChar = True
      Size = 31
    end
    object TableFKRDBFIELD_SOURCE: TIBStringField
      FieldName = 'RDB$FIELD_SOURCE'
      Origin = 'RDB$RELATION_FIELDS.RDB$FIELD_SOURCE'
      FixedChar = True
      Size = 31
    end
    object TableFKRDBFIELD_NAME3: TIBStringField
      FieldName = 'RDB$FIELD_NAME3'
      Origin = 'RDB$INDEX_SEGMENTS.RDB$FIELD_NAME'
      FixedChar = True
      Size = 31
    end
    object TableFKRDBRELATION_NAME2: TIBStringField
      FieldName = 'RDB$RELATION_NAME2'
      Origin = 'RDB$RELATION_FIELDS.RDB$RELATION_NAME'
      FixedChar = True
      Size = 31
    end
  end
  object IBTrSys: TIBTransaction
    Active = False
    DefaultDatabase = DM.IBData
    Params.Strings = (
      'read_committed'
      'rec_version'
      'nowait'
      'read')
    AutoStopAction = saNone
    Left = 640
    Top = 40
  end
  object DataSource1: TDataSource
    Left = 472
    Top = 40
  end
  object TablePK: TIBQuery
    Database = DM.IBData
    Transaction = DM.IBTr
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      
        'select RDB$RELATION_FIELDS.RDB$FIELD_NAME AS FIELD_NAME, RDB$REL' +
        'ATION_FIELDS.RDB$RELATION_NAME AS TABLE_NAME'
      'from RDB$RELATION_FIELDS'
      
        'left outer join RDB$FIELDS on RDB$RELATION_FIELDS.RDB$FIELD_SOUR' +
        'CE=RDB$FIELDS.RDB$FIELD_NAME'
      ''
      ''
      'where RDB$RELATION_FIELDS.RDB$SYSTEM_FLAG=0  and'
      'RDB$RELATION_FIELDS.RDB$FIELD_SOURCE='#39'DOMAIN_IDTABLE'#39'  '
      '')
    Left = 600
    Top = 104
    object TablePKFIELD_NAME: TIBStringField
      FieldName = 'FIELD_NAME'
      Origin = 'RDB$RELATION_FIELDS.RDB$FIELD_NAME'
      FixedChar = True
      Size = 31
    end
    object TablePKTABLE_NAME: TIBStringField
      FieldName = 'TABLE_NAME'
      Origin = 'RDB$RELATION_FIELDS.RDB$RELATION_NAME'
      FixedChar = True
      Size = 31
    end
  end
  object TableDataOut: TIBDataSet
    Database = DM.IBData
    Transaction = IBTr
    BufferChunks = 1000
    CachedUpdates = False
    DeleteSQL.Strings = (
      '')
    InsertSQL.Strings = (
      '')
    RefreshSQL.Strings = (
      'Select '
      '  ID_XDATA_OUT,'
      '  GID_XDATA_OUT,'
      '  IDTISM_XDATA_OUT,'
      '  IDBASE_XDATA_OUT,'
      '  IDMESSAGE_XDATA_OUT'
      'from XDATA_OUT '
      'where'
      '  ID_XDATA_OUT = :ID_XDATA_OUT')
    SelectSQL.Strings = (
      'select * '
      'from XDATA_OUT'
      'left outer join XTISM on IDTISM_XDATA_OUT=ID_XTISM'
      'where  IDBASE_XDATA_OUT=:PARAM_IDBASE and '
      '(IDMESSAGE_XDATA_OUT IS NULL or IDMESSAGE_XDATA_OUT=0)')
    ModifySQL.Strings = (
      'update XDATA_OUT'
      'set'
      '  IDMESSAGE_XDATA_OUT = :IDMESSAGE_XDATA_OUT'
      'where'
      '  ID_XDATA_OUT = :OLD_ID_XDATA_OUT')
    Left = 320
    Top = 64
    object TableDataOutID_XDATA_OUT: TIntegerField
      FieldName = 'ID_XDATA_OUT'
      Origin = 'XDATA_OUT.ID_XDATA_OUT'
      Required = True
    end
    object TableDataOutGID_XDATA_OUT: TIBStringField
      FieldName = 'GID_XDATA_OUT'
      Origin = 'XDATA_OUT.GID_XDATA_OUT'
      Size = 10
    end
    object TableDataOutIDTISM_XDATA_OUT: TIntegerField
      FieldName = 'IDTISM_XDATA_OUT'
      Origin = 'XDATA_OUT.IDTISM_XDATA_OUT'
    end
    object TableDataOutIDBASE_XDATA_OUT: TIntegerField
      FieldName = 'IDBASE_XDATA_OUT'
      Origin = 'XDATA_OUT.IDBASE_XDATA_OUT'
    end
    object TableDataOutIDMESSAGE_XDATA_OUT: TIntegerField
      FieldName = 'IDMESSAGE_XDATA_OUT'
      Origin = 'XDATA_OUT.IDMESSAGE_XDATA_OUT'
    end
    object TableDataOutID_XTISM: TIntegerField
      FieldName = 'ID_XTISM'
      Origin = 'XTISM.ID_XTISM'
    end
    object TableDataOutGID_XTISM: TIBStringField
      FieldName = 'GID_XTISM'
      Origin = 'XTISM.GID_XTISM'
      Size = 10
    end
    object TableDataOutPOS_XTISM: TDateTimeField
      FieldName = 'POS_XTISM'
      Origin = 'XTISM.POS_XTISM'
    end
    object TableDataOutNAMETAB_XTISM: TIBStringField
      FieldName = 'NAMETAB_XTISM'
      Origin = 'XTISM.NAMETAB_XTISM'
      Size = 10
    end
    object TableDataOutIDREC_XTISM: TIntegerField
      FieldName = 'IDREC_XTISM'
      Origin = 'XTISM.IDREC_XTISM'
    end
    object TableDataOutTYPEOB_XTISM: TIntegerField
      FieldName = 'TYPEOB_XTISM'
      Origin = 'XTISM.TYPEOB_XTISM'
    end
    object TableDataOutIDUSER_XTISM: TIntegerField
      FieldName = 'IDUSER_XTISM'
      Origin = 'XTISM.IDUSER_XTISM'
    end
    object TableDataOutPRBASE_XTISM: TIBStringField
      FieldName = 'PRBASE_XTISM'
      Origin = 'XTISM.PRBASE_XTISM'
      Size = 2
    end
    object TableDataOutOPER_XTISM: TIntegerField
      FieldName = 'OPER_XTISM'
      Origin = 'XTISM.OPER_XTISM'
    end
  end
  object DocAll: TIBQuery
    Database = DM.IBData
    Transaction = IBTr1
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      'select TDOC, IDSKLDOC from GALLDOC'
      'where IDDOC=:PARAM_IDDOC')
    Left = 328
    Top = 128
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'PARAM_IDDOC'
        ParamType = ptUnknown
      end>
    object DocAllTDOC: TIBStringField
      FieldName = 'TDOC'
      Origin = 'GALLDOC.TDOC'
      Size = 10
    end
    object DocAllIDSKLDOC: TIntegerField
      FieldName = 'IDSKLDOC'
      Origin = 'GALLDOC.IDSKLDOC'
    end
  end
  object Doc: TIBQuery
    Database = DM.IBData
    Transaction = IBTr1
    BufferChunks = 1000
    CachedUpdates = False
    Left = 352
    Top = 128
  end
  object DocT: TIBQuery
    Database = DM.IBData
    Transaction = IBTr1
    BufferChunks = 1000
    CachedUpdates = False
    Left = 376
    Top = 128
  end
end
