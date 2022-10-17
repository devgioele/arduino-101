const int signal_length = 100;
const int pause_length = 1500;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(signal_length);
  digitalWrite(LED_BUILTIN, LOW);
  delay(pause_length);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(signal_length);
  digitalWrite(LED_BUILTIN, LOW);
  delay(pause_length);
}
