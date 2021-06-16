import pyshark
from scapy.all import *
import time
networkInterface = 'Wi-Fi'

capture = pyshark.LiveCapture(interface=networkInterface)
print("listening from %s" % networkInterface)
print('Details of Packets arrived:')
for packet in capture.sniff_continuously(packet_count=10):

    # packet)
    print('Length of capture:', len(packet))
    try:
        localtime = time.asctime(time.localtime(time.time()))
        # get packet content
        protocol = packet.transport_layer  # protocol type
        src_addr = packet.ip.src  # source address
        src_port = packet[protocol].srcport  # source port
        dst_addr = packet.ip.dst  # destination address
        dst_port = packet[protocol].dstport  # destination port
        packet_time = packet.sniff_time
        packet_timestamp = packet.sniff_timestamp
        print("Highest packet layer:", packet.highest_layer)
        print("Packet sniff time:", packet_time)
        print("Packet sniff timestamp:", packet_timestamp)
        print("Localtime:", localtime)
        print("Source IP-Source port:", src_addr, src_port)
        print("Destination IP- Dest. port:", dst_addr, dst_port)
        print("Protocol:", protocol)

    except AttributeError as e:
        # ignore packets other than TCP, UDP and IPv4
        pass
    print(" ")
