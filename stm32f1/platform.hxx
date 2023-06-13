// SPDX-License-Identifier: BSD-3-Clause
#ifndef STM32F1_PLATFORM_HXX
#define STM32F1_PLATFORM_HXX

#include <cstdint>
#include <cstddef>
#include <array>

// NOLINTBEGIN(cppcoreguidelines-avoid-const-or-ref-data-members)
namespace stm32
{
	// USB periphal structure
	struct usb_t final
	{
		std::array<volatile uint32_t, 8> epCtrlStat;
		std::array<const volatile uint32_t, 4> reserved;
		volatile uint32_t ctrl;
		volatile uint32_t intStatus;
		const volatile uint32_t frameNumber;
		volatile uint32_t address;
		volatile uint32_t bufferTablePtr;
	};

	// USB endpoint structure
	struct usbEP_t final
	{
		volatile uint32_t txAddress;
		volatile uint32_t txCount;
		volatile uint32_t rxAddress;
		volatile uint32_t rxCount;
	};

	// GPIO peripheral structure
	struct gpio_t final
	{
		std::array<volatile uint32_t, 2> config;
		const volatile uint32_t dataIn;
		volatile uint32_t dataOut;
		volatile uint32_t pinSetReset;
		volatile uint32_t pinReset;
		volatile uint32_t configLock;
	};

	// Reset and Clock Control peripheral structure
	struct rcc_t final
	{
		volatile uint32_t clockCtrl;
		volatile uint32_t clockConfig;
		volatile uint32_t clockInterrupt;
		volatile uint32_t apb2PeriphReset;
		volatile uint32_t apb1PeriphReset;
		volatile uint32_t ahbPeriphReset;
		volatile uint32_t apb2PeriphClockEn;
		volatile uint32_t apb1PeriphClockEn;
		volatile uint32_t backupDomainCtrl;
		volatile uint32_t ctrlStatus;
	};

	// Flash Controller peripheral structure
	struct flash_t final
	{
		volatile uint32_t accessCtrl;
		volatile uint32_t flashKey;
		volatile uint32_t optionKey;
		volatile uint32_t status;
		volatile uint32_t control;
		volatile uint32_t address;
		const volatile uint32_t reserved;
		volatile uint32_t optionByte;
		volatile uint32_t writeProtection;
	};

	// System (Cortex-M) peripherals

	// System Tick structure
	struct sysTick_t final
	{
		volatile uint32_t ctrl;
		volatile uint32_t load;
		volatile uint32_t value;
		volatile uint32_t calibration;
	};

	// Nested Vectored Interrupt Controller structure
	struct nvic_t final
	{
		std::array<volatile uint32_t, 8> intrSetEnable;
		std::array<const volatile uint32_t, 24> reserved0;
		std::array<volatile uint32_t, 8> intrClrEnable;
		std::array<const volatile uint32_t, 24> reserved1;
		std::array<volatile uint32_t, 8> intrSetPending;
		std::array<const volatile uint32_t, 24> reserved2;
		std::array<volatile uint32_t, 8> intrClrPending;
		std::array<const volatile uint32_t, 24> reserved3;
		std::array<const volatile uint32_t, 8> intrActive;

		constexpr void enableInterrupt(const uint32_t intrNumber) noexcept
			{ intrSetEnable[intrNumber >> 5U] = UINT32_C(1) << (intrNumber & 0x1fU); }
		constexpr void disableInterrupt(const uint32_t intrNumber) noexcept
			{ intrClrEnable[intrNumber >> 5U] = UINT32_C(1) << (intrNumber & 0x1fU); }
	};

	// System Controller Block
	struct scb_t final
	{
		const volatile uint32_t cpuid;
		volatile uint32_t intCtrl;
		volatile uint32_t vtable;
		volatile uint32_t apint;
		volatile uint32_t sysCtrl;
		volatile uint32_t cfgCtrl;
		std::array<volatile uint32_t, 3> sysPriority;
		volatile uint32_t sysHandlerCtrl;
		volatile uint32_t faultStatus;
		volatile uint32_t hardFaultStatus;
		std::array<const volatile uint32_t, 2> reserved0;
		volatile uint32_t memMgmtFaultAddr;
		volatile uint32_t faultAddr;
	};

	// Memory Protection Unit structure
	struct mpu_t final
	{
		struct regionAlias_t final
		{
			volatile uint32_t base;
			volatile uint32_t attr;
		};

		const volatile uint32_t type;
		volatile uint32_t ctrl;
		volatile uint32_t number;
		volatile uint32_t base;
		volatile uint32_t attr;
		std::array<regionAlias_t, 3> aliases;
	};

	// Debug Controller Block structure
	struct dcb_t final
	{
		volatile uint32_t haltCtrlStatus;
		volatile uint32_t coreRegisterSelect;
		volatile uint32_t coreRegisterData;
		volatile uint32_t exceptMonitorCtrl;
	};

	// Peripheral ID structure
	struct pid_t final
	{
	private:
		std::array<const volatile uint32_t, 8> pid;

	public:
		[[nodiscard]] constexpr auto begin() noexcept { return pid.begin(); }
		[[nodiscard]] constexpr auto begin() const noexcept { return pid.begin(); }
		[[nodiscard]] constexpr auto end() noexcept { return pid.end(); }
		[[nodiscard]] constexpr auto end() const noexcept { return pid.end(); }
		[[nodiscard]] constexpr auto size() const noexcept { return pid.size(); }
		[[nodiscard]] constexpr auto data() noexcept { return pid.data(); }
		[[nodiscard]] constexpr auto data() const noexcept { return pid.data(); }
		[[nodiscard]] constexpr auto &operator [](const size_t i) noexcept
			{ return pid[(i + 4U) & 7U]; }
		[[nodiscard]] constexpr auto &operator [](const size_t i) const noexcept
			{ return pid[(i + 4U) & 7U]; }
	};

	// Instrumentation Trace Macrocell structure
	struct itm_t final
	{
		// +0x0
		std::array<volatile uint32_t, 32> channelData;
		std::array<const volatile uint32_t, 864> reserved0;
		// +0xE00
		volatile uint32_t traceChannelEn;
		std::array<const volatile uint32_t, 15> reserved1;
		// +0xE40
		volatile uint32_t tracePriv;
		std::array<const volatile uint32_t, 15> reserved2;
		// +0xE80
		volatile uint32_t traceCtrl;
		std::array<const volatile uint32_t, 83> reserved3;
		// +0xFD0
		pid_t pid;
		std::array<const volatile uint32_t, 4> cid;
	};

	// Trace Port Interface Unit structure
	struct tpiu_t final
	{
		const volatile uint32_t supportedParallelSize;
		volatile uint32_t currentParallelSize;
		std::array<const volatile uint32_t, 2> reserved0;
		volatile uint32_t asyncClockPrescale;
		std::array<const volatile uint32_t, 55> reserved1;
		volatile uint32_t selectedPinProtocol;
		std::array<const volatile uint32_t, 131> reserved2;
		const volatile uint32_t formatterStatus;
		volatile uint32_t formatterCtrl;
		const volatile uint32_t formatterSyncCounter;
		std::array<const volatile uint32_t, 759> reserved3;
		const volatile uint32_t trigger;
		const volatile uint32_t etmFIFOData;
		const volatile uint32_t itATBCounter2;
		const volatile uint32_t reserved4;
		const volatile uint32_t itATBCounter0;
		const volatile uint32_t itmFIFOData;
		volatile uint32_t itCtrl;
		std::array<const volatile uint32_t, 39> reserved5;
		volatile uint32_t claimSet;
		volatile uint32_t claimClear;
		std::array<const volatile uint32_t, 8> reserved6;
		const volatile uint32_t deviceID;
		const volatile uint32_t deviceType;
		pid_t pid;
		std::array<const volatile uint32_t, 4> cid;
	};

	static_assert(sizeof(tpiu_t) == 4096);

	// Embedded Trace Macrocell structure
	struct etm_t final
	{
		volatile uint32_t mainCtrl;
		const volatile uint32_t cfgCode;
		volatile uint32_t triggerEvt;
		const volatile uint32_t reserved0;
		volatile uint32_t status;
		const volatile uint32_t sysCfg;
		std::array<const volatile uint32_t, 2> reserved1;
		volatile uint32_t traceEnEvt;
		volatile uint32_t traceEnCtrl1;
		volatile uint32_t fifoFullLevel;
		std::array<const volatile uint32_t, 5> reserved2;
		volatile uint32_t freeRunCounterReload;
		std::array<const volatile uint32_t, 103> reserved3;
		const volatile uint32_t syncFreq;
		const volatile uint32_t idCode;
		const volatile uint32_t cfgCodeExt;
		const volatile uint32_t reserved4;
		volatile uint32_t traceEnICECtrl;
		const volatile uint32_t reserved5;
		volatile uint32_t timestampEvt;
		const volatile uint32_t reserved6;
		volatile uint32_t coreSightTraceID;
	};

	constexpr static uintptr_t usbBase{0x40005c00U};
	constexpr static uintptr_t packetBufferBase{0x40006000U};
	constexpr static uintptr_t gpioABase{0x40010800U};
	constexpr static uintptr_t gpioBBase{0x40010c00U};
	constexpr static uintptr_t gpioCBase{0x40011000U};
	constexpr static uintptr_t gpioDBase{0x40011400U};
	constexpr static uintptr_t gpioEBase{0x40011800U};
	constexpr static uintptr_t gpioFBase{0x40011c00U};
	constexpr static uintptr_t gpioGBase{0x40012000U};
	constexpr static uintptr_t rccBase{0x40021000U};
	constexpr static uintptr_t flashCtrlBase{0x40022000U};

	constexpr static uintptr_t itmBase{0xe0000000U};
	constexpr static uintptr_t sysTickBase{0xe000e010U};
	constexpr static uintptr_t nvicBase{0xe000e100U};
	constexpr static uintptr_t scbBase{0xe000ed00U};
	constexpr static uintptr_t mpuBase{0xe000ed90U};
	constexpr static uintptr_t dcbBase{0xe000edf0U};
	constexpr static uintptr_t tpiuBase{0xe0040000U};
	constexpr static uintptr_t etmBase{0xe0041000U};
} // namespace stm32
// NOLINTEND(cppcoreguidelines-avoid-const-or-ref-data-members)

// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast)
// NOLINTBEGIN(performance-no-int-to-ptr
// NOLINTBEGIN(cppcoreguidelines-avoid-non-const-global-variables)
static auto &usbCtrl{*reinterpret_cast<stm32::usb_t *>(stm32::usbBase)};
static auto &gpioA{*reinterpret_cast<stm32::gpio_t *>(stm32::gpioABase)};
static auto &gpioB{*reinterpret_cast<stm32::gpio_t *>(stm32::gpioBBase)};
static auto &gpioC{*reinterpret_cast<stm32::gpio_t *>(stm32::gpioCBase)};
static auto &gpioD{*reinterpret_cast<stm32::gpio_t *>(stm32::gpioDBase)};
static auto &gpioE{*reinterpret_cast<stm32::gpio_t *>(stm32::gpioEBase)};
static auto &gpioF{*reinterpret_cast<stm32::gpio_t *>(stm32::gpioFBase)};
static auto &gpioG{*reinterpret_cast<stm32::gpio_t *>(stm32::gpioGBase)};
static auto &rcc{*reinterpret_cast<stm32::rcc_t *>(stm32::rccBase)};
static auto &flashCtrl{*reinterpret_cast<stm32::flash_t *>(stm32::flashCtrlBase)};

static auto &sysTick{*reinterpret_cast<stm32::sysTick_t *>(stm32::sysTickBase)};
static auto &nvic{*reinterpret_cast<stm32::nvic_t *>(stm32::nvicBase)};
static auto &scb{*reinterpret_cast<stm32::scb_t *>(stm32::scbBase)};
static auto &mpu{*reinterpret_cast<stm32::mpu_t *>(stm32::mpuBase)};
static auto &dcb{*reinterpret_cast<stm32::dcb_t *>(stm32::dcbBase)};
static auto &itm{*reinterpret_cast<stm32::itm_t *>(stm32::itmBase)};
static auto &tpiu{*reinterpret_cast<stm32::tpiu_t *>(stm32::tpiuBase)};
static auto &etm{*reinterpret_cast<stm32::etm_t *>(stm32::etmBase)};
// NOLINTEND(cppcoreguidelines-avoid-non-const-global-variables)
// NOLINTEND(performance-no-int-to-ptr
// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast)

#endif /*STM32F1_PLATFORM_HXX*/
