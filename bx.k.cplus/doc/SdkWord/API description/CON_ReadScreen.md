# CON_ReadScreen

- 函数

```C++
COMMAND_API CON_ReadScreen(DWORD dwHand,BYTE* ScreenStatus,USHORT* len);
```

```C#
public static extern int CON_ReadScreen(uint dwHand,byte[] ScreenStatus,ref ushort len);
```

```Delphi
 
```

```vb

```

- 参数

| 参数         | 描述                   |
| ------------ | ---------------------- |
| dwHand       | 连接控制卡函数的返回值 |
| ScreenStatus | 屏幕状态               |
| len          | 设置默认为0            |

- 返回值

详见错误码及说明

- 说明

参数回读