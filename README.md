# ArduMonitor
Shows real-time CPU and RAM statistics of a Linux Machine on a LCD display via Arduino.

[See it in action (Video)](https://gfycat.com/WhiteGrandioseAsianlion)

<img src="http://i.imgur.com/4EwSknUl.jpg?2">

## Hardware
  - Arduino UNO
  - HD44780 LCD Display
  - Ethernet Shield
  - A Linux machine (bash, ruby, PHP)

## Software
  - **statPoll.sh** The resident bash script. Fetches the stats from `/proc/meminfo` and `uptime` and runs `statParse.rb` on them;

  - **statParse.rb** Parses the relevant informations;

  - **statWeb.php** Reads the final file and prints in a webpage;

  - **statRead.ino** The Arduino program. Sets up the display and the ethernet shield. Connects to Network and prints the results and a refresh indicator.
