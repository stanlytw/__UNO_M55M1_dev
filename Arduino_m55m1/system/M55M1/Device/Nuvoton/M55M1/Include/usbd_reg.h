/**************************************************************************//**
 * @file     usbd_reg.h
 * @version  V1.00
 * @brief    USBD register definition header file
 *
 * @copyright SPDX-License-Identifier: Apache-2.0
 * @copyright Copyright (C) 2023 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/

#ifndef __USBD_REG_H__
#define __USBD_REG_H__

#if defined ( __CC_ARM   )
    #pragma anon_unions
#endif

/**
    @addtogroup REGISTER Control Register
    @{
*/

/**
    @addtogroup USBD USB Device Controller (USBD)
    Memory Mapped Structure for USBD Controller
    @{
*/

typedef struct
{
    /**
     * @var USBD_EP_T::BUFSEG
     * Offset:  * Offset: 0x500/0x510/0x520/0x530/0x540/0x550/0x560/0x570/0x580/0x590/0x5A0/0x5B0/0x5C0/0x5E0/0x5F0/0x600/0x610/0x620/0x630/0x640/0x650/0x660/0x670/0x680  Endpoint Buffer Segmentation Register  Endpoint n Buffer Segmentation Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[10:3]  |BUFSEG    |Endpoint Buffer Segmentation
     * |        |          |It is used to indicate the offset address for each endpoint with the USB SRAM starting address The effective starting address of the endpoint is
     * |        |          |USBD_SRAM address + { BUFSEG, 3'b000}
     * |        |          |Where the USBD_SRAM address = USBD_BA+0x800h.
     * |        |          |Refer to the section 6.33.5.7 for the endpoint SRAM structure and its description.
     * @var USBD_EP_T::MXPLD
     * Offset: 0x504/0x514/0x524/0x534/0x544/0x554/0x564/0x574/0x584/0x594/0x5A4/0x5B4/0x5C4/0x5E4/0x5F4/0x604/0x614/0x624/0x634/0x644/0x654/0x664/0x674/0x684  Endpoint n Maximal Payload Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[8:0]   |MXPLD     |Maximal Payload
     * |        |          |Define the data length which is transmitted to host (IN token) or the actual data length which is received from the host (OUT token)
     * |        |          |It also used to indicate that the endpoint is ready to be transmitted in IN token or received in OUT token.
     * |        |          |(1) When the register is written by CPU,
     * |        |          |For IN token, the value of MXPLD is used to define the data length to be transmitted and indicate the data buffer is ready.
     * |        |          |For OUT token, it means that the controller is ready to receive data from the host and the value of MXPLD is the maximal data length comes from host.
     * |        |          |(2) When the register is read by CPU,
     * |        |          |For IN token, the value of MXPLD is indicated by the data length be transmitted to host
     * |        |          |For OUT token, the value of MXPLD is indicated the actual data length receiving from host.
     * |        |          |Note: Once MXPLD is written, the data packets will be transmitted/received immediately after IN/OUT token arrived.
     * @var USBD_EP_T::CFG
     * Offset: 0x508/0x518/0x528/0x538/0x548/0x558/0x568/0x578/0x588/0x598/0x5A8/0x5B8/0x5C8/0x5E8/0x5F8/0x608/0x618/0x628/0x638/0x648/0x658/0x668/0x678/0x688  Endpoint n Configuration Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[3:0]   |EPNUM     |Endpoint Number
     * |        |          |These bits are used to define the endpoint number of the current endpoint
     * |[4]     |ISOCH     |Isochronous Endpoint
     * |        |          |This bit is used to set the endpoint as Isochronous endpoint, no handshake.
     * |        |          |0 = No Isochronous endpoint.
     * |        |          |1 = Isochronous endpoint.
     * |[6:5]   |STATE     |Endpoint STATE
     * |        |          |00 = Endpoint is Disabled.
     * |        |          |01 = Out endpoint.
     * |        |          |10 = IN endpoint.
     * |        |          |11 = Undefined.
     * |[7]     |DSQSYNC   |Data Sequence Synchronization
     * |        |          |0 = DATA0 PID.
     * |        |          |1 = DATA1 PID.
     * |        |          |Note: It is used to specify the DATA0 or DATA1 PID in the following IN token transaction
     * |        |          |hardware will toggle automatically in IN token base on the bit.
     * |[9]     |CSTALL    |Clear STALL Response
     * |        |          |0 = Disable the device to clear the STALL handshake in setup stage.
     * |        |          |1 = Clear the device to response STALL handshake in setup stage.
     * |[10]    |DBTGACTIVE|Double Buffer Toggle Active Bit
     * |        |          |0 = Inactive in double buffer mode.
     * |        |          |1 = Active in double buffer mode.
     * |        |          |When DBEN = 1 and endpoint successful transfer, DBTGACTIVE of each double buffer will be toggled automatically by hardware.
     * |[11]    |DBEN      |Double Buffer Enable
     * |        |          |0 = Single buffer mode.
     * |        |          |1 = Double buffer mode.
     * @var USBD_EP_T::CFGP
     * Offset: 0x50C/0x51C/0x52C/0x53C/0x54C/0x55C/0x56C/0x57C/0x58C/0x59C/0x5AC/0x5BC/0x5CC/0x5EC/0x5FC/0x60C/0x61C/0x62C/0x63C/0x64C/0x65C/0x66C/0x67C/0x68C  Endpoint n Set Stall and Clear In/Out Ready Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |CLRRDY    |Clear Ready
     * |        |          |When the USBD_MXPLD0~24 register is set by user, it means that the endpoint is ready to transmit or receive data
     * |        |          |If the user wants to disable this transaction before the transaction start, users can set this bit to 1 to disable it and it is auto clear to 0.
     * |        |          |For IN token, write '1' to clear the IN token had ready to transmit the data to USB.
     * |        |          |For OUT token, write '1' to clear the OUT token had ready to receive the data from USB.
     * |        |          |This bit is write 1 only and is always 0 when it is read back.
     * |[1]     |SSTALL    |Set STALL
     * |        |          |0 = Disable the device to response STALL.
     * |        |          |1 = Set the device to respond STALL automatically.
     */
    __IO uint32_t BUFSEG;               /*!< [0x0000] Endpoint n Buffer Segmentation Register                          */
    __IO uint32_t MXPLD;                /*!< [0x0004] Endpoint n Maximal Payload Register                              */
    __IO uint32_t CFG;                  /*!< [0x0008] Endpoint n Configuration Register                                */
    __IO uint32_t CFGP;                 /*!< [0x000c] Endpoint n Set Stall and Clear In/Out Ready Control Register     */

} USBD_EP_T;

typedef struct
{


    /**
     * @var USBD_T::INTEN
     * Offset: 0x00  USB Device Interrupt Enable Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |BUSIEN    |Bus Event Interrupt Enable Bit
     * |        |          |0 = BUS event interrupt Disabled.
     * |        |          |1 = BUS event interrupt Enabled.
     * |[1]     |USBIEN    |USB Event Interrupt Enable Bit
     * |        |          |0 = USB event interrupt Disabled.
     * |        |          |1 = USB event interrupt Enabled.
     * |[2]     |VBDETIEN  |VBUS Detection Interrupt Enable Bit
     * |        |          |0 = VBUS detection Interrupt Disabled.
     * |        |          |1 = VBUS detection Interrupt Enabled.
     * |[3]     |NEVWKIEN  |USB No-event-wake-up Interrupt Enable Bit
     * |        |          |0 = No-event-wake-up Interrupt Disabled.
     * |        |          |1 = No-event-wake-up Interrupt Enabled.
     * |[4]     |SOFIEN    |Start of Frame Interrupt Enable Bit
     * |        |          |0 = SOF Interrupt Disabled.
     * |        |          |1 = SOF Interrupt Enabled.
     * |[8]     |WKEN      |Wake-up Function Enable Bit
     * |        |          |0 = USB wake-up function Disabled.
     * |        |          |1 = USB wake-up function Enabled.
     * |[15]    |INNAKEN   |Active NAK Function and Its Status in IN Token
     * |        |          |0 = When device responds NAK after receiving IN token, IN NAK status will not be updated to USBD_EPSTS0 and USBD_EPSTS1register, so that the USB interrupt event will not be asserted.
     * |        |          |1 = IN NAK status will be updated to USBD_EPSTS0 and USBD_EPSTS1 register and the USB interrupt event will be asserted, when the device responds NAK after receiving IN token.
     * @var USBD_T::INTSTS
     * Offset: 0x04  USB Device Interrupt Event Status Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |BUSIF     |BUS Interrupt Status
     * |        |          |The BUS event means that there is one of the suspense or the resume function in the bus.
     * |        |          |0 = No BUS event occurred.
     * |        |          |1 = Bus event occurred; check USBD_ATTR[3:0] to know which kind of bus event was occurred, cleared by writing 1 to USBD_INTSTS[0].
     * |[1]     |USBIF     |USB Event Interrupt Status
     * |        |          |The USB event includes the SETUP Token, IN Token, OUT ACK, ISO IN, or ISO OUT events in the bus.
     * |        |          |0 = No USB event occurred.
     * |        |          |1 = USB event occurred
     * |        |          |Check EPSTS0~25 in USBD_EPSTS0~3 to know which kind of USB event was occurred, cleared by writing 1 to USBD_INTSTS[1] or USBD_INTSTS[27:16] or USBD_EPINTSTS[24:0] and SETUP (USBD_INTSTS[31]).
     * |[2]     |VBDETIF   |VBUS Detection Interrupt Status
     * |        |          |0 = There is not attached/detached event in the USB.
     * |        |          |1 = There is attached/detached event in the USB bus and it is cleared by writing 1 to USBD_INTSTS[2].
     * |[3]     |NEVWKIF   |No-event-wake-up Interrupt Status
     * |        |          |0 = NEVWK event did not occur.
     * |        |          |1 = No-event-wake-up event occurred, cleared by writing 1 to USBD_INTSTS[3].
     * |[4]     |SOFIF     |Start of Frame Interrupt Status
     * |        |          |0 = SOF event did not occur.
     * |        |          |1 = SOF event occurred, cleared by writing 1 to USBD_INTSTS[4].
     * |[16]    |EPEVT0    |Endpoint 0's USB Event Status
     * |        |          |0 = No event occurred in endpoint 0.
     * |        |          |1 = USB event occurred on Endpoint 0
     * |        |          |Check USBD_EPSTS0[3:0] to know which kind of USB event was occurred, cleared by writing 1 to USBD_INTSTS[16] or USBD_EPINTSTS[0] or USBD_INTSTS[1].
     * |[17]    |EPEVT1    |Endpoint 1's USB Event Status
     * |        |          |0 = No event occurred in endpoint 1.
     * |        |          |1 = USB event occurred on Endpoint 1
     * |        |          |Check USBD_EPSTS0[7:4] to know which kind of USB event was occurred, cleared by writing 1 to USBD_INTSTS[17] or USBD_EPINTSTS[1] or USBD_INTSTS[1].
     * |[18]    |EPEVT2    |Endpoint 2's USB Event Status
     * |        |          |0 = No event occurred in endpoint 2.
     * |        |          |1 = USB event occurred on Endpoint 2
     * |        |          |Check USBD_EPSTS0[11:8] to know which kind of USB event was occurred, cleared by writing 1 to USBD_INTSTS[18] or USBD_EPINTSTS[2] or USBD_INTSTS[1].
     * |[19]    |EPEVT3    |Endpoint 3's USB Event Status
     * |        |          |0 = No event occurred in endpoint 3.
     * |        |          |1 = USB event occurred on Endpoint 3
     * |        |          |Check USBD_EPSTS0[15:12] to know which kind of USB event was occurred, cleared by writing 1 to USBD_INTSTS[19] or USBD_EPINTSTS[3] or USBD_INTSTS[1].
     * |[20]    |EPEVT4    |Endpoint 4's USB Event Status
     * |        |          |0 = No event occurred in endpoint 4.
     * |        |          |1 = USB event occurred on Endpoint 4
     * |        |          |Check USBD_EPSTS0[19:16] to know which kind of USB event was occurred, cleared by writing 1 to USBD_INTSTS[20] or USBD_EPINTSTS[4] or USBD_INTSTS[1].
     * |[21]    |EPEVT5    |Endpoint 5's USB Event Status
     * |        |          |0 = No event occurred in endpoint 5.
     * |        |          |1 = USB event occurred on Endpoint 5
     * |        |          |Check USBD_EPSTS0[23:20] to know which kind of USB event was occurred, cleared by writing 1 to USBD_INTSTS[21] or USBD_EPINTSTS[5] or USBD_INTSTS[1].
     * |[22]    |EPEVT6    |Endpoint 6's USB Event Status
     * |        |          |0 = No event occurred in endpoint 6.
     * |        |          |1 = USB event occurred on Endpoint 6
     * |        |          |Check USBD_EPSTS0[27:24] to know which kind of USB event was occurred, cleared by writing 1 to USBD_INTSTS[22] or USBD_EPINTSTS[6] or USBD_INTSTS[1].
     * |[23]    |EPEVT7    |Endpoint 7's USB Event Status
     * |        |          |0 = No event occurred in endpoint 7.
     * |        |          |1 = USB event occurred on Endpoint 7
     * |        |          |Check USBD_EPSTS0[31:28] to know which kind of USB event was occurred, cleared by writing 1 to USBD_INTSTS[23] or USBD_EPINTSTS[7] or USBD_INTSTS[1].
     * |[24]    |EPEVT8    |Endpoint 8's USB Event Status
     * |        |          |0 = No event occurred in endpoint 8.
     * |        |          |1 = USB event occurred on Endpoint 8
     * |        |          |Check USBD_EPSTS1[3:0] to know which kind of USB event was occurred, cleared by writing 1 to USBD_INTSTS[24] or USBD_EPINTSTS[8] or USBD_INTSTS[1].
     * |[25]    |EPEVT9    |Endpoint 9's USB Event Status
     * |        |          |0 = No event occurred in endpoint 9.
     * |        |          |1 = USB event occurred on Endpoint 9
     * |        |          |Check USBD_EPSTS1[7:4] to know which kind of USB event was occurred, cleared by writing 1 to USBD_INTSTS[25] or USBD_EPINTSTS[9] or USBD_INTSTS[1].
     * |[26]    |EPEVT10   |Endpoint 10's USB Event Status
     * |        |          |0 = No event occurred in endpoint 10.
     * |        |          |1 = USB event occurred on Endpoint 10
     * |        |          |Check USBD_EPSTS1[11:8] to know which kind of USB event was occurred, cleared by writing 1 to USBD_INTSTS[26] or USBD_EPINTSTS[10] or USBD_INTSTS[1].
     * |[27]    |EPEVT11   |Endpoint 11's USB Event Status
     * |        |          |0 = No event occurred in endpoint 11.
     * |        |          |1 = USB event occurred on Endpoint 11
     * |        |          |Check USBD_EPSTS1[15:12] to know which kind of USB event was occurred, cleared by writing 1 to USBD_INTSTS[27] or USBD_EPINTSTS[11] or USBD_INTSTS[1].
     * |[31]    |SETUP     |Setup Event Status
     * |        |          |0 = No Setup event.
     * |        |          |1 = Setup event occurred, cleared by writing 1 to USBD_INTSTS[31].
     * @var USBD_T::FADDR
     * Offset: 0x08  USB Device Function Address Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[6:0]   |FADDR     |USB Device Function Address
     * @var USBD_T::EPSTS
     * Offset: 0x0C  USB Device Endpoint Status Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[7]     |OV        |Overrun
     * |        |          |It indicates that the received data is over the maximum payload number or not.
     * |        |          |0 = No overrun.
     * |        |          |1 = Out Data is more than the Max Payload in MXPLD register or the Setup Data is more than 8 bytes.
     * @var USBD_T::ATTR
     * Offset: 0x10  USB Device Bus Status and Attribution Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |USBRST    |USB Reset Status (Read Only)
     * |        |          |0 = Bus no reset.
     * |        |          |1 = Bus reset when SE0 (single-ended 0) more than 2.5us.
     * |[1]     |SUSPEND   |Suspend Status (Read Only)
     * |        |          |0 = Bus no suspend.
     * |        |          |1 = Bus idle more than 3ms, either cable is plugged-out or host is sleeping.
     * |[2]     |RESUME    |Resume Status (Read Only)
     * |        |          |0 = No bus resume.
     * |        |          |1 = Resume from suspend.
     * |[3]     |TOUT      |Time-out Status (Read Only)
     * |        |          |0 = No time-out.
     * |        |          |1 = No Bus response more than 18 bits time.
     * |[4]     |PHYEN     |PHY Transceiver Function Enable Bit
     * |        |          |0 = PHY transceiver function Disabled.
     * |        |          |1 = PHY transceiver function Enabled.
     * |[5]     |RWAKEUP   |Remote Wake-up
     * |        |          |0 = Release the USB bus from K state.
     * |        |          |1 = Force USB bus to K (USB_D+ low, USB_D- high) state, used for remote wake-up.
     * |[7]     |USBEN     |USB Controller Enable Bit
     * |        |          |0 = USB Controller Disabled.
     * |        |          |1 = USB Controller Enabled.
     * |[8]     |DPPUEN    |Pull-up Resistor on USB_DP Enable Bit
     * |        |          |0 = Pull-up resistor in USB_D+ bus Disabled.
     * |        |          |1 = Pull-up resistor in USB_D+ bus Active.
     * |[9]     |PWRDN     |Power-down PHY Transceiver, Low Active
     * |        |          |0 = Power-down related circuit of PHY transceiver.
     * |        |          |1 = Turn-on related circuit of PHY transceiver.
     * |[10]    |BYTEM     |CPU Access USB SRAM Size Mode Selection
     * |        |          |0 = Word mode: The size of the transfer from CPU to USB SRAM can be Word only.
     * |        |          |1 = Byte mode: The size of the transfer from CPU to USB SRAM can be Byte only.
     * |[11]    |LPMACK    |LPM Token Acknowledge Enable Bit
     * |        |          |The NYET/ACK will be returned only on a successful LPM transaction if no errors in both the EXT token and the LPM token and a valid bLinkState = 0001 (L1) is received, else ERROR and STALL will be returned automatically, respectively.
     * |        |          |0= The valid LPM Token will be NYET.
     * |        |          |1= The valid LPM Token will be ACK.
     * |[12]    |L1SUSPEND |LPM L1 Suspend (Read Only)
     * |        |          |0 = Bus no L1 state suspend.
     * |        |          |1 = This bit is set by the hardware when LPM command to enter the L1 state is successfully received and acknowledged.
     * |[13]    |L1RESUME  |LPM L1 Resume (Read Only)
     * |        |          |0 = Bus no LPM L1 state resume.
     * |        |          |1 = LPM L1 state resume from LPM L1 state suspend.
     * @var USBD_T::VBUSDET
     * Offset: 0x14  USB Device VBUS Detection Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |VBUSDET   |Device VBUS Detection
     * |        |          |0 = Controller is not attached to the USB host.
     * |        |          |1 = Controller is attached to the USB host.
     * @var USBD_T::STBUFSEG
     * Offset: 0x18  SETUP Token Buffer Segmentation Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[10:3]  |STBUFSEG  |SETUP Token Buffer Segmentation
     * |        |          |It is used to indicate the offset address for the SETUP token with the USB Device SRAM starting address
     * |        |          |The effective starting address is USBD_SRAM address + {STBUFSEG, 3'b000}
     * |        |          |Where the USBD_SRAM address = USBD_BA+0x800h.
     * |        |          |Note: It is used for SETUP token only.
     * @var USBD_T::EPSTS0
     * Offset: 0x20  USB Device Endpoint Status Register 0
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[03:00] |EPSTS0    |Endpoint 0 Status
     * |        |          |These bits are used to indicate the current status of this endpoint.
     * |        |          |0000 = In ACK.
     * |        |          |0001 = In NAK.
     * |        |          |0010 = Out Packet Data0 ACK.
     * |        |          |0110 = Out Packet Data1 ACK.
     * |        |          |0111 = Isochronous transfer end.
     * |[07:04] |EPSTS1    |Endpoint 1 Status
     * |        |          |These bits are used to indicate the current status of this endpoint.
     * |        |          |0000 = In ACK.
     * |        |          |0001 = In NAK.
     * |        |          |0010 = Out Packet Data0 ACK.
     * |        |          |0110 = Out Packet Data1 ACK.
     * |        |          |0111 = Isochronous transfer end.
     * |[11:08] |EPSTS2    |Endpoint 2 Status
     * |        |          |These bits are used to indicate the current status of this endpoint.
     * |        |          |0000 = In ACK.
     * |        |          |0001 = In NAK.
     * |        |          |0010 = Out Packet Data0 ACK.
     * |        |          |0110 = Out Packet Data1 ACK.
     * |        |          |0111 = Isochronous transfer end.
     * |[15:12] |EPSTS3    |Endpoint 3 Status
     * |        |          |These bits are used to indicate the current status of this endpoint.
     * |        |          |0000 = In ACK.
     * |        |          |0001 = In NAK.
     * |        |          |0010 = Out Packet Data0 ACK.
     * |        |          |0110 = Out Packet Data1 ACK.
     * |        |          |0111 = Isochronous transfer end.
     * |[19:16] |EPSTS4    |Endpoint 4 Status
     * |        |          |These bits are used to indicate the current status of this endpoint.
     * |        |          |0000 = In ACK.
     * |        |          |0001 = In NAK.
     * |        |          |0010 = Out Packet Data0 ACK.
     * |        |          |0110 = Out Packet Data1 ACK.
     * |        |          |0111 = Isochronous transfer end.
     * |[23:20] |EPSTS5    |Endpoint 5 Status
     * |        |          |These bits are used to indicate the current status of this endpoint.
     * |        |          |0000 = In ACK.
     * |        |          |0001 = In NAK.
     * |        |          |0010 = Out Packet Data0 ACK.
     * |        |          |0110 = Out Packet Data1 ACK.
     * |        |          |0111 = Isochronous transfer end.
     * |[27:24] |EPSTS6    |Endpoint 6 Status
     * |        |          |These bits are used to indicate the current status of this endpoint.
     * |        |          |0000 = In ACK.
     * |        |          |0001 = In NAK.
     * |        |          |0010 = Out Packet Data0 ACK.
     * |        |          |0110 = Out Packet Data1 ACK.
     * |        |          |0111 = Isochronous transfer end.
     * |[31:28] |EPSTS7    |Endpoint 7 Status
     * |        |          |These bits are used to indicate the current status of this endpoint.
     * |        |          |0000 = In ACK.
     * |        |          |0001 = In NAK.
     * |        |          |0010 = Out Packet Data0 ACK.
     * |        |          |0110 = Out Packet Data1 ACK.
     * |        |          |0111 = Isochronous transfer end.
     * @var USBD_T::EPSTS1
     * Offset: 0x24  USB Device Endpoint Status Register 1
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[3:0]   |EPSTS8    |Endpoint 8 Status
     * |        |          |These bits are used to indicate the current status of this endpoint.
     * |        |          |0000 = In ACK.
     * |        |          |0001 = In NAK.
     * |        |          |0010 = Out Packet Data0 ACK.
     * |        |          |0110 = Out Packet Data1 ACK.
     * |        |          |0111 = Isochronous transfer end.
     * |[7:4]   |EPSTS9    |Endpoint 9 Status
     * |        |          |These bits are used to indicate the current status of this endpoint.
     * |        |          |0000 = In ACK.
     * |        |          |0001 = In NAK.
     * |        |          |0010 = Out Packet Data0 ACK.
     * |        |          |0110 = Out Packet Data1 ACK.
     * |        |          |0111 = Isochronous transfer end.
     * |[11:8]  |EPSTS10   |Endpoint 10 Status
     * |        |          |These bits are used to indicate the current status of this endpoint.
     * |        |          |0000 = In ACK.
     * |        |          |0001 = In NAK.
     * |        |          |0010 = Out Packet Data0 ACK.
     * |        |          |0110 = Out Packet Data1 ACK.
     * |        |          |0111 = Isochronous transfer end.
     * |[15:12] |EPSTS11   |Endpoint 11 Status
     * |        |          |These bits are used to indicate the current status of this endpoint.
     * |        |          |0000 = In ACK.
     * |        |          |0001 = In NAK.
     * |        |          |0010 = Out Packet Data0 ACK.
     * |        |          |0110 = Out Packet Data1 ACK.
     * |        |          |0111 = Isochronous transfer end.
     * |[19:16] |EPSTS12   |Endpoint 12 Status
     * |        |          |These bits are used to indicate the current status of this endpoint.
     * |        |          |0000 = In ACK.
     * |        |          |0001 = In NAK.
     * |        |          |0010 = Out Packet Data0 ACK.
     * |        |          |0110 = Out Packet Data1 ACK.
     * |        |          |0111 = Isochronous transfer end.
     * |[23:20] |EPSTS13   |Endpoint 13 Status
     * |        |          |These bits are used to indicate the current status of this endpoint.
     * |        |          |0000 = In ACK.
     * |        |          |0001 = In NAK.
     * |        |          |0010 = Out Packet Data0 ACK.
     * |        |          |0110 = Out Packet Data1 ACK.
     * |        |          |0111 = Isochronous transfer end.
     * |[27:24] |EPSTS14   |Endpoint 14 Status
     * |        |          |These bits are used to indicate the current status of this endpoint.
     * |        |          |0000 = In ACK.
     * |        |          |0001 = In NAK.
     * |        |          |0010 = Out Packet Data0 ACK.
     * |        |          |0110 = Out Packet Data1 ACK.
     * |        |          |0111 = Isochronous transfer end.
     * |[31:28] |EPSTS15   |Endpoint 15 Status
     * |        |          |These bits are used to indicate the current status of this endpoint.
     * |        |          |0000 = In ACK.
     * |        |          |0001 = In NAK.
     * |        |          |0010 = Out Packet Data0 ACK.
     * |        |          |0110 = Out Packet Data1 ACK.
     * |        |          |0111 = Isochronous transfer end.
     * @var USBD_T::EPSTS2
     * Offset: 0x28  USB Device Endpoint Status Register 2
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[3:0]   |EPSTS16   |Endpoint 16 Status
     * |        |          |These bits are used to indicate the current status of this endpoint.
     * |        |          |0000 = In ACK.
     * |        |          |0001 = In NAK.
     * |        |          |0010 = Out Packet Data0 ACK.
     * |        |          |0110 = Out Packet Data1 ACK.
     * |        |          |0111 = Isochronous transfer end.
     * |[7:4]   |EPSTS17   |Endpoint 17 Status
     * |        |          |These bits are used to indicate the current status of this endpoint.
     * |        |          |0000 = In ACK.
     * |        |          |0001 = In NAK.
     * |        |          |0010 = Out Packet Data0 ACK.
     * |        |          |0110 = Out Packet Data1 ACK.
     * |        |          |0111 = Isochronous transfer end.
     * |[11:8]  |EPSTS18   |Endpoint 18 Status
     * |        |          |These bits are used to indicate the current status of this endpoint.
     * |        |          |0000 = In ACK.
     * |        |          |0001 = In NAK.
     * |        |          |0010 = Out Packet Data0 ACK.
     * |        |          |0110 = Out Packet Data1 ACK.
     * |        |          |0111 = Isochronous transfer end.
     * |[15:12] |EPSTS19   |Endpoint 19 Status
     * |        |          |These bits are used to indicate the current status of this endpoint.
     * |        |          |0000 = In ACK.
     * |        |          |0001 = In NAK.
     * |        |          |0010 = Out Packet Data0 ACK.
     * |        |          |0110 = Out Packet Data1 ACK.
     * |        |          |0111 = Isochronous transfer end.
     * |[19:16] |EPSTS20   |Endpoint 20 Status
     * |        |          |These bits are used to indicate the current status of this endpoint.
     * |        |          |0000 = In ACK.
     * |        |          |0001 = In NAK.
     * |        |          |0010 = Out Packet Data0 ACK.
     * |        |          |0110 = Out Packet Data1 ACK.
     * |        |          |0111 = Isochronous transfer end.
     * |[23:20] |EPSTS21   |Endpoint 21 Status
     * |        |          |These bits are used to indicate the current status of this endpoint.
     * |        |          |0000 = In ACK.
     * |        |          |0001 = In NAK.
     * |        |          |0010 = Out Packet Data0 ACK.
     * |        |          |0110 = Out Packet Data1 ACK.
     * |        |          |0111 = Isochronous transfer end.
     * |[27:24] |EPSTS22   |Endpoint 22 Status
     * |        |          |These bits are used to indicate the current status of this endpoint.
     * |        |          |0000 = In ACK.
     * |        |          |0001 = In NAK.
     * |        |          |0010 = Out Packet Data0 ACK.
     * |        |          |0110 = Out Packet Data1 ACK.
     * |        |          |0111 = Isochronous transfer end.
     * |[31:28] |EPSTS23   |Endpoint 23 Status
     * |        |          |These bits are used to indicate the current status of this endpoint.
     * |        |          |0000 = In ACK.
     * |        |          |0001 = In NAK.
     * |        |          |0010 = Out Packet Data0 ACK.
     * |        |          |0110 = Out Packet Data1 ACK.
     * |        |          |0111 = Isochronous transfer end.
     * @var USBD_T::EPSTS3
     * Offset: 0x2C  USB Device Endpoint Status Register 3
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[3:0]   |EPSTS24   |Endpoint 24 Status
     * |        |          |These bits are used to indicate the current status of this endpoint.
     * |        |          |0000 = In ACK.
     * |        |          |0001 = In NAK.
     * |        |          |0010 = Out Packet Data0 ACK.
     * |        |          |0110 = Out Packet Data1 ACK.
     * |        |          |0111 = Isochronous transfer end.
     * @var USBD_T::EPINTSTS
     * Offset: 0x30  USB Device Endpoint Interrupt Event Status Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |EPEVT0    |Endpoint 0's USB Event Status
     * |        |          |0 = No event occurred in endpoint 0.
     * |        |          |1 = USB event occurred on Endpoint 0.
     * |        |          |Check USBD_EPSTS0[3:0] to know which kind of USB event was occurred, cleared by writing 1 to USBD_EPINTSTS[0] or USBD_INTSTS[16] or USBD_INTSTS[1].
     * |[1]     |EPEVT1    |Endpoint 1's USB Event Status
     * |        |          |0 = No event occurred in endpoint 1.
     * |        |          |1 = USB event occurred on Endpoint 1.
     * |        |          |Check USBD_EPSTS0[7:4] to know which kind of USB event was occurred, cleared by writing 1 to USBD_EPINTSTS[1] or USBD_INTSTS[17] or USBD_INTSTS[1].
     * |[2]     |EPEVT2    |Endpoint 2's USB Event Status
     * |        |          |0 = No event occurred in endpoint 2.
     * |        |          |1 = USB event occurred on Endpoint 2.
     * |        |          |Check USBD_EPSTS0[11:8] to know which kind of USB event was occurred, cleared by writing 1 to USBD_EPINTSTS[2] or USBD_EPINTSTS[2] or USBD_INTSTS[18] or USBD_INTSTS[1].
     * |[3]     |EPEVT3    |Endpoint 3's USB Event Status
     * |        |          |0 = No event occurred in endpoint 3.
     * |        |          |1 = USB event occurred on Endpoint 3.
     * |        |          |Check USBD_EPSTS0[15:12] to know which kind of USB event was occurred, cleared by writing 1 to USBD_EPINTSTS[3] or USBD_INTSTS[19] or USBD_INTSTS[1].
     * |[4]     |EPEVT4    |Endpoint 4's USB Event Status
     * |        |          |0 = No event occurred in endpoint 4.
     * |        |          |1 = USB event occurred on Endpoint 4.
     * |        |          |Check USBD_EPSTS0[19:16] to know which kind of USB event was occurred, cleared by writing 1 to USBD_EPINTSTS[4] or USBD_INTSTS[20] or USBD_INTSTS[1].
     * |[5]     |EPEVT5    |Endpoint 5's USB Event Status
     * |        |          |0 = No event occurred in endpoint 5.
     * |        |          |1 = USB event occurred on Endpoint 5.
     * |        |          |Check USBD_EPSTS0[23:20] to know which kind of USB event was occurred, cleared by writing 1 to USBD_EPINTSTS[5] or USBD_INTSTS[21] or USBD_INTSTS[1].
     * |[6]     |EPEVT6    |Endpoint 6's USB Event Status
     * |        |          |0 = No event occurred in endpoint 6.
     * |        |          |1 = USB event occurred on Endpoint 6.
     * |        |          |Check USBD_EPSTS0[27:24] to know which kind of USB event was occurred, cleared by writing 1 to USBD_EPINTSTS[6] or USBD_INTSTS[22] or USBD_INTSTS[1].
     * |[7]     |EPEVT7    |Endpoint 7's USB Event Status
     * |        |          |0 = No event occurred in endpoint 7.
     * |        |          |1 = USB event occurred on Endpoint 7.
     * |        |          |Check USBD_EPSTS0[31:28] to know which kind of USB event was occurred, cleared by writing 1 to USBD_EPINTSTS[7] or USBD_INTSTS[23] or USBD_INTSTS[1].
     * |[8]     |EPEVT8    |Endpoint 8's USB Event Status
     * |        |          |0 = No event occurred in endpoint 8.
     * |        |          |1 = USB event occurred on Endpoint 8.
     * |        |          |Check USBD_EPSTS1[3:0] to know which kind of USB event was occurred, cleared by writing 1 to USBD_EPINTSTS[8] or USBD_INTSTS[24] or USBD_INTSTS[1].
     * |[9]     |EPEVT9    |Endpoint 9's USB Event Status
     * |        |          |0 = No event occurred in endpoint 9.
     * |        |          |1 = USB event occurred on Endpoint 9.
     * |        |          |Check USBD_EPSTS1[7:4] to know which kind of USB event was occurred, cleared by writing 1 to USBD_EPINTSTS[9] or USBD_INTSTS[25] or USBD_INTSTS[1].
     * |[10]    |EPEVT10   |Endpoint 10's USB Event Status
     * |        |          |0 = No event occurred in endpoint 10.
     * |        |          |1 = USB event occurred on Endpoint 10.
     * |        |          |Check USBD_EPSTS1[11:8] to know which kind of USB event was occurred, cleared by writing 1 to USBD_EPINTSTS[10] or USBD_INTSTS[26] or USBD_INTSTS[1].
     * |[11]    |EPEVT11   |Endpoint 11's USB Event Status
     * |        |          |0 = No event occurred in endpoint 11.
     * |        |          |1 = USB event occurred on Endpoint 11.
     * |        |          |Check USBD_EPSTS1[15:12] to know which kind of USB event was occurred, cleared by writing 1 to USBD_EPINTSTS[11] or USBD_INTSTS[27] or USBD_INTSTS[1].
     * |[12]    |EPEVT12   |Endpoint 12's USB Event Status
     * |        |          |0 = No event occurred in endpoint 12.
     * |        |          |1 = USB event occurred on Endpoint 12.
     * |        |          |Check USBD_EPSTS1[19:16] to know which kind of USB event was occurred, cleared by writing 1 to USBD_EPINTSTS[12] or USBD_INTSTS[1].
     * |[13]    |EPEVT13   |Endpoint 13's USB Event Status
     * |        |          |0 = No event occurred in endpoint 13.
     * |        |          |1 = USB event occurred on Endpoint 13.
     * |        |          |Check USBD_EPSTS1[23:20] to know which kind of USB event was occurred, cleared by writing 1 to USBD_EPINTSTS[13] or USBD_INTSTS[1].
     * |[14]    |EPEVT14   |Endpoint 14's USB Event Status
     * |        |          |0 = No event occurred in endpoint 14.
     * |        |          |1 = USB event occurred on Endpoint 14.
     * |        |          |Check USBD_EPSTS1[27:24] to know which kind of USB event was occurred, cleared by writing 1 to USBD_EPINTSTS[14] or USBD_INTSTS[1].
     * |[15]    |EPEVT15   |Endpoint 15's USB Event Status
     * |        |          |0 = No event occurred in endpoint 15.
     * |        |          |1 = USB event occurred on Endpoint 15.
     * |        |          |Check USBD_EPSTS1[31:28] to know which kind of USB event was occurred, cleared by writing 1 to USBD_EPINTSTS[15] or USBD_INTSTS[1].
     * |[16]    |EPEVT16   |Endpoint 16's USB Event Status
     * |        |          |0 = No event occurred in endpoint 16.
     * |        |          |1 = USB event occurred on Endpoint 16.
     * |        |          |Check USBD_EPSTS2[3:0] to know which kind of USB event was occurred, cleared by writing 1 to USBD_EPINTSTS[16] or USBD_INTSTS[1].
     * |[17]    |EPEVT17   |Endpoint 17's USB Event Status
     * |        |          |0 = No event occurred in endpoint 17.
     * |        |          |1 = USB event occurred on Endpoint 17.
     * |        |          |Check USBD_EPSTS2[7:4] to know which kind of USB event was occurred, cleared by writing 1 to USBD_EPINTSTS[17] or USBD_INTSTS[1].
     * |[18]    |EPEVT18   |Endpoint 18's USB Event Status
     * |        |          |0 = No event occurred in endpoint 18.
     * |        |          |1 = USB event occurred on Endpoint 18.
     * |        |          |Check USBD_EPSTS2[11:8] to know which kind of USB event was occurred, cleared by writing 1 to USBD_EPINTSTS[18] or USBD_INTSTS[1].
     * |[19]    |EPEVT19   |Endpoint 19's USB Event Status
     * |        |          |0 = No event occurred in endpoint 19.
     * |        |          |1 = USB event occurred on Endpoint 19.
     * |        |          |Check USBD_EPSTS2[15:12] to know which kind of USB event was occurred, cleared by writing 1 to USBD_EPINTSTS[19] or USBD_INTSTS[1].
     * |[20]    |EPEVT20   |Endpoint 20's USB Event Status
     * |        |          |0 = No event occurred in endpoint 20.
     * |        |          |1 = USB event occurred on Endpoint 20.
     * |        |          |Check USBD_EPSTS2[19:16] to know which kind of USB event was occurred, cleared by writing 1 to USBD_EPINTSTS[20] or USBD_INTSTS[1].
     * |[21]    |EPEVT21   |Endpoint 21's USB Event Status
     * |        |          |0 = No event occurred in endpoint 21.
     * |        |          |1 = USB event occurred on Endpoint 21.
     * |        |          |Check USBD_EPSTS2[23:20] to know which kind of USB event was occurred, cleared by writing 1 to USBD_EPINTSTS[21] or USBD_INTSTS[1].
     * |[22]    |EPEVT22   |Endpoint 22's USB Event Status
     * |        |          |0 = No event occurred in endpoint 22.
     * |        |          |1 = USB event occurred on Endpoint 22.
     * |        |          |Check USBD_EPSTS2[27:24] to know which kind of USB event was occurred, cleared by writing 1 to USBD_EPINTSTS[22] or USBD_INTSTS[1].
     * |[23]    |EPEVT23   |Endpoint 23's USB Event Status
     * |        |          |0 = No event occurred in endpoint 23.
     * |        |          |1 = USB event occurred on Endpoint 23.
     * |        |          |Check USBD_EPSTS2[31:28] to know which kind of USB event was occurred, cleared by writing 1 to USBD_EPINTSTS[23] or USBD_INTSTS[1].
     * |[24]    |EPEVT24   |Endpoint 24's USB Event Status
     * |        |          |0 = No event occurred in endpoint 24.
     * |        |          |1 = USB event occurred on Endpoint 24.
     * |        |          |Check USBD_EPSTS3[3:0] to know which kind of USB event was occurred, cleared by writing 1 to USBD_EPINTSTS[24] or USBD_INTSTS[1].
     * @var USBD_T::LPMATTR
     * Offset: 0x88  USB LPM Attribution Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[3:0]   |LPMLINKSTS|LPM Link State
     * |        |          |These bits contain the bLinkState received with last ACK LPM Token
     * |[7:4]   |LPMBESL   |LPM Best Effort Service Latency
     * |        |          |These bits contain the BESL value received with last ACK LPM Token
     * |[8]     |LPMRWAKUP |LPM Remote Wakeup
     * |        |          |This bit contains the bRemoteWake value received with last ACK LPM Token
     * @var USBD_T::FN
     * Offset: 0x8C  USB Frame Number Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[10:0]  |FN        |Frame Number
     * |        |          |These bits contain the 11 bits frame number in the last received SOF packet.
     * @var USBD_T::SE0
     * Offset: 0x90  USB Device Drive SE0 Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |SE0       |Drive Single Ended Zero in USB Bus
     * |        |          |The Single Ended Zero (SE0) is when both lines (USB_D+ and USB_D-) are being pulled low.
     * |        |          |0 = Normal operation.
     * |        |          |1 = Force USB PHY transceiver to drive SE0.
     */

    __IO uint32_t INTEN;                 /*!< [0x0000] USB Device Interrupt Enable Register                             */
    __IO uint32_t INTSTS;                /*!< [0x0004] USB Device Interrupt Event Status Register                       */
    __IO uint32_t FADDR;                 /*!< [0x0008] USB Device Function Address Register                             */
    __I  uint32_t EPSTS;                 /*!< [0x000c] USB Device Endpoint Status Register                              */
    __IO uint32_t ATTR;                  /*!< [0x0010] USB Device Bus Status and Attribution Register                   */
    __I  uint32_t VBUSDET;               /*!< [0x0014] USB Device VBUS Detection Register                               */
    __IO uint32_t STBUFSEG;              /*!< [0x0018] SETUP Token Buffer Segmentation Register                         */
    __I  uint32_t RESERVE0[1];
    __I  uint32_t EPSTS0;                /*!< [0x0020] USB Device Endpoint Status Register 0                            */
    __I  uint32_t EPSTS1;                /*!< [0x0024] USB Device Endpoint Status Register 1                            */
    __I  uint32_t EPSTS2;                /*!< [0x0028] USB Device Endpoint Status Register 2                            */
    __I  uint32_t EPSTS3;                /*!< [0x002c] USB Device Endpoint Status Register 3                            */
    __IO uint32_t EPINTSTS;              /*!< [0x0030] USB Device Endpoint Interrupt Event Status Register              */
    __I  uint32_t RESERVE1[21];
    __I  uint32_t LPMATTR;               /*!< [0x0088] USB LPM Attribution Register                                     */
    __I  uint32_t FN;                    /*!< [0x008c] USB Frame Number Register                                        */
    __IO uint32_t SE0;                   /*!< [0x0090] USB Device Drive SE0 Control Register                            */
    __I  uint32_t RESERVE3[283];
    USBD_EP_T     EP[25];                /*!< [0x500~0x68c] USB End Point 0 ~ 24 Configuration Register                 */

} USBD_T;

/**
    @addtogroup USBD_CONST USBD Bit Field Definition
    Constant Definitions for USBD Controller
@{ */

#define USBD_INTEN_BUSIEN_Pos            (0)                                               /*!< USBD_T::INTEN: BUSIEN Position         */
#define USBD_INTEN_BUSIEN_Msk            (0x1ul << USBD_INTEN_BUSIEN_Pos)                  /*!< USBD_T::INTEN: BUSIEN Mask             */

#define USBD_INTEN_USBIEN_Pos            (1)                                               /*!< USBD_T::INTEN: USBIEN Position         */
#define USBD_INTEN_USBIEN_Msk            (0x1ul << USBD_INTEN_USBIEN_Pos)                  /*!< USBD_T::INTEN: USBIEN Mask             */

#define USBD_INTEN_VBDETIEN_Pos          (2)                                               /*!< USBD_T::INTEN: VBDETIEN Position       */
#define USBD_INTEN_VBDETIEN_Msk          (0x1ul << USBD_INTEN_VBDETIEN_Pos)                /*!< USBD_T::INTEN: VBDETIEN Mask           */

#define USBD_INTEN_NEVWKIEN_Pos          (3)                                               /*!< USBD_T::INTEN: NEVWKIEN Position       */
#define USBD_INTEN_NEVWKIEN_Msk          (0x1ul << USBD_INTEN_NEVWKIEN_Pos)                /*!< USBD_T::INTEN: NEVWKIEN Mask           */

#define USBD_INTEN_SOFIEN_Pos            (4)                                               /*!< USBD_T::INTEN: SOFIEN Position         */
#define USBD_INTEN_SOFIEN_Msk            (0x1ul << USBD_INTEN_SOFIEN_Pos)                  /*!< USBD_T::INTEN: SOFIEN Mask             */

#define USBD_INTEN_WKEN_Pos              (8)                                               /*!< USBD_T::INTEN: WKEN Position           */
#define USBD_INTEN_WKEN_Msk              (0x1ul << USBD_INTEN_WKEN_Pos)                    /*!< USBD_T::INTEN: WKEN Mask               */

#define USBD_INTEN_INNAKEN_Pos           (15)                                              /*!< USBD_T::INTEN: INNAKEN Position        */
#define USBD_INTEN_INNAKEN_Msk           (0x1ul << USBD_INTEN_INNAKEN_Pos)                 /*!< USBD_T::INTEN: INNAKEN Mask            */

#define USBD_INTSTS_BUSIF_Pos            (0)                                               /*!< USBD_T::INTSTS: BUSIF Position         */
#define USBD_INTSTS_BUSIF_Msk            (0x1ul << USBD_INTSTS_BUSIF_Pos)                  /*!< USBD_T::INTSTS: BUSIF Mask             */

#define USBD_INTSTS_USBIF_Pos            (1)                                               /*!< USBD_T::INTSTS: USBIF Position         */
#define USBD_INTSTS_USBIF_Msk            (0x1ul << USBD_INTSTS_USBIF_Pos)                  /*!< USBD_T::INTSTS: USBIF Mask             */

#define USBD_INTSTS_VBDETIF_Pos          (2)                                               /*!< USBD_T::INTSTS: VBDETIF Position       */
#define USBD_INTSTS_VBDETIF_Msk          (0x1ul << USBD_INTSTS_VBDETIF_Pos)                /*!< USBD_T::INTSTS: VBDETIF Mask           */

#define USBD_INTSTS_NEVWKIF_Pos          (3)                                               /*!< USBD_T::INTSTS: NEVWKIF Position       */
#define USBD_INTSTS_NEVWKIF_Msk          (0x1ul << USBD_INTSTS_NEVWKIF_Pos)                /*!< USBD_T::INTSTS: NEVWKIF Mask           */

#define USBD_INTSTS_SOFIF_Pos            (4)                                               /*!< USBD_T::INTSTS: SOFIF Position         */
#define USBD_INTSTS_SOFIF_Msk            (0x1ul << USBD_INTSTS_SOFIF_Pos)                  /*!< USBD_T::INTSTS: SOFIF Mask             */

#define USBD_INTSTS_EPEVT0_Pos           (16)                                              /*!< USBD_T::INTSTS: EPEVT0 Position        */
#define USBD_INTSTS_EPEVT0_Msk           (0x1ul << USBD_INTSTS_EPEVT0_Pos)                 /*!< USBD_T::INTSTS: EPEVT0 Mask            */

#define USBD_INTSTS_EPEVT1_Pos           (17)                                              /*!< USBD_T::INTSTS: EPEVT1 Position        */
#define USBD_INTSTS_EPEVT1_Msk           (0x1ul << USBD_INTSTS_EPEVT1_Pos)                 /*!< USBD_T::INTSTS: EPEVT1 Mask            */

#define USBD_INTSTS_EPEVT2_Pos           (18)                                              /*!< USBD_T::INTSTS: EPEVT2 Position        */
#define USBD_INTSTS_EPEVT2_Msk           (0x1ul << USBD_INTSTS_EPEVT2_Pos)                 /*!< USBD_T::INTSTS: EPEVT2 Mask            */

#define USBD_INTSTS_EPEVT3_Pos           (19)                                              /*!< USBD_T::INTSTS: EPEVT3 Position        */
#define USBD_INTSTS_EPEVT3_Msk           (0x1ul << USBD_INTSTS_EPEVT3_Pos)                 /*!< USBD_T::INTSTS: EPEVT3 Mask            */

#define USBD_INTSTS_EPEVT4_Pos           (20)                                              /*!< USBD_T::INTSTS: EPEVT4 Position        */
#define USBD_INTSTS_EPEVT4_Msk           (0x1ul << USBD_INTSTS_EPEVT4_Pos)                 /*!< USBD_T::INTSTS: EPEVT4 Mask            */

#define USBD_INTSTS_EPEVT5_Pos           (21)                                              /*!< USBD_T::INTSTS: EPEVT5 Position        */
#define USBD_INTSTS_EPEVT5_Msk           (0x1ul << USBD_INTSTS_EPEVT5_Pos)                 /*!< USBD_T::INTSTS: EPEVT5 Mask            */

#define USBD_INTSTS_EPEVT6_Pos           (22)                                              /*!< USBD_T::INTSTS: EPEVT6 Position        */
#define USBD_INTSTS_EPEVT6_Msk           (0x1ul << USBD_INTSTS_EPEVT6_Pos)                 /*!< USBD_T::INTSTS: EPEVT6 Mask            */

#define USBD_INTSTS_EPEVT7_Pos           (23)                                              /*!< USBD_T::INTSTS: EPEVT7 Position        */
#define USBD_INTSTS_EPEVT7_Msk           (0x1ul << USBD_INTSTS_EPEVT7_Pos)                 /*!< USBD_T::INTSTS: EPEVT7 Mask            */

#define USBD_INTSTS_EPEVT8_Pos           (24)                                              /*!< USBD_T::INTSTS: EPEVT8 Position        */
#define USBD_INTSTS_EPEVT8_Msk           (0x1ul << USBD_INTSTS_EPEVT8_Pos)                 /*!< USBD_T::INTSTS: EPEVT8 Mask            */

#define USBD_INTSTS_EPEVT9_Pos           (25)                                              /*!< USBD_T::INTSTS: EPEVT9 Position        */
#define USBD_INTSTS_EPEVT9_Msk           (0x1ul << USBD_INTSTS_EPEVT9_Pos)                 /*!< USBD_T::INTSTS: EPEVT9 Mask            */

#define USBD_INTSTS_EPEVT10_Pos          (26)                                              /*!< USBD_T::INTSTS: EPEVT10 Position       */
#define USBD_INTSTS_EPEVT10_Msk          (0x1ul << USBD_INTSTS_EPEVT10_Pos)                /*!< USBD_T::INTSTS: EPEVT10 Mask           */

#define USBD_INTSTS_EPEVT11_Pos          (27)                                              /*!< USBD_T::INTSTS: EPEVT11 Position       */
#define USBD_INTSTS_EPEVT11_Msk          (0x1ul << USBD_INTSTS_EPEVT11_Pos)                /*!< USBD_T::INTSTS: EPEVT11 Mask           */

#define USBD_INTSTS_SETUP_Pos            (31)                                              /*!< USBD_T::INTSTS: SETUP Position         */
#define USBD_INTSTS_SETUP_Msk            (0x1ul << USBD_INTSTS_SETUP_Pos)                  /*!< USBD_T::INTSTS: SETUP Mask             */

#define USBD_FADDR_FADDR_Pos             (0)                                               /*!< USBD_T::FADDR: FADDR Position          */
#define USBD_FADDR_FADDR_Msk             (0x7ful << USBD_FADDR_FADDR_Pos)                  /*!< USBD_T::FADDR: FADDR Mask              */

#define USBD_EPSTS_OV_Pos                (7)                                               /*!< USBD_T::EPSTS: OV Position             */
#define USBD_EPSTS_OV_Msk                (0x1ul << USBD_EPSTS_OV_Pos)                      /*!< USBD_T::EPSTS: OV Mask                 */

#define USBD_ATTR_USBRST_Pos             (0)                                               /*!< USBD_T::ATTR: USBRST Position          */
#define USBD_ATTR_USBRST_Msk             (0x1ul << USBD_ATTR_USBRST_Pos)                   /*!< USBD_T::ATTR: USBRST Mask              */

#define USBD_ATTR_SUSPEND_Pos            (1)                                               /*!< USBD_T::ATTR: SUSPEND Position         */
#define USBD_ATTR_SUSPEND_Msk            (0x1ul << USBD_ATTR_SUSPEND_Pos)                  /*!< USBD_T::ATTR: SUSPEND Mask             */

#define USBD_ATTR_RESUME_Pos             (2)                                               /*!< USBD_T::ATTR: RESUME Position          */
#define USBD_ATTR_RESUME_Msk             (0x1ul << USBD_ATTR_RESUME_Pos)                   /*!< USBD_T::ATTR: RESUME Mask              */

#define USBD_ATTR_TOUT_Pos               (3)                                               /*!< USBD_T::ATTR: TOUT Position            */
#define USBD_ATTR_TOUT_Msk               (0x1ul << USBD_ATTR_TOUT_Pos)                     /*!< USBD_T::ATTR: TOUT Mask                */

#define USBD_ATTR_PHYEN_Pos              (4)                                               /*!< USBD_T::ATTR: PHYEN Position           */
#define USBD_ATTR_PHYEN_Msk              (0x1ul << USBD_ATTR_PHYEN_Pos)                    /*!< USBD_T::ATTR: PHYEN Mask               */

#define USBD_ATTR_RWAKEUP_Pos            (5)                                               /*!< USBD_T::ATTR: RWAKEUP Position         */
#define USBD_ATTR_RWAKEUP_Msk            (0x1ul << USBD_ATTR_RWAKEUP_Pos)                  /*!< USBD_T::ATTR: RWAKEUP Mask             */

#define USBD_ATTR_USBEN_Pos              (7)                                               /*!< USBD_T::ATTR: USBEN Position           */
#define USBD_ATTR_USBEN_Msk              (0x1ul << USBD_ATTR_USBEN_Pos)                    /*!< USBD_T::ATTR: USBEN Mask               */

#define USBD_ATTR_DPPUEN_Pos             (8)                                               /*!< USBD_T::ATTR: DPPUEN Position          */
#define USBD_ATTR_DPPUEN_Msk             (0x1ul << USBD_ATTR_DPPUEN_Pos)                   /*!< USBD_T::ATTR: DPPUEN Mask              */

#define USBD_ATTR_PWRDN_Pos              (9)                                               /*!< USBD_T::ATTR: PWRDN Position           */
#define USBD_ATTR_PWRDN_Msk              (0x1ul << USBD_ATTR_PWRDN_Pos)                    /*!< USBD_T::ATTR: PWRDN Mask               */

#define USBD_ATTR_BYTEM_Pos              (10)                                              /*!< USBD_T::ATTR: BYTEM Position           */
#define USBD_ATTR_BYTEM_Msk              (0x1ul << USBD_ATTR_BYTEM_Pos)                    /*!< USBD_T::ATTR: BYTEM Mask               */

#define USBD_ATTR_LPMACK_Pos             (11)                                              /*!< USBD_T::ATTR: LPMACK Position          */
#define USBD_ATTR_LPMACK_Msk             (0x1ul << USBD_ATTR_LPMACK_Pos)                   /*!< USBD_T::ATTR: LPMACK Mask              */

#define USBD_ATTR_L1SUSPEND_Pos          (12)                                              /*!< USBD_T::ATTR: L1SUSPEND Position       */
#define USBD_ATTR_L1SUSPEND_Msk          (0x1ul << USBD_ATTR_L1SUSPEND_Pos)                /*!< USBD_T::ATTR: L1SUSPEND Mask           */

#define USBD_ATTR_L1RESUME_Pos           (13)                                              /*!< USBD_T::ATTR: L1RESUME Position        */
#define USBD_ATTR_L1RESUME_Msk           (0x1ul << USBD_ATTR_L1RESUME_Pos)                 /*!< USBD_T::ATTR: L1RESUME Mask            */

#define USBD_VBUSDET_VBUSDET_Pos         (0)                                               /*!< USBD_T::VBUSDET: VBUSDET Position      */
#define USBD_VBUSDET_VBUSDET_Msk         (0x1ul << USBD_VBUSDET_VBUSDET_Pos)               /*!< USBD_T::VBUSDET: VBUSDET Mask          */

#define USBD_STBUFSEG_STBUFSEG_Pos       (3)                                               /*!< USBD_T::STBUFSEG: STBUFSEG Position    */
#define USBD_STBUFSEG_STBUFSEG_Msk       (0xfful << USBD_STBUFSEG_STBUFSEG_Pos)            /*!< USBD_T::STBUFSEG: STBUFSEG Mask        */

#define USBD_EPSTS0_EPSTS0_Pos           (0)                                               /*!< USBD_T::EPSTS0: EPSTS0 Position        */
#define USBD_EPSTS0_EPSTS0_Msk           (0xful << USBD_EPSTS0_EPSTS0_Pos)                 /*!< USBD_T::EPSTS0: EPSTS0 Mask            */

#define USBD_EPSTS0_EPSTS1_Pos           (4)                                               /*!< USBD_T::EPSTS0: EPSTS1 Position        */
#define USBD_EPSTS0_EPSTS1_Msk           (0xful << USBD_EPSTS0_EPSTS1_Pos)                 /*!< USBD_T::EPSTS0: EPSTS1 Mask            */

#define USBD_EPSTS0_EPSTS2_Pos           (8)                                               /*!< USBD_T::EPSTS0: EPSTS2 Position        */
#define USBD_EPSTS0_EPSTS2_Msk           (0xful << USBD_EPSTS0_EPSTS2_Pos)                 /*!< USBD_T::EPSTS0: EPSTS2 Mask            */

#define USBD_EPSTS0_EPSTS3_Pos           (12)                                              /*!< USBD_T::EPSTS0: EPSTS3 Position        */
#define USBD_EPSTS0_EPSTS3_Msk           (0xful << USBD_EPSTS0_EPSTS3_Pos)                 /*!< USBD_T::EPSTS0: EPSTS3 Mask            */

#define USBD_EPSTS0_EPSTS4_Pos           (16)                                              /*!< USBD_T::EPSTS0: EPSTS4 Position        */
#define USBD_EPSTS0_EPSTS4_Msk           (0xful << USBD_EPSTS0_EPSTS4_Pos)                 /*!< USBD_T::EPSTS0: EPSTS4 Mask            */

#define USBD_EPSTS0_EPSTS5_Pos           (20)                                              /*!< USBD_T::EPSTS0: EPSTS5 Position        */
#define USBD_EPSTS0_EPSTS5_Msk           (0xful << USBD_EPSTS0_EPSTS5_Pos)                 /*!< USBD_T::EPSTS0: EPSTS5 Mask            */

#define USBD_EPSTS0_EPSTS6_Pos           (24)                                              /*!< USBD_T::EPSTS0: EPSTS6 Position        */
#define USBD_EPSTS0_EPSTS6_Msk           (0xful << USBD_EPSTS0_EPSTS6_Pos)                 /*!< USBD_T::EPSTS0: EPSTS6 Mask            */

#define USBD_EPSTS0_EPSTS7_Pos           (28)                                              /*!< USBD_T::EPSTS0: EPSTS7 Position        */
#define USBD_EPSTS0_EPSTS7_Msk           (0xful << USBD_EPSTS0_EPSTS7_Pos)                 /*!< USBD_T::EPSTS0: EPSTS7 Mask            */

#define USBD_EPSTS1_EPSTS8_Pos           (0)                                               /*!< USBD_T::EPSTS1: EPSTS8 Position        */
#define USBD_EPSTS1_EPSTS8_Msk           (0xful << USBD_EPSTS1_EPSTS8_Pos)                 /*!< USBD_T::EPSTS1: EPSTS8 Mask            */

#define USBD_EPSTS1_EPSTS9_Pos           (4)                                               /*!< USBD_T::EPSTS1: EPSTS9 Position        */
#define USBD_EPSTS1_EPSTS9_Msk           (0xful << USBD_EPSTS1_EPSTS9_Pos)                 /*!< USBD_T::EPSTS1: EPSTS9 Mask            */

#define USBD_EPSTS1_EPSTS10_Pos          (8)                                               /*!< USBD_T::EPSTS1: EPSTS10 Position       */
#define USBD_EPSTS1_EPSTS10_Msk          (0xful << USBD_EPSTS1_EPSTS10_Pos)                /*!< USBD_T::EPSTS1: EPSTS10 Mask           */

#define USBD_EPSTS1_EPSTS11_Pos          (12)                                              /*!< USBD_T::EPSTS1: EPSTS11 Position       */
#define USBD_EPSTS1_EPSTS11_Msk          (0xful << USBD_EPSTS1_EPSTS11_Pos)                /*!< USBD_T::EPSTS1: EPSTS11 Mask           */

#define USBD_EPSTS1_EPSTS12_Pos          (16)                                              /*!< USBD_T::EPSTS1: EPSTS12 Position       */
#define USBD_EPSTS1_EPSTS12_Msk          (0xful << USBD_EPSTS1_EPSTS12_Pos)                /*!< USBD_T::EPSTS1: EPSTS12 Mask           */

#define USBD_EPSTS1_EPSTS13_Pos          (20)                                              /*!< USBD_T::EPSTS1: EPSTS13 Position       */
#define USBD_EPSTS1_EPSTS13_Msk          (0xful << USBD_EPSTS1_EPSTS13_Pos)                /*!< USBD_T::EPSTS1: EPSTS13 Mask           */

#define USBD_EPSTS1_EPSTS14_Pos          (24)                                              /*!< USBD_T::EPSTS1: EPSTS14 Position       */
#define USBD_EPSTS1_EPSTS14_Msk          (0xful << USBD_EPSTS1_EPSTS14_Pos)                /*!< USBD_T::EPSTS1: EPSTS14 Mask           */

#define USBD_EPSTS1_EPSTS15_Pos          (28)                                              /*!< USBD_T::EPSTS1: EPSTS15 Position       */
#define USBD_EPSTS1_EPSTS15_Msk          (0xful << USBD_EPSTS1_EPSTS15_Pos)                /*!< USBD_T::EPSTS1: EPSTS15 Mask           */

#define USBD_EPSTS2_EPSTS16_Pos          (0)                                               /*!< USBD_T::EPSTS2: EPSTS16 Position       */
#define USBD_EPSTS2_EPSTS16_Msk          (0xful << USBD_EPSTS2_EPSTS16_Pos)                /*!< USBD_T::EPSTS2: EPSTS16 Mask           */

#define USBD_EPSTS2_EPSTS17_Pos          (4)                                               /*!< USBD_T::EPSTS2: EPSTS17 Position       */
#define USBD_EPSTS2_EPSTS17_Msk          (0xful << USBD_EPSTS2_EPSTS17_Pos)                /*!< USBD_T::EPSTS2: EPSTS17 Mask           */

#define USBD_EPSTS2_EPSTS18_Pos          (8)                                               /*!< USBD_T::EPSTS2: EPSTS18 Position       */
#define USBD_EPSTS2_EPSTS18_Msk          (0xful << USBD_EPSTS2_EPSTS18_Pos)                /*!< USBD_T::EPSTS2: EPSTS18 Mask           */

#define USBD_EPSTS2_EPSTS19_Pos          (12)                                              /*!< USBD_T::EPSTS2: EPSTS19 Position       */
#define USBD_EPSTS2_EPSTS19_Msk          (0xful << USBD_EPSTS2_EPSTS19_Pos)                /*!< USBD_T::EPSTS2: EPSTS19 Mask           */

#define USBD_EPSTS2_EPSTS20_Pos          (16)                                              /*!< USBD_T::EPSTS2: EPSTS20 Position       */
#define USBD_EPSTS2_EPSTS20_Msk          (0xful << USBD_EPSTS2_EPSTS20_Pos)                /*!< USBD_T::EPSTS2: EPSTS20 Mask           */

#define USBD_EPSTS2_EPSTS21_Pos          (20)                                              /*!< USBD_T::EPSTS2: EPSTS21 Position       */
#define USBD_EPSTS2_EPSTS21_Msk          (0xful << USBD_EPSTS2_EPSTS21_Pos)                /*!< USBD_T::EPSTS2: EPSTS21 Mask           */

#define USBD_EPSTS2_EPSTS22_Pos          (24)                                              /*!< USBD_T::EPSTS2: EPSTS22 Position       */
#define USBD_EPSTS2_EPSTS22_Msk          (0xful << USBD_EPSTS2_EPSTS22_Pos)                /*!< USBD_T::EPSTS2: EPSTS22 Mask           */

#define USBD_EPSTS2_EPSTS23_Pos          (28)                                              /*!< USBD_T::EPSTS2: EPSTS23 Position       */
#define USBD_EPSTS2_EPSTS23_Msk          (0xful << USBD_EPSTS2_EPSTS23_Pos)                /*!< USBD_T::EPSTS2: EPSTS23 Mask           */

#define USBD_EPSTS3_EPSTS24_Pos          (0)                                               /*!< USBD_T::EPSTS3: EPSTS24 Position       */
#define USBD_EPSTS3_EPSTS24_Msk          (0xful << USBD_EPSTS3_EPSTS24_Pos)                /*!< USBD_T::EPSTS3: EPSTS24 Mask           */

#define USBD_EPINTSTS_EPEVT0_Pos         (0)                                               /*!< USBD_T::EPINTSTS: EPEVT0 Position      */
#define USBD_EPINTSTS_EPEVT0_Msk         (0x1ul << USBD_EPINTSTS_EPEVT0_Pos)               /*!< USBD_T::EPINTSTS: EPEVT0 Mask          */

#define USBD_EPINTSTS_EPEVT1_Pos         (1)                                               /*!< USBD_T::EPINTSTS: EPEVT1 Position      */
#define USBD_EPINTSTS_EPEVT1_Msk         (0x1ul << USBD_EPINTSTS_EPEVT1_Pos)               /*!< USBD_T::EPINTSTS: EPEVT1 Mask          */

#define USBD_EPINTSTS_EPEVT2_Pos         (2)                                               /*!< USBD_T::EPINTSTS: EPEVT2 Position      */
#define USBD_EPINTSTS_EPEVT2_Msk         (0x1ul << USBD_EPINTSTS_EPEVT2_Pos)               /*!< USBD_T::EPINTSTS: EPEVT2 Mask          */

#define USBD_EPINTSTS_EPEVT3_Pos         (3)                                               /*!< USBD_T::EPINTSTS: EPEVT3 Position      */
#define USBD_EPINTSTS_EPEVT3_Msk         (0x1ul << USBD_EPINTSTS_EPEVT3_Pos)               /*!< USBD_T::EPINTSTS: EPEVT3 Mask          */

#define USBD_EPINTSTS_EPEVT4_Pos         (4)                                               /*!< USBD_T::EPINTSTS: EPEVT4 Position      */
#define USBD_EPINTSTS_EPEVT4_Msk         (0x1ul << USBD_EPINTSTS_EPEVT4_Pos)               /*!< USBD_T::EPINTSTS: EPEVT4 Mask          */

#define USBD_EPINTSTS_EPEVT5_Pos         (5)                                               /*!< USBD_T::EPINTSTS: EPEVT5 Position      */
#define USBD_EPINTSTS_EPEVT5_Msk         (0x1ul << USBD_EPINTSTS_EPEVT5_Pos)               /*!< USBD_T::EPINTSTS: EPEVT5 Mask          */

#define USBD_EPINTSTS_EPEVT6_Pos         (6)                                               /*!< USBD_T::EPINTSTS: EPEVT6 Position      */
#define USBD_EPINTSTS_EPEVT6_Msk         (0x1ul << USBD_EPINTSTS_EPEVT6_Pos)               /*!< USBD_T::EPINTSTS: EPEVT6 Mask          */

#define USBD_EPINTSTS_EPEVT7_Pos         (7)                                               /*!< USBD_T::EPINTSTS: EPEVT7 Position      */
#define USBD_EPINTSTS_EPEVT7_Msk         (0x1ul << USBD_EPINTSTS_EPEVT7_Pos)               /*!< USBD_T::EPINTSTS: EPEVT7 Mask          */

#define USBD_EPINTSTS_EPEVT8_Pos         (8)                                               /*!< USBD_T::EPINTSTS: EPEVT8 Position      */
#define USBD_EPINTSTS_EPEVT8_Msk         (0x1ul << USBD_EPINTSTS_EPEVT8_Pos)               /*!< USBD_T::EPINTSTS: EPEVT8 Mask          */

#define USBD_EPINTSTS_EPEVT9_Pos         (9)                                               /*!< USBD_T::EPINTSTS: EPEVT9 Position      */
#define USBD_EPINTSTS_EPEVT9_Msk         (0x1ul << USBD_EPINTSTS_EPEVT9_Pos)               /*!< USBD_T::EPINTSTS: EPEVT9 Mask          */

#define USBD_EPINTSTS_EPEVT10_Pos        (10)                                              /*!< USBD_T::EPINTSTS: EPEVT10 Position     */
#define USBD_EPINTSTS_EPEVT10_Msk        (0x1ul << USBD_EPINTSTS_EPEVT10_Pos)              /*!< USBD_T::EPINTSTS: EPEVT10 Mask         */

#define USBD_EPINTSTS_EPEVT11_Pos        (11)                                              /*!< USBD_T::EPINTSTS: EPEVT11 Position     */
#define USBD_EPINTSTS_EPEVT11_Msk        (0x1ul << USBD_EPINTSTS_EPEVT11_Pos)              /*!< USBD_T::EPINTSTS: EPEVT11 Mask         */

#define USBD_EPINTSTS_EPEVT12_Pos        (12)                                              /*!< USBD_T::EPINTSTS: EPEVT12 Position     */
#define USBD_EPINTSTS_EPEVT12_Msk        (0x1ul << USBD_EPINTSTS_EPEVT12_Pos)              /*!< USBD_T::EPINTSTS: EPEVT12 Mask         */

#define USBD_EPINTSTS_EPEVT13_Pos        (13)                                              /*!< USBD_T::EPINTSTS: EPEVT13 Position     */
#define USBD_EPINTSTS_EPEVT13_Msk        (0x1ul << USBD_EPINTSTS_EPEVT13_Pos)              /*!< USBD_T::EPINTSTS: EPEVT13 Mask         */

#define USBD_EPINTSTS_EPEVT14_Pos        (14)                                              /*!< USBD_T::EPINTSTS: EPEVT14 Position     */
#define USBD_EPINTSTS_EPEVT14_Msk        (0x1ul << USBD_EPINTSTS_EPEVT14_Pos)              /*!< USBD_T::EPINTSTS: EPEVT14 Mask         */

#define USBD_EPINTSTS_EPEVT15_Pos        (15)                                              /*!< USBD_T::EPINTSTS: EPEVT15 Position     */
#define USBD_EPINTSTS_EPEVT15_Msk        (0x1ul << USBD_EPINTSTS_EPEVT15_Pos)              /*!< USBD_T::EPINTSTS: EPEVT15 Mask         */

#define USBD_EPINTSTS_EPEVT16_Pos        (16)                                              /*!< USBD_T::EPINTSTS: EPEVT16 Position     */
#define USBD_EPINTSTS_EPEVT16_Msk        (0x1ul << USBD_EPINTSTS_EPEVT16_Pos)              /*!< USBD_T::EPINTSTS: EPEVT16 Mask         */

#define USBD_EPINTSTS_EPEVT17_Pos        (17)                                              /*!< USBD_T::EPINTSTS: EPEVT17 Position     */
#define USBD_EPINTSTS_EPEVT17_Msk        (0x1ul << USBD_EPINTSTS_EPEVT17_Pos)              /*!< USBD_T::EPINTSTS: EPEVT17 Mask         */

#define USBD_EPINTSTS_EPEVT18_Pos        (18)                                              /*!< USBD_T::EPINTSTS: EPEVT18 Position     */
#define USBD_EPINTSTS_EPEVT18_Msk        (0x1ul << USBD_EPINTSTS_EPEVT18_Pos)              /*!< USBD_T::EPINTSTS: EPEVT18 Mask         */

#define USBD_EPINTSTS_EPEVT19_Pos        (19)                                              /*!< USBD_T::EPINTSTS: EPEVT19 Position     */
#define USBD_EPINTSTS_EPEVT19_Msk        (0x1ul << USBD_EPINTSTS_EPEVT19_Pos)              /*!< USBD_T::EPINTSTS: EPEVT19 Mask         */

#define USBD_EPINTSTS_EPEVT20_Pos        (20)                                              /*!< USBD_T::EPINTSTS: EPEVT20 Position     */
#define USBD_EPINTSTS_EPEVT20_Msk        (0x1ul << USBD_EPINTSTS_EPEVT20_Pos)              /*!< USBD_T::EPINTSTS: EPEVT20 Mask         */

#define USBD_EPINTSTS_EPEVT21_Pos        (21)                                              /*!< USBD_T::EPINTSTS: EPEVT21 Position     */
#define USBD_EPINTSTS_EPEVT21_Msk        (0x1ul << USBD_EPINTSTS_EPEVT21_Pos)              /*!< USBD_T::EPINTSTS: EPEVT21 Mask         */

#define USBD_EPINTSTS_EPEVT22_Pos        (22)                                              /*!< USBD_T::EPINTSTS: EPEVT22 Position     */
#define USBD_EPINTSTS_EPEVT22_Msk        (0x1ul << USBD_EPINTSTS_EPEVT22_Pos)              /*!< USBD_T::EPINTSTS: EPEVT22 Mask         */

#define USBD_EPINTSTS_EPEVT23_Pos        (23)                                              /*!< USBD_T::EPINTSTS: EPEVT23 Position     */
#define USBD_EPINTSTS_EPEVT23_Msk        (0x1ul << USBD_EPINTSTS_EPEVT23_Pos)              /*!< USBD_T::EPINTSTS: EPEVT23 Mask         */

#define USBD_EPINTSTS_EPEVT24_Pos        (24)                                              /*!< USBD_T::EPINTSTS: EPEVT24 Position     */
#define USBD_EPINTSTS_EPEVT24_Msk        (0x1ul << USBD_EPINTSTS_EPEVT24_Pos)              /*!< USBD_T::EPINTSTS: EPEVT24 Mask         */

#define USBD_LPMATTR_LPMLINKSTS_Pos      (0)                                               /*!< USBD_T::LPMATTR: LPMLINKSTS Position   */
#define USBD_LPMATTR_LPMLINKSTS_Msk      (0xful << USBD_LPMATTR_LPMLINKSTS_Pos)            /*!< USBD_T::LPMATTR: LPMLINKSTS Mask       */

#define USBD_LPMATTR_LPMBESL_Pos         (4)                                               /*!< USBD_T::LPMATTR: LPMBESL Position      */
#define USBD_LPMATTR_LPMBESL_Msk         (0xful << USBD_LPMATTR_LPMBESL_Pos)               /*!< USBD_T::LPMATTR: LPMBESL Mask          */

#define USBD_LPMATTR_LPMRWAKUP_Pos       (8)                                               /*!< USBD_T::LPMATTR: LPMRWAKUP Position    */
#define USBD_LPMATTR_LPMRWAKUP_Msk       (0x1ul << USBD_LPMATTR_LPMRWAKUP_Pos)             /*!< USBD_T::LPMATTR: LPMRWAKUP Mask        */

#define USBD_FN_FN_Pos                   (0)                                               /*!< USBD_T::FN: FN Position                */
#define USBD_FN_FN_Msk                   (0x7fful << USBD_FN_FN_Pos)                       /*!< USBD_T::FN: FN Mask                    */

#define USBD_SE0_SE0_Pos                 (0)                                               /*!< USBD_T::SE0: SE0 Position              */
#define USBD_SE0_SE0_Msk                 (0x1ul << USBD_SE0_SE0_Pos)                       /*!< USBD_T::SE0: SE0 Mask                  */

#define USBD_BUFSEG_BUFSEG_Pos           (3)                                               /*!< USBD_EP_T::BUFSEG: BUFSEG Position     */
#define USBD_BUFSEG_BUFSEG_Msk           (0xfful << USBD_BUFSEG_BUFSEG_Pos)                /*!< USBD_EP_T::BUFSEG: BUFSEG Mask         */

#define USBD_MXPLD_MXPLD_Pos             (0)                                               /*!< USBD_EP_T::MXPLD: MXPLD Position       */
#define USBD_MXPLD_MXPLD_Msk             (0x7fful << USBD_MXPLD_MXPLD_Pos)                 /*!< USBD_EP_T::MXPLD: MXPLD Mask           */

#define USBD_CFG_EPNUM_Pos               (0)                                               /*!< USBD_EP_T::CFG: EPNUM Position         */
#define USBD_CFG_EPNUM_Msk               (0xful << USBD_CFG_EPNUM_Pos)                     /*!< USBD_EP_T::CFG: EPNUM Mask             */

#define USBD_CFG_ISOCH_Pos               (4)                                               /*!< USBD_EP_T::CFG: ISOCH Position         */
#define USBD_CFG_ISOCH_Msk               (0x1ul << USBD_CFG_ISOCH_Pos)                     /*!< USBD_EP_T::CFG: ISOCH Mask             */

#define USBD_CFG_STATE_Pos               (5)                                               /*!< USBD_EP_T::CFG: STATE Position         */
#define USBD_CFG_STATE_Msk               (0x3ul << USBD_CFG_STATE_Pos)                     /*!< USBD_EP_T::CFG: STATE Mask             */

#define USBD_CFG_DSQSYNC_Pos             (7)                                               /*!< USBD_EP_T::CFG: DSQSYNC Position       */
#define USBD_CFG_DSQSYNC_Msk             (0x1ul << USBD_CFG_DSQSYNC_Pos)                   /*!< USBD_EP_T::CFG: DSQSYNC Mask           */

#define USBD_CFG_CSTALL_Pos              (9)                                               /*!< USBD_EP_T::CFG: CSTALL Position        */
#define USBD_CFG_CSTALL_Msk              (0x1ul << USBD_CFG_CSTALL_Pos)                    /*!< USBD_EP_T::CFG: CSTALL Mask            */

#define USBD_CFG_DBTGACTIVE_Pos          (10)                                              /*!< USBD_EP_T::CFG: DBTGACTIVE Position    */
#define USBD_CFG_DBTGACTIVE_Msk          (0x1ul << USBD_CFG_DBTGACTIVE_Pos)                /*!< USBD_EP_T::CFG: DBTGACTIVE Mask        */

#define USBD_CFG_DBEN_Pos                (11)                                              /*!< USBD_EP_T::CFG: DBEN Position          */
#define USBD_CFG_DBEN_Msk                (0x1ul << USBD_CFG_DBEN_Pos)                      /*!< USBD_EP_T::CFG: DBEN Mask              */

#define USBD_CFGP_CLRRDY_Pos             (0)                                               /*!< USBD_EP_T::CFGP: CLRRDY Position       */
#define USBD_CFGP_CLRRDY_Msk             (0x1ul << USBD_CFGP_CLRRDY_Pos)                   /*!< USBD_EP_T::CFGP: CLRRDY Mask           */

#define USBD_CFGP_SSTALL_Pos             (1)                                               /*!< USBD_EP_T::CFGP: SSTALL Position       */
#define USBD_CFGP_SSTALL_Msk             (0x1ul << USBD_CFGP_SSTALL_Pos)                   /*!< USBD_EP_T::CFGP: SSTALL Mask           */

/** @} USBD_CONST */
/** @} end of USBD register group */
/** @} end of REGISTER group */

#if defined ( __CC_ARM   )
    #pragma no_anon_unions
#endif

#endif /* __USBD_REG_H__ */
