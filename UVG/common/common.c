const char* confpath(void)
{
	static const char *path = NULL;
	if (path)
		return path;

	path = getenv("UVG_CONFIGPATH");

	if (path == NULL) 
    {
		/*Exit the application with error*/
	}

	return path;
}