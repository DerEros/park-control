EESchema Schematic File Version 4
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
Text Label 2500 7300 0    50   ~ 0
GND
Wire Wire Line
	2200 6800 1950 6800
Text Label 1950 6800 0    50   ~ 0
VCC
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
Wire Notes Line
	4300 6300 4300 7800
Text Notes 500  6400 0    50   ~ 0
Power
$Comp
L Connector:Jack-DC J1
U 1 1 5D8248FB
P 800 6950
F 0 "J1" H 857 7275 50  0000 C CNN
F 1 "Jack-DC" H 857 7184 50  0000 C CNN
F 2 "" H 850 6910 50  0001 C CNN
F 3 "~" H 850 6910 50  0001 C CNN
	1    800  6950
	1    0    0    -1  
$EndComp
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
	1100 6850 1250 6850
Wire Wire Line
	1250 6850 1250 6800
Wire Wire Line
	1250 6800 1500 6800
Wire Wire Line
	1750 6800 1500 6800
Connection ~ 1500 6800
Wire Wire Line
	1100 7050 1250 7050
Wire Wire Line
	1250 7050 1250 7100
Wire Wire Line
	1250 7100 1500 7100
Wire Wire Line
	1500 7100 1750 7100
Connection ~ 1500 7100
Text Label 1600 6800 0    50   ~ 0
VCC
Text Label 1600 7100 0    50   ~ 0
GND
$EndSCHEMATC
