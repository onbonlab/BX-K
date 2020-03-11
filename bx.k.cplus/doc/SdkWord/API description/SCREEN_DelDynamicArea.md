# SCREEN_DelDynamicArea

- 函数

```C++
COMMAND_API SCREEN_DelDynamicArea(DWORD dwHand,BYTE DeleteAreaId); 
```

```C#
public static extern int DelDynamicArea(uint dwHand,byte DeleteAreaId);
```

```Delphi
SCREEN_DelDynamicArea:function(dwHand:Cardinal; DeleteAreaId:byte):Integer;stdcall; 
```

```vb

```

- 参数

| 参数         | 描述                   |
| ------------ | ---------------------- |
| dwHand       | 连接控制卡函数的返回值 |
| DeleteAreaId | 要删除的动态区编号     |

- 返回值

详见错误码及说明

- 说明

删除动态区