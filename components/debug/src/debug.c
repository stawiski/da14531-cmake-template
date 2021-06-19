#include <debug.h>

#include <da1458x_config_basic.h>
#include <da1458x_config_advanced.h>
#include <da1458x_scatter_config.h>
#include <rwip_config.h>
#include <ke_mem.h>

void Debug_CrashHandler(void)
{
    Debug_PrintMemoryUsage();
    __BKPT(0);
}

static void printMemory(const char* name, uint8_t type, uint16_t size)
{
    uint16_t usage = ke_get_mem_usage(type);
    DEBUG_PRINTF("%s = %d / %d (%.1f%%)\r\n", name, usage, size, ((float)usage*100.0f)/(float)size);
}

void Debug_PrintMemoryUsage(void)
{
    DEBUG_PRINTF("Mem usage:\r\n");
    printMemory("ENV", KE_MEM_ENV, __SCT_HEAP_ENV_SIZE);
    printMemory("ATT_DB", KE_MEM_ATT_DB, __SCT_HEAP_DB_SIZE);
    printMemory("KE_MSG", KE_MEM_KE_MSG, __SCT_HEAP_MSG_SIZE);
    printMemory("NON_RET", KE_MEM_NON_RETENTION, __SCT_HEAP_NON_RET_SIZE);
    DEBUG_PRINTF("MAX = %lu\r\n", (uint32_t)ke_get_max_mem_usage());
}

void Debug_Breakpoint(void)
{
    __BKPT(0);
}
