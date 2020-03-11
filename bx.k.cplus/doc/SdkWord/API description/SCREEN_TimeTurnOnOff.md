# SCREEN_TimeTurnOnOff

- 函数

```C++
COMMAND_API SCREEN_TimeTurnOnOff(DWORD dwHand,BYTE* pTimer,int nGroup);	
```

```C#
public static extern int SCREEN_TimeTurnOnOff(uint dwHand,byte[] pTimer,int nGroup);
```

```Delphi
SCREEN_TimeTurnOnOff:function(dwHand:Cardinal;pTimer:PChar; nGroup:Integer):Integer;stdcall;
```

```vb

```

- 参数

| 参数   | 描述                                                         |
| ------ | ------------------------------------------------------------ |
| dwHan  | 连接控制卡函数的返回值                                       |
| pTimer | 定时器定时开机时间，BCD码标示，格式如下：时（1）+分（1）定时关机时间，BCD码表示，格式如下：时（1）+分（1） |
| nGroup | 分组编号                                                     |

- 返回值

详见错误码及说明

- 说明

设置定时开关机