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
