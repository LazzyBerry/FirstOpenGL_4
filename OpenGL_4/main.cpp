#include <gl/glut.h>
#include <iostream>

//外部変数
int status = 0; //ボタンの状態


//各種コールバック関数

//ディスプレイ
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.f, 0.f);

	glutWireTeapot(1.0); //ティーポットを描画

	glFlush();
}

//ウィンドウサイズを変更した際
void reshape(int w, int h)
{
	glViewport(0, 0, w, h);//ビューポートの設定

	glMatrixMode(GL_PROJECTION);//射影行列の設定
	glLoadIdentity();
	gluPerspective(30, (double)w / h, 1.0, 100.0);

	glMatrixMode(GL_MODELVIEW); //モデルビュー行列の設定
	glLoadIdentity();
	gluLookAt(3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

//メイン関数

int main(int argc, char* argv[])
{
	glutInit(&argc, argv); //GLUTの初期化

	//Windowの作成
	glutInitWindowSize(640, 480);
	glutInitDisplayMode(GLUT_RGBA); //ディスプレイモード
	glutCreateWindow("3DGraphics");

	//コールバック関数登録
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	//カラーバッファの初期化
	glClearColor(1.f, 1.f, 1.f, 1.f);

	glutMainLoop(); //メインループへ

	return 0;
}