#include <Arduino.h>

int c1 = 0;
int c2 = 0;
int c3 = 0;

static SemaphoreHandle_t mutex;

void task1(void *parameters)
{
  for (;;)
  {
    if (xSemaphoreTake(mutex, 0) == pdTRUE)
    {
      Serial.print("Task 1:");
      Serial.println(1);
      c1++;
      xSemaphoreGive(mutex);
    }
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
void task2(void *parameters)
{
  for (;;)
  {
    if (xSemaphoreTake(mutex, 0) == pdTRUE)
    {
      Serial.print("Task 2:");
      Serial.println(2);
      c2++;
      xSemaphoreGive(mutex);
    }
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
void task3(void *parameters)
{
  for (;;)
  {
    if (xSemaphoreTake(mutex, 0) == pdTRUE)
    {
      Serial.print("Task 3:");
      Serial.println(3);
      c3++;
      xSemaphoreGive(mutex);
    }
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
void setup()
{
  Serial.begin(115200);
  vTaskDelay(10000 / portTICK_PERIOD_MS);
  mutex = xSemaphoreCreateMutex();
  xTaskCreate(task1, "Task1", 1000, NULL, 1, NULL);
  vTaskDelay(10000 / portTICK_PERIOD_MS);
  xTaskCreate(task2, "Task2", 1000, NULL, 1, NULL);
  vTaskDelay(10000 / portTICK_PERIOD_MS);
  xTaskCreate(task3, "Task3", 1000, NULL, 1, NULL);
}

void loop()
{
}
