#include <lpc214x.h>

void PLL_Init(void) {
 PLL0CFG = 0x24; // M = 5, N = 1
 PLL0CON = 0x01; // Enable PLL
 PLL0FEED = 0xAA; // Feed sequence
 PLL0FEED = 0x55;

 while (!(PLL0STAT & (1 << 10))); // Wait for PLL to lock
 PLL0CON = 0x03; // Connect PLL
 PLL0FEED = 0xAA;
 PLL0FEED = 0x55;

 VPBDIV = 0x02; // Set PCLK = CCLK / 2
}

int main() {
 PLL_Init();
 while(1);
}
