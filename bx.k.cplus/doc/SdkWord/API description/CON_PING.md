# CON_PING

- 函数

```C++
COMMAND_API CON_PING(DWORD dwHand);
```

```C#
public static extern int CON_PING(uint dwHand);
```

```Delphi
N_PING:function(dwHand:Cardinal):Integer;stdcall;
```

```vb
Public Declare Function CON_PING Lib "Led5kSDK.dll" (ByVal hand As Integer) As Double
```

- 参数

| 参数   | 描述                   |
| ------ | ---------------------- |
| dwHand | 连接控制卡函数的返回值 |

- 返回值

详见错误码及说明

- 说明

若ping命令执行成功，说明与控制卡通信成功