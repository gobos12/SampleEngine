#pragma once

namespace Win32
{
	class ENGINE_API SubObject
	{
	public:
		SubObject(std::wstring className, std::wstring classTitle, HICON icon);
		~SubObject();

		virtual VOID RegisterNewClass();
		virtual VOID Initialize() = 0;

	protected:
		static LRESULT CALLBACK SetupMessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
		static LRESULT AssignMessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

		/* message handler for ALL subobjects*/
		virtual LRESULT CommonMessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

		/* message handler for inherited subobjects */
		virtual LRESULT MessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) = 0;

	protected:
		std::wstring m_Class;
		std::wstring m_Title;
		HICON m_hIcon;
		HWND m_Handle;

	public:
		HWND GetHandle() { return m_Handle; }
	};
}