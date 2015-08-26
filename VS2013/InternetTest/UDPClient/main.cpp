#include<stdlib.h>
#include<iostream>
#include<boost\asio.hpp>

using namespace std;
using namespace boost::asio;

void main()
{
	io_service io_clientA;
	ip::udp::socket udp_socket(io_clientA);
	ip::udp::endpoint local_address(ip::address::from_string("127.0.0.1"), 1080);

	udp_socket.open(local_address.protocol());
	//udp_socket.bind(local_address);

	char send_string[1024] = { 0 };

	while (true)
	{
		cout << "ÇëÊäÈë£º";
		cout << endl;
		cin >> send_string;
		cout << endl;

		udp_socket.send_to(buffer(send_string), local_address);
		memset(send_string, 0x00, sizeof(send_string));

		udp_socket.receive_from(buffer(send_string), local_address);
		cout << "ÊÕµ½£º" << send_string << endl;
		
		memset(send_string, 0x00, sizeof(send_string));
	}

	system("pause");
}