#include <iostream>
#include <string>
#include <memory>

struct destintaion {
    std::string ip;
    std::string port;
    destintaion(std::string ip, std::string port):port(port), ip(ip){}
};

struct connection {
    std::string ip;
    std::string port;
    connection(std::string ip, std::string port):port(port), ip(ip) {}
};

connection conn(destintaion *dest) {
    std::shared_ptr<connection> p(new connection(dest->ip, dest->port));
    std::cout << "connect to " << p->ip;
    return *p;
}

void disconnect(connection *con) {
    std::cout << "disconnect " << con->ip;
}

void end_connect(connection *con) {
    disconnect(con);
}

void f(destintaion &d)
{
	connection conn = conn(&d);
	std::shared_ptr<connection> p(&conn, end_connection);
	std::cout << "connecting now(" << p.use_count() << ")" << std::endl;
}
