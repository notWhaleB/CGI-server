# CGI-server

### Using

##### Build
```
cmake CMakeLists.txt
make
```
To use the demo content requires php:
```
sudo apt-get install php5-cli
```

##### Run
```
./CGIServer port document_root cgi_root
```
* binding port (40000 by default).
* document_root – directory with a site (webserver/site/ by default).
* cgi_root – directory with cgi.py and error files (webserver/ by default).
