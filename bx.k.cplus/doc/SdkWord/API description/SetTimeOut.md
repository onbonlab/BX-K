# SetTimeOut

- 函数

```C++
LED5KSDK_API void WINAPI SetTimeout(DWORD dwHand,DWORD nSec)
```

```C#
public static extern void SetTimeOut(uint dwHand,uint nSec);
```

```Delphi
SetTimeout:function(dwHand:Cardinal;nSec:Cardinal):Integer;stdcall;
```

```vb
Public Declare Function SetTimeOut Lib "Led5kSDK.dll" (ByVal hand As Integer, ByVal nSec As Integer) As Double
```

- 参数

| 参数   | 描述                   |
| ------ | ---------------------- |
| dwHand | 连接控制卡函数的返回值 |
| nSec   | 设计超时时间，单位为s  |

- 说明

连接控制卡后，通过调用该函数设置通讯超时时间