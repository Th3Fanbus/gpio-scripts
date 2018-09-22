#include <stdlib.h>
#include <stdio.h>

typedef unsigned int u32;

u32 gpio_dump[] = {
	0x80000005, //(GP0CONFIGA)
	0x00000004, //(GP0CONFIGB)
	0x80000005, //(GP1CONFIGA)
	0x00000004, //(GP1CONFIGB)
	0x80000005, //(GP2CONFIGA)
	0x00000004, //(GP2CONFIGB)
	0x80000005, //(GP3CONFIGA)
	0x00000004, //(GP3CONFIGB)
	0x80000000, //(GP4CONFIGA)
	0x00000004, //(GP4CONFIGB)
	0x80000000, //(GP5CONFIGA)
	0x00000004, //(GP5CONFIGB)
	0x80000000, //(GP6CONFIGA)
	0x00000004, //(GP6CONFIGB)
	0x80000000, //(GP7CONFIGA)
	0x00000004, //(GP7CONFIGB)
	0xc0000015, //(GP8CONFIGA)
	0x00000000, //(GP8CONFIGB)
	0x80000005, //(GP9CONFIGA)
	0x00000004, //(GP9CONFIGB)
	0x4000000d, //(GP10CONFIGA)
	0x00000000, //(GP10CONFIGB)
	0xc0000010, //(GP11CONFIGA)
	0x00000004, //(GP11CONFIGB)
	0x80000005, //(GP12CONFIGA)
	0x00000004, //(GP12CONFIGB)
	0x00000005, //(GP13CONFIGA)
	0x00000000, //(GP13CONFIGB)
	0x80000005, //(GP14CONFIGA)
	0x00000004, //(GP14CONFIGB)
	0x80000005, //(GP15CONFIGA)
	0x00000004, //(GP15CONFIGB)
	0x80000005, //(GP16CONFIGA)
	0x00000004, //(GP16CONFIGB)
	0xc000001d, //(GP17CONFIGA)
	0x00000000, //(GP17CONFIGB)
	0xc0000000, //(GP18CONFIGA)
	0x00000004, //(GP18CONFIGB)
	0xc0000000, //(GP19CONFIGA)
	0x00000004, //(GP19CONFIGB)
	0x80000000, //(GP20CONFIGA)
	0x00000004, //(GP20CONFIGB)
	0x80000000, //(GP21CONFIGA)
	0x00000004, //(GP21CONFIGB)
	0xc0000000, //(GP22CONFIGA)
	0x00000004, //(GP22CONFIGB)
	0xc0000000, //(GP23CONFIGA)
	0x00000004, //(GP23CONFIGB)
	0xc0000005, //(GP24CONFIGA)
	0x00000004, //(GP24CONFIGB)
	0x00000001, //(GP25CONFIGA)
	0x00000004, //(GP25CONFIGB)
	0x40000005, //(GP26CONFIGA)
	0x00000004, //(GP26CONFIGB)
	0x4000001d, //(GP27CONFIGA)
	0x00000000, //(GP27CONFIGB)
	0xc0000005, //(GP28CONFIGA)
	0x00000004, //(GP28CONFIGB)
	0xc0000000, //(GP29CONFIGA)
	0x00000004, //(GP29CONFIGB)
	0xc0000000, //(GP30CONFIGA)
	0x00000004, //(GP30CONFIGB)
	0xc0000000, //(GP31CONFIGA)
	0x00000004, //(GP31CONFIGB)
	0xc0000000, //(GP32CONFIGA)
	0x00000004, //(GP32CONFIGB)
	0x80000005, //(GP33CONFIGA)
	0x00000004, //(GP33CONFIGB)
	0xc000000d, //(GP34CONFIGA)
	0x00000000, //(GP34CONFIGB)
	0x80000005, //(GP35CONFIGA)
	0x00000004, //(GP35CONFIGB)
	0x80000005, //(GP36CONFIGA)
	0x00000004, //(GP36CONFIGB)
	0xc0000004, //(GP37CONFIGA)
	0x00000004, //(GP37CONFIGB)
	0x80000005, //(GP38CONFIGA)
	0x00000004, //(GP38CONFIGB)
	0x80000005, //(GP39CONFIGA)
	0x00000004, //(GP39CONFIGB)
	0xc0000000, //(GP40CONFIGA)
	0x00000004, //(GP40CONFIGB)
	0xc0000000, //(GP41CONFIGA)
	0x00000004, //(GP41CONFIGB)
	0xc0000000, //(GP42CONFIGA)
	0x00000004, //(GP42CONFIGB)
	0x80000001, //(GP43CONFIGA)
	0x00000004, //(GP43CONFIGB)
	0x80000005, //(GP44CONFIGA)
	0x00000004, //(GP44CONFIGB)
	0x80000005, //(GP45CONFIGA)
	0x00000004, //(GP45CONFIGB)
	0x00000011, //(GP46CONFIGA)
	0x00000004, //(GP46CONFIGB)
	0x0000000d, //(GP47CONFIGA)
	0x00000004, //(GP47CONFIGB)
	0x80000011, //(GP48CONFIGA)
	0x00000004, //(GP48CONFIGB)
	0x00000011, //(GP49CONFIGA)
	0x00000004, //(GP49CONFIGB)
	0x40000015, //(GP50CONFIGA)
	0x00000000, //(GP50CONFIGB)
	0x40000015, //(GP51CONFIGA)
	0x00000004, //(GP51CONFIGB)
	0xc0000001, //(GP52CONFIGA)
	0x00000004, //(GP52CONFIGB)
	0x40000005, //(GP53CONFIGA)
	0x00000004, //(GP53CONFIGB)
	0x40000015, //(GP54CONFIGA)
	0x00000004, //(GP54CONFIGB)
	0x40000015, //(GP55CONFIGA)
	0x00000004, //(GP55CONFIGB)
	0x80000015, //(GP56CONFIGA)
	0x00000000, //(GP56CONFIGB)
	0x00000015, //(GP57CONFIGA)
	0x00000000, //(GP57CONFIGB)
	0x40000015, //(GP58CONFIGA)
	0x00000000, //(GP58CONFIGB)
	0x40000015, //(GP59CONFIGA)
	0x00000000, //(GP59CONFIGB)
	0xc0000001, //(GP60CONFIGA)
	0x00000004, //(GP60CONFIGB)
	0xc0000000, //(GP61CONFIGA)
	0x00000004, //(GP61CONFIGB)
	0x80000000, //(GP62CONFIGA)
	0x00000004, //(GP62CONFIGB)
	0xc0000004, //(GP63CONFIGA)
	0x00000004, //(GP63CONFIGB)
	0x80000000, //(GP64CONFIGA)
	0x00000004, //(GP64CONFIGB)
	0x80000000, //(GP65CONFIGA)
	0x00000004, //(GP65CONFIGB)
	0x80000000, //(GP66CONFIGA)
	0x00000004, //(GP66CONFIGB)
	0x80000000, //(GP67CONFIGA)
	0x00000004, //(GP67CONFIGB)
	0x80000000, //(GP68CONFIGA)
	0x00000004, //(GP68CONFIGB)
	0x80000000, //(GP69CONFIGA)
	0x00000004, //(GP69CONFIGB)
	0x80000005, //(GP70CONFIGA)
	0x00000004, //(GP70CONFIGB)
	0xc0000000, //(GP71CONFIGA)
	0x00000004, //(GP71CONFIGB)
	0xc0000000, //(GP72CONFIGA)
	0x00000004, //(GP72CONFIGB)
	0x80000000, //(GP73CONFIGA)
	0x00000004, //(GP73CONFIGB)
	0xc0000000, //(GP74CONFIGA)
	0x00000004, //(GP74CONFIGB)
	0xc0000000, //(GP75CONFIGA)
	0x00000004, //(GP75CONFIGB)
	0x80000005, //(GP76CONFIGA)
	0x00000004, //(GP76CONFIGB)
	0x4000000d, //(GP77CONFIGA)
	0x00000000, //(GP77CONFIGB)
	0x40000015, //(GP78CONFIGA)
	0x00000004, //(GP78CONFIGB)
	0x4000001d, //(GP79CONFIGA)
	0x00000004, //(GP79CONFIGB)
	0x40000015, //(GP80CONFIGA)
	0x00000004, //(GP80CONFIGB)
	0x80000000, //(GP81CONFIGA)
	0x00000004, //(GP81CONFIGB)
	0xc0000008, //(GP82CONFIGA)
	0x00000000, //(GP82CONFIGB)
	0x00000001, //(GP83CONFIGA)
	0x00000004, //(GP83CONFIGB)
	0x80000001, //(GP84CONFIGA)
	0x00000004, //(GP84CONFIGB)
	0x80000001, //(GP85CONFIGA)
	0x00000004, //(GP85CONFIGB)
	0x80000001, //(GP86CONFIGA)
	0x00000004, //(GP86CONFIGB)
	0x00000001, //(GP87CONFIGA)
	0x00000004, //(GP87CONFIGB)
	0x80000001, //(GP88CONFIGA)
	0x00000004, //(GP88CONFIGB)
	0x80000001, //(GP89CONFIGA)
	0x00000004, //(GP89CONFIGB)
	0x00000001, //(GP90CONFIGA)
	0x00000004, //(GP90CONFIGB)
	0x80000005, //(GP91CONFIGA)
	0x00000004, //(GP91CONFIGB)
	0x80000005, //(GP92CONFIGA)
	0x00000004, //(GP92CONFIGB)
	0x80000005, //(GP93CONFIGA)
	0x00000004, //(GP93CONFIGB)
	0x80000005, //(GP94CONFIGA)
	0x00000004, //(GP94CONFIGB)
};

u32 gpio_own[] = {
	0xf7fddbff, //(GPIO_OWN1)
	0xfffffffb, //(GPIO_OWN2)
	0x7fffffff, //(GPIO_OWN3)
};

u32 gpi_rout[] = {
	0x00000000, //(GPI_ROUT)
	0x00000004, //(RESERVED)
	0x00004000, //(RESERVED)
};

u32 gpi_ie[] = {
	0x00000000, //(GPI_IE[31:0])
	0x00000000, //(GPI_IE[63:32])
	0x00000000, //(GPI_IE[94:64])
};

u32 gpio_pirq_to_apic = 0xffff; //(GPIPRIOQ2IOXAPIC)

/* LynxPoint LP GPIOBASE Registers */
#define GPIO_OWNER(set)		(0x00 + ((set) * 4))
#define GPIO_PIRQ_APIC_EN	0x10
#define GPIO_BLINK		0x18
#define GPIO_SER_BLINK		0x1c
#define GPIO_SER_BLINK_CS	0x20
#define GPIO_SER_BLINK_DATA	0x24
#define GPIO_ROUTE(set)		(0x30 + ((set) * 4))
#define GPIO_RESET(set)		(0x60 + ((set) * 4))
#define GPIO_GLOBAL_CONFIG	0x7c
#define GPIO_IRQ_IS(set)	(0x80 + ((set) * 4))
#define GPIO_IRQ_IE(set)	(0x90 + ((set) * 4))
#define GPIO_CONFIG0(gpio)	(0x100 + ((gpio) * 8))
#define GPIO_CONFIG1(gpio)	(0x104 + ((gpio) * 8))

#define MAX_GPIO_NUMBER		94 /* zero based */
#define GPIO_LIST_END		0xffffffff

/* conf0 */

#define GPIO_MODE_NATIVE	(0 << 0)
#define GPIO_MODE_GPIO		(1 << 0)

#define GPIO_DIR_OUTPUT		(0 << 2)
#define GPIO_DIR_INPUT		(1 << 2)

#define GPIO_NO_INVERT		(0 << 3)
#define GPIO_INVERT		(1 << 3)

#define GPIO_IRQ_EDGE		(0 << 4)
#define GPIO_IRQ_LEVEL		(1 << 4)

#define GPI_LEVEL		(1 << 30)

#define GPO_LEVEL_SHIFT		31
#define GPO_LEVEL_MASK		(1UL << GPO_LEVEL_SHIFT)
#define GPO_LEVEL_LOW		(0UL << GPO_LEVEL_SHIFT)
#define GPO_LEVEL_HIGH		(1UL << GPO_LEVEL_SHIFT)

/* conf1 */

#define GPIO_PULL_NONE		(0 << 0)
#define GPIO_PULL_DOWN		(1 << 0)
#define GPIO_PULL_UP		(2 << 0)

#define GPIO_SENSE_ENABLE	(0 << 2)
#define GPIO_SENSE_DISABLE	(1 << 2)

/* owner */

#define GPIO_OWNER_ACPI		0
#define GPIO_OWNER_GPIO		1

/* route */

#define GPIO_ROUTE_SCI		0
#define GPIO_ROUTE_SMI		1

/* irqen */

#define GPIO_IRQ_DISABLE	0
#define GPIO_IRQ_ENABLE		1

/* blink */

#define GPO_NO_BLINK		0
#define GPO_BLINK		1

/* reset */

#define GPIO_RESET_PWROK	0
#define GPIO_RESET_RSMRST	1

/* pirq route to io-apic */

#define GPIO_PIRQ_APIC_MASK	0
#define GPIO_PIRQ_APIC_ROUTE	1

#define LP_GPIO_END \
	{ .conf0 = GPIO_LIST_END }

#define LP_GPIO_NATIVE \
	{ .conf0 = GPIO_MODE_NATIVE }

#define LP_GPIO_UNUSED \
	{ .conf0 = GPIO_MODE_GPIO | GPIO_DIR_INPUT, \
	  .owner = GPIO_OWNER_GPIO, \
	  .conf1 = GPIO_SENSE_DISABLE }

#define LP_GPIO_ACPI_SCI \
	{ .conf0 = GPIO_MODE_GPIO | GPIO_DIR_INPUT | GPIO_INVERT, \
	  .owner = GPIO_OWNER_ACPI, \
	  .route = GPIO_ROUTE_SCI }

#define LP_GPIO_ACPI_SMI \
	{ .conf0 = GPIO_MODE_GPIO | GPIO_DIR_INPUT | GPIO_INVERT, \
	  .owner = GPIO_OWNER_ACPI, \
	  .route = GPIO_ROUTE_SMI }

#define LP_GPIO_INPUT \
	{ .conf0 = GPIO_MODE_GPIO | GPIO_DIR_INPUT, \
	  .owner = GPIO_OWNER_GPIO }

#define LP_GPIO_INPUT_INVERT \
	{ .conf0 = GPIO_MODE_GPIO | GPIO_DIR_INPUT | GPIO_INVERT, \
	  .owner = GPIO_OWNER_GPIO }

#define LP_GPIO_IRQ_EDGE \
	{ .conf0 = GPIO_MODE_GPIO | GPIO_DIR_INPUT | GPIO_IRQ_EDGE, \
	  .owner = GPIO_OWNER_GPIO, \
	  .irqen = GPIO_IRQ_ENABLE }

#define LP_GPIO_IRQ_LEVEL \
	{ .conf0 = GPIO_MODE_GPIO | GPIO_DIR_INPUT | GPIO_IRQ_LEVEL, \
	  .owner = GPIO_OWNER_GPIO, \
	  .irqen = GPIO_IRQ_ENABLE }

#define LP_GPIO_PIRQ \
	{ .conf0 = GPIO_MODE_GPIO | GPIO_DIR_INPUT, \
	  .owner = GPIO_OWNER_GPIO, \
	  .pirq  = GPIO_PIRQ_APIC_ROUTE }

#define LP_GPIO_OUT_HIGH \
	{ .conf0 = GPIO_MODE_GPIO | GPIO_DIR_OUTPUT | GPO_LEVEL_HIGH, \
	  .owner = GPIO_OWNER_GPIO, \
	  .conf1 = GPIO_SENSE_DISABLE }

#define LP_GPIO_OUT_LOW \
	{ .conf0 = GPIO_MODE_GPIO | GPIO_DIR_OUTPUT | GPO_LEVEL_LOW, \
	  .owner = GPIO_OWNER_GPIO, \
	  .conf1 = GPIO_SENSE_DISABLE }

u32 a(u32 i) /* Accesses GPnCONFIGA */
{
	return i * 2;
}

u32 b(u32 i) /* Accesses GPnCONFIGB */
{
	return (i * 2) + 1;
}

const char *gpio_cfg(u32 i)
{
	u32 gpio_owner_gpio =		gpio_own[i / 32] & (1 << (i % 32));
	u32 gpio_route_smi =		gpi_rout[i / 32] & (1 << (i % 32));
	u32 gpio_irq_enable =		gpi_ie[i / 32] & (1 << (i % 32));

	u32 gpio_pirq_apic_route =	gpio_pirq_to_apic & (1 << i);

	u32 gpio_mode_gpio =		gpio_dump[a(i)] & (1 << 0);
	u32 gpio_dir_input =		gpio_dump[a(i)] & (1 << 2);
	u32 gpio_invert =		gpio_dump[a(i)] & (1 << 3);
	u32 gpio_irq_level =		gpio_dump[a(i)] & (1 << 4);
	u32 gpo_level_high =		gpio_dump[a(i)] & (1 << 31);

	//u32 gpio_pull_down =		gpio_dump[b(i)] & (1 << 0);
	//u32 gpio_pull_up =		gpio_dump[b(i)] & (2 << 0);
	u32 gpio_sense_disable =	gpio_dump[b(i)] & (1 << 2);

	if (!gpio_mode_gpio) return "LP_GPIO_NATIVE";

	if (gpio_dir_input) {
		if (gpio_owner_gpio) {
			if (gpio_sense_disable) {
				return "LP_GPIO_UNUSED";
			} else if (gpio_invert) {
				return "LP_GPIO_INPUT_INVERT";
			} else if (gpio_pirq_apic_route) {
				return "LP_GPIO_PIRQ";
			} else if (gpio_irq_enable) {
				return	(gpio_irq_level) ?
					"LP_GPIO_IRQ_LEVEL":
					"LP_GPIO_IRQ_EDGE";
			} else {
				return "LP_GPIO_INPUT";
			}
		} else {
			if (gpio_invert) {
				return	(gpio_route_smi) ?
					"LP_GPIO_ACPI_SMI":
					"LP_GPIO_ACPI_SCI";
			} else {
				/* This should not happen */
				//exit(EXIT_FAILURE);
			}
		}
	} else {
		if (gpio_sense_disable) {
			return	(gpo_level_high) ?
				"LP_GPIO_OUT_HIGH":
				"LP_GPIO_OUT_LOW";
		} else {
			/* This should not happen */
			//exit(EXIT_FAILURE);
		}
	}
	return "LP_GPIO_UNUSED"; /* Safe default */
}

int main(void)
{
	u32 i;

	printf("/*\n"
" * This file is part of the coreboot project.\n"
" *\n"
" * Copyright (C) 2018 Angel Pons <th3fanbus@gmail.com>\n"
" *\n"
" * This program is free software; you can redistribute it and/or modify\n"
" * it under the terms of the GNU General Public License as published by\n"
" * the Free Software Foundation; version 2 of the License.\n"
" *\n"
" * This program is distributed in the hope that it will be useful,\n"
" * but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
" * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
" * GNU General Public License for more details.\n"
" */\n"
"\n"
"#include <southbridge/intel/lynxpoint/lp_gpio.h>\n"
"\n"
);

	printf("const struct pch_lp_gpio_map mainboard_gpio_map[] = {\n");
	for (i=0; i<95; i++) {
		printf("\t%s,\n", gpio_cfg(i));
	}
	printf("\tLP_GPIO_END\n};\n\n");
	return EXIT_SUCCESS;
}