# CON_ControllerStatus

- 函数

```C++
COMMAND_API CON_ControllerStatus(DWORD dwHand,BYTE* pStatus,USHORT* len);
```

```C#
public static extern int CON_ControllerStatus(uint dwHand,byte[] pStatus,ref ushort len);
```

```Delphi

```

```vb
 
```

- 参数

| 参数    | 描述                      |
| ------- | ------------------------- |
| dwHand  | 连接控制卡函数的返回值    |
| pStatus | 具体见代码 控制器查询状态 |
| len     | 设置默认为0               |

- 返回值

详见错误码及说明

- 说明

查询控制器当前的图文节目(个数和节目名)、动态节目(列表和个数)、开机状态、亮度值、以
及控制卡时间。