#include <STM32FreeRTOS.h>


  void blink1Task (void *pvParameters) {
    UNUSED(pvParameters);
    pinMode(LED_BUILTIN, OUTPUT);

    while (true){
      digitalWrite(LED_BUILTIN, HIGH);
      vTaskDelay(configTICK_RATE_HZ);
      digitalWrite(LED_BUILTIN, LOW);
      vTaskDelay(configTICK_RATE_HZ);
    }
    
  }

  void message (void *pvParameters){
    UNUSED(pvParameters);
    pinMode(D2,INPUT);

    while(true) {
        Serial.println("Hola Mundo");
        vTaskDelay(configTICK_RATE_HZ / 10); // Pequeña pausa para evitar rebotes del botón
    }
  }




void setup(){
  Serial.begin(9600);

  xTaskCreate(blink1Task, "Task1", configMINIMAL_STACK_SIZE +50, NULL,tskIDLE_PRIORITY +1, NULL);
  xTaskCreate(message, "Task2", configMINIMAL_STACK_SIZE +50, NULL,tskIDLE_PRIORITY +2, NULL);
  
  vTaskStartScheduler();

  Serial.println("Die");
  while(1);

}

void loop() {}
