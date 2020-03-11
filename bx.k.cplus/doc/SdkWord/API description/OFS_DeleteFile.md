# OFS_DeleteFile

- 函数

```C++
COMMAND_API OFS_DeleteFile(DWORD dwHand,USHORT FileNumber,char* pFileNameList);	
```

```C#
public static extern int OFS_DeleteFile(uint dwHand,ushort FileNumber,byte[] pFileNameList);
```

```Delphi
OFS_DeleteFile:function(dwHand:Cardinal; FileNumber:Word;pFileNameList:Pchar):Integer;stdcall;
```

```vb

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