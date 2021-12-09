all:
	g++ Server.cpp -o Server -Iinclude/asio-1.20.0/include -lws2_32
	g++ Client.cpp -o Client -Iinclude/asio-1.20.0/include -lws2_32
	g++ AsyncServer.cpp -o Client -Iinclude/asio-1.20.0/include -IC:/C++\ Libraries/boost_1_64_0/boost -lboost_system -lws2_32
