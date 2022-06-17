# Hello_User
This application is welcomed by the user according to the current time.


Задача. Поприветствовать пользователя в зависимости от времени и выбранного языка.

23-5 good night

5-12 good morning

12-18 good day

18-23 good evening

Русский язык

1) Запуск приложения, интерфейс, ввод данных:

Для того чтобы работать с приложением, следует скачать с Google Disk папку Hello_Release, распаковать архив в удобное место, открыть папку bin и запустить helloUser.exe.

Язык по умолчанию - Английский. По центру окна появляется приветствие пользователя в зависимости от времени и языка, под приветствием - текущее системное время.

Для изменения языка следует выбрать в выпадающем списке нужный язык, каждый элемент выпадающего списка имеет иконку-флаг и название языка.

2) Обработка данных:

Так как приложение должно уметь работать на нескольких языках, используется Qt Linquist. По умолчанию язык приложения - Английский, на основе него происходят переводы, которые внесены в приложении Qt Linquist для каждого языка. В зависимости от выбранного языка загружается файл перевода. Функция tr(), в которую обернуты все строки, показывает, что данная строка должна быть переведена в соответствии с загруженным файлом перевода.

Функция connect связывает сигнал, испускающийся от comboBox и означающий изменение выбранного элемента, и слот (лямбда-функцию), которая вызывается при испускании сигнала. В этой функции происходит загрузка файла перевода, установка переводчика.

После этого происходит событие - changeEvent, в котором определяется, что язык изменён, то есть установлен новый файл перевода, и вызывается функция updateTime.

В функции updateTime происходит определение системного времени, обновление надписей на соответствующий язык в зависимости от загруженного файла перевода с использованием функции tr.

3) Вывод данных:

По центру окна появляется приветствие пользователя в зависимости от времени и языка, под приветствием - текущее системное время.

English

1) Application launch, interface, data entry:

In order to work with the application, you should download the Hello_Release folder from Google Disk, unzip the archive to a convenient location, open the bin folder and run helloUser.exe.

The default language is English. The user's greeting appears in the center of the window, depending on the time and language, under the greeting - the current system time.

To change the language, select the desired language in the drop-down list, each element of the drop-down list has a flag icon and the name of the language.

2) Data processing:

Since the application must be able to work in several languages, Qt Linquist is used. By default, the application language is English, which is the basis for the translations that are made in the Qt Linquist application for each language. Depending on the selected language, a translation file is loaded. The tr() function, in which all strings are wrapped, indicates that the given string should be translated according to the loaded translation file.

The connect function binds the signal emitted from the comboBox to indicate that the selected item has changed, and a slot (lambda function) that is called when the signal is emitted. In this function, the translation file is loaded, the translator is installed.

After that, an event occurs - changeEvent, in which it is determined that the language has been changed, that is, a new translation file has been installed, and the updateTime function is called.

In the updateTime function, the system time is determined, the inscriptions are updated for the corresponding language depending on the loaded translation file using the tr function.

3) Data output:

The user's greeting appears in the center of the window, depending on the time and language, under the greeting - the current system time.
