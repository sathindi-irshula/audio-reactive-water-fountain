const int VALVE1_PIN = 2; // Low
const int VALVE2_PIN = 3; // Low-Mid
const int VALVE3_PIN = 4; // High-Mid
const int VALVE4_PIN = 5; // High

#define RELAY_ON  LOW
#define RELAY_OFF HIGH

char inputBuffer[32];
byte bufferPos = 0;

void processCommand(char* command);

void setup() {
  Serial.begin(115200);

  digitalWrite(VALVE1_PIN, RELAY_OFF);
  digitalWrite(VALVE2_PIN, RELAY_OFF);
  digitalWrite(VALVE3_PIN, RELAY_OFF);
  digitalWrite(VALVE4_PIN, RELAY_OFF);

  pinMode(VALVE1_PIN, OUTPUT);
  pinMode(VALVE2_PIN, OUTPUT);
  pinMode(VALVE3_PIN, OUTPUT);
  pinMode(VALVE4_PIN, OUTPUT);

  Serial.println("SYSTEM_READY");
}

void loop() {
  while (Serial.available() > 0) {
    char inChar = Serial.read();

    if (inChar == '\n' || inChar == '\r') {
      if (bufferPos > 0) {
        inputBuffer[bufferPos] = '\0';
        processCommand(inputBuffer);
        bufferPos = 0;
      }
    } else {
      if (bufferPos < sizeof(inputBuffer) - 1) {
        inputBuffer[bufferPos++] = inChar;
      }
    }
  }
}

void processCommand(char* command) {
  String cmd = String(command);
  cmd.trim();

  if (cmd == "LOW_1")          { digitalWrite(VALVE1_PIN, RELAY_ON);  }
  else if (cmd == "LOW_0")     { digitalWrite(VALVE1_PIN, RELAY_OFF); }
  else if (cmd == "LOWMID_1")  { digitalWrite(VALVE2_PIN, RELAY_ON);  }
  else if (cmd == "LOWMID_0")  { digitalWrite(VALVE2_PIN, RELAY_OFF); }
  else if (cmd == "HIGHMID_1") { digitalWrite(VALVE3_PIN, RELAY_ON);  }
  else if (cmd == "HIGHMID_0") { digitalWrite(VALVE3_PIN, RELAY_OFF); }
  else if (cmd == "HIGH_1")    { digitalWrite(VALVE4_PIN, RELAY_ON);  }
  else if (cmd == "HIGH_0")    { digitalWrite(VALVE4_PIN, RELAY_OFF); }
  else if (cmd == "ALL_ON")    {
    digitalWrite(VALVE1_PIN, RELAY_ON);
    digitalWrite(VALVE2_PIN, RELAY_ON);
    digitalWrite(VALVE3_PIN, RELAY_ON);
    digitalWrite(VALVE4_PIN, RELAY_ON);
  }
  else if (cmd == "ALL_OFF")   {
    digitalWrite(VALVE1_PIN, RELAY_OFF);
    digitalWrite(VALVE2_PIN, RELAY_OFF);
    digitalWrite(VALVE3_PIN, RELAY_OFF);
    digitalWrite(VALVE4_PIN, RELAY_OFF);
  }
}
