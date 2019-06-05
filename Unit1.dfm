object Form1: TForm1
  Left = 205
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  ClientHeight = 577
  ClientWidth = 444
  Color = clInactiveBorder
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 246
    Top = 217
    Width = 3
    Height = 13
  end
  object Label2: TLabel
    Left = 208
    Top = 182
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
  object Label3: TLabel
    Left = 11
    Top = 13
    Width = 50
    Height = 27
    Caption = 'DEC :'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
  end
  object TB_field_hex: TEdit
    Left = 81
    Top = 56
    Width = 350
    Height = 21
    TabOrder = 0
    OnKeyPress = TB_field_hexKeyPress
  end
  object Button1: TButton
    Left = 81
    Top = 417
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
    Left = 176
    Top = 467
    Width = 185
    Height = 50
    Caption = 'detailed result'
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
    Left = 221
    Top = 417
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
    Left = 291
    Top = 417
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
    Left = 81
    Top = 367
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
    Left = 151
    Top = 367
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
    Left = 221
    Top = 367
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
    Left = 291
    Top = 367
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
    Left = 81
    Top = 317
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
    Left = 151
    Top = 317
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
    Left = 221
    Top = 317
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
    Left = 291
    Top = 317
    Width = 70
    Height = 50
    Caption = '*'
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
    Left = 81
    Top = 267
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
    Left = 291
    Top = 267
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
    Left = 81
    Top = 217
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
    Left = 151
    Top = 217
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
    Left = 221
    Top = 217
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
    Left = 361
    Top = 217
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
    Left = 151
    Top = 267
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
    Left = 221
    Top = 267
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
    Left = 151
    Top = 417
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
    Left = 297
    Top = 179
    Width = 134
    Height = 21
    Color = clBtnHighlight
    Enabled = False
    TabOrder = 22
  end
  object Button21: TButton
    Tag = 20
    Left = 81
    Top = 467
    Width = 96
    Height = 50
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
  object TB_field_dec: TEdit
    Left = 81
    Top = 83
    Width = 350
    Height = 21
    TabOrder = 24
    OnKeyPress = TB_field_hexKeyPress
  end
  object TB_field_oct: TEdit
    Left = 81
    Top = 110
    Width = 350
    Height = 21
    TabOrder = 25
    OnKeyPress = TB_field_hexKeyPress
  end
  object TB_field_bin: TEdit
    Left = 81
    Top = 137
    Width = 350
    Height = 21
    TabOrder = 26
    OnKeyPress = TB_field_hexKeyPress
  end
  object Button22: TButton
    Tag = 22
    Left = 291
    Top = 217
    Width = 70
    Height = 50
    Caption = '%'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 27
    OnClick = Button1Click
  end
  object Button27: TButton
    Tag = 31
    Left = 361
    Top = 267
    Width = 70
    Height = 50
    Caption = 'c'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 28
    OnClick = Button1Click
  end
  object Button32: TButton
    Tag = 32
    Left = 11
    Top = 56
    Width = 49
    Height = 22
    Caption = 'HEX'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 29
    OnClick = Button1Click
  end
  object Button33: TButton
    Tag = 33
    Left = 11
    Top = 83
    Width = 49
    Height = 22
    Caption = 'DEC'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 30
    OnClick = Button1Click
  end
  object Button34: TButton
    Tag = 34
    Left = 11
    Top = 110
    Width = 49
    Height = 22
    Caption = 'OCT'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 31
    OnClick = Button1Click
  end
  object Button35: TButton
    Tag = 35
    Left = 11
    Top = 138
    Width = 49
    Height = 22
    Caption = 'BIN'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 32
    OnClick = Button1Click
  end
  object Button36: TButton
    Tag = 36
    Left = 11
    Top = 217
    Width = 70
    Height = 50
    Caption = 'A'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 33
    OnClick = Button1Click
  end
  object Button37: TButton
    Tag = 37
    Left = 11
    Top = 267
    Width = 70
    Height = 50
    Caption = 'B'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 34
    OnClick = Button1Click
  end
  object Button38: TButton
    Tag = 38
    Left = 11
    Top = 317
    Width = 70
    Height = 50
    Caption = 'C'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 35
    OnClick = Button1Click
  end
  object Button39: TButton
    Tag = 39
    Left = 11
    Top = 367
    Width = 70
    Height = 50
    Caption = 'D'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 36
    OnClick = Button1Click
  end
  object Button40: TButton
    Tag = 40
    Left = 11
    Top = 417
    Width = 70
    Height = 50
    Caption = 'E'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 37
    OnClick = Button1Click
  end
  object TB_field: TEdit
    Left = 81
    Top = 13
    Width = 350
    Height = 31
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 38
    OnKeyPress = TB_field_hexKeyPress
  end
  object Button41: TButton
    Tag = 41
    Left = 11
    Top = 467
    Width = 70
    Height = 50
    Caption = 'F'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 39
    OnClick = Button1Click
  end
  object Button42: TButton
    Tag = 42
    Left = 361
    Top = 467
    Width = 70
    Height = 50
    Caption = 'x'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 40
    OnClick = Button1Click
  end
  object Button43: TButton
    Tag = 43
    Left = 11
    Top = 517
    Width = 420
    Height = 50
    Caption = 'diagram'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 41
    OnClick = Button43Click
  end
  object ProgressBar1: TProgressBar
    Left = 11
    Top = 183
    Width = 158
    Height = 17
    BackgroundColor = clInactiveBorder
    TabOrder = 42
  end
  object Button44: TButton
    Tag = 27
    Left = 361
    Top = 317
    Width = 70
    Height = 50
    Caption = 'e'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 43
    OnClick = Button1Click
  end
  object Button45: TButton
    Tag = 28
    Left = 361
    Top = 367
    Width = 70
    Height = 50
    Caption = 'pi'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 44
    OnClick = Button1Click
  end
  object Button46: TButton
    Tag = 29
    Left = 361
    Top = 417
    Width = 70
    Height = 50
    Caption = '^'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Showcard Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 45
    OnClick = Button1Click
  end
end
