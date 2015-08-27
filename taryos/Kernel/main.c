void	ClearScreen();
void	OnScreen(int x, int y, char * pszText, int nColor);

// Application entry point, invoked from Entry.obj

void main()
{
	// Display a banner.
	// ClearScreen();
	OnScreen(30, 12, "Hello World!", 14);

	while (1);
	/* NEVER EXECUTED */
}



// Clears the screen.

void ClearScreen()
{
	int x,y;
	char *	pScreen = (char *) 0xb8000;

	for (y = 0; y < 25; y++)
		for (x = 0; x < 80; x++)
		{
			*pScreen++ = ' ';
			*pScreen++ = 7;
		}
}

// Displays a string on the screen, assuming a 80x25 color adapter.

void OnScreen(int x, int y, char * pszText, int nColor)
{
	char *	pScreen = (char *) (0xb8000 + y * 160 + x * 2);

	while (*pszText)
	{
		*pScreen++ = *pszText++;
		*pScreen++ = nColor;
	}
}
