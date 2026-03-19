#include <iostream>
#include <boost/asio.hpp>
#include <ostream>

void print(const boost::system::error_code& error_code)
{
    if (error_code) std::cerr << "Error code: " << error_code << std::endl;

    std::cout << "hello world async" << std::endl;
}

int main()
{
    boost::asio::io_context io;
    boost::asio::steady_timer timer(io, boost::asio::chrono::seconds(5));

    // timer.async_wait(&print);

    timer.wait();

    std::cout << "hello world" << std::endl;

    io.run();

    return 0;
}