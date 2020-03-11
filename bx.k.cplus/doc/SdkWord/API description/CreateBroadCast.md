# CreateBroadCast

- 函数

```C++
LED5KSDK_API DWORD WINAPI CreateBroadCast(char *broad_ip,UINT broad_port,bx_5k_card_type card_type,unsigned char* BarCodes,BYTE Option,int mode);
```

```C#
public static extern uint CreateBroadCast(byte[] broad_ip,uint broad_port,
bx_5k_card_type card_type,int mode);
```

```Delphi
CreateBroadCast:function(broad_ip:PChar; broad_port:Integer; card_type:byte; barcode:PChar;Option:Byte; mode:Integer):Cardinal;stdcall;  
```

```vb
Public Declare Function CreateBroadCast Lib "Led5kSDK.dll" (ByVal led_ip As String, ByVal led_port As Integer, ByVal card_type As Byte,  ByVal mode As Single) As Integer
```

- 参数

| 参数       | 描述                                                   |
| ---------- | ------------------------------------------------------ |
| broad_ip   | 广播IP                                                 |
| broad_port | 端口号                                                 |
| card_type  | 控制卡类型 枚举类型                                    |
| mode       | 显⽰模式：0普通模式 ； 1动态模式（动态区优先节⽬显⽰） |


- 说明

通过广播模式连接控制卡，设置广播IP、端口号、控制卡类型