object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'DBReader'
  ClientHeight = 504
  ClientWidth = 840
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesigned
  OnCreate = FormCreate
  DesignSize = (
    840
    504)
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 472
    Width = 74
    Height = 16
    Caption = 'Choose table'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 300
    Top = 200
    Width = 241
    Height = 48
    Caption = 'Choose table!'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -40
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 355
    Top = 470
    Width = 87
    Height = 16
    Caption = 'Column Search'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object DBGrid1: TDBGrid
    Left = 5
    Top = 5
    Width = 830
    Height = 444
    Margins.Left = 0
    Margins.Top = 0
    Margins.Right = 0
    Margins.Bottom = 0
    Anchors = [akLeft, akTop, akRight, akBottom]
    DataSource = DataSource1
    DrawingStyle = gdsGradient
    FixedColor = clWhite
    Options = [dgEditing, dgAlwaysShowEditor, dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
  end
  object DBNavigator1: TDBNavigator
    Left = 5
    Top = 441
    Width = 830
    Height = 25
    Margins.Left = 0
    Margins.Top = 0
    Margins.Right = 0
    Margins.Bottom = 0
    DataSource = DataSource1
    Anchors = [akLeft, akTop, akRight, akBottom]
    TabOrder = 1
    ExplicitWidth = 900
  end
  object Button1: TButton
    Left = 717
    Top = 468
    Width = 113
    Height = 23
    Margins.Left = 0
    Margins.Top = 0
    Margins.Right = 0
    Margins.Bottom = 0
    Caption = 'Search'
    TabOrder = 2
    OnClick = Button1Click
  end
  object ComboBox1: TComboBox
    Left = 445
    Top = 469
    Width = 145
    Height = 21
    Margins.Left = 0
    Margins.Top = 0
    Margins.Right = 0
    Margins.Bottom = 0
    TabOrder = 3
  end
  object Edit1: TEdit
    Left = 593
    Top = 469
    Width = 121
    Height = 21
    TabOrder = 4
  end
  object Edit2: TEdit
    Left = 88
    Top = 469
    Width = 121
    Height = 21
    TabOrder = 5
  end
  object Button2: TButton
    Left = 212
    Top = 469
    Width = 75
    Height = 22
    Margins.Left = 0
    Margins.Top = 0
    Margins.Right = 0
    Margins.Bottom = 0
    Caption = 'Sumbit'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    OnClick = Button2Click
  end
  object MainMenu1: TMainMenu
    Left = 8
    Top = 40
    object OpenDatabase1: TMenuItem
      Caption = 'File'
      object Open1: TMenuItem
        Caption = 'Open'
        OnClick = Open1Click
      end
      object Close2: TMenuItem
        Caption = 'Close'
        OnClick = Close2Click
      end
    end
    object Close1: TMenuItem
      Caption = 'Close'
      OnClick = Close1Click
    end
  end
  object ADOConnection1: TADOConnection
    Provider = 'MSDASQL.1'
    Left = 48
    Top = 40
  end
  object DataSource1: TDataSource
    DataSet = ADOQuery1
    Left = 88
    Top = 40
  end
  object OpenDialog1: TOpenDialog
    Left = 168
    Top = 40
  end
  object ADOQuery1: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    Left = 128
    Top = 40
  end
end
