# SCREEN_SendDynamicArea

- 函数

```C++
COMMAND_API SCREEN_SendDynamicArea(DWORD dwHand,bx_5k_area_header header,USHORT TextLen,BYTE* AreaText);
```

```C#
public static extern int SCREEN_SendDynamicArea(uint dwHand,bx_5k_area_header header,ushort TextLen,byte[] AreaText);
```

```Delphi
SCREEN_SendDynamicArea:function(dwHand:Cardinal;header:Tbx_5k_area_header;TextLen:Word;AreaText:PChar):Integer;stdcall;
```

```vb
Public Declare Auto Function SCREEN_SendDynamicArea Lib "Led5kSDK.dll" (ByVal dwHand As Integer, ByVal header As bx_5k_area_header, ByVal TextLen As UInteger, ByVal AreaText() As Byte) As Integer
```

- 参数

| 参数     | 描述                                                         |
| -------- | ------------------------------------------------------------ |
| dwHand   | 连接控制卡函数的返回值                                       |
| header   | 结构体类型bx_5k_area_header【附录】,动态区数据参数，参数设置见区域数据格式设置 |
| TextLen  | 动态区数据长度                                               |
| AreaText | 动态区数据                                                   |

- 返回值

详见错误码及说明

- 说明

发送动态区，该函数向指定的动态区域发送动态区节目，参考“区域数据格式设置”设置相应的参数，添加节目内容，计算内容长度。节目断电后不会保存。