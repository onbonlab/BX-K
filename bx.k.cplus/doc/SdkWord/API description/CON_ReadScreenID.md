# CON_ReadScreenID

- 函数

```C++
COMMAND_API CON_ReadScreenID(DWORD dwHand,USHORT* pScreenID);
```

```C#
public static extern int CON_ReadScreenID(uint dwHand,ref ushort pScreenID);
```

```Delphi

```

```vb

```

- 参数

| 参数      | 描述                   |
| --------- | ---------------------- |
| dwHand    | 连接控制卡函数的返回值 |
| pScreenID | 回读的屏号             |

- 返回值

详见错误码及说明

- 说明

读取控制卡屏号