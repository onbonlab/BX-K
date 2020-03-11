# CreateComClient

- 函数

```C++
LED5KSDK_API DWORD WINAPI CreateComClient(BYTE com,DWORD baudrate,bx_5k_card_type card_type,int mode,USHORT ScreenID);
```

```C#
public static extern uint CreateComClient (byte com,uint baudrate,bx_5k_card_type card_type card_type,int mode,ushort ScreenID);
```

```Delphi
CreateComClient:function(com:byte;baudrate:DWORD;card_type:byte;mode:Integer;ScreenID:Word):Integer;stdcall;
```

```vb
Public Declare Function CreateComClient Lib "Led5kSDK.dll" (ByVal com As Single, ByVal baudrate As Integer, ByVal card_type As Byte,  ByVal mode As Single, ByVal ScreenID As Single) As Integer
```

- 参数

| 参数      | 描述                                                   |
| --------- | ------------------------------------------------------ |
| com       | 串口号                                                 |
| baudrate  | 波特率                                                 |
| card_type | 控制卡型号 枚举类型                                    |
| mode      | 显⽰模式：0普通模式 ； 1动态模式（动态区优先节⽬显⽰） |
| ScreenID  | 屏号                                                   |

- 说明

通过串口连接控制卡，设置控制卡串口号、波特率、控制卡型号和屏号。