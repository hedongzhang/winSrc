#include<stdlib.h>
#include<iostream>
#include<boost\asio.hpp>

using namespace std;
using namespace boost::asio;

void main()
{
	io_service serviceA;
	ip::tcp::socket my_socket(serviceA);
	ip::tcp::endpoint aim_endpoint(ip::address_v4::from_string("127.0.0.1"),1024);

	boost::system::error_code ec;
	my_socket.connect(aim_endpoint,ec);

	char send_string[1024] = { 0 };
	while (true)
	{
		cout << "ÇëÊäÈë£º";
		cout << endl;
		cin >> send_string;
		cout << endl;

		my_socket.write_some(buffer(send_string), ec);
		memset(send_string, 0x00, sizeof(send_string));

		my_socket.read_some(buffer(send_string), ec);
		cout << "ÊÕµ½£º" << send_string << endl;

		memset(send_string, 0x00, sizeof(send_string));
	}


	system("pause");
}