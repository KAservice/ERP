object FormaElementaSprARM: TFormaElementaSprARM
  Left = 405
  Top = 171
  Caption = #1069#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1040#1056#1052'"'
  ClientHeight = 461
  ClientWidth = 513
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 120
  TextHeight = 16
  object Panel1: TPanel
    Left = 0
    Top = 411
    Width = 513
    Height = 50
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 0
    ExplicitTop = 368
    ExplicitWidth = 500
    object cxButtonSave: TcxButton
      Left = 191
      Top = 10
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionSave
      TabOrder = 0
    end
    object cxButtonOborud: TcxButton
      Left = 74
      Top = 10
      Width = 109
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1054#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077
      TabOrder = 1
      OnClick = cxButtonOborudClick
    end
    object cxButtonOK: TcxButton
      Left = 290
      Top = 10
      Width = 93
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionOK
      TabOrder = 2
    end
    object cxButtonClose: TcxButton
      Left = 390
      Top = 10
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      TabOrder = 3
    end
  end
  object cxPageControl1: TcxPageControl
    Left = 0
    Top = 0
    Width = 513
    Height = 411
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    ActivePage = cxTabSheet1
    Align = alClient
    TabOrder = 1
    ExplicitWidth = 500
    ExplicitHeight = 368
    ClientRectBottom = 411
    ClientRectRight = 513
    ClientRectTop = 27
    object cxTabSheet1: TcxTabSheet
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1054#1089#1085#1086#1074#1085#1099#1077
      ImageIndex = 0
      object Label2: TLabel
        Left = 315
        Top = 20
        Width = 32
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1050#1086#1076':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label4: TLabel
        Left = 30
        Top = 281
        Width = 70
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1048#1085#1092'. '#1073#1072#1079#1072':'
      end
      object Label3: TLabel
        Left = 39
        Top = 246
        Width = 41
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1050#1072#1089#1089#1072':'
      end
      object Label7: TLabel
        Left = 39
        Top = 197
        Width = 60
        Height = 20
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1057#1082#1083#1072#1076':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -17
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label6: TLabel
        Left = 30
        Top = 158
        Width = 64
        Height = 20
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1060#1080#1088#1084#1072':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -17
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label11: TLabel
        Left = 20
        Top = 118
        Width = 109
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1055#1086#1076#1088#1072#1079#1076#1077#1083#1077#1085#1080#1077':'
      end
      object Label1: TLabel
        Left = 20
        Top = 79
        Width = 102
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
      end
      object CodecxDBTextEdit: TcxDBTextEdit
        Left = 364
        Top = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'CODE_SARM'
        TabOrder = 0
        OnKeyDown = CodecxDBTextEditKeyDown
        Width = 118
      end
      object NamecxDBTextEdit: TcxDBTextEdit
        Left = 138
        Top = 75
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NAME_SARM'
        TabOrder = 1
        OnKeyDown = NamecxDBTextEditKeyDown
        Width = 344
      end
      object NamePodcxDBButtonEdit: TcxDBButtonEdit
        Left = 138
        Top = 108
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NAMEPOD'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.ReadOnly = True
        Properties.OnButtonClick = NamePodcxDBButtonEditPropertiesButtonClick
        TabOrder = 2
        Width = 344
      end
      object NameFirmcxDBButtonEdit: TcxDBButtonEdit
        Left = 138
        Top = 154
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NAMEFIRM'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameFirmcxDBButtonEditPropertiesButtonClick
        TabOrder = 3
        Width = 344
      end
      object NameSkladcxDBButtonEdit: TcxDBButtonEdit
        Left = 138
        Top = 196
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NAMESKLAD'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameSkladcxDBButtonEditPropertiesButtonClick
        TabOrder = 4
        Width = 344
      end
      object NameKKMcxDBButtonEdit: TcxDBButtonEdit
        Left = 137
        Top = 242
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NAMEKKM'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameKKMcxDBButtonEditPropertiesButtonClick
        TabOrder = 5
        Width = 345
      end
      object NameInfBasecxDBButtonEdit: TcxDBButtonEdit
        Left = 138
        Top = 281
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NAME_SINFBASE_OBMEN'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameInfBasecxDBButtonEditPropertiesButtonClick
        TabOrder = 6
        Width = 344
      end
      object cxLabel4: TcxLabel
        Left = 1
        Top = 328
        Caption = #1050#1072#1090#1077#1075#1086#1088#1080#1103' '#1091#1089#1090#1088#1086#1081#1089#1090#1074':'
      end
      object NameActivecategorycxDBButtonEdit: TcxDBButtonEdit
        Left = 162
        Top = 327
        DataBinding.DataField = 'NAME_REM_SACTCATEGORY'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end
          item
            Caption = 'X'
            Kind = bkText
          end>
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameActivecategorycxDBButtonEditPropertiesButtonClick
        TabOrder = 8
        Width = 320
      end
    end
    object cxTabSheet2: TcxTabSheet
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099
      ImageIndex = 1
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object StrParcxDBMemo: TcxDBMemo
        Left = 0
        Top = 0
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Align = alClient
        DataBinding.DataField = 'STRPAR_SARM'
        TabOrder = 0
        Height = 384
        Width = 513
      end
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 184
    Top = 40
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
      OnExecute = ActionOpenHelpExecute
    end
    object ActionClose: TAction
      Caption = #1047#1072#1082#1088#1099#1090#1100
      ImageIndex = 53
      OnExecute = ActionCloseExecute
    end
    object ActionOK: TAction
      Caption = #1054#1050
      ImageIndex = 54
      OnExecute = ActionOKExecute
    end
    object ActionSave: TAction
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      ImageIndex = 55
      OnExecute = ActionSaveExecute
    end
  end
end
