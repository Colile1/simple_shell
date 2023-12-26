#include "shell.h" 

/**
 * clear_info - starts info_t struct
 * @info: pointer to the info_t structure to start
 */
void clear_info(info_t *info)
{
info->arg = NULL;
info->argv = NULL;
info->path = NULL;
info->argc = 0;
}
