# BX-5K/6K CSharp SDK
本项目为仰邦科技 BX-5K/6K 系列的 C++ 实现，调用仰邦封装的动态库文件，任何人都可直接在此代码上进行添加与修改。

本项目由Visual Stuio 2010编写， 本 demo 中提供了 TCP 模式和RS485/232的简单使用方式。

* Delphi代码

  https://github.com/onbonlab/bx.k.cplus/blob/master/src/MainFrm.pas

* 可执行程序

  https://github.com/onbonlab/bx.k.cplus/releases



## 支持功能

* 更新动态区（单个）
* 删除动态区
* 更新节目（单个节目，节目可有多个普通区域）
* 删除节目
* 其他

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
InitSdk(2, 2);

//创建连接句柄
FdwHandle:Cardinal;
//TCP连接
byte[] led_ip = System.Text.Encoding.ASCII.GetBytes(textBox6.Text);
uint led_port = Convert.ToUInt32(textBox5.Text);
int hand = CreateClient(led_ip, led_port, (Led5kSDK.bx_5k_card_type)0xFE,2,0, null);

//RS485/232
//uint hand = ONNONLed5KSDKD.Led5kSDK.CreateComClient(com, 57600,(Led5kSDK.bx_5k_card_type)0xFE,0, ScreenID);

//设置通信超时时长，单位秒，如果不使用接口，默认10秒
SetTimeout(hand,10);

  //设置动态区区域属性和显示内容
  public static LedZK.bx_5k_area_header bx_5k1;
  bx_5k1.AreaType = 0x00;
  bx_5k1.AreaX = 0;
  bx_5k1.AreaY = 0;
  bx_5k1.AreaWidth = 8;
  bx_5k1.AreaHeight = 32;
  bx_5k1.DynamicAreaLoc = (byte)0;
  bx_5k1.Lines_sizes = 0;
  bx_5k1.RunMode = (byte)0;
  bx_5k1.Timeout = (byte)2;
  bx_5k1.Reserved1 = 0;
  bx_5k1.Reserved2 = 0;
  bx_5k1.Reserved3 = 0;
  byte[] SingleLine_list = new byte[2];
  SingleLine_list[0] = 0x01;
  SingleLine_list[1] = 0x02;
  int sll = 0;
  bx_5k1.SingleLine = SingleLine_list[sll];
  byte[] NewLine_list = new byte[2];
  NewLine_list[0] = 0x01;
  NewLine_list[1] = 0x02;
  int nl = 0;
  bx_5k1.NewLine = NewLine_list[nl];
  bx_5k1.DisplayMode = (byte)2;
  bx_5k1.ExitMode = 0;
  bx_5k1.Speed = (byte)1;
  bx_5k1.StayTime = 10;
  byte[] AText1 = System.Text.Encoding.GetEncoding("GBK").GetBytes("显示内容");
  bx_5k1.DataLen = AText1.Length;
  //更新动态区
  int err=SCREEN_SendDynamicArea(hand,header,Length(Text),PChar(Text));
  
  //删除动态区，指定编号删除，255-删除所有动态区
  err=SCREEN_DelDynamicArea(hand,255);

//销毁连接句柄
//【创建句柄到销毁句柄中间一直保持连接，建议使用短连接，每次通信前创建连接，通信后销毁连接】
Destroy_Handle(hand);

//释放动态库
ReleaseSdk();
```

