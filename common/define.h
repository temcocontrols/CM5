#ifndef	DEFINE_H
#define	DEFINE_H

#include "types.h"
#include "e2prom.h"
#include "user_data.h"
#include "commsub.h"
#include "product.h"
#include "bacnet.h"



#define CRC_YES 1
#define CRC_NO 0

//#define BIG	1
//#define SMALL 2
//#define TINY 3
//#define VAV 4

#define READ_VARIABLES      3
#define WRITE_VARIABLES     6
#define MULTIPLE_WRITE		16
#define CHECKONLINE				0x19
#define CHECKONLINE_WIHTCOM	 0x18

#define TEMCO_MODBUS 		0xff

#define READ_COIL  			0X01
#define READ_DIS_INPUT 	0X02
#define READ_INPUT      0x04
#define WRITE_COIL 			0X05
#define WRITE_MULTI_COIL 0x0f 

#define READ_REMOTE_INPUT		0x09

#define DATABUFLEN			137

#define ORIGINALADDRESSVALUE	100
#define CALIBRATION_OFFSET    128 //allows us to store FLASH_CALIBRATION as an U18_T

// 199 is the highest address we can use when storing variables in the flash memory
#define 	EEP_SERINALNUMBER_WRITE_FLAG	199 
#define 	TOTAL_EE_PARAMETERS		208
 
#define DHCP   1
#define STATIC 0

#if ARM_MINI || ASIX_MINI
#define HI_COMMON_CHANNEL  32
#else  // TSTAT10
#define HI_COMMON_CHANNEL  12  // 8(UI) + 4(HSP counter)
#define COMMON_CHANNEL 			8
#endif

typedef	enum
{
	NOUSE = 0,
	BACNET_SLAVE,
	MODBUS_SLAVE,
	PTP_RS232_GSM,
	SUB_GSM,
	MAIN_ZIG,
	SUB_ZIG,
	MODBUS_MASTER,
	RS232_METER,
	BACNET_MASTER,
	MAX_COM_TYPE
}E_UART_TYPE;


#if (ARM_MINI || ASIX_MINI)
typedef struct 
{
	uint16_t baut;
	uint8_t type;
	uint8_t len;
	uint8_t cmd[10];
	uint32_t res;
}RS232_CMD;

extern RS232_CMD rs232_cmd;
void send_rs232_command(void);
#endif

#define BAC_MSTP 0
#define BAC_IP 1


//#define MODBUS 0 
//#define TCP_IP 1
//#define BAC_MSTP 2
//#define BAC_IP 3
//#define BAC_PTP 4
#define BAC_GSM 2

#define WR_DESCRIPTION_SIZE			31
#define AR_DESCRIPTION_SIZE			29
//#define ID_SIZE						4
#define AR_TIME_SIZE				46
#define WR_TIME_SIZE			    72
#define SCH_TIME_SIZE				1


#define PRODUCT_CM5		50
#define PRODUCT_MINI_BIG	35
#define PRODUCT_MINI_SMALL	35
#define PRODUCT_MINI_TINY	35
#define PRODUCT_MINI_VAV	35
#define PRODUCT_MINI_NEW_TINY	35

#define PRODUCT_MINI_ARM   74


#define PRODUCT_VAV   35

typedef struct
{
	U8_T serialNum[4];
	U8_T address; 	
	U8_T protocal;
	U8_T product_model;
	U8_T hardRev;
	U8_T baudrate;
	U8_T unit;
//	U8_T switch_tstat_val;
	U8_T IspVer;
	U8_T PicVer;
	U8_T update_status;
	U8_T  base_addr;
	U8_T  tcp_type;   /* 0 -- DHCP, 1-- STATIC */
	U8_T  ip_addr[4];
	U8_T  mac_addr[6];
	U8_T  	subnet[4];
	U8_T  	getway[4];
	U16_T 	tcp_port;
	U8_T  mini_type;
	U8_T  sub_port;
//	U8_T zigbee_or_gsm;
	U8_T point_sequence;
	U8_T main_port;
	U8_T external_nodes_plug_and_play;
	U8_T com_config[3];
	U16_T start_adc[11];
	U8_T refresh_flash_timer;

	U8_T network_number;
	U8_T  en_username;
	U8_T  cus_unit;

	U8_T  usb_mode;
	U8_T en_dyndns;
	U8_T en_sntp;	
	
	U16_T Bip_port;
	U16_T vcc_adc; // 
	U8_T network_master;
	
	U8_T fix_com_config;
//	U8_T backlight;
	U8_T LCD_time_off_delay;
	U8_T en_time_sync_with_pc;
	
	U8_T uart_parity[3];
	U8_T uart_stopbit[3];
//	U8_T network_ID[3]; // 3 RS485 port
	U16_T zigbee_module_id;
	U8_T dead_master;
	U8_T disable_tstat10_display;  // display icons and scrolling string
	lcdconfig display_lcd;
	U8_T start_month;
	U8_T start_day;
	U8_T end_month;
	U8_T end_day;

}STR_MODBUS;

typedef struct
{
	u8 enable; // whether enalbe adding module by hand
	u32 flag; 
	// bit 0: wifi
	// bit1. 10K ?????
	// bit2. HUM ?????
	// bit3. OCC ???
	// bit4. CO2 ????
	// bit5. Pressure ??
	// bit6. TVOC ???????
	// bit7. Light ????
	// bit8. ?????
	// bit9. Zigbee ??
	// bit10. PM2.5 ??
	// bit11. AI ????1KPT 
	// bit13. 
	
}STR_EX_MODULE;


typedef enum
{
	E_FLAG_WIFI,// bit 0: wifi
	E_FLAG_10K,// bit1. 10K ?????
	E_FLAG_HUM,// bit2. HUM ?????
	E_FLAG_OCC,// bit3. OCC ???
	E_FLAG_CO2,// bit4. CO2 ????
	E_FLAG_PRESS,// bit5. Pressure ??
	E_FLAG_TVOC,// bit6. TVOC ???????
	E_FLAG_LIGHT,// bit7. Light ????
	E_FLAG_VOICE,// bit8. voice
	E_FLAG_ZIGBEE,// bit9. Zigbee ??
	E_FLAG_PM25,// bit10. PM2.5 ??
	E_FLAG_PT1K,// bit11. AI ????1KPT 
	//E_FLAG_10K,// bit13. 
}E_EX_FLAG;



typedef enum {PORT_RS485_SUB,PORT_ZIGBEE,PORT_RS485_MAIN}E_UART_PORT;


extern U8_T uart0_baudrate;
extern U8_T uart1_baudrate;
extern U8_T uart2_baudrate;
extern U8_T temp_baut[3];
extern U8_T flag_temp_baut[3];

extern STR_EX_MODULE far ex_moudle;

extern	U8_T far bbmd_en;
extern	U16_T far mstp_network;

//typedef union
//{
//	unsigned char byte[4];
//	unsigned long longbyte;
//
//}UN_HIGH_COUNT;
//
//extern UN_HIGH_COUNT high_spd_counter[HI_COMMON_CHANNEL];
extern U32_T far high_spd_counter[HI_COMMON_CHANNEL];
extern U32_T far high_spd_counter_tempbuf[HI_COMMON_CHANNEL];
extern U8_T far high_spd_en[HI_COMMON_CHANNEL];
extern U32_T far Input_RPM[HI_COMMON_CHANNEL];
extern U8_T far flag_count_in[HI_COMMON_CHANNEL];
typedef	union
{
	unsigned int  word;
	unsigned char byte[2];
}UN_RELAY;



extern UN_Time far update_dyndns_time;
extern UN_Time Rtc;


extern U16_T far input_raw[MAX_INS];
extern U16_T far input_raw_back[MAX_INS];
extern U16_T far output_raw[MAX_OUTS];
extern U16_T far output_raw_back[MAX_OUTS];
extern U16_T subnet_rec_package_size;
extern U8_T max_dos;
extern U8_T max_aos;


extern U16_T far chip_info[6];
extern U8_T far high_spd_flag[HI_COMMON_CHANNEL];
extern U8_T far clear_high_spd[HI_COMMON_CHANNEL];
extern U8_T far InputLed[32];
extern U8_T OutputLed[24];
extern U8_T far input_type[32];
extern U8_T far input_type1[32];
	
extern STR_MODBUS  far Modbus;
extern U16_T count_flash;

extern uint8_t count_lcd_time_off_delay;
//extern u8 own_ip[4];


extern bit flag_logic_control;
extern U8_T flag_output_control;
extern UN_RELAY relay_value;
extern U8_T far flag_output;



extern S16_T far timezone;
extern U8_T far Daylight_Saving_Time;
extern U8_T far SntpServer[4];

extern U8_T far zigbee_exist;


extern U8_T far scan_port;
extern U8_T far scan_baut;

extern U8_T flag_Update_Sntp;
extern U8_T Update_Sntp_Retry;
extern U32_T count_sntp;

#define BASE_ADDR   0x30 



#define PIC_REV 0x01  // pic688


#define CM5_ADDRESS 254
#define PRODUCT_MODEL	50




typedef enum
{
 	UART_1200 = 0,
	UART_2400,
	UART_3600,
	UART_4800,
	UART_7200,
	UART_9600,
	UART_19200,
	UART_38400,
	//UART_57600,
	UART_76800,
	UART_115200,
	UART_921600,
	UART_57600,
	UART_BAUDRATE_MAX

}E_BAUD;
// define flash address



#if (ARM_MINI || ARM_CM5 || ARM_TSTAT_WIFI)

#define		SW_OFF 	 0
#define 	SW_HAND	 2
#define		SW_AUTO	 1


typedef enum{
	//EEP_IP = 0x19
//	EEP_MAC = 0x06,	  // 6 bytes 0x06 - 0x0b
//	EEP_IP = 0x19,  // 4 bytes	  0x19 - 0x1c
//	EEP_SUBNET = 0x1d, // 4 bytes  0x1d - 0x20
//--- other thing
	EEP_SERIALNUMBER_LOWORD = 0 + USER_BASE_ADDR,             
	EEP_SERIALNUMBER_HIWORD = 2 + USER_BASE_ADDR,
	EEP_NO_USED1,  // NO USED
	EEP_DYNDNS_PROVIDER, 
	EEP_ADDRESS						= 6 + USER_BASE_ADDR,
	EEP_EN_SNTP,   
	EEP_HARDWARE_REV,			// same as bootloader
 	EEP_UART0_BAUDRATE,				//	9
	EEP_EN_DYNDNS,     
  EEP_ADDRESS_PLUG_N_PLAY ,
	EEP_TIME_ZONE_HI,    
	EEP_TIME_ZONE_LO,  
//	EEP_TCP_TYPE,
	EEP_MINI_TYPE = 14,   // same as bootloader
	EEP_ISP_REV = 15,		// same as bootloader
	//EEP_GETWAY = 16 + USER_BASE_ADDR,  // 4 bytes
	// 16 is used for EEP_UPDATE_STATUS
	EEP_VRESION_HI = 18,
	EEP_VERSION_LO,
	
	EEP_NETWORK = 20 + USER_BASE_ADDR,
	EEP_MSTP_NETWORK_HI,
	EEP_MSTP_NETWORK_LO,
	EEP_BBMD_EN,
	
	EEP_ETR_REBOOT,
	EEP_DAYLIGHT_SAVING_TIME,
	EEP_NETWORK_MASTER, 
	
	EEP_DYNDNS_UPDATE_LO,  // 27
	EEP_DYNDNS_UPDATE_HI,

	EEP_COM0_CONFIG = 29 + USER_BASE_ADDR,
  EEP_COM1_CONFIG,
	EEP_COM2_CONFIG,
	EEP_EN_NODE_PLUG_N_PLAY,
	EEP_OUTPUT_MODE,//EEP_NO_USED20,  // NO USED 33
	EEP_REFRESH_FLASH,
  
	EEP_CPU_TYPE = 38,
	EEP_APP2BOOT_TYPE = 39,
	
	EEP_MAC = 40	,
	EEP_TCP_TYPE = EEP_MAC + 6	,
	EEP_IP = EEP_MAC + 7,
	EEP_SUBNET = EEP_MAC + 11,
	EEP_GETWAY = EEP_MAC + 15 ,
	EEP_TCP_SERVER = EEP_MAC + 19 ,
	EEP_PORT_HIGH,
	EEP_PORT_LOW,
 	
	EEP_OUT_1V,
	EEP_OUT_2V = EEP_OUT_1V + 2,
	EEP_OUT_3V = EEP_OUT_1V + 4,
	EEP_OUT_4V = EEP_OUT_1V + 6,
	EEP_OUT_5V = EEP_OUT_1V + 8,
	EEP_OUT_6V = EEP_OUT_1V + 10,
	EEP_OUT_7V = EEP_OUT_1V + 12,
	EEP_OUT_8V = EEP_OUT_1V + 14,
	EEP_OUT_9V = EEP_OUT_1V + 16,
	EEP_OUT_10V = EEP_OUT_1V + 18,


	EEP_UART1_BAUDRATE = EEP_OUT_10V + 2,
	EEP_UART2_BAUDRATE,
	
	EEP_SD_BLOCK_A1,
	EEP_SD_BLOCK_A12 = EEP_SD_BLOCK_A1 + 22,
	EEP_SD_BLOCK_D1 = EEP_SD_BLOCK_A12 + 2,
	EEP_SD_BLOCK_D12 = EEP_SD_BLOCK_D1 + 22,	
	

	EEP_SWITCH = 146 + USER_BASE_ADDR, 
	EEP_GSM_SEVER_OR_CLIENT,

	EEP_GSM_IP1,
	EEP_GSM_IP2,
	EEP_GSM_IP3,
	EEP_GSM_IP4,
	EEP_GSM_TCP_PORT_LO,
	EEP_GSM_TCP_PORT_HI,

	EEP_USER_NAME,  
	EEP_CUS_UNIT,  
	EEP_PANEL_NUMBER,	  
	EEP_MAX_MASTER,//EEP_STATION_NUM,	 
	
	EEP_SERIALNUMBER_WRITE_FLAG,

	EEP_SNTP_SERVER1,	
	EEP_SNTP_SERVER2,
	EEP_SNTP_SERVER3,
	EEP_SNTP_SERVER4,  

	EEP_INSTANCE1, // 163
	EEP_INSTANCE2,
	EEP_INSTANCE3,
	EEP_INSTANCE4,
	
	EEP_REMOTE_SERVER1,  // 167
	EEP_REMOTE_SERVER2,
	EEP_REMOTE_SERVER3,
	EEP_REMOTE_SERVER4,

//	EEP_PORT_LOW = 171 + USER_BASE_ADDR,
//	EEP_PORT_HIGH,

	EEP_SNTP_TIME1,
	EEP_SNTP_TIME2,
	EEP_SNTP_TIME3,
	EEP_SNTP_TIME4,
	

	EEP_BAC_VENDOR_ID_LO , // 175
	EEP_VCC_ADC_LO,
	EEP_VCC_ADC_HI,
	EEP_FIX_COM_CONFIG,  // 178
	
		
	EEP_SD_BLOCK_HI1 = 179 + USER_BASE_ADDR,  // LOW BYTE -> Analog, high BYTE -> Digital
	EEP_SD_BLOCK_HI12 = EEP_SD_BLOCK_HI1 + 12,
	

	
	EEP_UART0_PARITY = 191 + USER_BASE_ADDR,
	EEP_UART2_PARITY = 192 + USER_BASE_ADDR,
	
	EEP_UART0_NETWORK = 193 + USER_BASE_ADDR,
	EEP_UART1_NETWORK = 194 + USER_BASE_ADDR,
	EEP_UART2_NETWORK = 195 + USER_BASE_ADDR,
	
	EEP_UART0_STOPBIT = 196 + USER_BASE_ADDR,
	EEP_UART2_STOPBIT = 197 + USER_BASE_ADDR,
	
	EEP_REBOOT_COUNTER = 198 + USER_BASE_ADDR, // NO USED
	EEP_DEAD_MASTER,

	EEP_BACNET_PORT_LO = 200 + USER_BASE_ADDR,  
	EEP_BACNET_PORT_HI = 201 + USER_BASE_ADDR,  	
	EEP_BACKLIGHT = 202 + USER_BASE_ADDR,   // no used
	EEP_EN_TIME_SYNC_PC = 203 + USER_BASE_ADDR, 
	
	EEP_PT1K_PARA_LO = 204 + USER_BASE_ADDR, 
	EEP_PT1K_PARA_HI,
	
	EEP_PIR_SENSOR_ZERO = 206 + USER_BASE_ADDR, 
	EEP_PIR_SENSETIVITY,
	EEP_OverrideTimer,
	
	EEP_EX_MOUDLE_EN = 209 + USER_BASE_ADDR, 
	EEP_EX_MOUDLE_FLAG1 = 210 + USER_BASE_ADDR,
	EEP_EX_MOUDLE_FLAG2,
	EEP_EX_MOUDLE_FLAG3,
	EEP_EX_MOUDLE_FLAG4,
	
	EEP_LCD_TIME_OFF_DELAY, // 214

	EEP_VOC_BASELINE1,
	EEP_VOC_BASELINE2,
	EEP_VOC_BASELINE3,
	EEP_VOC_BASELINE4,

	EEP_RUNNING_TIME1,
	EEP_RUNNING_TIME2,
	EEP_RUNNING_TIME3,
	EEP_RUNNING_TIME4,
	
	EEP_WRITE_WIFI_MAC,
	EEP_DISABLE_T10_DIS,
	EEP_BAC_VENDOR_ID_HI,
	
	EEP_DLS_START_MON, // DAYLIGHT SAVING TIME START MONTH
	EEP_DLS_START_DAY, // DAYLIGHT SAVING TIME START DAY
	EEP_DLS_END_MON, // DAYLIGHT SAVING TIME END MONTH
	EEP_DLS_END_DAY, // DAYLIGHT SAVING TIME END DAY
	
	MAX_EEP_CONSTRANGE = 255,
}E_EEP;


#endif




#if (ASIX_MINI || ASIX_CM5)
typedef enum{
	//EEP_IP = 0x19
	EEP_MAC = 0x06,	  // 6 bytes 0x06 - 0x0b
	EEP_IP = 0x19,  // 4 bytes	  0x19 - 0x1c
	EEP_SUBNET = 0x1d, // 4 bytes  0x1d - 0x20
//--- other thing
	EEP_SERIALNUMBER_LOWORD = 0 + USER_BASE_ADDR,             
	EEP_SERIALNUMBER_HIWORD = 2 + USER_BASE_ADDR,
	EEP_LCD_TIME_OFF_DELAY,//EEP_NO_USED1,  // NO USED
	EEP_DYNDNS_PROVIDER, 
	EEP_ADDRESS						= 6 + USER_BASE_ADDR,
	EEP_EN_SNTP,   
	EEP_HARDWARE_REV,
 	EEP_UART0_BAUDRATE,				//	63
	EEP_EN_DYNDNS,     
  EEP_ADDRESS_PLUG_N_PLAY ,
	EEP_TIME_ZONE_HI,    
	EEP_TIME_ZONE_LO,  
	EEP_TCP_TYPE,
	EEP_MINI_TYPE,
	EEP_GETWAY = 16 + USER_BASE_ADDR,  // 4 bytes
	
	EEP_VRESION_HI = 18,
	EEP_VERSION_LO,
	
	EEP_NETWORK = 20 + USER_BASE_ADDR,
	EEP_MSTP_NETWORK_HI,
	EEP_MSTP_NETWORK_LO,
	EEP_BBMD_EN,
	
	EEP_ETR_REBOOT,
	EEP_DAYLIGHT_SAVING_TIME,
	EEP_NETWORK_MASTER, 
	
	EEP_DYNDNS_UPDATE_LO,  // 20
	EEP_DYNDNS_UPDATE_HI,

	EEP_COM0_CONFIG = 29 + USER_BASE_ADDR,
  EEP_COM1_CONFIG,
	EEP_COM2_CONFIG,
	EEP_EN_NODE_PLUG_N_PLAY,
	EEP_OUTPUT_MODE,
	EEP_REFRESH_FLASH,
   	
	EEP_OUT_1V,
	EEP_OUT_2V,
	EEP_OUT_3V,
	EEP_OUT_4V,
	EEP_OUT_5V,
	EEP_OUT_6V,
	EEP_OUT_7V,
	EEP_OUT_8V,
	EEP_OUT_9V,
	EEP_OUT_10V,

	EEP_VCC_ADC_LO,
	EEP_VCC_ADC_HI,
	EEP_FIX_COM_CONFIG,
	EEP_UART0_PARITY,
	EEP_UART2_PARITY,
	EEP_PANEL_NUMBER,

	EEP_UART1_BAUDRATE,
	EEP_UART2_BAUDRATE,
	
	EEP_SD_BLOCK_A1 = 53 + USER_BASE_ADDR,
	EEP_SD_BLOCK_A12 = 75 + USER_BASE_ADDR,
	EEP_SD_BLOCK_D1 = 77 + USER_BASE_ADDR,
	EEP_SD_BLOCK_D12 = 99 + USER_BASE_ADDR,	
	
	EEP_DEAD_MASTER = 101 + USER_BASE_ADDR,
	EEP_NO_USED27 = 102 + USER_BASE_ADDR, // NO USED
	EEP_NO_USED71 = 145 + USER_BASE_ADDR, // NO USED


	EEP_SWITCH = 146 + USER_BASE_ADDR, 
	EEP_GSM_SEVER_OR_CLIENT,

	EEP_GSM_IP1,
	EEP_GSM_IP2,
	EEP_GSM_IP3,
	EEP_GSM_IP4,
	EEP_GSM_TCP_PORT_LO,
	EEP_GSM_TCP_PORT_HI,

	EEP_USER_NAME,  
	EEP_CUS_UNIT,  
	EEP_USB_MODE,	   // NO USED
	EEP_STATION_NUM,	  // no used

	EEP_SERIALNUMBER_WRITE_FLAG,

	EEP_SNTP_SERVER1,	
	EEP_SNTP_SERVER2,
	EEP_SNTP_SERVER3,
	EEP_SNTP_SERVER4,  

	EEP_INSTANCE1, // 163
	EEP_INSTANCE2,
	EEP_INSTANCE3,
	EEP_INSTANCE4,
	
	EEP_REMOTE_SERVER1,  // 167
	EEP_REMOTE_SERVER2,
	EEP_REMOTE_SERVER3,
	EEP_REMOTE_SERVER4,

	EEP_PORT_LOW = 171 + USER_BASE_ADDR,
	EEP_PORT_HIGH,

	EEP_SNTP_TIME1,
	EEP_SNTP_TIME2,
	EEP_SNTP_TIME3,
	EEP_SNTP_TIME4,
	
	EEP_BAC_VENDOR_ID,  // 177

	EEP_SD_BLOCK_HI1 = 181 + USER_BASE_ADDR,  // LOW BYTE -> Analog, high BYTE -> Digital
	EEP_SD_BLOCK_HI12 = EEP_SD_BLOCK_HI1 + 12,
	
	EEP_BACNET_PORT_LO = 200 + USER_BASE_ADDR,
	EEP_BACNET_PORT_HI,
	EEP_BACKLIGHT,
	EEP_EN_TIME_SYNC_PC,
	
	EEP_REBOOT_COUNTER,
	EEP_NO_USED114 = 207 + USER_BASE_ADDR, 


	MAX_EEP_CONSTRANGE = 255,
}E_EEP;
#endif


#define SCHEDUAL_MODBUS_ADDRESS		200

typedef enum {
	MODBUS_COIL_OUTPUT_START = 0,
	MODBUS_COIL_OUTPUT_END = MODBUS_COIL_OUTPUT_START + MAX_OUTS - 1,
	
	MODBUS_COIL_INPUT_START = 64,
	MODBUS_COIL_INPUT_END = MODBUS_COIL_INPUT_START + MAX_INS - 1,
};

typedef enum {

	MODBUS_SERIALNUMBER_LOWORD = 0,             
	MODBUS_SERIALNUMBER_HIWORD	= 2,
	MODBUS_FIRMWARE_VERSION_NUMBER_LO   	= 4  ,
	MODBUS_FIRMWARE_VERSION_NUMBER_HI,
	MODBUS_ADDRESS					= 6,
	MODBUS_PRODUCT_MODEL,  // 7
	MODBUS_HARDWARE_REV,  // 8

 	
//	MODBUS_INIT_WR_TIME, 
	MODBUS_PIC = 9,
  MODBUS_ADDRESS_PLUG_N_PLAY= 10,
//	MODBUS_TIME_ZONE = 11,	

	MODBUS_UART0_BAUDRATE = 12,   // for uart0
	MODBUS_EN_NODES_PLUG_N_PLAY,//	 	nodes_plug_and_play
//	MODBUS_DAYLIGHT_ENABLE,
//	MODBUS_DAYLIGHT_STATUS,
//	MODBUS_RESET_FLASH,	
	MODBUS_ISP_VER = 14,
// registers needed for updating status
	MODBUS_UPDATE_STATUS = 16,	
	MODBUS_UNIT =17,
	MODBUS_UART1_BAUDRATE,
	MODBUS_UART2_BAUDRATE,

	MODBUS_MSTP_OR_MODBUS = 21, 
	MODBUS_SNTP_SERVER1,  // 22
	MODBUS_SNTP_SERVER2,
	MODBUS_SNTP_SERVER3,
	MODBUS_SNTP_SERVER4,
	MODBUS_SNTP_TIMEZONE, // 26
	MODBUS_SNTP_EN,		//  27
	MODBUS_TIMEZONE_SUMMER,
	
	MODBUS_MSTP_MAX_MASTER,
	
	MODBUS_DEAD_MASTER,

	MODBUS_INSTANCE_HI = 32, 
	MODBUS_TEST_CMD = 33,
	MODBUS_MINI_TYPE,
	MODBUS_INSTANCE_LO,  // 	
	MODBUS_PANEL_NUMBER,
	MODBUS_BACKLIGHT, 
	MODBUS_BIP_PORT, // 38 	
	MODBUS_EN_TIME_SYNC_PC,// 39 // no used
	MODBUS_EN_USER,  // 40
	MODBUS_EN_CUS_UNIT,

	MODBUS_STATION_NUM,  // MSTP ID
	MODBUS_EN_DYNDNS,  // 43
	MODBUS_DYNDNS_PROVIDER,// 44
	MODBUS_DYNDNS_UPDATE,// 45
	MODBUS_NETWORK,  // 46
	MODBUS_MSTP_NETWORK, // 47
	MODBUS_BBMD_EN,  // 48
	MODBUS_NETWORK_MASTER,
	
// FOR SEAN  
	MODBUS_PIC_WATCHDOG = 50,

//	MODBUS_CHIP1_HW,  // PIC
//	MODBUS_CHIP2_HW,  // C8051F023
//	MODBUS_CHIP3_HW,  // LED
//	MODBUS_CHIP4_HW,  // SWITCH
//	MODBUS_CHIP1_SW,   
//	MODBUS_CHIP2_SW,
//	MODBUS_CHIP3_SW,
//	MODBUS_CHIP4_SW,
	MODBUS_NETWORK_UART0,
	MODBUS_NETWORK_UART1,
	MODBUS_NETWORK_UART2,
	
	MODBUS_INPUT_MOUDLE,  // 54 --> 0 is without pt, 1 is with PT sensor
	MODBUS_TOP_FW,
	MODBUS_TOP_HW,

  MODBUS_COM0_TYPE = 59,
	MODBUS_COM1_TYPE,
	MODBUS_COM2_TYPE,

	MODBUS_REFRESH_FLASH,
	MODBUS_FLASH_TIME_COUNT,

	MODBUS_OUTPUT_1V = 70, 
	MODBUS_OUTPUT_2V,
	MODBUS_OUTPUT_3V,
	MODBUS_OUTPUT_4V,
	MODBUS_OUTPUT_5V,
	MODBUS_OUTPUT_6V,
	MODBUS_OUTPUT_7V,
	MODBUS_OUTPUT_8V,
	MODBUS_OUTPUT_9V,
	MODBUS_OUTPUT_10V,
	MODBUS_OUTPUT_TEST_VALUE = 80,
	MODBUS_OUTPUT_TEST_FLAG,
	MODBUS_OUTPUT_MODE,  // AUTO - 1 OR STATIC - 0
	MODBUS_VCC_ADC = 83, // calibration intpu д 4095	
	//MODBUS_PT1K = 84,  // Write 0c У��ֵ
	MODBUS_INPUT1_RAW, // 84
	
	Modbus_Bacnet_Vendor_ID = 90,	
	Modbus_Fix_Com_Config = 91, // ONLY FOR ONE CUSTOMER
	
	MODBUS_ENABLE_WRITE_MAC = 93,
//	MODBUS_IO_LIB_REV,
//	MODUBS_BAC_LIB_REV,
	MODBUS_RUN_TIME_LO,
	MODBUS_RUN_TIME_HI,
	
	MODBUS_SCAN_SUB_PORT, // 96  T3000 will write when auto scan, cant delete
	MODBUS_SCAN_SUB_BAUT, // 97  T3000 will write when auto scan, cant delete
	MODBUS_LCD_TIME_OFF_DELAY,
	

	/* 100 ~ 133 */
  MODBUS_MAC_1 = 100,
	MODBUS_MAC_2,
	MODBUS_MAC_3,
	MODBUS_MAC_4,
	MODBUS_MAC_5,
	MODBUS_MAC_6,

	MODBUS_TCP_TYPE = 106,	  // DHCP OR STATIC

	MODBUS_IP_1,	  // IP have 4 bytes
	MODBUS_IP_2,
	MODBUS_IP_3,
	MODBUS_IP_4,

	MODBUS_SUBNET_1,	  // subnet have 4 bytes
	MODBUS_SUBNET_2,
	MODBUS_SUBNET_3,
	MODBUS_SUBNET_4,

	MODBUS_GETWAY_1,	  // getway have 4 bytes
	MODBUS_GETWAY_2,
	MODBUS_GETWAY_3,
	MODBUS_GETWAY_4,

	MODBUS_TCPSERVER,		// no used
	MODBUS_TCP_LISTEN_PORT,	

	MODBUS_GSM_IP_1,
	MODBUS_GSM_IP_2,
	MODBUS_GSM_IP_3,
	MODBUS_GSM_IP_4,
	MODBUS_GSM_TCPPORT,
	MODBUS_GSM_SEVER_OR_CLIENT,
//	MODBUS_GSM_UDPPORT,
//	MODBUS_GSM_TCP_LINKID,
//	MODBUS_GSM_UDP_LINKID,

	

  MODBUS_UART0_PARITY = 150,  // UART0 parity
	MODBUS_UART1_PARITY = 151,  // UART1 parity	
	MODBUS_UART2_PARITY = 152,	// UART2 parity
	
	MODBUS_UART0_STOPBIT = 153,  // UART0 stopbit
	MODBUS_UART1_STOPBIT = 154,  // UART1 stopbit	
	MODBUS_UART2_STOPBIT = 155,	// UART2 stopbit
	

	MODBUS_TIMER_ADDRESS = SCHEDUAL_MODBUS_ADDRESS, // 200
	

	
	MODBUS_AO1_FEEDBACK = 210,
	MODBUS_AO16_FEEDBACK = 225,
	
	
	MODBUS_CUSTOMER_DEVICE = 280,
	
	MODBUS_ZIGBEE_MOUDLE_ID = 297,

	MODBUS_ADD_ID_BY_HAND = 298 ,
	MODBUS_TOTAL_NO = 299  ,  // NUMBER OF ZONES

	MODBUS_SUBADDR_FIRST = 300 ,	// 193
	MODBUS_SUBADDR_LAST = 400 , // 200

#if BAC_COMMON

	MODBUS_RV_FIRST = 401,
	MODBUS_RV_LAST = MODBUS_RV_FIRST + MAX_AVS * 2 - 1,
	MODBUS_RI_FIRST, // 657
	MODBUS_RI_LAST = MODBUS_RI_FIRST + MAX_INS * 2 - 1,
	MODBUS_RO_FIRST,  // 785
	MODBUS_RO_LAST = MODBUS_RO_FIRST + MAX_OUTS * 2 - 1,
	
#endif
	
	MODBUS_PANNEL_NAME	= 714 ,
	MODBUS_NAME1 ,
	MODBUS_NAME_END = MODBUS_NAME1 + 10 ,
	
	// only for tstat10
	MODBUS_DISALBE_TSTAT10_DIS = 729,
	MODBUS_TEMPERATURE = 730,	
	MODBUS_TVOC,
	MODBUS_HUMIDY,	
	MODBUS_OCCUPID,
	MODBUS_CO2,
	MODBUS_LIGHT,
	MODBUS_VOICE,
	
	MODBUS_PULSE1 = 740,
	MODBUS_PULSE2 ,
	MODBUS_PULSE3 ,
	MODBUS_PULSE4 ,
	
	// type
	// uint8_t number;
//	uint8_t point_type;	 // first 3 bit for number
//	uint8_t panel;   
//	uint8_t sub_id;
//	uint8_t	network_number; // networknumber, when first bit is 0

	MODBUS_LCD_CONFIG_FIRST = 800,
	MODBUS_LCD_CONFIG_END = MODBUS_LCD_CONFIG_FIRST + sizeof(lcdconfig) - 1,
	


/******** WIFI START ************************/
	MODBUS_WIFI_START = 2000,
	MODBUS_WIFI_SSID_MANUAL_EN = 2000,  // 2001 ~ 2009 reserved
	MODBUS_WIFI_MODE, // 0-AUTO 1-STATIC
	MODBUS_WIFI_STATUS,
	MODBUS_WIFI_RESTORE,
	MODBUS_WIFI_MODBUS_PORT,
	MODBUS_WIFI_BACNET_PORT,
	MODBUS_WIFI_REV, // current is 2
	MODBUS_WIIF_START_SMART,
	MODBUS_WIFI_RSSI,//
	
	MODBUS_WIFI_SSID_START = 2010,	// 2010 ~ 2041 user name 64 bytes
	MODBUS_WIFI_SSID_END = 2041,	
	MODBUS_WIFI_PASS_START = 2042,	// 2042 ~ 2057 password 32 bytes
	MODBUS_WIFI_PASS_END = 2057,
	
	MODBUS_WIFI_IP1 = 2058 ,
	MODBUS_WIFI_NETMASK = 2062,
	MODBUS_WIFI_GETWAY = 2066,
	MDOBUS_WIFI_MACADDR = 2070,
	
	MODBUS_WIFI_END = 2100,
/******** WIFI END ************************/

/******** ZIGBEE START ************************/
	MODBUS_ZIGBEE_SUB_NUM = 5030, // 5030 ~ 5099
	MODBUS_ZIGBEE_ID_SIGANL_FIRST = 5031,
	MODBUS_ZIGBEE_ID_SIGANL_END = 5099,
	// ID + SIGNEL STRENGTH
/******** ZIGBEE END ************************/

  MODBUS_T3000_PRIVATE = 5100,
	

//  SD BLOCK
	MODBUS_SD_BLOCK_A1 = 6000,  // 6000
  MODBUS_SD_BLOCK_A12 = 6011,
	MODBUS_SD_BLOCK_D1 = 6012,  // 6000
  MODBUS_SD_BLOCK_D12 = 6023,
	MODBUS_SD_BLOCK_H1 = 6024,  // 6000
  MODBUS_SD_BLOCK_H12 = 6035,

	MODBUS_TEST = 7000,
	MODBUS_TEST_50 = 7050,

//	MODBUS_OUT_NUM = 7100,
//	MODBUS_IN_NUM = 8001,
//	MODBUS_VAR_NUM = 8002,
//	MODBUS_CON_NUM = 8003,
//	MODBUS_WR_NUM = 8004,
//	MODBUS_AR_NUM = 8005,
//	MODBUS_PRG_NUM = 8006,
//	MODBUS_TBL_NUM = 8007,
//	MODBUS_TZ_NUM = 8008,
//	MODBUS_AMON_NUM = 8009,
//	MODBUS_GRP_NUM = 8010,
//	MODBUS_ARRAY_NUM = 8011,
//	MODBUS_ALARM_NUM = 8012,
//	MODBUS_UNIT_NUM = 8013,
//	MODBUS_USER_NAME_NUM = 8014,
//	MODBUS_ALARM_SET_NUM = 8015,
//	MODBUS_SUB_NO,
//	MODBUS_SEQUENCE,  // there are 2 ways to list INPUT struct 0 -- same as T3-4AO  1 - same as bacnet point packet

	MODBUS_OUTPUT_FIRST = 7100,
	MODBUS_OUTPUT_LAST = MODBUS_OUTPUT_FIRST + MAX_OUTS * 2 - 1,

	MODBUS_OUTPUT_SWICH_FIRST ,	// 7228
	MODBUS_OUTPUT_SWICH_LAST = MODBUS_OUTPUT_SWICH_FIRST + MAX_OUTS - 1,

	MODBUS_OUTPUT_RANGE_FIRST,  // 7292
	MODBUS_OUTPUT_RANGE_LAST = MODBUS_OUTPUT_RANGE_FIRST + MAX_OUTS - 1,

	MODBUS_OUTPUT_AM_FIRST,  // 7356
	MODBUS_OUTPUT_AM_LAST = MODBUS_OUTPUT_AM_FIRST + MAX_OUTS - 1,

	MODBUS_OUTPUT_AD_FIRST,  // 7420  ANALOG OR DIGITAL
	MODBUS_OUTPUT_AD_LAST = MODBUS_OUTPUT_AD_FIRST + MAX_OUTS - 1,


	MODBUS_INPUT_FIRST,	  // 7484
	MODBUS_INPUT_LAST = MODBUS_INPUT_FIRST + MAX_INS * 2- 1,

	MODBUS_INPUT_FILTER_FIRST,	// 7612
	MODBUS_INPUT_FILTER_LAST = MODBUS_INPUT_FILTER_FIRST + MAX_OUTS - 1,

	MODBUS_INPUT_CAL_FIRST,	  // 7676
	MODBUS_INPUT_CAL_LAST = MODBUS_INPUT_CAL_FIRST + MAX_INS - 1,

	MODBUS_INPUT_CAL_SIGN_FIRST,  // 7740
	MODBUS_INPUT_CAL_SIGN_LAST =  MODBUS_INPUT_CAL_SIGN_FIRST + MAX_INS - 1, 

	MODBUS_INPUT_RANGE_FIRST,	  // 7804
	MODBUS_INPUT_RANGE_LAST = MODBUS_INPUT_RANGE_FIRST + MAX_INS - 1,

	MODBUS_INPUT_AM_FIRST,  // 7868
	MODBUS_INPUT_AM_LAST = MODBUS_INPUT_AM_FIRST + MAX_INS - 1,
	
  MODBUS_INPUT_HI_SPD_COUNTER_FIRST,	  // 7932
	MODBUS_INPUT_HI_SPD_COUNTER_LAST = MODBUS_INPUT_HI_SPD_COUNTER_FIRST + 32/*HI_COMMON_CHANNEL*/ * 2 - 1,

	MODBUS_INPUT_HI_SPD_EN_FIRST, //7996
	MODBUS_INPUT_HI_SPD_EN_LAST = MODBUS_INPUT_HI_SPD_EN_FIRST + 32/*HI_COMMON_CHANNEL*/ - 1,

	MODBUS_INPUT_TYPE_FIRST, // 8028
	MODBUS_INPUT_TYPE_LAST = MODBUS_INPUT_TYPE_FIRST + MAX_INS - 1,

	MODBUS_VAR_FIRST, // 8092
	MODBUS_VAR_LAST = MODBUS_VAR_FIRST + MAX_VARS * 2 - 1,

	MODBUS_VAR_AM_FIRST,  // 8348
	MODBUS_VAR_AM_LAST = MODBUS_VAR_AM_FIRST + MAX_VARS - 1,

	// add weekly roution
	MODBUS_WR_AM_FIRST, // 8476
	MODBUS_WR_AM_LAST = MODBUS_WR_AM_FIRST + MAX_WR - 1,

	MODBUS_WR_OUT_FIRST, // 8484
	MODBUS_WR_OUT_LAST = MODBUS_WR_OUT_FIRST + MAX_WR - 1,

	MODBUS_WR_HOLIDAY1_FIRST, // 8492
	MODBUS_WR_HOLIDAY1_LAST = MODBUS_WR_HOLIDAY1_FIRST + MAX_WR - 1,

	MODBUS_WR_STATE1_FIRST,  // 8500
	MODBUS_WR_STATE1_LAST = MODBUS_WR_STATE1_FIRST + MAX_WR - 1,

	MODBUS_WR_HOLIDAY2_FIRST, // 8508
	MODBUS_WR_HOLIDAY2_LAST = MODBUS_WR_HOLIDAY2_FIRST + MAX_WR - 1,

	MODBUS_WR_STATE2_FIRST,  // 8516
	MODBUS_WR_STATE2_LAST = MODBUS_WR_STATE2_FIRST + MAX_WR - 1,

	// weekly_time
	//	MODBUS_WR_TIME_BYTE_FIRST, 
	//	MODBUS_WR_TIME_BYTE_LAST = MODBUS_WR_TIME_BYTE_FIRST + MAX_WR * MAX_SCHEDULES_PER_WEEK * 8 - 1,

	// annual roution
	MODBUS_AR_AM_FIRST,  // 8524
	MODBUS_AR_AM_LAST = MODBUS_AR_AM_FIRST + MAX_AR - 1,

	MODBUS_AR_OUT_FIRST, // 8528 - 8659
	MODBUS_AR_OUT_LAST = MODBUS_AR_OUT_FIRST + MAX_AR - 1,

//	MODBUS_ID_FIRST, // 8532
//	MODBUS_ID_LAST = MODBUS_ID_FIRST + MAX_ID * ID_SIZE - 1,
//	MODBUS_AR_TIME_BYTE_FIRST,
//	MODBUS_AR_TIME_BYTE_LAST = MODBUS_AR_TIME_BYTE_FIRST + MAX_AR * AR_DATES_SIZE - 1,
	MODBUS_VAR_RANGE_FIRST,  // 8532 - 8659
	MODBUS_VAR_RANGE_LAST = MODBUS_VAR_RANGE_FIRST + MAX_VARS - 1,
	
	MODBUS_VAR_AD_FIRST,  // 8660 - 8787
	MODBUS_VAR_AD_LAST = MODBUS_VAR_AD_FIRST + MAX_VARS - 1,


	MODBUS_OUTPUT_RELINQUISH_START = 9400, 
	MODBUS_OUTPUT_RELINQUISH_END = MODBUS_OUTPUT_RELINQUISH_START + 2 * MAX_OUTS - 1,  // 128



	MODBUS_SETTING_BLOCK_FIRST = 9800,
	MODBUS_USER_BLOCK_FIRST = MODBUS_SETTING_BLOCK_FIRST,

	MODBUS_SETTING_BLOCK_LAST = 9999,

	MODBUS_OUTPUT_BLOCK_FIRST = 10000,     // 10000 -  11471  45
	MODBUS_OUTPUT_BLOCK_LAST = MODBUS_OUTPUT_BLOCK_FIRST + MAX_OUTS * ((sizeof(Str_out_point) + 1) / 2) - 1,

	MODBUS_INPUT_BLOCK_FIRST, // 11472 - 12943   46
	MODBUS_INPUT_BLOCK_LAST = MODBUS_INPUT_BLOCK_FIRST + MAX_INS * ((sizeof(Str_in_point) + 1) / 2) - 1,

	MODBUS_VAR_BLOCK_FIRST,  // 12944 - 15503  39
	MODBUS_VAR_BLOCK_LAST = MODBUS_VAR_BLOCK_FIRST + MAX_VARS * ((sizeof(Str_variable_point) + 1) / 2) - 1,

	MODBUS_PRG_BLOCK_FIRST, // 15504 - 15807   37
	MODBUS_PRG_BLOCK_LAST = MODBUS_PRG_BLOCK_FIRST + MAX_PRGS * ((sizeof(Str_program_point) + 1) / 2) - 1,

	MODBUS_WR_BLOCK_FIRST,  // 15808 -  15975    42
	MODBUS_WR_BLOCK_LAST = MODBUS_WR_BLOCK_FIRST + MAX_WR * ((sizeof(Str_weekly_routine_point) + 1) / 2) - 1,

	MODBUS_AR_BLOCK_FIRST,  // 15976 - 16043   33 
	MODBUS_AR_BLOCK_LAST = MODBUS_AR_BLOCK_FIRST + MAX_AR * ((sizeof(Str_annual_routine_point) + 1) / 2) - 1,

	MODBUS_CODE_BLOCK_FIRST, // 16044 - 32043  
	MODBUS_CODE_BLOCK_LAST = MODBUS_CODE_BLOCK_FIRST + MAX_PRGS * (CODE_ELEMENT * MAX_CODE / 2) - 1,

	MODBUS_WR_TIME_FIRST,  // 32044 - 32619
	MODBUS_WR_TIME_LAST = MODBUS_WR_TIME_FIRST + MAX_WR * ((sizeof(Wr_one_day) * MAX_SCHEDULES_PER_WEEK + 1) / 2) - 1,

	MODBUS_AR_TIME_FIRST, // 32620 - 32711  46
	MODBUS_AR_TIME_LAST = MODBUS_AR_TIME_FIRST + MAX_AR * (AR_DATES_SIZE / 2) - 1,

	MODBUS_CONTROLLER_BLOCK_FIRST,  // 32712 - 32935  28*16
	MODBUS_CONTROLLER_BLOCK_LAST = MODBUS_CONTROLLER_BLOCK_FIRST + MAX_CONS * ((sizeof(Str_controller_point) + 1) / 2) - 1,

//	MODBUS_WR_FIRST, 
//	MODBUS_WR_LAST = MODBUS_WR_FIRST + MAX_WR * sizeof(Str_weekly_routine_point),
//
//	MODBUS_AR_FIRST, 
//	MODBUS_AR_LAST = MODBUS_AR_FIRST + MAX_AR * sizeof(Str_annual_routine_point),
//
//	
//	MODBUS_SUB_INFO_FIRST = 18000,
//	MODBUS_SUB_INFO_LAST = MODBUS_SUB_INFO_FIRST + SUB_NO * Tst_reg_num,


// add customer range 
	MODBUS_CUSTOMER_RANGE_BLOCK_FIRST,  // 32936 - 33200  53 * 5
	MODBUS_CUSTOMER_RANGE_BLOCK_LAST = MODBUS_CUSTOMER_RANGE_BLOCK_FIRST + MAX_TBLS * ((sizeof(Str_table_point) + 1) / 2) - 1,

	MODBUS_WR_FLAG_FIRST,  // 33201 - 33488  wr_time_on_off   8 * 9 * 4
	MDOBUS_WR_FLAG_LAST = MODBUS_WR_FLAG_FIRST + MAX_WR * ((MAX_SCHEDULES_PER_WEEK * 8 + 1) / 2) - 1,

	//MODBUS_DIGITAL_TABLE_FIRST, // 33489 - 33592  digi_units 25/2 * 8
	//MODBUS_DIGITAL_TABLE_LAST = MODBUS_DIGITAL_TABLE_FIRST + MAX_DIG_UNIT * ((sizeof(Units_element) + 1) / 2) - 1,

	MODBUS_USER_BLOCK_LAST = MDOBUS_WR_FLAG_LAST,

	MODBUS_TASK_TEST = 40000,// 15 * 6
	
	MODBUS_EX_MOUDLE_EN = 65000,
	MODBUS_EX_MOUDLE_FLAG12 = 65001,
	MODBUS_EX_MOUDLE_FLAG34 = 65002,
	MODBUS_CPU_TYPE = 65010,
	
}E_MODBUS; 




#endif