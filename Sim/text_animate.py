'''
Modify the input_strings array with frames of your image.
Create image according to format:
- special chars:
- * - for space
- ` - for newline
Do NOT use the special chars for cosmetic purpose, they will be overwritten


AUTHOR: Caleb "H1vac" B
'''


import pygame
import time

def transform_string(s):
    return ["\n" if c == '`' else (' ' if c == '*' else c) for c in s]

def animate_strings(strings, font_size=20, delay=0.2):
    pygame.init()
    screen = pygame.display.set_mode((400, 300))
    pygame.display.set_caption("String Animation")
    font = pygame.font.Font(None, font_size)
    
    running = True
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
        
        screen.fill((0, 0, 0))  # Black background
        y_offset = 50
        
        for frame in strings:
            screen.fill((0, 0, 0))
            y = y_offset
            for line in frame.split('\n'):
                text_surface = font.render(line, True, (255, 255, 255))
                screen.blit(text_surface, (50, y))
                y += font_size
            
            pygame.display.flip()
            time.sleep(delay)
        
    pygame.quit()

# Example usage
input_strings = ["hello*world", "h*e*l*l*o`", "*****world`"]
#input_strings = ["*************`*****^**^****`****(@__@)***`*****BBB*****`****$%^&*****`***$%^&******`*************`","*******^**^**`******(@__@)*`*******BBB***`******$%^&***`*****$%^&****`*************`*************`"
]




transformed_strings = ["".join(transform_string(s)) for s in input_strings]
animate_strings(transformed_strings)
