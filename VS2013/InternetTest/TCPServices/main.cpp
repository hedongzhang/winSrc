#include<stdlib.h>
#include<iostream>
#include<boost\asio.hpp>

using namespace std;
using namespace boost::asio;

void main()
{
	io_service serviceA;
	ip::tcp::acceptor accepter(serviceA,ip::tcp::endpoint(ip::tcp::v4(),1024));
	//while (true)
	//{
		ip::tcp::socket my_sock(serviceA);
		accepter.accept(my_sock);
		cout << "客户端：" << my_sock.remote_endpoint().address() << "连接上！" << endl;

		while (true)
		{
			char receive_string[1024] = { 0 };
			boost::system::error_code ec;
			long size = 0;
			size = my_sock.read_some(buffer(receive_string), ec);
			cout << "收到：" << receive_string << endl;

			my_sock.write_some(buffer(receive_string,size),ec);
			cout << "发送：" << receive_string << endl;
		}
	//}

	system("pause");
}