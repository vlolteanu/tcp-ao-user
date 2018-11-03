#ifndef TCPAO_H
#define TCPAO_H

#include <linux/socket.h>

enum tcpao_kdf
{
	TCPAO_KDF_HMAC_SHA1    = 0,
	TCPAO_KDF_AES_128_CMAC = 1,
	TCPAO_KDF_DUMBASS      = 0xDEAD,
};

enum tcao_hmac
{
	TCPAO_HMAC_SHA_1_96   = 0,
	TCPAO_AES_128_CMAC_96 = 1,
	TCPAO_HMAC_DUMBASS    = 0xDEAD,
};

enum tcpao_flags
{
	TCPAO_OTHER_OPTS = 0x01,
	TCPAO_LOCAL_NAT  = 0x02,
	TCPAO_REMOTE_NAT = 0x04,
};

#define TCP_AO_MAX_MASTER_LEN 128

struct tcpao_key
{
	struct  __kernel_sockaddr_storage addr;

	uint8_t send_id;
	uint8_t recv_id;

	uint16_t flags;

	uint16_t kdf;
	uint16_t hmac;

	uint16_t master_len;
	uint8_t master[TCP_AO_MAX_MASTER_LEN];
} __attribute__((packed));

#define TCP_AO_REGISTER   50
#define TCP_AO_UNREGISTER 51

#endif // TCPAO_H
