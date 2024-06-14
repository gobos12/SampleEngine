#pragma once

#include "SubObject.h"

#include <Uxtheme.h>
	#pragma comment(lib, "uxtheme.lib")

namespace Win32
{
	class ENGINE_API Window : public Win32::SubObject
	{
	public:
		Window(std::wstring classTitle, HICON icon, WindowType type  = RESIZEABLE);
		~Window();

		virtual VOID Initialize() override;
		virtual LRESULT MessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) override;

		VOID RedrawWindow();

		VOID OnNonClientCreate();

		VOID OnNonClientPaint(HRGN region);

	protected:
		SIZE		m_Size;
		WindowType  m_Type;

	public:
		SIZE		Size() { return m_Size; }

	public:
		VOID		Size(SIZE size) { m_Size = size; }
		VOID		Size(INT cx, INT cy) { m_Size.cx = cx; m_Size.cy = cy; }
	};
}