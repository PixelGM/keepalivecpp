#include "httplib/httplib.h"
#include <iostream>

void keepAlive() {
    httplib::Server svr;

    svr.Get("/", [](const httplib::Request&, httplib::Response& res) {
        std::cout << "Received a request at /" << std::endl;
        res.set_content("Bot is running!", "text/plain");
        });
    
    // svr.listen("localhost", 3000);
    svr.listen("0.0.0.0", 3000); // Change "localhost" to "0.0.0.0"
}

int main() {
    std::cout << "Server is ready." << std::endl;
    keepAlive();
    return 0;
}