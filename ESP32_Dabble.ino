#define CUSTOM_SETTINGS
#define INCLUDE_TERMINAL_MODULE
#include <DabbleESP32.h>

void setup() {
  // 115200 is the standard baud rate for ESP32 boards
  Serial.begin(115200); 
  
  // Initialize Dabble Bluetooth with your desired device name
  Dabble.begin("ESP32_Dabble"); 
  
  Serial.println("Bluetooth is ready. Connect using Dabble app.");
}

void loop() {
  // This function must be called continuously to read smartphone data
  Dabble.processInput();

  if (Terminal.available()) {
    String message = Terminal.readString();
    
    // Print to the computer's Serial Monitor
    Serial.print("Received from phone: ");
    Serial.println(message);

    // Send a response back to the Dabble app Terminal
    Terminal.print("ESP32: Message received - ");
    Terminal.println(message);
  }
  
  // Small delay to maintain stability
  delay(10); 
}
