# CON_CheckCurrentFirmware

- 函数

```C++
COMMAND_API CON_CheckCurrentFirmware(DWORD dwHand,char* FirmwareName,char* FirmwareVersion,char* FirmwareDateTime);
```

```C#
public static extern int CON_CheckCurrentFirmware(uint dwHand,byte [] FirmwareVersion,byte[] FirmwareDateTime);
```

```Delphi
 
```

```vb

```

- 参数

| 参数             | 描述                   |
| ---------------- | ---------------------- |
| dwHand           | 连接控制卡函数的返回值 |
| FirmwareVersion  | 固件版本号             |
| FirmwareDateTime | 固件时间               |

- 返回值

详见错误码及说明

- 说明

查询固件版本号