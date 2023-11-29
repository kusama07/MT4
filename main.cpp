#include <Novice.h>
#include "Mymath.h"
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
		Vector3 from0 = Normalize(Vector3{ 1.0f,0.7f,0.5f });
		Vector3 to0 = { -from0.x,-from0.y,-from0.z };
		Vector3 from1 = Normalize(Vector3{ -0.6f,0.9f,0.2f });
		Vector3 to1 = Normalize(Vector3{ 0.4f,0.7f,-0.5f });
		Matrix4x4 rotateMatrix0 = DirectionToDirection(
			Normalize(Vector3{ 1.0f,0.0f,0.0f }), Normalize(Vector3{ -1.0f,0.0f,0.0f }));
		Matrix4x4 rotateMatrix1 = DirectionToDirection(from0,to0);
		Matrix4x4 rotateMatrix2 = DirectionToDirection(from1, to1);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		ImGui::Begin("rotateMatrix");
		ImGui::Text("rotateMatrix0");
		ImGui::Text(" %1.3f %1.3f %1.3f %1.3f", rotateMatrix0.m[0][0], rotateMatrix0.m[0][1], rotateMatrix0.m[0][2], rotateMatrix0.m[0][3]);
		ImGui::Text(" %1.3f %1.3f %1.3f %1.3f", rotateMatrix0.m[1][0], rotateMatrix0.m[1][1], rotateMatrix0.m[1][2], rotateMatrix0.m[1][3]);
		ImGui::Text(" %1.3f %1.3f %1.3f %1.3f", rotateMatrix0.m[2][0], rotateMatrix0.m[2][1], rotateMatrix0.m[2][2], rotateMatrix0.m[2][3]);
		ImGui::Text(" %1.3f %1.3f %1.3f %1.3f", rotateMatrix0.m[3][0], rotateMatrix0.m[3][1], rotateMatrix0.m[3][2], rotateMatrix0.m[3][3]);
		ImGui::Text("rotateMatrix1");
		ImGui::Text(" %1.3f %1.3f %1.3f %1.3f", rotateMatrix1.m[0][0], rotateMatrix1.m[0][1], rotateMatrix1.m[0][2], rotateMatrix1.m[0][3]);
		ImGui::Text(" %1.3f %1.3f %1.3f %1.3f", rotateMatrix1.m[1][0], rotateMatrix1.m[1][1], rotateMatrix1.m[1][2], rotateMatrix1.m[1][3]);
		ImGui::Text(" %1.3f %1.3f %1.3f %1.3f", rotateMatrix1.m[2][0], rotateMatrix1.m[2][1], rotateMatrix1.m[2][2], rotateMatrix1.m[2][3]);
		ImGui::Text(" %1.3f %1.3f %1.3f %1.3f", rotateMatrix1.m[3][0], rotateMatrix1.m[3][1], rotateMatrix1.m[3][2], rotateMatrix1.m[3][3]);
		ImGui::Text("rotateMatrix2");
		ImGui::Text(" %1.3f %1.3f %1.3f %1.3f", rotateMatrix2.m[0][0], rotateMatrix2.m[0][1], rotateMatrix2.m[0][2], rotateMatrix2.m[0][3]);
		ImGui::Text(" %1.3f %1.3f %1.3f %1.3f", rotateMatrix2.m[1][0], rotateMatrix2.m[1][1], rotateMatrix2.m[1][2], rotateMatrix2.m[1][3]);
		ImGui::Text(" %1.3f %1.3f %1.3f %1.3f", rotateMatrix2.m[2][0], rotateMatrix2.m[2][1], rotateMatrix2.m[2][2], rotateMatrix2.m[2][3]);
		ImGui::Text(" %1.3f %1.3f %1.3f %1.3f", rotateMatrix2.m[3][0], rotateMatrix2.m[3][1], rotateMatrix2.m[3][2], rotateMatrix2.m[3][3]);

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
