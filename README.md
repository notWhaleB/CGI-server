# CGI-server

1. Сервер способен раздавать статические файлы в текстовом и бинарном виде через HTTP протокол, используя системные вызовы Unix-подобных ОС, передача данных происходит через сокеты.
2. Сервер поддерживает многопоточность, многопоточность реализована с помощью класса std::thread стандарта c++11.
3. Сервер может возвращать результат работы внешних программ, для демонстрации возможностей используется препроцессор PHP. Связь между сервером и CGI разветвителем (Python скрипт) осуществляется через popen(), также связь между разветвителем и внешними программами осуществляется через popen(), разветвитель контроллирует маршрутизацию запросов, а также возвращает ошибку 404 в случае её возникновения.

### Использование

##### Компиляция:
```
cmake CMakeLists.txt
make
```
Для работы динамической части, необходимо установить интерпретатор php в систему.
```
sudo apt-get install php5-cli
```

##### Параметры запуска:
```
./CGIServer port document_root cgi_root
```
* port – порт, на котором открывается соединение (40000 по умолчанию).
* document_root – директория с сайтом (webserver/site/ по умолчанию).
* cgi_root – директория с cgi.py и файлами ошибок (webserver/ по умолчанию).

