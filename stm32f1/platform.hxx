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
		volatile uint32_t ep0CtrlStat;
		volatile uint32_t ep1CtrlStat;
		volatile uint32_t ep2CtrlStat;
		volatile uint32_t ep3CtrlStat;
		volatile uint32_t ep4CtrlStat;
		volatile uint32_t ep5CtrlStat;
		volatile uint32_t ep6CtrlStat;
		volatile uint32_t ep7CtrlStat;
		std::array<const volatile uint32_t, 4> reserved;
		volatile uint32_t ctrl;
		volatile uint32_t intStatus;
		const volatile uint32_t frameNumber;
		volatile uint32_t address;
		volatile uint32_t bufferTablePtr;
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

	constexpr static uintptr_t usbBase{0x40005c00U};
	constexpr static uintptr_t gpioABase{0x40010800U};
	constexpr static uintptr_t gpioBBase{0x40010c00U};
	constexpr static uintptr_t gpioCBase{0x40011000U};
	constexpr static uintptr_t gpioDBase{0x40011400U};
	constexpr static uintptr_t gpioEBase{0x40011800U};
	constexpr static uintptr_t gpioFBase{0x40011c00U};
	constexpr static uintptr_t gpioGBase{0x40012000U};
	constexpr static uintptr_t rccBase{0x40021000U};

	constexpr static uintptr_t nvicBase{0xe000e100U};
} // namespace stm32
// NOLINTEND(cppcoreguidelines-avoid-const-or-ref-data-members)

// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast)
// NOLINTBEGIN(performance-no-int-to-ptr
// NOLINTBEGIN(cppcoreguidelines-avoid-non-const-global-variables)
static auto &rcc{*reinterpret_cast<stm32::rcc_t *>(stm32::rccBase)};
static auto &gpioA{*reinterpret_cast<stm32::gpio_t *>(stm32::gpioABase)};
static auto &gpioB{*reinterpret_cast<stm32::gpio_t *>(stm32::gpioBBase)};
static auto &gpioC{*reinterpret_cast<stm32::gpio_t *>(stm32::gpioCBase)};
static auto &gpioD{*reinterpret_cast<stm32::gpio_t *>(stm32::gpioDBase)};
static auto &gpioE{*reinterpret_cast<stm32::gpio_t *>(stm32::gpioEBase)};
static auto &gpioF{*reinterpret_cast<stm32::gpio_t *>(stm32::gpioFBase)};
static auto &gpioG{*reinterpret_cast<stm32::gpio_t *>(stm32::gpioGBase)};
static auto &usbCtrl{*reinterpret_cast<stm32::usb_t *>(stm32::usbBase)};

static auto &nvic{*reinterpret_cast<stm32::nvic_t *>(stm32::nvicBase)};
// NOLINTEND(cppcoreguidelines-avoid-non-const-global-variables)
// NOLINTEND(performance-no-int-to-ptr
// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast)

#endif /*STM32F1_PLATFORM_HXX*/
