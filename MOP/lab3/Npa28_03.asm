;Дан массив из 10 байтов. Посчитать количество байтов, в которых
;сброшены 6 и 4 биты.

model SMALL
stack 100h
dataseg
count dw ?; количество элементов
MB db 0F1h,1h,0D8h,3h,50h,5h,55h,7h,0h,2Ah

    codeseg
    startupcode
    
    lea BX, MB
    mov CX, 10
    xor DX, DX

BEG:
    mov AL,[BX];
    test AL, 01010000b
    jnz NO ; биты 4 и 6 установлены
    inc DX ; иначе увличиваем счётчик
NO:
    inc BX;
    loop BEG;
; Конец цикла

mov count,DX;

QUIT: exitcode 0
end