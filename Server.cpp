#include <iostream>
#include <asio.hpp>

using std::string;
using std::cout;
using asio::ip::tcp;
using std::endl;

string read_(tcp::socket &socket){
    asio::streambuf buf;
    asio::read_until(socket, buf, "\n");

    string data = asio::buffer_cast<const char*>(buf.data());
    return data;
}
void send_(tcp::socket &socket, const string &message){
    const string msg = message + "\n";
    asio::write( socket, asio::buffer(msg));
}
int main() {
      asio::io_service io_service;
      tcp::acceptor acceptor_(io_service, tcp::endpoint(tcp::v4(), 1234 ));
      tcp::socket socket_(io_service);
      acceptor_.accept(socket_);
      string message = read_(socket_);
      cout << message << endl;
      send_(socket_, "Hello From Server!");
      cout << "Servent sent Hello message to Client!" << endl;
   return 0;
}