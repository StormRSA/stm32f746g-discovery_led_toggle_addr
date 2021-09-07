#define PERIPH_BASE				(0x40000000UL)

#define AHB1PERIPH_OFFSET 		(0x00020000UL)
#define AHB1PERIPH_BASE 		(PERIPH_BASE + AHB1PERIPH_OFFSET)

#define GPIOI_OFFSET			(0x2000UL)
#define GPIOI_BASE				(AHB1PERIPH_BASE + GPIOI_OFFSET)

#define RCC_OFFSET				(0x3800UL)
#define RCC_BASE				(AHB1PERIPH_BASE + RCC_OFFSET)

#define RCC_AHB1EN_R_OFFSET		(0x30UL)
#define RCC_AHB1EN_R			(*(volatile unsigned int *)(RCC_BASE + RCC_AHB1EN_R_OFFSET))

#define MODE_R_OFFSET			(0x00UL)
#define GPIOI_MODE_R			(*(volatile unsigned int *)(GPIOI_BASE + MODE_R_OFFSET))

#define OD_R_OFFSET				(0x14UL)
#define GPIOI_OD_R				(*(volatile unsigned int *)(GPIOI_BASE + OD_R_OFFSET))

#define GPIOI_CLK_EN			(1U << 8)

#define PIN_1					(1U << 1)
#define LED_PIN					PIN_1

void delay(int delay)

{

	volatile int i;

	for(; delay>0 ;delay--)

	{

		for(i =0; i<3195;i++);

	}

}

int main(void)
{
	/* 1. Enable clock access for GPIOI.*/
	RCC_AHB1EN_R |= GPIOI_CLK_EN;

	/* 2. Sets GPIOI PIN 1 High. */
	GPIOI_MODE_R |= (1U << 2);
	GPIOI_MODE_R &= ~(1U << 3);


	while(1)
	{
		/* 3. Toggles PIN 1 LED. */
		GPIOI_OD_R ^= LED_PIN;
		delay(100);

	}
}
