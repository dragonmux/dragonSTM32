// SPDX-License-Identifier: BSD-3-Clause
#ifndef STM32H7_CONSTANTS_HXX
#define STM32H7_CONSTANTS_HXX

#include <cstdint>
#include <cstring>
#include "stm32h7/platform.hxx"

namespace vals
{
	namespace crs
	{
		// Control register constants
		constexpr static uint32_t ctrlSyncOKItrEnable{0x00000001U};
		constexpr static uint32_t ctrlSyncWarnItrEnable{0x00000002U};
		constexpr static uint32_t ctrlErrorItrEnable{0x00000004U};
		constexpr static uint32_t ctrlExpectedSyncItrEnable{0x00000008U};
		constexpr static uint32_t ctrlErrorCounterEnable{0x00000020U};
		constexpr static uint32_t ctrlAutoTrimEnable{0x00000040U};
		constexpr static uint32_t ctrlSoftwareSync{0x00000080U};
		constexpr static uint32_t ctrlTrimMask{0x00003f00U};

		// Configuration register constants
		constexpr static uint32_t configReloadMask{0x0000ffffU};
		constexpr static uint32_t configFreqErrorLimitMask{0x00ff0000U};
		constexpr static uint32_t configSyncDividerMask{0x07000000U};
		constexpr static uint32_t configSyncSourceMask{0x30000000U};
		constexpr static uint32_t configSyncSourceCRSSync{0x00000000U};
		constexpr static uint32_t configSyncSourceLSE{0x10000000U};
		constexpr static uint32_t configSyncSourceUSBSOF{0x20000000U};
		constexpr static uint32_t configSyncRising{0x00000000U};
		constexpr static uint32_t configSyncFalling{0x80000000U};

		constexpr inline uint32_t configFreqErrorLimit(const uint8_t limit) noexcept
			{ return static_cast<uint32_t>(limit) << 16U; }
		// XXX: This needs the division factors switch-case'd
		constexpr inline uint32_t configSyncDivider(const uint8_t divider) noexcept
			{ return static_cast<uint32_t>(divider & 0x07U) << 24U; }
	} // namespace crs

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

		// Backup domain control register constants
		constexpr static uint32_t backupDomainCtrlLSIEnable{0x00000001U};
		constexpr static uint32_t backupDomainCtrlLSIReady{0x00000002U};
		constexpr static uint32_t backupDomainCtrlLSEBypass{0x00000004U};
		constexpr static uint32_t backupDomainCtrlLSEDriveMask{0x00000018U};
		constexpr static uint32_t backupDomainCtrlLSEDriveLow{0x00000000U};
		constexpr static uint32_t backupDomainCtrlLSEDriveMediumLow{0x00000008U};
		constexpr static uint32_t backupDomainCtrlLSEDriveMediumHigh{0x00000010U};
		constexpr static uint32_t backupDomainCtrlLSEDriveHigh{0x00000018U};
		constexpr static uint32_t backupDomainCtrlLSESecEnable{0x00000020U};
		constexpr static uint32_t backupDomainCtrlLSESecFailDetected{0x00000040U};
		constexpr static uint32_t backupDomainCtrlRTCClockMask{0x00000300U};
		constexpr static uint32_t backupDomainCtrlRTCClockNone{0x00000000U};
		constexpr static uint32_t backupDomainCtrlRTCClockLSE{0x00000100U};
		constexpr static uint32_t backupDomainCtrlRTCClockLSI{0x00000200U};
		constexpr static uint32_t backupDomainCtrlRTCClockDividedHSE{0x00000300U};
		constexpr static uint32_t backupDomainCtrlRTCEnable{0x00008000U};
		constexpr static uint32_t backupDomainCtrlDomainReset{0x00010000U};

		// Clock control and status register constants
		constexpr static uint32_t clockCtrlStatusLSIEnable{0x00000001U};
		constexpr static uint32_t clockCtrlStatusLSIReady{0x00000002U};

		// AHB3 peripheral reset register constants
		constexpr static uint32_t ahb3ResetMDMA{0x00000001U};
		constexpr static uint32_t ahb3ResetDMA2D{0x00000010U};
		constexpr static uint32_t ahb3ResetFMC{0x00001000U};
		constexpr static uint32_t ahb3ResetOctoSPI1{0x00004000U};
		constexpr static uint32_t ahb3ResetSDMMC1{0x00010000U};
		constexpr static uint32_t ahb3ResetOctoSPI2{0x00080000U};
		constexpr static uint32_t ahb3ResetOctoSPIIOManager{0x00200000U};
		constexpr static uint32_t ahb3ResetOTFDec1{0x00400000U};
		constexpr static uint32_t ahb3ResetOTFDec2{0x00800000U};
		constexpr static uint32_t ahb3ResetCPU{0x80000000U};

		// AHB1 peripheral reset register constants
		constexpr static uint32_t ahb1ResetDMA1{0x00000001U};
		constexpr static uint32_t ahb1ResetDMA2{0x00000002U};
		constexpr static uint32_t ahb1ResetADC1_2{0x00000020U};
		constexpr static uint32_t ahb1ResetEth1MAC{0x00008000U};
		constexpr static uint32_t ahb1ResetUSB1HS{0x02000000U};

		// AHB2 peripheral reset register constants
		constexpr static uint32_t ahb2ResetDCMI_PSSI{0x00000001U};
		constexpr static uint32_t ahb2ResetCrypt{0x00000010U};
		constexpr static uint32_t ahb2ResetHash{0x00000020U};
		constexpr static uint32_t ahb2ResetRNG{0x00000040U};
		constexpr static uint32_t ahb2ResetSDMMC2{0x00000200U};
		constexpr static uint32_t ahb2ResetFMAC{0x00010000U};
		constexpr static uint32_t ahb2ResetCORDIC{0x00020000U};

		// AHB4 peripheral reset register constants
		constexpr static uint32_t ahb4ResetGPIOA{0x00000001U};
		constexpr static uint32_t ahb4ResetGPIOB{0x00000002U};
		constexpr static uint32_t ahb4ResetGPIOC{0x00000004U};
		constexpr static uint32_t ahb4ResetGPIOD{0x00000008U};
		constexpr static uint32_t ahb4ResetGPIOE{0x00000010U};
		constexpr static uint32_t ahb4ResetGPIOF{0x00000020U};
		constexpr static uint32_t ahb4ResetGPIOG{0x00000040U};
		constexpr static uint32_t ahb4ResetGPIOH{0x00000080U};
		constexpr static uint32_t ahb4ResetGPIOJ{0x00000200U};
		constexpr static uint32_t ahb4ResetGPIOK{0x00000400U};
		constexpr static uint32_t ahb4ResetCRC{0x00080000U};
		constexpr static uint32_t ahb4ResetBDMA{0x00200000U};
		constexpr static uint32_t ahb4ResetADC3{0x01000000U};
		constexpr static uint32_t ahb4ResetHSEM{0x02000000U};

		// APB3 peripheral reset register constants
		constexpr static uint32_t apb3ResetLTDC{0x00000008U};

		// AHB3 peripheral reset register 1 constants
		constexpr static uint32_t apb1Reset1TIM2{0x00000001U};
		constexpr static uint32_t apb1Reset1TIM3{0x00000002U};
		constexpr static uint32_t apb1Reset1TIM4{0x00000004U};
		constexpr static uint32_t apb1Reset1TIM5{0x00000008U};
		constexpr static uint32_t apb1Reset1TIM6{0x00000010U};
		constexpr static uint32_t apb1Reset1TIM7{0x00000020U};
		constexpr static uint32_t apb1Reset1TIM12{0x00000040U};
		constexpr static uint32_t apb1Reset1TIM13{0x00000080U};
		constexpr static uint32_t apb1Reset1TIM14{0x00000100U};
		constexpr static uint32_t apb1Reset1LPTIM1{0x00000200U};
		constexpr static uint32_t apb1Reset1SPI2{0x00004000U};
		constexpr static uint32_t apb1Reset1SPI3{0x00008000U};
		constexpr static uint32_t apb1Reset1SPDIFRX{0x00010000U};
		constexpr static uint32_t apb1Reset1USART2{0x00020000U};
		constexpr static uint32_t apb1Reset1USART3{0x00040000U};
		constexpr static uint32_t apb1Reset1UART4{0x00080000U};
		constexpr static uint32_t apb1Reset1UART5{0x00100000U};
		constexpr static uint32_t apb1Reset1I2C1{0x00200000U};
		constexpr static uint32_t apb1Reset1I2C2{0x00400000U};
		constexpr static uint32_t apb1Reset1I2C3{0x00800000U};
		constexpr static uint32_t apb1Reset1I2C5{0x02000000U};
		constexpr static uint32_t apb1Reset1HDMI_CEC{0x08000000U};
		constexpr static uint32_t apb1Reset1DAC1_2{0x20000000U};
		constexpr static uint32_t apb1Reset1UART7{0x40000000U};
		constexpr static uint32_t apb1Reset1UART8{0x80000000U};

		// AHB3 peripheral reset register 2 constants
		constexpr static uint32_t apb1Reset2CRS{0x00000002U};
		constexpr static uint32_t apb1Reset2SWPMI{0x00000004U};
		constexpr static uint32_t apb1Reset2OpAmp{0x00000010U};
		constexpr static uint32_t apb1Reset2MDIOS{0x00000020U};
		constexpr static uint32_t apb1Reset2FDCAN{0x00000100U};
		constexpr static uint32_t apb1Reset2TIM23{0x01000000U};
		constexpr static uint32_t apb1Reset2TIM24{0x02000000U};

		// APB2 peripheral reset register constants
		constexpr static uint32_t apb2ResetTIM1{0x00000001U};
		constexpr static uint32_t apb2ResetTIM8{0x00000002U};
		constexpr static uint32_t apb2ResetUSART1{0x00000010U};
		constexpr static uint32_t apb2ResetUSART6{0x00000020U};
		constexpr static uint32_t apb2ResetUART9{0x00000040U};
		constexpr static uint32_t apb2ResetUSART10{0x00000080U};
		constexpr static uint32_t apb2ResetSPI1{0x00001000U};
		constexpr static uint32_t apb2ResetSPI4{0x00002000U};
		constexpr static uint32_t apb2ResetTIM15{0x00010000U};
		constexpr static uint32_t apb2ResetTIM16{0x00020000U};
		constexpr static uint32_t apb2ResetTIM17{0x00040000U};
		constexpr static uint32_t apb2ResetSPI5{0x00100000U};
		constexpr static uint32_t apb2ResetSAI1{0x00400000U};
		constexpr static uint32_t apb2ResetDFSDM1{0x40000000U};

		// APB4 peripheral reset register constants
		constexpr static uint32_t apb4ResetSysCfg{0x00000002U};
		constexpr static uint32_t apb4ResetLPUART1{0x00000008U};
		constexpr static uint32_t apb4ResetSPI6{0x00000020U};
		constexpr static uint32_t apb4ResetI2C4{0x00000080U};
		constexpr static uint32_t apb4ResetLPTIM2{0x00000200U};
		constexpr static uint32_t apb4ResetLPTIM3{0x00000400U};
		constexpr static uint32_t apb4ResetLPTIM4{0x00000800U};
		constexpr static uint32_t apb4ResetLPTIM5{0x00001000U};
		constexpr static uint32_t apb4ResetComp1_2{0x00002000U};
		constexpr static uint32_t apb4ResetVRefBuf{0x00004000U};
		constexpr static uint32_t apb4ResetSAI4{0x00200000U};
		constexpr static uint32_t apb4ResetDTS{0x04000000U};

		// Globally controled peripheral reset register constants
		constexpr static uint32_t globalCtrlWWDG1ResetScope{0x00000001U};

		// Domain 3 autonomous mode register constants
		constexpr static uint32_t domain3AutonomousModeBDMAEnable{0x00000001U};
		constexpr static uint32_t domain3AutonomousModeLPUART1Enable{0x00000008U};
		constexpr static uint32_t domain3AutonomousModeSPI6Enable{0x00000020U};
		constexpr static uint32_t domain3AutonomousModeI2C4Enable{0x00000080U};
		constexpr static uint32_t domain3AutonomousModeLPTIM2Enable{0x00000200U};
		constexpr static uint32_t domain3AutonomousModeLPTIM3Enable{0x00000400U};
		constexpr static uint32_t domain3AutonomousModeLPTIM4Enable{0x00000800U};
		constexpr static uint32_t domain3AutonomousModeLPTIM5Enable{0x00001000U};
		constexpr static uint32_t domain3AutonomousModeComp1_2Enable{0x00004000U};
		constexpr static uint32_t domain3AutonomousModeVRefEnable{0x00008000U};
		constexpr static uint32_t domain3AutonomousModeRTCEnable{0x00010000U};
		constexpr static uint32_t domain3AutonomousModeCRCEnable{0x00080000U};
		constexpr static uint32_t domain3AutonomousModeSAI4Enable{0x00200000U};
		constexpr static uint32_t domain3AutonomousModeADC3Enable{0x01000000U};
		constexpr static uint32_t domain3AutonomousModeDTSEnable{0x04000000U};
		constexpr static uint32_t domain3AutonomousModeBRKAMEnable{0x10000000U};
		constexpr static uint32_t domain3AutonomousModeSRAM4Enable{0x20000000U};

		// Reset status register constants
		constexpr static uint32_t resetStatusClearFlags{0x00010000U};
		constexpr static uint32_t resetStatusCPU{0x00020000U};
		constexpr static uint32_t resetStatusDomain1{0x00080000U};
		constexpr static uint32_t resetStatusDomain2{0x00100000U};
		constexpr static uint32_t resetStatusBOR{0x00200000U};
		constexpr static uint32_t resetStatusResetPin{0x00400000U};
		constexpr static uint32_t resetStatusPOR{0x00800000U};
		constexpr static uint32_t resetStatusSystem{0x01000000U};
		constexpr static uint32_t resetStatusIWDG1{0x04000000U};
		constexpr static uint32_t resetStatusWWDG1{0x10000000U};
		constexpr static uint32_t resetStatusLowPowerError{0x40000000U};

		// AHB3 peripheral enable register constants
		constexpr static uint32_t ahb3EnableMDMA{0x00000001U};
		constexpr static uint32_t ahb3EnableDMA2D{0x00000010U};
		constexpr static uint32_t ahb3EnableFMC{0x00001000U};
		constexpr static uint32_t ahb3EnableOctoSPI1{0x00004000U};
		constexpr static uint32_t ahb3EnableSDMMC1{0x00010000U};
		constexpr static uint32_t ahb3EnableOctoSPI2{0x00800000U};
		constexpr static uint32_t ahb3EnableOctoSPIIOManager{0x02000000U};
		constexpr static uint32_t ahb3EnableOTFDec1{0x04000000U};
		constexpr static uint32_t ahb3EnableOTFDec2{0x08000000U};

		// AHB1 peripheral enable register constants
		constexpr static uint32_t ahb1EnableDMA1{0x00000001U};
		constexpr static uint32_t ahb1EnableDMA2{0x00000002U};
		constexpr static uint32_t ahb1EnableADC1_2{0x00000020U};
		constexpr static uint32_t ahb1EnableEth1MAC{0x00008000U};
		constexpr static uint32_t ahb1EnableEth1Tx{0x00010000U};
		constexpr static uint32_t ahb1EnableEth1Rx{0x00020000U};
		constexpr static uint32_t ahb1EnableUSB1HS{0x02000000U};
		constexpr static uint32_t ahb1EnableUSB1Phy{0x04000000U};

		// AHB2 peripheral enable register constants
		constexpr static uint32_t ahb2EnableDCMI_PSSI{0x00000001U};
		constexpr static uint32_t ahb2EnableCrypt{0x00000010U};
		constexpr static uint32_t ahb2EnableHash{0x00000020U};
		constexpr static uint32_t ahb2EnableRNG{0x00000040U};
		constexpr static uint32_t ahb2EnableSDMMC2{0x00000200U};
		constexpr static uint32_t ahb2EnableFMAC{0x00010000U};
		constexpr static uint32_t ahb2EnableCORDIC{0x00020000U};
		constexpr static uint32_t ahb2EnableSRAM1{0x20000000U};
		constexpr static uint32_t ahb2EnableSRAM2{0x40000000U};

		// AHB4 peripheral enable register constants
		constexpr static uint32_t ahb4EnableGPIOA{0x00000001U};
		constexpr static uint32_t ahb4EnableGPIOB{0x00000002U};
		constexpr static uint32_t ahb4EnableGPIOC{0x00000004U};
		constexpr static uint32_t ahb4EnableGPIOD{0x00000008U};
		constexpr static uint32_t ahb4EnableGPIOE{0x00000010U};
		constexpr static uint32_t ahb4EnableGPIOF{0x00000020U};
		constexpr static uint32_t ahb4EnableGPIOG{0x00000040U};
		constexpr static uint32_t ahb4EnableGPIOH{0x00000080U};
		constexpr static uint32_t ahb4EnableGPIOJ{0x00000200U};
		constexpr static uint32_t ahb4EnableGPIOK{0x00000400U};
		constexpr static uint32_t ahb4EnableCRC{0x00080000U};
		constexpr static uint32_t ahb4EnableBDMA{0x00200000U};
		constexpr static uint32_t ahb4EnableADC3{0x01000000U};
		constexpr static uint32_t ahb4EnableHSEM{0x02000000U};
		constexpr static uint32_t ahb4EnableBKRAM{0x10000000U};

		// APB3 peripheral enable register constants
		constexpr static uint32_t apb3EnableLTDC{0x00000008U};
		constexpr static uint32_t apb3EnableWWDG1{0x00000040U};

		// APB1 peripheral enable register 1 constants
		constexpr static uint32_t apb1Enable1TIM2{0x00000001U};
		constexpr static uint32_t apb1Enable1TIM3{0x00000002U};
		constexpr static uint32_t apb1Enable1TIM4{0x00000004U};
		constexpr static uint32_t apb1Enable1TIM5{0x00000008U};
		constexpr static uint32_t apb1Enable1TIM6{0x00000010U};
		constexpr static uint32_t apb1Enable1TIM7{0x00000020U};
		constexpr static uint32_t apb1Enable1TIM12{0x00000040U};
		constexpr static uint32_t apb1Enable1TIM13{0x00000080U};
		constexpr static uint32_t apb1Enable1TIM14{0x00000100U};
		constexpr static uint32_t apb1Enable1LPTIM1{0x00000200U};
		constexpr static uint32_t apb1Enable1SPI2{0x00004000U};
		constexpr static uint32_t apb1Enable1SPI3{0x00008000U};
		constexpr static uint32_t apb1Enable1SPDIFRX{0x00010000U};
		constexpr static uint32_t apb1Enable1USART2{0x00020000U};
		constexpr static uint32_t apb1Enable1USART3{0x00040000U};
		constexpr static uint32_t apb1Enable1UART4{0x00080000U};
		constexpr static uint32_t apb1Enable1UART5{0x00100000U};
		constexpr static uint32_t apb1Enable1I2C1{0x00200000U};
		constexpr static uint32_t apb1Enable1I2C2{0x00400000U};
		constexpr static uint32_t apb1Enable1I2C3{0x00800000U};
		constexpr static uint32_t apb1Enable1I2C5{0x02000000U};
		constexpr static uint32_t apb1Enable1HDMI_CEC{0x08000000U};
		constexpr static uint32_t apb1Enable1DAC1_2{0x20000000U};
		constexpr static uint32_t apb1Enable1UART7{0x40000000U};
		constexpr static uint32_t apb1Enable1UART8{0x80000000U};

		// APB1 peripheral enable register 2 constants
		constexpr static uint32_t apb1Enable2CRS{0x00000002U};
		constexpr static uint32_t apb1Enable2SWPMI{0x00000004U};
		constexpr static uint32_t apb1Enable2OpAmp{0x00000010U};
		constexpr static uint32_t apb1Enable2DMIOS{0x00000020U};
		constexpr static uint32_t apb1Enable2FDCAN{0x00000100U};
		constexpr static uint32_t apb1Enable2TIM23{0x01000000U};
		constexpr static uint32_t apb1Enable2TIM24{0x02000000U};

		// APB2 peripheral enable register constants
		constexpr static uint32_t apb2EnableTIM1{0x00000001U};
		constexpr static uint32_t apb2EnableTIM8{0x00000002U};
		constexpr static uint32_t apb2EnableUSART1{0x00000010U};
		constexpr static uint32_t apb2EnableUSART6{0x00000020U};
		constexpr static uint32_t apb2EnableUART9{0x00000040U};
		constexpr static uint32_t apb2EnableUSART10{0x00000080U};
		constexpr static uint32_t apb2EnableSPI1{0x00001000U};
		constexpr static uint32_t apb2EnableSPI4{0x00002000U};
		constexpr static uint32_t apb2EnableTIM15{0x00010000U};
		constexpr static uint32_t apb2EnableTIM16{0x00020000U};
		constexpr static uint32_t apb2EnableTIM17{0x00040000U};
		constexpr static uint32_t apb2EnableSPI5{0x00100000U};
		constexpr static uint32_t apb2EnableSAI1{0x00400000U};
		constexpr static uint32_t apb2EnableDFSDM1{0x40000000U};

		// APB4 peripheral enable register constants
		constexpr static uint32_t apb4EnableSysCfg{0x00000002U};
		constexpr static uint32_t apb4EnableLPUART1{0x00000008U};
		constexpr static uint32_t apb4EnableSPI6{0x00000020U};
		constexpr static uint32_t apb4EnableI2C4{0x00000080U};
		constexpr static uint32_t apb4EnableLPTIM2{0x00000200U};
		constexpr static uint32_t apb4EnableLPTIM3{0x00000400U};
		constexpr static uint32_t apb4EnableLPTIM4{0x00000800U};
		constexpr static uint32_t apb4EnableLPTIM5{0x00001000U};
		constexpr static uint32_t apb4EnableComp1_2{0x00004000U};
		constexpr static uint32_t apb4EnableVRefBuf{0x00008000U};
		constexpr static uint32_t apb4EnableRTCAPB{0x00010000U};
		constexpr static uint32_t apb4EnableSAI4{0x00200000U};
		constexpr static uint32_t apb4EnableDTS{0x04000000U};
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
