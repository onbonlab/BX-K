# InitSdk

- 函数

```C++
LED5KSDK_API void WINAPI InitSdk(BYTE minorVer, BYTE majorVer);
```

```C#
public static extern void InitSdk(byte minorVer,byte majorVer);
```

```Delphi
InitSdk: procedure(minorVer:Byte; majorVer:Byte);stdcall; 
```

```vb
Public Declare Function InitSdk Lib "Led5kSDK.dll" (ByVal minorVer As Byte, ByVal majorVer As Byte) As Long 
```

- 参数

| 参数     | 描述                        |
| -------- | --------------------------- |
| minorVer | 固定值为2，不能改变，无意义 |
| majorVer | 固定值为2，不能改变，无意义 |

- 说明

初始化动态库