

#ifndef __D3DApplication_h__
#define __D3DApplication_h__

#include <d3d11.h>
#include "Core.h"
#include "Application.h"
#include <WindowsX.h>
#include "D3DUtil.h"

NAMESPACEBEGIN(GameEngine)

class D3DApplication : public Application
{
public:
	D3DApplication(HINSTANCE mhAppInst);
	~D3DApplication();

	virtual bool Init();
	virtual int Run();
	virtual void Clear();
	virtual void Present();

	virtual bool InitQt(HWND hwnd);
	virtual void RenderQt();
	virtual void ResetQt();

	virtual void UpdateScene(float dt){}
	virtual void DrawScene();

	LRESULT MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
private:
	bool InitMainWindow();
	bool InitDirect3D(HWND hwnd);
	void CalculateFrameStats();

	virtual void OnResize();
	// Convenience overrides for handling mouse input.
	virtual void OnMouseDown(WPARAM btnState, int x, int y) { }
	virtual void OnMouseUp(WPARAM btnState, int x, int y) { }
	virtual void OnMouseMove(WPARAM btnState, int x, int y) { }
protected:
	HWND      mhMainWnd;
	bool      mAppPaused;
	bool      mMinimized;
	bool      mMaximized;
	bool      mResizing;

	UINT      m4xMsaaQuality;
	bool mEnable4xMsaa;
	ID3D11Device* md3dDevice;
	D3D_DRIVER_TYPE md3dDriverType;
	ID3D11DeviceContext* md3dImmediateContext;
	IDXGISwapChain* mSwapChain;
	ID3D11Texture2D* mDepthStencilBuffer;
	ID3D11RenderTargetView* mRenderTargetView;
	ID3D11DepthStencilView* mDepthStencilView;
	D3D11_VIEWPORT mScreenViewport;
};

NAMESPACEEND

#endif
