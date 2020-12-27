dataseg
    s1 db ‘ text string for example $‘
    len dw 32
codeseg
    mov AX, @DATA
    mov DS, AX
    mov ES, AX
    mov CX, len ; размер строки
    lea DI, s1 ; адрес первого символа строки
    mov AL, ‘ ‘ ; разделитель слов
    xor BX, BX ; счетчик слов
    cld
next:
    repe scasb ; пропускаем пробелы
    je exit ; кроме пробелов ничего нет – закончить
    inc BX ; нарастить счетчик
    repne scasb ; ищем конец слова
    jne exit ; строка закончилась – закончить
    jmp next    
exit: ; BX – счетчик слов