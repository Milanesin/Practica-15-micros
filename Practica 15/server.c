/**
 * Copyright (c) 2023 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "btstack.h"
#include "pico/cyw43_arch.h"
#include "pico/btstack_cyw43.h"
#include "hardware/adc.h"
#include "pico/stdlib.h"

#include "server_common.h"

#define HEARTBEAT_PERIOD_MS 100

static btstack_timer_source_t heartbeat;
static btstack_packet_callback_registration_t hci_event_callback_registration;

// Función que se ejecuta cada HEARTBEAT_PERIOD_MS
static void heartbeat_handler(struct btstack_timer_source *ts) {
    static uint32_t counter = 0;
    counter++;

    if (counter % 10 == 0) {
        poll_temp();

        if (le_notification_enabled) {
            att_server_request_can_send_now_event(con_handle);
        }
    }

    static int led_on = true;
    led_on = !led_on;
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, led_on);

    btstack_run_loop_set_timer(ts, HEARTBEAT_PERIOD_MS);
    btstack_run_loop_add_timer(ts);
}

int main() {
    stdio_init_all();

    if (cyw43_arch_init()) {
        printf("Wi-Fi init failed");
        return -1;
    }

    // informar sobre el estado de BTstack
    hci_event_callback_registration.callback = &packet_handler;
    hci_add_event_handler(&hci_event_callback_registration);

    // registrar para eventos ATT
    att_server_register_packet_handler(packet_handler);

    // configurar temporizador heartbeat
    heartbeat.process = &heartbeat_handler;
    btstack_run_loop_set_timer(&heartbeat, HEARTBEAT_PERIOD_MS);
    btstack_run_loop_add_timer(&heartbeat);

    // encender bluetooth
    hci_power_control(HCI_POWER_ON);

    // ejecutar bucle principal
#if 0
    // si usas cyw43_arch_poll
    btstack_run_loop_execute();
#else
    // bucle infinito para seguir ejecutando el código
    while (true) {
        sleep_ms(100);
    }
#endif

    return 0;
}
