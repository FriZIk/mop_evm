program BruteHash;

uses
  Forms,
  BruteHash_unit in 'BruteHash_unit.pas' {frmMain};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TfrmMain, frmMain);
  Application.Run;
end.
