#define rMIO_PIN_07 (*(volatile unsigned int *)0xF800071C)
#define rMIO_PIN_50 (*(volatile unsigned int *)0xF80007C8)

#define rDIRM_0 (*(volatile unsigned int *)0xE000A204)
#define rDIRM_1 (*(volatile unsigned int *)0xE000A244)
#define rOEN_0 (*(volatile unsigned int *)0xE000A208)
#define rDATA_0 (*(volatile unsigned int *)0xE000A040)
#define rDATA_1_R0 (*(volatile unsigned int *)0xE000A064)
int main()
{
    rMIO_PIN_07 = 0x0000600;
    rMIO_PIN_50 = 0x0000600;
    rDIRM_1 = 0xFFFBFFFF & rDIRM_1;
    rDIRM_0 = 0x00000080 | rDIRM_0;
    rOEN_0 = 0x00000080 | rOEN_0;
    int flag;
    while (1)
    {
        flag = rDATA_1_R0 & 0x00040000;
        if (flag == 0x00040000)
        {
            rDATA_0 = rDATA_0 | 0x00000080;
        }
        else
        {
            rDATA_0 = rDATA_0 & 0xFFFFFF7F;
        }
    }
}