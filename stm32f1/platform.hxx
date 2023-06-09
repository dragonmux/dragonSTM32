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

	constexpr static uintptr_t usbBase{0x40005c00U};
	constexpr static uintptr_t rccBase{0x40021000U};
} // namespace stm32
// NOLINTEND(cppcoreguidelines-avoid-const-or-ref-data-members)

// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast)
// NOLINTBEGIN(performance-no-int-to-ptr
// NOLINTBEGIN(cppcoreguidelines-avoid-non-const-global-variables)
static auto &rcc{*reinterpret_cast<stm32::rcc_t *>(stm32::rccBase)};
static auto &usbCtrl{*reinterpret_cast<stm32::usb_t *>(stm32::usbBase)};
// NOLINTEND(cppcoreguidelines-avoid-non-const-global-variables)
// NOLINTEND(performance-no-int-to-ptr
// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast)

#endif /*STM32F1_PLATFORM_HXX*/
