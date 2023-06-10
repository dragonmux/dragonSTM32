// SPDX-License-Identifier: BSD-3-Clause
#ifndef STM32F1_CONSTANTS_HXX
#define STM32F1_CONSTANTS_HXX

#include <cstdint>
#include "stm32f1/platform.hxx"

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

		// Control register constants
		constexpr static uint32_t controlMask{0xffff00e0U};
		constexpr static uint32_t controlForceReset{0x00000001U};
		constexpr static uint32_t controlPowerDown{0x00000002U};
		constexpr static uint32_t controlLowPowerMode{0x00000004U};
		constexpr static uint32_t controlForceSuspend{0x00000008U};
		constexpr static uint32_t controlResume{0x00000010U};
		constexpr static uint32_t controlExpectedSOFItrEn{0x00000100U};
		constexpr static uint32_t controlSOFItrEn{0x00000200U};
		constexpr static uint32_t controlResetItrEn{0x00000400U};
		constexpr static uint32_t controlSuspendItrEn{0x00000800U};
		constexpr static uint32_t controlWakeupItrEn{0x00001000U};
		constexpr static uint32_t controlErrorItrEn{0x00002000U};
		constexpr static uint32_t controlPacketMemItrEn{0x00004000U};
		constexpr static uint32_t controlCorrectXferItrEn{0x00008000U};

		// Interrupt Status register constants
		constexpr static uint32_t itrStatusClearMask{0xffff00e0U};
		constexpr static uint32_t itrStatusMask{0x0000ff1fU};
		constexpr static uint32_t itrStatusEndpoint{0x0000001fU};
		constexpr static uint32_t itrStatusExpectedSOF{0x00000100U};
		constexpr static uint32_t itrStatusSOF{0x00000200U};
		constexpr static uint32_t itrStatusReset{0x00000400U};
		constexpr static uint32_t itrStatusSuspend{0x00000800U};
		constexpr static uint32_t itrStatusWakeup{0x00001000U};
		constexpr static uint32_t itrStatusError{0x00002000U};
		constexpr static uint32_t itrStatusPacketMem{0x00004000U};
		constexpr static uint32_t itrStatusCorrextXfer{0x00008000U};
	} // namespace usb

	enum class gpio_t : uint8_t
	{
		pin0 = 0,
		pin1 = 1,
		pin2 = 2,
		pin3 = 3,
		pin4 = 4,
		pin5 = 5,
		pin6 = 6,
		pin7 = 7,
		pin8 = 8,
		pin9 = 9,
		pin10 = 10,
		pin11 = 11,
		pin12 = 12,
		pin13 = 13,
		pin14 = 14,
		pin15 = 15,
	};

	namespace gpio
	{
		enum class mode_t : uint8_t
		{
			input = 0U,
			output10MHz = 1U,
			output2MHz = 2U,
			output50MHz = 3U
		};

		enum class config_t : uint8_t
		{
			inputAnalog = 0U,
			inputFloating = 1U,
			inputPullUpDown = 2U,
			outputNormalPushPull = 3U,
			outputNormalOpenDrain = 4U,
			outputAltFnPushPull = 8U,
			outputAltOpenDrain = 12U
		};

		namespace internal
		{
			constexpr inline uint32_t config(const config_t pinConfig)
			{
				const auto value{static_cast<uint8_t>(pinConfig)};
				if (value < static_cast<uint8_t>(config_t::outputNormalPushPull))
					return value << 2U;
				if (value > static_cast<uint8_t>(config_t::outputNormalPushPull))
					return value;
				return 0U;
			}
		} // namespace internal

		template<gpio_t pinNumber> constexpr inline void config(stm32::gpio_t &gpio, const mode_t pinMode,
			const config_t pinConfig)
		{
			constexpr size_t index = (static_cast<uint8_t>(pinNumber) >> 3U) & 1U;
			constexpr uint8_t shift = (static_cast<uint8_t>(pinNumber) & 7U) * 4U;
			constexpr uint32_t configMask = ~((0x0000000fU) << shift);
			gpio.config[index] = (gpio.config[index] & configMask) | (static_cast<uint32_t>(pinMode) << shift) |
				(internal::config(pinConfig) << shift);
		}
	} // namespace gpio

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
