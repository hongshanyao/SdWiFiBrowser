# !/bin/bash

echo "Today is $(date) "

BinaryDir="binary"
EsptoolPath="esptool.py"

BaseArgs="--chip esp32 --baud 115200"
SetupArgs="--before default_reset --after hard_reset write_flash -z --flash_mode dio --flash_freq 80m --flash_size detect"

Bootloader="0x1000 $BinaryDir/bootloader_dio_80m.bin"
Bootapp="0xe000 $BinaryDir/boot_app0.bin"
Partitions="0x8000 $BinaryDir/partitions_8M.bin"
Firmware="0x10000 $BinaryDir/firmware-8M.bin"
LocalFS="0x670000 $BinaryDir/spiffs_8M.bin"

echo $EsptoolPath $BaseArgs $SetupArgs $Bootloader $Bootapp $Firmware $Partitions
$EsptoolPath $BaseArgs $SetupArgs $Bootloader $Bootapp $Firmware $Partitions

echo $EsptoolPath $BaseArgs $SetupArgs $LocalFS
$EsptoolPath $BaseArgs $SetupArgs $LocalFS