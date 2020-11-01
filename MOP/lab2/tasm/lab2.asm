model SMALL
stack 100h

dataseg
MAX dw ?
MASS dw 1h,2h,3h,5h,4h,5,6h,7h,8h,9h

codeseg
startupcode
lea BX, MASS ; Загрузить адрес массива
mov CX, 10 ; Установить счетчик
mov AX, [BX] ; Первый элемент массива в аккумулятор
BEG: cmp [BX], AX ; Сравнить текущий элемент массива с
    ; максимумом
    jl NO ; он меньше
    mov AX, [BX] ; он больше
    NO: add BX, 2 ; Следующий элемент массива
loop BEG ; Возврат, если счетчик CX не пуст

mov MAX, AX

QUIT: exitcode 0
end