#include <iostream>
#include <string_view>
#include <boost/asio.hpp>

constexpr std::string_view telemetry_packet {"{\"speed\": -1, "
                                        	 "\"altitude\": 7760, "
											 "\"longitude\": 138.73863, "
											 "\"callsign\": \"Radiosonde Auto RX\", "
											 "\"time\": \"23:42:58\", "
											 "\"latitude\": -34.94502, "
											 "\"type\": \"PAYLOAD_SUMMARY\", "
											 "\"heading\": -1}"};
constexpr unsigned udp_port {55673};


class UDPBroadcastSender {

	private:

		boost::asio::io_service & m_io_service;
		boost::asio::ip::udp::socket m_socket;
		boost::asio::ip::udp::endpoint m_endpoint;

	public:
	
		UDPBroadcastSender(boost::asio::io_service & io_service, const unsigned src_udp_port) 
			: m_io_service{io_service}, m_socket{io_service} {

			m_endpoint.address(boost::asio::ip::address_v4::broadcast());
			m_endpoint.port(src_udp_port);

			m_socket.open(boost::asio::ip::udp::v4());

			m_socket.set_option(boost::asio::ip::udp::socket::reuse_address(true));
			m_socket.set_option(boost::asio::socket_base::broadcast(true));

		}

		~UDPBroadcastSender() {

			m_socket.close();

		}

		void send(const std::string_view & src_udp_packet) {
 
			if (m_socket.send_to(boost::asio::buffer(src_udp_packet, src_udp_packet.size()), m_endpoint))
				std::cout << "Packet sended!";
			else
				std::cout << "Error! Packet not send.";

		}

};

int main(int argc, char * argv[]) {
	
	boost::asio::io_service io_service;
	
	UDPBroadcastSender udp_sender(io_service, udp_port);

	udp_sender.send(telemetry_packet);

	return 0;

}
