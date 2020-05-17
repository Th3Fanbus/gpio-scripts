#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

typedef const uint16_t cte16_t;
typedef const uint32_t cte32_t;

/* Number of GPIOs (array size) */
#define GPIO_ARR_SIZE	95

/* Bit macro */
#define BIT(x)		(1 << (x))

/* FIXME: Read these values from elsewhere */

static cte32_t gpio_own[3] = {
	0xffff7fff,
	0xff7bff7f,
	0x7fffffbf,
};

static cte16_t pirq_to_ioxapic	= 0x8400;

static cte32_t gpo_blink	= 0x00000000;

static cte16_t gpi_nmi_en	= 0x0000;

/*
 * Note that inteltool only prints one GPI_ROUT register.
 * Please also use the two RESERVED values right below GPI_ROUT.
 */
static cte32_t gpi_rout[3] = {
	0x00050000,
	0x00000000,
	0x00050000,
};

static cte32_t alt_gpi_smi_en	= 0x00000080;

static cte32_t gp_rst_sel[3] = {
	0x01000000,
	0x00000000,
	0x00000000,
};

static cte32_t gpio_gc		= 0x00000000;

static cte32_t gpi_ie[3] = {
	0x00000000,
	0x00000000,
	0x00000000,
};

static cte32_t gp_config[GPIO_ARR_SIZE + GPIO_ARR_SIZE] = {
	0x00000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x40000005,
	0x00000004,
	0x40000005,
	0x00000004,
	0x00000004,
	0x00000004,
	0x00000004,
	0x00000004,
	0x00000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x40000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x0000001d,
	0x00000000,
	0x00000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x00000004,
	0x00000004,
	0x40000004,
	0x00000004,
	0x40000004,
	0x00000004,
	0x00000005,
	0x00000004,
	0x40000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x40000005,
	0x00000000,
	0x00000005,
	0x00000000,
	0x40000005,
	0x00000004,
	0x40000004,
	0x00000004,
	0x00000004,
	0x00000004,
	0x40000001,
	0x00000004,
	0x00000004,
	0x00000004,
	0x00000004,
	0x00000004,
	0x00000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x4000000d,
	0x00000000,
	0x40000004,
	0x00000004,
	0x40000004,
	0x00000004,
	0x00000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x40000005,
	0x00000000,
	0x40000015,
	0x00000000,
	0x40000005,
	0x00000004,
	0x40000005,
	0x00000004,
	0x00000005,
	0x00000000,
	0x00000005,
	0x00000000,
	0x40000015,
	0x00000000,
	0x00000005,
	0x00000004,
	0x40000005,
	0x00000004,
	0x40000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x40000005,
	0x00000004,
	0x40000005,
	0x00000004,
	0x40000005,
	0x00000004,
	0x40000000,
	0x00000004,
	0x00000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x4000001d,
	0x00000000,
	0x00000005,
	0x00000004,
	0x40000004,
	0x00000004,
	0x40000005,
	0x00000004,
	0x40000004,
	0x00000004,
	0x40000004,
	0x00000004,
	0x00000005,
	0x00000004,
	0xc0000011,
	0x00000004,
	0x40000005,
	0x00000004,
	0x40000005,
	0x00000004,
	0x40000005,
	0x00000004,
	0x00000000,
	0x00000004,
	0x40000004,
	0x00000004,
	0x00000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x00000005,
	0x00000004,
	0x00000005,
	0x00000004,
};

#define GPIO_OWNER(gpio)	(!!(gpio_own[(gpio) / 32] & BIT((gpio) % 32)))
#define     GPIO_OWNER_ACPI	0
#define     GPIO_OWNER_GPIO	1

#define GPO_BLINK(gpio)		(!!(gpo_blink & BIT(gpio)))
#define GPI_NMI_EN(gpio)	(!!(gpi_nmi_en & BIT((gpio) - 32)))

#define GPI_ROUT(gpio)		(!!(gpi_rout[(gpio) / 32] & BIT((gpio) % 32)))
#define     GPI_ROUT_SCI	0
#define     GPI_ROUT_NMI_SMI	1

#define ALT_GPI_SMI_EN(gpio)	(!!(alt_gpi_smi_en & BIT((gpio) - 32)))

#define GP_RST_SEL(gpio)	(!!(gp_rst_sel[(gpio) / 32] & BIT((gpio) % 32)))

#define GPI_IE(gpio)		(!!(gpi_ie[(gpio) / 32] & BIT((gpio) % 32)))

/* Accessors for GPnCONFIGA and GPnCONFIGB */
#define GP_CFG_A(gpio)			(gp_config[0 + (gpio) + (gpio)])
#define GP_CFG_B(gpio)			(gp_config[1 + (gpio) + (gpio)])

static const char *gpio_cfg(cte32_t gpio)
{
	printf("\t{\n");
	printf("\t\t.conf0 = 0x%08x,\n", GP_CFG_A(gpio));
	printf("\t\t.conf1 = 0x%08x,\n", GP_CFG_B(gpio));
	printf("\t\t.owner = %u,\n",     GPIO_OWNER(gpio));
	printf("\t\t.route = %u,\n",     GPI_ROUT(gpio));
	printf("\t\t.irqen = %u,\n",     GPI_IE(gpio));
	printf("\t\t.reset = %u,\n",     GP_RST_SEL(gpio));
	if (gpio < 32)
		printf("\t\t.blink = %u,\n",     GPO_BLINK(gpio));
	return "}";
#if 0
	cte32_t gpio_owner_gpio		= GPIO_OWNER(gpio);
	cte32_t gpio_route_smi		= GPI_ROUT(gpio);
	cte32_t gpio_irq_enable		= GPI_IE(gpio);

	cte32_t gpio_mode_gpio		= GP_CFG_A(gpio) & (1 << 0);
	cte32_t gpio_dir_input		= GP_CFG_A(gpio) & (1 << 2);
	cte32_t gpio_invert		= GP_CFG_A(gpio) & (1 << 3);
	cte32_t gpio_irq_level		= GP_CFG_A(gpio) & (1 << 4);
	cte32_t gpo_level_high		= GP_CFG_A(gpio) & (1 << 31);

	cte32_t gpio_pull_down		= GP_CFG_B(gpio) & (1 << 0);
	cte32_t gpio_pull_up		= GP_CFG_B(gpio) & (1 << 1);
	cte32_t gpio_sense_disable	= GP_CFG_B(gpio) & (1 << 2);

	if (!gpio_mode_gpio)
		return "LP_GPIO_NATIVE";

	if (gpio_dir_input) {
		if (gpio_owner_gpio) {
			if (gpio_sense_disable) {
				return "LP_GPIO_UNUSED";
			} else if (gpio_invert) {
				return "LP_GPIO_INPUT_INVERT";
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
				return "LP_GPIO_UNUSED /* FIXME: Double-check this. */";
			}
		}
	} else {
		if (gpio_sense_disable) {
			return	(gpo_level_high) ?
				"LP_GPIO_OUT_HIGH":
				"LP_GPIO_OUT_LOW";
		} else {
			/* This should not happen */
			return "LP_GPIO_UNUSED /* FIXME: Double-check this as well. */";
		}
	}
	return "LP_GPIO_UNUSED /* FIXME: Confirm this is correct. */"; /* Default */
#endif
}

int main(void)
{
	printf("/* SPDX-License-Identifier: GPL-2.0-only */\n");
	printf("\n");
	printf("#include <southbridge/intel/lynxpoint/lp_gpio.h>\n");
	printf("\n");

	printf("const struct pch_lp_gpio_map mainboard_gpio_map[] =\n{\n");

	for (uint32_t i = 0; i < GPIO_ARR_SIZE; i++) {
		printf("\t%s,\n", gpio_cfg(i));
	}

	printf("\tLP_GPIO_END,\n};\n\n");
	return EXIT_SUCCESS;
}
