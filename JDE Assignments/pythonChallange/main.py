import numpy as np
import json

from GameOfLife import GameOfLife

def display_buffer(pattern):
	for line in pattern:
		for pixel in line:
			#print(pixel)
			if(pixel==0.0):
				print("-",end='')
			#	print("-",end='')
			else:
				print("O",end='')
		print()
	#pattern = pattern.astype(str)
	#pattern[pattern == '0'] = ' '
	#pattern[pattern == '1'] = 'O'
	#print(pattern)


if __name__ == "__main__":
	print("There are some already Avilable patterns")
	print("you can create your own paterrn in the intitial_patterns_file.json")
	#ask user for patterns to select from
	with open('initial_patterns_file.json','r') as initial_patterns_file:
			patterns = json.load(initial_patterns_file)

	with open("config.json",'r') as configuration_file:
		conifurations = json.load(configuration_file)

	load_pattern = input("Do you want to Select a pattern of load a default Pattern(y/n) : ")
	if(load_pattern == 'y' or 
	   load_pattern == 'Y' or 
	   load_pattern == "yes" or 
	   load_pattern == "Yes"):
		for pattern_key in patterns.keys():
			print("Pattern key : ",pattern_key)
			display_buffer(np.array(patterns[pattern_key]))

		selected_pattern_key = (input("Enter the Pattern Key to initialize : "))
		selected_pattern = np.array(patterns[selected_pattern_key])
	else:
		selected_pattern = np.array(patterns[conifurations['default_model']]) #deafault pattern to start from

	

	gameOfLife = GameOfLife()
	gameOfLife.setBoardSize(conifurations['board_size'])
	gameOfLife.setDelay(conifurations['delay'])
	gameOfLife.setBlankPixel(conifurations['blank_pixel'])
	gameOfLife.setLivePixel(conifurations['live_pixel'])
	gameOfLife.setPadding(conifurations['left_pad'], conifurations['left_pad'])
	gameOfLife.setPattern(selected_pattern)

	gameOfLife.live()