#include "shell.h"

/**
 * get_hist_file - gets the history file
 * @info: structure of parameter
 *
 * Return: allocated string containg history file
 */

char *get_hist_file(info_t *info)
{
	char *buf, *dir;

	dir = _getenv(info, "HOME=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, dir);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);
	return (buf);
}

/**
 * write_hist - creates a file, or appends to an existing file
 * @info: Structure of the parametre
 *
 * Return: 1 on success, else -1
 */
int write_hist(info_t *info)
{
	ssize_t f_dscr;
	char *filename = get_hist_file(info);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	f_dscr = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (f_dscr == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_putsf_dscr(node->str, f_dscr);
		_putf_dscr('\n', f_dscr);
	}
	_putf_dscr(BUF_FLUSH, f_dscr);
	close(f_dscr);
	return (1);
}

/**
 * read_hist - reads history from file
 * @info: Structure of the parametre
 *
 * Return: histcount on success, else return 0
 */
int read_hist(info_t *info)
{
	int i, last = 0, linecount = 0;
	ssize_t f_dscr, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_hist_file(info);

	if (!filename)
		return (0);

	f_dscr = open(filename, O_RDONLY);
	free(filename);
	if (f_dscr == -1)
		return (0);
	if (!fstat(f_dscr, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(f_dscr, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(f_dscr);
	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			build_hist_list(info, buf + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		build_hist_list(info, buf + last, linecount++);
	free(buf);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_hist(info);
	return (info->histcount);
}

/**
 * build_hist_list - adds entry to a history linked list
 * @info: Structure with potential arguments. Used to maintains
 * @buf: buffer
 * @linecount: the history linecount, histcount
 *
 * Return: 0
 */
int build_hist_list(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	add_node_end(&node, buf, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * renumber_hist - renumbers the history linked list after changes
 * @info: Structure with potential arguments. Used to maintains
 *
 * Return: the new histcount
 */
int renumber_hist(info_t *info)
{
	list_t *node = info->history;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (info->histcount = i);
}
