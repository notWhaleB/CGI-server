#include "main.h"

std::string runPath, sitePath, CGIPath;

#define DEFAULT_PORT 40000

int main(int argc, const char *argv[]) {
    runPath = argv[0];
    while(runPath.back() != '/') {
        runPath.pop_back();
    }

    uint16_t serverPort;
    if (argc < 2) {
        serverPort = DEFAULT_PORT;
    } else {
        serverPort = static_cast<uint16_t>(strtol(argv[1], nullptr, 10));
    }

    if (argc < 3) {
        sitePath = runPath + "webserver/site/";
    } else {
        sitePath = argv[2];
        if (sitePath[0] != '/') {
            sitePath = runPath + sitePath;
        }
    }

    if (argc < 4) {
        CGIPath = runPath + "webserver/";
    } else {
        CGIPath = argv[3];
        if (CGIPath[0] != '/') {
            CGIPath = runPath + CGIPath;
        }
    }

    HttpServer serv;
    std::cout << "Starting server..." << std::endl;
    serv.start_server(INADDR_ANY, serverPort, http1_1_handler);
    std::cout << "Server started on 0.0.0.0:" << serverPort << "." << std::endl;

    std::string cmd;
    while (std::cin >> cmd) {
        if (cmd == "stop") {
            std::cout << "Stopping server..." << std::endl;
            serv.stop_server();
            std::cout << "Server stopped." << std::endl;
            return 0;
        } else {
            std::cout << cmd << ": command not found" << std::endl;
        }
    }

    return 0;
}
