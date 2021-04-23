# Как запрогать KUKA KR 10 R1100-2 b и в перспективе ещё что-то
Гайд, как в **SprutCAM** запустить симмуляцию этой параши
Ссылка на плейлист по теме: https://www.youtube.com/playlist?list=PLWVHi75wSxP4SbJSh5Muk088U5NEgaHeW
В частности нам понадобится урок номер 3 для добавления робота и тд.

## Скачивание SprutCam
    Ссылка на скачивание: https://download.sprutcam.com/links/SC14_release_Ru.zip
Установка тривиальная там вообще ничего делать не надо, нажал и ждёшь. После установки надо бы создать аккаунт для активации пробной лицензии на месяц. 

## Папка где хранятся конфигурации роботов
    C:\ProgramData\Sprut Technology\SprutCAM\Version 14\Machines\Schemas\Robots
Так же можно указывать свои директории, тогда их в конфигураторе на плюсик надо добавить.

## Где скачать эти злоебучие xml-описания роботов.
    Общая директория https://storage.sprutcam.com/robots/
    1. Для Kuka: https://storage.sprutcam.com/robots/Kuka/
    2. Для Fanuc: https://storage.sprutcam.com/robots/Fanuc/

## Смена инструмента в симмуляции.
Чтобы сменить инструмент в симуляции необходимо 
1. Иметь **3d модель** (формат? По идее любой, но в гайде фигурировал **.3dm**) нового инструмента и импортипровать его в проект (вкладка модель, папка - наверное оснастка).
2. Сохранить модель в формет osd (Save as)
3. Изменить XML файл описания робота(C:\ProgramData\Sprut Technology\SprutCAM\Version 14\Machines\Schemas\Robots\Kuka KR10 R1100-2\Kuka KR10_R1100-2.xml) следующим образом:
    ```
    ...
    <ToolBlockSelector>
		<ActiveNode DefaultValue="ToolBlock"/>
		<ToolBlock>
			<ImageFile DefaultValue="Images\Spindle_M.osd"/>
		</ToolBlock>
	</ToolBlockSelector>
    ...
    ```
4. Вроде бы, один из этих захватов наш: https://schunk.com/ru_ru/zakhvatnye-sistemy/series/egp/