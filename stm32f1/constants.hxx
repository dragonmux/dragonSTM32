// SPDX-License-Identifier: BSD-3-Clause
#ifndef STM32F1_CONSTANTS_HXX
#define STM32F1_CONSTANTS_HXX

#include <cstdint>
#include <cstring>
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
		constexpr static uint32_t epTXDataToggle{0x00000040U};
		constexpr static uint32_t epStatusTXCorrectXfer{0x00000080U};
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
		constexpr static uint32_t epRXDataToggle{0x00004000U};
		constexpr static uint32_t epStatusRXCorrectXfer{0x00008000U};
		constexpr static uint32_t epCtrlTypeMask{0xfffff9ffU};
		constexpr static uint32_t epStatusXORMaskTX{0x00000030U};
		constexpr static uint32_t epStatusXORMaskRX{0x00003000U};
		constexpr static uint32_t epCtrlTXMask{0xffffff0fU};
		constexpr static uint32_t epCtrlRXMask{0xffff0fffU};
		constexpr static uint32_t epCtrlKeepMask{0xffff070fU};
		constexpr static uint32_t epCtrlCorrectXferMask{0x00008080U};

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

		static inline void epCtrlStatusSetType(const size_t endpoint, const uint32_t epType) noexcept
		{
			const uint32_t value{usbCtrl.epCtrlStat[endpoint]};
			usbCtrl.epCtrlStat[endpoint] = (value & (epCtrlKeepMask & epCtrlTypeMask)) |
				epCtrlCorrectXferMask | epType;
		}

		static inline void epCtrlStatusUpdateTX(const size_t endpoint, const uint16_t newValue) noexcept
		{
			// Grab the current value of the register
			const uint32_t oldValue{usbCtrl.epCtrlStat[endpoint]};
			// Calculate the XOR bits value
			const auto xorValue{(oldValue ^ newValue) & epStatusXORMaskTX};
			// Grab the bits to be kept as-is
			const auto keepValue{oldValue & epCtrlKeepMask};
			// Compute new correct transfer values
			const auto xferValue{(newValue & epStatusTXCorrectXfer) | epStatusRXCorrectXfer};
			// Put it all together and write it back
			usbCtrl.epCtrlStat[endpoint] = xorValue | keepValue | xferValue;
		}

		static inline void epCtrlStatusUpdateRX(const size_t endpoint, const uint16_t newValue) noexcept
		{
			// Grab the current value of the register
			const uint32_t oldValue{usbCtrl.epCtrlStat[endpoint]};
			// Calculate the XOR bits value
			const auto xorValue{(oldValue ^ newValue) & epStatusXORMaskRX};
			// Grab the bits to be kept as-is
			const auto keepValue{oldValue & epCtrlKeepMask};
			// Compute new correct transfer values
			const auto xferValue{(newValue & epStatusRXCorrectXfer) | epStatusTXCorrectXfer};
			// Put it all together and write it back
			usbCtrl.epCtrlStat[endpoint] = xorValue | keepValue | xferValue;
		}

		static inline void epCtrlSetDataToggleTX(const size_t endpoint, const bool value) noexcept
		{
			// Grab the old value
			const uint32_t oldValue{usbCtrl.epCtrlStat[endpoint]};
			// Figure out the value we want the toggle bit
			const uint32_t toggleValue{value ? epTXDataToggle : 0U};
			// Figure out the XOR bit state accordingly
			const auto xorValue{(oldValue & epTXDataToggle) ^ toggleValue};
			// Grab the bits to be kept as-is
			const auto keepValue{oldValue & epCtrlKeepMask};
			// Put it all together and write it back
			usbCtrl.epCtrlStat[endpoint] = xorValue | keepValue | epCtrlCorrectXferMask;
		}

		static inline void epCtrlSetDataToggleRX(const size_t endpoint, const bool value) noexcept
		{
			// Grab the old value
			const uint32_t oldValue{usbCtrl.epCtrlStat[endpoint]};
			// Figure out the value we want the toggle bit
			const uint32_t toggleValue{value ? epRXDataToggle : 0U};
			// Figure out the XOR bit state accordingly
			const auto xorValue{(oldValue & epRXDataToggle) ^ toggleValue};
			// Grab the bits to be kept as-is
			const auto keepValue{oldValue & epCtrlKeepMask};
			// Put it all together and write it back
			usbCtrl.epCtrlStat[endpoint] = xorValue | keepValue | epCtrlCorrectXferMask;
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
			constexpr inline uint32_t config(const config_t pinConfig) noexcept
			{
				const auto value{static_cast<uint8_t>(pinConfig)};
				if (value < static_cast<uint8_t>(config_t::outputNormalPushPull))
					return value << 2U;
				if (value > static_cast<uint8_t>(config_t::outputNormalPushPull))
					return value;
				return 0U;
			}
		} // namespace internal

		template<gpio_t pinNumber> static inline void config(stm32::gpio_t &gpio, const mode_t pinMode,
			const config_t pinConfig) noexcept
		{
			constexpr size_t index{(static_cast<uint8_t>(pinNumber) >> 3U) & 1U};
			constexpr auto shift{(static_cast<uint8_t>(pinNumber) & 7U) * 4U};
			constexpr auto configMask{~(0x0000000fU << shift)};
			gpio.config[index] = (gpio.config[index] & configMask) | (static_cast<uint32_t>(pinMode) << shift) |
				(internal::config(pinConfig) << shift);
		}

		static inline void clear(stm32::gpio_t &gpio, const gpio_t pinNumber) noexcept
			{ gpio.pinReset = UINT32_C(1) << static_cast<uint8_t>(pinNumber); }
		static inline void set(stm32::gpio_t &gpio, const gpio_t pinNumber) noexcept
			{ gpio.pinSetReset = UINT32_C(1) << static_cast<uint8_t>(pinNumber); }

		static inline bool value(const stm32::gpio_t &gpio, const gpio_t pinNumber) noexcept
		{
			uint32_t value{};
			std::memcpy(&value, const_cast<const uint32_t *>(&gpio.dataIn), sizeof(uint32_t));
			return value & (UINT32_C(1) << static_cast<uint8_t>(pinNumber));
		}
	} // namespace gpio

	namespace rcc
	{
		// Clock Control register constants
		constexpr static uint32_t clockCtrlHSIEnable{0x00000001U};
		constexpr static uint32_t clockCtrlHSIReady{0x00000002U};
		constexpr static uint32_t clockCtrlHSEEnable{0x00010000U};
		constexpr static uint32_t clockCtrlHSEReady{0x00020000U};
		constexpr static uint32_t clockCtrlPLLEnable{0x01000000U};
		constexpr static uint32_t clockCtrlPLLReady{0x02000000U};

		// Clock Configuration register constants
		constexpr static uint32_t clockConfigSourceHSI{0x00000000U};
		constexpr static uint32_t clockConfigSourceHSE{0x00000001U};
		constexpr static uint32_t clockConfigSourcePLL{0x00000002U};
		constexpr static uint32_t clockConfigSourceMask{0x00000003U};
		constexpr static uint32_t clockConfigStatusHSI{0x00000000U};
		constexpr static uint32_t clockConfigStatusHSE{0x00000004U};
		constexpr static uint32_t clockConfigStatusPLL{0x00000008U};
		constexpr static uint32_t clockConfigStatusMask{0x0000000cU};
		constexpr static uint32_t clockConfigAHBPrescaleMask{0x000000f0U};
		constexpr static uint32_t clockConfigAPB1PrescaleMask{0x00000700U};
		constexpr static uint32_t clockConfigAPB2PrescaleMask{0x00003800U};
		constexpr static uint32_t clockConfigADCPrescaleMask{0x0000c000U};
		constexpr static uint32_t clockConfigPLLSourceHSI{0x00000000U};
		constexpr static uint32_t clockConfigPLLSourceHSE{0x00010000U};
		constexpr static uint32_t clockConfigPLLSourceMask{0x00010000U};
		constexpr static uint32_t clockConfigPLLPrescaleMask{0x00020000U};
		constexpr static uint32_t clockConfigPLLMultiplierMask{0x003c0000U};
		constexpr static uint32_t clockConfigUSBPrescaleMask{0x00400000U};
		constexpr static uint32_t clockConfigOutputNone{0x00000000U};
		constexpr static uint32_t clockConfigOutputSysClock{0x04000000U};
		constexpr static uint32_t clockConfigOutputHSI{0x05000000U};
		constexpr static uint32_t clockConfigOutputHSE{0x06000000U};
		constexpr static uint32_t clockConfigOutputPLL{0x07000000U};
		constexpr static uint32_t clockConfigOutputMask{0x07000000U};

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

		// Control/Status register constants
		constexpr static uint32_t ctrlStatusIntLowSpeedOscEn{0x00000001U};
		constexpr static uint32_t ctrlStatusIntLowSpeedOscReady{0x00000002U};
		constexpr static uint32_t ctrlStatusClearResetCause{0x01000000U};
		constexpr static uint32_t ctrlStatusResetCauseNRST{0x04000000U};
		constexpr static uint32_t ctrlStatusResetCausePOR{0x08000000U};
		constexpr static uint32_t ctrlStatusResetCauseSoftware{0x10000000U};
		constexpr static uint32_t ctrlStatusResetCauseIndepWDT{0x20000000U};
		constexpr static uint32_t ctrlStatusResetCauseWindowWDT{0x40000000U};
		constexpr static uint32_t ctrlStatusResetCauseLowPower{0x80000000U};

		constexpr inline uint32_t clockConfigAHBPrescale(const uint16_t prescale)
		{
			return [&]() -> uint32_t
			{
				if (prescale < 2U)
					return 0U;
				if (prescale < 4U)
					return 8U;
				if (prescale < 8U)
					return 9U;
				if (prescale < 16U)
					return 10U;
				if (prescale < 64U)
					return 11U;
				if (prescale < 128U)
					return 12U;
				if (prescale < 256U)
					return 13U;
				if (prescale < 512U)
					return 14U;
				return 15U;
			}() << 4U;
		}

		constexpr inline uint32_t clockConfigAPB1Prescale(const uint8_t prescale)
		{
			return [&]() -> uint32_t
			{
				if (prescale < 2U)
					return 0U;
				if (prescale < 4U)
					return 4U;
				if (prescale < 8U)
					return 5U;
				if (prescale < 16U)
					return 6U;
				return 7U;
			}() << 8U;
		}

		constexpr inline uint32_t clockConfigAPB2Prescale(const uint8_t prescale)
		{
			return [&]() -> uint32_t
			{
				if (prescale < 2U)
					return 0U;
				if (prescale < 4U)
					return 4U;
				if (prescale < 8U)
					return 5U;
				if (prescale < 16U)
					return 6U;
				return 7U;
			}() << 11U;
		}

		constexpr inline uint32_t clockConfigADCPrescale(const uint8_t prescale)
		{
			return [&]() -> uint32_t
			{
				if (prescale < 4U)
					return 0U;
				if (prescale < 6U)
					return 1U;
				if (prescale < 8U)
					return 2U;
				return 3U;
			}() << 14U;
		}

		constexpr inline uint32_t clockConfigPLLPrescale(const uint8_t prescale)
		{
			return [&]() -> uint32_t
			{
				if (prescale < 2)
					return 0;
				return 1;
			}() << 16U;
		}

		constexpr inline uint32_t clockConfigPLLMultiplier(const uint8_t multiplier)
		{
			return [](int value) -> uint32_t
			{
				if (value < 0)
					return 0U;
				if (value > 14)
					return 14U;
				return uint32_t(value);
			}(multiplier - 2) << 18U;
		}
	} // namespace rcc

	namespace flash
	{
		constexpr static uint32_t accessCtrlLatencyMask{0x00000007U};
		constexpr static uint32_t accessCtrlHalfCycleAccess{0x00000008U};
		constexpr static uint32_t accessCtrlPrefetchBufferEnable{0x00000010U};
		constexpr static uint32_t accessCtrlPrefetchBufferStatus{0x00000020U};

		constexpr static uint16_t readUnprotectKey{0x00a5};
		constexpr static uint32_t unlockKey1{0x45670123U};
		constexpr static uint32_t unlockKey2{0xcdef89abU};

		constexpr static uint32_t statusBusy{0x00000001U};
		constexpr static uint32_t statusProgError{0x00000004U};
		constexpr static uint32_t statusWriteProtError{0x00000010U};
		constexpr static uint32_t statusEndOfOperation{0x00000020U};
		constexpr static uint32_t statusErrorMask{0x00000014U};

		constexpr static uint32_t controlProgram{0x00000001U};
		constexpr static uint32_t controlPageErase{0x00000002U};
		constexpr static uint32_t controlMassErase{0x00000004U};
		constexpr static uint32_t controlOptByteProgram{0x00000010U};
		constexpr static uint32_t controlOptByteErase{0x00000020U};
		constexpr static uint32_t controlStartErase{0x00000040U};
		constexpr static uint32_t controlLock{0x00000080U};
		constexpr static uint32_t controlOptByteItrEnable{0x00000200U};
		constexpr static uint32_t controlErrorItrEnable{0x00000400U};
		constexpr static uint32_t controlEndOfOpItrEnable{0x00001000U};

		constexpr static std::uintptr_t bankSplit{0x08080000U};

		constexpr inline uint32_t acccesCtrlLatency(uint8_t latency) noexcept
			{ return latency & accessCtrlLatencyMask; }
	} // namespace flash

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
		constexpr static uint32_t dma2Channel4And5{59U};

		constexpr static size_t systemIRQs{15U};
		constexpr static size_t peripheralIRQs{60U};
	} // namespace irqs

	namespace scb
	{
		constexpr static const uint32_t apintKey{0x05FA0000};
		constexpr static const uint32_t apintSystemResetRequest{0x00000004};
	} // namespace scb

	namespace dcb
	{
		constexpr static const uint32_t exceptMonitorCtrlEnableTrace{0x01000000U};
	} // namespace dcb

	namespace itm
	{
		// "Stimulus Port" (channel) register read-back constants
		constexpr static const uint32_t channelReady{0x00000001U};

		// Trace enable register constants
		constexpr static inline uint32_t enableChannel(const uint8_t channel) noexcept
			{ return 1U << channel; }

		// Trace control register constants
		constexpr static const uint32_t traceCtrlEnableITM{0x00000001U};
		constexpr static const uint32_t traceCtrlDisableITM{0x00000000U};
		constexpr static const uint32_t traceCtrlEnableLocalTimestamp{0x00000002U};
		constexpr static const uint32_t traceCtrlDisableLocalTimestamp{0x00000000U};
		constexpr static const uint32_t traceCtrlEnableSynchronousTPIU{0x00000004U};
		constexpr static const uint32_t traceCtrlDisableSynchronousTPIU{0x00000000U};
	} // namespace itm

	namespace tpiu
	{
		// Formatter flush control register constants
		constexpr static const uint32_t formatterCtrlEnableContinuous{0x00000002U};
		constexpr static const uint32_t formatterCtrlDisableContinuous{0x00000000U};
		constexpr static const uint32_t formatterCtrlTrigger{0x00000100U};

		// Formatter flush status register constants
		constexpr static const uint32_t formatterStatusTrigger{0x00000001U};

		// Selected pin protocol register constants
		constexpr static const uint32_t selectedPinProtocolParallel{0x00000000U};
		constexpr static const uint32_t selectedPinProtocolSWOManchester{0x00000001U};
		constexpr static const uint32_t selectedPinProtocolSWONRZ{0x00000002U};
	} // namespace tpiu
} // namespace vals

namespace stm32
{
	using usbEPTable_t = std::array<usbEP_t, vals::usb::endpoints>;
} // namespace stm32

#endif /*STM32F1_CONSTANTS_HXX*/
