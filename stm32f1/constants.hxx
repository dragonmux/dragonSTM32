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
		constexpr static size_t endpoints{8U};

		// Device address register constants
		constexpr static uint32_t addressMask{0x0000007fU};
		constexpr static uint32_t addressClrMask{0xffffff00U};
		constexpr static uint32_t addressUSBEnable{0x00000080U};

		// Control register constants
		constexpr static uint32_t controlMask{0xffff00e0U};
		constexpr static uint32_t controlItrMask{0xffff00ffU};
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
		constexpr static uint32_t itrStatusCorrectXfer{0x00008000U};

		// Endpoint register constants
		constexpr static uint32_t epClearMask{0xffff0000U};
		constexpr static uint32_t epAddressMask{0x0000000fU};
		constexpr static uint32_t epCtrlTXDisabled{0x00000000U};
		constexpr static uint32_t epCtrlTXStall{0x00000010U};
		constexpr static uint32_t epCtrlTXNack{0x00000020U};
		constexpr static uint32_t epCtrlTXValid{0x00000030U};
		constexpr static uint32_t epTxDataToggle{0x00000040U};
		constexpr static uint32_t epStatusTxCorrectXfer{0x00000080U};
		constexpr static uint32_t epCtrlKindStatusOut{0x00000100U};
		constexpr static uint32_t epCtrlKindDoubleBuffered{0x00000100U};
		constexpr static uint32_t epCtrlTypeBulk{0x00000000U};
		constexpr static uint32_t epCtrlTypeControl{0x00000200U};
		constexpr static uint32_t epCtrlTypeIsochronous{0x00000400U};
		constexpr static uint32_t epCtrlTypeInterrupt{0x00000600U};
		constexpr static uint32_t epStatusSetup{0x00000800U};
		constexpr static uint32_t epCtrlRXDisabled{0x00000000U};
		constexpr static uint32_t epCtrlRXStall{0x00001000U};
		constexpr static uint32_t epCtrlRXNack{0x00002000U};
		constexpr static uint32_t epCtrlRXValid{0x00003000U};
		constexpr static uint32_t epRxDataToggle{0x00004000U};
		constexpr static uint32_t epStatusRxCorrectXfer{0x00008000U};
		constexpr static uint32_t epCtrlTXMask{0xffffff0fU};
		constexpr static uint32_t epCtrlRXMask{0xffff0fffU};
		constexpr static uint32_t epCtrlTypeMask{0xfffff9ffU};

		// Recieve Endpoint Byte Count register constants
		constexpr static uint32_t rxCountBlockSize2{0x00000000U};
		constexpr static uint32_t rxCountBlockSize32{0x00008000U};
		constexpr static uint32_t rxCountBlockCountMask{0x00007c00U};
		constexpr static uint32_t rxCountByteMask{0x000001ffU};
		constexpr static size_t rxCountBlockCountShift{10U};

		constexpr inline uint32_t epAddress(const size_t address) noexcept
			{ return address & epAddressMask; }

		// NB: This assumes the buffer size is a power of two, more than 1 and less than 1024
		constexpr inline uint32_t rxBufferSize(const size_t bufferLength) noexcept
		{
			if (bufferLength < 64U)
			{
				// Divide the length by 2 then shift it up into place
				const uint32_t blockCount = (bufferLength >> 1U) << rxCountBlockCountShift;
				return rxCountBlockSize2 | (blockCount & rxCountBlockCountMask);
			}
			// Divide the length by 32 then shift it up into place
			const uint32_t blockCount = (bufferLength >> 5U) << rxCountBlockCountShift;
			return rxCountBlockSize32 | (blockCount & rxCountBlockCountMask);
		}
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

		constexpr inline void clear(stm32::gpio_t &gpio, gpio_t pinNumber)
			{ gpio.pinReset = UINT32_C(1) << static_cast<uint8_t>(pinNumber); }
		constexpr inline void set(stm32::gpio_t &gpio, gpio_t pinNumber)
			{ gpio.pinSetReset = UINT32_C(1) << static_cast<uint8_t>(pinNumber); }
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

	namespace irqs
	{
		constexpr static uint32_t windowWatchdog{0U};
		constexpr static uint32_t programmableVoltageDetector{1U};
		constexpr static uint32_t tamper{2U};
		constexpr static uint32_t rtc{3U};
		constexpr static uint32_t flash{4U};
		constexpr static uint32_t rcc{5U};
		constexpr static uint32_t exti0{6U};
		constexpr static uint32_t exti1{7U};
		constexpr static uint32_t exti2{8U};
		constexpr static uint32_t exti3{9U};
		constexpr static uint32_t exti4{10U};
		constexpr static uint32_t dma1Channel1{11U};
		constexpr static uint32_t dma1Channel2{12U};
		constexpr static uint32_t dma1Channel3{13U};
		constexpr static uint32_t dma1Channel4{14U};
		constexpr static uint32_t dma1Channel5{15U};
		constexpr static uint32_t dma1Channel6{16U};
		constexpr static uint32_t dma1Channel7{17U};
		constexpr static uint32_t adc1And2{18U};
		constexpr static uint32_t usbHighPriority{19U};
		constexpr static uint32_t canTX{19U};
		constexpr static uint32_t usbLowPriority{20U};
		constexpr static uint32_t canRX0{20U};
		constexpr static uint32_t canRX1{21U};
		constexpr static uint32_t canSCE{22U};
		constexpr static uint32_t exti5Through9{23U};
		constexpr static uint32_t timer1Break{24U};
		constexpr static uint32_t timer1Update{25U};
		constexpr static uint32_t timer1TriggerComm{26U};
		constexpr static uint32_t timer1CaptureCompare{27U};
		constexpr static uint32_t timer2{28U};
		constexpr static uint32_t timer3{29U};
		constexpr static uint32_t timer4{30U};
		constexpr static uint32_t i2c1Event{31U};
		constexpr static uint32_t i2c1Error{32U};
		constexpr static uint32_t i2c2Event{33U};
		constexpr static uint32_t i2c2Error{34U};
		constexpr static uint32_t spi1{35U};
		constexpr static uint32_t spi2{36U};
		constexpr static uint32_t usart1{37U};
		constexpr static uint32_t usart2{38U};
		constexpr static uint32_t usart3{39U};
		constexpr static uint32_t exti10Through15{40U};
		constexpr static uint32_t rtcAlarm{41U};
		constexpr static uint32_t usbWakeup{42U};
		constexpr static uint32_t timer8Break{43U};
		constexpr static uint32_t timer8Update{44U};
		constexpr static uint32_t timer8TriggerComm{45U};
		constexpr static uint32_t timer8CaptureCompare{46U};
		constexpr static uint32_t adc3{47U};
		constexpr static uint32_t fsmc{48U};
		constexpr static uint32_t sdio{49U};
		constexpr static uint32_t timer5{50U};
		constexpr static uint32_t spi3{51U};
		constexpr static uint32_t uart4{52U};
		constexpr static uint32_t uart5{53U};
		constexpr static uint32_t timer6{54U};
		constexpr static uint32_t timer7{55U};
		constexpr static uint32_t dma2Channel1{56U};
		constexpr static uint32_t dma2Channel2{57U};
		constexpr static uint32_t dma2Channel3{58U};
		constexpr static uint32_t dma2Channel4And5{29U};
	} // namespace irqs
} // namespace vals

namespace stm32
{
	using usbEPTable_t = std::array<usbEP_t, vals::usb::endpoints>;
} // namespace stm32

#endif /*STM32F1_CONSTANTS_HXX*/
