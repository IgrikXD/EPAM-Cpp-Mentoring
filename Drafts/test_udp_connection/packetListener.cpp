#include <iostream>
#include <string_view>
#include <boost/asio.hpp>

constexpr unsigned udp_port {55673};

class UDPListener {

	private:

		boost::asio::io_service & m_io_service;
		boost::asio::ip::udp::socket m_socket;
		boost::asio::ip::udp::endpoint m_endpoint;

	public:
		
		UDPListener(boost::asio::io_service & io_service, const unsigned src_udp_port) 
			: m_io_service{io_service}, m_socket{io_service} {

			m_endpoint.address(boost::asio::ip::address_v4::any());
			m_endpoint.port(src_udp_port);

			m_socket.open(boost::asio::ip::udp::v4());
    		m_socket.bind(m_endpoint);

		}

		~UDPListener() {

			m_socket.close();

		}

		void receive(void) {

			char buff[1024];

			std::cout << "UDP packet listener has been started. Wait for packets..." << std::endl;
			std::cout << "Press Ctrl+C for exit." << std::endl << std::endl;

			while (true) {
				
				boost::asio::ip::udp::endpoint sender_endpoint;
				int bytes = m_socket.receive_from(boost::asio::buffer(buff), sender_endpoint);
				
				std::cout << "Message received:" << std::endl;
				std::cout << std::string_view(buff, bytes) << std::endl;

			}

		}

};

int main(int argc, char * argv[]) {
	
	boost::asio::io_service io_service;
	
	UDPListener udp_receiver(io_service, udp_port);

	udp_receiver.receive();

	return 0;

}
