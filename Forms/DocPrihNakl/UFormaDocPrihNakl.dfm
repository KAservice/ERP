object FormaDocPrihNakl: TFormaDocPrihNakl
  Left = 290
  Top = 119
  Caption = #1044#1086#1082#1091#1084#1077#1085#1090' "'#1055#1088#1080#1093#1086#1076#1085#1072#1103' '#1085#1072#1082#1083#1072#1076#1085#1072#1103'"'
  ClientHeight = 603
  ClientWidth = 849
  Color = clBtnFace
  Constraints.MinWidth = 848
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  PopupMenu = PopupMenu1
  Position = poScreenCenter
  Visible = True
  OnActivate = FormActivate
  OnClose = FormClose
  OnDeactivate = FormDeactivate
  PixelsPerInch = 120
  TextHeight = 16
  object Panel2: TPanel
    Left = 0
    Top = 507
    Width = 849
    Height = 96
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object DBTextFNameUser: TDBText
      Left = 20
      Top = 10
      Width = 164
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      AutoSize = True
      DataField = 'FNAME_USER'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -18
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object ProsmotrLabel: TLabel
      Left = 20
      Top = 30
      Width = 155
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1090#1086#1083#1100#1082#1086' '#1087#1088#1086#1089#1084#1086#1090#1088
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -18
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object cxButtonPrint: TcxButton
      Left = 230
      Top = 49
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionPrint
      TabOrder = 0
    end
    object cxButtonSave: TcxButton
      Left = 330
      Top = 49
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionSave
      TabOrder = 1
    end
    object cxButtonDvReg: TcxButton
      Left = 430
      Top = 49
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionDvReg
      TabOrder = 2
    end
    object cxButtonOK: TcxButton
      Left = 529
      Top = 49
      Width = 93
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionOK
      TabOrder = 3
    end
    object cxButtonClose: TcxButton
      Left = 629
      Top = 49
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      TabOrder = 4
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 289
    Width = 0
    Height = 218
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 2
  end
  object Panel4: TPanel
    Left = 847
    Top = 289
    Width = 2
    Height = 218
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 3
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 849
    Height = 289
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 45
      Top = 97
      Width = 281
      Height = 26
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1088#1080#1093#1086#1076#1085#1072#1103' '#1085#1072#1082#1083#1072#1076#1085#1072#1103'  '#8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 493
      Top = 123
      Width = 40
      Height = 32
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1086#1090' '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -28
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label3: TLabel
      Left = 16
      Top = 260
      Width = 86
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077':'
    end
    object Label4: TLabel
      Left = 23
      Top = 193
      Width = 75
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1086#1089#1090#1072#1074#1097#1080#1082':'
    end
    object Label5: TLabel
      Left = 36
      Top = 69
      Width = 47
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1060#1080#1088#1084#1072':'
    end
    object Label6: TLabel
      Left = 482
      Top = 43
      Width = 43
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1082#1083#1072#1076':'
    end
    object Label7: TLabel
      Left = 470
      Top = 193
      Width = 152
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1058#1080#1087' '#1094#1077#1085' '#1087#1088#1080#1086#1073#1088#1077#1090#1077#1085#1080#1103':'
    end
    object RTPriceLabel: TLabel
      Left = 484
      Top = 220
      Width = 138
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1058#1080#1087' '#1094#1077#1085' '#1088#1077#1072#1083#1080#1079#1072#1094#1080#1080':'
    end
    object ToolBar2: TToolBar
      Left = 0
      Top = 0
      Width = 849
      Height = 30
      Color = clBtnFace
      EdgeBorders = [ebTop, ebRight, ebBottom]
      Images = DM.ImageList1
      ParentColor = False
      TabOrder = 12
      object ToolButton1: TToolButton
        Left = 0
        Top = 0
        Width = 17
        Caption = 'ToolButton1'
        Style = tbsSeparator
      end
      object ToolButtonInsert: TToolButton
        Left = 17
        Top = 0
        Action = ActionAddString
        ParentShowHint = False
        PopupMenu = PopupMenu1
        ShowHint = True
      end
      object ToolButtonPodbor: TToolButton
        Left = 40
        Top = 0
        Caption = 'ToolButtonPodbor'
        ImageIndex = 14
        OnClick = ToolButtonPodborClick
      end
      object ToolButton4: TToolButton
        Left = 63
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1074#1089#1077' '#1090#1086#1074#1072#1088#1099' '#1080#1079' '#1074#1099#1073#1088#1072#1085#1085#1086#1081' '#1075#1088#1091#1087#1087#1099
        Caption = 'ToolButton4'
        ImageIndex = 34
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButton4Click
      end
      object ToolButtonDelete: TToolButton
        Left = 86
        Top = 0
        Action = ActionDeleteString
        ParentShowHint = False
        PopupMenu = PopupMenu1
        ShowHint = True
      end
      object ToolButton2: TToolButton
        Left = 109
        Top = 0
        Width = 171
        Caption = 'ToolButton2'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object UpdatePriceDocPoNacToolButton: TToolButton
        Left = 280
        Top = 0
        Hint = #1054#1073#1085#1086#1074#1080#1090#1100' '#1094#1077#1085#1099' '#1076#1086#1082#1091#1084#1077#1085#1090#1072' '#1074' '#1089#1086#1086#1090#1074#1077#1090#1089#1090#1074#1080#1080' '#1089' '#1085#1072#1094#1077#1085#1082#1086#1081' '#1087#1086' '#1075#1088#1091#1087#1087#1072#1084
        Caption = 'UpdatePriceDocPoNacToolButton'
        ImageIndex = 41
        ParentShowHint = False
        ShowHint = True
        OnClick = UpdatePriceDocPoNacToolButtonClick
      end
      object ToolButtonUpdatePrice: TToolButton
        Left = 303
        Top = 0
        Hint = 
          #1054#1073#1085#1086#1074#1080#1090#1100' '#1074#1089#1077' '#1094#1077#1085#1099' '#1074' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1077' '#1079#1072' '#1073#1072#1079#1086#1074#1099#1077' '#1077#1076#1080#1085#1080#1094#1099' '#1080#1079#1084#1077#1088#1077#1085#1080#1103' '#1085#1072' ' +
          #1086#1089#1085#1086#1074#1072#1085#1080#1080' '#1085#1072#1094#1077#1085#1082#1080' '#1087#1086' '#1075#1088#1091#1087#1087#1072#1084
        Caption = 'ToolButtonUpdatePrice'
        ImageIndex = 41
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonUpdatePriceClick
      end
      object ToolButtonCheckPriceNaRoznSklade: TToolButton
        Left = 326
        Top = 0
        Hint = #1055#1088#1086#1074#1077#1088#1080#1090#1100' '#1094#1077#1085#1099' '#1085#1072' '#1088#1086#1079#1085#1080#1095#1085#1086#1084' '#1089#1082#1083#1072#1076#1077
        Caption = 'ToolButtonCheckPriceNaRoznSklade'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonCheckPriceNaRoznSkladeClick
      end
      object ToolButtonShowSUM1: TToolButton
        Left = 349
        Top = 0
        Hint = #1055#1086#1082#1072#1079#1072#1090#1100' '#1089#1091#1084#1084#1091' '#1076#1083#1103' '#1088#1072#1089#1095#1077#1090#1072' '#1094#1077#1085
        Caption = 'ToolButtonShowSUM1'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        Style = tbsCheck
        OnClick = ToolButtonShowSUM1Click
      end
      object ToolButtonUpdatePriceBasEd: TToolButton
        Left = 372
        Top = 0
        Hint = 
          #1054#1073#1085#1086#1074#1080#1090#1100' '#1094#1077#1085#1099' '#1087#1088#1080#1086#1073#1088#1077#1090#1077#1085#1080#1103' '#1080' '#1088#1077#1072#1083#1080#1079#1072#1094#1080#1080' '#1074' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1077' '#1079#1072' '#1073#1072#1079#1086#1074#1099#1077 +
          ' '#1077#1076#1080#1085#1080#1094#1099' '#1080#1079#1084#1077#1088#1077#1085#1080#1103' '#1085#1072' '#1086#1089#1085#1086#1074#1077' '#1094#1077#1085#1099' '#1076#1086#1082#1091#1084#1077#1085#1090#1072
        Caption = 'ToolButtonUpdatePriceBasEd'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonUpdatePriceBasEdClick
      end
      object ToolButton3: TToolButton
        Left = 395
        Top = 0
        Width = 8
        Caption = 'ToolButton3'
        ImageIndex = 4
        Style = tbsSeparator
      end
      object ToolButtonExtModule: TToolButton
        Left = 403
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
        Caption = 'ToolButtonExtModule'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButton5: TToolButton
        Left = 426
        Top = 0
        Action = ActionEditNom
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButton6: TToolButton
        Left = 449
        Top = 0
        Action = ActionEditEd
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonUpdateGtdSpr: TToolButton
        Left = 472
        Top = 0
        Hint = #1054#1073#1085#1086#1074#1080#1090#1100' '#1043#1058#1044' '#1074' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1077' "'#1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072'" '#1080#1079' '#1076#1086#1082#1091#1084#1077#1085#1090#1072
        Caption = 'ToolButtonUpdateGtdSpr'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonUpdateGtdSprClick
      end
      object ToolButtonMoveInDocPer: TToolButton
        Left = 495
        Top = 0
        Hint = #1055#1077#1088#1077#1085#1077#1089#1090#1080' '#1074#1099#1076#1077#1083#1077#1085#1085#1099#1077' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099' '#1074' '#1085#1086#1074#1086#1077' '#1055#1077#1088#1077#1084#1077#1097#1077#1085#1080#1077
        Caption = 'ToolButtonMoveInDocPer'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonMoveInDocPerClick
      end
      object ToolButtonSetFlagDvUchetAddOborud: TToolButton
        Left = 518
        Top = 0
        Hint = 
          #1059#1089#1090#1072#1085#1086#1074#1080#1090#1100' '#1074' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1077' '#1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072' '#1092#1083#1072#1075#1080' '#1044#1086#1073#1072#1074#1083#1103#1090#1100' '#1074' '#1089#1087#1088#1072#1074#1086#1095#1085 +
          #1080#1082' '#1054#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077' '#1080' '#1044#1074#1086#1081#1085#1086#1081' '#1091#1095#1077#1090' '#1091' '#1074#1099#1076#1077#1083#1077#1085#1085#1099#1093' '#1087#1086#1079#1080#1094#1080#1081
        Caption = 'ToolButtonSetFlagDvUchetAddOborud'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonSetFlagDvUchetAddOborudClick
      end
      object ToolButtonSetAddOborud: TToolButton
        Left = 541
        Top = 0
        Hint = 
          #1059#1089#1090#1072#1085#1086#1074#1080#1090#1100' '#1074' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1077' '#1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072' '#1092#1083#1072#1075#1080' '#1044#1086#1073#1072#1074#1083#1103#1090#1100' '#1074' '#1089#1087#1088#1072#1074#1086#1095#1085 +
          #1080#1082' '#1054#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077' '#1091' '#1074#1099#1076#1077#1083#1077#1085#1085#1099#1093' '#1087#1086#1079#1080#1094#1080#1081
        Caption = 'ToolButtonSetAddOborud'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonSetAddOborudClick
      end
      object ToolButtonSetDvUchet: TToolButton
        Left = 564
        Top = 0
        Hint = 
          #1059#1089#1090#1072#1085#1086#1074#1080#1090#1100' '#1074' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1077' '#1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072' '#1092#1083#1072#1075' '#1044#1074#1086#1081#1085#1086#1081' '#1091#1095#1077#1090' '#1091' '#1074#1099#1076#1077#1083#1077 +
          #1085#1085#1099#1093' '#1087#1086#1079#1080#1094#1080#1081
        Caption = 'ToolButtonSetDvUchet'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonSetDvUchetClick
      end
    end
    object PrimcxDBTextEdit: TcxDBTextEdit
      Left = 110
      Top = 257
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'PRIMDOC'
      TabOrder = 9
      OnKeyDown = PrimcxDBTextEditKeyDown
      Width = 496
    end
    object TypeRPriceComboBox: TcxComboBox
      Left = 630
      Top = 217
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Properties.DropDownListStyle = lsFixedList
      Properties.OnChange = TypeRPriceComboBoxPropertiesChange
      TabOrder = 11
      Width = 216
    end
    object TypePriceComboBox: TcxComboBox
      Left = 622
      Top = 188
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Properties.DropDownListStyle = lsFixedList
      Properties.OnChange = TypePriceComboBoxPropertiesChange
      TabOrder = 10
      Width = 216
    end
    object NameKlientcxDBButtonEdit: TcxDBButtonEdit
      Left = 106
      Top = 190
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAMEKLIENT'
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 13
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameKlientcxDBButtonEditPropertiesButtonClick
      TabOrder = 8
      Width = 336
    end
    object NumDoccxDBTextEdit: TcxDBTextEdit
      Left = 385
      Top = 131
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NUMDOC'
      TabOrder = 3
      OnKeyDown = NumDoccxDBTextEditKeyDown
      Width = 100
    end
    object PosDoccxDBDateEdit: TcxDBDateEdit
      Left = 541
      Top = 131
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'POSDOC'
      Properties.Kind = ckDateTime
      TabOrder = 4
      OnKeyDown = PosDoccxDBDateEditKeyDown
      Width = 164
    end
    object NameFirmcxDBButtonEdit: TcxDBButtonEdit
      Left = 98
      Top = 65
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
      TabOrder = 1
      Width = 336
    end
    object NameInfBasecxDBButtonEdit: TcxDBButtonEdit
      Left = 98
      Top = 38
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
      TabOrder = 0
      Width = 336
    end
    object cxLabel1: TcxLabel
      Left = 20
      Top = 39
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1048#1085#1092'. '#1073#1072#1079#1072':'
    end
    object NameSkladcxDBButtonEdit: TcxDBButtonEdit
      Left = 532
      Top = 38
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
      TabOrder = 2
      Width = 306
    end
    object EditPropPartcxButton: TcxButton
      Left = 746
      Top = 118
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1072#1088#1090#1080#1103
      TabOrder = 14
      OnClick = EditPropPartcxButtonClick
    end
    object PosDocPostcxDBDateEdit: TcxDBDateEdit
      Left = 689
      Top = 156
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'POSDOCPOST_DPRN'
      Properties.Kind = ckDateTime
      TabOrder = 7
      OnKeyPress = PosDocPostcxDBDateEditKeyPress
      Width = 149
    end
    object NumDocPostcxDBTextEdit: TcxDBTextEdit
      Left = 519
      Top = 156
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NUMDOCPOST_DPRN'
      TabOrder = 6
      OnKeyPress = NumDocPostcxDBTextEditKeyPress
      Width = 137
    end
    object cxLabel2: TcxLabel
      Left = 347
      Top = 157
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1044#1086#1082#1091#1084#1077#1085#1090' '#1087#1086#1089#1090#1072#1074#1097#1080#1082#1072' '#8470
    end
    object cxLabel3: TcxLabel
      Left = 663
      Top = 163
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1086#1090
    end
    object cxLabel9: TcxLabel
      Left = 442
      Top = 63
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1041#1080#1079#1085#1077#1089' '#1086#1087#1077#1088#1072#1094#1080#1103':'
    end
    object NameBusinessOpercxDBButtonEdit: TcxDBButtonEdit
      Left = 566
      Top = 62
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAME_SBUSINESS_OPER'
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
      Properties.OnButtonClick = NameBusinessOpercxDBButtonEditPropertiesButtonClick
      TabOrder = 18
      Width = 272
    end
    object NameProjectcxDBButtonEdit: TcxDBButtonEdit
      Left = 566
      Top = 87
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAME_SPROJECT'
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
      Properties.OnButtonClick = NameProjectcxDBButtonEditPropertiesButtonClick
      TabOrder = 19
      Width = 272
    end
    object cxLabel4: TcxLabel
      Left = 508
      Top = 88
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1088#1086#1077#1082#1090':'
    end
    object PrefiksNumcxDBTextEdit: TcxDBTextEdit
      Left = 232
      Top = 131
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'PREFIKS_NUM_GALLDOC'
      TabOrder = 5
      Width = 145
    end
    object OtvHrancxDBCheckBox: TcxDBCheckBox
      Left = 649
      Top = 263
      Caption = #1086#1090#1074'. '#1093#1088#1072#1085#1077#1085#1080#1077
      DataBinding.DataField = 'FL_OTV_HRAN_DPRN'
      Properties.ValueChecked = 1
      Properties.ValueUnchecked = 0
      TabOrder = 21
      Width = 121
    end
    object OtchetPostcxDBCheckBox: TcxDBCheckBox
      Left = 648
      Top = 241
      Caption = #1086#1090#1095#1077#1090' '#1087#1086#1089#1090#1072#1074#1097#1080#1082#1091
      DataBinding.DataField = 'FL_TREB_OTCHET_DPRN'
      Properties.ValueChecked = 1
      Properties.ValueUnchecked = 0
      TabOrder = 22
      Width = 169
    end
  end
  object TablecxPageControl: TcxPageControl
    Left = 0
    Top = 289
    Width = 847
    Height = 218
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    ActivePage = MaincxTabSheet
    Align = alClient
    TabOrder = 4
    ClientRectBottom = 218
    ClientRectRight = 847
    ClientRectTop = 27
    object MaincxTabSheet: TcxTabSheet
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1054#1089#1085#1086#1074#1085#1072#1103' (F5)'
      ImageIndex = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object cxGrid1: TcxGrid
        Left = 0
        Top = 0
        Width = 847
        Height = 191
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Align = alClient
        TabOrder = 0
        object cxGrid1DBTableView1: TcxGridDBTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.Options = [dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding, dcoImmediatePost]
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <
            item
              Kind = skSum
              Column = cxGrid1DBTableView1SUMPRNT
            end
            item
              Kind = skSum
              Column = cxGrid1DBTableView1RSUM_DPRNT
            end>
          DataController.Summary.SummaryGroups = <>
          OptionsBehavior.GoToNextCellOnEnter = True
          OptionsBehavior.IncSearch = True
          OptionsSelection.InvertSelect = False
          OptionsSelection.MultiSelect = True
          OptionsView.CellAutoHeight = True
          OptionsView.ColumnAutoWidth = True
          OptionsView.Footer = True
          Styles.Footer = DM.cxStyleHeaderTable
          Styles.Header = DM.cxStyleHeaderTable
          object cxGrid1DBTableView1RECNO: TcxGridDBColumn
            Caption = #8470
            DataBinding.FieldName = 'RECNO'
            Options.Editing = False
            Styles.Header = DM.cxStyleHeaderTable
            Width = 35
          end
          object cxGrid1DBTableView1CODENOM: TcxGridDBColumn
            Caption = #1050#1086#1076
            DataBinding.FieldName = 'CODENOM'
            PropertiesClassName = 'TcxLabelProperties'
            Width = 55
          end
          object cxGrid1DBTableView1ARTNOM: TcxGridDBColumn
            Caption = #1040#1088#1090#1080#1082#1091#1083
            DataBinding.FieldName = 'ARTNOM'
            PropertiesClassName = 'TcxLabelProperties'
            Width = 56
          end
          object cxGrid1DBTableView1NAMENOM: TcxGridDBColumn
            Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072
            DataBinding.FieldName = 'NAMENOM'
            PropertiesClassName = 'TcxButtonEditProperties'
            Properties.Buttons = <
              item
                Default = True
                Kind = bkEllipsis
              end>
            Properties.ReadOnly = True
            Properties.OnButtonClick = cxGrid1DBTableView1NAMENOMPropertiesButtonClick
            Styles.Header = DM.cxStyleHeaderTable
            Width = 196
          end
          object cxGrid1DBTableView1KOLPRNT: TcxGridDBColumn
            Caption = #1050#1086#1083'.'
            DataBinding.FieldName = 'KOLPRNT'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.Precision = 15
            Styles.Header = DM.cxStyleHeaderTable
            Width = 33
          end
          object cxGrid1DBTableView1NAMEED: TcxGridDBColumn
            Caption = #1045#1076#1080#1085#1080#1094#1072
            DataBinding.FieldName = 'NAMEED'
            PropertiesClassName = 'TcxButtonEditProperties'
            Properties.Buttons = <
              item
                Default = True
                Kind = bkEllipsis
              end>
            Properties.ReadOnly = True
            Properties.OnButtonClick = cxGrid1DBTableView1NAMEEDPropertiesButtonClick
            Styles.Header = DM.cxStyleHeaderTable
            Width = 45
          end
          object cxGrid1DBTableView1KFPRNT: TcxGridDBColumn
            Caption = #1050
            DataBinding.FieldName = 'KFPRNT'
            Options.Editing = False
            Styles.Header = DM.cxStyleHeaderTable
            Width = 38
          end
          object cxGrid1DBTableView1SHED: TcxGridDBColumn
            Caption = #1064#1050
            DataBinding.FieldName = 'SHED'
            PropertiesClassName = 'TcxLabelProperties'
            Width = 57
          end
          object cxGrid1DBTableView1SUM1: TcxGridDBColumn
            Caption = #1044#1083#1103' '#1088#1072#1089#1095#1077#1090#1072
            DataBinding.ValueType = 'Float'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.Precision = 15
            Properties.OnValidate = cxGrid1DBTableView1SUM1PropertiesValidate
            Width = 59
          end
          object cxGrid1DBTableView1PRICEPRNT: TcxGridDBColumn
            Caption = #1062#1077#1085#1072
            DataBinding.FieldName = 'PRICEPRNT'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.Precision = 15
            Styles.Header = DM.cxStyleHeaderTable
            Width = 54
          end
          object cxGrid1DBTableView1SUMPRNT: TcxGridDBColumn
            Caption = #1057#1091#1084#1084#1072
            DataBinding.FieldName = 'SUMPRNT'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.Precision = 15
            Styles.Header = DM.cxStyleHeaderTable
            Width = 55
          end
          object cxGrid1DBTableView1NAC_DPRNT: TcxGridDBColumn
            Caption = '%'
            DataBinding.FieldName = 'NAC_DPRNT'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.OnValidate = cxGrid1DBTableView1NAC_DPRNTPropertiesValidate
            Styles.Header = DM.cxStyleHeaderTable
            Width = 30
          end
          object cxGrid1DBTableView1RPRICE_DPRNT: TcxGridDBColumn
            Caption = #1056#1086#1079#1085'. '#1094#1077#1085#1072
            DataBinding.FieldName = 'RPRICE_DPRNT'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.Precision = 15
            Styles.Header = DM.cxStyleHeaderTable
            Width = 68
          end
          object cxGrid1DBTableView1RSUM_DPRNT: TcxGridDBColumn
            Caption = #1056#1086#1079#1085'. '#1089#1091#1084#1084#1072
            DataBinding.FieldName = 'RSUM_DPRNT'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.Precision = 15
            Styles.Header = DM.cxStyleHeaderTable
            Width = 64
          end
          object cxGrid1DBTableView1IDNOMPRNT: TcxGridDBColumn
            DataBinding.FieldName = 'IDNOMPRNT'
            Visible = False
          end
          object cxGrid1DBTableView1IDEDPRNT: TcxGridDBColumn
            DataBinding.FieldName = 'IDEDPRNT'
            Visible = False
          end
        end
        object cxGrid1Level1: TcxGridLevel
          GridView = cxGrid1DBTableView1
        end
      end
    end
    object AdditionallycxTabSheet: TcxTabSheet
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1044#1086#1087#1086#1083#1085'. (F6)'
      ImageIndex = 1
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object cxGrid2: TcxGrid
        Left = 0
        Top = 0
        Width = 847
        Height = 191
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Align = alClient
        TabOrder = 0
        object cxGrid2DBTableView1: TcxGridDBTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <>
          DataController.Summary.SummaryGroups = <>
          OptionsView.ColumnAutoWidth = True
          Styles.Header = DM.cxStyleHeaderTable
          object cxGrid2DBTableView1RECNO: TcxGridDBColumn
            Caption = #8470
            DataBinding.FieldName = 'RECNO'
            Width = 34
          end
          object cxGrid2DBTableView1NAMENOM: TcxGridDBColumn
            Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072
            DataBinding.FieldName = 'NAMENOM'
            Width = 137
          end
          object cxGrid2DBTableView1KOLPRNT: TcxGridDBColumn
            Caption = #1050#1086#1083'.'
            DataBinding.FieldName = 'KOLPRNT'
            Width = 36
          end
          object cxGrid2DBTableView1KFPRNT: TcxGridDBColumn
            Caption = #1050#1060
            DataBinding.FieldName = 'KFPRNT'
            Width = 37
          end
          object cxGrid2DBTableView1NAMEED: TcxGridDBColumn
            Caption = #1045#1076#1080#1085#1080#1094#1072
            DataBinding.FieldName = 'NAMEED'
            Width = 58
          end
          object cxGrid2DBTableView1SRGODNPART: TcxGridDBColumn
            Caption = #1057#1088#1086#1082' '#1075#1086#1076#1085#1086#1089#1090#1080
            DataBinding.FieldName = 'SRGODNPART'
            PropertiesClassName = 'TcxDateEditProperties'
            Properties.Kind = ckDateTime
            Width = 88
          end
          object cxGrid2DBTableView1GTDPART: TcxGridDBColumn
            Caption = #1043#1058#1044
            DataBinding.FieldName = 'GTDPART'
            Width = 164
          end
          object cxGrid2DBTableView1SERTPART: TcxGridDBColumn
            Caption = #1057#1077#1088#1090#1080#1092#1080#1082#1072#1090
            DataBinding.FieldName = 'SERTPART'
            Width = 132
          end
        end
        object cxGrid2DBBandedTableView1: TcxGridDBBandedTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.Options = [dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding, dcoImmediatePost]
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <>
          DataController.Summary.SummaryGroups = <>
          OptionsView.ColumnAutoWidth = True
          OptionsView.BandCaptionsInColumnAlternateCaption = True
          Styles.Header = DM.cxStyleHeaderTable
          Bands = <
            item
            end>
          object cxGrid2DBBandedTableView1RECNO: TcxGridDBBandedColumn
            Caption = #8470
            DataBinding.FieldName = 'RECNO'
            Options.Editing = False
            Width = 34
            Position.BandIndex = 0
            Position.ColIndex = 0
            Position.RowIndex = 0
          end
          object cxGrid2DBBandedTableView1NAMENOM: TcxGridDBBandedColumn
            Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072
            DataBinding.FieldName = 'NAMENOM'
            Options.Editing = False
            Width = 162
            Position.BandIndex = 0
            Position.ColIndex = 1
            Position.RowIndex = 0
          end
          object cxGrid2DBBandedTableView1KOLPRNT: TcxGridDBBandedColumn
            Caption = #1050#1086#1083'.'
            DataBinding.FieldName = 'KOLPRNT'
            Options.Editing = False
            Width = 34
            Position.BandIndex = 0
            Position.ColIndex = 2
            Position.RowIndex = 0
          end
          object cxGrid2DBBandedTableView1KFPRNT: TcxGridDBBandedColumn
            Caption = #1050#1060
            DataBinding.FieldName = 'KFPRNT'
            Options.Editing = False
            Width = 35
            Position.BandIndex = 0
            Position.ColIndex = 3
            Position.RowIndex = 0
          end
          object cxGrid2DBBandedTableView1NAMEED: TcxGridDBBandedColumn
            Caption = #1045#1076#1080#1085#1080#1094#1072
            DataBinding.FieldName = 'NAMEED'
            Options.Editing = False
            Width = 74
            Position.BandIndex = 0
            Position.ColIndex = 4
            Position.RowIndex = 0
          end
          object cxGrid2DBBandedTableView1SRGODNPART: TcxGridDBBandedColumn
            Caption = #1057#1088#1086#1082' '#1075#1086#1076#1085#1086#1089#1090#1080
            DataBinding.FieldName = 'SRGODNPART'
            PropertiesClassName = 'TcxDateEditProperties'
            Properties.Kind = ckDateTime
            Width = 80
            Position.BandIndex = 0
            Position.ColIndex = 5
            Position.RowIndex = 0
          end
          object cxGrid2DBBandedTableView1GTDPART: TcxGridDBBandedColumn
            Caption = #1043#1058#1044
            DataBinding.FieldName = 'GTDPART'
            Width = 152
            Position.BandIndex = 0
            Position.ColIndex = 6
            Position.RowIndex = 0
          end
          object cxGrid2DBBandedTableView1SERTPART: TcxGridDBBandedColumn
            Caption = #1057#1077#1088#1090#1080#1092#1080#1082#1072#1090
            DataBinding.FieldName = 'SERTPART'
            Width = 115
            Position.BandIndex = 0
            Position.ColIndex = 7
            Position.RowIndex = 0
          end
        end
        object cxGrid2Level1: TcxGridLevel
          GridView = cxGrid2DBBandedTableView1
        end
      end
    end
  end
  object PopupMenu1: TPopupMenu
    Left = 616
    Top = 392
    object AddNewString: TMenuItem
      Caption = #1053#1086#1074#1072#1103' '#1089#1090#1088#1086#1082#1072
      ShortCut = 45
      OnClick = AddNewStringClick
    end
    object DeleteString: TMenuItem
      Caption = #1059#1076#1072#1083#1080#1090#1100' '#1089#1090#1088#1086#1082#1091
      ShortCut = 46
      OnClick = DeleteStringClick
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
    object ActionAddString: TAction
      Caption = 'ActionAddString'
      ImageIndex = 0
      ShortCut = 45
      OnExecute = ActionAddStringExecute
    end
    object ActionDeleteString: TAction
      Caption = 'ActionDeleteString'
      ImageIndex = 2
      ShortCut = 46
      OnExecute = ActionDeleteStringExecute
    end
    object ActionSetMainTabSheet: TAction
      Caption = 'ActionSetMainTabSheet'
      ShortCut = 116
      OnExecute = ActionSetMainTabSheetExecute
    end
    object ActionSetAdditionallyTabSheet: TAction
      Caption = 'ActionSetAdditionallyTabSheet'
      ShortCut = 117
      OnExecute = ActionSetAdditionallyTabSheetExecute
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
    object ActionDvReg: TAction
      Caption = #1055#1088#1086#1074#1077#1089#1090#1080
      ImageIndex = 56
      OnExecute = ActionDvRegExecute
    end
    object ActionSave: TAction
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      ImageIndex = 55
      OnExecute = ActionSaveExecute
    end
    object ActionPrint: TAction
      Caption = #1055#1077#1095#1072#1090#1100
      ImageIndex = 43
      OnExecute = ActionPrintExecute
    end
    object ActionEditNom: TAction
      Caption = 'ActionEditNom'
      Hint = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100' '#1087#1072#1088#1072#1084#1077#1090#1088#1099' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099
      ImageIndex = 45
      ShortCut = 118
      OnExecute = ActionEditNomExecute
    end
    object ActionEditEd: TAction
      Caption = 'ActionEditEd'
      Hint = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100' '#1087#1072#1088#1072#1084#1077#1090#1088#1099' '#1077#1076#1080#1085#1080#1094#1099
      ImageIndex = 45
      ShortCut = 119
      OnExecute = ActionEditEdExecute
    end
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 384
    Top = 16
  end
end
