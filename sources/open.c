int							open_file(
	char const *file,
	int *ret_fd)
{
	int		r;

	if ((*ret_fd = open(file, O_RDONLY)) < 0)
		return (SYS_ERR);
	return (SUCCESS);
}
