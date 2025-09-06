import pygame, math
pygame.init()
screen = pygame.display.set_mode((500,500))
screen.fill((0,0,0))
pygame.draw.circle(screen,(255,255,255),(250,250),200,1)

#for your reference: here's how to draw a simple circle with trig functions
#centered at 250, 250 and with a radius of 200
for i in range(360):
    angle = math.radians(i)   # turn degrees into radians
    x = 250 + int(200 * math.cos(angle))
    y = 250 + int(200 * math.sin(angle))
    pygame.draw.circle(screen, (250,0,0), (x,y), 2)  


#here's the code to do the lines across the circle:
    
N = 180   # how many dots we place around the circle
a = 10    # how big of a jump we take when we connect lines

for i in range(N):
    # angle for the first dot
    t1 = 2*math.pi*i/N

    # figure out which other dot to connect to
    j  = (a*i) % N        # "jump" a*i
    t2 = 2*math.pi*j/N

    # first endpoint for the line
    x1 = 250 + int(200*math.cos(t1))
    y1 = 250 + int(200*math.sin(t1))

    # second endpoint for the line
    x2 = 250 + int(200*math.cos(t2))
    y2 = 250 + int(200*math.sin(t2))

    # draw the line between the two dots
    pygame.draw.line(screen,(255,255,255),(x1,y1),(x2,y2),1)

pygame.display.flip()

