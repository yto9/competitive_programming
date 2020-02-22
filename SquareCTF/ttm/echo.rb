require 'eventmachine'

module EchoServer
  def post_init
    puts "-- someone connected to the echo server!"
    send_data "Hello!\n"
  end

  def receive_data data
  begin
    send_data ">>>you sent: #{data}"
    p data.class
    if data.match(/[a-zA-Z]/).nil?
        eval(data)
        send_data "I wish you would greet me the way I greeted you.\n"
    else
        send_data "Sorry, I can't understand you.\n"
    end
    close_connection if data =~ /quit/i
  rescue SyntaxError => se
      send_data se.message
      send_data "\n"
      send_data se.exception.backtrace.join("\n")
  end
  end

  def unbind
    puts "-- someone disconnected from the echo server!"
  end
end

# Note that this will block current thread.
EventMachine.run {
  EventMachine.start_server "127.0.0.1", 8081, EchoServer
}