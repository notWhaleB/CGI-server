#include "main.h"

std::string runPath;

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
