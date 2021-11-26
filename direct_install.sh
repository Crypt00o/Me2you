#!/bin/bash
#RED="\e[31m"
ORANGE="\e[33m"
#BLUE="\e[94m"
#GREEN="\e[92m"
STOP="\e[0m"
BLACK="\e[90m"
RED="\e[91m"
GREEN="\e[92m"
YELLOW="\e[93m"
BLUE="\e[94m"
PURPLE="\e[95m"
CYAN="\e[96m"
WHITE="\e[97m"

# Checking Device Arch 
printf "${BLUE}"
printf "=========================================\n"
printf "${GREEN}"
echo "
 __  __      ____                    
|  \/  | ___|___ \ _   _  ___  _   _ 
| |\/| |/ _ \ __) | | | |/ _ \| | | |
| |  | |  __// __/| |_| | (_) | |_| |
|_|  |_|\___|_____|\__, |\___/ \__,_|
                   |___/             "
printf "${ORANGE}"
printf "\neslam,s Me2you Chat App "
printf "${RED}"; echo "    +01095456354"
printf "${BLUE}"
printf "========================================="
echo ' ';echo ' '
sleep 5
printf "${BLUE}"
printf "\n[-] Starting Daownloading [-]"
printf "${YELLOW}"
git clone "https://github.com/Crypt00o/Me2you" ; cd Me2you
printf "${GREEN}"
echo "[+] Checking Device Arch [+] "
printf "${YELLOW}"
for i in {1..50} 
do sleep 0.05 ;printf "."
done
printf "${GREEN}"
printf " [%%100] "
sleep 2
start(){
machine=$(uname -m);
if [ $machine == "x86_64" ] 
then cp linux/amd64/* . ;chmod +x client ;chmod +x server;
elif [ $machine == "i686" ] 
then cp linux/i686/* . ;chmod +x client ;chmod +x server;
elif [ $machine == "aarch64" ] 
then cp linux/aarch64/* . ;chmod +x client ;chmod +x server;
fi
}
start
printf "${YELLOW}"
printf "\n\t\t[+] Done [+] "
printf "${RED}" 
printf "\n\n now you can use :\n "
printf "${GREEN}"
printf "./server <port>  #example : ./server 8080 \n"
printf "./client <ip> <port> #example : ./client 127.0.0.1 8080"
printf "${STOP}"
