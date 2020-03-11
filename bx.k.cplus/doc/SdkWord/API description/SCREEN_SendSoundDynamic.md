# SCREEN_SendSoundDynamic

- 函数

```C++
COMMAND_API SCREEN_SendSoundDynamicArea(DWORD dwHand,bx_5k_area_header header,USHORT TextLen,BYTE* AreaText,BYTE SoundMode,BYTE SoundPerson,BYTE SoundVolume,BYTE SoundSpeed,int sound_len,BYTE* sounddata);
```

```C#
public static extern int SCREEN_SendSoundDynamic(uint dwHand, bx_5k_area_header header, ushort TextLen, byte[] AreaText, byte SoundMode, byte SoundPerson, byte SoundVolume, byte SoundSpeed, int sound_len, byte[] sounddata);
```

```Delphi
SCREEN_SendSound:function(dwHand:Cardinal;sound:Tbx_5k_sound;TextLen:Integer;AreaText:PChar):Integer;stdcall;
```

```vb

```

- 参数

- 参数

| 参数        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| dwHand      | 连接控制卡函数的返回值                                       |
| header      | 结构体类型bx_5k_area_header,动态区数据参数，参数设置见区域数据格式设置 |
| TextLen     | 动态区数据长度                                               |
| AreaText    | 动态区数据                                                   |
| SoundMode   | 声音类型                                                     |
| SoundPerson | 发音人                                                       |
| SoundVolume | 音量                                                         |
| SoundSpeed  | 音速                                                         |
| sound_len   | 声音数据长度                                                 |
| sounddata   | 声音数据                                                     |

- 返回值

详见错误码及说明

- 说明


发送语音动态区