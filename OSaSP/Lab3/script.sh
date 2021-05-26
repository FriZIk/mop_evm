#!/bin/bash
DirName=$1
String=$2
if [[ $String = '' ]];then echo Пустая строка, завершаемся
else
    #WD=$(pwd)
    test=$(grep $String -rl $DirName)
    if [[ $test = '' ]];then
       echo Строка не найдена, введите другую
    else
        for i in $test ;do:
	    echo -n Чтобы вы хотели сделать с файлом $i
            read Choise
            if [[ $Choise = 'a' ]];then
                rm $i
                echo Файл $i удалён
            elif [[ $Choise = 'b' ]];then
                chmod -rwx $i # не работает
                echo К файлу $i ограничен доступ
            elif [[ $Choise = 'c' ]];then
                echo Файл $i оставлен без изменений
            fi
        done
    fi
fi
