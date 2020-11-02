; Вариант 14
; Найти сумму отрицательных чисел. Массив слов.

model SMALL
stack 100h

dataseg 
sum dw ?;
arr dw 1h,-2h,3h,4h,-5h,6h,7h,8h,9h,10h


codeseg
startupcode
lea BX, arr
mov CX, 10 ; dlina masiva
xor AX, AX ; nul
xor DX, DX ;

BEG: cmp [BX],AX
    jns NO
    add DX,[BX] ;esli -
    NO: add BX,2 ; esli +
loop BEG

mov sum,DX ;v dop code

QUIT: exitcode 0
end

;65529 = -7
;65528 = -8