#include <stdio.h>

typedef unsigned int u32;

u32 GPIO_USE_SEL=0x18fefffe;
u32 GPIO_USE_SEL_DIFF=0xffffffff;

u32 GP_IO_SEL=0xe108a581;
u32 GP_IO_SEL_DIFF=0xffffffff;

u32 GP_LVL=0xebfeedff;
u32 GP_LVL_DIFF=0xffffffff;

u32 GPI_INV=0x00002480;
u32 GPI_INV_DIFF=0xffffffff;


u32 GPIO_USE_SEL2=0x130300ff;
u32 GPIO_USE_SEL2_DIFF=0xffffffff;

u32 GP_IO_SEL2=0x0e54ff00;
u32 GP_IO_SEL2_DIFF=0xffffffff;

u32 GP_LVL2=0x1dfefff3;
u32 GP_LVL2_DIFF=0xffffffff;


u32 GPIO_USE_SEL3=0x00000000;
u32 GPIO_USE_SEL3_DIFF=0xffffffff;

u32 GP_IO_SEL3=0x00000000;
u32 GP_IO_SEL3_DIFF=0xffffffff;

u32 GP_LVL3=0x00000000;
u32 GP_LVL3_DIFF=0xffffffff;

int main(void)
{
	int i;

	printf("/*\n"
" * This file is part of the coreboot project.\n"
" *\n"
" * Copyright (C) 2011 Google Inc.\n"
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
"#ifndef BOARD_GPIO_H\n"
"#define BOARD_GPIO_H\n"
"\n"
"#include <southbridge/intel/common/gpio.h>\n"
"\n"
);

	printf("const struct pch_gpio_set1 pch_gpio_set1_mode = {\n");
	for (i=0; i<32; i++) {
		if (GPIO_USE_SEL_DIFF & (1 << i))
			printf("	.gpio%d = %s,\n",
				i, (GPIO_USE_SEL & (1 << i))?"GPIO_MODE_GPIO":"GPIO_MODE_NATIVE");
	}
	printf("};\n\n");

	printf("const struct pch_gpio_set1 pch_gpio_set1_direction = {\n");
	for (i=0; i<32; i++) {
		if (GP_IO_SEL_DIFF & (1 << i))
			printf("	.gpio%d = %s,\n",
				i, (GP_IO_SEL & (1 << i))?"GPIO_DIR_INPUT":"GPIO_DIR_OUTPUT");
	}
	printf("};\n\n");

	printf("const struct pch_gpio_set1 pch_gpio_set1_level = {\n");
	for (i=0; i<32; i++) {
		if (GP_LVL_DIFF & (1 << i)  && GPIO_USE_SEL & (1 << i))
			printf("	.gpio%d = %s,\n",
				i, (GP_LVL & (1 << i))?"GPIO_LEVEL_HIGH":"GPIO_LEVEL_LOW");
	}
	printf("};\n\n");

	printf("const struct pch_gpio_set1 pch_gpio_set1_invert = {\n");
	for (i=0; i<32; i++) {
		if (GPI_INV_DIFF & (1 << i))
			printf("	.gpio%d = %s,\n",
				i, (GPI_INV & (1 << i))?"GPIO_INVERT":"GPIO_???");
	}
	printf("};\n\n");




	printf("const struct pch_gpio_set2 pch_gpio_set2_mode = {\n");
	for (i=0; i<32; i++) {
		if (GPIO_USE_SEL2_DIFF & (1 << i))
			printf("	.gpio%d = %s,\n",
				i+32, (GPIO_USE_SEL2 & (1 << i))?"GPIO_MODE_GPIO":"GPIO_MODE_NATIVE");
	}
	printf("};\n\n");

	printf("const struct pch_gpio_set2 pch_gpio_set2_direction = {\n");
	for (i=0; i<32; i++) {
		if (GP_IO_SEL2_DIFF & (1 << i))
			printf("	.gpio%d = %s,\n",
				i+32, (GP_IO_SEL2 & (1 << i))?"GPIO_DIR_INPUT":"GPIO_DIR_OUTPUT");
	}
	printf("};\n\n");

	printf("const struct pch_gpio_set2 pch_gpio_set2_level = {\n");
	for (i=0; i<32; i++) {
		if (GP_LVL2_DIFF & (1 << i)  && GPIO_USE_SEL2 & (1 << i))
			printf("	.gpio%d = %s,\n",
				i+32, (GP_LVL2 & (1 << i))?"GPIO_LEVEL_HIGH":"GPIO_LEVEL_LOW");
	}
	printf("};\n\n");



	printf("const struct pch_gpio_set3 pch_gpio_set3_mode = {\n");
	for (i=0; i<32; i++) {
		if (GPIO_USE_SEL3_DIFF & (1 << i))
			printf("	.gpio%d = %s,\n",
				i+64, (GPIO_USE_SEL3 & (1 << i))?"GPIO_MODE_GPIO":"GPIO_MODE_NATIVE");
	}
	printf("};\n\n");

	printf("const struct pch_gpio_set3 pch_gpio_set3_direction = {\n");
	for (i=0; i<32; i++) {
		if (GP_IO_SEL3_DIFF & (1 << i))
			printf("	.gpio%d = %s,\n",
				i+64, (GP_IO_SEL3 & (1 << i))?"GPIO_DIR_INPUT":"GPIO_DIR_OUTPUT");
	}
	printf("};\n\n");

	printf("const struct pch_gpio_set3 pch_gpio_set3_level = {\n");
	for (i=0; i<32; i++) {
		if (GP_LVL3_DIFF & (1 << i)  && GPIO_USE_SEL3 & (1 << i))
			printf("	.gpio%d = %s,\n",
				i+64, (GP_LVL3 & (1 << i))?"GPIO_LEVEL_HIGH":"GPIO_LEVEL_LOW");
	}
	printf("};\n\n");

printf(
"const struct pch_gpio_map mainboard_gpio_map = {\n"
"	.set1 = {\n"
"		.mode      = &pch_gpio_set1_mode,\n"
"		.direction = &pch_gpio_set1_direction,\n"
"		.level     = &pch_gpio_set1_level,\n"
"		.invert    = &pch_gpio_set1_invert,\n"
"	},\n"
"	.set2 = {\n"
"		.mode      = &pch_gpio_set2_mode,\n"
"		.direction = &pch_gpio_set2_direction,\n"
"		.level     = &pch_gpio_set2_level,\n"
"	},\n"
"	.set3 = {\n"
"		.mode      = &pch_gpio_set3_mode,\n"
"		.direction = &pch_gpio_set3_direction,\n"
"		.level     = &pch_gpio_set3_level,\n"
"	},\n"
"};\n"
"#endif\n");

	return 0;
}
