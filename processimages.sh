#!/bin/bash
target_folder="/Users/angel/Downloads/digital camera2"
program="/Users/angel/Downloads/給新生的 DC 競賽資料 2/sony_raw_decrypt/Debug/sony_clear.exe"

for file in "digital camera2"/*.srf; do
    "$program" "$file"
done

