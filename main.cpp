//App → (your TCP/IP stack) → TAP device → Linux kernel → Network so appearently it works like this
fd = open("/dev/net/tap", O_RDWR); //virtual ethernet interface
struct eth_hdr {
    unsigned char dmac[6];
    unsigned char smac[6];
    uint16_t ethertype;
};
read(fd, buf, size);              // 1. get data
struct eth_hdr *hdr = (struct eth_hdr *) buf;  // 2. interpret it

parse Ethernet

switch(ethertype)
     ARP handler
     (later) IP handler //appearently i dont quiet understand but it is how firewall works? uhh note from future, it isnt but kinda sim
//oh i get it 
// now we need "arp'
//so the arp solves the problem that we know ip but dont know mac (not apple btw)
struct arp_hdr {
    uint16_t hwtype;   // Ethernet = 1
    uint16_t protype;  // IPv4 = 0x0800
    uint16_t opcode;   // 1=request, 2=reply
};
// so this is the arp packet structure
//so this is like the bones in humans
//ok that was a terrible example
//so after i receive arp request if tar ip = my ip swap ?
//do arp (after)
//arping -I tap0 10.0.0.4 example runcode
int main() {
    int fd;
    char dev[IFNAMSIZ] = "tap0";

    // 1. create TAP device
    fd = tun_alloc(dev);

    // 2. (optional but important) configure it externally:
    // ip addr add 10.0.0.4/24 dev tap0
    // ip link set dev tap0 up

    // 3. NOW run your loop
    char buf[1500];

    while (1) {
        int len = read(fd, buf, sizeof(buf));
        struct eth_hdr *hdr = (struct eth_hdr *) buf;
        switch (ntohs(hdr->ethertype)) {
            case 0x0806: // ARP
                handle_arp(fd, buf, len);
                break;
            case 0x0800: // IPv4
                handle_ip(fd, buf, len);
                break;
        }
    }
}
