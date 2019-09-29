EESchema Schematic File Version 4
LIBS:ParkControlPCB-cache
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Park Control PCB"
Date "2019-09-17"
Rev "1"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Regulator_Linear:LM1117-3.3 U1
U 1 1 5D813E23
P 3100 6850
F 0 "U1" H 3100 7092 50  0000 C CNN
F 1 "LM1117-3.3" H 3100 7001 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223" H 3100 6850 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm1117.pdf" H 3100 6850 50  0001 C CNN
	1    3100 6850
	1    0    0    -1  
$EndComp
Text Label 6600 4650 0    50   ~ 0
GND
Wire Wire Line
	6600 2600 6600 2900
Text Label 6600 2650 0    50   ~ 0
3V3
Wire Wire Line
	3100 7150 3100 7200
Wire Wire Line
	2800 6850 2550 6850
$Comp
L Device:CP C1
U 1 1 5D81651B
P 3650 7000
F 0 "C1" H 3768 7046 50  0000 L CNN
F 1 "100 μF" H 3768 6955 50  0000 L CNN
F 2 "Capacitor_Tantalum_SMD:CP_EIA-3528-12_Kemet-T_Pad1.50x2.35mm_HandSolder" H 3688 6850 50  0001 C CNN
F 3 "~" H 3650 7000 50  0001 C CNN
	1    3650 7000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 6850 3650 6850
Wire Wire Line
	3650 6850 3950 6850
Connection ~ 3650 6850
Text Label 3800 6850 0    50   ~ 0
3V3
Wire Wire Line
	3100 7200 3650 7200
Wire Wire Line
	3650 7200 3650 7150
Connection ~ 3100 7200
Wire Wire Line
	3100 7200 3100 7350
Wire Notes Line
	500  6300 4300 6300
Text Notes 500  6400 0    50   ~ 0
Power
$Comp
L Device:CP C2
U 1 1 5D825275
P 1700 6950
F 0 "C2" H 1818 6996 50  0000 L CNN
F 1 "1000 uF, 6,3V" H 1818 6905 50  0000 L CNN
F 2 "Capacitor_Tantalum_SMD:CP_EIA-3528-12_Kemet-T_Pad1.50x2.35mm_HandSolder" H 1738 6800 50  0001 C CNN
F 3 "~" H 1700 6950 50  0001 C CNN
	1    1700 6950
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 6900 1450 6900
Wire Wire Line
	1450 6900 1450 6800
Wire Wire Line
	1450 6800 1700 6800
Wire Wire Line
	1950 6800 1700 6800
Connection ~ 1700 6800
Wire Wire Line
	1300 7000 1450 7000
Wire Wire Line
	1450 7000 1450 7100
Wire Wire Line
	1450 7100 1700 7100
Wire Wire Line
	1700 7100 1950 7100
Connection ~ 1700 7100
Text Label 1800 6800 0    50   ~ 0
VCC
Text Label 1800 7100 0    50   ~ 0
GND
$Comp
L Connector:Conn_01x02_Male J2
U 1 1 5D8A7152
P 1100 6900
F 0 "J2" H 1208 7081 50  0000 C CNN
F 1 "PWR" H 1208 6990 50  0000 C CNN
F 2 "Connector_PinHeader_1.00mm:PinHeader_1x02_P1.00mm_Vertical" H 1100 6900 50  0001 C CNN
F 3 "~" H 1100 6900 50  0001 C CNN
	1    1100 6900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5D8A8E66
P 1450 7100
F 0 "#PWR0101" H 1450 6850 50  0001 C CNN
F 1 "GND" H 1455 6927 50  0000 C CNN
F 2 "" H 1450 7100 50  0001 C CNN
F 3 "" H 1450 7100 50  0001 C CNN
	1    1450 7100
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0102
U 1 1 5D8A9159
P 1450 6800
F 0 "#PWR0102" H 1450 6650 50  0001 C CNN
F 1 "VCC" H 1467 6973 50  0000 C CNN
F 2 "" H 1450 6800 50  0001 C CNN
F 3 "" H 1450 6800 50  0001 C CNN
	1    1450 6800
	1    0    0    -1  
$EndComp
Text Label 2550 6850 0    50   ~ 0
VCC
Text Label 3100 7350 0    50   ~ 0
GND
Connection ~ 1450 6800
Connection ~ 1450 7100
$Comp
L power:VCC #PWR0103
U 1 1 5D8AC6BB
P 650 7500
F 0 "#PWR0103" H 650 7350 50  0001 C CNN
F 1 "VCC" H 668 7673 50  0000 C CNN
F 2 "" H 650 7500 50  0001 C CNN
F 3 "" H 650 7500 50  0001 C CNN
	1    650  7500
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 5D8ACD38
P 1050 7500
F 0 "#PWR0104" H 1050 7250 50  0001 C CNN
F 1 "GND" H 1055 7327 50  0000 C CNN
F 2 "" H 1050 7500 50  0001 C CNN
F 3 "" H 1050 7500 50  0001 C CNN
	1    1050 7500
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5D8AD159
P 650 7400
F 0 "#FLG0101" H 650 7475 50  0001 C CNN
F 1 "PWR_FLAG" H 650 7573 50  0000 C CNN
F 2 "" H 650 7400 50  0001 C CNN
F 3 "~" H 650 7400 50  0001 C CNN
	1    650  7400
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 5D8AD496
P 1050 7400
F 0 "#FLG0102" H 1050 7475 50  0001 C CNN
F 1 "PWR_FLAG" H 1050 7573 50  0000 C CNN
F 2 "" H 1050 7400 50  0001 C CNN
F 3 "~" H 1050 7400 50  0001 C CNN
	1    1050 7400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1050 7400 1050 7500
Wire Wire Line
	650  7400 650  7500
Wire Notes Line
	4300 5050 500  5050
Text Notes 500  5150 0    50   ~ 0
Programming Interface
$Comp
L Connector:Conn_01x04_Male J1
U 1 1 5D8B02C9
P 800 5600
F 0 "J1" H 908 5881 50  0000 C CNN
F 1 "Prog" H 908 5790 50  0000 C CNN
F 2 "Connector_PinHeader_1.00mm:PinHeader_1x04_P1.00mm_Vertical" H 800 5600 50  0001 C CNN
F 3 "~" H 800 5600 50  0001 C CNN
	1    800  5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	1000 5500 1450 5500
Wire Wire Line
	1000 5600 1450 5600
Wire Wire Line
	1000 5700 1450 5700
Wire Wire Line
	1000 5800 1450 5800
Text Label 1300 5500 0    50   ~ 0
SCK
Text Label 1300 5600 0    50   ~ 0
MISO
Text Label 1300 5700 0    50   ~ 0
MOSI
Text Label 1300 5800 0    50   ~ 0
SS
Wire Wire Line
	6000 3700 5750 3700
Wire Wire Line
	6000 3800 5750 3800
Wire Wire Line
	6000 4100 5750 4100
Wire Wire Line
	6000 4200 5750 4200
Text Label 5750 3700 0    50   ~ 0
SS
Text Label 5750 3800 0    50   ~ 0
MISO
Text Label 5750 4100 0    50   ~ 0
MOSI
Text Label 5750 4200 0    50   ~ 0
SCK
Wire Notes Line
	4300 3700 500  3700
Text Notes 500  3800 0    50   ~ 0
LED Connectors
$Comp
L Connector:Conn_01x03_Male J3
U 1 1 5D8B6DB2
P 900 4450
F 0 "J3" H 1008 4731 50  0000 C CNN
F 1 "LED1" H 1008 4640 50  0000 C CNN
F 2 "Connector_PinHeader_1.00mm:PinHeader_1x03_P1.00mm_Vertical" H 900 4450 50  0001 C CNN
F 3 "~" H 900 4450 50  0001 C CNN
	1    900  4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	1100 4350 1550 4350
Wire Wire Line
	1100 4450 1150 4450
Wire Wire Line
	1100 4550 1550 4550
Text Label 1400 4350 0    50   ~ 0
VCC
Text Label 1400 4550 0    50   ~ 0
GND
Text Label 1500 4450 0    50   ~ 0
DIN_LED_1
Wire Notes Line
	2050 6300 2050 5050
Wire Wire Line
	9200 2850 9200 2600
Wire Wire Line
	9400 2850 9400 2600
Text Label 9200 2650 3    50   ~ 0
3V3
Text Label 9400 2650 3    50   ~ 0
VCC
Wire Wire Line
	9300 4250 9300 4650
Text Label 9300 4650 1    50   ~ 0
GND
$Comp
L Logic_LevelTranslator:TXS0108EPW U3
U 1 1 5D8C9423
P 9300 3550
F 0 "U3" H 9300 2761 50  0000 C CNN
F 1 "TXS0108EPW" H 9300 2670 50  0000 C CNN
F 2 "Package_SO:TSSOP-20_4.4x6.5mm_P0.65mm" H 9300 2800 50  0001 C CNN
F 3 "www.ti.com/lit/ds/symlink/txs0108e.pdf" H 9300 3450 50  0001 C CNN
	1    9300 3550
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5D8CE997
P 1300 4450
F 0 "R1" V 1093 4450 50  0000 C CNN
F 1 "470" V 1184 4450 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 1230 4450 50  0001 C CNN
F 3 "~" H 1300 4450 50  0001 C CNN
	1    1300 4450
	0    1    1    0   
$EndComp
Wire Wire Line
	1450 4450 1550 4450
$Comp
L Connector:Conn_01x03_Male J4
U 1 1 5D8D89CE
P 2150 4450
F 0 "J4" H 2258 4731 50  0000 C CNN
F 1 "LED2" H 2258 4640 50  0000 C CNN
F 2 "Connector_PinHeader_1.00mm:PinHeader_1x03_P1.00mm_Vertical" H 2150 4450 50  0001 C CNN
F 3 "~" H 2150 4450 50  0001 C CNN
	1    2150 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2350 4350 2800 4350
Wire Wire Line
	2350 4450 2400 4450
Wire Wire Line
	2350 4550 2800 4550
Text Label 2650 4350 0    50   ~ 0
VCC
Text Label 2650 4550 0    50   ~ 0
GND
$Comp
L Device:R R2
U 1 1 5D8D89DE
P 2550 4450
F 0 "R2" V 2343 4450 50  0000 C CNN
F 1 "470" V 2434 4450 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 2480 4450 50  0001 C CNN
F 3 "~" H 2550 4450 50  0001 C CNN
	1    2550 4450
	0    1    1    0   
$EndComp
Wire Wire Line
	2700 4450 2800 4450
Text Label 2750 4450 0    50   ~ 0
DIN_LED_2
Wire Wire Line
	9700 3250 10000 3250
Wire Wire Line
	9700 3350 10000 3350
Text Label 9750 3250 0    50   ~ 0
DIN_LED_1
Text Label 9750 3350 0    50   ~ 0
DIN_LED_2
Wire Wire Line
	8900 3250 8550 3250
Wire Wire Line
	8900 3350 8550 3350
Text Label 8550 3250 0    50   ~ 0
LED_1
Text Label 8550 3350 0    50   ~ 0
LED_2
$Comp
L Device:R R3
U 1 1 5D8E1782
P 5700 3100
F 0 "R3" V 5493 3100 50  0000 C CNN
F 1 "10K" V 5584 3100 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 5630 3100 50  0001 C CNN
F 3 "~" H 5700 3100 50  0001 C CNN
	1    5700 3100
	0    1    1    0   
$EndComp
Wire Wire Line
	6000 3100 5850 3100
Wire Wire Line
	5550 3100 5350 3100
Text Label 5400 3100 0    50   ~ 0
3V3
Wire Wire Line
	7400 4000 7200 4000
$Comp
L Device:R R6
U 1 1 5D8E6AA7
P 7550 4000
F 0 "R6" V 7343 4000 50  0000 C CNN
F 1 "10K" V 7434 4000 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 7480 4000 50  0001 C CNN
F 3 "~" H 7550 4000 50  0001 C CNN
	1    7550 4000
	0    1    1    0   
$EndComp
Wire Wire Line
	7700 4000 7950 4000
Text Label 7800 4000 0    50   ~ 0
GND
Wire Wire Line
	7200 3100 7400 3100
$Comp
L Device:R R4
U 1 1 5D8E8DEA
P 7550 3100
F 0 "R4" V 7343 3100 50  0000 C CNN
F 1 "10K" V 7434 3100 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 7480 3100 50  0001 C CNN
F 3 "~" H 7550 3100 50  0001 C CNN
	1    7550 3100
	0    1    1    0   
$EndComp
Wire Wire Line
	7950 3100 7850 3100
Text Label 7800 3100 0    50   ~ 0
3V3
Wire Wire Line
	7200 3300 7400 3300
$Comp
L Device:R R5
U 1 1 5D8EC73C
P 7550 3300
F 0 "R5" V 7750 3300 50  0000 C CNN
F 1 "10K" V 7650 3300 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 7480 3300 50  0001 C CNN
F 3 "~" H 7550 3300 50  0001 C CNN
	1    7550 3300
	0    1    1    0   
$EndComp
Wire Wire Line
	7700 3300 7850 3300
Wire Wire Line
	7850 3300 7850 3100
Connection ~ 7850 3100
Wire Wire Line
	7850 3100 7700 3100
Wire Wire Line
	6000 3300 5850 3300
$Comp
L Device:R R7
U 1 1 5D8F3E21
P 5700 3300
F 0 "R7" V 5900 3300 50  0000 C CNN
F 1 "10K" V 5800 3300 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 5630 3300 50  0001 C CNN
F 3 "~" H 5700 3300 50  0001 C CNN
	1    5700 3300
	0    1    1    0   
$EndComp
Wire Wire Line
	5550 3300 5350 3300
Text Label 5400 3300 0    50   ~ 0
3V3
Text Label 7200 3200 0    50   ~ 0
LED_1
Wire Wire Line
	7200 3200 7450 3200
Wire Wire Line
	7200 3500 7450 3500
Wire Wire Line
	7200 3600 7450 3600
Wire Wire Line
	7200 3700 7450 3700
Wire Wire Line
	7200 3800 7450 3800
Text Label 7200 3600 0    50   ~ 0
US_E_1
Text Label 7200 3800 0    50   ~ 0
US_E_2
Text Label 7200 3500 0    50   ~ 0
US_T_1
Text Label 7200 3700 0    50   ~ 0
US_T_2
Wire Wire Line
	8900 3450 8550 3450
Wire Wire Line
	8900 3550 8550 3550
Wire Wire Line
	8900 3650 8550 3650
Wire Wire Line
	8900 3750 8550 3750
Text Label 8550 3450 0    50   ~ 0
US_T_1
Text Label 8550 3650 0    50   ~ 0
US_T_2
Text Label 8550 3550 0    50   ~ 0
US_E_1
Text Label 8550 3750 0    50   ~ 0
US_E_2
Wire Wire Line
	9700 3450 10000 3450
Wire Wire Line
	9700 3550 10000 3550
Wire Wire Line
	9700 3650 10000 3650
Wire Wire Line
	9700 3750 10000 3750
Text Label 9750 3450 0    50   ~ 0
US_T_1_5V
Text Label 9750 3650 0    50   ~ 0
US_T_2_5V
Text Label 9750 3550 0    50   ~ 0
US_E_1_5V
Text Label 9750 3750 0    50   ~ 0
US_E_2_5V
Wire Wire Line
	6600 4400 6600 4650
$Comp
L RF_Module:ESP-12F U2
U 1 1 5D81043C
P 6600 3700
F 0 "U2" H 6600 4681 50  0000 C CNN
F 1 "ESP-12F" H 6600 4590 50  0000 C CNN
F 2 "RF_Module:ESP-12E" H 6600 3700 50  0001 C CNN
F 3 "http://wiki.ai-thinker.com/_media/esp8266/esp8266_series_modules_user_manual_v1.1.pdf" H 6250 3800 50  0001 C CNN
	1    6600 3700
	1    0    0    -1  
$EndComp
NoConn ~ 6000 3500
NoConn ~ 6000 4000
Wire Wire Line
	7200 3900 7450 3900
Wire Notes Line
	4300 2350 500  2350
Wire Notes Line
	4300 2350 4300 7800
Text Notes 500  2450 0    50   ~ 0
Ultrasound Sensors
$Comp
L Connector:Conn_01x04_Male J5
U 1 1 5D93A18F
P 600 2950
F 0 "J5" H 708 3231 50  0000 C CNN
F 1 "US1" H 708 3140 50  0000 C CNN
F 2 "Connector_PinHeader_1.00mm:PinHeader_1x04_P1.00mm_Vertical" H 600 2950 50  0001 C CNN
F 3 "~" H 600 2950 50  0001 C CNN
	1    600  2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	800  2850 1250 2850
Wire Wire Line
	800  3150 1250 3150
Wire Wire Line
	800  2950 1250 2950
Wire Wire Line
	800  3050 1250 3050
Text Label 950  2850 0    50   ~ 0
VCC
Text Label 950  3150 0    50   ~ 0
GND
Text Label 950  2950 0    50   ~ 0
US_T_1_5V
Text Label 950  3050 0    50   ~ 0
US_E_1_5V
$Comp
L Connector:Conn_01x04_Male J6
U 1 1 5D949902
P 1700 2950
F 0 "J6" H 1808 3231 50  0000 C CNN
F 1 "US2" H 1808 3140 50  0000 C CNN
F 2 "Connector_PinHeader_1.00mm:PinHeader_1x04_P1.00mm_Vertical" H 1700 2950 50  0001 C CNN
F 3 "~" H 1700 2950 50  0001 C CNN
	1    1700 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 2850 2350 2850
Wire Wire Line
	1900 3150 2350 3150
Wire Wire Line
	1900 2950 2350 2950
Wire Wire Line
	1900 3050 2350 3050
Text Label 2050 2850 0    50   ~ 0
VCC
Text Label 2050 3150 0    50   ~ 0
GND
Text Label 2050 2950 0    50   ~ 0
US_T_2_5V
Text Label 2050 3050 0    50   ~ 0
US_E_2_5V
Wire Wire Line
	8900 3150 8550 3150
Text Label 8550 3150 0    50   ~ 0
OE
NoConn ~ 6000 3900
$Comp
L Device:R R8
U 1 1 5D91A088
P 7700 4250
F 0 "R8" H 7770 4296 50  0000 L CNN
F 1 "10K" H 7770 4205 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 7630 4250 50  0001 C CNN
F 3 "~" H 7700 4250 50  0001 C CNN
	1    7700 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	7700 4550 7700 4400
Text Label 7700 4500 0    50   ~ 0
GND
Wire Wire Line
	7200 3400 7450 3400
Text Label 7200 3400 0    50   ~ 0
LED_2
NoConn ~ 8900 3850
NoConn ~ 8900 3950
NoConn ~ 9700 3850
NoConn ~ 9700 3950
NoConn ~ 7450 3900
Wire Wire Line
	7200 4100 7700 4100
Wire Wire Line
	7700 4100 7950 4100
Connection ~ 7700 4100
Text Label 7850 4100 0    50   ~ 0
OE
$EndSCHEMATC
