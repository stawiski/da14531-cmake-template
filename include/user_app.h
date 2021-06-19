#ifndef USER_APP_H_
#define USER_APP_H_

#include <stdint.h>

#include <arch_api.h>
#include <ke_msg.h>
#include <arch.h>

void app_on_init(void);
void app_resume_from_sleep(void);
arch_main_loop_callback_ret_t app_on_system_powered(void);
sleep_mode_t app_validate_sleep(sleep_mode_t sleep_mode);
void app_going_to_sleep(sleep_mode_t sleep_mode);

#endif // USER_APP_H_
