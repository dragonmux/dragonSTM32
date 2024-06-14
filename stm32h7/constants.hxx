// SPDX-License-Identifier: BSD-3-Clause
#ifndef STM32H7_CONSTANTS_HXX
#define STM32H7_CONSTANTS_HXX

#include <cstdint>
#include <cstring>
#include "stm32h7/platform.hxx"

namespace vals
{
	namespace rcc
	{
		// Control register constants
		constexpr static uint32_t ctrlHSIEnable{0x00000001U};
		constexpr static uint32_t ctrlHSIAlwaysEnable{0x00000002U};
		constexpr static uint32_t ctrlHSIReady{0x00000004U};
		constexpr static uint32_t ctrlHSIDivideMask{0x00000018U};
		constexpr static uint32_t ctrlHSIDivide1{0x00000000U};
		constexpr static uint32_t ctrlHSIDivide2{0x00000008U};
		constexpr static uint32_t ctrlHSIDivide4{0x00000010U};
		constexpr static uint32_t ctrlHSIDivide8{0x00000018U};
		constexpr static uint32_t ctrlHSIDividerActive{0x00000020U};
		constexpr static uint32_t ctrlCSIEnable{0x00000080U};
		constexpr static uint32_t ctrlCSIReady{0x00000100U};
		constexpr static uint32_t ctrlCSIAlwaysOn{0x00000200U};
		constexpr static uint32_t ctrlHSI48Enable{0x00001000U};
		constexpr static uint32_t ctrlHSI48Ready{0x00002000U};
		constexpr static uint32_t ctrlDomain1ClocksReady{0x00004000U};
		constexpr static uint32_t ctrlDomain2ClocksReady{0x00008000U};
		constexpr static uint32_t ctrlHSEEnable{0x00010000U};
		constexpr static uint32_t ctrlHSEReady{0x00020000U};
		constexpr static uint32_t ctrlHSEBypass{0x00040000U};
		constexpr static uint32_t ctrlHSEClockSecurityEnable{0x00080000U};
		constexpr static uint32_t ctrlPLL1Enable{0x01000000U};
		constexpr static uint32_t ctrlPLL1Ready{0x02000000U};
		constexpr static uint32_t ctrlPLL2Enable{0x04000000U};
		constexpr static uint32_t ctrlPLL2Ready{0x08000000U};
		constexpr static uint32_t ctrlPLL3Enable{0x10000000U};
		constexpr static uint32_t ctrlPLL3Ready{0x20000000U};
	} // namespace rcc

	namespace pwr
	{
		// Control 1 register constants
		constexpr static uint32_t ctrl1LowPowerDeepsleepSVOS3{0x00000001U};
		constexpr static uint32_t ctrl1PVDEnable{0x00000010U};
		constexpr static uint32_t ctrl1PVDSelectorMask{0x000000e0U};
		constexpr static uint32_t ctrl1PVDSelector1V95{0x00000000U};
		constexpr static uint32_t ctrl1PVDSelector2V1{0x00000020U};
		constexpr static uint32_t ctrl1PVDSelector2V25{0x00000040U};
		constexpr static uint32_t ctrl1PVDSelector2V4{0x00000060U};
		constexpr static uint32_t ctrl1PVDSelector2V55{0x00000080U};
		constexpr static uint32_t ctrl1PVDSelector2V7{0x000000a0U};
		constexpr static uint32_t ctrl1PVDSelector2V85{0x000000c0U};
		constexpr static uint32_t ctrl1PVDSelectorExternal{0x000000e0U};
		constexpr static uint32_t ctrl1DisableBackuDomainWP{0x00000100U};
		constexpr static uint32_t ctrl1FlashLowPowerDStop{0x00000200U};
		constexpr static uint32_t ctrl1SysStopVOSMask{0x0000c000U};
		constexpr static uint32_t ctrl1SysStopVOS5{0x00004000U};
		constexpr static uint32_t ctrl1SysStopVOS4{0x00008000U};
		constexpr static uint32_t ctrl1SysStopVOS3{0x0000c000U};
		constexpr static uint32_t ctrl1AnalogMonitorEnable{0x00010000U};
		constexpr static uint32_t ctrl1AnalogMonitorThresholdMask{0x00060000U};
		constexpr static uint32_t ctrl1AnalogMonitorThreshold1V7{0x00000000U};
		constexpr static uint32_t ctrl1AnalogMonitorThreshold2V1{0x00020000U};
		constexpr static uint32_t ctrl1AnalogMonitorThreshold2V5{0x00040000U};
		constexpr static uint32_t ctrl1AnalogMonitorThreshold2V8{0x00060000U};

		// Status 1 register constants
		constexpr static uint32_t status1PVDThresholdBreached{0x00000010U};
		constexpr static uint32_t status1ActiveVOSReady{0x00002000U};
		constexpr static uint32_t status1ActiveVOSMask{0x0000c000U};
		constexpr static uint32_t status1AnalogMonitorThresholdBreached{0x00010000U};

		// Control 2 register constants
		constexpr static uint32_t ctrl2BackupRegulatorEnable{0x00000001U};
		constexpr static uint32_t ctrl2VBatTempMonitorEnable{0x00000001U};
		constexpr static uint32_t ctrl2BackupRegulatorReady{0x00010000U};
		constexpr static uint32_t ctrl2VBatLevelLow{0x00100000U};
		constexpr static uint32_t ctrl2VBatLevelHigh{0x00200000U};
		constexpr static uint32_t ctrl2TemperatureLow{0x00400000U};
		constexpr static uint32_t ctrl2TemperatureHigh{0x00800000U};

		// Control 3 register constants
		constexpr static uint32_t ctrl3BypassEnable{0x00000001U};
		constexpr static uint32_t ctrl3LDOEnable{0x00000002U};
		constexpr static uint32_t ctrl3SMPSEnable{0x00000004U};
		constexpr static uint32_t ctrl3SMPSHighPowerForceEnable{0x00000008U};
		constexpr static uint32_t ctrl3SMPSOutputMask{0x00000030U};
		constexpr static uint32_t ctrl3SMPSOutput1V8{0x00000010U};
		constexpr static uint32_t ctrl3SMPSOutput2V5{0x00000020U};
		constexpr static uint32_t ctrl3VBatChargeEnable{0x00000100U};
		constexpr static uint32_t ctrl3VBatChargeResistorMask{0x00000200U};
		constexpr static uint32_t ctrl3VBatChargeResistor5k{0x00000000U};
		constexpr static uint32_t ctrl3VBatChargeResistor1k5{0x00000200U};
		constexpr static uint32_t ctrl3SMPSReady{0x00010000U};
		constexpr static uint32_t ctrl3USB33MonitorEnable{0x01000000U};
		constexpr static uint32_t ctrl3USB33RegulatorEnable{0x02000000U};
		constexpr static uint32_t ctrl3USB33Ready{0x04000000U};

		// CPU Control register constants
		constexpr static uint32_t cpuCtrlAllowDomain1DStandby{0x00000001U};
		constexpr static uint32_t cpuCtrlAllowDomain2DStandby{0x00000002U};
		constexpr static uint32_t cpuCtrlAllowDomain3DStandby{0x00000004U};
		constexpr static uint32_t cpuCtrlSysHasStopped{0x00000020U};
		constexpr static uint32_t cpuCtrlSysHasStandby{0x00000040U};
		constexpr static uint32_t cpuCtrlDomain1HasStandby{0x00000080U};
		constexpr static uint32_t cpuCtrlDomain2HasStandby{0x00000100U};
		constexpr static uint32_t cpuCtrlClearStandbyFlags{0x00000200U};
		constexpr static uint32_t cpuCtrlForceDomain3Run{0x00000800U};

		// Domain 3 Control register constants
		constexpr static uint32_t domain3CtrlVOSReady{0x00002000U};
		constexpr static uint32_t domain3CtrlVOSMask{0x0000c000U};
		constexpr static uint32_t domain3CtrlVOS0{0x00000000U};
		constexpr static uint32_t domain3CtrlVOS3{0x00004000U};
		constexpr static uint32_t domain3CtrlVOS2{0x00008000U};
		constexpr static uint32_t domain3CtrlVOS1{0x0000c000U};

		// Wakeup flag registers constants
		constexpr static uint32_t wakeupFlag1{0x00000001U};
		constexpr static uint32_t wakeupFlag2{0x00000002U};
		constexpr static uint32_t wakeupFlag4{0x00000008U};
		constexpr static uint32_t wakeupFlag6{0x00000020U};
		constexpr static size_t wakeupEnableShift{0U};
		constexpr static size_t wakeupPolarityShift{8U};

		enum class pullConfig_t : uint8_t
		{
			none = 0U,
			pullUp = 1U,
			pullDown = 2U,
		};

		constexpr inline uint32_t wakeupPullConfig(const uint8_t pin, const pullConfig_t config) noexcept
			{ return (static_cast<uint32_t>(config) << (pin << 1U)) << 16U; }
	} // namespace pwr
} // namespace vals

#endif /*STM32H7_CONSTANTS_HXX*/
