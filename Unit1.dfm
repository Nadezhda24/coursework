object Form1: TForm1
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1050#1072#1083#1100#1082#1091#1083#1103#1090#1086#1088
  ClientHeight = 360
  ClientWidth = 314
  Color = clInactiveBorder
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 112
    Top = 64
    Width = 3
    Height = 13
  end
  object Label2: TLabel
    Left = 87
    Top = 43
    Width = 83
    Height = 18
    Caption = 'accuracy :'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
  end
  object TB_field: TEdit
    Left = 17
    Top = 13
    Width = 280
    Height = 21
    Enabled = False
    TabOrder = 0
  end
  object Button1: TButton
    Left = 17
    Top = 267
    Width = 70
    Height = 50
    Caption = '0'
    Font.Charset = ANSI_CHARSET
    Font.Color = clBlack
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = Button1Click
  end
  object BT_showResult: TButton
    Tag = 21
    Left = 107
    Top = 317
    Width = 190
    Height = 27
    Caption = 'show'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = BT_showResultClick
  end
  object Button3: TButton
    Tag = 18
    Left = 157
    Top = 267
    Width = 70
    Height = 50
    Caption = '='
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = Button1Click
  end
  object Button4: TButton
    Tag = 17
    Left = 227
    Top = 267
    Width = 70
    Height = 50
    Caption = '+'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = Button1Click
  end
  object Button5: TButton
    Tag = 1
    Left = 17
    Top = 217
    Width = 70
    Height = 50
    Caption = '1'
    Font.Charset = ANSI_CHARSET
    Font.Color = clBlack
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = Button1Click
  end
  object Button6: TButton
    Tag = 2
    Left = 87
    Top = 217
    Width = 70
    Height = 50
    Caption = '2'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    OnClick = Button1Click
  end
  object Button7: TButton
    Tag = 3
    Left = 157
    Top = 217
    Width = 70
    Height = 50
    Caption = '3'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    OnClick = Button1Click
  end
  object Button8: TButton
    Tag = 16
    Left = 227
    Top = 217
    Width = 70
    Height = 50
    Caption = '-'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 8
    OnClick = Button1Click
  end
  object Button9: TButton
    Tag = 4
    Left = 17
    Top = 167
    Width = 70
    Height = 50
    Caption = '4'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 9
    OnClick = Button1Click
  end
  object Button10: TButton
    Tag = 5
    Left = 87
    Top = 167
    Width = 70
    Height = 50
    Caption = '5'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 10
    OnClick = Button1Click
  end
  object Button11: TButton
    Tag = 6
    Left = 157
    Top = 167
    Width = 70
    Height = 50
    Caption = '6'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 11
    OnClick = Button1Click
  end
  object Button12: TButton
    Tag = 15
    Left = 227
    Top = 167
    Width = 70
    Height = 50
    Caption = 'x'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 12
    OnClick = Button1Click
  end
  object Button13: TButton
    Tag = 7
    Left = 17
    Top = 117
    Width = 70
    Height = 50
    Caption = '7'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 13
    OnClick = Button1Click
  end
  object Button16: TButton
    Tag = 14
    Left = 227
    Top = 117
    Width = 70
    Height = 50
    Caption = '/'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 14
    OnClick = Button1Click
  end
  object Button17: TButton
    Tag = 10
    Left = 17
    Top = 67
    Width = 70
    Height = 50
    Caption = '('
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 15
    OnClick = Button1Click
  end
  object Button18: TButton
    Tag = 11
    Left = 87
    Top = 67
    Width = 70
    Height = 50
    Caption = ')'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 16
    OnClick = Button1Click
  end
  object Button19: TButton
    Tag = 12
    Left = 157
    Top = 67
    Width = 70
    Height = 50
    Caption = 'div'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 17
    OnClick = Button1Click
  end
  object Button20: TButton
    Tag = 13
    Left = 227
    Top = 67
    Width = 70
    Height = 50
    Caption = '<'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 18
    OnClick = Button1Click
  end
  object Button2: TButton
    Tag = 8
    Left = 87
    Top = 117
    Width = 70
    Height = 50
    Caption = '8'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 19
    OnClick = Button1Click
  end
  object Button14: TButton
    Tag = 9
    Left = 157
    Top = 117
    Width = 70
    Height = 50
    Caption = '9'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 20
    OnClick = Button1Click
  end
  object Button15: TButton
    Tag = 19
    Left = 87
    Top = 267
    Width = 70
    Height = 50
    Caption = '.'
    Font.Charset = ANSI_CHARSET
    Font.Color = clBlack
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 21
    OnClick = Button1Click
  end
  object TB_accuracy: TEdit
    Left = 176
    Top = 40
    Width = 121
    Height = 21
    Color = clBtnHighlight
    Enabled = False
    TabOrder = 22
  end
  object Button21: TButton
    Tag = 20
    Left = 17
    Top = 317
    Width = 90
    Height = 27
    Caption = 'accuracy '
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 23
    OnClick = Button21Click
  end
end
