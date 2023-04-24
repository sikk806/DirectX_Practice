#include <Windows.h>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <iostream>

using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

//ostream& XM_CALLCONV operator<<(ostream& os, FXMVECTOR v) {
//	XMFLOAT3 dest;
//	XMStoreFloat3(&dest, v);
//
//	os << "(" << dest.x << ", " << dest.y << ", " << dest.z << ")";
//	return os;
//}


int main(void) {
	cout.setf(ios_base::boolalpha);

	if (!XMVerifyCPUSupport()) {
		cout << "DIrectXMath를 지원하지 않음." << endl;
		return 0;
	}

	XMVECTOR p = XMVectorZero();
	XMVECTOR q = XMVectorSplatOne();
	XMVECTOR u = XMVectorSet(1.0f, 2.0f, 3.0f, 0.0f);
	XMVECTOR v = XMVectorReplicate(-2.0f);
	XMVECTOR w = XMVectorSplatZ(u);

	FXMVECTOR temp = XMVectorSet(1.0f, 1.0f, 1.0f, 0.0f);


	XMFLOAT4 uVec4;
	XMStoreFloat4(&uVec4, u);
	cout << uVec4.x << endl;

	//XMVECTOR tmp = XMLoadFloat4(&uVec4);
	XMFLOAT4 tmp;
	tmp = uVec4;

	XMFLOAT4 minus4;
	XMStoreFloat4(&minus4, u);
	cout << minus4.x << " " << minus4.y << " " << minus4.z << endl;

	XMVECTOR a = XMVector3AngleBetweenVectors(u, temp);
	XMStoreFloat4(&minus4, a);
	cout << minus4.x << " " << minus4.y << " " << minus4.z << " " << minus4.w << endl;

	//cout << "p = " << p << endl;
	//cout << "q = " << q << endl;
	//cout << "u = " << u << endl;
	//cout << "v = " << v << endl;
	//cout << "w = " << w << endl;

	return 0;
}