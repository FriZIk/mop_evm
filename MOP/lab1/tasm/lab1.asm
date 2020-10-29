;X = 3A + (B + 5)/2 – C – 1. 


model SMALL
stack 100h ; Размер стека

dataseg
A dw 10 
B dw 20
C dw 5
X dw ?

codeseg 
startupcode ; макрокоманда
mov AX, A ;значение А в регистр AX
sal AX, 1 ; 2A в AX
add AX, A ; 3A в AX
mov BX, B ; B в BX
add BX, 5 ; B+5 в BX
sar BX, 1 ; (B+5)/2 в BX
add AX, BX ; 3A+(B+5)/2 в AX
sub AX, C ; 3A+(B+5)/2-C в AX
dec AX ; 3A+(B+5)/2-C-1 в AX
mov X, AX ; 3A+(B+5)/2-C-1 в X
;Конец работы
QUIT: exitcode 0
end