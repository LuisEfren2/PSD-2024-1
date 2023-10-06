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


void blink2Task(void *pvParameters) {
  UNUSED(pvParameters);
  pinMode(D12, OUTPUT);

  while(true){
    digitalWrite(D12, HIGH);
    vTaskDelay((500UL*configTICK_RATE_HZ)/1000UL);
    digitalWrite(D12, LOW);
    vTaskDelay((500UL*configTICK_RATE_HZ)/1000UL);
  }
}

  void blink3Task (void *pvParameters) {
    UNUSED(pvParameters);
    pinMode(D11, OUTPUT);

    while (true){
      digitalWrite(D11, HIGH);
      vTaskDelay(configTICK_RATE_HZ);
      digitalWrite(D11, LOW);
      vTaskDelay(configTICK_RATE_HZ);
    }
  }

void setup(){
  Serial.begin(9600);

  xTaskCreate(blink1Task, "Task1", configMINIMAL_STACK_SIZE +50, NULL,tskIDLE_PRIORITY +2, NULL);

  xTaskCreate(blink2Task, "Task2", configMINIMAL_STACK_SIZE +50, NULL,tskIDLE_PRIORITY +1, NULL);

  xTaskCreate(blink3Task, "Task3", configMINIMAL_STACK_SIZE +50, NULL,tskIDLE_PRIORITY +1, NULL);
  
  vTaskStartScheduler();

  Serial.println("Die");
  while(1);

}

void loop() {}
