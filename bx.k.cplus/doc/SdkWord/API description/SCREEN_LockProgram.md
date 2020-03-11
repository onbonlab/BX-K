# SCREEN_LockProgram

- 函数

```C++
COMMAND_API SCREEN_LockProgram(DWORD dwHand,BYTE LockFlag,BYTE StoreMode,char* ProgramFileName);
```

```C#
public static extern int SCREEN_LockProgram(uint dwHand,byte LockFlag,byte StoreMode,byte[] ProgramFileName);
```

```Delphi

```

```vb

```

- 参数

| 参数            | 描述                         |
| --------------- | ---------------------------- |
| dwHand          | 连接控制卡函数的返回值       |
| LockFlag        | 当前图文节目锁定为1，解锁为0 |
| StoreMode       | 默认为0                      |
| ProgramFileName | 当前显示的图文节目名         |

- 返回值

详见错误码及说明

- 说明

该函数是锁定或解锁当前图文节目，若为是锁定节目则函数参数 LockFlag=1；解锁 LockFlag=0