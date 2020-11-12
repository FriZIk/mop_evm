    model SMALL
    stack 100h
    dataseg
MB db 04h,07h,11h,23h,04h,38h,3Fh,2Ah,0Dh,34h
    codeseg
    startupcode
    lea BX, MB ; BX – текущий адрес массива MB
    mov CX, 10 ; CX – счетчик числа итераций
BEG:
    mov AL, [BX] ; считать очередной байт массива
    test AL, 00000001b; установлен ли бит 0 ?
    jz BIT0CLR ; нет, бит 0 сброшен
    ; бит 0 установлен
    test AL, 0FFh ; четное число единиц ?
    jp OK ; да, больше ничего делать не надо
    or AL, 80h ; нечетное, дополнить до четного
    jmp short OK
BIT0CLR: ; бит 0 сброшен
    test AL, 0FFh ; четное число единиц ?
    jnp OK ; нет, больше ничего делать не нужно
    or AL, 80h ; четное, дополнить до нечетного
OK:
    mov [BX], AL ; записать измененный байт массива
    inc BX ; BX<-адрес очередн. элемента массива
    loop BEG
    ;Конец работы
QUIT: exitcode 0
end