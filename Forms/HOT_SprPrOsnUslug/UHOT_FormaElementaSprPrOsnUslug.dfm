object HOT_FormaElementaSprPrOsnUslug: THOT_FormaElementaSprPrOsnUslug
  Left = 385
  Top = 51
  Caption = #1069#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1055#1088#1077#1081#1089#1082#1091#1088#1072#1085#1090' '#1086#1089#1085#1086#1074#1085#1099#1093' '#1091#1089#1083#1091#1075'"'
  ClientHeight = 250
  ClientWidth = 742
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
    Top = 192
    Width = 742
    Height = 58
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 0
    object cxButtonOK: TcxButton
      Left = 528
      Top = 18
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionOK
      TabOrder = 0
    end
    object cxButtonClose: TcxButton
      Left = 628
      Top = 18
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      TabOrder = 1
    end
    object cxButtonSave: TcxButton
      Left = 428
      Top = 18
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionSave
      TabOrder = 2
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 742
    Height = 192
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 1
    object Label3: TLabel
      Left = 10
      Top = 129
      Width = 101
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1058#1080#1087' '#1087#1086#1089#1077#1083#1077#1085#1080#1103':'
    end
    object Label2: TLabel
      Left = 10
      Top = 73
      Width = 74
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1050#1072#1090#1077#1075#1086#1088#1080#1103'::'
    end
    object Label1: TLabel
      Left = 404
      Top = 73
      Width = 132
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1059#1089#1083#1091#1075#1072' '#1087#1088#1086#1078#1080#1074#1072#1085#1080#1103':'
    end
    object Label4: TLabel
      Left = 404
      Top = 129
      Width = 147
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1059#1089#1083#1091#1075#1072' '#1073#1088#1086#1085#1080#1088#1086#1074#1072#1085#1080#1103':'
    end
    object Label5: TLabel
      Left = 10
      Top = 36
      Width = 424
      Height = 26
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1090#1088#1086#1082#1072' '#1087#1088#1077#1081#1089#1082#1091#1088#1072#1085#1090#1072' '#1086#1089#1085#1086#1074#1085#1099#1093' '#1091#1089#1083#1091#1075':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold, fsUnderline]
      ParentFont = False
    end
    object NameCatcxDBButtonEdit: TcxDBButtonEdit
      Left = 10
      Top = 96
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAME_HOT_SCATNOM'
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameCatcxDBButtonEditPropertiesButtonClick
      TabOrder = 0
      Width = 365
    end
    object NameTypePosNomcxDBButtonEdit: TcxDBButtonEdit
      Left = 10
      Top = 153
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAME_HOT_STYPEPOS'
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameTypePosNomcxDBButtonEditPropertiesButtonClick
      TabOrder = 1
      Width = 365
    end
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 742
      Height = 29
      Caption = 'ToolBar1'
      EdgeBorders = [ebLeft, ebTop, ebRight, ebBottom]
      Images = DM.ImageList1
      TabOrder = 2
      object ToolButton1: TToolButton
        Left = 0
        Top = 0
        Caption = 'ToolButtonAdd'
        ImageIndex = 0
      end
      object ToolButton2: TToolButton
        Left = 23
        Top = 0
        Caption = 'ToolButtonDelete'
        ImageIndex = 2
      end
    end
    object NameNomPrcxDBButtonEdit: TcxDBButtonEdit
      Left = 404
      Top = 96
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAMENOMPR'
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameNomPrcxDBButtonEditPropertiesButtonClick
      TabOrder = 3
      Width = 316
    end
    object NameNomBrcxDBButtonEdit: TcxDBButtonEdit
      Left = 404
      Top = 153
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAMENOMBR'
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameNomBrcxDBButtonEditPropertiesButtonClick
      TabOrder = 4
      Width = 316
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
