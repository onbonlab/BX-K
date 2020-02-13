# BX-5K/6K Delphi SDK
本项目为仰邦科技 BX-5K/6K 系列的 delphi 实现，调用仰邦封装的动态库文件，任何人都可直接在此代码上进行添加与修改。

本项目由纯delphi7编写， 本 demo 中提供了 TCP 模式和RS485/232的简单使用方式。

* Delphi代码

  https://github.com/onbonlab/bx.k.delphi/blob/master/src/MainFrm.pas

* 可执行程序

  https://github.com/onbonlab/bx.k.delphi/releases



## 支持功能

* 更新动态区（单个）
* 删除动态区
* 更新节目（单个节目，节目可有多个普通区域）
* 删除节目

## 调用方法

此API接口的调用方式如下：

**步骤1：**

初始化动态库

```
InitSdk(2,2);
```

**步骤2：**

创建通信连接，获取连接句柄

**步骤3：**

使用连接句柄进行通信指令，更新显示屏显示效果及其他命令

**步骤4：**

销毁连接句柄

**步骤5：**

释放动态库

```
ReleaseSdk();
```

## 使用例程

```
//初始化动态库
InitSdk(2,2);

//创建连接句柄
FdwHandle:Cardinal;
//TCP连接
P:String;
IP:='192.168.89.56';
FdwHandle:=CreateClient(PChar(IP),5005,$FE,2,0,@CallBackClose);
//RS485/232
//FdwHandle:=CreateComClient(4,57600,$FE,0,1);

//设置通信超时时长，单位秒，如果不使用接口，默认10秒
SetTimeout(FdwHandle,10);

  //设置动态区区域属性和显示内容
  header:Tbx_5k_area_header;
  Text:String;
  Rst:Integer;
  Text:='123';
  header.AreaType:=6;
  header.AreaX:=0;
  header.AreaY:=0;
  header.AreaWidth:=4;
  header.AreaHeight:=32;
  header.DynamicAreaLoc:=0;
  header.Lines_sizes:=0 ;
  header.RunMode:=0;
  header.Timeout:=2 ;
  header.Reserved1:=0;
  header.Reserved2:=0;
  header.Reserved3:=0;
  header.SingleLine:=1;
  header.NewLine:=1 ;
  header.DisplayMode:=0;
  header.ExitMode:=0;
  header.Speed:=10;
  header.StayTime:=4;
  header.DataLen:=Length(Text);
  //更新动态区
  Rst:=SCREEN_SendDynamicArea(FdwHandle,header,Length(Text),PChar(Text));
  
  //删除动态区，指定编号删除，255-删除所有动态区
  Rst:=SCREEN_DelDynamicArea(FdwHandle,255);

//销毁连接句柄
//【创建句柄到销毁句柄中间一直保持连接，建议使用短连接，每次通信前创建连接，通信后销毁连接】
Destroy_Handle(FdwHandle);

//释放动态库
ReleaseSdk();
```

