// |------------------------------- HEADER -------------------------------------------------------|
// APPLICATION:      GM-UART BLUETOOTH ADAPTER
// PURPOSE:          MAIN
// AUTHOR:           JUSTIN BLAND
// DATE:             22/11/2020
// AUDIT DATE:
// STATUS:           IN DEVELOPMENT
//
// LICENCE:          CREATIVE COMMONS (CC BY-NC-SA 4.0)
//
// DESIGNED MCU:     TEST - ESP32 DEV MODULE | PRODUCTION - ESP32 WROOM-32
//
// REVISIONS:
//                   22/11/2020  FILE CREATION

// |------------------------------- HELPFUL INFO -------------------------------------------------|
  // ESP-32 PINOUT (USEFUL ONLY)
    // SERIAL PINS
      //  GM-UART PINS        GPIO-17 TX | GPIO-16 RX | HARDWARE SERIAL
      //  PROGRAMMING SERIAL  GPIO-01 TX | GPIO-03 RX | HARDWARE SERIAL
      //  DIAGNOSTIC SERIAL   GPIO-01 TX | GPIO-03 RX | HARDWARE SERIAL
      
    // STATUS LEDS
      //  SYSTEM OK LED       GPIO-25
      //  SYSTEM FAULT LED    GPIO-26
      //  BT CONNECTED LED    GPIO-27

    // FUNCTION PINS
      // DIAGNOSTIC ENABLE    GPIOXX  | PULL HIGH TO ENABLE

// |------------------------------- DEFINITIONS --------------------------------------------------|
#include "HardwareSerial.h"
#include "BluetoothSerial.h"

const int OKLed = 25;
const int FaultLed = 26;
const int BTConLed = 27;

HardwareSerial DiagnosticSerial(0);

HardwareSerial UartSerial(2);
BluetoothSerial SerialBT;

bool DebugEn = false;
bool BTClien = false;

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif




// |------------------------------- PROGRAM START ------------------------------------------------|
void setup() {
  // Open GM-UART port
  UartSerial.begin(8192);
  UartSerial.setRxBufferSize(1024);
  // Open Bluetooth Serial
  SerialBT.begin("Blue Dragon ALDL");

  SerialBT.register_callback(callback);


  // Open Debug
   if (DebugEn = true)
    {
      DiagnosticSerial.begin(115200);
    }
}

void loop()
{
    if (BTClien = true)
    {
      
        // read from port 1, send to port 0:
        if (SerialBT.available()) {
            int inByte = SerialBT.read();
            UartSerial.write(inByte);
        }

        // read from port 0, send to port 1:
        if (UartSerial.available()) {
            int inByte = UartSerial.read();
            SerialBT.write(inByte);
        }
    }
}

// |------------------------------- SPECIAL FUNCTIONS --------------------------------------------|
void DiagOutput(String msg)
{
  if (DebugEn = true)
  {
    DiagnosticSerial.println(msg);
  }
}

void ErrorOutput(String msg)
{
    DiagOutput(msg);
    DiagOutput("Restarting Device in 5 Seconds.....");
    delay(5000);
    ESP.restart();
}

void ToggleOKLed(bool onoff)
{
    if (onoff == true) 
    {
        ToggleFaultLed(false);
        digitalWrite(OKLed, HIGH);
    }
    else if (onoff == false) 
    {
        ToggleFaultLed(true);
        digitalWrite(OKLed, LOW);
    }
    else 
    {
        ErrorOutput("ERROR! - OK LED | Schrodinger's Boolean");
    }
}

void ToggleFaultLed(bool onoff)
{
    if (onoff == true)
    {
        ToggleOKLed(false);
        digitalWrite(FaultLed, HIGH);
    }

    else if (onoff == false) 
    {
        ToggleOKLed(true);
        digitalWrite(FaultLed, HIGH);
    }
    else
    {
        ErrorOutput("ERROR! - Fault LED | Schrodinger's Boolean");
    }
}

void ToggleBTCon(bool onoff) 
{
    if (onoff == true)
    {
        // Digital Write BT Connection LED
        digitalWrite(BTConLed, HIGH);
        DiagOutput("Bluetooth Client Connected");
        BTClien = true;
    }
    else if (onoff == false)
    {
        digitalWrite(BTConLed, LOW);
        DiagOutput("Bluetooth Client Disconnected");
        BTClien = false;
    }
    else
    {
        ErrorOutput("ERROR! - BT LED | Schrodinger's Boolean");
    }
}

void callback(esp_spp_cb_event_t event, esp_spp_cb_param_t* param) {
    if (event == ESP_SPP_SRV_OPEN_EVT) {
        ToggleBTCon(true);
        String BTMac = "Client Mac: ";
        for (int i = 0; i < 6; i++) {

            int temp = (param->srv_open.rem_bda[i]);
            BTMac += (String(temp));

            if (i < 5) {
                BTMac += (":");
            }

        }
        DiagOutput(BTMac);
    }
    if (event == ESP_SPP_CLOSE_EVT)
    {
        ToggleBTCon(false);       
    }
}