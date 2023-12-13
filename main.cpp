#include <Novice.h>
#include "Mymath.h"
#include "Quaternion.h"
#include "ImGuiManager.h"

const char kWindowTitle[] = "LE2B_10_kusama";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		Quaternion rotation = MakeRotateAxisAngleQuaternion(Normalize(Vector3{ 1.0f,0.4f,-0.2f }), 0.45f);
		Vector3 pointY = { 2.1f,-0.9f,1.3f };
		Matrix4x4 rotateMatrix = MakeRotateMatrix(rotation);
		Vector3 rotateByQuaternion = RotateVector(pointY, rotation);
		Vector3 rotateByMatrix = Transform(pointY, rotateMatrix);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		ImGui::Begin("qaternion");
		ImGui::Text("rotate");
		ImGui::Text(" %1.2f %1.2f %1.2f %1.2f", rotation.x, rotation.y, rotation.z, rotation.w);
		ImGui::Text("rotateMatrix");
		ImGui::Text(" %1.3f %1.3f %1.3f %1.3f", rotateMatrix.m[0][0], rotateMatrix.m[0][1], rotateMatrix.m[0][2], rotateMatrix.m[0][3]);
		ImGui::Text(" %1.3f %1.3f %1.3f %1.3f", rotateMatrix.m[1][0], rotateMatrix.m[1][1], rotateMatrix.m[1][2], rotateMatrix.m[1][3]);
		ImGui::Text(" %1.3f %1.3f %1.3f %1.3f", rotateMatrix.m[2][0], rotateMatrix.m[2][1], rotateMatrix.m[2][2], rotateMatrix.m[2][3]);
		ImGui::Text(" %1.3f %1.3f %1.3f %1.3f", rotateMatrix.m[3][0], rotateMatrix.m[3][1], rotateMatrix.m[3][2], rotateMatrix.m[3][3]);
		ImGui::Text("rotateByQuaternion");
		ImGui::Text(" %1.2f %1.2f %1.2f", rotateByQuaternion.x, rotateByQuaternion.y, rotateByQuaternion.z);
		ImGui::Text("rotateByMatrix");
		ImGui::Text(" %1.2f %1.2f %1.2f", rotateByMatrix.x, rotateByMatrix.y, rotateByMatrix.z);

		ImGui::End();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
