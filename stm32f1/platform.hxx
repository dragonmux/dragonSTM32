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

	constexpr static const uintptr_t usbBase{0x40005c00U};
} // namespace stm32
// NOLINTEND(cppcoreguidelines-avoid-const-or-ref-data-members)

// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast)
// NOLINTBEGIN(performance-no-int-to-ptr
// NOLINTBEGIN(cppcoreguidelines-avoid-non-const-global-variables)
static auto &usbCtrl{*reinterpret_cast<stm32::usb_t *>(stm32::usbBase)};
// NOLINTEND(cppcoreguidelines-avoid-non-const-global-variables)
// NOLINTEND(performance-no-int-to-ptr
// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast)

#endif /*STM32F1_PLATFORM_HXX*/
