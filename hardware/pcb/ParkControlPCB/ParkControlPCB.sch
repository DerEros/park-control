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
L RF_Module:ESP-12F U2
U 1 1 5D81043C
P 5750 3800
F 0 "U2" H 5750 4781 50  0000 C CNN
F 1 "ESP-12F" H 5750 4690 50  0000 C CNN
F 2 "RF_Module:ESP-12E" H 5750 3800 50  0001 C CNN
F 3 "http://wiki.ai-thinker.com/_media/esp8266/esp8266_series_modules_user_manual_v1.1.pdf" H 5400 3900 50  0001 C CNN
	1    5750 3800
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:LM1117-3.3 U1
U 1 1 5D813E23
P 2500 6800
F 0 "U1" H 2500 7042 50  0000 C CNN
F 1 "LM1117-3.3" H 2500 6951 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223" H 2500 6800 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm1117.pdf" H 2500 6800 50  0001 C CNN
	1    2500 6800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 4500 5750 4750
Text Label 5750 4750 0    50   ~ 0
GND
Wire Wire Line
	5750 2700 5750 3000
Text Label 5750 2750 0    50   ~ 0
3V3
Wire Wire Line
	2500 7100 2500 7150
Wire Wire Line
	2200 6800 1950 6800
$Comp
L Device:CP C1
U 1 1 5D81651B
P 3050 6950
F 0 "C1" H 3168 6996 50  0000 L CNN
F 1 "100 μF" H 3168 6905 50  0000 L CNN
F 2 "Capacitor_Tantalum_SMD:CP_EIA-3528-12_Kemet-T_Pad1.50x2.35mm_HandSolder" H 3088 6800 50  0001 C CNN
F 3 "~" H 3050 6950 50  0001 C CNN
	1    3050 6950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 6800 3050 6800
Wire Wire Line
	3050 6800 3350 6800
Connection ~ 3050 6800
Text Label 3200 6800 0    50   ~ 0
3V3
Wire Wire Line
	2500 7150 3050 7150
Wire Wire Line
	3050 7150 3050 7100
Connection ~ 2500 7150
Wire Wire Line
	2500 7150 2500 7300
Wire Notes Line
	500  6300 4300 6300
Text Notes 500  6400 0    50   ~ 0
Power
$Comp
L Device:CP C2
U 1 1 5D825275
P 1500 6950
F 0 "C2" H 1618 6996 50  0000 L CNN
F 1 "1000 uF, 6,3V" H 1618 6905 50  0000 L CNN
F 2 "Capacitor_Tantalum_SMD:CP_EIA-3528-12_Kemet-T_Pad1.50x2.35mm_HandSolder" H 1538 6800 50  0001 C CNN
F 3 "~" H 1500 6950 50  0001 C CNN
	1    1500 6950
	1    0    0    -1  
$EndComp
Wire Wire Line
	1100 6900 1250 6900
Wire Wire Line
	1250 6900 1250 6800
Wire Wire Line
	1250 6800 1500 6800
Wire Wire Line
	1750 6800 1500 6800
Connection ~ 1500 6800
Wire Wire Line
	1100 7000 1250 7000
Wire Wire Line
	1250 7000 1250 7100
Wire Wire Line
	1250 7100 1500 7100
Wire Wire Line
	1500 7100 1750 7100
Connection ~ 1500 7100
Text Label 1600 6800 0    50   ~ 0
VCC
Text Label 1600 7100 0    50   ~ 0
GND
$Comp
L Connector:Conn_01x02_Male J2
U 1 1 5D8A7152
P 900 6900
F 0 "J2" H 1008 7081 50  0000 C CNN
F 1 "Conn_01x02_Male" H 1008 6990 50  0000 C CNN
F 2 "Connector_PinHeader_1.00mm:PinHeader_1x02_P1.00mm_Vertical" H 900 6900 50  0001 C CNN
F 3 "~" H 900 6900 50  0001 C CNN
	1    900  6900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5D8A8E66
P 1250 7100
F 0 "#PWR0101" H 1250 6850 50  0001 C CNN
F 1 "GND" H 1255 6927 50  0000 C CNN
F 2 "" H 1250 7100 50  0001 C CNN
F 3 "" H 1250 7100 50  0001 C CNN
	1    1250 7100
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0102
U 1 1 5D8A9159
P 1250 6800
F 0 "#PWR0102" H 1250 6650 50  0001 C CNN
F 1 "VCC" H 1267 6973 50  0000 C CNN
F 2 "" H 1250 6800 50  0001 C CNN
F 3 "" H 1250 6800 50  0001 C CNN
	1    1250 6800
	1    0    0    -1  
$EndComp
Text Label 1950 6800 0    50   ~ 0
VCC
Text Label 2500 7300 0    50   ~ 0
GND
Connection ~ 1250 6800
Connection ~ 1250 7100
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
P 800 7500
F 0 "#PWR0104" H 800 7250 50  0001 C CNN
F 1 "GND" H 805 7327 50  0000 C CNN
F 2 "" H 800 7500 50  0001 C CNN
F 3 "" H 800 7500 50  0001 C CNN
	1    800  7500
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
P 800 7400
F 0 "#FLG0102" H 800 7475 50  0001 C CNN
F 1 "PWR_FLAG" H 800 7573 50  0000 C CNN
F 2 "" H 800 7400 50  0001 C CNN
F 3 "~" H 800 7400 50  0001 C CNN
	1    800  7400
	1    0    0    -1  
$EndComp
Wire Wire Line
	800  7400 800  7500
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
F 1 "Conn_01x04_Male" H 908 5790 50  0000 C CNN
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
	5150 3800 4900 3800
Wire Wire Line
	5150 3900 4900 3900
Wire Wire Line
	5150 4200 4900 4200
Wire Wire Line
	5150 4300 4900 4300
Text Label 4900 3800 0    50   ~ 0
SS
Text Label 4900 3900 0    50   ~ 0
MISO
Text Label 4900 4200 0    50   ~ 0
MOSI
Text Label 4900 4300 0    50   ~ 0
SCK
Wire Notes Line
	4300 3700 500  3700
Wire Notes Line
	4300 3700 4300 7800
Text Notes 500  3800 0    50   ~ 0
LED Connectors
$Comp
L Connector:Conn_01x03_Male J3
U 1 1 5D8B6DB2
P 800 4350
F 0 "J3" H 908 4631 50  0000 C CNN
F 1 "Conn_01x03_Male" H 908 4540 50  0000 C CNN
F 2 "Connector_PinHeader_1.00mm:PinHeader_1x03_P1.00mm_Vertical" H 800 4350 50  0001 C CNN
F 3 "~" H 800 4350 50  0001 C CNN
	1    800  4350
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Male J4
U 1 1 5D8B72A1
P 1900 4350
F 0 "J4" H 2008 4631 50  0000 C CNN
F 1 "Conn_01x03_Male" H 2008 4540 50  0000 C CNN
F 2 "Connector_PinHeader_1.00mm:PinHeader_1x03_P1.00mm_Vertical" H 1900 4350 50  0001 C CNN
F 3 "~" H 1900 4350 50  0001 C CNN
	1    1900 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	1000 4250 1450 4250
Wire Wire Line
	1000 4350 1450 4350
Wire Wire Line
	1000 4450 1450 4450
Wire Wire Line
	2100 4250 2600 4250
Wire Wire Line
	2100 4350 2600 4350
Wire Wire Line
	2100 4450 2600 4450
Text Label 1300 4250 0    50   ~ 0
VCC
Text Label 2450 4250 0    50   ~ 0
VCC
Text Label 1300 4450 0    50   ~ 0
GND
Text Label 2450 4450 0    50   ~ 0
GND
Text Label 1300 4350 0    50   ~ 0
DIN_LED_1
Text Label 2450 4350 0    50   ~ 0
DIN_LED_2
Wire Notes Line
	2050 6300 2050 5050
Wire Wire Line
	8350 2950 8350 2700
Wire Wire Line
	8550 2950 8550 2700
Text Label 8350 2750 3    50   ~ 0
3V3
Text Label 8550 2750 3    50   ~ 0
VCC
Wire Wire Line
	8450 4350 8450 4750
Text Label 8450 4750 1    50   ~ 0
GND
$Comp
L Logic_LevelTranslator:TXS0108EPW U3
U 1 1 5D8C9423
P 8450 3650
F 0 "U3" H 8450 2861 50  0000 C CNN
F 1 "TXS0108EPW" H 8450 2770 50  0000 C CNN
F 2 "Package_SO:TSSOP-20_4.4x6.5mm_P0.65mm" H 8450 2900 50  0001 C CNN
F 3 "www.ti.com/lit/ds/symlink/txs0108e.pdf" H 8450 3550 50  0001 C CNN
	1    8450 3650
	1    0    0    -1  
$EndComp
$EndSCHEMATC
