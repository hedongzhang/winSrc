#include<stdlib.h>
#include<iostream>
#include<boost\asio.hpp>

using namespace std;
using namespace boost::asio;

void main()
{
	io_service io_serviceA;
	ip::udp::socket udp_socket(io_serviceA);
	ip::udp::endpoint local_address(ip::address::from_string("127.0.0.1"), 1080);

	udp_socket.open(local_address.protocol());
	udp_socket.bind(local_address);

	char receive_string[1024] = { 0 };

	while (true)
	{
		ip::udp::endpoint send_address;
		udp_socket.receive_from(buffer(receive_string), send_address);
		cout << "ÊÕµ½£º" << receive_string << endl;
		udp_socket.send_to(buffer(receive_string), send_address);
		system(receive_string);
		memset(receive_string, 0x00, sizeof(receive_string));
	}


	cout << "h" << endl;
	system("pause");
}