# 附录

控制器类型

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

- 结构体定义数据

```c#
public struct bx_5k_area_header
{
    public byte AreaType;
    public short AreaX;
    public short AreaY;
    public short AreaWidth;
    public short AreaHeigth;
    public byte DynamicAreaLoc;
    public byte Lines_sizes;
    public byte RunMode;
    public short Timeout;
    public byte Reserved1;
    public byte Reserved2;
    public byte Reserved3;
    public byte SingleLine;
    public byte NewLine;
    public byte DisplayMode;
    public byte ExitMode;
    public byte Speed;
    public byte StayTime;
    public int DataLen;
}
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


* 联系我们

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