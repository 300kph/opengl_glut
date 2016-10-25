#include <GL/glut.h>
static int rotate = 0;
static float translate = 3.0;
GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;
void init(void)
{
    glClearColor (0.8, 0.8, 0.8, 0.0);
    glShadeModel (GL_FLAT);
}
void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 0.0, 0.0);
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(0.0,0.0,-translate);
    glRotatef(X,1.0,0.0,0.0);
    glRotatef(Y,0.0,1.0,0.0);
    glRotatef(Z,0.0,0.0,1.0);
    glutWireSphere(1,10,10);//边长为 1.0 的立方体
    glPopMatrix();
    glLoadIdentity();
    glTranslatef(0.0,0.0,-translate);
    glBegin(GL_LINES);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(2.5, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 2.5, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 1.5);
    glEnd();
    glFlush();
}
void reshape (int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0,1.0,-1.0,1.0,1.0,5.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void keyboard(unsigned char key, int x,int y)
{
    //该函数是键盘响应函数
    switch(key)
    {
    case 'z':
        Z += 5.0f;
        glutPostRedisplay();//调用 display 函数,重新显示一遍
        break;
    case 'x':
        X += 5.0f;
        glutPostRedisplay();
        break;
    case 'y':
        Y += 5.0f;
        glutPostRedisplay();
        break;
    default:
        break;
    }
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (250, 250);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("OpenGL Transform Demo");
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);// 注册键盘响应函数
    glutMainLoop();
    return 0;
}
