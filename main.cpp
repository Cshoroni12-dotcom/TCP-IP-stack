//App → (your TCP/IP stack) → TAP device → Linux kernel → Network so appearently it works like this
fd = open("/dev/net/tap", O_RDWR);
