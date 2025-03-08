# !/bin/bash

EsptoolPath="esptool.py"

BaseArgs="--chip esp32 --baud 115200"
SetupArgs="--before default_reset --after hard_reset write_flash -z --flash_mode dio --flash_freq 80m --flash_size detect"

echo $EsptoolPath $BaseArgs erase_flash
$EsptoolPath $BaseArgs erase_flash