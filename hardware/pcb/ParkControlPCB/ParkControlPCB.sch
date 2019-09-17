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
P 2750 5050
F 0 "U1" H 2750 5292 50  0000 C CNN
F 1 "LM1117-3.3" H 2750 5201 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223" H 2750 5050 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm1117.pdf" H 2750 5050 50  0001 C CNN
	1    2750 5050
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
	2750 5350 2750 5400
Text Label 2750 5550 0    50   ~ 0
GND
Wire Wire Line
	2450 5050 2200 5050
Text Label 2200 5050 0    50   ~ 0
VCC
$Comp
L Device:CP C1
U 1 1 5D81651B
P 3300 5200
F 0 "C1" H 3418 5246 50  0000 L CNN
F 1 "100 μF" H 3418 5155 50  0000 L CNN
F 2 "Capacitor_Tantalum_SMD:CP_EIA-3528-12_Kemet-T_Pad1.50x2.35mm_HandSolder" H 3338 5050 50  0001 C CNN
F 3 "~" H 3300 5200 50  0001 C CNN
	1    3300 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 5050 3300 5050
Wire Wire Line
	3300 5050 3600 5050
Connection ~ 3300 5050
Text Label 3450 5050 0    50   ~ 0
3V3
Wire Wire Line
	2750 5400 3300 5400
Wire Wire Line
	3300 5400 3300 5350
Connection ~ 2750 5400
Wire Wire Line
	2750 5400 2750 5550
$EndSCHEMATC
