#ifndef _COMMON_H_
#define _COMMON_H_
#include "arduino.h"
#include <avr/wdt.h>
#include <ArduinoJson.h>
#include <EEPROM.h>
#include <SD.h>
#define DE_BUG
#define GSM_UART Serial1
#define RFID_UART Serial2
#define WIFI_PROBE Serial3

#ifdef DE_BUG    //   在COMMON.h 中启用
  #define mySerial Serial  
#endif

#define DEV_ID "T1868881606"  //设备ID号

#define TEMP_RANG_MIN  "00000000"   // 临时卡范围最小值 0
#define TEMP_RANG_MAX  "00004E20"   // 临时卡范围最大值 20000

//* SD card attached to SPI bus as follows:    
//** MOSI - pin 51
//** MISO - pin 50
//** CLK - pin 52
//** CS -  pin 53
const int led = 2;        //白色led引脚定义D2
const int sw = 3;         //门禁关闭检测引脚D3
const int led_red = 6;    //红色led未上线亮、上线熄灭、刷卡时灭一下 D6
const int led_blue = 7;   //蓝色led未上线熄灭、上线亮、刷卡时灭一下 D7
const int beep = 49;      //蜂鸣器引脚 D49  高电平响
const int locked = 42;    //继电器引脚定义 D42
const int gsm_reset = 38;  //GSM模块复位引脚定义 D38
const int rfid_reset = 4; //RFID刷卡模块复位引脚定义 D4

const char filetype[2][16]={"LIST.TXT","RECORD.TXT"};

extern unsigned char beep_flag; //蜂鸣器标志  0 不响  1 响
extern unsigned char locked_flag;
extern unsigned char tmp_card_Enable;//临时卡开门使能标志
extern unsigned int locked_keep;//开锁时长
extern unsigned int warning_keep;//监测报警时长
extern unsigned long locked_start;//开锁起始时间
extern unsigned long calibration_seconds;  //上线时间
extern unsigned long system_seconds;        //系统时间
extern unsigned long switch_detect_start;//门禁状态监测持续开门起始时间
extern File record_File;

#endif
