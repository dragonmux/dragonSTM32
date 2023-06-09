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

		constexpr static const uint8_t endpointDirMask{0x7fU};
		constexpr inline uint8_t endpoint(const endpointDir_t dir, const uint8_t number) noexcept
			{ return uint8_t(dir) | (number & endpointDirMask); }

		// Device address register constants
		constexpr static uint32_t addressMask{0x0000007fU};
		constexpr static uint32_t addressClrMask{0xffffff00U};
		constexpr static uint32_t addressUSBEnable{0x00000080U};
	} // namespace usb
} // namespace vals

#endif /*STM32F1_CONSTANTS_HXX*/
