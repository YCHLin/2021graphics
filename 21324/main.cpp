#include <GL/glut.h>
int N=0,vx[3000],vy[3000];
float angle=0;///�ŧi����
void display(void)

{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();///�ƥ��x�}
    glRotatef(angle,0,0,1);///���� ��Z�b����
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<N;i++){
        glVertex2f((vx[i]-150)/150.0,-(vy[i]-150)/150.0);
    }
    glEnd();
    glPopMatrix();///�٭�x�}
    glutSwapBuffers();
}

void keyboard(unsigned char key,int x,int y)
{
    angle++;///�[�������L��
    display();
}

void motion(int x, int y)
{
    vx[N]=x;vy[N]=y;
    N++;
    display();
}


int main(int argc, char *argv[])

{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("���F!");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);///���UKeyboard
    glutMotionFunc(motion);
    glutMainLoop();

}
