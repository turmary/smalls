VERSION 5.00
Begin VB.Form FrmMain 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Form1"
   ClientHeight    =   2400
   ClientLeft      =   45
   ClientTop       =   435
   ClientWidth     =   4590
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   2400
   ScaleWidth      =   4590
   StartUpPosition =   3  '窗口缺省
   Begin VB.Frame Frame2 
      Caption         =   "取模函数测试"
      Height          =   855
      Left            =   240
      TabIndex        =   4
      Top             =   1320
      Width           =   4095
      Begin VB.TextBox Text4 
         Enabled         =   0   'False
         Height          =   375
         Left            =   3000
         TabIndex        =   9
         Top             =   360
         Width           =   975
      End
      Begin VB.TextBox Text3 
         Height          =   375
         Left            =   1440
         TabIndex        =   6
         Top             =   360
         Width           =   1095
      End
      Begin VB.TextBox Text2 
         Height          =   375
         Left            =   120
         TabIndex        =   5
         Top             =   360
         Width           =   975
      End
      Begin VB.Label Label2 
         Caption         =   "="
         Height          =   255
         Left            =   2640
         TabIndex        =   8
         Top             =   480
         Width           =   135
      End
      Begin VB.Label Label1 
         Caption         =   "%"
         Height          =   255
         Left            =   1200
         TabIndex        =   7
         Top             =   480
         Width           =   135
      End
   End
   Begin VB.Frame Frame1 
      Caption         =   "Dll 内部计数器"
      Height          =   975
      Left            =   240
      TabIndex        =   0
      Top             =   120
      Width           =   4095
      Begin VB.CommandButton Command2 
         Caption         =   "减少(&D)"
         Height          =   375
         Left            =   3000
         TabIndex        =   3
         Top             =   360
         Width           =   855
      End
      Begin VB.CommandButton Command1 
         Caption         =   "增加(&A)"
         Height          =   375
         Left            =   2160
         TabIndex        =   2
         Top             =   360
         Width           =   855
      End
      Begin VB.TextBox Text1 
         Enabled         =   0   'False
         Height          =   375
         Left            =   240
         TabIndex        =   1
         Top             =   360
         Width           =   1695
      End
   End
End
Attribute VB_Name = "FrmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Declare Function IncCounter Lib "First_DLL" () As Long
Private Declare Function DecCounter Lib "First_DLL" () As Long
Private Declare Function ModC Lib "First_DLL" (ByVal A As Long, ByVal B As Long) As Long
Private Declare Function PortIn Lib "First_DLL" (Port As Integer) As Long
Private Declare Function PortOut Lib "First_DLL" (Port As Integer, Val As Byte) As Long

Private Sub Command1_Click()
    Text1.Text = IncCounter()
End Sub

Private Sub Command2_Click()
    Text1.Text = DecCounter()
End Sub

Private Sub Text2_Change()
    If Int(Val(Text3.Text)) <> 0 Then
        Text4.Text = ModC(Int(Val(Text2.Text)), Int(Val(Text3.Text)))
    End If
    Text1.Text = Val(Text1.Text) + 1
End Sub

Private Sub Text3_Change()
    If Int(Val(Text3.Text)) <> 0 Then
        Text4.Text = ModC(Int(Val(Text2.Text)), Int(Val(Text3.Text)))
    End If
    Text1.Text = Val(Text1.Text) - 1
    'Call PortIn(&H378)
    'Call PortOut(&H378, &HFF)
End Sub

