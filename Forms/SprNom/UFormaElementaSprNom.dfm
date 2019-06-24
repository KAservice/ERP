object FormaElementaSprNom: TFormaElementaSprNom
  Left = 249
  Top = 132
  Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072
  ClientHeight = 549
  ClientWidth = 581
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
  OnActivate = FormActivate
  OnClose = FormClose
  OnDeactivate = FormDeactivate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 581
    Height = 41
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 2
    object cxButtonPrice: TcxButton
      Left = 332
      Top = 9
      Width = 59
      Height = 25
      Caption = #1062#1077#1085#1099
      TabOrder = 0
      OnClick = cxButtonPriceClick
    end
    object cxButtonEd: TcxButton
      Left = 4
      Top = 9
      Width = 52
      Height = 25
      Caption = #1045#1076#1080#1085#1080#1094#1099
      TabOrder = 1
      OnClick = cxButtonEdClick
    end
    object cxButtonPart: TcxButton
      Left = 55
      Top = 9
      Width = 51
      Height = 25
      Caption = #1055#1072#1088#1090#1080#1080
      TabOrder = 2
      OnClick = cxButtonPartClick
    end
    object cxButtonMod: TcxButton
      Left = 171
      Top = 9
      Width = 55
      Height = 25
      Caption = #1052#1086#1076#1080#1092#1080#1082'.'
      TabOrder = 3
      OnClick = cxButtonModClick
    end
    object cxButtonProd: TcxButton
      Left = 106
      Top = 9
      Width = 65
      Height = 25
      Caption = #1055#1088#1086#1076#1091#1082#1094#1080#1103
      TabOrder = 4
      OnClick = cxButtonProdClick
    end
    object cxButtonSezKF: TcxButton
      Left = 225
      Top = 9
      Width = 55
      Height = 25
      Caption = #1057#1077#1079#1086#1085'. '#1050
      TabOrder = 5
      OnClick = cxButtonSezKFClick
    end
    object cxButtonOpenFormSpiskaSprImportNom: TcxButton
      Left = 280
      Top = 9
      Width = 56
      Height = 25
      Caption = #1048#1084#1087#1086#1088#1090
      TabOrder = 6
      OnClick = cxButtonOpenFormSpiskaSprImportNomClick
    end
    object cxButtonpriceSchedule: TcxButton
      Left = 387
      Top = 9
      Width = 70
      Height = 25
      Caption = #1043#1088#1072#1092#1080#1082' '#1094#1077#1085
      TabOrder = 7
      OnClick = cxButtonpriceScheduleClick
    end
    object cxButtonNachisl: TcxButton
      Left = 456
      Top = 9
      Width = 63
      Height = 25
      Caption = #1053#1072#1095#1080#1089#1083'.'
      TabOrder = 8
      OnClick = cxButtonNachislClick
    end
    object cxButtonAnalog: TcxButton
      Left = 518
      Top = 9
      Width = 55
      Height = 25
      Caption = #1040#1085#1072#1083#1086#1075#1080
      TabOrder = 9
      OnClick = cxButtonAnalogClick
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 513
    Width = 581
    Height = 36
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object cxButtonSave: TcxButton
      Left = 286
      Top = 8
      Width = 75
      Height = 25
      Action = ActionSave
      TabOrder = 0
    end
    object cxButtonOK: TcxButton
      Left = 367
      Top = 8
      Width = 75
      Height = 25
      Action = ActionOK
      TabOrder = 1
    end
    object cxButtonClose: TcxButton
      Left = 448
      Top = 8
      Width = 75
      Height = 25
      Action = ActionClose
      Cancel = True
      TabOrder = 2
    end
    object cxButtonOpenSprNomImage: TcxButton
      Left = 24
      Top = 8
      Width = 82
      Height = 25
      Caption = #1048#1079#1086#1073#1088#1072#1078#1077#1085#1080#1103
      TabOrder = 3
      OnClick = cxButtonOpenSprNomImageClick
    end
    object cxButtonOpenSprNomProperties: TcxButton
      Left = 113
      Top = 8
      Width = 84
      Height = 25
      Caption = #1057#1074#1086#1081#1089#1090#1074#1072
      TabOrder = 4
      OnClick = cxButtonOpenSprNomPropertiesClick
    end
  end
  object cxPageControl1: TcxPageControl
    Left = 0
    Top = 41
    Width = 581
    Height = 472
    ActivePage = cxTabSheet1
    Align = alClient
    TabOrder = 0
    ClientRectBottom = 472
    ClientRectRight = 581
    ClientRectTop = 24
    object cxTabSheet1: TcxTabSheet
      Caption = #1054#1089#1085#1086#1074#1085#1072#1103' (F5)'
      ImageIndex = 0
      object Label9: TLabel
        Left = 41
        Top = 48
        Width = 22
        Height = 13
        Caption = #1058#1080#1087':'
      end
      object Label1: TLabel
        Left = 424
        Top = 36
        Width = 27
        Height = 16
        Caption = #1050#1086#1076':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label12: TLabel
        Left = 312
        Top = 67
        Width = 101
        Height = 16
        Caption = #1040#1088#1090'/'#1089#1077#1088'. '#1085#1086#1084#1077#1088':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label4: TLabel
        Left = 152
        Top = 155
        Width = 122
        Height = 13
        Caption = #1050#1088#1072#1090#1082#1086#1077' '#1085#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
      end
      object Label2: TLabel
        Left = 32
        Top = 96
        Width = 79
        Height = 13
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
      end
      object Label3: TLabel
        Left = 27
        Top = 115
        Width = 118
        Height = 13
        Caption = #1055#1086#1083#1085#1086#1077' '#1085#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
      end
      object NameGrpLabel: TLabel
        Left = 471
        Top = 3
        Width = 71
        Height = 13
        Alignment = taRightJustify
        Caption = 'NameGrpLabel'
      end
      object FNamecxDBTextEdit: TcxDBTextEdit
        Left = 27
        Top = 127
        DataBinding.DataField = 'FNAMENOM'
        Properties.ValidateOnEnter = True
        TabOrder = 4
        OnKeyPress = FNamecxDBTextEditKeyPress
        Width = 515
      end
      object KrNamecxDBTextEdit: TcxDBTextEdit
        Left = 280
        Top = 152
        DataBinding.DataField = 'KRNAMENOM'
        Properties.MaxLength = 40
        TabOrder = 5
        OnKeyDown = KrNamecxDBTextEditKeyDown
        Width = 262
      end
      object NameNomcxDBTextEdit: TcxDBTextEdit
        Left = 128
        Top = 93
        DataBinding.DataField = 'NAMENOM'
        Properties.ValidateOnEnter = True
        TabOrder = 3
        OnKeyPress = NameNomcxDBTextEditKeyPress
        Width = 414
      end
      object ArtcxDBTextEdit: TcxDBTextEdit
        Left = 421
        Top = 66
        DataBinding.DataField = 'ARTNOM'
        TabOrder = 2
        OnKeyDown = ArtcxDBTextEditKeyDown
        Width = 121
      end
      object CodecxDBTextEdit: TcxDBTextEdit
        Left = 457
        Top = 35
        DataBinding.DataField = 'CODENOM'
        TabOrder = 1
        OnKeyDown = CodecxDBTextEditKeyDown
        Width = 85
      end
      object TNomcxDBImageComboBox: TcxDBImageComboBox
        Left = 75
        Top = 45
        RepositoryItem = DM.cxEditRepository1ImageComboBoxTNOM
        DataBinding.DataField = 'TNOM'
        Properties.Items = <>
        TabOrder = 0
        Width = 132
      end
      object GroupBoxFisEd: TGroupBox
        Left = 27
        Top = 333
        Width = 239
        Height = 75
        Caption = #1060#1080#1079#1080#1095#1077#1089#1082#1072#1103' '#1077#1076#1080#1085#1080#1094#1072
        TabOrder = 8
        object CodeFisEdcxDBLabel: TcxDBLabel
          Left = 14
          Top = 54
          DataBinding.DataField = 'CODE_SED'
          Properties.Alignment.Horz = taRightJustify
          Height = 21
          Width = 70
          AnchorX = 84
        end
        object cxLabel8: TcxLabel
          Left = 90
          Top = 54
          Caption = '/'
        end
        object BarCodeFisEdcxDBLabel: TcxDBLabel
          Left = 103
          Top = 54
          DataBinding.DataField = 'SHED'
          Height = 21
          Width = 121
        end
        object cxLabel9: TcxLabel
          Left = 105
          Top = 37
          Caption = #1050#1060'2:'
        end
        object KF2FisEdcxDBLabel: TcxDBLabel
          Left = 139
          Top = 37
          DataBinding.DataField = 'KF2_SED'
          Height = 21
          Width = 80
        end
        object KFFisEdcxDBLabel: TcxDBLabel
          Left = 47
          Top = 37
          DataBinding.DataField = 'KFED'
          Height = 21
          Width = 43
        end
        object cxLabel10: TcxLabel
          Left = 16
          Top = 37
          Caption = #1050#1060'1:'
        end
        object cxButtonAddFisEd: TcxButton
          Left = 176
          Top = 12
          Width = 23
          Height = 23
          Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1085#1086#1074#1091#1102' '#1077#1076#1080#1085#1080#1094#1091
          Glyph.Data = {
            36040000424D3604000000000000360000002800000010000000100000000100
            2000000000000004000000000000000000000000000000000000000000000000
            0000000000000000000000000000445644B35B715AEE546753EE546954EE566C
            56EE495C49D20000000000000000000000000000000000000000000000000000
            0000000000000000000000000000495B49C4B0D9AEFFCCF6C9FFCBF6C8FFB7E1
            B4FF546954E50000000000000000000000000000000000000000000000000000
            0000000000000000000000000000495C49C0B7E1B5FFD6FFD3FFD5FFD2FFBFEB
            BCFF536853E10000000000000000000000000000000000000000000000000000
            0000000000000000000000000000495C49BFB5DFB3FFD4FFD1FFD3FFD0FFBDE9
            BAFF536853E00000000000000000000000000000000000000000000000000000
            0000000000000000000000000000455845C4B5DFB3FFD4FFD1FFD3FFD0FFBDE8
            BAFF516651E30000000000000000000000000000000000000000415241D6576C
            56EE576C56EE566C56EE546954EE607860FBB3DDB1FFD4FFD1FFD3FFD0FFBCE8
            B9FF698369FD546954EE576C56EE576B56EE566B56EE445645D9506550E9C1EE
            BEFFCFFCCCFFCCFCC9FFCCFCCAFFCBFAC8FFCDFCCAFFCFFFCCFFCFFFCCFFCEFD
            CBFFCAF9C7FFCCFCCAFFCCFCCAFFCEFCCBFFC6F3C3FF5A7059ED4F634FE5C5F3
            C2FFD4FFD1FFD1FFCEFFD1FFCEFFD1FFCEFFD0FFCDFFCFFFCCFFCFFFCCFFCFFF
            CCFFD1FFCEFFD1FFCEFFD1FFCEFFD3FFD0FFCAF9C7FF596E58E9516551E5C7F6
            C5FFD7FFD4FFD4FFD0FFD4FFD1FFD4FFD0FFD0FFCDFFCFFFCCFFCFFFCCFFD0FF
            CDFFD3FFD0FFD4FFD1FFD4FFD0FFD6FFD3FFCCFCCAFF5A715AE9556A55F1B1DA
            AEFFBAE2B7FFB7E2B5FFB7E2B4FFB5DFB2FFC7F5C4FFD0FFCDFFD0FFCDFFC9F8
            C6FFB6E1B4FFB7E2B5FFB7E2B5FFB9E2B7FFB3DDB1FF5D745DF5324032933B4A
            3AA43A493AA4394739A4374537A4516751E9B4DEB2FFD4FFD1FFD3FFD0FFBCE8
            B9FF5D755DF4364436A83A493AA4394939A43A493AA433413496000000000000
            0000000000000000000000000000495C49BEB5DFB3FFD4FFD1FFD3FFD0FFBDEA
            BBFF516651E00000000000000000000000000000000000000000000000000000
            00000000000000000000000000004C5F4CC0B5DFB3FFD4FFD1FFD3FFD0FFBDEA
            BBFF536953E10000000000000000000000000000000000000000000000000000
            00000000000000000000000000004C604CC0B7E2B5FFD8FFD5FFD7FFD4FFC1EE
            BEFF546953E10000000000000000000000000000000000000000000000000000
            00000000000000000000000000004E624EC4A6CEA5FFBDE5BBFFBDE5BAFFACD6
            ABFF546B54E50000000000000000000000000000000000000000000000000000
            0000000000000000000000000000445644B05A715AEA596F59E95C745CEF5F77
            5FEF475947D20000000000000000000000000000000000000000}
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
          OnClick = cxButtonAddFisEdClick
        end
        object cxButtonEditFisEd: TcxButton
          Left = 205
          Top = 12
          Width = 23
          Height = 23
          Hint = #1048#1079#1084#1077#1085#1080#1090#1100' '#1087#1072#1088#1072#1084#1077#1090#1088#1099' '#1092#1080#1079#1080#1095#1077#1089#1082#1086#1081' '#1077#1076#1080#1085#1080#1094#1099
          Glyph.Data = {
            36040000424D3604000000000000360000002800000010000000100000000100
            2000000000000004000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000384738868FB1
            8FEA85A485E582A182E57F9E7FE5809E7FE5809E7FE5809E7FE5809E7FE5809E
            7FE5809E7FE57F9E7FE581A081E583A283E58FB18FE93E4E3E90070A071986A5
            86E28EAF8EFF799778FF8EAE8DFF8BAD8AFF8BAD8AFF8BAD8AFF8BAD8AFF8BAD
            8AFF8BAD8AFF8EAE8DFF7C9B7CFF86A686FF8AAA8AEB0B0E0B2200000000212A
            214F9ABE99FE8AAC89FFC9F6C6FFD0FECDFFCEFDCBFFCEFDCBFFCEFDCBFFCDFD
            CBFFCEFDCBFFCDFACAFF8BAE8AFF96BA96FF2731275D00000000000000000000
            00005267529FA5CBA5FFA4CCA2FFD4FFD1FFD0FFCDFFD0FFCDFFD0FFCDFFD0FF
            CDFFD5FFD2FFA8D1A7FFA0C5A0FF5A6F59AD0000000000000000000000000000
            000006070618809E80DDA3C9A3FFBCEABAFFD2FFCFFFCFFFCCFFCFFFCCFFD2FF
            CFFFC1EFBEFFA0C59FFF86A385E7070907200000000000000000000000000000
            0000000000001D261D49A3C6A3FDAAD2A9FFCDFBCAFFD0FFCDFFD0FFCDFFCFFD
            CCFFA9D2A8FFA5C8A5FF212A2157000000000000000000000000000000000000
            000000000000000000004C5F4C98B4DDB4FFB6E3B5FFD1FFCEFFD1FFCEFFB9E6
            B7FFB6DDB5FF546653A600000000000000000000000000000000000000000000
            0000000000000000000004060414809F80DCBBE7BBFFC6F6C4FFC9F9C6FFBCE9
            BCFF8AA889E50608051D00000000000000000000000000000000000000000000
            00000000000000000000000000001F281F4FA7CEA7FEC1F0C0FFC1F1C1FFB1D8
            B0FF242D245D0000000000000000000000000000000000000000000000000000
            00000000000000000000000000000000000047594795C2EDC1FFCAF5C9FF4F62
            4FA4000000000000000000000000000000000000000000000000000000000000
            00000000000000000000000000000000000003040310809F80DF89A989E90406
            0518000000000000000000000000000000000000000000000000000000000000
            000000000000000000000000000000000000000000002029204D232D235A0000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000}
          ParentShowHint = False
          ShowHint = True
          TabOrder = 1
          OnClick = cxButtonEditFisEdClick
        end
        object FisEdcxDBLookupComboBox: TcxDBLookupComboBox
          Left = 3
          Top = 16
          DataBinding.DataField = 'IDFISED_SNOM'
          Properties.DropDownListStyle = lsFixedList
          Properties.KeyFieldNames = 'IDED'
          Properties.ListColumns = <
            item
              FieldName = 'NAMEED'
            end>
          TabOrder = 9
          Width = 167
        end
      end
      object GroupBoxOsnEd: TGroupBox
        Left = 27
        Top = 256
        Width = 239
        Height = 75
        Caption = #1054#1089#1085#1086#1074#1085#1072#1103' '#1077#1076#1080#1085#1080#1094#1072
        TabOrder = 7
        object CodeOsnEdcxDBLabel: TcxDBLabel
          Left = 16
          Top = 54
          DataBinding.DataField = 'CODE_SED'
          Properties.Alignment.Horz = taRightJustify
          Height = 21
          Width = 70
          AnchorX = 86
        end
        object cxLabel5: TcxLabel
          Left = 90
          Top = 54
          Caption = '/'
        end
        object BarCodeOsnEdcxDBLabel: TcxDBLabel
          Left = 103
          Top = 54
          DataBinding.DataField = 'SHED'
          Height = 21
          Width = 121
        end
        object cxLabel6: TcxLabel
          Left = 105
          Top = 37
          Caption = #1050#1060'2:'
        end
        object KF2OsnEdcxDBLabel: TcxDBLabel
          Left = 139
          Top = 37
          DataBinding.DataField = 'KF2_SED'
          Height = 21
          Width = 80
        end
        object KFOsnEdcxDBLabel: TcxDBLabel
          Left = 47
          Top = 37
          DataBinding.DataField = 'KFED'
          Height = 21
          Width = 43
        end
        object cxLabel7: TcxLabel
          Left = 16
          Top = 37
          Caption = #1050#1060'1:'
        end
        object cxButtonAddOsnEd: TcxButton
          Left = 176
          Top = 12
          Width = 23
          Height = 23
          Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1085#1086#1074#1091#1102' '#1077#1076#1080#1085#1080#1094#1091
          Glyph.Data = {
            36040000424D3604000000000000360000002800000010000000100000000100
            2000000000000004000000000000000000000000000000000000000000000000
            0000000000000000000000000000445644B35B715AEE546753EE546954EE566C
            56EE495C49D20000000000000000000000000000000000000000000000000000
            0000000000000000000000000000495B49C4B0D9AEFFCCF6C9FFCBF6C8FFB7E1
            B4FF546954E50000000000000000000000000000000000000000000000000000
            0000000000000000000000000000495C49C0B7E1B5FFD6FFD3FFD5FFD2FFBFEB
            BCFF536853E10000000000000000000000000000000000000000000000000000
            0000000000000000000000000000495C49BFB5DFB3FFD4FFD1FFD3FFD0FFBDE9
            BAFF536853E00000000000000000000000000000000000000000000000000000
            0000000000000000000000000000455845C4B5DFB3FFD4FFD1FFD3FFD0FFBDE8
            BAFF516651E30000000000000000000000000000000000000000415241D6576C
            56EE576C56EE566C56EE546954EE607860FBB3DDB1FFD4FFD1FFD3FFD0FFBCE8
            B9FF698369FD546954EE576C56EE576B56EE566B56EE445645D9506550E9C1EE
            BEFFCFFCCCFFCCFCC9FFCCFCCAFFCBFAC8FFCDFCCAFFCFFFCCFFCFFFCCFFCEFD
            CBFFCAF9C7FFCCFCCAFFCCFCCAFFCEFCCBFFC6F3C3FF5A7059ED4F634FE5C5F3
            C2FFD4FFD1FFD1FFCEFFD1FFCEFFD1FFCEFFD0FFCDFFCFFFCCFFCFFFCCFFCFFF
            CCFFD1FFCEFFD1FFCEFFD1FFCEFFD3FFD0FFCAF9C7FF596E58E9516551E5C7F6
            C5FFD7FFD4FFD4FFD0FFD4FFD1FFD4FFD0FFD0FFCDFFCFFFCCFFCFFFCCFFD0FF
            CDFFD3FFD0FFD4FFD1FFD4FFD0FFD6FFD3FFCCFCCAFF5A715AE9556A55F1B1DA
            AEFFBAE2B7FFB7E2B5FFB7E2B4FFB5DFB2FFC7F5C4FFD0FFCDFFD0FFCDFFC9F8
            C6FFB6E1B4FFB7E2B5FFB7E2B5FFB9E2B7FFB3DDB1FF5D745DF5324032933B4A
            3AA43A493AA4394739A4374537A4516751E9B4DEB2FFD4FFD1FFD3FFD0FFBCE8
            B9FF5D755DF4364436A83A493AA4394939A43A493AA433413496000000000000
            0000000000000000000000000000495C49BEB5DFB3FFD4FFD1FFD3FFD0FFBDEA
            BBFF516651E00000000000000000000000000000000000000000000000000000
            00000000000000000000000000004C5F4CC0B5DFB3FFD4FFD1FFD3FFD0FFBDEA
            BBFF536953E10000000000000000000000000000000000000000000000000000
            00000000000000000000000000004C604CC0B7E2B5FFD8FFD5FFD7FFD4FFC1EE
            BEFF546953E10000000000000000000000000000000000000000000000000000
            00000000000000000000000000004E624EC4A6CEA5FFBDE5BBFFBDE5BAFFACD6
            ABFF546B54E50000000000000000000000000000000000000000000000000000
            0000000000000000000000000000445644B05A715AEA596F59E95C745CEF5F77
            5FEF475947D20000000000000000000000000000000000000000}
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
          OnClick = cxButtonAddOsnEdClick
        end
        object cxButtonEditOsnEd: TcxButton
          Left = 205
          Top = 12
          Width = 23
          Height = 23
          Hint = #1048#1079#1084#1077#1085#1080#1090#1100' '#1087#1072#1088#1072#1084#1077#1090#1088#1099' '#1086#1089#1085#1086#1074#1085#1086#1081' '#1077#1076#1080#1085#1080#1094#1099
          Glyph.Data = {
            36040000424D3604000000000000360000002800000010000000100000000100
            2000000000000004000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000384738868FB1
            8FEA85A485E582A182E57F9E7FE5809E7FE5809E7FE5809E7FE5809E7FE5809E
            7FE5809E7FE57F9E7FE581A081E583A283E58FB18FE93E4E3E90070A071986A5
            86E28EAF8EFF799778FF8EAE8DFF8BAD8AFF8BAD8AFF8BAD8AFF8BAD8AFF8BAD
            8AFF8BAD8AFF8EAE8DFF7C9B7CFF86A686FF8AAA8AEB0B0E0B2200000000212A
            214F9ABE99FE8AAC89FFC9F6C6FFD0FECDFFCEFDCBFFCEFDCBFFCEFDCBFFCDFD
            CBFFCEFDCBFFCDFACAFF8BAE8AFF96BA96FF2731275D00000000000000000000
            00005267529FA5CBA5FFA4CCA2FFD4FFD1FFD0FFCDFFD0FFCDFFD0FFCDFFD0FF
            CDFFD5FFD2FFA8D1A7FFA0C5A0FF5A6F59AD0000000000000000000000000000
            000006070618809E80DDA3C9A3FFBCEABAFFD2FFCFFFCFFFCCFFCFFFCCFFD2FF
            CFFFC1EFBEFFA0C59FFF86A385E7070907200000000000000000000000000000
            0000000000001D261D49A3C6A3FDAAD2A9FFCDFBCAFFD0FFCDFFD0FFCDFFCFFD
            CCFFA9D2A8FFA5C8A5FF212A2157000000000000000000000000000000000000
            000000000000000000004C5F4C98B4DDB4FFB6E3B5FFD1FFCEFFD1FFCEFFB9E6
            B7FFB6DDB5FF546653A600000000000000000000000000000000000000000000
            0000000000000000000004060414809F80DCBBE7BBFFC6F6C4FFC9F9C6FFBCE9
            BCFF8AA889E50608051D00000000000000000000000000000000000000000000
            00000000000000000000000000001F281F4FA7CEA7FEC1F0C0FFC1F1C1FFB1D8
            B0FF242D245D0000000000000000000000000000000000000000000000000000
            00000000000000000000000000000000000047594795C2EDC1FFCAF5C9FF4F62
            4FA4000000000000000000000000000000000000000000000000000000000000
            00000000000000000000000000000000000003040310809F80DF89A989E90406
            0518000000000000000000000000000000000000000000000000000000000000
            000000000000000000000000000000000000000000002029204D232D235A0000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000}
          ParentShowHint = False
          ShowHint = True
          TabOrder = 1
          OnClick = cxButtonEditOsnEdClick
        end
        object OsnEdcxDBLookupComboBox: TcxDBLookupComboBox
          Left = 3
          Top = 16
          DataBinding.DataField = 'IDOSNEDNOM'
          Properties.DropDownListStyle = lsFixedList
          Properties.KeyFieldNames = 'IDED'
          Properties.ListColumns = <
            item
              FieldName = 'NAMEED'
            end>
          TabOrder = 9
          Width = 167
        end
      end
      object GroupBoxBasEd: TGroupBox
        Left = 27
        Top = 179
        Width = 239
        Height = 75
        Caption = #1041#1072#1079#1086#1074#1072#1103' '#1077#1076#1080#1085#1080#1094#1072
        TabOrder = 6
        object NameBasEdcxDBLabel: TcxDBLabel
          Left = 16
          Top = 16
          DataBinding.DataField = 'NAMEED'
          ParentFont = False
          Style.Font.Charset = DEFAULT_CHARSET
          Style.Font.Color = clWindowText
          Style.Font.Height = -12
          Style.Font.Name = 'MS Sans Serif'
          Style.Font.Style = [fsBold]
          Style.IsFontAssigned = True
          Height = 21
          Width = 121
        end
        object CodeBasEdcxDBLabel: TcxDBLabel
          Left = 16
          Top = 54
          DataBinding.DataField = 'CODE_SED'
          Properties.Alignment.Horz = taRightJustify
          Height = 21
          Width = 70
          AnchorX = 86
        end
        object cxLabel2: TcxLabel
          Left = 90
          Top = 54
          Caption = '/'
        end
        object BarCodeBasEdcxDBLabel: TcxDBLabel
          Left = 103
          Top = 54
          DataBinding.DataField = 'SHED'
          Height = 21
          Width = 121
        end
        object cxLabel3: TcxLabel
          Left = 16
          Top = 37
          Caption = #1050#1060'1:'
        end
        object cxLabel4: TcxLabel
          Left = 105
          Top = 37
          Caption = #1050#1060'2:'
        end
        object KFBasEdcxDBLabel: TcxDBLabel
          Left = 47
          Top = 37
          DataBinding.DataField = 'KFED'
          Height = 21
          Width = 43
        end
        object KF2BasEdcxDBLabel: TcxDBLabel
          Left = 139
          Top = 37
          DataBinding.DataField = 'KF2_SED'
          Height = 21
          Width = 80
        end
        object cxButtonEditBasEd: TcxButton
          Left = 176
          Top = 11
          Width = 23
          Height = 23
          Hint = #1048#1079#1084#1077#1085#1080#1090#1100' '#1087#1072#1088#1072#1084#1077#1090#1088#1099' '#1073#1072#1079#1086#1074#1086#1081' '#1077#1076#1080#1085#1080#1094#1099
          Glyph.Data = {
            36040000424D3604000000000000360000002800000010000000100000000100
            2000000000000004000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000384738868FB1
            8FEA85A485E582A182E57F9E7FE5809E7FE5809E7FE5809E7FE5809E7FE5809E
            7FE5809E7FE57F9E7FE581A081E583A283E58FB18FE93E4E3E90070A071986A5
            86E28EAF8EFF799778FF8EAE8DFF8BAD8AFF8BAD8AFF8BAD8AFF8BAD8AFF8BAD
            8AFF8BAD8AFF8EAE8DFF7C9B7CFF86A686FF8AAA8AEB0B0E0B2200000000212A
            214F9ABE99FE8AAC89FFC9F6C6FFD0FECDFFCEFDCBFFCEFDCBFFCEFDCBFFCDFD
            CBFFCEFDCBFFCDFACAFF8BAE8AFF96BA96FF2731275D00000000000000000000
            00005267529FA5CBA5FFA4CCA2FFD4FFD1FFD0FFCDFFD0FFCDFFD0FFCDFFD0FF
            CDFFD5FFD2FFA8D1A7FFA0C5A0FF5A6F59AD0000000000000000000000000000
            000006070618809E80DDA3C9A3FFBCEABAFFD2FFCFFFCFFFCCFFCFFFCCFFD2FF
            CFFFC1EFBEFFA0C59FFF86A385E7070907200000000000000000000000000000
            0000000000001D261D49A3C6A3FDAAD2A9FFCDFBCAFFD0FFCDFFD0FFCDFFCFFD
            CCFFA9D2A8FFA5C8A5FF212A2157000000000000000000000000000000000000
            000000000000000000004C5F4C98B4DDB4FFB6E3B5FFD1FFCEFFD1FFCEFFB9E6
            B7FFB6DDB5FF546653A600000000000000000000000000000000000000000000
            0000000000000000000004060414809F80DCBBE7BBFFC6F6C4FFC9F9C6FFBCE9
            BCFF8AA889E50608051D00000000000000000000000000000000000000000000
            00000000000000000000000000001F281F4FA7CEA7FEC1F0C0FFC1F1C1FFB1D8
            B0FF242D245D0000000000000000000000000000000000000000000000000000
            00000000000000000000000000000000000047594795C2EDC1FFCAF5C9FF4F62
            4FA4000000000000000000000000000000000000000000000000000000000000
            00000000000000000000000000000000000003040310809F80DF89A989E90406
            0518000000000000000000000000000000000000000000000000000000000000
            000000000000000000000000000000000000000000002029204D232D235A0000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000000000000000
            0000000000000000000000000000000000000000000000000000}
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
          OnClick = cxButtonEditBasEdClick
        end
      end
      object cxLabel14: TcxLabel
        Left = 24
        Top = 8
        Caption = #1054#1089#1085#1086#1074#1085#1099#1077' '#1087#1072#1088#1072#1084#1077#1090#1088#1099' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099
        ParentFont = False
        Style.Font.Charset = DEFAULT_CHARSET
        Style.Font.Color = clNavy
        Style.Font.Height = -19
        Style.Font.Name = 'MS Sans Serif'
        Style.Font.Style = [fsBold]
        Style.IsFontAssigned = True
      end
      object GroupBox1: TGroupBox
        Left = 272
        Top = 179
        Width = 270
        Height = 230
        Caption = #1062#1077#1085#1099
        TabOrder = 10
        object ToolBar4: TToolBar
          Left = 2
          Top = 15
          Width = 266
          Height = 28
          Caption = 'ToolBar4'
          Color = clCaptionText
          Images = DM.ImageList1
          ParentColor = False
          TabOrder = 0
          object ToolButton1: TToolButton
            Left = 0
            Top = 0
            Width = 9
            Caption = 'ToolButton1'
            ImageIndex = 3
            Style = tbsSeparator
          end
          object ToolButtonAddPrice: TToolButton
            Left = 9
            Top = 0
            Caption = 'ToolButtonAddPrice'
            ImageIndex = 0
            OnClick = ToolButtonAddPriceClick
          end
          object ToolButtonDeletePrice: TToolButton
            Left = 32
            Top = 0
            Caption = 'ToolButtonDeletePrice'
            ImageIndex = 2
            OnClick = ToolButtonDeletePriceClick
          end
        end
        object cxGrid1: TcxGrid
          Left = 2
          Top = 43
          Width = 266
          Height = 185
          Align = alClient
          TabOrder = 1
          object cxGrid1DBTableView1: TcxGridDBTableView
            NavigatorButtons.ConfirmDelete = False
            DataController.Summary.DefaultGroupSummaryItems = <>
            DataController.Summary.FooterSummaryItems = <>
            DataController.Summary.SummaryGroups = <>
            OptionsBehavior.IncSearch = True
            OptionsSelection.InvertSelect = False
            OptionsView.ColumnAutoWidth = True
            OptionsView.GroupByBox = False
            Styles.Header = DM.cxStyleHeaderTable
            object cxGrid1DBTableView1FL_CHANGE_PRICE: TcxGridDBColumn
              Caption = #1048#1079#1084'.'
              Options.Editing = False
              Styles.Header = DM.cxStyleHeaderTable
              Width = 20
            end
            object cxGrid1DBTableView1NAMETPRICE: TcxGridDBColumn
              Caption = #1058#1080#1087' '#1094#1077#1085
              DataBinding.FieldName = 'NAMETPRICE'
              Styles.Header = DM.cxStyleHeaderTable
              Width = 91
            end
            object cxGrid1DBTableView1NameEd: TcxGridDBColumn
              Caption = #1045#1076'.'
              DataBinding.FieldName = 'IDED_SPRICE'
              PropertiesClassName = 'TcxLookupComboBoxProperties'
              Properties.DropDownListStyle = lsFixedList
              Properties.ImmediatePost = True
              Properties.KeyFieldNames = 'IDED'
              Properties.ListColumns = <
                item
                  FieldName = 'NAMEED'
                end>
              Width = 60
            end
            object cxGrid1DBTableView1ZNACH_PRICE: TcxGridDBColumn
              Caption = #1047#1085#1072#1095#1077#1085#1080#1077
              DataBinding.FieldName = 'ZNACH_PRICE'
              PropertiesClassName = 'TcxCalcEditProperties'
              Properties.DisplayFormat = '0.00'
              Properties.Precision = 15
              Styles.Header = DM.cxStyleHeaderTable
              Width = 93
            end
          end
          object cxGrid1Level1: TcxGridLevel
            GridView = cxGrid1DBTableView1
          end
        end
      end
    end
    object cxTabSheet2: TcxTabSheet
      Caption = #1044#1086#1087#1086#1083#1085#1080#1090#1077#1083#1100#1085#1086' (F6)'
      ImageIndex = 1
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object Label6: TLabel
        Left = 294
        Top = 138
        Width = 40
        Height = 13
        Caption = #1060#1080#1088#1084#1072':'
      end
      object Label19: TLabel
        Left = 95
        Top = 138
        Width = 38
        Height = 13
        Caption = '% '#1053#1044#1057':'
      end
      object Label20: TLabel
        Left = 25
        Top = 241
        Width = 25
        Height = 13
        Caption = #1043#1058#1044':'
      end
      object Label21: TLabel
        Left = 295
        Top = 165
        Width = 39
        Height = 13
        Caption = #1057#1090#1088#1072#1085#1072':'
      end
      object Label18: TLabel
        Left = 19
        Top = 5
        Width = 240
        Height = 13
        Caption = #1044#1086#1087#1086#1083#1085#1080#1090#1077#1083#1100#1085#1072#1103' '#1080#1085#1092#1086#1088#1084#1072#1094#1080#1103' '#1086' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1077':'
      end
      object Label22: TLabel
        Left = 19
        Top = 164
        Width = 99
        Height = 13
        Caption = #1042#1080#1076' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099':'
      end
      object Label23: TLabel
        Left = 363
        Top = 326
        Width = 49
        Height = 13
        Caption = #1057#1082#1080#1076#1082#1072' 1:'
      end
      object Label24: TLabel
        Left = 364
        Top = 353
        Width = 49
        Height = 13
        Caption = #1057#1082#1080#1076#1082#1072' 2:'
      end
      object Label25: TLabel
        Left = 363
        Top = 380
        Width = 49
        Height = 13
        Caption = #1057#1082#1080#1076#1082#1072' 3:'
      end
      object Label26: TLabel
        Left = 25
        Top = 326
        Width = 157
        Height = 13
        Caption = #1058#1080#1087' '#1079#1085#1072#1095#1077#1085#1080#1103'  '#1089#1088#1086#1082#1072' '#1075#1086#1076#1085#1086#1089#1090#1080':'
      end
      object Label27: TLabel
        Left = 49
        Top = 353
        Width = 133
        Height = 13
        Caption = #1047#1085#1072#1095#1077#1085#1080#1077' '#1089#1088#1086#1082#1072' '#1075#1086#1076#1085#1086#1089#1090#1080':'
      end
      object MinOstcxDBCalcEdit: TcxDBCalcEdit
        Left = 402
        Top = 265
        DataBinding.DataField = 'MINOSTNOM'
        Properties.AssignedValues.DisplayFormat = True
        TabOrder = 9
        OnKeyPress = MinOstcxDBCalcEditKeyPress
        Width = 121
      end
      object cxLabel1: TcxLabel
        Left = 273
        Top = 269
        Caption = #1052#1080#1085#1080#1084#1072#1083#1100#1085#1099#1081' '#1086#1089#1090#1072#1090#1086#1082':'
      end
      object DescrcxDBMemo: TcxDBMemo
        Left = 19
        Top = 19
        DataBinding.DataField = 'DESCR_SNOM'
        TabOrder = 0
        Height = 110
        Width = 520
      end
      object NameFirmcxDBButtonEdit: TcxDBButtonEdit
        Left = 341
        Top = 135
        DataBinding.DataField = 'NAMEFIRM'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.ReadOnly = True
        Properties.OnButtonClick = cxDBButtonEdit1PropertiesButtonClick
        TabOrder = 3
        Width = 198
      end
      object NameCountrycxDBButtonEdit: TcxDBButtonEdit
        Left = 341
        Top = 162
        DataBinding.DataField = 'NAME_SCOUNTRY'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameCountrycxDBButtonEditPropertiesButtonClick
        TabOrder = 4
        Width = 198
      end
      object GTDcxDBTextEdit: TcxDBTextEdit
        Left = 79
        Top = 238
        DataBinding.DataField = 'GTDNOM'
        TabOrder = 7
        OnKeyDown = GTDcxDBTextEditKeyDown
        Width = 460
      end
      object VidNomcxDBButtonEdit: TcxDBButtonEdit
        Left = 19
        Top = 183
        DataBinding.DataField = 'NAME_SVIDNOM'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.OnButtonClick = VidNomcxDBButtonEditPropertiesButtonClick
        TabOrder = 2
        Width = 219
      end
      object Skidka1cxDBCalcEdit: TcxDBCalcEdit
        Left = 418
        Top = 323
        DataBinding.DataField = 'SKIDKA1_SNOM'
        Properties.AssignedValues.DisplayFormat = True
        TabOrder = 14
        Width = 121
      end
      object Skidka2cxDBCalcEdit: TcxDBCalcEdit
        Left = 418
        Top = 350
        DataBinding.DataField = 'SKIDKA2_SNOM'
        Properties.AssignedValues.DisplayFormat = True
        TabOrder = 15
        Width = 121
      end
      object Skidka3cxDBCalcEdit: TcxDBCalcEdit
        Left = 418
        Top = 377
        DataBinding.DataField = 'SKIDKA3_SNOM'
        Properties.AssignedValues.DisplayFormat = True
        TabOrder = 16
        Width = 121
      end
      object SrokGodncxDBCalcEdit: TcxDBCalcEdit
        Left = 188
        Top = 350
        DataBinding.DataField = 'SRGODN_SNOM'
        TabOrder = 12
        Width = 121
      end
      object NDScxDBImageComboBox: TcxDBImageComboBox
        Left = 144
        Top = 135
        RepositoryItem = DM.cxEditRepository1ImageComboBoxNDS
        DataBinding.DataField = 'STNDSNOM'
        Properties.Items = <>
        TabOrder = 1
        Width = 94
      end
      object TypeSrokaGodncxDBImageComboBox: TcxDBImageComboBox
        Left = 188
        Top = 323
        RepositoryItem = DM.cxEditRepository1ImageComboBoxTypeSrokaGodn
        DataBinding.DataField = 'TYPESRGODN_SNOM'
        Properties.Items = <>
        TabOrder = 11
        Width = 121
      end
      object GodenDocxDBDateEdit: TcxDBDateEdit
        Left = 188
        Top = 377
        DataBinding.DataField = 'GODEN_DO_SNOM'
        Properties.Kind = ckDateTime
        TabOrder = 13
        Width = 121
      end
      object cxLabel11: TcxLabel
        Left = 130
        Top = 378
        Caption = #1043#1086#1076#1077#1085' '#1076#1086':'
      end
      object SuppliercxDBButtonEdit: TcxDBButtonEdit
        Left = 341
        Top = 213
        DataBinding.DataField = 'SUPPLIER_NAME'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.OnButtonClick = SuppliercxDBButtonEditPropertiesButtonClick
        TabOrder = 6
        Width = 198
      end
      object ProducercxDBButtonEdit: TcxDBButtonEdit
        Left = 341
        Top = 186
        DataBinding.DataField = 'PRODUCER_NAME'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.OnButtonClick = ProducercxDBButtonEditPropertiesButtonClick
        TabOrder = 5
        Width = 198
      end
      object cxLabel12: TcxLabel
        Left = 248
        Top = 187
        Caption = #1055#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1100':'
      end
      object cxLabel13: TcxLabel
        Left = 245
        Top = 214
        Caption = #1054#1089#1085'. '#1087#1086#1089#1090#1072#1074#1097#1080#1082':'
      end
      object PogrcxDBCalcEdit: TcxDBCalcEdit
        Left = 402
        Top = 291
        DataBinding.DataField = 'POGR_SNOM'
        TabOrder = 10
        OnKeyPress = PogrcxDBCalcEditKeyPress
        Width = 121
      end
      object cxLabel15: TcxLabel
        Left = 319
        Top = 292
        Caption = #1055#1086#1075#1088#1077#1096#1085#1086#1089#1090#1100':'
      end
      object WarrantycxDBSpinEdit: TcxDBSpinEdit
        Left = 188
        Top = 407
        DataBinding.DataField = 'WARRANTY_SNOM'
        TabOrder = 17
        Width = 121
      end
      object TransportcxDBCheckBox: TcxDBCheckBox
        Left = 319
        Top = 400
        Caption = #1073#1077#1089#1087#1083#1072#1090#1085#1072#1103' '#1076#1086#1089#1090#1072#1074#1082#1072
        DataBinding.DataField = 'FL_TRANSPORT_SNOM'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        TabOrder = 18
        Width = 148
      end
      object CreditcxDBCheckBox: TcxDBCheckBox
        Left = 474
        Top = 400
        Caption = #1082#1088#1077#1076#1080#1090
        DataBinding.DataField = 'FL_CREDIT_SNOM'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        TabOrder = 19
        Width = 65
      end
      object cxLabel16: TcxLabel
        Left = 96
        Top = 411
        Caption = #1043#1072#1088#1072#1085#1090#1080#1103' ('#1084#1077#1089'.):'
      end
      object NameBrandcxDBButtonEdit: TcxDBButtonEdit
        Left = 79
        Top = 265
        DataBinding.DataField = 'NAME_SBRAND'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameBrandcxDBButtonEditPropertiesButtonClick
        TabOrder = 8
        Width = 170
      end
      object cxLabel17: TcxLabel
        Left = 25
        Top = 266
        Caption = #1041#1088#1077#1085#1076':'
      end
      object cxDBCheckBoxAddInSprOborud: TcxDBCheckBox
        Left = 319
        Top = 414
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1076#1086#1073#1072#1074#1083#1103#1090#1100' '#1074' '#1089#1087#1088'. "'#1054#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077'"'
        DataBinding.DataField = 'FL_ADD_IN_SOBORUD_SNOM'
        Properties.ValueChecked = 1
        Properties.ValueGrayed = 0
        Properties.ValueUnchecked = 0
        TabOrder = 20
        Width = 220
      end
      object FlDvRegcxDBCheckBox: TcxDBCheckBox
        Left = 319
        Top = 427
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1076#1074#1086#1081#1085#1086#1081' '#1091#1095#1077#1090' '
        DataBinding.DataField = 'FL_DVREG_SNOM'
        Properties.ValueChecked = 1
        Properties.ValueGrayed = 0
        Properties.ValueUnchecked = 0
        TabOrder = 21
        Width = 220
      end
    end
    object cxTabSheet3: TcxTabSheet
      Caption = 'cxTabSheet3'
      ImageIndex = 2
      object cxDBButtonEditNAME_SDEPARTMENT: TcxDBButtonEdit
        Left = 191
        Top = 112
        DataBinding.DataField = 'NAME_SDEPARTMENT'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end
          item
            Caption = 'X'
            Kind = bkText
          end>
        Properties.OnButtonClick = cxDBButtonEditNAME_SDEPARTMENTPropertiesButtonClick
        TabOrder = 0
        Width = 266
      end
      object cxLabel18: TcxLabel
        Left = 68
        Top = 112
        Caption = #1054#1090#1076#1077#1083':'
      end
      object cxLabel19: TcxLabel
        Left = 68
        Top = 161
        Caption = #1053#1072#1073#1086#1088' '#1089#1074#1086#1081#1089#1090#1074':'
      end
      object cxDBButtonEditNAME_SPROPNABOR: TcxDBButtonEdit
        Left = 191
        Top = 160
        DataBinding.DataField = 'NAME_SPROPNABOR'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end
          item
            Caption = 'X'
            Kind = bkText
          end>
        TabOrder = 3
        Width = 266
      end
      object cxLabel20: TcxLabel
        Left = 68
        Top = 209
        Caption = #1053#1072#1073#1086#1088' '#1080#1079#1086#1073#1088#1072#1078#1077#1085#1080#1081':'
      end
      object cxDBButtonEditNAME_SVIDIMAGE_NABOR: TcxDBButtonEdit
        Left = 191
        Top = 208
        DataBinding.DataField = 'NAME_SVIDIMAGE_NABOR'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end
          item
            Caption = 'X'
            Kind = bkText
          end>
        TabOrder = 5
        Width = 266
      end
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 288
    Top = 120
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
      OnExecute = ActionOpenHelpExecute
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
    object ActionSave: TAction
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      ImageIndex = 55
      OnExecute = ActionSaveExecute
    end
  end
end
