void setup() {
  static HardwareTimer timer(TIM150);
  timer.setOverflow(2,HERTZ_FORMAT);
  timer.attachInterrupt(onTimer);
  timer.resume();
  pinMode(LED_BUILTINM, OUTPUT);

  pinMode(BUTTON, INPUT);
  attachInterrupt(digitalPinTiInterrupt(BUTTON), onInterrupt, FALLING);
  pinMode(D12,OUTPUT)

}

void loop() {
  loop1();
  loop2();

}

void loop1(void){
  static byte led {LOW};

  if(!isTimeUp) return;
  isTimeUp = LOW;
  led = !led;
  digitalWrite(LED_BUILTIN, led);
}

void loop2(void) {
  static byte led {LOW};
  
  if(!isInterrupt) return;
  delay(150);
  isInterrupt = LOW;
  led = !led;
  digitalWrite(D12, led);
}

void onTimer(void){
  isTimeUp = HIGH;
  
}