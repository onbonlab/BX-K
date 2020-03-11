# SCREEN_ForceOnOff

- 函数

```C++
COMMAND_API SCREEN_ForceOnOff(DWORD dwHand,BYTE OnOffFlag);
```

```C#
public static extern int SCREEN_ForceOnOff(uint dwHand,byte OnOffFlag);
```

```Delphi
CREEN_ForceOnOff:function(dwHand:Cardinal;OnOffFlag:byte):Integer;stdcall;
```

```vb

```

- 参数

| 参数      | 描述                   |
| --------- | ---------------------- |
| dwHand    | 连接控制卡函数的返回值 |
| OnOffFlag | 开关标志1标示开2标示关 |

- 返回值

详见错误码及说明

- 说明

强制开关机