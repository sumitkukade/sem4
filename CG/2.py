import pygame
from pygame.locals import *

from OpenGL.GL import *
from OpenGL.GLU import *

vertices = ((1,-1,-1),(1,1,-1),(-1,1,-1),(-1,-1,-1),(1,-1,1),(1,1,1),(-1,-1,1),(-1,1,1))
edges = ((0,1),(0,3),(0,4),(2,1),(2,3),(2,7),(6,3),(6,4),(6,7),(5,1),(5,4),(5,7))

def cube():
    glBegin(GL_LINES)
    for edge in edges:
        for vertex in edge:
            glVertex3fv(vertices[vertex])

    glEnd()

def main():
    i = 0
    j = 0
    pygame.init()
    display = (1366,768)
    pygame.display.set_mode(display,DOUBLEBUF|OPENGL)

    gluPerspective(45,(1366/768), 1.1, 90.0)

    glTranslatef(0.0,0.0,-7)
    glRotatef(0,0,0,0)
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)
        cube()
        pygame.display.flip()
        pygame.time.wait(1)
        glRotatef(1*i,1,1,1)
        j+=1
        if(j==300):
            i+=1
            j=0
            print i
main()

