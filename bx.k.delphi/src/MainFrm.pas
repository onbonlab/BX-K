unit MainFrm;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls;

type
  TCallBackClose = procedure(dwHand:Cardinal;err_code:Integer); stdcall;

  Tbx_5k_area_header = packed record
  	AreaType:Byte;//一个字节
    AreaX:Word;  //2个字节
    AreaY:Word;
    AreaWidth:Word;
    AreaHeight:Word;
    DynamicAreaLoc:Byte;
    Lines_sizes:Byte ;
    RunMode:Byte;
    Timeout:Word ;
    Reserved1:Byte;
    Reserved2:Byte;
    Reserved3:Byte;
    SingleLine:Byte;
    NewLine:Byte ;
    DisplayMode:Byte;
    ExitMode:Byte;
    Speed:Byte;
    StayTime:Byte;
    DataLen:DWORD;   //4个字节
  end;

  Tbx_5k_sound  = packed record
   StoreFlag:Byte;
   SoundPerson:Byte;//一个字节
   SoundVolum:Byte;
   SoundSpeed:Byte;
   SoundDataMode:Byte;
   SoundReplayTimes:Integer;
   SoundReplayDelay:Integer;
   SoundReservedParaLen:Byte;
   SoundDataLen:Integer;
  end;

type
  TMainForm = class(TForm)
    btn1: TButton;
    btn2: TButton;
    btn6: TButton;
    btn5: TButton;
    btn3: TButton;
    btn4: TButton;
    btn10: TButton;
    btn11: TButton;
    btn7: TButton;
    btn8: TButton;
    btn9: TButton;
    procedure FormCreate(Sender: TObject);
    procedure btn1Click(Sender: TObject);
    procedure btn2Click(Sender: TObject);
    procedure btn6Click(Sender: TObject);
    procedure btn5Click(Sender: TObject);
    procedure btn11Click(Sender: TObject);
    procedure btn3Click(Sender: TObject);
    procedure btn4Click(Sender: TObject);
    procedure btn7Click(Sender: TObject);
    procedure btn10Click(Sender: TObject);
    procedure btn8Click(Sender: TObject);
    procedure btn9Click(Sender: TObject);
  private
    { Private declarations }
    FdwHandle:Cardinal;
  protected
    function GetAreaData(header:Tbx_5k_area_header;Text:string):string;
  public
    { Public declarations }
  end;


var
  MainForm: TMainForm;
  hDll:THandle;
  InitSdk: procedure(minorVer:Byte; majorVer:Byte);stdcall;  //初始化
  ReleaseSdk: procedure();stdcall;  //释放
  CreateBroadCast:function(broad_ip:PChar; broad_port:Integer; card_type:byte; barcode:PChar;Option:Byte; mode:Integer):Cardinal;stdcall;  //广播
  CreateComClient:function(com:byte;baudrate:DWORD;card_type:byte;mode:Integer;ScreenID:Word):Integer;stdcall; //串口
  CreateClient:function(led_ip:PChar;led_port:Integer;card_type:Byte;tmout_sec:Integer;mode:Integer; pFunc:TCallBackClose):Integer;stdcall; //网口
  SetTimeout:function(dwHand:Cardinal;nSec:Cardinal):Integer;stdcall; //设置超时
  CON_PING:function(dwHand:Cardinal):Integer;stdcall;//ping
  Destroy_Handle:procedure(dwHand:Cardinal);stdcall; //释放句柄
  SCREEN_SendDynamicArea:function(dwHand:Cardinal;header:Tbx_5k_area_header;TextLen:Word;AreaText:PChar):Integer;stdcall; //发送动态区
  SCREEN_DelDynamicArea:function(dwHand:Cardinal; DeleteAreaId:byte):Integer;stdcall; //删除动态区
  OFS_SendFileData:function(dwHand:Cardinal; overwrite:byte; pFileName:PChar; DisplayType:Word; PlayTimes:Byte;
            ProgramLife:PChar; ProgramWeek:Byte; ProgramTime:Byte; Period:PChar; AreaNum:Byte;AreaDataList:PChar;AreaDataListLen:Integer):Integer;stdcall;//发节目
  OFS_DeleteFile:function(dwHand:Cardinal; FileNumber:Word;pFileNameList:Pchar):Integer;stdcall; //删除节目
  CON_ControllerStatus:function(dwHand:Cardinal;pStatus:PChar; var len:Word):Integer;stdcall; //查询控制器状态
  SCREEN_ForceOnOff:function(dwHand:Cardinal;OnOffFlag:byte):Integer;stdcall;//强制开关机
  SCREEN_TimeTurnOnOff:function(dwHand:Cardinal;pTimer:PChar; nGroup:Integer):Integer;stdcall;//定时开关机
  SCREEN_SetBrightness:function(dwHand:Cardinal; BrightnessType:byte; CurrentBrightness:byte;BrightnessValue:PChar):Integer;stdcall;//调亮
  SCREEN_SendSound:function(dwHand:Cardinal;sound:Tbx_5k_sound;TextLen:Integer;AreaText:PChar):Integer;stdcall; //语音
  SCREEN_CancelTimeOnOff:function(dwHand:Cardinal):Integer;stdcall;//取消定时开关机
implementation

{$R *.dfm}

procedure TMainForm.FormCreate(Sender: TObject);
begin
  hDll := LoadLibrary('Led5kSDK.dll');
  if hDll < 32 then exit; //如果Dll无法加载则跳出
  InitSdk := GetProcAddress(hDll, 'InitSdk');
  ReleaseSdk := GetProcAddress(hDll, 'ReleaseSdk');
  CreateBroadCast := GetProcAddress(hDll, 'CreateBroadCast');
  CreateComClient:=GetProcAddress(hDll, 'CreateComClient');
  CreateClient:=GetProcAddress(hDll, 'CreateClient');
  SetTimeout := GetProcAddress(hDll, 'SetTimeout');
  CON_PING := GetProcAddress(hDll, 'CON_PING');
  Destroy_Handle:=GetProcAddress(hDll, 'Destroy');
  SCREEN_SendDynamicArea:=GetProcAddress(hDll, 'SCREEN_SendDynamicArea');
  SCREEN_DelDynamicArea:=GetProcAddress(hDll, 'SCREEN_DelDynamicArea');
  OFS_SendFileData:=GetProcAddress(hDll, 'OFS_SendFileData');
  OFS_DeleteFile:=GetProcAddress(hDll, 'OFS_DeleteFile');
  CON_ControllerStatus:=GetProcAddress(hDll, 'CON_ControllerStatus');
  SCREEN_ForceOnOff:=GetProcAddress(hDll, 'SCREEN_ForceOnOff');
  SCREEN_TimeTurnOnOff:=GetProcAddress(hDll, 'SCREEN_TimeTurnOnOff');
  SCREEN_SetBrightness:=GetProcAddress(hDll, 'SCREEN_SetBrightness');
  SCREEN_SendSound:=GetProcAddress(hDll, 'SCREEN_SendSound');
  SCREEN_CancelTimeOnOff:=GetProcAddress(hDll, 'SCREEN_CancelTimeOnOff');
end;

procedure CallBackClose(dwHand:Cardinal;err_code:Integer);stdcall;
begin
  //
end;

procedure SaveBinFile(pdata: PChar; nDataLen: Cardinal; szFileName: string);
var
  fp: file;
begin
  try
    if not DirectoryExists(ExtractFilePath(szFileName)) then
      CreateDir(ExtractFilePath(szFileName));
    AssignFile(fp, szFileName);
    Rewrite(fp, 1);
    BlockWrite(fp, pdata^, nDataLen);
  finally
    CloseFile(fp);
  end;
end;

function TMainForm.GetAreaData(header:Tbx_5k_area_header;Text:string):string;
var
  Len:Integer;
  SendBuf:string;
begin
  SetLength(SendBuf,SizeOf(header));
  CopyMemory(@SendBuf[1],@header,SizeOf(header));
  SendBuf:=SendBuf+Text;
  Len:=Length(SendBuf)+4;
  SendBuf:=Char(Len and $00FF)+Char((Len shr 8) and $00FF)+Char((Len shr 16) and $00FF)+Char((Len shr 24) and $00FF)+SendBuf;
  //SaveBinFile(@SendBuf[1],Length(SendBuf),'E:\1.bin');
  //ShowMessage(IntToStr(Length(SendBuf)));
  Result:=SendBuf;
end;

procedure TMainForm.btn1Click(Sender: TObject);
begin
  InitSdk(2,2);
end;

procedure TMainForm.btn2Click(Sender: TObject);
var
  IP:String;
  BarCode:String;
begin
  IP:='255.255.255.255';
  BarCode:='';
  FdwHandle:=CreateBroadCast(Pchar(IP),5007,$FE,PChar(BarCode),0,0);
  SetTimeout(FdwHandle,10);
end;

procedure TMainForm.btn6Click(Sender: TObject);
var
  header:Tbx_5k_area_header;
  Text:String;
  Rst:Integer;
begin
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

  Rst:=SCREEN_SendDynamicArea(FdwHandle,header,Length(Text),PChar(Text));
  ShowMessage(IntToStr(Rst));
end;

procedure TMainForm.btn5Click(Sender: TObject);
var
  Rst:Integer;
begin
  Rst:=CON_PING(FdwHandle);
  ShowMessage(IntToStr(Rst));
end;

procedure TMainForm.btn11Click(Sender: TObject);
begin
  ReleaseSdk();
end;

procedure TMainForm.btn3Click(Sender: TObject);
begin
  FdwHandle:=CreateComClient(4,57600,$FE,0,1);
  SetTimeout(FdwHandle,10);
end;

procedure TMainForm.btn4Click(Sender: TObject);
var
  IP:String;
begin
  IP:='192.168.89.56';
  FdwHandle:=CreateClient(PChar(IP),5005,$FE,2,0,@CallBackClose);
  SetTimeout(FdwHandle,10);
end;

procedure TMainForm.btn7Click(Sender: TObject);
var
  Rst:Integer;
begin
  Rst:=SCREEN_DelDynamicArea(FdwHandle,255);
  ShowMessage(IntToStr(Rst));
end;

procedure TMainForm.btn10Click(Sender: TObject);
begin
  Destroy_Handle(FdwHandle);
end;

procedure TMainForm.btn8Click(Sender: TObject);
var
  FileName:string;
  header:Tbx_5k_area_header;
  Text:String;
  SendBuf:string;
  Rst:Integer;
  ProgramLife,Period:string;
begin
  FileName:='P001';
  SetLength(ProgramLife,8);
  ProgramLife[1]:=Char($ff);
  ProgramLife[2]:=Char($ff);
  ProgramLife[3]:=Char($ff);
  ProgramLife[4]:=Char($ff);
  ProgramLife[5]:=Char($ff);
  ProgramLife[6]:=Char($ff);
  ProgramLife[7]:=Char($ff);
  ProgramLife[8]:=Char($ff);
  SetLength(Period,7);
  Period[1]:=Char(0);
  Period[2]:=Char(0);
  Period[3]:=Char(0);
  Period[4]:=Char(0);
  Period[5]:=Char(0);
  Period[6]:=Char(0);
  Period[7]:=Char(0);

  Text:='中文测试';
  header.AreaType:=0;
  header.AreaX:=0;
  header.AreaY:=0;
  header.AreaWidth:=8;
  header.AreaHeight:=32;
  header.DynamicAreaLoc:=$FF;
  header.Lines_sizes:=0 ;
  header.RunMode:=0;
  header.Timeout:=0 ;
  header.Reserved1:=0;
  header.Reserved2:=0;
  header.Reserved3:=0;
  header.SingleLine:=1;
  header.NewLine:=1 ;
  header.DisplayMode:=1;
  header.ExitMode:=0;
  header.Speed:=0;
  header.StayTime:=10;
  header.DataLen:=Length(Text);
  SendBuf:=GetAreaData(header,Text);
  Rst:=OFS_SendFileData(FdwHandle,1,PChar(FileName),0,1,PChar(ProgramLife),1,0,PChar(Period),1,PChar(SendBuf),Length(SendBuf));
  ShowMessage(IntToStr(Rst));
end;

procedure TMainForm.btn9Click(Sender: TObject);
var
  FileName:string;
  Rst:Integer;
begin
  FileName:='P001';
  Rst:=OFS_DeleteFile(FdwHandle,1,PChar(FileName));
  ShowMessage(IntToStr(Rst));
end;

end.
