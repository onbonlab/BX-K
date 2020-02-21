Imports System.Text
Imports System.Runtime.InteropServices

Public Class Form1
    Dim hand As Integer
    Dim err As Double

    ''' <summary>
    ''' 结构体转换成字节数组
    ''' </summary>
    ''' <param name="oStructure">要转化的结构体</param>
    Public Function StructureToByteArray(ByVal oStructure As Object) As Byte()
        Dim oSize As Integer = Marshal.SizeOf(oStructure)
        Dim tByte(oSize - 1) As Byte
        Dim tPtr As IntPtr = Marshal.AllocHGlobal(oSize)
        Marshal.StructureToPtr(oStructure, tPtr, False)
        Marshal.Copy(tPtr, tByte, 0, oSize)
        Marshal.FreeHGlobal(tPtr)
        Return tByte
    End Function


    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Led5k.InitSdk(2, 2)
        Dim str As String = "192.168.89.122"
        Dim bName() As Byte
        Dim code As Encoding = Encoding.ASCII
        bName = code.GetBytes(str)
        Dim io() As Char
        io = code.GetChars(bName)


        Dim led_port As Integer '端口赋值
        led_port = 5005

        Dim card_type As Led5k.bx_5k_card_type
        card_type = Led5k.bx_5k_card_type.BX_Any '控制卡型号赋值

        Dim tmout_sec As Single
        tmout_sec = 1 '超时时间赋值

        Dim mode As Single
        mode = 0 '运行模式赋值，1代表动态模式

        Dim pCloseFunc As Long = 0 '回调函数，空值
        'hand = Led5k.CreateComClient(4, 57600, card_type, mode, 1)
        hand = Led5k.CreateClient(str, 5005, card_type, tmout_sec, mode, pCloseFunc)
        Label1.Text = CStr(hand)
        err = Led5k.CON_PING(hand)
        Label1.Text = CStr(hand)
    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        err = Led5k.SCREEN_ForceOnOff(hand, 2)
    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        err = Led5k.SCREEN_ForceOnOff(hand, 1)
    End Sub

    Private Sub Button4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button4.Click
        Dim AreaText As String
        Dim code As Encoding = Encoding.GetEncoding("gb2312")
        Dim str() As Byte
        AreaText = "Hello,123"
        str = code.GetBytes(AreaText)

        Dim header As Led5k.bx_5k_area_header
        header.AreaType = 0             '固定值
        header.AreaX = 0 / 8          'X_像素坐标/最小单元
        header.AreaY = 0              'Y_像素坐标
        header.AreaWidth = 32 / 8     '宽_像素总数/最小单元
        header.AreaHeight = 16         '高_像素总数
        header.DynamicAreaLoc = 0     '动态区编号
        header.Lines_sizes = 0        '行间距
        header.RunMode = 0            '运行模式，0 动态区数据循环显示；1 动态区数据显示完成后静止显示最后1页数据；2动态区域数据循环显示，超过设定时间后动态区仍未更新时删除动态区。
        header.Timeout = 2            '动态区数据超时时间，单位为s
        header.Reserved1 = 0        '保留字
        header.Reserved2 = 0
        header.Reserved3 = 0
        header.SingleLine = 1         '是否单行显.，0x01 单行显示 0x02 多行显示
        header.NewLine = 1            '是否自动换行，0x01手动换行，文字中必须加换行符；0x02自动换行。
        header.DisplayMode = 1        '显示模式，其定义如下： 0x01 静止显示，0x02 快速打出，0x03 向左移动，0x04 向右移动，0x05向上移动，0x06 向下移动
        header.ExitMode = 0           '默认为0
        header.Speed = 0              '显示速度，0x00最快，0x18最慢
        header.StayTime = 1           '显示特技停留时间单位为0.5s
        header.DataLen = str.Length '数据长度包含转意字符

        err = Led5k.SCREEN_SendDynamicArea(hand, header, header.DataLen, str)
        Label1.Text = CStr(err)
    End Sub

    Private Sub Button5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button5.Click
        Dim BrightnessValue(48) As Byte
        For intCount As Integer = 0 To 48
            BrightnessValue(intCount) = 0
        Next
        err = Led5k.SCREEN_SetBrightness(hand, 1, 15, BrightnessValue)
    End Sub

    Private Sub Button6_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button6.Click
        Dim BrightnessValue(48) As Byte
        For intCount As Integer = 0 To 48
            '30分钟一个时间段，取值0-15
            BrightnessValue(intCount) = 10
        Next
        err = Led5k.SCREEN_SetBrightness(hand, 2, 0, BrightnessValue)
    End Sub

    Private Sub Button7_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button7.Click
        Dim AreaText As String
        Dim code As Encoding = Encoding.GetEncoding("GBK")
        Dim name() As Byte
        AreaText = "P000"
        name = code.GetBytes(AreaText)
        err = Led5k.SCREEN_LockProgram(hand, 1, 0, name)
    End Sub

    Private Sub Button8_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button8.Click
        Dim AreaText As String
        Dim code As Encoding = Encoding.GetEncoding("GBK")
        Dim name() As Byte
        AreaText = "P000"
        name = code.GetBytes(AreaText)
        err = Led5k.SCREEN_LockProgram(hand, 0, 0, name)
    End Sub

    Private Sub Button9_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button9.Click
        err = Led5k.SCREEN_DelDynamicArea(hand, 255)
    End Sub

    Private Sub Button10_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button10.Click
        Dim AreaText As String
        Dim code As Encoding = Encoding.GetEncoding("GBK")
        Dim str(), FileName(), ProgramLife(8), Period(7) As Byte
        AreaText = "P000"
        FileName = code.GetBytes(AreaText)
        For intCount As Integer = 0 To 8
            ProgramLife(intCount) = 255
        Next
        For intCount As Integer = 0 To 7
            Period(intCount) = 0
        Next
        Dim header As Led5k.bx_5k_area_header

        AreaText = "中文测试"
        str = code.GetBytes(AreaText)
        header.AreaType = 0
        header.AreaX = 0
        header.AreaY = 0
        header.AreaWidth = 8
        header.AreaHeight = 32
        header.DynamicAreaLoc = 255
        header.Lines_sizes = 0
        header.RunMode = 0
        header.Timeout = 0
        header.Reserved1 = 0
        header.Reserved2 = 0
        header.Reserved3 = 0
        header.SingleLine = 1
        header.NewLine = 1
        header.DisplayMode = 1
        header.ExitMode = 0
        header.Speed = 0
        header.StayTime = 10
        header.DataLen = str.Length
        Dim bytess() = StructureToByteArray(header)

        Dim SendBuf() As Byte
        ReDim SendBuf(bytess.Length + str.Length - 1)
        Array.Copy(bytess, SendBuf, bytess.Length)
        Array.Copy(str, 0, SendBuf, bytess.Length, str.Length)
        err = Led5k.OFS_SendFileData(hand, 1, FileName, 0, 1, ProgramLife, 1, 0, Period, 1, SendBuf, SendBuf.Length)
    End Sub

    Private Sub Button11_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button11.Click
        Dim AreaText As String
        Dim code As Encoding = Encoding.GetEncoding("GBK")
        Dim name() As Byte
        AreaText = "P000"
        name = code.GetBytes(AreaText)
        err = Led5k.OFS_DeleteFile(hand, 1, name)
    End Sub

    Private Sub Button12_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button12.Click
        err = Led5k.CON_SytemClockCorrect(hand)
    End Sub
End Class
