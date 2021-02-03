EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Sistema para RTOS"
Date "2021-01-31"
Rev "v1"
Comp ""
Comment1 "Elaborada por: Hugo René Pérez Cabrera"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_ST_STM32F1:STM32F103C8Tx U1
U 1 1 601907F1
P 2500 3100
F 0 "U1" H 2450 1511 50  0000 C CNN
F 1 "STM32F103C8Tx" H 2900 1450 50  0000 C CNN
F 2 "Package_QFP:LQFP-48_7x7mm_P0.5mm" H 1900 1700 50  0001 R CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/CD00161566.pdf" H 2500 3100 50  0001 C CNN
	1    2500 3100
	1    0    0    -1  
$EndComp
Wire Notes Line
	4200 5250 4200 500 
Text Notes 5800 950  0    250  ~ 0
Interfaz de Usuario
Text Label 1550 1800 0    50   ~ 0
NRST
Text Label 1550 2000 0    50   ~ 0
BOOT0
Text Label 1550 2200 0    50   ~ 0
PD0
Text Label 1550 2300 0    50   ~ 0
PD1
Text Label 1550 2500 0    50   ~ 0
PC13
Text Label 1550 2600 0    50   ~ 0
PC14
Text Label 1550 2700 0    50   ~ 0
PC15
Text Label 1550 2900 0    50   ~ 0
PB0
Text Label 1550 3000 0    50   ~ 0
PB1
Text Label 1550 3100 0    50   ~ 0
PB2
Text Label 1550 3200 0    50   ~ 0
PB3
Text Label 1550 3300 0    50   ~ 0
PB4
Text Label 1550 3400 0    50   ~ 0
PB5
Text Label 1550 3500 0    50   ~ 0
PB6
Text Label 1550 3600 0    50   ~ 0
PB7
Text Label 1550 3700 0    50   ~ 0
PB8
Text Label 1550 3800 0    50   ~ 0
PB9
Text Label 1550 3900 0    50   ~ 0
PB10
Text Label 1550 4000 0    50   ~ 0
PB11
Text Label 1550 4100 0    50   ~ 0
PB12
Text Label 1550 4200 0    50   ~ 0
PB13
Text Label 1550 4300 0    50   ~ 0
PB14
Text Label 1550 4400 0    50   ~ 0
PB15
Wire Wire Line
	2600 4600 2600 4750
Wire Wire Line
	2500 4600 2500 4750
Wire Wire Line
	2400 4600 2400 4750
Wire Wire Line
	2300 4600 2300 4750
Wire Wire Line
	1550 4400 1800 4400
Wire Wire Line
	1800 4300 1550 4300
Wire Wire Line
	1550 4200 1800 4200
Wire Wire Line
	1550 4100 1800 4100
Wire Wire Line
	1550 4000 1800 4000
Wire Wire Line
	1550 3900 1800 3900
Wire Wire Line
	1550 3800 1800 3800
Wire Wire Line
	1550 3700 1800 3700
Wire Wire Line
	1550 3600 1800 3600
Wire Wire Line
	1550 3500 1800 3500
Wire Wire Line
	1800 3400 1550 3400
Wire Wire Line
	1800 3300 1550 3300
Wire Wire Line
	1800 3200 1550 3200
Wire Wire Line
	1800 3100 1550 3100
Wire Wire Line
	1800 3000 1550 3000
Wire Wire Line
	1800 2900 1550 2900
Wire Wire Line
	1550 2700 1800 2700
Wire Wire Line
	1550 2600 1800 2600
Wire Wire Line
	1550 2500 1800 2500
Wire Wire Line
	1550 2300 1800 2300
Wire Wire Line
	1550 2200 1800 2200
Wire Wire Line
	1550 2000 1800 2000
Wire Wire Line
	1550 1800 1800 1800
Wire Wire Line
	2300 1350 2300 1600
Wire Wire Line
	2400 1350 2400 1600
Wire Wire Line
	2500 1350 2500 1600
Wire Wire Line
	2600 1350 2600 1600
Text Label 3350 4400 2    50   ~ 0
PA15
Text Label 3350 4300 2    50   ~ 0
PA14
Text Label 3350 4200 2    50   ~ 0
PA13
Text Label 3350 4100 2    50   ~ 0
PA12
Text Label 3350 4000 2    50   ~ 0
PA11
Text Label 3350 3900 2    50   ~ 0
PA10
Text Label 3350 3800 2    50   ~ 0
PA9
Text Label 3350 3700 2    50   ~ 0
PA8
Text Label 3350 3600 2    50   ~ 0
PA7
Text Label 3350 3500 2    50   ~ 0
PA6
Text Label 3350 3400 2    50   ~ 0
PA5
Text Label 3350 3300 2    50   ~ 0
PA4
Text Label 3350 3200 2    50   ~ 0
PA3
Text Label 3350 3100 2    50   ~ 0
PA2
Text Label 3350 3000 2    50   ~ 0
PA1
Text Label 3350 2900 2    50   ~ 0
PA0
Wire Wire Line
	3350 2900 3100 2900
Wire Wire Line
	3100 3000 3350 3000
Wire Wire Line
	3350 3100 3100 3100
Wire Wire Line
	3350 3200 3100 3200
Wire Wire Line
	3350 3300 3100 3300
Wire Wire Line
	3350 3400 3100 3400
Wire Wire Line
	3350 3500 3100 3500
Wire Wire Line
	3350 3600 3100 3600
Wire Wire Line
	3350 3700 3100 3700
Wire Wire Line
	3350 3800 3100 3800
Wire Wire Line
	3100 3900 3350 3900
Wire Wire Line
	3100 4000 3350 4000
Wire Wire Line
	3100 4100 3350 4100
Wire Wire Line
	3100 4200 3350 4200
Wire Wire Line
	3100 4300 3350 4300
Wire Wire Line
	3100 4400 3350 4400
$Comp
L Switch:SW_Push SW1
U 1 1 601A0669
P 4800 1450
F 0 "SW1" H 4800 1735 50  0000 C CNN
F 1 "SW_Push" H 4800 1644 50  0000 C CNN
F 2 "" H 4800 1650 50  0001 C CNN
F 3 "~" H 4800 1650 50  0001 C CNN
	1    4800 1450
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW2
U 1 1 601A1436
P 4800 1950
F 0 "SW2" H 4800 2235 50  0000 C CNN
F 1 "SW_Push" H 4800 2144 50  0000 C CNN
F 2 "" H 4800 2150 50  0001 C CNN
F 3 "~" H 4800 2150 50  0001 C CNN
	1    4800 1950
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW3
U 1 1 601A1952
P 4800 2450
F 0 "SW3" H 4800 2735 50  0000 C CNN
F 1 "SW_Push" H 4800 2644 50  0000 C CNN
F 2 "" H 4800 2650 50  0001 C CNN
F 3 "~" H 4800 2650 50  0001 C CNN
	1    4800 2450
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW4
U 1 1 601A1CE7
P 4800 2950
F 0 "SW4" H 4800 3235 50  0000 C CNN
F 1 "SW_Push" H 4800 3144 50  0000 C CNN
F 2 "" H 4800 3150 50  0001 C CNN
F 3 "~" H 4800 3150 50  0001 C CNN
	1    4800 2950
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR0101
U 1 1 601A4B96
P 4600 3200
F 0 "#PWR0101" H 4600 2950 50  0001 C CNN
F 1 "Earth" H 4600 3050 50  0001 C CNN
F 2 "" H 4600 3200 50  0001 C CNN
F 3 "~" H 4600 3200 50  0001 C CNN
	1    4600 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 3200 4600 2950
Connection ~ 4600 2950
Wire Wire Line
	4600 1950 4600 2450
Connection ~ 4600 2450
Wire Wire Line
	4600 2450 4600 2950
Wire Wire Line
	4600 1450 4600 1950
Connection ~ 4600 1950
Text Label 5200 1450 0    50   ~ 0
PA0
Text Label 5200 1950 0    50   ~ 0
PA1
Text Label 5200 2450 0    50   ~ 0
PA2
Text Label 5200 2950 0    50   ~ 0
PA3
Wire Wire Line
	5000 1450 5200 1450
Wire Wire Line
	5000 1950 5200 1950
Wire Wire Line
	5000 2450 5200 2450
Wire Wire Line
	5000 2950 5200 2950
$Comp
L Device:LED D1
U 1 1 601B1147
P 7650 1600
F 0 "D1" H 7643 1345 50  0000 C CNN
F 1 "LED" H 7643 1436 50  0000 C CNN
F 2 "" H 7650 1600 50  0001 C CNN
F 3 "~" H 7650 1600 50  0001 C CNN
	1    7650 1600
	-1   0    0    1   
$EndComp
$Comp
L Device:R R1
U 1 1 601BB4BF
P 7100 1600
F 0 "R1" V 6893 1600 50  0000 C CNN
F 1 "330" V 6984 1600 50  0000 C CNN
F 2 "" V 7030 1600 50  0001 C CNN
F 3 "~" H 7100 1600 50  0001 C CNN
	1    7100 1600
	0    1    1    0   
$EndComp
Wire Wire Line
	7250 1600 7500 1600
Text Label 6750 1600 0    50   ~ 0
PB9
Wire Wire Line
	6750 1600 6950 1600
$Comp
L Device:LED D2
U 1 1 601C88D8
P 7650 2100
F 0 "D2" H 7643 1845 50  0000 C CNN
F 1 "LED" H 7643 1936 50  0000 C CNN
F 2 "" H 7650 2100 50  0001 C CNN
F 3 "~" H 7650 2100 50  0001 C CNN
	1    7650 2100
	-1   0    0    1   
$EndComp
$Comp
L Device:R R2
U 1 1 601C88DE
P 7100 2100
F 0 "R2" V 6893 2100 50  0000 C CNN
F 1 "330" V 6984 2100 50  0000 C CNN
F 2 "" V 7030 2100 50  0001 C CNN
F 3 "~" H 7100 2100 50  0001 C CNN
	1    7100 2100
	0    1    1    0   
$EndComp
Wire Wire Line
	7250 2100 7500 2100
Text Label 6750 2100 0    50   ~ 0
PB8
Wire Wire Line
	6750 2100 6950 2100
$Comp
L Device:LED D3
U 1 1 601C9F47
P 7650 2600
F 0 "D3" H 7643 2345 50  0000 C CNN
F 1 "LED" H 7643 2436 50  0000 C CNN
F 2 "" H 7650 2600 50  0001 C CNN
F 3 "~" H 7650 2600 50  0001 C CNN
	1    7650 2600
	-1   0    0    1   
$EndComp
$Comp
L Device:R R3
U 1 1 601C9F4D
P 7100 2600
F 0 "R3" V 6893 2600 50  0000 C CNN
F 1 "330" V 6984 2600 50  0000 C CNN
F 2 "" V 7030 2600 50  0001 C CNN
F 3 "~" H 7100 2600 50  0001 C CNN
	1    7100 2600
	0    1    1    0   
$EndComp
Wire Wire Line
	7250 2600 7500 2600
Text Label 6750 2600 0    50   ~ 0
PB7
Wire Wire Line
	6750 2600 6950 2600
$Comp
L power:Earth #PWR0102
U 1 1 601CB39B
P 7800 3100
F 0 "#PWR0102" H 7800 2850 50  0001 C CNN
F 1 "Earth" H 7800 2950 50  0001 C CNN
F 2 "" H 7800 3100 50  0001 C CNN
F 3 "~" H 7800 3100 50  0001 C CNN
	1    7800 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	7800 3100 7800 2600
Wire Wire Line
	7800 2600 7800 2100
Connection ~ 7800 2600
Wire Wire Line
	7800 2100 7800 1600
Connection ~ 7800 2100
Text Notes 750  900  0    250  ~ 0
Microcontrolador
Text Notes 4400 4000 0    250  ~ 0
Matriz LED
$Comp
L Interface_USB:FT230XQ U2
U 1 1 601D4573
P 9700 2300
F 0 "U2" H 9700 3181 50  0000 C CNN
F 1 "FT230XQ" H 9700 3090 50  0000 C CNN
F 2 "Package_DFN_QFN:QFN-16-1EP_4x4mm_P0.65mm_EP2.1x2.1mm" H 11050 1700 50  0001 C CNN
F 3 "https://www.ftdichip.com/Support/Documents/DataSheets/ICs/DS_FT230X.pdf" H 9700 2300 50  0001 C CNN
	1    9700 2300
	-1   0    0    -1  
$EndComp
Wire Wire Line
	9600 3000 9700 3000
Connection ~ 9700 3000
Wire Wire Line
	9700 3000 9800 3000
$Comp
L power:Earth #PWR0103
U 1 1 601DA991
P 9700 3150
F 0 "#PWR0103" H 9700 2900 50  0001 C CNN
F 1 "Earth" H 9700 3000 50  0001 C CNN
F 2 "" H 9700 3150 50  0001 C CNN
F 3 "~" H 9700 3150 50  0001 C CNN
	1    9700 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	9700 3000 9700 3150
$Comp
L power:VCC #PWR0104
U 1 1 601DCC85
P 9800 1350
F 0 "#PWR0104" H 9800 1200 50  0001 C CNN
F 1 "VCC" H 9815 1523 50  0000 C CNN
F 2 "" H 9800 1350 50  0001 C CNN
F 3 "" H 9800 1350 50  0001 C CNN
	1    9800 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	9800 1350 9800 1600
Text Label 8800 2000 0    50   ~ 0
PA9
Text Label 8800 1900 0    50   ~ 0
PA10
Wire Wire Line
	8800 1900 9000 1900
Wire Wire Line
	8800 2000 9000 2000
Wire Notes Line
	4200 3600 11200 3600
$Comp
L power:VDD #PWR0105
U 1 1 601F6844
P 2400 1150
F 0 "#PWR0105" H 2400 1000 50  0001 C CNN
F 1 "VDD" H 2415 1323 50  0000 C CNN
F 2 "" H 2400 1150 50  0001 C CNN
F 3 "" H 2400 1150 50  0001 C CNN
	1    2400 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 1350 2500 1350
Wire Wire Line
	2500 1350 2400 1350
Connection ~ 2500 1350
Wire Wire Line
	2400 1350 2400 1150
Connection ~ 2400 1350
Wire Wire Line
	2700 1600 2700 1350
Wire Wire Line
	2700 1350 2600 1350
Connection ~ 2600 1350
Wire Wire Line
	2300 1350 2400 1350
Wire Wire Line
	2300 4750 2400 4750
Wire Wire Line
	2400 4750 2500 4750
Connection ~ 2400 4750
Wire Wire Line
	2500 4750 2600 4750
Connection ~ 2500 4750
$Comp
L power:Earth #PWR0106
U 1 1 60206B48
P 2400 4900
F 0 "#PWR0106" H 2400 4650 50  0001 C CNN
F 1 "Earth" H 2400 4750 50  0001 C CNN
F 2 "" H 2400 4900 50  0001 C CNN
F 3 "~" H 2400 4900 50  0001 C CNN
	1    2400 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 4900 2400 4750
Text Label 4500 4200 0    50   ~ 0
PA5
Text Label 4500 4400 0    50   ~ 0
PA6
Text Label 4500 4600 0    50   ~ 0
PA7
$Comp
L power:VDD #PWR0107
U 1 1 60212083
P 4700 4800
F 0 "#PWR0107" H 4700 4650 50  0001 C CNN
F 1 "VDD" V 4715 4927 50  0000 L CNN
F 2 "" H 4700 4800 50  0001 C CNN
F 3 "" H 4700 4800 50  0001 C CNN
	1    4700 4800
	0    -1   -1   0   
$EndComp
$Comp
L power:Earth #PWR0108
U 1 1 60213112
P 4700 5000
F 0 "#PWR0108" H 4700 4750 50  0001 C CNN
F 1 "Earth" H 4700 4850 50  0001 C CNN
F 2 "" H 4700 5000 50  0001 C CNN
F 3 "~" H 4700 5000 50  0001 C CNN
	1    4700 5000
	0    1    1    0   
$EndComp
Text Label 5400 4600 2    50   ~ 0
DIN
Text Label 5400 4400 2    50   ~ 0
CS
Text Label 5400 4200 2    50   ~ 0
CLK
Text Label 5400 5000 2    50   ~ 0
GND
Text Label 5400 4800 2    50   ~ 0
VDD
Wire Wire Line
	4500 4200 5400 4200
Wire Wire Line
	4500 4400 5400 4400
Wire Wire Line
	4500 4600 5400 4600
Wire Wire Line
	4700 4800 5400 4800
Wire Wire Line
	4700 5000 5400 5000
Wire Notes Line
	6750 5250 6750 3600
Wire Notes Line
	500  5250 6750 5250
$EndSCHEMATC
