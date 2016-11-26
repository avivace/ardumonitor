/* 
  ## ArduMonitor ##
  Antonio Vivace, 2016
  twitter.com/avivace4
  github.com/avivace/ardumonitor
  LICENSED UNDER GPL-3.0
*/

#include <SPI.h>
#include <Ethernet.h>
#include <LiquidCrystal.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

IPAddress server(51,254,100,118);

// Fallback IP if DHCP fails to assing
IPAddress ip(192, 168, 0, 177);

// Init Ethernet
EthernetClient client;

// Init LCD
LiquidCrystal lcd(19, 18, 17, 16, 15, 14);

void setup() {
  // Digital pins are fucked up by the ethernet shield
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);

  // LCD Setup
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Starting");

  // Open Serial
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect (needed for native USB)
  }

  // start the Ethernet connection:
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // try to congifure using IP address instead of DHCP:
    Ethernet.begin(mac, ip);
  }
  // give the Ethernet shield a second to initialize:
  lcd.clear();
  lcd.print("Connecting");
  delay(1000);
  Serial.println("connecting...");

  lcd.clear();

      // if you get a connection, report back via serial:
  if (client.connect(server, 80)) {
    lcd.print("Connected");
    Serial.println("connected");
    // Make a HTTP request:
    client.println("GET /your/file.php HTTP/1.1");
    client.println("Host: YOUR IP");
    client.println("Connection: close");
    client.println();
  } else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }

}

void loop() {
  lcd.setCursor(15, 0);
  lcd.print("#");

  boolean data = false;
  String str;
  // incoming bytes
  while (client.available()) {
    char c = client.read();
    if (data) str.concat(c);
    if (c == '+') data = true;
    Serial.print(c);
  }

  lcd.setCursor(0, 0);
	lcd.print(str.substring(1));
  // if the server's disconnected, stop the client:
  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();
    Serial.println(str);
    lcd.setCursor(15, 0);
    lcd.print(" ");
  }

  delay(1000);

  // if you get a connection, report back via serial:
  if (client.connect(server, 80)) {
    // lcd.print("Connected");
    Serial.println("connected");
    // Make a HTTP request:
    client.println("GET /your/file.php HTTP/1.1");
    client.println("Host: YOUR IP");
    client.println("Connection: close");
    client.println();
    lcd.setCursor(0, 1);
    lcd.print("  RAM    avgLoad");
  } else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }
}