# CON_ReSet

- 函数

```C++
COMMAND_API CON_Reset(DWORD dwHand);
```

```C#
public static extern int CON_ReSet(uint dwHand);
```

```Delphi
CON_ReSet: procedure(dwHand:Cardinal):Integer;stdcall; 
```

```vb
Public Declare Function CON_ReSet Lib "Led5kSDK.dll" (ByVal hand As Integer) As Long 
```

- 参数

| 参数   | 描述                   |
| ------ | ---------------------- |
| dwHand | 连接控制卡函数的返回值 |

- 返回值

详见错误码及说明

- 说明

复位，控制器连接接收到系统复位命令后，擦除FirmWare文件外的所有数据文件，然后复位CPU。