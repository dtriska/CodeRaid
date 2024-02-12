import os
import sys
import tty
import termios

class MazeGame:
    def __init__(self, maze):
        self.maze = maze
        self.player_pos = self.find_start_position()
        self.game_over = False

    def find_start_position(self):
        for y, row in enumerate(self.maze):
            for x, cell in enumerate(row):
                if cell == 'S':
                    return (x, y)
        return None

    def move_player(self, direction):
        x, y = self.player_pos
        new_x, new_y = x, y

        if direction == 'up':
            new_y -= 1
        elif direction == 'down':
            new_y += 1
        elif direction == 'left':
            new_x -= 1
        elif direction == 'right':
            new_x += 1

        if 0 <= new_y < len(self.maze) and 0 <= new_x < len(self.maze[0]):
            if self.maze[new_y][new_x] != '#':
                self.player_pos = (new_x, new_y)
                if self.maze[new_y][new_x] == 'E':
                    self.game_over = True
            else:
                print("You can't go through walls!")

    def display_maze(self):
        os.system('clear')
        for y, row in enumerate(self.maze):
            for x, cell in enumerate(row):
                if (x, y) == self.player_pos:
                    print('P', end='')
                else:
                    print(cell, end='')
            print()

    def play(self):
        self.display_maze()

        while not self.game_over:
            direction = input("Enter direction (up/down/left/right): ").lower()
            self.move_player(direction)
            self.display_maze()

        print("Congratulations! You reached the end of the maze.")

def main():
    maze = [
        "#####",
        "#S  #",
        "# # #",
        "#   #",
        "###E#"
    ]

    game = MazeGame(maze)
    game.play()

if __name__ == "__main__":
    main()
