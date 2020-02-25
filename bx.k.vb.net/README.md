# BX-5K/6K CSharp SDK
本项目为仰邦科技 BX-5K/6K 系列的 VB.net 实现，调用仰邦封装的动态库文件，任何人都可直接在此代码上进行添加与修改。

本项目由Visual Stuio 2010编写， 本 demo 中提供了 TCP 模式和RS485/232的简单使用方式。

* Delphi代码

  https://github.com/onbonlab/bx.k.VB.net/blob/master/src/MainFrm.pas

* 可执行程序

  https://github.com/onbonlab/bx.k.VB.net/releases



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


        Dim nResult As Long
        'nResult = Led5k.InitSdk(2, 2)
        Dim str As String = "192.168.89.122"
        Dim bName() As Byte
        Dim code As Encoding = Encoding.ASCII
        bName = code.GetBytes(str)
        Dim io() As Char
        io = code.GetChars(bName)


        Dim led_port As Integer '端口赋值
        led_port = 5005

        Dim card_type As Led5k.bx_5k_card_type
        card_type = Led5k.bx_5k_card_type.BX_Any '控制卡型号赋值

        Dim tmout_sec As Single
        tmout_sec = 1 '超时时间赋值

        Dim mode As Single
        mode = 0 '运行模式赋值，1代表动态模式

        Dim pCloseFunc As Long = 0 '回调函数，空值
        'hand = Led5k.CreateComClient(4, 57600, card_type, mode, 1)
        hand = Led5k.CreateClient(str, 5005, card_type, tmout_sec, mode, pCloseFunc)
        Label1.Text = CStr(hand)
        err = Led5k.CON_PING(hand)


        Dim AreaText As String
        Dim code As Encoding = Encoding.GetEncoding("gb2312")
        Dim str(), font() As Byte
        AreaText = "Hello,123"
        str = code.GetBytes(AreaText)

        Dim header As Led5k.bx_5k_area_header
        header.AreaType = 0             '固定值
        header.AreaX = 0 / 8          'X_像素坐标/最小单元
        header.AreaY = 0              'Y_像素坐标
        header.AreaWidth = 32 / 8     '宽_像素总数/最小单元
        header.AreaHeight = 16         '高_像素总数
        header.DynamicAreaLoc = 0     '动态区编号
        header.Lines_sizes = 0        '行间距
        header.RunMode = 0            '运行模式，0 动态区数据循环显示；1 动态区数据显示完成后静止显示最后1页数据；2动态区域数据循环显示，超过设定时间后动态区仍未更新时删除动态区。
        header.Timeout = 2            '动态区数据超时时间，单位为s
        header.Reserved1 = 0        '保留字
        header.Reserved2 = 0
        header.Reserved3 = 0
        header.SingleLine = 1         '是否单行显.，0x01 单行显示 0x02 多行显示
        header.NewLine = 1            '是否自动换行，0x01手动换行，文字中必须加换行符；0x02自动换行。
        header.DisplayMode = 1        '显示模式，其定义如下： 0x01 静止显示，0x02 快速打出，0x03 向左移动，0x04 向右移动，0x05向上移动，0x06 向下移动
        header.ExitMode = 0           '默认为0
        header.Speed = 0              '显示速度，0x00最快，0x18最慢
        header.StayTime = 1           '显示特技停留时间单位为0.5s
        header.DataLen = str.Length '数据长度包含转意字符

        err = Led5k.SCREEN_SendDynamicArea(hand, header, header.DataLen, str)
  
  //删除动态区，指定编号删除，255-删除所有动态区
  err=SCREEN_DelDynamicArea(hand,255);

//销毁连接句柄
//【创建句柄到销毁句柄中间一直保持连接，建议使用短连接，每次通信前创建连接，通信后销毁连接】
Destroy_Handle(hand);

//释放动态库
ReleaseSdk();
```

