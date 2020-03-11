# CON_CheckCurrentFont

- 函数

```C++
COMMAND_API CON_CheckCurrentFont(DWORD dwHand,BYTE* fontStatus,USHORT* len);
```

```C#
public static extern int CON_CurrentCustomer(uint dwHand,byte [] fontStatus,ref ushort len);
```

```Delphi

```

```vb

```

- 参数

| 参数       | 描述                   |
| ---------- | ---------------------- |
| dwHand     | 连接控制卡函数的返回值 |
| fontStatus | 字库状态               |
| len        | 设置默认为0            |

- 返回值

详见错误码及说明

- 说明

查询字库信息