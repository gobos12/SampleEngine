#include "Engine.h"
#include "Win32Utils.h"

namespace Win32
{
	namespace Utils
	{
		/* TODO: look into functionality */
		BOOL AddBitmap(const WCHAR* szFileName, HDC hWinDC, INT x, INT y)
		{
			BITMAP qBitmap;
			HDC hLocalDC = CreateCompatibleDC(hWinDC);

			HBITMAP hBitmap = (HBITMAP)LoadImage(NULL, szFileName, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			if (hBitmap == NULL)
			{
				MessageBox(NULL, L"LoadImage Failed", L"Error", MB_OK);
				return false;
			}

			GetObject(reinterpret_cast<HGDIOBJ>(hBitmap), sizeof(BITMAP), reinterpret_cast<LPVOID>(&qBitmap));
			SelectObject(hLocalDC, hBitmap);

			if (!BitBlt(hWinDC, x, y, qBitmap.bmWidth, qBitmap.bmHeight, hLocalDC, 0, 0, SRCCOPY))
			{
				MessageBox(NULL, L"Blit Failed", L"Error", MB_OK);
				return false;
			}

			// Uninitialize & dellocate resources
			::DeleteDC(hLocalDC);
			::DeleteObject(hBitmap);
			
			return true;
		}
	}
}


