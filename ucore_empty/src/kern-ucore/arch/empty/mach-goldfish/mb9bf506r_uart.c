#include <types.h>
#include <mb9bf506r.h>
/*
 *    Function Name : uart_init
 *    Create Date   : 2012/09/04-2013/05/28
 *    Author        : Wangxd-Zhangzl
 *    Description   : init uart as Asynchronous Mode,
 *                    115200bps, 8bit, non-parity,1 stop bit.
 *    Param	        : none
 *    Return Code   : none
 */
void uart_init(void)
{
//    uint32_t address;
//    uint32_t data;

    /* set to peripheral mode and MFS 0 for UART0 transmit/receive */
    FM3_GPIO->PFR2 |= 0x0006;
    FM3_GPIO->EPFR07 |= 0x0040;

    /* Asynchronous Mode,115200bps, 8bit, non-parity, 1 stop bit,Set Asynchronous Mode */
    FM3_MFS0_UART->SMR = 0x01;

    /* Disable receiver and transmitter  */
    FM3_MFS0_UART->SCR = 0x0;

    /* V = CLK/baud - 1= 346.00   */
    FM3_MFS0_UART->BGR = 0x15a;

    /* non-parity, 8bit */
    FM3_MFS0_UART->ESCR = 0x00;

    /* Enable receiver and transmitter */
    FM3_MFS0_UART->SCR = 0x03;

    return;
}

/*
 *    Function Name : uart_sendchar
 *    Create Date   : 2012/9/5-2013/05/28
 *    Author        : Wangxd-Zhangzl
 *    Description   : send a char to uart util success
 *    Param	        : uint8_t c: char to send
 *    Return Code   : none.
 */
void uart_sendchar(uint8_t c)
{
    uint32_t delay = 1000;

    /* Wait for the transmitter to be ready while  */
    while((FM3_MFS0_UART->SSR & (0x1<<1)) == 0){
        ;
    }
    do{
        delay--;
    }while(delay);

    /* Send characterjust a character,not a word */
    FM3_MFS0_UART->TDR = c;

    /* Wait for the transmitter to be end while  */
    while((FM3_MFS0_UART->SSR & (0x1<<1)) == 0){
        ;
    }
}

/*
 *    Function Name : uart_recvchar
 *    Create Date   : 2011/9/5-2013/05/28
 *    Author        : Wangxd-Zhangzl
 *    Description   : receive char from uart,util success
 *    Param	        : none.
 *    Return Code   : uint8_t c: char to receive
 */
uint8_t uart_recvchar(void)
{
    uint8_t c;

    /* Wait for the receiver to be ready while */
    while((FM3_MFS0_UART->SSR & (0x1<<2)) == 0){
            ;
    }

    c = FM3_MFS0_UART->RDR;

    return c;
}

