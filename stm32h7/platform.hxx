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

	constexpr static uintptr_t infoBase{0x1ff1e800U};
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
} // namespace stm32
// NOLINTEND(cppcoreguidelines-avoid-const-or-ref-data-members)

// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast)
// NOLINTBEGIN(performance-no-int-to-ptr
// NOLINTBEGIN(cppcoreguidelines-avoid-non-const-global-variables)
static auto &deviceInfo{*reinterpret_cast<stm32::info_t *>(stm32::infoBase)};
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
// NOLINTEND(cppcoreguidelines-avoid-non-const-global-variables)
// NOLINTEND(performance-no-int-to-ptr
// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast)

#endif /*STM32H7_PLATFORM_HXX*/
