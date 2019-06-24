object FormaGurPKO: TFormaGurPKO
  Left = 238
  Top = 172
  Width = 769
  Height = 490
  Caption = #1046#1091#1088#1085#1072#1083' '#1087#1088#1080#1093#1086#1076#1085#1099#1093' '#1082#1072#1089#1089#1086#1074#1099#1093' '#1086#1088#1076#1077#1088#1086#1074
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 761
    Height = 97
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 0
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 761
      Height = 29
      Caption = 'ToolBar1'
      Images = DM.ImageList1
      TabOrder = 0
      object ToolButton1: TToolButton
        Left = 0
        Top = 2
        Width = 8
        Caption = 'ToolButton1'
        Style = tbsSeparator
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 366
    Width = 761
    Height = 97
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
  end
  object Panel3: TPanel
    Left = 0
    Top = 97
    Width = 9
    Height = 269
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 2
  end
  object Panel4: TPanel
    Left = 753
    Top = 97
    Width = 8
    Height = 269
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 3
  end
  object DBGrid1: TDBGrid
    Left = 9
    Top = 97
    Width = 744
    Height = 269
    Align = alClient
    DataSource = DataSource1
    ReadOnly = True
    TabOrder = 4
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'PRDOC'
        Title.Caption = #1055#1088'.'
        Width = 26
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'POSDOC'
        Title.Caption = #1044#1072#1090#1072
        Width = 108
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'NUMDOC'
        Title.Caption = #1053#1086#1084#1077#1088
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'NAMEFIRM'
        Title.Caption = #1060#1080#1088#1084#1072
        Width = 136
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'NAMEKKM'
        Title.Caption = #1050#1050#1052
        Width = 67
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'NAMEKLIENT'
        Title.Caption = #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090
        Width = 220
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'SUMDOC'
        Title.Caption = #1057#1091#1084#1084#1072
        Width = 74
        Visible = True
      end>
  end
  object IBQGurnal: TIBQuery
    Database = DM.IBData
    Transaction = IBTr
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      'select  GALLDOC.*, NAMEKKM, NAMEKLIENT, NAMEFIRM'
      'from '
      '  GALLDOC'
      'left outer join  DPKO on IDDOC=IDDOCPKO'
      'left outer join SKKM on IDKKMPKO=IDKKM'
      'left outer join SKLIENT on IDKLDOC=IDKLIENT'
      'left outer join SFIRM on IDFIRMDOC=IDFIRM'
      'where'
      ' TDOC='#39'PKO'#39)
    Left = 632
    Top = 8
    object IBQGurnalIDDOC: TIntegerField
      FieldName = 'IDDOC'
      Origin = 'GALLDOC.IDDOC'
      Required = True
    end
    object IBQGurnalPOSDOC: TDateTimeField
      FieldName = 'POSDOC'
      Origin = 'GALLDOC.POSDOC'
    end
    object IBQGurnalPRDOC: TSmallintField
      FieldName = 'PRDOC'
      Origin = 'GALLDOC.PRDOC'
    end
    object IBQGurnalTDOC: TIBStringField
      FieldName = 'TDOC'
      Origin = 'GALLDOC.TDOC'
      Size = 3
    end
    object IBQGurnalNUMDOC: TIntegerField
      FieldName = 'NUMDOC'
      Origin = 'GALLDOC.NUMDOC'
    end
    object IBQGurnalIDFIRMDOC: TIntegerField
      FieldName = 'IDFIRMDOC'
      Origin = 'GALLDOC.IDFIRMDOC'
    end
    object IBQGurnalIDSKLDOC: TIntegerField
      FieldName = 'IDSKLDOC'
      Origin = 'GALLDOC.IDSKLDOC'
    end
    object IBQGurnalIDKLDOC: TIntegerField
      FieldName = 'IDKLDOC'
      Origin = 'GALLDOC.IDKLDOC'
    end
    object IBQGurnalSUMDOC: TIBBCDField
      FieldName = 'SUMDOC'
      Origin = 'GALLDOC.SUMDOC'
      Precision = 18
      Size = 2
    end
    object IBQGurnalIDUSERDOC: TIntegerField
      FieldName = 'IDUSERDOC'
      Origin = 'GALLDOC.IDUSERDOC'
    end
    object IBQGurnalNAMEKKM: TIBStringField
      FieldName = 'NAMEKKM'
      Origin = 'SKKM.NAMEKKM'
      Size = 50
    end
    object IBQGurnalNAMEKLIENT: TIBStringField
      FieldName = 'NAMEKLIENT'
      Origin = 'SKLIENT.NAMEKLIENT'
      Size = 50
    end
    object IBQGurnalNAMEFIRM: TIBStringField
      FieldName = 'NAMEFIRM'
      Origin = 'SFIRM.NAMEFIRM'
      Size = 50
    end
  end
  object IBTr: TIBTransaction
    Active = True
    DefaultDatabase = DM.IBData
    Params.Strings = (
      'read_committed'
      'rec_version'
      'nowait')
    AutoStopAction = saNone
    Left = 664
    Top = 8
  end
  object DataSource1: TDataSource
    DataSet = IBQGurnal
    Left = 600
    Top = 8
  end
  object IBQDoc: TIBQuery
    Database = DM.IBData
    Transaction = IBTr
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      'select  GALLDOC.*, OSNPKO, NAMEKKM, NAMEKLIENT, NAMEFIRM'
      'from '
      '  GALLDOC'
      'left outer join  DPKO on IDDOC=IDDOCPKO'
      'left outer join SKKM on IDKKMPKO=IDKKM'
      'left outer join SKLIENT on IDKLDOC=IDKLIENT'
      'left outer join SFIRM on IDFIRMDOC=IDFIRM'
      'where'
      '  IDDOC=:PARAM_IDDOC')
    Left = 632
    Top = 40
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'PARAM_IDDOC'
        ParamType = ptUnknown
      end>
    object IBQDocIDDOC: TIntegerField
      FieldName = 'IDDOC'
      Origin = 'GALLDOC.IDDOC'
      Required = True
    end
    object IBQDocPOSDOC: TDateTimeField
      FieldName = 'POSDOC'
      Origin = 'GALLDOC.POSDOC'
    end
    object IBQDocPRDOC: TSmallintField
      FieldName = 'PRDOC'
      Origin = 'GALLDOC.PRDOC'
    end
    object IBQDocTDOC: TIBStringField
      FieldName = 'TDOC'
      Origin = 'GALLDOC.TDOC'
      Size = 3
    end
    object IBQDocNUMDOC: TIntegerField
      FieldName = 'NUMDOC'
      Origin = 'GALLDOC.NUMDOC'
    end
    object IBQDocIDFIRMDOC: TIntegerField
      FieldName = 'IDFIRMDOC'
      Origin = 'GALLDOC.IDFIRMDOC'
    end
    object IBQDocIDSKLDOC: TIntegerField
      FieldName = 'IDSKLDOC'
      Origin = 'GALLDOC.IDSKLDOC'
    end
    object IBQDocIDKLDOC: TIntegerField
      FieldName = 'IDKLDOC'
      Origin = 'GALLDOC.IDKLDOC'
    end
    object IBQDocSUMDOC: TIBBCDField
      FieldName = 'SUMDOC'
      Origin = 'GALLDOC.SUMDOC'
      Precision = 18
      Size = 2
    end
    object IBQDocIDUSERDOC: TIntegerField
      FieldName = 'IDUSERDOC'
      Origin = 'GALLDOC.IDUSERDOC'
    end
    object IBQDocOSNPKO: TIBStringField
      FieldName = 'OSNPKO'
      Origin = 'DPKO.OSNPKO'
      Size = 50
    end
    object IBQDocNAMEKKM: TIBStringField
      FieldName = 'NAMEKKM'
      Origin = 'SKKM.NAMEKKM'
      Size = 50
    end
    object IBQDocNAMEKLIENT: TIBStringField
      FieldName = 'NAMEKLIENT'
      Origin = 'SKLIENT.NAMEKLIENT'
      Size = 50
    end
    object IBQDocNAMEFIRM: TIBStringField
      FieldName = 'NAMEFIRM'
      Origin = 'SFIRM.NAMEFIRM'
      Size = 50
    end
  end
end
