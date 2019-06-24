object FormaCreateTriggerLog: TFormaCreateTriggerLog
  Left = 0
  Top = 0
  Caption = #1058#1088#1080#1075#1075#1077#1088#1099' '#1083#1086#1075#1075#1080#1088#1086#1074#1072#1085#1080#1103
  ClientHeight = 662
  ClientWidth = 1076
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
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 1076
    Height = 662
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    ActivePage = TabSheet1
    Align = alClient
    TabOrder = 0
    object TabSheet1: TTabSheet
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1044#1086#1073#1072#1074#1083#1077#1085#1080#1077' '#1087#1086#1083#1077#1081
      object Label5: TLabel
        Left = 4
        Top = 52
        Width = 37
        Height = 17
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1055#1086#1083#1077':'
      end
      object Label6: TLabel
        Left = 170
        Top = 52
        Width = 47
        Height = 17
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1044#1086#1084#1077#1085':'
      end
      object Label7: TLabel
        Left = 124
        Top = 260
        Width = 350
        Height = 51
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Alignment = taCenter
        Caption = 
          #1047#1072#1087#1086#1083#1085#1103#1077#1090' '#1090#1072#1073#1083#1080#1094#1091' XTABLE_BASE '#1076#1083#1103' '#1087#1086#1089#1083#1077#1076#1091#1102#1097#1077#1075#1086' '#1088#1091#1095#1085#1086#1075#1086' '#1088#1077#1076#1072#1082#1090#1080#1088#1086 +
          #1074#1072#1085#1080#1103'. '#1044#1083#1103' '#1082#1072#1078#1076#1086#1081' '#1090#1072#1073#1083#1080#1094#1099' '#1085#1077#1086#1073#1093#1086#1076#1080#1084#1086' '#1091#1082#1072#1079#1072#1090#1100' '#1090#1080#1087' '#1086#1073#1098#1077#1082#1090#1072'.'
        WordWrap = True
      end
      object Panel1: TPanel
        Left = 0
        Top = 391
        Width = 1068
        Height = 239
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Align = alBottom
        TabOrder = 0
        object DBGrid2: TDBGrid
          Left = 1
          Top = 1
          Width = 1066
          Height = 237
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Align = alClient
          DataSource = DataSource2
          TabOrder = 0
          TitleFont.Charset = DEFAULT_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -14
          TitleFont.Name = 'Tahoma'
          TitleFont.Style = []
          Columns = <
            item
              Expanded = False
              FieldName = 'RDB$FIELD_NAME'
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'RDB$FIELD_SOURCE'
              Width = 197
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'RDB$FIELD_SCALE'
              Width = 154
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'RDB$FIELD_TYPE'
              Width = 163
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'RDB$FIELD_PRECISION'
              Width = 161
              Visible = True
            end>
        end
      end
      object Panel2: TPanel
        Left = 546
        Top = 0
        Width = 522
        Height = 391
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Align = alRight
        TabOrder = 1
        object DBGrid1: TDBGrid
          Left = 1
          Top = 1
          Width = 520
          Height = 389
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Align = alClient
          DataSource = DataSource1
          TabOrder = 0
          TitleFont.Charset = DEFAULT_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -14
          TitleFont.Name = 'Tahoma'
          TitleFont.Style = []
          Columns = <
            item
              Expanded = False
              FieldName = 'RECNO'
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'FIELD_NAME'
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'TABLE_NAME'
              Visible = True
            end>
        end
      end
      object NameFieldEdit: TEdit
        Left = 4
        Top = 77
        Width = 158
        Height = 25
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        TabOrder = 2
        Text = 'NameFieldEdit'
      end
      object NameDomainEdit: TEdit
        Left = 170
        Top = 77
        Width = 158
        Height = 25
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        TabOrder = 3
        Text = 'NameDomainEdit'
      end
      object ButtonAddField: TButton
        Left = 336
        Top = 73
        Width = 98
        Height = 33
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1044#1086#1073#1072#1074#1080#1090#1100
        TabOrder = 4
        OnClick = ButtonAddFieldClick
      end
      object ButtondelField: TButton
        Left = 438
        Top = 73
        Width = 98
        Height = 33
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1059#1076#1072#1083#1080#1090#1100
        TabOrder = 5
        OnClick = ButtondelFieldClick
      end
      object ButtonCreateStrTable: TButton
        Left = 4
        Top = 253
        Width = 98
        Height = 33
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1057#1090#1088#1091#1082#1090#1091#1088#1072
        TabOrder = 6
        OnClick = ButtonCreateStrTableClick
      end
      object GroupBox1: TGroupBox
        Left = -5
        Top = 136
        Width = 532
        Height = 64
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1058#1088#1080#1075#1075#1077#1088#1099' '#1076#1083#1103' '#1086#1076#1085#1086#1081' '#1074#1099#1073#1088#1072#1085#1085#1086#1081' '#1090#1072#1073#1083#1080#1094#1099
        TabOrder = 7
        object ButtonCreateTriggerAfterInsert: TButton
          Left = 10
          Top = 24
          Width = 148
          Height = 32
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1055#1086#1089#1083#1077' '#1074#1089#1090#1072#1074#1082#1080
          TabOrder = 0
          OnClick = ButtonCreateTriggerAfterInsertClick
        end
        object ButtonCreateTriggerAfterUpdate: TButton
          Left = 177
          Top = 24
          Width = 158
          Height = 32
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1055#1086#1089#1083#1077' '#1080#1079#1084#1077#1085#1077#1085#1080#1103
          TabOrder = 1
          OnClick = ButtonCreateTriggerAfterUpdateClick
        end
        object ButtonCreatetriggerAfterDelete: TButton
          Left = 354
          Top = 24
          Width = 174
          Height = 32
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1055#1086#1089#1083#1077' '#1091#1076#1072#1083#1077#1085#1080#1103
          TabOrder = 2
          OnClick = ButtonCreatetriggerAfterDeleteClick
        end
      end
      object ButtonClear: TButton
        Left = 5
        Top = 304
        Width = 97
        Height = 33
        Caption = 'Clear'
        TabOrder = 8
        OnClick = ButtonClearClick
      end
      object ButtonSetGenMaxValue: TButton
        Left = 3
        Top = 352
        Width = 174
        Height = 25
        Caption = 'ButtonSetGenMaxValue'
        TabOrder = 9
        OnClick = ButtonSetGenMaxValueClick
      end
    end
    object TabSheet2: TTabSheet
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1058#1077#1082#1089#1090' '#1090#1088#1080#1075#1075#1077#1088#1072
      ImageIndex = 1
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object RichEdit1: TRichEdit
        Left = 0
        Top = 0
        Width = 1068
        Height = 630
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Align = alClient
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Tahoma'
        Font.Style = []
        Lines.Strings = (
          'RichEdit1')
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
    object TabSheet3: TTabSheet
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1058#1088#1080#1075#1075#1077#1088#1099' '#1083#1086#1075#1075#1080#1088#1086#1074#1072#1085#1080#1103
      ImageIndex = 2
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object GroupBox2: TGroupBox
        Left = 14
        Top = 41
        Width = 533
        Height = 60
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1090#1088#1080#1075#1075#1077#1088#1099' '#1074#1086' '#1074#1089#1077' '#1090#1072#1073#1083#1080#1094#1099
        TabOrder = 0
        object ButtonCreateALLTriggerAfterInsert: TButton
          Left = 10
          Top = 22
          Width = 148
          Height = 33
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1055#1086#1089#1083#1077' '#1074#1089#1090#1072#1074#1082#1080
          TabOrder = 0
          OnClick = ButtonCreateALLTriggerAfterInsertClick
        end
        object ButtonCreateALLTriggerAfterUpdate: TButton
          Left = 177
          Top = 22
          Width = 158
          Height = 33
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1055#1086#1089#1083#1077' '#1080#1079#1084#1077#1085#1077#1085#1080#1103
          TabOrder = 1
          OnClick = ButtonCreateALLTriggerAfterUpdateClick
        end
        object ButtonCreateAllTriggerAfterDelete: TButton
          Left = 354
          Top = 22
          Width = 174
          Height = 33
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1055#1086#1089#1083#1077' '#1091#1076#1072#1083#1077#1085#1080#1103
          TabOrder = 2
          OnClick = ButtonCreateAllTriggerAfterDeleteClick
        end
      end
      object GroupBox3: TGroupBox
        Left = 14
        Top = 124
        Width = 533
        Height = 60
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1059#1076#1072#1083#1080#1090#1100' '#1090#1088#1080#1075#1075#1077#1088#1099' '#1074#1086' '#1074#1089#1077#1093' '#1090#1072#1073#1083#1080#1094#1072#1093
        TabOrder = 1
        object ButtonDeleteALLTriggerAfterInsert: TButton
          Left = 10
          Top = 22
          Width = 148
          Height = 33
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1055#1086#1089#1083#1077' '#1074#1089#1090#1072#1074#1082#1080
          TabOrder = 0
          OnClick = ButtonDeleteALLTriggerAfterInsertClick
        end
        object ButtonDeleteALLTriggerAfterUpdate: TButton
          Left = 177
          Top = 22
          Width = 158
          Height = 33
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1055#1086#1089#1083#1077' '#1080#1079#1084#1077#1085#1077#1085#1080#1103
          TabOrder = 1
          OnClick = ButtonDeleteALLTriggerAfterUpdateClick
        end
        object ButtonDeleteTriggerAfterDelete: TButton
          Left = 354
          Top = 22
          Width = 174
          Height = 33
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1055#1086#1089#1083#1077' '#1091#1076#1072#1083#1077#1085#1080#1103
          TabOrder = 2
          OnClick = ButtonDeleteTriggerAfterDeleteClick
        end
      end
      object GroupBox4: TGroupBox
        Left = 14
        Top = 211
        Width = 533
        Height = 240
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1058#1086#1083#1100#1082#1086' '#1074' '#1086#1076#1085#1086#1081' '#1090#1072#1073#1083#1080#1094#1077
        TabOrder = 2
        object Label1: TLabel
          Left = 10
          Top = 61
          Width = 223
          Height = 17
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1042#1089#1090#1072#1074#1080#1090#1100' '#1090#1088#1080#1075#1075#1077#1088#1099' '#1083#1086#1075#1075#1080#1088#1086#1074#1072#1085#1080#1103':'
        end
        object Label2: TLabel
          Left = 10
          Top = 160
          Width = 217
          Height = 17
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1059#1076#1072#1083#1080#1090#1100' '#1090#1088#1080#1075#1075#1077#1088#1099' '#1083#1086#1075#1075#1080#1088#1086#1074#1072#1085#1080#1103':'
        end
        object TableNameEdit: TEdit
          Left = 10
          Top = 26
          Width = 159
          Height = 25
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          TabOrder = 0
          Text = 'TableNameEdit'
        end
        object Button1: TButton
          Left = 10
          Top = 86
          Width = 148
          Height = 33
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1055#1086#1089#1083#1077' '#1074#1089#1090#1072#1074#1082#1080
          TabOrder = 1
          OnClick = Button1Click
        end
        object Button3: TButton
          Left = 354
          Top = 188
          Width = 160
          Height = 33
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1055#1086#1089#1083#1077' '#1091#1076#1072#1083#1077#1085#1080#1103
          TabOrder = 2
          OnClick = Button3Click
        end
        object Button2: TButton
          Left = 177
          Top = 188
          Width = 158
          Height = 33
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1055#1086#1089#1083#1077' '#1080#1079#1084#1077#1085#1077#1085#1080#1103
          TabOrder = 3
          OnClick = Button2Click
        end
        object Button5: TButton
          Left = 177
          Top = 85
          Width = 158
          Height = 33
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1055#1086#1089#1083#1077' '#1080#1079#1084#1077#1085#1077#1085#1080#1103
          TabOrder = 4
          OnClick = Button5Click
        end
        object Button6: TButton
          Left = 354
          Top = 85
          Width = 160
          Height = 33
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1055#1086#1089#1083#1077' '#1091#1076#1072#1083#1077#1085#1080#1103
          TabOrder = 5
          OnClick = Button6Click
        end
        object Button4: TButton
          Left = 10
          Top = 184
          Width = 148
          Height = 33
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1055#1086#1089#1083#1077' '#1074#1089#1090#1072#1074#1082#1080
          TabOrder = 6
          OnClick = Button4Click
        end
      end
    end
  end
  object DataSource1: TDataSource
    DataSet = Tables
    Left = 816
    Top = 136
  end
  object DataSource2: TDataSource
    DataSet = Fields
    Left = 232
    Top = 368
  end
  object IBTr: TpFIBTransaction
    DefaultDatabase = DataModuleMain.pFIBDatabase
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 736
    Top = 136
  end
  object Tables: TpFIBDataSet
    SelectSQL.Strings = (
      
        'select RDB$RELATION_FIELDS.RDB$FIELD_NAME AS FIELD_NAME, RDB$REL' +
        'ATION_FIELDS.RDB$RELATION_NAME AS TABLE_NAME'
      'from RDB$RELATION_FIELDS'
      
        'left outer join RDB$FIELDS on RDB$RELATION_FIELDS.RDB$FIELD_SOUR' +
        'CE=RDB$FIELDS.RDB$FIELD_NAME'
      ''
      ''
      'where RDB$RELATION_FIELDS.RDB$SYSTEM_FLAG=0  and'
      'RDB$RELATION_FIELDS.RDB$FIELD_SOURCE='#39'DOMAIN_IDTABLE'#39'  '
      'ORDER BY TABLE_NAME')
    OnCalcFields = TablesCalcFields
    Transaction = IBTr
    Database = DataModuleMain.pFIBDatabase
    Left = 872
    Top = 128
    object TablesRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TablesFIELD_NAME: TFIBWideStringField
      FieldName = 'FIELD_NAME'
      Size = 31
    end
    object TablesTABLE_NAME: TFIBWideStringField
      FieldName = 'TABLE_NAME'
      Size = 31
    end
  end
  object IBTrUpdate: TpFIBTransaction
    DefaultDatabase = DataModuleMain.pFIBDatabase
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 840
    Top = 280
  end
  object Query: TpFIBQuery
    Transaction = IBTr
    Database = DataModuleMain.pFIBDatabase
    Left = 664
    Top = 200
    qoStartTransaction = True
  end
  object QueryUpdate: TpFIBQuery
    Transaction = IBTrUpdate
    Database = DataModuleMain.pFIBDatabase
    Left = 744
    Top = 296
    qoStartTransaction = True
  end
  object Fields: TpFIBDataSet
    SelectSQL.Strings = (
      'select * '
      'from RDB$RELATION_FIELDS'
      
        'left outer join RDB$FIELDS on RDB$RELATION_FIELDS.RDB$FIELD_SOUR' +
        'CE=RDB$FIELDS.RDB$FIELD_NAME'
      ''
      ''
      'where RDB$RELATION_FIELDS.RDB$SYSTEM_FLAG=0'
      'and RDB$RELATION_FIELDS.RDB$RELATION_NAME=:TABLE_NAME')
    Transaction = IBTr
    Database = DataModuleMain.pFIBDatabase
    DataSource = DataSource1
    Left = 328
    Top = 368
    object FieldsRDBFIELD_NAME: TFIBWideStringField
      FieldName = 'RDB$FIELD_NAME'
      Size = 31
    end
    object FieldsRDBFIELD_SOURCE: TFIBWideStringField
      FieldName = 'RDB$FIELD_SOURCE'
      Size = 31
    end
    object FieldsRDBFIELD_SCALE: TFIBSmallIntField
      FieldName = 'RDB$FIELD_SCALE'
    end
    object FieldsRDBFIELD_TYPE: TFIBSmallIntField
      FieldName = 'RDB$FIELD_TYPE'
    end
    object FieldsRDBFIELD_PRECISION: TFIBSmallIntField
      FieldName = 'RDB$FIELD_PRECISION'
    end
  end
  object IBScript1: TpFIBScripter
    Database = DataModuleMain.pFIBDatabase
    Transaction = IBTrUpdate
    Left = 448
    Top = 224
  end
end
