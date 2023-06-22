#pragma once

// Use LWIP without OS awareness
#define NO_SYS 1

// Conditional LWIP compilation
#define LWIP_SOCKET 0 // enable socket API
#define LWIP_ARP 1 // enable ARP functionality
#define LWIP_ETHERNET 1 // enable ethernet support (even if ARP is disabled)
#define LWIP_ICMP 1 // enable ICMP support (kills RFC 1122 compliance)
#define LWIP_RAW 1 // enable the application layer to hook into the IP layer
#define LWIP_DHCP 1 // enable DHCP module
#define LWIP_IPV4 1 // enable IPv4
#define LWIP_TCP 1 // enable TCP
#define LWIP_UDP 1 // enable UDP
#define LWIP_DNS 1 // enable DNS - UDP must be available
#define LWIP_ALTCP 1 // enable the altcp abstraction layer
#define LWIP_NETCONN 0 // enables the Netconn API

#define MEM_LIBC_MALLOC 0 // use malloc/free/realloc provided by the C library, not lwip's allocator
#define MEM_ALIGNMENT 4 // set to the alignment of the CPU (4 bytes or 2 bytes)
#define MEM_SIZE 4000 // the size of the heap in bytes

#define MEMP_NUM_TCP_SEG 32 // number of simultaneously queued TCP segments
#define MEMP_NUM_ARP_QUEUE 10 // number of simultaneously queued outgoing packets waiting for ARP requests to finish

#define PBUF_POOL_SIZE 24 // the number of buffers in the pbuf pool

#define TCP_MSS 1460 // TCP maximum segment size
#define TCP_WND (8 * TCP_MSS) // TCP sliding window size (must be at least 2 * TCP_MSS)
#define TCP_SND_BUF (8 * TCP_MSS) // TCP sender buffer space (bytes) - for performance should be at least 2 * TCP_MSS
#define TCP_SND_QUEUELEN ((4 * (TCP_SND_BUF) + (TCP_MSS - 1)) / (TCP_MSS)) // TCP sender buffer space (pbufs) - must be at least (2 * TCP_SND_BUF / TCP_MSS)

#define LWIP_NETIF_STATUS_CALLBACK 1 // supports a callback function whenever an interface changes its up/down status
#define LWIP_NETIF_LINK_CALLBACK 1 // supports a callback function from an interface whenever the link changes
#define LWIP_NETIF_HOSTNAME 1 // use DHCP_OPTION_HOSTNAME with netif's hostname field
#define LWIP_NETIF_TX_SINGLE_PBUF 1 // tries to put all data into one single pbuf - might involve memcpy's before transmitting that would not otherwise be needed, so use only if necessary!
#define DHCP_DOES_ARP_CHECK 0 // do an ARP check on the offered address
#define LWIP_DHCP_DOES_ACD_CHECK 0 // perform address conflict detection on the DHCP address

#define LWIP_TCP_KEEPALIVE 1 // enable TCP_KEEPIDLE, TCP_KEEPINTVL and TCP_KEEPCNT options processing

#define MEM_STATS 0 // enables mem.c stats
#define SYS_STATS 0 // enables system stats
#define MEMP_STATS 0 // enables memp.c pool stats
#define LINK_STATS 0 // enables link stats

#define LWIP_CHKSUM_ALGORITHM 3 // the checksum algorithm - not documented?

#define LWIP_ALTCP_TLS 1 // enables TLS support for ALTCP API
#define LWIP_ALTCP_TLS_MBEDTLS 1 // uses the inbuilt mbedtls port for altcp

#ifdef BUILD_DEBUG
#define LWIP_DEBUG 1 // enables debug message printing (subject to some conditions)
#define LWIP_STATS 1 // enables statistics collection
#define LWIP_STATS_DISPLAY 1 // compile the statistics output functions in

#define ALTCP_MBEDTLS_DEBUG LWIP_DBG_ON // set the debug level of the mbedtls file
#endif

// Disable debug messages we do not care about
#define ETHARP_DEBUG LWIP_DBG_OFF
#define NETIF_DEBUG LWIP_DBG_OFF
#define PBUF_DEBUG LWIP_DBG_OFF
#define API_LIB_DEBUG LWIP_DBG_OFF
#define API_MSG_DEBUG LWIP_DBG_OFF
#define SOCKETS_DEBUG LWIP_DBG_OFF
#define ICMP_DEBUG LWIP_DBG_OFF
#define INET_DEBUG LWIP_DBG_OFF
#define IP_DEBUG LWIP_DBG_OFF
#define IP_REASS_DEBUG LWIP_DBG_OFF
#define RAW_DEBUG LWIP_DBG_OFF
#define MEM_DEBUG LWIP_DBG_OFF
#define MEMP_DEBUG LWIP_DBG_OFF
#define SYS_DEBUG LWIP_DBG_OFF
#define TCP_DEBUG LWIP_DBG_OFF
#define TCP_INPUT_DEBUG LWIP_DBG_OFF
#define TCP_OUTPUT_DEBUG LWIP_DBG_OFF
#define TCP_RTO_DEBUG LWIP_DBG_OFF
#define TCP_CWND_DEBUG LWIP_DBG_OFF
#define TCP_WND_DEBUG LWIP_DBG_OFF
#define TCP_FR_DEBUG LWIP_DBG_OFF
#define TCP_QLEN_DEBUG LWIP_DBG_OFF
#define TCP_RST_DEBUG LWIP_DBG_OFF
#define UDP_DEBUG LWIP_DBG_OFF
#define TCPIP_DEBUG LWIP_DBG_OFF
#define PPP_DEBUG LWIP_DBG_OFF
#define SLIP_DEBUG LWIP_DBG_OFF
#define DHCP_DEBUG LWIP_DBG_OFF
