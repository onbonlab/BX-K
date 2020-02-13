# Led5kSDK接口说明文档

## 1 快速开发导读

字库卡（BX-5K1/5K2、BX-5MK1/5MK2、BX-5K1Q-YY、BX-6K1/K2/K3）支持动态链接库开发和协议开发，本文档主要针对动态链接库开发的相关说明，需要协议开发请参照我们提供的协议文档。
如果你想尽快开发出一个能简单控制的软件，建议按以下流程阅读本文档，并进行软件开发。

- 阅读错误码及说明
- 阅读API调用顺序
- 阅读函数说明

## 2 错误码及说明

动态库中每个接口函数最后都返回函数执行结果，用户可根据函数执行结果查找判断该函数的执行情况。

### *2.1错误状态*

| 错误名称             | 代码 | 说明                                            |
| -------------------- | ---- | ----------------------------------------------- |
| ERR_NO               | 0    | 没有错误                                        |
| ERR_OUTOFGROUP       | 1    | Command Group Error                             |
| ERR_NOCMD            | 2    | Command Not Found                               |
| ERR_BUSY             | 3    | The Contorller is busy now                      |
| ERR_MEMORYVOLUME     | 4    | Out of the Memory Volume                        |
| ERR_CCHECKSUM        | 5    | CRC16 Checksum Error                            |
| ERR_FILENOTEXIST     | 6    | File Not Exist                                  |
| ERR_FLASH            | 7    | Flash Access Error                              |
| ERR_FILE_DOWNLOAD    | 8    | File Download Error                             |
| ERR_FILE_NAME        | 9    | File Name Error                                 |
| ERR_FILE_TYPE        | 10   | File Type Error                                 |
| ERR_FILE_CRC16       | 11   | File CRC16 Error                                |
| ERR_FONT_NOT_EXIST   | 12   | Font Library Not Exist                          |
| ERR_FIRMWARE_TYPE    | 13   | Firmware Type Error (Check the controller type) |
| ERR_DATE_TIME_FORMAT | 14   | Date Time format error                          |
| ERR_FILE_EXIST       | 15   | File Exist for File overwrite                   |
| ERR_FILE_BLOCK_NUM   | 16   | File block number error                         |
| ERR_COMMUNICATE      | 100  | 通信失败                                        |
| ERR_PROTOCOL         | 101  | 协议数据不正确                                  |
| ERR_TIMEOUT          | 102  | 通信超时                                        |
| ERR_NETCLOSE         | 103  | 通讯断开                                        |
| ERR_INVALID_HAND     | 104  | 无效句柄                                        |
| ERR_PARAMETER        | 105  | 参数错误                                        |
| ERR_SHOULDREPEAT     | 106  | 需要重复上次的错误包                            |
| ERR_FILE             | 107  | 无效文件                                        |

## 3 显示屏初始化说明

控制器接入动态库使用的系统前需要首先使用我司提供的 LedshowZK2017软件来进行控制卡
地址、通讯波特率、网络 IP(如有网口)、端口地址(如有网口)、扫描方式等设置；设置好后就可以再接入本动态库的系统中按照之前设定好的相关参数来设定显示屏的其它参数、信息和命令了。

## 4 API调用顺序

### *4.1总体次序*
![image](img\flowsheet.png)

## 5 函数说明

### *5.1 初始化 InitSdk函数* 

- 函数

```
InitSdk: procedure(minorVer:Byte; majorVer:Byte);stdcall; 
```

- 参数

| 参数     | 描述                |
| -------- | ------------------- |
| minorVer | 固定值为2，不能改变 |
| majorVer | 固定值为2，不能改变 |

- 说明

初始化动态库

### *5.2 释放动态库 ReleaseSdk函数*

- 函数

```
ReleaseSdk: procedure();stdcall;
```

- 参数

无

- 说明

释放动态库

### *5.3 UDP模式 CreateBroadCast函数*

- 函数

```
CreateBroadCast:function(broad_ip:PChar; broad_port:Integer; card_type:byte; barcode:PChar;Option:Byte; mode:Integer):Cardinal;stdcall; 
```

- 参数

| 参数       | 描述                                                   |
| ---------- | ------------------------------------------------------ |
| broad_ip   | 广播IP                                                 |
| broad_port | 端口号                                                 |
| card_type  | 控制卡类型 枚举类型，附录                              |
| mode       | 显⽰模式：0普通模式 ； 1动态模式（动态区优先节⽬显⽰） |


- 说明

通过广播模式连接控制卡，设置广播IP、端口号、控制卡类型

### *5.4 TCP模式 CreateClient函数* ###

- 函数

```
CreateClient:function(led_ip:PChar;led_port:Integer;card_type:Byte;tmout_sec:Integer;mode:Integer; pFunc:TCallBackClose):Integer;stdcall;
```

- 参数

| 参数       | 描述                                                   |
| ---------- | ------------------------------------------------------ |
| led_ip     | 控制卡IP                                               |
| led_port   | 端口号                                                 |
| card_type  | 控制卡型号 枚举类型，附录                              |
| tmout_sec  | 创建连接超时时间，单位秒                               |
| mode       | 显⽰模式：0普通模式 ； 1动态模式（动态区优先节⽬显⽰） |
| pCloseFunc | 回调函数，参数值可为null                               |

- 说明

通过网络固定IP模式连接控制卡，设置控制卡IP、端口号、控制卡类型，回调函数：

```
TCallBackClose = procedure(dwHand:Cardinal;err_code:Integer); stdcall;
```

### *5.6 串口模式 CreateComClient函数* ###

- 函数

```
CreateComClient:function(com:byte;baudrate:DWORD;card_type:byte;mode:Integer;ScreenID:Word):Integer;stdcall;
```

- 参数

| 参数      | 描述                                                   |
| --------- | ------------------------------------------------------ |
| com       | 串口号                                                 |
| baudrate  | 波特率                                                 |
| card_type | 控制卡型号 枚举类型                                    |
| mode      | 显⽰模式：0普通模式 ； 1动态模式（动态区优先节⽬显⽰） |
| ScreenID  | 屏号                                                   |

- 说明

通过串口连接控制卡，设置控制卡串口号、波特率、控制卡型号和屏号。

### *5.8 销毁连接 Destroy函数* ###

- 函数

```
Destroy_Handle:procedure(dwHand:Cardinal);stdcall;
```

- 参数

| 参数   | 描述                   |
| ------ | ---------------------- |
| dwHand | 连接控制卡函数的返回值 |

- 说明

销毁通讯，delphi里面**Destroy**不能当接口名，需要修改

### *5.9 设置通信超时 SetTimeOut函数* 

- 函数

```
SetTimeout:function(dwHand:Cardinal;nSec:Cardinal):Integer;stdcall;
```

- 参数

| 参数   | 描述                   |
| ------ | ---------------------- |
| dwHand | 连接控制卡函数的返回值 |
| nSec   | 通信超时时间，单位为s  |

- 说明

连接控制卡后，通过调用该函数设置通讯超时时间

### *5.10 CON_PING函数*

- 函数

```
N_PING:function(dwHand:Cardinal):Integer;stdcall;
```

- 参数

| 参数   | 描述                   |
| ------ | ---------------------- |
| dwHand | 连接控制卡函数的返回值 |

- 返回值

详见错误码及说明

- 说明

若ping命令执行成功，说明与控制卡通信成功

### *5.12 查询控制卡状态 CON_ControllerStatus函数*

- 函数

```
CON_ControllerStatus:function(dwHand:Cardinal;pStatus:PChar; var len:Word):Integer;stdcall;
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

### *5.16 校时 CON_SystemClockCorrect函数*

- 函数

```
CON_SystemClockCorrect:function(dwHand:Cardinal):Integer;stdcall;
```

- 参数

| 参数   | 描述                   |
| ------ | ---------------------- |
| dwHand | 连接控制卡函数的返回值 |

- 返回值

详见错误码及说明

- 说明

校正系统时间

### *5.21 SCREEN_ForceOnOff函数*

- 函数

```
CREEN_ForceOnOff:function(dwHand:Cardinal;OnOffFlag:byte):Integer;stdcall;
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

### *5.22 SCREEN_TimeTurnOnOff函数*

- 函数

```
SCREEN_TimeTurnOnOff:function(dwHand:Cardinal;pTimer:PChar; nGroup:Integer):Integer;stdcall;
```

- 参数

| 参数   | 描述                                                         |
| ------ | ------------------------------------------------------------ |
| dwHan  | 连接控制卡函数的返回值                                       |
| pTimer | 定时器定时开机时间，BCD码标示，格式如下：时（1）+分（1）定时关机时间 |
| nGroup | 分组编号                                                     |

- 返回值

详见错误码及说明

- 说明

设置定时开关机

### *5.23 SCREEN_SetBrigthness函数*

- 函数

```
 SCREEN_SetBrightness:function(dwHand:Cardinal; BrightnessType:byte; CurrentBrightness:byte;BrightnessValue:PChar):Integer;stdcall;
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

### *5.26 SCREEN_DelDynamicArea函数*

- 函数

```
SCREEN_DelDynamicArea:function(dwHand:Cardinal; DeleteAreaId:byte):Integer;stdcall;
```

- 参数

| 参数         | 描述                                  |
| ------------ | ------------------------------------- |
| dwHand       | 连接控制卡函数的返回值                |
| DeleteAreaId | 要删除的动态区编号，255删除所有动态区 |

- 返回值

详见错误码及说明

- 说明

删除动态区

### *5.27  SCREEN_SendDynamicArea函数*

- 函数

```
SCREEN_SendDynamicArea:function(dwHand:Cardinal;header:Tbx_5k_area_header;TextLen:Word;AreaText:PChar):Integer;stdcall;
```

- 参数

| 参数     | 描述                                                         |
| -------- | ------------------------------------------------------------ |
| dwHand   | 连接控制卡函数的返回值                                       |
| header   | 结构体类型bx_5k_area_header,动态区数据参数，参数设置见区域数据格式设置 |
| TextLen  | 动态区数据长度                                               |
| AreaText | 动态区数据                                                   |

- 返回值

详见错误码及说明

- 说明

发送动态区，断电后不会保存。

### *5.37 OFS_DeleteFile函数*

- 函数

```
OFS_DeleteFile:function(dwHand:Cardinal; FileNumber:Word;pFileNameList:Pchar):Integer;stdcall;
```

- 参数

| 参数          | 描述                                                 |
| ------------- | ---------------------------------------------------- |
| dwHand        | 连接控制卡函数的返回值                               |
| FileNumber    | 删除当前图文节目个数为1，删除所有节目该参数值为0     |
| pFileNameList | 删除当前图文节目的节目名，删除所有节目该参数值为null |

- 返回值

详见错误码及说明

- 说明

该函数用来删除图文区节目，若删除当前显示的节目，函数的参数FileName=1，pFileNameList的值为要删除的图文节目名，若删除所有节目，则函数的参数FileName=0，pFileNameList=null


### *5.38 OFS_SendFileData函数*

- 函数

```
OFS_SendFileData:function(dwHand:Cardinal; overwrite:byte; pFileName:PChar; DisplayType:Word; PlayTimes:Byte;ProgramLife:PChar; ProgramWeek:Byte; ProgramTime:Byte; Period:PChar; AreaNum:Byte;AreaDataList:PChar;AreaDataListLen:Integer):Integer;stdcall;
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

### *5.28  SCREEN_SendSoundDynamic函数*

- 函数

```
SCREEN_SendSound:function(dwHand:Cardinal;sound:Tbx_5k_sound;TextLen:Integer;AreaText:PChar):Integer;stdcall;
```

- 参数

| 参数     | 描述                                                        |
| -------- | ----------------------------------------------------------- |
| dwHand   | 连接控制卡函数的返回值                                      |
| header   | 结构体类型Tbx_5k_sound,语音参数，参数设置见语音数据格式设置 |
| TextLen  | 声音数据长度                                                |
| AreaText | 声音数据                                                    |

- 返回值

详见错误码及说明

- 说明


发送语音

## 附录

### 错误码

| 错误码 | 错误类型                                        |
| ------ | ----------------------------------------------- |
| 1      | Command Group Error                             |
| 2      | Command Not Found                               |
| 3      | The Controller is busy now                      |
| 4      | Out of the Memory Volume                        |
| 5      | CRC16 Checksum Error                            |
| 6      | File Not Exist                                  |
| 7      | Flash Access Error                              |
| 8      | File Download Error                             |
| 9      | Filename Error                                  |
| 10     | File type Error                                 |
| 11     | File CRC16 Error                                |
| 12     | Font Library Not Exist                          |
| 13     | Firmware Type Error (Check the controller type) |
| 14     | Date Time format error                          |
| 15     | File Exist for File overwrite                   |
| 16     | File block number error                         |
| 100    | /通信失败                                       |
| 101    | 协议数据不正确                                  |
| 102    | 通信超时                                        |
| 103    | 通信断开                                        |
| 104    | 无效句柄                                        |
| 105    | 参数错误                                        |
| 106    | 需要重复上次数据包                              |
| 107    | 无效文件                                        |
| 0      | No Error                                        |

### 控制器类型

| 控制卡型号 | 控制卡型号值 |
| ---------- | ------------ |
| 通配符     | 0xFE         |
| BX-5K1     | 0x51         |
| BX-5K2     | 0x58         |
| BX-5MK1    | 0x54         |
| BX-5MK2    | 0x53         |
| BX-5K1Q-YY | 0x5c         |
| BX-6K1     | 0x61         |
| BX-6K2     | 0x62         |
| BX-6K3     | 0x63         |
| BX-6K1-YY  | 0x64         |
| BX-6K2-YY  | 0x65         |
| BX-6K3-YY  | 0x66         |
| BX-6K1-4G  | 0x67         |
| BX-6K2-4G  | 0x68         |

### 结构体定义数据

```
  Tbx_5k_area_header = packed record
  	AreaType:Byte;//一个字节
    AreaX:Word;  //2个字节
    AreaY:Word;
    AreaWidth:Word;
    AreaHeight:Word;
    DynamicAreaLoc:Byte;
    Lines_sizes:Byte ;
    RunMode:Byte;
    Timeout:Word ;
    Reserved1:Byte;
    Reserved2:Byte;
    Reserved3:Byte;
    SingleLine:Byte;
    NewLine:Byte ;
    DisplayMode:Byte;
    ExitMode:Byte;
    Speed:Byte;
    StayTime:Byte;
    DataLen:DWORD;   //4个字节
  end;
```

- 区域数据格式设置

| 参数           | 数据长度 | 默认值 | 描述                                                         |
| -------------- | -------- | ------ | ------------------------------------------------------------ |
| AreaType       | 1        | 0x00   | 区域类型                                                     |
| AreaX          | 2        |        | 区域X坐标，以字节为单位（8个像素点）                         |
| AreaY          | 2        |        | 区域Y坐标，以字节为单位（8个像素点）                         |
| AreaWidth      | 2        |        | 区域宽度，以字节为单位（8个像素点）                          |
| AreaHeight     | 2        |        | 区域高度，以字节为单位（8个像素点）                          |
| DynamicAreaLoc | 1        | 0XFF   | 动态区编号注意，该参数只对动态区有效其他区域为默认值，动态区必须统一编号，编号从0开始递增 |
| Lines_sizes    | 1        |        | 行间距                                                       |
| RunMode        | 1        |        | 动态区运行模式 0 动态区数据循环显示 1 动态区数据显示完成后静止显示最后一页数据 2 动态区域数据循环显示，超过设定时间后动态区仍未更新时删除动态区 |
| Timeout        | 2        |        | 动态区数据超时时间，单位为s                                  |
| Reserved       | 3        | 0x00   | 保留字                                                       |
| SingleLine     | 1        | 0x02   | 是否单行显示，0x01 单行显示 0x02 多行显示                    |
| NewLine        | 1        |        | 是否自动换行，0x01 不自动换行，显示数据在换行时必须插入换行符 0x02 自动换行 显示类容不需要插入换行符，但是只能使用统一的中文字体和英文字体 |
| DisplayMode    | 1        |        | 显示方式，其定义如下： 0x01 静止显示，0x02 快速打出，0x03 向左移动，0x04 向右移动，0x05向上移动，0x06 向下移动 |
| ExitMode       | 1        | 0x00   | 退出方式                                                     |
| Speed          | 1        |        | 显示速度，0x00最快，0x18最慢                                 |
| StayTime       | 1        |        | 显示特技停留时间单位为0.5s                                   |
| DataLen        |          |        | 数据长度（包括换行，颜色等转义参数）                         |

- 查询控制器状态

- 语音设置

  ```
    Tbx_5k_sound  = packed record
     StoreFlag:Byte;
     SoundPerson:Byte;//一个字节
     SoundVolum:Byte;
     SoundSpeed:Byte;
     SoundDataMode:Byte;
     SoundReplayTimes:Integer;
     SoundReplayDelay:Integer;
     SoundReservedParaLen:Byte;
     SoundDataLen:Integer;
    end;
  ```

  | 参数                 | 说明                                                         |
  | -------------------- | ------------------------------------------------------------ |
  | StoreFlag            | 是否使能语音播放;0 表示不使能语音; 1 表示播放下文中 SoundData 部分内容; |
  | SoundPerson          | 发音人 该值范围是 0 - 5                                      |
  | SoundVolum           | 音量，该值范围是 0~10，共 11 种，0表示静音                   |
  | SoundSpeed           | 语速，该值范围是 0~10                                        |
  | SoundDataMode        | SoundData 的编码格式：该值意义如下：0x00 GB2312; 0x01 GBK; 0x02 BIG5; 0x03 UNICODE |
  | SoundReplayTimes     | 重播次数 该值为 0，表示播放 1 次该值为 1，表示播放 2 次，该值为 0xffffffff，表示播放无限次重 |
  | SoundReplayDelay     | 播时间间隔，该值表示两次播放语音的时间间隔，单位为 10ms      |
  | SoundReservedParaLen | 0x00 语音参数保留参数长度                                    |
  | SoundDataLen         | 语音数据长度                                                 |

  

### 联系我们

**上海仰邦科技股份有限公司（总部）**

地址：上海市徐汇区钦州北路1199号88幢7楼

电话：021-64554198 021-64554199

传真：021-64955166

邮编：200233

网址[：](http://www.onbonbx.com/)

**仰邦（江苏）光电实业有限公司（昆山光电实业基地）**

地址：江苏省昆山市开发区富春江路1299号

电话：0512-36912677 0512-36912688 0512-36912699

传真： 0251-36912670

邮编： 215300

**苏州仰邦科技股份有限公司（分部）

地址： 苏州市吴中区塔韵路178号501

电话： 0512-66589212

**二次开发支持**

邮箱：dev@onbonbx.com













