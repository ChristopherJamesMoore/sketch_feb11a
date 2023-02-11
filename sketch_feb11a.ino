// mains presence variables
const byte Mains_Presence_Pin = 15;
unsigned long PreviousMillis = 0;
const long INTERVAL = 10000;
unsigned long currentMillis;

const int Red_LED = 3;
const int Green_LED = 13;
const byte Relay_Pin = 2;

// battery voltage check
const byte V_Measure_Pin = 16;
long int V_Measure; // voltage read from ADC
long V_Average;
long V_Value_X_Ten;
const byte Charge_Increase = 5;

void setup() {
  pinMode (V_Measure_Pin, INPUT); // measure battery voltage
  pinMode (Mains_Presence_Pin, INPUT_PULLUP); // measure mains presence
  pinMode (Relay_Pin, OUTPUT); // relay
  pinMode (Red_LED, OUTPUT);
  pinMode (Green_LED, OUTPUT);
  Serial.begin (9600); // serial port
  POST();
}

void POST() { // initial check 

  // checking for mains on start up
  long Now_Time = millis ();
  bool Mains_On = false;
  do
  {
    if (digitalRead (Mains_Presence_Pin) == LOW)
    {
      Mains_On = true; // mains detected
      Serial.print (Mains_On); // serial port
    }
  } while (millis () - Now_Time >= 1000); // in theory will not overflow

  // checking for battery voltage on start up
  for (int Read_One_Hundred = 0; Read_One_Hundred <= 100; Read_One_Hundred++)
  {
    V_Measure = analogRead (V_Measure_Pin);
    long V_Value_X_Ten = (V_Measure * 10) / 64;
    V_Average + V_Value_X_Ten;
  }
  long V_Average = V_Average / 100;
  if (V_Value_X_Ten > 122 && V_Value_X_Ten < 147)
  {
    // battery health OK
    Serial.print (V_Average); // serial port
  }
  digitalWrite (Relay_Pin, HIGH);
  for (int Charge_For = 0; Charge_For < 11; Charge_For++)
  {
    digitalWrite (Green_LED, HIGH);
    delay (250);
    digitalWrite (Green_LED, LOW);
    delay (750);
  }
  V_Measure = analogRead (V_Measure_Pin);
  long v_Value_X_Ten = (V_Measure * 10) / 64;
  if (v_Value_X_Ten >= V_Average + Charge_Increase)
  {
    Serial.print (V_Average); // serial port
    // charge OK
  }
  loop();
}

void loop() { // main iteration

  // battery monitoring
    // average voltage
  // ov protection
  // mains on check
  // charging
  // 
}
