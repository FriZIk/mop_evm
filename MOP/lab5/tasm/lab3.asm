;Ввести с клавиатуры строку, состоящую из целых чисел, разделенных
;пробелами. Найти количество чисел больших, чем первое число строки.

model SMALL
stack 100h
dataseg

Ask db 0Ah,0Dh,'Vvedite stroku:','$'
Answer db 0Ah,0Dh, 'Resultat:','$'
Counter db 0 ; Счетчик чисел меньше первого
Num db 0 ; переменная общего назначения)
Inpstr db 80, ?, 82 dup( ? ) ; буфер ввода
Outputstr db 0Ah, 0Dh, ?, ?, 0Dh, 0Ah, '$'

max db -100;

codeseg
startupcode
Begin:
    lea DX, Ask
    mov AH, 09h
    int 21h
    lea DX, Inpstr
    mov AH, 0Ah
    int 21h
    ;Обработка
    lea BX, Inpstr+2 ;адрес начала введенной строки
    mov CL, Inpstr+1 ;кол-во введенных символов строки
    jmp Сycle0

Mult:
    ; Формируем число поразрядно 
    mov AL, 10;
    mul Num
    mov Num, AL
    jmp Cycle1

Сycle0:
    mov AL, [BX];
    add BL, 1
    cmp AL, ' '
	je NC
    
    ;Если всё таки цифра
    sub AL, '0'
    push AX
    jmp Mult

Cycle1:
    pop AX
    add Num, AL;
loop Сycle0

NC: 
    cmp Num,0
    je NC1

    ; Если это первое число в массиве то устанавливаем
    cmp max,-100
    ;cmp CL, Inpstr+1 ; это рабоатет ТОЛЬКО для однозначных чисел
    jnz SRAV
    ; записываем первое число массива в max
    mov AL, Num
    mov max, AL
    jmp Clear

SRAV:
    ; Сравниваем текущее число с первым
    mov AL,max

    cmp Num,AL; 
    js Clear;результат <0
    cmp Num,AL;
    jz Clear;результат равен 0
    inc Counter;

Clear:
    mov Num, 0

NC1:
    ; Если символы в строке кончились, то печататем результат 
    ; иначе продолжаем цикл 
    cmp CL, 0
	je Print
	loop Сycle0 

Print: 
    lea DX, Answer
    mov AH, 09h
    int 21h

	xor AX, AX
	mov AL, Counter
	mov BL, 10
	div BL
	add AH, '0' 
	add AL, '0' 
	cmp AL, 0
	mov Outputstr+2, AL
	mov Outputstr+3, AH	
	
	lea DX, Outputstr
	mov AH, 09h
	int 21h
; В массив вывода переносим два байта с первой и второй цифрой счетчика
; Вызываем прерывание 21h для вывода в консоль буфера вывода   

QUIT:
    exitcode 0
end

;==============================================;
; Одноразрядные тесты
; 1. 1 2 3 4                        Ответ: 3;
; 2. 4 3 2 1                        Ответ: 0;
; 3. 2 9 4 6 2 8 9                  Ответ: 5;
; 4. 1 1 1 1 1                      Ответ: 0;
; 5. 4 2 1 1 1                      Ответ: 0;
; Все одноразрядные тесты пройдены
;==============================================;
; Многоразрядные тесты
; 1. 11 12 13 14                    Ответ: 3;
; 2. 101 102 103 104                Ответ: 3;
; 3. 125 25 85 126                  Ответ: 1;
;==============================================;
