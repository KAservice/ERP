object FDocPrihNakl: TFDocPrihNakl
  Left = 258
  Top = 258
  Width = 690
  Height = 464
  Caption = #1044#1086#1082#1091#1084#1077#1085#1090' "'#1055#1088#1080#1093#1086#1076#1085#1072#1103' '#1085#1072#1082#1083#1072#1076#1085#1072#1103'"'
  Color = clBtnFace
  Constraints.MinWidth = 689
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
  object Panel2: TPanel
    Left = 0
    Top = 333
    Width = 682
    Height = 97
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 0
    object LabelSumma: TLabel
      Left = 480
      Top = 13
      Width = 174
      Height = 20
      Caption = #1057#1091#1084#1084#1072' '#1076#1086#1082#1091#1084#1077#1085#1090#1072': 0,00'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object ButtonClose: TButton
      Left = 480
      Top = 56
      Width = 75
      Height = 25
      Caption = #1047#1072#1082#1088#1099#1090#1100
      TabOrder = 0
      OnClick = ButtonCloseClick
    end
    object ButtonOK: TButton
      Left = 400
      Top = 56
      Width = 75
      Height = 25
      Caption = #1054#1050
      TabOrder = 1
      OnClick = ButtonOKClick
    end
    object ButtonDvReg: TButton
      Left = 312
      Top = 56
      Width = 75
      Height = 25
      Caption = #1055#1088#1086#1074#1077#1089#1090#1080
      TabOrder = 2
      OnClick = ButtonDvRegClick
    end
    object ButtonSave: TButton
      Left = 224
      Top = 56
      Width = 75
      Height = 25
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      TabOrder = 3
      OnClick = ButtonSaveClick
    end
    object ButtonPrint: TButton
      Left = 144
      Top = 56
      Width = 75
      Height = 25
      Caption = #1055#1077#1095#1072#1090#1100
      TabOrder = 4
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 129
    Width = 9
    Height = 204
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 1
  end
  object Panel4: TPanel
    Left = 673
    Top = 129
    Width = 9
    Height = 204
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 2
  end
  object DBGrid1: TDBGrid
    Left = 9
    Top = 129
    Width = 664
    Height = 204
    Align = alClient
    DataSource = DMDocPrihNakl.DataSourceDocT
    TabOrder = 3
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    OnColExit = DBGrid1ColExit
    OnEditButtonClick = DBGrid1EditButtonClick
    OnExit = DBGrid1Exit
    OnKeyPress = DBGrid1KeyPress
    Columns = <
      item
        Expanded = False
        FieldName = 'RECNO'
        Title.Caption = #8470
        Width = 54
        Visible = True
      end
      item
        ButtonStyle = cbsEllipsis
        Expanded = False
        FieldName = 'NAMENOM'
        Title.Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
        Width = 255
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'KOLPRNT'
        Title.Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086
        Width = 72
        Visible = True
      end
      item
        ButtonStyle = cbsEllipsis
        Expanded = False
        FieldName = 'NAMEED'
        Title.Caption = #1045#1076#1080#1085#1080#1094#1072
        Width = 76
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'KFPRNT'
        Title.Caption = 'K'
        Width = 60
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'PRICEPRNT'
        Title.Caption = #1062#1077#1085#1072
        Width = 70
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'SUMPRNT'
        Title.Caption = #1057#1091#1084#1084#1072
        Width = 90
        Visible = True
      end>
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 682
    Height = 129
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 4
    object Label1: TLabel
      Left = 16
      Top = 48
      Width = 250
      Height = 24
      Caption = #1055#1088#1080#1093#1086#1076#1085#1072#1103' '#1085#1072#1082#1083#1072#1076#1085#1072#1103'  '#8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 368
      Top = 48
      Width = 36
      Height = 29
      Caption = #1086#1090' '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -24
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label3: TLabel
      Left = 80
      Top = 96
      Width = 66
      Height = 13
      Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077':'
    end
    object FDateDoc: TDateTimePicker
      Left = 408
      Top = 48
      Width = 121
      Height = 24
      CalAlignment = dtaLeft
      Date = 38451.6406000232
      Time = 38451.6406000232
      DateFormat = dfShort
      DateMode = dmComboBox
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Kind = dtkDate
      ParseInput = False
      ParentFont = False
      TabOrder = 0
      OnChange = FDateDocChange
    end
    object ToolBar2: TToolBar
      Left = 0
      Top = 0
      Width = 682
      Height = 25
      Color = clBtnFace
      EdgeBorders = [ebTop, ebRight, ebBottom]
      Images = DM.ImageList1
      ParentColor = False
      TabOrder = 1
      object ToolButton1: TToolButton
        Left = 0
        Top = 2
        Width = 17
        Caption = 'ToolButton1'
        Style = tbsSeparator
      end
      object ToolButtonInsert: TToolButton
        Left = 17
        Top = 2
        Caption = 'ToolButtonInsert'
        ImageIndex = 0
        OnClick = ToolButtonInsertClick
      end
      object ToolButtonDelete: TToolButton
        Left = 40
        Top = 2
        Caption = 'ToolButtonDelete'
        ImageIndex = 2
        OnClick = ToolButtonDeleteClick
      end
    end
    object DBPrim: TDBEdit
      Left = 176
      Top = 96
      Width = 417
      Height = 21
      DataField = 'PRIM'
      TabOrder = 2
    end
    object DBNumberDoc: TDBEdit
      Left = 280
      Top = 48
      Width = 73
      Height = 24
      DataField = 'NUMBER_DOC'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
    end
  end
end
