import sys
import re
import os

BASE_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

def read_bytes(filename):
    with open(filename, "rb") as file:
        byte = file.read(1)
        while byte != b"":
            yield byte
            byte = file.read(1)

def static(filename):
    if not os.path.isfile(filename):
        return static("404.html")
    with open(filename, "rb") as file:
        return bytes([i[0] for i in read_bytes(filename)])

def php(filename):
    if not os.path.isfile(filename):
        return static("404.html")
    return "\n".join(line for line in
                     os.popen("php " + sys.argv[1], "r").readlines()).encode("utf-8")

if re.match(r"^.*\.php", sys.argv[1]):
    os.write(1, php(sys.argv[1]))
else:
    os.write(1, static(sys.argv[1]))
