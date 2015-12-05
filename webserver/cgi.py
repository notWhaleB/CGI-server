import sys
import re
import os


def static(filename):
    if not os.path.isfile(filename):
        return static("404.html")
    with open(filename) as file:
        return "\n".join(line for line in file.readlines())


def php(filename):
    if not os.path.isfile(filename):
        return static("404.html")
    return "\n".join(line for line in
                     os.popen("php " + sys.argv[1], "r").readlines())

if re.match(r"^.*\.php", sys.argv[1]):
    print(php(sys.argv[1]))
else:
    print(static(sys.argv[1]))
