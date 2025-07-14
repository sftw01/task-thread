
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"

#include "driver/gpio.h"

#include "portmacro.h"
#include "FreeRTOSConfig.h"
#include "sdkconfig.h"

#define LED_GPIO_PIN 23 // GPIO pin for the LED

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

void app_main(void)
{
    gpio_set_direction(LED_GPIO_PIN, GPIO_MODE_OUTPUT); // Set the GPIO pin as output
    uint8_t sw = 0;

    while (1)
    {
        gpio_set_level(LED_GPIO_PIN, sw);      // Set the LED state
        sw = !sw;                              // Toggle the state
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay for 1 second

        const char *pinAsString = TOSTRING(LED_GPIO_PIN);
        printf("LED GPIO %s (%d) is %s\n", pinAsString, LED_GPIO_PIN, sw ? "ON" : "OFF");
    }
}
