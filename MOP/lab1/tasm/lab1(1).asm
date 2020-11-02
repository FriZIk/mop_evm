model SMALL
stack 100h

dataseg
A dw 11 
B dw 21
C dw 6
X dw ?

codeseg 
startupcode

mov AX,A;
sar AX,2; A/4
mov BX,0;
sub BX,AX; -A/4
mov AX,C;
add AX,BX; C - A/4
mov BX,AX;
sal AX,3; 
sub BX,AX; -7(C-A/4)
mov AX,B;
add AX,AX;
add AX,B;
add BX,AX;-7(C – A/4) + 3B
sub BX,5;
mov X,BX;-7(C – A/4) + 3B – 5 

QUIT: exitcode 0
end

tasm lab -zi -l 
tlink -v
td 