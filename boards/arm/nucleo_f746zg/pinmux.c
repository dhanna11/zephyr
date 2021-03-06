/*
 * Copyright (c) 2018 Adam Palmer
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <kernel.h>
#include <device.h>
#include <init.h>
#include <pinmux.h>
#include <sys_io.h>

#include <pinmux/stm32/pinmux_stm32.h>

/* NUCLEO-F746ZG pin configurations  */
static const struct pin_config pinconf[] = {
#ifdef CONFIG_UART_STM32_PORT_2
	{ STM32_PIN_PD5, STM32F7_PINMUX_FUNC_PD5_USART2_TX },
	{ STM32_PIN_PD6, STM32F7_PINMUX_FUNC_PD6_USART2_RX },
	{ STM32_PIN_PD4, STM32F7_PINMUX_FUNC_PD4_USART2_RTS },
	{ STM32_PIN_PD3, STM32F7_PINMUX_FUNC_PD3_USART2_CTS },
#endif
#ifdef CONFIG_UART_STM32_PORT_3
	{ STM32_PIN_PD8, STM32F7_PINMUX_FUNC_PD8_USART3_TX },
	{ STM32_PIN_PD9, STM32F7_PINMUX_FUNC_PD9_USART3_RX },
#endif
#ifdef CONFIG_UART_STM32_PORT_6
	{ STM32_PIN_PG14, STM32F7_PINMUX_FUNC_PG14_USART6_TX },
	{ STM32_PIN_PG9, STM32F7_PINMUX_FUNC_PG9_USART6_RX },
#endif
#ifdef CONFIG_ETH_STM32_HAL
	{ STM32_PIN_PC1, STM32F7_PINMUX_FUNC_PC1_ETH },
	{ STM32_PIN_PC4, STM32F7_PINMUX_FUNC_PC4_ETH },
	{ STM32_PIN_PC5, STM32F7_PINMUX_FUNC_PC5_ETH },
	{ STM32_PIN_PA1, STM32F7_PINMUX_FUNC_PA1_ETH },
	{ STM32_PIN_PA2, STM32F7_PINMUX_FUNC_PA2_ETH },
	{ STM32_PIN_PA7, STM32F7_PINMUX_FUNC_PA7_ETH },
	{ STM32_PIN_PG11, STM32F7_PINMUX_FUNC_PG11_ETH },
	{ STM32_PIN_PG13, STM32F7_PINMUX_FUNC_PG13_ETH },
	{ STM32_PIN_PB13, STM32F7_PINMUX_FUNC_PB13_ETH },
#endif  /* CONFIG_ETH_STM32_HAL */
#ifdef CONFIG_USB_DC_STM32
	{ STM32_PIN_PA11, STM32F7_PINMUX_FUNC_PA11_OTG_FS_DM },
	{ STM32_PIN_PA12, STM32F7_PINMUX_FUNC_PA12_OTG_FS_DP },
#endif	/* CONFIG_USB_DC_STM32 */
#ifdef CONFIG_I2C_1
	{ STM32_PIN_PB8, STM32F7_PINMUX_FUNC_PB8_I2C1_SCL },
	{ STM32_PIN_PB9, STM32F7_PINMUX_FUNC_PB9_I2C1_SDA },
#endif
#ifdef CONFIG_PWM_STM32_1
	{ STM32_PIN_PE13, STM32F7_PINMUX_FUNC_PE13_PWM1_CH3 },
#endif /* CONFIG_PWM_STM32_1 */
#ifdef CONFIG_SPI_1
	{ STM32_PIN_PA4, STM32F7_PINMUX_FUNC_PA4_SPI1_NSS },
	{ STM32_PIN_PA5, STM32F7_PINMUX_FUNC_PA5_SPI1_SCK },
	{ STM32_PIN_PA6, STM32F7_PINMUX_FUNC_PA6_SPI1_MISO },
	{ STM32_PIN_PA7, STM32F7_PINMUX_FUNC_PA7_SPI1_MOSI },
#endif	/* CONFIG_SPI_1 */
};

static int pinmux_stm32_init(struct device *port)
{
	ARG_UNUSED(port);

	stm32_setup_pins(pinconf, ARRAY_SIZE(pinconf));

	return 0;
}

SYS_INIT(pinmux_stm32_init, PRE_KERNEL_1,
	 CONFIG_PINMUX_STM32_DEVICE_INITIALIZATION_PRIORITY);
