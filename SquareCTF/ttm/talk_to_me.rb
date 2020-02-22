














def receive_data(data)
    if data.match(/[a-z]/).nil?
        eval(data)
        p "I wish you would greet me the way I greeted you."
    else
        p "Sorry, I can't understand you."
    end







end

def main
    receive_data(ARGV[0])
end

if __FILE__ == $0
    main
end