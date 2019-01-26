#ifndef ETH
#define ETH
//********************************************************************************************
//
// File : ethernet.h implement for Ethernet Protocol
//
//********************************************************************************************
//
// Copyright (C) 2007
//
// This program is free software; you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free Software
// Foundation; either version 2 of the License, or (at your option) any later
// version.
// This program is distributed in the hope that it will be useful, but
//
// WITHOUT ANY WARRANTY;
//
// without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
// PURPOSE. See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along with
// this program; if not, write to the Free Software Foundation, Inc., 51
// Franklin St, Fifth Floor, Boston, MA 02110, USA
//
// http://www.gnu.de/gpl-ger.html
//
//********************************************************************************************
#define ETH_TYPE_ARP_V		0x0806
#define ETH_TYPE_ARP_H_V	0x08
#define ETH_TYPE_ARP_L_V	0x06
#define ETH_TYPE_IP_V		0x0800
#define ETH_TYPE_IP_H_V		0x08
#define ETH_TYPE_IP_L_V		0x00

#define ETH_HEADER_LEN		14

#define ETH_DST_MAC_P		0
#define ETH_SRC_MAC_P		6
#define ETH_TYPE_H_P		12
#define ETH_TYPE_L_P		13

#define LOW(ushort) (ushort&0xFF)
#define HIGH(ushort) ((ushort>>8)&0xFF)

//********************************************************************************************
//
// Prototype function
//
//********************************************************************************************
//void eth_generate_packet ( ETH_HEADER eth_header );
WORD software_checksum( BYTE *rxtx_buffer, WORD len, DWORD sum);// refactor
void eth_generate_header ( BYTE *rxtx_buffer, const WORD_BYTES type, const unsigned char destMac[MAC_ADDRESS_SIZE]);
unsigned char ethCheckType(unsigned char *rxtx_buffer, unsigned short type);// todo refactor
unsigned char EthWaitPacket(unsigned char *rxtx_buffer, unsigned short type, unsigned short timeout);
#endif
