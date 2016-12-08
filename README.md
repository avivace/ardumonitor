# ArduMonitor
Shows real-time CPU and RAM statistics of a **remote** Linux Machine on a LCD display via Arduino or on a web frontend. There is a Server software, running  on the machine you want to monitor and some Clients, to see the stats in realtime on varius platforms.

[Arduino in action (Video)](https://gfycat.com/WhiteGrandioseAsianlion)
<img src="http://i.imgur.com/4EwSknUl.jpg?2">


## Client
#### Arduino
  - Arduino UNO
  - HD44780 LCD Display
  - Ethernet Shield

**statRead.ino** is the Arduino software. Sets up the display and the ethernet shield. Connects to Network and prints the results and a refresh indicator.

#### Web Frontend
HTML5 and some JS for fancy effects.


## Server
  - **statPoll.sh** The resident bash script. Fetches the stats from `/proc/meminfo`,`uptime`, `vnstat` and runs `statParse.rb` on them;

  - **statParse.rb** Parses the relevant informations;

  - **statWeb.php** Reads the final file and prints in a webpage;

Be sure to sync the refresh rates of the server and the client so you don't waste work. Keep in mind that the `loadAvg` array in statParse contains the last 1 - 5 - 15 minutes average load.

## Related implementations
#### Local Machine
This project is focused on having a **standalone** Arduino configuration to monitor a remote Linux computer. Instead, if you have phisical access to the machine you want to monitor, you can just send the data via serial and print them on the display, without connecting it to the Network.

#### Windows Server
A cool application of this concept could be a real-time monitor of a gaming PC, showing every CPU and GPU core load, RAM and VRAM usage, temperature sensors, fan speeds, memory and processor clocks and so on.

I've a sort of early release of this, showing only RAM and CPU usage using a resident VB script (the stats are from `ComputerInfo` .NET Framework property).

Fetching the stats from Windows isn't easy as on Linux, and that solution didn't bring me far. On the other hand, Open Hardware Monitor can provide all the stats I mentioned above and has a data interface. This should provide a good point of start.
