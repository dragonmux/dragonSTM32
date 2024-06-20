// SPDX-License-Identifier: BSD-3-Clause
#ifndef STM32H7_PLATFORM_HXX
#define STM32H7_PLATFORM_HXX

#include <cstdint>
#include <cstddef>
#include <array>

// NOLINTBEGIN(cppcoreguidelines-avoid-const-or-ref-data-members)
namespace stm32
{
	// Info peripheral structure
	struct info_t final
	{
		std::array<const volatile uint32_t, 3> uniqueID;
		std::array<const volatile uint32_t, 29> reserved1;
		const volatile uint32_t flashSize;
		std::array<const volatile uint32_t, 15> reserved2;
		const volatile uint32_t lineID;
	};

	// Clock recovery system controller peripheral structure
	struct crs_t final
	{
		volatile uint32_t ctrl;
		volatile uint32_t config;
		volatile uint32_t intStatus;
		volatile uint32_t intClear;
	};

	// GPIO peripheral structure
	struct gpio_t final
	{
		volatile uint32_t mode;
		volatile uint32_t outputType;
		volatile uint32_t outputSpeed;
		volatile uint32_t pullUpDownConfig;
		const volatile uint32_t dataIn;
		volatile uint32_t dataOut;
		volatile uint32_t pinSetReset;
		volatile uint32_t configLock;
		std::array<volatile uint32_t, 2> altFunction;
	};

	// Reset and Clock Controller peripheral structure
	struct rcc_t final
	{
		volatile uint32_t ctrl;
		volatile uint32_t hsiConfig;
		volatile uint32_t clockRecoveryConfig;
		volatile uint32_t csiConfig;
		volatile uint32_t config;
		const volatile uint32_t reserved1;
		volatile uint32_t domain1Config;
		volatile uint32_t domain2Config;
		volatile uint32_t domain3Config;
		const volatile uint32_t reserved2;
		volatile uint32_t pllClockSelect;
		volatile uint32_t pllClockConfig;
		volatile uint32_t pll1DividerConfig;
		volatile uint32_t pll1FractionalConfig;
		volatile uint32_t pll2DividerConfig;
		volatile uint32_t pll2FractionalConfig;
		volatile uint32_t pll3DividerConfig;
		volatile uint32_t pll3FractionalConfig;
		const volatile uint32_t reserved3;
		volatile uint32_t domain1ClockConfig;
		volatile uint32_t domain2ClockConfig1;
		volatile uint32_t domain2ClockConfig2;
		volatile uint32_t domain3ClockConfig;
		const volatile uint32_t reserved4;
		volatile uint32_t clockIntEnable;
		volatile uint32_t clockIntStatus;
		volatile uint32_t clockIntClear;
		const volatile uint32_t reserved5;
		volatile uint32_t backupDomainCtrl;
		volatile uint32_t clockCtrlStatus;
		const volatile uint32_t reserved6;
		volatile uint32_t ahb3Reset;
		volatile uint32_t ahb1Reset;
		volatile uint32_t ahb2Reset;
		volatile uint32_t ahb4Reset;
		volatile uint32_t apb3Reset;
		std::array<volatile uint32_t, 2> apb1Reset;
		volatile uint32_t apb2Reset;
		volatile uint32_t apb4Reset;
		volatile uint32_t globalCtrl;
		const volatile uint32_t reserved7;
		volatile uint32_t domain3AutonomousMode;
		std::array<const volatile uint32_t, 9> reserved8;
		volatile uint32_t resetStatus;
		volatile uint32_t ahb3Enable;
		volatile uint32_t ahb1Enable;
		volatile uint32_t ahb2Enable;
		volatile uint32_t ahb4Enable;
		volatile uint32_t apb3Enable;
		std::array<volatile uint32_t, 2> apb1Enable;
		volatile uint32_t apb2Enable;
		volatile uint32_t apb4Enable;
		const volatile uint32_t reserved9;
		volatile uint32_t ahb3LowPowerEnable;
		volatile uint32_t ahb1LowPowerEnable;
		volatile uint32_t ahb2LowPowerEnable;
		volatile uint32_t ahb4LowPowerEnable;
		volatile uint32_t apb3LowPowerEnable;
		std::array<volatile uint32_t, 2> apb1LowPowerEnable;
		volatile uint32_t apb2LowPowerEnable;
		volatile uint32_t apb4LowPowerEnable;
	};

	// Power controller peripheral structure
	struct pwr_t final
	{
		volatile uint32_t ctrl1;
		const volatile uint32_t status1;
		volatile uint32_t ctrl2;
		volatile uint32_t ctrl3;
		volatile uint32_t cpuCtrl;
		const volatile uint32_t reserved;
		volatile uint32_t domain3Ctrl;
		volatile uint32_t wakeupClear;
		volatile uint32_t wakeupStatus;
		volatile uint32_t wakeupEnable;
	};

	constexpr static uintptr_t infoBase{0x1ff1e800U};
	constexpr static uintptr_t usb1HSBase{0x40040000U};
	constexpr static uintptr_t crsBase{0x40008400U};
	constexpr static uintptr_t gpioABase{0x58020000U};
	constexpr static uintptr_t gpioBBase{0x58020400U};
	constexpr static uintptr_t gpioCBase{0x58020800U};
	constexpr static uintptr_t gpioDBase{0x58020c00U};
	constexpr static uintptr_t gpioEBase{0x58021000U};
	constexpr static uintptr_t gpioFBase{0x58021400U};
	constexpr static uintptr_t gpioGBase{0x58021800U};
	constexpr static uintptr_t gpioHBase{0x58021c00U};
	constexpr static uintptr_t gpioJBase{0x58022400U};
	constexpr static uintptr_t gpioKBase{0x58022800U};
	constexpr static uintptr_t rccBase{0x58024400U};
	constexpr static uintptr_t pwrBase{0x58024800U};
} // namespace stm32
// NOLINTEND(cppcoreguidelines-avoid-const-or-ref-data-members)

// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast)
// NOLINTBEGIN(performance-no-int-to-ptr
// NOLINTBEGIN(cppcoreguidelines-avoid-non-const-global-variables)
static auto &deviceInfo{*reinterpret_cast<stm32::info_t *>(stm32::infoBase)};
static auto &crs{*reinterpret_cast<stm32::crs_t *>(stm32::crsBase)};
static auto &gpioA{*reinterpret_cast<stm32::gpio_t *>(stm32::gpioABase)};
static auto &gpioB{*reinterpret_cast<stm32::gpio_t *>(stm32::gpioBBase)};
static auto &gpioC{*reinterpret_cast<stm32::gpio_t *>(stm32::gpioCBase)};
static auto &gpioD{*reinterpret_cast<stm32::gpio_t *>(stm32::gpioDBase)};
static auto &gpioE{*reinterpret_cast<stm32::gpio_t *>(stm32::gpioEBase)};
static auto &gpioF{*reinterpret_cast<stm32::gpio_t *>(stm32::gpioFBase)};
static auto &gpioG{*reinterpret_cast<stm32::gpio_t *>(stm32::gpioGBase)};
static auto &gpioH{*reinterpret_cast<stm32::gpio_t *>(stm32::gpioHBase)};
static auto &gpioJ{*reinterpret_cast<stm32::gpio_t *>(stm32::gpioJBase)};
static auto &gpioK{*reinterpret_cast<stm32::gpio_t *>(stm32::gpioKBase)};
static auto &rcc{*reinterpret_cast<stm32::rcc_t *>(stm32::rccBase)};
static auto &pwr{*reinterpret_cast<stm32::pwr_t *>(stm32::pwrBase)};
// NOLINTEND(cppcoreguidelines-avoid-non-const-global-variables)
// NOLINTEND(performance-no-int-to-ptr
// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast)

#endif /*STM32H7_PLATFORM_HXX*/
