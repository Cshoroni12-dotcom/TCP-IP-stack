//App → (your TCP/IP stack) → TAP device → Linux kernel → Network so appearently it works like this
fd = open("/dev/net/tap", O_RDWR); //virtual ethernet interface
struct eth_hdr {
    unsigned char dmac[6];
    unsigned char smac[6];
    uint16_t ethertype;
};
struct eth_hdr *hdr = (struct eth_hdr *) buf; // gives perm
read(fd, buf)

parse Ethernet

switch(ethertype)
     ARP handler
     (later) IP handler //appearently i dont quiet understand but it is how firewall works?
//oh i get it 
// now we need "arp'
//so the arp solves the problem that we know ip but dont know mac (not apple btw)
