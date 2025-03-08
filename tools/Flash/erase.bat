@echo off

set EsptoolPath=win64\esptool.exe

set BaseArgs=--chip esp32 --baud 115200
set SetupArgs=--before default_reset --after hard_reset write_flash -z --flash_mode dio --flash_freq 80m --flash_size detect

echo %EsptoolPath% %BaseArgs% erase_flash
%EsptoolPath% %BaseArgs% erase_flash

pause
