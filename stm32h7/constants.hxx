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

		// Clock configuration register constants
		constexpr static uint32_t configSystemClockMask{0x00000007U};
		constexpr static uint32_t configSystemClockHSI{0x00000000U};
		constexpr static uint32_t configSystemClockCSI{0x00000001U};
		constexpr static uint32_t configSystemClockHSE{0x00000002U};
		constexpr static uint32_t configSystemClockPLL{0x00000003U};
		constexpr static uint32_t configActiveSystemClockMask{0x00000038U};
		constexpr static size_t configActiveSystemClockShift{2U};
		constexpr static uint32_t configPostStopSysClockHSI{0x00000000U};
		constexpr static uint32_t configPostStopSysClockCSI{0x00000040U};
		constexpr static uint32_t configPostStopPeriphClockHSI{0x00000000U};
		constexpr static uint32_t configPostStopPeriphClockCSI{0x00000080U};
		constexpr static uint32_t configRTCFromHSEDividerMask{0x00003f00U};
		constexpr static uint32_t configTimerPrescaler2{0x00000000U};
		constexpr static uint32_t configTimerPrescaler4{0x00008000U};
		constexpr static uint32_t configClockOut1PrescalerMask{0x003c0000U};
		constexpr static uint32_t configClockOut1SourceMask{0x01c00000U};
		constexpr static uint32_t configClockOut1SourceHSI{0x00000000U};
		constexpr static uint32_t configClockOut1SourceLSE{0x00400000U};
		constexpr static uint32_t configClockOut1SourceHSE{0x00800000U};
		constexpr static uint32_t configClockOut1SourcePLL1Q{0x00c00000U};
		constexpr static uint32_t configClockOut1SourceHSI48{0x01000000U};
		constexpr static uint32_t configClockOut2PrescalerMask{0x1e000000U};
		constexpr static uint32_t configClockOut2SourceMask{0xe0000000U};
		constexpr static uint32_t configClockOut2SourceSysClock{0x00000000U};
		constexpr static uint32_t configClockOut2SourcePLL2P{0x20000000U};
		constexpr static uint32_t configClockOut2SourceHSE{0x40000000U};
		constexpr static uint32_t configClockOut2SourcePLL1P{0x60000000U};
		constexpr static uint32_t configClockOut2SourceCSI{0x80000000U};
		constexpr static uint32_t configClockOut2SourceLSI{0xa0000000U};

		constexpr inline uint32_t configRTCFromHSEDivider(const uint8_t divider) noexcept
			{ return static_cast<uint32_t>(divider & 0x3fU) << 8U; }
		constexpr inline uint32_t configClockOut1Prescaler(const uint8_t prescaler) noexcept
			{ return static_cast<uint32_t>(prescaler & 0x0fU) << 18U; }
		constexpr inline uint32_t configClockOut2Prescaler(const uint8_t prescaler) noexcept
			{ return static_cast<uint32_t>(prescaler & 0x0fU) << 25U; }

		// Domain 1 clock configuration register constants
		constexpr static uint32_t domain1ConfigAHBPrescalerMask{0x0000000fU};
		constexpr static uint32_t domain1ConfigAPB3PrescalerMask{0x00000070U};
		constexpr static uint32_t domain1ConfigCorePrescalerMask{0x00000f00U};

		// XXX: These need to properly handle the high bit enables and map the input values
		constexpr inline uint32_t domain1ConfigAHBPrescaler(const uint8_t prescaler) noexcept
			{ return static_cast<uint32_t>(prescaler); }
		constexpr inline uint32_t domain1ConfigAPB3Prescaler(const uint8_t prescaler) noexcept
			{ return static_cast<uint32_t>(prescaler) << 4U; }
		constexpr inline uint32_t domain1ConfigCorePrescaler(const uint8_t prescaler) noexcept
			{ return static_cast<uint32_t>(prescaler) << 8U; }

		// Domain 2 clock configuration register constants
		constexpr static uint32_t domain2ConfigAPB1PrescalerMask{0x00000070U};
		constexpr static uint32_t domain2ConfigAPB2PrescalerMask{0x00000700U};

		constexpr inline uint32_t domain2ConfigAPB1Prescaler(const uint8_t prescaler) noexcept
			{ return static_cast<uint32_t>(prescaler) << 4U; }
		constexpr inline uint32_t domain2ConfigAPB2Prescaler(const uint8_t prescaler) noexcept
			{ return static_cast<uint32_t>(prescaler) << 8U; }

		// Domain 3 clock configuration register constants
		constexpr static uint32_t domain3ConfigAPB4PrescalerMask{0x00000030U};

		constexpr inline uint32_t domain3ConfigAPB4Prescaler(const uint8_t prescaler) noexcept
			{ return static_cast<uint32_t>(prescaler) << 4U; }

		// Domain 1 peripheral clock configuration register constants
		constexpr static uint32_t domain1ClockConfigFMCMask{0x00000003U};
		constexpr static uint32_t domain1ClockConfigFMCHClk3{0x00000000U};
		constexpr static uint32_t domain1ClockConfigFMCPLL1Q{0x00000001U};
		constexpr static uint32_t domain1ClockConfigFMCPLL2R{0x00000002U};
		constexpr static uint32_t domain1ClockConfigFMCPerClk{0x00000003U};
		constexpr static uint32_t domain1ClockConfigOctoSPIMask{0x00000030U};
		constexpr static uint32_t domain1ClockConfigOctoSPIHClk3{0x00000000U};
		constexpr static uint32_t domain1ClockConfigOctoSPIPLL1Q{0x00000010U};
		constexpr static uint32_t domain1ClockConfigOctoSPIPLL2R{0x00000020U};
		constexpr static uint32_t domain1ClockConfigOctoSPIPerClk{0x00000030U};
		constexpr static uint32_t domain1ClockConfigSDMMCMask{0x00010000U};
		constexpr static uint32_t domain1ClockConfigSDMMCPLL1Q{0x00000000U};
		constexpr static uint32_t domain1ClockConfigSDMMCPLL2R{0x00010000U};
		constexpr static uint32_t domain1ClockConfigPerClkMask{0x30000000U};
		constexpr static uint32_t domain1ClockConfigPerClkHSI{0x00000000U};
		constexpr static uint32_t domain1ClockConfigPerClkCSI{0x10000000U};
		constexpr static uint32_t domain1ClockConfigPerClkHSE{0x20000000U};

		// Domain 2 peripheral clock configuration register 1 constants
		constexpr static uint32_t domain2ClockConfig1SAI1Mask{0x00000007U};
		constexpr static uint32_t domain2ClockConfig1SAI1PLL1Q{0x00000000U};
		constexpr static uint32_t domain2ClockConfig1SAI1PLL2P{0x00000001U};
		constexpr static uint32_t domain2ClockConfig1SAI1PLL3P{0x00000002U};
		constexpr static uint32_t domain2ClockConfig1SAI1I2SClk{0x00000003U};
		constexpr static uint32_t domain2ClockConfig1SAI1PerClk{0x00000004U};
		constexpr static uint32_t domain2ClockConfig1SPI123Mask{0x00007000U};
		constexpr static uint32_t domain2ClockConfig1SPI123PLL1Q{0x00000000U};
		constexpr static uint32_t domain2ClockConfig1SPI123PLL2P{0x00001000U};
		constexpr static uint32_t domain2ClockConfig1SPI123PLL3P{0x00002000U};
		constexpr static uint32_t domain2ClockConfig1SPI123I2SClk{0x00003000U};
		constexpr static uint32_t domain2ClockConfig1SPI123PerClk{0x00004000U};
		constexpr static uint32_t domain2ClockConfig1SPI45Mask{0x00070000U};
		constexpr static uint32_t domain2ClockConfig1SPI45APBClk{0x00000000U};
		constexpr static uint32_t domain2ClockConfig1SPI45PLL2Q{0x00010000U};
		constexpr static uint32_t domain2ClockConfig1SPI45PLL3Q{0x00020000U};
		constexpr static uint32_t domain2ClockConfig1SPI45HSI{0x00030000U};
		constexpr static uint32_t domain2ClockConfig1SPI45CSI{0x00040000U};
		constexpr static uint32_t domain2ClockConfig1SPI45HSE{0x00050000U};
		constexpr static uint32_t domain2ClockConfig1SPDIFMask{0x00300000U};
		constexpr static uint32_t domain2ClockConfig1SPDIFPLL1Q{0x00000000U};
		constexpr static uint32_t domain2ClockConfig1SPDIFPLL2R{0x00100000U};
		constexpr static uint32_t domain2ClockConfig1SPDIFPLL3R{0x00200000U};
		constexpr static uint32_t domain2ClockConfig1SPDIFHSI{0x00300000U};
		constexpr static uint32_t domain2ClockConfig1DFSDM1Mask{0x01000000U};
		constexpr static uint32_t domain2ClockConfig1DFSDM1PClk2{0x00000000U};
		constexpr static uint32_t domain2ClockConfig1DFSDM1SysClk{0x01000000U};
		constexpr static uint32_t domain2ClockConfig1FDCANMask{0x30000000U};
		constexpr static uint32_t domain2ClockConfig1FDCANHSE{0x00000000U};
		constexpr static uint32_t domain2ClockConfig1FDCANPLL1Q{0x10000000U};
		constexpr static uint32_t domain2ClockConfig1FDCANPLL2Q{0x20000000U};
		constexpr static uint32_t domain2ClockConfig1SWPMIMask{0x80000000U};
		constexpr static uint32_t domain2ClockConfig1SWPMIPClk{0x00000000U};
		constexpr static uint32_t domain2ClockConfig1SWPMIHSI{0x80000000U};

		// Domain 2 peripheral clock configuration register 2 constants
		constexpr static uint32_t domain2ClockConfig2USART234578Mask{0x00000007U};
		constexpr static uint32_t domain2ClockConfig2USART234578PClk1{0x00000000U};
		constexpr static uint32_t domain2ClockConfig2USART234578PLL2Q{0x00000001U};
		constexpr static uint32_t domain2ClockConfig2USART234578PLL3Q{0x00000002U};
		constexpr static uint32_t domain2ClockConfig2USART234578HSI{0x00000003U};
		constexpr static uint32_t domain2ClockConfig2USART234578CSI{0x00000004U};
		constexpr static uint32_t domain2ClockConfig2USART234578LSE{0x00000005U};
		constexpr static uint32_t domain2ClockConfig2USART16910Mask{0x00000038U};
		constexpr static uint32_t domain2ClockConfig2USART16910PClk2{0x00000000U};
		constexpr static uint32_t domain2ClockConfig2USART16910PLL2Q{0x00000008U};
		constexpr static uint32_t domain2ClockConfig2USART16910PLL3Q{0x00000010U};
		constexpr static uint32_t domain2ClockConfig2USART16910HSI{0x00000018U};
		constexpr static uint32_t domain2ClockConfig2USART16910CSI{0x00000020U};
		constexpr static uint32_t domain2ClockConfig2USART16910LSE{0x00000028U};
		constexpr static uint32_t domain2ClockConfig2RNGMask{0x00000300U};
		constexpr static uint32_t domain2ClockConfig2RNGHSI8{0x00000000U};
		constexpr static uint32_t domain2ClockConfig2RNGPLL1Q{0x00000100U};
		constexpr static uint32_t domain2ClockConfig2RNGLSE{0x00000200U};
		constexpr static uint32_t domain2ClockConfig2RNGLSI{0x00000300U};
		constexpr static uint32_t domain2ClockConfig2I2C1235Mask{0x00003000U};
		constexpr static uint32_t domain2ClockConfig2I2C1235PClk1{0x00000000U};
		constexpr static uint32_t domain2ClockConfig2I2C1235PLL3R{0x00001000U};
		constexpr static uint32_t domain2ClockConfig2I2C1235HSI{0x00002000U};
		constexpr static uint32_t domain2ClockConfig2I2C1235CSI{0x00003000U};
		constexpr static uint32_t domain2ClockConfig2USBMask{0x00300000U};
		constexpr static uint32_t domain2ClockConfig2USBPLL1Q{0x00100000U};
		constexpr static uint32_t domain2ClockConfig2USBPLL3Q{0x00200000U};
		constexpr static uint32_t domain2ClockConfig2USBHSI48{0x00300000U};
		constexpr static uint32_t domain2ClockConfig2HDMI_CECMask{0x00c00000U};
		constexpr static uint32_t domain2ClockConfig2HDMI_CECLSE{0x00000000U};
		constexpr static uint32_t domain2ClockConfig2HDMI_CECLSI{0x00400000U};
		constexpr static uint32_t domain2ClockConfig2HDMI_CECCSI{0x00800000U};
		constexpr static uint32_t domain2ClockConfig2LPTIM1Mask{0x70000000U};
		constexpr static uint32_t domain2ClockConfig2LPTIM1PClk1{0x00000000U};
		constexpr static uint32_t domain2ClockConfig2LPTIM1PLL2P{0x10000000U};
		constexpr static uint32_t domain2ClockConfig2LPTIM1PLL3R{0x20000000U};
		constexpr static uint32_t domain2ClockConfig2LPTIM1LSE{0x30000000U};
		constexpr static uint32_t domain2ClockConfig2LPTIM1LSI{0x40000000U};
		constexpr static uint32_t domain2ClockConfig2LPTIM1PerClk{0x50000000U};

		// Domain 4 peripheral clock configuration register constants
		constexpr static uint32_t domain3ClockConfigLPUART1Mask{0x00000007U};
		constexpr static uint32_t domain3ClockConfigLPUART1PClkD3{0x00000000U};
		constexpr static uint32_t domain3ClockConfigLPUART1PLL2Q{0x00000001U};
		constexpr static uint32_t domain3ClockConfigLPUART1PLL3Q{0x00000002U};
		constexpr static uint32_t domain3ClockConfigLPUART1HSI{0x00000003U};
		constexpr static uint32_t domain3ClockConfigLPUART1CSI{0x00000004U};
		constexpr static uint32_t domain3ClockConfigLPUART1LSE{0x00000005U};
		constexpr static uint32_t domain3ClockConfigI2C4Mask{0x00000300U};
		constexpr static uint32_t domain3ClockConfigI2C4PClk4{0x00000000U};
		constexpr static uint32_t domain3ClockConfigI2C4PLL3R{0x00000100U};
		constexpr static uint32_t domain3ClockConfigI2C4HSI{0x00000200U};
		constexpr static uint32_t domain3ClockConfigI2C4CSI{0x00000300U};
		constexpr static uint32_t domain3ClockConfigLPTIM2Mask{0x00001c00U};
		constexpr static uint32_t domain3ClockConfigLPTIM2PClk4{0x00000000U};
		constexpr static uint32_t domain3ClockConfigLPTIM2PLL2P{0x00000400U};
		constexpr static uint32_t domain3ClockConfigLPTIM2PLL3R{0x00000800U};
		constexpr static uint32_t domain3ClockConfigLPTIM2LSE{0x00000c00U};
		constexpr static uint32_t domain3ClockConfigLPTIM2LSI{0x00001000U};
		constexpr static uint32_t domain3ClockConfigLPTIM2PerClk{0x00001400U};
		constexpr static uint32_t domain3ClockConfigLPTIM345Mask{0x0000e000U};
		constexpr static uint32_t domain3ClockConfigLPTIM345PClk4{0x00000000U};
		constexpr static uint32_t domain3ClockConfigLPTIM345PLL2P{0x00002000U};
		constexpr static uint32_t domain3ClockConfigLPTIM345PLL3R{0x00004000U};
		constexpr static uint32_t domain3ClockConfigLPTIM345LSE{0x00006000U};
		constexpr static uint32_t domain3ClockConfigLPTIM345LSI{0x00008000U};
		constexpr static uint32_t domain3ClockConfigLPTIM345PerClk{0x0000a000U};
		constexpr static uint32_t domain3ClockConfigADCMask{0x00030000U};
		constexpr static uint32_t domain3ClockConfigADCPLL2P{0x00000000U};
		constexpr static uint32_t domain3ClockConfigADCPLL3R{0x00010000U};
		constexpr static uint32_t domain3ClockConfigADCPerClk{0x00020000U};
		constexpr static uint32_t domain3ClockConfigSAI4AMask{0x00e00000U};
		constexpr static uint32_t domain3ClockConfigSAI4APLL1Q{0x00000000U};
		constexpr static uint32_t domain3ClockConfigSAI4APLL2P{0x00200000U};
		constexpr static uint32_t domain3ClockConfigSAI4APLL3P{0x00400000U};
		constexpr static uint32_t domain3ClockConfigSAI4AI2SClk{0x00600000U};
		constexpr static uint32_t domain3ClockConfigSAI4APerClk{0x00800000U};
		constexpr static uint32_t domain3ClockConfigSAI4ASPDIFRXClk{0x00a00000U};
		constexpr static uint32_t domain3ClockConfigSAI4BMask{0x07000000U};
		constexpr static uint32_t domain3ClockConfigSAI4BPLL1Q{0x00000000U};
		constexpr static uint32_t domain3ClockConfigSAI4BPLL2P{0x01000000U};
		constexpr static uint32_t domain3ClockConfigSAI4BPLL3P{0x02000000U};
		constexpr static uint32_t domain3ClockConfigSAI4BI2SClk{0x03000000U};
		constexpr static uint32_t domain3ClockConfigSAI4BPerClk{0x04000000U};
		constexpr static uint32_t domain3ClockConfigSAI4BSPDIFRXClk{0x05000000U};
		constexpr static uint32_t domain3ClockConfigSAI6Mask{0x70000000U};
		constexpr static uint32_t domain3ClockConfigSAI6PClk4{0x00000000U};
		constexpr static uint32_t domain3ClockConfigSAI6PLL2Q{0x10000000U};
		constexpr static uint32_t domain3ClockConfigSAI6PLL3Q{0x20000000U};
		constexpr static uint32_t domain3ClockConfigSAI6HSI{0x30000000U};
		constexpr static uint32_t domain3ClockConfigSAI6CSI{0x40000000U};
		constexpr static uint32_t domain3ClockConfigSAI6HSE{0x50000000U};
		constexpr static uint32_t domain3ClockConfigSAI6I2CClk{0x60000000U};
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
