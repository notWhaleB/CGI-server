# CGI-server

### Проект выполняет
Бегишев Никита Александрович, группа 146

### Что реализовано
##### Статика
Сервер способен раздавать статические файлы в текстовом и бинарном виде через HTTP протокол, используя POSIX совместимые системные вызовы, передача данных происходит через сокеты.

##### Многопоточность
Сервер поддерживает многопоточность, многопоточность реализована с помощью класса std::thread, который предоставлен стандартом языка c++11.

##### Динамический контент
Сервер может возвращать результат работы внешних программ. Для демонстрации возможностей используется препроцессор PHP. Связь между сервером и CGI разветвителем (Python скрипт cgi.py) осуществляется через popen(), также связь между разветвителем и внешними программами осуществляется через popen(), разветвитель контроллирует маршрутизацию запросов, а также возвращает ошибку 404 в случае её возникновения.

##### Конфигурирование
При запуске сервера можно указывать порт, директорию с сайтом, а также директорию с самим сервером.

##### Unicode совместимость
Сервер поддерживает unicode (UTF-8)


### Использование

##### Компиляция
```
cmake CMakeLists.txt
make
```
Для работы динамической части, необходимо установить интерпретатор php в систему.
```
sudo apt-get install php5-cli
```

##### Параметры запуска
```
./CGIServer port document_root cgi_root
```
* port – порт, на котором открывается соединение (40000 по умолчанию).
* document_root – директория с сайтом (webserver/site/ по умолчанию).
* cgi_root – директория с cgi.py и файлами ошибок (webserver/ по умолчанию).

Статику и многопоточность, например, можно протестировать на одном из моих проектов (https://github.com/notWhaleB/Diversity), в котором много статических файлов, и они загружаются асинхронно. В таком случае первым параметром при запуске нужно указать порт, а вторым директорию, куда будет склонирован проект Diversity.

