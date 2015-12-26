import sys
import re
import os
from urllib.parse import unquote

BASE_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

user_request = unquote(sys.argv[1])
serv_path = unquote(sys.argv[2])

def error_404():
    if os.path.isfile(serv_path + "404.html"):
        return static(serv_path + "404.html")
    else:
        return "Internal server error.".encode("utf-8")

def read_bytes(filename):
    with open(filename, "rb") as file:
        byte = file.read(1)
        while byte != b"":
            yield byte
            byte = file.read(1)

def static(filename):
    if not os.path.isfile(filename):
        return error_404()
    with open(filename, "rb") as file:
        return bytes([i[0] for i in read_bytes(filename)])

def php(filename):
    if not os.path.isfile(filename):
        return error_404()
    return "\n".join(line for line in
                     os.popen("php " + filename, "r").readlines()).encode("utf-8")

if re.match(r"^.*\.php", user_request):
    os.write(1, php(user_request))
else:
    os.write(1, static(user_request))
