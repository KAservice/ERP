object ArmOf: TArmOf
  Left = 284
  Top = 101
  Caption = #1040#1056#1052' '#1086#1092#1080#1094#1080#1072#1085#1090#1072
  ClientHeight = 742
  ClientWidth = 962
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIForm
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  WindowState = wsMaximized
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 120
  TextHeight = 16
  object StatusBar: TStatusBar
    Left = 0
    Top = 723
    Width = 962
    Height = 19
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Panels = <
      item
        Width = 100
      end
      item
        Width = 300
      end
      item
        Width = 50
      end
      item
        Width = 50
      end
      item
        Width = 50
      end
      item
        Width = 50
      end>
    ExplicitTop = 719
    ExplicitWidth = 782
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 962
    Height = 64
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    AutoSize = True
    TabOrder = 1
    object BitBtnOpenStrobject: TBitBtn
      Left = 199
      Top = 1
      Width = 98
      Height = 62
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1054#1073#1098#1077#1082#1090#1099
      DoubleBuffered = True
      ParentDoubleBuffered = False
      TabOrder = 0
      OnClick = BitBtnOpenStrObjectClick
    end
    object BitBtnExit: TBitBtn
      Left = 857
      Top = 1
      Width = 98
      Height = 62
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1042#1099#1093#1086#1076
      DoubleBuffered = True
      ParentDoubleBuffered = False
      TabOrder = 1
      OnClick = BitBtnExitClick
    end
    object Button1: TButton
      Left = 101
      Top = 1
      Width = 98
      Height = 62
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1072#1088#1086#1083#1100
      TabOrder = 2
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 2
      Top = 1
      Width = 99
      Height = 62
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1041#1083#1086#1082#1080#1088'.'
      TabOrder = 3
      OnClick = Button2Click
    end
    object BitBtnCreateCheck: TBitBtn
      Left = 297
      Top = 1
      Width = 98
      Height = 62
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionOpenCheck
      Caption = #1063#1077#1082' '#1050#1050#1052
      DoubleBuffered = True
      ParentDoubleBuffered = False
      TabOrder = 4
    end
    object ButtonPrintXReport: TButton
      Left = 561
      Top = 1
      Width = 97
      Height = 62
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = 'X -'#1086#1090#1095#1077#1090
      TabOrder = 5
      OnClick = ButtonPrintXReportClick
    end
    object ButtonPrintZReport: TButton
      Left = 658
      Top = 1
      Width = 100
      Height = 62
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = 'Z-'#1086#1090#1095#1077#1090
      TabOrder = 6
      OnClick = ButtonPrintZReportClick
    end
    object ButtonSumma: TButton
      Left = 758
      Top = 1
      Width = 99
      Height = 62
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1091#1084#1084#1072
      TabOrder = 7
      OnClick = ButtonSummaClick
    end
    object ButtonReports: TButton
      Left = 463
      Top = 1
      Width = 97
      Height = 62
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1054#1090#1095#1077#1090#1099
      TabOrder = 8
      OnClick = ButtonReportsClick
    end
  end
  object ActionList1: TActionList
    Left = 248
    Top = 152
    object ActionOpenCheck: TAction
      Caption = #1063#1077#1082' '#1050#1050#1052
      OnExecute = ActionOpenCheckExecute
    end
    object ActionOpenHelp: TAction
      Caption = #1057#1087#1088#1072#1074#1082#1072
      ShortCut = 112
      OnExecute = ActionOpenHelpExecute
    end
    object ActionNo: TAction
      Caption = 'ActionNo'
    end
  end
  object ApplicationEvents1: TApplicationEvents
    OnIdle = ApplicationEvents1Idle
    Left = 560
    Top = 360
  end
end
