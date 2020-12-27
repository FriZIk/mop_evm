// ******************************************************
//
// Brute-force HASH attacker
//
// v. 1.4
// Coded by -= Eagle =- in 2005
//
// ******************************************************
unit BruteHash_unit;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ExtCtrls, ComCtrls, Buttons, XPMan,
  { Hashes: }
  DCPtiger, DCPsha512, DCPsha256, DCPsha1, DCPripemd160,
  DCPripemd128, DCPhaval, DCPmd4, DCPcrypt2, DCPmd5;

type
  TfrmMain = class(TForm)
    OpenDialog: TOpenDialog;
    lblHash: TLabel;
    memHash: TMemo;
    rgHash: TRadioGroup;
    bbtnDicSelect: TBitBtn;
    bbtnStartStop: TBitBtn;
    bbtnAbout: TBitBtn;
    bbtnExit: TBitBtn;
    rgCase: TRadioGroup;
    pbWork: TProgressBar;
    ledPassword: TLabeledEdit;
    procedure FormCreate(Sender: TObject);
    procedure ErrMsg(ErrC: Byte; Sz: Word);
    procedure bbtnDicSelectClick(Sender: TObject);
    procedure bbtnStartStopClick(Sender: TObject);
    procedure bbtnAboutClick(Sender: TObject);
    procedure bbtnExitClick(Sender: TObject);
  end;
  HexString = String[2];

var
  frmMain: TfrmMain;
  StopFlag: Boolean = False;
  DicWords: Integer; { Total words in dictionnary }
  DicS: String;      { Dictionnary buffer }
  DicF: TextFile;    { Dictionnary file }

const
  HexDigits: array [0..15] of Char = '0123456789ABCDEF';

implementation

{$R *.dfm}

procedure TfrmMain.FormCreate(Sender: TObject);
begin
end;

// ******************************************************
// Converts byte to its heximal appearance
// ******************************************************
function HexByte(B: Byte): HexString;
var
  Temp: HexString;
begin
  Temp[0] := #2;
  Temp[1] := HexDigits[B ShR 4];
  Temp[2] := HexDigits[B And $F];
  HexByte := Temp;
end;

// ******************************************************
// Show error dialog
// ******************************************************
procedure TfrmMain.ErrMsg(ErrC: Byte; Sz: Word);
var
  ErrS: String;
begin
  case ErrC of
    1: ErrS := 'Invalid hash format!';
    2: ErrS := 'Invalid hash size (must be ' + IntToStr(Sz) + '-bit)';
    3: ErrS := 'Dictionnary file not found!';
  end;
  MessageDlg(ErrS, mtWarning, [mbOK], 0);
end;

// ******************************************************
// Main procedure
// ******************************************************
procedure TfrmMain.bbtnStartStopClick(Sender: TObject);
var
  H: TDCP_hash;            { DCP Hash class }
  D: array of Byte;        { Hash buffer }
  HashStr, S: String[128]; { Hash in string appearance }
  I: Byte;                 { Counter }
  PBP,                     { Progress bar position - if I'll use pbWork.Position,
                             this will slow down work process }
  N: Integer;              { Current word position in dictionnary }
  CaseIndex: Byte;         { Adjust case index (like PBP) }

// ******************************************************
// Subprocedure - sets flags to previous positions
// ******************************************************
procedure PrepareWorkStop(SF: Boolean; Nfo: String);
begin
  StopFlag := SF;
  pbWork.Position := pbWork.Min;
  bbtnStartStop.Caption := '&Start';
  if Nfo <> '' then
    if Nfo = #0 then
      begin
        ledPassword.Color := clRed;
        ledPassword.Text := 'Password not found!';
      end else
      begin
        ledPassword.Color := clLime;
        ledPassword.Text := Nfo;
      end;
end;

{TODO estimate function}
// ******************************************************
// Main procedure BEGIN
// ******************************************************
begin
  ledPassword.Color := clBtnFace;
  if pbWork.Position > pbWork.Min then
    begin
      PrepareWorkStop(True, '');
      Exit;
    end;
  ledPassword.Text := '';
  HashStr := '';
  for I := 0 to 3 do HashStr := HashStr + memHash.Lines[I];
  HashStr := UpperCase(HashStr);
  case rgHash.ItemIndex of
    0: H := TDCP_Haval.Create(Self);
    1: H := TDCP_MD4.Create(Self);
    2: H := TDCP_MD5.Create(Self);
    3: H := TDCP_RipeMD128.Create(Self);
    4: H := TDCP_RipeMD160.Create(Self);
    5: H := TDCP_SHA1.Create(Self);
    6: H := TDCP_SHA256.Create(Self);
    7: H := TDCP_SHA384.Create(Self);
    8: H := TDCP_SHA512.Create(Self);
    9: H := TDCP_Tiger.Create(Self);
  end;
  if Length(HashStr) * 4 <> H.GetHashSize then
    begin
      ErrMsg(2, H.GetHashSize);
      Exit;
    end;
  SetLength(D, H.GetHashSize div 8);
  for I := 1 to Length(HashStr) do
    if not (Char(HashStr[I]) in ['0'..'9', 'A'..'F']) then
      begin
        ErrMsg(1, 0);
        Exit;
      end;
  CaseIndex := rgCase.ItemIndex;
  pbWork.Max := 100;
  pbWork.Max := DicWords div 100 + 1;
  PBP := pbWork.Min;
  bbtnStartStop.Caption := 'S&top';
  AssignFile(DicF, OpenDialog.FileName);
  Reset(DicF);
  for N := 0 to DicWords - 1 do
    begin
      if StopFlag then
        begin
          PrepareWorkStop(False, '');
          Exit;
        end;
      if (PBP * 100 + 1) = N then
         begin
           Application.ProcessMessages;
           pbWork.Position := pbWork.Position + 1;
           Inc(PBP);
         end;
      ReadLn(DicF, DicS);
      case CaseIndex of
        0: S := UpperCase(DicS);
        1: S := LowerCase(DicS);
      end;
      H.Init;
      H.UpdateStr(DicS);
      H.Final(D[0]);
      H.Burn;
      S := '';
      for I := 1 to Length(D) do S := S + HexByte(D[I - 1]);
      if S = HashStr then
        begin
          PrepareWorkStop(False, DicS);
          Exit;
        end;
    end;
  CloseFile(DicF);
  H.Free;
  PrepareWorkStop(False, #0);
end;


// ******************************************************
// Dictionnary select dialog
// ******************************************************
procedure TfrmMain.bbtnDicSelectClick(Sender: TObject);
begin
  if OpenDialog.Execute then
    begin
      if not FileExists(OpenDialog.FileName) then
        begin
          bbtnStartStop.Enabled := False;
          ErrMsg(3, 0);
          Exit;
        end;
      bbtnStartStop.Enabled := True;
      FileMode := fmOpenRead;
      AssignFile(DicF, OpenDialog.FileName);
      Reset(DicF);
      DicWords := 0;
      repeat
        Inc(DicWords);
        ReadLn(DicF);
      until EOF(DicF);
      CloseFile(DicF);
      MessageDlg('Choosed dictionnary contains ' + IntToStr(DicWords) + ' words.', mtInformation, [mbOK], 0);
    end;
end;

// ******************************************************
// About dialog
// ******************************************************
procedure TfrmMain.bbtnAboutClick(Sender: TObject);
begin
  MessageDlg('BruteHash v1.4'+#13+#10+'Coded by --= Eagle =-- in 2005'+#13+#10+''+#13+#10+'This tools is created for brute-force'+#13+#10+'attacking known password hash.', mtInformation, [mbOK], 0);
end;

// ******************************************************
// Program exit
// ******************************************************
procedure TfrmMain.bbtnExitClick(Sender: TObject);
begin
  Halt;
end;

end.
