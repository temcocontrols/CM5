#ifndef _TCP_DEBUG_H
#define _TCP_DEBUG_H

#define TCP_PRINT_IDLE   0
#define TCP_PRINT_STR    1
#define TCP_PRINT_HEX    2 

void EthernetDebug_appcall(void);
void tcp_printf_hex(char *str,int nlength,char *des_str);//��ཫ84��ת��Ϊhex  bufferΪ256;
void tcp_printf_str(char *str);
#endif