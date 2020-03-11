# OFS_SendFileData

- 函数

```C++
COMMAND_API OFS_SendFileData(DWORD dwHand,BYTE overwrite,char* pFileName,USHORT DisplayType,BYTE PlayTimes,BYTE* ProgramLife,BYTE ProgramWeek,BYTE ProgramTime,BYTE* Period,BYTE AreaNum, BYTE* AreaDataList,int AreaDataListLen);
```

```C#
public static extern int OFS_SendFileData(uint dwHand, byte overwrite, byte[] pFileName, ushort DisplayType, byte PlayTimes,byte[] ProgramLife, byte ProgramWeek, byte ProgramTime, byte[] Period, byte AreaNum, byte[] AreaDataList, int AreaDataListLen);
```

```Delphi
OFS_SendFileData:function(dwHand:Cardinal; overwrite:byte; pFileName:PChar; DisplayType:Word; PlayTimes:Byte;ProgramLife:PChar; ProgramWeek:Byte; ProgramTime:Byte; Period:PChar; AreaNum:Byte;AreaDataList:PChar;AreaDataListLen:Integer):Integer;stdcall;
```

```vb

```

- 参数

| 参数            | 描述                                                         |
| --------------- | ------------------------------------------------------------ |
| dwHand          | 连接控制卡函数的返回值                                       |
| overwrite       | 设置默认参数为1                                              |
| pFileName       | 文件名 PXXX XXX为文件编号，ASCII码表示文件名为字符串发送按顺序发送，如“P123”，则先发送“P”最后发送“3” |
| DisplayType     | 节目播放方式默认设置为0 --顺序播放                           |
| PlayTimes       | 节目重复播放次数，默认为1                                    |
| ProgramLife     | 节目生命周期即有效时间范围，默认设置为programLife= newbyte[8]ProgramLif[0]—ProgramLife[7]=0xff表示播放始终有效 |
| ProgramWeek     | 节目的星期属性，默认设置为1，表示一周都有效                  |
| ProgramTime     | 节目定时播放参数，当前为非0，表示非定时                      |
| Period          | 节目播放时段，当前设置为null表示全天有效                     |
| AreaNum         | 节目播放个数                                                 |
| AreaDataList    | 区域数据参考区域数据格式设置                                 |
| AreaDataListLen | 区域数据长度                                                 |

- 返回值

详见错误码及说明

- 说明

通过制定的通讯模式连接到控制卡，向指定的图文区域发送图文节目，该节目断电后会自动保存。