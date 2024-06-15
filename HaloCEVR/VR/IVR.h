#pragma once
#include "../Maths/Matrices.h"

typedef uint64_t InputBindingID;

enum class ControllerRole
{
	Left,
	Right
};

class IVR
{
public:
	virtual void Init() = 0;
	virtual void OnGameFinishInit() = 0;
	virtual void UpdatePoses() = 0;
	virtual void PreDrawFrame(struct Renderer* renderer, float deltaTime) = 0;
	virtual void PostDrawFrame(struct Renderer* renderer, float deltaTime) = 0;

	virtual void UpdateCameraFrustum(struct CameraFrustum* frustum, int eye) = 0;

	virtual int GetViewWidth() = 0;
	virtual int GetViewHeight() = 0;
	virtual float GetViewWidthStretch() = 0;
	virtual float GetViewHeightStretch() = 0;
	virtual float GetAspect() = 0;
	virtual void Recentre() = 0;
	virtual void SetLocationOffset(Vector3 NewOffset) = 0;
	virtual Vector3 GetLocationOffset() = 0;
	virtual void SetYawOffset(float NewOffset) = 0;
	virtual float GetYawOffset() = 0;
	virtual Matrix4 GetHMDTransform(bool bRenderPose = false) = 0;
	virtual Matrix4 GetControllerTransform(ControllerRole Role, bool bRenderPose = false) = 0;
	virtual struct IDirect3DSurface9* GetRenderSurface(int eye) = 0;
	virtual struct IDirect3DTexture9* GetRenderTexture(int eye) = 0;
	virtual struct IDirect3DSurface9* GetUISurface() = 0;

	virtual void SetMouseVisibility(bool bIsVisible) = 0;
	virtual void UpdateInputs() = 0;
	virtual InputBindingID RegisterBoolInput(std::string set, std::string action) = 0;
	virtual InputBindingID RegisterVector2Input(std::string set, std::string action) = 0;
	virtual bool GetBoolInput(InputBindingID id) = 0;
	virtual bool GetBoolInput(InputBindingID id, bool &bHasChanged) = 0;
	virtual Vector2 GetVector2Input(InputBindingID id) = 0;
	virtual Vector2 GetMousePos() = 0;
	virtual bool GetMouseDown() = 0;
};