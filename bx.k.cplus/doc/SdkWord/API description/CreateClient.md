# CreateClient

- 函数

```C++
LED5KSDK_API DWORD WINAPI CreateClient(char *led_ip,UINT led_port,bx_5k_card_type card_type,int tmout_sec,int mode,void (CALLBACK* pClose)(DWORD dwHand,int err_code)=NULL);
```

```C#
public static extern uint CreateClient(byte[] led_ip,uint led_port,bx_5k_card_type card_type,int tmout_sec,int mode,CallBackClientClose pCloseFunc);
```

```Delphi
CreateClient:function(led_ip:PChar;led_port:Integer;card_type:Byte;tmout_sec:Integer;mode:Integer; pFunc:TCallBackClose):Integer;stdcall;
```

```vb
Public Declare Function CreateClient Lib "Led5kSDK.dll" (ByVal led_ip As String, ByVal led_port As Integer, ByVal card_type As Byte, ByVal tmout_sec As Single, ByVal mode As Single, ByVal pCloseFunc As Single) As Integer
```

- 参数

| 参数       | 描述                                                   |
| ---------- | ------------------------------------------------------ |
| led_ip     | 控制卡IP                                               |
| led_port   | 端口号                                                 |
| card_type  | 控制卡型号 枚举类型                                    |
| tmout_sec  | 创建连接超时时间                                       |
| mode       | 显⽰模式：0普通模式 ； 1动态模式（动态区优先节⽬显⽰） |
| pCloseFunc | 回调函数，参数值为null                                 |

- 说明

通过网络固定IP模式连接控制卡，设置控制卡IP、端口号、控制卡类型，回调函数：