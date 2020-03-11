# BX5MK_SetIPAddress

- 函数

```C++
COMMAND_API BX5MK_SetIPAddress(DWORD dwHand,BYTE ConnnectMode,char* ip,char* SubnetMask,char* Gateway,USHORT port,BYTE ServerMode,char* ServerIPAddress,USHORT ServerPort,char* ServerAccessPassword,USHORT HeartBeatInterval,char* NetID);
```

```C#
public static extern int BX5MK_SetIPAddress(uint dwHand, byte ConnnectMode, byte[] ip, byte[] SubnetMask, byte[] Gateway, ushort port,byte ServerMode, byte[] ServerIPAddress, ushort ServerPort, byte[] ServerAccessPassword, ushort HeartBeatInterval, byte[] NetID);
```

```Delphi

```

```vb
 
```

- 参数

| 参数                 | 描述                                     |
| -------------------- | ---------------------------------------- |
| dwHand               | 连接控制卡函数的返回值                   |
| ConnectMode          | 连接方式                                 |
| ip                   | ip地址                                   |
| SubnetMask           | 子网掩码                                 |
| Getway               | 默认网关                                 |
| port                 | 端口号                                   |
| ServerMode           | 服务器模式是否使能，  1 – 使能，0 – 禁止 |
| ServerIPAddress      | 服务器 IP 地址                           |
| ServerPort           | 服务器 端口号                            |
| ServerAccessPassword | 服务器访问密码                           |
| HeartBeatInterval    | 心跳时间间隔（单位：秒）                 |
| NetID                | 控制器网络 ID                            |

- 返回值


- 说明
  设置IP地址