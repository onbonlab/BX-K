# SCREEN_SetBrigthness

- 函数

```C++
COMMAND_API SCREEN_SetBrightness(DWORD dwHand,BYTE BrightnessType,BYTE CurrentBrightness,BYTE* BrightnessValue);
```

```C#
public static extern int SCREEN_SetBrightness(uint dwHand,byte BrigthnessType,byte CurrentBrigthness,byte [] BrigthnessValue);
```

```Delphi
SCREEN_SetBrightness:function(dwHand:Cardinal; BrightnessType:byte; CurrentBrightness:byte;BrightnessValue:PChar):Integer;stdcall;
```

```vb

```

- 参数

| 参数              | 描述                                                         |
| ----------------- | ------------------------------------------------------------ |
| dwHand            | 连接控制卡函数的返回值                                       |
| BrigthnessType    | 亮度调整方式 0x01—强制调节亮度 0x02—定时调节亮度             |
| CurrentBrigthness | 当前亮度，强制调节亮度时有效，亮度值为0-15共16级。亮度值为15时亮度最高 |
| BrigthnessValue   | 亮度值列表，用于定时调亮把一天分为48个时段，每30分钟为一个时段，此处48个字节为每个时段的亮度值 |

- 返回值

详见错误码及说明

- 说明

调整屏幕亮度值