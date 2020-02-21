Imports System.Runtime.InteropServices

Public Class Led5k
    'Public Enum bx5k_err

    '    ERR_NO = 0 'No Error 
    '    ERR_OUTOFGROUP = 1 'Command Group Error 
    '    ERR_NOCMD = 2 'Command Not Found 
    '    ERR_BUSY = 3 'The Controller is busy now 
    '    ERR_MEMORYVOLUME = 4 'Out of the Memory Volume
    '    ERR_CHECKSUM = 5 'CRC16 Checksum Error 
    '    ERR_FILENOTEXIST = 6 'File Not Exist 
    '    ERR_FLASH = 7 'Flash Access Error 
    '    ERR_FILE_DOWNLOAD = 8 'File Download Error 
    '    ERR_FILE_NAME = 9 'Filename Error 
    '    ERR_FILE_TYPE = 10 'File type Error 
    '    ERR_FILE_CRC16 = 11 'File CRC16 Error 
    '    ERR_FONT_NOT_EXIST = 12 'Font Library Not Exist 
    '    ERR_FIRMWARE_TYPE = 13 'Firmware Type Error (Check the controller type) 
    '    ERR_DATE_TIME_FORMAT = 14 'Date Time format error 
    '    ERR_FILE_EXIST = 15 'File Exist for File overwrite 
    '    ERR_FILE_BLOCK_NUM = 16 'File block number error 
    '    ERR_COMMUNICATE = 100 '通信失败
    '    ERR_PROTOCOL = 101 '协议数据不正确
    '    ERR_TIMEOUT = 102 '通信超时
    '    ERR_NETCLOSE = 103 '通信断开
    '    ERR_INVALID_HAND = 104 '无效句柄
    '    ERR_PARAMETER = 105 '参数错误
    '    ERR_SHOULDREPEAT = 106 '需要重复上次数据包
    '    ERR_FILE = 107 '无效文件
    'End Enum

    ''串口停止位

    'Public Enum serial_stopbits As Byte

    '    COM_ONESTOPBIT = 0
    '    COM_ONE5STOPBITS = 1
    '    COM_TWOSTOPBITS = 2
    'End Enum
    ''/串口校验模式
    'Public Enum serial_parity As Byte

    '    COM_NOPARITY = 0
    '    COM_ODDPARITY = 1
    '    COM_EVENPARITY = 2
    '    COM_MARKPARITY = 3
    '    COM_SPACEPARITY = 4
    'End Enum

    ''串口数据位
    'Public Enum serial_databits As Byte

    '    COM_4BITS = 4
    '    COM_5BITS = 5
    '    COM_6BITS = 6
    '    COM_7BITS = 7
    '    COM_8BITS = 8
    'End Enum

    '控制器类型
    Public Enum bx_5k_card_type As Byte
        BX_Any = 254
        BX_5K1 = 81
        BX_5K2 = 88
        BX_5MK2 = 83
        BX_5MK1 = 86
        BX_5K1Q_YY = 92
        BX_6K1 = 97
        BX_6K2 = 98
        BX_6K3 = 99
        BX_6K1_YY = 100
        BX_6K2_YY = 101
        BX_6K3_YY = 102
    End Enum

    ''-------区域格式------
    '' area header | data |
    ''---------------------
    ''节目内区域定义
    <StructLayout(LayoutKind.Sequential, Pack:=1)> _
    Public Structure bx_5k_area_header
        Dim AreaType As Byte
        Dim AreaX As UShort
        Dim AreaY As UShort
        Dim AreaWidth As UShort
        Dim AreaHeight As UShort
        Dim DynamicAreaLoc As Byte
        Dim Lines_sizes As Byte
        Dim RunMode As Byte
        Dim Timeout As UShort
        Dim Reserved1 As Byte
        Dim Reserved2 As Byte
        Dim Reserved3 As Byte
        Dim SingleLine As Byte
        Dim NewLine As Byte
        Dim DisplayMode As Byte
        Dim ExitMode As Byte
        Dim Speed As Byte
        Dim StayTime As Byte
        Dim DataLen As UInteger
    End Structure

    Public Declare Function InitSdk Lib "Led5kSDK.dll" (ByVal minorVer As Byte, ByVal majorVer As Byte) As Long '初始化函数库
    Public Declare Function ReleaseSdk Lib "Led5kSDK.dll" () As Long '释放函数库
    Public Declare Function callbackclientclose Lib "Led5kSDK.dll" (ByVal hand As Long, ByVal err As Integer) As Long '回调函数

    Public Declare Function CreateClient Lib "Led5kSDK.dll" (ByVal led_ip As String, ByVal led_port As Integer, ByVal card_type As Byte,
                                                             ByVal tmout_sec As Single, ByVal mode As Single, ByVal pCloseFunc As Single) As Integer

    Public Declare Function CON_PING Lib "Led5kSDK.dll" (ByVal hand As Integer) As Double
    Public Declare Function SCREEN_ForceOnOff Lib "Led5kSDK.dll" (ByVal hand As Integer, ByVal OnOffFlag As Byte) As Double
    Public Declare Function CreateComClient Lib "Led5kSDK.dll" (ByVal com As Byte, ByVal baudrate As Integer, ByVal card_type As bx_5k_card_type, ByVal mode As Integer, ByVal ScreenID As UShort) As Integer

    Public Declare Auto Function SCREEN_SendDynamicArea Lib "Led5kSDK.dll" (ByVal dwHand As Integer, ByVal header As bx_5k_area_header, ByVal TextLen As UInteger, ByVal AreaText() As Byte) As Integer
    'Public Declare Auto Function SCREEN_SendDynamicArea Lib "Led5kSDK.dll" (ByVal dwHand As Integer, ByRef header As bx_5k_area_header, ByVal TextLen As UInteger, ByVal AreaText As String) As Integer

    Public Declare Auto Function SCREEN_SetBrightness Lib "Led5kSDK.dll" (ByVal dwHand As Integer, ByVal BrightnessType As Byte, ByVal CurrentBrightness As Byte, ByVal BrightnessValue() As Byte) As Integer
    Public Declare Auto Function SCREEN_LockProgram Lib "Led5kSDK.dll" (ByVal dwHand As Integer, ByVal LockFlag As Byte, ByVal StoreMode As Byte, ByVal ProgramFileName() As Byte) As Integer
    Public Declare Auto Function SCREEN_DelDynamicArea Lib "Led5kSDK.dll" (ByVal dwHand As Integer, ByVal DeleteAreaId As Byte) As Integer

    Public Declare Auto Function OFS_SendFileData Lib "Led5kSDK.dll" (ByVal dwHand As Integer, ByVal overwrite As Byte, ByVal pFileName() As Byte, ByVal DisplayType As Integer, ByVal PlayTimes As Byte,
            ByVal ProgramLife() As Byte, ByVal ProgramWeek As Byte, ByVal ProgramTime As Byte, ByVal Period() As Byte, ByVal AreaNum As Byte, ByVal AreaDataList() As Byte, ByVal AreaDataListLen As Integer) As Integer
    Public Declare Auto Function OFS_DeleteFile Lib "Led5kSDK.dll" (ByVal dwHand As Integer, ByVal FileNumber As Integer, ByVal pFileNameList() As Byte) As Integer

    Public Declare Auto Function CON_SytemClockCorrect Lib "Led5kSDK.dll" (ByVal dwHand As Integer) As Integer
End Class
