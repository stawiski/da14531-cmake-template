#include "ble_handlers.h"

#include <da1458x_config_basic.h>
#include <da1458x_config_advanced.h>
#include <user_config.h>
#include <rwip_config.h>

#include <ke_msg.h>
#include <custs1.h>
#include <custs1_task.h>
#include <user_custs1_def.h>
#include <user_custs1_def.h>

#include <debug.h>

static const char* msgidToString(ke_msg_id_t msgid)
{
    const char* result = "undefined";
    switch (msgid)
    {
        case CUSTS1_CREATE_DB_REQ:
        {
            result = "CUSTS1_CREATE_DB_REQ";
            break;
        }
        case CUSTS1_CREATE_DB_CFM:
        {
            result = "CUSTS1_CREATE_DB_CFM";
            break;
        }
        case CUSTS1_ENABLE_REQ:
        {
            result = "CUSTS1_ENABLE_REQ";
            break;
        }
        case CUSTS1_VAL_SET_REQ:
        {
            result = "CUSTS1_VAL_SET_REQ";
            break;
        }
        case CUSTS1_VALUE_REQ_IND:
        {
            result = "CUSTS1_VALUE_REQ_IND";
            break;
        }
        case CUSTS1_VALUE_REQ_RSP:
        {
            result = "CUSTS1_VALUE_REQ_RSP";
            break;
        }
        case CUSTS1_VAL_NTF_REQ:
        {
            result = "CUSTS1_VAL_NTF_REQ";
            break;
        }
        case CUSTS1_VAL_NTF_CFM:
        {
            result = "CUSTS1_VAL_NTF_CFM";
            break;
        }
        case CUSTS1_VAL_IND_REQ:
        {
            result = "CUSTS1_VAL_IND_REQ";
            break;
        }
        case CUSTS1_VAL_IND_CFM:
        {
            result = "CUSTS1_VAL_IND_CFM";
            break;
        }
        case CUSTS1_VAL_WRITE_IND:
        {
            result = "CUSTS1_VAL_WRITE_IND";
            break;
        }
        case CUSTS1_DISABLE_IND:
        {
            result = "CUSTS1_DISABLE_IND";
            break;
        }
        case CUSTS1_ERROR_IND:
        {
            result = "CUSTS1_ERROR_IND";
            break;
        }
        case CUSTS1_ATT_INFO_REQ:
        {
            result = "CUSTS1_ATT_INFO_REQ";
            break;
        }
        case CUSTS1_ATT_INFO_RSP:
        {
            result = "CUSTS1_ATT_INFO_RSP";
            break;
        }
        default:
        {
            break;
        }
    }
    return result;
}

void user_catch_rest_hndl(ke_msg_id_t const msgid, void const *param, ke_task_id_t const dest_id, ke_task_id_t const src_id)
{
    switch(msgid)
    {
        default:
        {
            printf("handler: %s\r\n", msgidToString(msgid));
            break;
        }
    }
}

void user_on_connection(uint8_t connection_idx, struct gapc_connection_req_ind const *param)
{
    printf("user_on_connection()\r\n");
    default_app_on_connection(connection_idx, param);
}

void user_on_disconnect( struct gapc_disconnect_ind const *param )
{
    printf("user_on_disconnect()\r\n");
    default_app_on_disconnect(param);
}
