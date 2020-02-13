program Led5KSDK;

uses
  Forms,
  MainFrm in 'MainFrm.pas' {MainForm};

{$R *.res}

begin
  Application.Initialize;
  Application.Title := 'Led5KSDK';
  Application.CreateForm(TMainForm, MainForm);
  Application.Run;
end.
