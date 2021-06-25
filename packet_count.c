#include <stdlib.h>
#include <stdio.h>
#include <pcap.h>


int main(int argc, char **argv) {

    pcap_t *handle;
    int counter=0;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct pcap_pkthdr header;
    const uint8_t *packet;

    handle = pcap_open_offline("/home/josh/Desktop/nn/test.pcap", errbuf);
    if (handle == NULL) {
        printf("Could not open file\n");
        exit(1);
    }

    while(packet = pcap_next(handle, &header)) {
        counter++;
        printf("packet number : %d\n", counter);
    }

    pcap_close(handle);
    return 0;
}