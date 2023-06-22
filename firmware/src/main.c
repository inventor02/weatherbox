#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "pico/cyw43_arch.h"
#include "lwip/netif.h"

#include "config/hardware.h"
#include "config/network.h"

__attribute__((noreturn)) void tight_blink_loop()
{
  while (true)
  {
    cyw43_arch_gpio_put(PIN_LED, true);
    sleep_ms(500);
    cyw43_arch_gpio_put(PIN_LED, false);
    sleep_ms(500);
  }
}

bool debug_init()
{
  stdio_uart_init();
  printf("weatherbox, version %s\n", BUILD_VERSION);

  return true;
}

bool network_init()
{
  printf("initialising network\n");
  printf("SSID is %s\n", CFG_WIFI_SSID);

  cyw43_arch_enable_sta_mode();
  if (cyw43_arch_wifi_connect_timeout_ms(CFG_WIFI_SSID, CFG_WIFI_PASSWORD, CYW43_AUTH_WPA2_AES_PSK, CFG_NETWORK_CONN_TIMEOUT))
  {
    printf("failed to connect to wireless network!\n");
    return false;
  }

  printf("network connected\n");
  netif_set_hostname(netif_default, "weatherbox");
  printf("IP: %s\n", ip4addr_ntoa(netif_ip4_addr(netif_default)));

  return true;
}

bool init()
{
  #ifdef BUILD_DEBUG
    debug_init();
  #endif

  unsigned char cc1 = CFG_CYW43_COUNTRY & 0x0000ff;
  unsigned char cc2 = (CFG_CYW43_COUNTRY & 0x00ff00) >> 8;
  uint8_t rev = (CFG_CYW43_COUNTRY & 0xff0000) >> 16;
  printf("CYW43 country is %c%c rev %d\n", cc1, cc2, rev);

  if (cyw43_arch_init_with_country(CFG_CYW43_COUNTRY)) {
    printf("CYW43 init failed!\n");
    return false;
  }

  cyw43_arch_gpio_put(PIN_LED, 1);

  if (!network_init())
  {
    printf("could not init network!\n");
    return false;
  }
}

void main()
{
  if (!init())
  {
    printf("initialisation failed!\n");
    tight_blink_loop();
  }

  // TODO: main method stub
  for (;;) tight_loop_contents();
}