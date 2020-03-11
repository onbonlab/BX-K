# Destroy

* 函数

```c++
LED5KSDK_API void WINAPI Destroy(DWORD dwHand);
```

```C#
public static extern void Destroy(uint dwHand);
```

```Delphi
Destroy_Handle:procedure(dwHand:Cardinal);stdcall;
```

```vb
Public Declare Function Destroy Lib "Led5kSDK.dll" (ByVal hand As Integer) As Double 
```

- 参数

| 参数   | 描述                   |
| ------ | ---------------------- |
| dwHand | 连接控制卡函数的返回值 |

- 说明

销毁通讯