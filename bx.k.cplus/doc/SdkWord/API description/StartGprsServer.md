# StartGprsServer

- 函数

```C++
LED5KSDK_API BOOL WINAPI StartGprsServer(UINT port,void (CALLBACK* pConnectFunc)(DWORD dwHand,unsigned char* pid),void (CALLBACK* pCloseFunc)(DWORD dwHand,unsigned char* pid,int err_code));
```

```C#
public static extern int (uint port,CallBack pCallBackCon,ClaaBackLedClose pCallBackClose);
```

```Delphi

```

```vb

```

- 参数

| 参数           | 描述           |
| -------------- | -------------- |
| port           | 端口           |
| pCallBackCon   | 回调，详见代码 |
| pCallBackClose | 回调，详见代码 |

- 返回值

详见错误码及说明

- 说明

  启动GPRS服务器