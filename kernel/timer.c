struct h3_timer {
	volatile unsigned int irq_ena;		/* 00 */
	volatile unsigned int irq_status;	/* 04 */
	int __pad1[2];
	volatile unsigned int t0_ctrl;		/* 10 */
	volatile unsigned int t0_ival;		/* 14 */
	volatile unsigned int t0_cval;		/* 18 */
	int __pad2;
	volatile unsigned int t1_ctrl;		/* 20 */
	volatile unsigned int t1_ival;		/* 24 */
	volatile unsigned int t1_cval;		/* 28 */
};

#define TIMER_BASE	( (struct h3_timer *) 0x01c20c00)

#define	CTL_ENABLE		0x01
#define	CTL_RELOAD		0x02		/* reload ival */
#define	CTL_SRC_32K		0x00
#define	CTL_SRC_24M		0x04

#define	CTL_PRE_1		0x00
#define	CTL_PRE_2		0x10
#define	CTL_PRE_4		0x20
#define	CTL_PRE_8		0x30
#define	CTL_PRE_16		0x40
#define	CTL_PRE_32		0x50
#define	CTL_PRE_64		0x60
#define	CTL_PRE_128		0x70

#define	CTL_SINGLE		0x80
#define	CTL_AUTO		0x00

#define MS	24000
#define US	24

void
ms_delay ( unsigned int ms )
{
	struct h3_timer *hp = TIMER_BASE;
	
	hp->irq_status = 0;
	hp->irq_ena = 0;
	
	hp->t0_ival = ms * MS - 1;

	hp->t0_ctrl = CTL_SRC_24M;
	hp->t0_ctrl |= CTL_RELOAD;
	while ( hp->t0_ctrl & CTL_RELOAD );
	hp->t0_ctrl |= CTL_ENABLE;

	while(!(hp->irq_status & 1));
	
	hp->irq_status = 1;
	
	hp->t0_ctrl &= ~CTL_ENABLE;
}

void
us_delay ( unsigned int us )
{
	struct h3_timer *hp = TIMER_BASE;
	
	hp->irq_status = 0;
	hp->irq_ena = 0;
	
	hp->t0_ival = us * US - 1;

	hp->t0_ctrl = CTL_SRC_24M;
	hp->t0_ctrl |= CTL_RELOAD;
	while ( hp->t0_ctrl & CTL_RELOAD );
	hp->t0_ctrl |= CTL_ENABLE;

	while(!(hp->irq_status & 1));
	
	hp->irq_status = 1;
	
	hp->t0_ctrl &= ~CTL_ENABLE;
}
