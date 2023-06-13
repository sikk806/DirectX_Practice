#pragma once
#ifndef _MODELCLASS_H_
#define _MODELCLASS_H_

#include "TextureClass.h"

#include <d3d11.h>
#include <directxmath.h>

using namespace DirectX;

class ModelClass
{
private:
/*
	// For Color
	struct VertexType
	{
		XMFLOAT3 position;
		XMFLOAT4 color;
	};
*/
	// For Texture
	struct VertexType
	{
		XMFLOAT3 position;
		XMFLOAT2 texture;
	};

public:
	ModelClass();
	ModelClass(const ModelClass&);
	~ModelClass();

	bool Initialize(ID3D11Device*, ID3D11DeviceContext*, char*);
	void Shutdown();
	void Render(ID3D11DeviceContext*);

	int GetIndexCount();

	// For Texture
	ID3D11ShaderResourceView* GetTexture();

private:
	bool InitializeBuffers(ID3D11Device*);
	void ShutdownBuffers();
	void RenderBuffers(ID3D11DeviceContext*);

	// For Texture
	bool LoadTexture(ID3D11Device*, ID3D11DeviceContext*, char*);
	void ReleaseTexture();

private:
	ID3D11Buffer* m_vertexBuffer, * m_indexBuffer;
	int m_vertexCount, m_indexCount;

	// For Texture
	TextureClass* m_Texture;
};

#endif
