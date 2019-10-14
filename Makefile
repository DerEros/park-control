ESP_ROOT=$(HOME)/git/esp8266
ESPTOOL=$(ESP_ROOT)/tools/esptool/esptool.py
BOARD=nodemcuv2
FS_DIR=WebUI/dist

include $(HOME)/git/makeEspArduino/makeEspArduino.mk

nodemodules:
	cd WebUI && npm install

ui: nodemodules
	cd WebUI && npm run build

compressui: ui
	cd WebUI/dist/ && gzip *
