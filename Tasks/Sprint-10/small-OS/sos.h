
#ifndef SOS_H_
#define SOS_H_

#define SOS_MAX_TASK_NUM        5           /* Maximum number of tasks in the system */
#define SOS_SYS_TICK            100         /* The system tick time in milli seconds */
typedef struct
{
    uint8_t_  TASK_PRIORITY     ;           /* The task's unique priority                         */
	uint16_t_ TASK_PERIODICITY  ;           /* The interval between each ready state for the task */
	void (*pvTaskFunction)(void);           /* The function to implement when task is ready       */
}str_sos_task_t_;


typedef enum
{
    SOS_STATUS_SUCCESS,
    SOS_STATUS_INVALID_STATE,
    SOS_STATUS_INVALID_TASK,
    SOS_STATUS_DB_FULL,
    SOS_STATUS_PRIORITY_ALREADY_EXISTS,
    SOS_STATUS_TASK_DOES_NOT_EXIST
}enu_system_status_t_;

/**
 * @brief Function to initialize the SOS DB
 * 
 * @return SOS_STATUS_SUCCESS      : When the OS is initialized successfully
 *         SOS_STATUS_INVALID_STATE: When OS has already been initialized
 */
enu_system_status_t_ sos_init (void);

/**
 * @brief Function to deinitialize the SOS DB
 * 
 * @return SOS_STATUS_SUCCESS      : When the OS is initialized successfully
 *         SOS_STATUS_INVALID_STATE: When OS has already been initialized
 */
enu_system_status_t_ sos_deinit (void);

/**
 * @brief Function add a task to the task DB
 * 
 * This function takes a reference to the structure of a task and
 * add it to the task DB
 * 
 * @param ptr_str_sos_task Pointer to the task to add
 * 
 * @return SOS_STATUS_SUCCESS     : When the task is modified successfully 
 *         SOS_INVALID_TASK       : When given struct pointer is NULL
 *         SOS_TASK_DOES_NOT_EXIST: When the referenced task doesn't exist in the DB
 */
enu_system_status_t_ sos_create_task (str_sos_task_t_* ptr_str_sos_task);

/**
 * @brief Function to modify the attributes of an existing task
 * 
 * This function takes a reference to the structure of an existing task 
 * (existing ID) and deletes it
 * 
 * @param ptr_str_sos_task Pointer to the task to delete
 * 
 * @return SOS_STATUS_SUCCESS     : When the task is deleted successfully 
 *         SOS_INVALID_TASK       : When given struct pointer is NULL
 *         SOS_TASK_DOES_NOT_EXIST: When the referenced task doesn't exist in the DB
 */
enu_system_status_t_ sos_delete_task (str_sos_task_t_* ptr_str_sos_task);

/**
 * @brief Function to modify the attributes of an existing task
 * 
 * This function takes a reference to the structure of an existing task 
 * (existing ID) and save it with the newly modified fields in struct 
 * 
 * @param ptr_str_sos_task Pointer to the task to modify
 * @return SOS_STATUS_SUCCESS     : When the task is modified successfully 
 *         SOS_INVALID_TASK       : When given struct pointer is NULL
 *         SOS_TASK_DOES_NOT_EXIST: When the referenced task doesn't exist in the DB
 */
enu_system_status_t_ sos_modify_task (str_sos_task_t_* ptr_str_sos_task);

/**
 * @brief Function to start the OS 
 * 
 * @return SOS_STATUS_SUCCESS      : When the OS is started successfully
 *         SOS_STATUS_INVALID_STATE: When the OS has not been initialized
 */
enu_system_status_t_ sos_run (void);

/**
 * @brief Function to stop the OS 
 * 
 * @return SOS_STATUS_SUCCESS      : When the OS is stopped successfully
 *         SOS_STATUS_INVALID_STATE: When the OS has not been running
 */
enu_system_status_t_ sos_disable (void);

/**
 * @brief Private function to run the ready tasks at each system tick
 *        (will not be included in interface) 
 */
static void sos_scheduler(void);

#endif
