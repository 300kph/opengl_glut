#define PI 3.1415926
#include<GL/gl.h>
#include<math.h>
　
void mySphere(float r, int slices, int stacks )
{
    // r:球的半径
    // slices:经度方向上的分片数
    // stacks:纬度方向上的分片数
    glBegin(GL_TRIANGLE_FAN);
    double sita = 0,phi = 0;
    double sitaUnit = 2 * PI / slices;
    double phiUnit = PI / stacks;
    double x, y, z;
    glVertex3f(0, 0, r);
    for(int i = 0; i < slices; i++)
    {
        　
        x = r*sin(phiUnit)*cos(sita);
        y = r*sin(phiUnit)*sin(sita);
        z = r*cos(phiUnit);
        glVertex3f(x, y, z);
        sita += sitaUnit;
    }
    glEnd();
    glBegin(GL_QUAD_STRIP);
    for(int i = 0; i < stacks; i++)
    {
        sita = 0, phi = 0;
        for(int j = 0; j < slices+1; j++)
        {
            x = r * sin((i+1) * phiUnit) * cos(sita);
            y = r * sin((i+1) * phiUnit) * sin(sita);
            z = r * cos((i+1) * phiUnit);
            glVertex3d(x,y,z);
            x = r * sin(i * phiUnit) * cos(sita);
            y = r * sin(i * phiUnit) * sin(sita);
            z = r * cos(i * phiUnit);
            glVertex3d(x, y , z);
            sita += sitaUnit;
        }
        　
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0, 0, -r);
    sita = 0, phi = 0;
    for(int i = 0; i < slices; i++)
    {
        　
        x = r * sin(phiUnit) * cos(sita);
        y = r * sin(phiUnit) * sin(sita);
        z = r * cos(PI-phiUnit);
        glVertex3f(x, y, z);
        sita += sitaUnit;
    }
    glEnd();
}
