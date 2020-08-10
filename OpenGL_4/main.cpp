#include <gl/glut.h>
#include <iostream>

//�O���ϐ�
int status = 0; //�{�^���̏��


//�e��R�[���o�b�N�֐�

//�f�B�X�v���C
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.f, 0.f);

	glutWireTeapot(1.0); //�e�B�[�|�b�g��`��

	glFlush();
}

//�E�B���h�E�T�C�Y��ύX������
void reshape(int w, int h)
{
	glViewport(0, 0, w, h);//�r���[�|�[�g�̐ݒ�

	glMatrixMode(GL_PROJECTION);//�ˉe�s��̐ݒ�
	glLoadIdentity();
	gluPerspective(30, (double)w / h, 1.0, 100.0);

	glMatrixMode(GL_MODELVIEW); //���f���r���[�s��̐ݒ�
	glLoadIdentity();
	gluLookAt(3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

//���C���֐�

int main(int argc, char* argv[])
{
	glutInit(&argc, argv); //GLUT�̏�����

	//Window�̍쐬
	glutInitWindowSize(640, 480);
	glutInitDisplayMode(GLUT_RGBA); //�f�B�X�v���C���[�h
	glutCreateWindow("3DGraphics");

	//�R�[���o�b�N�֐��o�^
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	//�J���[�o�b�t�@�̏�����
	glClearColor(1.f, 1.f, 1.f, 1.f);

	glutMainLoop(); //���C�����[�v��

	return 0;
}