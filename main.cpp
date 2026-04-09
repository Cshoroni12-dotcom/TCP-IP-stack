//App → (your TCP/IP stack) → TAP device → Linux kernel → Network so appearently it works like this
fd = open("/dev/net/tap", O_RDWR); //virtual ethernet interface
struct eth_hdr {
    unsigned char dmac[6];
    unsigned char smac[6];
    uint16_t ethertype;
};
