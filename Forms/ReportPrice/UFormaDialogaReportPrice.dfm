object FormaDialogaReportPrice: TFormaDialogaReportPrice
  Left = 265
  Top = 130
  Caption = #1055#1088#1072#1081#1089'-'#1083#1080#1089#1090':'
  ClientHeight = 246
  ClientWidth = 501
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
  OnCreate = FormCreate
  PixelsPerInch = 120
  TextHeight = 16
  object Label1: TLabel
    Left = 10
    Top = 10
    Width = 324
    Height = 64
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Alignment = taCenter
    Caption = #1054#1090#1095#1077#1090' '#1087#1086' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1091' '#1073#1099#1089#1090#1088#1086#1075#1086' '#1074#1099#1079#1086#1074#1072' ('#1084#1077#1085#1102'):'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    WordWrap = True
  end
  object Label4: TLabel
    Left = 10
    Top = 128
    Width = 109
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1055#1086#1076#1088#1072#1079#1076#1077#1083#1077#1085#1080#1077':'
  end
  object NamePodrEdit: TcxButtonEdit
    Left = 123
    Top = 118
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = NamePodrEditPropertiesButtonClick
    TabOrder = 0
    Text = 'NamePodrEdit'
    Width = 361
  end
  object cxButtonClose: TcxButton
    Left = 391
    Top = 186
    Width = 93
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1047#1072#1082#1088#1099#1090#1100
    TabOrder = 1
    OnClick = cxButtonCloseClick
  end
  object cxButtonCreate: TcxButton
    Left = 246
    Top = 186
    Width = 121
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1057#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 2
    OnClick = cxButtonCreateClick
  end
  object GrpBV: TpFIBDataSet
    SelectSQL.Strings = (
      'select  *'
      'from '
      '  SGBVNOM'
      'where IDPOD_GBVNOM=:PARAM_IDPOD'
      'order by NAME_GBVNOM'
      '')
    Transaction = IBTr
    Database = DM.pFIBData
    Left = 320
    Top = 32
    object GrpBVNAME_GBVNOM: TFIBStringField
      FieldName = 'NAME_GBVNOM'
      Size = 50
      EmptyStrToNull = True
    end
    object GrpBVID_GBVNOM: TFIBBCDField
      FieldName = 'ID_GBVNOM'
      Size = 0
      RoundByScale = True
    end
    object GrpBVIDGRP_GBVNOM: TFIBBCDField
      FieldName = 'IDGRP_GBVNOM'
      Size = 0
      RoundByScale = True
    end
    object GrpBVIDPOD_GBVNOM: TFIBBCDField
      FieldName = 'IDPOD_GBVNOM'
      Size = 0
      RoundByScale = True
    end
  end
  object NomBV: TpFIBDataSet
    SelectSQL.Strings = (
      'select  FNAMENOM, IDNOM'
      'from '
      '  SBVNOM'
      'left outer join SNOM on IDNOM_BVNOM=IDNOM'
      'where IDGRP_BVNOM=:PARAM_IDGRP_BVNOM')
    Transaction = IBTr
    Database = DM.pFIBData
    Left = 360
    object NomBVFNAMENOM: TFIBStringField
      FieldName = 'FNAMENOM'
      Size = 100
      EmptyStrToNull = True
    end
    object NomBVIDNOM: TFIBBCDField
      FieldName = 'IDNOM'
      Size = 0
      RoundByScale = True
    end
  end
  object Ed: TpFIBDataSet
    SelectSQL.Strings = (
      'select NAMEED, KFED, ZNACH_PRICE'
      'from '
      '  SED'
      
        'left outer join SPRICE on (IDNOM_PRICE=:PARAM_IDNOM)  AND (IDTYP' +
        'E_PRICE=:PARAM_IDTYPE_PRICE)'
      'where IDNOMED=:PARAM_IDNOM'
      'order by KFED')
    Transaction = IBTr
    Database = DM.pFIBData
    Left = 360
    Top = 32
    object EdNAMEED: TFIBStringField
      FieldName = 'NAMEED'
      Size = 50
      EmptyStrToNull = True
    end
    object EdKFED: TFIBBCDField
      FieldName = 'KFED'
      Size = 3
      RoundByScale = True
    end
    object EdZNACH_PRICE: TFIBBCDField
      FieldName = 'ZNACH_PRICE'
      Size = 2
      RoundByScale = True
    end
  end
  object IBTr: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 320
  end
  object ActionList: TActionList
    Left = 184
    Top = 40
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
    end
  end
end
