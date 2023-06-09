// SPDX-License-Identifier: BSD-3-Clause
#ifndef STM32F1_CONSTANTS_HXX
#define STM32F1_CONSTANTS_HXX

#include <cstdint>

namespace vals
{
	namespace usb
	{
		enum class endpointDir_t : uint8_t
		{
			controllerOut = 0x00U,
			controllerIn = 0x80U
		};

		constexpr static uint8_t endpointDirMask{0x7fU};
		constexpr inline uint8_t endpoint(const endpointDir_t dir, const uint8_t number) noexcept
			{ return uint8_t(dir) | (number & endpointDirMask); }

		// Device address register constants
		constexpr static uint32_t addressMask{0x0000007fU};
		constexpr static uint32_t addressClrMask{0xffffff00U};
		constexpr static uint32_t addressUSBEnable{0x00000080U};
	} // namespace usb

	namespace rcc
	{
		// APB2 Peripheral Clock Enable register constants
		constexpr static uint32_t apb2PeriphClockEnAltFnIO{0x00000001U};
		constexpr static uint32_t apb2PeriphClockEnGPIOPortA{0x00000004U};
		constexpr static uint32_t apb2PeriphClockEnGPIOPortB{0x00000008U};
		constexpr static uint32_t apb2PeriphClockEnGPIOPortC{0x00000010U};
		constexpr static uint32_t apb2PeriphClockEnGPIOPortD{0x00000020U};
		constexpr static uint32_t apb2PeriphClockEnGPIOPortE{0x00000040U};
		constexpr static uint32_t apb2PeriphClockEnGPIOPortF{0x00000080U};
		constexpr static uint32_t apb2PeriphClockEnGPIOPortG{0x00000100U};
		constexpr static uint32_t apb2PeriphClockEnADC1{0x00000200U};
		constexpr static uint32_t apb2PeriphClockEnADC2{0x00000400U};
		constexpr static uint32_t apb2PeriphClockEnTimer1{0x00000800U};
		constexpr static uint32_t apb2PeriphClockEnSPI1{0x00001000U};
		constexpr static uint32_t apb2PeriphClockEnTimer8{0x00002000U};
		constexpr static uint32_t apb2PeriphClockEnUSART1{0x00004000U};
		constexpr static uint32_t apb2PeriphClockEnADC3{0x00008000U};
		constexpr static uint32_t apb2PeriphClockEnTimer9{0x00080000U};
		constexpr static uint32_t apb2PeriphClockEnTimer10{0x00100000U};
		constexpr static uint32_t apb2PeriphClockEnTimer11{0x00200000U};

		// APB1 Peripheral Clock Enable register constants
		constexpr static uint32_t apb1PeriphClockEnTimer2{0x00000001U};
		constexpr static uint32_t apb1PeriphClockEnTimer3{0x00000002U};
		constexpr static uint32_t apb1PeriphClockEnTimer4{0x00000004U};
		constexpr static uint32_t apb1PeriphClockEnTimer5{0x00000008U};
		constexpr static uint32_t apb1PeriphClockEnTimer6{0x00000010U};
		constexpr static uint32_t apb1PeriphClockEnTimer7{0x00000020U};
		constexpr static uint32_t apb1PeriphClockEnTimer12{0x00000040U};
		constexpr static uint32_t apb1PeriphClockEnTimer13{0x00000080U};
		constexpr static uint32_t apb1PeriphClockEnTimer14{0x00000100U};
		constexpr static uint32_t apb1PeriphClockEnWindowWDT{0x00000800U};
		constexpr static uint32_t apb1PeriphClockEnSPI2{0x00004000U};
		constexpr static uint32_t apb1PeriphClockEnSPI3{0x00008000U};
		constexpr static uint32_t apb1PeriphClockEnUSART2{0x00020000U};
		constexpr static uint32_t apb1PeriphClockEnUSART3{0x00040000U};
		constexpr static uint32_t apb1PeriphClockEnUART4{0x00080000U};
		constexpr static uint32_t apb1PeriphClockEnUART5{0x00100000U};
		constexpr static uint32_t apb1PeriphClockEnI2C1{0x00200000U};
		constexpr static uint32_t apb1PeriphClockEnI2C2{0x00400000U};
		constexpr static uint32_t apb1PeriphClockEnUSB{0x00800000U};
		constexpr static uint32_t apb1PeriphClockEnCAN{0x02000000U};
		constexpr static uint32_t apb1PeriphClockEnBackup{0x08000000U};
		constexpr static uint32_t apb1PeriphClockEnPower{0x10000000U};
		constexpr static uint32_t apb1PeriphClockEnDAC{0x20000000U};
	} // namespace rcc
} // namespace vals

#endif /*STM32F1_CONSTANTS_HXX*/
